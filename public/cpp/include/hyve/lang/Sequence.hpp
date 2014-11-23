/* include/hyve/lang/Sequence.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::sequence.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_sequence_H
#define hyve_lang_sequence_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Collection.hpp"

namespace hyve {
    namespace lang {
        class Sequence : public ::hyve::lang::Collection {
            
            // Constructor (new,define)
            public: Sequence(const ::hyve::lang::Typedef &elementType,
                     ::hyve::lang::uint32 max);
            
            // Scoped constructor (declare,define)
            public: Sequence(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                    const ::hyve::lang::Typedef &elementType,
                     ::hyve::lang::uint32 max);
            
            // Handle constructor
            public: Sequence(::hyve::lang::sequence handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::sequence _handle() const;
        };
    }
}

#endif

