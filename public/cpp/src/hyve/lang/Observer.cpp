/* src/hyve/lang/Observer.cpp
 *
 *  Generated on Oct 28 2014
 *    C++ implementationfile for ::hyve::lang::observer.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "hyve/lang/Observer.hpp"
#include "hyve/lang/_meta.hpp"
#include "hyve/lang/Object.hpp"
#include "hyve/lang/Dispatcher.hpp"

namespace hyve {
    namespace lang {
        
        // Constructor
        Observer::Observer(const ::hyve::lang::Object &observable,
                 ::hyve::lang::eventMask mask,
                 ::hyve::lang::string expression,
                 ::hyve::lang::uint32 _template,
                const ::hyve::lang::Dispatcher &dispatcher,
                const ::hyve::lang::Object &me) : ::hyve::lang::Function((::hyve::lang::function)NULL) {
            this->__handle = ::hyve::_new((::hyve::lang::_typedef)::hyve::lang::observer_h);
            this->observable(observable);
            this->mask(mask);
            this->expression(expression);
            this->_template(_template);
            this->dispatcher(dispatcher);
            this->me(me);
            this->define();
        }
        
        // Constructor (declare & define)
        Observer::Observer(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                const ::hyve::lang::Object &observable,
                 ::hyve::lang::eventMask mask,
                 ::hyve::lang::string expression,
                 ::hyve::lang::uint32 _template,
                const ::hyve::lang::Dispatcher &dispatcher,
                const ::hyve::lang::Object &me) : ::hyve::lang::Function((::hyve::lang::function)NULL) {
            this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)::hyve::lang::observer_h);
            this->observable(observable);
            this->mask(mask);
            this->expression(expression);
            this->_template(_template);
            this->dispatcher(dispatcher);
            this->me(me);
            this->define();
        }
        
        // Construct from handle
        Observer::Observer(::hyve::lang::observer handle, bool owner) : ::hyve::lang::Function((::hyve::lang::function)handle, owner) {
            // Handle is set and keep'd by Object::Object(object handle)
        }
        
        // Get handle
        ::hyve::lang::observer Observer::_handle() const {
            return (::hyve::lang::observer)this->__handle;
        }
        
        // ::hyve::lang::object observable
        ::hyve::lang::Object Observer::observable() const {
            ::hyve::lang::Object result(((::hyve::lang::observer)this->__handle)->observable);
            return result;
        }
        void Observer::observable(const ::hyve::lang::Object &v) const {
            if (v) {
                hyve::set((hyve::lang::object*)&((::hyve::lang::observer)this->__handle)->observable, v._handle());
            } else {
                hyve::set((hyve::lang::object*)&((::hyve::lang::observer)this->__handle)->observable, NULL);
            }
        }
        
        // ::hyve::lang::eventMask mask
        ::hyve::lang::eventMask Observer::mask() const {
            return ((::hyve::lang::observer)this->__handle)->mask;
        }
        void Observer::mask( ::hyve::lang::eventMask v) const {
            ((::hyve::lang::observer)this->__handle)->mask = v;
        }
        
        // ::hyve::lang::string expression
        ::hyve::lang::string Observer::expression() const {
            return ((::hyve::lang::observer)this->__handle)->expression;
        }
        void Observer::expression( ::hyve::lang::string v) const {
            if (((::hyve::lang::observer)this->__handle)->expression) {
                hyve::dealloc(((::hyve::lang::observer)this->__handle)->expression);
            };
            ((::hyve::lang::observer)this->__handle)->expression = v ? hyve::strdup(v) : NULL;
        }
        
        // ::hyve::lang::uint32 template
        ::hyve::lang::uint32 Observer::_template() const {
            return ((::hyve::lang::observer)this->__handle)->_template;
        }
        void Observer::_template( ::hyve::lang::uint32 v) const {
            ((::hyve::lang::observer)this->__handle)->_template = v;
        }
        
        // ::hyve::lang::dispatcher dispatcher
        ::hyve::lang::Dispatcher Observer::dispatcher() const {
            ::hyve::lang::Dispatcher result(((::hyve::lang::observer)this->__handle)->dispatcher);
            return result;
        }
        void Observer::dispatcher(const ::hyve::lang::Dispatcher &v) const {
            if (v) {
                hyve::set((hyve::lang::object*)&((::hyve::lang::observer)this->__handle)->dispatcher, v._handle());
            } else {
                hyve::set((hyve::lang::object*)&((::hyve::lang::observer)this->__handle)->dispatcher, NULL);
            }
        }
        
        // ::hyve::lang::object me
        ::hyve::lang::Object Observer::me() const {
            ::hyve::lang::Object result(((::hyve::lang::observer)this->__handle)->me);
            return result;
        }
        void Observer::me(const ::hyve::lang::Object &v) const {
            if (v) {
                hyve::set((hyve::lang::object*)&((::hyve::lang::observer)this->__handle)->me, v._handle());
            } else {
                hyve::set((hyve::lang::object*)&((::hyve::lang::observer)this->__handle)->me, NULL);
            }
        }
        
        // ::hyve::lang::object observing
        ::hyve::lang::Object Observer::observing() const {
            ::hyve::lang::Object result(((::hyve::lang::observer)this->__handle)->observing);
            return result;
        }
        void Observer::observing(const ::hyve::lang::Object &v) const {
            if (v) {
                hyve::set((hyve::lang::object*)&((::hyve::lang::observer)this->__handle)->observing, v._handle());
            } else {
                hyve::set((hyve::lang::object*)&((::hyve::lang::observer)this->__handle)->observing, NULL);
            }
        }
        
        // ::hyve::lang::observer delayedBinder
        ::hyve::lang::Observer Observer::delayedBinder() const {
            ::hyve::lang::Observer result(((::hyve::lang::observer)this->__handle)->delayedBinder);
            return result;
        }
        void Observer::delayedBinder(const ::hyve::lang::Observer &v) const {
            if (v) {
                hyve::set((hyve::lang::object*)&((::hyve::lang::observer)this->__handle)->delayedBinder, v._handle());
            } else {
                hyve::set((hyve::lang::object*)&((::hyve::lang::observer)this->__handle)->delayedBinder, NULL);
            }
        }
        
        /* ::hyve::lang::observer::listen(lang::object observable,lang::object me) */
        ::hyve::lang::int16 Observer::listen(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &me) const {
            ::hyve::lang::int16 _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::observer_listen_h),&_result,this->__handle,observable._handle(),me._handle());
            return _result;
        }
        
        /* ::hyve::lang::observer::setDispatcher(lang::dispatcher dispatcher) */
        ::hyve::lang::_void Observer::setDispatcher(const ::hyve::lang::Dispatcher &dispatcher) const {
            ::hyve::call((::hyve::lang::function)(::hyve::lang::observer_setDispatcher_h),NULL,this->__handle,dispatcher._handle());
        }
        
        /* ::hyve::lang::observer::silence(lang::object me) */
        ::hyve::lang::int16 Observer::silence(const ::hyve::lang::Object &me) const {
            ::hyve::lang::int16 _result;
            ::hyve::call((::hyve::lang::function)(::hyve::lang::observer_silence_h),&_result,this->__handle,me._handle());
            return _result;
        }
    }
}

