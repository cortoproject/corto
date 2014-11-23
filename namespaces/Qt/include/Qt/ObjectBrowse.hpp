/* include/Qt/ObjectBrowse.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::ObjectBrowse.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_ObjectBrowse_H
#define Qt_ObjectBrowse_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Widget.hpp"

/* $begin($header) */
#include "QTreeWidget"
#include "SlotBase.h"

namespace QT {
    class ObjectBrowseSlots : public QObject, public SlotBase {
        Q_OBJECT
    public:
        ObjectBrowseSlots(QT::objectBrowse handle, QTreeWidget *handle_q);
    public slots:
        void itemActivated(QTreeWidgetItem* item, int index);
    private:
        QT::objectBrowse handle;
        QTreeWidget *handle_q;
    };
}
/* $end */

namespace QT {
    class ObjectBrowse : public QT::Widget {
        
        // Constructor (new,define)
        public: ObjectBrowse(const QT::PaintEvent_t &paintEvent,
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
                 ::hyve::lang::_bool showPrimitives);
        
        // Scoped constructor (declare,define)
        public: ObjectBrowse(::hyve::lang::Object *_parent,
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
                 ::hyve::lang::_bool showPrimitives);
        
        // Handle constructor
        public: ObjectBrowse(QT::objectBrowse handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::objectBrowse _handle() const;
        
        // ::hyve::lang::string expr
        public: ::hyve::lang::string expr() const;
        public: void expr( ::hyve::lang::string v) const;
        
        // ::hyve::lang::object object
        public: ::hyve::lang::Object object() const;
        public: void object(const ::hyve::lang::Object &v) const;
        
        // ::hyve::lang::object prevObject
        public: ::hyve::lang::Object prevObject() const;
        public: void prevObject(const ::hyve::lang::Object &v) const;
        
        // ::hyve::lang::bool showPrimitives
        public: ::hyve::lang::_bool showPrimitives() const;
        public: void showPrimitives( ::hyve::lang::_bool v) const;
        
        // construct(::Qt::ObjectBrowse object)
        public: static ::hyve::lang::int16 construct(const QT::ObjectBrowse &object);
        
        // destruct(::Qt::ObjectBrowse object)
        public: static ::hyve::lang::_void destruct(const QT::ObjectBrowse &object);
        
        // onDestruct
        public: ::hyve::lang::_void onDestruct(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
        
        // onSelf
        public: ::hyve::lang::_void onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
        
        // onUpdate
        public: ::hyve::lang::_void onUpdate(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
        
        // setObject(::hyve::lang::object object)
        public: ::hyve::lang::_void setObject(const ::hyve::lang::Object &object) const;
        /* $begin($classfooter) */
        void refresh() const;
        /* $end */
    };
}

#endif

