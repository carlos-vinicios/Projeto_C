#ifndef CREATEGASTOS_H
#define CREATEGASTOS_H

#include <QDialog>
#include "createcatgasto.h"

namespace Ui {
class createGastos;
}

class createGastos : public QDialog
{
    Q_OBJECT

public:
    explicit createGastos(QWidget *parent = 0);
    ~createGastos();
    void setComboBox();

private slots:
    void on_saveButton_clicked();

    void on_cancelButton_clicked();

    void on_createCatGastoButton_clicked();

private:
    Ui::createGastos *ui;
    CreateCatGasto *novaCat;
};

#endif // CREATEGASTOS_H
