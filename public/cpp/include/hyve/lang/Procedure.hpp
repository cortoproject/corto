/* include/hyve/lang/Procedure.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::procedure.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_procedure_H
#define hyve_lang_procedure_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Struct.hpp"

namespace hyve {
    namespace lang {
        class Procedure : public ::hyve::lang::Struct {
            
            // Constructor (new,define)
            public: Procedure( ::hyve::lang::procedureKind kind);
            
            // Scoped constructor (declare,define)
            public: Procedure(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                     ::hyve::lang::procedureKind kind);
            
            // Handle constructor
            public: Procedure(::hyve::lang::procedure handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::procedure _handle() const;
            
            // ::hyve::lang::procedureKind kind
            public: ::hyve::lang::procedureKind kind() const;
            public: void kind( ::hyve::lang::procedureKind v) const;
            
            // bind(lang::object object)
            public: ::hyve::lang::int16 bind(const ::hyve::lang::Object &object) const;
            
            // unbind(lang::object object)
            public: ::hyve::lang::_void unbind(const ::hyve::lang::Object &object) const;
        };
    }
}

#endif

