/* ic_object.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "ic.h"

/* ::cortex::ic::object::construct() */
cx_int16 ic_object_construct(ic_object _this) {
/* $begin(::cortex::ic::object::construct) */
    ic_storage(_this)->kind = IC_OBJECT;
    ic_storage(_this)->name = cx_strdup(cx_nameof(_this->ptr));
    cx_set(&ic_storage(_this)->type, cx_typeof(_this->ptr));
    ic_storage(_this)->isReference = TRUE;
    return ic_storage_construct(ic_storage(_this));
/* $end */
}
