#include <QMessageBox>
#include "creategastos.h"
#include "createcatgasto.h"
#include "ui_createcatgasto.h"
#include "datacontrol.h"
#include "categoria.h"

createGastos *viewGasto;

CreateCatGasto::CreateCatGasto(QWidget *parent) : //recebe como parametro a classe de criação de gastos
    QWidget(parent),
    ui(new Ui::CreateCatGasto)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
    viewGasto = static_cast<createGastos*>(parent); //realiza um casting para acessar os métodos públicos da classe pai
}

CreateCatGasto::~CreateCatGasto()
{
    delete ui;
}

void CreateCatGasto::on_salvarButton_clicked()
{
    Categoria newCategoria;
    QMessageBox msgBox;
    int result;
    QString nome = ui->nomeInput->text();
    QByteArray nomeChar = nome.toLatin1();
    newCategoria.nome = nomeChar.data();
    result = storeCategoria(newCategoria);
    switch (result) {
        case 1:
            msgBox.setText("Cadastro realizado com sucesso!");
            msgBox.exec();
            viewGasto->setComboBox(); //atualiza os elementos da combobox
            delete this;
            break;
        case 0:
            msgBox.setText("O nome não pode está vázio!");
            msgBox.exec();
            break;
        case 2:
            msgBox.setText("Erro na manipulação da base de dados. Por favor, contate o desenvolvedor!");
            msgBox.exec();
            break;
    }
}

void CreateCatGasto::on_cancelarButton_clicked()
{
    delete this;
}
