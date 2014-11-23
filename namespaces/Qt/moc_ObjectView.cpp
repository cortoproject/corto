/****************************************************************************
** Meta object code from reading C++ file 'ObjectView.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "include/Qt/ObjectView.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ObjectView.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QT__ObjectViewSlots[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,   21,   20,   20, 0x0a,
      63,   21,   20,   20, 0x0a,
     122,   94,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QT__ObjectViewSlots[] = {
    "QT::ObjectViewSlots\0\0item\0"
    "itemDoubleClicked(QTableWidgetItem*)\0"
    "itemClicked(QTableWidgetItem*)\0"
    "oldRow,oldColumn,row,column\0"
    "cellEntered(int,int,int,int)\0"
};

void QT::ObjectViewSlots::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ObjectViewSlots *_t = static_cast<ObjectViewSlots *>(_o);
        switch (_id) {
        case 0: _t->itemDoubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->itemClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->cellEntered((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QT::ObjectViewSlots::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QT::ObjectViewSlots::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QT__ObjectViewSlots,
      qt_meta_data_QT__ObjectViewSlots, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QT::ObjectViewSlots::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QT::ObjectViewSlots::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QT::ObjectViewSlots::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QT__ObjectViewSlots))
        return static_cast<void*>(const_cast< ObjectViewSlots*>(this));
    if (!strcmp(_clname, "SlotBase"))
        return static_cast< SlotBase*>(const_cast< ObjectViewSlots*>(this));
    return QObject::qt_metacast(_clname);
}

int QT::ObjectViewSlots::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
