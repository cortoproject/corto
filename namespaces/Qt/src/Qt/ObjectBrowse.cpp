/* src/Qt/ObjectBrowse.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::ObjectBrowse.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/ObjectBrowse.hpp"
#include "Qt/_meta.hpp"
#include "hyve/lang/Object.hpp"

/* $begin($header) */
#include "Qt/Application.hpp"
#include "QTreeWidget"
#include "hyve/lang/Observer.hpp"
#include "stdio.h"

Q_DECLARE_METATYPE(hyve::lang::string)

namespace QT {
    ObjectBrowseSlots::ObjectBrowseSlots(QT::objectBrowse handle, QTreeWidget *handle_q) {
        this->handle = handle;
        this->handle_q = handle_q;
        QObject::connect(handle_q, SIGNAL(itemActivated(QTreeWidgetItem*,int)),this,SLOT(itemActivated(QTreeWidgetItem*,int)));
    }
    void ObjectBrowseSlots::itemActivated(QTreeWidgetItem* item,int index) {
        hyve::lang::string expr;
        (void)index;
        if (!this->muted) {
            hyve::updateBegin(this->handle);
            if (this->handle->expr) {
                hyve::dealloc(this->handle->expr);
            }
            expr = item->data(0, Qt::UserRole).value<hyve::lang::string>();
            if (expr) {
                this->handle->expr = hyve::strdup(expr);
            } else {
                this->handle->expr = NULL;
            }
            hyve::updateEndFrom(this->handle, this->handle);
        }
    }

    using namespace hyve;

    // Class that serializes object to ObjectBrowse
    class SerializeObjectBrowse : public hyve::Serializer {
    public:
        // Forward to Serialzer::Serializer
        SerializeObjectBrowse(const ObjectBrowse* browse, lang::modifier access, lang::operatorKind accessKind, serializerTraceKind traceKind)
                : Serializer(access, accessKind, traceKind) {
            this->browse = browse;
            this->widget = (QTreeWidget*)this->browse->qhandle();
            this->item = NULL;
            this->expr = NULL;
        }

        // Serialize composite value
        lang::int16 serializeComposite(value* info) {
            return this->serializeMembers(info);
        }

        // Serialize member & inheritance
        lang::int16 serializeMember(value* info) {
            lang::int16 result = 0;
            QTreeWidgetItem *item, *prevItem;
            hyve::id id, expr;
            lang::_typedef t;
            lang::string memberName;
            lang::string prevExpr;
            QVariant var;

            prevItem = this->item;
            memberName = NULL;

            t = info->type();

            /* Only add composite and collection members */
            if (this->browse->_handle()->showPrimitives || (!t->real->reference || (info->kind == BASE)) &&
               ((t->real->kind == hyve::lang::COMPOSITE) || (t->real->kind == hyve::lang::COLLECTION)))
            {
                /* Create new item */
                if (this->item) {
                    item = new QTreeWidgetItem(this->item);
                } else {
                    item = new QTreeWidgetItem(this->widget);
                }

                // If kind is member, serialize member
                if (info->kind == MEMBER) {
                    memberName = hyve::nameof(info->is.member.t);

                // If kind is object, serialize base-class
                } else if (info->kind == BASE) {
                    memberName = "super";
                }

                // Set item contents
                item->setText(0, memberName);
                if (hyve::checkAttr(t, hyve::ATTR_SCOPED)) {
                    item->setText(1, hyve::fullname(t, id));
                } else {
                    hyve::lang::string str;
                    str = hyve::toString(t, 0);
                    item->setText(1, str);
                    hyve::dealloc(str);
                }

                // Create expression string for current member
                prevExpr = this->expr;
                if (prevExpr) {
                    sprintf(expr, "%s.%s", prevExpr, memberName);
                } else {
                    sprintf(expr, ".%s", memberName);
                }

                // Set item data
                var.setValue(hyve::strdup(expr));
                item->setData(0, Qt::UserRole, var);

                // Serialize contents
                this->item = item;
                this->expr = expr;
                result = this->serializeValue(info);
                this->expr = prevExpr;
                this->item = prevItem;
            }

            return result;
        }

        lang::int16 serializeBase(value* info) {
            this->serializeMember(info);
        }

