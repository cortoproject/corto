/* src/hyve/lang/List.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::list.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/List.hpp"
#include "hyve/lang/_meta.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        List::List(const ::hyve::lang::Typedef &elementType,
                 ::hyve::lang::uint32 max) : ::hyve::lang::Collection((::hyve::lang::collection)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::list_h);
            this->elementType(elementType);
            this->max(max);
            this->define();
        }
        
        // Constructor (declare & define)
        List::List(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                const ::hyve::lang::Typedef &elementType,
                 ::hyve::lang::uint32 max) : ::hyve::lang::Collection((::hyve::lang::collection)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::list_h);
            this->elementType(elementType);
            this->max(max);
            this->define();
        }
        
        // Construct from handle
        List::List(::hyve::lang::list handle, bool owner) : ::hyve::lang::Collection((::hyve::lang::collection)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::list List::_handle() const {
            return (::hyve::lang::list)this->__handle;
        }
    }
}

