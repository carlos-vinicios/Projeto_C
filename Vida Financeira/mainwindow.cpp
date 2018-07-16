#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDesktopWidget.h"
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QHeaderView"
#include "string.h"
#include "user.h"
#include "categoria.h"
#include "gasto.h"
#include "investimento.h"
#include "capital.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setWindowState(Qt::WindowMaximized); //define o state da janela para maximizado
    ui->setupUi(this);

    QPalette pal = this->palette();
    QPixmap bkgnd(":/Downloads/background2.jpg");
    pal.setBrush(QPalette::Window, bkgnd);
    this->setPalette(pal);

    dataAtual = QDate::currentDate();
    ui->labelMes->setText(dataAtual.toString("MMMM"));
    mes = dataAtual.month();
    ano = dataAtual.year();

    startUser();
    startGastos(dataAtual);
    startInvest();
    startCapital();
    startEstatisticas();
}

void clearWidgets(QLayout * layout) { //realiza a limpeza dos elementos de um layout
   if (! layout)
      return;
   while (auto item = layout->takeAt(0)) {
      delete item->widget();
      clearWidgets(item->layout());
   }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addGastoButton_clicked()
{
    newGasto = new createGastos(this);
    newGasto->setWindowModality(Qt::ApplicationModal);//define que a widget será um modal
    newGasto->show();
}

void MainWindow::on_addCapitais_clicked()
{
    newCapital = new CreateCapital(this);
    newCapital->setWindowModality(Qt::ApplicationModal);//define que a widget será um modal
    newCapital->show();
}

void MainWindow::on_addInvestimentos_clicked()
{
    newInvestimento = new CreateInvestimento(this);
    newInvestimento->setWindowModality(Qt::ApplicationModal);//define que a widget será um modal
    newInvestimento->show();
}

void MainWindow::on_mesAnterior_clicked()
{
    QDate newData;

    mes--;
    if(mes < 1){
        mes = 12;
        ano--;
    }

    newData.setDate(ano, mes, 1);
    ui->labelMes->setText(newData.toString("MMMM"));
    updateGastos(newData, 0);
    updateCapitais(newData, 0);
    updateInvest(newData, 0);
}

void MainWindow::on_mesSeguin_clicked()
{
    QDate newData;

    if(mes < dataAtual.month() || ano < dataAtual.year()){
        mes++;
        if(mes > 12){
            mes = 1;
            ano++;
        }
        newData.setDate(ano, mes, 1);
        ui->labelMes->setText(newData.toString("MMMM"));
        updateGastos(newData, 0);
        updateCapitais(newData, 0);
        updateInvest(newData, 0);
    }
}

void setTableConfig(QTableWidget *table, QString c1, QString c2, QString c3){ //realiza as configurações de responsividade das tabelas apresentadas
    QStringList tableHeader;
    QString tableHeaderStyle = "::section{background-color:#FF7C3A; color:#FFF; font-size:14px; font: large 'Segoe UI'; padding:2px; border:none; border-right:1px solid black} ::section::last{border-right:none;}";
    tableHeader<<c1<<c2<<c3; //define as titulos para as colunas
    table->setColumnCount(3); //define a quantidade de coluna
    table->setHorizontalHeaderLabels(tableHeader); //seta os titulos criados
    table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //impede a criação de barra de scroll
    table->horizontalHeader()->setStretchLastSection(true); //ajusta a útlima cell para o tamanho da tabela
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //ajusta as cells de acordo com o reajuste
    table->horizontalHeader()->setStyleSheet(tableHeaderStyle);
    table->verticalHeader()->setVisible(false);
}

void MainWindow::startUser(){ //inicializa as informações do usuario
    QLabel *userName;
    user = userRegistrado();
    if(user.id < 0){
        newUser = new createUser();
        newUser->setWindowModality(Qt::ApplicationModal);
        newUser->show();
    }else{
        userName = new QLabel(user.nome, this);
        userName->setCursor(Qt::PointingHandCursor);
        userName->setStyleSheet(headerTextStyle);
        ui->userInfosGrid->addWidget(userName, 0, 4, Qt::AlignRight);
    }
}

void MainWindow::startGastos(QDate data){
    Categorias *allCategorias;
    QString textGastoMes;
    int row = 0, col = 0;
    float gastoTotal = 0, rendaRestante;

    allCategorias = listAllCategorias();
    allCategorias = allCategorias->next;
    while(allCategorias != NULL){
        createDivGasto(allCategorias->categoria, row, col, &gastoTotal, data); //cria a tabela com titulo e total para cada cadegoria dada (mês atual)
        allCategorias = allCategorias->next;
        col += 2; //realiza os calculos para posicionamento de cada tabela das categorias
        if(col >= 8){
            col = 0;
            row += 3;
        }
    }

    if(mes == dataAtual.month() && ano == dataAtual.year()){
        rendaRestante = user.renda - gastoTotal;
        textGastoMes.sprintf("Renda restante: R$ %.2f", (rendaRestante)); //monta o texto a ser exibido como o total do mês
        if(userGastoMes == NULL){
            userGastoMes = new QLabel(textGastoMes, this); //define a label do total do mes
            userGastoMes->setStyleSheet(headerTextStyle);
            ui->userInfosGrid->addWidget(userGastoMes, 0, 0); //adiciona a label a main
        }else{
            userGastoMes->setText(textGastoMes); //define a label do total do mes
        }
    }

    delete allCategorias;
}

void MainWindow::createDivGasto(Categoria cat, int row, int col, float *gastoTotal, QDate data){ //cria cada div com tables para exibição dos gastos de cada categoria
    Gastos *gastosCat, *tmp;
    QString valor, nomeCat, totalCat, tableTitleStyle, valorTableStyle;
    QLabel *tableCat, *tableTotal;
    float valorCat = 0;
    int n = 0;

    tableTitleStyle = "color:rgb(255, 105, 46); font-size:16px; font: large 'Segoe UI'; padding-left: 20px;";
    valorTableStyle = "color:rgb(255, 105, 46); font-size:16px; font: large 'Segoe UI'; padding-right: 20px;";

    QHBoxLayout *header = new QHBoxLayout;
    QVBoxLayout *layout = new QVBoxLayout;
    QTableWidget *table = new QTableWidget(this);
    setTableConfig(table, "Data", "Descrição", "Valor");

    gastosCat = listGastoByMonth(data.toString("MM/yyyy").toLatin1().data());
    gastosCat = filterGastosByCategoria(gastosCat, cat.id);

    tmp = gastosCat; //realiza o calculo do valor total da categoria
    while( tmp != NULL){
        valorCat += tmp->gasto.valor;
        tmp = tmp->next;
    }
    cat.total = valorCat;
    *gastoTotal+= cat.total; //acrescenta o valor total de de cada categoria

    gastosCat = gastosCat->next;
    while(gastosCat != NULL){ //adiciona cada gasto a sua respectiva categoria
        n++;
        table->setRowCount(n);
        valor.setNum(gastosCat->gasto.valor);
        table->setItem(n-1, 0, new QTableWidgetItem(gastosCat->gasto.data));
        table->setItem(n-1, 1, new QTableWidgetItem(QString::fromLatin1(gastosCat->gasto.desc)));
        table->setItem(n-1, 2, new QTableWidgetItem("R$ " + valor));
        gastosCat = gastosCat->next;
    }

    //define os titulos de cada tabela de categoria, colocando o seu titulo e total
    nomeCat.sprintf("%s", cat.nome);
    totalCat.sprintf("Total: R$ %.2f", cat.total);
    tableCat = new QLabel(nomeCat, this);
    tableCat->setStyleSheet(tableTitleStyle);
    tableTotal = new QLabel(totalCat, this);
    tableTotal->setStyleSheet(valorTableStyle);
    header->addWidget(tableCat);
    header->addWidget(tableTotal, 0, Qt::AlignRight);
    layout->addLayout(header);
    layout->addWidget(table);
    ui->gridLayoutGasto->addLayout(layout, row, col);

    delete tmp;
    delete gastosCat;
}

void MainWindow::startCapital(){
    Capitais *capitais;
    QString valor;
    int n = 0;

    tableCapital = new QTableWidget(this);
    setTableConfig(tableCapital, "Data", "Descrição", "Valor");

    capitais = filterCapitalByMonth(listAllCapitais(), dataAtual.toString("MM/yyyy").toLatin1().data());
    capitais = capitais->next;
    while(capitais != NULL){
        n++;
        tableCapital->setRowCount(n);
        valor.setNum(capitais->capital.valor);
        tableCapital->setItem(n-1, 0, new QTableWidgetItem(capitais->capital.data));
        tableCapital->setItem(n-1, 1, new QTableWidgetItem(QString::fromLatin1(capitais->capital.desc)));
        tableCapital->setItem(n-1, 2, new QTableWidgetItem("R$ " + valor));
        capitais = capitais->next;
    }
    delete capitais;

    ui->layoutCapitais->addWidget(tableCapital);
}

void MainWindow::startInvest(){ //realiza o carregamento das informações dos investimentos presentes no arquivo
    Investimentos *investimentos;
    QString valor, textTotalInvest;
    int n = 0;
    float total = 0;

    tableInvest = new QTableWidget(this);
    setTableConfig(tableInvest, "Data", "Local", "Valor");

    investimentos = filterInvestimentoByMonth(listAllInvestimentos(), dataAtual.toString("MM/yyyy").toLatin1().data());
    investimentos = investimentos->next;
    while(investimentos != NULL){
        n++;
        tableInvest->setRowCount(n);
        valor.setNum(investimentos->investimento.valor);
        total+= investimentos->investimento.valor;
        tableInvest->setItem(n-1, 0, new QTableWidgetItem(investimentos->investimento.data));
        tableInvest->setItem(n-1, 1, new QTableWidgetItem(investimentos->investimento.local));
        tableInvest->setItem(n-1, 2, new QTableWidgetItem("R$ " + valor));
        investimentos = investimentos->next;
    }

    ui->layoutInvestimentos->addWidget(tableInvest);
    textTotalInvest.sprintf("Total investido: R$ %.2f", total);
    userInvestido = new QLabel(textTotalInvest, this);
    userInvestido->setStyleSheet(headerTextStyle);
    ui->userInfosGrid->addWidget(userInvestido, 0, 1);

    delete investimentos;
}

void MainWindow::startEstatisticas(){
    Gastos *gastos, *listaGasto, *listaGasto2;
    Investimentos *investimentos, *listaInvest, *listaInvest2;
    Capitais *capitais, *listaCapitais, *listaCapitais2;
    QList<QString> mesAnoComputados;
    QDate data;
    QLabel *mesText, *gastoText, *investText, *capitalText, *gastoTitleText, *investTitleText, *capitaisTitleText;
    QString dataString="", mesString="", anoString="", gastoString, investString, capitalString, headerStyle, contentStyle;
    float totalGasto = 0, totalInvest = 0, totalCapital = 0;
    int row = 1, start = 0, scretch = 0;

    headerStyle = "background-color:#FF692E; font-size:16px; font: large 'Segoe UI'; color:#FFF; padding:10px 60px;";
    contentStyle = "font-size:16px; font: large 'Segoe UI'; padding:10px 60px;";

    gastos = listAllGastos();
    gastos = gastos->next;
    capitais = listAllCapitais();
    capitais = capitais->next;
    investimentos = listAllInvestimentos();
    investimentos = investimentos->next;

    gastoTitleText = new QLabel("Gasto");
    investTitleText = new QLabel("Investimento");
    capitaisTitleText = new QLabel("Capitais");

    gastoTitleText->setStyleSheet(headerStyle);
    investTitleText->setStyleSheet(headerStyle);
    capitaisTitleText->setStyleSheet(headerStyle);

    ui->gridLayoutEstatisticas->addWidget(gastoTitleText, 0, 1, 1, 1, Qt::AlignCenter);
    ui->gridLayoutEstatisticas->addWidget(investTitleText, 0, 2, 1, 1, Qt::AlignCenter);
    ui->gridLayoutEstatisticas->addWidget(capitaisTitleText, 0, 3, 1, 1, Qt::AlignCenter);
    ui->gridLayoutEstatisticas->setRowStretch(0, scretch);
    scretch++;

    for(listaGasto = gastos; listaGasto != NULL; listaGasto = listaGasto->next){
        if(strstr(listaGasto->gasto.data, dataAtual.toString("MM/yyyy").toLatin1().data()) == NULL){
            for(int i = 0; i < strlen(listaGasto->gasto.data); i++){
                if(listaGasto->gasto.data[i] == '/'){
                    start++;
                }
                if(start > 0){//pega o mes e ano para usar no strstr dos outros gastos
                    dataString+= listaGasto->gasto.data[i];
                }
                if(start == 1){ //pega o mes da data
                    mesString += listaGasto->gasto.data[i+1];
                    mesString += listaGasto->gasto.data[i+2];
                    start++;//pora não copiar duas vezes
                }
                if(start == 3){ //pega o ano da data
                    anoString += listaGasto->gasto.data[i+1];
                    anoString += listaGasto->gasto.data[i+2];
                    anoString += listaGasto->gasto.data[i+3];
                    anoString += listaGasto->gasto.data[i+4];
                    start++;//pora não copiar quatro vezes
                }
            }
            if(!mesAnoComputados.contains(dataString)){
                data.setDate(anoString.toInt(), mesString.toInt(), 1);
                row = data.month();
                mesText = new QLabel(data.toString("MMMM"));
                mesText->setStyleSheet(contentStyle);
                ui->gridLayoutEstatisticas->addWidget(mesText, row, 0, 1, 1, Qt::AlignCenter);
                totalGasto+=listaGasto->gasto.valor;
                for(listaGasto2 = gastos; listaGasto2 != NULL; listaGasto2 = listaGasto2->next){
                    if(listaGasto2 != listaGasto && strstr(listaGasto2->gasto.data, dataString.toLatin1().data()) != NULL){
                        totalGasto+=listaGasto2->gasto.valor;
                    }
                }
                gastoString.sprintf("R$ %.2f", totalGasto);
                gastoText = new QLabel(gastoString);
                ui->gridLayoutEstatisticas->addWidget(gastoText, row, 1, 1, 1, Qt::AlignCenter);
                for(listaInvest = investimentos; listaInvest != NULL; listaInvest = listaInvest->next){
                    if(strstr(listaInvest->investimento.data, dataString.toLatin1().data()) != NULL){
                        totalInvest += listaInvest->investimento.valor;
                    }
                }
                investString.sprintf("R$ %.2f", totalInvest);
                investText = new QLabel(investString);
                ui->gridLayoutEstatisticas->addWidget(investText, row, 2, 1, 1, Qt::AlignCenter);
                for(listaCapitais = capitais; listaCapitais != NULL; listaCapitais = listaCapitais->next){
                    if(strstr(listaCapitais->capital.data, dataString.toLatin1().data()) != NULL){
                        totalCapital += listaCapitais->capital.valor;
                    }
                }
                capitalString.sprintf("R$ %.2f", totalCapital);
                capitalText = new QLabel(capitalString);
                ui->gridLayoutEstatisticas->addWidget(capitalText, row, 3, 1, 1, Qt::AlignCenter);

                mesAnoComputados.append(dataString);
                //limpeza das variaveis
                dataString = "";
                mesString= "";
                anoString= "";
                gastoString = "";
                investString = "";
                capitalString = "";
                totalGasto = 0;
                totalInvest = 0;
                totalCapital = 0;
                start = 0;
            }
        }
    }

    for(listaInvest = investimentos; listaInvest != NULL; listaInvest = listaInvest->next){
        if(strstr(listaInvest->investimento.data, dataAtual.toString("MM/yyyy").toLatin1().data()) == NULL){
            for(int i = 0; i < strlen(listaInvest->investimento.data); i++){
                if(listaInvest->investimento.data[i] == '/'){
                    start++;
                }
                if(start > 0){//pega o mes e ano para usar no strstr dos outros gastos
                    dataString+= listaInvest->investimento.data[i];
                }
                if(start == 1){ //pega o mes da data
                    mesString += listaInvest->investimento.data[i+1];
                    mesString += listaInvest->investimento.data[i+2];
                    start++;//pora não copiar duas vezes
                }
                if(start == 3){ //pega o ano da data
                    anoString += listaInvest->investimento.data[i+1];
                    anoString += listaInvest->investimento.data[i+2];
                    anoString += listaInvest->investimento.data[i+3];
                    anoString += listaInvest->investimento.data[i+4];
                    start++;//pora não copiar quatro vezes
                }
            }
            if(!mesAnoComputados.contains(dataString)){
                data.setDate(anoString.toInt(), mesString.toInt(), 1);
                row = data.month();
                mesText = new QLabel(data.toString("MMMM"));
                ui->gridLayoutEstatisticas->addWidget(mesText, row, 0, 1, 1, Qt::AlignCenter);
                totalInvest+=listaInvest->investimento.valor;
                for(listaInvest2 = investimentos; listaInvest2 != NULL; listaInvest2 = listaInvest2->next){
                    if(listaInvest != listaInvest2 && strstr(listaInvest2->investimento.data, dataString.toLatin1().data()) != NULL){
                        totalInvest += listaInvest2->investimento.valor;
                    }
                }
                investString.sprintf("R$ %.2f", totalInvest);
                investText = new QLabel(investString);
                ui->gridLayoutEstatisticas->addWidget(investText, row, 2);
                for(listaGasto = gastos; listaGasto != NULL; listaGasto = listaGasto->next){
                    if(listaGasto != listaGasto && strstr(listaGasto->gasto.data, dataString.toLatin1().data()) != NULL){
                        totalGasto+=listaGasto->gasto.valor;
                    }
                }
                gastoString.sprintf("R$ %.2f", totalGasto);
                gastoText = new QLabel(gastoString);
                ui->gridLayoutEstatisticas->addWidget(gastoText, row, 1, 1, 1, Qt::AlignCenter);
                for(listaCapitais = capitais; listaCapitais != NULL; listaCapitais = listaCapitais->next){
                    if(strstr(listaCapitais->capital.data, dataString.toLatin1().data()) != NULL){
                        totalCapital += listaCapitais->capital.valor;
                    }
                }
                capitalString.sprintf("R$ %.2f", totalCapital);
                capitalText = new QLabel(capitalString);
                ui->gridLayoutEstatisticas->addWidget(capitalText, row, 3, 1, 1, Qt::AlignCenter);

                mesAnoComputados.append(dataString);
                //limpeza das variaveis
                dataString = "";
                mesString= "";
                anoString= "";
                gastoString = "";
                investString = "";
                capitalString = "";
                totalGasto = 0;
                totalInvest = 0;
                totalCapital = 0;
                start = 0;
            }
        }
    }

    for(listaCapitais = capitais; listaCapitais != NULL; listaCapitais = listaCapitais->next){
        if(strstr(listaCapitais->capital.data, dataAtual.toString("MM/yyyy").toLatin1().data()) == NULL){
            for(int i = 0; i < strlen(listaCapitais->capital.data); i++){
                if(listaCapitais->capital.data[i] == '/'){
                    start++;
                }
                if(start > 0){//pega o mes e ano para usar no strstr dos outros gastos
                    dataString+= listaCapitais->capital.data[i];
                }
                if(start == 1){ //pega o mes da data
                    mesString += listaCapitais->capital.data[i+1];
                    mesString += listaCapitais->capital.data[i+2];
                    start++;//pora não copiar duas vezes
                }
                if(start == 3){ //pega o ano da data
                    anoString += listaCapitais->capital.data[i+1];
                    anoString += listaCapitais->capital.data[i+2];
                    anoString += listaCapitais->capital.data[i+3];
                    anoString += listaCapitais->capital.data[i+4];
                    start++;//pora não copiar quatro vezes
                }
            }
            if(!mesAnoComputados.contains(dataString)){
                data.setDate(anoString.toInt(), mesString.toInt(), 1);
                row = data.month();
                mesText = new QLabel(data.toString("MMMM"));
                ui->gridLayoutEstatisticas->addWidget(mesText, row, 0, 1, 1, Qt::AlignCenter);
                totalCapital+=listaCapitais->capital.valor;
                for(listaCapitais2 = capitais; listaCapitais2 != NULL; listaCapitais2 = listaCapitais2->next){
                    if(listaCapitais != listaCapitais2 && strstr(listaCapitais->capital.data, dataString.toLatin1().data()) != NULL){
                        totalCapital += listaCapitais2->capital.valor;
                    }
                }
                capitalString.sprintf("R$ %.2f", totalCapital);
                capitalText = new QLabel(capitalString);
                ui->gridLayoutEstatisticas->addWidget(capitalText, row, 3, 1, 1, Qt::AlignCenter);
                for(listaGasto = gastos; listaGasto != NULL; listaGasto = listaGasto->next){
                    if(strstr(listaGasto->gasto.data, dataString.toLatin1().data()) != NULL){
                        totalGasto+=listaGasto->gasto.valor;
                    }
                }
                gastoString.sprintf("R$ %.2f", totalGasto);
                gastoText = new QLabel(gastoString);
                ui->gridLayoutEstatisticas->addWidget(gastoText, row, 1, 1, 1, Qt::AlignCenter);
                for(listaInvest = investimentos; listaInvest != NULL; listaInvest = listaInvest->next){
                    if(strstr(listaInvest->investimento.data, dataString.toLatin1().data()) != NULL){
                        totalInvest += listaInvest->investimento.valor;
                    }
                }
                investString.sprintf("R$ %.2f", totalInvest);
                investText = new QLabel(investString);
                ui->gridLayoutEstatisticas->addWidget(investText, row, 2, 1, 1, Qt::AlignCenter);

                mesAnoComputados.append(dataString);
                //limpeza das variaveis
                dataString = "";
                mesString= "";
                anoString= "";
                gastoString = "";
                investString = "";
                capitalString = "";
                totalGasto = 0;
                totalInvest = 0;
                totalCapital = 0;
                start = 0;
            }
        }
    }
    row = ui->gridLayoutEstatisticas->rowCount();
    ui->gridLayoutEstatisticas->setRowStretch(row, scretch);

//    delete gastos; delete listaGasto; delete listaGasto2;
//    delete investimentos; delete listaInvest, delete listaInvest2;
//    delete capitais, delete listaCapitais, delete listaCapitais2;
//    mesAnoComputados.clear();
}

void MainWindow::resetMonth(){
    ui->labelMes->setText(dataAtual.toString("MMMM"));
    mes = dataAtual.month();
    ano = dataAtual.year();
}

void MainWindow::updateGastos(QDate data, int type){
    clearWidgets(ui->gridLayoutGasto);
    if(type)//se for um insert
        resetMonth();
    startGastos(data);
}

void MainWindow::updateInvest(QDate data, int type){
    Investimentos *investimentos;
    QString valor, textTotalInvest;
    int n = 0;
    float total = 0;

    tableInvest->setRowCount(0);
    if(type)//se for um insert
        resetMonth();

    investimentos = filterInvestimentoByMonth(listAllInvestimentos(), data.toString("MM/yyyy").toLatin1().data());
    investimentos = investimentos->next;
    while(investimentos != NULL){
        n++;
        tableInvest->setRowCount(n);
        valor.setNum(investimentos->investimento.valor);
        total+= investimentos->investimento.valor;
        tableInvest->setItem(n-1, 0, new QTableWidgetItem(investimentos->investimento.data));
        tableInvest->setItem(n-1, 1, new QTableWidgetItem(investimentos->investimento.local));
        tableInvest->setItem(n-1, 2, new QTableWidgetItem("R$ " + valor));
        investimentos = investimentos->next;
    }
    delete investimentos;

    tableInvest->repaint();
    if(mes == dataAtual.month() && ano == dataAtual.year()){
        textTotalInvest.sprintf("Total investido: R$ %.2f", total);
        userInvestido->setText(textTotalInvest);
    }
}

void MainWindow::updateCapitais(QDate data, int type){
    Capitais *capitais;
    QString valor;
    int n = 0;

    tableCapital->setRowCount(0);
    if(type)//se for um insert
        resetMonth();

    capitais = filterCapitalByMonth(listAllCapitais(), data.toString("MM/yyyy").toLatin1().data());;
    capitais = capitais->next;
    while(capitais != NULL){
        n++;
        tableCapital->setRowCount(n);
        valor.setNum(capitais->capital.valor);
        tableCapital->setItem(n-1, 0, new QTableWidgetItem(capitais->capital.data));
        tableCapital->setItem(n-1, 1, new QTableWidgetItem(QString::fromLatin1(capitais->capital.desc)));
        tableCapital->setItem(n-1, 2, new QTableWidgetItem("R$ " + valor));
        capitais = capitais->next;
    }
    delete capitais;

    tableCapital->repaint();
}
