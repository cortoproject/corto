/* include/hyve/lang/Uint.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::uint.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_uint_H
#define hyve_lang_uint_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Primitive.hpp"

namespace hyve {
    namespace lang {
        class Uint : public ::hyve::lang::Primitive {
            
            // Constructor (new,define)
            public: Uint( ::hyve::lang::width width,
                     ::hyve::lang::uint64 min,
                     ::hyve::lang::uint64 max);
            
            // Scoped constructor (declare,define)
            public: Uint(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                     ::hyve::lang::width width,
                     ::hyve::lang::uint64 min,
                     ::hyve::lang::uint64 max);
            
            // Handle constructor
            public: Uint(::hyve::lang::uint handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::uint _handle() const;
            
            // ::hyve::lang::uint64 max
            public: ::hyve::lang::uint64 max() const;
            public: void max( ::hyve::lang::uint64 v) const;
            
            // ::hyve::lang::uint64 min
            public: ::hyve::lang::uint64 min() const;
            public: void min( ::hyve::lang::uint64 v) const;
        };
    }
}

#endif

