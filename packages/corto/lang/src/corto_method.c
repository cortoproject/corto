/* corto_method.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* ::corto::lang::method::bind() */
corto_int16 _corto_method_bind(corto_method this) {
/* $begin(::corto::lang::method::bind) */
    
    /* Bind function */
    if (corto_function_bind(corto_function(this))) {
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::lang::method::init() */
corto_int16 _corto_method_init(corto_method this) {
/* $begin(::corto::lang::method::init) */
    corto_object parent;
    
    /* Locate parent class object */
    parent = corto_parentof(this);

    /* Parent of method must be an interface type */
    if (corto_class_instanceof(corto_interface_o, parent)) {
        if (corto_interface_bindMethod(corto_interface(parent), this)) {
            goto error;
        }
    }

    return corto_function_init(corto_function(this));
error:
    return -1;
/* $end */
}
