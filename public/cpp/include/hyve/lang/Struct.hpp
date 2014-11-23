/* include/hyve/lang/Struct.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::struct.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_struct_H
#define hyve_lang_struct_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Interface.hpp"
namespace hyve {
    namespace lang {
        class Member;
        class Type;
    }
}

namespace hyve {
    namespace lang {
        class Struct : public ::hyve::lang::Interface {
            
            // Constructor (new,define)
            public: Struct(const ::hyve::lang::Typedef &defaultType,
                    const ::hyve::lang::Typedef &parentType,
                     ::hyve::lang::state parentState,
                    const ::hyve::lang::Interface &base,
                     ::hyve::lang::modifier baseAccess);
            
            // Scoped constructor (declare,define)
            public: Struct(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                    const ::hyve::lang::Typedef &defaultType,
                    const ::hyve::lang::Typedef &parentType,
                     ::hyve::lang::state parentState,
                    const ::hyve::lang::Interface &base,
                     ::hyve::lang::modifier baseAccess);
            
            // Handle constructor
            public: Struct(::hyve::lang::_struct handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::_struct _handle() const;
            
            // ::hyve::lang::modifier baseAccess
            public: ::hyve::lang::modifier baseAccess() const;
            public: void baseAccess( ::hyve::lang::modifier v) const;
            
            // ::hyve::lang::uint16 delegateCount
            public: ::hyve::lang::uint16 delegateCount() const;
            public: void delegateCount( ::hyve::lang::uint16 v) const;
            
            // castable(lang::type type)
            public: ::hyve::lang::_bool castable(const ::hyve::lang::Type &type) const;
            public: ::hyve::lang::_bool castable_v(const ::hyve::lang::Type &type) const;
            
            // compatible(lang::type type)
            public: ::hyve::lang::_bool compatible(const ::hyve::lang::Type &type) const;
            public: ::hyve::lang::_bool compatible_v(const ::hyve::lang::Type &type) const;
            
            // resolveMember(lang::string name)
            public: ::hyve::lang::Member resolveMember(::hyve::lang::string name) const;
            public: ::hyve::lang::Member resolveMember_v(::hyve::lang::string name) const;
        };
    }
}

#endif

