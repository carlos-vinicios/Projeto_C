#include <QMessageBox>
#include "mainwindow.h"
#include "createinvestimento.h"
#include "ui_createinvestimento.h"
#include "datacontrol.h"
#include "investimento.h"

MainWindow *mainView;

CreateInvestimento::CreateInvestimento(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateInvestimento)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint); //define o tipo de janela aberta
    ui->dateInput->setDate(QDate::currentDate());//define a data do calendário para a data atual do sistema
    mainView = static_cast<MainWindow*>(parent); //realiza um casting para acessar os métodos públicos da classe pai
}

CreateInvestimento::~CreateInvestimento()
{
    delete ui;
}

void CreateInvestimento::on_saveButton_clicked()
{
    Investimento novoInvestimento;
    QMessageBox msgBox;
    int result;
    msgBox.setWindowTitle("Novo Investimento");
    QDate data = ui->dateInput->date();
    QString dataString = data.toString("dd/MM/yyyy");
    QString local = ui->localInput->text();
    QString valor = ui->valorInput->text();
    QByteArray dataData = dataString.toLatin1();
    QByteArray localData = local.toLatin1();
    novoInvestimento.data = dataData.data();
    novoInvestimento.local = localData.data();
    novoInvestimento.valor = valor.toFloat();
    result = storeInvestimento(novoInvestimento);
    switch (result) {
        case 1:
            msgBox.setText("Cadastro realizado com sucesso!");
            msgBox.exec();
            mainView->updateInvest(mainView->dataAtual, 1);
            delete this;//fecha a dialog de adição de gastos
            break;
        case 0:
            msgBox.setText("A data não pode está vázia!");
            msgBox.exec();
            break;
        case 2:
            msgBox.setText("O local não pode está vázia!");
            msgBox.exec();
            break;
        case 3:
            msgBox.setText("O valor digitado é invalido!");
            msgBox.exec();
            break;
        case 4:
            msgBox.setText("Erro na manipulação da base de dados. Por favor, contate o desenvolvedor!");
            msgBox.exec();
            break;
    }
}

void CreateInvestimento::on_cancelButton_clicked()
{
    delete this;
}
