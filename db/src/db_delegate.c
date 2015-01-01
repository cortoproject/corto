/* cx_delegate.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "cx__meta.h"

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::delegate::init(lang::delegate object) */
cx_int16 cx_delegate_init(cx_delegate object) {
/* $begin(::cortex::lang::delegate::init) */
    cx_object parent;

    /* Initialize function */
    if (cx_function_init(cx_function(object))) {
        goto error;
    }

    parent = cx_parentof(object);
    if (parent) {
        /* Parent of delegate must be an abstract */
        if (cx_class_instanceof(cx_interface_o, parent)) {
            /* Bind delegate to class */
            if (cx_interface(parent)->kind == DB_CLASS) {
                if (cx_class_bindDelegate(cx_class(parent), object)) {
                    goto error;
                }
            } else {
                cx_id id1, id2;
                cx_error("delegate::init: parent '%s' of method '%s' is not a class object.", cx_fullname(parent, id1), cx_fullname(object, id2));
            }
        }
    } else {
        cx_id id;
        cx_error("delegate::init: '%s' is an orphan", cx_fullname(object, id));
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}
