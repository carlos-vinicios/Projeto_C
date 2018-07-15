#ifndef CREATECATGASTO_H
#define CREATECATGASTO_H

#include <QWidget>

namespace Ui {
class CreateCatGasto;
}

class CreateCatGasto : public QWidget
{
    Q_OBJECT

public:
    explicit CreateCatGasto(QWidget *parent = 0);
    ~CreateCatGasto();

private slots:
    void on_salvarButton_clicked();

    void on_cancelarButton_clicked();

private:
    Ui::CreateCatGasto *ui;
};

#endif // CREATECATGASTO_H
