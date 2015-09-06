/* Fast_Template.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_Fast_LIB
#include "Fast.h"

/* ::corto::Fast::Template::construct() */
cx_int16 _Fast_Template_construct(Fast_Template this) {
/* $begin(::corto::Fast::Template::construct) */

    if (Fast_Local_construct(Fast_Local(this))) {
        goto error;
    } else {
        Fast_Storage(this)->kind = Fast_TemplateStorage;
    }

    return Fast_Storage_construct(Fast_Storage(this));
error:
    return -1;
/* $end */
}
