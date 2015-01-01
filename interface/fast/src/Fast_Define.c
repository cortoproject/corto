/* Fast_Define.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"
#include "Fast__meta.h"

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::Fast::Define::construct(Fast::Define object) */
db_int16 Fast_Define_construct(Fast_Define object) {
/* $begin(::cortex::Fast::Define::construct) */

    Fast_Node(object)->kind = FAST_Define;

    return 0;
/* $end */
}

/* ::cortex::Fast::Define::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Define_toIc_v(Fast_Define _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::cortex::Fast::Define::toIc) */
	db_ic object;
	db_icOp op;
	DB_UNUSED(stored);
	DB_UNUSED(storage);

	object = Fast_Node_toIc(Fast_Node(_this->object), program, NULL, TRUE);

	op = db_icOp__create(program, Fast_Node(_this)->line, DB_IC_DEFINE, (db_icValue)object, NULL, NULL);
	db_icProgram_addIc(program, (db_ic)op);

    op->s1Deref = DB_IC_DEREF_ADDRESS;

	return NULL;
/* $end */
}
