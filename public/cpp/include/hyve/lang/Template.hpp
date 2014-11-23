/* include/hyve/lang/Template.hpp
 *
 *  Generated on Jan  9 2014
 *    C++ definitions for ::hyve::lang::template.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_template_H
#define hyve_lang_template_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Type.hpp"

namespace hyve {
    namespace lang {
        class Template : public ::hyve::lang::Type {
            
            // Constructor (new,define)
            public: Template();
            
            // Scoped constructor (declare,define)
            public: Template(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name);
            
            // Handle constructor
            public: Template(::hyve::lang::_template handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::_template _handle() const;
        };
    }
}

#endif