        // Serialize element
        lang::int16 serializeElement(value* info) {
            lang::int16 result = 0;
            QTreeWidgetItem *item, *prevItem;
            hyve::id id, expr;
            lang::_typedef t;
            hyve::id memberName;
            lang::string prevExpr;
            QVariant var;

            prevItem = this->item;

            t = info->type();
            /* Only add composite and collection members */
            if (this->browse->_handle()->showPrimitives || (!t->real->reference || (info->kind == OBJECT)) &&
               ((t->real->kind == hyve::lang::COMPOSITE) || (t->real->kind == hyve::lang::COLLECTION)))
            {

                /* Create new item */
                if (this->item) {
                    item = new QTreeWidgetItem(this->item);
                } else {
                    item = new QTreeWidgetItem(this->widget);
                }

                // If kind is member, serialize member
                ::sprintf(memberName, "[%d]", info->is.element.t.index);

                // Set item contents
                item->setText(0, memberName);
                if (hyve::checkAttr(t, hyve::ATTR_SCOPED)) {
                    item->setText(1, hyve::fullname(t, id));
                } else {
                    hyve::lang::string str;
                    str = hyve::toString(t, 0);
                    item->setText(1, str);
                    hyve::dealloc(str);
                }

                // Create expression string for current member
                prevExpr = this->expr;
                if (prevExpr) {
                    sprintf(expr, "%s%s", prevExpr, memberName);
                } else {
                    sprintf(expr, "%s", memberName);
                }

                // Set item data
                var.setValue(hyve::strdup(expr));
                item->setData(0, Qt::UserRole, var);

                // Serialize contents
                this->item = item;
                this->expr = expr;
                result = this->serializeValue(info);
                this->expr = prevExpr;
                this->item = prevItem;
            }

            return result;
        }

    private:
        const ObjectBrowse* browse;
        QTreeWidget* widget;
        QTreeWidgetItem* item;
        lang::string expr;
    };
}
/* $end */

namespace QT {
    
