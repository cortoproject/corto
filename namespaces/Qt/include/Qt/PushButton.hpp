/* include/Qt/PushButton.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::PushButton.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_PushButton_H
#define Qt_PushButton_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/AbstractButton.hpp"

namespace QT {
    class PushButton : public QT::AbstractButton {
        
        // Constructor (new,define)
        public: PushButton(const QT::PaintEvent_t &paintEvent,
                const QT::MouseEvent_t &mousePressEvent,
                 ::hyve::lang::int32 x,
                 ::hyve::lang::int32 y,
                 ::hyve::lang::int32 width,
                 ::hyve::lang::int32 height,
                 ::hyve::lang::_bool enabled,
                 ::hyve::lang::_bool visible,
                 ::hyve::lang::string styleSheet,
                 ::hyve::lang::string text,
                 ::hyve::lang::_bool checkable,
                 ::hyve::lang::_bool down,
                 ::hyve::lang::_bool checked);
        
        // Scoped constructor (declare,define)
        public: PushButton(::hyve::lang::Object *_parent,
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
                 ::hyve::lang::string text,
                 ::hyve::lang::_bool checkable,
                 ::hyve::lang::_bool down,
                 ::hyve::lang::_bool checked);
        
        // Handle constructor
        public: PushButton(QT::pushButton handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::pushButton _handle() const;
        
        // construct(::Qt::PushButton object)
        public: static ::hyve::lang::int16 construct(const QT::PushButton &object);
        
        // destruct(::Qt::PushButton object)
        public: static ::hyve::lang::_void destruct(const QT::PushButton &object);
        
        // onSelf
        public: ::hyve::lang::_void onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
    };
}

#endif

