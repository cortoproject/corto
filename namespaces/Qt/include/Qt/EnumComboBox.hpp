/* include/Qt/EnumComboBox.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::EnumComboBox.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_EnumComboBox_H
#define Qt_EnumComboBox_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/ComboBox.hpp"

namespace QT {
    class EnumComboBox : public QT::ComboBox {
        
        // Constructor (new,define)
        public: EnumComboBox(const QT::PaintEvent_t &paintEvent,
                const QT::MouseEvent_t &mousePressEvent,
                 ::hyve::lang::int32 x,
                 ::hyve::lang::int32 y,
                 ::hyve::lang::int32 width,
                 ::hyve::lang::int32 height,
                 ::hyve::lang::_bool enabled,
                 ::hyve::lang::_bool visible,
                 ::hyve::lang::string styleSheet,
                 hyve::ll_h items,
                 ::hyve::lang::uint32 currentIndex,
                const ::hyve::lang::Enum &type,
                 ::hyve::lang::constant value);
        
        // Scoped constructor (declare,define)
        public: EnumComboBox(::hyve::lang::Object *_parent,
                ::hyve::lang::string _name,
                const QT::PaintEvent_t &paintEvent,
                const QT::MouseEvent_t &mousePressEvent,
                 ::hyve::lang::int32 x,
                 ::hyve::lang::int32 y,
                 ::hyve::lang::int32 width,
                 ::hyve::lang::int32 height,
                 ::hyve::lang::_bool enabled,
                 ::hyve::lang::_bool visible,
                 ::hyve::lang::string styleSheet,
                 hyve::ll_h items,
                 ::hyve::lang::uint32 currentIndex,
                const ::hyve::lang::Enum &type,
                 ::hyve::lang::constant value);
        
        // Handle constructor
        public: EnumComboBox(QT::enumComboBox handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::enumComboBox _handle() const;
        
        // ::hyve::lang::enum type
        public: ::hyve::lang::Enum type() const;
        public: void type(const ::hyve::lang::Enum &v) const;
        
        // ::hyve::lang::constant value
        public: ::hyve::lang::constant value() const;
        public: void value( ::hyve::lang::constant v) const;
        
        // construct(::Qt::EnumComboBox object)
        public: static ::hyve::lang::int16 construct(const QT::EnumComboBox &object);
        
        // destruct(::Qt::EnumComboBox object)
        public: static ::hyve::lang::_void destruct(const QT::EnumComboBox &object);
    };
}

#endif

