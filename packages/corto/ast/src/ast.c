/* ast.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_ast_LIB
#include "ast.h"

/* $header() */
#include "ast__private.h"
#include "ast.h"
#include "cx_util.h"
#include "cx_loader.h"
#include "cx_file.h"
#include "cx_mm.h"

cx_threadKey ast_PARSER_KEY;

/* Run a corto file */
int fast_cortoRun(cx_string file, int argc, char* argv[], void* udata) {
    cx_char* source;
    ast_Parser p;
    cx_int32 i;
    cx_stringSeq seq;
    CX_UNUSED(udata);

    seq.buffer = cx_alloc(argc * sizeof(cx_string));
    seq.length = argc;
    for (i = 0; i < argc; i++) {
        seq.buffer[i] = argv[i];
    }

    source = cx_fileLoad(file);
    if (source) {
        /* Create parser */
        p = ast_ParserCreate(source, file);

        /* Parse script */
        ast_Parser_parse(p, seq);
        cx_release(p);
        cx_dealloc(source);
    } else {
        goto error;
    }

    cx_dealloc(seq.buffer);

    return 0;
error:
    return -1;
}

/* Create a call-expression */
ast_Call ast_createCallWithArguments(ast_Expression instance, cx_string function, ast_Expression arguments) {
    ast_Call result;
    ast_CallBuilder builder;

    /* Initialize builder */
    ast_CallBuilderInit(&builder);
    ast_CallBuilderSet(&builder,
        function,
        arguments,
        instance,
        yparser()->scope,
        yparser()->block);
    result = ast_CallBuilder_build(&builder);
    ast_CallBuilderDeinit(&builder);

    return result;
}

/* Create a call-expression */
ast_Call ast_createCall(ast_Expression instance, cx_string function, cx_uint32 numArgs, ...) {
    ast_Expression args = NULL, arg = NULL;
    va_list arglist;
    cx_uint32 i;

    /* Create comma-expression if there is more than one argument */
    va_start(arglist, numArgs);
    if (numArgs > 1) {
        args = ast_Expression(ast_CommaCreate());
        for(i=0; i<numArgs; i++) {
            arg = va_arg(arglist, ast_Expression);
            ast_Comma_addExpression(ast_Comma(args), arg);
        }
    } else if (numArgs) {
        args = va_arg(arglist, ast_Expression);
    }
    va_end(arglist);

    if (args) {
        ast_Parser_collect(yparser(), args);
    }

    return ast_createCallWithArguments(instance, function, args);
}

ast_Call ast_createCallFromExpr(ast_Expression f, ast_Expression arguments) {
    ast_Call result = NULL;
    ast_Expression instance = NULL;
    cx_id name;
    cx_object scope = yparser()->scope;
    ast_CallBuilder builder;

    if (ast_Node(f)->kind == Ast_StorageExpr) {
        switch(ast_Storage(f)->kind) {

        case Ast_ObjectStorage: {
            cx_object o = ast_Object(f)->value;
            cx_signatureName(cx_nameof(o), name);
            scope = cx_parentof(o);
            break;
        }

        case Ast_LocalStorage:
            strcpy(name, ast_Local(f)->name);
            break;

        case Ast_MemberStorage:
            instance = ast_Member(f)->lvalue;
            strcpy(name, ast_String(ast_Member(f)->rvalue)->value);
            break;

        case Ast_ElementStorage:
            result = ast_Call(ast_DelegateCallCreate(NULL, arguments, f));
            break;

        default:
            ast_Parser_error(yparser(), "'%s' expression is not callable",
                cx_nameof(cx_enum_constant(ast_storageKind_o, ast_Storage(f)->kind)));
            goto error;
        }
    }

    if (!result) {
        ast_CallBuilderInit(&builder);
        ast_CallBuilderSet(&builder, name, arguments, instance, scope, yparser()->block);
        result = ast_CallBuilder_build(&builder);
        ast_CallBuilderDeinit(&builder);
    }

    return result;
error:
    return NULL;
}
/* $end */

/* ::corto::ast::isOperatorAssignment(operatorKind operator) */
cx_bool _ast_isOperatorAssignment(cx_operatorKind operator) {
/* $begin(::corto::ast::isOperatorAssignment) */
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

/* ::corto::ast::report(string kind,string filename,uint32 line,uint32 column,string error,string token) */
cx_void _ast_report(cx_string kind, cx_string filename, cx_uint32 line, cx_uint32 column, cx_string error, cx_string token) {
/* $begin(::corto::ast::report) */
    CX_UNUSED(token);

    if(filename) {
        cx_print("%s:%d:%d: %s: %s", filename, line, column, kind, error);
    } else {
        cx_print("%d:%d: %s: %s", line, column, kind, error);
    }

/* $end */
}

/* ::corto::ast::reportError(string filename,uint32 line,uint32 column,string error,string token) */
cx_void _ast_reportError(cx_string filename, cx_uint32 line, cx_uint32 column, cx_string error, cx_string token) {
/* $begin(::corto::ast::reportError) */

    ast_report("error", filename, line, column, error, token);

/* $end */
}

/* ::corto::ast::reportWarning(string filename,uint32 line,uint32 column,string error,string token) */
cx_void _ast_reportWarning(cx_string filename, cx_uint32 line, cx_uint32 column, cx_string error, cx_string token) {
/* $begin(::corto::ast::reportWarning) */

    ast_report("warning", filename, line, column, error, token);

/* $end */
}

/* ::corto::ast::valueKindFromType(type type) */
ast_valueKind _ast_valueKindFromType(cx_type type) {
/* $begin(::corto::ast::valueKindFromType) */
    ast_valueKind result = Ast_Nothing;

    if (type->reference) {
        result = Ast_Ref;
    } else {
        if (type->kind != CX_PRIMITIVE) {
            /* Exception to common error-reporting pattern: calling functions need to throw an error. The
             * rationale is that at this level there is little information available to report a meaningful
             * error. */
            goto error;
        }

        switch(cx_primitive(type)->kind) {
        case CX_BOOLEAN:
            result = Ast_Bool;
            break;
        case CX_CHARACTER:
            result = Ast_Char;
            break;
        case CX_INTEGER:
            result = Ast_SignedInt;
            break;
        case CX_BINARY:
        case CX_UINTEGER:
            result = Ast_Int;
            break;
        case CX_FLOAT:
            result = Ast_Float;
            break;
        case CX_TEXT:
            result = Ast_Text;
            break;
        case CX_ENUM:
        case CX_BITMASK:
            result = Ast_Enum;
            break;
        }
    }

    return result;
error:
    return Ast_Nothing;
/* $end */
}

int astMain(int argc, char* argv[]) {
/* $begin(main) */
    CX_UNUSED(argc);
    CX_UNUSED(argv);
    if (cx_threadTlsKey(&ast_PARSER_KEY, NULL)) {
        return -1;
    }
    /* Register corto extension */
    cx_loaderRegister("cx", fast_cortoRun, NULL);
    return 0;
/* $end */
}
