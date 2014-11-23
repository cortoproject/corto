/* include/hyve/lang/Interface.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::interface.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_interface_H
#define hyve_lang_interface_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Type.hpp"
namespace hyve {
    namespace lang {
        class Member;
        class Type;
        class Method;
    }
}

namespace hyve {
    namespace lang {
        class Interface : public ::hyve::lang::Type {
            
            // Constructor (new,define)
            public: Interface(const ::hyve::lang::Typedef &defaultType,
                    const ::hyve::lang::Typedef &parentType,
                     ::hyve::lang::state parentState,
                    const ::hyve::lang::Interface &base);
            
            // Scoped constructor (declare,define)
            public: Interface(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                    const ::hyve::lang::Typedef &defaultType,
                    const ::hyve::lang::Typedef &parentType,
                     ::hyve::lang::state parentState,
                    const ::hyve::lang::Interface &base);
            
            // Handle constructor
            public: Interface(::hyve::lang::interface handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::interface _handle() const;
            
            // ::hyve::lang::interface base
            public: ::hyve::lang::Interface base() const;
            public: void base(const ::hyve::lang::Interface &v) const;
            
            // ::hyve::lang::compositeKind kind
            public: ::hyve::lang::compositeKind kind() const;
            public: void kind( ::hyve::lang::compositeKind v) const;
            
            // ::hyve::lang::memberSeq members
            public: ::hyve::lang::memberSeq members() const;
            public: void members( ::hyve::lang::memberSeq v) const;
            
            // ::hyve::lang::vtable methods
            public: ::hyve::lang::vtable methods() const;
            public: void methods( ::hyve::lang::vtable v) const;
            
            // ::hyve::lang::uint32 nextMemberId
            public: ::hyve::lang::uint32 nextMemberId() const;
            public: void nextMemberId( ::hyve::lang::uint32 v) const;
            
            // bindMethod(lang::method method)
            public: ::hyve::lang::int16 bindMethod(const ::hyve::lang::Method &method) const;
            public: ::hyve::lang::int16 bindMethod_v(const ::hyve::lang::Method &method) const;
            
            // compatible(lang::type type)
            public: ::hyve::lang::_bool compatible(const ::hyve::lang::Type &type) const;
            public: ::hyve::lang::_bool compatible_v(const ::hyve::lang::Type &type) const;
            
            // resolveMember(lang::string name)
            public: ::hyve::lang::Member resolveMember(::hyve::lang::string name) const;
            public: ::hyve::lang::Member resolveMember_v(::hyve::lang::string name) const;
            
            // resolveMethod(lang::string name)
            public: ::hyve::lang::Method resolveMethod(::hyve::lang::string name) const;
            
            // resolveMethodById(lang::uint32 id)
            public: ::hyve::lang::Method resolveMethodById(::hyve::lang::uint32 id) const;
            
            // resolveMethodId(lang::string name)
            public: ::hyve::lang::uint32 resolveMethodId(::hyve::lang::string name) const;
        };
    }
}

#endif

