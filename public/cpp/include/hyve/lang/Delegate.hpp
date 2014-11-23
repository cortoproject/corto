/* include/hyve/lang/Delegate.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::delegate.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_delegate_H
#define hyve_lang_delegate_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Function.hpp"

namespace hyve {
    namespace lang {
        class Delegate : public ::hyve::lang::Function {
            
            // Constructor (new,define)
            public: Delegate(const ::hyve::lang::Typedef &returnType);
            
            // Scoped constructor (declare,define)
            public: Delegate(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                    const ::hyve::lang::Typedef &returnType);
            
            // Handle constructor
            public: Delegate(::hyve::lang::delegate handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::delegate _handle() const;
            
            // ::hyve::lang::uint32 id
            public: ::hyve::lang::uint32 id() const;
            public: void id( ::hyve::lang::uint32 v) const;
        };
    }
}

#endif

