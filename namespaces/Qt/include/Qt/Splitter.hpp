/* include/Qt/Splitter.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::Splitter.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_Splitter_H
#define Qt_Splitter_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Widget.hpp"

namespace QT {
    class Splitter : public QT::Widget {
        
        // Constructor (new,define)
        public: Splitter(const QT::PaintEvent_t &paintEvent,
                const QT::MouseEvent_t &mousePressEvent,
                 ::hyve::lang::int32 x,
                 ::hyve::lang::int32 y,
                 ::hyve::lang::int32 width,
                 ::hyve::lang::int32 height,
                 ::hyve::lang::_bool enabled,
                 ::hyve::lang::_bool visible,
                 ::hyve::lang::string styleSheet,
                 QT::SplitterItem_seq widgets,
                 QT::Orientation orientation);
        
        // Scoped constructor (declare,define)
        public: Splitter(::hyve::lang::Object *_parent,
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
                 QT::SplitterItem_seq widgets,
                 QT::Orientation orientation);
        
        // Handle constructor
        public: Splitter(QT::splitter handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::splitter _handle() const;
        
        // ::Qt::Orientation orientation
        public: QT::Orientation orientation() const;
        public: void orientation( QT::Orientation v) const;
        
        // <0x8174668> widgets
        public: QT::SplitterItem_seq widgets() const;
        public: void widgets( QT::SplitterItem_seq v) const;
        
        // construct(::Qt::Splitter object)
        public: static ::hyve::lang::int16 construct(const QT::Splitter &object);
        
        // destruct(::Qt::Splitter object)
        public: static ::hyve::lang::_void destruct(const QT::Splitter &object);
        
        // init(::Qt::Splitter object)
        public: static ::hyve::lang::int16 init(const QT::Splitter &object);
        
        // onSelf
        public: ::hyve::lang::_void onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
        /* $begin($classfooter) */
        void refresh() const;
        /* $end */
    };
}

#endif

