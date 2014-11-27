/* Fast_If.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast_If.h"
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

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::If::construct(If object) */
db_int16 Fast_If_construct(Fast_If object) {
/* $begin(::hyve::Fast::If::construct) */
	db_type conditionType;

	Fast_Node(object)->kind = FAST_If;

	if (object->condition) {
		conditionType = Fast_Expression_getType(object->condition);
		if (conditionType) {
			/* Check if condition can evaluate to a boolean value */
			if (!object->condition->forceReference && !conditionType->reference && (conditionType->kind != DB_PRIMITIVE)) {
				Fast_Parser_error(yparser(), "expression does not evaluate to condition");
				goto error;
			}
		}
	}
    
    object->warnUnreachable = TRUE;

	return 0;
error:
	return -1;
/* $end */
}

/* ::hyve::Fast::If::noWarnUnreachable() */
void Fast_If_noWarnUnreachable(Fast_If _this) {
/* $begin(::hyve::Fast::If::noWarnUnreachable) */
    _this->warnUnreachable = FALSE;
/* $end */
}

/* ::hyve::Fast::If::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_If_toIc_v(Fast_If _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::hyve::Fast::If::toIc) */
	db_icStorage accumulator;
	db_icLabel labelEval = NULL, labelEnd = NULL;
	db_ic expr;
	db_icOp eval, jumpEnd;
    db_bool inverse = FALSE, condResult = FALSE;
    Fast_Expression condition = NULL;
	DB_UNUSED(storage);
	DB_UNUSED(stored);
    
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
			accumulator = (db_icStorage)db_icProgram_accumulatorPush(
				program, 
				Fast_Node(_this)->line, 
				Fast_Expression_getType(_this->condition),
				_this->condition->isReference);

			/* Parse condition */
			expr = Fast_Node_toIc(Fast_Node(condition), program, accumulator, TRUE);

			/* Create label to jump to when condition evaluates true */
			labelEval = db_icLabel__create(program, Fast_Node(_this)->line);

			/* Evaluate condition, insert jump */
			if (_this->falseBranch) {
				eval = db_icOp__create(program, Fast_Node(_this)->line, inverse ? DB_IC_JNEQ : DB_IC_JEQ, (db_icValue)expr, (db_icValue)labelEval, NULL);
				db_icProgram_addIc(program, (db_ic)eval);

				/* Label to jump over true-branch */
				labelEnd = db_icLabel__create(program, Fast_Node(_this)->line);
			} else {
				eval = db_icOp__create(program, Fast_Node(_this)->line, inverse ? DB_IC_JEQ : DB_IC_JNEQ, (db_icValue)expr, (db_icValue)labelEval, NULL);
				db_icProgram_addIc(program, (db_ic)eval);
			}

			if (condition->forceReference) {
				eval->s1Deref = DB_IC_DEREF_ADDRESS;
			}

			db_icProgram_accumulatorPop(program, Fast_Node(_this)->line);
		}

		/* Parse false-branch if provided */
		if (_this->falseBranch) {
			Fast_If_toIc(_this->falseBranch, program, NULL, TRUE);

			/* Insert jump to end (would otherwise continue at true-branch) */
			jumpEnd = db_icOp__create(program, Fast_Node(_this)->line, DB_IC_JUMP, (db_icValue)labelEnd, NULL, NULL);
			db_icProgram_addIc(program, (db_ic)jumpEnd);

			/* If condition evaluates true, jump to this label */
			db_icProgram_addIc(program, (db_ic)labelEval);
		}

		/* Insert true-branch */
		Fast_Block_toIc(_this->trueBranch, program, NULL, FALSE);
		if (_this->condition && !_this->falseBranch) {
			db_icProgram_addIc(program, (db_ic)labelEval);
		}

		if (_this->falseBranch) {
			db_icProgram_addIc(program, (db_ic)labelEnd);
		}
	}

	return NULL;
/* $end */
}
