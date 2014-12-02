/* Fast_Wait.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"
#include "Fast__meta.h"

/* $header() */
#include "Fast_Expression.h"
#include "Fast_Parser.h"
#include "Fast__api.h"
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
Fast_Parser yparser(void);

void Fast_buildInheritanceStack(db_interface t, db_interface *stack, db_uint32 *count) {
    db_interface base;
    db_uint32 sp;

    (*count) = 0;

    /* Count depth */
    base = t;
    do{
        (*count)++;
    }while((base = base->base));

    /* Fill stack */
    sp = *count;
    base = t;
    do{
        stack[--sp] = base;
    }while((base = base->base));
}

db_interface Fast_findCommonAncestor(db_interface t1, db_interface t2) {
    db_interface result = NULL;
    db_interface stack1[DB_MAX_INHERITANCE_DEPTH], stack2[DB_MAX_INHERITANCE_DEPTH];
    db_uint32 count1, count2;

    /* Build inheritance stacks */
    Fast_buildInheritanceStack(t1, stack1, &count1);
    Fast_buildInheritanceStack(t2, stack2, &count2);

    /* Find highest common ancestor (if exists) */
    count1 = count1 > count2 ? count2 : count1;
    while(count1) {
        count1--;
        if (stack1[count1] == stack2[count1]) {
            result = stack1[count1];
            break;
        }
    }

    return result;
}

/* $end */

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::Wait::construct(Wait object) */
db_int16 Fast_Wait_construct(Fast_Wait object) {
/* $begin(::hyve::Fast::Wait::construct) */
    db_iter exprIter;
    Fast_Expression expr, timeoutExpr;
    db_type exprType, resultType = NULL;

    Fast_Node(object)->kind = FAST_Wait;

    /* Walk types of waitlist, check if all expressions evaluate to objects or reference values. Compare types in
     * waitlist to determine type of wait expression by taking the highest common ancestor. If no common ancestor
     * is found the type of the wait expression is a generic object. */
    exprIter = db_llIter(object->exprList);
    while(db_iterHasNext(&exprIter) && (resultType != db_object_o)) {
        expr = db_iterNext(&exprIter);
        exprType = Fast_Expression_getType(expr);

        if (!(exprType->reference || expr->isReference)) {
            Fast_Parser_error(yparser(), "one or more expressions in the waitlist do not evaluate to an object");
            goto error;
        }

        /* Find common ancestor */
        if (!resultType) {
            resultType = exprType;
        } else {
            if (resultType != exprType) {
                switch(resultType->kind) {
                case DB_COMPOSITE:
                    resultType = (db_type)Fast_findCommonAncestor((db_interface)resultType, (db_interface)exprType);
                    if (!resultType) {
                        resultType = db_object_o;
                    }
                    break;
                default:
                    resultType = db_object_o; /* No common ancestor */
                    break;
                }
            }
        }
    }

    if (object->timeout) {
        timeoutExpr = Fast_Expression_cast(object->timeout, db_type(db_float32_o));
        if (timeoutExpr) {
            db_set(&object->timeout, timeoutExpr);
        }
    } else {
        object->timeout = Fast_Expression(Fast_FloatingPoint__create(0));
    }

    /* Set type of expression */
    Fast_Expression(object)->type = Fast_Variable(Fast_Object__create(resultType));
    Fast_Expression(object)->isReference = TRUE; /* Result is always an object */

    return 0;
error:
    return -1;
/* $end */
}

/* ::hyve::Fast::Wait::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Wait_toIc_v(Fast_Wait _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::hyve::Fast::Wait::toIc) */
    db_iter exprIter;
    Fast_Expression expr;
    db_ic ic, result;
    db_icOp op;

    DB_UNUSED(stored);

    if (storage) {
        result = (db_ic)storage;
    } else {
        result = (db_ic)db_icProgram_accumulatorPush(
            program, Fast_Node(_this)->line, Fast_Expression_getType(Fast_Expression(_this)), TRUE);
    }

    exprIter = db_llIter(_this->exprList);
    while(db_iterHasNext(&exprIter)) {
        expr = db_iterNext(&exprIter);

        /* Parse object-expression */
        ic = Fast_Node_toIc(Fast_Node(expr), program, NULL, TRUE);

        /* Insert waitfor instruction */
        op = db_icOp__create(program, Fast_Node(_this)->line, DB_IC_WAITFOR, (db_icValue)ic, NULL, NULL);
        db_icProgram_addIc(program, (db_ic)op);
        if (expr->isReference) {
            op->s1Deref = DB_IC_DEREF_ADDRESS;
        }
    }

    /* Parse timeout-expression */
    if (_this->timeout) {
        ic = Fast_Node_toIc(Fast_Node(_this->timeout), program, NULL, TRUE);
    } else {
        ic = NULL;
    }

    /* Insert wait instruction */
    op = db_icOp__create(program, Fast_Node(_this)->line, DB_IC_WAIT, (db_icValue)result, (db_icValue)ic, NULL);
    db_icProgram_addIc(program, (db_ic)op);

    return result;
/* $end */
}
