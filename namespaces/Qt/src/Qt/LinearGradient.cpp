/* src/Qt/LinearGradient.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::LinearGradient.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/LinearGradient.hpp"
#include "Qt/_meta.hpp"

/* $begin($header) */
#include "QLinearGradient"
/* $end */

namespace QT {
    
    // Constructor
    LinearGradient::LinearGradient( QT::GradientStop_seq stops,
             QT::GradientCoordinateMode coordinateMode,
             QT::GradientSpread spread,
             QT::PointF start,
             QT::PointF finalStop) : QT::Gradient((QT::gradient)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::LinearGradient_h);
        this->stops(stops);
        this->coordinateMode(coordinateMode);
        this->spread(spread);
        this->start(start);
        this->finalStop(finalStop);
        this->define();
    }
    
    // Constructor (declare & define)
    LinearGradient::LinearGradient(::hyve::lang::Object *_parent,
            ::hyve::lang::string _name,
             QT::GradientStop_seq stops,
             QT::GradientCoordinateMode coordinateMode,
             QT::GradientSpread spread,
             QT::PointF start,
             QT::PointF finalStop) : QT::Gradient((QT::gradient)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::LinearGradient_h);
        this->stops(stops);
        this->coordinateMode(coordinateMode);
        this->spread(spread);
        this->start(start);
        this->finalStop(finalStop);
        this->define();
    }
    
    // Construct from handle
    LinearGradient::LinearGradient(QT::linearGradient handle, bool owner) : QT::Gradient((QT::gradient)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::linearGradient LinearGradient::_handle() const {
        return (QT::linearGradient)this->__handle;
    }
    
    // ::Qt::PointF start
    QT::PointF LinearGradient::start() const {
        return ((QT::linearGradient)this->__handle)->start;
    }
    void LinearGradient::start( QT::PointF v) const {
        ((QT::linearGradient)this->__handle)->start = v;
    }
    
    // ::Qt::PointF finalStop
    QT::PointF LinearGradient::finalStop() const {
        return ((QT::linearGradient)this->__handle)->finalStop;
    }
    void LinearGradient::finalStop( QT::PointF v) const {
        ((QT::linearGradient)this->__handle)->finalStop = v;
    }
    
    /* ::Qt::LinearGradient::init(::Qt::LinearGradient object) */
    ::hyve::lang::int16 LinearGradient::init(const QT::LinearGradient &object) {
    /* $begin(::Qt::LinearGradient::init(::Qt::LinearGradient object)) */
        object.kind(QT::Linear);
        return 0;
    /* $end */
    }
    /* $begin($classfooter) */
    void LinearGradient::toQ(QT::linearGradient f, QLinearGradient *q) {
        q->setStart(f->start.x, f->start.y);
        q->setFinalStop(f->finalStop.x, f->finalStop.y);
        QT::Gradient::toQ((QT::gradient)f,q);
    }

    /* $end */
}

