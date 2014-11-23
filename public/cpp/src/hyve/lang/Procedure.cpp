/* src/hyve/lang/Procedure.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::procedure.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Procedure.hpp"
#include "hyve/lang/_meta.hpp"
#include "hyve/lang/Object.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Procedure::Procedure( ::hyve::lang::procedureKind kind) : ::hyve::lang::Struct((::hyve::lang::_struct)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::procedure_h);
            this->kind(kind);
            this->define();
        }
        
        // Constructor (declare & define)
        Procedure::Procedure(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                 ::hyve::lang::procedureKind kind) : ::hyve::lang::Struct((::hyve::lang::_struct)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::procedure_h);
            this->kind(kind);
            this->define();
        }
        
        // Construct from handle
        Procedure::Procedure(::hyve::lang::procedure handle, bool owner) : ::hyve::lang::Struct((::hyve::lang::_struct)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::procedure Procedure::_handle() const {
            return (::hyve::lang::procedure)this->__handle;
        }
        
        // ::hyve::lang::procedureKind kind
        ::hyve::lang::procedureKind Procedure::kind() const {
            return ((::hyve::lang::procedure)this->__handle)->kind;
        }
        void Procedure::kind( ::hyve::lang::procedureKind v) const {
            ((::hyve::lang::procedure)this->__handle)->kind = v;
        }
        
        /* ::hyve::lang::procedure::bind(lang::object object) */
        ::hyve::lang::int16 Procedure::bind(const ::hyve::lang::Object &object) const {
            ::hyve::lang::int16 _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::procedure_bind_h),&_result,this->__handle,object._handle());
            return _result;
        }
        
        /* ::hyve::lang::procedure::unbind(lang::object object) */
        ::hyve::lang::_void Procedure::unbind(const ::hyve::lang::Object &object) const {
            ::hyve::call((::hyve::lang::function)(::hyve::lang::procedure_unbind_h),NULL,this->__handle,object._handle());
        }
    }
}

