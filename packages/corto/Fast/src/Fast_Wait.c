/* Fast_Wait.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"

/* $header() */
#include "Fast__private.h"

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

/* ::corto::Fast::Wait::construct() */
cx_int16 _Fast_Wait_construct(Fast_Wait _this) {
/* $begin(::corto::Fast::Wait::construct) */
    cx_iter exprIter;
    Fast_Expression expr, timeoutExpr;
    cx_type exprType, resultType = NULL;

    Fast_Node(_this)->kind = Fast_WaitExpr;

    /* Walk types of waitlist, check if all expressions evaluate to _this or reference values. Compare types in
     * waitlist to determine type of wait expression by taking the highest common ancestor. If no common ancestor
     * is found the type of the wait expression is a generic _this. */
    exprIter = cx_llIter(_this->exprList);
    while(cx_iterHasNext(&exprIter) && (resultType != cx_object_o)) {
        expr = cx_iterNext(&exprIter);
        exprType = Fast_Expression_getType(expr);

        if (!(exprType->reference || expr->isReference)) {
            Fast_Parser_error(yparser(), "one or more expressions in the waitlist do not evaluate to an _this");
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

    if (_this->timeout) {
        timeoutExpr = Fast_Expression_cast(_this->timeout, cx_type(cx_float32_o), FALSE);
        if (timeoutExpr) {
            cx_setref(&_this->timeout, timeoutExpr);
        }
    } else {
        _this->timeout = Fast_Expression(Fast_FloatingPoint__create(0));
    }

    /* Set type of expression */
    cx_setref(&Fast_Expression(_this)->type, resultType);
    Fast_Expression(_this)->isReference = TRUE; /* Result is always an _this */

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::Fast::Wait::hasReturnedResource() */
cx_bool _Fast_Wait_hasReturnedResource_v(Fast_Wait _this) {
/* $begin(::corto::Fast::Wait::hasReturnedResource) */
    CX_UNUSED(_this);
    return FALSE;
/* $end */
}

/* ::corto::Fast::Wait::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Wait_toIc_v(Fast_Wait _this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::Fast::Wait::toIc) */
    cx_iter exprIter;
    Fast_Expression expr;
    ic_node ic, result;

    CX_UNUSED(stored);

    if (storage) {
        result = (ic_node)storage;
    } else {
        result = (ic_node)ic_program_pushAccumulator(
            program, Fast_Expression_getType(Fast_Expression(_this)), TRUE, FALSE);
    }

    exprIter = cx_llIter(_this->exprList);
    while(cx_iterHasNext(&exprIter)) {
        expr = cx_iterNext(&exprIter);

        /* Parse object-expression */
        ic = Fast_Node_toIc(Fast_Node(expr), program, NULL, TRUE);

        /* Insert waitfor instruction */
        IC_1(program, Fast_Node(_this)->line, ic_waitfor, ic, 
            expr->isReference ? IC_DEREF_ADDRESS : IC_DEREF_VALUE);
    }

    /* Parse timeout-expression */
    if (_this->timeout) {
        ic = Fast_Node_toIc(Fast_Node(_this->timeout), program, NULL, TRUE);
    } else {
        ic = NULL;
    }

    /* Insert wait instruction */
    IC_3(program, Fast_Node(_this)->line, ic_wait, result, ic, NULL, 
        IC_DEREF_VALUE, IC_DEREF_VALUE, IC_DEREF_VALUE);

    return result;
/* $end */
}
