/* include/Qt/MainWindow.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::MainWindow.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_MainWindow_H
#define Qt_MainWindow_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Widget.hpp"

namespace QT {
    class MainWindow : public QT::Widget {
        
        // Constructor (new,define)
        public: MainWindow(const QT::PaintEvent_t &paintEvent,
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
        public: MainWindow(::hyve::lang::Object *_parent,
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
        public: MainWindow(QT::mainWindow handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::mainWindow _handle() const;
        
        // ::hyve::lang::word cw
        public: ::hyve::lang::word cw() const;
        public: void cw( ::hyve::lang::word v) const;
        
        // ::hyve::lang::string title
        public: ::hyve::lang::string title() const;
        public: void title( ::hyve::lang::string v) const;
        
        // construct(::Qt::MainWindow object)
        public: static ::hyve::lang::int16 construct(const QT::MainWindow &object);
        
        // destruct(::Qt::MainWindow object)
        public: static ::hyve::lang::_void destruct(const QT::MainWindow &object);
        
        // onSelf
        public: ::hyve::lang::_void onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
        /* $begin($classfooter) */
        void refresh() const;
        /* $end */
    };
}

#endif

