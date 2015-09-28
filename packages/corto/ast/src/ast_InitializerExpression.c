/* ast_InitializerExpression.c
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

/* ::corto::ast::InitializerExpression::construct() */
cx_int16 _ast_InitializerExpression_construct(ast_InitializerExpression this) {
/* $begin(::corto::ast::InitializerExpression::construct) */
    cx_int16 result = 0;

    ast_Node(this)->kind = Ast_InitializerExpr;

    return result;
/* $end */
}

/* ::corto::ast::InitializerExpression::define() */
cx_int16 _ast_InitializerExpression_define(ast_InitializerExpression this) {
/* $begin(::corto::ast::InitializerExpression::define) */
    ast_InitOper *elem = ast_InitOperListAppendAlloc(this->operations);
    elem->kind = Ast_InitOpDefine;
    return 0;
/* $end */
}

/* ::corto::ast::InitializerExpression::hasReturnedResource() */
cx_bool _ast_InitializerExpression_hasReturnedResource_v(ast_InitializerExpression this) {
/* $begin(::corto::ast::InitializerExpression::hasReturnedResource) */
    CX_UNUSED(this);
    return FALSE;
/* $end */
}

/* ::corto::ast::InitializerExpression::insert(Expression variable) */
cx_int16 _ast_InitializerExpression_insert(ast_InitializerExpression this, ast_Expression variable) {
/* $begin(::corto::ast::InitializerExpression::insert) */
    ast_DynamicInitializer initializer;

    cx_setref(&ast_Initializer(this)->variables[0].object, variable);
    cx_setref(&ast_Expression(this)->type, variable->type);

    ast_Expression var = ast_Initializer(this)->variables[0].object;
    if (ast_Storage(var)->kind == Ast_TemporaryStorage) {
        ast_Init init = ast_InitCreate(ast_Storage(var));
        ast_Parser_addStatement(yparser(), ast_Node(init));
        ast_Parser_collect(yparser(), init);
    }

    /* Create initializer */
    /* Note that since I'm passing MY list of variables, I need to fix the reference count! */
    cx_claim(ast_Initializer(this)->variables[0].object);
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

    cx_release(initializer);

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::ast::InitializerExpression::member(string name) */
cx_int32 _ast_InitializerExpression_member(ast_InitializerExpression this, cx_string name) {
/* $begin(::corto::ast::InitializerExpression::member) */
    ast_InitOper *elem = ast_InitOperListAppendAlloc(this->operations);
    elem->kind = Ast_InitOpMember;
    elem->name = cx_strdup(name);
    return 0;
/* $end */
}

/* ::corto::ast::InitializerExpression::pop() */
cx_int16 _ast_InitializerExpression_pop(ast_InitializerExpression this) {
/* $begin(::corto::ast::InitializerExpression::pop) */
    ast_InitOper *elem = ast_InitOperListAppendAlloc(this->operations);
    elem->kind = Ast_InitOpPop;
    return 0;
/* $end */
}

/* ::corto::ast::InitializerExpression::push() */
cx_int16 _ast_InitializerExpression_push(ast_InitializerExpression this) {
/* $begin(::corto::ast::InitializerExpression::push) */
    ast_InitOper *elem = ast_InitOperListAppendAlloc(this->operations);
    elem->kind = Ast_InitOpPush;
    return 0;
/* $end */
}

/* ::corto::ast::InitializerExpression::value(Expression v) */
cx_int16 _ast_InitializerExpression_value(ast_InitializerExpression this, ast_Expression v) {
/* $begin(::corto::ast::InitializerExpression::value) */
    ast_InitOper *elem = ast_InitOperListAppendAlloc(this->operations);
    elem->kind = Ast_InitOpValue;
    cx_setref(&elem->expr, v);
    return 0;
/* $end */
}
