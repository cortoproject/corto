/* include/hyve/lang/ObservableEvent.hpp
 *
 *  Generated on Oct 28 2014
 *    C++ definitions for ::hyve::lang::observableEvent.
 *    This file contains generated code. Do not modify!
 */

#ifndef hyve_lang_observableEvent_H
#define hyve_lang_observableEvent_H

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"
#include "hyve/lang/Event.hpp"

namespace hyve {
    namespace lang {
        class ObservableEvent : public ::hyve::lang::Event {
            
            // Constructor (new,define)
            public: ObservableEvent( ::hyve::lang::uint16 kind,
                    const ::hyve::lang::Observer &observer,
                    const ::hyve::lang::Object &me,
                    const ::hyve::lang::Object &source,
                    const ::hyve::lang::Object &observable);
            
            // Scoped constructor (declare,define)
            public: ObservableEvent(::hyve::lang::Object *_parent,
                    ::hyve::lang::string _name,
                     ::hyve::lang::uint16 kind,
                    const ::hyve::lang::Observer &observer,
                    const ::hyve::lang::Object &me,
                    const ::hyve::lang::Object &source,
                    const ::hyve::lang::Object &observable);
            
            // Handle constructor
            public: ObservableEvent(::hyve::lang::observableEvent handle, bool owner = TRUE);
            
            // Obtain handle
            public: ::hyve::lang::observableEvent _handle() const;
            
            // ::hyve::lang::object me
            public: ::hyve::lang::Object me() const;
            public: void me(const ::hyve::lang::Object &v) const;
            
            // ::hyve::lang::object observable
            public: ::hyve::lang::Object observable() const;
            public: void observable(const ::hyve::lang::Object &v) const;
            
            // ::hyve::lang::observer observer
            public: ::hyve::lang::Observer observer() const;
            public: void observer(const ::hyve::lang::Observer &v) const;
            
            // ::hyve::lang::object source
            public: ::hyve::lang::Object source() const;
            public: void source(const ::hyve::lang::Object &v) const;
        };
    }
}

#endif

