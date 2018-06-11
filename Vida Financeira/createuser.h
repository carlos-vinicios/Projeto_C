#ifndef CREATEUSER_H
#define CREATEUSER_H

#include <QWidget>

namespace Ui {
    class createUser;
}

class createUser : public QWidget
{
    Q_OBJECT

public:
    explicit createUser(QWidget *parent = 0);
    ~createUser();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_saveButton_clicked();

private:
    Ui::createUser *ui;
};

#endif // CREATEUSER_H
