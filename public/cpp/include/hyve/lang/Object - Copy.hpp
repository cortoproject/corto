/*
 * fractal.hpp
 *
 *  Created on: Dec 21, 2012
 *      Author: sander
 */

#ifndef FRACTAL_OBJECT_HPP_
#define FRACTAL_OBJECT_HPP_

#include "fractal.hpp"
#include "fractal/lang/_type.hpp"

namespace fractal {

	namespace lang {

		/* Base-class for fractal C++ proxy objects
		 *
		 *   This class contains convenience functions for object-management in C++.
		 */
		class Object {
		public:
			// Default constructor & destructor
			Object() { this->__handle = NULL; this->owner = FALSE;}
			virtual ~Object();

			// Create proxy from handle
			Object(fractal::lang::object handle, bool owner = TRUE);

			// Create new object
			static fractal::lang::Object* _new(
					::fractal::lang::Type* type);

			// Declare new object in scope of self
			::fractal::lang::Object* declare(
				::fractal::lang::string name,
				::fractal::lang::Type* type);

			// Define object
			::fractal::lang::int16 define();

			// Lookup object
			::fractal::lang::Object* lookup(
				::fractal::lang::string name);

			// Resolve object
			::fractal::lang::Object* resolve(
				::fractal::lang::string name);

			// Get type
			::fractal::lang::Typedef* _typeof();

			// Get refcount
			::fractal::lang::uint32 countof();

			// Get name
			::fractal::lang::string nameof();

			// Get parent
			::fractal::lang::Object* parentof();

			// Get scoped name
			::fractal::lang::string fullname(::fractal::id buffer);

			// Check for attribubte
			::fractal::lang::_bool checkAttr(::fractal::lang::uint8 attr);

			// Check for state
			::fractal::lang::_bool checkState(::fractal::lang::uint8 state);

			// Convert to string
			::fractal::lang::string tostring();

			// Update object
			::fractal::lang::int32 update();
			::fractal::lang::int32 updateFrom(
				::fractal::lang::Object* object);
			::fractal::lang::int32 updateBegin();
			::fractal::lang::int32 updateTry();
			::fractal::lang::int32 updateEnd();
			::fractal::lang::int32 updateEndFrom(
				::fractal::lang::Object* object);
			::fractal::lang::int32 updateCancel();

			// Read object
			::fractal::lang::int32 readBegin();
			::fractal::lang::int32 readEnd();

			::fractal::lang::object _handle();
		protected:
			// Handle to actual object
			::fractal::lang::object __handle;
		private:
			bool owner;
		};
	}
}

#endif /* FRACTAL_HPP_ */
