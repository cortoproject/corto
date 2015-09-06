/* ic_function.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_ic_LIB
#include "ic.h"

/* ::corto::ic::function::construct() */
cx_int16 _ic_function_construct(ic_function _this) {
/* $begin(::corto::ic::function::construct) */
    ic_node(_this)->kind = IC_FUNCTION;
    return ic_node_construct(ic_node(_this));
/* $end */
}

/* ::corto::ic::function::str(string in) */
cx_string _ic_function_str(ic_function _this, cx_string in) {
/* $begin(::corto::ic::function::str) */
    cx_id id;
    in = strappend(in, "\n%%function %s", cx_fullname(_this->function, id));
    return in;
/* $end */
}
