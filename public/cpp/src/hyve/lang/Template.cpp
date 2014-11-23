/* src/hyve/lang/Template.cpp
 *
 *  Generated on Jan  9 2014
 *    C++ implementationfile for ::hyve::lang::template.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Template.hpp"
#include "hyve/lang/_meta.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Template::Template() : ::hyve::lang::Type((::hyve::lang::type)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::_template_h);
            this->define();
        }
        
        // Constructor (declare & define)
        Template::Template(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name) : ::hyve::lang::Type((::hyve::lang::type)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::_template_h);
            this->define();
        }
        
        // Construct from handle
        Template::Template(::hyve::lang::_template handle, bool owner) : ::hyve::lang::Type((::hyve::lang::type)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::_template Template::_handle() const {
            return (::hyve::lang::_template)this->__handle;
        }
    }
}

