/* include/Qt/ProgressBar.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::ProgressBar.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_ProgressBar_H
#define Qt_ProgressBar_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Widget.hpp"

namespace QT {
    class ProgressBar : public QT::Widget {
        
        // Constructor (new,define)
        public: ProgressBar(const QT::PaintEvent_t &paintEvent,
                const QT::MouseEvent_t &mousePressEvent,
                 ::hyve::lang::int32 x,
                 ::hyve::lang::int32 y,
                 ::hyve::lang::int32 width,
                 ::hyve::lang::int32 height,
                 ::hyve::lang::_bool enabled,
                 ::hyve::lang::_bool visible,
                 ::hyve::lang::string styleSheet,
                 ::hyve::lang::int32 minimum,
                 ::hyve::lang::int32 maximum,
                 ::hyve::lang::int32 value,
                 QT::Orientation orientation,
                 ::hyve::lang::string text,
                 ::hyve::lang::string format);
        
        // Scoped constructor (declare,define)
        public: ProgressBar(::hyve::lang::Object *_parent,
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
                 ::hyve::lang::int32 minimum,
                 ::hyve::lang::int32 maximum,
                 ::hyve::lang::int32 value,
                 QT::Orientation orientation,
                 ::hyve::lang::string text,
                 ::hyve::lang::string format);
        
        // Handle constructor
        public: ProgressBar(QT::progressBar handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::progressBar _handle() const;
        
        // ::hyve::lang::string format
        public: ::hyve::lang::string format() const;
        public: void format( ::hyve::lang::string v) const;
        
        // ::hyve::lang::int32 maximum
        public: ::hyve::lang::int32 maximum() const;
        public: void maximum( ::hyve::lang::int32 v) const;
        
        // ::hyve::lang::int32 minimum
        public: ::hyve::lang::int32 minimum() const;
        public: void minimum( ::hyve::lang::int32 v) const;
        
        // ::Qt::Orientation orientation
        public: QT::Orientation orientation() const;
        public: void orientation( QT::Orientation v) const;
        
        // ::hyve::lang::string text
        public: ::hyve::lang::string text() const;
        public: void text( ::hyve::lang::string v) const;
        
        // ::hyve::lang::int32 value
        public: ::hyve::lang::int32 value() const;
        public: void value( ::hyve::lang::int32 v) const;
        
        // construct(::Qt::ProgressBar object)
        public: static ::hyve::lang::int16 construct(const QT::ProgressBar &object);
        
        // destruct(::Qt::ProgressBar object)
        public: static ::hyve::lang::_void destruct(const QT::ProgressBar &object);
        
        // onSelf
        public: ::hyve::lang::_void onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
        /* $begin($classfooter) */
        void refresh() const;
        /* $end */
    };
}

#endif

