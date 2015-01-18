/* Fast_UnaryExpr.c
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

/* ::cortex::Fast::UnaryExpr::construct() */
cx_int16 Fast_UnaryExpr_construct(Fast_UnaryExpr _this) {
/* $begin(::cortex::Fast::UnaryExpr::construct) */
    cx_type lvalueType;

    lvalueType = Fast_Expression_getType(_this->lvalue);
    Fast_Node(_this)->kind = FAST_Unary;

    if (_this->operator == CX_COND_NOT) {
        Fast_Expression(_this)->type = Fast_Variable(Fast_Object__create(cx_bool_o));
    } else {
        Fast_Expression(_this)->type = Fast_Variable(Fast_Object__create(lvalueType));
    }

    return 0;
/* $end */
}

/* ::cortex::Fast::UnaryExpr::hasSideEffects() */
cx_bool Fast_UnaryExpr_hasSideEffects_v(Fast_UnaryExpr _this) {
/* $begin(::cortex::Fast::UnaryExpr::hasSideEffects) */

    return Fast_Expression_hasSideEffects(_this->lvalue);

/* $end */
}

/* ::cortex::Fast::UnaryExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_UnaryExpr_toIc_v(Fast_UnaryExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::UnaryExpr::toIc) */
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

    switch(_this->operator) {
    case CX_INC:
    case CX_DEC:
        op = cx_icOp__create(program, Fast_Node(_this)->line, cx_icOpKindFromOperator(_this->operator), (cx_icValue)lvalue, NULL, NULL);
        cx_icProgram_addIc(program, (cx_ic)op);
        result = (cx_icStorage)lvalue;
        break;
    default:
        op = cx_icOp__create(program, Fast_Node(_this)->line, cx_icOpKindFromOperator(_this->operator), (cx_icValue)result, (cx_icValue)lvalue, NULL);
        cx_icProgram_addIc(program, (cx_ic)op);
        break;
    }

    if (!storage) {
        cx_icProgram_accumulatorPop(program, Fast_Node(_this)->line);
    }

    return (cx_ic)result;
/* $end */
}
