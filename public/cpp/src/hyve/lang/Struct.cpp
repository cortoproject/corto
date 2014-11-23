/* src/hyve/lang/Struct.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::struct.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Struct.hpp"
#include "hyve/lang/_meta.hpp"
#include "hyve/lang/Member.hpp"
#include "hyve/lang/Type.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Struct::Struct(const ::hyve::lang::Typedef &defaultType,
                const ::hyve::lang::Typedef &parentType,
                 ::hyve::lang::state parentState,
                const ::hyve::lang::Interface &base,
                 ::hyve::lang::modifier baseAccess) : ::hyve::lang::Interface((::hyve::lang::interface)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::_struct_h);
            this->defaultType(defaultType);
            this->parentType(parentType);
            this->parentState(parentState);
            this->base(base);
            this->baseAccess(baseAccess);
            this->define();
        }
        
        // Constructor (declare & define)
        Struct::Struct(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                const ::hyve::lang::Typedef &defaultType,
                const ::hyve::lang::Typedef &parentType,
                 ::hyve::lang::state parentState,
                const ::hyve::lang::Interface &base,
                 ::hyve::lang::modifier baseAccess) : ::hyve::lang::Interface((::hyve::lang::interface)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::_struct_h);
            this->defaultType(defaultType);
            this->parentType(parentType);
            this->parentState(parentState);
            this->base(base);
            this->baseAccess(baseAccess);
            this->define();
        }
        
        // Construct from handle
        Struct::Struct(::hyve::lang::_struct handle, bool owner) : ::hyve::lang::Interface((::hyve::lang::interface)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::_struct Struct::_handle() const {
            return (::hyve::lang::_struct)this->__handle;
        }
        
        // ::hyve::lang::modifier baseAccess
        ::hyve::lang::modifier Struct::baseAccess() const {
            return ((::hyve::lang::_struct)this->__handle)->baseAccess;
        }
        void Struct::baseAccess( ::hyve::lang::modifier v) const {
            ((::hyve::lang::_struct)this->__handle)->baseAccess = v;
        }
        
        // ::hyve::lang::uint16 delegateCount
        ::hyve::lang::uint16 Struct::delegateCount() const {
            return ((::hyve::lang::_struct)this->__handle)->delegateCount;
        }
        void Struct::delegateCount( ::hyve::lang::uint16 v) const {
            ((::hyve::lang::_struct)this->__handle)->delegateCount = v;
        }
        
        /* ::hyve::lang::struct::castable(lang::type type) */
        ::hyve::lang::_bool Struct::castable_v(const ::hyve::lang::Type &type) const {
            ::hyve::lang::_bool _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::_struct_castable_h),&_result,this->__handle,type._handle());
            return _result;
        }
        
        /* virtual ::hyve::lang::struct::castable(lang::type type) */
        ::hyve::lang::_bool Struct::castable(const ::hyve::lang::Type &type) const {
            hyve::lang::Class _type((hyve::lang::_class)this->_typeof()._handle());
            static hyve::lang::uint32 _actualMethodId;
            
            if (!_actualMethodId) {
                _actualMethodId = _type.resolveMethodId((hyve::lang::string)"castable(lang::type type)");
            }
            hyve::lang::Method _actualMethod = _type.resolveMethodById(_actualMethodId);
            ::hyve::lang::_bool _result;
            ::hyve::call((::hyve::lang::function)((hyve::lang::function)_actualMethod._handle()),&_result,this->__handle,type._handle());
            return _result;
        }
        
        /* ::hyve::lang::struct::compatible(lang::type type) */
        ::hyve::lang::_bool Struct::compatible_v(const ::hyve::lang::Type &type) const {
            ::hyve::lang::_bool _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::_struct_compatible_h),&_result,this->__handle,type._handle());
            return _result;
        }
        
        /* virtual ::hyve::lang::struct::compatible(lang::type type) */
        ::hyve::lang::_bool Struct::compatible(const ::hyve::lang::Type &type) const {
            hyve::lang::Class _type((hyve::lang::_class)this->_typeof()._handle());
            static hyve::lang::uint32 _actualMethodId;
            
            if (!_actualMethodId) {
                _actualMethodId = _type.resolveMethodId((hyve::lang::string)"compatible(lang::type type)");
            }
            hyve::lang::Method _actualMethod = _type.resolveMethodById(_actualMethodId);
            ::hyve::lang::_bool _result;
            ::hyve::call((::hyve::lang::function)((hyve::lang::function)_actualMethod._handle()),&_result,this->__handle,type._handle());
            return _result;
        }
        
        /* ::hyve::lang::struct::resolveMember(lang::string name) */
        ::hyve::lang::Member Struct::resolveMember_v(::hyve::lang::string name) const {
            ::hyve::lang::member _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::_struct_resolveMember_h),&_result,this->__handle,name);
            ::hyve::lang::Member __result(_result);
            return __result;
        }
        
        /* virtual ::hyve::lang::struct::resolveMember(lang::string name) */
        ::hyve::lang::Member Struct::resolveMember(::hyve::lang::string name) const {
            hyve::lang::Class _type((hyve::lang::_class)this->_typeof()._handle());
            static hyve::lang::uint32 _actualMethodId;
            
            if (!_actualMethodId) {
                _actualMethodId = _type.resolveMethodId((hyve::lang::string)"resolveMember(lang::string name)");
            }
            hyve::lang::Method _actualMethod = _type.resolveMethodById(_actualMethodId);
            ::hyve::lang::member _result;
            ::hyve::call((::hyve::lang::function)((hyve::lang::function)_actualMethod._handle()),&_result,this->__handle,name);
            ::hyve::lang::Member __result(_result);
            return __result;
        }
    }
}

