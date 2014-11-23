/* src/Qt/AbstractButton.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::AbstractButton.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/AbstractButton.hpp"
#include "Qt/_meta.hpp"

/* $begin($header) */
namespace QT {
    AbstractButtonSlots::AbstractButtonSlots(QT::abstractButton handle, QAbstractButton *handle_q) {
        this->handle = handle;
        this->handle_q = handle_q;
        QObject::connect(handle_q, SIGNAL(pressed()), this, SLOT(pressed()));
        QObject::connect(handle_q, SIGNAL(toggled(bool)), this, SLOT(toggled(bool)));
    }
    void AbstractButtonSlots::pressed() {
        if (!handle->checkable && !this->muted) {
            hyve::updateFrom(this->handle, this->handle);
        }
    }
    void AbstractButtonSlots::toggled(bool checked) {
        if (!this->muted) {
            hyve::updateBegin(this->handle);
            this->handle->checked = checked;
            hyve::updateEndFrom(this->handle, this->handle);
        }
    }
}
/* $end */

namespace QT {
    
    // Constructor
    AbstractButton::AbstractButton(const QT::PaintEvent_t &paintEvent,
            const QT::MouseEvent_t &mousePressEvent,
             ::hyve::lang::int32 x,
             ::hyve::lang::int32 y,
             ::hyve::lang::int32 width,
             ::hyve::lang::int32 height,
             ::hyve::lang::_bool enabled,
             ::hyve::lang::_bool visible,
             ::hyve::lang::string styleSheet,
             ::hyve::lang::string text,
             ::hyve::lang::_bool checkable,
             ::hyve::lang::_bool down,
             ::hyve::lang::_bool checked) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::AbstractButton_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->text(text);
        this->checkable(checkable);
        this->down(down);
        this->checked(checked);
        this->define();
    }
    
    // Constructor (declare & define)
    AbstractButton::AbstractButton(::hyve::lang::Object *_parent,
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
             ::hyve::lang::string text,
             ::hyve::lang::_bool checkable,
             ::hyve::lang::_bool down,
             ::hyve::lang::_bool checked) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::AbstractButton_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->text(text);
        this->checkable(checkable);
        this->down(down);
        this->checked(checked);
        this->define();
    }
    
    // Construct from handle
    AbstractButton::AbstractButton(QT::abstractButton handle, bool owner) : QT::Widget((QT::widget)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::abstractButton AbstractButton::_handle() const {
        return (QT::abstractButton)this->__handle;
    }
    
    // ::hyve::lang::string text
    ::hyve::lang::string AbstractButton::text() const {
        return ((QT::abstractButton)this->__handle)->text;
    }
    void AbstractButton::text( ::hyve::lang::string v) const {
        if (((QT::abstractButton)this->__handle)->text) {
            hyve::dealloc(((QT::abstractButton)this->__handle)->text);
        };
        ((QT::abstractButton)this->__handle)->text = v ? hyve::strdup(v) : NULL;
    }
    
    // ::hyve::lang::bool checkable
    ::hyve::lang::_bool AbstractButton::checkable() const {
        return ((QT::abstractButton)this->__handle)->checkable;
    }
    void AbstractButton::checkable( ::hyve::lang::_bool v) const {
        ((QT::abstractButton)this->__handle)->checkable = v;
    }
    
    // ::hyve::lang::bool down
    ::hyve::lang::_bool AbstractButton::down() const {
        return ((QT::abstractButton)this->__handle)->down;
    }
    void AbstractButton::down( ::hyve::lang::_bool v) const {
        ((QT::abstractButton)this->__handle)->down = v;
    }
    
    // ::hyve::lang::bool checked
    ::hyve::lang::_bool AbstractButton::checked() const {
        return ((QT::abstractButton)this->__handle)->checked;
    }
    void AbstractButton::checked( ::hyve::lang::_bool v) const {
        ((QT::abstractButton)this->__handle)->checked = v;
    }
    
    /* ::Qt::AbstractButton::construct(::Qt::AbstractButton object) */
    ::hyve::lang::int16 AbstractButton::construct(const QT::AbstractButton &object) {
    /* $begin(::Qt::AbstractButton::construct(::Qt::AbstractButton object)) */
        QAbstractButton *button_q;

        /* Obtain button object */
        button_q = (QAbstractButton*)object.qhandle();

        /* Setup slots if not set by specialized class */
        if (!object.qslots()) {
            object.qslots((hyve::lang::word)new AbstractButtonSlots(object._handle(), button_q));
        }

        /* Call widget constructor */
        if (QT::Widget::construct(object)) {
            goto error;
        }

        object.refresh();

        return 0;
    error:
        return -1;
    /* $end */
    }
    
    /* ::Qt::AbstractButton::destruct(::Qt::AbstractButton object) */
    ::hyve::lang::_void AbstractButton::destruct(const QT::AbstractButton &object) {
    /* $begin(::Qt::AbstractButton::destruct(::Qt::AbstractButton object)) */
        /* Free slots */
        delete (AbstractButtonSlots*)object.qslots();
    /* $end */
    }
    /* $begin($classfooter) */
    void AbstractButton::refresh() const {
        QAbstractButton *widget;
        widget = (QAbstractButton*)this->qhandle();

        /* Set button text */
        widget->setText(QString::fromUtf8(this->text()));

        /* Check or uncheck button */
        widget->setChecked(this->checked());

        ((Widget*)this)->refresh();
    }
    /* $end */
}

