/****************************************************************************
** Meta object code from reading C++ file 'Slider.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "include/Qt/Slider.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Slider.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QT__SliderSlots[] = {

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
      23,   17,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QT__SliderSlots[] = {
    "QT::SliderSlots\0\0value\0sliderMoved(int)\0"
};

void QT::SliderSlots::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SliderSlots *_t = static_cast<SliderSlots *>(_o);
        switch (_id) {
        case 0: _t->sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QT::SliderSlots::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QT::SliderSlots::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QT__SliderSlots,
      qt_meta_data_QT__SliderSlots, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QT::SliderSlots::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QT::SliderSlots::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QT::SliderSlots::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QT__SliderSlots))
        return static_cast<void*>(const_cast< SliderSlots*>(this));
    if (!strcmp(_clname, "SlotBase"))
        return static_cast< SlotBase*>(const_cast< SliderSlots*>(this));
    return QObject::qt_metacast(_clname);
}

int QT::SliderSlots::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
