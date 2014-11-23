/* src/Qt/ConicalGradient.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::ConicalGradient.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/ConicalGradient.hpp"
#include "Qt/_meta.hpp"

namespace QT {
    
    // Constructor
    ConicalGradient::ConicalGradient( QT::GradientStop_seq stops,
             QT::GradientCoordinateMode coordinateMode,
             QT::GradientSpread spread,
             QT::real angle,
             QT::PointF center) : QT::Gradient((QT::gradient)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::ConicalGradient_h);
        this->stops(stops);
        this->coordinateMode(coordinateMode);
        this->spread(spread);
        this->angle(angle);
        this->center(center);
        this->define();
    }
    
    // Constructor (declare & define)
    ConicalGradient::ConicalGradient(::hyve::lang::Object *_parent,
            ::hyve::lang::string _name,
             QT::GradientStop_seq stops,
             QT::GradientCoordinateMode coordinateMode,
             QT::GradientSpread spread,
             QT::real angle,
             QT::PointF center) : QT::Gradient((QT::gradient)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::ConicalGradient_h);
        this->stops(stops);
        this->coordinateMode(coordinateMode);
        this->spread(spread);
        this->angle(angle);
        this->center(center);
        this->define();
    }
    
    // Construct from handle
    ConicalGradient::ConicalGradient(QT::conicalGradient handle, bool owner) : QT::Gradient((QT::gradient)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::conicalGradient ConicalGradient::_handle() const {
        return (QT::conicalGradient)this->__handle;
    }
    
    // ::Qt::real angle
    QT::real ConicalGradient::angle() const {
        return ((QT::conicalGradient)this->__handle)->angle;
    }
    void ConicalGradient::angle( QT::real v) const {
        ((QT::conicalGradient)this->__handle)->angle = v;
    }
    
    // ::Qt::PointF center
    QT::PointF ConicalGradient::center() const {
        return ((QT::conicalGradient)this->__handle)->center;
    }
    void ConicalGradient::center( QT::PointF v) const {
        ((QT::conicalGradient)this->__handle)->center = v;
    }
    
    /* ::Qt::ConicalGradient::init(::Qt::ConicalGradient object) */
    ::hyve::lang::int16 ConicalGradient::init(const QT::ConicalGradient &object) {
    /* $begin(::Qt::ConicalGradient::init(::Qt::ConicalGradient object)) */
        object.kind(QT::Conical);
        return 0;
    /* $end */
    }
    /* $begin($classfooter) */
    void ConicalGradient::toQ(QT::conicalGradient f, QConicalGradient *q) {
        q->setCenter(f->center.x, f->center.y);
        q->setAngle(f->angle);
        QT::Gradient::toQ((QT::gradient)f, q);
    }

    /* $end */
}

