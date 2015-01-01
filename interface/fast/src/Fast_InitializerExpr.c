/* Fast_InitializerExpr.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"
#include "Fast__meta.h"

/* $header() */
#include "Fast__api.h"
#include "Fast_DynamicInitializer.h"
/* $end */

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::Fast::InitializerExpr::construct(InitializerExpr object) */
db_int16 Fast_InitializerExpr_construct(Fast_InitializerExpr object) {
/* $begin(::cortex::Fast::InitializerExpr::construct) */
    db_int16 result = 0;

    Fast_Node(object)->kind = FAST_Initializer;
    if (!result) {
        
        /* The construct could have created an initial push for composite objects. Since this push will
         * be recreated when creating the actual initializer, remove it from the list. */
        Fast_InitOper_list__clear(object->operations);
    } else {
        goto error;
    }

    return result;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::InitializerExpr::define() */
db_int16 Fast_InitializerExpr_define(Fast_InitializerExpr _this) {
/* $begin(::cortex::Fast::InitializerExpr::define) */
    Fast_InitOper *elem = Fast_InitOper_list__append(_this->operations);
    elem->kind = FAST_InitDefine;
    return 0;
/* $end */
}

/* ::cortex::Fast::InitializerExpr::insert(Expression variable) */
db_int16 Fast_InitializerExpr_insert(Fast_InitializerExpr _this, Fast_Expression variable) {
/* $begin(::cortex::Fast::InitializerExpr::insert) */
    Fast_DynamicInitializer initializer;

    db_set_ext(_this, &Fast_Initializer(_this)->variables[0].object, variable, ".variables[0].object");
    db_set_ext(_this, &Fast_Expression(_this)->type, variable->type, ".type");

    /* Create initializer */
    /* Note that since I'm passing MY list of variables, I need to fix the reference count! */
    db_keep_ext(NULL, Fast_Initializer(_this)->variables[0].object, "keep object for dynamic initializer");
    initializer = Fast_DynamicInitializer__create(Fast_Initializer(_this)->variables, 1, _this->assignValue);
    
    /* Walk operations */
    Fast_InitOper_list__foreach(_this->operations, elem)
        switch(elem->kind) {
        case FAST_InitPush:
            if (Fast_DynamicInitializer_push(initializer)) {
                goto error;
            }
            break;
        case FAST_InitPop:
            if (Fast_DynamicInitializer_pop(initializer)) {
                goto error;
            }
            break;
        case FAST_InitDefine:
            if (Fast_DynamicInitializer_define(initializer)) {
                goto error;
            }
            break;
        case FAST_InitValue:
            if (Fast_DynamicInitializer_value(initializer, elem->expr)) {
                goto error;
            }
            break;
        case FAST_InitMember:
            if (Fast_Initializer_member(Fast_Initializer(initializer), elem->name)) {
                goto error;
            }
           break;
        }
    }

    db_free_ext(NULL, initializer, "free temporary initializer");

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::InitializerExpr::member(lang::string name) */
db_int32 Fast_InitializerExpr_member(Fast_InitializerExpr _this, db_string name) {
/* $begin(::cortex::Fast::InitializerExpr::member) */
    Fast_InitOper *elem = Fast_InitOper_list__append(_this->operations);
    elem->kind = FAST_InitMember;
    elem->name = db_strdup(name);
    return 0;
/* $end */
}

/* ::cortex::Fast::InitializerExpr::pop() */
db_int16 Fast_InitializerExpr_pop(Fast_InitializerExpr _this) {
/* $begin(::cortex::Fast::InitializerExpr::pop) */
    Fast_InitOper *elem = Fast_InitOper_list__append(_this->operations);
    elem->kind = FAST_InitPop;
    return 0;
/* $end */
}

/* ::cortex::Fast::InitializerExpr::push() */
db_int16 Fast_InitializerExpr_push(Fast_InitializerExpr _this) {
/* $begin(::cortex::Fast::InitializerExpr::push) */
    Fast_InitOper *elem = Fast_InitOper_list__append(_this->operations);
    elem->kind = FAST_InitPush;
    return 0;
/* $end */
}

/* ::cortex::Fast::InitializerExpr::value(Expression v) */
db_int16 Fast_InitializerExpr_value(Fast_InitializerExpr _this, Fast_Expression v) {
/* $begin(::cortex::Fast::InitializerExpr::value) */
    Fast_InitOper *elem = Fast_InitOper_list__append(_this->operations);
    elem->kind = FAST_InitValue;
    db_set(&elem->expr, v);
    return 0;
/* $end */
}
