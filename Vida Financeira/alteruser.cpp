#include "alteruser.h"
#include "QMessageBox"
#include "ui_alteruser.h"
#include "datacontrol.h"
#include "user.h"

AlterUser::AlterUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlterUser)
{
    ui->setupUi(this);
}

AlterUser::~AlterUser()
{
    delete ui;
}

void AlterUser::on_saveButton_clicked()
{
//    QString renda;
//    QMessageBox *msgBox;
//    int result;

//    renda = ui->rendaInput->text();

////    result = updateUser();

//    switch (result) {
//        case 1:
//            msgBox.setText("Cadastro realizado com sucesso!");
//            msgBox.exec();
//            delete this;
//            break;
//        case 0:
//            msgBox.setText("O nome não pode está vázio!");
//            msgBox.exec();
//            break;
//        case 2:
//            msgBox.setText("A data de nascimento não pode está vázia!");
//            msgBox.exec();
//            break;
//        case 3:
//            msgBox.setText("A descrição não pode está vázia!");
//            msgBox.exec();
//            break;
//        case 4:
//            msgBox.setText("Valor da renda deve ser superior a 0!");
//            msgBox.exec();
//            break;
//        case 5:
//            msgBox.setText("Erro na manipulação da base de dados. Por favor, contate o desenvolvedor!");
//            msgBox.exec();
//            break;
//    }
}

void AlterUser::on_cancelButton_clicked()
{
    delete this;
}
