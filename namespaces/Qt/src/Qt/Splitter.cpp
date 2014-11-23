/* src/Qt/Splitter.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::Splitter.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/Splitter.hpp"
#include "Qt/_meta.hpp"
#include "hyve/lang/Object.hpp"

/* $begin($header) */
#include "QSplitter"
/* $end */

namespace QT {
    
    // Constructor
    Splitter::Splitter(const QT::PaintEvent_t &paintEvent,
            const QT::MouseEvent_t &mousePressEvent,
             ::hyve::lang::int32 x,
             ::hyve::lang::int32 y,
             ::hyve::lang::int32 width,
             ::hyve::lang::int32 height,
             ::hyve::lang::_bool enabled,
             ::hyve::lang::_bool visible,
             ::hyve::lang::string styleSheet,
             QT::SplitterItem_seq widgets,
             QT::Orientation orientation) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::Splitter_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->widgets(widgets);
        this->orientation(orientation);
        this->define();
    }
    
    // Constructor (declare & define)
    Splitter::Splitter(::hyve::lang::Object *_parent,
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
             QT::SplitterItem_seq widgets,
             QT::Orientation orientation) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::Splitter_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->widgets(widgets);
        this->orientation(orientation);
        this->define();
    }
    
    // Construct from handle
    Splitter::Splitter(QT::splitter handle, bool owner) : QT::Widget((QT::widget)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::splitter Splitter::_handle() const {
        return (QT::splitter)this->__handle;
    }
    
    // <0x8174668> widgets
    QT::SplitterItem_seq Splitter::widgets() const {
        return ((QT::splitter)this->__handle)->widgets;
    }
    void Splitter::widgets( QT::SplitterItem_seq v) const {
        ((QT::splitter)this->__handle)->widgets = v;
    }
    
    // ::Qt::Orientation orientation
    QT::Orientation Splitter::orientation() const {
        return ((QT::splitter)this->__handle)->orientation;
    }
    void Splitter::orientation( QT::Orientation v) const {
        ((QT::splitter)this->__handle)->orientation = v;
    }
    
    /* ::Qt::Splitter::construct(::Qt::Splitter object) */
    ::hyve::lang::int16 Splitter::construct(const QT::Splitter &object) {
    /* $begin(::Qt::Splitter::construct(::Qt::Splitter object)) */
        QSplitter *widget;
        QWidget *parent_q; /* Parent handle to Qt object */

        /* Obtain parent handle (Could also have been done using proxy-objects, but this is faster) */
        parent_q = (QWidget*)object.widgetParent();

        /* Create button */
        widget = new QSplitter(parent_q);
        if (!widget) {
            hyve::error("Qt::PushButton::construct: failed to create object '%s'", object.nameof());
            goto error;
        }

        /* Set handle */
        object.qhandle((hyve::lang::word)widget);

        /* Call abstractbutton constructor */
        QT::Widget::construct(object);

        /* Setup splitter */
        object.refresh();

        /* Show button */
        widget->show();
        return 0;
    error:
        return -1;
    /* $end */
    }
    
    /* ::Qt::Splitter::destruct(::Qt::Splitter object) */
    ::hyve::lang::_void Splitter::destruct(const QT::Splitter &object) {
    /* $begin(::Qt::Splitter::destruct(::Qt::Splitter object)) */
        (void)object;

        /* << Insert implementation >> */

    /* $end */
    }
    
    /* ::Qt::Splitter::init(::Qt::Splitter object) */
    ::hyve::lang::int16 Splitter::init(const QT::Splitter &object) {
    /* $begin(::Qt::Splitter::init(::Qt::Splitter object)) */
        object.orientation(QT::Horizontal);
        return QT::Widget::init(object);
    /* $end */
    }
    
    /* ::Qt::Splitter::onSelf */
    ::hyve::lang::_void Splitter::onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::Splitter::onSelf) */

        /* << Insert implementation >> */

    /* $end */
    }
    /* $begin($classfooter) */
    void Splitter::refresh() const {
        QSplitter *widget;
        QList<int> list;
        hyve::lang::uint32 i;
        QT::SplitterItem *item;

        widget = (QSplitter*)this->qhandle();

        widget->setOrientation((Qt::Orientation)this->orientation());

        for(i=0; i<this->widgets().length; i++) {
            item = &this->widgets().buffer[i];
            widget->addWidget((QWidget*)item->widget->_parent.qhandle);
            list.append(item->width);
            widget->setStretchFactor(i, item->stretch);
        }

        widget->setSizes(list);
    }
    /* $end */
}

