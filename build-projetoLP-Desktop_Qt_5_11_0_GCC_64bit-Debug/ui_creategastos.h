/********************************************************************************
** Form generated from reading UI file 'creategastos.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEGASTOS_H
#define UI_CREATEGASTOS_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_createGastos
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *labelCate;
    QLabel *labelDesc;
    QLineEdit *valorInput;
    QTextEdit *descInput;
    QPushButton *cancelButton;
    QPushButton *saveButton;
    QComboBox *categoriasComboBox;
    QCheckBox *mensalInput;
    QLabel *labelValor;
    QDateEdit *dateInput;
    QLabel *labelData;
    QPushButton *createCatGastoButton;

    void setupUi(QDialog *createGastos)
    {
        if (createGastos->objectName().isEmpty())
            createGastos->setObjectName(QStringLiteral("createGastos"));
        createGastos->resize(428, 396);
        createGastos->setMinimumSize(QSize(428, 356));
        createGastos->setMaximumSize(QSize(428, 396));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setPointSize(10);
        createGastos->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icons/main_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        createGastos->setWindowIcon(icon);
        createGastos->setStyleSheet(QLatin1String("QDialog{\n"
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
"}\n"
"QLineEdit{\n"
"	border:none;\n"
"	background-color: transparent;\n"
"	padding:5px;\n"
"	border-bottom: 1px solid #000;\n"
"}\n"
"QDateEdit{\n"
"	padding:5px;\n"
"}\n"
"QCheckBox{\n"
"	color:#FF692E;\n"
"	margin: 10px 0;\n"
"}"));
        verticalLayout = new QVBoxLayout(createGastos);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelCate = new QLabel(createGastos);
        labelCate->setObjectName(QStringLiteral("labelCate"));

        gridLayout->addWidget(labelCate, 10, 0, 1, 1);

        labelDesc = new QLabel(createGastos);
        labelDesc->setObjectName(QStringLiteral("labelDesc"));

        gridLayout->addWidget(labelDesc, 13, 0, 1, 1);

        valorInput = new QLineEdit(createGastos);
        valorInput->setObjectName(QStringLiteral("valorInput"));

        gridLayout->addWidget(valorInput, 9, 0, 1, 1, Qt::AlignLeft);

        descInput = new QTextEdit(createGastos);
        descInput->setObjectName(QStringLiteral("descInput"));

        gridLayout->addWidget(descInput, 14, 0, 1, 2);

        cancelButton = new QPushButton(createGastos);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(cancelButton, 15, 1, 1, 1, Qt::AlignLeft);

        saveButton = new QPushButton(createGastos);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setCursor(QCursor(Qt::PointingHandCursor));
        saveButton->setStyleSheet(QStringLiteral(""));
        saveButton->setAutoDefault(false);
        saveButton->setFlat(false);

        gridLayout->addWidget(saveButton, 15, 0, 1, 1, Qt::AlignRight);

        categoriasComboBox = new QComboBox(createGastos);
        categoriasComboBox->setObjectName(QStringLiteral("categoriasComboBox"));
        categoriasComboBox->setMaxVisibleItems(5);

        gridLayout->addWidget(categoriasComboBox, 11, 0, 1, 1);

        mensalInput = new QCheckBox(createGastos);
        mensalInput->setObjectName(QStringLiteral("mensalInput"));

        gridLayout->addWidget(mensalInput, 12, 0, 1, 1);

        labelValor = new QLabel(createGastos);
        labelValor->setObjectName(QStringLiteral("labelValor"));

        gridLayout->addWidget(labelValor, 7, 0, 1, 1, Qt::AlignLeft);

        dateInput = new QDateEdit(createGastos);
        dateInput->setObjectName(QStringLiteral("dateInput"));
        dateInput->setCursor(QCursor(Qt::ArrowCursor));
        dateInput->setCalendarPopup(true);
        dateInput->setDate(QDate(2000, 1, 1));

        gridLayout->addWidget(dateInput, 6, 0, 1, 1);

        labelData = new QLabel(createGastos);
        labelData->setObjectName(QStringLiteral("labelData"));

        gridLayout->addWidget(labelData, 5, 0, 1, 1);

        createCatGastoButton = new QPushButton(createGastos);
        createCatGastoButton->setObjectName(QStringLiteral("createCatGastoButton"));
        createCatGastoButton->setStyleSheet(QLatin1String("padding:0;\n"
"background-color:none;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Icons/icons8-plus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        createCatGastoButton->setIcon(icon1);
        createCatGastoButton->setIconSize(QSize(25, 25));
        createCatGastoButton->setAutoDefault(false);
        createCatGastoButton->setFlat(true);

        gridLayout->addWidget(createCatGastoButton, 11, 1, 1, 1, Qt::AlignLeft);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(createGastos);

        saveButton->setDefault(false);


        QMetaObject::connectSlotsByName(createGastos);
    } // setupUi

    void retranslateUi(QDialog *createGastos)
    {
        createGastos->setWindowTitle(QApplication::translate("createGastos", "Novo gasto", nullptr));
        labelCate->setText(QApplication::translate("createGastos", "Categoria:", nullptr));
        labelDesc->setText(QApplication::translate("createGastos", "Descri\303\247\303\243o:", nullptr));
        valorInput->setPlaceholderText(QApplication::translate("createGastos", "200.00", nullptr));
        cancelButton->setText(QApplication::translate("createGastos", "Cancelar", nullptr));
        saveButton->setText(QApplication::translate("createGastos", "Salvar", nullptr));
        mensalInput->setText(QApplication::translate("createGastos", "Gasto mensal", nullptr));
        labelValor->setText(QApplication::translate("createGastos", "Valor:", nullptr));
        labelData->setText(QApplication::translate("createGastos", "Data:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createGastos: public Ui_createGastos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEGASTOS_H
