/* Fast_Init.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_Fast_LIB
#include "Fast.h"

/* $header() */
#include "Fast__private.h"
/* $end */

/* ::corto::Fast::Init::construct() */
cx_int16 _Fast_Init_construct(Fast_Init _this) {
/* $begin(::corto::Fast::Init::construct) */
	cx_type t = Fast_Expression_getType(Fast_Expression(_this->storage));
    Fast_Node(_this)->kind = Fast_InitExpr;
    cx_setref(&Fast_Expression(_this)->type, t);
    return 0;
/* $end */
}

/* ::corto::Fast::Init::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Init_toIc_v(Fast_Init _this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::Fast::Init::toIc) */
    ic_node s;
    CX_UNUSED(stored);
    CX_UNUSED(storage);

    s = Fast_Node_toIc(Fast_Node(_this->storage), program, NULL, TRUE);
    IC_1(program, Fast_Node(_this)->line, ic_init, s, IC_DEREF_ADDRESS);

    return NULL;
/* $end */
}
