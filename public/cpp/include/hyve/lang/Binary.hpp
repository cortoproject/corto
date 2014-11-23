/* include/hyve/lang/Binary.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::binary.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_binary_H
#define hyve_lang_binary_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Primitive.hpp"

namespace hyve {
    namespace lang {
        class Binary : public ::hyve::lang::Primitive {
            
            // Constructor (new,define)
            public: Binary( ::hyve::lang::width width);
            
            // Scoped constructor (declare,define)
            public: Binary(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                     ::hyve::lang::width width);
            
            // Handle constructor
            public: Binary(::hyve::lang::binary handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::binary _handle() const;
        };
    }
}

#endif

