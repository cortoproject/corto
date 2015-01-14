/* Fast_Variable.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"
#include "Fast__meta.h"

/* ::cortex::Fast::Variable::construct() */
cx_int16 Fast_Variable_construct(Fast_Variable _this) {
/* $begin(::cortex::Fast::Variable::construct) */

    Fast_Node(object)->kind = FAST_Variable;

    return 0;
/* $end */
}
