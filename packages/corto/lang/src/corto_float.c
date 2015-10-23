/* corto_float.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "corto.h"

/* ::corto::lang::float::init() */
corto_int16 _corto_float_init(corto_float this) {
/* $begin(::corto::lang::float::init) */
    corto_primitive(this)->kind = CORTO_FLOAT;
    return corto_primitive_init((corto_primitive)this);
/* $end */
}
