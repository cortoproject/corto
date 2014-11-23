/* src/hyve/lang/ObservableEvent.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::observableEvent.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/ObservableEvent.hpp"
#include "hyve/lang/_meta.hpp"
#include "hyve/lang/Observer.hpp"
#include "hyve/lang/Object.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        ObservableEvent::ObservableEvent( ::hyve::lang::uint16 kind,
                const ::hyve::lang::Observer &observer,
                const ::hyve::lang::Object &me,
                const ::hyve::lang::Object &source,
                const ::hyve::lang::Object &observable) : ::hyve::lang::Event((::hyve::lang::event)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::observableEvent_h);
            this->kind(kind);
            this->observer(observer);
            this->me(me);
            this->source(source);
            this->observable(observable);
            this->define();
        }
        
        // Constructor (declare & define)
        ObservableEvent::ObservableEvent(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                 ::hyve::lang::uint16 kind,
                const ::hyve::lang::Observer &observer,
                const ::hyve::lang::Object &me,
                const ::hyve::lang::Object &source,
                const ::hyve::lang::Object &observable) : ::hyve::lang::Event((::hyve::lang::event)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::observableEvent_h);
            this->kind(kind);
            this->observer(observer);
            this->me(me);
            this->source(source);
            this->observable(observable);
            this->define();
        }
        
        // Construct from handle
        ObservableEvent::ObservableEvent(::hyve::lang::observableEvent handle, bool owner) : ::hyve::lang::Event((::hyve::lang::event)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::observableEvent ObservableEvent::_handle() const {
            return (::hyve::lang::observableEvent)this->__handle;
        }
        
        // ::hyve::lang::observer observer
        ::hyve::lang::Observer ObservableEvent::observer() const {
            ::hyve::lang::Observer result(((::hyve::lang::observableEvent)this->__handle)->observer);
            return result;
        }
        void ObservableEvent::observer(const ::hyve::lang::Observer &v) const {
            if (v) {
                hyve::set((hyve::lang::object*)&((::hyve::lang::observableEvent)this->__handle)->observer, v._handle());
            } else {
                hyve::set((hyve::lang::object*)&((::hyve::lang::observableEvent)this->__handle)->observer, NULL);
            }
        }
        
        // ::hyve::lang::object me
        ::hyve::lang::Object ObservableEvent::me() const {
            ::hyve::lang::Object result(((::hyve::lang::observableEvent)this->__handle)->me);
            return result;
        }
        void ObservableEvent::me(const ::hyve::lang::Object &v) const {
            if (v) {
                hyve::set((hyve::lang::object*)&((::hyve::lang::observableEvent)this->__handle)->me, v._handle());
            } else {
                hyve::set((hyve::lang::object*)&((::hyve::lang::observableEvent)this->__handle)->me, NULL);
            }
        }
        
        // ::hyve::lang::object source
        ::hyve::lang::Object ObservableEvent::source() const {
            ::hyve::lang::Object result(((::hyve::lang::observableEvent)this->__handle)->source);
            return result;
        }
        void ObservableEvent::source(const ::hyve::lang::Object &v) const {
            if (v) {
                hyve::set((hyve::lang::object*)&((::hyve::lang::observableEvent)this->__handle)->source, v._handle());
            } else {
                hyve::set((hyve::lang::object*)&((::hyve::lang::observableEvent)this->__handle)->source, NULL);
            }
        }
        
        // ::hyve::lang::object observable
        ::hyve::lang::Object ObservableEvent::observable() const {
            ::hyve::lang::Object result(((::hyve::lang::observableEvent)this->__handle)->observable);
            return result;
        }
        void ObservableEvent::observable(const ::hyve::lang::Object &v) const {
            if (v) {
                hyve::set((hyve::lang::object*)&((::hyve::lang::observableEvent)this->__handle)->observable, v._handle());
            } else {
                hyve::set((hyve::lang::object*)&((::hyve::lang::observableEvent)this->__handle)->observable, NULL);
            }
        }
    }
}

