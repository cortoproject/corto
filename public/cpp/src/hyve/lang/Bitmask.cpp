/* src/hyve/lang/Bitmask.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::bitmask.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Bitmask.hpp"
#include "hyve/lang/_meta.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Bitmask::Bitmask() : ::hyve::lang::Enum((::hyve::lang::_enum)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::bitmask_h);
            this->define();
        }
        
        // Constructor (declare & define)
        Bitmask::Bitmask(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name) : ::hyve::lang::Enum((::hyve::lang::_enum)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::bitmask_h);
            this->define();
        }
        
        // Construct from handle
        Bitmask::Bitmask(::hyve::lang::bitmask handle, bool owner) : ::hyve::lang::Enum((::hyve::lang::_enum)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::bitmask Bitmask::_handle() const {
            return (::hyve::lang::bitmask)this->__handle;
        }
    }
}

