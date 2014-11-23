/* include/hyve/lang/Typedef.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::typedef.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_typedef_H
#define hyve_lang_typedef_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Object.hpp"
namespace hyve {
    namespace lang {
        class Type;
    }
}

namespace hyve {
    namespace lang {
        class Typedef : public ::hyve::lang::Object {
            
            // Constructor (new,define)
            public: Typedef(const ::hyve::lang::Typedef &type);
            
            // Scoped constructor (declare,define)
            public: Typedef(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                    const ::hyve::lang::Typedef &type);
            
            // Handle constructor
            public: Typedef(::hyve::lang::_typedef handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::_typedef _handle() const;
            
            // ::hyve::lang::type real
            public: ::hyve::lang::Type real() const;
            public: void real(const ::hyve::lang::Type &v) const;
            
            // ::hyve::lang::typedef type
            public: ::hyve::lang::Typedef type() const;
            public: void type(const ::hyve::lang::Typedef &v) const;
            
            // realType()
            public: ::hyve::lang::Type realType() const;
        };
    }
}

#endif

