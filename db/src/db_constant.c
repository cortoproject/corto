/* db_constant.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* $header() */
#include "db__enum.h"
#include "db__bitmask.h"
/* $end */

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::lang::constant::init(constant& object) */
db_int16 db_constant_init(db_constant *object) {
/* $begin(::hyve::lang::constant::init) */
	db_object parent;

	parent = db_parentof(object);

	/* Parent must be an enum */
	if (db_typeof(parent) == db_typedef(db_enum_o)) {
		db__enum_bindConstant(parent, object);
	} else if (db_typeof(parent) == db_typedef(db_bitmask_o)) {
	    db__bitmask_bindConstant(parent, object);
	} else {
		db_id id;
		db_error("::constant::init: parent of constant '%s' is not an enum.", db_fullname(object, id));
		goto error;
	}

	return 0;
error:
	return -1;/* $end */
}
