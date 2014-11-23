/* src/hyve/lang/Map.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::map.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Map.hpp"
#include "hyve/lang/_meta.hpp"
#include "hyve/lang/Typedef.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Map::Map(const ::hyve::lang::Typedef &elementType,
                const ::hyve::lang::Typedef &keyType,
                 ::hyve::lang::uint32 max) : ::hyve::lang::Collection((::hyve::lang::collection)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::map_h);
            this->elementType(elementType);
            this->keyType(keyType);
            this->max(max);
            this->define();
        }
        
        // Constructor (declare & define)
        Map::Map(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                const ::hyve::lang::Typedef &elementType,
                const ::hyve::lang::Typedef &keyType,
                 ::hyve::lang::uint32 max) : ::hyve::lang::Collection((::hyve::lang::collection)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::map_h);
            this->elementType(elementType);
            this->keyType(keyType);
            this->max(max);
            this->define();
        }
        
        // Construct from handle
        Map::Map(::hyve::lang::map handle, bool owner) : ::hyve::lang::Collection((::hyve::lang::collection)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::map Map::_handle() const {
            return (::hyve::lang::map)this->__handle;
        }
        
        // ::hyve::lang::typedef elementType
        ::hyve::lang::Typedef Map::elementType() const {
            ::hyve::lang::Typedef result(((::hyve::lang::map)this->__handle)->elementType);
            return result;
        }
        void Map::elementType(const ::hyve::lang::Typedef &v) const {
            if (v) {
                hyve::set((hyve::lang::object*)&((::hyve::lang::map)this->__handle)->elementType, v._handle());
            } else {
                hyve::set((hyve::lang::object*)&((::hyve::lang::map)this->__handle)->elementType, NULL);
            }
        }
        
        // ::hyve::lang::typedef keyType
        ::hyve::lang::Typedef Map::keyType() const {
            ::hyve::lang::Typedef result(((::hyve::lang::map)this->__handle)->keyType);
            return result;
        }
        void Map::keyType(const ::hyve::lang::Typedef &v) const {
            if (v) {
                hyve::set((hyve::lang::object*)&((::hyve::lang::map)this->__handle)->keyType, v._handle());
            } else {
                hyve::set((hyve::lang::object*)&((::hyve::lang::map)this->__handle)->keyType, NULL);
            }
        }
        
        // ::hyve::lang::uint32 max
        ::hyve::lang::uint32 Map::max() const {
            return ((::hyve::lang::map)this->__handle)->max;
        }
        void Map::max( ::hyve::lang::uint32 v) const {
            ((::hyve::lang::map)this->__handle)->max = v;
        }
    }
}

