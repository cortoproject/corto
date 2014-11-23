/* include/Qt/MouseEvent_t.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::mouseEvent_t.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_mouseEvent_t_H
#define Qt_mouseEvent_t_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/InputEvent_t.hpp"

namespace QT {
    class MouseEvent_t : public QT::InputEvent_t {
        
        // Constructor (new,define)
        public: MouseEvent_t( QT::KeyboardModifiers modifiers,
                 ::hyve::lang::int32 x,
                 ::hyve::lang::int32 y,
                 QT::MouseButton buttons);
        
        // Scoped constructor (declare,define)
        public: MouseEvent_t(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                 QT::KeyboardModifiers modifiers,
                 ::hyve::lang::int32 x,
                 ::hyve::lang::int32 y,
                 QT::MouseButton buttons);
        
        // Handle constructor
        public: MouseEvent_t(QT::mouseEvent_t handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::mouseEvent_t _handle() const;
        
        // ::Qt::MouseButton buttons
        public: QT::MouseButton buttons() const;
        public: void buttons( QT::MouseButton v) const;
        
        // ::hyve::lang::int32 x
        public: ::hyve::lang::int32 x() const;
        public: void x( ::hyve::lang::int32 v) const;
        
        // ::hyve::lang::int32 y
        public: ::hyve::lang::int32 y() const;
        public: void y( ::hyve::lang::int32 v) const;
    };
}

#endif

