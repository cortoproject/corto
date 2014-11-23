/* include/Qt/Font.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::Font.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_Font_H
#define Qt_Font_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Object.hpp"

namespace QT {
    class Font : public QT::Object {
        
        // Constructor (new,define)
        public: Font( ::hyve::lang::string family,
                 ::hyve::lang::int32 pointSize,
                 QT::FontWeight weight,
                 ::hyve::lang::_bool italic);
        
        // Scoped constructor (declare,define)
        public: Font(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                 ::hyve::lang::string family,
                 ::hyve::lang::int32 pointSize,
                 QT::FontWeight weight,
                 ::hyve::lang::_bool italic);
        
        // Handle constructor
        public: Font(QT::font handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::font _handle() const;
        
        // ::hyve::lang::string family
        public: ::hyve::lang::string family() const;
        public: void family( ::hyve::lang::string v) const;
        
        // ::hyve::lang::bool italic
        public: ::hyve::lang::_bool italic() const;
        public: void italic( ::hyve::lang::_bool v) const;
        
        // ::hyve::lang::int32 pointSize
        public: ::hyve::lang::int32 pointSize() const;
        public: void pointSize( ::hyve::lang::int32 v) const;
        
        // ::Qt::FontWeight weight
        public: QT::FontWeight weight() const;
        public: void weight( QT::FontWeight v) const;
        
        // construct(::Qt::Font object)
        public: static ::hyve::lang::int16 construct(const QT::Font &object);
        
        // destruct(::Qt::Font object)
        public: static ::hyve::lang::_void destruct(const QT::Font &object);
    };
}

#endif

