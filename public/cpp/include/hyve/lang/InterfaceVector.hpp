/* include/hyve/lang/InterfaceVector.hpp
 *
 *  Generated on Jun 22 2013
 *    C++ definitions for ::hyve::lang::interfaceVector.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_interfaceVector_H
#define hyve_lang_interfaceVector_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Object.hpp"

namespace hyve {
    namespace lang {
        class InterfaceVector : public ::hyve::lang::Object {
            
            // Constructor (new,define)
            public: InterfaceVector(::hyve::lang::word interface,
                    ::hyve::lang::vtable vector);
            
            // Scoped constructor (declare,define)
            public: InterfaceVector(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                    ::hyve::lang::word interface,
                    ::hyve::lang::vtable vector);
            
            // Handle constructor
            public: InterfaceVector(::hyve::lang::interfaceVector handle);
            
            // Obtain handle
            public: ::hyve::lang::interfaceVector _handle();
            
            // ::hyve::lang::word interface
            public: ::hyve::lang::word interface();
            public: void interface(::hyve::lang::word v);
            
            // ::hyve::lang::vtable vector
            public: ::hyve::lang::vtable vector();
            public: void vector(::hyve::lang::vtable v);
        };
    }
}

#endif

