/* src/Qt/PaintEvent_t.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::paintEvent_t.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/PaintEvent_t.hpp"
#include "Qt/_meta.hpp"
#include "Qt/Painter.hpp"

namespace QT {
    
    // Constructor
    PaintEvent_t::PaintEvent_t(const QT::Painter &painter) : ::hyve::lang::Object((::hyve::lang::object)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::paintEvent_t_h);
        this->painter(painter);
        this->define();
    }
    
    // Constructor (declare & define)
    PaintEvent_t::PaintEvent_t(::hyve::lang::Object *_parent,
            ::hyve::lang::string _name,
            const QT::Painter &painter) : ::hyve::lang::Object((::hyve::lang::object)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::paintEvent_t_h);
        this->painter(painter);
        this->define();
    }
    
    // Construct from handle
    PaintEvent_t::PaintEvent_t(QT::paintEvent_t handle, bool owner) : ::hyve::lang::Object((::hyve::lang::object)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::paintEvent_t PaintEvent_t::_handle() const {
        return (QT::paintEvent_t)this->__handle;
    }
    
    // ::Qt::Painter painter
    QT::Painter PaintEvent_t::painter() const {
        QT::Painter result(((QT::paintEvent_t)this->__handle)->painter);
        return result;
    }
    void PaintEvent_t::painter(const QT::Painter &v) const {
        if (v) {
            hyve::set((hyve::lang::object*)&((QT::paintEvent_t)this->__handle)->painter, v._handle());
        } else {
            hyve::set((hyve::lang::object*)&((QT::paintEvent_t)this->__handle)->painter, NULL);
        }
    }
}

