/* db_metaprocedure.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* $header() */
db_int16 db_type_bindMetaprocedure(db_type _this, db_metaprocedure procedure);
/* $end */

/* callback ::hyve::lang::procedure::bind(lang::object object) -> ::hyve::lang::metaprocedure::bind(lang::metaprocedure object) */
db_int16 db_metaprocedure_bind(db_metaprocedure object) {
/* $begin(::hyve::lang::metaprocedure::bind) */
	db_object parent;

	parent = db_parentof(object);
	if (db_instanceof(db_typedef(db_type_o), parent)) {
		if (db_type_bindMetaprocedure(db_type(parent), object)) {
			goto error;
		}
	} else {
		db_id id, id2;
		db_error("metaoperation '%s' not defined in scope of '%s' which is not a type", db_fullname(object, id), db_fullname(parent, id2));
		goto error;
	}

    return db_function_bind(db_function(object));
error:
	return -1;
/* $end */
}
