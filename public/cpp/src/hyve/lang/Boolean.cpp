/* src/hyve/lang/Boolean.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::boolean.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Boolean.hpp"
#include "hyve/lang/_meta.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Boolean::Boolean( ::hyve::lang::width width) : ::hyve::lang::Primitive((::hyve::lang::primitive)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::boolean_h);
            this->width(width);
            this->define();
        }
        
        // Constructor (declare & define)
        Boolean::Boolean(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                 ::hyve::lang::width width) : ::hyve::lang::Primitive((::hyve::lang::primitive)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::boolean_h);
            this->width(width);
            this->define();
        }
        
        // Construct from handle
        Boolean::Boolean(::hyve::lang::boolean handle, bool owner) : ::hyve::lang::Primitive((::hyve::lang::primitive)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::boolean Boolean::_handle() const {
            return (::hyve::lang::boolean)this->__handle;
        }
    }
}

