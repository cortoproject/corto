/* cx_procedure.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* $header() */
#include "cx_observer.h"
#include "cx_function.h"
/* $end */

/* ::cortex::lang::procedure::init() */
cx_int16 cx_procedure_init(cx_procedure _this) {
/* $begin(::cortex::lang::procedure::init) */

    if (cx_interface_init(cx_interface(_this))) {
        goto error;
    }

    cx_interface(_this)->kind = CX_PROCEDURE;
    cx_type(_this)->reference = TRUE;

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::lang::procedure::unbind(function object) */
cx_void cx_procedure_unbind(cx_procedure _this, cx_function object) {
/* $begin(::cortex::lang::procedure::unbind) */
    if (_this->kind == CX_OBSERVER){
        cx_observer_unbind(cx_observer(object));
    } else {
        cx_function_unbind(object);
    }
/* $end */
}
