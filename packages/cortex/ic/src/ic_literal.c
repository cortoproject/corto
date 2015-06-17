/* ic_literal.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "ic.h"

/* ::cortex::ic::literal::construct() */
cx_int16 ic_literal_construct(ic_literal _this) {
/* $begin(::cortex::ic::literal::construct) */
    ic_node(_this)->kind = IC_LITERAL;
    return ic_node_construct(ic_node(_this));
/* $end */
}

/* ::cortex::ic::literal::str(string in) */
cx_string ic_literal_str(ic_literal _this, cx_string in) {
/* $begin(::cortex::ic::literal::str) */
    cx_string result = NULL;

    if (_this->value.value) {
        if (cx_primitive(_this->value.type)->kind == CX_TEXT) {
            in = strappend(in, "\"");
        }
        cx_convert(cx_primitive(_this->value.type), _this->value.value, cx_primitive(cx_string_o), &result);
        in = strappend(in, result);
        cx_dealloc(result);
        if (cx_primitive(_this->value.type)->kind == CX_TEXT) {
            in = strappend(in, "\"");
        }
    } else {
        in = strappend(in, "(null)");
    }

    return in;
/* $end */
}
