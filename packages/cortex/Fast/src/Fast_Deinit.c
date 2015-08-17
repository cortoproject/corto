/* Fast_Deinit.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"

/* $header() */
#include "Fast__private.h"
/* $end */

/* ::cortex::Fast::Deinit::construct() */
cx_int16 _Fast_Deinit_construct(Fast_Deinit _this) {
/* $begin(::cortex::Fast::Deinit::construct) */
	cx_type t = Fast_Expression_getType(Fast_Expression(_this->storage));
    Fast_Node(_this)->kind = Fast_DeinitExpr;
    cx_setref(&Fast_Expression(_this)->type, t);
    return 0;
/* $end */
}

/* ::cortex::Fast::Deinit::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Deinit_toIc_v(Fast_Deinit _this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::cortex::Fast::Deinit::toIc) */
    ic_node s;
    CX_UNUSED(stored);
    CX_UNUSED(storage);

    s = Fast_Node_toIc(Fast_Node(_this->storage), program, NULL, TRUE);
    IC_1(program, Fast_Node(_this)->line, ic_deinit, s, IC_DEREF_ADDRESS);

    return NULL;
/* $end */
}
