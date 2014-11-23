/* include/Qt/AbstractButton.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::AbstractButton.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_AbstractButton_H
#define Qt_AbstractButton_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Widget.hpp"

/* $begin($header) */
#include "QAbstractButton"
#include "SlotBase.h"

/* Glue-class that forwards signals to hyve */
namespace QT {
    class AbstractButtonSlots : public QObject, public SlotBase {
        Q_OBJECT
    public:
        AbstractButtonSlots(QT::abstractButton handle, QAbstractButton *handle_q);
    public slots:
        void pressed();
        void toggled(bool checked);
    private:
        QT::abstractButton handle;
        QAbstractButton *handle_q;
    };
}
/* $end */

namespace QT {
    class AbstractButton : public QT::Widget {
        
        // Constructor (new,define)
        public: AbstractButton(const QT::PaintEvent_t &paintEvent,
                const QT::MouseEvent_t &mousePressEvent,
                 ::hyve::lang::int32 x,
                 ::hyve::lang::int32 y,
                 ::hyve::lang::int32 width,
                 ::hyve::lang::int32 height,
                 ::hyve::lang::_bool enabled,
                 ::hyve::lang::_bool visible,
                 ::hyve::lang::string styleSheet,
                 ::hyve::lang::string text,
                 ::hyve::lang::_bool checkable,
                 ::hyve::lang::_bool down,
                 ::hyve::lang::_bool checked);
        
        // Scoped constructor (declare,define)
        public: AbstractButton(::hyve::lang::Object *_parent,
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
                 ::hyve::lang::string text,
                 ::hyve::lang::_bool checkable,
                 ::hyve::lang::_bool down,
                 ::hyve::lang::_bool checked);
        
        // Handle constructor
        public: AbstractButton(QT::abstractButton handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::abstractButton _handle() const;
        
        // ::hyve::lang::bool checkable
        public: ::hyve::lang::_bool checkable() const;
        public: void checkable( ::hyve::lang::_bool v) const;
        
        // ::hyve::lang::bool checked
        public: ::hyve::lang::_bool checked() const;
        public: void checked( ::hyve::lang::_bool v) const;
        
        // ::hyve::lang::bool down
        public: ::hyve::lang::_bool down() const;
        public: void down( ::hyve::lang::_bool v) const;
        
        // ::hyve::lang::string text
        public: ::hyve::lang::string text() const;
        public: void text( ::hyve::lang::string v) const;
        
        // construct(::Qt::AbstractButton object)
        public: static ::hyve::lang::int16 construct(const QT::AbstractButton &object);
        
        // destruct(::Qt::AbstractButton object)
        public: static ::hyve::lang::_void destruct(const QT::AbstractButton &object);
        /* $begin($classfooter) */
        void refresh() const;
        /* $end */
    };
}

#endif

