/* include/Qt/ConicalGradient.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::ConicalGradient.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_ConicalGradient_H
#define Qt_ConicalGradient_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Gradient.hpp"

namespace QT {
    class ConicalGradient : public QT::Gradient {
        
        // Constructor (new,define)
        public: ConicalGradient( QT::GradientStop_seq stops,
                 QT::GradientCoordinateMode coordinateMode,
                 QT::GradientSpread spread,
                 QT::real angle,
                 QT::PointF center);
        
        // Scoped constructor (declare,define)
        public: ConicalGradient(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                 QT::GradientStop_seq stops,
                 QT::GradientCoordinateMode coordinateMode,
                 QT::GradientSpread spread,
                 QT::real angle,
                 QT::PointF center);
        
        // Handle constructor
        public: ConicalGradient(QT::conicalGradient handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::conicalGradient _handle() const;
        
        // ::Qt::real angle
        public: QT::real angle() const;
        public: void angle( QT::real v) const;
        
        // ::Qt::PointF center
        public: QT::PointF center() const;
        public: void center( QT::PointF v) const;
        
        // init(::Qt::ConicalGradient object)
        public: static ::hyve::lang::int16 init(const QT::ConicalGradient &object);
        /* $begin($classfooter) */
        static void toQ(QT::conicalGradient f, QConicalGradient *q);
        /* $end */
    };
}

#endif

