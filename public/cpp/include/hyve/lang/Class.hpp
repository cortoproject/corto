/* include/hyve/lang/Class.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::class.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_class_H
#define hyve_lang_class_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Struct.hpp"
namespace hyve {
    namespace lang {
        class Observer;
        class Method;
    }
}

namespace hyve {
    namespace lang {
        class Class : public ::hyve::lang::Struct {
            
            // Constructor (new,define)
            public: Class(const ::hyve::lang::Typedef &defaultType,
                    const ::hyve::lang::Typedef &parentType,
                     ::hyve::lang::state parentState,
                    const ::hyve::lang::Interface &base,
                     ::hyve::lang::modifier baseAccess,
                     ::hyve::lang::interfaceSeq implements);
            
            // Scoped constructor (declare,define)
            public: Class(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                    const ::hyve::lang::Typedef &defaultType,
                    const ::hyve::lang::Typedef &parentType,
                     ::hyve::lang::state parentState,
                    const ::hyve::lang::Interface &base,
                     ::hyve::lang::modifier baseAccess,
                     ::hyve::lang::interfaceSeq implements);
            
            // Handle constructor
            public: Class(::hyve::lang::_class handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::_class _handle() const;
            
            // ::hyve::lang::interfaceSeq implements
            public: ::hyve::lang::interfaceSeq implements() const;
            public: void implements( ::hyve::lang::interfaceSeq v) const;
            
            // ::hyve::lang::interfaceVectorSeq interfaceVector
            public: ::hyve::lang::interfaceVectorSeq interfaceVector() const;
            public: void interfaceVector( ::hyve::lang::interfaceVectorSeq v) const;
            
            // ::hyve::lang::observerSeq observers
            public: ::hyve::lang::observerSeq observers() const;
            public: void observers( ::hyve::lang::observerSeq v) const;
            
            // allocSize()
            public: ::hyve::lang::uint32 allocSize() const;
            public: ::hyve::lang::uint32 allocSize_v() const;
            
            // bindMethod(lang::method method)
            public: ::hyve::lang::int16 bindMethod(const ::hyve::lang::Method &method) const;
            public: ::hyve::lang::int16 bindMethod_v(const ::hyve::lang::Method &method) const;
            
            // construct(lang::object object)
            public: ::hyve::lang::int16 construct(const ::hyve::lang::Object &object) const;
            
            // destruct(lang::object object)
            public: ::hyve::lang::_void destruct(const ::hyve::lang::Object &object) const;
            
            // instanceof(lang::object object)
            public: ::hyve::lang::_bool instanceof(const ::hyve::lang::Object &object) const;
            
            // privateObserver(lang::object object,lang::observer observer)
            public: ::hyve::lang::Observer privateObserver(const ::hyve::lang::Object &object, const ::hyve::lang::Observer &observer) const;
        };
    }
}

#endif

