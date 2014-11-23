/* include/hyve/lang/Metaprocedure.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::metaprocedure.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_metaprocedure_H
#define hyve_lang_metaprocedure_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Function.hpp"

namespace hyve {
    namespace lang {
        class Metaprocedure : public ::hyve::lang::Function {
            
            // Constructor (new,define)
            public: Metaprocedure(const ::hyve::lang::Typedef &returnType);
            
            // Scoped constructor (declare,define)
            public: Metaprocedure(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                    const ::hyve::lang::Typedef &returnType);
            
            // Handle constructor
            public: Metaprocedure(::hyve::lang::metaprocedure handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::metaprocedure _handle() const;
        };
    }
}

#endif

