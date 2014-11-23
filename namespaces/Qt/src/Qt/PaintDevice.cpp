/* src/Qt/PaintDevice.cpp
 *
 *  Generated on Feb  5 2014
 *    C++ implementationfile for ::Qt::PaintDevice.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "hyve/lang/Class.hpp"
#include "hyve/lang/Method.hpp"
#include "Qt/PaintDevice.hpp"
#include "Qt/_meta.hpp"

namespace QT {
    
    // Constructor
    PaintDevice::PaintDevice() {
        this->__handle = ::hyve::_new((::hyve::lang::_typedef)QT::PaintDevice_h);
        this->define();
    }
    
    // Constructor (declare & define)
    PaintDevice::PaintDevice(::hyve::lang::Object *_parent,
            ::hyve::lang::string _name) {
        this->__handle = ::hyve::declare(_parent->_handle(), _name, (::hyve::lang::_typedef)QT::PaintDevice_h);
        this->define();
    }
    
    // Construct from handle
    PaintDevice::PaintDevice(QT::paintDevice handle, bool owner) : ::hyve::lang::Object((::hyve::lang::object)handle, owner) {
        // Handle is set and keep'd by Object::Object(object handle)
    }
    
    // Get handle
    QT::paintDevice PaintDevice::_handle() const {
        return (QT::paintDevice)this->__handle;
    }
}

