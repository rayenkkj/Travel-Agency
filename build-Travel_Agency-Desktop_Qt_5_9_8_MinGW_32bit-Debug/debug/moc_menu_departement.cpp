/****************************************************************************
** Meta object code from reading C++ file 'menu_departement.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Travel_Agency/menu_departement.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menu_departement.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Menu_departement_t {
    QByteArrayData data[10];
    char stringdata0[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Menu_departement_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Menu_departement_t qt_meta_stringdata_Menu_departement = {
    {
QT_MOC_LITERAL(0, 0, 16), // "Menu_departement"
QT_MOC_LITERAL(1, 17, 21), // "on_Supprimer2_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 19), // "on_Ajouter2_clicked"
QT_MOC_LITERAL(4, 60, 20), // "on_Modifier2_clicked"
QT_MOC_LITERAL(5, 81, 22), // "on_rechercherd_clicked"
QT_MOC_LITERAL(6, 104, 30), // "on_afficherdepartement_clicked"
QT_MOC_LITERAL(7, 135, 18), // "on_pb_back_clicked"
QT_MOC_LITERAL(8, 154, 24), // "on_affichertrie2_clicked"
QT_MOC_LITERAL(9, 179, 15) // "on_next_clicked"

    },
    "Menu_departement\0on_Supprimer2_clicked\0"
    "\0on_Ajouter2_clicked\0on_Modifier2_clicked\0"
    "on_rechercherd_clicked\0"
    "on_afficherdepartement_clicked\0"
    "on_pb_back_clicked\0on_affichertrie2_clicked\0"
    "on_next_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Menu_departement[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Menu_departement::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Menu_departement *_t = static_cast<Menu_departement *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Supprimer2_clicked(); break;
        case 1: _t->on_Ajouter2_clicked(); break;
        case 2: _t->on_Modifier2_clicked(); break;
        case 3: _t->on_rechercherd_clicked(); break;
        case 4: _t->on_afficherdepartement_clicked(); break;
        case 5: _t->on_pb_back_clicked(); break;
        case 6: _t->on_affichertrie2_clicked(); break;
        case 7: _t->on_next_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Menu_departement::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Menu_departement.data,
      qt_meta_data_Menu_departement,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Menu_departement::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Menu_departement::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Menu_departement.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Menu_departement::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
