/* src/hyve/lang/Array.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::array.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Array.hpp"
#include "hyve/lang/_meta.hpp"
#include "hyve/lang/Typedef.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Array::Array(const ::hyve::lang::Typedef &elementType,
                 ::hyve::lang::uint32 max) : ::hyve::lang::Collection((::hyve::lang::collection)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::array_h);
            this->elementType(elementType);
            this->max(max);
            this->define();
        }
        
        // Constructor (declare & define)
        Array::Array(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                const ::hyve::lang::Typedef &elementType,
                 ::hyve::lang::uint32 max) : ::hyve::lang::Collection((::hyve::lang::collection)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::array_h);
            this->elementType(elementType);
            this->max(max);
            this->define();
        }
        
        // Construct from handle
        Array::Array(::hyve::lang::array handle, bool owner) : ::hyve::lang::Collection((::hyve::lang::collection)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::array Array::_handle() const {
            return (::hyve::lang::array)this->__handle;
        }
        
        // ::hyve::lang::typedef elementType
        ::hyve::lang::Typedef Array::elementType() const {
            ::hyve::lang::Typedef result(((::hyve::lang::array)this->__handle)->elementType);
            return result;
        }
        void Array::elementType(const ::hyve::lang::Typedef &v) const {
            if (v) {
                hyve::set((hyve::lang::object*)&((::hyve::lang::array)this->__handle)->elementType, v._handle());
            } else {
                hyve::set((hyve::lang::object*)&((::hyve::lang::array)this->__handle)->elementType, NULL);
            }
        }
    }
}

