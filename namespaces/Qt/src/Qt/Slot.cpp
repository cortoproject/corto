/* src/Qt/Slot.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::slot.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/Slot.hpp"
#include "Qt/_meta.hpp"

namespace QT {
    
    // Constructor
    Slot::Slot(const ::hyve::lang::Typedef &type,
             ::hyve::lang::modifier modifiers,
             ::hyve::lang::state state,
             ::hyve::lang::_bool weak) : ::hyve::lang::Member((::hyve::lang::member)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::slot_h);
        this->type(type);
        this->modifiers(modifiers);
        this->state(state);
        this->weak(weak);
        this->define();
    }
    
    // Constructor (declare & define)
    Slot::Slot(::hyve::lang::Object *_parent,
            ::hyve::lang::string _name,
            const ::hyve::lang::Typedef &type,
             ::hyve::lang::modifier modifiers,
             ::hyve::lang::state state,
             ::hyve::lang::_bool weak) : ::hyve::lang::Member((::hyve::lang::member)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::slot_h);
        this->type(type);
        this->modifiers(modifiers);
        this->state(state);
        this->weak(weak);
        this->define();
    }
    
    // Construct from handle
    Slot::Slot(QT::slot handle, bool owner) : ::hyve::lang::Member((::hyve::lang::member)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::slot Slot::_handle() const {
        return (QT::slot)this->__handle;
    }
    
    /* ::Qt::slot::construct(::Qt::slot object) */
    ::hyve::lang::int16 Slot::construct(const QT::Slot &object) {
    /* $begin(::Qt::slot::construct(::Qt::slot object)) */
        ((hyve::lang::member)object._handle())->modifiers |= hyve::lang::CONST;
        return 0;
    /* $end */
    }
}

