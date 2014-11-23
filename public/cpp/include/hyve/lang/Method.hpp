/* include/hyve/lang/Method.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::method.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_method_H
#define hyve_lang_method_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Function.hpp"

namespace hyve {
    namespace lang {
        class Method : public ::hyve::lang::Function {
            
            // Constructor (new,define)
            public: Method(const ::hyve::lang::Typedef &returnType,
                     ::hyve::lang::_bool _virtual);
            
            // Scoped constructor (declare,define)
            public: Method(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                    const ::hyve::lang::Typedef &returnType,
                     ::hyve::lang::_bool _virtual);
            
            // Handle constructor
            public: Method(::hyve::lang::method handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::method _handle() const;
            
            // ::hyve::lang::bool virtual
            public: ::hyve::lang::_bool _virtual() const;
            public: void _virtual( ::hyve::lang::_bool v) const;
        };
    }
}

#endif

