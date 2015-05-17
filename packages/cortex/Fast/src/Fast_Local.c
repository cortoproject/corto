/* Fast_Local.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"

/* $header() */
#include "Fast__private.h"
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

/* ::cortex::Fast::Local::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Local_toIc_v(Fast_Local _this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::cortex::Fast::Local::toIc) */
    ic_node result;
    CX_UNUSED(storage);
    CX_UNUSED(stored);
    CX_UNUSED(program);

    result = (ic_node)ic_program_getVariable(
                program,
                _this->name);

    return result;
/* $end */
}
