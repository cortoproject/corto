/* Fast_Temporary.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"

/* ::cortex::Fast::Temporary::construct() */
cx_int16 _Fast_Temporary_construct(Fast_Temporary _this) {
/* $begin(::cortex::Fast::Temporary::construct) */

    Fast_Storage(_this)->kind = Fast_TemporaryStorage;
    cx_setref(&Fast_Expression(_this)->type, _this->type);
    Fast_Expression(_this)->isReference = _this->reference;

    return Fast_Storage_construct(Fast_Storage(_this));
/* $end */
}

/* ::cortex::Fast::Temporary::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Temporary_toIc_v(Fast_Temporary _this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::cortex::Fast::Temporary::toIc) */
    CX_UNUSED(storage);
    CX_UNUSED(stored);
    CX_UNUSED(program);

    if (!_this->ic) {
        _this->ic = (cx_word)ic_accumulator__create(NULL, _this->type, _this->reference || _this->type->reference, FALSE);
    }

    return (ic_node)_this->ic;
/* $end */
}
