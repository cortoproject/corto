/* src/Qt/ObjectTree.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::ObjectTree.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/ObjectTree.hpp"
#include "Qt/_meta.hpp"
#include "hyve/lang/Object.hpp"

/* $begin($header) */
#include "stdio.h"
#include "Qt/Application.hpp"
#include "hyve/lang/Observer.hpp"

namespace QT {
    ObjectTreeSlots::ObjectTreeSlots(QT::objectTree handle, QTreeWidget *handle_q) {
        this->handle = handle;
        this->handle_q = handle_q;
        QObject::connect(handle_q, SIGNAL(itemActivated(QTreeWidgetItem*,int)),this,SLOT(itemActivated(QTreeWidgetItem*,int)));
    }
    void ObjectTreeSlots::itemActivated(QTreeWidgetItem* item,int index) {
        (void)index;
        if (!this->muted) {
            hyve::updateBegin(this->handle);
            if (this->handle->object) {
                hyve::free(this->handle->object);
            }
            this->handle->object = item->data(0, Qt::UserRole).value<hyve::lang::object>();
            hyve::keep(this->handle->object);
            hyve::updateEndFrom(this->handle, this->handle);
        }
    }
}
/* $end */

namespace QT {
    
    // Constructor
    ObjectTree::ObjectTree(const QT::PaintEvent_t &paintEvent,
            const QT::MouseEvent_t &mousePressEvent,
             ::hyve::lang::int32 x,
             ::hyve::lang::int32 y,
             ::hyve::lang::int32 width,
             ::hyve::lang::int32 height,
             ::hyve::lang::_bool enabled,
             ::hyve::lang::_bool visible,
             ::hyve::lang::string styleSheet,
            const ::hyve::lang::Object &scope,
            const ::hyve::lang::Object &object) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::ObjectTree_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->scope(scope);
        this->object(object);
        this->define();
    }
    
    // Constructor (declare & define)
    ObjectTree::ObjectTree(::hyve::lang::Object *_parent,
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
            const ::hyve::lang::Object &object) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::ObjectTree_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->scope(scope);
        this->object(object);
        this->define();
    }
    
    // Construct from handle
    ObjectTree::ObjectTree(QT::objectTree handle, bool owner) : QT::Widget((QT::widget)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::objectTree ObjectTree::_handle() const {
        return (QT::objectTree)this->__handle;
    }
    
    // ::hyve::lang::object scope
    ::hyve::lang::Object ObjectTree::scope() const {
        ::hyve::lang::Object result(((QT::objectTree)this->__handle)->scope);
        return result;
    }
    void ObjectTree::scope(const ::hyve::lang::Object &v) const {
        if (v) {
            hyve::set((hyve::lang::object*)&((QT::objectTree)this->__handle)->scope, v._handle());
        } else {
            hyve::set((hyve::lang::object*)&((QT::objectTree)this->__handle)->scope, NULL);
        }
    }
    
    // ::hyve::lang::object object
    ::hyve::lang::Object ObjectTree::object() const {
        ::hyve::lang::Object result(((QT::objectTree)this->__handle)->object);
        return result;
    }
    void ObjectTree::object(const ::hyve::lang::Object &v) const {
        if (v) {
            hyve::set((hyve::lang::object*)&((QT::objectTree)this->__handle)->object, v._handle());
        } else {
            hyve::set((hyve::lang::object*)&((QT::objectTree)this->__handle)->object, NULL);
        }
    }
    
    /* ::Qt::ObjectTree::construct(::Qt::ObjectTree object) */
    ::hyve::lang::int16 ObjectTree::construct(const QT::ObjectTree &object) {
    /* $begin(::Qt::ObjectTree::construct(::Qt::ObjectTree object)) */
        QTreeWidget *widget;
        QWidget* parent_q; /* Parent handle to hyve object */

        /* Obtain parent handle (Could also have been done using proxy-objects, but this is faster) */
        parent_q = (QWidget*)object.widgetParent();

        /* Create button */
        widget = new QTreeWidget(parent_q);
        if (!widget) {
            hyve::error("Qt::ObjectTree::construct: failed to create object '%s'", object.nameof());
            goto error;
        }

        /* Set handle */
        object.qhandle((hyve::lang::word)widget);

        /* Call abstractbutton constructor */
        QT::Widget::construct(object);
        widget->setExpandsOnDoubleClick(false);

        if (!object._handle()->scope) {
            hyve::set(&object._handle()->scope, ::root_h); /* If no scope is set, use root */
        }

        object.init();

        {
            hyve::lang::Observer onNew(QT::ObjectTree_onNew_h);
            hyve::lang::Observer onConstruct(QT::ObjectTree_onConstruct_h);
            hyve::lang::Observer onDestruct(QT::ObjectTree_onDestruct_h);
            hyve::lang::Dispatcher dispatcher(QT::app(),false);
            hyve::lang::Object observable(object.scope());

            onNew.setDispatcher(dispatcher);
            onNew.listen(observable, object);

            onConstruct.setDispatcher(dispatcher);
            onConstruct.listen(observable, object);

            onDestruct.setDispatcher(dispatcher);
            onDestruct.listen(observable, object);
        }

        /* Setup slots */
        object.qslots((hyve::lang::word)new ObjectTreeSlots(object._handle(), widget));

        /* Show button */
        widget->show();

        widget->setEnabled(true);
        return 0;
    error:
        return -1;
    /* $end */
    }
    
    /* ::Qt::ObjectTree::destruct(::Qt::ObjectTree object) */
    ::hyve::lang::_void ObjectTree::destruct(const QT::ObjectTree &object) {
    /* $begin(::Qt::ObjectTree::destruct(::Qt::ObjectTree object)) */
        (void)object;
    /* $end */
    }
    
    /* ::Qt::ObjectTree::init(::Qt::ObjectTree object) */
    ::hyve::lang::int16 ObjectTree::init(const QT::ObjectTree &object) {
    /* $begin(::Qt::ObjectTree::init(::Qt::ObjectTree object)) */
        return 0;
    /* $end */
    }
    
    /* ::Qt::ObjectTree::onConstruct */
    ::hyve::lang::_void ObjectTree::onConstruct(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::ObjectTree::onConstruct) */
        (void)observable;
        (void)source;
    /* $end */
    }
    
    /* ::Qt::ObjectTree::onDestruct */
    ::hyve::lang::_void ObjectTree::onDestruct(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::ObjectTree::onDestruct) */
        QTreeWidgetItem *item, *parent;
        hyve::lang::object observable_h;
        (void)observable;

        observable_h = observable._handle();
        item = findItem(observable_h, &parent);

        if (parent && item) {
            parent->removeChild(item);
        }
    /* $end */
    }
    
    /* ::Qt::ObjectTree::onNew */
    ::hyve::lang::_void ObjectTree::onNew(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::ObjectTree::onNew) */
        QTreeWidgetItem *item;
        hyve::lang::object observable_h;
        (void)observable;

        observable_h = source._handle();
        item = findItem(hyve::parentof(observable_h), NULL);

        // Insert new item in parent
        newItem(item, observable_h);
    /* $end */
    }
    
    /* ::Qt::ObjectTree::onSelf */
    ::hyve::lang::_void ObjectTree::onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::ObjectTree::onSelf) */
        (void)observable;
        (void)source;
    /* $end */
    }
}
/* $begin($footer) */
namespace QT {

