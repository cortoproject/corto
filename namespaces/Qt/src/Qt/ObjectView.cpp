/* src/Qt/ObjectView.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::ObjectView.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/ObjectView.hpp"
#include "Qt/_meta.hpp"
#include "hyve/lang/Object.hpp"

/* $begin($header) */
#include "Qt/Application.hpp"
#include "QTableWidget"
#include "QApplication"
#include "QHeaderView"
#include "hyve/lang/Observer.hpp"
#include "stdio.h"
#include "hyve/lang/_meta.hpp"

#define ROLE_PTR  (Qt::UserRole)
#define ROLE_TYPE (Qt::UserRole + 1)
#define ROLE_EXPR (Qt::UserRole + 2)
#define ROLE_LOCKED (Qt::UserRole + 3)
#define ROLE_LINK (Qt::UserRole + 4)
#define ROLE_INDEX (Qt::UserRole + 5)

Q_DECLARE_METATYPE(hyve::lang::string)
Q_DECLARE_METATYPE(hyve::lang::type)
Q_DECLARE_METATYPE(void*)

using namespace hyve;

namespace QT {
    using namespace hyve;

    // Count members of object
    class SerializeMemberCount : public hyve::Serializer {
    public:
        SerializeMemberCount(hyve::lang::object object, lang::modifier access, lang::operatorKind accessKind, serializerTraceKind traceKind)
                : Serializer(access, accessKind, traceKind) {
            if (object) {
                this->count = 0;
                if (this->serialize(object)) {
                    id id;
                    error("SerializeMemberCount: serialize of %s failed.", fullname(object, id));
                    this->count = 0;
                }
            }
        }
        SerializeMemberCount(lang::modifier access, lang::operatorKind accessKind, serializerTraceKind traceKind)
                : Serializer(access, accessKind, traceKind) {
            this->count = 0;
        }
        lang::int16 serializeMember(value* info) {
            lang::int16 result = 0;
            if (info->kind == MEMBER) {
                this->count++;
            }
            return result;
        }
        lang::int16 serializeElement(value* info) {
            (void)info;
            this->count++;
            return 0;
        }
        int count;
    };

    // Class that serializes object to ObjectView
    class SerializeObjectView : public hyve::Serializer {
    public:
        // Forward to Serialzer::Serializer
        SerializeObjectView(const ObjectView* view, lang::modifier access, lang::operatorKind accessKind, serializerTraceKind traceKind)
                : Serializer(access, accessKind, traceKind) {
            SerializeMemberCount s(view->_handle()->object, access, accessKind, traceKind);
            this->view = view;
            this->widget = (QTableWidget*)this->view->qhandle();
            this->row = 0;
            this->rowCount = s.count;
            this->depth = 0;
            this->complex = 0;
            this->orientation = QT::Vertical;
            this->element = 0;
            this->baseType = NULL;
        }

