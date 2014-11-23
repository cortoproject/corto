/* include/hyve/lang/Parameter.hpp
 *
 *  Generated on Jun 22 2013
 *    C++ definitions for ::hyve::lang::parameter.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_parameter_H
#define hyve_lang_parameter_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Object.hpp"

namespace hyve {
    namespace lang {
        class Parameter : public ::hyve::lang::Object {
            
            // Constructor (new,define)
            public: Parameter(::hyve::lang::string name,
                    ::hyve::lang::Typedef *type,
                    ::hyve::lang::_bool passByReference);
            
            // Scoped constructor (declare,define)
            public: Parameter(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                    ::hyve::lang::string name,
                    ::hyve::lang::Typedef *type,
                    ::hyve::lang::_bool passByReference);
            
            // Handle constructor
            public: Parameter(::hyve::lang::parameter handle);
            
            // Obtain handle
            public: ::hyve::lang::parameter _handle();
            
            // ::hyve::lang::string name
            public: ::hyve::lang::string name();
            public: void name(::hyve::lang::string v);
            
            // ::hyve::lang::bool passByReference
            public: ::hyve::lang::_bool passByReference();
            public: void passByReference(::hyve::lang::_bool v);
            
            // ::hyve::lang::typedef type
            public: ::hyve::lang::Typedef *type();
            public: void type(::hyve::lang::Typedef *v);
        };
    }
}

#endif

