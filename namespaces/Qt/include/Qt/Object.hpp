/* include/Qt/Object.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::Object.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_Object_H
#define Qt_Object_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "hyve/lang/Object.hpp"

namespace QT {
    class Object : public ::hyve::lang::Object {
        
        // Constructor (new,define)
        public: Object();
        
        // Scoped constructor (declare,define)
        public: Object(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name);
        
        // Handle constructor
        public: Object(QT::object handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::object _handle() const;
        
        // ::hyve::lang::word qhandle
        public: ::hyve::lang::word qhandle() const;
        public: void qhandle( ::hyve::lang::word v) const;
        
        // widgetParent()
        public: ::hyve::lang::word widgetParent() const;
    };
}

#endif

