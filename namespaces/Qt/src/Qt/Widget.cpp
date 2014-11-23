/* src/Qt/Widget.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::Widget.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/Widget.hpp"
#include "Qt/_meta.hpp"
#include "Qt/PaintEvent_t.hpp"
#include "Qt/Painter.hpp"
#include "Qt/MouseEvent_t.hpp"

/* $begin($header) */
#include <QWidget>
#include "Qt/Painter.hpp"
#include "QPainter"
#include "QPaintEvent"

namespace QT {
    class QTWidget : QWidget {
    public:
        QTWidget(QT::widget widget, QWidget *parent) : QWidget(parent) {
            this->widget = widget;
        }

        void paintEvent(QPaintEvent *event) {
            QPainter *painter;
            QT::painter _painter;

            (void)event;

            /* Get hyve and Qt painter object */
            _painter = widget->painter;
            painter = (QPainter*)_painter->_parent.qhandle;

            /* Begin drawing */
            painter->begin(this);
            /*painter->fillRect(event->rect(), QColor(0xff, 0xff, 0xff));*/
            painter->setRenderHint(QPainter::Antialiasing);

             /* Forward event */
            widget->paintEvent->painter = _painter;
            hyve::update(widget->paintEvent);
            widget->paintEvent->painter = NULL;

            painter->end();
        }

        void mousePressEvent(QMouseEvent *event) {
            widget->mousePressEvent->x = event->x();
            widget->mousePressEvent->y = event->y();
            widget->mousePressEvent->buttons = (QT::MouseButton)event->buttons();
            widget->mousePressEvent->_parent.modifiers = (QT::KeyboardModifiers)event->modifiers();
            hyve::update(widget->mousePressEvent);
        }

        void resizeEvent(QResizeEvent *) {
            widget->width = this->width();
            widget->height = this->height();
            printf("ResizeEvent!");
        }

    private:
        QT::widget widget;

    };
}


/* $end */

namespace QT {
    
    // Constructor
    Widget::Widget(const QT::PaintEvent_t &paintEvent,
            const QT::MouseEvent_t &mousePressEvent,
             ::hyve::lang::int32 x,
             ::hyve::lang::int32 y,
             ::hyve::lang::int32 width,
             ::hyve::lang::int32 height,
             ::hyve::lang::_bool enabled,
             ::hyve::lang::_bool visible,
             ::hyve::lang::string styleSheet) : QT::Object((QT::object)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::Widget_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->define();
    }
    
    // Constructor (declare & define)
    Widget::Widget(::hyve::lang::Object *_parent,
            ::hyve::lang::string _name,
            const QT::PaintEvent_t &paintEvent,
            const QT::MouseEvent_t &mousePressEvent,
             ::hyve::lang::int32 x,
             ::hyve::lang::int32 y,
             ::hyve::lang::int32 width,
             ::hyve::lang::int32 height,
             ::hyve::lang::_bool enabled,
             ::hyve::lang::_bool visible,
             ::hyve::lang::string styleSheet) : QT::Object((QT::object)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::Widget_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->define();
    }
    
