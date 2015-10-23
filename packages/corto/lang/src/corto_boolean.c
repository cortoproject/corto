/* corto_boolean.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "corto.h"

/* ::corto::lang::boolean::init() */
corto_int16 _corto_boolean_init(corto_boolean this) {
/* $begin(::corto::lang::boolean::init) */
    corto_primitive(this)->kind = CORTO_BOOLEAN;
    corto_primitive(this)->width = CORTO_WIDTH_8;
    return corto_primitive_init((corto_primitive)this);
/* $end */
}
