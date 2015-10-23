/* ic_object.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "ic.h"

/* ::corto::ic::object::construct() */
corto_int16 _ic_object_construct(ic_object this) {
/* $begin(::corto::ic::object::construct) */
    corto_id id;
    ic_storage(this)->kind = IC_OBJECT;
    ic_storage(this)->name = corto_strdup(corto_fullname(this->ptr, id));
    corto_setref(&ic_storage(this)->type, corto_typeof(this->ptr));
    ic_storage(this)->isReference = TRUE;
    return ic_storage_construct(ic_storage(this));
/* $end */
}
