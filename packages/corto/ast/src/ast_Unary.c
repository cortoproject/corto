/* ast_Unary.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_ast_LIB
#include "ast.h"

/* $header() */
#include "ast__private.h"
/* $end */

/* ::corto::ast::Unary::construct() */
cx_int16 _ast_Unary_construct(ast_Unary this) {
/* $begin(::corto::ast::Unary::construct) */
    cx_type lvalueType;

    lvalueType = ast_Expression_getType(this->lvalue);
    ast_Node(this)->kind = Ast_UnaryExpr;

    if (lvalueType->kind != CX_ITERATOR) {
        if (this->operator == CX_COND_NOT) {
            cx_setref(&ast_Expression(this)->type, cx_bool_o);
        } else {
            cx_setref(&ast_Expression(this)->type, lvalueType);
        }
    } else {
        if (this->operator == CX_MUL) {
            cx_type iterType = cx_iterator(lvalueType)->elementType;
            cx_setref(&ast_Expression(this)->type, iterType);
            ast_Expression(this)->isReference = TRUE;
        } else {
            ast_Parser_error(yparser(), "invalid operator for iterator");
            goto error;
        }
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::ast::Unary::hasReturnedResource() */
cx_bool _ast_Unary_hasReturnedResource_v(ast_Unary this) {
/* $begin(::corto::ast::Unary::hasReturnedResource) */
    return ast_Expression_hasReturnedResource(this->lvalue);
/* $end */
}

/* ::corto::ast::Unary::hasSideEffects() */
cx_bool _ast_Unary_hasSideEffects_v(ast_Unary this) {
/* $begin(::corto::ast::Unary::hasSideEffects) */
    return ast_Expression_hasSideEffects(this->lvalue);
/* $end */
}

/* ::corto::ast::Unary::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _ast_Unary_toIc_v(ast_Unary this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::ast::Unary::toIc) */
    ic_storage result;
    ic_node lvalue;
    CX_UNUSED(stored);

    if (storage) {
        result = storage;
    } else {
        result = (ic_storage)ic_program_pushAccumulator(
            program,  
            ast_Expression_getType(ast_Expression(this)),
            ast_Expression(this)->isReference,
            FALSE);
    }

    lvalue = ast_Node_toIc(ast_Node(this->lvalue), program, result, TRUE);

    switch(this->operator) {
    case CX_INC:
    case CX_DEC:
        IC_1(program, ast_Node(this)->line, ic_opKindFromOperator(this->operator), lvalue, IC_DEREF_VALUE);
        result = ic_storage(lvalue);
        break;
    case CX_MUL: {
        /* Create an element with the iterator as base */
        result = (ic_storage)ic_elementCreate(ic_storage(lvalue), NULL);
        break;
    }
    default:
        IC_3(program, ast_Node(this)->line, ic_opKindFromOperator(this->operator), result, lvalue, NULL,
            IC_DEREF_VALUE, IC_DEREF_VALUE, IC_DEREF_VALUE);
        break;
    }

    if (!storage) {
        ic_program_popAccumulator(program);
    }

    return (ic_node)result;
/* $end */
}
