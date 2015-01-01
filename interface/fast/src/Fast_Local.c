/* Fast_Local.c
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
/* $end */

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::Fast::Local::construct(Local object) */
db_int16 Fast_Local_construct(Fast_Local object) {
/* $begin(::cortex::Fast::Local::construct) */

    Fast_Node(object)->kind = FAST_Variable;
    Fast_Variable(object)->kind = FAST_Local;
    Fast_Expression(object)->type = Fast_Variable(Fast_Object__create(db_typedef(Fast_ObjectBase(object->type)->value)->real));
    object->isReference |= Fast_Expression_getType(Fast_Expression(object))->reference;
    Fast_Expression(object)->isReference = object->isReference;

    if (Fast_Expression_getType(Fast_Expression(object))->reference) {
    	Fast_Expression(object)->forceReference = TRUE;
    }

    return 0;
/* $end */
}

/* ::cortex::Fast::Local::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Local_toIc_v(Fast_Local _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::cortex::Fast::Local::toIc) */
	db_ic result;
	DB_UNUSED(storage);
	DB_UNUSED(stored);

	result = (db_ic)db_icLocal__create(
                program,
                Fast_Node(_this)->line,
                _this->name,
                Fast_Expression_getType(Fast_Expression(_this)),
               _this->kind == FAST_LocalParameter,
               _this->kind == FAST_LocalReturn,
               FALSE);

	if (_this->isReference) {
		((db_icStorage)result)->isReference = TRUE;
	}

	return result;
/* $end */
}
