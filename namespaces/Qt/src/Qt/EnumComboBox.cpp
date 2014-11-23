/* src/Qt/EnumComboBox.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::EnumComboBox.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/EnumComboBox.hpp"
#include "Qt/_meta.hpp"
#include "hyve/lang/Enum.hpp"

namespace QT {
    
    // Constructor
    EnumComboBox::EnumComboBox(const QT::PaintEvent_t &paintEvent,
            const QT::MouseEvent_t &mousePressEvent,
             ::hyve::lang::int32 x,
             ::hyve::lang::int32 y,
             ::hyve::lang::int32 width,
             ::hyve::lang::int32 height,
             ::hyve::lang::_bool enabled,
             ::hyve::lang::_bool visible,
             ::hyve::lang::string styleSheet,
             hyve::ll_h items,
             ::hyve::lang::uint32 currentIndex,
            const ::hyve::lang::Enum &type,
             ::hyve::lang::constant value) : QT::ComboBox((QT::comboBox)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::EnumComboBox_h);
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
        this->type(type);
        this->value(value);
        this->define();
    }
    
    // Constructor (declare & define)
    EnumComboBox::EnumComboBox(::hyve::lang::Object *_parent,
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
             ::hyve::lang::uint32 currentIndex,
            const ::hyve::lang::Enum &type,
             ::hyve::lang::constant value) : QT::ComboBox((QT::comboBox)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::EnumComboBox_h);
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
        this->type(type);
        this->value(value);
        this->define();
    }
    
    // Construct from handle
    EnumComboBox::EnumComboBox(QT::enumComboBox handle, bool owner) : QT::ComboBox((QT::comboBox)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::enumComboBox EnumComboBox::_handle() const {
        return (QT::enumComboBox)this->__handle;
    }
    
    // ::hyve::lang::enum type
    ::hyve::lang::Enum EnumComboBox::type() const {
        ::hyve::lang::Enum result(((QT::enumComboBox)this->__handle)->type);
        return result;
    }
    void EnumComboBox::type(const ::hyve::lang::Enum &v) const {
        if (v) {
            hyve::set((hyve::lang::object*)&((QT::enumComboBox)this->__handle)->type, v._handle());
        } else {
            hyve::set((hyve::lang::object*)&((QT::enumComboBox)this->__handle)->type, NULL);
        }
    }
    
    // ::hyve::lang::constant value
    ::hyve::lang::constant EnumComboBox::value() const {
        return ((QT::enumComboBox)this->__handle)->value;
    }
    void EnumComboBox::value( ::hyve::lang::constant v) const {
        ((QT::enumComboBox)this->__handle)->value = v;
    }
    
    /* ::Qt::EnumComboBox::construct(::Qt::EnumComboBox object) */
    ::hyve::lang::int16 EnumComboBox::construct(const QT::EnumComboBox &object) {
    /* $begin(::Qt::EnumComboBox::construct(::Qt::EnumComboBox object)) */
        hyve::lang::uint32 i;
        hyve::lang::constant *c;
        hyve::ll items;
        hyve::lang::int16 result;
        hyve::lang::string *strptr;

        /* Create new list */
        if (!object.items()) {
            object.items(hyve::ll::_new());
        }

        /* Use convenience-wrapper for list */
        items = hyve::ll(object.items());

        /* Walk constants, add them to items-list */
        for(i=0; i<object._handle()->type->constants.length; i++) {
            c = (hyve::lang::constant*)object._handle()->type->constants.buffer[i];
            strptr = (hyve::lang::string*)hyve::alloc(sizeof(hyve::lang::string));
            *strptr = hyve::strdup(hyve::nameof(c));
            items.append(strptr);
        }

        /* Call ComboBox constructor */
        result = QT::ComboBox::construct(object);

        return result;
    /* $end */
    }
    
    /* ::Qt::EnumComboBox::destruct(::Qt::EnumComboBox object) */
    ::hyve::lang::_void EnumComboBox::destruct(const QT::EnumComboBox &object) {
    /* $begin(::Qt::EnumComboBox::destruct(::Qt::EnumComboBox object)) */
        (void)object;
    /* $end */
    }
}

