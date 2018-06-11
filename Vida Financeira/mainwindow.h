#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "creategastos.h"
#include "createuser.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addGastoButton_clicked();

    void on_addCapitais_clicked();

private:
    Ui::MainWindow *ui;
    createGastos *newGasto;
    createUser *newUser;
};

#endif // MAINWINDOW_H
