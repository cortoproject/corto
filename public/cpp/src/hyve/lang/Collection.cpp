/* src/hyve/lang/Collection.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::collection.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Collection.hpp"
#include "hyve/lang/_meta.hpp"
#include "hyve/lang/Typedef.hpp"
#include "hyve/lang/Type.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Collection::Collection(const ::hyve::lang::Typedef &elementType,
                 ::hyve::lang::uint32 max) : ::hyve::lang::Type((::hyve::lang::type)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::collection_h);
            this->elementType(elementType);
            this->max(max);
            this->define();
        }
        
        // Constructor (declare & define)
        Collection::Collection(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                const ::hyve::lang::Typedef &elementType,
                 ::hyve::lang::uint32 max) : ::hyve::lang::Type((::hyve::lang::type)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::collection_h);
            this->elementType(elementType);
            this->max(max);
            this->define();
        }
        
        // Construct from handle
        Collection::Collection(::hyve::lang::collection handle, bool owner) : ::hyve::lang::Type((::hyve::lang::type)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::collection Collection::_handle() const {
            return (::hyve::lang::collection)this->__handle;
        }
        
        // ::hyve::lang::collectionKind kind
        ::hyve::lang::collectionKind Collection::kind() const {
            return ((::hyve::lang::collection)this->__handle)->kind;
        }
        void Collection::kind( ::hyve::lang::collectionKind v) const {
            ((::hyve::lang::collection)this->__handle)->kind = v;
        }
        
        // ::hyve::lang::typedef elementType
        ::hyve::lang::Typedef Collection::elementType() const {
            ::hyve::lang::Typedef result(((::hyve::lang::collection)this->__handle)->elementType);
            return result;
        }
        void Collection::elementType(const ::hyve::lang::Typedef &v) const {
            if (v) {
                hyve::set((hyve::lang::object*)&((::hyve::lang::collection)this->__handle)->elementType, v._handle());
            } else {
                hyve::set((hyve::lang::object*)&((::hyve::lang::collection)this->__handle)->elementType, NULL);
            }
        }
        
        // ::hyve::lang::uint32 max
        ::hyve::lang::uint32 Collection::max() const {
            return ((::hyve::lang::collection)this->__handle)->max;
        }
        void Collection::max( ::hyve::lang::uint32 v) const {
            ((::hyve::lang::collection)this->__handle)->max = v;
        }
        
        /* ::hyve::lang::collection::castable(lang::type type) */
        ::hyve::lang::_bool Collection::castable_v(const ::hyve::lang::Type &type) const {
            ::hyve::lang::_bool _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::collection_castable_h),&_result,this->__handle,type._handle());
            return _result;
        }
        
        /* virtual ::hyve::lang::collection::castable(lang::type type) */
        ::hyve::lang::_bool Collection::castable(const ::hyve::lang::Type &type) const {
            hyve::lang::Class _type((hyve::lang::_class)this->_typeof()._handle());
            static hyve::lang::uint32 _actualMethodId;
            
            if (!_actualMethodId) {
                _actualMethodId = _type.resolveMethodId((hyve::lang::string)"castable(lang::type type)");
            }
            hyve::lang::Method _actualMethod = _type.resolveMethodById(_actualMethodId);
            ::hyve::lang::_bool _result;
            ::hyve::call((::hyve::lang::function)((hyve::lang::function)_actualMethod._handle()),&_result,this->__handle,type._handle());
            return _result;
        }
    }
}

