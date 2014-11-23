/* include/hyve/lang/Boolean.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::boolean.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_boolean_H
#define hyve_lang_boolean_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Primitive.hpp"

namespace hyve {
    namespace lang {
        class Boolean : public ::hyve::lang::Primitive {
            
            // Constructor (new,define)
            public: Boolean( ::hyve::lang::width width);
            
            // Scoped constructor (declare,define)
            public: Boolean(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                     ::hyve::lang::width width);
            
            // Handle constructor
            public: Boolean(::hyve::lang::boolean handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::boolean _handle() const;
        };
    }
}

#endif

