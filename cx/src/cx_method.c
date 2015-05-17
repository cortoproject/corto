/* cx_method.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* ::cortex::lang::method::bind() */
cx_int16 cx_method_bind(cx_method _this) {
/* $begin(::cortex::lang::method::bind) */
    
    /* Bind function */
    if (cx_function_bind(cx_function(_this))) {
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::lang::method::init() */
cx_int16 cx_method_init(cx_method _this) {
/* $begin(::cortex::lang::method::init) */
    cx_object parent;
    
    /* Locate parent class object */
    parent = cx_parentof(_this);

    /* Parent of method must be an interface type */
    if (cx_class_instanceof(cx_interface_o, parent)) {
        /* Can't use the cx_interface_bindMethod here, since that would introduce a bootstrap issue. */
        if (cx_typeof(parent) == cx_type(cx_interface_o)) {
            if (cx_interface_bindMethod(cx_interface(parent), _this)) {
                goto error;
            }
        } else if (cx_typeof(parent) == cx_type(cx_struct_o)) {
            if (cx_interface_bindMethod(cx_interface(parent), _this)) {
                goto error;
            }
        } else if (cx_typeof(parent) == cx_type(cx_class_o)) {
            if (cx_interface_bindMethod(cx_interface(parent), _this)) {
                goto error;
            }
        }
    }

    return cx_function_init(cx_function(_this));
error:
    return -1;
/* $end */
}
