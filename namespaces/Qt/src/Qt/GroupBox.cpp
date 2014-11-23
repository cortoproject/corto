/* src/Qt/GroupBox.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::GroupBox.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/GroupBox.hpp"
#include "Qt/_meta.hpp"

/* $begin($header) */
#include "QGroupBox"
/* $end */

namespace QT {
    
    // Constructor
    GroupBox::GroupBox(const QT::PaintEvent_t &paintEvent,
            const QT::MouseEvent_t &mousePressEvent,
             ::hyve::lang::int32 x,
             ::hyve::lang::int32 y,
             ::hyve::lang::int32 width,
             ::hyve::lang::int32 height,
             ::hyve::lang::_bool enabled,
             ::hyve::lang::_bool visible,
             ::hyve::lang::string styleSheet,
             ::hyve::lang::string title) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::GroupBox_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->title(title);
        this->define();
    }
    
    // Constructor (declare & define)
    GroupBox::GroupBox(::hyve::lang::Object *_parent,
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
             ::hyve::lang::string title) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::GroupBox_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->title(title);
        this->define();
    }
    
    // Construct from handle
    GroupBox::GroupBox(QT::groupBox handle, bool owner) : QT::Widget((QT::widget)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::groupBox GroupBox::_handle() const {
        return (QT::groupBox)this->__handle;
    }
    
    // ::hyve::lang::string title
    ::hyve::lang::string GroupBox::title() const {
        return ((QT::groupBox)this->__handle)->title;
    }
    void GroupBox::title( ::hyve::lang::string v) const {
        if (((QT::groupBox)this->__handle)->title) {
            hyve::dealloc(((QT::groupBox)this->__handle)->title);
        };
        ((QT::groupBox)this->__handle)->title = v ? hyve::strdup(v) : NULL;
    }
    
    /* ::Qt::GroupBox::construct(::Qt::GroupBox object) */
    ::hyve::lang::int16 GroupBox::construct(const QT::GroupBox &object) {
    /* $begin(::Qt::GroupBox::construct(::Qt::GroupBox object)) */
        QGroupBox *object_q;
        QWidget *parent_q; /* Parent handle to Qt object */

        /* Obtain parent handle (Could also have been done using proxy-objects, but this is faster) */
        parent_q = (QWidget*)object.widgetParent();

        object_q = new QGroupBox(parent_q);
        object.qhandle((hyve::lang::word)object_q);
        object_q->setTitle(QString::fromUtf8(object.title()));

        /* Call widget constructor for object */
        if (QT::Widget::construct(object)) {
            goto error;
        }

        /* Show object */
        object_q->show();

        return 0;
    error:
        return -1;
    /* $end */
    }
    
    /* ::Qt::GroupBox::destruct(::Qt::GroupBox object) */
    ::hyve::lang::_void GroupBox::destruct(const QT::GroupBox &object) {
    /* $begin(::Qt::GroupBox::destruct(::Qt::GroupBox object)) */
        (void)object;
    /* $end */
    }
}

