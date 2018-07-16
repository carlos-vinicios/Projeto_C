#ifndef ALTERUSER_H
#define ALTERUSER_H

#include <QWidget>

namespace Ui {
class AlterUser;
}

class AlterUser : public QWidget
{
    Q_OBJECT

public:
    explicit AlterUser(QWidget *parent = 0);
    ~AlterUser();

private slots:
    void on_saveButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::AlterUser *ui;
};

#endif // ALTERUSER_H
