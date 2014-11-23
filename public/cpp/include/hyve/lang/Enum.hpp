/* include/hyve/lang/Enum.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::enum.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_enum_H
#define hyve_lang_enum_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Primitive.hpp"

namespace hyve {
    namespace lang {
        class Enum : public ::hyve::lang::Primitive {
            
            // Constructor (new,define)
            public: Enum();
            
            // Scoped constructor (declare,define)
            public: Enum(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name);
            
            // Handle constructor
            public: Enum(::hyve::lang::_enum handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::_enum _handle() const;
            
            // ::hyve::lang::objectSeq constants
            public: ::hyve::lang::objectSeq constants() const;
            public: void constants( ::hyve::lang::objectSeq v) const;
            
            // constant(lang::int32 value)
            public: ::hyve::lang::Object constant(::hyve::lang::int32 value) const;
        };
    }
}

#endif

