/* Fast.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"
#include "Fast__meta.h"

/* $header() */
#include "Fast_Parser.h"
#include "Fast_Call.h"
#include "Fast_CommaExpr.h"
#include "Fast__api.h"
Fast_Parser yparser(void);

/* Create a call-expression */
Fast_Call Fast_createMethodCall(Fast_Expression obj, db_string function, db_uint32 numArgs, ...) {
    Fast_Call result;
    Fast_Expression args=NULL, arg=NULL, member=NULL;
    Fast_String functionStr;
	va_list arglist;
    db_uint32 i;
    
    /* Create comma-expression if there is more than one argument */
    va_start(arglist, numArgs);
    if (numArgs > 1) {
        args = Fast_Expression(Fast_CommaExpr__create());
        for(i=0; i<numArgs; i++) {
            arg = va_arg(arglist, Fast_Expression);
            Fast_CommaExpr_addExpression(Fast_CommaExpr(args), arg);
        }
    } else if (numArgs) {
        args = va_arg(arglist, Fast_Expression);
    }
    va_end(arglist);
    
    /* Create member expression */
    functionStr = Fast_String__create(function);

    /* Create memberexpression */
    member = Fast_Expression(Fast_MemberExpr__create(obj, Fast_Expression(functionStr)));
    if (!member) {
        /* TODO: free resources */
        goto error;
    }

    result = Fast_Call__create(member, Fast_Expression(args));
    Fast_Parser_collect(yparser(), result);
    if (args) {
        Fast_Parser_collect(yparser(), args);
    }
    Fast_Parser_collect(yparser(), member);

    return result;
error:
    return NULL;
}

/* $end */

/* ::cortex::Fast::valueKindFromType(lang::type type) */
Fast_valueKind Fast_valueKindFromType(db_type type) {
/* $begin(::cortex::Fast::valueKindFromType) */
	Fast_valueKind result = FAST_Null;

	if (type->reference) {
		result = FAST_Reference;
	} else {
		if (type->kind != DB_PRIMITIVE) {
            /* Exception to common error-reporting pattern: calling functions need to throw an error. The
             * rationale is that at this level there is little information available to report a meaningful
             * error. */
            goto error;
        }

		switch(db_primitive(type)->kind) {
		case DB_BOOLEAN:
			result = FAST_Boolean;
			break;
		case DB_CHARACTER:
			result = FAST_Character;
			break;
		case DB_INTEGER:
			result = FAST_SignedInteger;
			break;
		case DB_BINARY:
		case DB_UINTEGER:
			result = FAST_Integer;
			break;
		case DB_FLOAT:
			result = FAST_FloatingPoint;
			break;
		case DB_TEXT:
			result = FAST_String;
			break;
		case DB_ENUM:
		case DB_BITMASK:
			result = FAST_Enumerated;
			break;
		case DB_ALIAS:
			result = FAST_Integer;
			break;
		}
	}

	return result;
error:
    return FAST_Null;
/* $end */
}
