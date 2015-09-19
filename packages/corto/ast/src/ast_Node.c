/* ast_Node.c
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

/* Optimize condition, check if condition can be evaluated at compile-time or can be unwinded */
ast_Expression ast_Node_optimizeCondition(ast_Expression condition, cx_bool *staticResult, cx_bool *inverse) {
    ast_Expression result = NULL;
    ast_ExpressionList conditions = ast_Expression_toList(condition);
    *inverse = FALSE;
    
    /* If condition is an expression list, inserts && between each expression. */
    ast_ExpressionListForeach(conditions, elem) {

        /* If condition is a unary NOT inverse the condition and evaluate lvalue of NOT expression instead */
        if (ast_Node(elem)->kind == Ast_UnaryExpr) {
            if (ast_Unary(elem)->operator == CX_COND_NOT) {
                *inverse = TRUE;
                elem = ast_Unary(elem)->lvalue;
            }
        }
      
        /* If condition is a literal, serialize it to a boolean and resolve condition at compile-time */
        if (elem && (ast_Node(elem)->kind == Ast_LiteralExpr)) {
            if (ast_Expression_serialize(elem, cx_type(cx_bool_o), (cx_word)staticResult)) {
                ast_Parser_error(yparser(), "failed to serialize literal condition expression");
                goto error;
            }
            if (*inverse) {
                *staticResult = !*staticResult;
            }
            elem = NULL;
        }
    
        if (!result) {
            result = elem;
        } else {
            /* If element, add element to AND expression */
            if (elem) {
                result = ast_Expression(ast_BinaryCreate(result, elem, CX_COND_AND));
                ast_Parser_collect(yparser(), result);
                
            /* If element was a literal either ignore it (if result was TRUE) or discard all other
             * expressions if result of literal expression was FALSE. */
            } else if (!*staticResult) {
                result = NULL;
                break;
            }
        }
    }

    ast_Expression_cleanList(conditions);
    
    return result;
error:
    return NULL;
}

/* $end */

/* ::corto::ast::Node::init() */
cx_int16 _ast_Node_init(ast_Node this) {
/* $begin(::corto::ast::Node::init) */
    this->line = yparser()->line;
    this->column = yparser()->column;
    return 0;
/* $end */
}

/* ::corto::ast::Node::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _ast_Node_toIc_v(ast_Node this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::ast::Node::toIc) */
    CX_UNUSED(this);
    CX_UNUSED(program);
    CX_UNUSED(storage);
    CX_UNUSED(stored);
    /* No code is generated for statement */
    return NULL;
/* $end */
}
