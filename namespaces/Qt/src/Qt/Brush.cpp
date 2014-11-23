/* src/Qt/Brush.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::Brush.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/Brush.hpp"
#include "Qt/_meta.hpp"
#include "Qt/Gradient.hpp"

/* $begin($header) */
#include "QBrush"
#include "Qt/ConicalGradient.hpp"
#include "Qt/LinearGradient.hpp"
#include "Qt/RadialGradient.hpp"
/* $end */

namespace QT {
    
    // Constructor
    Brush::Brush( QT::Color color,
            const QT::Gradient &gradient) : QT::Object((QT::object)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::Brush_h);
        this->color(color);
        this->gradient(gradient);
        this->define();
    }
    
    // Constructor (declare & define)
    Brush::Brush(::hyve::lang::Object *_parent,
            ::hyve::lang::string _name,
             QT::Color color,
            const QT::Gradient &gradient) : QT::Object((QT::object)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::Brush_h);
        this->color(color);
        this->gradient(gradient);
        this->define();
    }
    
    // Construct from handle
    Brush::Brush(QT::brush handle, bool owner) : QT::Object((QT::object)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::brush Brush::_handle() const {
        return (QT::brush)this->__handle;
    }
    
    // ::Qt::Color color
    QT::Color Brush::color() const {
        return ((QT::brush)this->__handle)->color;
    }
    void Brush::color( QT::Color v) const {
        ((QT::brush)this->__handle)->color = v;
    }
    
    // ::Qt::Gradient gradient
    QT::Gradient Brush::gradient() const {
        QT::Gradient result(((QT::brush)this->__handle)->gradient);
        return result;
    }
    void Brush::gradient(const QT::Gradient &v) const {
        if (v) {
            hyve::set((hyve::lang::object*)&((QT::brush)this->__handle)->gradient, v._handle());
        } else {
            hyve::set((hyve::lang::object*)&((QT::brush)this->__handle)->gradient, NULL);
        }
    }
    
    /* ::Qt::Brush::construct(::Qt::Brush object) */
    ::hyve::lang::int16 Brush::construct(const QT::Brush &object) {
    /* $begin(::Qt::Brush::construct(::Qt::Brush object)) */
        QBrush *brush;
        QT::gradient f;

        if (!object._handle()->gradient) {
            QColor c(object.color().r, object.color().g, object.color().b, object.color().alpha);
            brush = new QBrush(c);
        } else {
            f = object._handle()->gradient;
            switch(f->kind) {
            case QT::Conical: {
                QConicalGradient q;
                QT::ConicalGradient::toQ((QT::conicalGradient)f, &q);
                brush = new QBrush(q);
                break;
            }
            case QT::Linear: {
                QLinearGradient q;
                QT::LinearGradient::toQ((QT::linearGradient)f, &q);
                brush = new QBrush(q);
                break;
            }
            case QT::Radial: {
                QRadialGradient q;
                QT::RadialGradient::toQ((QT::radialGradient)f, &q);
                brush = new QBrush(q);
                break;
            }
            }
        }

        object.qhandle((hyve::lang::word)brush);

        return 0;
    /* $end */
    }
    
    /* ::Qt::Brush::destruct(::Qt::Brush object) */
    ::hyve::lang::_void Brush::destruct(const QT::Brush &object) {
    /* $begin(::Qt::Brush::destruct(::Qt::Brush object)) */
        QBrush *brush;
        brush = (QBrush*)object.qhandle();
        delete brush;
    /* $end */
    }
}

