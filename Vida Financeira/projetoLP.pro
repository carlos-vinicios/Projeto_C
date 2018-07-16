#-------------------------------------------------
#
# Project created by QtCreator 2018-05-11T00:40:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projetoLP
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    capital.cpp \
    categoria.cpp \
    datacontrol.cpp \
    filemanager.cpp \
    gasto.cpp \
    investimento.cpp \
    user.cpp \
    creategastos.cpp \
    createuser.cpp \
    createcatgasto.cpp \
    createcapital.cpp \
    createinvestimento.cpp

HEADERS += \
        mainwindow.h \
    capital.h \
    categoria.h \
    datacontrol.h \
    filemanager.h \
    gasto.h \
    investimento.h \
    user.h \
    creategastos.h \
    createuser.h \
    createcatgasto.h \
    createcapital.h \
    createinvestimento.h

FORMS += \
        mainwindow.ui \
    creategastos.ui \
    createuser.ui \
    createcatgasto.ui \
    createcapital.ui \
    createinvestimento.ui

RESOURCES += \
    icons.qrc

DISTFILES += \
    ../../../../Downloads/download (1).jpg
