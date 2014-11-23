/* include/hyve/lang/Callback.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::callback.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_callback_H
#define hyve_lang_callback_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Function.hpp"

namespace hyve {
    namespace lang {
        class Callback : public ::hyve::lang::Function {
            
            // Constructor (new,define)
            public: Callback(const ::hyve::lang::Typedef &returnType,
                    const ::hyve::lang::Delegate &delegate);
            
            // Scoped constructor (declare,define)
            public: Callback(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                    const ::hyve::lang::Typedef &returnType,
                    const ::hyve::lang::Delegate &delegate);
            
            // Handle constructor
            public: Callback(::hyve::lang::callback handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::callback _handle() const;
            
            // ::hyve::lang::delegate delegate
            public: ::hyve::lang::Delegate delegate() const;
            public: void delegate(const ::hyve::lang::Delegate &v) const;
        };
    }
}

#endif

