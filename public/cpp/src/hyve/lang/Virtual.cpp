/* src/hyve/lang/Virtual.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::virtual.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Virtual.hpp"
#include "hyve/lang/_meta.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Virtual::Virtual(const ::hyve::lang::Typedef &returnType,
                 ::hyve::lang::_bool _virtual) : ::hyve::lang::Method((::hyve::lang::method)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::_virtual_h);
            this->returnType(returnType);
            this->_virtual(_virtual);
            this->define();
        }
        
        // Constructor (declare & define)
        Virtual::Virtual(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                const ::hyve::lang::Typedef &returnType,
                 ::hyve::lang::_bool _virtual) : ::hyve::lang::Method((::hyve::lang::method)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::_virtual_h);
            this->returnType(returnType);
            this->_virtual(_virtual);
            this->define();
        }
        
        // Construct from handle
        Virtual::Virtual(::hyve::lang::_virtual handle, bool owner) : ::hyve::lang::Method((::hyve::lang::method)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::_virtual Virtual::_handle() const {
            return (::hyve::lang::_virtual)this->__handle;
        }
    }
}

