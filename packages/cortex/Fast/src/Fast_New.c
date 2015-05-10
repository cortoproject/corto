/* Fast_New.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"

/* $header() */
#include "Fast__private.h"
/* $end */

/* ::cortex::Fast::New::construct() */
cx_int16 Fast_New_construct(Fast_New _this) {
/* $begin(::cortex::Fast::New::construct) */

    Fast_Node(_this)->kind = Fast_NewExpr;
    cx_set(&Fast_Expression(_this)->type, _this->type);
    Fast_Expression(_this)->isReference = TRUE;

    return 0;
/* $end */
}

/* ::cortex::Fast::New::hasSideEffects() */
cx_bool Fast_New_hasSideEffects_v(Fast_New _this) {
/* $begin(::cortex::Fast::New::hasSideEffects) */
    CX_UNUSED(_this);
    return TRUE;
/* $end */
}

/* ::cortex::Fast::New::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_New_toIc_v(Fast_New _this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::cortex::Fast::New::toIc) */
    ic_node type, attrs, result;
    CX_UNUSED(stored);

    if (storage) {
        result = (ic_node)storage;
    } else {
        result = (ic_node)ic_program_pushAccumulator(program, Fast_Expression_getType(Fast_Expression(_this)), TRUE, FALSE);
    }

    type = (ic_node)ic_object__create(Fast_Expression(_this)->type);
    if (_this->attributes) {
        attrs = Fast_Node_toIc(Fast_Node(_this->attributes), program, NULL, TRUE);
    } else {
        attrs = NULL;
    }

    IC_3(program, Fast_Node(_this)->line, ic_new, 
        result, type, attrs, IC_DEREF_ADDRESS, IC_DEREF_ADDRESS, IC_DEREF_VALUE)

    return result;
/* $end */
}
