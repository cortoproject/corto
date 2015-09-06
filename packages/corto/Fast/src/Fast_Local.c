/* Fast_Local.c
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

/* ::corto::Fast::Local::construct() */
cx_int16 _Fast_Local_construct(Fast_Local this) {
/* $begin(::corto::Fast::Local::construct) */

    Fast_Node(this)->kind = Fast_StorageExpr;
    Fast_Storage(this)->kind = Fast_LocalStorage;
    cx_setref(&Fast_Expression(this)->type, this->type);
    Fast_Expression(this)->isReference = this->reference || this->type->reference;

    return Fast_Storage_construct(Fast_Storage(this));
/* $end */
}

/* ::corto::Fast::Local::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Local_toIc_v(Fast_Local this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::Fast::Local::toIc) */
    ic_node result;
    CX_UNUSED(storage);
    CX_UNUSED(stored);
    CX_UNUSED(program);

    result = (ic_node)ic_program_getVariable(
                program,
                this->name);

    return result;
/* $end */
}
