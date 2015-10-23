/* ic_literal.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "ic.h"

/* ::corto::ic::literal::construct() */
corto_int16 _ic_literal_construct(ic_literal this) {
/* $begin(::corto::ic::literal::construct) */
    ic_node(this)->kind = IC_LITERAL;
    return ic_node_construct(ic_node(this));
/* $end */
}

/* ::corto::ic::literal::str(string in) */
corto_string _ic_literal_str(ic_literal this, corto_string in) {
/* $begin(::corto::ic::literal::str) */
    corto_string result = NULL;

    if (this->value.value) {
        if (corto_primitive(this->value.type)->kind == CORTO_TEXT) {
            in = strappend(in, "\"");
        }
        corto_convert(corto_primitive(this->value.type), this->value.value, corto_primitive(corto_string_o), &result);
        in = strappend(in, result);
        corto_dealloc(result);
        if (corto_primitive(this->value.type)->kind == CORTO_TEXT) {
            in = strappend(in, "\"");
        }
    } else {
        in = strappend(in, "(null)");
    }

    return in;
/* $end */
}
