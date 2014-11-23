/* src/hyve/lang/Int.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::int.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Int.hpp"
#include "hyve/lang/_meta.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Int::Int( ::hyve::lang::width width,
                 ::hyve::lang::int64 min,
                 ::hyve::lang::int64 max) : ::hyve::lang::Primitive((::hyve::lang::primitive)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::_int_h);
            this->width(width);
            this->min(min);
            this->max(max);
            this->define();
        }
        
        // Constructor (declare & define)
        Int::Int(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                 ::hyve::lang::width width,
                 ::hyve::lang::int64 min,
                 ::hyve::lang::int64 max) : ::hyve::lang::Primitive((::hyve::lang::primitive)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::_int_h);
            this->width(width);
            this->min(min);
            this->max(max);
            this->define();
        }
        
        // Construct from handle
        Int::Int(::hyve::lang::_int handle, bool owner) : ::hyve::lang::Primitive((::hyve::lang::primitive)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::_int Int::_handle() const {
            return (::hyve::lang::_int)this->__handle;
        }
        
        // ::hyve::lang::int64 min
        ::hyve::lang::int64 Int::min() const {
            return ((::hyve::lang::_int)this->__handle)->min;
        }
        void Int::min( ::hyve::lang::int64 v) const {
            ((::hyve::lang::_int)this->__handle)->min = v;
        }
        
        // ::hyve::lang::int64 max
        ::hyve::lang::int64 Int::max() const {
            return ((::hyve::lang::_int)this->__handle)->max;
        }
        void Int::max( ::hyve::lang::int64 v) const {
            ((::hyve::lang::_int)this->__handle)->max = v;
        }
    }
}

