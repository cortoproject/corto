/* src/hyve/lang/Sequence.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::sequence.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Sequence.hpp"
#include "hyve/lang/_meta.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Sequence::Sequence(const ::hyve::lang::Typedef &elementType,
                 ::hyve::lang::uint32 max) : ::hyve::lang::Collection((::hyve::lang::collection)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::sequence_h);
            this->elementType(elementType);
            this->max(max);
            this->define();
        }
        
        // Constructor (declare & define)
        Sequence::Sequence(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                const ::hyve::lang::Typedef &elementType,
                 ::hyve::lang::uint32 max) : ::hyve::lang::Collection((::hyve::lang::collection)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::sequence_h);
            this->elementType(elementType);
            this->max(max);
            this->define();
        }
        
        // Construct from handle
        Sequence::Sequence(::hyve::lang::sequence handle, bool owner) : ::hyve::lang::Collection((::hyve::lang::collection)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::sequence Sequence::_handle() const {
            return (::hyve::lang::sequence)this->__handle;
        }
    }
}

