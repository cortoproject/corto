/* ic_variable.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_ic_LIB
#include "ic.h"

/* ::corto::ic::variable::construct() */
cx_int16 _ic_variable_construct(ic_variable _this) {
/* $begin(::corto::ic::variable::construct) */
    ic_storage(_this)->kind = IC_VARIABLE;
    return ic_storage_construct(ic_storage(_this));
/* $end */
}
