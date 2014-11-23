/* include/hyve/lang/Function.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::function.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_function_H
#define hyve_lang_function_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Object.hpp"

namespace hyve {
    namespace lang {
        class Function : public ::hyve::lang::Object {
            
            // Constructor (new,define)
            public: Function(const ::hyve::lang::Typedef &returnType);
            
            // Scoped constructor (declare,define)
            public: Function(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                    const ::hyve::lang::Typedef &returnType);
            
            // Handle constructor
            public: Function(::hyve::lang::function handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::function _handle() const;
            
            // ::hyve::lang::word impl
            public: ::hyve::lang::word impl() const;
            public: void impl( ::hyve::lang::word v) const;
            
            // ::hyve::lang::word impludata
            public: ::hyve::lang::word impludata() const;
            public: void impludata( ::hyve::lang::word v) const;
            
            // ::hyve::lang::uint32 kind
            public: ::hyve::lang::uint32 kind() const;
            public: void kind( ::hyve::lang::uint32 v) const;
            
            // ::hyve::lang::uint32 nextParameterId
            public: ::hyve::lang::uint32 nextParameterId() const;
            public: void nextParameterId( ::hyve::lang::uint32 v) const;
            
            // ::hyve::lang::bool overloaded
            public: ::hyve::lang::_bool overloaded() const;
            public: void overloaded( ::hyve::lang::_bool v) const;
            
            // ::hyve::lang::parameterSeq parameters
            public: ::hyve::lang::parameterSeq parameters() const;
            public: void parameters( ::hyve::lang::parameterSeq v) const;
            
            // ::hyve::lang::object resource
            public: ::hyve::lang::Object resource() const;
            public: void resource(const ::hyve::lang::Object &v) const;
            
            // ::hyve::lang::typedef returnType
            public: ::hyve::lang::Typedef returnType() const;
            public: void returnType(const ::hyve::lang::Typedef &v) const;
            
            // ::hyve::lang::int16 size
            public: ::hyve::lang::int16 size() const;
            public: void size( ::hyve::lang::int16 v) const;
        };
    }
}

#endif

