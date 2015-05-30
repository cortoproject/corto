/* Fast_Unary.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"

/* $header() */
#include "Fast__private.h"
/* $end */

/* ::cortex::Fast::Unary::construct() */
cx_int16 Fast_Unary_construct(Fast_Unary _this) {
/* $begin(::cortex::Fast::Unary::construct) */
    cx_type lvalueType;

    lvalueType = Fast_Expression_getType(_this->lvalue);
    Fast_Node(_this)->kind = Fast_UnaryExpr;

    if (lvalueType->kind != CX_ITERATOR) {
        if (_this->operator == CX_COND_NOT) {
            cx_set(&Fast_Expression(_this)->type, cx_bool_o);
        } else {
            cx_set(&Fast_Expression(_this)->type, lvalueType);
        }
    } else {
        if (_this->operator == CX_MUL) {
            cx_type iterType = cx_iterator(lvalueType)->elementType;
            cx_set(&Fast_Expression(_this)->type, iterType);
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

/* ::cortex::Fast::Unary::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Unary_toIc_v(Fast_Unary _this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::cortex::Fast::Unary::toIc) */
    ic_storage result;
    ic_node lvalue;
    CX_UNUSED(stored);

    if (storage) {
        result = storage;
    } else {
        result = (ic_storage)ic_program_pushAccumulator(
            program,  
            Fast_Expression_getType(Fast_Expression(_this)),
            Fast_Expression(_this)->isReference,
            FALSE);
    }

    lvalue = Fast_Node_toIc(Fast_Node(_this->lvalue), program, result, TRUE);

    switch(_this->operator) {
    case CX_INC:
    case CX_DEC:
        IC_1(program, Fast_Node(_this)->line, ic_opKindFromOperator(_this->operator), lvalue, IC_DEREF_VALUE);
        result = ic_storage(lvalue);
        break;
    case CX_MUL: {
        /* Create an element with the iterator as base */
        result = (ic_storage)ic_element__create(ic_storage(lvalue), NULL);
        break;
    }
    default:
        IC_3(program, Fast_Node(_this)->line, ic_opKindFromOperator(_this->operator), result, lvalue, NULL,
            IC_DEREF_VALUE, IC_DEREF_VALUE, IC_DEREF_VALUE);
        break;
    }

    if (!storage) {
        ic_program_popAccumulator(program);
    }

    return (ic_node)result;
/* $end */
}
