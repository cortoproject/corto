/* include/hyve/lang/Bitmask.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::bitmask.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_bitmask_H
#define hyve_lang_bitmask_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Enum.hpp"

namespace hyve {
    namespace lang {
        class Bitmask : public ::hyve::lang::Enum {
            
            // Constructor (new,define)
            public: Bitmask();
            
            // Scoped constructor (declare,define)
            public: Bitmask(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name);
            
            // Handle constructor
            public: Bitmask(::hyve::lang::bitmask handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::bitmask _handle() const;
        };
    }
}

#endif

