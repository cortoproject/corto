/* include/hyve/lang/Virtual.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::virtual.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_virtual_H
#define hyve_lang_virtual_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Method.hpp"

namespace hyve {
    namespace lang {
        class Virtual : public ::hyve::lang::Method {
            
            // Constructor (new,define)
            public: Virtual(const ::hyve::lang::Typedef &returnType,
                     ::hyve::lang::_bool _virtual);
            
            // Scoped constructor (declare,define)
            public: Virtual(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                    const ::hyve::lang::Typedef &returnType,
                     ::hyve::lang::_bool _virtual);
            
            // Handle constructor
            public: Virtual(::hyve::lang::_virtual handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::_virtual _handle() const;
        };
    }
}

#endif

