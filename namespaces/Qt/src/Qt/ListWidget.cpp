/* src/Qt/ListWidget.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::ListWidget.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/ListWidget.hpp"
#include "Qt/_meta.hpp"
#include "hyve/lang/Object.hpp"

/* $begin($header) */
#include "QListWidget"
/* $end */

namespace QT {
    
    // Constructor
    ListWidget::ListWidget(const QT::PaintEvent_t &paintEvent,
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
             ::hyve::lang::string currentText) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::ListWidget_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->items(items);
        this->currentIndex(currentIndex);
        this->currentText(currentText);
        this->define();
    }
    
    // Constructor (declare & define)
    ListWidget::ListWidget(::hyve::lang::Object *_parent,
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
             ::hyve::lang::string currentText) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::ListWidget_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->items(items);
        this->currentIndex(currentIndex);
        this->currentText(currentText);
        this->define();
    }
    
    // Construct from handle
    ListWidget::ListWidget(QT::listWidget handle, bool owner) : QT::Widget((QT::widget)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::listWidget ListWidget::_handle() const {
        return (QT::listWidget)this->__handle;
    }
    
    // <0x81621e0> items
    hyve::ll_h ListWidget::items() const {
        return ((QT::listWidget)this->__handle)->items;
    }
    void ListWidget::items( hyve::ll_h v) const {
        ((QT::listWidget)this->__handle)->items = v;
    }
    
    // ::hyve::lang::uint32 currentIndex
    ::hyve::lang::uint32 ListWidget::currentIndex() const {
        return ((QT::listWidget)this->__handle)->currentIndex;
    }
    void ListWidget::currentIndex( ::hyve::lang::uint32 v) const {
        ((QT::listWidget)this->__handle)->currentIndex = v;
    }
    
    // ::hyve::lang::string currentText
    ::hyve::lang::string ListWidget::currentText() const {
        return ((QT::listWidget)this->__handle)->currentText;
    }
    void ListWidget::currentText( ::hyve::lang::string v) const {
        if (((QT::listWidget)this->__handle)->currentText) {
            hyve::dealloc(((QT::listWidget)this->__handle)->currentText);
        };
        ((QT::listWidget)this->__handle)->currentText = v ? hyve::strdup(v) : NULL;
    }
    
    /* ::Qt::ListWidget::construct(::Qt::ListWidget object) */
    ::hyve::lang::int16 ListWidget::construct(const QT::ListWidget &object) {
    /* $begin(::Qt::ListWidget::construct(::Qt::ListWidget object)) */
        QListWidget *object_q;
        QWidget *parent_q; /* Parent handle to Qt object */
        hyve::lang::uint32 elements, i;
        QStringList strSeq;
        hyve::lang::string str;

        /* Obtain parent handle (Could also have been done using proxy-objects, but this is faster) */
        parent_q = (QWidget*)object.widgetParent();

        /* Create button */
        object_q = new QListWidget(parent_q);
        if (!object_q) {
            hyve::error("Qt::QListWidget::construct: failed to create object '%s'", object.nameof());
            goto error;
        }

        /* Add list-items */
        if (object.items()) {
            hyve::ll list;
            list = hyve::ll(object.items());
            elements = list.size();
            for(i=0; i<elements; i++) {
                str = *(char**)list.get(i);
                strSeq.append(QString::fromUtf8(str));
            }
            object_q->insertItems(0, strSeq);
        }

        /* Set handle */
        object.qhandle((hyve::lang::word)object_q);

        /* Call abstractbutton constructor */
        QT::Widget::construct(object);

        /* Show button */
        object_q->show();
        return 0;
    error:
        return -1;
    /* $end */
    }
    
    /* ::Qt::ListWidget::destruct(::Qt::ListWidget object) */
    ::hyve::lang::_void ListWidget::destruct(const QT::ListWidget &object) {
    /* $begin(::Qt::ListWidget::destruct(::Qt::ListWidget object)) */
        (void)object;
    /* $end */
    }
    
    /* ::Qt::ListWidget::insertItem(::hyve::lang::string label) */
    ::hyve::lang::_void ListWidget::insertItem(::hyve::lang::string label) const {
    /* $begin(::Qt::ListWidget::insertItem(::hyve::lang::string label)) */
        QListWidget *object_q;
        hyve::ll items;

        object_q = (QListWidget*)this->qhandle();
        object_q->insertItem(object_q->count() + 1, QString::fromUtf8(strdup(label)));
    /* $end */
    }
    
    /* ::Qt::ListWidget::onSelf */
    ::hyve::lang::_void ListWidget::onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::ListWidget::onSelf) */
        (void)observable;
        (void)source;
    /* $end */
    }
}

