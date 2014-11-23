/* src/Qt/GridLayout.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::GridLayout.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/GridLayout.hpp"
#include "Qt/_meta.hpp"
#include "hyve/lang/Object.hpp"

/* $begin($header) */
#include "QGridLayout"
/* $end */

namespace QT {
    
    // Constructor
    GridLayout::GridLayout( QT::GridRow_seq rows,
             QT::GridColumn_seq columns,
             QT::GridWidget_seq widgets) : QT::Object((QT::object)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::GridLayout_h);
        this->rows(rows);
        this->columns(columns);
        this->widgets(widgets);
        this->define();
    }
    
    // Constructor (declare & define)
    GridLayout::GridLayout(::hyve::lang::Object *_parent,
            ::hyve::lang::string _name,
             QT::GridRow_seq rows,
             QT::GridColumn_seq columns,
             QT::GridWidget_seq widgets) : QT::Object((QT::object)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::GridLayout_h);
        this->rows(rows);
        this->columns(columns);
        this->widgets(widgets);
        this->define();
    }
    
    // Construct from handle
    GridLayout::GridLayout(QT::gridLayout handle, bool owner) : QT::Object((QT::object)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::gridLayout GridLayout::_handle() const {
        return (QT::gridLayout)this->__handle;
    }
    
    // <0x816f668> rows
    QT::GridRow_seq GridLayout::rows() const {
        return ((QT::gridLayout)this->__handle)->rows;
    }
    void GridLayout::rows( QT::GridRow_seq v) const {
        ((QT::gridLayout)this->__handle)->rows = v;
    }
    
    // <0x816ffa8> columns
    QT::GridColumn_seq GridLayout::columns() const {
        return ((QT::gridLayout)this->__handle)->columns;
    }
    void GridLayout::columns( QT::GridColumn_seq v) const {
        ((QT::gridLayout)this->__handle)->columns = v;
    }
    
    // <0x81708d0> widgets
    QT::GridWidget_seq GridLayout::widgets() const {
        return ((QT::gridLayout)this->__handle)->widgets;
    }
    void GridLayout::widgets( QT::GridWidget_seq v) const {
        ((QT::gridLayout)this->__handle)->widgets = v;
    }
    
    /* ::Qt::GridLayout::construct(::Qt::GridLayout object) */
    ::hyve::lang::int16 GridLayout::construct(const QT::GridLayout &object) {
    /* $begin(::Qt::GridLayout::construct(::Qt::GridLayout object)) */
        QGridLayout *widget;
        QWidget *parent_q; /* Parent handle to Qt object */

        /* Obtain parent handle (Could also have been done using proxy-objects, but this is faster) */
        parent_q = (QWidget*)object.widgetParent();

        /* Create button */
        widget = new QGridLayout(parent_q);
        if (!widget) {
            hyve::error("Qt::PushButton::construct: failed to create object '%s'", object.nameof());
            goto error;
        }

        /* Set handle */
        object.qhandle((hyve::lang::word)widget);
        object.refresh();

        return 0;
    error:
        return -1;
    /* $end */
    }
    
    /* ::Qt::GridLayout::destruct(::Qt::GridLayout object) */
    ::hyve::lang::_void GridLayout::destruct(const QT::GridLayout &object) {
    /* $begin(::Qt::GridLayout::destruct(::Qt::GridLayout object)) */
        (void)object;
    /* $end */
    }
    
    /* ::Qt::GridLayout::onSelf */
    ::hyve::lang::_void GridLayout::onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::GridLayout::onSelf) */
        (void)observable;
        (void)source;
    /* $end */
    }
    /* $begin($classfooter) */
    void GridLayout::refresh() const {
        QGridLayout* widget;
        hyve::lang::uint32 i;
        QT::GridRow *row;
        QT::GridColumn *column;
        QT::GridWidget *gw;
        QWidget *qgw;

        widget = (QGridLayout*)this->qhandle();

        // Set spacing
        widget->setSpacing(6);
        widget->setContentsMargins(1, 1, 1, 1);
        widget->setSizeConstraint(QLayout::SetNoConstraint);

        // Set row parameters */
        for(i=0; i<this->rows().length; i++) {
            row = &this->rows().buffer[i];
            widget->setRowStretch(i, row->stretch);
            widget->setRowMinimumHeight(i, row->minimumHeight);
        }

        // Set column parameters
        for(i=0; i<this->columns().length; i++) {
            column = &this->columns().buffer[i];
            widget->setColumnStretch(i, column->stretch);
            widget->setColumnMinimumWidth(i, column->minimumWidth);
        }

        // Set widgets
        for(i=0; i<this->widgets().length; i++) {
            gw = &this->widgets().buffer[i];
            qgw = (QWidget*)gw->widget->_parent.qhandle;
            widget->addWidget(qgw, gw->row, gw->column, gw->rowspan, gw->columnspan);
        }
    }
    /* $end */
}

