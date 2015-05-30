/* ic_address.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "ic.h"

/* ::cortex::ic::address::construct() */
cx_int16 ic_address_construct(ic_address _this) {
/* $begin(::cortex::ic::address::construct) */
    ic_node(_this)->kind = IC_ADDRESS;
    return ic_node_construct(ic_node(_this));
/* $end */
}
