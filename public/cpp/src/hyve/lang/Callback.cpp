/* src/hyve/lang/Callback.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::callback.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Callback.hpp"
#include "hyve/lang/_meta.hpp"
#include "hyve/lang/Delegate.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Callback::Callback(const ::hyve::lang::Typedef &returnType,
                const ::hyve::lang::Delegate &delegate) : ::hyve::lang::Function((::hyve::lang::function)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::callback_h);
            this->returnType(returnType);
            this->delegate(delegate);
            this->define();
        }
        
        // Constructor (declare & define)
        Callback::Callback(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                const ::hyve::lang::Typedef &returnType,
                const ::hyve::lang::Delegate &delegate) : ::hyve::lang::Function((::hyve::lang::function)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::callback_h);
            this->returnType(returnType);
            this->delegate(delegate);
            this->define();
        }
        
        // Construct from handle
        Callback::Callback(::hyve::lang::callback handle, bool owner) : ::hyve::lang::Function((::hyve::lang::function)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::callback Callback::_handle() const {
            return (::hyve::lang::callback)this->__handle;
        }
        
        // ::hyve::lang::delegate delegate
        ::hyve::lang::Delegate Callback::delegate() const {
            ::hyve::lang::Delegate result(((::hyve::lang::callback)this->__handle)->delegate);
            return result;
        }
        void Callback::delegate(const ::hyve::lang::Delegate &v) const {
            if (v) {
                hyve::set((hyve::lang::object*)&((::hyve::lang::callback)this->__handle)->delegate, v._handle());
            } else {
                hyve::set((hyve::lang::object*)&((::hyve::lang::callback)this->__handle)->delegate, NULL);
            }
        }
    }
}

