/* src/Qt/Label.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::Label.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/Label.hpp"
#include "Qt/_meta.hpp"
#include "hyve/lang/Object.hpp"

/* $begin($header) */
#include "QLabel"
/* $end */

namespace QT {
    
    // Constructor
    Label::Label(const QT::PaintEvent_t &paintEvent,
            const QT::MouseEvent_t &mousePressEvent,
             ::hyve::lang::int32 x,
             ::hyve::lang::int32 y,
             ::hyve::lang::int32 width,
             ::hyve::lang::int32 height,
             ::hyve::lang::_bool enabled,
             ::hyve::lang::_bool visible,
             ::hyve::lang::string styleSheet,
             ::hyve::lang::string text,
             QT::Alignment alignment) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::Label_h);
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
        this->alignment(alignment);
        this->define();
    }
    
    // Constructor (declare & define)
    Label::Label(::hyve::lang::Object *_parent,
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
             QT::Alignment alignment) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::Label_h);
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
        this->alignment(alignment);
        this->define();
    }
    
    // Construct from handle
    Label::Label(QT::label handle, bool owner) : QT::Widget((QT::widget)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::label Label::_handle() const {
        return (QT::label)this->__handle;
    }
    
    // ::hyve::lang::string text
    ::hyve::lang::string Label::text() const {
        return ((QT::label)this->__handle)->text;
    }
    void Label::text( ::hyve::lang::string v) const {
        if (((QT::label)this->__handle)->text) {
            hyve::dealloc(((QT::label)this->__handle)->text);
        };
        ((QT::label)this->__handle)->text = v ? hyve::strdup(v) : NULL;
    }
    
    // ::Qt::Alignment alignment
    QT::Alignment Label::alignment() const {
        return ((QT::label)this->__handle)->alignment;
    }
    void Label::alignment( QT::Alignment v) const {
        ((QT::label)this->__handle)->alignment = v;
    }
    
    /* ::Qt::Label::construct(::Qt::Label object) */
    ::hyve::lang::int16 Label::construct(const QT::Label &object) {
    /* $begin(::Qt::Label::construct(::Qt::Label object)) */
        QLabel *widget;
        QWidget *parent_q; /* Parent handle to Qt object */
        (void)object;

        /* Obtain parent handle (Could also have been done using proxy-objects, but this is faster) */
        parent_q = (QWidget*)object.widgetParent();

        /* Create button */
        widget = new QLabel(parent_q);
        if (!widget) {
            hyve::error("Qt::QLabel::construct: failed to create object '%s'", object.nameof());
            goto error;
        }

        /* Set handle */
        object.qhandle((hyve::lang::word)widget);

        /* Call abstractbutton constructor */
        QT::Widget::construct(object);

        // Update widget
        object.refresh();

        /* Show button */
        widget->show();
        return 0;
    error:
        return -1;
    /* $end */
    }
    
    /* ::Qt::Label::destruct(::Qt::Label object) */
    ::hyve::lang::_void Label::destruct(const QT::Label &object) {
    /* $begin(::Qt::Label::destruct(::Qt::Label object)) */
        (void)object;
    /* $end */
    }
    
    /* ::Qt::Label::init(::Qt::Label object) */
    ::hyve::lang::int16 Label::init(const QT::Label &object) {
    /* $begin(::Qt::Label::init(::Qt::Label object)) */
        object.alignment(QT::AlignLeft);
        return QT::Widget::init(object);
    /* $end */
    }
    
    /* ::Qt::Label::onSelf */
    ::hyve::lang::_void Label::onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::Label::onSelf) */
        this->refresh();
    /* $end */
    }
    
    /* ::Qt::Label::setText(::hyve::lang::string text) */
    ::hyve::lang::_void Label::setText(::hyve::lang::string text) const {
    /* $begin(::Qt::Label::setText(::hyve::lang::string text)) */
        this->updateBegin();
        this->text(text);
        this->refresh();
        this->updateEnd();
    /* $end */
    }
    /* $begin($classfooter) */
    void Label::refresh() const {
        QLabel *widget;
        widget = (QLabel*)this->qhandle();
        widget->setText(this->text());
        widget->setAlignment((Qt::Alignment)this->alignment());
    }
    /* $end */
}

