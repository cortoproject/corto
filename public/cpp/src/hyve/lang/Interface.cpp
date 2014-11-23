/* src/hyve/lang/Interface.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Interface.hpp"
#include "hyve/lang/_meta.hpp"
#include "hyve/lang/Member.hpp"
#include "hyve/lang/Type.hpp"
#include "hyve/lang/Method.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Interface::Interface(const ::hyve::lang::Typedef &defaultType,
                const ::hyve::lang::Typedef &parentType,
                 ::hyve::lang::state parentState,
                const ::hyve::lang::Interface &base) : ::hyve::lang::Type((::hyve::lang::type)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::interface_h);
            this->defaultType(defaultType);
            this->parentType(parentType);
            this->parentState(parentState);
            this->base(base);
            this->define();
        }
        
        // Constructor (declare & define)
        Interface::Interface(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                const ::hyve::lang::Typedef &defaultType,
                const ::hyve::lang::Typedef &parentType,
                 ::hyve::lang::state parentState,
                const ::hyve::lang::Interface &base) : ::hyve::lang::Type((::hyve::lang::type)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::interface_h);
            this->defaultType(defaultType);
            this->parentType(parentType);
            this->parentState(parentState);
            this->base(base);
            this->define();
        }
        
        // Construct from handle
        Interface::Interface(::hyve::lang::interface handle, bool owner) : ::hyve::lang::Type((::hyve::lang::type)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::interface Interface::_handle() const {
            return (::hyve::lang::interface)this->__handle;
        }
        
        // ::hyve::lang::compositeKind kind
        ::hyve::lang::compositeKind Interface::kind() const {
            return ((::hyve::lang::interface)this->__handle)->kind;
        }
        void Interface::kind( ::hyve::lang::compositeKind v) const {
            ((::hyve::lang::interface)this->__handle)->kind = v;
        }
        
        // ::hyve::lang::uint32 nextMemberId
        ::hyve::lang::uint32 Interface::nextMemberId() const {
            return ((::hyve::lang::interface)this->__handle)->nextMemberId;
        }
        void Interface::nextMemberId( ::hyve::lang::uint32 v) const {
            ((::hyve::lang::interface)this->__handle)->nextMemberId = v;
        }
        
        // ::hyve::lang::memberSeq members
        ::hyve::lang::memberSeq Interface::members() const {
            return ((::hyve::lang::interface)this->__handle)->members;
        }
        void Interface::members( ::hyve::lang::memberSeq v) const {
            ((::hyve::lang::interface)this->__handle)->members = v;
        }
        
        // ::hyve::lang::vtable methods
        ::hyve::lang::vtable Interface::methods() const {
            return ((::hyve::lang::interface)this->__handle)->methods;
        }
        void Interface::methods( ::hyve::lang::vtable v) const {
            ((::hyve::lang::interface)this->__handle)->methods = v;
        }
        
        // ::hyve::lang::interface base
        ::hyve::lang::Interface Interface::base() const {
            ::hyve::lang::Interface result(((::hyve::lang::interface)this->__handle)->base);
            return result;
        }
        void Interface::base(const ::hyve::lang::Interface &v) const {
            if (v) {
                hyve::set((hyve::lang::object*)&((::hyve::lang::interface)this->__handle)->base, v._handle());
            } else {
                hyve::set((hyve::lang::object*)&((::hyve::lang::interface)this->__handle)->base, NULL);
            }
        }
        
        /* ::hyve::lang::interface::bindMethod(lang::method method) */
        ::hyve::lang::int16 Interface::bindMethod_v(const ::hyve::lang::Method &method) const {
            ::hyve::lang::int16 _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::interface_bindMethod_h),&_result,this->__handle,method._handle());
            return _result;
        }
        
        /* virtual ::hyve::lang::interface::bindMethod(lang::method method) */
        ::hyve::lang::int16 Interface::bindMethod(const ::hyve::lang::Method &method) const {
            hyve::lang::Class _type((hyve::lang::_class)this->_typeof()._handle());
            static hyve::lang::uint32 _actualMethodId;
            
            if (!_actualMethodId) {
                _actualMethodId = _type.resolveMethodId((hyve::lang::string)"bindMethod(lang::method method)");
            }
            hyve::lang::Method _actualMethod = _type.resolveMethodById(_actualMethodId);
            ::hyve::lang::int16 _result;
            ::hyve::call((::hyve::lang::function)((hyve::lang::function)_actualMethod._handle()),&_result,this->__handle,method._handle());
            return _result;
        }
        
        /* ::hyve::lang::interface::compatible(lang::type type) */
        ::hyve::lang::_bool Interface::compatible_v(const ::hyve::lang::Type &type) const {
            ::hyve::lang::_bool _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::interface_compatible_h),&_result,this->__handle,type._handle());
            return _result;
        }
        
        /* virtual ::hyve::lang::interface::compatible(lang::type type) */
        ::hyve::lang::_bool Interface::compatible(const ::hyve::lang::Type &type) const {
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
        
        /* ::hyve::lang::interface::resolveMember(lang::string name) */
        ::hyve::lang::Member Interface::resolveMember_v(::hyve::lang::string name) const {
            ::hyve::lang::member _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::interface_resolveMember_h),&_result,this->__handle,name);
            ::hyve::lang::Member __result(_result);
            return __result;
        }
        
        /* virtual ::hyve::lang::interface::resolveMember(lang::string name) */
        ::hyve::lang::Member Interface::resolveMember(::hyve::lang::string name) const {
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
        
        /* ::hyve::lang::interface::resolveMethod(lang::string name) */
        ::hyve::lang::Method Interface::resolveMethod(::hyve::lang::string name) const {
            ::hyve::lang::method _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::interface_resolveMethod_h),&_result,this->__handle,name);
            ::hyve::lang::Method __result(_result);
            return __result;
        }
        
        /* ::hyve::lang::interface::resolveMethodById(lang::uint32 id) */
        ::hyve::lang::Method Interface::resolveMethodById(::hyve::lang::uint32 id) const {
            ::hyve::lang::method _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::interface_resolveMethodById_h),&_result,this->__handle,id);
            ::hyve::lang::Method __result(_result);
            return __result;
        }
        
        /* ::hyve::lang::interface::resolveMethodId(lang::string name) */
        ::hyve::lang::uint32 Interface::resolveMethodId(::hyve::lang::string name) const {
            ::hyve::lang::uint32 _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::interface_resolveMethodId_h),&_result,this->__handle,name);
            return _result;
        }
    }
}