    // Constructor
    ObjectBrowse::ObjectBrowse(const QT::PaintEvent_t &paintEvent,
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
             ::hyve::lang::_bool showPrimitives) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::ObjectBrowse_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->object(object);
        this->expr(expr);
        this->showPrimitives(showPrimitives);
        this->define();
    }
    
    // Constructor (declare & define)
    ObjectBrowse::ObjectBrowse(::hyve::lang::Object *_parent,
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
             ::hyve::lang::_bool showPrimitives) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::ObjectBrowse_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->object(object);
        this->expr(expr);
        this->showPrimitives(showPrimitives);
        this->define();
    }
    
    // Construct from handle
    ObjectBrowse::ObjectBrowse(QT::objectBrowse handle, bool owner) : QT::Widget((QT::widget)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::objectBrowse ObjectBrowse::_handle() const {
        return (QT::objectBrowse)this->__handle;
    }
    
    // ::hyve::lang::object object
    ::hyve::lang::Object ObjectBrowse::object() const {
        ::hyve::lang::Object result(((QT::objectBrowse)this->__handle)->object);
        return result;
    }
    void ObjectBrowse::object(const ::hyve::lang::Object &v) const {
        if (v) {
            hyve::set((hyve::lang::object*)&((QT::objectBrowse)this->__handle)->object, v._handle());
        } else {
            hyve::set((hyve::lang::object*)&((QT::objectBrowse)this->__handle)->object, NULL);
        }
    }
    
    // ::hyve::lang::object prevObject
    ::hyve::lang::Object ObjectBrowse::prevObject() const {
        ::hyve::lang::Object result(((QT::objectBrowse)this->__handle)->prevObject);
        return result;
    }
    void ObjectBrowse::prevObject(const ::hyve::lang::Object &v) const {
        if (v) {
            hyve::set((hyve::lang::object*)&((QT::objectBrowse)this->__handle)->prevObject, v._handle());
        } else {
            hyve::set((hyve::lang::object*)&((QT::objectBrowse)this->__handle)->prevObject, NULL);
        }
    }
    
    // ::hyve::lang::string expr
    ::hyve::lang::string ObjectBrowse::expr() const {
        return ((QT::objectBrowse)this->__handle)->expr;
    }
    void ObjectBrowse::expr( ::hyve::lang::string v) const {
        if (((QT::objectBrowse)this->__handle)->expr) {
            hyve::dealloc(((QT::objectBrowse)this->__handle)->expr);
        };
        ((QT::objectBrowse)this->__handle)->expr = v ? hyve::strdup(v) : NULL;
    }
    
    // ::hyve::lang::bool showPrimitives
    ::hyve::lang::_bool ObjectBrowse::showPrimitives() const {
        return ((QT::objectBrowse)this->__handle)->showPrimitives;
    }
    void ObjectBrowse::showPrimitives( ::hyve::lang::_bool v) const {
        ((QT::objectBrowse)this->__handle)->showPrimitives = v;
    }
    
    /* ::Qt::ObjectBrowse::construct(::Qt::ObjectBrowse object) */
    ::hyve::lang::int16 ObjectBrowse::construct(const QT::ObjectBrowse &object) {
    /* $begin(::Qt::ObjectBrowse::construct(::Qt::ObjectBrowse object)) */
        QTreeWidget *widget;
        QWidget *parent_q; /* Parent handle to Qt object */
        QTreeWidgetItem* header;

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

        /* Setup header */
        header = widget->headerItem();
        header->setText(0, QString("Name"));
        header->setText(1, QString("Type"));
        widget->setExpandsOnDoubleClick(false);

        /* Initialize */
        object.refresh();

        /* Set dispatcher for own observers */
        {
            hyve::lang::Observer onUpdate(QT::ObjectBrowse_onUpdate_h); // Create proxy for template observer
            hyve::lang::Dispatcher dispatcher(QT::app(),false);
            onUpdate.setDispatcher(dispatcher);
        }

        /* Setup slots */
        object.qslots((hyve::lang::word)new ObjectBrowseSlots(object._handle(), widget));

        /* Show button */
        widget->show();
        return 0;
    error:
        return -1;
    /* $end */
    }
    
    /* ::Qt::ObjectBrowse::destruct(::Qt::ObjectBrowse object) */
    ::hyve::lang::_void ObjectBrowse::destruct(const QT::ObjectBrowse &object) {
    /* $begin(::Qt::ObjectBrowse::destruct(::Qt::ObjectBrowse object)) */
        (void)object;
    /* $end */
    }
    
    /* ::Qt::ObjectBrowse::onDestruct */
    ::hyve::lang::_void ObjectBrowse::onDestruct(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::ObjectBrowse::onDestruct) */

        /* << Insert implementation >> */

    /* $end */
    }
    
    /* ::Qt::ObjectBrowse::onSelf */
    ::hyve::lang::_void ObjectBrowse::onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::ObjectBrowse::onSelf) */
        (void)observable;
        (void)source;
    /* $end */
    }
    
    /* ::Qt::ObjectBrowse::onUpdate */
    ::hyve::lang::_void ObjectBrowse::onUpdate(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::ObjectBrowse::onUpdate) */
        (void)observable;
        (void)source;
        this->refresh();
    /* $end */
    }
    
    /* ::Qt::ObjectBrowse::setObject(::hyve::lang::object object) */
    ::hyve::lang::_void ObjectBrowse::setObject(const ::hyve::lang::Object &object) const {
    /* $begin(::Qt::ObjectBrowse::setObject(::hyve::lang::object object)) */
        this->updateBegin();
        this->object(object);
        {
            hyve::lang::Observer observer(QT::ObjectBrowse_onUpdate_h); // Create proxy for template observer
            hyve::lang::Observer privateObserver = QT::ObjectBrowse_o->privateObserver(*this, observer);

            if (this->_handle()->expr) {
                hyve::dealloc(this->_handle()->expr);
                this->_handle()->expr = NULL;
            }

            // Get private observer, re-set observable
            if (object.checkAttr(hyve::ATTR_OBSERVABLE)) {
                /*privateObserver.setObservable(object);*/
            }
            this->refresh();
        }
        this->updateEndFrom(*this);
    /* $end */
    }
    /* $begin($classfooter) */
    void ObjectBrowse::refresh() const {
        ((QTreeWidget*)this->qhandle())->clear();
        if (this->_handle()->object) {
            QTreeWidget* widget;
            QTreeWidgetItem *item;
            SerializeObjectBrowse s(this,0,hyve::lang::XOR,hyve::SERIALIZER_TRACE_ON_FAIL);
            hyve::id id;

            // Get handle to widget
            widget = (QTreeWidget*)this->qhandle();

            // Insert root
            item = new QTreeWidgetItem(widget);
            item->setText(0, "<object root>");
            item->setText(1, hyve::fullname(hyve::_typeof(this->_handle()->object), id));

            s.serialize(this->_handle()->object);
        }
    }
    /* $end */
}

