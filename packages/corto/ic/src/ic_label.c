/* ic_label.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_ic_LIB
#include "ic.h"

/* ::corto::ic::label::construct() */
cx_int16 _ic_label_construct(ic_label this) {
/* $begin(::corto::ic::label::construct) */
    ic_node(this)->kind = IC_LABEL;
    this->id = ic_program_getLabel(ic_program_get());
    return ic_node_construct(ic_node(this));
/* $end */
}

/* ::corto::ic::label::str(string in) */
cx_string _ic_label_str(ic_label this, cx_string in) {
/* $begin(::corto::ic::label::str) */
    in = strappend(in, "%%L%d", this->id);
    return in;
/* $end */
}
