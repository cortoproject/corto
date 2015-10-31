/* $CORTO_GENERATED
 *
 * ast_StaticCall.c
 *
 * Only ode written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "ast.h"

/* $header() */
#include "ast__private.h"
/* $end */

corto_int16 _ast_StaticCall_construct(ast_StaticCall this) {
/* $begin(::corto::ast::StaticCall::construct) */
    ast_Object fExpr;

    fExpr = ast_ObjectCreate(this->function);
    ast_Parser_collect(yparser(), fExpr);
    corto_setref(&ast_Call(this)->functionExpr, fExpr);

    /* Set parameters */
    ast_Call_setParameters(ast_Call(this), this->function);

    /* If function is a metaprocedure, signal Call class to push this as any */
    ast_Call(this)->instanceIsAny = 
        (corto_procedure(corto_typeof(this->function))->kind == CORTO_METAPROCEDURE);

    return ast_Call_construct(ast_Call(this));
/* $end */
}
