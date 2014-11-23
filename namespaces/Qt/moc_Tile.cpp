/****************************************************************************
** Meta object code from reading C++ file 'Tile.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "include/Qt/Tile.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Tile.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QT__QTTile[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       4,   29, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      28,   11,   11,   11, 0x0a,
      47,   11,   11,   11, 0x0a,

 // properties: name, type, flags
      73,   67, 0x87095103,
      86,   79, 0x43095103,
     102,   79, 0x43095103,
     114,   79, 0x43095103,

       0        // eod
};

static const char qt_meta_stringdata_QT__QTTile[] = {
    "QT::QTTile\0\0resizeTimeout()\0"
    "finishedMoveAnim()\0finishedColorAnim()\0"
    "float\0fader\0QColor\0actualTextColor\0"
    "actualColor\0actualTitleBarColor\0"
};

void QT::QTTile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QTTile *_t = static_cast<QTTile *>(_o);
        switch (_id) {
        case 0: _t->resizeTimeout(); break;
        case 1: _t->finishedMoveAnim(); break;
        case 2: _t->finishedColorAnim(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QT::QTTile::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QT::QTTile::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QT__QTTile,
      qt_meta_data_QT__QTTile, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QT::QTTile::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QT::QTTile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QT::QTTile::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QT__QTTile))
        return static_cast<void*>(const_cast< QTTile*>(this));
    return QWidget::qt_metacast(_clname);
}

int QT::QTTile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< float*>(_v) = getFader(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = getActualTextColor(); break;
        case 2: *reinterpret_cast< QColor*>(_v) = getActualColor(); break;
        case 3: *reinterpret_cast< QColor*>(_v) = getActualTitleBarColor(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setFader(*reinterpret_cast< float*>(_v)); break;
        case 1: setActualTextColor(*reinterpret_cast< QColor*>(_v)); break;
        case 2: setActualColor(*reinterpret_cast< QColor*>(_v)); break;
        case 3: setActualTitleBarColor(*reinterpret_cast< QColor*>(_v)); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
