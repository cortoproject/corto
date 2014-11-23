/* include/Qt/PaintDevice.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::PaintDevice.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_PaintDevice_H
#define Qt_PaintDevice_H

#include "hyve.hpp"
#include "Qt/_type.hpp"

namespace QT {
    class PaintDevice : public ::hyve::lang::Object {
        
        // Constructor (new,define)
        public: PaintDevice();
        
        // Scoped constructor (declare,define)
        public: PaintDevice(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name);
        
        // Handle constructor
        public: PaintDevice(QT::paintDevice handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::paintDevice _handle() const;
    };
}

#endif

