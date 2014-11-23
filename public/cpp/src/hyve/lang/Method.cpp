/* src/hyve/lang/Method.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::method.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/_meta.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Method::Method(const ::hyve::lang::Typedef &returnType,
                 ::hyve::lang::_bool _virtual) : ::hyve::lang::Function((::hyve::lang::function)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::method_h);
            this->returnType(returnType);
            this->_virtual(_virtual);
            this->define();
        }
        
        // Constructor (declare & define)
        Method::Method(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                const ::hyve::lang::Typedef &returnType,
                 ::hyve::lang::_bool _virtual) : ::hyve::lang::Function((::hyve::lang::function)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::method_h);
            this->returnType(returnType);
            this->_virtual(_virtual);
            this->define();
        }
        
        // Construct from handle
        Method::Method(::hyve::lang::method handle, bool owner) : ::hyve::lang::Function((::hyve::lang::function)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::method Method::_handle() const {
            return (::hyve::lang::method)this->__handle;
        }
        
        // ::hyve::lang::bool virtual
        ::hyve::lang::_bool Method::_virtual() const {
            return ((::hyve::lang::method)this->__handle)->_virtual;
        }
        void Method::_virtual( ::hyve::lang::_bool v) const {
            ((::hyve::lang::method)this->__handle)->_virtual = v;
        }
    }
}

