/* include/Qt/Brush.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::Brush.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_Brush_H
#define Qt_Brush_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Object.hpp"

namespace QT {
    class Brush : public QT::Object {
        
        // Constructor (new,define)
        public: Brush( QT::Color color,
                const QT::Gradient &gradient);
        
        // Scoped constructor (declare,define)
        public: Brush(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                 QT::Color color,
                const QT::Gradient &gradient);
        
        // Handle constructor
        public: Brush(QT::brush handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::brush _handle() const;
        
        // ::Qt::Color color
        public: QT::Color color() const;
        public: void color( QT::Color v) const;
        
        // ::Qt::Gradient gradient
        public: QT::Gradient gradient() const;
        public: void gradient(const QT::Gradient &v) const;
        
        // construct(::Qt::Brush object)
        public: static ::hyve::lang::int16 construct(const QT::Brush &object);
        
        // destruct(::Qt::Brush object)
        public: static ::hyve::lang::_void destruct(const QT::Brush &object);
    };
}

#endif

