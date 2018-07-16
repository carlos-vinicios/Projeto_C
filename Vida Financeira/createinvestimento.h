#ifndef CREATEINVESTIMENTO_H
#define CREATEINVESTIMENTO_H

#include <QDialog>

namespace Ui {
class CreateInvestimento;
}

class CreateInvestimento : public QDialog
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
