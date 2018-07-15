#include <QMessageBox>
#include "mainwindow.h"
#include "creategastos.h"
#include "ui_creategastos.h"
#include "datacontrol.h"
#include "gasto.h"
#include "categoria.h"

int *idCategorias;
MainWindow *mainView3;

createGastos::createGastos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createGastos)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint); //define o tipo de janela aberta
    setComboBox(); //seta os elementos da combobox
    ui->dateInput->setDate(QDate::currentDate());//define a data do calendário para a data atual do sistema
    mainView3 = static_cast<MainWindow*>(parent); //realiza um casting para acessar os métodos públicos da classe pai
}

createGastos::~createGastos()
{
    delete ui;
}

void createGastos::on_saveButton_clicked()
{
    Gasto novoGasto;
    QMessageBox msgBox;
    int result, tipo;
    msgBox.setWindowTitle("Novo gasto");
    QDate data = ui->dateInput->date();
    QString dataString = data.toString("dd/MM/yyyy");
    QString desc = ui->descInput->toPlainText();
    QString valor = ui->valorInput->text();
    if(ui->mensalInput->isChecked()){
        tipo = 1;//gasto mensal
    }else{
        tipo = 2;//gasto rotativo
    }
    QByteArray dataData = dataString.toLatin1();
    QByteArray descData = desc.toLatin1();
    novoGasto.data = dataData.data();
    novoGasto.desc = descData.data();
    novoGasto.valor = valor.toFloat();
    novoGasto.tipo = tipo;
    novoGasto.categoria = idCategorias[ui->categoriasComboBox->currentIndex()];
    result = storeGasto(novoGasto);
    switch (result) {
        case 1:
            msgBox.setText("Cadastro realizado com sucesso!");
            msgBox.exec();
            mainView3->updateGastos(mainView3->dataAtual, 1);
            delete this;//fecha a dialog de adição de gastos
            break;
        case 0:
            msgBox.setText("A data não pode está vázia!");
            msgBox.exec();
            break;
        case 2:
            msgBox.setText("A descrição não pode está vázia!");
            msgBox.exec();
            break;
        case 3:
            msgBox.setText("O valor digitado é invalido!");
            msgBox.exec();
            break;
        case 4:
            msgBox.setText("O gasto deve possuir um tipo!");
            msgBox.exec();
            break;
        case 5:
            msgBox.setText("O gasto deve possuir uma categoria!");
            msgBox.exec();
            break;
        case 6:
            msgBox.setText("Erro na manipulação da base de dados. Por favor, contate o desenvolvedor!");
            msgBox.exec();
            break;
    }
}

void createGastos::on_cancelButton_clicked()
{
    delete this;
}

void createGastos::on_createCatGastoButton_clicked()
{
    novaCat = new CreateCatGasto(this); //enviando o this para sinalizar a janela criada que o pai dela é esta
    novaCat->setWindowModality(Qt::ApplicationModal);
    novaCat->show();
}

void createGastos::setComboBox(){ //função que cria os elementos da combobox
    ui->categoriasComboBox->clear();
    int i=0;
    Categorias *todasCategorias;
    todasCategorias = listAllCategorias();
    idCategorias = new int[sizeof(*todasCategorias)];
    while(todasCategorias != NULL){
        QString nome = QString::asprintf(todasCategorias->categoria.nome);
        ui->categoriasComboBox->addItem(nome);
        idCategorias[i] = todasCategorias->categoria.id;
        todasCategorias = todasCategorias->next;
        i++;
    }
    delete todasCategorias;
}
