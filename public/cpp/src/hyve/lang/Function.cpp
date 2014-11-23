/* src/hyve/lang/Function.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::function.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Function.hpp"
#include "hyve/lang/_meta.hpp"
#include "hyve/lang/Typedef.hpp"
#include "hyve/lang/Object.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Function::Function(const ::hyve::lang::Typedef &returnType) : ::hyve::lang::Object((::hyve::lang::object)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::function_h);
            this->returnType(returnType);
            this->define();
        }
        
        // Constructor (declare & define)
        Function::Function(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                const ::hyve::lang::Typedef &returnType) : ::hyve::lang::Object((::hyve::lang::object)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::function_h);
            this->returnType(returnType);
            this->define();
        }
        
        // Construct from handle
        Function::Function(::hyve::lang::function handle, bool owner) : ::hyve::lang::Object((::hyve::lang::object)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::function Function::_handle() const {
            return (::hyve::lang::function)this->__handle;
        }
        
        // ::hyve::lang::typedef returnType
        ::hyve::lang::Typedef Function::returnType() const {
            ::hyve::lang::Typedef result(((::hyve::lang::function)this->__handle)->returnType);
            return result;
        }
        void Function::returnType(const ::hyve::lang::Typedef &v) const {
            if (v) {
                hyve::set((hyve::lang::object*)&((::hyve::lang::function)this->__handle)->returnType, v._handle());
            } else {
                hyve::set((hyve::lang::object*)&((::hyve::lang::function)this->__handle)->returnType, NULL);
            }
        }
        
        // ::hyve::lang::bool overloaded
        ::hyve::lang::_bool Function::overloaded() const {
            return ((::hyve::lang::function)this->__handle)->overloaded;
        }
        void Function::overloaded( ::hyve::lang::_bool v) const {
            ((::hyve::lang::function)this->__handle)->overloaded = v;
        }
        
        // ::hyve::lang::uint32 kind
        ::hyve::lang::uint32 Function::kind() const {
            return ((::hyve::lang::function)this->__handle)->kind;
        }
        void Function::kind( ::hyve::lang::uint32 v) const {
            ((::hyve::lang::function)this->__handle)->kind = v;
        }
        
        // ::hyve::lang::word impl
        ::hyve::lang::word Function::impl() const {
            return ((::hyve::lang::function)this->__handle)->impl;
        }
        void Function::impl( ::hyve::lang::word v) const {
            ((::hyve::lang::function)this->__handle)->impl = v;
        }
        
        // ::hyve::lang::word impludata
        ::hyve::lang::word Function::impludata() const {
            return ((::hyve::lang::function)this->__handle)->impludata;
        }
        void Function::impludata( ::hyve::lang::word v) const {
            ((::hyve::lang::function)this->__handle)->impludata = v;
        }
        
        // ::hyve::lang::object resource
        ::hyve::lang::Object Function::resource() const {
            ::hyve::lang::Object result(((::hyve::lang::function)this->__handle)->resource);
            return result;
        }
        void Function::resource(const ::hyve::lang::Object &v) const {
            if (v) {
                hyve::set((hyve::lang::object*)&((::hyve::lang::function)this->__handle)->resource, v._handle());
            } else {
                hyve::set((hyve::lang::object*)&((::hyve::lang::function)this->__handle)->resource, NULL);
            }
        }
        
        // ::hyve::lang::int16 size
        ::hyve::lang::int16 Function::size() const {
            return ((::hyve::lang::function)this->__handle)->size;
        }
        void Function::size( ::hyve::lang::int16 v) const {
            ((::hyve::lang::function)this->__handle)->size = v;
        }
        
        // ::hyve::lang::parameterSeq parameters
        ::hyve::lang::parameterSeq Function::parameters() const {
            return ((::hyve::lang::function)this->__handle)->parameters;
        }
        void Function::parameters( ::hyve::lang::parameterSeq v) const {
            ((::hyve::lang::function)this->__handle)->parameters = v;
        }
        
        // ::hyve::lang::uint32 nextParameterId
        ::hyve::lang::uint32 Function::nextParameterId() const {
            return ((::hyve::lang::function)this->__handle)->nextParameterId;
        }
        void Function::nextParameterId( ::hyve::lang::uint32 v) const {
            ((::hyve::lang::function)this->__handle)->nextParameterId = v;
        }
    }
}

