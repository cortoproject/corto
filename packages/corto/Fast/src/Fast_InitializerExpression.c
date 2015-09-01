/* Fast_InitializerExpression.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"

/* $header() */
#include "Fast__private.h"
/* $end */

/* ::corto::Fast::InitializerExpression::construct() */
cx_int16 _Fast_InitializerExpression_construct(Fast_InitializerExpression _this) {
/* $begin(::corto::Fast::InitializerExpression::construct) */
    cx_int16 result = 0;

    Fast_Node(_this)->kind = Fast_InitializerExpr;

    return result;
/* $end */
}

/* ::corto::Fast::InitializerExpression::define() */
cx_int16 _Fast_InitializerExpression_define(Fast_InitializerExpression _this) {
/* $begin(::corto::Fast::InitializerExpression::define) */
    Fast_InitOper *elem = Fast_InitOperListAppend(_this->operations);
    elem->kind = Fast_InitOpDefine;
    return 0;
/* $end */
}

/* ::corto::Fast::InitializerExpression::hasReturnedResource() */
cx_bool _Fast_InitializerExpression_hasReturnedResource_v(Fast_InitializerExpression _this) {
/* $begin(::corto::Fast::InitializerExpression::hasReturnedResource) */
    CX_UNUSED(_this);
    return FALSE;
/* $end */
}

/* ::corto::Fast::InitializerExpression::insert(Expression variable) */
cx_int16 _Fast_InitializerExpression_insert(Fast_InitializerExpression _this, Fast_Expression variable) {
/* $begin(::corto::Fast::InitializerExpression::insert) */
    Fast_DynamicInitializer initializer;

    cx_setref(&Fast_Initializer(_this)->variables[0].object, variable);
    cx_setref(&Fast_Expression(_this)->type, variable->type);

    Fast_Expression var = Fast_Initializer(_this)->variables[0].object;
    if (Fast_Storage(var)->kind == Fast_TemporaryStorage) {
        Fast_Init init = Fast_InitCreate(Fast_Storage(var));
        Fast_Parser_addStatement(yparser(), Fast_Node(init));
        Fast_Parser_collect(yparser(), init);
    }

    /* Create initializer */
    /* Note that since I'm passing MY list of variables, I need to fix the reference count! */
    cx_claim(Fast_Initializer(_this)->variables[0].object);
    initializer = Fast_DynamicInitializerCreate(Fast_Initializer(_this)->variables, 1, _this->assignValue);

    /* Walk operations */
    Fast_InitOperListForeach(_this->operations, elem)
        switch(elem->kind) {
        case Fast_InitOpPush:
            if (Fast_DynamicInitializer_push(initializer)) {
                goto error;
            }
            break;
        case Fast_InitOpPop:
            if (Fast_DynamicInitializer_pop(initializer)) {
                goto error;
            }
            break;
        case Fast_InitOpDefine:
            if (Fast_DynamicInitializer_define(initializer)) {
                goto error;
            }
            break;
        case Fast_InitOpValue:
            if (Fast_DynamicInitializer_value(initializer, elem->expr)) {
                goto error;
            }
            break;
        case Fast_InitOpMember:
            if (Fast_Initializer_member(Fast_Initializer(initializer), elem->name)) {
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

/* ::corto::Fast::InitializerExpression::member(string name) */
cx_int32 _Fast_InitializerExpression_member(Fast_InitializerExpression _this, cx_string name) {
/* $begin(::corto::Fast::InitializerExpression::member) */
    Fast_InitOper *elem = Fast_InitOperListAppend(_this->operations);
    elem->kind = Fast_InitOpMember;
    elem->name = cx_strdup(name);
    return 0;
/* $end */
}

/* ::corto::Fast::InitializerExpression::pop() */
cx_int16 _Fast_InitializerExpression_pop(Fast_InitializerExpression _this) {
/* $begin(::corto::Fast::InitializerExpression::pop) */
    Fast_InitOper *elem = Fast_InitOperListAppend(_this->operations);
    elem->kind = Fast_InitOpPop;
    return 0;
/* $end */
}

/* ::corto::Fast::InitializerExpression::push() */
cx_int16 _Fast_InitializerExpression_push(Fast_InitializerExpression _this) {
/* $begin(::corto::Fast::InitializerExpression::push) */
    Fast_InitOper *elem = Fast_InitOperListAppend(_this->operations);
    elem->kind = Fast_InitOpPush;
    return 0;
/* $end */
}

/* ::corto::Fast::InitializerExpression::value(Expression v) */
cx_int16 _Fast_InitializerExpression_value(Fast_InitializerExpression _this, Fast_Expression v) {
/* $begin(::corto::Fast::InitializerExpression::value) */
    Fast_InitOper *elem = Fast_InitOperListAppend(_this->operations);
    elem->kind = Fast_InitOpValue;
    cx_setref(&elem->expr, v);
    return 0;
/* $end */
}
