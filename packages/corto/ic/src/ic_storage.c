/* ic_storage.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "ic.h"

/* ::corto::ic::storage::construct() */
corto_int16 _ic_storage_construct(ic_storage this) {
/* $begin(::corto::ic::storage::construct) */
    ic_node(this)->kind = IC_STORAGE;
    return ic_node_construct(ic_node(this));
/* $end */
}

/* ::corto::ic::storage::free() */
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

/* ::corto::ic::storage::str(string in) */
corto_string _ic_storage_str(ic_storage this, corto_string in) {
/* $begin(::corto::ic::storage::str) */
    return strappend(in, this->name);
/* $end */
}
