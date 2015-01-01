/* Fast_ObjectBase.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"
#include "Fast__meta.h"

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::Fast::ObjectBase::construct(ObjectBase object) */
db_int16 Fast_ObjectBase_construct(Fast_ObjectBase object) {
/* $begin(::cortex::Fast::ObjectBase::construct) */

    Fast_Variable(object)->kind = FAST_Object;

    return Fast_Variable_construct(Fast_Variable(object));
/* $end */
}
