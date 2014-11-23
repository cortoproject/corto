/* src/hyve/lang/Float.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::float.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Float.hpp"
#include "hyve/lang/_meta.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Float::Float( ::hyve::lang::width width,
                 ::hyve::lang::float64 min,
                 ::hyve::lang::float64 max) : ::hyve::lang::Primitive((::hyve::lang::primitive)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::_float_h);
            this->width(width);
            this->min(min);
            this->max(max);
            this->define();
        }
        
        // Constructor (declare & define)
        Float::Float(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                 ::hyve::lang::width width,
                 ::hyve::lang::float64 min,
                 ::hyve::lang::float64 max) : ::hyve::lang::Primitive((::hyve::lang::primitive)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::_float_h);
            this->width(width);
            this->min(min);
            this->max(max);
            this->define();
        }
        
        // Construct from handle
        Float::Float(::hyve::lang::_float handle, bool owner) : ::hyve::lang::Primitive((::hyve::lang::primitive)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::_float Float::_handle() const {
            return (::hyve::lang::_float)this->__handle;
        }
        
        // ::hyve::lang::float64 min
        ::hyve::lang::float64 Float::min() const {
            return ((::hyve::lang::_float)this->__handle)->min;
        }
        void Float::min( ::hyve::lang::float64 v) const {
            ((::hyve::lang::_float)this->__handle)->min = v;
        }
        
        // ::hyve::lang::float64 max
        ::hyve::lang::float64 Float::max() const {
            return ((::hyve::lang::_float)this->__handle)->max;
        }
        void Float::max( ::hyve::lang::float64 v) const {
            ((::hyve::lang::_float)this->__handle)->max = v;
        }
    }
}

