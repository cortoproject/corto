/* src/hyve/lang/Typedef.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::typedef.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Typedef.hpp"
#include "hyve/lang/_meta.hpp"
#include "hyve/lang/Type.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Typedef::Typedef(const ::hyve::lang::Typedef &type) : ::hyve::lang::Object((::hyve::lang::object)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::_typedef_h);
            this->type(type);
            this->define();
        }
        
        // Constructor (declare & define)
        Typedef::Typedef(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                const ::hyve::lang::Typedef &type) : ::hyve::lang::Object((::hyve::lang::object)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::_typedef_h);
            this->type(type);
            this->define();
        }
        
        // Construct from handle
        Typedef::Typedef(::hyve::lang::_typedef handle, bool owner) : ::hyve::lang::Object((::hyve::lang::object)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::_typedef Typedef::_handle() const {
            return (::hyve::lang::_typedef)this->__handle;
        }
        
        // ::hyve::lang::typedef type
        ::hyve::lang::Typedef Typedef::type() const {
            ::hyve::lang::Typedef result(((::hyve::lang::_typedef)this->__handle)->type);
            return result;
        }
        void Typedef::type(const ::hyve::lang::Typedef &v) const {
            if (v) {
                hyve::set((hyve::lang::object*)&((::hyve::lang::_typedef)this->__handle)->type, v._handle());
            } else {
                hyve::set((hyve::lang::object*)&((::hyve::lang::_typedef)this->__handle)->type, NULL);
            }
        }
        
        // ::hyve::lang::type real
        ::hyve::lang::Type Typedef::real() const {
            ::hyve::lang::Type result(((::hyve::lang::_typedef)this->__handle)->real);
            return result;
        }
        void Typedef::real(const ::hyve::lang::Type &v) const {
            if (v) {
                hyve::set((hyve::lang::object*)&((::hyve::lang::_typedef)this->__handle)->real, v._handle());
            } else {
                hyve::set((hyve::lang::object*)&((::hyve::lang::_typedef)this->__handle)->real, NULL);
            }
        }
        
        /* ::hyve::lang::typedef::realType() */
        ::hyve::lang::Type Typedef::realType() const {
            ::hyve::lang::type _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::_typedef_realType_h),&_result,this->__handle);
            ::hyve::lang::Type __result(_result);
            return __result;
        }
    }
}

