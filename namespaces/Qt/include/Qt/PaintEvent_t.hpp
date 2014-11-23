/* include/Qt/PaintEvent_t.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::paintEvent_t.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_paintEvent_t_H
#define Qt_paintEvent_t_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "hyve/lang/Object.hpp"

namespace QT {
    class PaintEvent_t : public ::hyve::lang::Object {
        
        // Constructor (new,define)
        public: PaintEvent_t(const QT::Painter &painter);
        
        // Scoped constructor (declare,define)
        public: PaintEvent_t(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                const QT::Painter &painter);
        
        // Handle constructor
        public: PaintEvent_t(QT::paintEvent_t handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::paintEvent_t _handle() const;
        
        // ::Qt::Painter painter
        public: QT::Painter painter() const;
        public: void painter(const QT::Painter &v) const;
    };
}

#endif

