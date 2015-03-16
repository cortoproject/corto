/* Fast_IteratorLocal.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"
#include "Fast__meta.h"

/* ::cortex::Fast::IteratorLocal::getBuddy() */
Fast_Local Fast_IteratorLocal_getBuddy(Fast_IteratorLocal _this) {
/* $begin(::cortex::Fast::IteratorLocal::getBuddy) */
    return _this->buddy;
/* $end */
}
