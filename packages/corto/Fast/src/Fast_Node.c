/* Fast_Node.c
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

/* Optimize condition, check if condition can be evaluated at compile-time or can be unwinded */
Fast_Expression Fast_Node_optimizeCondition(Fast_Expression condition, cx_bool *staticResult, cx_bool *inverse) {
    Fast_Expression result = NULL;
    Fast_ExpressionList conditions = Fast_Expression_toList(condition);
    *inverse = FALSE;
    
    /* If condition is an expression list, inserts && between each expression. */
    Fast_ExpressionListForeach(conditions, elem)

        /* If condition is a unary NOT inverse the condition and evaluate lvalue of NOT expression instead */
        if (Fast_Node(elem)->kind == Fast_UnaryExpr) {
            if (Fast_Unary(elem)->operator == CX_COND_NOT) {
                *inverse = TRUE;
                elem = Fast_Unary(elem)->lvalue;
            }
        }
      
        /* If condition is a literal, serialize it to a boolean and resolve condition at compile-time */
        if (elem && (Fast_Node(elem)->kind == Fast_LiteralExpr)) {
            if (Fast_Expression_serialize(elem, cx_type(cx_bool_o), (cx_word)staticResult)) {
                Fast_Parser_error(yparser(), "failed to serialize literal condition expression");
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
                result = Fast_Expression(Fast_BinaryCreate(result, elem, CX_COND_AND));
                Fast_Parser_collect(yparser(), result);
                
            /* If element was a literal either ignore it (if result was TRUE) or discard all other
             * expressions if result of literal expression was FALSE. */
            } else if (!*staticResult) {
                result = NULL;
                break;
            }
        }
    }

    Fast_Expression_cleanList(conditions);
    
    return result;
error:
    return NULL;
}

/* $end */

/* ::corto::Fast::Node::init() */
cx_int16 _Fast_Node_init(Fast_Node _this) {
/* $begin(::corto::Fast::Node::init) */
    _this->line = yparser()->line;
    _this->column = yparser()->column;
    return 0;
/* $end */
}

/* ::corto::Fast::Node::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Node_toIc_v(Fast_Node _this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::Fast::Node::toIc) */
    CX_UNUSED(_this);
    CX_UNUSED(program);
    CX_UNUSED(storage);
    CX_UNUSED(stored);
    /* No code is generated for statement */
    return NULL;
/* $end */
}
