/* Fast_While.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"

/* $header() */
#include "Fast__private.h"
/* $end */

/* ::cortex::Fast::While::construct() */
cx_int16 Fast_While_construct(Fast_While _this) {
/* $begin(::cortex::Fast::While::construct) */
    cx_type conditionType;

    Fast_Node(_this)->kind = Fast_WhileExpr;

    conditionType = Fast_Expression_getType(_this->condition);
    if (conditionType) {
        /* Check if condition can evaluate to a boolean value */
        if (!cx_type_castable(cx_type(cx_bool_o), conditionType)) {
            Fast_Parser_error(yparser(), "expression does not evaluate to condition");
            goto error;
        }
    } else {
        Fast_Parser_error(yparser(), "dynamic expressions in while-condition not yet supported");
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::While::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_While_toIc_v(Fast_While _this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::cortex::Fast::While::toIc) */
    ic_storage accumulator;
    ic_label labelEval, labelNeq;
    Fast_Expression condition = NULL;
    cx_bool condResult = FALSE, inverse = FALSE;
    ic_node expr = NULL;
    CX_UNUSED(storage);
    CX_UNUSED(stored);

    /* Obtain accumulator for evaluating the condition */
    accumulator = (ic_storage)ic_program_pushAccumulator(
        program, Fast_Expression_getType(_this->condition), _this->condition->isReference, FALSE);

    /* Create label to jump back to evaluation */
    labelEval = ic_label__create();

    /* Optimize condition - take into account literals, unwind condition for NOT-operator */
    condition = Fast_Node_optimizeCondition(_this->condition, &condResult, &inverse);

    if (!_this->isUntil) {
        if (condition) {
            expr = Fast_Node_toIc(Fast_Node(condition), program, accumulator, TRUE);
        }

        /* Create label to jump to when condition evaluates false */
        labelNeq = ic_label__create();
        
        /* Evaluate condition, insert jump */
        if (expr) {
            IC_3(program, Fast_Node(_this)->line, inverse ? ic_jeq : ic_jneq, expr, labelNeq, NULL,
                IC_DEREF_VALUE, IC_DEREF_VALUE, IC_DEREF_VALUE);
        }
    }

    /* Insert evaluation label */
    ic_program_add(program, ic_node(labelEval));

    /* -- from here it is a straightforward do-while loop */
    ic_program_popAccumulator(program);

    /* Parse block */
    if (_this->trueBranch) {
        if (condition || condResult) {
            if (_this->trueBranch->_while != _this) {
                Fast_Block_toIc(_this->trueBranch, program, NULL, FALSE);
            } else {
                Fast_Block_toIcBody(_this->trueBranch, program, NULL, FALSE);
            }
        }
    }

    /* Parse condition */
    if (condition) {
        expr = Fast_Node_toIc(Fast_Node(condition), program, accumulator, TRUE);
    }

    /* Evaluate condition, insert jump to evaluate */
    if (expr) {
        IC_3(program, Fast_Node(_this)->line, inverse ? ic_jneq : ic_jeq, expr, labelEval, NULL,
            IC_DEREF_VALUE, IC_DEREF_VALUE, IC_DEREF_VALUE);
    }

    if (!_this->isUntil) {
        /* Insert label */
        ic_program_add(program, ic_node(labelNeq));
    }

    return NULL;

/* $end */
}
