/* corto_procedure.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* $header() */
#include "corto_observer.h"
#include "corto_function.h"
/* $end */

/* ::corto::lang::procedure::init() */
corto_int16 _corto_procedure_init(corto_procedure this) {
/* $begin(::corto::lang::procedure::init) */

    if (corto_interface_init(corto_interface(this))) {
        goto error;
    }

    corto_interface(this)->kind = CORTO_PROCEDURE;
    corto_type(this)->reference = TRUE;

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::lang::procedure::unbind(function object) */
corto_void _corto_procedure_unbind(corto_procedure this, corto_function object) {
/* $begin(::corto::lang::procedure::unbind) */
    if (this->kind == CORTO_OBSERVER){
        corto_observer_unbind(corto_observer(object));
    } else {
        corto_function_unbind(object);
    }
/* $end */
}
