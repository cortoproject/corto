/* ic_address.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_ic_LIB
#include "ic.h"

/* ::corto::ic::address::construct() */
cx_int16 _ic_address_construct(ic_address this) {
/* $begin(::corto::ic::address::construct) */
    ic_node(this)->kind = IC_ADDRESS;
    return ic_node_construct(ic_node(this));
/* $end */
}
