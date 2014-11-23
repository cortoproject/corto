/* src/hyve/lang/Member.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::member.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Member.hpp"
#include "hyve/lang/_meta.hpp"
#include "hyve/lang/Typedef.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Member::Member(const ::hyve::lang::Typedef &type,
                 ::hyve::lang::modifier modifiers,
                 ::hyve::lang::state state,
                 ::hyve::lang::_bool weak) : ::hyve::lang::Object((::hyve::lang::object)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::member_h);
            this->type(type);
            this->modifiers(modifiers);
            this->state(state);
            this->weak(weak);
            this->define();
        }
        
        // Constructor (declare & define)
        Member::Member(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                const ::hyve::lang::Typedef &type,
                 ::hyve::lang::modifier modifiers,
                 ::hyve::lang::state state,
                 ::hyve::lang::_bool weak) : ::hyve::lang::Object((::hyve::lang::object)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::member_h);
            this->type(type);
            this->modifiers(modifiers);
            this->state(state);
            this->weak(weak);
            this->define();
        }
        
        // Construct from handle
        Member::Member(::hyve::lang::member handle, bool owner) : ::hyve::lang::Object((::hyve::lang::object)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::member Member::_handle() const {
            return (::hyve::lang::member)this->__handle;
        }
        
        // ::hyve::lang::typedef type
        ::hyve::lang::Typedef Member::type() const {
            ::hyve::lang::Typedef result(((::hyve::lang::member)this->__handle)->type);
            return result;
        }
        void Member::type(const ::hyve::lang::Typedef &v) const {
            if (v) {
                hyve::set((hyve::lang::object*)&((::hyve::lang::member)this->__handle)->type, v._handle());
            } else {
                hyve::set((hyve::lang::object*)&((::hyve::lang::member)this->__handle)->type, NULL);
            }
        }
        
        // ::hyve::lang::modifier modifiers
        ::hyve::lang::modifier Member::modifiers() const {
            return ((::hyve::lang::member)this->__handle)->modifiers;
        }
        void Member::modifiers( ::hyve::lang::modifier v) const {
            ((::hyve::lang::member)this->__handle)->modifiers = v;
        }
        
        // ::hyve::lang::state state
        ::hyve::lang::state Member::state() const {
            return ((::hyve::lang::member)this->__handle)->state;
        }
        void Member::state( ::hyve::lang::state v) const {
            ((::hyve::lang::member)this->__handle)->state = v;
        }
        
        // ::hyve::lang::bool weak
        ::hyve::lang::_bool Member::weak() const {
            return ((::hyve::lang::member)this->__handle)->weak;
        }
        void Member::weak( ::hyve::lang::_bool v) const {
            ((::hyve::lang::member)this->__handle)->weak = v;
        }
        
        // ::hyve::lang::uint32 id
        ::hyve::lang::uint32 Member::id() const {
            return ((::hyve::lang::member)this->__handle)->id;
        }
        void Member::id( ::hyve::lang::uint32 v) const {
            ((::hyve::lang::member)this->__handle)->id = v;
        }
        
        // ::hyve::lang::uint32 offset
        ::hyve::lang::uint32 Member::offset() const {
            return ((::hyve::lang::member)this->__handle)->offset;
        }
        void Member::offset( ::hyve::lang::uint32 v) const {
            ((::hyve::lang::member)this->__handle)->offset = v;
        }
    }
}

