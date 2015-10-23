/* corto_text.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "corto.h"

/* ::corto::lang::text::init() */
corto_int16 _corto_text_init(corto_text this) {
/* $begin(::corto::lang::text::init) */
    corto_type(this)->hasResources = TRUE;
    corto_primitive(this)->kind = CORTO_TEXT;
    corto_primitive(this)->width = CORTO_WIDTH_WORD;
    return corto_primitive_init((corto_primitive)this);
/* $end */
}
