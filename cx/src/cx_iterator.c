/* cx_iterator.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::iterator::init(lang::iterator object) */
cx_int16 cx_iterator_init(cx_iterator object) {
/* $begin(::cortex::lang::iterator::init) */
    cx_type(object)->kind = CX_ITERATOR;
    return 0;
/* $end */
}
