/* include/Qt/ObjectView.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::ObjectView.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_ObjectView_H
#define Qt_ObjectView_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Widget.hpp"

/* $begin($header) */
#include "QTableWidget"
#include "SlotBase.h"
/* Glue-class that forwards signals to hyve */
namespace QT {
    class ObjectViewSlots : public QObject, public SlotBase {
        Q_OBJECT
    public:
        ObjectViewSlots(QT::objectView handle, QTableWidget *handle_q);
    public slots:
        void itemDoubleClicked(QTableWidgetItem* item);
        void itemClicked(QTableWidgetItem* item);
        void cellEntered(int oldRow, int oldColumn, int row, int column);
    private:
        QT::objectView handle;
        QTableWidget *handle_q;
    };
}
/* $end */

namespace QT {
    class ObjectView : public QT::Widget {
        
        // Constructor (new,define)
        public: ObjectView(const QT::PaintEvent_t &paintEvent,
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
                 ::hyve::lang::_bool showHeaders,
                 ::hyve::lang::string_seq fields,
                 ::hyve::lang::string selected,
                 ::hyve::lang::uint32 selectedElement);
        
        // Scoped constructor (declare,define)
        public: ObjectView(::hyve::lang::Object *_parent,
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
                 ::hyve::lang::_bool showHeaders,
                 ::hyve::lang::string_seq fields,
                 ::hyve::lang::string selected,
                 ::hyve::lang::uint32 selectedElement);
        
        // Handle constructor
        public: ObjectView(QT::objectView handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::objectView _handle() const;
        
        // ::hyve::lang::string expr
        public: ::hyve::lang::string expr() const;
        public: void expr( ::hyve::lang::string v) const;
        
        // <0x8185520> fields
        public: ::hyve::lang::string_seq fields() const;
        public: void fields( ::hyve::lang::string_seq v) const;
        
        // ::hyve::lang::object object
        public: ::hyve::lang::Object object() const;
        public: void object(const ::hyve::lang::Object &v) const;
        
        // ::hyve::lang::string selected
        public: ::hyve::lang::string selected() const;
        public: void selected( ::hyve::lang::string v) const;
        
        // ::hyve::lang::uint32 selectedElement
        public: ::hyve::lang::uint32 selectedElement() const;
        public: void selectedElement( ::hyve::lang::uint32 v) const;
        
        // ::hyve::lang::bool showHeaders
        public: ::hyve::lang::_bool showHeaders() const;
        public: void showHeaders( ::hyve::lang::_bool v) const;
        
        // construct(::Qt::ObjectView object)
        public: static ::hyve::lang::int16 construct(const QT::ObjectView &object);
        
        // destruct(::Qt::ObjectView object)
        public: static ::hyve::lang::_void destruct(const QT::ObjectView &object);
        
        // init(::Qt::ObjectView object)
        public: static ::hyve::lang::int16 init(const QT::ObjectView &object);
        
        // onDestruct
        public: ::hyve::lang::_void onDestruct(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
        
        // onSelf
        public: ::hyve::lang::_void onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
        
        // onUpdate
        public: ::hyve::lang::_void onUpdate(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
        
        // setObject(::hyve::lang::object object)
        public: ::hyve::lang::_void setObject(const ::hyve::lang::Object &object) const;
        
        // updateObject()
        public: ::hyve::lang::_void updateObject() const;
        /* $begin($classfooter) */
        void refresh() const;
        void unlock() const;
        /* $end */
    };
}

#endif

