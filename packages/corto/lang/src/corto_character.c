/* corto_character.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "corto.h"

/* ::corto::lang::character::init() */
corto_int16 _corto_character_init(corto_character this) {
/* $begin(::corto::lang::character::init) */
    corto_primitive(this)->kind = CORTO_CHARACTER;
    return corto_primitive_init((corto_primitive)this);
/* $end */
}
