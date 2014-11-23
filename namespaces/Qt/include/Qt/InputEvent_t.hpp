/* include/Qt/InputEvent_t.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::inputEvent_t.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_inputEvent_t_H
#define Qt_inputEvent_t_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "hyve/lang/Object.hpp"

namespace QT {
    class InputEvent_t : public ::hyve::lang::Object {
        
        // Constructor (new,define)
        public: InputEvent_t( QT::KeyboardModifiers modifiers);
        
        // Scoped constructor (declare,define)
        public: InputEvent_t(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                 QT::KeyboardModifiers modifiers);
        
        // Handle constructor
        public: InputEvent_t(QT::inputEvent_t handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::inputEvent_t _handle() const;
        
        // ::Qt::KeyboardModifiers modifiers
        public: QT::KeyboardModifiers modifiers() const;
        public: void modifiers( QT::KeyboardModifiers v) const;
    };
}

#endif

