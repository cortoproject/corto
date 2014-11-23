/* Fast_While.c
 *
 *  Generated on Nov 18 2014
 *    This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast_While.h"
#include "Fast__meta.h"


/* $header() */
#include "Fast__api.h"
#include "Fast.h"
#include "Fast_Expression.h"
#include "Fast_Block.h"
#include "db_ic.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
/* $end */

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::While::construct(While object) */
db_int16 Fast_While_construct(Fast_While object) {
/* $begin(::hyve::Fast::While::construct) */
	db_type conditionType;

	Fast_Node(object)->kind = FAST_While;

	conditionType = Fast_Expression_getType(object->condition);
	if (conditionType) {
		/* Check if condition can evaluate to a boolean value */
		if (!db_type_castable(db_type(db_bool_o), conditionType)) {
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

/* virtual ::hyve::Fast::While::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_While_toIc(Fast_While _this, db_icProgram program, db_icStorage storage, db_bool stored) {
    static db_uint32 _methodId;
    db_method _method;
    db_ic _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)");
    }
    db_assert(_methodId, "virtual method 'toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)@%d'", db_nameof(_this), _methodId);

    /* Call method directly if it's a C-function. */
    if (_method->_parent.kind == DB_PROCEDURE_CDECL) {
        db_assert(_method->_parent.impl, "missing implementation for '%s::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.", db_nameof(_this));
        _result = ((db_ic(*)(Fast_While, db_icProgram , db_icStorage , db_bool ))_method->_parent.impl)(_this, program, storage, stored);
    } else {
        /* Function is implemented in another language. */
        db_call(db_function(_method), &_result, _this, program, storage, stored);
    }
    
    return _result;
}

/* ::hyve::Fast::While::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_While_toIc_v(Fast_While _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::hyve::Fast::While::toIc) */
	db_icStorage accumulator;
	db_icLabel labelEval, labelNeq;
    Fast_Expression condition = NULL;
    db_bool condResult = FALSE, inverse = FALSE;
	db_ic expr = NULL;
	db_icOp eval;
	DB_UNUSED(storage);
	DB_UNUSED(stored);

	/* Obtain accumulator for evaluating the condition */
	accumulator = (db_icStorage)db_icProgram_accumulatorPush(
        program, Fast_Node(_this)->line, Fast_Expression_getType(_this->condition), _this->condition->isReference);

	/* Create label to jump back to evaluation */
	labelEval = db_icLabel__create(program, Fast_Node(_this)->line);

    /* Optimize condition - take into account literals, unwind condition for NOT-operator */
    condition = Fast_Node_optimizeCondition(_this->condition, &condResult, &inverse);
    if (condition) {
        expr = Fast_Node_toIc(Fast_Node(condition), program, accumulator, TRUE);
    }
    
    if (!_this->isUntil) {
        /* Create label to jump to when condition evaluates false */
        labelNeq = db_icLabel__create(program, Fast_Node(_this)->line);
        
        /* Evaluate condition, insert jump */
        if (expr) {
            eval = db_icOp__create(program, Fast_Node(_this)->line, inverse?DB_IC_JEQ:DB_IC_JNEQ, (db_icValue)expr, (db_icValue)labelNeq, NULL);
            db_icProgram_addIc(program, (db_ic)eval);
        }
    }

	/* Insert evaluation label */
	db_icProgram_addIc(program, (db_ic)labelEval);

	/* -- from here it is a straightforward do-while loop */
	db_icProgram_accumulatorPop(program, Fast_Node(_this)->line);

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
        eval = db_icOp__create(program, Fast_Node(_this)->line, inverse?DB_IC_JNEQ:DB_IC_JEQ, (db_icValue)expr, (db_icValue)labelEval, NULL);
        db_icProgram_addIc(program, (db_ic)eval);
    }

    if (!_this->isUntil) {
        /* Insert label */
        db_icProgram_addIc(program, (db_ic)labelNeq);
    }

	return NULL;

/* $end */
}
