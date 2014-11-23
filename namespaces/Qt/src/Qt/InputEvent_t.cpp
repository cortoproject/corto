/* src/Qt/InputEvent_t.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::inputEvent_t.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/InputEvent_t.hpp"
#include "Qt/_meta.hpp"

namespace QT {
    
    // Constructor
    InputEvent_t::InputEvent_t( QT::KeyboardModifiers modifiers) : ::hyve::lang::Object((::hyve::lang::object)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::inputEvent_t_h);
        this->modifiers(modifiers);
        this->define();
    }
    
    // Constructor (declare & define)
    InputEvent_t::InputEvent_t(::hyve::lang::Object *_parent,
            ::hyve::lang::string _name,
             QT::KeyboardModifiers modifiers) : ::hyve::lang::Object((::hyve::lang::object)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::inputEvent_t_h);
        this->modifiers(modifiers);
        this->define();
    }
    
    // Construct from handle
    InputEvent_t::InputEvent_t(QT::inputEvent_t handle, bool owner) : ::hyve::lang::Object((::hyve::lang::object)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::inputEvent_t InputEvent_t::_handle() const {
        return (QT::inputEvent_t)this->__handle;
    }
    
    // ::Qt::KeyboardModifiers modifiers
    QT::KeyboardModifiers InputEvent_t::modifiers() const {
        return ((QT::inputEvent_t)this->__handle)->modifiers;
    }
    void InputEvent_t::modifiers( QT::KeyboardModifiers v) const {
        ((QT::inputEvent_t)this->__handle)->modifiers = v;
    }
}

