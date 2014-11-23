/* include/Qt/Pen.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::Pen.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_Pen_H
#define Qt_Pen_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Object.hpp"

namespace QT {
    class Pen : public QT::Object {
        
        // Constructor (new,define)
        public: Pen( QT::Color color,
                 ::hyve::lang::uint32 width);
        
        // Scoped constructor (declare,define)
        public: Pen(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                 QT::Color color,
                 ::hyve::lang::uint32 width);
        
        // Handle constructor
        public: Pen(QT::pen handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::pen _handle() const;
        
        // ::Qt::Color color
        public: QT::Color color() const;
        public: void color( QT::Color v) const;
        
        // ::hyve::lang::uint32 width
        public: ::hyve::lang::uint32 width() const;
        public: void width( ::hyve::lang::uint32 v) const;
        
        // construct(::Qt::Pen object)
        public: static ::hyve::lang::int16 construct(const QT::Pen &object);
        
        // destruct(::Qt::Pen object)
        public: static ::hyve::lang::_void destruct(const QT::Pen &object);
    };
}

#endif

