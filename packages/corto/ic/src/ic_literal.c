/* ic_literal.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_ic_LIB
#include "ic.h"

/* ::corto::ic::literal::construct() */
cx_int16 _ic_literal_construct(ic_literal this) {
/* $begin(::corto::ic::literal::construct) */
    ic_node(this)->kind = IC_LITERAL;
    return ic_node_construct(ic_node(this));
/* $end */
}

/* ::corto::ic::literal::str(string in) */
cx_string _ic_literal_str(ic_literal this, cx_string in) {
/* $begin(::corto::ic::literal::str) */
    cx_string result = NULL;

    if (this->value.value) {
        if (cx_primitive(this->value.type)->kind == CX_TEXT) {
            in = strappend(in, "\"");
        }
        cx_convert(cx_primitive(this->value.type), this->value.value, cx_primitive(cx_string_o), &result);
        in = strappend(in, result);
        cx_dealloc(result);
        if (cx_primitive(this->value.type)->kind == CX_TEXT) {
            in = strappend(in, "\"");
        }
    } else {
        in = strappend(in, "(null)");
    }

    return in;
/* $end */
}
