/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[354];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 32), // "on_pushButton_Platzieren_clicked"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 27), // "on_pushButton_Start_clicked"
QT_MOC_LITERAL(4, 73, 29), // "on_pushButton_Schritt_clicked"
QT_MOC_LITERAL(5, 103, 27), // "on_pushButton_Pause_clicked"
QT_MOC_LITERAL(6, 131, 13), // "keyPressEvent"
QT_MOC_LITERAL(7, 145, 10), // "QKeyEvent*"
QT_MOC_LITERAL(8, 156, 8), // "keyEvent"
QT_MOC_LITERAL(9, 165, 17), // "schrittZahlUpdate"
QT_MOC_LITERAL(10, 183, 16), // "strength_Updated"
QT_MOC_LITERAL(11, 200, 13), // "speed_Updated"
QT_MOC_LITERAL(12, 214, 12), // "life_Updated"
QT_MOC_LITERAL(13, 227, 18), // "properties_Updated"
QT_MOC_LITERAL(14, 246, 13), // "buildNoisemap"
QT_MOC_LITERAL(15, 260, 6), // "action"
QT_MOC_LITERAL(16, 267, 19), // "wachsenVorbedingung"
QT_MOC_LITERAL(17, 287, 6), // "Being&"
QT_MOC_LITERAL(18, 294, 1), // "b"
QT_MOC_LITERAL(19, 296, 19), // "paarungVorbedingung"
QT_MOC_LITERAL(20, 316, 17), // "jagenVorbedingung"
QT_MOC_LITERAL(21, 334, 19) // "angriffVorbedingung"

    },
    "MainWindow\0on_pushButton_Platzieren_clicked\0"
    "\0on_pushButton_Start_clicked\0"
    "on_pushButton_Schritt_clicked\0"
    "on_pushButton_Pause_clicked\0keyPressEvent\0"
    "QKeyEvent*\0keyEvent\0schrittZahlUpdate\0"
    "strength_Updated\0speed_Updated\0"
    "life_Updated\0properties_Updated\0"
    "buildNoisemap\0action\0wachsenVorbedingung\0"
    "Being&\0b\0paarungVorbedingung\0"
    "jagenVorbedingung\0angriffVorbedingung"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    1,   98,    2, 0x08 /* Private */,
       9,    0,  101,    2, 0x08 /* Private */,
      10,    1,  102,    2, 0x08 /* Private */,
      11,    1,  105,    2, 0x08 /* Private */,
      12,    1,  108,    2, 0x08 /* Private */,
      13,    1,  111,    2, 0x08 /* Private */,
      14,    0,  114,    2, 0x08 /* Private */,
      15,    0,  115,    2, 0x08 /* Private */,
      16,    1,  116,    2, 0x08 /* Private */,
      19,    1,  119,    2, 0x08 /* Private */,
      20,    1,  122,    2, 0x08 /* Private */,
      21,    1,  125,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 17,   18,
    QMetaType::Bool, 0x80000000 | 17,   18,
    QMetaType::Bool, 0x80000000 | 17,   18,
    QMetaType::Bool, 0x80000000 | 17,   18,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_Platzieren_clicked(); break;
        case 1: _t->on_pushButton_Start_clicked(); break;
        case 2: _t->on_pushButton_Schritt_clicked(); break;
        case 3: _t->on_pushButton_Pause_clicked(); break;
        case 4: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 5: _t->schrittZahlUpdate(); break;
        case 6: _t->strength_Updated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->speed_Updated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->life_Updated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->properties_Updated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->buildNoisemap(); break;
        case 11: _t->action(); break;
        case 12: { bool _r = _t->wachsenVorbedingung((*reinterpret_cast< Being(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 13: { bool _r = _t->paarungVorbedingung((*reinterpret_cast< Being(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 14: { bool _r = _t->jagenVorbedingung((*reinterpret_cast< Being(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 15: { bool _r = _t->angriffVorbedingung((*reinterpret_cast< Being(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
