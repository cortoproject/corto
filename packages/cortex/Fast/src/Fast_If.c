/* Fast_If.c
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

/* ::cortex::Fast::If::construct() */
cx_int16 _Fast_If_construct(Fast_If _this) {
/* $begin(::cortex::Fast::If::construct) */
    cx_type conditionType;

    Fast_Node(_this)->kind = Fast_IfExpr;

    if (_this->condition) {
        conditionType = Fast_Expression_getType(_this->condition);
        if (conditionType) {
            /* Check if condition can evaluate to a boolean value */
            if ((!_this->condition->deref == Fast_ByReference) && !conditionType->reference && (conditionType->kind != CX_PRIMITIVE)) {
                Fast_Parser_error(yparser(), "expression does not evaluate to condition");
                goto error;
            }
        }
    }
    
    _this->warnUnreachable = TRUE;

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::If::noWarnUnreachable() */
cx_void _Fast_If_noWarnUnreachable(Fast_If _this) {
/* $begin(::cortex::Fast::If::noWarnUnreachable) */
    _this->warnUnreachable = FALSE;
/* $end */
}

/* ::cortex::Fast::If::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_If_toIc_v(Fast_If _this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::cortex::Fast::If::toIc) */
    ic_storage accumulator;
    ic_label labelEval = NULL, labelEnd = NULL;
    ic_node expr;
    cx_bool inverse = FALSE, condResult = FALSE;
    Fast_Expression condition = NULL;
    CX_UNUSED(storage);
    CX_UNUSED(stored);
    
    if (_this->condition && !(condition = Fast_Node_optimizeCondition(_this->condition, &condResult, &inverse))) {
        if (condResult) {
            Fast_Block_toIc(_this->trueBranch, program, NULL, FALSE);
            if (_this->falseBranch && _this->warnUnreachable) {
                Fast_Parser_warning(yparser(), "false-branch has no effect");
            }
        } else if (_this->falseBranch) {
            Fast_If_toIc(_this->falseBranch, program, NULL, FALSE);
            if (_this->trueBranch && _this->warnUnreachable) {
                Fast_Parser_warning(yparser(), "true-branch has no effect");
            }
        }
    } else {

        /* The if-statement will insert the false-branch before the true branch. The reason for this is that
         * the first branch that comes directly after the condition evaluation, needs a second jump to
         * jump over the other branch. Assuming that the true-branch is most commonly occurring, it makes
         * sense to optimize for this case.
         * If there is no false-branch, obviously the true-branch is first to insert.
         */

        /* Parse condition (if no condition, assume true) */
        if (_this->condition) {
            ic_derefKind deref1 = IC_DEREF_VALUE;

            if (condition->deref == Fast_ByReference) {
                deref1 = IC_DEREF_ADDRESS;
            }

            /* Obtain accumulator for evaluating the condition */
            accumulator = (ic_storage)ic_program_pushAccumulator(
                program,
                Fast_Expression_getType(_this->condition),
                _this->condition->isReference,
                FALSE);

            /* Parse condition */
            expr = Fast_Node_toIc(Fast_Node(condition), program, accumulator, TRUE);

            /* Create label to jump to when condition evaluates true */
            labelEval = ic_label__create();

            /* Evaluate condition, insert jump */
            if (_this->falseBranch) {
                IC_3(program, Fast_Node(_this)->line, inverse ? ic_jneq : ic_jeq, expr, 
                    labelEval, NULL, deref1, IC_DEREF_VALUE, IC_DEREF_VALUE);

                /* Label to jump over true-branch */
                labelEnd = ic_label__create();
            } else {
                IC_3(program, Fast_Node(_this)->line, inverse ? ic_jeq : ic_jneq, expr,
                    labelEval, NULL, deref1, IC_DEREF_VALUE, IC_DEREF_VALUE);
            }

            ic_program_popAccumulator(program);
        }

        /* Parse false-branch if provided */
        if (_this->falseBranch) {
            Fast_If_toIc(_this->falseBranch, program, NULL, TRUE);

            /* Insert jump to end (would otherwise continue at true-branch) */
            IC_1(program, Fast_Node(_this)->line, ic_jump, labelEnd, IC_DEREF_VALUE);

            /* If condition evaluates true, jump to this label */
            ic_program_add(program, ic_node(labelEval));
        }

        /* Insert true-branch */
        Fast_Block_toIc(_this->trueBranch, program, NULL, FALSE);
        if (_this->condition && !_this->falseBranch) {
            ic_program_add(program, (ic_node)labelEval);
        }

        if (_this->falseBranch) {
            ic_program_add(program, (ic_node)labelEnd);
        }
    }

    return NULL;
/* $end */
}
