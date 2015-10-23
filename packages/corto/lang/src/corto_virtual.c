/* corto_virtual.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "corto.h"

/* ::corto::lang::virtual::init() */
corto_int16 _corto_virtual_init(corto_virtual this) {
/* $begin(::corto::lang::virtual::init) */
    corto_method(this)->_virtual = TRUE;
    return corto_method_init(corto_method(this));
/* $end */
}
