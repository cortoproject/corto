/* Fast_Unary.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_Fast_LIB
#include "Fast.h"

/* $header() */
#include "Fast__private.h"
/* $end */

/* ::corto::Fast::Unary::construct() */
cx_int16 _Fast_Unary_construct(Fast_Unary this) {
/* $begin(::corto::Fast::Unary::construct) */
    cx_type lvalueType;

    lvalueType = Fast_Expression_getType(this->lvalue);
    Fast_Node(this)->kind = Fast_UnaryExpr;

    if (lvalueType->kind != CX_ITERATOR) {
        if (this->operator == CX_COND_NOT) {
            cx_setref(&Fast_Expression(this)->type, cx_bool_o);
        } else {
            cx_setref(&Fast_Expression(this)->type, lvalueType);
        }
    } else {
        if (this->operator == CX_MUL) {
            cx_type iterType = cx_iterator(lvalueType)->elementType;
            cx_setref(&Fast_Expression(this)->type, iterType);
            Fast_Expression(this)->isReference = TRUE;
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

/* ::corto::Fast::Unary::hasReturnedResource() */
cx_bool _Fast_Unary_hasReturnedResource_v(Fast_Unary this) {
/* $begin(::corto::Fast::Unary::hasReturnedResource) */
    return Fast_Expression_hasReturnedResource(this->lvalue);
/* $end */
}

/* ::corto::Fast::Unary::hasSideEffects() */
cx_bool _Fast_Unary_hasSideEffects_v(Fast_Unary this) {
/* $begin(::corto::Fast::Unary::hasSideEffects) */
    return Fast_Expression_hasSideEffects(this->lvalue);
/* $end */
}

/* ::corto::Fast::Unary::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Unary_toIc_v(Fast_Unary this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::Fast::Unary::toIc) */
    ic_storage result;
    ic_node lvalue;
    CX_UNUSED(stored);

    if (storage) {
        result = storage;
    } else {
        result = (ic_storage)ic_program_pushAccumulator(
            program,  
            Fast_Expression_getType(Fast_Expression(this)),
            Fast_Expression(this)->isReference,
            FALSE);
    }

    lvalue = Fast_Node_toIc(Fast_Node(this->lvalue), program, result, TRUE);

    switch(this->operator) {
    case CX_INC:
    case CX_DEC:
        IC_1(program, Fast_Node(this)->line, ic_opKindFromOperator(this->operator), lvalue, IC_DEREF_VALUE);
        result = ic_storage(lvalue);
        break;
    case CX_MUL: {
        /* Create an element with the iterator as base */
        result = (ic_storage)ic_elementCreate(ic_storage(lvalue), NULL);
        break;
    }
    default:
        IC_3(program, Fast_Node(this)->line, ic_opKindFromOperator(this->operator), result, lvalue, NULL,
            IC_DEREF_VALUE, IC_DEREF_VALUE, IC_DEREF_VALUE);
        break;
    }

    if (!storage) {
        ic_program_popAccumulator(program);
    }

    return (ic_node)result;
/* $end */
}