        // Apply layout to item
        void layoutItem(QTableWidgetItem *item, value *info) {
            lang::modifier access;
            QColor backgroundColor = QColor(0xff,0xff,0xff);
            QColor textColor = QColor(0,0,0);
            QFont font;
            lang::type t;

            font = item->font();
            font.setPointSize(10);

            // Determine access
            if (hyve::checkAttr(info->object(), hyve::ATTR_WRITABLE)) {
                access = lang::GLOBAL;
            } else {
                access = lang::READONLY;
            }
            if (access == lang::GLOBAL) {
                value *parent;
                parent = info;
                do {
                    switch(parent->kind) {
                    case hyve::MEMBER:
                        access &= parent->is.member.t->modifiers;
                        break;
                    case hyve::OBJECT:
                        if (parent->parent) {
                            lang::_struct e = (lang::_struct)parent->parent->type()->real;
                            access &= e->baseAccess;
                        }
                        break;
                    default:
                        break;
                    }
                }while((parent = parent->parent) && !access);
            }

            // Get type & determine coloring
            t = info->type()->real;
            if (t->reference) {
                textColor = QColor(0xdd,0x88,0x00);
                font.setItalic(false);
                font.setWeight(QFont::Bold);
            } else {
                font.setItalic(false);
                font.setWeight(QFont::Normal);
                switch(t->kind) {
                case lang::PRIMITIVE:
                    switch(((lang::primitive)t)->kind) {
                    case lang::BOOLEAN:
                    case lang::ENUM:
                    case lang::BITMASK:
                        textColor = QColor(0,0,0xff);
                        break;
                    case lang::TEXT:
                        textColor = QColor(0xaa,0,0);
                        break;
                    default:
                        break;
                    }
                    break;
                case lang::COMPOSITE:
                case lang::COLLECTION:
                    backgroundColor = QColor(0xff,0xff,0xdd);
                    item->setFlags(Qt::NoItemFlags);
                    break;
                default:
                    break;
                }
            }

            // Set colors
            if (!item->data(ROLE_LOCKED).value<bool>()) {
                item->setFont(font);
                if (access) { /* Restrictions apply */
                    backgroundColor = QColor(0xf6,0xf6,0xf6);
                    item->setFlags(Qt::NoItemFlags);
                } else {
                    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled);
                }
                item->setTextColor(textColor);
                item->setBackgroundColor(backgroundColor);
            }
        }

        void countValueMembers(value* info, lang::modifier access, lang::operatorKind accessKind, serializerTraceKind traceKind) {
            SerializeMemberCount s(access, accessKind, traceKind);
            s.serializeValue(info);
            this->rowCount = s.count;
            if (!this->rowCount) {
                // Little hack: if the rowcount is 0, this probably indicates that only a primitive value
                // is being serialized. Because the primitive-callback does not set rowcount, this is
                // performed here. A rowcount of 0 could also mean that a composite object has no
                // members, or a collection has no elements, in which case the rowcount is set twice,
                // which doesn't matter.
                this->widget->setColumnCount(1);
                this->widget->setRowCount(1);
                this->widget->setVerticalHeaderItem(0, new QTableWidgetItem("value"));
            }
        }

        // Serialize composite value
        lang::int16 serializeComposite(value* info) {
            lang::int16 result = 0;
            if (!this->depth) {
                // Set number of members for composite value
                if (this->orientation == QT::Vertical) {
                    this->widget->setColumnCount(2);
                    this->widget->setRowCount(this->rowCount);
                    this->widget->verticalHeader()->setResizeMode(0, QHeaderView::ResizeToContents);
                    this->widget->horizontalHeader()->setStretchLastSection(true);
                    this->widget->horizontalHeader()->hide();
                    this->widget->verticalHeader()->hide();
                } else {
                    if (!this->element) {
						hyve::lang::uint32 length = this->view->_handle()->fields.length;
						if (!length) {
							SerializeMemberCount s(access, this->accessKind, traceKind);
							s.serializeValue(info);
							this->widget->setColumnCount(s.count);
						} else {
							this->widget->setColumnCount(length);
						}
                    }
                }

                // Serialize composite members
                this->row = 0;
                this->depth++; this->complex++;
                result = this->serializeMembers(info);
                this->depth--; this->complex--;
            } else {
                QTableWidgetItem *item;
                QVariant var;
                lang::string str;
                hyve::id expr;

                str = toString(info, 256);
                if (this->orientation == QT::Vertical) {
                    this->widget->setItem(this->row, 1, item = new QTableWidgetItem(str));
                } else {
                    this->widget->setItem(this->element, this->row, item = new QTableWidgetItem(str));
                }
                this->layoutItem(item, info);
                hyve::dealloc(str);

                // Set item-expr
                var.setValue(hyve::strdup(info->expr(expr, sizeof(expr))));
                item->setData(ROLE_EXPR, var);

                // Set item-index
                var.setValue(this->element);
                item->setData(ROLE_INDEX, var);
            }
            return result;
        }

