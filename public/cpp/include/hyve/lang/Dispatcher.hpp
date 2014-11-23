/* include/hyve/lang/Dispatcher.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::dispatcher.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_dispatcher_H
#define hyve_lang_dispatcher_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
namespace hyve {
    namespace lang {
        class Event;
        class ObservableEvent;
        class Observer;
    }
}

namespace hyve {
    namespace lang {
        class Dispatcher : public ::hyve::lang::Object {
            
            // Constructor (new,define)
            public: Dispatcher();
            
            // Scoped constructor (declare,define)
            public: Dispatcher(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name);
            
            // Handle constructor
            public: Dispatcher(::hyve::lang::dispatcher handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::dispatcher _handle() const;
            
            // getEvent(lang::observer observer,lang::object me,lang::object observable,lang::object src)
            public: ::hyve::lang::ObservableEvent getEvent(const ::hyve::lang::Observer &observer, const ::hyve::lang::Object &me, const ::hyve::lang::Object &observable, const ::hyve::lang::Object &src) const;
            public: ::hyve::lang::ObservableEvent getEvent_v(const ::hyve::lang::Observer &observer, const ::hyve::lang::Object &me, const ::hyve::lang::Object &observable, const ::hyve::lang::Object &src) const;
            
            // post(lang::event event)
            public: ::hyve::lang::_void post(const ::hyve::lang::Event &event) const;
            public: ::hyve::lang::_void post_v(const ::hyve::lang::Event &event) const;
        };
    }
}

#endif

