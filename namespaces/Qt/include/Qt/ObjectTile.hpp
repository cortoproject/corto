/* include/Qt/ObjectTile.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::ObjectTile.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_ObjectTile_H
#define Qt_ObjectTile_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Tile.hpp"

namespace QT {
    class ObjectTile : public QT::Tile {
        
        // Constructor (new,define)
        public: ObjectTile(const QT::PaintEvent_t &paintEvent,
                const QT::MouseEvent_t &mousePressEvent,
                 ::hyve::lang::int32 x,
                 ::hyve::lang::int32 y,
                 ::hyve::lang::int32 width,
                 ::hyve::lang::int32 height,
                 ::hyve::lang::_bool enabled,
                 ::hyve::lang::_bool visible,
                 ::hyve::lang::string styleSheet,
                 ::hyve::lang::string title,
                 QT::Color textColor,
                 QT::Color foregroundColor,
                 QT::Color backgroundColor,
                 QT::TileMode mode,
                 ::hyve::lang::string scope,
                 ::hyve::lang::word scopeCache);
        
        // Scoped constructor (declare,define)
        public: ObjectTile(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                const QT::PaintEvent_t &paintEvent,
                const QT::MouseEvent_t &mousePressEvent,
                 ::hyve::lang::int32 x,
                 ::hyve::lang::int32 y,
                 ::hyve::lang::int32 width,
                 ::hyve::lang::int32 height,
                 ::hyve::lang::_bool enabled,
                 ::hyve::lang::_bool visible,
                 ::hyve::lang::string styleSheet,
                 ::hyve::lang::string title,
                 QT::Color textColor,
                 QT::Color foregroundColor,
                 QT::Color backgroundColor,
                 QT::TileMode mode,
                 ::hyve::lang::string scope,
                 ::hyve::lang::word scopeCache);
        
        // Handle constructor
        public: ObjectTile(QT::objectTile handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::objectTile _handle() const;
        
        // ::hyve::lang::string scope
        public: ::hyve::lang::string scope() const;
        public: void scope( ::hyve::lang::string v) const;
        
        // ::hyve::lang::word scopeCache
        public: ::hyve::lang::word scopeCache() const;
        public: void scopeCache( ::hyve::lang::word v) const;
        
        // construct(::Qt::ObjectTile object)
        public: static ::hyve::lang::int16 construct(const QT::ObjectTile &object);
        
        // createTile(::hyve::lang::object obj)
        public: QT::ObjectTile createTile(const ::hyve::lang::Object &obj) const;
        public: QT::ObjectTile createTile_v(const ::hyve::lang::Object &obj) const;
        
        // destruct(::Qt::ObjectTile object)
        public: static ::hyve::lang::_void destruct(const QT::ObjectTile &object);
        
        // onDestruct
        public: ::hyve::lang::_void onDestruct(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
        
        // onNew
        public: ::hyve::lang::_void onNew(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
    };
}

#endif

