/* src/hyve/lang/Uint.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::uint.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Uint.hpp"
#include "hyve/lang/_meta.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Uint::Uint( ::hyve::lang::width width,
                 ::hyve::lang::uint64 min,
                 ::hyve::lang::uint64 max) : ::hyve::lang::Primitive((::hyve::lang::primitive)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::uint_h);
            this->width(width);
            this->min(min);
            this->max(max);
            this->define();
        }
        
        // Constructor (declare & define)
        Uint::Uint(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                 ::hyve::lang::width width,
                 ::hyve::lang::uint64 min,
                 ::hyve::lang::uint64 max) : ::hyve::lang::Primitive((::hyve::lang::primitive)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::uint_h);
            this->width(width);
            this->min(min);
            this->max(max);
            this->define();
        }
        
        // Construct from handle
        Uint::Uint(::hyve::lang::uint handle, bool owner) : ::hyve::lang::Primitive((::hyve::lang::primitive)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::uint Uint::_handle() const {
            return (::hyve::lang::uint)this->__handle;
        }
        
        // ::hyve::lang::uint64 min
        ::hyve::lang::uint64 Uint::min() const {
            return ((::hyve::lang::uint)this->__handle)->min;
        }
        void Uint::min( ::hyve::lang::uint64 v) const {
            ((::hyve::lang::uint)this->__handle)->min = v;
        }
        
        // ::hyve::lang::uint64 max
        ::hyve::lang::uint64 Uint::max() const {
            return ((::hyve::lang::uint)this->__handle)->max;
        }
        void Uint::max( ::hyve::lang::uint64 v) const {
            ((::hyve::lang::uint)this->__handle)->max = v;
        }
    }
}

