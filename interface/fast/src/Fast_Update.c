/* Fast_Update.c
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
#include "Fast.h"
#include "Fast_Expression.h"
#include "Fast_Block.h"
#include "cx_ic.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
/* $end */

/* ::cortex::Fast::Update::construct() */
cx_int16 Fast_Update_construct(Fast_Update _this) {
/* $begin(::cortex::Fast::Update::construct) */
    cx_type t;
    cx_iter exprIter;
    Fast_Expression expr;

    Fast_Node(_this)->kind = FAST_Update;

    exprIter = cx_llIter(_this->exprList);
    while(cx_iterHasNext(&exprIter)) {
        expr = cx_iterNext(&exprIter);
        t = Fast_Expression_getType(expr);
        if (!t->reference) {
            if (!expr->isReference) {
                Fast_Parser_error(yparser(), "one or more expressions in the update statement are not of a reference type");
                goto error;
            }
        }
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::Update::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Update_toIc_v(Fast_Update _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::Update::toIc) */
    cx_ic expr, from = NULL;
    cx_iter exprIter;
    cx_icOp op;
    CX_UNUSED(storage);
    CX_UNUSED(stored);

    /* Evaluate expression */
    if (_this->from) {
        from = Fast_Node_toIc(Fast_Node(_this->from), program, NULL, TRUE);
    }

    /* Add update statement for each expression in exprList */
    exprIter = cx_llIter(_this->exprList);
    while(cx_iterHasNext(&exprIter)) {
        Fast_Expression fastExpr = cx_iterNext(&exprIter);
        expr = Fast_Node_toIc(Fast_Node(fastExpr), program, NULL, TRUE);
        if (!_this->block) {
            op = cx_icOp__create(program, Fast_Node(_this)->line, CX_IC_UPDATE, (cx_icValue)expr, (cx_icValue)from, NULL);
            cx_icProgram_addIc(program, (cx_ic)op);
            op->s1Deref = CX_IC_DEREF_ADDRESS;

        } else {
            op = cx_icOp__create(program, Fast_Node(_this)->line, CX_IC_UPDATEBEGIN, (cx_icValue)expr, NULL, NULL);
            cx_icProgram_addIc(program, (cx_ic)op);
            op->s1Deref = CX_IC_DEREF_ADDRESS;
        }
    }

    if (_this->block) {
        /* Translate block to ic */
        Fast_Block_toIc(_this->block, program, NULL, FALSE);

        exprIter = cx_llIter(_this->exprList);
        while(cx_iterHasNext(&exprIter)) {
            Fast_Expression fastExpr = cx_iterNext(&exprIter);
            expr = Fast_Node_toIc(Fast_Node(fastExpr), program, NULL, TRUE);
            op = cx_icOp__create(program, Fast_Node(_this)->line, CX_IC_UPDATEEND, (cx_icValue)expr, (cx_icValue)from, NULL);
            cx_icProgram_addIc(program, (cx_ic)op);
            op->s1Deref = CX_IC_DEREF_ADDRESS;
        }
    }

    return NULL;
/* $end */
}
