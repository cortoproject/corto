/* Fast_Variable.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast_Variable.h"
#include "Fast__meta.h"


/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::Variable::construct(Variable object) */
db_int16 Fast_Variable_construct(Fast_Variable object) {
/* $begin(::hyve::Fast::Variable::construct) */

    Fast_Node(object)->kind = FAST_Variable;

    return 0;
/* $end */
}
