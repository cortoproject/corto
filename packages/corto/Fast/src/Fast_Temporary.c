/* Fast_Temporary.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_Fast_LIB
#include "Fast.h"

/* ::corto::Fast::Temporary::construct() */
cx_int16 _Fast_Temporary_construct(Fast_Temporary this) {
/* $begin(::corto::Fast::Temporary::construct) */

    Fast_Storage(this)->kind = Fast_TemporaryStorage;
    cx_setref(&Fast_Expression(this)->type, this->type);
    Fast_Expression(this)->isReference = this->reference;

    return Fast_Storage_construct(Fast_Storage(this));
/* $end */
}

/* ::corto::Fast::Temporary::setProxy(Temporary proxy) */
cx_void _Fast_Temporary_setProxy(Fast_Temporary this, Fast_Temporary proxy) {
/* $begin(::corto::Fast::Temporary::setProxy) */
    cx_setref(&this->proxy, proxy);
/* $end */
}

/* ::corto::Fast::Temporary::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Temporary_toIc_v(Fast_Temporary this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::Fast::Temporary::toIc) */
    CX_UNUSED(storage);
    CX_UNUSED(stored);
    CX_UNUSED(program);

    if (!this->proxy && !this->ic) {
        ic_node acc = ic_node(ic_accumulatorCreate(NULL, this->type, this->reference || this->type->reference, FALSE));
        cx_setref(&this->ic, acc);
        cx_release(acc);
    } else if (this->proxy) {
        ic_node acc = Fast_Temporary_toIc(this->proxy, program, storage, stored);
        cx_setref(&this->ic, acc);
    }

    return this->ic;
/* $end */
}
