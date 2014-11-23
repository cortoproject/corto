/* include/hyve/lang/Character.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::character.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_character_H
#define hyve_lang_character_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Primitive.hpp"

namespace hyve {
    namespace lang {
        class Character : public ::hyve::lang::Primitive {
            
            // Constructor (new,define)
            public: Character( ::hyve::lang::width width);
            
            // Scoped constructor (declare,define)
            public: Character(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                     ::hyve::lang::width width);
            
            // Handle constructor
            public: Character(::hyve::lang::character handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::character _handle() const;
        };
    }
}

#endif

