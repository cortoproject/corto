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

/* callback ::cortex::lang::class::construct(object object) -> ::cortex::Fast::Local::construct(Local object) */
cx_int16 Fast_Local_construct(Fast_Local object) {
/* $begin(::cortex::Fast::Local::construct) */

    Fast_Node(object)->kind = FAST_Variable;
    Fast_Variable(object)->kind = FAST_Local;
    Fast_Expression(object)->type = 
        Fast_Variable(Fast_Object__create(cx_typedef(Fast_ObjectBase(object->type)->value)->real));
    object->isReference |= Fast_Expression_getType(Fast_Expression(object))->reference;
    Fast_Expression(object)->isReference = object->isReference;

    if (Fast_Expression_getType(Fast_Expression(object))->reference) {
        Fast_Expression(object)->forceReference = TRUE;
    }

    return 0;
/* $end */
}

/* ::cortex::Fast::Local::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Local_toIc_v(Fast_Local _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::Local::toIc) */
    cx_ic result;
    CX_UNUSED(storage);
    CX_UNUSED(stored);

    result = (cx_ic)cx_icLocal__create(
                program,
                Fast_Node(_this)->line,
                _this->name,
                Fast_Expression_getType(Fast_Expression(_this)),
               _this->kind == FAST_LocalParameter,
               _this->kind == FAST_LocalReturn,
               FALSE);

    if (_this->isReference) {
        ((cx_icStorage)result)->isReference = TRUE;
    }

    return result;
/* $end */
}
