/* include/hyve/lang/Event.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::event.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_event_H
#define hyve_lang_event_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Object.hpp"

namespace hyve {
    namespace lang {
        class Event : public ::hyve::lang::Object {
            
            // Constructor (new,define)
            public: Event( ::hyve::lang::uint16 kind);
            
            // Scoped constructor (declare,define)
            public: Event(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                     ::hyve::lang::uint16 kind);
            
            // Handle constructor
            public: Event(::hyve::lang::event handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::event _handle() const;
            
            // ::hyve::lang::bool handled
            public: ::hyve::lang::_bool handled() const;
            public: void handled( ::hyve::lang::_bool v) const;
            
            // ::hyve::lang::uint16 kind
            public: ::hyve::lang::uint16 kind() const;
            public: void kind( ::hyve::lang::uint16 v) const;
            
            // processed()
            public: ::hyve::lang::_void processed() const;
            
            // uniqueKind()
            public: static ::hyve::lang::int16 uniqueKind();
        };
    }
}

#endif

