/* Fast_Define.c
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

/* ::cortex::Fast::Define::construct() */
cx_int16 Fast_Define_construct(Fast_Define _this) {
/* $begin(::cortex::Fast::Define::construct) */

    Fast_Node(_this)->kind = Fast_DefineExpr;

    return 0;
/* $end */
}

/* ::cortex::Fast::Define::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Define_toIc_v(Fast_Define _this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::cortex::Fast::Define::toIc) */
    ic_node object;
    CX_UNUSED(stored);
    CX_UNUSED(storage);

    object = Fast_Node_toIc(Fast_Node(_this->object), program, NULL, TRUE);
    IC_1(program, Fast_Node(_this)->line, ic_define, object, IC_DEREF_ADDRESS);

    return NULL;
/* $end */
}
