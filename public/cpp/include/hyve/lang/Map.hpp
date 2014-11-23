/* include/hyve/lang/Map.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::map.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_map_H
#define hyve_lang_map_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Collection.hpp"

namespace hyve {
    namespace lang {
        class Map : public ::hyve::lang::Collection {
            
            // Constructor (new,define)
            public: Map(const ::hyve::lang::Typedef &elementType,
                    const ::hyve::lang::Typedef &keyType,
                     ::hyve::lang::uint32 max);
            
            // Scoped constructor (declare,define)
            public: Map(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                    const ::hyve::lang::Typedef &elementType,
                    const ::hyve::lang::Typedef &keyType,
                     ::hyve::lang::uint32 max);
            
            // Handle constructor
            public: Map(::hyve::lang::map handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::map _handle() const;
            
            // ::hyve::lang::typedef elementType
            public: ::hyve::lang::Typedef elementType() const;
            public: void elementType(const ::hyve::lang::Typedef &v) const;
            
            // ::hyve::lang::typedef keyType
            public: ::hyve::lang::Typedef keyType() const;
            public: void keyType(const ::hyve::lang::Typedef &v) const;
            
            // ::hyve::lang::uint32 max
            public: ::hyve::lang::uint32 max() const;
            public: void max( ::hyve::lang::uint32 v) const;
        };
    }
}

#endif

