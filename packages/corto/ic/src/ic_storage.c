/* ic_storage.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_ic_LIB
#include "ic.h"

/* ::corto::ic::storage::construct() */
cx_int16 _ic_storage_construct(ic_storage this) {
/* $begin(::corto::ic::storage::construct) */
    ic_node(this)->kind = IC_STORAGE;
    return ic_node_construct(ic_node(this));
/* $end */
}

/* ::corto::ic::storage::free() */
cx_void _ic_storage_free(ic_storage this) {
/* $begin(::corto::ic::storage::free) */
    cx_type type = this->type;
    if (this->isReference || ((type->kind == CX_PRIMITIVE) && (cx_primitive(type)->kind == CX_TEXT))) {
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
cx_string _ic_storage_str(ic_storage this, cx_string in) {
/* $begin(::corto::ic::storage::str) */
    return strappend(in, this->name);
/* $end */
}
