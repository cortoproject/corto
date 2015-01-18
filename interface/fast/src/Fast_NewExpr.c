/* Fast_NewExpr.c
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
#include "Fast_Parser.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
/* $end */

/* ::cortex::Fast::NewExpr::construct() */
cx_int16 Fast_NewExpr_construct(Fast_NewExpr _this) {
/* $begin(::cortex::Fast::NewExpr::construct) */

    Fast_Node(_this)->kind = FAST_New;
    Fast_Expression(_this)->type = Fast_Variable(_this->type);
    cx_keep_ext(_this, _this->type, "Set type of Fast::NewExpr");

    return 0;
/* $end */
}

/* ::cortex::Fast::NewExpr::hasSideEffects() */
cx_bool Fast_NewExpr_hasSideEffects_v(Fast_NewExpr _this) {
/* $begin(::cortex::Fast::NewExpr::hasSideEffects) */
    CX_UNUSED(_this);
    return TRUE;
/* $end */
}

/* ::cortex::Fast::NewExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_NewExpr_toIc_v(Fast_NewExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::NewExpr::toIc) */
    cx_ic type, attrs, result;
    cx_icOp op;
    CX_UNUSED(stored);

    if (storage) {
        result = (cx_ic)storage;
    } else {
        result = (cx_ic)cx_icProgram_accumulatorPush(program, Fast_Node(_this)->line, Fast_Expression_getType(Fast_Expression(_this)), TRUE);
    }

    type = Fast_Node_toIc(Fast_Node(_this->type), program, NULL, TRUE);
    if (_this->attributes) {
        attrs = Fast_Node_toIc(Fast_Node(_this->attributes), program, NULL, TRUE);
    } else {
        attrs = NULL;
    }

    op = cx_icOp__create(program, Fast_Node(_this)->line, CX_IC_NEW, (cx_icValue)result, (cx_icValue)type, (cx_icValue)attrs);
    op->s1Deref = CX_IC_DEREF_ADDRESS;
    cx_icProgram_addIc(program, (cx_ic)op);

    return result;
/* $end */
}
