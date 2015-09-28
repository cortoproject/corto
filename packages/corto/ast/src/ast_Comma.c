/* ast_Comma.c
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

/* ::corto::ast::Comma::addExpression(Expression expr) */
cx_int16 _ast_Comma_addExpression(ast_Comma this, ast_Expression expr) {
/* $begin(::corto::ast::Comma::addExpression) */
    if (expr) {
        cx_assert(this->expressions != NULL, "initialization failed");
        cx_llAppend(this->expressions, expr); cx_claim(expr);
        if (cx_llSize(this->expressions) == 1) {
            cx_setref(&ast_Expression(this)->type, expr->type);
        }
    }

    return 0;
/* $end */
}

/* ::corto::ast::Comma::addOrCreate(Expression list,Expression expr) */
ast_Expression _ast_Comma_addOrCreate(ast_Expression list, ast_Expression expr) {
/* $begin(::corto::ast::Comma::addOrCreate) */
    ast_Expression result;
    
    if (!list) {
        result = expr;
    } else if (ast_Node(list)->kind == Ast_CommaExpr) {
        ast_Comma_addExpression(ast_Comma(list), expr);
        result = list;
    } else {
        result = ast_Expression(ast_CommaCreate());
        ast_Comma_addExpression(ast_Comma(result), list);
        ast_Comma_addExpression(ast_Comma(result), expr);
        ast_Parser_collect(yparser(), result);
    }
    
    return result;
/* $end */
}

/* ::corto::ast::Comma::construct() */
cx_int16 _ast_Comma_construct(ast_Comma this) {
/* $begin(::corto::ast::Comma::construct) */
    if (this->expressions) {
        ast_Expression firstExpr = cx_llGet(this->expressions, 0);

        if (yparser()->line == 8) {
            if (firstExpr) {
                cx_setref(&ast_Expression(this)->type, firstExpr->type);
            }
        }
    }
    
    return 0;
/* $end */
}

/* ::corto::ast::Comma::hasReturnedResource() */
cx_bool _ast_Comma_hasReturnedResource_v(ast_Comma this) {
/* $begin(::corto::ast::Comma::hasReturnedResource) */
    cx_bool result = FALSE;

    ast_ExpressionListForeach(this->expressions, elem) {
        if (ast_Expression_hasReturnedResource(elem)) {
            result = TRUE;
            break;
        }
    }

    return result;
/* $end */
}

/* ::corto::ast::Comma::hasSideEffects() */
cx_bool _ast_Comma_hasSideEffects_v(ast_Comma this) {
/* $begin(::corto::ast::Comma::hasSideEffects) */
    cx_bool result = FALSE;
    
    ast_ExpressionListForeach(this->expressions, elem) {
        if (ast_Expression_hasSideEffects(elem)) {
            result = TRUE;
            break;
        }
    }

    return result;
/* $end */
}

/* ::corto::ast::Comma::init() */
cx_int16 _ast_Comma_init(ast_Comma this) {
/* $begin(::corto::ast::Comma::init) */

    ast_Node(this)->kind = Ast_CommaExpr;
    ast_Expression(this)->type = NULL;

    return ast_Node_init(ast_Node(this));
/* $end */
}

/* ::corto::ast::Comma::insertOrCreate(Expression list,Expression expr) */
ast_Expression _ast_Comma_insertOrCreate(ast_Expression list, ast_Expression expr) {
/* $begin(::corto::ast::Comma::insertOrCreate) */
    ast_Expression result;
    
    if (!list) {
        result = expr;
    } else if (ast_Node(list)->kind == Ast_CommaExpr) {
        ast_Comma_addExpression(ast_Comma(list), expr);
        result = list;
    } else {
        result = ast_Expression(ast_CommaCreate());
        ast_Comma_addExpression(ast_Comma(result), expr);
        ast_Comma_addExpression(ast_Comma(result), list);
        ast_Parser_collect(yparser(), result);
    }
    
    return result;
/* $end */
}

/* ::corto::ast::Comma::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _ast_Comma_toIc_v(ast_Comma this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::ast::Comma::toIc) */

    ast_ExpressionListForeach(this->expressions, expr) {
        ast_Node_toIc(expr, program, storage, stored);
    }

    return NULL;
/* $end */
}

/* ::corto::ast::Comma::toList() */
ast_NodeList _ast_Comma_toList(ast_Comma this) {
/* $begin(::corto::ast::Comma::toList) */

    ast_NodeList result = cx_llNew();
    ast_ExpressionListForeach(this->expressions, expr) {
        cx_llAppend(result, expr); cx_claim(expr);
    }

    return result;
/* $end */
}
