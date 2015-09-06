/* cx_procedure.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* $header() */
#include "cx_observer.h"
#include "cx_function.h"
/* $end */

/* ::corto::lang::procedure::init() */
cx_int16 _cx_procedure_init(cx_procedure this) {
/* $begin(::corto::lang::procedure::init) */

    if (cx_interface_init(cx_interface(this))) {
        goto error;
    }

    cx_interface(this)->kind = CX_PROCEDURE;
    cx_type(this)->reference = TRUE;

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::lang::procedure::unbind(function object) */
cx_void _cx_procedure_unbind(cx_procedure this, cx_function object) {
/* $begin(::corto::lang::procedure::unbind) */
    if (this->kind == CX_OBSERVER){
        cx_observer_unbind(cx_observer(object));
    } else {
        cx_function_unbind(object);
    }
/* $end */
}
