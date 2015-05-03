/* ic_literal.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "ic.h"

/* ::cortex::ic::literal::str(string in) */
cx_string ic_literal_str(ic_literal _this, cx_string in) {
/* $begin(::cortex::ic::literal::str) */
    cx_string result;

    cx_convert(cx_primitive(cx_string_o), &result, cx_primitive(_this->value.type), _this->value.value);
    strappend(in, result);
    cx_dealloc(result);

    return in;
/* $end */
}
