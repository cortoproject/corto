/* src/hyve/lang/Metaprocedure.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::metaprocedure.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Metaprocedure.hpp"
#include "hyve/lang/_meta.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Metaprocedure::Metaprocedure(const ::hyve::lang::Typedef &returnType) : ::hyve::lang::Function((::hyve::lang::function)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::metaprocedure_h);
            this->returnType(returnType);
            this->define();
        }
        
        // Constructor (declare & define)
        Metaprocedure::Metaprocedure(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                const ::hyve::lang::Typedef &returnType) : ::hyve::lang::Function((::hyve::lang::function)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::metaprocedure_h);
            this->returnType(returnType);
            this->define();
        }
        
        // Construct from handle
        Metaprocedure::Metaprocedure(::hyve::lang::metaprocedure handle, bool owner) : ::hyve::lang::Function((::hyve::lang::function)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::metaprocedure Metaprocedure::_handle() const {
            return (::hyve::lang::metaprocedure)this->__handle;
        }
    }
}

