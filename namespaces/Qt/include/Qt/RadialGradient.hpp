/* include/Qt/RadialGradient.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::RadialGradient.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_RadialGradient_H
#define Qt_RadialGradient_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Gradient.hpp"

namespace QT {
    class RadialGradient : public QT::Gradient {
        
        // Constructor (new,define)
        public: RadialGradient( QT::GradientStop_seq stops,
                 QT::GradientCoordinateMode coordinateMode,
                 QT::GradientSpread spread,
                 QT::PointF center,
                 QT::PointF focalPoint,
                 QT::real radius);
        
        // Scoped constructor (declare,define)
        public: RadialGradient(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                 QT::GradientStop_seq stops,
                 QT::GradientCoordinateMode coordinateMode,
                 QT::GradientSpread spread,
                 QT::PointF center,
                 QT::PointF focalPoint,
                 QT::real radius);
        
        // Handle constructor
        public: RadialGradient(QT::radialGradient handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::radialGradient _handle() const;
        
        // ::Qt::PointF center
        public: QT::PointF center() const;
        public: void center( QT::PointF v) const;
        
        // ::Qt::PointF focalPoint
        public: QT::PointF focalPoint() const;
        public: void focalPoint( QT::PointF v) const;
        
        // ::Qt::real radius
        public: QT::real radius() const;
        public: void radius( QT::real v) const;
        
        // init(::Qt::RadialGradient object)
        public: static ::hyve::lang::int16 init(const QT::RadialGradient &object);
        /* $begin($classfooter) */
        static void toQ(QT::radialGradient f, QRadialGradient *q);
        /* $end */
    };
}

#endif

