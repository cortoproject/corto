/* include/hyve/lang/Alias.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::alias.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_alias_H
#define hyve_lang_alias_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Primitive.hpp"

namespace hyve {
    namespace lang {
        class Alias : public ::hyve::lang::Primitive {
            
            // Constructor (new,define)
            public: Alias( ::hyve::lang::string typeName);
            
            // Scoped constructor (declare,define)
            public: Alias(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                     ::hyve::lang::string typeName);
            
            // Handle constructor
            public: Alias(::hyve::lang::alias handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::alias _handle() const;
            
            // ::hyve::lang::string typeName
            public: ::hyve::lang::string typeName() const;
            public: void typeName( ::hyve::lang::string v) const;
        };
    }
}

#endif

