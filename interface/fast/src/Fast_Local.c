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

/* ::cortex::Fast::Local::construct() */
cx_int16 Fast_Local_construct(Fast_Local _this) {
/* $begin(::cortex::Fast::Local::construct) */

    Fast_Node(_this)->kind = Fast_StorageExpr;
    Fast_Storage(_this)->kind = Fast_LocalStorage;
    cx_set(&Fast_Expression(_this)->type, _this->type);
    Fast_Expression(_this)->isReference = _this->reference || _this->type->reference;

    return Fast_Storage_construct(Fast_Storage(_this));
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
               _this->kind == Fast_LocalParameter,
               _this->kind == Fast_LocalReturn,
               FALSE);

    if (Fast_Expression(_this)->isReference) {
        ((cx_icStorage)result)->isReference = TRUE;
    }

    return result;
/* $end */
}
