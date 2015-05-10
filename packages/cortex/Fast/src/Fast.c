/* Fast.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"

/* $header() */
#include "Fast__private.h"

/* Create a call-expression */
Fast_Call Fast_createCallWithArguments(Fast_Expression instance, cx_string function, Fast_Expression arguments) {
    Fast_Call result;
    Fast_CallBuilder builder;

    /* Initialize builder */
    Fast_CallBuilder__init(&builder, 
        function, 
        arguments, 
        instance, 
        yparser()->scope, 
        yparser()->block);
    result = Fast_CallBuilder_build(&builder);
    Fast_CallBuilder__deinit(&builder);

    return result;
}

/* Create a call-expression */
Fast_Call Fast_createCall(Fast_Expression instance, cx_string function, cx_uint32 numArgs, ...) {
    Fast_Expression args = NULL, arg = NULL;
    va_list arglist;
    cx_uint32 i;
    
    /* Create comma-expression if there is more than one argument */
    va_start(arglist, numArgs);
    if (numArgs > 1) {
        args = Fast_Expression(Fast_Comma__create());
        for(i=0; i<numArgs; i++) {
            arg = va_arg(arglist, Fast_Expression);
            Fast_Comma_addExpression(Fast_Comma(args), arg);
        }
    } else if (numArgs) {
        args = va_arg(arglist, Fast_Expression);
    }
    va_end(arglist);

    if (args) {
        Fast_Parser_collect(yparser(), args);
    }

    return Fast_createCallWithArguments(instance, function, args);
}

Fast_Call Fast_createCallFromExpr(Fast_Expression f, Fast_Expression arguments) {
    Fast_Call result = NULL;
    Fast_Expression instance = NULL;
    cx_id name;
    cx_object scope = yparser()->scope;
    Fast_CallBuilder builder;

    if (Fast_Node(f)->kind == Fast_StorageExpr) {
        switch(Fast_Storage(f)->kind) {

        case Fast_ObjectStorage: {
            cx_object o = Fast_Object(f)->value;
            cx_signatureName(cx_nameof(o), name);
            scope = cx_parentof(o);
            break;
        }

        case Fast_LocalStorage:
            strcpy(name, Fast_Local(f)->name);
            break;

        case Fast_MemberStorage:
            instance = Fast_Member(f)->lvalue;
            strcpy(name, Fast_String(Fast_Member(f)->rvalue)->value);
            break;

        case Fast_ElementStorage:
            result = Fast_Call(Fast_DelegateCall__create(NULL, arguments, f));
            break;

        default:
            Fast_Parser_error(yparser(), "'%s' expression is not callable",
                cx_nameof(cx_enum_constant(Fast_storageKind_o, Fast_Storage(f)->kind)));
            goto error;
        }
    }

    if (!result) {
        Fast_CallBuilder__init(&builder, name, arguments, instance, scope, yparser()->block);
        result = Fast_CallBuilder_build(&builder);
        Fast_CallBuilder__deinit(&builder);
    }

    return result;
error:
    return NULL;
}
/* $end */

/* ::cortex::Fast::isOperatorAssignment(operatorKind operator) */
cx_bool Fast_isOperatorAssignment(cx_operatorKind operator) {
/* $begin(::cortex::Fast::isOperatorAssignment) */
    cx_bool result;
    switch(operator) {
    case CX_ASSIGN:
    case CX_ASSIGN_ADD:
    case CX_ASSIGN_SUB:
    case CX_ASSIGN_DIV:
    case CX_ASSIGN_MUL:
    case CX_ASSIGN_MOD:
    case CX_ASSIGN_OR:
    case CX_ASSIGN_AND:
        result = TRUE;
        break;
    default:
        result = FALSE;
        break;
    }
    return result;
/* $end */
}

/* ::cortex::Fast::report(string kind,string filename,uint32 line,uint32 column,string error,string token) */
cx_void Fast_report(cx_string kind, cx_string filename, cx_uint32 line, cx_uint32 column, cx_string error, cx_string token) {
/* $begin(::cortex::Fast::report) */
    CX_UNUSED(token);
    
    if(filename) {
        cx_print("%s:%d:%d: %s: %s", filename, line, column, kind, error);
    } else {
        cx_print("%d:%d: %s: %s", line, column, kind, error);
    }

/* $end */
}

/* ::cortex::Fast::reportError(string filename,uint32 line,uint32 column,string error,string token) */
cx_void Fast_reportError(cx_string filename, cx_uint32 line, cx_uint32 column, cx_string error, cx_string token) {
/* $begin(::cortex::Fast::reportError) */
    
    Fast_report("error", filename, line, column, error, token);

/* $end */
}

/* ::cortex::Fast::reportWarning(string filename,uint32 line,uint32 column,string error,string token) */
cx_void Fast_reportWarning(cx_string filename, cx_uint32 line, cx_uint32 column, cx_string error, cx_string token) {
/* $begin(::cortex::Fast::reportWarning) */

    Fast_report("warning", filename, line, column, error, token);

/* $end */
}

/* ::cortex::Fast::valueKindFromType(type type) */
Fast_valueKind Fast_valueKindFromType(cx_type type) {
/* $begin(::cortex::Fast::valueKindFromType) */
    Fast_valueKind result = Fast_Nothing;

    if (type->reference) {
        result = Fast_Ref;
    } else {
        if (type->kind != CX_PRIMITIVE) {
            /* Exception to common error-reporting pattern: calling functions need to throw an error. The
             * rationale is that at this level there is little information available to report a meaningful
             * error. */
            goto error;
        }

        switch(cx_primitive(type)->kind) {
        case CX_BOOLEAN:
            result = Fast_Bool;
            break;
        case CX_CHARACTER:
            result = Fast_Char;
            break;
        case CX_INTEGER:
            result = Fast_SignedInt;
            break;
        case CX_BINARY:
        case CX_UINTEGER:
            result = Fast_Int;
            break;
        case CX_FLOAT:
            result = Fast_Float;
            break;
        case CX_TEXT:
            result = Fast_Text;
            break;
        case CX_ENUM:
        case CX_BITMASK:
            result = Fast_Enum;
            break;
        case CX_ALIAS:
            result = Fast_Int;
            break;
        }
    }

    return result;
error:
    return Fast_Nothing;
/* $end */
}
