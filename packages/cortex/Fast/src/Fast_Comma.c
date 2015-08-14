/* Fast_Comma.c
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

/* ::cortex::Fast::Comma::addExpression(Expression expr) */
cx_int16 Fast_Comma_addExpression(Fast_Comma _this, Fast_Expression expr) {
/* $begin(::cortex::Fast::Comma::addExpression) */
    if (expr) {
        cx_assert(_this->expressions != NULL, "initialization failed");
        cx_llAppend(_this->expressions, expr); cx_claim(expr);
        if (cx_llSize(_this->expressions) == 1) {
            cx_setref(&Fast_Expression(_this)->type, expr->type);
        }
    }

    return 0;
/* $end */
}

/* ::cortex::Fast::Comma::addOrCreate(Expression list,Expression expr) */
Fast_Expression Fast_Comma_addOrCreate(Fast_Expression list, Fast_Expression expr) {
/* $begin(::cortex::Fast::Comma::addOrCreate) */
    Fast_Expression result;
    
    if (!list) {
        result = expr;
    } else if (Fast_Node(list)->kind == Fast_CommaExpr) {
        Fast_Comma_addExpression(Fast_Comma(list), expr);
        result = list;
    } else {
        result = Fast_Expression(Fast_Comma__create());
        Fast_Comma_addExpression(Fast_Comma(result), list);
        Fast_Comma_addExpression(Fast_Comma(result), expr);
        Fast_Parser_collect(yparser(), result);
    }
    
    return result;
/* $end */
}

/* ::cortex::Fast::Comma::construct() */
cx_int16 Fast_Comma_construct(Fast_Comma _this) {
/* $begin(::cortex::Fast::Comma::construct) */
    if (_this->expressions) {
        Fast_Expression firstExpr = cx_llGet(_this->expressions, 0);

        if (yparser()->line == 8) {
            if (firstExpr) {
                cx_setref(&Fast_Expression(_this)->type, firstExpr->type);
            }
        }
    }
    
    return 0;
/* $end */
}

/* ::cortex::Fast::Comma::hasReturnedResource() */
cx_bool Fast_Comma_hasReturnedResource_v(Fast_Comma _this) {
/* $begin(::cortex::Fast::Comma::hasReturnedResource) */
    cx_bool result = FALSE;

    Fast_Expression_list__foreach(_this->expressions, elem)
        if (Fast_Expression_hasReturnedResource(elem)) {
            result = TRUE;
            break;
        }
    }

    return result;
/* $end */
}

/* ::cortex::Fast::Comma::hasSideEffects() */
cx_bool Fast_Comma_hasSideEffects_v(Fast_Comma _this) {
/* $begin(::cortex::Fast::Comma::hasSideEffects) */
    cx_bool result = FALSE;
    
    Fast_Expression_list__foreach(_this->expressions, elem)
        if (Fast_Expression_hasSideEffects(elem)) {
            result = TRUE;
            break;
        }
    }

    return result;
/* $end */
}

/* ::cortex::Fast::Comma::init() */
cx_int16 Fast_Comma_init(Fast_Comma _this) {
/* $begin(::cortex::Fast::Comma::init) */

    Fast_Node(_this)->kind = Fast_CommaExpr;
    Fast_Expression(_this)->type = NULL;

    return Fast_Node_init(Fast_Node(_this));
/* $end */
}

/* ::cortex::Fast::Comma::insertOrCreate(Expression list,Expression expr) */
Fast_Expression Fast_Comma_insertOrCreate(Fast_Expression list, Fast_Expression expr) {
/* $begin(::cortex::Fast::Comma::insertOrCreate) */
    Fast_Expression result;
    
    if (!list) {
        result = expr;
    } else if (Fast_Node(list)->kind == Fast_CommaExpr) {
        Fast_Comma_addExpression(Fast_Comma(list), expr);
        result = list;
    } else {
        result = Fast_Expression(Fast_Comma__create());
        Fast_Comma_addExpression(Fast_Comma(result), expr);
        Fast_Comma_addExpression(Fast_Comma(result), list);
        Fast_Parser_collect(yparser(), result);
    }
    
    return result;
/* $end */
}

/* ::cortex::Fast::Comma::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Comma_toIc_v(Fast_Comma _this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::cortex::Fast::Comma::toIc) */
    cx_iter iter;
    Fast_Node expr;
    
    iter = cx_llIter(_this->expressions);
    while(cx_iterHasNext(&iter)) {
        expr = cx_iterNext(&iter);
        Fast_Node_toIc(expr, program, storage, stored);
    }

    return NULL;
/* $end */
}

/* ::cortex::Fast::Comma::toList() */
Fast_Node_list Fast_Comma_toList(Fast_Comma _this) {
/* $begin(::cortex::Fast::Comma::toList) */
    Fast_Node node;
    cx_iter iter;
    Fast_Node_list result = cx_llNew();
    iter = cx_llIter(_this->expressions);
    while(cx_iterHasNext(&iter)) {
        node = cx_iterNext(&iter);
        cx_llAppend(result, node); cx_claim(node);
    }

    return result;
/* $end */
}
