/* src/Qt/MainWindow.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::MainWindow.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/MainWindow.hpp"
#include "Qt/_meta.hpp"
#include "hyve/lang/Object.hpp"

/* $begin($header) */
#include "QMainWindow"
#include "QMoveEvent"
#include "QResizeEvent"
#include "SlotBase.hpp"
#include "hyve/lang/Observer.hpp"
#include "hyve/lang/Dispatcher.hpp"
#include "Qt/Application.hpp"

// Catch move and resize eventhandlers
namespace QT {
class QTMainWindow : public QMainWindow, public SlotBase {
public:
    QTMainWindow(const QT::MainWindow& wnd, QWidget *parent = NULL) : QMainWindow(parent) {
        this->wnd = wnd._handle();
    }

    void moveEvent(QMoveEvent *event) {
        if (!this->muted) {
            this->muted = TRUE;
            QPoint pos = event->pos();
            hyve::updateBegin(this->wnd);
            ((QT::widget)wnd)->x = pos.x();
            ((QT::widget)wnd)->y = pos.y();
            hyve::updateEndFrom(this->wnd, this->wnd);
            this->muted = FALSE;
        }
    }

    void resizeEvent(QResizeEvent *event) {
        if (!this->muted) {
            QSize size = event->size();
            this->muted = TRUE;
            hyve::updateBegin(this->wnd);
            ((QT::widget)wnd)->width = size.width();
            ((QT::widget)wnd)->height = size.height();
            hyve::updateEndFrom(this->wnd, this->wnd);
            this->muted = FALSE;
        }
    }

private:
    QT::mainWindow wnd;
};
}
/* $end */

namespace QT {
    
    // Constructor
    MainWindow::MainWindow(const QT::PaintEvent_t &paintEvent,
            const QT::MouseEvent_t &mousePressEvent,
             ::hyve::lang::int32 x,
             ::hyve::lang::int32 y,
             ::hyve::lang::int32 width,
             ::hyve::lang::int32 height,
             ::hyve::lang::_bool enabled,
             ::hyve::lang::_bool visible,
             ::hyve::lang::string styleSheet,
             ::hyve::lang::string title) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::MainWindow_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->title(title);
        this->define();
    }
    
    // Constructor (declare & define)
    MainWindow::MainWindow(::hyve::lang::Object *_parent,
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
             ::hyve::lang::string title) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::MainWindow_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->title(title);
        this->define();
    }
    
    // Construct from handle
    MainWindow::MainWindow(QT::mainWindow handle, bool owner) : QT::Widget((QT::widget)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::mainWindow MainWindow::_handle() const {
        return (QT::mainWindow)this->__handle;
    }
    
    // ::hyve::lang::string title
    ::hyve::lang::string MainWindow::title() const {
        return ((QT::mainWindow)this->__handle)->title;
    }
    void MainWindow::title( ::hyve::lang::string v) const {
        if (((QT::mainWindow)this->__handle)->title) {
            hyve::dealloc(((QT::mainWindow)this->__handle)->title);
        };
        ((QT::mainWindow)this->__handle)->title = v ? hyve::strdup(v) : NULL;
    }
    
    // ::hyve::lang::word cw
    ::hyve::lang::word MainWindow::cw() const {
        return ((QT::mainWindow)this->__handle)->cw;
    }
    void MainWindow::cw( ::hyve::lang::word v) const {
        ((QT::mainWindow)this->__handle)->cw = v;
    }
    
    /* ::Qt::MainWindow::construct(::Qt::MainWindow object) */
    ::hyve::lang::int16 MainWindow::construct(const QT::MainWindow &object) {
    /* $begin(::Qt::MainWindow::construct(::Qt::MainWindow object)) */
        QMainWindow *wnd;
        QWidget *cw; /* central widget */
        QIcon icon("hyveicon.png");

        wnd = new QT::QTMainWindow(object);
        object.qhandle((hyve::lang::word)wnd);
        wnd->setWindowTitle(QString::fromUtf8(object.title()));

        wnd->setWindowIcon(icon);

        if (object._handle()->_parent.styleSheet) {
            wnd->setStyleSheet(object._handle()->_parent.styleSheet);
        }

        /* Call widget constructor for window */
        if (QT::Widget::construct(object)) {
            goto error;
        }

        /* Create central widget */
        cw = new QWidget(wnd);
        cw->setObjectName(QString::fromUtf8("centralwidget"));
        wnd->setCentralWidget(cw);
        wnd->show();

        /* Set dispatcher for own observers */
        {
            hyve::lang::Observer onSelf(QT::MainWindow_onSelf_h); // Create proxy for template observer
            hyve::lang::Dispatcher dispatcher(QT::app(),false);
            onSelf.setDispatcher(dispatcher);
        }

        /* Set object-handle window. */
        object.qhandle((hyve::lang::word)wnd);

        /* Keep a pointer to the central widget. This object servers as parent for
           widgets in this window. */
        object.cw((hyve::lang::word)cw);

        return 0;
    error:
        return -1;
    /* $end */
    }
    
    /* ::Qt::MainWindow::destruct(::Qt::MainWindow object) */
    ::hyve::lang::_void MainWindow::destruct(const QT::MainWindow &object) {
    /* $begin(::Qt::MainWindow::destruct(::Qt::MainWindow object)) */
        (void)object;
    /* $end */
    }
    
    /* ::Qt::MainWindow::onSelf */
    ::hyve::lang::_void MainWindow::onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::MainWindow::onSelf) */
        QTMainWindow *handle = (QTMainWindow*)this->qhandle();
        (void)observable;
        (void)source;

        // Refresh widget (mute events)
        handle->mute(true);
        this->refresh();
        handle->mute(false);
    /* $end */
    }
    /* $begin($classfooter) */
    void MainWindow::refresh() const {
        QMainWindow *widget;
        widget = (QMainWindow*)this->qhandle();
        widget->setWindowTitle(QString::fromUtf8(this->title()));
        ((Widget*)this)->refresh(false);
    }

    /* $end */
}

