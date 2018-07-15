#include <QMessageBox>
#include "mainwindow.h"
#include "createcapital.h"
#include "ui_createcapital.h"
#include "datacontrol.h"
#include "capital.h"

MainWindow *mainView2;

CreateCapital::CreateCapital(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateCapital)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint); //define o tipo de janela aberta
    ui->dateInput->setDate(QDate::currentDate());//define a data do calendário para a data atual do sistema
    mainView2 = static_cast<MainWindow*>(parent); //realiza um casting para acessar os métodos públicos da classe pai
}

CreateCapital::~CreateCapital()
{
    delete ui;
}

void CreateCapital::on_saveButton_clicked()
{
    Capital novoCapital;
    QMessageBox msgBox;
    int result;
    msgBox.setWindowTitle("Recebimento de Capital");
    QDate data = ui->dateInput->date();
    QString dataString = data.toString("dd/MM/yyyy");
    QString desc = ui->descInput->toPlainText();
    QString valor = ui->valorInput->text();
    QByteArray dataData = dataString.toLatin1();
    QByteArray descData = desc.toLatin1();
    novoCapital.data = dataData.data();
    novoCapital.desc = descData.data();
    novoCapital.valor = valor.toFloat();
    result = storeCapital(novoCapital);
    switch (result) {
        case 1:
            msgBox.setText("Cadastro realizado com sucesso!");
            msgBox.exec();
            mainView2->updateCapitais(mainView2->dataAtual, 1);
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
            msgBox.setText("Erro na manipulação da base de dados. Por favor, contate o desenvolvedor!");
            msgBox.exec();
            break;
    }
}

void CreateCapital::on_cancelButton_clicked()
{
    delete this;
}
