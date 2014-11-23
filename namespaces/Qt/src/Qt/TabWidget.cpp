/* src/Qt/TabWidget.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::TabWidget.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/TabWidget.hpp"
#include "Qt/_meta.hpp"
#include "Qt/Widget.hpp"

/* $begin($header) */
#include "QTabWidget"


namespace QT {
    TabWidgetSlots::TabWidgetSlots(QT::tabWidget handle, QTabWidget *handle_q) {
        this->handle = handle;
        this->handle_q = handle_q;
        QObject::connect(handle_q, SIGNAL(currentChanged(int)), this, SLOT(currentChanged(int)));
        QObject::connect(handle_q, SIGNAL(tabCloseRequested(int)), this, SLOT(tabCloseRequested(int)));
    }

    QT::TabWidgetTab *TabWidgetSlots::getTab(int index) {
        hyve::ll tabs(handle->tabs);
        QT::TabWidgetTab *tab = NULL;

        if (index >= 0) {
            tab = (QT::TabWidgetTab*)tabs.get(index);
        }
        return tab;
    }

    void TabWidgetSlots::currentChanged(int index) {
        QT::TabWidgetTab *tab;

        if (!this->muted && (index >= 0)) {
            this->muted = TRUE;
            hyve::updateBegin(this->handle);

            tab = this->getTab(index);
            this->handle->currentIndex = index;
            hyve::set((void**)&handle->currentWidget, tab->widget);

            hyve::updateEndFrom(this->handle, this->handle);
            this->muted = FALSE;
        }
    }

    void TabWidgetSlots::tabCloseRequested(int index) {
        hyve::ll tabs(handle->tabs);
        QT::TabWidgetTab *tab;

        if (!this->muted && (index >= 0)) {
            this->muted = TRUE;
            hyve::updateBegin(this->handle);

            /* Find current widget */
            tab = getTab(index);

            /* Remove from list */
            if (tab) {
                tabs.remove(tab);
                hyve::free(tab->widget);
                hyve::dealloc(tab->label);
                hyve::dealloc(tab);
            } else {
                hyve::error("element not found for tab-index %d");
            }

            if (handle_q->currentIndex() == index) {
                hyve::set((void**)&handle->currentWidget, NULL);
            }

            hyve::updateEndFrom(this->handle, this->handle);
            this->muted = FALSE;
        } else {
            hyve::set((void**)&handle->currentWidget, NULL);
        }
    }
}
/* $end */

namespace QT {
    
