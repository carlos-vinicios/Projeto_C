/********************************************************************************
** Form generated from reading UI file 'createcatgasto.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECATGASTO_H
#define UI_CREATECATGASTO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateCatGasto
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *cancelarButton;
    QPushButton *salvarButton;
    QLineEdit *nomeInput;
    QLabel *labelCatNome;

    void setupUi(QWidget *CreateCatGasto)
    {
        if (CreateCatGasto->objectName().isEmpty())
            CreateCatGasto->setObjectName(QStringLiteral("CreateCatGasto"));
        CreateCatGasto->setWindowModality(Qt::WindowModal);
        CreateCatGasto->resize(280, 117);
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setPointSize(12);
        CreateCatGasto->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Downloads/main_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        CreateCatGasto->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(CreateCatGasto);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(3);
        gridLayout->setVerticalSpacing(6);
        cancelarButton = new QPushButton(CreateCatGasto);
        cancelarButton->setObjectName(QStringLiteral("cancelarButton"));
        cancelarButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(cancelarButton, 2, 1, 1, 1, Qt::AlignLeft);

        salvarButton = new QPushButton(CreateCatGasto);
        salvarButton->setObjectName(QStringLiteral("salvarButton"));
        salvarButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(salvarButton, 2, 0, 1, 1, Qt::AlignRight);

        nomeInput = new QLineEdit(CreateCatGasto);
        nomeInput->setObjectName(QStringLiteral("nomeInput"));

        gridLayout->addWidget(nomeInput, 1, 0, 1, 2);

        labelCatNome = new QLabel(CreateCatGasto);
        labelCatNome->setObjectName(QStringLiteral("labelCatNome"));

        gridLayout->addWidget(labelCatNome, 0, 0, 1, 2, Qt::AlignLeft|Qt::AlignVCenter);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(CreateCatGasto);

        QMetaObject::connectSlotsByName(CreateCatGasto);
    } // setupUi

    void retranslateUi(QWidget *CreateCatGasto)
    {
        CreateCatGasto->setWindowTitle(QApplication::translate("CreateCatGasto", "Nova Categoria", nullptr));
        cancelarButton->setText(QApplication::translate("CreateCatGasto", "Cancelar", nullptr));
        salvarButton->setText(QApplication::translate("CreateCatGasto", "Salvar", nullptr));
        labelCatNome->setText(QApplication::translate("CreateCatGasto", "Nome da categoria:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateCatGasto: public Ui_CreateCatGasto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECATGASTO_H
