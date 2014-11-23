/* src/Qt/CustomPlot.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::CustomPlot.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/CustomPlot.hpp"
#include "Qt/_meta.hpp"
#include "hyve/lang/Object.hpp"

/* $begin($header) */
#include "QCustomPlot.h"
#include "hyve/lang/Observer.hpp"
#include "hyve/lang/Dispatcher.hpp"
#include "Qt/Application.hpp"
/* $end */

namespace QT {
    
    // Constructor
    CustomPlot::CustomPlot(const QT::PaintEvent_t &paintEvent,
            const QT::MouseEvent_t &mousePressEvent,
             ::hyve::lang::int32 x,
             ::hyve::lang::int32 y,
             ::hyve::lang::int32 width,
             ::hyve::lang::int32 height,
             ::hyve::lang::_bool enabled,
             ::hyve::lang::_bool visible,
             ::hyve::lang::string styleSheet,
            const ::hyve::lang::Object &object,
             ::hyve::lang::string expr,
             ::hyve::lang::uint32 autoX) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::CustomPlot_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->object(object);
        this->expr(expr);
        this->autoX(autoX);
        this->define();
    }
    
    // Constructor (declare & define)
    CustomPlot::CustomPlot(::hyve::lang::Object *_parent,
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
            const ::hyve::lang::Object &object,
             ::hyve::lang::string expr,
             ::hyve::lang::uint32 autoX) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::CustomPlot_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->object(object);
        this->expr(expr);
        this->autoX(autoX);
        this->define();
    }
    
    // Construct from handle
    CustomPlot::CustomPlot(QT::customPlot handle, bool owner) : QT::Widget((QT::widget)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::customPlot CustomPlot::_handle() const {
        return (QT::customPlot)this->__handle;
    }
    
    // ::hyve::lang::object object
    ::hyve::lang::Object CustomPlot::object() const {
        ::hyve::lang::Object result(((QT::customPlot)this->__handle)->object);
        return result;
    }
    void CustomPlot::object(const ::hyve::lang::Object &v) const {
        if (v) {
            hyve::set((hyve::lang::object*)&((QT::customPlot)this->__handle)->object, v._handle());
        } else {
            hyve::set((hyve::lang::object*)&((QT::customPlot)this->__handle)->object, NULL);
        }
    }
    
    // ::hyve::lang::string expr
    ::hyve::lang::string CustomPlot::expr() const {
        return ((QT::customPlot)this->__handle)->expr;
    }
    void CustomPlot::expr( ::hyve::lang::string v) const {
        if (((QT::customPlot)this->__handle)->expr) {
            hyve::dealloc(((QT::customPlot)this->__handle)->expr);
        };
        ((QT::customPlot)this->__handle)->expr = v ? hyve::strdup(v) : NULL;
    }
    
    // ::hyve::lang::uint32 autoX
    ::hyve::lang::uint32 CustomPlot::autoX() const {
        return ((QT::customPlot)this->__handle)->autoX;
    }
    void CustomPlot::autoX( ::hyve::lang::uint32 v) const {
        ((QT::customPlot)this->__handle)->autoX = v;
    }
    
    /* ::Qt::CustomPlot::construct(::Qt::CustomPlot object) */
    ::hyve::lang::int16 CustomPlot::construct(const QT::CustomPlot &object) {
    /* $begin(::Qt::CustomPlot::construct(::Qt::CustomPlot object)) */
        QWidget *parent_q; /* Parent handle to Qt object */
        QCustomPlot *plot;

        /* Obtain parent handle (Could also have been done using proxy-objects, but this is faster) */
        parent_q = (QWidget*)object.widgetParent();
        plot = new QCustomPlot(parent_q);
        if (!plot) {
            hyve::error("Qt::CustomPlot::construct: failed to create object '%s'", object.nameof());
            goto error;
        }

        /* Set dispatcher for own observers */
        {
            hyve::lang::Observer observer(QT::CustomPlot_onUpdate_h); // Create proxy for template observer
            hyve::lang::Observer onUpdate = QT::CustomPlot_o->privateObserver(object, observer);
            hyve::lang::Dispatcher dispatcher(QT::app());
            onUpdate.setDispatcher(dispatcher);
        }

        /* Set handle */
        object.qhandle((hyve::lang::word)plot);

        /* Call widget constructor */
        if (QT::Widget::construct(object)) {
            goto error;
        }

        return 0;
    error:
        return -1;
    /* $end */
    }
    
    /* ::Qt::CustomPlot::destruct(::Qt::CustomPlot object) */
    ::hyve::lang::int16 CustomPlot::destruct(const QT::CustomPlot &object) {
    /* $begin(::Qt::CustomPlot::destruct(::Qt::CustomPlot object)) */

        /* << Insert implementation >> */

    /* $end */
    }
    
    /* ::Qt::CustomPlot::init(::Qt::CustomPlot object) */
    ::hyve::lang::int16 CustomPlot::init(const QT::CustomPlot &object) {
    /* $begin(::Qt::CustomPlot::init(::Qt::CustomPlot object)) */
        return QT::Widget::init(object);
    /* $end */
    }
    
    /* ::Qt::CustomPlot::onDestruct */
    ::hyve::lang::_void CustomPlot::onDestruct(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::CustomPlot::onDestruct) */

        /* << Insert implementation >> */

    /* $end */
    }
    
    /* ::Qt::CustomPlot::onSelf */
    ::hyve::lang::_void CustomPlot::onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::CustomPlot::onSelf) */
        this->refresh();
    /* $end */
    }
    
    /* ::Qt::CustomPlot::onUpdate */
    ::hyve::lang::_void CustomPlot::onUpdate(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::CustomPlot::onUpdate) */
        QCustomPlot *plot;

        plot = (QCustomPlot*)this->qhandle();
        if (plot->graphCount()) {
            hyve::lang::uint32 count;
            hyve::valueStack stack;
            hyve::lang::type type;
            void* value;

            if (this->_handle()->expr && strlen(this->_handle()->expr)) {
                hyve::parseExpr(this->_handle()->object, this->_handle()->expr, stack, &count);
                hyve::free(this->_handle()->object);
                type = (hyve::lang::type)stack[count-1].type();
                value = stack[count - 1].ptr();
                switch(type->kind) {
                case hyve::lang::PRIMITIVE:
                    switch(((hyve::lang::primitive)type)->kind) {
                    case hyve::lang::INTEGER:
                        switch(((hyve::lang::primitive)type)->width) {
                        case hyve::lang::WIDTH_8:
                            plot->graph(0)->addData(this->autoX(),*(hyve::lang::int8*)value);
                            break;
                        case hyve::lang::WIDTH_16:
                            plot->graph(0)->addData(this->autoX(),*(hyve::lang::int16*)value);
                            break;
                        case hyve::lang::WIDTH_32:
                            plot->graph(0)->addData(this->autoX(),*(hyve::lang::int32*)value);
                            break;
                        case hyve::lang::WIDTH_64:
                            plot->graph(0)->addData(this->autoX(),*(hyve::lang::int64*)value);
                            break;
                        case hyve::lang::WIDTH_WORD:
                            plot->graph(0)->addData(this->autoX(),*(hyve::lang::word*)value);
                            break;
                        }
                        break;
                    case hyve::lang::UINTEGER:
                        switch(((hyve::lang::primitive)type)->width) {
                        case hyve::lang::WIDTH_8:
                            plot->graph(0)->addData(this->autoX(),*(hyve::lang::uint8*)value);
                            break;
                        case hyve::lang::WIDTH_16:
                            plot->graph(0)->addData(this->autoX(),*(hyve::lang::uint16*)value);
                            break;
                        case hyve::lang::WIDTH_32:
                            plot->graph(0)->addData(this->autoX(),*(hyve::lang::uint32*)value);
                            break;
                        case hyve::lang::WIDTH_64:
                            plot->graph(0)->addData(this->autoX(),*(hyve::lang::uint64*)value);
                            break;
                        case hyve::lang::WIDTH_WORD:
                            plot->graph(0)->addData(this->autoX(),*(hyve::lang::word*)value);
                            break;
                        }
                        break;
                    case hyve::lang::FLOAT:
                        switch(((hyve::lang::primitive)type)->width) {
                        case hyve::lang::WIDTH_32:
                            plot->graph(0)->addData(this->autoX(),*(hyve::lang::float32*)value);
                            break;
                        case hyve::lang::WIDTH_64:
                            plot->graph(0)->addData(this->autoX(),*(hyve::lang::float64*)value);
                            break;
                        default:
                            break;
                        }
                        break;
                    default:
                        hyve::id id;
                        hyve::error("Qt::CustomPlot::onUpdate: primitive value of type '%s' can't be plotted", hyve::fullname(type, id));
                        break;
                    }
                    break;
                default:
                    hyve::error("Qt::CustomPlot::onUpdate: can't plot '%s', expression does not evaluate to a numeric value", this->_handle()->expr);
                    break;
                }
            }

            this->autoX(this->autoX()+1);
        }

        plot->graph(0)->rescaleAxes();
        plot->replot();
    /* $end */
    }
    /* $begin($classfooter) */

    /* Refresh values */
    void CustomPlot::refresh() const {
        hyve::lang::Observer observer(QT::CustomPlot_onUpdate_h); // Create proxy for template observer
        hyve::lang::Object object(this->_handle()->object);
        QCustomPlot *plot;

        plot = (QCustomPlot*)this->qhandle();
        plot->clearGraphs();
        plot->addGraph();

        // Get private observer, re-set observable
        if (object.checkAttr(hyve::ATTR_OBSERVABLE)) {
            observer.listen(object, *this);
        }

        plot->replot();

        ((Widget*)this)->refresh();
    }
    /* $end */
}

