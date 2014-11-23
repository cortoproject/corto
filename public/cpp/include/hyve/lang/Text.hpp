/* include/hyve/lang/Text.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::text.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_text_H
#define hyve_lang_text_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Primitive.hpp"

namespace hyve {
    namespace lang {
        class Text : public ::hyve::lang::Primitive {
            
            // Constructor (new,define)
            public: Text( ::hyve::lang::width charWidth,
                     ::hyve::lang::uint64 length);
            
            // Scoped constructor (declare,define)
            public: Text(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                     ::hyve::lang::width charWidth,
                     ::hyve::lang::uint64 length);
            
            // Handle constructor
            public: Text(::hyve::lang::text handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::text _handle() const;
            
            // ::hyve::lang::width charWidth
            public: ::hyve::lang::width charWidth() const;
            public: void charWidth( ::hyve::lang::width v) const;
            
            // ::hyve::lang::uint64 length
            public: ::hyve::lang::uint64 length() const;
            public: void length( ::hyve::lang::uint64 v) const;
        };
    }
}

#endif

