/* Fast_StaticCall.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"
#include "Fast__meta.h"

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::Fast::StaticCall::construct(Fast::StaticCall object) */
cx_int16 Fast_StaticCall_construct(Fast_StaticCall object) {
/* $begin(::cortex::Fast::StaticCall::construct) */
    Fast_Object fExpr;

    fExpr = Fast_Object__create(object->function);
    Fast_Parser_collect(yparser(), fExpr);
    cx_set(&Fast_Call(object)->functionExpr, fExpr);

    /* Set parameters */
    Fast_Call_setParameters(Fast_Call(object), object->function);

    /* If function is a metaprocedure, signal Call class to push this as any */
    Fast_Call(object)->instanceIsAny = 
        (cx_procedure(cx_typeof(object->function))->kind == CX_METAPROCEDURE);

    return Fast_Call_construct(Fast_Call(object));
/* $end */
}
