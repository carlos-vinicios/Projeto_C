#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDesktopWidget.h"
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QHeaderView"
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
    dataAtual = QDate::currentDate();
    ui->labelMes->setText(dataAtual.toString("MMMM"));
    mes = dataAtual.month();
    ano = dataAtual.year();
    startUser();
    startGastos(dataAtual);
    startInvest();
    startCapital();
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
    tableHeader<<c1<<c2<<c3; //define as titulos para as colunas
    table->setColumnCount(3); //define a quantidade de coluna
    table->setHorizontalHeaderLabels(tableHeader); //seta os titulos criados
    table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //impede a criação de barra de scroll
    table->horizontalHeader()->setStretchLastSection(true); //ajusta a útlima cell para o tamanho da tabela
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //ajusta as cells de acordo com o reajuste
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
            ui->userInfosGrid->addWidget(userGastoMes, 0, 0); //adiciona a label a main
        }else{
            userGastoMes->setText(textGastoMes); //define a label do total do mes
        }
    }

    delete[] allCategorias;
}

void MainWindow::createDivGasto(Categoria cat, int row, int col, float *gastoTotal, QDate data){ //cria cada div com tables para exibição dos gastos de cada categoria
    Gastos *gastosCat, *tmp;
    QString valor, nomeCat, totalCat;
    float valorCat = 0;
    int n = 0;

    QHBoxLayout *header = new QHBoxLayout;
    QVBoxLayout *layout = new QVBoxLayout;
    QTableWidget *table = new QTableWidget(this);
    setTableConfig(table, "Data", "Descrição", "Valor");

    gastosCat = filterGastoByMonth(listGastosByCategoria(cat.id), data.toString("/MM/yyyy").toLatin1().data());

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
        table->setItem(n-1, 1, new QTableWidgetItem(gastosCat->gasto.desc));
        table->setItem(n-1, 2, new QTableWidgetItem("R$ " + valor));
        gastosCat = gastosCat->next;
    }

    //define os titulos de cada tabela de categoria, colocando o seu titulo e total
    nomeCat.sprintf("%s", cat.nome);
    totalCat.sprintf("Total: R$ %.2f", cat.total);
    header->addWidget(new QLabel(nomeCat, this));
    header->addWidget(new QLabel(totalCat, this), 0, Qt::AlignRight);
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
        tableCapital->setItem(n-1, 1, new QTableWidgetItem(capitais->capital.desc));
        tableCapital->setItem(n-1, 2, new QTableWidgetItem("R$ " + valor));
        capitais = capitais->next;
    }
    delete[] capitais;

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
    delete[] investimentos;

    ui->layoutInvestimentos->addWidget(tableInvest);
    textTotalInvest.sprintf("Total investido: R$ %.2f", total);
    userInvestido = new QLabel(textTotalInvest, this);
    ui->userInfosGrid->addWidget(userInvestido, 0, 1);
}

void MainWindow::resetMonth(){
    ui->labelMes->setText(dataAtual.toString("MMMM"));
    mes = dataAtual.month();
    ano = dataAtual.year();
}

void MainWindow::updateGastos(QDate data, int type){
    clearWidgets(ui->gridLayoutGasto);
    if(type)
        resetMonth();
    startGastos(data);
}

void MainWindow::updateInvest(QDate data, int type){
    Investimentos *investimentos;
    QString valor, textTotalInvest;
    int n = 0;
    float total = 0;

    tableInvest->setRowCount(0);
    if(type)
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
    delete[] investimentos;

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
    if(type)
        resetMonth();

    capitais = capitais = filterCapitalByMonth(listAllCapitais(), data.toString("MM/yyyy").toLatin1().data());;
    capitais = capitais->next;
    while(capitais != NULL){
        n++;
        tableCapital->setRowCount(n);
        valor.setNum(capitais->capital.valor);
        tableCapital->setItem(n-1, 0, new QTableWidgetItem(capitais->capital.data));
        tableCapital->setItem(n-1, 1, new QTableWidgetItem(capitais->capital.desc));
        tableCapital->setItem(n-1, 2, new QTableWidgetItem("R$ " + valor));
        capitais = capitais->next;
    }
    delete[] capitais;

    tableCapital->repaint();
}