        // Serialize collection value
        lang::int16 serializeCollection(value* info) {
            lang::int16 result = 0;
            if (!this->depth) {
                this->widget->setRowCount(this->rowCount);
                this->widget->horizontalHeader()->setStretchLastSection(true);
                this->widget->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
                this->element = -1;
                this->orientation = QT::Horizontal;
                if (this->view->showHeaders()) {
                    this->widget->horizontalHeader()->show();
                } else {
                    this->widget->horizontalHeader()->hide();
                }

                // Will be overwritten for composite types, but is set so that the
                // primitive & reference callbacks don't have to account for setting up headers.
                this->widget->setColumnCount(1);
                this->widget->setHorizontalHeaderItem(0, new QTableWidgetItem("value"));

                // Serialize composite members
                this->complex++;
                result = this->serializeElements(info);
                this->complex--;
                this->element = -1; // Reset element
            } else {
                lang::string str;
                hyve::id expr;
                QVariant var;
                QTableWidgetItem *item;
                str = toString(info, 256);
                if (this->orientation == QT::Vertical) {
                    this->widget->setItem(this->row, 1, item = new QTableWidgetItem(str));
                } else {
                    this->widget->setItem(this->element,this->row,item = new QTableWidgetItem(str));
                }
                this->layoutItem(item, info);
                hyve::dealloc(str);

                // Set item-expr
                var.setValue(hyve::strdup(info->expr(expr, sizeof(expr))));
                item->setData(ROLE_EXPR, var);

                // Set item-index
                var.setValue(this->element);
                item->setData(ROLE_INDEX, var);
            }
            return result;
        }

        // Serialize primitive
        lang::int16 serializePrimitive(value* info) {
            lang::type t;
            lang::int16 result = 0;
            lang::string str;
            lang::_void *ptr;
            QTableWidgetItem *item;
            QVariant var;

            // Get type and value
            t = info->type()->real;
            ptr = info->ptr();

            if (info->kind == OBJECT) {
                this->widget->setColumnCount(1);
                this->widget->setRowCount(1);
                this->widget->setVerticalHeaderItem(0, new QTableWidgetItem("value"));
            }

            // Convert value
            if (this->orientation == QT::Vertical) {
                if (!(item = this->widget->item(this->row, 1))) {
                    this->widget->setItem(this->row, 1, item = new QTableWidgetItem());
                }
            } else {
                if (!(item = this->widget->item(this->element, this->row))) {
                    this->widget->setItem(this->element, this->row, item = new QTableWidgetItem());
                }
            }
            this->layoutItem(item, info);
            if (!item->data(ROLE_LOCKED).value<bool>()) {
                hyve::id id;
                convert((lang::primitive)t, ptr, (lang::primitive)lang::string_h, &str);
                item->setText(str);

                // Set item-pointer
                var.setValue(ptr);
                item->setData(ROLE_PTR, var);

                // Set item-type
                var.setValue(t);
                item->setData(ROLE_TYPE, var);

                // Set item-expr
                var.setValue(hyve::strdup(info->expr(id, sizeof(id))));
                item->setData(ROLE_EXPR, var);

                // Set item-index
                var.setValue(this->element);
                item->setData(ROLE_INDEX, var);
            }

            if (!this->complex) {
                this->widget->verticalHeader()->hide();
                this->widget->horizontalHeader()->hide();
                this->widget->verticalHeader()->setStretchLastSection(false);
                this->widget->horizontalHeader()->setStretchLastSection(true);
                this->widget->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);
                item->setTextAlignment(Qt::AlignTop);
            } else {
                item->setTextAlignment(Qt::AlignVCenter);
            }

