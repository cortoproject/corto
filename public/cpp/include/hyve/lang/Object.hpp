/*
 * hyve.hpp
 *
 *  Created on: Dec 21, 2012
 *      Author: sander
 */

#ifndef FRACTAL_OBJECT_HPP_
#define FRACTAL_OBJECT_HPP_

#include "hyve.hpp"
#include "hyve/lang/_type.hpp"

namespace hyve {

	namespace lang {

		/* Base-class for hyve C++ proxy objects
		 *
		 *   This class contains convenience functions for object-management in C++.
		 */
		class Object {
		public:
			// Default constructor & destructor
			Object() { this->__handle = NULL; this->owner = FALSE;}
			virtual ~Object();

			// Create proxy from handle
			Object(hyve::lang::object handle, bool owner = TRUE);

			// Create new object
			static hyve::lang::Object _new(
					::hyve::lang::Type &type);

			// Declare new object in scope of self
			::hyve::lang::Object declare(
				::hyve::lang::string name,
				::hyve::lang::Type &type) const;

			// Destruct scoped object
			void destruct() const;

			// Define object
			::hyve::lang::int16 define() const;

			// Lookup object
			::hyve::lang::Object lookup(
				::hyve::lang::string name) const;

			// Resolve object
			::hyve::lang::Object resolve(
				::hyve::lang::string name) const;

			// Get type
			::hyve::lang::Typedef _typeof() const;

			// Get refcount
			::hyve::lang::uint32 countof() const;

			// Get name
			::hyve::lang::string nameof() const;

			// Get parent
			::hyve::lang::Object parentof() const;

			// Get number of childs in scope
			::hyve::lang::uint32 scopeSize() const;

			// Get scoped name
			::hyve::lang::string fullname(::hyve::id buffer) const;

			// Check for attribubte
			::hyve::lang::_bool checkAttr(::hyve::lang::uint8 attr) const;

			// Check for state
			::hyve::lang::_bool checkState(::hyve::lang::uint8 state) const;

			// Convert to string
			::hyve::lang::string tostring() const;

			// Update object
			::hyve::lang::int32 update() const;
			::hyve::lang::int32 updateFrom(
				const ::hyve::lang::Object& object) const;
			::hyve::lang::int32 updateBegin() const;
			::hyve::lang::int32 updateTry() const;
			::hyve::lang::int32 updateEnd() const;
			::hyve::lang::int32 updateEndFrom(
				const ::hyve::lang::Object& object) const;
			::hyve::lang::int32 updateCancel() const;

			// Read object
			::hyve::lang::int32 readBegin() const;
			::hyve::lang::int32 readEnd() const;

			::hyve::lang::object _handle() const;

			explicit operator bool() const;
		protected:
			// Handle to actual object
			::hyve::lang::object __handle;
		private:
			bool owner;
		};
	}
}

#endif /* FRACTAL_HPP_ */
