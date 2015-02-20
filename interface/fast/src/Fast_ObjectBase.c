/* Fast_ObjectBase.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"
#include "Fast__meta.h"

/* ::cortex::Fast::ObjectBase::construct() */
cx_int16 Fast_ObjectBase_construct(Fast_ObjectBase _this) {
/* $begin(::cortex::Fast::ObjectBase::construct) */

    Fast_Variable(_this)->kind = Fast_ObjectExpr;

    return Fast_Variable_construct(Fast_Variable(_this));
/* $end */
}
