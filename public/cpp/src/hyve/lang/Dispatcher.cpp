/* src/hyve/lang/Dispatcher.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::dispatcher.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Dispatcher.hpp"
#include "hyve/lang/_meta.hpp"
#include "hyve/lang/Event.hpp"
#include "hyve/lang/Object.hpp"
#include "hyve/lang/Observer.hpp"
#include "hyve/lang/ObservableEvent.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Dispatcher::Dispatcher() {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::dispatcher_h);
            this->define();
        }
        
        // Constructor (declare & define)
        Dispatcher::Dispatcher(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::dispatcher_h);
            this->define();
        }
        
        // Construct from handle
        Dispatcher::Dispatcher(::hyve::lang::dispatcher handle, bool owner) : ::hyve::lang::Object((::hyve::lang::object)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::dispatcher Dispatcher::_handle() const {
            return (::hyve::lang::dispatcher)this->__handle;
        }
        
        /* ::hyve::lang::dispatcher::getEvent(lang::observer observer,lang::object me,lang::object observable,lang::object src) */
        ::hyve::lang::ObservableEvent Dispatcher::getEvent_v(const ::hyve::lang::Observer &observer, const ::hyve::lang::Object &me, const ::hyve::lang::Object &observable, const ::hyve::lang::Object &src) const {
            ::hyve::lang::observableEvent _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::dispatcher_getEvent_h),&_result,this->__handle,observer._handle(),me._handle(),observable._handle(),src._handle());
            ::hyve::lang::ObservableEvent __result(_result);
            return __result;
        }
        
        /* virtual ::hyve::lang::dispatcher::getEvent(lang::observer observer,lang::object me,lang::object observable,lang::object src) */
        ::hyve::lang::ObservableEvent Dispatcher::getEvent(const ::hyve::lang::Observer &observer, const ::hyve::lang::Object &me, const ::hyve::lang::Object &observable, const ::hyve::lang::Object &src) const {
            hyve::lang::Class _type((hyve::lang::_class)this->_typeof()._handle());
            static hyve::lang::uint32 _actualMethodId;
            
            if (!_actualMethodId) {
                _actualMethodId = _type.resolveMethodId((hyve::lang::string)"getEvent(lang::observer observer,lang::object me,lang::object observable,lang::object src)");
            }
            hyve::lang::Method _actualMethod = _type.resolveMethodById(_actualMethodId);
            ::hyve::lang::observableEvent _result;
            ::hyve::call((::hyve::lang::function)((hyve::lang::function)_actualMethod._handle()),&_result,this->__handle,observer._handle(),me._handle(),observable._handle(),src._handle());
            ::hyve::lang::ObservableEvent __result(_result);
            return __result;
        }
        
        /* ::hyve::lang::dispatcher::post(lang::event event) */
        ::hyve::lang::_void Dispatcher::post_v(const ::hyve::lang::Event &event) const {
            ::hyve::call((::hyve::lang::function)(::hyve::lang::dispatcher_post_h),NULL,this->__handle,event._handle());
        }
        
        /* virtual ::hyve::lang::dispatcher::post(lang::event event) */
        ::hyve::lang::_void Dispatcher::post(const ::hyve::lang::Event &event) const {
            hyve::lang::Class _type((hyve::lang::_class)this->_typeof()._handle());
            static hyve::lang::uint32 _actualMethodId;
            
            if (!_actualMethodId) {
                _actualMethodId = _type.resolveMethodId((hyve::lang::string)"post(lang::event event)");
            }
            hyve::lang::Method _actualMethod = _type.resolveMethodById(_actualMethodId);
            ::hyve::call((::hyve::lang::function)((hyve::lang::function)_actualMethod._handle()),NULL,this->__handle,event._handle());
        }
    }
}

