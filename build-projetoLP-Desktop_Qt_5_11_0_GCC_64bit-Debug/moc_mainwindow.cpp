/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Vida Financeira/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[269];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 25), // "on_addGastoButton_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 22), // "on_addCapitais_clicked"
QT_MOC_LITERAL(4, 61, 27), // "on_addInvestimentos_clicked"
QT_MOC_LITERAL(5, 89, 9), // "startUser"
QT_MOC_LITERAL(6, 99, 11), // "startGastos"
QT_MOC_LITERAL(7, 111, 4), // "data"
QT_MOC_LITERAL(8, 116, 14), // "createDivGasto"
QT_MOC_LITERAL(9, 131, 9), // "Categoria"
QT_MOC_LITERAL(10, 141, 3), // "cat"
QT_MOC_LITERAL(11, 145, 3), // "row"
QT_MOC_LITERAL(12, 149, 3), // "col"
QT_MOC_LITERAL(13, 153, 6), // "float*"
QT_MOC_LITERAL(14, 160, 10), // "gastoTotal"
QT_MOC_LITERAL(15, 171, 11), // "startInvest"
QT_MOC_LITERAL(16, 183, 12), // "startCapital"
QT_MOC_LITERAL(17, 196, 17), // "startEstatisticas"
QT_MOC_LITERAL(18, 214, 22), // "on_mesAnterior_clicked"
QT_MOC_LITERAL(19, 237, 20), // "on_mesSeguin_clicked"
QT_MOC_LITERAL(20, 258, 10) // "resetMonth"

    },
    "MainWindow\0on_addGastoButton_clicked\0"
    "\0on_addCapitais_clicked\0"
    "on_addInvestimentos_clicked\0startUser\0"
    "startGastos\0data\0createDivGasto\0"
    "Categoria\0cat\0row\0col\0float*\0gastoTotal\0"
    "startInvest\0startCapital\0startEstatisticas\0"
    "on_mesAnterior_clicked\0on_mesSeguin_clicked\0"
    "resetMonth"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    1,   78,    2, 0x08 /* Private */,
       8,    5,   81,    2, 0x08 /* Private */,
      15,    0,   92,    2, 0x08 /* Private */,
      16,    0,   93,    2, 0x08 /* Private */,
      17,    0,   94,    2, 0x08 /* Private */,
      18,    0,   95,    2, 0x08 /* Private */,
      19,    0,   96,    2, 0x08 /* Private */,
      20,    0,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,    7,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int, QMetaType::Int, 0x80000000 | 13, QMetaType::QDate,   10,   11,   12,   14,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_addGastoButton_clicked(); break;
        case 1: _t->on_addCapitais_clicked(); break;
        case 2: _t->on_addInvestimentos_clicked(); break;
        case 3: _t->startUser(); break;
        case 4: _t->startGastos((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 5: _t->createDivGasto((*reinterpret_cast< Categoria(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< float*(*)>(_a[4])),(*reinterpret_cast< QDate(*)>(_a[5]))); break;
        case 6: _t->startInvest(); break;
        case 7: _t->startCapital(); break;
        case 8: _t->startEstatisticas(); break;
        case 9: _t->on_mesAnterior_clicked(); break;
        case 10: _t->on_mesSeguin_clicked(); break;
        case 11: _t->resetMonth(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
