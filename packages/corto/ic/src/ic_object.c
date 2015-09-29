/* ic_object.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "ic.h"

/* ::corto::ic::object::construct() */
cx_int16 _ic_object_construct(ic_object this) {
/* $begin(::corto::ic::object::construct) */
    cx_id id;
    ic_storage(this)->kind = IC_OBJECT;
    ic_storage(this)->name = cx_strdup(cx_fullname(this->ptr, id));
    cx_setref(&ic_storage(this)->type, cx_typeof(this->ptr));
    ic_storage(this)->isReference = TRUE;
    return ic_storage_construct(ic_storage(this));
/* $end */
}
