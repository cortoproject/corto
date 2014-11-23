/* include/hyve/lang/List.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::list.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_list_H
#define hyve_lang_list_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Collection.hpp"

namespace hyve {
    namespace lang {
        class List : public ::hyve::lang::Collection {
            
            // Constructor (new,define)
            public: List(const ::hyve::lang::Typedef &elementType,
                     ::hyve::lang::uint32 max);
            
            // Scoped constructor (declare,define)
            public: List(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                    const ::hyve::lang::Typedef &elementType,
                     ::hyve::lang::uint32 max);
            
            // Handle constructor
            public: List(::hyve::lang::list handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::list _handle() const;
        };
    }
}

#endif

