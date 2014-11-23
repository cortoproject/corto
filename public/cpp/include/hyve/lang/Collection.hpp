/* include/hyve/lang/Collection.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::collection.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_collection_H
#define hyve_lang_collection_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Type.hpp"
namespace hyve {
    namespace lang {
        class Type;
    }
}

namespace hyve {
    namespace lang {
        class Collection : public ::hyve::lang::Type {
            
            // Constructor (new,define)
            public: Collection(const ::hyve::lang::Typedef &elementType,
                     ::hyve::lang::uint32 max);
            
            // Scoped constructor (declare,define)
            public: Collection(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                    const ::hyve::lang::Typedef &elementType,
                     ::hyve::lang::uint32 max);
            
            // Handle constructor
            public: Collection(::hyve::lang::collection handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::collection _handle() const;
            
            // ::hyve::lang::typedef elementType
            public: ::hyve::lang::Typedef elementType() const;
            public: void elementType(const ::hyve::lang::Typedef &v) const;
            
            // ::hyve::lang::collectionKind kind
            public: ::hyve::lang::collectionKind kind() const;
            public: void kind( ::hyve::lang::collectionKind v) const;
            
            // ::hyve::lang::uint32 max
            public: ::hyve::lang::uint32 max() const;
            public: void max( ::hyve::lang::uint32 v) const;
            
            // castable(lang::type type)
            public: ::hyve::lang::_bool castable(const ::hyve::lang::Type &type) const;
            public: ::hyve::lang::_bool castable_v(const ::hyve::lang::Type &type) const;
        };
    }
}

#endif

