/* src/hyve/lang/Enum.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::enum.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Enum.hpp"
#include "hyve/lang/_meta.hpp"
#include "hyve/lang/Object.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Enum::Enum() : ::hyve::lang::Primitive((::hyve::lang::primitive)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::_enum_h);
            this->define();
        }
        
        // Constructor (declare & define)
        Enum::Enum(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name) : ::hyve::lang::Primitive((::hyve::lang::primitive)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::_enum_h);
            this->define();
        }
        
        // Construct from handle
        Enum::Enum(::hyve::lang::_enum handle, bool owner) : ::hyve::lang::Primitive((::hyve::lang::primitive)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::_enum Enum::_handle() const {
            return (::hyve::lang::_enum)this->__handle;
        }
        
        // ::hyve::lang::objectSeq constants
        ::hyve::lang::objectSeq Enum::constants() const {
            return ((::hyve::lang::_enum)this->__handle)->constants;
        }
        void Enum::constants( ::hyve::lang::objectSeq v) const {
            ((::hyve::lang::_enum)this->__handle)->constants = v;
        }
        
        /* ::hyve::lang::enum::constant(lang::int32 value) */
        ::hyve::lang::Object Enum::constant(::hyve::lang::int32 value) const {
            ::hyve::lang::object _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::_enum_constant_h),&_result,this->__handle,value);
            return _result;
        }
    }
}

