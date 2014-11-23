/* src/Qt/LineEdit.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::LineEdit.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/LineEdit.hpp"
#include "Qt/_meta.hpp"
#include "hyve/lang/Object.hpp"

/* $begin($header) */
namespace QT {
    LineEditSlots::LineEditSlots(QT::lineEdit handle, QLineEdit *handle_q) {
        this->handle = handle;
        this->handle_q = handle_q;
        QObject::connect(handle_q, SIGNAL(textChanged(QString)), this, SLOT(textChanged(QString)));
    }
    void LineEditSlots::textChanged(QString string) {
        QByteArray data;
        hyve::lang::string str;
        if (!this->muted) {
            hyve::updateBegin(this->handle);

            if (this->handle->text) {
                hyve::dealloc(this->handle->text);
            }
            data = string.toUtf8();
            str = data.data();

            this->handle->text = hyve::strdup(str);

            hyve::updateEndFrom(this->handle, this->handle);
        }
    }
}
/* $end */

namespace QT {
    
    // Constructor
    LineEdit::LineEdit(const QT::PaintEvent_t &paintEvent,
            const QT::MouseEvent_t &mousePressEvent,
             ::hyve::lang::int32 x,
             ::hyve::lang::int32 y,
             ::hyve::lang::int32 width,
             ::hyve::lang::int32 height,
             ::hyve::lang::_bool enabled,
             ::hyve::lang::_bool visible,
             ::hyve::lang::string styleSheet,
             ::hyve::lang::string text,
             ::hyve::lang::_bool readonly) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::LineEdit_h);
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
        this->readonly(readonly);
        this->define();
    }
    
    // Constructor (declare & define)
    LineEdit::LineEdit(::hyve::lang::Object *_parent,
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
             ::hyve::lang::_bool readonly) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::LineEdit_h);
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
        this->readonly(readonly);
        this->define();
    }
    
    // Construct from handle
    LineEdit::LineEdit(QT::lineEdit handle, bool owner) : QT::Widget((QT::widget)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::lineEdit LineEdit::_handle() const {
        return (QT::lineEdit)this->__handle;
    }
    
    // ::hyve::lang::string text
    ::hyve::lang::string LineEdit::text() const {
        return ((QT::lineEdit)this->__handle)->text;
    }
    void LineEdit::text( ::hyve::lang::string v) const {
        if (((QT::lineEdit)this->__handle)->text) {
            hyve::dealloc(((QT::lineEdit)this->__handle)->text);
        };
        ((QT::lineEdit)this->__handle)->text = v ? hyve::strdup(v) : NULL;
    }
    
    // ::hyve::lang::bool readonly
    ::hyve::lang::_bool LineEdit::readonly() const {
        return ((QT::lineEdit)this->__handle)->readonly;
    }
    void LineEdit::readonly( ::hyve::lang::_bool v) const {
        ((QT::lineEdit)this->__handle)->readonly = v;
    }
    
    /* ::Qt::LineEdit::construct(::Qt::LineEdit object) */
    ::hyve::lang::int16 LineEdit::construct(const QT::LineEdit &object) {
    /* $begin(::Qt::LineEdit::construct(::Qt::LineEdit object)) */
        QLineEdit *edit;
        QWidget *parent_q; /* Parent handle to Qt object */

        /* Obtain parent handle (Could also have been done using proxy-objects, but this is faster) */
        parent_q = (QWidget*)object.widgetParent();

        /* Create edit */
        edit = new QLineEdit(parent_q);
        if (!edit) {
            hyve::error("Qt::LineEdit::construct: failed to create button '%s'", object.nameof());
            goto error;
        }

        /* Install slots */
        object.qslots((hyve::lang::word)new QT::LineEditSlots(object._handle(), edit));

        /* Set handle */
        object.qhandle((hyve::lang::word)edit);

        object.refresh();

        /* Show button */
        edit->show();
        return 0;
    error:
        return -1;
    /* $end */
    }
    
    /* ::Qt::LineEdit::destruct(::Qt::LineEdit object) */
    ::hyve::lang::_void LineEdit::destruct(const QT::LineEdit &object) {
    /* $begin(::Qt::LineEdit::destruct(::Qt::LineEdit object)) */
        delete (QT::LineEditSlots*)object.qslots();
    /* $end */
    }
    
    /* ::Qt::LineEdit::onSelf */
    ::hyve::lang::_void LineEdit::onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::LineEdit::onSelf) */
        (void)observable;
        (void)source;
        ((LineEditSlots*)this->qslots())->mute(true);
        this->refresh();
        ((LineEditSlots*)this->qslots())->mute(false);
    /* $end */
    }
    /* $begin($classfooter) */
    void LineEdit::refresh() const {
        QLineEdit *edit;

        edit = (QLineEdit*)this->qhandle();

        /* Set text */
        edit->setText(this->text());
        ((QT::Widget*)this)->refresh();
    }
    /* $end */
}

