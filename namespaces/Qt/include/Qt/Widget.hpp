/* include/Qt/Widget.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::Widget.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_Widget_H
#define Qt_Widget_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Object.hpp"
#include "Qt/PaintDevice.hpp"

/* $begin($header) */
        void refresh();
        /* $end */

namespace QT {
    class Widget : public QT::Object {
        
        // Constructor (new,define)
        public: Widget(const QT::PaintEvent_t &paintEvent,
                const QT::MouseEvent_t &mousePressEvent,
                 ::hyve::lang::int32 x,
                 ::hyve::lang::int32 y,
                 ::hyve::lang::int32 width,
                 ::hyve::lang::int32 height,
                 ::hyve::lang::_bool enabled,
                 ::hyve::lang::_bool visible,
                 ::hyve::lang::string styleSheet);
        
        // Scoped constructor (declare,define)
        public: Widget(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                const QT::PaintEvent_t &paintEvent,
                const QT::MouseEvent_t &mousePressEvent,
                 ::hyve::lang::int32 x,
                 ::hyve::lang::int32 y,
                 ::hyve::lang::int32 width,
                 ::hyve::lang::int32 height,
                 ::hyve::lang::_bool enabled,
                 ::hyve::lang::_bool visible,
                 ::hyve::lang::string styleSheet);
        
        // Handle constructor
        public: Widget(QT::widget handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::widget _handle() const;
        
        // ::hyve::lang::bool enabled
        public: ::hyve::lang::_bool enabled() const;
        public: void enabled( ::hyve::lang::_bool v) const;
        
        // ::hyve::lang::int32 height
        public: ::hyve::lang::int32 height() const;
        public: void height( ::hyve::lang::int32 v) const;
        
        // ::Qt::mouseEvent_t mousePressEvent
        public: QT::MouseEvent_t mousePressEvent() const;
        public: void mousePressEvent(const QT::MouseEvent_t &v) const;
        
        // ::Qt::Painter painter
        public: QT::Painter painter() const;
        public: void painter(const QT::Painter &v) const;
        
        // ::Qt::paintEvent_t paintEvent
        public: QT::PaintEvent_t paintEvent() const;
        public: void paintEvent(const QT::PaintEvent_t &v) const;
        
        // ::hyve::lang::word qslots
        public: ::hyve::lang::word qslots() const;
        public: void qslots( ::hyve::lang::word v) const;
        
        // ::hyve::lang::string styleSheet
        public: ::hyve::lang::string styleSheet() const;
        public: void styleSheet( ::hyve::lang::string v) const;
        
        // ::hyve::lang::bool visible
        public: ::hyve::lang::_bool visible() const;
        public: void visible( ::hyve::lang::_bool v) const;
        
        // ::hyve::lang::int32 width
        public: ::hyve::lang::int32 width() const;
        public: void width( ::hyve::lang::int32 v) const;
        
        // ::hyve::lang::int32 x
        public: ::hyve::lang::int32 x() const;
        public: void x( ::hyve::lang::int32 v) const;
        
        // ::hyve::lang::int32 y
        public: ::hyve::lang::int32 y() const;
        public: void y( ::hyve::lang::int32 v) const;
        
        // construct(::Qt::Widget object)
        public: static ::hyve::lang::int16 construct(const QT::Widget &object);
        
        // destruct(::Qt::Widget object)
        public: static ::hyve::lang::_void destruct(const QT::Widget &object);
        
        // hide()
        public: ::hyve::lang::_void hide() const;
        
        // init(::Qt::Widget object)
        public: static ::hyve::lang::int16 init(const QT::Widget &object);
        
        // repaint()
        public: ::hyve::lang::_void repaint() const;
        
        // show()
        public: ::hyve::lang::_void show() const;
        /* $begin($classfooter) */
        void refresh(bool move = true) const;
        /* $end */
    };
}

#endif

