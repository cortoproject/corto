/* src/Qt/RadialGradient.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::RadialGradient.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/RadialGradient.hpp"
#include "Qt/_meta.hpp"

/* $begin($header) */
#include "QRadialGradient"
/* $end */

namespace QT {
    
    // Constructor
    RadialGradient::RadialGradient( QT::GradientStop_seq stops,
             QT::GradientCoordinateMode coordinateMode,
             QT::GradientSpread spread,
             QT::PointF center,
             QT::PointF focalPoint,
             QT::real radius) : QT::Gradient((QT::gradient)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::RadialGradient_h);
        this->stops(stops);
        this->coordinateMode(coordinateMode);
        this->spread(spread);
        this->center(center);
        this->focalPoint(focalPoint);
        this->radius(radius);
        this->define();
    }
    
    // Constructor (declare & define)
    RadialGradient::RadialGradient(::hyve::lang::Object *_parent,
            ::hyve::lang::string _name,
             QT::GradientStop_seq stops,
             QT::GradientCoordinateMode coordinateMode,
             QT::GradientSpread spread,
             QT::PointF center,
             QT::PointF focalPoint,
             QT::real radius) : QT::Gradient((QT::gradient)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::RadialGradient_h);
        this->stops(stops);
        this->coordinateMode(coordinateMode);
        this->spread(spread);
        this->center(center);
        this->focalPoint(focalPoint);
        this->radius(radius);
        this->define();
    }
    
    // Construct from handle
    RadialGradient::RadialGradient(QT::radialGradient handle, bool owner) : QT::Gradient((QT::gradient)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::radialGradient RadialGradient::_handle() const {
        return (QT::radialGradient)this->__handle;
    }
    
    // ::Qt::PointF center
    QT::PointF RadialGradient::center() const {
        return ((QT::radialGradient)this->__handle)->center;
    }
    void RadialGradient::center( QT::PointF v) const {
        ((QT::radialGradient)this->__handle)->center = v;
    }
    
    // ::Qt::PointF focalPoint
    QT::PointF RadialGradient::focalPoint() const {
        return ((QT::radialGradient)this->__handle)->focalPoint;
    }
    void RadialGradient::focalPoint( QT::PointF v) const {
        ((QT::radialGradient)this->__handle)->focalPoint = v;
    }
    
    // ::Qt::real radius
    QT::real RadialGradient::radius() const {
        return ((QT::radialGradient)this->__handle)->radius;
    }
    void RadialGradient::radius( QT::real v) const {
        ((QT::radialGradient)this->__handle)->radius = v;
    }
    
    /* ::Qt::RadialGradient::init(::Qt::RadialGradient object) */
    ::hyve::lang::int16 RadialGradient::init(const QT::RadialGradient &object) {
    /* $begin(::Qt::RadialGradient::init(::Qt::RadialGradient object)) */
        object.kind(QT::Radial);
        return 0;
    /* $end */
    }
    /* $begin($classfooter) */
    void RadialGradient::toQ(QT::radialGradient f, QRadialGradient *q) {
        q->setCenter(f->center.x, f->center.y);
        q->setFocalPoint(f->focalPoint.x, f->focalPoint.y);
        q->setRadius(f->radius);
        QT::Gradient::toQ((QT::gradient)f, q);
    }

    /* $end */
}

