/* cx_constant.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

/* $header() */
#include "cx__enum.h"
#include "cx__bitmask.h"
/* $end */

/* ::cortex::lang::constant::init() */
cx_int16 cx_constant_init(cx_constant *_this) {
/* $begin(::cortex::lang::constant::init) */
    cx_object parent;

    parent = cx_parentof(_this);

    /* Parent must be an enum */
    if (cx_typeof(parent) == cx_type(cx_enum_o)) {
        cx__enum_bindConstant(parent, _this);
    } else if (cx_typeof(parent) == cx_type(cx_bitmask_o)) {
        cx__bitmask_bindConstant(parent, _this);
    } else {
        cx_id id;
        cx_error("::constant::init: parent of constant '%s' is not an enum.", cx_fullname(_this, id));
        goto error;
    }

    return 0;
error:
    return -1;/* $end */
}
