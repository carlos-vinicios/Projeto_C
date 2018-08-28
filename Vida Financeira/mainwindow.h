#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QLabel>
#include <QDate>
#include "creategastos.h"
#include "createuser.h"
#include "createcapital.h"
#include "createinvestimento.h"
#include "datacontrol.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void updateCapitais(QDate data, int type);
    void updateInvest(QDate data, int type);
    void updateGastos(QDate data, int type);
    QDate dataAtual;

private slots:
    void on_addGastoButton_clicked();

    void on_addCapitais_clicked();

    void on_addInvestimentos_clicked();

    void startUser();

    void startGastos(QDate data);

    void createDivGasto(Categoria cat, int row, int col, float *gastoTotal, QDate data);

    void startInvest();

    void startCapital();

    void startEstatisticas();

    void on_mesAnterior_clicked();

    void on_mesSeguin_clicked();

    void resetMonth();

private:
    Ui::MainWindow *ui;
    Usuario user;
    createGastos *newGasto;
    createUser *newUser;
    CreateCapital *newCapital;
    CreateInvestimento *newInvestimento;
    QTableWidget *tableInvest;
    QTableWidget *tableCapital;
    QLabel *userInvestido;
    QLabel *userGastoMes = NULL;
    QString headerTextStyle = "color:rgb(255, 105, 46); font-size:18px; font: large 'Segoe UI';";
    int mes, ano;
};

#endif // MAINWINDOW_H
