/* ic_storage.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "ic.h"

/* ::cortex::ic::storage::construct() */
cx_int16 ic_storage_construct(ic_storage _this) {
/* $begin(::cortex::ic::storage::construct) */
    ic_node(_this)->kind = IC_STORAGE;
    return ic_node_construct(ic_node(_this));
/* $end */
}

/* ::cortex::ic::storage::free() */
cx_void ic_storage_free(ic_storage _this) {
/* $begin(::cortex::ic::storage::free) */
    cx_type type = _this->type;
    if (_this->isReference || ((type->kind == CX_PRIMITIVE) && (cx_primitive(type)->kind == CX_TEXT))) {
        ic_op freeIc;
        
        /* Insert free-instruction */
        freeIc = ic_op__create(0, ic_free, ic_node(_this), NULL, NULL, IC_DEREF_VALUE, 0, 0, FALSE);
        if (_this->isReference) {
            freeIc->s1Deref = IC_DEREF_ADDRESS;
        }
        ic_program_add(ic_program_get(), ic_node(freeIc));
    }
/* $end */
}

/* ::cortex::ic::storage::str(string in) */
cx_string ic_storage_str(ic_storage _this, cx_string in) {
/* $begin(::cortex::ic::storage::str) */
    return strappend(in, _this->name);
/* $end */
}
