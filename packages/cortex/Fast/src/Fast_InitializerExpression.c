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

/* ::cortex::Fast::InitializerExpression::construct() */
cx_int16 Fast_InitializerExpression_construct(Fast_InitializerExpression _this) {
/* $begin(::cortex::Fast::InitializerExpression::construct) */
    cx_int16 result = 0;

    Fast_Node(_this)->kind = Fast_InitializerExpr;

    return result;
/* $end */
}

/* ::cortex::Fast::InitializerExpression::define() */
cx_int16 Fast_InitializerExpression_define(Fast_InitializerExpression _this) {
/* $begin(::cortex::Fast::InitializerExpression::define) */
    Fast_InitOper *elem = Fast_InitOper_list__append(_this->operations);
    elem->kind = Fast_InitDefine;
    return 0;
/* $end */
}

/* ::cortex::Fast::InitializerExpression::insert(Expression variable) */
cx_int16 Fast_InitializerExpression_insert(Fast_InitializerExpression _this, Fast_Expression variable) {
/* $begin(::cortex::Fast::InitializerExpression::insert) */
    Fast_DynamicInitializer initializer;

    cx_setref(&Fast_Initializer(_this)->variables[0].object, variable);
    cx_setref(&Fast_Expression(_this)->type, variable->type);

    Fast_Expression var = Fast_Initializer(_this)->variables[0].object;
    if (Fast_Storage(var)->kind == Fast_TemporaryStorage) {
        Fast_Init init = Fast_Init__create(Fast_Storage(var));
        Fast_Parser_addStatement(yparser(), Fast_Node(init));
        Fast_Parser_collect(yparser(), init);
    }

    /* Create initializer */
    /* Note that since I'm passing MY list of variables, I need to fix the reference count! */
    cx_claim(Fast_Initializer(_this)->variables[0].object);
    initializer = Fast_DynamicInitializer__create(Fast_Initializer(_this)->variables, 1, _this->assignValue);

    /* Walk operations */
    Fast_InitOper_list__foreach(_this->operations, elem)
        switch(elem->kind) {
        case Fast_InitPush:
            if (Fast_DynamicInitializer_push(initializer)) {
                goto error;
            }
            break;
        case Fast_InitPop:
            if (Fast_DynamicInitializer_pop(initializer)) {
                goto error;
            }
            break;
        case Fast_InitDefine:
            if (Fast_DynamicInitializer_define(initializer)) {
                goto error;
            }
            break;
        case Fast_InitValue:
            if (Fast_DynamicInitializer_value(initializer, elem->expr)) {
                goto error;
            }
            break;
        case Fast_InitMember:
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

/* ::cortex::Fast::InitializerExpression::member(string name) */
cx_int32 Fast_InitializerExpression_member(Fast_InitializerExpression _this, cx_string name) {
/* $begin(::cortex::Fast::InitializerExpression::member) */
    Fast_InitOper *elem = Fast_InitOper_list__append(_this->operations);
    elem->kind = Fast_InitMember;
    elem->name = cx_strdup(name);
    return 0;
/* $end */
}

/* ::cortex::Fast::InitializerExpression::pop() */
cx_int16 Fast_InitializerExpression_pop(Fast_InitializerExpression _this) {
/* $begin(::cortex::Fast::InitializerExpression::pop) */
    Fast_InitOper *elem = Fast_InitOper_list__append(_this->operations);
    elem->kind = Fast_InitPop;
    return 0;
/* $end */
}

/* ::cortex::Fast::InitializerExpression::push() */
cx_int16 Fast_InitializerExpression_push(Fast_InitializerExpression _this) {
/* $begin(::cortex::Fast::InitializerExpression::push) */
    Fast_InitOper *elem = Fast_InitOper_list__append(_this->operations);
    elem->kind = Fast_InitPush;
    return 0;
/* $end */
}

/* ::cortex::Fast::InitializerExpression::value(Expression v) */
cx_int16 Fast_InitializerExpression_value(Fast_InitializerExpression _this, Fast_Expression v) {
/* $begin(::cortex::Fast::InitializerExpression::value) */
    Fast_InitOper *elem = Fast_InitOper_list__append(_this->operations);
    elem->kind = Fast_InitValue;
    cx_setref(&elem->expr, v);
    return 0;
/* $end */
}
