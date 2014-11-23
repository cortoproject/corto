/* include/Qt/ObjectTree.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::ObjectTree.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_ObjectTree_H
#define Qt_ObjectTree_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Widget.hpp"

/* $begin($header) */
#include "QTreeWidget"
#include "SlotBase.h"

namespace QT {
    class ObjectTreeSlots : public QObject, public SlotBase {
        Q_OBJECT
    public:
        ObjectTreeSlots(QT::objectTree handle, QTreeWidget *handle_q);
    public slots:
        void itemActivated(QTreeWidgetItem* item, int index);
    private:
        QT::objectTree handle;
        QTreeWidget *handle_q;
    };
}
/* $end */

namespace QT {
    class ObjectTree : public QT::Widget {
        
        // Constructor (new,define)
        public: ObjectTree(const QT::PaintEvent_t &paintEvent,
                const QT::MouseEvent_t &mousePressEvent,
                 ::hyve::lang::int32 x,
                 ::hyve::lang::int32 y,
                 ::hyve::lang::int32 width,
                 ::hyve::lang::int32 height,
                 ::hyve::lang::_bool enabled,
                 ::hyve::lang::_bool visible,
                 ::hyve::lang::string styleSheet,
                const ::hyve::lang::Object &scope,
                const ::hyve::lang::Object &object);
        
        // Scoped constructor (declare,define)
        public: ObjectTree(::hyve::lang::Object *_parent,
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
                const ::hyve::lang::Object &scope,
                const ::hyve::lang::Object &object);
        
        // Handle constructor
        public: ObjectTree(QT::objectTree handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::objectTree _handle() const;
        
        // ::hyve::lang::object object
        public: ::hyve::lang::Object object() const;
        public: void object(const ::hyve::lang::Object &v) const;
        
        // ::hyve::lang::object scope
        public: ::hyve::lang::Object scope() const;
        public: void scope(const ::hyve::lang::Object &v) const;
        
        // construct(::Qt::ObjectTree object)
        public: static ::hyve::lang::int16 construct(const QT::ObjectTree &object);
        
        // destruct(::Qt::ObjectTree object)
        public: static ::hyve::lang::_void destruct(const QT::ObjectTree &object);
        
        // init(::Qt::ObjectTree object)
        public: static ::hyve::lang::int16 init(const QT::ObjectTree &object);
        
        // onConstruct
        public: ::hyve::lang::_void onConstruct(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
        
        // onDestruct
        public: ::hyve::lang::_void onDestruct(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
        
        // onNew
        public: ::hyve::lang::_void onNew(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
        
        // onSelf
        public: ::hyve::lang::_void onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
        /* $begin($classfooter) */
        // Initialize tree
        void init() const;

        // scopeWalk
        static int scopeWalk(hyve::lang::object o, void* userData);

        // new item
        QTreeWidgetItem* newItem(QTreeWidgetItem *parent, hyve::lang::object o) const;

        // find item
        QTreeWidgetItem* findItem(hyve::lang::object o, QTreeWidgetItem** parent_out) const;
        /* $end */
    };
}

#endif

