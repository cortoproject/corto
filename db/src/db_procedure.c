/* db_procedure.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* $header() */
#include "db_observer.h"
#include "db_function.h"
/* $end */

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::procedure::init(lang::procedure object) */
db_int16 db_procedure_init(db_procedure object) {
/* $begin(::cortex::lang::procedure::init) */

    if (db_interface_init(db_interface(object))) {
    	goto error;
    }

    db_interface(object)->kind = DB_PROCEDURE;
    db_type(object)->reference = TRUE;

    return 0;
error:
	return -1;
/* $end */
}

/* ::cortex::lang::procedure::unbind(lang::object object) */
db_void db_procedure_unbind(db_procedure _this, db_object object) {
/* $begin(::cortex::lang::procedure::unbind) */
    if (_this->kind == DB_OBSERVER){
        db_observer_unbind(object);
    } else {
        db_function_unbind(object);
    }
/* $end */
}
