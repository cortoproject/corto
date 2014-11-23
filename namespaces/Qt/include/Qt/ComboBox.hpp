/* include/Qt/ComboBox.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::ComboBox.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_ComboBox_H
#define Qt_ComboBox_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Widget.hpp"

/* $begin($header) */
#include "QComboBox"
#include "SlotBase.h"

/* Glue-class that forwards signals to hyve */
namespace QT {
    class ComboBoxSlots : public QObject, public SlotBase {
        Q_OBJECT
    public:
        ComboBoxSlots(QT::comboBox handle, QComboBox *handle_q);
    public slots:
        void changed(QString string);
    private:
        QT::comboBox handle;
        QComboBox *handle_q;
    };
}
/* $end */

namespace QT {
    class ComboBox : public QT::Widget {
        
        // Constructor (new,define)
        public: ComboBox(const QT::PaintEvent_t &paintEvent,
                const QT::MouseEvent_t &mousePressEvent,
                 ::hyve::lang::int32 x,
                 ::hyve::lang::int32 y,
                 ::hyve::lang::int32 width,
                 ::hyve::lang::int32 height,
                 ::hyve::lang::_bool enabled,
                 ::hyve::lang::_bool visible,
                 ::hyve::lang::string styleSheet,
                 hyve::ll_h items,
                 ::hyve::lang::uint32 currentIndex);
        
        // Scoped constructor (declare,define)
        public: ComboBox(::hyve::lang::Object *_parent,
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
                 ::hyve::lang::uint32 currentIndex);
        
        // Handle constructor
        public: ComboBox(QT::comboBox handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::comboBox _handle() const;
        
        // ::hyve::lang::uint32 currentIndex
        public: ::hyve::lang::uint32 currentIndex() const;
        public: void currentIndex( ::hyve::lang::uint32 v) const;
        
        // ::hyve::lang::string currentText
        public: ::hyve::lang::string currentText() const;
        public: void currentText( ::hyve::lang::string v) const;
        
        // <0x815cd48> items
        public: hyve::ll_h items() const;
        public: void items( hyve::ll_h v) const;
        
        // construct(::Qt::ComboBox object)
        public: static ::hyve::lang::int16 construct(const QT::ComboBox &object);
        
        // destruct(::Qt::ComboBox object)
        public: static ::hyve::lang::_void destruct(const QT::ComboBox &object);
        
        // onSelf
        public: ::hyve::lang::_void onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
        /* $begin($classfooter) */
        void refresh() const;
        /* $end */
    };
}

#endif

