/* ic_node.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "ic.h"

/* ::cortex::ic::node::str(string in) */
cx_string ic_node_str_v(ic_node _this, cx_string in) {
/* $begin(::cortex::ic::node::str) */
    CX_UNUSED(_this);

    return strappend(in, "?<node>");

/* $end */
}
