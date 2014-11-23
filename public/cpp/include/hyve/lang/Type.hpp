/* include/hyve/lang/Type.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::type.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_type_H
#define hyve_lang_type_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Typedef.hpp"
namespace hyve {
    namespace lang {
        class Function;
    }
}

namespace hyve {
    namespace lang {
        class Type : public ::hyve::lang::Typedef {
            
            // Constructor (new,define)
            public: Type(const ::hyve::lang::Typedef &defaultType,
                    const ::hyve::lang::Typedef &parentType,
                     ::hyve::lang::state parentState);
            
            // Scoped constructor (declare,define)
            public: Type(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                    const ::hyve::lang::Typedef &defaultType,
                    const ::hyve::lang::Typedef &parentType,
                     ::hyve::lang::state parentState);
            
            // Handle constructor
            public: Type(::hyve::lang::type handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::type _handle() const;
            
            // ::hyve::lang::uint16 alignment
            public: ::hyve::lang::uint16 alignment() const;
            public: void alignment( ::hyve::lang::uint16 v) const;
            
            // ::hyve::lang::typedef defaultType
            public: ::hyve::lang::Typedef defaultType() const;
            public: void defaultType(const ::hyve::lang::Typedef &v) const;
            
            // ::hyve::lang::bool hasResources
            public: ::hyve::lang::_bool hasResources() const;
            public: void hasResources( ::hyve::lang::_bool v) const;
            
            // ::hyve::lang::typeKind kind
            public: ::hyve::lang::typeKind kind() const;
            public: void kind( ::hyve::lang::typeKind v) const;
            
            // ::hyve::lang::vtable metaprocedures
            public: ::hyve::lang::vtable metaprocedures() const;
            public: void metaprocedures( ::hyve::lang::vtable v) const;
            
            // ::hyve::lang::state parentState
            public: ::hyve::lang::state parentState() const;
            public: void parentState( ::hyve::lang::state v) const;
            
            // ::hyve::lang::typedef parentType
            public: ::hyve::lang::Typedef parentType() const;
            public: void parentType(const ::hyve::lang::Typedef &v) const;
            
            // ::hyve::lang::bool reference
            public: ::hyve::lang::_bool reference() const;
            public: void reference( ::hyve::lang::_bool v) const;
            
            // ::hyve::lang::uint32 size
            public: ::hyve::lang::uint32 size() const;
            public: void size( ::hyve::lang::uint32 v) const;
            
            // ::hyve::lang::uint32 templateId
            public: ::hyve::lang::uint32 templateId() const;
            public: void templateId( ::hyve::lang::uint32 v) const;
            
            // alignmentof()
            public: ::hyve::lang::uint16 alignmentof() const;
            
            // allocSize()
            public: ::hyve::lang::uint32 allocSize() const;
            public: ::hyve::lang::uint32 allocSize_v() const;
            
            // castable(lang::type type)
            public: ::hyve::lang::_bool castable(const ::hyve::lang::Type &type) const;
            public: ::hyve::lang::_bool castable_v(const ::hyve::lang::Type &type) const;
            
            // compatible(lang::type type)
            public: ::hyve::lang::_bool compatible(const ::hyve::lang::Type &type) const;
            public: ::hyve::lang::_bool compatible_v(const ::hyve::lang::Type &type) const;
            
            // init(lang::object object)
            public: ::hyve::lang::int16 init(const ::hyve::lang::Object &object) const;
            
            // resolveProcedure(lang::string name)
            public: ::hyve::lang::Function resolveProcedure(::hyve::lang::string name) const;
            
            // sizeof()
            public: ::hyve::lang::uint32 _sizeof() const;
        };
    }
}

#endif

