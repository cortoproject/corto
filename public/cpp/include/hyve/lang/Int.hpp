/* include/hyve/lang/Int.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::int.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_int_H
#define hyve_lang_int_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Primitive.hpp"

namespace hyve {
    namespace lang {
        class Int : public ::hyve::lang::Primitive {
            
            // Constructor (new,define)
            public: Int( ::hyve::lang::width width,
                     ::hyve::lang::int64 min,
                     ::hyve::lang::int64 max);
            
            // Scoped constructor (declare,define)
            public: Int(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                     ::hyve::lang::width width,
                     ::hyve::lang::int64 min,
                     ::hyve::lang::int64 max);
            
            // Handle constructor
            public: Int(::hyve::lang::_int handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::_int _handle() const;
            
            // ::hyve::lang::int64 max
            public: ::hyve::lang::int64 max() const;
            public: void max( ::hyve::lang::int64 v) const;
            
            // ::hyve::lang::int64 min
            public: ::hyve::lang::int64 min() const;
            public: void min( ::hyve::lang::int64 v) const;
        };
    }
}

#endif

