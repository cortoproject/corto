/* ic_label.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "ic.h"

/* ::cortex::ic::label::str(string in) */
cx_string ic_label_str(ic_label _this, cx_string in) {
/* $begin(::cortex::ic::label::str) */
    in = strappend(in, "%%label %d", _this->id);
    return in;
/* $end */
}
