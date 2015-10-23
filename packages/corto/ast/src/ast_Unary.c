/* ast_Unary.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "ast.h"

/* $header() */
#include "ast__private.h"
/* $end */

/* ::corto::ast::Unary::construct() */
corto_int16 _ast_Unary_construct(ast_Unary this) {
/* $begin(::corto::ast::Unary::construct) */
    corto_type lvalueType;

    lvalueType = ast_Expression_getType(this->lvalue);
    ast_Node(this)->kind = Ast_UnaryExpr;

    if (lvalueType->kind != CORTO_ITERATOR) {
        if (this->_operator == CORTO_COND_NOT) {
            corto_setref(&ast_Expression(this)->type, corto_bool_o);
        } else {
            corto_setref(&ast_Expression(this)->type, lvalueType);
        }
    } else {
        if (this->_operator == CORTO_MUL) {
            corto_type iterType = corto_iterator(lvalueType)->elementType;
            corto_setref(&ast_Expression(this)->type, iterType);
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
corto_bool _ast_Unary_hasReturnedResource_v(ast_Unary this) {
/* $begin(::corto::ast::Unary::hasReturnedResource) */
    return ast_Expression_hasReturnedResource(this->lvalue);
/* $end */
}

/* ::corto::ast::Unary::hasSideEffects() */
corto_bool _ast_Unary_hasSideEffects_v(ast_Unary this) {
/* $begin(::corto::ast::Unary::hasSideEffects) */
    return ast_Expression_hasSideEffects(this->lvalue);
/* $end */
}

/* ::corto::ast::Unary::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _ast_Unary_toIc_v(ast_Unary this, ic_program program, ic_storage storage, corto_bool stored) {
/* $begin(::corto::ast::Unary::toIc) */
    ic_storage result;
    ic_node lvalue;
    CORTO_UNUSED(stored);

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

    switch(this->_operator) {
    case CORTO_INC:
    case CORTO_DEC:
        IC_1(program, ast_Node(this)->line, ic_opKindFromOperator(this->_operator), lvalue, IC_DEREF_VALUE);
        result = ic_storage(lvalue);
        break;
    case CORTO_MUL: {
        /* Create an element with the iterator as base */
        result = (ic_storage)ic_elementCreate(ic_storage(lvalue), NULL);
        break;
    }
    default:
        IC_3(program, ast_Node(this)->line, ic_opKindFromOperator(this->_operator), result, lvalue, NULL,
            IC_DEREF_VALUE, IC_DEREF_VALUE, IC_DEREF_VALUE);
        break;
    }

    if (!storage) {
        ic_program_popAccumulator(program);
    }

    return (ic_node)result;
/* $end */
}
