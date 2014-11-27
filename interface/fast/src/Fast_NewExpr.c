/* Fast_NewExpr.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast_NewExpr.h"
#include "Fast__meta.h"


/* $header() */
#include "Fast__api.h"
#include "Fast_Parser.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
/* $end */

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::NewExpr::construct(Fast::NewExpr object) */
db_int16 Fast_NewExpr_construct(Fast_NewExpr object) {
/* $begin(::hyve::Fast::NewExpr::construct) */

    Fast_Node(object)->kind = FAST_New;
    Fast_Expression(object)->type = Fast_Variable(object->type);
    db_keep_ext(object, object->type, "Set type of Fast::NewExpr");

    return 0;
/* $end */
}

/* ::hyve::Fast::NewExpr::hasSideEffects() */
db_bool Fast_NewExpr_hasSideEffects_v(Fast_NewExpr _this) {
/* $begin(::hyve::Fast::NewExpr::hasSideEffects) */
    DB_UNUSED(_this);
    return TRUE;
/* $end */
}

/* ::hyve::Fast::NewExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_NewExpr_toIc_v(Fast_NewExpr _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::hyve::Fast::NewExpr::toIc) */
	db_ic type, attrs, result;
	db_icOp op;
	DB_UNUSED(stored);

	if (storage) {
		result = (db_ic)storage;
	} else {
		result = (db_ic)db_icProgram_accumulatorPush(program, Fast_Node(_this)->line, Fast_Expression_getType(Fast_Expression(_this)), TRUE);
	}

	type = Fast_Node_toIc(Fast_Node(_this->type), program, NULL, TRUE);
	if (_this->attributes) {
		attrs = Fast_Node_toIc(Fast_Node(_this->attributes), program, NULL, TRUE);
	} else {
		attrs = NULL;
	}

	op = db_icOp__create(program, Fast_Node(_this)->line, DB_IC_NEW, (db_icValue)result, (db_icValue)type, (db_icValue)attrs);
	op->s1Deref = DB_IC_DEREF_ADDRESS;
	db_icProgram_addIc(program, (db_ic)op);

	return result;
/* $end */
}