    // Construct from handle
    Widget::Widget(QT::widget handle, bool owner) : QT::Object((QT::object)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::widget Widget::_handle() const {
        return (QT::widget)this->__handle;
    }
    
    // ::Qt::paintEvent_t paintEvent
    QT::PaintEvent_t Widget::paintEvent() const {
        QT::PaintEvent_t result(((QT::widget)this->__handle)->paintEvent);
        return result;
    }
    void Widget::paintEvent(const QT::PaintEvent_t &v) const {
        if (v) {
            hyve::set((hyve::lang::object*)&((QT::widget)this->__handle)->paintEvent, v._handle());
        } else {
            hyve::set((hyve::lang::object*)&((QT::widget)this->__handle)->paintEvent, NULL);
        }
    }
    
    // ::Qt::mouseEvent_t mousePressEvent
    QT::MouseEvent_t Widget::mousePressEvent() const {
        QT::MouseEvent_t result(((QT::widget)this->__handle)->mousePressEvent);
        return result;
    }
    void Widget::mousePressEvent(const QT::MouseEvent_t &v) const {
        if (v) {
            hyve::set((hyve::lang::object*)&((QT::widget)this->__handle)->mousePressEvent, v._handle());
        } else {
            hyve::set((hyve::lang::object*)&((QT::widget)this->__handle)->mousePressEvent, NULL);
        }
    }
    
    // ::hyve::lang::int32 x
    ::hyve::lang::int32 Widget::x() const {
        return ((QT::widget)this->__handle)->x;
    }
    void Widget::x( ::hyve::lang::int32 v) const {
        ((QT::widget)this->__handle)->x = v;
    }
    
    // ::hyve::lang::int32 y
    ::hyve::lang::int32 Widget::y() const {
        return ((QT::widget)this->__handle)->y;
    }
    void Widget::y( ::hyve::lang::int32 v) const {
        ((QT::widget)this->__handle)->y = v;
    }
    
    // ::hyve::lang::int32 width
    ::hyve::lang::int32 Widget::width() const {
        return ((QT::widget)this->__handle)->width;
    }
    void Widget::width( ::hyve::lang::int32 v) const {
        ((QT::widget)this->__handle)->width = v;
    }
    
    // ::hyve::lang::int32 height
    ::hyve::lang::int32 Widget::height() const {
        return ((QT::widget)this->__handle)->height;
    }
    void Widget::height( ::hyve::lang::int32 v) const {
        ((QT::widget)this->__handle)->height = v;
    }
    
    // ::hyve::lang::bool enabled
    ::hyve::lang::_bool Widget::enabled() const {
        return ((QT::widget)this->__handle)->enabled;
    }
    void Widget::enabled( ::hyve::lang::_bool v) const {
        ((QT::widget)this->__handle)->enabled = v;
    }
    
    // ::hyve::lang::bool visible
    ::hyve::lang::_bool Widget::visible() const {
        return ((QT::widget)this->__handle)->visible;
    }
    void Widget::visible( ::hyve::lang::_bool v) const {
        ((QT::widget)this->__handle)->visible = v;
    }
    
    // ::hyve::lang::string styleSheet
    ::hyve::lang::string Widget::styleSheet() const {
        return ((QT::widget)this->__handle)->styleSheet;
    }
    void Widget::styleSheet( ::hyve::lang::string v) const {
        if (((QT::widget)this->__handle)->styleSheet) {
            hyve::dealloc(((QT::widget)this->__handle)->styleSheet);
        };
        ((QT::widget)this->__handle)->styleSheet = v ? hyve::strdup(v) : NULL;
    }
    
    // ::Qt::Painter painter
    QT::Painter Widget::painter() const {
        QT::Painter result(((QT::widget)this->__handle)->painter);
        return result;
    }
    void Widget::painter(const QT::Painter &v) const {
        if (v) {
            hyve::set((hyve::lang::object*)&((QT::widget)this->__handle)->painter, v._handle());
        } else {
            hyve::set((hyve::lang::object*)&((QT::widget)this->__handle)->painter, NULL);
        }
    }
    
    // ::hyve::lang::word qslots
    ::hyve::lang::word Widget::qslots() const {
        return ((QT::widget)this->__handle)->qslots;
    }
    void Widget::qslots( ::hyve::lang::word v) const {
        ((QT::widget)this->__handle)->qslots = v;
    }
    
    /* ::Qt::Widget::construct(::Qt::Widget object) */
    ::hyve::lang::int16 Widget::construct(const QT::Widget &object) {
    /* $begin(::Qt::Widget::construct(::Qt::Widget object)) */
        if (!object.qhandle()) {
            object.qhandle((hyve::lang::word)new QTWidget(object._handle(), (QWidget*)object.widgetParent()));
        }

        object.refresh();
        return 0;
    /* $end */
    }
    
    /* ::Qt::Widget::destruct(::Qt::Widget object) */
    ::hyve::lang::_void Widget::destruct(const QT::Widget &object) {
    /* $begin(::Qt::Widget::destruct(::Qt::Widget object)) */
        (void)object;

    /* $end */
    }
    
    /* ::Qt::Widget::hide() */
    ::hyve::lang::_void Widget::hide() const {
    /* $begin(::Qt::Widget::hide()) */
        QWidget *widget;
        widget = (QWidget*)this->qhandle();
        widget->hide();
    /* $end */
    }
    
    /* ::Qt::Widget::init(::Qt::Widget object) */
    ::hyve::lang::int16 Widget::init(const QT::Widget &object) {
    /* $begin(::Qt::Widget::init(::Qt::Widget object)) */
        QT::paintEvent_t event;
        QT::mouseEvent_t mouseEvent;
        QT::painter painter;
        object.enabled(true);
        object.visible(true);

        /* Create observable paint-event */
        event = (QT::paintEvent_t)hyve::_new((hyve::lang::_typedef)QT::paintEvent_t_h, hyve::ATTR_OBSERVABLE | hyve::ATTR_WRITABLE);
        /* Define paint-event */
        hyve::define(event);
        object._handle()->paintEvent = event;

        /* Create observable mousePress-event */
        mouseEvent = (QT::mouseEvent_t)hyve::_new((hyve::lang::_typedef)QT::mouseEvent_t_h, hyve::ATTR_OBSERVABLE | hyve::ATTR_WRITABLE);
        /* Define paint-event */
        hyve::define(event);
        object._handle()->mousePressEvent = mouseEvent;

        /* Create painter */
        painter = (QT::painter)hyve::_new((hyve::lang::_typedef)QT::Painter_h);
        /* Define painter */
        hyve::define(painter);
        object._handle()->painter = painter;

        /* Set x, y, width and height to default values */
        object.x(-1);
        object.y(-1);
        object.width(-1);
        object.height(-1);

        return 0;
    /* $end */
    }
    
    /* ::Qt::Widget::repaint() */
    ::hyve::lang::_void Widget::repaint() const {
    /* $begin(::Qt::Widget::repaint()) */
        QWidget *widget;
        widget = (QWidget*)this->qhandle();
    /* $end */
    }
    
    /* ::Qt::Widget::show() */
    ::hyve::lang::_void Widget::show() const {
    /* $begin(::Qt::Widget::show()) */
        QWidget *widget;
        widget = (QWidget*)this->qhandle();
        widget->show();
    /* $end */
    }
    /* $begin($classfooter) */
    void Widget::refresh(bool move) const {
        QWidget* w;

        w = (QWidget*)this->qhandle();

        /* Resize widget */
        if (w) {
            if ((this->width()>=0) && (this->height()>=0)) {
                w->resize(this->width(), this->height());
            }

            /* Move widget */
            if (move) {
                if ((this->x()>=0) && (this->y()>=0)) {
                    w->move(this->x(), this->y());
                }
            }

            /* Enable or disable widget */
            w->setEnabled(this->enabled());

            /* Show or hide widget */
            if (this->visible()) {
                w->show();
            } else {
                w->hide();
            }
        }
    }
    /* $end */
}

