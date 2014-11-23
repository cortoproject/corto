/* src/hyve/lang/Primitive.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::primitive.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Primitive.hpp"
#include "hyve/lang/_meta.hpp"
#include "hyve/lang/Type.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Primitive::Primitive( ::hyve::lang::width width) : ::hyve::lang::Type((::hyve::lang::type)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::primitive_h);
            this->width(width);
            this->define();
        }
        
        // Constructor (declare & define)
        Primitive::Primitive(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                 ::hyve::lang::width width) : ::hyve::lang::Type((::hyve::lang::type)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::primitive_h);
            this->width(width);
            this->define();
        }
        
        // Construct from handle
        Primitive::Primitive(::hyve::lang::primitive handle, bool owner) : ::hyve::lang::Type((::hyve::lang::type)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::primitive Primitive::_handle() const {
            return (::hyve::lang::primitive)this->__handle;
        }
        
        // ::hyve::lang::primitiveKind kind
        ::hyve::lang::primitiveKind Primitive::kind() const {
            return ((::hyve::lang::primitive)this->__handle)->kind;
        }
        void Primitive::kind( ::hyve::lang::primitiveKind v) const {
            ((::hyve::lang::primitive)this->__handle)->kind = v;
        }
        
        // ::hyve::lang::width width
        ::hyve::lang::width Primitive::width() const {
            return ((::hyve::lang::primitive)this->__handle)->width;
        }
        void Primitive::width( ::hyve::lang::width v) const {
            ((::hyve::lang::primitive)this->__handle)->width = v;
        }
        
        // ::hyve::lang::uint8 convertId
        ::hyve::lang::uint8 Primitive::convertId() const {
            return ((::hyve::lang::primitive)this->__handle)->convertId;
        }
        void Primitive::convertId( ::hyve::lang::uint8 v) const {
            ((::hyve::lang::primitive)this->__handle)->convertId = v;
        }
        
        /* ::hyve::lang::primitive::castable(lang::type type) */
        ::hyve::lang::_bool Primitive::castable_v(const ::hyve::lang::Type &type) const {
            ::hyve::lang::_bool _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::primitive_castable_h),&_result,this->__handle,type._handle());
            return _result;
        }
        
        /* virtual ::hyve::lang::primitive::castable(lang::type type) */
        ::hyve::lang::_bool Primitive::castable(const ::hyve::lang::Type &type) const {
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
        
        /* ::hyve::lang::primitive::compatible(lang::type type) */
        ::hyve::lang::_bool Primitive::compatible_v(const ::hyve::lang::Type &type) const {
            ::hyve::lang::_bool _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::primitive_compatible_h),&_result,this->__handle,type._handle());
            return _result;
        }
        
        /* virtual ::hyve::lang::primitive::compatible(lang::type type) */
        ::hyve::lang::_bool Primitive::compatible(const ::hyve::lang::Type &type) const {
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
    }
}

