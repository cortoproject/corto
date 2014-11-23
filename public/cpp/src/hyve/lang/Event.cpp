/* src/hyve/lang/Event.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::event.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Event.hpp"
#include "hyve/lang/_meta.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Event::Event( ::hyve::lang::uint16 kind) : ::hyve::lang::Object((::hyve::lang::object)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::event_h);
            this->kind(kind);
            this->define();
        }
        
        // Constructor (declare & define)
        Event::Event(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                 ::hyve::lang::uint16 kind) : ::hyve::lang::Object((::hyve::lang::object)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::event_h);
            this->kind(kind);
            this->define();
        }
        
        // Construct from handle
        Event::Event(::hyve::lang::event handle, bool owner) : ::hyve::lang::Object((::hyve::lang::object)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::event Event::_handle() const {
            return (::hyve::lang::event)this->__handle;
        }
        
        // ::hyve::lang::uint16 kind
        ::hyve::lang::uint16 Event::kind() const {
            return ((::hyve::lang::event)this->__handle)->kind;
        }
        void Event::kind( ::hyve::lang::uint16 v) const {
            ((::hyve::lang::event)this->__handle)->kind = v;
        }
        
        // ::hyve::lang::bool handled
        ::hyve::lang::_bool Event::handled() const {
            return ((::hyve::lang::event)this->__handle)->handled;
        }
        void Event::handled( ::hyve::lang::_bool v) const {
            ((::hyve::lang::event)this->__handle)->handled = v;
        }
        
        /* ::hyve::lang::event::processed() */
        ::hyve::lang::_void Event::processed() const {
            ::hyve::call((::hyve::lang::function)(::hyve::lang::event_processed_h),NULL,this->__handle);
        }
        
        /* ::hyve::lang::event::uniqueKind() */
        ::hyve::lang::int16 Event::uniqueKind() {
            ::hyve::lang::int16 _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::event_uniqueKind_h),&_result);
            return _result;
        }
    }
}

