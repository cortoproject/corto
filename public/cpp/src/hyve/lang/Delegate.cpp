/* src/hyve/lang/Delegate.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::delegate.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Delegate.hpp"
#include "hyve/lang/_meta.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Delegate::Delegate(const ::hyve::lang::Typedef &returnType) : ::hyve::lang::Function((::hyve::lang::function)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::delegate_h);
            this->returnType(returnType);
            this->define();
        }
        
        // Constructor (declare & define)
        Delegate::Delegate(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                const ::hyve::lang::Typedef &returnType) : ::hyve::lang::Function((::hyve::lang::function)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::delegate_h);
            this->returnType(returnType);
            this->define();
        }
        
        // Construct from handle
        Delegate::Delegate(::hyve::lang::delegate handle, bool owner) : ::hyve::lang::Function((::hyve::lang::function)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::delegate Delegate::_handle() const {
            return (::hyve::lang::delegate)this->__handle;
        }
        
        // ::hyve::lang::uint32 id
        ::hyve::lang::uint32 Delegate::id() const {
            return ((::hyve::lang::delegate)this->__handle)->id;
        }
        void Delegate::id( ::hyve::lang::uint32 v) const {
            ((::hyve::lang::delegate)this->__handle)->id = v;
        }
    }
}