            return result;
        }

        // Serialize reference
        lang::int16 serializeReference(value* info) {
            id id;
            lang::object ptr;
            QTableWidgetItem *item;
            QVariant var;

            ptr = *(lang::object*)info->ptr();

            // If object is not scoped, append serialized string
            if (ptr) {
                if (!hyve::checkAttr(ptr, ATTR_SCOPED)) {
                    lang::string str;
                    str = hyve::toString(ptr, 0);
                    strcpy(id, str);
                    hyve::dealloc(str);
                } else {
                    fullname(ptr, id);
                }
            } else {
                *id = 0;
                ::strcpy(id, "<null>");
            }

            if (this->orientation == QT::Vertical) {
                this->widget->setItem(this->row, 1, item = new QTableWidgetItem(id));
            } else {
                this->widget->setItem(this->element, this->row, item = new QTableWidgetItem(id));
            }

            /* Set object to link to */
            var.setValue(ptr);
            item->setData(ROLE_LINK, var);

            // Set item-expr
            var.setValue(hyve::strdup(info->expr(id, sizeof(id))));
            item->setData(ROLE_EXPR, var);

            // Set item-index
            var.setValue(this->element);
            item->setData(ROLE_INDEX, var);

            this->layoutItem(item, info);
            return 0;
        }

        void insertBaseLine(lang::_typedef type) {
            QTableWidgetItem *item;
            QFont defaultFont;
            hyve::id id;
            // Insert item for displaying basetype
            this->widget->setRowCount(this->row+1);
            item = new QTableWidgetItem();
            item->setText(fullname(type, id));
            item->setBackground(QColor(0xee,0xee,0xee));
            item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
            defaultFont = item->font();
            defaultFont.setWeight(QFont::Bold);
            item->setFont(defaultFont);
            item->setTextColor(QColor(0x99,0x99,0x99));
            this->widget->setItem(this->row, 0, item);
            this->widget->setSpan(this->row, 0, 1, 2);
            this->row++;
        }

        // Serialize member & inheritance
        lang::int16 serializeMember(value* info) {
            lang::int16 result = 0;

            // If kind is member, serialize member
            hyve::lang::_bool parseMember = TRUE;

            // If fields are set, only serialize specified members */
            if (this->view->_handle()->fields.length) {
                parseMember = FALSE;
                for(unsigned i=0; i<this->view->_handle()->fields.length; i++) {
                    if (!strcmp(nameof(info->is.member.t), this->view->_handle()->fields.buffer[i])) {
                        parseMember = TRUE;
                        break;
                    }
                }
            }

            // Set member name
            if (parseMember) {
                if (this->orientation == QT::Vertical) {
                    QTableWidgetItem *item = new QTableWidgetItem(nameof(info->is.member.t));
                    QFont font = item->font();
                    font.setPointSize(10);
                    item->setFont(font);

                    // Make sure table has enough rows
                    this->widget->setRowCount(this->row+1);
                    this->widget->setItem(this->row, 0, item);
                } else {
                    if (!this->element) {
                        this->widget->setHorizontalHeaderItem(this->row, new QTableWidgetItem(nameof(info->is.member.t)));
                    }
                }
                // Serialize value
                result = this->serializeValue(info);
                // Increment row
                this->row++;
            }

            return result;
        }

        // Serialize member & inheritance
        lang::int16 serializeBase(value* info) {
            hyve::lang::_typedef type;
            lang::int16 result = 0;

            if (!((lang::interface)info->type())->base) {
                insertBaseLine(info->type());
            }

            type = this->baseType;
            this->baseType = info->type();
            result = this->serializeMembers(info);

            // Insert item for displaying basetype
            insertBaseLine(type);
        }

        // Serialize element
        lang::int16 serializeElement(value* info) {
            (void)info;
            this->element++;
            return this->serializeValue(info);
        }

        // Serialize object
        lang::int16 serializeObject(value* info) {
            lang::int16 result = 0;
            lang::type t = info->type()->real;

            if ((t->kind == lang::VOID)) {
                this->widget->clear();
                this->widget->setColumnCount(0);
                this->widget->setRowCount(0);
            } else {
                this->baseType = info->type();
                result = this->serializeValue(info);
            }
            return result;
        }

    private:
        const ObjectView* view;
        QTableWidget* widget;
        int row;
        int rowCount;
        int element;
        int depth;
        int complex;
        hyve::lang::_typedef baseType;
        QT::Orientation orientation;
    };

    ObjectViewSlots::ObjectViewSlots(QT::objectView handle, QTableWidget *handle_q) {
        this->handle = handle;
        this->handle_q = handle_q;
        QObject::connect(handle_q, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(itemDoubleClicked(QTableWidgetItem*)));
        QObject::connect(handle_q, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(itemClicked(QTableWidgetItem*)));
        QObject::connect(handle_q, SIGNAL(currentCellChanged(int,int,int,int)), this, SLOT(cellEntered(int,int,int,int)));
    }

    void ObjectViewSlots::itemClicked(QTableWidgetItem* item) {
        if (QApplication::keyboardModifiers() & Qt::ControlModifier) {
            QT::ObjectView view(this->handle);
            hyve::lang::Object obj(item->data(ROLE_LINK).value<void*>());
            if (obj._handle()) {
                view.setObject(obj);
            }
        }
    }

    void ObjectViewSlots::itemDoubleClicked(QTableWidgetItem* item) {
        item->setData(ROLE_LOCKED,QVariant(true));
        item->setBackgroundColor(QColor(0xdd,0xdd,0xff));
    }

    void ObjectViewSlots::cellEntered(int row, int column, int oldRow, int oldColumn) {
        QTableWidgetItem* item;
        lang::string expr;

        if (!this->muted) {
            item = this->handle_q->item(row, column);
            expr = item->data(ROLE_EXPR).value<lang::string>();

            hyve::updateBegin(this->handle);
            if (this->handle->selected) {
                hyve::dealloc(this->handle->selected);
            }
            if (expr) {
                this->handle->selected = hyve::strdup(expr);
            } else {
                this->handle->selected = NULL;
            }
            this->handle->selectedElement = item->data(ROLE_INDEX).value<lang::uint32>();
            hyve::updateEnd(this->handle);
        }
    }
}
/* $end */