    // Initialize tree
    void ObjectTree::init() const {
        QTreeWidget* widget;
        QTreeWidgetItem* header;

        widget = (QTreeWidget*)this->qhandle();
        widget->clear();

        // Setup header
        header = widget->headerItem();
        header->setText(0, QString("Name"));
        header->setText(1, QString("Type"));
        widget->setColumnWidth(0, 150);
        widget->setColumnWidth(1, 150);
    }

    QTreeWidgetItem* ObjectTree::newItem(QTreeWidgetItem *parent, hyve::lang::object o) const {
        QVariant var;
        hyve::id id;
        QTreeWidgetItem* item;

        /* Create new item */
        if (parent) {
            item = new QTreeWidgetItem(parent);
        } else {
            QTreeWidget *widget = (QTreeWidget*)this->qhandle();
            item = new QTreeWidgetItem(widget);
        }

        /* Set name */
        item->setText(0, hyve::nameof(o));

        /* Set type */
        if (hyve::checkAttr(o, hyve::ATTR_SCOPED)) {
            item->setText(1, hyve::fullname(hyve::_typeof(o), id));
        } else {
            hyve::lang::string str;
            str = hyve::toString(hyve::_typeof(o), 0);
            item->setText(1, str);
            hyve::dealloc(str);
        }

        var.setValue(o);
        item->setData(0, Qt::UserRole, var);

        return item;
    }

    QTreeWidgetItem* ObjectTree::findItem(hyve::lang::object o, QTreeWidgetItem** parent_out) const {
        QTreeWidgetItem *item, *child, *parent;
        QTreeWidget* widget;
        hyve::lang::object parent_h;
        hyve::lang::object parents[hyve::MAX_SCOPE_DEPTH];
        hyve::lang::uint32 parentCount = 0;

        if (parent_out) {
            *parent_out = NULL;
        }

        // Build stack of scope until the root of the ObjectTree is found
        parents[parentCount++] = parent_h = o;
        while((parent_h = hyve::parentof(parent_h)) && (parent_h != this->_handle()->scope) && (parent_h != root_h)) {
            parents[parentCount++] = parent_h;
        }

        // Get Qt Widget
        widget = (QTreeWidget*)this->qhandle();
        item = widget->invisibleRootItem();

        // Find parent in tree
        parent = NULL;
        while(parentCount) {
            bool found = FALSE;
            hyve::lang::object childObject;
            for(int i=0; i<item->childCount(); i++) {
                child = item->child(i);
                childObject = child->data(0, Qt::UserRole).value<hyve::lang::object>();
                if (childObject == parents[parentCount-1]) {
                    parent = item;
                    item = child;
                    parentCount--;
                    found = TRUE;
                    break;
                }
            }
            if (!found) {
                /* A parent is removed before all children are gone. Can happen when there are reference-cycles. */
                return NULL;
            }
        }
        if (parent_out) {
            *parent_out = parent;
        }

        return item;
    }
}
/* $end */

