/* ast_StaticCall.c
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

/* ::corto::ast::StaticCall::construct() */
cx_int16 _ast_StaticCall_construct(ast_StaticCall this) {
/* $begin(::corto::ast::StaticCall::construct) */
    ast_Object fExpr;

    fExpr = ast_ObjectCreate(this->function);
    ast_Parser_collect(yparser(), fExpr);
    cx_setref(&ast_Call(this)->functionExpr, fExpr);

    /* Set parameters */
    ast_Call_setParameters(ast_Call(this), this->function);

    /* If function is a metaprocedure, signal Call class to push this as any */
    ast_Call(this)->instanceIsAny = 
        (cx_procedure(cx_typeof(this->function))->kind == CX_METAPROCEDURE);

    return ast_Call_construct(ast_Call(this));
/* $end */
}
