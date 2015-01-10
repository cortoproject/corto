/* Fast_CommaExpr.c
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
#include "Fast_Parser.h"
Fast_Parser yparser(void);
/* $end */

/* ::cortex::Fast::CommaExpr::addExpression(Expression expr) */
cx_int16 Fast_CommaExpr_addExpression(Fast_CommaExpr _this, Fast_Expression expr) {
/* $begin(::cortex::Fast::CommaExpr::addExpression) */
    if (expr) {
        cx_assert(_this->expressions != NULL, "initialization failed");
        cx_llAppend(_this->expressions, expr); cx_keep(expr);
        if (cx_llSize(_this->expressions) == 1) {
            cx_set(&Fast_Expression(_this)->type, expr->type);
        }
    }

    return 0;
/* $end */
}

/* ::cortex::Fast::CommaExpr::addOrCreate(Expression list,Expression expr) */
Fast_Expression Fast_CommaExpr_addOrCreate(Fast_Expression list, Fast_Expression expr) {
/* $begin(::cortex::Fast::CommaExpr::addOrCreate) */
    Fast_Expression result;
    
    if (!list) {
        result = expr;
    } else if (Fast_Node(list)->kind == FAST_CommaExpr) {
        Fast_CommaExpr_addExpression(Fast_CommaExpr(list), expr);
        result = list;
    } else {
        result = Fast_Expression(Fast_CommaExpr__create());
        Fast_CommaExpr_addExpression(Fast_CommaExpr(result), list);
        Fast_CommaExpr_addExpression(Fast_CommaExpr(result), expr);
        Fast_Parser_collect(yparser(), result);
    }
    
    return result;
/* $end */
}

/* callback ::cortex::lang::class::construct(object object) -> ::cortex::Fast::CommaExpr::construct(CommaExpr object) */
cx_int16 Fast_CommaExpr_construct(Fast_CommaExpr object) {
/* $begin(::cortex::Fast::CommaExpr::construct) */
    if (object->expressions) {
        Fast_Expression firstExpr = cx_llGet(object->expressions, 0);

        if (yparser()->line == 8) {
            if (firstExpr) {
                cx_set(&Fast_Expression(object)->type, firstExpr->type);
            }
        }
    }
    
    return 0;
/* $end */
}

/* ::cortex::Fast::CommaExpr::hasSideEffects() */
cx_bool Fast_CommaExpr_hasSideEffects_v(Fast_CommaExpr _this) {
/* $begin(::cortex::Fast::CommaExpr::hasSideEffects) */
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

/* callback ::cortex::lang::type::init(object object) -> ::cortex::Fast::CommaExpr::init(CommaExpr object) */
cx_int16 Fast_CommaExpr_init(Fast_CommaExpr object) {
/* $begin(::cortex::Fast::CommaExpr::init) */

    Fast_Node(object)->kind = FAST_CommaExpr;
    Fast_Expression(object)->type = NULL;

    return Fast_Expression_init(Fast_Expression(object));
/* $end */
}

/* ::cortex::Fast::CommaExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_CommaExpr_toIc_v(Fast_CommaExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::CommaExpr::toIc) */
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

/* ::cortex::Fast::CommaExpr::toList() */
Fast_Node_list Fast_CommaExpr_toList(Fast_CommaExpr _this) {
/* $begin(::cortex::Fast::CommaExpr::toList) */
    Fast_Node node;
    cx_iter iter;
    Fast_Node_list result = cx_llNew();
    iter = cx_llIter(_this->expressions);
    while(cx_iterHasNext(&iter)) {
        node = cx_iterNext(&iter);
        cx_llAppend(result, node); cx_keep(node);
    }

    return result;
/* $end */
}
