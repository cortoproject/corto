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
cx_int16 Fast_Define_construct(Fast_Define object) {
/* $begin(::cortex::Fast::Define::construct) */

    Fast_Node(object)->kind = FAST_Define;

    return 0;
/* $end */
}

/* ::cortex::Fast::Define::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
cx_ic Fast_Define_toIc_v(Fast_Define _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::Define::toIc) */
    cx_ic object;
    cx_icOp op;
    CX_UNUSED(stored);
    CX_UNUSED(storage);

    object = Fast_Node_toIc(Fast_Node(_this->object), program, NULL, TRUE);

    op = cx_icOp__create(program, Fast_Node(_this)->line, CX_IC_DEFINE, (cx_icValue)object, NULL, NULL);
    cx_icProgram_addIc(program, (cx_ic)op);

    op->s1Deref = CX_IC_DEREF_ADDRESS;

    return NULL;
/* $end */
}
