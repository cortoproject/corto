/* src/Qt/RadioButton.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::RadioButton.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/RadioButton.hpp"
#include "Qt/_meta.hpp"
#include "hyve/lang/Object.hpp"

/* $begin($header) */
#include "QRadioButton"
/* $end */

namespace QT {
    
    // Constructor
    RadioButton::RadioButton(const QT::PaintEvent_t &paintEvent,
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
             ::hyve::lang::_bool checked) : QT::AbstractButton((QT::abstractButton)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::RadioButton_h);
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
    RadioButton::RadioButton(::hyve::lang::Object *_parent,
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
             ::hyve::lang::_bool checked) : QT::AbstractButton((QT::abstractButton)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::RadioButton_h);
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
    RadioButton::RadioButton(QT::radioButton handle, bool owner) : QT::AbstractButton((QT::abstractButton)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::radioButton RadioButton::_handle() const {
        return (QT::radioButton)this->__handle;
    }
    
    /* ::Qt::RadioButton::construct(::Qt::RadioButton object) */
    ::hyve::lang::int16 RadioButton::construct(const QT::RadioButton &object) {
    /* $begin(::Qt::RadioButton::construct(::Qt::RadioButton object)) */
        QRadioButton *button;
        QWidget *parent_q; /* Parent handle to Qt object */

        /* Obtain parent handle (Could also have been done using proxy-objects, but this is faster) */
        parent_q = (QWidget*)object.widgetParent();

        /* Create button */
        button = new QRadioButton(parent_q);
        if (!button) {
            hyve::error("Qt::RadioButton::construct: failed to create object '%s'", object.nameof());
            goto error;
        }

        /* Set state to state of hyve object */
        button->setChecked(object.checked());

        /* Set checkable */
        object.checkable(true);

        /* Set handle */
        object.qhandle((hyve::lang::word)button);

        /* Call abstractbutton constructor */
        QT::AbstractButton::construct(object);

        /* Show button */
        button->show();
        return 0;
    error:
        return -1;
    /* $end */
    }
    
    /* ::Qt::RadioButton::destruct(::Qt::RadioButton object) */
    ::hyve::lang::_void RadioButton::destruct(const QT::RadioButton &object) {
    /* $begin(::Qt::RadioButton::destruct(::Qt::RadioButton object)) */
         (void)object;
    /* $end */
    }
    
    /* ::Qt::RadioButton::onSelf */
    ::hyve::lang::_void RadioButton::onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::RadioButton::onSelf) */
        SlotBase *slot;
        (void)observable;
        (void)source;
        slot = (AbstractButtonSlots*)this->qslots();
        slot->mute(true);
        this->refresh();
        slot->mute(false);
    /* $end */
    }
}

