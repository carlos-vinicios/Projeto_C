/********************************************************************************
** Form generated from reading UI file 'createuser.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEUSER_H
#define UI_CREATEUSER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_createUser
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *title;
    QLabel *sub_title;
    QGridLayout *gridLayout;
    QDateEdit *nascInput;
    QLabel *labelNome;
    QLineEdit *nomeInput;
    QLabel *labelNasc;
    QLineEdit *rendaInput;
    QLabel *labelDesc;
    QTextEdit *descInput;
    QPushButton *saveButton;
    QLabel *labelRenda;

    void setupUi(QWidget *createUser)
    {
        if (createUser->objectName().isEmpty())
            createUser->setObjectName(QStringLiteral("createUser"));
        createUser->resize(426, 370);
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setPointSize(11);
        createUser->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icons/icons8-plus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        createUser->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(createUser);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        title = new QLabel(createUser);
        title->setObjectName(QStringLiteral("title"));

        verticalLayout->addWidget(title, 0, Qt::AlignHCenter);

        sub_title = new QLabel(createUser);
        sub_title->setObjectName(QStringLiteral("sub_title"));
        QFont font1;
        font1.setPointSize(8);
        sub_title->setFont(font1);

        verticalLayout->addWidget(sub_title, 0, Qt::AlignHCenter);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        nascInput = new QDateEdit(createUser);
        nascInput->setObjectName(QStringLiteral("nascInput"));
        nascInput->setCalendarPopup(true);

        gridLayout->addWidget(nascInput, 3, 0, 1, 1);

        labelNome = new QLabel(createUser);
        labelNome->setObjectName(QStringLiteral("labelNome"));

        gridLayout->addWidget(labelNome, 0, 0, 1, 1, Qt::AlignLeft);

        nomeInput = new QLineEdit(createUser);
        nomeInput->setObjectName(QStringLiteral("nomeInput"));

        gridLayout->addWidget(nomeInput, 1, 0, 1, 2);

        labelNasc = new QLabel(createUser);
        labelNasc->setObjectName(QStringLiteral("labelNasc"));

        gridLayout->addWidget(labelNasc, 2, 0, 1, 1, Qt::AlignLeft);

        rendaInput = new QLineEdit(createUser);
        rendaInput->setObjectName(QStringLiteral("rendaInput"));

        gridLayout->addWidget(rendaInput, 5, 0, 1, 2, Qt::AlignLeft);

        labelDesc = new QLabel(createUser);
        labelDesc->setObjectName(QStringLiteral("labelDesc"));

        gridLayout->addWidget(labelDesc, 6, 0, 1, 1, Qt::AlignLeft);

        descInput = new QTextEdit(createUser);
        descInput->setObjectName(QStringLiteral("descInput"));

        gridLayout->addWidget(descInput, 7, 0, 1, 2);

        saveButton = new QPushButton(createUser);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        gridLayout->addWidget(saveButton, 8, 0, 1, 2, Qt::AlignHCenter);

        labelRenda = new QLabel(createUser);
        labelRenda->setObjectName(QStringLiteral("labelRenda"));

        gridLayout->addWidget(labelRenda, 4, 0, 1, 1, Qt::AlignLeft);


        verticalLayout->addLayout(gridLayout);

        QWidget::setTabOrder(nomeInput, nascInput);
        QWidget::setTabOrder(nascInput, rendaInput);
        QWidget::setTabOrder(rendaInput, descInput);
        QWidget::setTabOrder(descInput, saveButton);

        retranslateUi(createUser);

        QMetaObject::connectSlotsByName(createUser);
    } // setupUi

    void retranslateUi(QWidget *createUser)
    {
        createUser->setWindowTitle(QApplication::translate("createUser", "Novo usu\303\241rio", nullptr));
        title->setText(QApplication::translate("createUser", "Bem vindo ao Vida Financeira", nullptr));
        sub_title->setText(QApplication::translate("createUser", "Realize o cadastro abaixo para utilizar o nosso programa", nullptr));
        labelNome->setText(QApplication::translate("createUser", "Nome:", nullptr));
        labelNasc->setText(QApplication::translate("createUser", "Data de nascimento:", nullptr));
        rendaInput->setPlaceholderText(QApplication::translate("createUser", "2000.00", nullptr));
        labelDesc->setText(QApplication::translate("createUser", "Descri\303\247\303\243o:", nullptr));
        saveButton->setText(QApplication::translate("createUser", "Cadastrar", nullptr));
        labelRenda->setText(QApplication::translate("createUser", "Renda", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createUser: public Ui_createUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEUSER_H
