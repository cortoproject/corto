/* src/Qt/Pen.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::Pen.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/Pen.hpp"
#include "Qt/_meta.hpp"

/* $begin($header) */
#include "QPen"
/* $end */

namespace QT {
    
    // Constructor
    Pen::Pen( QT::Color color,
             ::hyve::lang::uint32 width) : QT::Object((QT::object)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::Pen_h);
        this->color(color);
        this->width(width);
        this->define();
    }
    
    // Constructor (declare & define)
    Pen::Pen(::hyve::lang::Object *_parent,
            ::hyve::lang::string _name,
             QT::Color color,
             ::hyve::lang::uint32 width) : QT::Object((QT::object)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::Pen_h);
        this->color(color);
        this->width(width);
        this->define();
    }
    
    // Construct from handle
    Pen::Pen(QT::pen handle, bool owner) : QT::Object((QT::object)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::pen Pen::_handle() const {
        return (QT::pen)this->__handle;
    }
    
    // ::Qt::Color color
    QT::Color Pen::color() const {
        return ((QT::pen)this->__handle)->color;
    }
    void Pen::color( QT::Color v) const {
        ((QT::pen)this->__handle)->color = v;
    }
    
    // ::hyve::lang::uint32 width
    ::hyve::lang::uint32 Pen::width() const {
        return ((QT::pen)this->__handle)->width;
    }
    void Pen::width( ::hyve::lang::uint32 v) const {
        ((QT::pen)this->__handle)->width = v;
    }
    
    /* ::Qt::Pen::construct(::Qt::Pen object) */
    ::hyve::lang::int16 Pen::construct(const QT::Pen &object) {
    /* $begin(::Qt::Pen::construct(::Qt::Pen object)) */
        QPen *pen;
        QColor c(object.color().r, object.color().g, object.color().b, object.color().alpha);

        pen = new QPen(c);
        pen->setWidth(object.width());
        object.qhandle((hyve::lang::word)pen);

        return 0;
    /* $end */
    }
    
    /* ::Qt::Pen::destruct(::Qt::Pen object) */
    ::hyve::lang::_void Pen::destruct(const QT::Pen &object) {
    /* $begin(::Qt::Pen::destruct(::Qt::Pen object)) */
        QPen *pen;

        pen = (QPen*)object.qhandle();
        delete pen;
    /* $end */
    }
}

