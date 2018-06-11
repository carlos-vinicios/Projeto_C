#include <QMessageBox>
#include <QCloseEvent>
#include <QProcess>
#include <QApplication>
#include "createuser.h"
#include "ui_createuser.h"
#include "datacontrol.h"
#include "user.h"

createUser::createUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createUser)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
}

createUser::~createUser()
{
    delete ui;
}

void createUser::closeEvent(QCloseEvent *event){
    QApplication::quit();
}

void createUser::on_saveButton_clicked()
{
    Usuario user;
    QMessageBox msgBox;
    int result;
    msgBox.setWindowTitle("Cadastro de Usuário");
    QString nome = ui->nomeInput->text();
    QString desc = ui->descInput->toPlainText();
    QDate date = ui->nascInput->date();
    QString dateString = date.toString("dd/MM/yyyy");
    QString renda = ui->rendaInput->text();
    QByteArray nomeData = nome.toLatin1();
    QByteArray descData = desc.toLatin1();
    QByteArray dateData = dateString.toLatin1();
    user.nome = nomeData.data();
    user.desc = descData.data();
    user.nasc = dateData.data();
    user.renda = renda.toFloat();
    result = storeUser(user);
    switch (result) {
        case 1:
            msgBox.setText("Cadastro realizado com sucesso!");
            msgBox.exec();
            break;
        case 0:
            msgBox.setText("O nome não pode está vázio!");
            msgBox.exec();
            break;
        case 2:
            msgBox.setText("A data de nascimento não pode está vázia!");
            msgBox.exec();
            break;
        case 3:
            msgBox.setText("A descrição não pode está vázia!");
            msgBox.exec();
            break;
        case 4:
            msgBox.setText("Valor da renda deve ser superior a 0!");
            msgBox.exec();
            break;
        case 5:
            msgBox.setText("Erro na manipulação da base de dados. Por favor, contate o desenvolvedor!");
            msgBox.exec();
            break;
    }
    close();
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}
