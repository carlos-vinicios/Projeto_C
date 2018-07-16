#ifndef CREATECAPITAL_H
#define CREATECAPITAL_H

#include <QDialog>

namespace Ui {
class CreateCapital;
}

class CreateCapital : public QDialog
{
    Q_OBJECT

public:
    explicit CreateCapital(QWidget *parent = 0);
    ~CreateCapital();

private slots:
    void on_saveButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::CreateCapital *ui;
};

#endif // CREATECAPITAL_H
