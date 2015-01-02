/* Fast_PostfixExpr.c
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
#include "Fast_Parser.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
/* $end */

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::Fast::PostfixExpr::construct(Fast::PostfixExpr object) */
cx_int16 Fast_PostfixExpr_construct(Fast_PostfixExpr object) {
/* $begin(::cortex::Fast::PostfixExpr::construct) */
    cx_type lvalueType;

    Fast_Node(object)->kind = FAST_Postfix;
    lvalueType = Fast_Expression_getType(object->lvalue);
    Fast_Expression(object)->type = Fast_Variable(Fast_Object__create(lvalueType));

    return 0;
/* $end */
}

/* ::cortex::Fast::PostfixExpr::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
cx_ic Fast_PostfixExpr_toIc_v(Fast_PostfixExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::PostfixExpr::toIc) */
    cx_icStorage result;
    cx_ic lvalue;
    cx_icOp op;
    CX_UNUSED(stored);

    if (storage) {
        result = storage;
    } else {
        result = (cx_icStorage)cx_icProgram_accumulatorPush(
            program, 
            Fast_Node(_this)->line, 
            Fast_Expression_getType(Fast_Expression(_this)),
            Fast_Expression(_this)->isReference);
    }

    lvalue = Fast_Node_toIc(Fast_Node(_this->lvalue), program, result, TRUE);

    op = cx_icOp__create(program, Fast_Node(_this)->line, cx_icOpKindFromOperator(_this->operator), (cx_icValue)lvalue, NULL, NULL);
    cx_icProgram_addIc(program, (cx_ic)op);

    if (!storage) {
        cx_icProgram_accumulatorPop(program, Fast_Node(_this)->line);
    }

    return (cx_ic)lvalue;
/* $end */
}
