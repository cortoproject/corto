/* include/hyve/lang/Reference.hpp
 *
 *  Generated on Aug  2 2013
 *    C++ definitions for ::hyve::lang::reference.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_reference_H
#define hyve_lang_reference_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Member.hpp"

namespace hyve {
    namespace lang {
        class Reference : public ::hyve::lang::Member {
            
            // Constructor (new,define)
            public: Reference(::hyve::lang::Typedef *type,
                    ::hyve::lang::modifier modifiers,
                    ::hyve::lang::uint32 id,
                    ::hyve::lang::uint8 state,
                    ::hyve::lang::_bool weak);
            
            // Scoped constructor (declare,define)
            public: Reference(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                    ::hyve::lang::Typedef *type,
                    ::hyve::lang::modifier modifiers,
                    ::hyve::lang::uint32 id,
                    ::hyve::lang::uint8 state,
                    ::hyve::lang::_bool weak);
            
            // Handle constructor
            public: Reference(::hyve::lang::reference handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::reference _handle();
            
            // ::hyve::lang::uint8 state
            public: ::hyve::lang::uint8 state();
            public: void state(::hyve::lang::uint8 v);
            
            // ::hyve::lang::bool weak
            public: ::hyve::lang::_bool weak();
            public: void weak(::hyve::lang::_bool v);
        };
    }
}

#endif

