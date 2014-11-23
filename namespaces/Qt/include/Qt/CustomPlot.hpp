/* include/Qt/CustomPlot.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::CustomPlot.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_CustomPlot_H
#define Qt_CustomPlot_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Widget.hpp"

namespace QT {
    class CustomPlot : public QT::Widget {
        
        // Constructor (new,define)
        public: CustomPlot(const QT::PaintEvent_t &paintEvent,
                const QT::MouseEvent_t &mousePressEvent,
                 ::hyve::lang::int32 x,
                 ::hyve::lang::int32 y,
                 ::hyve::lang::int32 width,
                 ::hyve::lang::int32 height,
                 ::hyve::lang::_bool enabled,
                 ::hyve::lang::_bool visible,
                 ::hyve::lang::string styleSheet,
                const ::hyve::lang::Object &object,
                 ::hyve::lang::string expr,
                 ::hyve::lang::uint32 autoX);
        
        // Scoped constructor (declare,define)
        public: CustomPlot(::hyve::lang::Object *_parent,
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
                const ::hyve::lang::Object &object,
                 ::hyve::lang::string expr,
                 ::hyve::lang::uint32 autoX);
        
        // Handle constructor
        public: CustomPlot(QT::customPlot handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::customPlot _handle() const;
        
        // ::hyve::lang::uint32 autoX
        public: ::hyve::lang::uint32 autoX() const;
        public: void autoX( ::hyve::lang::uint32 v) const;
        
        // ::hyve::lang::string expr
        public: ::hyve::lang::string expr() const;
        public: void expr( ::hyve::lang::string v) const;
        
        // ::hyve::lang::object object
        public: ::hyve::lang::Object object() const;
        public: void object(const ::hyve::lang::Object &v) const;
        
        // construct(::Qt::CustomPlot object)
        public: static ::hyve::lang::int16 construct(const QT::CustomPlot &object);
        
        // destruct(::Qt::CustomPlot object)
        public: static ::hyve::lang::int16 destruct(const QT::CustomPlot &object);
        
        // init(::Qt::CustomPlot object)
        public: static ::hyve::lang::int16 init(const QT::CustomPlot &object);
        
        // onDestruct
        public: ::hyve::lang::_void onDestruct(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
        
        // onSelf
        public: ::hyve::lang::_void onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
        
        // onUpdate
        public: ::hyve::lang::_void onUpdate(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
        /* $begin($classfooter) */
        void refresh() const;
        /* $end */
    };
}

#endif

