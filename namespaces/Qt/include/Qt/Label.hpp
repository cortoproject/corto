/* include/Qt/Label.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::Label.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_Label_H
#define Qt_Label_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Widget.hpp"

namespace QT {
    class Label : public QT::Widget {
        
        // Constructor (new,define)
        public: Label(const QT::PaintEvent_t &paintEvent,
                const QT::MouseEvent_t &mousePressEvent,
                 ::hyve::lang::int32 x,
                 ::hyve::lang::int32 y,
                 ::hyve::lang::int32 width,
                 ::hyve::lang::int32 height,
                 ::hyve::lang::_bool enabled,
                 ::hyve::lang::_bool visible,
                 ::hyve::lang::string styleSheet,
                 ::hyve::lang::string text,
                 QT::Alignment alignment);
        
        // Scoped constructor (declare,define)
        public: Label(::hyve::lang::Object *_parent,
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
                 QT::Alignment alignment);
        
        // Handle constructor
        public: Label(QT::label handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::label _handle() const;
        
        // ::Qt::Alignment alignment
        public: QT::Alignment alignment() const;
        public: void alignment( QT::Alignment v) const;
        
        // ::hyve::lang::string text
        public: ::hyve::lang::string text() const;
        public: void text( ::hyve::lang::string v) const;
        
        // construct(::Qt::Label object)
        public: static ::hyve::lang::int16 construct(const QT::Label &object);
        
        // destruct(::Qt::Label object)
        public: static ::hyve::lang::_void destruct(const QT::Label &object);
        
        // init(::Qt::Label object)
        public: static ::hyve::lang::int16 init(const QT::Label &object);
        
        // onSelf
        public: ::hyve::lang::_void onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
        
        // setText(::hyve::lang::string text)
        public: ::hyve::lang::_void setText(::hyve::lang::string text) const;
        /* $begin($classfooter) */
        void refresh() const;
        /* $end */
    };
}

#endif

