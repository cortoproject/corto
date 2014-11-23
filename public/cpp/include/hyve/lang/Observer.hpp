/* include/hyve/lang/Observer.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::observer.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_observer_H
#define hyve_lang_observer_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Function.hpp"
namespace hyve {
    namespace lang {
        class Dispatcher;
    }
}

namespace hyve {
    namespace lang {
        class Observer : public ::hyve::lang::Function {
            
            // Constructor (new,define)
            public: Observer(const ::hyve::lang::Object &observable,
                     ::hyve::lang::eventMask mask,
                     ::hyve::lang::string expression,
                     ::hyve::lang::uint32 _template,
                    const ::hyve::lang::Dispatcher &dispatcher,
                    const ::hyve::lang::Object &me);
            
            // Scoped constructor (declare,define)
            public: Observer(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                    const ::hyve::lang::Object &observable,
                     ::hyve::lang::eventMask mask,
                     ::hyve::lang::string expression,
                     ::hyve::lang::uint32 _template,
                    const ::hyve::lang::Dispatcher &dispatcher,
                    const ::hyve::lang::Object &me);
            
            // Handle constructor
            public: Observer(::hyve::lang::observer handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::observer _handle() const;
            
            // ::hyve::lang::observer delayedBinder
            public: ::hyve::lang::Observer delayedBinder() const;
            public: void delayedBinder(const ::hyve::lang::Observer &v) const;
            
            // ::hyve::lang::dispatcher dispatcher
            public: ::hyve::lang::Dispatcher dispatcher() const;
            public: void dispatcher(const ::hyve::lang::Dispatcher &v) const;
            
            // ::hyve::lang::string expression
            public: ::hyve::lang::string expression() const;
            public: void expression( ::hyve::lang::string v) const;
            
            // ::hyve::lang::eventMask mask
            public: ::hyve::lang::eventMask mask() const;
            public: void mask( ::hyve::lang::eventMask v) const;
            
            // ::hyve::lang::object me
            public: ::hyve::lang::Object me() const;
            public: void me(const ::hyve::lang::Object &v) const;
            
            // ::hyve::lang::object observable
            public: ::hyve::lang::Object observable() const;
            public: void observable(const ::hyve::lang::Object &v) const;
            
            // ::hyve::lang::object observing
            public: ::hyve::lang::Object observing() const;
            public: void observing(const ::hyve::lang::Object &v) const;
            
            // ::hyve::lang::uint32 template
            public: ::hyve::lang::uint32 _template() const;
            public: void _template( ::hyve::lang::uint32 v) const;
            
            // listen(lang::object observable,lang::object me)
            public: ::hyve::lang::int16 listen(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &me) const;
            
            // setDispatcher(lang::dispatcher dispatcher)
            public: ::hyve::lang::_void setDispatcher(const ::hyve::lang::Dispatcher &dispatcher) const;
            
            // silence(lang::object me)
            public: ::hyve::lang::int16 silence(const ::hyve::lang::Object &me) const;
        };
    }
}

#endif

