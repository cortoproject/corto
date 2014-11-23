/* src/Qt/CheckBox.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::CheckBox.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/CheckBox.hpp"
#include "Qt/_meta.hpp"
#include "hyve/lang/Object.hpp"

/* $begin($header) */
#include "QCheckBox"
/* $end */

namespace QT {
    
    // Constructor
    CheckBox::CheckBox(const QT::PaintEvent_t &paintEvent,
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
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::CheckBox_h);
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
    CheckBox::CheckBox(::hyve::lang::Object *_parent,
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
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::CheckBox_h);
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
    CheckBox::CheckBox(QT::checkBox handle, bool owner) : QT::AbstractButton((QT::abstractButton)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::checkBox CheckBox::_handle() const {
        return (QT::checkBox)this->__handle;
    }
    
    /* ::Qt::CheckBox::construct(::Qt::CheckBox object) */
    ::hyve::lang::int16 CheckBox::construct(const QT::CheckBox &object) {
    /* $begin(::Qt::CheckBox::construct(::Qt::CheckBox object)) */
        QCheckBox *button;
        QWidget *parent_q; /* Parent handle to Qt object */

        /* Obtain parent handle (Could also have been done using proxy-objects, but this is faster) */
        parent_q = (QWidget*)object.widgetParent();

        /* Create button */
        button = new QCheckBox(parent_q);
        if (!button) {
            hyve::error("Qt::CheckBox::construct: failed to create object '%s'", object.nameof());
            goto error;
        }

        /* Set handle */
        object.qhandle((hyve::lang::word)button);

        /* Set checkable to true */
        object.checkable(true);

        /* Call abstractbutton constructor */
        QT::AbstractButton::construct(object);

        /* Refresh */
        object.refresh();

        /* Show button */
        button->show();
        return 0;
    error:
        return -1;
    /* $end */
    }
    
    /* ::Qt::CheckBox::destruct(::Qt::CheckBox object) */
    ::hyve::lang::_void CheckBox::destruct(const QT::CheckBox &object) {
    /* $begin(::Qt::CheckBox::destruct(::Qt::CheckBox object)) */
        (void)object;
    /* $end */
    }
    
    /* ::Qt::CheckBox::onSelf */
    ::hyve::lang::_void CheckBox::onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::CheckBox::onSelf) */
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

