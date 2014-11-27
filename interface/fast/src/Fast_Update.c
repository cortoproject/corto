/* Fast_Update.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast_Update.h"
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

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::Update::construct(Update object) */
db_int16 Fast_Update_construct(Fast_Update object) {
/* $begin(::hyve::Fast::Update::construct) */
	db_type t;
	db_iter exprIter;
	Fast_Expression expr;

    Fast_Node(object)->kind = FAST_Update;

    exprIter = db_llIter(object->exprList);
    while(db_iterHasNext(&exprIter)) {
    	expr = db_iterNext(&exprIter);
    	t = Fast_Expression_getType(expr);
    	if (!t->reference) {
    		if (!expr->isReference) {
    			Fast_Parser_error(yparser(), "one or more expressions in the update statement are not of a reference type");
    			goto error;
    		}
    	}
    }

    return 0;
error:
	return -1;
/* $end */
}

/* ::hyve::Fast::Update::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Update_toIc_v(Fast_Update _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::hyve::Fast::Update::toIc) */
    db_ic expr, from = NULL;
    db_iter exprIter;
    db_icOp op;
    DB_UNUSED(storage);
    DB_UNUSED(stored);

    /* Evaluate expression */
    if (_this->from) {
    	from = Fast_Node_toIc(Fast_Node(_this->from), program, NULL, TRUE);
    }

    /* Add update statement for each expression in exprList */
    exprIter = db_llIter(_this->exprList);
    while(db_iterHasNext(&exprIter)) {
    	Fast_Expression fastExpr = db_iterNext(&exprIter);
    	expr = Fast_Node_toIc(Fast_Node(fastExpr), program, NULL, TRUE);
		if (!_this->block) {
			op = db_icOp__create(program, Fast_Node(_this)->line, DB_IC_UPDATE, (db_icValue)expr, (db_icValue)from, NULL);
			db_icProgram_addIc(program, (db_ic)op);
			op->s1Deref = DB_IC_DEREF_ADDRESS;

		} else {
			op = db_icOp__create(program, Fast_Node(_this)->line, DB_IC_UPDATEBEGIN, (db_icValue)expr, NULL, NULL);
			db_icProgram_addIc(program, (db_ic)op);
			op->s1Deref = DB_IC_DEREF_ADDRESS;
		}
    }

    if (_this->block) {
        /* Translate block to ic */
        Fast_Block_toIc(_this->block, program, NULL, FALSE);

        exprIter = db_llIter(_this->exprList);
        while(db_iterHasNext(&exprIter)) {
        	Fast_Expression fastExpr = db_iterNext(&exprIter);
        	expr = Fast_Node_toIc(Fast_Node(fastExpr), program, NULL, TRUE);
			op = db_icOp__create(program, Fast_Node(_this)->line, DB_IC_UPDATEEND, (db_icValue)expr, (db_icValue)from, NULL);
			db_icProgram_addIc(program, (db_ic)op);
			op->s1Deref = DB_IC_DEREF_ADDRESS;
        }
    }

    return NULL;
/* $end */
}
