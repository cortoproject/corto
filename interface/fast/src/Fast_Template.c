/* Fast_Template.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"
#include "Fast__meta.h"

/* ::cortex::Fast::Template::construct() */
cx_int16 Fast_Template_construct(Fast_Template _this) {
/* $begin(::cortex::Fast::Template::construct) */

    if (Fast_Local_construct(Fast_Local(_this))) {
        goto error;
    } else {
        Fast_Variable(_this)->kind = Fast_TemplateExpr;
    }

    return Fast_Variable_construct(Fast_Variable(_this));
error:
    return -1;
/* $end */
}
