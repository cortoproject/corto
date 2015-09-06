/* Fast_DelegateCall.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_Fast_LIB
#include "Fast.h"

/* $header() */
#include "Fast__private.h"
/* $end */

/* ::corto::Fast::DelegateCall::construct() */
cx_int16 _Fast_DelegateCall_construct(Fast_DelegateCall this) {
/* $begin(::corto::Fast::DelegateCall::construct) */
    if (!this->expr) {
        Fast_Parser_error(yparser(), "no expression provided for delegate call");
        goto error;
    } else {
        cx_uint32 i;
        cx_delegate type = cx_delegate(Fast_Expression_getType(this->expr));

        /* Create expression to obtain pointer to the instance */
        Fast_String instanceString = Fast_StringCreate("instance");
        Fast_Member iExpr = Fast_MemberCreate(this->expr, Fast_Expression(instanceString));
        cx_setref(&Fast_Call(this)->instanceExpr, iExpr);
        Fast_Parser_collect(yparser(), iExpr);
        Fast_Parser_collect(yparser(), instanceString);

        /* Set function expression to delegate */
        cx_setref(&Fast_Call(this)->functionExpr, this->expr);

        /* Set parameters */
        cx_setref(&Fast_Call(this)->returnType, type->returnType);
        Fast_Call(this)->returnsReference = type->returnsReference;

        cx_parameterSeqSize(&Fast_Call(this)->parameters, type->parameters.length);

        for (i = 0; i < type->parameters.length; i++) {
            cx_setref(&Fast_Call(this)->parameters.buffer[i].type, type->parameters.buffer[i].type);
            Fast_Call(this)->parameters.buffer[i].passByReference = type->parameters.buffer[i].passByReference;
        }
    }

    return Fast_Call_construct(Fast_Call(this));
error:
    return -1;
/* $end */
}
