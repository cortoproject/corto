/* src/Qt/MouseEvent_t.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::mouseEvent_t.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/MouseEvent_t.hpp"
#include "Qt/_meta.hpp"

namespace QT {
    
    // Constructor
    MouseEvent_t::MouseEvent_t( QT::KeyboardModifiers modifiers,
             ::hyve::lang::int32 x,
             ::hyve::lang::int32 y,
             QT::MouseButton buttons) : QT::InputEvent_t((QT::inputEvent_t)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::mouseEvent_t_h);
        this->modifiers(modifiers);
        this->x(x);
        this->y(y);
        this->buttons(buttons);
        this->define();
    }
    
    // Constructor (declare & define)
    MouseEvent_t::MouseEvent_t(::hyve::lang::Object *_parent,
            ::hyve::lang::string _name,
             QT::KeyboardModifiers modifiers,
             ::hyve::lang::int32 x,
             ::hyve::lang::int32 y,
             QT::MouseButton buttons) : QT::InputEvent_t((QT::inputEvent_t)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::mouseEvent_t_h);
        this->modifiers(modifiers);
        this->x(x);
        this->y(y);
        this->buttons(buttons);
        this->define();
    }
    
    // Construct from handle
    MouseEvent_t::MouseEvent_t(QT::mouseEvent_t handle, bool owner) : QT::InputEvent_t((QT::inputEvent_t)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::mouseEvent_t MouseEvent_t::_handle() const {
        return (QT::mouseEvent_t)this->__handle;
    }
    
    // ::hyve::lang::int32 x
    ::hyve::lang::int32 MouseEvent_t::x() const {
        return ((QT::mouseEvent_t)this->__handle)->x;
    }
    void MouseEvent_t::x( ::hyve::lang::int32 v) const {
        ((QT::mouseEvent_t)this->__handle)->x = v;
    }
    
    // ::hyve::lang::int32 y
    ::hyve::lang::int32 MouseEvent_t::y() const {
        return ((QT::mouseEvent_t)this->__handle)->y;
    }
    void MouseEvent_t::y( ::hyve::lang::int32 v) const {
        ((QT::mouseEvent_t)this->__handle)->y = v;
    }
    
    // ::Qt::MouseButton buttons
    QT::MouseButton MouseEvent_t::buttons() const {
        return ((QT::mouseEvent_t)this->__handle)->buttons;
    }
    void MouseEvent_t::buttons( QT::MouseButton v) const {
        ((QT::mouseEvent_t)this->__handle)->buttons = v;
    }
}

