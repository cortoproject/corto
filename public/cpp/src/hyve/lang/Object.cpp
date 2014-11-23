/*
 * Object.cpp
 *
 *  Created on: Jan 6, 2013
 *      Author: sander
 */

#include "hyve/lang/Object.hpp"
#include "hyve/lang/Type.hpp"

namespace hyve {
	namespace lang {

		// Create proxy from handle
		Object::Object(hyve::lang::object handle, bool owner) {
		    if (handle && owner) {
                hyve::keep(NULL, handle, "keep object [C++ proxy new]");
		    }
            this->__handle = handle;
            this->owner = owner;
		}

		Object::~Object() {
			if (this->__handle && owner) {
				hyve::free(NULL, this->__handle, "free object [C++ proxy delete]");
			}
		}

		// Create new object
		hyve::lang::Object Object::_new(
				::hyve::lang::Type &type) {
			Object result(::hyve::_new((_typedef)type._handle()));
			return result;
		}

		// Declare new object in scope of self
		::hyve::lang::Object Object::declare(
			::hyve::lang::string name,
			::hyve::lang::Type &type) const {
			Object result(::hyve::declare(this->__handle, name, (_typedef)type._handle()));
			return result;
		}

		// Destruct scoped object
		void Object::destruct() const {
			::hyve::destruct(this->__handle);
		}

		// Define object
		::hyve::lang::int16 Object::define() const {
			return ::hyve::define(this->__handle);
		}

		// Lookup object
		::hyve::lang::Object Object::lookup(
			::hyve::lang::string name) const {
			Object result(::hyve::lookup(this->__handle, name));
			return result;
		}

		// Resolve object
		::hyve::lang::Object Object::resolve(
			::hyve::lang::string name) const {
			Object result(::hyve::resolve(this->__handle, name));
			return result;
		}

		// Get type
		::hyve::lang::Typedef Object::_typeof() const {
			hyve::lang::Typedef result(::hyve::_typeof(this->__handle));
			return result;
		}

		// Get refcount
		::hyve::lang::uint32 Object::countof() const {
			return ::hyve::countof(this->__handle);
		}

		// Get name
		::hyve::lang::string Object::nameof() const {
			return ::hyve::nameof(this->__handle);
		}

		// Get parent
		::hyve::lang::Object Object::parentof() const {
			Object result(::hyve::parentof(this->__handle));
			return result;
		}

		::hyve::lang::uint32 Object::scopeSize() const {
			return hyve::scopeSize(this->__handle);
		}

		// Get scoped name
		::hyve::lang::string Object::fullname(::hyve::id buffer) const {
			return ::hyve::fullname(this->__handle, buffer);
		}

        // Check for attribubte
        ::hyve::lang::_bool Object::checkAttr(::hyve::lang::uint8 attr) const {
            return hyve::checkAttr(this->__handle, attr);
        }

        // Check for state
        ::hyve::lang::_bool Object::checkState(::hyve::lang::uint8 state) const {
            return hyve::checkState(this->__handle, state);
        }

		// Convert to string
		::hyve::lang::string Object::tostring() const {
			return ::hyve::toString(this->__handle, 0);
		}

		// Update object
		::hyve::lang::int32 Object::update() const {
			return ::hyve::update(this->__handle);
		}
		::hyve::lang::int32 Object::updateFrom(
			const ::hyve::lang::Object &object) const {
			return ::hyve::updateFrom(this->__handle, object._handle());
		}
		::hyve::lang::int32 Object::updateBegin() const {
			return ::hyve::updateBegin(this->__handle);
		}
		::hyve::lang::int32 Object::updateTry() const {
			return ::hyve::updateTry(this->__handle);
		}
		::hyve::lang::int32 Object::updateEnd() const {
			return ::hyve::updateEnd(this->__handle);
		}
		::hyve::lang::int32 Object::updateEndFrom(
			const ::hyve::lang::Object &object) const {
			return ::hyve::updateEndFrom(this->__handle, object._handle());
		}
		::hyve::lang::int32 Object::updateCancel() const {
			return ::hyve::updateCancel(this->__handle);
		}

		// Read object
		::hyve::lang::int32 Object::readBegin() const {
			return ::hyve::readBegin(this->__handle);
		}
		::hyve::lang::int32 Object::readEnd() const {
			return ::hyve::readEnd(this->__handle);
		}

		// Obtain handle
		::hyve::lang::object Object::_handle() const {
			return this->__handle;
		}

		Object::operator bool() const{
			return this->__handle != NULL;
		}
	}
}
