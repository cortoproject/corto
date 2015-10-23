/* corto_constant.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* $header() */
#include "corto__enum.h"
#include "corto__bitmask.h"
/* $end */

/* ::corto::lang::constant::init() */
corto_int16 _corto_constant_init(corto_constant *this) {
/* $begin(::corto::lang::constant::init) */
    corto_object parent;

    parent = corto_parentof(this);

    /* Parent must be an enum */
    if (corto_typeof(parent) == corto_type(corto_enum_o)) {
        corto__enum_bindConstant(parent, this);
    } else if (corto_typeof(parent) == corto_type(corto_bitmask_o)) {
        corto__bitmask_bindConstant(parent, this);
    } else {
        corto_id id;
        corto_error("::constant::init: parent of constant '%s' is not an enum.", corto_fullname(this, id));
        goto error;
    }

    return 0;
error:
    return -1;/* $end */
}
