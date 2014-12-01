/* db_callback.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* callback ::hyve::lang::procedure::bind(lang::object object) -> ::hyve::lang::callback::bind(lang::callback object) */
db_int16 db_callback_bind(db_callback object) {
/* $begin(::hyve::lang::callback::bind) */
    db_class delegateClass;
    db_object parent;

    db_assert(object->delegate != NULL, "callback '%s' has <null> for member delegate.", db_nameof(object));

    if (db_function_bind(db_function(object))) {
    	goto error;
    }

    delegateClass = db_class(db_parentof(object->delegate));
    parent = db_parentof(object);
    if (parent) {
        if (db_class_bindCallback(delegateClass, object->delegate, db_type(parent), object)) {
            goto error;
        }
    } else {
        db_id id;
        db_error("callback::bind: '%s' is an orphan.", db_fullname(object, id));
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::lang::callback::init(lang::callback object) */
db_int16 db_callback_init(db_callback object) {
/* $begin(::hyve::lang::callback::init) */

    /* Call function initializer */
    if (db_function_init(db_function(object))) {
        goto error;
    }

    /* This greatly facilitates the bootstrap. */
    if (object->delegate) {
        return db_callback_bind(object);
    }

    return 0;
error:
    return -1;
/* $end */
}
