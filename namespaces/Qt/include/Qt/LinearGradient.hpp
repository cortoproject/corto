/* include/Qt/LinearGradient.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::LinearGradient.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_LinearGradient_H
#define Qt_LinearGradient_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Gradient.hpp"

namespace QT {
    class LinearGradient : public QT::Gradient {
        
        // Constructor (new,define)
        public: LinearGradient( QT::GradientStop_seq stops,
                 QT::GradientCoordinateMode coordinateMode,
                 QT::GradientSpread spread,
                 QT::PointF start,
                 QT::PointF finalStop);
        
        // Scoped constructor (declare,define)
        public: LinearGradient(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                 QT::GradientStop_seq stops,
                 QT::GradientCoordinateMode coordinateMode,
                 QT::GradientSpread spread,
                 QT::PointF start,
                 QT::PointF finalStop);
        
        // Handle constructor
        public: LinearGradient(QT::linearGradient handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::linearGradient _handle() const;
        
        // ::Qt::PointF finalStop
        public: QT::PointF finalStop() const;
        public: void finalStop( QT::PointF v) const;
        
        // ::Qt::PointF start
        public: QT::PointF start() const;
        public: void start( QT::PointF v) const;
        
        // init(::Qt::LinearGradient object)
        public: static ::hyve::lang::int16 init(const QT::LinearGradient &object);
        /* $begin($classfooter) */
        static void toQ(QT::linearGradient f, QLinearGradient *q);
        /* $end */
    };
}

#endif

