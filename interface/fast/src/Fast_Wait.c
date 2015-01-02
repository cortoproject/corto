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

void Fast_buildInheritanceStack(cx_interface t, cx_interface *stack, cx_uint32 *count) {
    cx_interface base;
    cx_uint32 sp;

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

cx_interface Fast_findCommonAncestor(cx_interface t1, cx_interface t2) {
    cx_interface result = NULL;
    cx_interface stack1[CX_MAX_INHERITANCE_DEPTH], stack2[CX_MAX_INHERITANCE_DEPTH];
    cx_uint32 count1, count2;

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

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::Fast::Wait::construct(Wait object) */
cx_int16 Fast_Wait_construct(Fast_Wait object) {
/* $begin(::cortex::Fast::Wait::construct) */
    cx_iter exprIter;
    Fast_Expression expr, timeoutExpr;
    cx_type exprType, resultType = NULL;

    Fast_Node(object)->kind = FAST_Wait;

    /* Walk types of waitlist, check if all expressions evaluate to objects or reference values. Compare types in
     * waitlist to determine type of wait expression by taking the highest common ancestor. If no common ancestor
     * is found the type of the wait expression is a generic object. */
    exprIter = cx_llIter(object->exprList);
    while(cx_iterHasNext(&exprIter) && (resultType != cx_object_o)) {
        expr = cx_iterNext(&exprIter);
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
                case CX_COMPOSITE:
                    resultType = (cx_type)Fast_findCommonAncestor((cx_interface)resultType, (cx_interface)exprType);
                    if (!resultType) {
                        resultType = cx_object_o;
                    }
                    break;
                default:
                    resultType = cx_object_o; /* No common ancestor */
                    break;
                }
            }
        }
    }

    if (object->timeout) {
        timeoutExpr = Fast_Expression_cast(object->timeout, cx_type(cx_float32_o));
        if (timeoutExpr) {
            cx_set(&object->timeout, timeoutExpr);
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

/* ::cortex::Fast::Wait::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
cx_ic Fast_Wait_toIc_v(Fast_Wait _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::Wait::toIc) */
    cx_iter exprIter;
    Fast_Expression expr;
    cx_ic ic, result;
    cx_icOp op;

    CX_UNUSED(stored);

    if (storage) {
        result = (cx_ic)storage;
    } else {
        result = (cx_ic)cx_icProgram_accumulatorPush(
            program, Fast_Node(_this)->line, Fast_Expression_getType(Fast_Expression(_this)), TRUE);
    }

    exprIter = cx_llIter(_this->exprList);
    while(cx_iterHasNext(&exprIter)) {
        expr = cx_iterNext(&exprIter);

        /* Parse object-expression */
        ic = Fast_Node_toIc(Fast_Node(expr), program, NULL, TRUE);

        /* Insert waitfor instruction */
        op = cx_icOp__create(program, Fast_Node(_this)->line, CX_IC_WAITFOR, (cx_icValue)ic, NULL, NULL);
        cx_icProgram_addIc(program, (cx_ic)op);
        if (expr->isReference) {
            op->s1Deref = CX_IC_DEREF_ADDRESS;
        }
    }

    /* Parse timeout-expression */
    if (_this->timeout) {
        ic = Fast_Node_toIc(Fast_Node(_this->timeout), program, NULL, TRUE);
    } else {
        ic = NULL;
    }

    /* Insert wait instruction */
    op = cx_icOp__create(program, Fast_Node(_this)->line, CX_IC_WAIT, (cx_icValue)result, (cx_icValue)ic, NULL);
    cx_icProgram_addIc(program, (cx_ic)op);

    return result;
/* $end */
}
