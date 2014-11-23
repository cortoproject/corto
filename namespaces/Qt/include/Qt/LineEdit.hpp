/* include/Qt/LineEdit.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::LineEdit.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_LineEdit_H
#define Qt_LineEdit_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Widget.hpp"

/* $begin($header) */
#include "QLineEdit"
#include "SlotBase.h"

/* Glue-class that forwards signals to hyve */
namespace QT {
    class LineEditSlots : public QObject,public SlotBase {
        Q_OBJECT
    public:
        LineEditSlots(QT::lineEdit handle, QLineEdit *handle_q);
    public slots:
        void textChanged(QString string);
    private:
        QT::lineEdit handle;
        QLineEdit *handle_q;
    };
}
/* $end */

namespace QT {
    class LineEdit : public QT::Widget {
        
        // Constructor (new,define)
        public: LineEdit(const QT::PaintEvent_t &paintEvent,
                const QT::MouseEvent_t &mousePressEvent,
                 ::hyve::lang::int32 x,
                 ::hyve::lang::int32 y,
                 ::hyve::lang::int32 width,
                 ::hyve::lang::int32 height,
                 ::hyve::lang::_bool enabled,
                 ::hyve::lang::_bool visible,
                 ::hyve::lang::string styleSheet,
                 ::hyve::lang::string text,
                 ::hyve::lang::_bool readonly);
        
        // Scoped constructor (declare,define)
        public: LineEdit(::hyve::lang::Object *_parent,
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
                 ::hyve::lang::_bool readonly);
        
        // Handle constructor
        public: LineEdit(QT::lineEdit handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::lineEdit _handle() const;
        
        // ::hyve::lang::bool readonly
        public: ::hyve::lang::_bool readonly() const;
        public: void readonly( ::hyve::lang::_bool v) const;
        
        // ::hyve::lang::string text
        public: ::hyve::lang::string text() const;
        public: void text( ::hyve::lang::string v) const;
        
        // construct(::Qt::LineEdit object)
        public: static ::hyve::lang::int16 construct(const QT::LineEdit &object);
        
        // destruct(::Qt::LineEdit object)
        public: static ::hyve::lang::_void destruct(const QT::LineEdit &object);
        
        // onSelf
        public: ::hyve::lang::_void onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
        /* $begin($classfooter) */
        void refresh() const;
        /* $end */
    };
}

#endif

