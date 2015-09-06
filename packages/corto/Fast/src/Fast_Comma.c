/* Fast_Comma.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_Fast_LIB
#include "Fast.h"

/* $header() */
#include "Fast__private.h"
/* $end */

/* ::corto::Fast::Comma::addExpression(Expression expr) */
cx_int16 _Fast_Comma_addExpression(Fast_Comma this, Fast_Expression expr) {
/* $begin(::corto::Fast::Comma::addExpression) */
    if (expr) {
        cx_assert(this->expressions != NULL, "initialization failed");
        cx_llAppend(this->expressions, expr); cx_claim(expr);
        if (cx_llSize(this->expressions) == 1) {
            cx_setref(&Fast_Expression(this)->type, expr->type);
        }
    }

    return 0;
/* $end */
}

/* ::corto::Fast::Comma::addOrCreate(Expression list,Expression expr) */
Fast_Expression _Fast_Comma_addOrCreate(Fast_Expression list, Fast_Expression expr) {
/* $begin(::corto::Fast::Comma::addOrCreate) */
    Fast_Expression result;
    
    if (!list) {
        result = expr;
    } else if (Fast_Node(list)->kind == Fast_CommaExpr) {
        Fast_Comma_addExpression(Fast_Comma(list), expr);
        result = list;
    } else {
        result = Fast_Expression(Fast_CommaCreate());
        Fast_Comma_addExpression(Fast_Comma(result), list);
        Fast_Comma_addExpression(Fast_Comma(result), expr);
        Fast_Parser_collect(yparser(), result);
    }
    
    return result;
/* $end */
}

/* ::corto::Fast::Comma::construct() */
cx_int16 _Fast_Comma_construct(Fast_Comma this) {
/* $begin(::corto::Fast::Comma::construct) */
    if (this->expressions) {
        Fast_Expression firstExpr = cx_llGet(this->expressions, 0);

        if (yparser()->line == 8) {
            if (firstExpr) {
                cx_setref(&Fast_Expression(this)->type, firstExpr->type);
            }
        }
    }
    
    return 0;
/* $end */
}

/* ::corto::Fast::Comma::hasReturnedResource() */
cx_bool _Fast_Comma_hasReturnedResource_v(Fast_Comma this) {
/* $begin(::corto::Fast::Comma::hasReturnedResource) */
    cx_bool result = FALSE;

    Fast_ExpressionListForeach(this->expressions, elem)
        if (Fast_Expression_hasReturnedResource(elem)) {
            result = TRUE;
            break;
        }
    }

    return result;
/* $end */
}

/* ::corto::Fast::Comma::hasSideEffects() */
cx_bool _Fast_Comma_hasSideEffects_v(Fast_Comma this) {
/* $begin(::corto::Fast::Comma::hasSideEffects) */
    cx_bool result = FALSE;
    
    Fast_ExpressionListForeach(this->expressions, elem)
        if (Fast_Expression_hasSideEffects(elem)) {
            result = TRUE;
            break;
        }
    }

    return result;
/* $end */
}

/* ::corto::Fast::Comma::init() */
cx_int16 _Fast_Comma_init(Fast_Comma this) {
/* $begin(::corto::Fast::Comma::init) */

    Fast_Node(this)->kind = Fast_CommaExpr;
    Fast_Expression(this)->type = NULL;

    return Fast_Node_init(Fast_Node(this));
/* $end */
}

/* ::corto::Fast::Comma::insertOrCreate(Expression list,Expression expr) */
Fast_Expression _Fast_Comma_insertOrCreate(Fast_Expression list, Fast_Expression expr) {
/* $begin(::corto::Fast::Comma::insertOrCreate) */
    Fast_Expression result;
    
    if (!list) {
        result = expr;
    } else if (Fast_Node(list)->kind == Fast_CommaExpr) {
        Fast_Comma_addExpression(Fast_Comma(list), expr);
        result = list;
    } else {
        result = Fast_Expression(Fast_CommaCreate());
        Fast_Comma_addExpression(Fast_Comma(result), expr);
        Fast_Comma_addExpression(Fast_Comma(result), list);
        Fast_Parser_collect(yparser(), result);
    }
    
    return result;
/* $end */
}

/* ::corto::Fast::Comma::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Comma_toIc_v(Fast_Comma this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::Fast::Comma::toIc) */
    cx_iter iter;
    Fast_Node expr;
    
    iter = cx_llIter(this->expressions);
    while(cx_iterHasNext(&iter)) {
        expr = cx_iterNext(&iter);
        Fast_Node_toIc(expr, program, storage, stored);
    }

    return NULL;
/* $end */
}

/* ::corto::Fast::Comma::toList() */
Fast_NodeList _Fast_Comma_toList(Fast_Comma this) {
/* $begin(::corto::Fast::Comma::toList) */
    Fast_Node node;
    cx_iter iter;
    Fast_NodeList result = cx_llNew();
    iter = cx_llIter(this->expressions);
    while(cx_iterHasNext(&iter)) {
        node = cx_iterNext(&iter);
        cx_llAppend(result, node); cx_claim(node);
    }

    return result;
/* $end */
}
