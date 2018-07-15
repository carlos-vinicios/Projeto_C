#ifndef CREATEINVESTIMENTO_H
#define CREATEINVESTIMENTO_H

#include <QWidget>

namespace Ui {
class CreateInvestimento;
}

class CreateInvestimento : public QWidget
{
    Q_OBJECT

public:
    explicit CreateInvestimento(QWidget *parent = 0);
    ~CreateInvestimento();

private slots:
    void on_saveButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::CreateInvestimento *ui;

};

#endif // CREATEINVESTIMENTO_H
