/* include/hyve/lang/Float.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::float.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_float_H
#define hyve_lang_float_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Primitive.hpp"

namespace hyve {
    namespace lang {
        class Float : public ::hyve::lang::Primitive {
            
            // Constructor (new,define)
            public: Float( ::hyve::lang::width width,
                     ::hyve::lang::float64 min,
                     ::hyve::lang::float64 max);
            
            // Scoped constructor (declare,define)
            public: Float(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                     ::hyve::lang::width width,
                     ::hyve::lang::float64 min,
                     ::hyve::lang::float64 max);
            
            // Handle constructor
            public: Float(::hyve::lang::_float handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::_float _handle() const;
            
            // ::hyve::lang::float64 max
            public: ::hyve::lang::float64 max() const;
            public: void max( ::hyve::lang::float64 v) const;
            
            // ::hyve::lang::float64 min
            public: ::hyve::lang::float64 min() const;
            public: void min( ::hyve::lang::float64 v) const;
        };
    }
}

#endif

