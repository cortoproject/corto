/* src/hyve/lang/Class.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::class.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Class.hpp"
#include "hyve/lang/_meta.hpp"
#include "hyve/lang/Observer.hpp"
#include "hyve/lang/Object.hpp"
#include "hyve/lang/Method.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Class::Class(const ::hyve::lang::Typedef &defaultType,
                const ::hyve::lang::Typedef &parentType,
                 ::hyve::lang::state parentState,
                const ::hyve::lang::Interface &base,
                 ::hyve::lang::modifier baseAccess,
                 ::hyve::lang::interfaceSeq implements) : ::hyve::lang::Struct((::hyve::lang::_struct)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::_class_h);
            this->defaultType(defaultType);
            this->parentType(parentType);
            this->parentState(parentState);
            this->base(base);
            this->baseAccess(baseAccess);
            this->implements(implements);
            this->define();
        }
        
        // Constructor (declare & define)
        Class::Class(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                const ::hyve::lang::Typedef &defaultType,
                const ::hyve::lang::Typedef &parentType,
                 ::hyve::lang::state parentState,
                const ::hyve::lang::Interface &base,
                 ::hyve::lang::modifier baseAccess,
                 ::hyve::lang::interfaceSeq implements) : ::hyve::lang::Struct((::hyve::lang::_struct)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::_class_h);
            this->defaultType(defaultType);
            this->parentType(parentType);
            this->parentState(parentState);
            this->base(base);
            this->baseAccess(baseAccess);
            this->implements(implements);
            this->define();
        }
        
        // Construct from handle
        Class::Class(::hyve::lang::_class handle, bool owner) : ::hyve::lang::Struct((::hyve::lang::_struct)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::_class Class::_handle() const {
            return (::hyve::lang::_class)this->__handle;
        }
        
        // ::hyve::lang::interfaceSeq implements
        ::hyve::lang::interfaceSeq Class::implements() const {
            return ((::hyve::lang::_class)this->__handle)->implements;
        }
        void Class::implements( ::hyve::lang::interfaceSeq v) const {
            ((::hyve::lang::_class)this->__handle)->implements = v;
        }
        
        // ::hyve::lang::interfaceVectorSeq interfaceVector
        ::hyve::lang::interfaceVectorSeq Class::interfaceVector() const {
            return ((::hyve::lang::_class)this->__handle)->interfaceVector;
        }
        void Class::interfaceVector( ::hyve::lang::interfaceVectorSeq v) const {
            ((::hyve::lang::_class)this->__handle)->interfaceVector = v;
        }
        
        // ::hyve::lang::observerSeq observers
        ::hyve::lang::observerSeq Class::observers() const {
            return ((::hyve::lang::_class)this->__handle)->observers;
        }
        void Class::observers( ::hyve::lang::observerSeq v) const {
            ((::hyve::lang::_class)this->__handle)->observers = v;
        }
        
        /* ::hyve::lang::class::allocSize() */
        ::hyve::lang::uint32 Class::allocSize_v() const {
            ::hyve::lang::uint32 _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::_class_allocSize_h),&_result,this->__handle);
            return _result;
        }
        
        /* virtual ::hyve::lang::class::allocSize() */
        ::hyve::lang::uint32 Class::allocSize() const {
            hyve::lang::Class _type((hyve::lang::_class)this->_typeof()._handle());
            static hyve::lang::uint32 _actualMethodId;
            
            if (!_actualMethodId) {
                _actualMethodId = _type.resolveMethodId((hyve::lang::string)"allocSize()");
            }
            hyve::lang::Method _actualMethod = _type.resolveMethodById(_actualMethodId);
            ::hyve::lang::uint32 _result;
            ::hyve::call((::hyve::lang::function)((hyve::lang::function)_actualMethod._handle()),&_result,this->__handle);
            return _result;
        }
        
        /* ::hyve::lang::class::bindMethod(lang::method method) */
        ::hyve::lang::int16 Class::bindMethod_v(const ::hyve::lang::Method &method) const {
            ::hyve::lang::int16 _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::_class_bindMethod_h),&_result,this->__handle,method._handle());
            return _result;
        }
        
        /* virtual ::hyve::lang::class::bindMethod(lang::method method) */
        ::hyve::lang::int16 Class::bindMethod(const ::hyve::lang::Method &method) const {
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
        
        /* ::hyve::lang::class::construct(lang::object object) */
        ::hyve::lang::int16 Class::construct(const ::hyve::lang::Object &object) const {
            ::hyve::lang::int16 _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::_class_construct_h),&_result,this->__handle,object._handle());
            return _result;
        }
        
        /* ::hyve::lang::class::destruct(lang::object object) */
        ::hyve::lang::_void Class::destruct(const ::hyve::lang::Object &object) const {
            ::hyve::call((::hyve::lang::function)(::hyve::lang::_class_destruct_h),NULL,this->__handle,object._handle());
        }
        
        /* ::hyve::lang::class::instanceof(lang::object object) */
        ::hyve::lang::_bool Class::instanceof(const ::hyve::lang::Object &object) const {
            ::hyve::lang::_bool _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::_class_instanceof_h),&_result,this->__handle,object._handle());
            return _result;
        }
        
        /* ::hyve::lang::class::privateObserver(lang::object object,lang::observer observer) */
        ::hyve::lang::Observer Class::privateObserver(const ::hyve::lang::Object &object, const ::hyve::lang::Observer &observer) const {
            ::hyve::lang::observer _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::_class_privateObserver_h),&_result,this->__handle,object._handle(),observer._handle());
            ::hyve::lang::Observer __result(_result);
            return __result;
        }
    }
}

