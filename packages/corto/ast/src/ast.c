/* ast.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "ast.h"

/* $header() */
#include "ast__private.h"
#include "ast.h"
#include "corto_util.h"
#include "corto_loader.h"
#include "corto_file.h"
#include "corto_mm.h"

corto_threadKey ast_PARSER_KEY;

/* Run a corto file */
int fast_cortoRun(corto_string file, int argc, char* argv[], void* udata) {
    corto_char* source;
    ast_Parser p;
    corto_int32 i;
    corto_stringSeq seq;
    CORTO_UNUSED(udata);

    seq.buffer = corto_alloc(argc * sizeof(corto_string));
    seq.length = argc;
    for (i = 0; i < argc; i++) {
        seq.buffer[i] = argv[i];
    }

    source = corto_fileLoad(file);
    if (source) {
        /* Create parser */
        p = ast_ParserCreate(source, file);

        /* Parse script */
        ast_Parser_parse(p, seq);
        corto_release(p);
        corto_dealloc(source);
    } else {
        goto error;
    }

    corto_dealloc(seq.buffer);

    return 0;
error:
    return -1;
}

/* Create a call-expression */
ast_Call ast_createCallWithArguments(ast_Expression instance, corto_string function, ast_Expression arguments) {
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
ast_Call ast_createCall(ast_Expression instance, corto_string function, corto_uint32 numArgs, ...) {
    ast_Expression args = NULL, arg = NULL;
    va_list arglist;
    corto_uint32 i;

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
    corto_id name;
    corto_object scope = yparser()->scope;
    ast_CallBuilder builder;

    if (ast_Node(f)->kind == Ast_StorageExpr) {
        switch(ast_Storage(f)->kind) {

        case Ast_ObjectStorage: {
            corto_object o = ast_Object(f)->value;
            corto_signatureName(corto_nameof(o), name);
            scope = corto_parentof(o);
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
                corto_nameof(corto_enum_constant(ast_storageKind_o, ast_Storage(f)->kind)));
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
corto_bool _ast_isOperatorAssignment(corto_operatorKind _operator) {
/* $begin(::corto::ast::isOperatorAssignment) */
    corto_bool result;
    switch(_operator) {
    case CORTO_ASSIGN:
    case CORTO_ASSIGN_ADD:
    case CORTO_ASSIGN_SUB:
    case CORTO_ASSIGN_DIV:
    case CORTO_ASSIGN_MUL:
    case CORTO_ASSIGN_MOD:
    case CORTO_ASSIGN_OR:
    case CORTO_ASSIGN_AND:
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
corto_void _ast_report(corto_string kind, corto_string filename, corto_uint32 line, corto_uint32 column, corto_string error, corto_string token) {
/* $begin(::corto::ast::report) */
    CORTO_UNUSED(token);

    if(filename) {
        corto_print("%s:%d:%d: %s: %s", filename, line, column, kind, error);
    } else {
        corto_print("%d:%d: %s: %s", line, column, kind, error);
    }

/* $end */
}

/* ::corto::ast::reportError(string filename,uint32 line,uint32 column,string error,string token) */
corto_void _ast_reportError(corto_string filename, corto_uint32 line, corto_uint32 column, corto_string error, corto_string token) {
/* $begin(::corto::ast::reportError) */

    ast_report("error", filename, line, column, error, token);

/* $end */
}

/* ::corto::ast::reportWarning(string filename,uint32 line,uint32 column,string error,string token) */
corto_void _ast_reportWarning(corto_string filename, corto_uint32 line, corto_uint32 column, corto_string error, corto_string token) {
/* $begin(::corto::ast::reportWarning) */

    ast_report("warning", filename, line, column, error, token);

/* $end */
}

/* ::corto::ast::valueKindFromType(type type) */
ast_valueKind _ast_valueKindFromType(corto_type type) {
/* $begin(::corto::ast::valueKindFromType) */
    ast_valueKind result = Ast_Nothing;

    if (type->reference) {
        result = Ast_Ref;
    } else {
        if (type->kind != CORTO_PRIMITIVE) {
            /* Exception to common error-reporting pattern: calling functions need to throw an error. The
             * rationale is that at this level there is little information available to report a meaningful
             * error. */
            goto error;
        }

        switch(corto_primitive(type)->kind) {
        case CORTO_BOOLEAN:
            result = Ast_Bool;
            break;
        case CORTO_CHARACTER:
            result = Ast_Char;
            break;
        case CORTO_INTEGER:
            result = Ast_SignedInt;
            break;
        case CORTO_BINARY:
        case CORTO_UINTEGER:
            result = Ast_Int;
            break;
        case CORTO_FLOAT:
            result = Ast_Float;
            break;
        case CORTO_TEXT:
            result = Ast_Text;
            break;
        case CORTO_ENUM:
        case CORTO_BITMASK:
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
    CORTO_UNUSED(argc);
    CORTO_UNUSED(argv);
    if (corto_threadTlsKey(&ast_PARSER_KEY, NULL)) {
        return -1;
    }
    /* Register corto extension */
    corto_loaderRegister("cx", fast_cortoRun, NULL);
    return 0;
/* $end */
}
