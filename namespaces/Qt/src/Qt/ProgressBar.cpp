/* src/Qt/ProgressBar.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::ProgressBar.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/ProgressBar.hpp"
#include "Qt/_meta.hpp"
#include "hyve/lang/Object.hpp"

/* $begin($header) */
#include "QProgressBar"
#include "hyve/lang/Observer.hpp"
#include "hyve/lang/Dispatcher.hpp"
#include "Qt/Application.hpp"
/* $end */

namespace QT {
    
    // Constructor
    ProgressBar::ProgressBar(const QT::PaintEvent_t &paintEvent,
            const QT::MouseEvent_t &mousePressEvent,
             ::hyve::lang::int32 x,
             ::hyve::lang::int32 y,
             ::hyve::lang::int32 width,
             ::hyve::lang::int32 height,
             ::hyve::lang::_bool enabled,
             ::hyve::lang::_bool visible,
             ::hyve::lang::string styleSheet,
             ::hyve::lang::int32 minimum,
             ::hyve::lang::int32 maximum,
             ::hyve::lang::int32 value,
             QT::Orientation orientation,
             ::hyve::lang::string text,
             ::hyve::lang::string format) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::ProgressBar_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->minimum(minimum);
        this->maximum(maximum);
        this->value(value);
        this->orientation(orientation);
        this->text(text);
        this->format(format);
        this->define();
    }
    
    // Constructor (declare & define)
    ProgressBar::ProgressBar(::hyve::lang::Object *_parent,
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
             ::hyve::lang::int32 minimum,
             ::hyve::lang::int32 maximum,
             ::hyve::lang::int32 value,
             QT::Orientation orientation,
             ::hyve::lang::string text,
             ::hyve::lang::string format) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::ProgressBar_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->minimum(minimum);
        this->maximum(maximum);
        this->value(value);
        this->orientation(orientation);
        this->text(text);
        this->format(format);
        this->define();
    }
    
    // Construct from handle
    ProgressBar::ProgressBar(QT::progressBar handle, bool owner) : QT::Widget((QT::widget)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::progressBar ProgressBar::_handle() const {
        return (QT::progressBar)this->__handle;
    }
    
    // ::hyve::lang::int32 minimum
    ::hyve::lang::int32 ProgressBar::minimum() const {
        return ((QT::progressBar)this->__handle)->minimum;
    }
    void ProgressBar::minimum( ::hyve::lang::int32 v) const {
        ((QT::progressBar)this->__handle)->minimum = v;
    }
    
    // ::hyve::lang::int32 maximum
    ::hyve::lang::int32 ProgressBar::maximum() const {
        return ((QT::progressBar)this->__handle)->maximum;
    }
    void ProgressBar::maximum( ::hyve::lang::int32 v) const {
        ((QT::progressBar)this->__handle)->maximum = v;
    }
    
    // ::hyve::lang::int32 value
    ::hyve::lang::int32 ProgressBar::value() const {
        return ((QT::progressBar)this->__handle)->value;
    }
    void ProgressBar::value( ::hyve::lang::int32 v) const {
        ((QT::progressBar)this->__handle)->value = v;
    }
    
    // ::Qt::Orientation orientation
    QT::Orientation ProgressBar::orientation() const {
        return ((QT::progressBar)this->__handle)->orientation;
    }
    void ProgressBar::orientation( QT::Orientation v) const {
        ((QT::progressBar)this->__handle)->orientation = v;
    }
    
    // ::hyve::lang::string text
    ::hyve::lang::string ProgressBar::text() const {
        return ((QT::progressBar)this->__handle)->text;
    }
    void ProgressBar::text( ::hyve::lang::string v) const {
        if (((QT::progressBar)this->__handle)->text) {
            hyve::dealloc(((QT::progressBar)this->__handle)->text);
        };
        ((QT::progressBar)this->__handle)->text = v ? hyve::strdup(v) : NULL;
    }
    
    // ::hyve::lang::string format
    ::hyve::lang::string ProgressBar::format() const {
        return ((QT::progressBar)this->__handle)->format;
    }
    void ProgressBar::format( ::hyve::lang::string v) const {
        if (((QT::progressBar)this->__handle)->format) {
            hyve::dealloc(((QT::progressBar)this->__handle)->format);
        };
        ((QT::progressBar)this->__handle)->format = v ? hyve::strdup(v) : NULL;
    }
    
    /* ::Qt::ProgressBar::construct(::Qt::ProgressBar object) */
    ::hyve::lang::int16 ProgressBar::construct(const QT::ProgressBar &object) {
    /* $begin(::Qt::ProgressBar::construct(::Qt::ProgressBar object)) */
        QProgressBar *bar;
        QWidget *parent_q; /* Parent handle to Qt object */

        /* Obtain parent handle (Could also have been done using proxy-objects, but this is faster) */
        parent_q = (QWidget*)object.widgetParent();

        /* Create edit */
        bar = new QProgressBar(parent_q);
        if (!bar) {
            hyve::error("Qt::ProgressBar::construct: failed to create '%s'", object.nameof());
            goto error;
        }

        /* Set handle */
        object.qhandle((hyve::lang::word)bar);

        /* Set dispatcher for own observers */
        {
            hyve::lang::Observer onSelf(QT::ProgressBar_onSelf_h); // Create proxy for template observer
            hyve::lang::Dispatcher dispatcher(QT::app(),false);
            onSelf.setDispatcher(dispatcher);
        }

        object.refresh();

        /* Show button */
        bar->show();

        return QT::Widget::construct(object);
    error:
        return -1;
    /* $end */
    }
    
    /* ::Qt::ProgressBar::destruct(::Qt::ProgressBar object) */
    ::hyve::lang::_void ProgressBar::destruct(const QT::ProgressBar &object) {
    /* $begin(::Qt::ProgressBar::destruct(::Qt::ProgressBar object)) */

        /* << Insert implementation >> */

    /* $end */
    }
    
    /* ::Qt::ProgressBar::onSelf */
    ::hyve::lang::_void ProgressBar::onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::ProgressBar::onSelf) */
        this->refresh();
    /* $end */
    }
    /* $begin($classfooter) */
    void ProgressBar::refresh() const {
        QProgressBar *bar;
        bar = (QProgressBar*)this->qhandle();
        bar->setMaximum(this->maximum());
        bar->setMinimum(this->minimum());
        bar->setValue(this->value());
        bar->setOrientation((Qt::Orientation)this->orientation());
        bar->setFormat(this->_handle()->format);
        if (this->_handle()->format) {
            bar->setTextVisible(true);
        }
    }
    /* $end */
}

