/* Fast_Define.c
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

/* ::corto::Fast::Define::construct() */
cx_int16 _Fast_Define_construct(Fast_Define _this) {
/* $begin(::corto::Fast::Define::construct) */

    Fast_Node(_this)->kind = Fast_DefineExpr;

    return 0;
/* $end */
}

/* ::corto::Fast::Define::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Define_toIc_v(Fast_Define _this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::Fast::Define::toIc) */
    ic_node object;
    CX_UNUSED(stored);
    CX_UNUSED(storage);

    object = Fast_Node_toIc(Fast_Node(_this->object), program, NULL, TRUE);
    IC_1(program, Fast_Node(_this)->line, ic_define, object, IC_DEREF_ADDRESS);

    return NULL;
/* $end */
}
