/* include/Qt/Slider.hpp
 *
 *  Generated on Feb  5 2014
 *    C++ definitions for ::Qt::Slider.
 *    This file contains generated code. Do not modify!
 */

#ifndef Qt_Slider_H
#define Qt_Slider_H

#include "hyve.hpp"
#include "Qt/_type.hpp"
#include "Qt/Widget.hpp"

/* $begin($header) */
#include "QSlider"
#include "SlotBase.h"
/* Glue-class that forwards signals to hyve */
namespace QT {
    class SliderSlots : public QObject, public SlotBase {
        Q_OBJECT
    public:
        SliderSlots(QT::slider handle, QSlider *handle_q);
    public slots:
        void sliderMoved(int value);
    private:
        QT::slider handle;
        QSlider *handle_q;
    };
}
/* $end */

namespace QT {
    class Slider : public QT::Widget {
        
        // Constructor (new,define)
        public: Slider(const QT::PaintEvent_t &paintEvent,
                const QT::MouseEvent_t &mousePressEvent,
                 ::hyve::lang::int32 x,
                 ::hyve::lang::int32 y,
                 ::hyve::lang::int32 width,
                 ::hyve::lang::int32 height,
                 ::hyve::lang::_bool enabled,
                 ::hyve::lang::_bool visible,
                 ::hyve::lang::string styleSheet,
                 ::hyve::lang::int32 value,
                 ::hyve::lang::int32 minimum,
                 ::hyve::lang::int32 maximum,
                 ::hyve::lang::int32 singleStep,
                 QT::Orientation orientation);
        
        // Scoped constructor (declare,define)
        public: Slider(::hyve::lang::Object *_parent,
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
                 ::hyve::lang::int32 value,
                 ::hyve::lang::int32 minimum,
                 ::hyve::lang::int32 maximum,
                 ::hyve::lang::int32 singleStep,
                 QT::Orientation orientation);
        
        // Handle constructor
        public: Slider(QT::slider handle, bool owner = TRUE);
        
        // Obtain handle
        public: QT::slider _handle() const;
        
        // ::hyve::lang::int32 maximum
        public: ::hyve::lang::int32 maximum() const;
        public: void maximum( ::hyve::lang::int32 v) const;
        
        // ::hyve::lang::int32 minimum
        public: ::hyve::lang::int32 minimum() const;
        public: void minimum( ::hyve::lang::int32 v) const;
        
        // ::Qt::Orientation orientation
        public: QT::Orientation orientation() const;
        public: void orientation( QT::Orientation v) const;
        
        // ::hyve::lang::int32 singleStep
        public: ::hyve::lang::int32 singleStep() const;
        public: void singleStep( ::hyve::lang::int32 v) const;
        
        // ::hyve::lang::int32 value
        public: ::hyve::lang::int32 value() const;
        public: void value( ::hyve::lang::int32 v) const;
        
        // construct(::Qt::Slider object)
        public: static ::hyve::lang::int16 construct(const QT::Slider &object);
        
        // destruct(::Qt::Slider object)
        public: static ::hyve::lang::_void destruct(const QT::Slider &object);
        
        // onSelf
        public: ::hyve::lang::_void onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const;
        /* $begin($classfooter) */
        void refresh() const;
        /* $end */
    };
}

#endif

