/* src/Qt/Font.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::Font.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/Font.hpp"
#include "Qt/_meta.hpp"

/* $begin($header) */
#include "QFont"
/* $end */

namespace QT {
    
    // Constructor
    Font::Font( ::hyve::lang::string family,
             ::hyve::lang::int32 pointSize,
             QT::FontWeight weight,
             ::hyve::lang::_bool italic) : QT::Object((QT::object)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::Font_h);
        this->family(family);
        this->pointSize(pointSize);
        this->weight(weight);
        this->italic(italic);
        this->define();
    }
    
    // Constructor (declare & define)
    Font::Font(::hyve::lang::Object *_parent,
            ::hyve::lang::string _name,
             ::hyve::lang::string family,
             ::hyve::lang::int32 pointSize,
             QT::FontWeight weight,
             ::hyve::lang::_bool italic) : QT::Object((QT::object)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::Font_h);
        this->family(family);
        this->pointSize(pointSize);
        this->weight(weight);
        this->italic(italic);
        this->define();
    }
    
    // Construct from handle
    Font::Font(QT::font handle, bool owner) : QT::Object((QT::object)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::font Font::_handle() const {
        return (QT::font)this->__handle;
    }
    
    // ::hyve::lang::string family
    ::hyve::lang::string Font::family() const {
        return ((QT::font)this->__handle)->family;
    }
    void Font::family( ::hyve::lang::string v) const {
        if (((QT::font)this->__handle)->family) {
            hyve::dealloc(((QT::font)this->__handle)->family);
        };
        ((QT::font)this->__handle)->family = v ? hyve::strdup(v) : NULL;
    }
    
    // ::hyve::lang::int32 pointSize
    ::hyve::lang::int32 Font::pointSize() const {
        return ((QT::font)this->__handle)->pointSize;
    }
    void Font::pointSize( ::hyve::lang::int32 v) const {
        ((QT::font)this->__handle)->pointSize = v;
    }
    
    // ::Qt::FontWeight weight
    QT::FontWeight Font::weight() const {
        return ((QT::font)this->__handle)->weight;
    }
    void Font::weight( QT::FontWeight v) const {
        ((QT::font)this->__handle)->weight = v;
    }
    
    // ::hyve::lang::bool italic
    ::hyve::lang::_bool Font::italic() const {
        return ((QT::font)this->__handle)->italic;
    }
    void Font::italic( ::hyve::lang::_bool v) const {
        ((QT::font)this->__handle)->italic = v;
    }
    
    /* ::Qt::Font::construct(::Qt::Font object) */
    ::hyve::lang::int16 Font::construct(const QT::Font &object) {
    /* $begin(::Qt::Font::construct(::Qt::Font object)) */
        QFont *font;

        font = new QFont(object.family(), object.pointSize(), (int)object.weight(), object.italic());
        object.qhandle((hyve::lang::word)font);

        return 0;
    /* $end */
    }
    
    /* ::Qt::Font::destruct(::Qt::Font object) */
    ::hyve::lang::_void Font::destruct(const QT::Font &object) {
    /* $begin(::Qt::Font::destruct(::Qt::Font object)) */
        QFont *font;

        font = (QFont*)object.qhandle();
        delete font;
    /* $end */
    }
}