namespace QT {
    
    // Constructor
    ObjectView::ObjectView(const QT::PaintEvent_t &paintEvent,
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
             ::hyve::lang::uint32 selectedElement) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::ObjectView_h);
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
        this->showHeaders(showHeaders);
        this->fields(fields);
        this->selected(selected);
        this->selectedElement(selectedElement);
        this->define();
    }
    
    // Constructor (declare & define)
    ObjectView::ObjectView(::hyve::lang::Object *_parent,
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
             ::hyve::lang::uint32 selectedElement) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::ObjectView_h);
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
        this->showHeaders(showHeaders);
        this->fields(fields);
        this->selected(selected);
        this->selectedElement(selectedElement);
        this->define();
    }
    
    // Construct from handle
    ObjectView::ObjectView(QT::objectView handle, bool owner) : QT::Widget((QT::widget)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::objectView ObjectView::_handle() const {
        return (QT::objectView)this->__handle;
    }
    
    // ::hyve::lang::object object
    ::hyve::lang::Object ObjectView::object() const {
        ::hyve::lang::Object result(((QT::objectView)this->__handle)->object);
        return result;
    }
    void ObjectView::object(const ::hyve::lang::Object &v) const {
        if (v) {
            hyve::set((hyve::lang::object*)&((QT::objectView)this->__handle)->object, v._handle());
        } else {
            hyve::set((hyve::lang::object*)&((QT::objectView)this->__handle)->object, NULL);
        }
    }
    
    // ::hyve::lang::string expr
    ::hyve::lang::string ObjectView::expr() const {
        return ((QT::objectView)this->__handle)->expr;
    }
    void ObjectView::expr( ::hyve::lang::string v) const {
        if (((QT::objectView)this->__handle)->expr) {
            hyve::dealloc(((QT::objectView)this->__handle)->expr);
        };
        ((QT::objectView)this->__handle)->expr = v ? hyve::strdup(v) : NULL;
    }
    
    // ::hyve::lang::bool showHeaders
    ::hyve::lang::_bool ObjectView::showHeaders() const {
        return ((QT::objectView)this->__handle)->showHeaders;
    }
    void ObjectView::showHeaders( ::hyve::lang::_bool v) const {
        ((QT::objectView)this->__handle)->showHeaders = v;
    }
    
    // <0x8185520> fields
    ::hyve::lang::string_seq ObjectView::fields() const {
        return ((QT::objectView)this->__handle)->fields;
    }
    void ObjectView::fields( ::hyve::lang::string_seq v) const {
        ((QT::objectView)this->__handle)->fields = v;
    }
    
    // ::hyve::lang::string selected
    ::hyve::lang::string ObjectView::selected() const {
        return ((QT::objectView)this->__handle)->selected;
    }
    void ObjectView::selected( ::hyve::lang::string v) const {
        if (((QT::objectView)this->__handle)->selected) {
            hyve::dealloc(((QT::objectView)this->__handle)->selected);
        };
        ((QT::objectView)this->__handle)->selected = v ? hyve::strdup(v) : NULL;
    }
    
    // ::hyve::lang::uint32 selectedElement
    ::hyve::lang::uint32 ObjectView::selectedElement() const {
        return ((QT::objectView)this->__handle)->selectedElement;
    }
    void ObjectView::selectedElement( ::hyve::lang::uint32 v) const {
        ((QT::objectView)this->__handle)->selectedElement = v;
    }
    
    /* ::Qt::ObjectView::construct(::Qt::ObjectView object) */
    ::hyve::lang::int16 ObjectView::construct(const QT::ObjectView &object) {
    /* $begin(::Qt::ObjectView::construct(::Qt::ObjectView object)) */
        QTableWidget *widget;
        QWidget* parent_q; /* Parent handle to hyve object */

        /* Obtain parent handle (Could also have been done using proxy-objects, but this is faster) */
        parent_q = (QWidget*)object.widgetParent();

        /* Create button */
        widget = new QTableWidget(parent_q);
        if (!widget) {
            hyve::error("Qt::ObjectView::construct: failed to create object '%s'", object.nameof());
            goto error;
        }

        /* Set handle */
        object.qhandle((hyve::lang::word)widget);

        // Scroll per pixel
        widget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        widget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

        /* Set dispatcher for own observers */
        {
            hyve::lang::Observer onUpdate(QT::ObjectView_onUpdate_h); // Create proxy for template observer
            hyve::lang::Dispatcher dispatcher(QT::app(),false);
            onUpdate.setDispatcher(dispatcher);
        }

        /* Setup slots */
        object.qslots((hyve::lang::word)new ObjectViewSlots(object._handle(), widget));

        if (object._handle()->object) {
            object.refresh();
        } else {
            widget->clear();
        }

        /* Call widget constructor */
        QT::Widget::construct(object);

        /* Show button */
        widget->show();

        return 0;
    error:
        return -1;
    /* $end */
    }
    
    /* ::Qt::ObjectView::destruct(::Qt::ObjectView object) */
    ::hyve::lang::_void ObjectView::destruct(const QT::ObjectView &object) {
    /* $begin(::Qt::ObjectView::destruct(::Qt::ObjectView object)) */
        QTableWidget *widget = (QTableWidget*)object.qhandle();
        delete widget;
    /* $end */
    }
    
    /* ::Qt::ObjectView::init(::Qt::ObjectView object) */
    ::hyve::lang::int16 ObjectView::init(const QT::ObjectView &object) {
    /* $begin(::Qt::ObjectView::init(::Qt::ObjectView object)) */
        object.showHeaders(true);
        return QT::Widget::init(object);
    /* $end */
    }
    
    /* ::Qt::ObjectView::onDestruct */
    ::hyve::lang::_void ObjectView::onDestruct(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::ObjectView::onDestruct) */

        /* << Insert implementation >> */

    /* $end */
    }
    
    /* ::Qt::ObjectView::onSelf */
    ::hyve::lang::_void ObjectView::onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::ObjectView::onSelf) */
        (void)observable;
        (void)source;
        this->refresh();
    /* $end */
    }
    
    /* ::Qt::ObjectView::onUpdate */
    ::hyve::lang::_void ObjectView::onUpdate(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::ObjectView::onUpdate) */
        (void)observable;
        (void)source;
        this->refresh();
    /* $end */
    }
    
    /* ::Qt::ObjectView::setObject(::hyve::lang::object object) */
    ::hyve::lang::_void ObjectView::setObject(const ::hyve::lang::Object &object) const {
    /* $begin(::Qt::ObjectView::setObject(::hyve::lang::object object)) */
        this->updateBegin();
        this->expr(NULL);
        this->object(object);
        // Serialize new value
        this->refresh();
        this->updateEndFrom(*this);
    /* $end */
    }
    
    /* ::Qt::ObjectView::updateObject() */
    ::hyve::lang::_void ObjectView::updateObject() const {
    /* $begin(::Qt::ObjectView::updateObject()) */
        hyve::lang::uint32 x,y;
        QTableWidget *widget;
        QTableWidgetItem *item;
        void* ptr;
        hyve::lang::type t;
        QByteArray txt;

        widget = (QTableWidget*)this->qhandle();

        // Walk items in table
        hyve::updateBegin(this->_handle()->object);
        for(x=0; x<(hyve::lang::uint32)widget->columnCount(); x++) {
            for(y=0; y<(hyve::lang::uint32)widget->rowCount(); y++) {
                item = widget->item(y, x);
                if (item) {
                    ptr = item->data(ROLE_PTR).value<void*>();
                    t = item->data(ROLE_TYPE).value<lang::type>();
                    if (ptr) {
                        lang::string txtptr;
                        txt = item->text().toUtf8();
                        txtptr = txt.data();
                        hyve::convert((lang::primitive)lang::string_h,&txtptr,(lang::primitive)t,ptr);
                    }
                }
            }
        }
        /* Unlock items */
        this->unlock();
        hyve::updateEndFrom(this->_handle()->object, this->_handle());

        // Re-read object (update-routine might have adjusted fields based on new values)
        this->refresh();

    /* $end */
    }
    /* $begin($classfooter) */
    /* Unlock items */
    void ObjectView::unlock() const {
        hyve::lang::uint32 x,y;
        QTableWidget *widget;

        widget = (QTableWidget*)this->qhandle();

        // Walk items in table
        for(x=0; x<(hyve::lang::uint32)widget->columnCount(); x++) {
            for(y=0; y<(hyve::lang::uint32)widget->rowCount(); y++) {
                QTableWidgetItem* item = widget->item(y, x);
                /* Unlock items */
                if (item) {
                    item->setData(ROLE_LOCKED, QVariant(false));
                }
            }
        }
    }

    /* Refresh values */
    void ObjectView::refresh() const {
        ((ObjectViewSlots*)this->qslots())->mute(true);

        SerializeObjectView s(this, lang::PRIVATE, lang::NOT, SERIALIZER_TRACE_ON_FAIL);
        hyve::lang::Observer observer(QT::ObjectView_onUpdate_h); // Create proxy for template observer

        if (this->_handle()->object) {
            hyve::lang::Object object(this->_handle()->object);

            // Get private observer, re-set observable
            if (object.checkAttr(hyve::ATTR_OBSERVABLE)) {
                observer.listen(object, *this);
            }

            // Serialize new value
            if (this->_handle()->expr && strlen(this->_handle()->expr)) {
                hyve::valueStack stack;
                lang::uint32 count;
                if (hyve::parseExpr(this->_handle()->object, this->_handle()->expr, stack, &count)) {
                    s.countValueMembers(&stack[count-1], lang::PRIVATE, lang::NOT, SERIALIZER_TRACE_ON_FAIL);
                    s.serializeValue(&stack[count-1]);
                    hyve::free(stack[0].is.o);
                } else {
                    hyve::error("ObjectView::refresh: failed to parse expression '%s'.", this->_handle()->expr);
                }
            } else {
                s.serialize(this->_handle()->object);
            }

            ((QTableWidget*)this->qhandle())->clearSelection();

            ((Widget*)this)->refresh();
        }
        ((ObjectViewSlots*)this->qslots())->mute(false);
    }
    /* $end */
}

