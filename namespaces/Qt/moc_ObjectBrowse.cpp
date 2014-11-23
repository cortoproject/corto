/****************************************************************************
** Meta object code from reading C++ file 'ObjectBrowse.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "include/Qt/ObjectBrowse.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ObjectBrowse.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QT__ObjectBrowseSlots[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      34,   23,   22,   22, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QT__ObjectBrowseSlots[] = {
    "QT::ObjectBrowseSlots\0\0item,index\0"
    "itemActivated(QTreeWidgetItem*,int)\0"
};

void QT::ObjectBrowseSlots::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ObjectBrowseSlots *_t = static_cast<ObjectBrowseSlots *>(_o);
        switch (_id) {
        case 0: _t->itemActivated((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QT::ObjectBrowseSlots::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QT::ObjectBrowseSlots::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QT__ObjectBrowseSlots,
      qt_meta_data_QT__ObjectBrowseSlots, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QT::ObjectBrowseSlots::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QT::ObjectBrowseSlots::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QT::ObjectBrowseSlots::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QT__ObjectBrowseSlots))
        return static_cast<void*>(const_cast< ObjectBrowseSlots*>(this));
    if (!strcmp(_clname, "SlotBase"))
        return static_cast< SlotBase*>(const_cast< ObjectBrowseSlots*>(this));
    return QObject::qt_metacast(_clname);
}

int QT::ObjectBrowseSlots::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