    // Constructor
    TabWidget::TabWidget(const QT::PaintEvent_t &paintEvent,
            const QT::MouseEvent_t &mousePressEvent,
             ::hyve::lang::int32 x,
             ::hyve::lang::int32 y,
             ::hyve::lang::int32 width,
             ::hyve::lang::int32 height,
             ::hyve::lang::_bool enabled,
             ::hyve::lang::_bool visible,
             ::hyve::lang::string styleSheet,
             hyve::ll_h tabs,
             ::hyve::lang::_bool closable,
             ::hyve::lang::_bool movable,
             ::hyve::lang::uint32 currentIndex,
            const QT::Widget &currentWidget,
             ::hyve::lang::uint32 count) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::TabWidget_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->tabs(tabs);
        this->closable(closable);
        this->movable(movable);
        this->currentIndex(currentIndex);
        this->currentWidget(currentWidget);
        this->count(count);
        this->define();
    }
    
    // Constructor (declare & define)
    TabWidget::TabWidget(::hyve::lang::Object *_parent,
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
             hyve::ll_h tabs,
             ::hyve::lang::_bool closable,
             ::hyve::lang::_bool movable,
             ::hyve::lang::uint32 currentIndex,
            const QT::Widget &currentWidget,
             ::hyve::lang::uint32 count) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::TabWidget_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->tabs(tabs);
        this->closable(closable);
        this->movable(movable);
        this->currentIndex(currentIndex);
        this->currentWidget(currentWidget);
        this->count(count);
        this->define();
    }
    
    // Construct from handle
    TabWidget::TabWidget(QT::tabWidget handle, bool owner) : QT::Widget((QT::widget)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::tabWidget TabWidget::_handle() const {
        return (QT::tabWidget)this->__handle;
    }
    
    // <0x8167488> tabs
    hyve::ll_h TabWidget::tabs() const {
        return ((QT::tabWidget)this->__handle)->tabs;
    }
    void TabWidget::tabs( hyve::ll_h v) const {
        ((QT::tabWidget)this->__handle)->tabs = v;
    }
    
    // ::hyve::lang::bool closable
    ::hyve::lang::_bool TabWidget::closable() const {
        return ((QT::tabWidget)this->__handle)->closable;
    }
    void TabWidget::closable( ::hyve::lang::_bool v) const {
        ((QT::tabWidget)this->__handle)->closable = v;
    }
    
    // ::hyve::lang::bool movable
    ::hyve::lang::_bool TabWidget::movable() const {
        return ((QT::tabWidget)this->__handle)->movable;
    }
    void TabWidget::movable( ::hyve::lang::_bool v) const {
        ((QT::tabWidget)this->__handle)->movable = v;
    }
    
    // ::hyve::lang::uint32 currentIndex
    ::hyve::lang::uint32 TabWidget::currentIndex() const {
        return ((QT::tabWidget)this->__handle)->currentIndex;
    }
    void TabWidget::currentIndex( ::hyve::lang::uint32 v) const {
        ((QT::tabWidget)this->__handle)->currentIndex = v;
    }
    
    // ::Qt::Widget currentWidget
    QT::Widget TabWidget::currentWidget() const {
        QT::Widget result(((QT::tabWidget)this->__handle)->currentWidget);
        return result;
    }
    void TabWidget::currentWidget(const QT::Widget &v) const {
        if (v) {
            hyve::set((hyve::lang::object*)&((QT::tabWidget)this->__handle)->currentWidget, v._handle());
        } else {
            hyve::set((hyve::lang::object*)&((QT::tabWidget)this->__handle)->currentWidget, NULL);
        }
    }
    
    // ::hyve::lang::uint32 count
    ::hyve::lang::uint32 TabWidget::count() const {
        return ((QT::tabWidget)this->__handle)->count;
    }
    void TabWidget::count( ::hyve::lang::uint32 v) const {
        ((QT::tabWidget)this->__handle)->count = v;
    }
    
    /* ::Qt::TabWidget::addTab(::hyve::lang::string label,::Qt::Widget widget) */
    ::hyve::lang::_void TabWidget::addTab(::hyve::lang::string label, const QT::Widget &widget) const {
    /* $begin(::Qt::TabWidget::addTab(::hyve::lang::string label,::Qt::Widget widget)) */
        QTabWidget *qhandle;
        QWidget *toAdd;
        QT::TabWidgetTab *newTab = (QT::TabWidgetTab*)hyve::alloc(sizeof(QT::TabWidgetTab));

        ((TabWidgetSlots*)this->qslots())->mute(true);

        this->updateBegin();

        if (!this->tabs()) {
            this->tabs(hyve::ll::_new());
        }

        hyve::ll tabs(this->tabs());

        qhandle = (QTabWidget*)this->qhandle();
        toAdd = (QWidget*)widget.qhandle();
        newTab->label = hyve::strdup(label);
        newTab->widget = widget._handle();
        tabs.append(newTab);
        hyve::keep(widget._handle());

        if (tabs.size() == 1) {
            this->_handle()->currentWidget = widget._handle();
            hyve::keep(widget._handle());
        }

        qhandle->addTab(toAdd, QString(label));
        qhandle->setCurrentIndex(qhandle->count()-1);
        hyve::set((void**)&this->_handle()->currentWidget, widget._handle());

        this->updateEndFrom(*this);

        ((TabWidgetSlots*)this->qslots())->mute(false);

    /* $end */
    }
    
    /* ::Qt::TabWidget::construct(::Qt::TabWidget object) */
    ::hyve::lang::int16 TabWidget::construct(const QT::TabWidget &object) {
    /* $begin(::Qt::TabWidget::construct(::Qt::TabWidget object)) */
        QTabWidget *widget;
        QWidget *parent_q; /* Parent handle to Qt object */
        hyve::ll tabs(object.tabs());

        /* Obtain parent handle (Could also have been done using proxy-objects, but this is faster) */
        parent_q = (QWidget*)object.widgetParent();

        /* Create button */
        widget = new QTabWidget(parent_q);
        if (!widget) {
            hyve::error("Qt::TabWidget::construct: failed to create object '%s'", object.nameof());
            goto error;
        }

        /* Set state to state of hyve object */
        widget->setTabsClosable(object.closable());
        widget->setMovable(object.movable());

        /* Add tabs */
        QT::TabWidgetTab *tab;
        for(int i=0; i<tabs.size(); i++) {
            tab = (QT::TabWidgetTab*)tabs.get(i);
            widget->addTab((QWidget*)tab->widget->_parent.qhandle, QString(tab->label));
        }

        /* Set handle */
        object.qhandle((hyve::lang::word)widget);

        /* Call abstractbutton constructor */
        QT::Widget::construct(object);

        /* Setup slots */
        object.qslots((hyve::lang::word)new TabWidgetSlots(object._handle(), widget));

        /* Show button */
        widget->show();
        return 0;
    error:
        return -1;
    /* $end */
    }
    
    /* ::Qt::TabWidget::destruct(::Qt::TabWidget object) */
    ::hyve::lang::_void TabWidget::destruct(const QT::TabWidget &object) {
    /* $begin(::Qt::TabWidget::destruct(::Qt::TabWidget object)) */
        /* From now on accept no more events */
        ((TabWidgetSlots*)object.qslots())->mute(true);
    /* $end */
    }
}

