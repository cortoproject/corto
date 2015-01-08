/* Fast_DelegateCall.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"
#include "Fast__meta.h"

/* callback ::cortex::lang::class::construct(object object) -> ::cortex::Fast::DelegateCall::construct(Fast::DelegateCall object) */
cx_int16 Fast_DelegateCall_construct(Fast_DelegateCall object) {
/* $begin(::cortex::Fast::DelegateCall::construct) */
    if (!object->expr) {
        Fast_Parser_error(yparser(), "no expression provided for delegate call");
        goto error;
    } else {
        cx_uint32 i;
        cx_procptr type = cx_procptr(Fast_Expression_getType(object->expr));

        /* Create expression to obtain pointer to the instance */
        Fast_String instanceString = Fast_String__create("instance");
        Fast_MemberExpr iExpr = Fast_MemberExpr__create(object->expr, Fast_Expression(instanceString));
        cx_set(&Fast_Call(object)->instanceExpr, iExpr);
        Fast_Parser_collect(yparser(), iExpr);
        Fast_Parser_collect(yparser(), instanceString);

        /* Set function expression to delegate */
        cx_set(&Fast_Call(object)->functionExpr, object->expr);

        /* Set parameters */
        cx_set(&Fast_Call(object)->returnType, type->returnType);
        Fast_Call(object)->returnsReference = type->returnsReference;

        cx_parameter_seq__size(&Fast_Call(object)->parameters, type->parameters.length);

        for (i = 0; i < type->parameters.length; i++) {
            cx_set(&Fast_Call(object)->parameters.buffer[i].type, type->parameters.buffer[i].type);
            Fast_Call(object)->parameters.buffer[i].passByReference = type->parameters.buffer[i].passByReference;
        }
    }

    return Fast_Call_construct(Fast_Call(object));
error:
    return -1;
/* $end */
}
