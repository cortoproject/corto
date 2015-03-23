/* Fast_Unary.c
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

/* ::cortex::Fast::Unary::construct() */
cx_int16 Fast_Unary_construct(Fast_Unary _this) {
/* $begin(::cortex::Fast::Unary::construct) */
    cx_type lvalueType;

    lvalueType = Fast_Expression_getType(_this->lvalue);
    Fast_Node(_this)->kind = Fast_UnaryExpr;

    if (lvalueType->kind != CX_ITERATOR) {
        if (_this->operator == CX_COND_NOT) {
            Fast_Expression(_this)->type = Fast_Variable(Fast_Object__create(cx_bool_o));
        } else {
            Fast_Expression(_this)->type = Fast_Variable(Fast_Object__create(lvalueType));
        }
    } else {
        if (_this->operator == CX_MUL) {
            cx_type iterType = cx_iterator(lvalueType)->elementType;
            Fast_Expression(_this)->type = Fast_Variable(Fast_Object__create(iterType));
            Fast_Expression(_this)->isReference = TRUE;
        } else {
            Fast_Parser_error(yparser(), "invalid operator for iterator");
            goto error;
        }
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::Unary::hasSideEffects() */
cx_bool Fast_Unary_hasSideEffects_v(Fast_Unary _this) {
/* $begin(::cortex::Fast::Unary::hasSideEffects) */

    return Fast_Expression_hasSideEffects(_this->lvalue);

/* $end */
}

/* ::cortex::Fast::Unary::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Unary_toIc_v(Fast_Unary _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::Unary::toIc) */
    cx_icStorage result;
    cx_ic lvalue;
    cx_icOp op;
    cx_type lvalueType = Fast_Expression_getType(_this->lvalue);
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
        op = cx_icOp__create(
            program, Fast_Node(_this)->line, cx_icOpKindFromOperator(_this->operator),
            (cx_icValue)lvalue, NULL, NULL);
        cx_icProgram_addIc(program, (cx_ic)op);
        result = (cx_icStorage)lvalue;
        break;
    case CX_MUL: {
        /* Create an element with the iterator as base */
        result = 
            (cx_icStorage)cx_icElement__create(
                program, Fast_Node(_this)->line, cx_iterator(lvalueType)->elementType, (cx_icStorage)lvalue, NULL);
        break;
    }
    default:
        op = cx_icOp__create(
            program, Fast_Node(_this)->line, cx_icOpKindFromOperator(_this->operator), 
            (cx_icValue)result, (cx_icValue)lvalue, NULL);
        cx_icProgram_addIc(program, (cx_ic)op);
        break;
    }

    if (!storage) {
        cx_icProgram_accumulatorPop(program, Fast_Node(_this)->line);
    }

    return (cx_ic)result;
/* $end */
}
