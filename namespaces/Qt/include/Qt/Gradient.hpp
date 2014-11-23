/* include/Qt/Gradient.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::Gradient.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_Gradient_H
#define Qt_Gradient_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Object.hpp"

/* $begin($header) */
#include "QGradient"
/* $end */

namespace QT {
    class Gradient : public QT::Object {
        
        // Constructor (new,define)
        public: Gradient( QT::GradientStop_seq stops,
                 QT::GradientCoordinateMode coordinateMode,
                 QT::GradientSpread spread);
        
        // Scoped constructor (declare,define)
        public: Gradient(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                 QT::GradientStop_seq stops,
                 QT::GradientCoordinateMode coordinateMode,
                 QT::GradientSpread spread);
        
        // Handle constructor
        public: Gradient(QT::gradient handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::gradient _handle() const;
        
        // ::Qt::GradientCoordinateMode coordinateMode
        public: QT::GradientCoordinateMode coordinateMode() const;
        public: void coordinateMode( QT::GradientCoordinateMode v) const;
        
        // ::Qt::GradientKind kind
        public: QT::GradientKind kind() const;
        public: void kind( QT::GradientKind v) const;
        
        // ::Qt::GradientSpread spread
        public: QT::GradientSpread spread() const;
        public: void spread( QT::GradientSpread v) const;
        
        // <0x810a898> stops
        public: QT::GradientStop_seq stops() const;
        public: void stops( QT::GradientStop_seq v) const;
        /* $begin($classfooter) */
        static void toQ(QT::gradient f, QGradient *q);
        /* $end */
    };
}

#endif

