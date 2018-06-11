#include <QMessageBox>
#include "creategastos.h"
#include "ui_creategastos.h"
#include "datacontrol.h"
#include "gasto.h"

createGastos::createGastos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createGastos)
{
    ui->setupUi(this);
    ui->dateInput->setDate(QDate::currentDate());//define a data do calendário para a data atual do sistema
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
    result = storeGasto(novoGasto);
    if(result){
        msgBox.setText("Gasto adicionado com sucesso!");
        msgBox.exec();
    }else{
        msgBox.setText("Ocorreram erros na adição do gasto!");
        msgBox.exec();
    }
    close();//fecha a dialog de adição de gastos
}

void createGastos::on_cancelButton_clicked()
{
    close();
}
