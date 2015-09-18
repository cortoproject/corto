/* ast_While.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_ast_LIB
#include "ast.h"

/* $header() */
#include "ast__private.h"
/* $end */

/* ::corto::ast::While::construct() */
cx_int16 _ast_While_construct(ast_While this) {
/* $begin(::corto::ast::While::construct) */
    cx_type conditionType;

    ast_Node(this)->kind = Ast_WhileExpr;

    conditionType = ast_Expression_getType(this->condition);
    if (conditionType) {
        /* Check if condition can evaluate to a boolean value */
        if (!cx_type_castable(cx_type(cx_bool_o), conditionType)) {
            ast_Parser_error(yparser(), "expression does not evaluate to condition");
            goto error;
        }
    } else {
        ast_Parser_error(yparser(), "dynamic expressions in while-condition not yet supported");
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::ast::While::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _ast_While_toIc_v(ast_While this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::ast::While::toIc) */
    ic_storage accumulator;
    ic_label labelEval, labelNeq = NULL;
    ast_Expression condition = NULL;
    cx_bool condResult = FALSE, inverse = FALSE;
    ic_node expr = NULL;
    CX_UNUSED(storage);
    CX_UNUSED(stored);

    /* Obtain accumulator for evaluating the condition */
    accumulator = (ic_storage)ic_program_pushAccumulator(
        program, ast_Expression_getType(this->condition), this->condition->isReference, FALSE);

    /* Create label to jump back to evaluation */
    labelEval = ic_labelCreate();

    /* Optimize condition - take into account literals, unwind condition for NOT-operator */
    condition = ast_Node_optimizeCondition(this->condition, &condResult, &inverse);

    if (!this->isUntil) {
        if (condition) {
            expr = ast_Node_toIc(ast_Node(condition), program, accumulator, TRUE);
        }

        /* Create label to jump to when condition evaluates false */
        labelNeq = ic_labelCreate();
        
        /* Evaluate condition, insert jump */
        if (expr) {
            IC_3(program, ast_Node(this)->line, inverse ? ic_jeq : ic_jneq, expr, labelNeq, NULL,
                IC_DEREF_VALUE, IC_DEREF_VALUE, IC_DEREF_VALUE);
        }
    }

    /* Insert evaluation label */
    ic_program_add(program, ic_node(labelEval));

    /* -- from here it is a straightforward do-while loop */
    ic_program_popAccumulator(program);

    /* Parse block */
    if (this->trueBranch) {
        if (condition || condResult) {
            if (this->trueBranch->_while != this) {
                ast_Block_toIc(this->trueBranch, program, NULL, FALSE);
            } else {
                ast_Block_toIcBody(this->trueBranch, program, NULL, FALSE);
            }
        }
    }

    /* Parse condition */
    if (condition) {
        expr = ast_Node_toIc(ast_Node(condition), program, accumulator, TRUE);
    }

    /* Evaluate condition, insert jump to evaluate */
    if (expr) {
        IC_3(program, ast_Node(this)->line, inverse ? ic_jneq : ic_jeq, expr, labelEval, NULL,
            IC_DEREF_VALUE, IC_DEREF_VALUE, IC_DEREF_VALUE);
    }

    if (!this->isUntil) {
        /* Insert label */
        ic_program_add(program, ic_node(labelNeq));
    }

    return NULL;

/* $end */
}
