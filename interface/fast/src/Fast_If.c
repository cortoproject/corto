/* Fast_If.c
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
#include "Fast.h"
#include "Fast_Expression.h"
#include "Fast_Block.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
void Fast_Parser_warning(Fast_Parser _this, char* fmt, ...);
/* $end */

/* ::cortex::Fast::If::construct() */
cx_int16 Fast_If_construct(Fast_If _this) {
/* $begin(::cortex::Fast::If::construct) */
    cx_type conditionType;

    Fast_Node(_this)->kind = FAST_If;

    if (_this->condition) {
        conditionType = Fast_Expression_getType(_this->condition);
        if (conditionType) {
            /* Check if condition can evaluate to a boolean value */
            if (!_this->condition->forceReference && !conditionType->reference && (conditionType->kind != CX_PRIMITIVE)) {
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
cx_void Fast_If_noWarnUnreachable(Fast_If _this) {
/* $begin(::cortex::Fast::If::noWarnUnreachable) */
    _this->warnUnreachable = FALSE;
/* $end */
}

/* ::cortex::Fast::If::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_If_toIc_v(Fast_If _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::If::toIc) */
    cx_icStorage accumulator;
    cx_icLabel labelEval = NULL, labelEnd = NULL;
    cx_ic expr;
    cx_icOp eval, jumpEnd;
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

            /* Obtain accumulator for evaluating the condition */
            accumulator = (cx_icStorage)cx_icProgram_accumulatorPush(
                program, 
                Fast_Node(_this)->line, 
                Fast_Expression_getType(_this->condition),
                _this->condition->isReference);

            /* Parse condition */
            expr = Fast_Node_toIc(Fast_Node(condition), program, accumulator, TRUE);

            /* Create label to jump to when condition evaluates true */
            labelEval = cx_icLabel__create(program, Fast_Node(_this)->line);

            /* Evaluate condition, insert jump */
            if (_this->falseBranch) {
                eval = cx_icOp__create(program, Fast_Node(_this)->line, inverse ? CX_IC_JNEQ : CX_IC_JEQ, (cx_icValue)expr, (cx_icValue)labelEval, NULL);
                cx_icProgram_addIc(program, (cx_ic)eval);

                /* Label to jump over true-branch */
                labelEnd = cx_icLabel__create(program, Fast_Node(_this)->line);
            } else {
                eval = cx_icOp__create(program, Fast_Node(_this)->line, inverse ? CX_IC_JEQ : CX_IC_JNEQ, (cx_icValue)expr, (cx_icValue)labelEval, NULL);
                cx_icProgram_addIc(program, (cx_ic)eval);
            }

            if (condition->forceReference) {
                eval->s1Deref = CX_IC_DEREF_ADDRESS;
            }

            cx_icProgram_accumulatorPop(program, Fast_Node(_this)->line);
        }

        /* Parse false-branch if provided */
        if (_this->falseBranch) {
            Fast_If_toIc(_this->falseBranch, program, NULL, TRUE);

            /* Insert jump to end (would otherwise continue at true-branch) */
            jumpEnd = cx_icOp__create(program, Fast_Node(_this)->line, CX_IC_JUMP, (cx_icValue)labelEnd, NULL, NULL);
            cx_icProgram_addIc(program, (cx_ic)jumpEnd);

            /* If condition evaluates true, jump to this label */
            cx_icProgram_addIc(program, (cx_ic)labelEval);
        }

        /* Insert true-branch */
        Fast_Block_toIc(_this->trueBranch, program, NULL, FALSE);
        if (_this->condition && !_this->falseBranch) {
            cx_icProgram_addIc(program, (cx_ic)labelEval);
        }

        if (_this->falseBranch) {
            cx_icProgram_addIc(program, (cx_ic)labelEnd);
        }
    }

    return NULL;
/* $end */
}
