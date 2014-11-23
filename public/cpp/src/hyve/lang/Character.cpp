/* src/hyve/lang/Character.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::character.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Character.hpp"
#include "hyve/lang/_meta.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Character::Character( ::hyve::lang::width width) : ::hyve::lang::Primitive((::hyve::lang::primitive)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::character_h);
            this->width(width);
            this->define();
        }
        
        // Constructor (declare & define)
        Character::Character(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                 ::hyve::lang::width width) : ::hyve::lang::Primitive((::hyve::lang::primitive)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::character_h);
            this->width(width);
            this->define();
        }
        
        // Construct from handle
        Character::Character(::hyve::lang::character handle, bool owner) : ::hyve::lang::Primitive((::hyve::lang::primitive)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::character Character::_handle() const {
            return (::hyve::lang::character)this->__handle;
        }
    }
}

