/* src/Qt/Object.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::Object.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/Object.hpp"
#include "Qt/_meta.hpp"

namespace QT {
    
    // Constructor
    Object::Object() : ::hyve::lang::Object((::hyve::lang::object)NULL) {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::Object_h);
        this->define();
    }
    
    // Constructor (declare & define)
    Object::Object(::hyve::lang::Object *_parent,
            ::hyve::lang::string _name) : ::hyve::lang::Object((::hyve::lang::object)NULL) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::Object_h);
        this->define();
    }
    
    // Construct from handle
    Object::Object(QT::object handle, bool owner) : ::hyve::lang::Object((::hyve::lang::object)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::object Object::_handle() const {
        return (QT::object)this->__handle;
    }
    
    // ::hyve::lang::word qhandle
    ::hyve::lang::word Object::qhandle() const {
        return ((QT::object)this->__handle)->qhandle;
    }
    void Object::qhandle( ::hyve::lang::word v) const {
        ((QT::object)this->__handle)->qhandle = v;
    }
    
    /* ::Qt::Object::widgetParent() */
    ::hyve::lang::word Object::widgetParent() const {
    /* $begin(::Qt::Object::widgetParent()) */
        hyve::lang::object _parent = NULL;
        hyve::lang::word handle = 0;

        /* Get parent handle */
        if (hyve::checkAttr(this->_handle(), hyve::ATTR_SCOPED)) {
            _parent = hyve::parentof(this->_handle());

            /* Check whether parent is a MainWindow, because then the centralWidget must be returned */
            if (hyve::_typeof(_parent) == (hyve::lang::_typedef)QT::MainWindow_h) {
                handle = ((mainWindow)_parent)->cw;
            } else {
                handle = ((object)_parent)->qhandle;
            }
        }

        return handle;
    /* $end */
    }
}

