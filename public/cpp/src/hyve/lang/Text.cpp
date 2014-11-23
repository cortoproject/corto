/* src/hyve/lang/Text.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::text.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Text.hpp"
#include "hyve/lang/_meta.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Text::Text( ::hyve::lang::width charWidth,
                 ::hyve::lang::uint64 length) : ::hyve::lang::Primitive((::hyve::lang::primitive)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::text_h);
            this->charWidth(charWidth);
            this->length(length);
            this->define();
        }
        
        // Constructor (declare & define)
        Text::Text(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                 ::hyve::lang::width charWidth,
                 ::hyve::lang::uint64 length) : ::hyve::lang::Primitive((::hyve::lang::primitive)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::text_h);
            this->charWidth(charWidth);
            this->length(length);
            this->define();
        }
        
        // Construct from handle
        Text::Text(::hyve::lang::text handle, bool owner) : ::hyve::lang::Primitive((::hyve::lang::primitive)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::text Text::_handle() const {
            return (::hyve::lang::text)this->__handle;
        }
        
        // ::hyve::lang::width charWidth
        ::hyve::lang::width Text::charWidth() const {
            return ((::hyve::lang::text)this->__handle)->charWidth;
        }
        void Text::charWidth( ::hyve::lang::width v) const {
            ((::hyve::lang::text)this->__handle)->charWidth = v;
        }
        
        // ::hyve::lang::uint64 length
        ::hyve::lang::uint64 Text::length() const {
            return ((::hyve::lang::text)this->__handle)->length;
        }
        void Text::length( ::hyve::lang::uint64 v) const {
            ((::hyve::lang::text)this->__handle)->length = v;
        }
    }
}

