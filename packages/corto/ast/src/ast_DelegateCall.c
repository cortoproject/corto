/* $CORTO_GENERATED
 *
 * ast_DelegateCall.c
 *
 * Code written between the begin and end tags will be preserved when the
 * file is regenerated.
 */

#include "ast.h"

/* $header() */
#include "ast__private.h"
/* $end */

corto_int16 _ast_DelegateCall_construct(ast_DelegateCall this) {
/* $begin(::corto::ast::DelegateCall::construct) */
    if (!this->expr) {
        ast_Parser_error(yparser(), "no expression provided for delegate call");
        goto error;
    } else {
        corto_uint32 i;
        corto_delegate type = corto_delegate(ast_Expression_getType(this->expr));

        /* Create expression to obtain pointer to the instance */
        ast_String instanceString = ast_StringCreate("instance");
        ast_Member iExpr = ast_MemberCreate(this->expr, ast_Expression(instanceString));
        corto_setref(&ast_Call(this)->instanceExpr, iExpr);
        ast_Parser_collect(yparser(), iExpr);
        ast_Parser_collect(yparser(), instanceString);

        /* Set function expression to delegate */
        corto_setref(&ast_Call(this)->functionExpr, this->expr);

        /* Set parameters */
        corto_setref(&ast_Call(this)->returnType, type->returnType);
        ast_Call(this)->returnsReference = type->returnsReference;

        corto_parameterSeqSize(&ast_Call(this)->parameters, type->parameters.length);

        for (i = 0; i < type->parameters.length; i++) {
            corto_setref(&ast_Call(this)->parameters.buffer[i].type, type->parameters.buffer[i].type);
            ast_Call(this)->parameters.buffer[i].passByReference = type->parameters.buffer[i].passByReference;
        }
    }

    return ast_Call_construct(ast_Call(this));
error:
    return -1;
/* $end */
}
