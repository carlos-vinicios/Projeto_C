#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDesktopWidget.h"
#include "datacontrol.h"
#include "user.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Usuario user;
    ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized); //define o state da janela para maximizado
    user = userRegistrado();
    if(user.id < 0){
        newUser = new createUser();
        newUser->setWindowModality(Qt::ApplicationModal);
        newUser->show();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addGastoButton_clicked()
{
    newGasto = new createGastos();
    newGasto->show();
}

void MainWindow::on_addCapitais_clicked()
{

}
