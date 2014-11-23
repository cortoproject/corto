/* include/hyve/lang/Member.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::member.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_member_H
#define hyve_lang_member_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Object.hpp"

namespace hyve {
    namespace lang {
        class Member : public ::hyve::lang::Object {
            
            // Constructor (new,define)
            public: Member(const ::hyve::lang::Typedef &type,
                     ::hyve::lang::modifier modifiers,
                     ::hyve::lang::state state,
                     ::hyve::lang::_bool weak);
            
            // Scoped constructor (declare,define)
            public: Member(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                    const ::hyve::lang::Typedef &type,
                     ::hyve::lang::modifier modifiers,
                     ::hyve::lang::state state,
                     ::hyve::lang::_bool weak);
            
            // Handle constructor
            public: Member(::hyve::lang::member handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::member _handle() const;
            
            // ::hyve::lang::uint32 id
            public: ::hyve::lang::uint32 id() const;
            public: void id( ::hyve::lang::uint32 v) const;
            
            // ::hyve::lang::modifier modifiers
            public: ::hyve::lang::modifier modifiers() const;
            public: void modifiers( ::hyve::lang::modifier v) const;
            
            // ::hyve::lang::uint32 offset
            public: ::hyve::lang::uint32 offset() const;
            public: void offset( ::hyve::lang::uint32 v) const;
            
            // ::hyve::lang::state state
            public: ::hyve::lang::state state() const;
            public: void state( ::hyve::lang::state v) const;
            
            // ::hyve::lang::typedef type
            public: ::hyve::lang::Typedef type() const;
            public: void type(const ::hyve::lang::Typedef &v) const;
            
            // ::hyve::lang::bool weak
            public: ::hyve::lang::_bool weak() const;
            public: void weak( ::hyve::lang::_bool v) const;
        };
    }
}

#endif

