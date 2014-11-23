/* src/Qt/Slider.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::Slider.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/Slider.hpp"
#include "Qt/_meta.hpp"
#include "hyve/lang/Object.hpp"

/* $begin($header) */
#include "QSlider"
#include "hyve/lang/Observer.hpp"
#include "hyve/lang/Dispatcher.hpp"
#include "Qt/Application.hpp"

namespace QT {
    SliderSlots::SliderSlots(QT::slider handle, QSlider *handle_q) {
        this->handle = handle;
        this->handle_q = handle_q;
        QObject::connect(handle_q, SIGNAL(sliderMoved(int)), this, SLOT(sliderMoved(int)));
    }
    void SliderSlots::sliderMoved(int value) {
        if (!this->muted) {
            hyve::updateBegin(this->handle);
            this->handle->value = value;
            hyve::updateEndFrom(this->handle, this->handle);
        }
    }
}
/* $end */

namespace QT {
    
    // Constructor
    Slider::Slider(const QT::PaintEvent_t &paintEvent,
            const QT::MouseEvent_t &mousePressEvent,
             ::hyve::lang::int32 x,
             ::hyve::lang::int32 y,
             ::hyve::lang::int32 width,
             ::hyve::lang::int32 height,
             ::hyve::lang::_bool enabled,
             ::hyve::lang::_bool visible,
             ::hyve::lang::string styleSheet,
             ::hyve::lang::int32 value,
             ::hyve::lang::int32 minimum,
             ::hyve::lang::int32 maximum,
             ::hyve::lang::int32 singleStep,
             QT::Orientation orientation) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::Slider_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->value(value);
        this->minimum(minimum);
        this->maximum(maximum);
        this->singleStep(singleStep);
        this->orientation(orientation);
        this->define();
    }
    
    // Constructor (declare & define)
    Slider::Slider(::hyve::lang::Object *_parent,
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
             ::hyve::lang::int32 value,
             ::hyve::lang::int32 minimum,
             ::hyve::lang::int32 maximum,
             ::hyve::lang::int32 singleStep,
             QT::Orientation orientation) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::Slider_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->value(value);
        this->minimum(minimum);
        this->maximum(maximum);
        this->singleStep(singleStep);
        this->orientation(orientation);
        this->define();
    }
    
    // Construct from handle
    Slider::Slider(QT::slider handle, bool owner) : QT::Widget((QT::widget)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::slider Slider::_handle() const {
        return (QT::slider)this->__handle;
    }
    
    // ::hyve::lang::int32 value
    ::hyve::lang::int32 Slider::value() const {
        return ((QT::slider)this->__handle)->value;
    }
    void Slider::value( ::hyve::lang::int32 v) const {
        ((QT::slider)this->__handle)->value = v;
    }
    
    // ::hyve::lang::int32 minimum
    ::hyve::lang::int32 Slider::minimum() const {
        return ((QT::slider)this->__handle)->minimum;
    }
    void Slider::minimum( ::hyve::lang::int32 v) const {
        ((QT::slider)this->__handle)->minimum = v;
    }
    
    // ::hyve::lang::int32 maximum
    ::hyve::lang::int32 Slider::maximum() const {
        return ((QT::slider)this->__handle)->maximum;
    }
    void Slider::maximum( ::hyve::lang::int32 v) const {
        ((QT::slider)this->__handle)->maximum = v;
    }
    
    // ::hyve::lang::int32 singleStep
    ::hyve::lang::int32 Slider::singleStep() const {
        return ((QT::slider)this->__handle)->singleStep;
    }
    void Slider::singleStep( ::hyve::lang::int32 v) const {
        ((QT::slider)this->__handle)->singleStep = v;
    }
    
    // ::Qt::Orientation orientation
    QT::Orientation Slider::orientation() const {
        return ((QT::slider)this->__handle)->orientation;
    }
    void Slider::orientation( QT::Orientation v) const {
        ((QT::slider)this->__handle)->orientation = v;
    }
    
    /* ::Qt::Slider::construct(::Qt::Slider object) */
    ::hyve::lang::int16 Slider::construct(const QT::Slider &object) {
    /* $begin(::Qt::Slider::construct(::Qt::Slider object)) */
        QSlider *slider;
        QWidget *parent_q; /* Parent handle to Qt object */

        /* Obtain parent handle (Could also have been done using proxy-objects, but this is faster) */
        parent_q = (QWidget*)object.widgetParent();

        /* Create edit */
        slider = new QSlider(parent_q);
        if (!slider) {
            hyve::error("Qt::Slider::construct: failed to create button '%s'", object.nameof());
            goto error;
        }

        /* Install slots */
        object.qslots((hyve::lang::word)new QT::SliderSlots(object._handle(), slider));

        /* Set handle */
        object.qhandle((hyve::lang::word)slider);

        /* Set dispatcher for own observers */
        {
            hyve::lang::Observer onSelf(QT::Slider_onSelf_h); // Create proxy for template observer
            hyve::lang::Dispatcher dispatcher(QT::app(),false);
            onSelf.setDispatcher(dispatcher);
        }

        object.refresh();

        /* Show button */
        slider->show();
        return 0;
    error:
        return -1;
    /* $end */
    }
    
    /* ::Qt::Slider::destruct(::Qt::Slider object) */
    ::hyve::lang::_void Slider::destruct(const QT::Slider &object) {
    /* $begin(::Qt::Slider::destruct(::Qt::Slider object)) */

        /* << Insert implementation >> */

    /* $end */
    }
    
    /* ::Qt::Slider::onSelf */
    ::hyve::lang::_void Slider::onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::Slider::onSelf) */
        ((SliderSlots*)this->qslots())->mute(true);
        this->refresh();
        ((SliderSlots*)this->qslots())->mute(false);
    /* $end */
    }
    /* $begin($classfooter) */
    void Slider::refresh() const {
        QSlider *slider;
        slider = (QSlider*)this->qhandle();
        slider->setMaximum(this->maximum());
        slider->setMinimum(this->minimum());
        slider->setValue(this->value());
        slider->setSingleStep(this->singleStep());
        slider->setOrientation((Qt::Orientation)this->orientation());
    }
    /* $end */
}

