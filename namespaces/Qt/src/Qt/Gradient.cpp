/* src/Qt/Gradient.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::Gradient.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/Gradient.hpp"
#include "Qt/_meta.hpp"

/* $begin($header) */
#include "QGradient"
/* $end */

namespace QT {
    
    // Constructor
    Gradient::Gradient( QT::GradientStop_seq stops,
             QT::GradientCoordinateMode coordinateMode,
             QT::GradientSpread spread) : QT::Object((QT::object)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::Gradient_h);
        this->stops(stops);
        this->coordinateMode(coordinateMode);
        this->spread(spread);
        this->define();
    }
    
    // Constructor (declare & define)
    Gradient::Gradient(::hyve::lang::Object *_parent,
            ::hyve::lang::string _name,
             QT::GradientStop_seq stops,
             QT::GradientCoordinateMode coordinateMode,
             QT::GradientSpread spread) : QT::Object((QT::object)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::Gradient_h);
        this->stops(stops);
        this->coordinateMode(coordinateMode);
        this->spread(spread);
        this->define();
    }
    
    // Construct from handle
    Gradient::Gradient(QT::gradient handle, bool owner) : QT::Object((QT::object)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::gradient Gradient::_handle() const {
        return (QT::gradient)this->__handle;
    }
    
    // ::Qt::GradientKind kind
    QT::GradientKind Gradient::kind() const {
        return ((QT::gradient)this->__handle)->kind;
    }
    void Gradient::kind( QT::GradientKind v) const {
        ((QT::gradient)this->__handle)->kind = v;
    }
    
    // <0x810a898> stops
    QT::GradientStop_seq Gradient::stops() const {
        return ((QT::gradient)this->__handle)->stops;
    }
    void Gradient::stops( QT::GradientStop_seq v) const {
        ((QT::gradient)this->__handle)->stops = v;
    }
    
    // ::Qt::GradientCoordinateMode coordinateMode
    QT::GradientCoordinateMode Gradient::coordinateMode() const {
        return ((QT::gradient)this->__handle)->coordinateMode;
    }
    void Gradient::coordinateMode( QT::GradientCoordinateMode v) const {
        ((QT::gradient)this->__handle)->coordinateMode = v;
    }
    
    // ::Qt::GradientSpread spread
    QT::GradientSpread Gradient::spread() const {
        return ((QT::gradient)this->__handle)->spread;
    }
    void Gradient::spread( QT::GradientSpread v) const {
        ((QT::gradient)this->__handle)->spread = v;
    }
    /* $begin($classfooter) */
    void Gradient::toQ(QT::gradient f, QGradient* q) {
        QT::GradientStop *stop;
        hyve::lang::uint32 i;

        /* Set stops of gradient */
        for(i=0; i<f->stops.length; i++) {
            stop = &f->stops.buffer[i];
            q->setColorAt(stop->pos, QColor(stop->color.r, stop->color.g, stop->color.b, stop->color.alpha));
        }

        q->setSpread((QGradient::Spread)f->spread);
        q->setCoordinateMode((QGradient::CoordinateMode)f->coordinateMode);
    }

    /* $end */
}

