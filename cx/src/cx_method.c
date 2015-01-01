/* cx_method.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

/* callback ::cortex::lang::procedure::bind(lang::object object) -> ::cortex::lang::method::bind(lang::method object) */
cx_int16 cx_method_bind(cx_method object) {
/* $begin(::cortex::lang::method::bind) */
    cx_object parent;

    /* Locate parent class object */
    parent = cx_parentof(object);
    if (parent) {
    	/* Bind function */
    	if (cx_function_bind(cx_function(object))) {
    		goto error;
    	}
    } else {
        cx_id id;
        cx_error("method::init: '%s' is an orphan.", cx_fullname(object, id));
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::method::init(lang::method object) */
cx_int16 cx_method_init(cx_method object) {
/* $begin(::cortex::lang::method::init) */
    cx_object parent;

    /* Locate parent class object */
    parent = cx_parentof(object);
    if (parent) {
        /* Parent of method must be an abstract type */
        if (cx_class_instanceof(cx_interface_o, parent)) {
            /* Can't use the cx_interface_bindMethod here, since that would introduce a bootstrap issue. */
            if (cx_typeof(parent) == cx_typedef(cx_interface_o)) {
                if (cx_interface_bindMethod_v(cx_interface(parent), object)) {
                    goto error;
                }
            } else if (cx_typeof(parent) == cx_typedef(cx_struct_o)) {
                if (cx_interface_bindMethod_v(cx_interface(parent), object)) {
                    goto error;
                }
            } else if (cx_typeof(parent) == cx_typedef(cx_class_o)) {
                if (cx_class_bindMethod(cx_class(parent), object)) {
                    goto error;
                }
            }
        } else {
            cx_id id1, id2;
            cx_error("method::init: parent '%s' of method '%s' is not an abstract object.", cx_fullname(parent, id1), cx_fullname(object, id2));
            goto error;
        }
    } else {
        cx_id id;
        cx_error("method::init: '%s' is an orphan.", cx_fullname(object, id));
        goto error;
    }


    return cx_function_init(cx_function(object));
error:
	return -1;
/* $end */
}
