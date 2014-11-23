/* Fast_ObjectBase.c
 *
 *  Generated on Nov 18 2014
 *    This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast_ObjectBase.h"
#include "Fast__meta.h"


/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::ObjectBase::construct(ObjectBase object) */
db_int16 Fast_ObjectBase_construct(Fast_ObjectBase object) {
/* $begin(::hyve::Fast::ObjectBase::construct) */

    Fast_Variable(object)->kind = FAST_Object;

    return Fast_Variable_construct(Fast_Variable(object));
/* $end */
}
