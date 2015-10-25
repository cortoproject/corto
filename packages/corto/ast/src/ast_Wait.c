/* $CORTO_GENERATED
 *
 * ast_Wait.c
 *
 * Code written between the begin and end tags will be preserved when the
 * file is regenerated.
 */

#include "ast.h"

/* $header() */
#include "ast__private.h"

void ast_buildInheritanceStack(corto_interface t, corto_interface *stack, corto_uint32 *count) {
    corto_interface base;
    corto_uint32 sp;

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

corto_interface ast_findCommonAncestor(corto_interface t1, corto_interface t2) {
    corto_interface result = NULL;
    corto_interface stack1[CORTO_MAX_INHERITANCE_DEPTH], stack2[CORTO_MAX_INHERITANCE_DEPTH];
    corto_uint32 count1, count2;

    /* Build inheritance stacks */
    ast_buildInheritanceStack(t1, stack1, &count1);
    ast_buildInheritanceStack(t2, stack2, &count2);

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

corto_int16 _ast_Wait_construct(ast_Wait this) {
/* $begin(::corto::ast::Wait::construct) */
    corto_iter exprIter;
    ast_Expression expr, timeoutExpr;
    corto_type exprType, resultType = NULL;

    ast_Node(this)->kind = Ast_WaitExpr;

    /* Walk types of waitlist, check if all expressions evaluate to this or reference values. Compare types in
     * waitlist to determine type of wait expression by taking the highest common ancestor. If no common ancestor
     * is found the type of the wait expression is a generic this. */
    exprIter = corto_llIter(this->exprList);
    while(corto_iterHasNext(&exprIter) && (resultType != corto_object_o)) {
        expr = corto_iterNext(&exprIter);
        exprType = ast_Expression_getType(expr);

        if (!(exprType->reference || expr->isReference)) {
            ast_Parser_error(yparser(), "one or more expressions in the waitlist do not evaluate to an this");
            goto error;
        }

        /* Find common ancestor */
        if (!resultType) {
            resultType = exprType;
        } else {
            if (resultType != exprType) {
                switch(resultType->kind) {
                case CORTO_COMPOSITE:
                    resultType = (corto_type)ast_findCommonAncestor((corto_interface)resultType, (corto_interface)exprType);
                    if (!resultType) {
                        resultType = corto_object_o;
                    }
                    break;
                default:
                    resultType = corto_object_o; /* No common ancestor */
                    break;
                }
            }
        }
    }

    if (this->timeout) {
        timeoutExpr = ast_Expression_cast(this->timeout, corto_type(corto_float32_o), FALSE);
        if (timeoutExpr) {
            corto_setref(&this->timeout, timeoutExpr);
        }
    } else {
        this->timeout = ast_Expression(ast_FloatingPointCreate(0));
    }

    /* Set type of expression */
    corto_setref(&ast_Expression(this)->type, resultType);
    ast_Expression(this)->isReference = TRUE; /* Result is always an this */

    return 0;
error:
    return -1;
/* $end */
}

corto_bool _ast_Wait_hasReturnedResource_v(ast_Wait this) {
/* $begin(::corto::ast::Wait::hasReturnedResource) */
    CORTO_UNUSED(this);
    return FALSE;
/* $end */
}

ic_node _ast_Wait_toIc_v(ast_Wait this, ic_program program, ic_storage storage, corto_bool stored) {
/* $begin(::corto::ast::Wait::toIc) */
    corto_iter exprIter;
    ast_Expression expr;
    ic_node ic, result;

    CORTO_UNUSED(stored);

    if (storage) {
        result = (ic_node)storage;
    } else {
        result = (ic_node)ic_program_pushAccumulator(
            program, ast_Expression_getType(ast_Expression(this)), TRUE, FALSE);
    }

    exprIter = corto_llIter(this->exprList);
    while(corto_iterHasNext(&exprIter)) {
        expr = corto_iterNext(&exprIter);

        /* Parse object-expression */
        ic = ast_Node_toIc(ast_Node(expr), program, NULL, TRUE);

        /* Insert waitfor instruction */
        IC_1(program, ast_Node(this)->line, ic_waitfor, ic, 
            expr->isReference ? IC_DEREF_ADDRESS : IC_DEREF_VALUE);
    }

    /* Parse timeout-expression */
    if (this->timeout) {
        ic = ast_Node_toIc(ast_Node(this->timeout), program, NULL, TRUE);
    } else {
        ic = NULL;
    }

    /* Insert wait instruction */
    IC_3(program, ast_Node(this)->line, ic_wait, result, ic, NULL, 
        IC_DEREF_VALUE, IC_DEREF_VALUE, IC_DEREF_VALUE);

    return result;
/* $end */
}
