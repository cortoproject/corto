/* Fast_Local.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"
#include "Fast__meta.h"

/* $header() */
#include "Fast__api.h"
/* $end */

/* ::cortex::Fast::Local::construct() */
cx_int16 Fast_Local_construct(Fast_Local _this) {
/* $begin(::cortex::Fast::Local::construct) */
    cx_type t = NULL;

    Fast_Node(_this)->kind = Fast_VariableExpr;
    Fast_Variable(_this)->kind = Fast_LocalExpr;
    Fast_Expression(_this)->type = 
        Fast_Variable(Fast_Object__create(cx_type(Fast_ObjectBase(_this->type)->value)));
    t = Fast_Expression_getType(Fast_Expression(_this));

    Fast_Expression(_this)->isReference = _this->reference | t->reference;

    if (Fast_Expression_getType(Fast_Expression(_this))->reference) {
        Fast_Expression(_this)->forceReference = TRUE;
    }

    return 0;
/* $end */
}

/* ::cortex::Fast::Local::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Local_toIc_v(Fast_Local _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::Local::toIc) */
    cx_ic result;
    CX_UNUSED(storage);
    CX_UNUSED(stored);

    result = (cx_ic)cx_icLocal__create(
                program,
                Fast_Node(_this)->line,
                _this->name,
                Fast_Expression_getType(Fast_Expression(_this)),
               _this->kind == Fast_LocalParameter,
               _this->kind == Fast_LocalReturn,
               FALSE);

    if (Fast_Expression(_this)->isReference) {
        ((cx_icStorage)result)->isReference = TRUE;
    }

    return result;
/* $end */
}
