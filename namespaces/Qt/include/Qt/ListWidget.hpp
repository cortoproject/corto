/* include/Qt/ListWidget.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::ListWidget.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_ListWidget_H
#define Qt_ListWidget_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Widget.hpp"

namespace QT {
    class ListWidget : public QT::Widget {
        
        // Constructor (new,define)
        public: ListWidget(const QT::PaintEvent_t &paintEvent,
                const QT::MouseEvent_t &mousePressEvent,
                 ::hyve::lang::int32 x,
                 ::hyve::lang::int32 y,
                 ::hyve::lang::int32 width,
                 ::hyve::lang::int32 height,
                 ::hyve::lang::_bool enabled,
                 ::hyve::lang::_bool visible,
                 ::hyve::lang::string styleSheet,
                 hyve::ll_h items,
                 ::hyve::lang::uint32 currentIndex,
                 ::hyve::lang::string currentText);
        
        // Scoped constructor (declare,define)
        public: ListWidget(::hyve::lang::Object *_parent,
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
                 hyve::ll_h items,
                 ::hyve::lang::uint32 currentIndex,
                 ::hyve::lang::string currentText);
        
        // Handle constructor
        public: ListWidget(QT::listWidget handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::listWidget _handle() const;
        
        // ::hyve::lang::uint32 currentIndex
        public: ::hyve::lang::uint32 currentIndex() const;
        public: void currentIndex( ::hyve::lang::uint32 v) const;
        
        // ::hyve::lang::string currentText
        public: ::hyve::lang::string currentText() const;
        public: void currentText( ::hyve::lang::string v) const;
        
        // <0x81621e0> items
        public: hyve::ll_h items() const;
        public: void items( hyve::ll_h v) const;
        
        // construct(::Qt::ListWidget object)
        public: static ::hyve::lang::int16 construct(const QT::ListWidget &object);
        
        // destruct(::Qt::ListWidget object)
        public: static ::hyve::lang::_void destruct(const QT::ListWidget &object);
        
        // insertItem(::hyve::lang::string label)
        public: ::hyve::lang::_void insertItem(::hyve::lang::string label) const;
        
        // onSelf
        public: ::hyve::lang::_void onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
    };
}

#endif

