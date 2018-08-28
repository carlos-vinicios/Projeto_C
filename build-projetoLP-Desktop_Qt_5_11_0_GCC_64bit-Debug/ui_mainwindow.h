/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *userInfosGrid;
    QGridLayout *mesSelections;
    QLabel *labelMes;
    QPushButton *mesAnterior;
    QPushButton *mesSeguin;
    QTabWidget *tabWidget;
    QWidget *tabGasto;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *layoutGastos;
    QGridLayout *gridLayoutGasto;
    QGridLayout *gridLayoutControlButtons;
    QPushButton *addGastoButton;
    QWidget *tabInvestimentos;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *layoutInvestimentos;
    QPushButton *addInvestimentos;
    QWidget *tabCapitais;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *layoutCapitais;
    QPushButton *addCapitais;
    QWidget *tabEstatisticas;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayoutEstatisticas;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(757, 354);
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setPointSize(12);
        MainWindow->setFont(font);
        MainWindow->setMouseTracking(false);
        MainWindow->setAcceptDrops(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icons/main_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setAutoFillBackground(true);
        MainWindow->setStyleSheet(QLatin1String("#MainWindow{\n"
"visibility: \"Maximized\";\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        centralWidget->setAutoFillBackground(true);
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        userInfosGrid = new QGridLayout();
        userInfosGrid->setSpacing(6);
        userInfosGrid->setObjectName(QStringLiteral("userInfosGrid"));
        userInfosGrid->setSizeConstraint(QLayout::SetFixedSize);

        verticalLayout->addLayout(userInfosGrid);

        mesSelections = new QGridLayout();
        mesSelections->setSpacing(6);
        mesSelections->setObjectName(QStringLiteral("mesSelections"));
        mesSelections->setContentsMargins(-1, 20, -1, 20);
        labelMes = new QLabel(centralWidget);
        labelMes->setObjectName(QStringLiteral("labelMes"));
        QFont font1;
        labelMes->setFont(font1);
        labelMes->setStyleSheet(QLatin1String("QLabel{\n"
"	color:rgb(255, 105, 46);\n"
"	text-transform: uppercase;\n"
"	font-size: 28px;\n"
"	font-weight: 2px;\n"
"}"));
        labelMes->setTextFormat(Qt::PlainText);
        labelMes->setAlignment(Qt::AlignCenter);

        mesSelections->addWidget(labelMes, 0, 1, 1, 1, Qt::AlignHCenter);

        mesAnterior = new QPushButton(centralWidget);
        mesAnterior->setObjectName(QStringLiteral("mesAnterior"));
        mesAnterior->setMinimumSize(QSize(46, 46));
        mesAnterior->setCursor(QCursor(Qt::PointingHandCursor));
        mesAnterior->setStyleSheet(QLatin1String("#mesAnterior{\n"
"	background-color: rgb(255, 155, 88);\n"
"	border-style: solid;\n"
"	border-radius:23px;\n"
"	max-width:46px;\n"
"	max-height:46px;\n"
"	min-width:46px;\n"
"	min-height:46px;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Icons/if_previous_308957.png"), QSize(), QIcon::Normal, QIcon::Off);
        mesAnterior->setIcon(icon1);
        mesAnterior->setIconSize(QSize(35, 35));
        mesAnterior->setAutoDefault(false);
        mesAnterior->setFlat(true);

        mesSelections->addWidget(mesAnterior, 0, 0, 1, 1, Qt::AlignRight);

        mesSeguin = new QPushButton(centralWidget);
        mesSeguin->setObjectName(QStringLiteral("mesSeguin"));
        mesSeguin->setMinimumSize(QSize(46, 46));
        QFont font2;
        font2.setPointSize(12);
        mesSeguin->setFont(font2);
        mesSeguin->setCursor(QCursor(Qt::PointingHandCursor));
        mesSeguin->setStyleSheet(QLatin1String("background-color: rgb(255, 155, 88);\n"
"border-style: solid;\n"
"border-radius:23px;\n"
"max-width:46px;\n"
"max-height:46px;\n"
"min-width:46px;\n"
"min-height:46px;"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Icons/if_next_308956.png"), QSize(), QIcon::Normal, QIcon::Off);
        mesSeguin->setIcon(icon2);
        mesSeguin->setIconSize(QSize(35, 35));
        mesSeguin->setFlat(true);

        mesSelections->addWidget(mesSeguin, 0, 2, 1, 1, Qt::AlignLeft);


        verticalLayout->addLayout(mesSelections);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QLatin1String("::tab:selected {\n"
"    background-color: rgb(255, 105, 46);\n"
"	color:#FFF;\n"
"}\n"
"::tab {\n"
"	color:#FFF;\n"
"	background-color: rgb(255, 155, 88);\n"
"	border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"	padding: 2px 15px;\n"
"}\n"
"::tab:hover {\n"
"  background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #ff9b58, stop: 0.4 #ff7037,\n"
"                                stop: 0.5 #ff7037, stop: 1.0 #ff9b58);\n"
"}"));
        tabGasto = new QWidget();
        tabGasto->setObjectName(QStringLiteral("tabGasto"));
        verticalLayout_3 = new QVBoxLayout(tabGasto);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        layoutGastos = new QGridLayout();
        layoutGastos->setSpacing(6);
        layoutGastos->setObjectName(QStringLiteral("layoutGastos"));
        gridLayoutGasto = new QGridLayout();
        gridLayoutGasto->setSpacing(6);
        gridLayoutGasto->setObjectName(QStringLiteral("gridLayoutGasto"));

        layoutGastos->addLayout(gridLayoutGasto, 2, 0, 1, 1);

        gridLayoutControlButtons = new QGridLayout();
        gridLayoutControlButtons->setSpacing(6);
        gridLayoutControlButtons->setObjectName(QStringLiteral("gridLayoutControlButtons"));
        addGastoButton = new QPushButton(tabGasto);
        addGastoButton->setObjectName(QStringLiteral("addGastoButton"));
        addGastoButton->setFont(font);
        addGastoButton->setCursor(QCursor(Qt::PointingHandCursor));
        addGastoButton->setLayoutDirection(Qt::RightToLeft);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Icons/icons8-plus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        addGastoButton->setIcon(icon3);
        addGastoButton->setIconSize(QSize(40, 40));
        addGastoButton->setFlat(true);

        gridLayoutControlButtons->addWidget(addGastoButton, 0, 3, 1, 1, Qt::AlignLeft);


        layoutGastos->addLayout(gridLayoutControlButtons, 1, 0, 1, 1);


        verticalLayout_3->addLayout(layoutGastos);

        tabWidget->addTab(tabGasto, QString());
        tabInvestimentos = new QWidget();
        tabInvestimentos->setObjectName(QStringLiteral("tabInvestimentos"));
        verticalLayout_4 = new QVBoxLayout(tabInvestimentos);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        layoutInvestimentos = new QGridLayout();
        layoutInvestimentos->setSpacing(6);
        layoutInvestimentos->setObjectName(QStringLiteral("layoutInvestimentos"));
        addInvestimentos = new QPushButton(tabInvestimentos);
        addInvestimentos->setObjectName(QStringLiteral("addInvestimentos"));
        addInvestimentos->setFont(font);
        addInvestimentos->setLayoutDirection(Qt::RightToLeft);
        addInvestimentos->setIcon(icon3);
        addInvestimentos->setIconSize(QSize(40, 40));
        addInvestimentos->setFlat(true);

        layoutInvestimentos->addWidget(addInvestimentos, 0, 0, 1, 1, Qt::AlignLeft);


        verticalLayout_4->addLayout(layoutInvestimentos);

        tabWidget->addTab(tabInvestimentos, QString());
        tabCapitais = new QWidget();
        tabCapitais->setObjectName(QStringLiteral("tabCapitais"));
        tabCapitais->setFont(font);
        verticalLayout_5 = new QVBoxLayout(tabCapitais);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        layoutCapitais = new QGridLayout();
        layoutCapitais->setSpacing(6);
        layoutCapitais->setObjectName(QStringLiteral("layoutCapitais"));
        addCapitais = new QPushButton(tabCapitais);
        addCapitais->setObjectName(QStringLiteral("addCapitais"));
        addCapitais->setFont(font);
        addCapitais->setLayoutDirection(Qt::RightToLeft);
        addCapitais->setIcon(icon3);
        addCapitais->setIconSize(QSize(40, 40));
        addCapitais->setFlat(true);

        layoutCapitais->addWidget(addCapitais, 0, 0, 1, 1, Qt::AlignLeft);


        verticalLayout_5->addLayout(layoutCapitais);

        tabWidget->addTab(tabCapitais, QString());
        tabEstatisticas = new QWidget();
        tabEstatisticas->setObjectName(QStringLiteral("tabEstatisticas"));
        tabEstatisticas->setFont(font);
        verticalLayout_2 = new QVBoxLayout(tabEstatisticas);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayoutEstatisticas = new QGridLayout();
        gridLayoutEstatisticas->setSpacing(0);
        gridLayoutEstatisticas->setObjectName(QStringLiteral("gridLayoutEstatisticas"));
        gridLayoutEstatisticas->setSizeConstraint(QLayout::SetMinAndMaxSize);

        verticalLayout_2->addLayout(gridLayoutEstatisticas);

        tabWidget->addTab(tabEstatisticas, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        mesAnterior->setDefault(false);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Vida Financeira", nullptr));
        labelMes->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        addGastoButton->setText(QApplication::translate("MainWindow", "Adicionar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabGasto), QApplication::translate("MainWindow", "Gastos", nullptr));
        addInvestimentos->setText(QApplication::translate("MainWindow", "Adicionar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabInvestimentos), QApplication::translate("MainWindow", "Investimentos", nullptr));
        addCapitais->setText(QApplication::translate("MainWindow", "Adicionar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabCapitais), QApplication::translate("MainWindow", "Capitais", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabEstatisticas), QApplication::translate("MainWindow", "Estat\303\255sticas", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
