/* include/Qt/Slot.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::slot.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_slot_H
#define Qt_slot_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "hyve/lang/Member.hpp"

namespace QT {
    class Slot : public ::hyve::lang::Member {
        
        // Constructor (new,define)
        public: Slot(const ::hyve::lang::Typedef &type,
                 ::hyve::lang::modifier modifiers,
                 ::hyve::lang::state state,
                 ::hyve::lang::_bool weak);
        
        // Scoped constructor (declare,define)
        public: Slot(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                const ::hyve::lang::Typedef &type,
                 ::hyve::lang::modifier modifiers,
                 ::hyve::lang::state state,
                 ::hyve::lang::_bool weak);
        
        // Handle constructor
        public: Slot(QT::slot handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::slot _handle() const;
        
        // construct(::Qt::slot object)
        public: static ::hyve::lang::int16 construct(const QT::Slot &object);
    };
}

#endif

