/* ast_PostFix.c
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

/* ::corto::ast::PostFix::construct() */
cx_int16 _ast_PostFix_construct(ast_PostFix this) {
/* $begin(::corto::ast::PostFix::construct) */
    cx_type lvalueType = ast_Expression_getType(this->lvalue);

    /* Validate whether operation is allowed */
    if (lvalueType->reference) {
        cx_id id;
        ast_Parser_error(
            yparser(), "invalid operator for reference type '%s'", ast_Parser_id(lvalueType, id));
        goto error;
    } else {
        cx_id id;
        switch(lvalueType->kind) {

        case CX_PRIMITIVE:
            switch(cx_primitive(lvalueType)->kind) {
            case CX_INTEGER:
            case CX_UINTEGER:
            case CX_BINARY:
            case CX_CHARACTER:
            case CX_FLOAT:
                break;
            default:
                ast_Parser_error(
                    yparser(), "invalid operator for type '%s'", ast_Parser_id(lvalueType, id));
                goto error;
                break;       
            }
            cx_setref(&ast_Expression(this)->type, lvalueType);
            break;

        case CX_ITERATOR:
            if (this->operator == CX_INC) {
                /* The result of an expression that increments an iterator is a boolean */
                cx_setref(&ast_Expression(this)->type, cx_bool_o);
            } else {
                ast_Parser_error(yparser(), "invalid operator for iterator");
                goto error;
            }
            break;

        default:
            ast_Parser_error(
                yparser(), "invalid operator for type '%s'", ast_Parser_id(lvalueType, id));
            goto error;
            break;
        }
    }

    ast_Node(this)->kind = Ast_PostfixExpr;
    
    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::ast::PostFix::hasReturnedResource() */
cx_bool _ast_PostFix_hasReturnedResource_v(ast_PostFix this) {
/* $begin(::corto::ast::PostFix::hasReturnedResource) */
    return ast_Expression_hasReturnedResource(this->lvalue);
/* $end */
}

/* ::corto::ast::PostFix::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _ast_PostFix_toIc_v(ast_PostFix this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::ast::PostFix::toIc) */
    ic_storage result;
    ic_node lvalue;
    cx_type lvalueType = ast_Expression_getType(this->lvalue);
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
    IC_3(program, ast_Node(this)->line, ic_opKindFromOperator(this->operator), lvalue, ic_node(result), NULL,
            IC_DEREF_VALUE, IC_DEREF_VALUE, IC_DEREF_VALUE);

    if (!storage) {
        ic_program_popAccumulator(program);
    } else if ((lvalueType->kind == CX_ITERATOR) && (this->operator == CX_INC)) {
        lvalue = (ic_node)storage;
    }

    return (ic_node)lvalue;
/* $end */
}
