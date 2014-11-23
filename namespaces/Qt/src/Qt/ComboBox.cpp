/* src/Qt/ComboBox.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::ComboBox.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/ComboBox.hpp"
#include "Qt/_meta.hpp"
#include "hyve/lang/Object.hpp"

/* $begin($header) */
namespace QT {
    ComboBoxSlots::ComboBoxSlots(QT::comboBox handle, QComboBox *handle_q) {
        this->handle = handle;
        this->handle_q = handle_q;
        QObject::connect(handle_q, SIGNAL(currentIndexChanged(QString)), this, SLOT(changed(QString)));
    }
    void ComboBoxSlots::changed(QString string) {
        QByteArray data;
        hyve::lang::string str;
        if (!this->muted) {
            hyve::updateBegin(this->handle);

            if (this->handle->currentText) {
                hyve::dealloc(this->handle->currentText);
            }
            data = string.toUtf8();
            str = data.data();

            this->handle->currentText = hyve::strdup(str);
            this->handle->currentIndex = this->handle_q->currentIndex();

            hyve::updateEndFrom(this->handle, this->handle);
        }
    }
}
/* $end */

namespace QT {
    
    // Constructor
    ComboBox::ComboBox(const QT::PaintEvent_t &paintEvent,
            const QT::MouseEvent_t &mousePressEvent,
             ::hyve::lang::int32 x,
             ::hyve::lang::int32 y,
             ::hyve::lang::int32 width,
             ::hyve::lang::int32 height,
             ::hyve::lang::_bool enabled,
             ::hyve::lang::_bool visible,
             ::hyve::lang::string styleSheet,
             hyve::ll_h items,
             ::hyve::lang::uint32 currentIndex) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::ComboBox_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->items(items);
        this->currentIndex(currentIndex);
        this->define();
    }
    
    // Constructor (declare & define)
    ComboBox::ComboBox(::hyve::lang::Object *_parent,
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
             ::hyve::lang::uint32 currentIndex) : QT::Widget((QT::widget)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::ComboBox_h);
        this->paintEvent(paintEvent);
        this->mousePressEvent(mousePressEvent);
        this->x(x);
        this->y(y);
        this->width(width);
        this->height(height);
        this->enabled(enabled);
        this->visible(visible);
        this->styleSheet(styleSheet);
        this->items(items);
        this->currentIndex(currentIndex);
        this->define();
    }
    
    // Construct from handle
    ComboBox::ComboBox(QT::comboBox handle, bool owner) : QT::Widget((QT::widget)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::comboBox ComboBox::_handle() const {
        return (QT::comboBox)this->__handle;
    }
    
    // <0x815cd48> items
    hyve::ll_h ComboBox::items() const {
        return ((QT::comboBox)this->__handle)->items;
    }
    void ComboBox::items( hyve::ll_h v) const {
        ((QT::comboBox)this->__handle)->items = v;
    }
    
    // ::hyve::lang::uint32 currentIndex
    ::hyve::lang::uint32 ComboBox::currentIndex() const {
        return ((QT::comboBox)this->__handle)->currentIndex;
    }
    void ComboBox::currentIndex( ::hyve::lang::uint32 v) const {
        ((QT::comboBox)this->__handle)->currentIndex = v;
    }
    
    // ::hyve::lang::string currentText
    ::hyve::lang::string ComboBox::currentText() const {
        return ((QT::comboBox)this->__handle)->currentText;
    }
    void ComboBox::currentText( ::hyve::lang::string v) const {
        if (((QT::comboBox)this->__handle)->currentText) {
            hyve::dealloc(((QT::comboBox)this->__handle)->currentText);
        };
        ((QT::comboBox)this->__handle)->currentText = v ? hyve::strdup(v) : NULL;
    }
    
    /* ::Qt::ComboBox::construct(::Qt::ComboBox object) */
    ::hyve::lang::int16 ComboBox::construct(const QT::ComboBox &object) {
    /* $begin(::Qt::ComboBox::construct(::Qt::ComboBox object)) */
        QComboBox *button;
        QWidget *parent_q; /* Parent handle to Qt object */

        /* Obtain parent handle (Could also have been done using proxy-objects, but this is faster) */
        parent_q = (QWidget*)object.widgetParent();

        /* Create button */
        button = new QComboBox(parent_q);
        if (!button) {
            hyve::error("Qt::QComboBox::construct: failed to create object '%s'", object.nameof());
            goto error;
        }

        /* Set slots */
        object.qslots((hyve::lang::word)new ComboBoxSlots(object._handle(), button));

        /* Set handle */
        object.qhandle((hyve::lang::word)button);

        /* Setup Qt object */
        object.refresh();

        /* Show button */
        button->show();
        return 0;
    error:
        return -1;
    /* $end */
    }
    
    /* ::Qt::ComboBox::destruct(::Qt::ComboBox object) */
    ::hyve::lang::_void ComboBox::destruct(const QT::ComboBox &object) {
    /* $begin(::Qt::ComboBox::destruct(::Qt::ComboBox object)) */
        (void)object;
    /* $end */
    }
    
    /* ::Qt::ComboBox::onSelf */
    ::hyve::lang::_void ComboBox::onSelf(const ::hyve::lang::Object &observable, const ::hyve::lang::Object &source) const {
    /* $begin(::Qt::ComboBox::onSelf) */
        (void)observable;
        (void)source;
        ((ComboBoxSlots*)this->qslots())->mute(true);
        this->refresh();
        ((ComboBoxSlots*)this->qslots())->mute(false);
    /* $end */
    }
    /* $begin($classfooter) */
    void ComboBox::refresh() const {
        QComboBox *button;
        hyve::lang::uint32 elements, i;
        QStringList strSeq;
        hyve::lang::string str;
        hyve::ll list;

        button = (QComboBox*)this->qhandle();

        /* Add list-items */
        list = hyve::ll(this->items());
        elements = list.size();
        if (elements) {
            for(i=0; i<elements; i++) {
                str = *(char**)list.get(i);
                strSeq.append(QString::fromUtf8(str));
            }

            button->clear();
            button->insertItems(0, strSeq);

            /* Set currentText */
            if (this->currentIndex() < list.size()) {
                this->currentText(hyve::strdup(*(hyve::lang::string*)list.get(this->currentIndex())));
                button->setCurrentIndex(this->currentIndex());
            } else {
                hyve::error("index exceeds listsize");
            }
        }

        /* Refresh widget */
        ((QT::Widget*)this)->refresh();
    }
    /* $end */
}

