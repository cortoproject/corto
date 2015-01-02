/* Fast_While.c
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
#include "cx_ic.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
/* $end */

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::Fast::While::construct(While object) */
cx_int16 Fast_While_construct(Fast_While object) {
/* $begin(::cortex::Fast::While::construct) */
    cx_type conditionType;

    Fast_Node(object)->kind = FAST_While;

    conditionType = Fast_Expression_getType(object->condition);
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

/* ::cortex::Fast::While::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
cx_ic Fast_While_toIc_v(Fast_While _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::While::toIc) */
    cx_icStorage accumulator;
    cx_icLabel labelEval, labelNeq;
    Fast_Expression condition = NULL;
    cx_bool condResult = FALSE, inverse = FALSE;
    cx_ic expr = NULL;
    cx_icOp eval;
    CX_UNUSED(storage);
    CX_UNUSED(stored);

    /* Obtain accumulator for evaluating the condition */
    accumulator = (cx_icStorage)cx_icProgram_accumulatorPush(
        program, Fast_Node(_this)->line, Fast_Expression_getType(_this->condition), _this->condition->isReference);

    /* Create label to jump back to evaluation */
    labelEval = cx_icLabel__create(program, Fast_Node(_this)->line);

    /* Optimize condition - take into account literals, unwind condition for NOT-operator */
    condition = Fast_Node_optimizeCondition(_this->condition, &condResult, &inverse);
    if (condition) {
        expr = Fast_Node_toIc(Fast_Node(condition), program, accumulator, TRUE);
    }
    
    if (!_this->isUntil) {
        /* Create label to jump to when condition evaluates false */
        labelNeq = cx_icLabel__create(program, Fast_Node(_this)->line);
        
        /* Evaluate condition, insert jump */
        if (expr) {
            eval = cx_icOp__create(program, Fast_Node(_this)->line, inverse?CX_IC_JEQ:CX_IC_JNEQ, (cx_icValue)expr, (cx_icValue)labelNeq, NULL);
            cx_icProgram_addIc(program, (cx_ic)eval);
        }
    }

    /* Insert evaluation label */
    cx_icProgram_addIc(program, (cx_ic)labelEval);

    /* -- from here it is a straightforward do-while loop */
    cx_icProgram_accumulatorPop(program, Fast_Node(_this)->line);

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
        eval = cx_icOp__create(program, Fast_Node(_this)->line, inverse?CX_IC_JNEQ:CX_IC_JEQ, (cx_icValue)expr, (cx_icValue)labelEval, NULL);
        cx_icProgram_addIc(program, (cx_ic)eval);
    }

    if (!_this->isUntil) {
        /* Insert label */
        cx_icProgram_addIc(program, (cx_ic)labelNeq);
    }

    return NULL;

/* $end */
}
