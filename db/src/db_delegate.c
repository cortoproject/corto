/* db_delegate.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::lang::delegate::init(lang::delegate object) */
db_int16 db_delegate_init(db_delegate object) {
/* $begin(::hyve::lang::delegate::init) */
    db_object parent;

    /* Initialize function */
    if (db_function_init(db_function(object))) {
        goto error;
    }

    parent = db_parentof(object);
    if (parent) {
        /* Parent of delegate must be an abstract */
        if (db_class_instanceof(db_interface_o, parent)) {
            /* Bind delegate to class */
            if (db_interface(parent)->kind == DB_CLASS) {
                if (db_class_bindDelegate(db_class(parent), object)) {
                    goto error;
                }
            } else {
                db_id id1, id2;
                db_error("delegate::init: parent '%s' of method '%s' is not a class object.", db_fullname(parent, id1), db_fullname(object, id2));
            }
        }
    } else {
        db_id id;
        db_error("delegate::init: '%s' is an orphan", db_fullname(object, id));
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}
