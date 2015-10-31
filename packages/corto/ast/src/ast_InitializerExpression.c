/* $CORTO_GENERATED
 *
 * ast_InitializerExpression.c
 *
 * Only ode written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "ast.h"

/* $header() */
#include "ast__private.h"
/* $end */

corto_int16 _ast_InitializerExpression_construct(ast_InitializerExpression this) {
/* $begin(::corto::ast::InitializerExpression::construct) */
    corto_int16 result = 0;

    ast_Node(this)->kind = Ast_InitializerExpr;

    return result;
/* $end */
}

corto_int16 _ast_InitializerExpression_define(ast_InitializerExpression this) {
/* $begin(::corto::ast::InitializerExpression::define) */
    ast_InitOper *elem = ast_InitOperListAppendAlloc(this->operations);
    elem->kind = Ast_InitOpDefine;
    return 0;
/* $end */
}

corto_bool _ast_InitializerExpression_hasReturnedResource_v(ast_InitializerExpression this) {
/* $begin(::corto::ast::InitializerExpression::hasReturnedResource) */
    CORTO_UNUSED(this);
    return FALSE;
/* $end */
}

corto_int16 _ast_InitializerExpression_insert(ast_InitializerExpression this, ast_Expression variable) {
/* $begin(::corto::ast::InitializerExpression::insert) */
    ast_DynamicInitializer initializer;

    corto_setref(&ast_Initializer(this)->variables[0].object, variable);
    corto_setref(&ast_Expression(this)->type, variable->type);

    ast_Expression var = ast_Initializer(this)->variables[0].object;
    if (ast_Storage(var)->kind == Ast_TemporaryStorage) {
        ast_Init init = ast_InitCreate(ast_Storage(var));
        ast_Parser_addStatement(yparser(), ast_Node(init));
        ast_Parser_collect(yparser(), init);
    }

    /* Create initializer */
    /* Note that since I'm passing MY list of variables, I need to fix the reference count! */
    corto_claim(ast_Initializer(this)->variables[0].object);
    initializer = ast_DynamicInitializerCreate(ast_Initializer(this)->variables, 1, this->assignValue);

    /* Walk operations */
    ast_InitOperListForeach(this->operations, elem) {
        switch(elem->kind) {
        case Ast_InitOpPush:
            if (ast_DynamicInitializer_push(initializer)) {
                goto error;
            }
            break;
        case Ast_InitOpPop:
            if (ast_DynamicInitializer_pop(initializer)) {
                goto error;
            }
            break;
        case Ast_InitOpDefine:
            if (ast_DynamicInitializer_define(initializer)) {
                goto error;
            }
            break;
        case Ast_InitOpValue:
            if (ast_DynamicInitializer_value(initializer, elem->expr)) {
                goto error;
            }
            break;
        case Ast_InitOpMember:
            if (ast_Initializer_member(ast_Initializer(initializer), elem->name)) {
                goto error;
            }
           break;
        }
    }

    corto_release(initializer);

    return 0;
error:
    return -1;
/* $end */
}

corto_int32 _ast_InitializerExpression_member(ast_InitializerExpression this, corto_string name) {
/* $begin(::corto::ast::InitializerExpression::member) */
    ast_InitOper *elem = ast_InitOperListAppendAlloc(this->operations);
    elem->kind = Ast_InitOpMember;
    elem->name = corto_strdup(name);
    return 0;
/* $end */
}

corto_int16 _ast_InitializerExpression_pop(ast_InitializerExpression this) {
/* $begin(::corto::ast::InitializerExpression::pop) */
    ast_InitOper *elem = ast_InitOperListAppendAlloc(this->operations);
    elem->kind = Ast_InitOpPop;
    return 0;
/* $end */
}

corto_int16 _ast_InitializerExpression_push(ast_InitializerExpression this) {
/* $begin(::corto::ast::InitializerExpression::push) */
    ast_InitOper *elem = ast_InitOperListAppendAlloc(this->operations);
    elem->kind = Ast_InitOpPush;
    return 0;
/* $end */
}

corto_int16 _ast_InitializerExpression_value(ast_InitializerExpression this, ast_Expression v) {
/* $begin(::corto::ast::InitializerExpression::value) */
    ast_InitOper *elem = ast_InitOperListAppendAlloc(this->operations);
    elem->kind = Ast_InitOpValue;
    corto_setref(&elem->expr, v);
    return 0;
/* $end */
}
