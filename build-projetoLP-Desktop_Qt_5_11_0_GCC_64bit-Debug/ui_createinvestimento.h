/********************************************************************************
** Form generated from reading UI file 'createinvestimento.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEINVESTIMENTO_H
#define UI_CREATEINVESTIMENTO_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CreateInvestimento
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *cancelButton;
    QLabel *labelValor;
    QLabel *labelData;
    QLabel *labelDesc;
    QPushButton *saveButton;
    QLineEdit *valorInput;
    QLineEdit *localInput;
    QDateEdit *dateInput;

    void setupUi(QDialog *CreateInvestimento)
    {
        if (CreateInvestimento->objectName().isEmpty())
            CreateInvestimento->setObjectName(QStringLiteral("CreateInvestimento"));
        CreateInvestimento->resize(324, 300);
        CreateInvestimento->setMinimumSize(QSize(324, 300));
        CreateInvestimento->setMaximumSize(QSize(324, 300));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setPointSize(12);
        CreateInvestimento->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icons/main_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        CreateInvestimento->setWindowIcon(icon);
        CreateInvestimento->setStyleSheet(QLatin1String("QDialog{\n"
"	background-image: url(:/Icons/background2.jpg);\n"
"}\n"
"QLabel{\n"
"	color:#FF692E;\n"
"	font: 12pt \"Segoe UI\";\n"
"}\n"
"QPushButton{\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ff9b58, stop: 0.4 #ff7037,\n"
"                                stop: 0.5 #ff7037, stop: 1.0 #ff9b58);\n"
"	border:none;\n"
"	padding: 10px;\n"
"	color:#FFF;\n"
"	margin-top: 10px;\n"
"}\n"
"QLineEdit{\n"
"	border:none;\n"
"	background-color:  transparent;\n"
"	padding:5px;\n"
"	border-bottom: 1px solid #000;\n"
"}\n"
"QDateEdit{\n"
"	padding:5px;\n"
"}"));
        verticalLayout = new QVBoxLayout(CreateInvestimento);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        cancelButton = new QPushButton(CreateInvestimento);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(cancelButton, 12, 1, 1, 1, Qt::AlignLeft);

        labelValor = new QLabel(CreateInvestimento);
        labelValor->setObjectName(QStringLiteral("labelValor"));

        gridLayout->addWidget(labelValor, 7, 0, 1, 1, Qt::AlignLeft|Qt::AlignVCenter);

        labelData = new QLabel(CreateInvestimento);
        labelData->setObjectName(QStringLiteral("labelData"));

        gridLayout->addWidget(labelData, 5, 0, 1, 1, Qt::AlignLeft|Qt::AlignVCenter);

        labelDesc = new QLabel(CreateInvestimento);
        labelDesc->setObjectName(QStringLiteral("labelDesc"));

        gridLayout->addWidget(labelDesc, 10, 0, 1, 1, Qt::AlignLeft|Qt::AlignVCenter);

        saveButton = new QPushButton(CreateInvestimento);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(saveButton, 12, 0, 1, 1, Qt::AlignRight);

        valorInput = new QLineEdit(CreateInvestimento);
        valorInput->setObjectName(QStringLiteral("valorInput"));

        gridLayout->addWidget(valorInput, 9, 0, 1, 2);

        localInput = new QLineEdit(CreateInvestimento);
        localInput->setObjectName(QStringLiteral("localInput"));

        gridLayout->addWidget(localInput, 11, 0, 1, 2);

        dateInput = new QDateEdit(CreateInvestimento);
        dateInput->setObjectName(QStringLiteral("dateInput"));
        dateInput->setCursor(QCursor(Qt::ArrowCursor));
        dateInput->setCalendarPopup(true);
        dateInput->setDate(QDate(2000, 1, 1));

        gridLayout->addWidget(dateInput, 6, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(CreateInvestimento);

        QMetaObject::connectSlotsByName(CreateInvestimento);
    } // setupUi

    void retranslateUi(QDialog *CreateInvestimento)
    {
        CreateInvestimento->setWindowTitle(QApplication::translate("CreateInvestimento", "Investimentos", nullptr));
        cancelButton->setText(QApplication::translate("CreateInvestimento", "Cancelar", nullptr));
        labelValor->setText(QApplication::translate("CreateInvestimento", "Valor:", nullptr));
        labelData->setText(QApplication::translate("CreateInvestimento", "Data:", nullptr));
        labelDesc->setText(QApplication::translate("CreateInvestimento", "Local:", nullptr));
        saveButton->setText(QApplication::translate("CreateInvestimento", "Salvar", nullptr));
        valorInput->setPlaceholderText(QApplication::translate("CreateInvestimento", "200.00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateInvestimento: public Ui_CreateInvestimento {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEINVESTIMENTO_H
