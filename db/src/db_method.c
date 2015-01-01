/* db_method.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* callback ::cortex::lang::procedure::bind(lang::object object) -> ::cortex::lang::method::bind(lang::method object) */
db_int16 db_method_bind(db_method object) {
/* $begin(::cortex::lang::method::bind) */
    db_object parent;

    /* Locate parent class object */
    parent = db_parentof(object);
    if (parent) {
    	/* Bind function */
    	if (db_function_bind(db_function(object))) {
    		goto error;
    	}
    } else {
        db_id id;
        db_error("method::init: '%s' is an orphan.", db_fullname(object, id));
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::method::init(lang::method object) */
db_int16 db_method_init(db_method object) {
/* $begin(::cortex::lang::method::init) */
    db_object parent;

    /* Locate parent class object */
    parent = db_parentof(object);
    if (parent) {
        /* Parent of method must be an abstract type */
        if (db_class_instanceof(db_interface_o, parent)) {
            /* Can't use the db_interface_bindMethod here, since that would introduce a bootstrap issue. */
            if (db_typeof(parent) == db_typedef(db_interface_o)) {
                if (db_interface_bindMethod_v(db_interface(parent), object)) {
                    goto error;
                }
            } else if (db_typeof(parent) == db_typedef(db_struct_o)) {
                if (db_interface_bindMethod_v(db_interface(parent), object)) {
                    goto error;
                }
            } else if (db_typeof(parent) == db_typedef(db_class_o)) {
                if (db_class_bindMethod(db_class(parent), object)) {
                    goto error;
                }
            }
        } else {
            db_id id1, id2;
            db_error("method::init: parent '%s' of method '%s' is not an abstract object.", db_fullname(parent, id1), db_fullname(object, id2));
            goto error;
        }
    } else {
        db_id id;
        db_error("method::init: '%s' is an orphan.", db_fullname(object, id));
        goto error;
    }


    return db_function_init(db_function(object));
error:
	return -1;
/* $end */
}
