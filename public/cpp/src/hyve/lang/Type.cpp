/* src/hyve/lang/Type.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::type.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Type.hpp"
#include "hyve/lang/_meta.hpp"
#include "hyve/lang/Function.hpp"
#include "hyve/lang/Object.hpp"
#include "hyve/lang/Typedef.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Type::Type(const ::hyve::lang::Typedef &defaultType,
                const ::hyve::lang::Typedef &parentType,
                 ::hyve::lang::state parentState) : ::hyve::lang::Typedef((::hyve::lang::_typedef)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::type_h);
            this->defaultType(defaultType);
            this->parentType(parentType);
            this->parentState(parentState);
            this->define();
        }
        
        // Constructor (declare & define)
        Type::Type(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                const ::hyve::lang::Typedef &defaultType,
                const ::hyve::lang::Typedef &parentType,
                 ::hyve::lang::state parentState) : ::hyve::lang::Typedef((::hyve::lang::_typedef)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::type_h);
            this->defaultType(defaultType);
            this->parentType(parentType);
            this->parentState(parentState);
            this->define();
        }
        
        // Construct from handle
        Type::Type(::hyve::lang::type handle, bool owner) : ::hyve::lang::Typedef((::hyve::lang::_typedef)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::type Type::_handle() const {
            return (::hyve::lang::type)this->__handle;
        }
        
        // ::hyve::lang::typeKind kind
        ::hyve::lang::typeKind Type::kind() const {
            return ((::hyve::lang::type)this->__handle)->kind;
        }
        void Type::kind( ::hyve::lang::typeKind v) const {
            ((::hyve::lang::type)this->__handle)->kind = v;
        }
        
        // ::hyve::lang::bool reference
        ::hyve::lang::_bool Type::reference() const {
            return ((::hyve::lang::type)this->__handle)->reference;
        }
        void Type::reference( ::hyve::lang::_bool v) const {
            ((::hyve::lang::type)this->__handle)->reference = v;
        }
        
        // ::hyve::lang::bool hasResources
        ::hyve::lang::_bool Type::hasResources() const {
            return ((::hyve::lang::type)this->__handle)->hasResources;
        }
        void Type::hasResources( ::hyve::lang::_bool v) const {
            ((::hyve::lang::type)this->__handle)->hasResources = v;
        }
        
        // ::hyve::lang::uint32 templateId
        ::hyve::lang::uint32 Type::templateId() const {
            return ((::hyve::lang::type)this->__handle)->templateId;
        }
        void Type::templateId( ::hyve::lang::uint32 v) const {
            ((::hyve::lang::type)this->__handle)->templateId = v;
        }
        
        // ::hyve::lang::uint32 size
        ::hyve::lang::uint32 Type::size() const {
            return ((::hyve::lang::type)this->__handle)->size;
        }
        void Type::size( ::hyve::lang::uint32 v) const {
            ((::hyve::lang::type)this->__handle)->size = v;
        }
        
        // ::hyve::lang::uint16 alignment
        ::hyve::lang::uint16 Type::alignment() const {
            return ((::hyve::lang::type)this->__handle)->alignment;
        }
        void Type::alignment( ::hyve::lang::uint16 v) const {
            ((::hyve::lang::type)this->__handle)->alignment = v;
        }
        
        // ::hyve::lang::typedef defaultType
        ::hyve::lang::Typedef Type::defaultType() const {
            ::hyve::lang::Typedef result(((::hyve::lang::type)this->__handle)->defaultType);
            return result;
        }
        void Type::defaultType(const ::hyve::lang::Typedef &v) const {
            if (v) {
                hyve::set((hyve::lang::object*)&((::hyve::lang::type)this->__handle)->defaultType, v._handle());
            } else {
                hyve::set((hyve::lang::object*)&((::hyve::lang::type)this->__handle)->defaultType, NULL);
            }
        }
        
        // ::hyve::lang::typedef parentType
        ::hyve::lang::Typedef Type::parentType() const {
            ::hyve::lang::Typedef result(((::hyve::lang::type)this->__handle)->parentType);
            return result;
        }
        void Type::parentType(const ::hyve::lang::Typedef &v) const {
            if (v) {
                hyve::set((hyve::lang::object*)&((::hyve::lang::type)this->__handle)->parentType, v._handle());
            } else {
                hyve::set((hyve::lang::object*)&((::hyve::lang::type)this->__handle)->parentType, NULL);
            }
        }
        
        // ::hyve::lang::state parentState
        ::hyve::lang::state Type::parentState() const {
            return ((::hyve::lang::type)this->__handle)->parentState;
        }
        void Type::parentState( ::hyve::lang::state v) const {
            ((::hyve::lang::type)this->__handle)->parentState = v;
        }
        
        // ::hyve::lang::vtable metaprocedures
        ::hyve::lang::vtable Type::metaprocedures() const {
            return ((::hyve::lang::type)this->__handle)->metaprocedures;
        }
        void Type::metaprocedures( ::hyve::lang::vtable v) const {
            ((::hyve::lang::type)this->__handle)->metaprocedures = v;
        }
        
        /* ::hyve::lang::type::alignmentof() */
        ::hyve::lang::uint16 Type::alignmentof() const {
            ::hyve::lang::uint16 _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::type_alignmentof_h),&_result,this->__handle);
            return _result;
        }
        
        /* ::hyve::lang::type::allocSize() */
        ::hyve::lang::uint32 Type::allocSize_v() const {
            ::hyve::lang::uint32 _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::type_allocSize_h),&_result,this->__handle);
            return _result;
        }
        
        /* virtual ::hyve::lang::type::allocSize() */
        ::hyve::lang::uint32 Type::allocSize() const {
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
        
        /* ::hyve::lang::type::castable(lang::type type) */
        ::hyve::lang::_bool Type::castable_v(const ::hyve::lang::Type &type) const {
            ::hyve::lang::_bool _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::type_castable_h),&_result,this->__handle,type._handle());
            return _result;
        }
        
        /* virtual ::hyve::lang::type::castable(lang::type type) */
        ::hyve::lang::_bool Type::castable(const ::hyve::lang::Type &type) const {
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
        
        /* ::hyve::lang::type::compatible(lang::type type) */
        ::hyve::lang::_bool Type::compatible_v(const ::hyve::lang::Type &type) const {
            ::hyve::lang::_bool _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::type_compatible_h),&_result,this->__handle,type._handle());
            return _result;
        }
        
        /* virtual ::hyve::lang::type::compatible(lang::type type) */
        ::hyve::lang::_bool Type::compatible(const ::hyve::lang::Type &type) const {
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
        
        /* ::hyve::lang::type::init(lang::object object) */
        ::hyve::lang::int16 Type::init(const ::hyve::lang::Object &object) const {
            ::hyve::lang::int16 _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::type_init_h),&_result,this->__handle,object._handle());
            return _result;
        }
        
        /* ::hyve::lang::type::resolveProcedure(lang::string name) */
        ::hyve::lang::Function Type::resolveProcedure(::hyve::lang::string name) const {
            ::hyve::lang::function _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::type_resolveProcedure_h),&_result,this->__handle,name);
            ::hyve::lang::Function __result(_result);
            return __result;
        }
        
        /* ::hyve::lang::type::sizeof() */
        ::hyve::lang::uint32 Type::_sizeof() const {
            ::hyve::lang::uint32 _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::type__sizeof_h),&_result,this->__handle);
            return _result;
        }
    }
}

