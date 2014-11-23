/* include/Qt/GroupBox.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::GroupBox.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_GroupBox_H
#define Qt_GroupBox_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Widget.hpp"

namespace QT {
    class GroupBox : public QT::Widget {
        
        // Constructor (new,define)
        public: GroupBox(const QT::PaintEvent_t &paintEvent,
                const QT::MouseEvent_t &mousePressEvent,
                 ::hyve::lang::int32 x,
                 ::hyve::lang::int32 y,
                 ::hyve::lang::int32 width,
                 ::hyve::lang::int32 height,
                 ::hyve::lang::_bool enabled,
                 ::hyve::lang::_bool visible,
                 ::hyve::lang::string styleSheet,
                 ::hyve::lang::string title);
        
        // Scoped constructor (declare,define)
        public: GroupBox(::hyve::lang::Object *_parent,
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
                 ::hyve::lang::string title);
        
        // Handle constructor
        public: GroupBox(QT::groupBox handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::groupBox _handle() const;
        
        // ::hyve::lang::string title
        public: ::hyve::lang::string title() const;
        public: void title( ::hyve::lang::string v) const;
        
        // construct(::Qt::GroupBox object)
        public: static ::hyve::lang::int16 construct(const QT::GroupBox &object);
        
        // destruct(::Qt::GroupBox object)
        public: static ::hyve::lang::_void destruct(const QT::GroupBox &object);
    };
}

#endif

