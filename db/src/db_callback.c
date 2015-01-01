/* cx_callback.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "cx__meta.h"

/* callback ::cortex::lang::procedure::bind(lang::object object) -> ::cortex::lang::callback::bind(lang::callback object) */
cx_int16 cx_callback_bind(cx_callback object) {
/* $begin(::cortex::lang::callback::bind) */
    cx_class delegateClass;
    cx_object parent;

    cx_assert(object->delegate != NULL, "callback '%s' has <null> for member delegate.", cx_nameof(object));

    if (cx_function_bind(cx_function(object))) {
    	goto error;
    }

    delegateClass = cx_class(cx_parentof(object->delegate));
    parent = cx_parentof(object);
    if (parent) {
        if (cx_class_bindCallback(delegateClass, object->delegate, cx_type(parent), object)) {
            goto error;
        }
    } else {
        cx_id id;
        cx_error("callback::bind: '%s' is an orphan.", cx_fullname(object, id));
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::callback::init(lang::callback object) */
cx_int16 cx_callback_init(cx_callback object) {
/* $begin(::cortex::lang::callback::init) */

    /* Call function initializer */
    if (cx_function_init(cx_function(object))) {
        goto error;
    }

    /* This greatly facilitates the bootstrap. */
    if (object->delegate) {
        return cx_callback_bind(object);
    }

    return 0;
error:
    return -1;
/* $end */
}
