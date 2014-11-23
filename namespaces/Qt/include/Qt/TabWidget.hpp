/* include/Qt/TabWidget.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::TabWidget.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_TabWidget_H
#define Qt_TabWidget_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Widget.hpp"
namespace QT {
    class Widget;
}

/* $begin($header) */
#include "QTabWidget"
#include "SlotBase.h"

namespace QT {
    class TabWidgetSlots : public QObject, public SlotBase {
        Q_OBJECT
    public:
        TabWidgetSlots(QT::tabWidget handle, QTabWidget *handle_q);
        QT::TabWidgetTab *getTab(int index);
    public slots:
        void currentChanged(int index);
        void tabCloseRequested(int index);
    private:
        QT::tabWidget handle;
        QTabWidget *handle_q;
    };
}
/* $end */

namespace QT {
    class TabWidget : public QT::Widget {
        
        // Constructor (new,define)
        public: TabWidget(const QT::PaintEvent_t &paintEvent,
                const QT::MouseEvent_t &mousePressEvent,
                 ::hyve::lang::int32 x,
                 ::hyve::lang::int32 y,
                 ::hyve::lang::int32 width,
                 ::hyve::lang::int32 height,
                 ::hyve::lang::_bool enabled,
                 ::hyve::lang::_bool visible,
                 ::hyve::lang::string styleSheet,
                 hyve::ll_h tabs,
                 ::hyve::lang::_bool closable,
                 ::hyve::lang::_bool movable,
                 ::hyve::lang::uint32 currentIndex,
                const QT::Widget &currentWidget,
                 ::hyve::lang::uint32 count);
        
        // Scoped constructor (declare,define)
        public: TabWidget(::hyve::lang::Object *_parent,
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
                 hyve::ll_h tabs,
                 ::hyve::lang::_bool closable,
                 ::hyve::lang::_bool movable,
                 ::hyve::lang::uint32 currentIndex,
                const QT::Widget &currentWidget,
                 ::hyve::lang::uint32 count);
        
        // Handle constructor
        public: TabWidget(QT::tabWidget handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::tabWidget _handle() const;
        
        // ::hyve::lang::bool closable
        public: ::hyve::lang::_bool closable() const;
        public: void closable( ::hyve::lang::_bool v) const;
        
        // ::hyve::lang::uint32 count
        public: ::hyve::lang::uint32 count() const;
        public: void count( ::hyve::lang::uint32 v) const;
        
        // ::hyve::lang::uint32 currentIndex
        public: ::hyve::lang::uint32 currentIndex() const;
        public: void currentIndex( ::hyve::lang::uint32 v) const;
        
        // ::Qt::Widget currentWidget
        public: QT::Widget currentWidget() const;
        public: void currentWidget(const QT::Widget &v) const;
        
        // ::hyve::lang::bool movable
        public: ::hyve::lang::_bool movable() const;
        public: void movable( ::hyve::lang::_bool v) const;
        
        // <0x8167488> tabs
        public: hyve::ll_h tabs() const;
        public: void tabs( hyve::ll_h v) const;
        
        // addTab(::hyve::lang::string label,::Qt::Widget widget)
        public: ::hyve::lang::_void addTab(::hyve::lang::string label, const QT::Widget &widget) const;
        
        // construct(::Qt::TabWidget object)
        public: static ::hyve::lang::int16 construct(const QT::TabWidget &object);
        
        // destruct(::Qt::TabWidget object)
        public: static ::hyve::lang::_void destruct(const QT::TabWidget &object);
    };
}

#endif

