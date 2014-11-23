/* include/hyve/lang/Primitive.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::primitive.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_primitive_H
#define hyve_lang_primitive_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Type.hpp"
namespace hyve {
    namespace lang {
        class Type;
    }
}

namespace hyve {
    namespace lang {
        class Primitive : public ::hyve::lang::Type {
            
            // Constructor (new,define)
            public: Primitive( ::hyve::lang::width width);
            
            // Scoped constructor (declare,define)
            public: Primitive(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                     ::hyve::lang::width width);
            
            // Handle constructor
            public: Primitive(::hyve::lang::primitive handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::primitive _handle() const;
            
            // ::hyve::lang::uint8 convertId
            public: ::hyve::lang::uint8 convertId() const;
            public: void convertId( ::hyve::lang::uint8 v) const;
            
            // ::hyve::lang::primitiveKind kind
            public: ::hyve::lang::primitiveKind kind() const;
            public: void kind( ::hyve::lang::primitiveKind v) const;
            
            // ::hyve::lang::width width
            public: ::hyve::lang::width width() const;
            public: void width( ::hyve::lang::width v) const;
            
            // castable(lang::type type)
            public: ::hyve::lang::_bool castable(const ::hyve::lang::Type &type) const;
            public: ::hyve::lang::_bool castable_v(const ::hyve::lang::Type &type) const;
            
            // compatible(lang::type type)
            public: ::hyve::lang::_bool compatible(const ::hyve::lang::Type &type) const;
            public: ::hyve::lang::_bool compatible_v(const ::hyve::lang::Type &type) const;
        };
    }
}

#endif

