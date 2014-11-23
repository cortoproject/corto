/* include/hyve/lang/Array.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::array.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_array_H
#define hyve_lang_array_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Collection.hpp"

namespace hyve {
    namespace lang {
        class Array : public ::hyve::lang::Collection {
            
            // Constructor (new,define)
            public: Array(const ::hyve::lang::Typedef &elementType,
                     ::hyve::lang::uint32 max);
            
            // Scoped constructor (declare,define)
            public: Array(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                    const ::hyve::lang::Typedef &elementType,
                     ::hyve::lang::uint32 max);
            
            // Handle constructor
            public: Array(::hyve::lang::array handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::array _handle() const;
            
            // ::hyve::lang::typedef elementType
            public: ::hyve::lang::Typedef elementType() const;
            public: void elementType(const ::hyve::lang::Typedef &v) const;
        };
    }
}

#endif

