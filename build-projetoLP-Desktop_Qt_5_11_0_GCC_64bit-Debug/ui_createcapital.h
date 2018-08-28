/********************************************************************************
** Form generated from reading UI file 'createcapital.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECAPITAL_H
#define UI_CREATECAPITAL_H

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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CreateCapital
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *labelDesc;
    QLineEdit *valorInput;
    QTextEdit *descInput;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QLabel *labelValor;
    QDateEdit *dateInput;
    QLabel *labelData;

    void setupUi(QDialog *CreateCapital)
    {
        if (CreateCapital->objectName().isEmpty())
            CreateCapital->setObjectName(QStringLiteral("CreateCapital"));
        CreateCapital->resize(352, 300);
        CreateCapital->setMinimumSize(QSize(352, 300));
        CreateCapital->setMaximumSize(QSize(352, 300));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setPointSize(11);
        CreateCapital->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icons/main_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        CreateCapital->setWindowIcon(icon);
        CreateCapital->setAutoFillBackground(false);
        CreateCapital->setStyleSheet(QLatin1String("QDialog{\n"
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
        verticalLayout = new QVBoxLayout(CreateCapital);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelDesc = new QLabel(CreateCapital);
        labelDesc->setObjectName(QStringLiteral("labelDesc"));

        gridLayout->addWidget(labelDesc, 10, 0, 1, 1);

        valorInput = new QLineEdit(CreateCapital);
        valorInput->setObjectName(QStringLiteral("valorInput"));

        gridLayout->addWidget(valorInput, 9, 0, 1, 1, Qt::AlignLeft);

        descInput = new QTextEdit(CreateCapital);
        descInput->setObjectName(QStringLiteral("descInput"));

        gridLayout->addWidget(descInput, 11, 0, 1, 2);

        saveButton = new QPushButton(CreateCapital);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(saveButton, 12, 0, 1, 1, Qt::AlignRight);

        cancelButton = new QPushButton(CreateCapital);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setCursor(QCursor(Qt::PointingHandCursor));
        cancelButton->setAutoFillBackground(false);

        gridLayout->addWidget(cancelButton, 12, 1, 1, 1, Qt::AlignLeft);

        labelValor = new QLabel(CreateCapital);
        labelValor->setObjectName(QStringLiteral("labelValor"));

        gridLayout->addWidget(labelValor, 7, 0, 1, 1, Qt::AlignLeft);

        dateInput = new QDateEdit(CreateCapital);
        dateInput->setObjectName(QStringLiteral("dateInput"));
        dateInput->setCursor(QCursor(Qt::ArrowCursor));
        dateInput->setCalendarPopup(true);
        dateInput->setDate(QDate(2000, 1, 1));

        gridLayout->addWidget(dateInput, 6, 0, 1, 1);

        labelData = new QLabel(CreateCapital);
        labelData->setObjectName(QStringLiteral("labelData"));

        gridLayout->addWidget(labelData, 5, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(CreateCapital);

        QMetaObject::connectSlotsByName(CreateCapital);
    } // setupUi

    void retranslateUi(QDialog *CreateCapital)
    {
        CreateCapital->setWindowTitle(QApplication::translate("CreateCapital", "Recebimento de Capital", nullptr));
        labelDesc->setText(QApplication::translate("CreateCapital", "Descri\303\247\303\243o:", nullptr));
        valorInput->setPlaceholderText(QApplication::translate("CreateCapital", "200.00", nullptr));
        saveButton->setText(QApplication::translate("CreateCapital", "Salvar", nullptr));
        cancelButton->setText(QApplication::translate("CreateCapital", "Cancelar", nullptr));
        labelValor->setText(QApplication::translate("CreateCapital", "Valor:", nullptr));
        labelData->setText(QApplication::translate("CreateCapital", "Data:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateCapital: public Ui_CreateCapital {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECAPITAL_H
