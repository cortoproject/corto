/* ic_function.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "ic.h"

/* ::cortex::ic::function::construct() */
cx_int16 ic_function_construct(ic_function _this) {
/* $begin(::cortex::ic::function::construct) */
    ic_node(_this)->kind = IC_FUNCTION;
    return ic_node_construct(ic_node(_this));
/* $end */
}

/* ::cortex::ic::function::str(string in) */
cx_string ic_function_str(ic_function _this, cx_string in) {
/* $begin(::cortex::ic::function::str) */
    cx_id id;
    in = strappend(in, "\n%%function %s", cx_fullname(_this->function, id));
    return in;
/* $end */
}
