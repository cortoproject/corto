/* Fast_CommaExpr.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast_CommaExpr.h"
#include "Fast__meta.h"


/* $header() */
#include "Fast__api.h"
#include "Fast_Parser.h"
Fast_Parser yparser(void);
/* $end */

/* ::hyve::Fast::CommaExpr::addExpression(Expression expr) */
db_int16 Fast_CommaExpr_addExpression(Fast_CommaExpr _this, Fast_Expression expr) {
/* $begin(::hyve::Fast::CommaExpr::addExpression) */
    if (expr) {
        db_assert(_this->expressions != NULL, "initialization failed");
        db_llAppend(_this->expressions, expr); db_keep(expr);
        if (db_llSize(_this->expressions) == 1) {
            db_set(&Fast_Expression(_this)->type, expr->type);
        }
    }

    return 0;
/* $end */
}

/* ::hyve::Fast::CommaExpr::addOrCreate(Expression list,Expression expr) */
Fast_Expression Fast_CommaExpr_addOrCreate(Fast_Expression list, Fast_Expression expr) {
/* $begin(::hyve::Fast::CommaExpr::addOrCreate) */
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

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::CommaExpr::construct(CommaExpr object) */
db_int16 Fast_CommaExpr_construct(Fast_CommaExpr object) {
/* $begin(::hyve::Fast::CommaExpr::construct) */
    if (object->expressions) {
        Fast_Expression firstExpr = db_llGet(object->expressions, 0);

        if (yparser()->line == 8) {
            if (firstExpr) {
                db_set(&Fast_Expression(object)->type, firstExpr->type);
            }
        }
    }
    
    return 0;
/* $end */
}

/* ::hyve::Fast::CommaExpr::hasSideEffects() */
db_bool Fast_CommaExpr_hasSideEffects_v(Fast_CommaExpr _this) {
/* $begin(::hyve::Fast::CommaExpr::hasSideEffects) */
    db_bool result = FALSE;
    
    Fast_Expression_list__foreach(_this->expressions, elem)
        if (Fast_Expression_hasSideEffects(elem)) {
            result = TRUE;
            break;
        }
    }

    return result;
/* $end */
}

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::Fast::CommaExpr::init(CommaExpr object) */
db_int16 Fast_CommaExpr_init(Fast_CommaExpr object) {
/* $begin(::hyve::Fast::CommaExpr::init) */

    Fast_Node(object)->kind = FAST_CommaExpr;
    Fast_Expression(object)->type = NULL;

    return Fast_Expression_init(Fast_Expression(object));
/* $end */
}

/* ::hyve::Fast::CommaExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_CommaExpr_toIc_v(Fast_CommaExpr _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::hyve::Fast::CommaExpr::toIc) */
    db_iter iter;
    Fast_Node expr;
    
    iter = db_llIter(_this->expressions);
    while(db_iterHasNext(&iter)) {
        expr = db_iterNext(&iter);
        Fast_Node_toIc(expr, program, storage, stored);
    }

    return NULL;
/* $end */
}

/* ::hyve::Fast::CommaExpr::toList() */
Fast_Node_list Fast_CommaExpr_toList(Fast_CommaExpr _this) {
/* $begin(::hyve::Fast::CommaExpr::toList) */
    Fast_Node node;
    db_iter iter;
    Fast_Node_list result = db_llNew();
    iter = db_llIter(_this->expressions);
    while(db_iterHasNext(&iter)) {
        node = db_iterNext(&iter);
        db_llAppend(result, node); db_keep(node);
    }

    return result;
/* $end */
}
