/* src/hyve/lang/Alias.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::alias.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Alias.hpp"
#include "hyve/lang/_meta.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Alias::Alias( ::hyve::lang::string typeName) : ::hyve::lang::Primitive((::hyve::lang::primitive)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::alias_h);
            this->typeName(typeName);
            this->define();
        }
        
        // Constructor (declare & define)
        Alias::Alias(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                 ::hyve::lang::string typeName) : ::hyve::lang::Primitive((::hyve::lang::primitive)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::alias_h);
            this->typeName(typeName);
            this->define();
        }
        
        // Construct from handle
        Alias::Alias(::hyve::lang::alias handle, bool owner) : ::hyve::lang::Primitive((::hyve::lang::primitive)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::alias Alias::_handle() const {
            return (::hyve::lang::alias)this->__handle;
        }
        
        // ::hyve::lang::string typeName
        ::hyve::lang::string Alias::typeName() const {
            return ((::hyve::lang::alias)this->__handle)->typeName;
        }
        void Alias::typeName( ::hyve::lang::string v) const {
            if (((::hyve::lang::alias)this->__handle)->typeName) {
                hyve::dealloc(((::hyve::lang::alias)this->__handle)->typeName);
            };
            ((::hyve::lang::alias)this->__handle)->typeName = v ? hyve::strdup(v) : NULL;
        }
    }
}

