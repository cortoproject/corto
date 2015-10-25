/* $CORTO_GENERATED
 *
 * ic_storage.c
 *
 * Code written between the begin and end tags will be preserved when the
 * file is regenerated.
 */

#include "ic.h"

corto_int16 _ic_storage_construct(ic_storage this) {
/* $begin(::corto::ic::storage::construct) */
    ic_node(this)->kind = IC_STORAGE;
    return ic_node_construct(ic_node(this));
/* $end */
}

corto_void _ic_storage_free(ic_storage this) {
/* $begin(::corto::ic::storage::free) */
    corto_type type = this->type;
    if (this->isReference || ((type->kind == CORTO_PRIMITIVE) && (corto_primitive(type)->kind == CORTO_TEXT))) {
        ic_op freeIc;

        /* Insert free-instruction */
        freeIc = ic_opCreate(0, ic_free, ic_node(this), NULL, NULL, IC_DEREF_VALUE, 0, 0, FALSE);
        if (this->isReference) {
            freeIc->s1Deref = IC_DEREF_ADDRESS;
        }
        ic_program_add(ic_program_get(), ic_node(freeIc));
    }
/* $end */
}

corto_string _ic_storage_str(ic_storage this, corto_string in) {
/* $begin(::corto::ic::storage::str) */
    return strappend(in, this->name);
/* $end */
}
