#ifndef CREATEGASTOS_H
#define CREATEGASTOS_H

#include <QDialog>

namespace Ui {
class createGastos;
}

class createGastos : public QDialog
{
    Q_OBJECT

public:
    explicit createGastos(QWidget *parent = 0);
    ~createGastos();

private slots:
    void on_saveButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::createGastos *ui;
};

#endif // CREATEGASTOS_H
