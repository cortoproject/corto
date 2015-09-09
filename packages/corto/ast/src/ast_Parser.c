/* ast_Parser.c
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

#define ast_CHECK_ERRSET(parser) cx_assert(!parser->errSet, "%s:%d:%d: parser did not check error-status set on line %d", this->filename, this->line, this->column, this->errLine)
/*#define ast_PARSER_DEBUG*/
#define fast_err this->errSet = TRUE; this->errLine = __LINE__;

extern cx_threadKey ast_PARSER_KEY;

void ast_Parser_error(ast_Parser this, char* fmt, ... ) {
    va_list args;
    char msgbuff[1024];
    cx_id token;
    int line = this->line;

    if (this->token) {
        if (*this->token == '\n') {
            sprintf(token, "end of line");
            line--;
        } else {
            sprintf(token, "'%s'", this->token);
        }
    } else {
        *token = '\0';
    }

    va_start(args, fmt);
    vsprintf(msgbuff, fmt, args);
    va_end(args);

    ast_reportError(this->filename, this->column ? line : line - 1, this->column, msgbuff, token);

    this->errors++;
}

void ast_Parser_warning(ast_Parser this, char* fmt, ... ) {
    va_list args;
    char msgbuff[1024];
    cx_id token;
    int line = this->line;

    if (this->token) {
        if (*this->token == '\n') {
            sprintf(token, "end of line");
            line--;
        } else {
            sprintf(token, "'%s'", this->token);
        }
    } else {
        *token = '\0';
    }

    va_start(args, fmt);
    vsprintf(msgbuff, fmt, args);
    va_end(args);

    ast_reportWarning(this->filename, line, this->column, msgbuff, token);

    this->warnings++;
}

/* Generate user-friendly id's for both scoped and unscoped objects */
cx_string ast_Parser_id(cx_object o, cx_id buffer) {
    if (!o) {
        sprintf(buffer, "null");
    } else if (cx_checkAttr(o, CX_ATTR_SCOPED)) {
        if (cx_parentof(o) == corto_lang_o) {
            strcpy(buffer, cx_nameof(o));
        } else {
            cx_fullname(o, buffer);
        }
    } else {
        cx_id tmp;
        cx_string_ser_t serData;
        struct cx_serializer_s s;
        serData.buffer = tmp;
        serData.length = sizeof(cx_id);
        serData.maxlength = sizeof(cx_id)-strlen("<anonymous>");
        serData.compactNotation=TRUE;
        serData.prefixType = TRUE;
        serData.enableColors = FALSE;
        s = cx_string_ser(CX_LOCAL, CX_NOT, CX_SERIALIZER_TRACE_NEVER);
        cx_serialize(&s, o, &serData);
        strcpy(buffer, tmp);
    }
    return buffer;
}

/* Translate result of parser to corto intermediate bytecode */
cx_int16 ast_Parser_toIc(ast_Parser this, cx_stringSeq argv) {
    ic_program program = ic_programCreate(this->filename);

    /* Parse root-block */
    ast_Block_toIc(this->block, program, NULL, FALSE);
    if (this->errors) {
        goto error;
    }

    /* Bind function implementations to function objects */
    if (ast_Parser_finalize(this, program)) {
        goto error;
    }

    /* Print program */
#ifdef IC_TRACING
    extern cx_bool CX_DEBUG_ENABLED;
    if (CX_DEBUG_ENABLED) {
        cx_string programStr = ic_program_toString(program);
        cx_print("%s", programStr);
        cx_dealloc(programStr);
    }
#endif

    ic_program_assemble(program);
    ic_program_run(program, 0, argv);

    /* Free program */
    cx_release(program);

    return 0;
error:
    cx_release(program);
    return -1;
}

/* Use cx_object as returntype as the actual type (ast_Expression) causes macro-expansion */
typedef cx_object (*ast_ExpandAction)(ast_Parser this, ast_Expression lvalue, ast_Expression rvalue, void *userData);

/* Combine results in new comma expression */
cx_object ast_Parser_combineComma(ast_Parser this, ast_Expression lvalue, ast_Expression rvalue, void *userData) {
    CX_UNUSED(this);
    CX_UNUSED(userData);
    return ast_Comma_addOrCreate(lvalue, rvalue);
}

/* Combine results as part of conditional expression */
cx_object ast_Parser_combineConditionalExpr(ast_Parser this, ast_Expression lvalue, ast_Expression rvalue, void *userData) {
    cx_operatorKind oper = *(cx_operatorKind*)userData;
    cx_operatorKind combineOper;
    ast_Expression result;

    /* Default combine is AND, except the != operator, which inserts an OR */
    if (lvalue) {
        if (oper == CX_COND_NEQ) {
            combineOper = CX_COND_OR;
        } else {
            combineOper = CX_COND_AND;
        }

        result = ast_Expression(ast_BinaryCreate(lvalue, rvalue, combineOper));
        ast_Parser_collect(this, result);

        /* Fold expression where possible */
        result = ast_Expression_fold(result);
        if (!result) {
            ast_Parser_error(this, "folding failed for expression");
        }
    } else {
        result = rvalue;
    }

    return result;
}

/* Create binary expression with ternary operand */
ast_Expression ast_Parser_createBinaryTernary(ast_Parser this, ast_Expression lvalue, ast_Expression rvalue, cx_operatorKind operator) {
    ast_Expression result = NULL;
    CX_UNUSED(this);

    /* If the operation is an assignment, the ternary operator has already constructed the binary operation through an lvalue - see
     * the implementation of ast_Parser_Ternary. If the operation is not an assignment, create the binary expression. */
    switch(operator) {
    case CX_ASSIGN:
    case CX_ASSIGN_ADD:
    case CX_ASSIGN_SUB:
    case CX_ASSIGN_MUL:
    case CX_ASSIGN_DIV:
    case CX_ASSIGN_MOD:
    case CX_ASSIGN_OR:
    case CX_ASSIGN_AND:
        ast_Ternary_setOperator(ast_Ternary(rvalue), operator);
        cx_setref(&result, rvalue);
        break;
    default:
        result = ast_Expression(ast_BinaryCreate(lvalue, rvalue, operator));
        ast_Parser_collect(this, result);
        break;
    }

    return result;
}

/* Match parameter */
cx_bool ast_Parser_matchDelegateParameter(
    ast_Parser this,
    cx_string name,
    cx_type t1,
    cx_bool isRef1,
    cx_type t2,
    cx_bool isRef2) {

    if ((t1 != t2) || (isRef1 && !isRef2)) {
        cx_id id1, id3, id4;

        ast_Parser_error(this, "%s %s '%s%s' of procedure doesn't match '%s%s' of delegate '%s'",
            name ? "parameter" : "",
            name ? name : "returntype",
            ast_Parser_id(t1, id1),
            isRef1 ? "&" : "",
            ast_Parser_id(t2, id3),
            isRef2 ? "&" : "",
            ast_Parser_id(t2, id4));
        goto error;
    }

    return TRUE;
error:
    return FALSE;
}

/* Create and validate delegate assignment */
ast_Expression ast_Parser_delegateAssignment(ast_Parser this, ast_Expression lvalue, ast_Expression rvalue) {
    cx_uint32 i;
    ast_Expression instance = NULL;
    ast_Expression functionExpr = NULL;
    cx_id functionName;
    Ast_InitializerExpression result = NULL;
    cx_string signature = NULL;
    cx_delegate type = NULL;
    ast_InitializerVariableArray64 variables;
    ast_CallBuilder builder;
    ast_Call tempCall = NULL;

    memset(variables, 0, sizeof(variables));

    /* Validate whether rvalue is an object */
    if ((ast_Node(rvalue)->kind == Ast_StorageExpr) && (ast_Storage(rvalue)->kind == Ast_ObjectStorage)) {
        cx_signatureName(cx_nameof(ast_Object(rvalue)->value), functionName);
    } else if ((ast_Node(rvalue)->kind == Ast_StorageExpr) && (ast_Storage(rvalue)->kind == Ast_MemberStorage)) {
        instance = ast_Member(rvalue)->lvalue;
        strcpy(functionName, ast_String(ast_Member(rvalue)->rvalue)->value);
    } else {
        ast_Parser_error(this, "dynamic delegate assignments are not yet supported");
        goto error;
    }

    type = cx_delegate(ast_Expression_getType(lvalue));

    /* Build request-signature */
    signature = cx_signatureOpen(functionName);
    for (i = 0; i < type->parameters.length; i++) {
        cx_parameter *p = &type->parameters.buffer[i];
        signature = cx_signatureAdd(signature, p->type, p->passByReference ? CX_PARAMETER_FORCEREFERENCE : 0);
    }
    signature = cx_signatureClose(signature);

    /* Resolve function */
    ast_CallBuilderInit(&builder);
    ast_CallBuilderSet(
        &builder,
        signature,
        NULL,
        instance,
        this->scope,
        yparser()->block);
    tempCall = ast_CallBuilder_build(&builder);
    ast_CallBuilderDeinit(&builder);

    if (!tempCall) {
        goto error;
    }

    /* Call::resolveActual will resolve a method that matches the signature of the delegate. However,
     * the overloading algorithm takes into account type compatibility: a uint32 request will match a
     * uint64 parameter. This algorithm assumes that the actual call will do an implicit conversion.
     * Delegates simply pass-through parameters and cannot perform this implicit casting. Therefore their
     * signatures have to match the parameter-types exactly. The only exception to this rule is inheritance.
     */

    /* Validate returntype */
    if (!ast_Parser_matchDelegateParameter(
        this,
        NULL,
        type->returnType,
        type->returnsReference,
        tempCall->returnType,
        tempCall->returnsReference)) {
        goto error;
    }

    /* Validate number of parameters */
    if (type->parameters.length != tempCall->parameters.length) {
        ast_Parser_error(this, "number of procedure parameters(%d) doesn't match delegate (%d)",
            tempCall->parameters.length,
            type->parameters.length);
        goto error;
    }

    /* Validate parameters */
    for (i=0; i<type->parameters.length; i++) {
        cx_parameter *p1, *p2;
        p1 = &type->parameters.buffer[i];
        p2 = &tempCall->parameters.buffer[i];

        if (!ast_Parser_matchDelegateParameter(
            this,
            p1->name,
            p1->type,
            p1->passByReference,
            p2->type,
            p2->passByReference)) {
            goto error;
        }
    }

    functionExpr = tempCall->functionExpr;

    /* If procedure is compatible with delegate type, do a complex assignment */
    cx_setref(&variables[0].object, lvalue);
    result = Ast_InitializerExpressionCreate(variables, 1, TRUE);
    Ast_InitializerExpression_push(result);
    if (instance) {
        Ast_InitializerExpression_member(result, "instance");
        Ast_InitializerExpression_value(result, instance);
    }
    Ast_InitializerExpression_member(result, "procedure");
    Ast_InitializerExpression_value(result, functionExpr);
    Ast_InitializerExpression_pop(result);
    Ast_InitializerExpression_define(result);
    ast_Parser_collect(this, result);

    cx_dealloc(signature);
    cx_release(tempCall);

    return ast_Expression(result);
error:
    if(signature) {
        cx_dealloc(signature);
    }
    return NULL;
}

/* Callback function for expansion of binary expressions */
cx_object ast_Parser_expandBinary(ast_Parser this, ast_Expression lvalue, ast_Expression rvalue, void *userData) {
    ast_Expression result = NULL;
    cx_type tleft, tright;
    cx_operatorKind operator = *(cx_operatorKind*)userData;

    if (!(tleft = ast_Expression_getType_expr(lvalue, rvalue))) {
        goto error;
    }

    if (!(tright = ast_Expression_getType_expr(rvalue, lvalue))) {
        goto error;
    }

    if (tleft && (tleft->kind == CX_COMPOSITE) && (cx_interface(tleft)->kind == CX_DELEGATE)) {
        if (*(cx_operatorKind*)userData == CX_ASSIGN) {
            rvalue = ast_Parser_delegateAssignment(this, lvalue, rvalue);
            if(!rvalue) {
                goto error;
            }
        } else {
            ast_Parser_error(this, "operators other than assign not valid for delegates");
            goto error;
        }
    }

    /* The way in which following kinds of binary expressions are evaluated is important:
     *  - Ternary expressions takes precedence over anything since they introduce additional binary expressions
     *    which in turn will be determined to be either primitive, composite or collection expressions.
     *  - A binary expression is only composite when both operands are of a composite type. Both of these
     *    types have to be compatible. This is partially to avoid amibiguity with collection expressions
     *    (collections with composite element types) and partially because there are no useful semantics
     *    (defined) for combining both composite and <insert other type> in one expression.
     *  - A binary expression is a collection expression when one of the operands is a collection. Whether
     *    the operation is valid or not is further determined by the binaryCollectionExpr function.
     *  - Remaining types (basically references and primitive types) are handled by a regular binary
     *    expression.
     */

    /* Ternary expression */
    if (ast_Node(rvalue)->kind == Ast_TernaryExpr) {
        result = ast_Parser_createBinaryTernary(this, lvalue, rvalue, operator);

    /* Binary expression with iterator value on the left-hand side */
    } else if (tleft && tleft->kind == CX_ITERATOR) {
        result = ast_Expression(ast_BinaryCreate(lvalue, rvalue, operator));

    /* Binary expression with primitive or reference values */
    } else {
        result = ast_Expression(ast_BinaryCreate(lvalue, rvalue, operator));

        /* Fold expression */
        if (result) {
            result = ast_Expression_fold(result);
            if (!result) {
                ast_Parser_error(this, "folding failed for expression");
                goto error;
            }
        }
    }

    if (!result) {
        goto error;
    }

    return result;
error:
    return NULL;
}

/* Callback function for expansion of element expressions */
cx_object ast_Parser_expandMember(ast_Parser this, ast_Expression lvalue, ast_Expression rvalue, void *userData) {
    CX_UNUSED(userData);
    CX_UNUSED(this);
    ast_Expression result = NULL;

    /* Create member expression */
    result = ast_Expression(ast_MemberCreate(lvalue, rvalue));
    if (!result) {
        goto error;
    }

    return result;
error:
    return NULL;
}


/* Callback function for expansion of element expressions */
cx_object ast_Parser_expandElement(ast_Parser this, ast_Expression lvalue, ast_Expression rvalue, void *userData) {
    CX_UNUSED(this);
    CX_UNUSED(userData);
    ast_Expression result = (ast_Expression)ast_ElementCreate(lvalue, rvalue);
    if (!result) {
        goto error;
    }

    return result;
error:
    return NULL;
}

/* Generic function to "explode" comma-expressions. This results in (ln * rn) expressions */
ast_Expression ast_Parser_explodeComma(ast_Parser this, ast_Expression lvalues, ast_Expression rvalues, ast_ExpandAction action, void *userData) {
    cx_ll lvalueList, rvalueList;
    ast_Expression result = NULL;
    ast_Expression var = NULL;
    cx_uint32 lvalueCount, rvalueCount;

    lvalueList = ast_Expression_toList(lvalues);
    rvalueList = ast_Expression_toList(rvalues);
    lvalueCount = cx_llSize(lvalueList);
    rvalueCount = cx_llSize(rvalueList);

    if ((rvalueCount > 1) && (lvalueCount == 1)) {
        /* Only temporarily store rvalue if it has side effects */
        if (ast_Expression_hasSideEffects(ast_Expression(cx_llGet(lvalueList,0)))) {
            if (ast_Node(rvalues)->kind != Ast_InitializerExpr) {
                var = ast_Expression(ast_TemporaryCreate(lvalues->type, lvalues->isReference));
                ast_Parser_addStatement(this, ast_Parser_binaryExpr(this, var, lvalues, CX_ASSIGN));
                rvalues = var;
            }
        }
    }

    ast_ExpressionListForeach(lvalueList, l)
        ast_ExpressionListForeach(rvalueList, r)
            ast_Expression e = action(this, var ? var : l, r, userData);
            if (!e) {
                goto error;
            }
            ast_Parser_collect(this, e);
            result = ast_Comma_addOrCreate(result, e);
        }
    }

    /* Clean-up list */
    ast_Expression_cleanList(lvalueList);
    ast_Expression_cleanList(rvalueList);

    return result;
error:
    return NULL;
}

/* Generic function to expand comma-expressions */
ast_Expression ast_Parser_expandComma(ast_Parser this, ast_Expression lvalues, ast_Expression rvalues, ast_ExpandAction action, ast_ExpandAction combine, void *userData) {
    cx_int16 lvalueCount, rvalueCount;
    cx_ll lvalueList, rvalueList;
    cx_iter lIter, rIter;
    cx_type tleft, tright;
    ast_Expression result = NULL, localResult = NULL;
    enum {
        EXPAND_LEFT,
        EXPAND_RIGHT,
        EXPAND_BOTH
    } expandMode = EXPAND_LEFT; /* Expand left, right or both */

    lvalueList = ast_Expression_toList(lvalues);
    rvalueList = ast_Expression_toList(rvalues);
    lvalueCount = cx_llSize(lvalueList);
    rvalueCount = cx_llSize(rvalueList);

    /* If there is more than one lvalue assign rvalue to temporary value first. This will assure that rvalue is evaluated
     * only once. */
    if ((lvalueCount > 1) && (rvalueCount == 1)) {
        /* Only temporarily store rvalue if it has side effects */
        if (ast_Expression_hasSideEffects(ast_Expression(cx_llGet(rvalueList,0)))) {
            if (ast_Node(rvalues)->kind != Ast_InitializerExpr) {
                ast_Expression var = ast_Expression(ast_TemporaryCreate(rvalues->type, FALSE));
                ast_Parser_addStatement(this, ast_Parser_binaryExpr(this, var, rvalues, CX_ASSIGN));
                rvalues = var;
            }
        }
        expandMode = EXPAND_LEFT;
    } else if ((rvalueCount > 1) && (lvalueCount == 1)) {
        expandMode = EXPAND_RIGHT;
    } else if (lvalueCount == rvalueCount) {
        expandMode = EXPAND_BOTH;
    } else {
        ast_Parser_error(this, "mismatch in expression count of binary operation (left = %d, right = %d)",
                          cx_llSize(lvalueList), cx_llSize(rvalueList));
        goto error;
    }

    /* Loop through lvalues */
    lIter = cx_llIter(lvalueList);
    rIter = cx_llIter(rvalueList);
    ast_Expression lvalue = lvalues;
    while((((expandMode == EXPAND_LEFT)||(expandMode == EXPAND_BOTH)) && cx_iterHasNext(&lIter)) || ((expandMode == EXPAND_RIGHT) && cx_iterHasNext(&rIter))) {

        /* If rvalueList is greater than 1, loop through rvalues as well */
        switch(expandMode) {
            case EXPAND_BOTH:
                rvalues = cx_iterNext(&rIter);
            case EXPAND_LEFT:
                lvalue = cx_iterNext(&lIter);
                break;
            case EXPAND_RIGHT:
                rvalues = cx_iterNext(&rIter);
                break;
        }

        /* Instantiate lvalue and rvalue into action-specific object */
        localResult = action(this, lvalue, rvalues, userData);
        if (!localResult) {
            goto error;
        }

        if (!(tleft = ast_Expression_getType_expr(lvalue,rvalues))) {
            goto error;
        }

        if (!(tright = ast_Expression_getType_expr(rvalues,lvalue))) {
            goto error;
        }

        if (localResult) {
            localResult = ast_Expression_fold(localResult);
            if (!localResult) {
                ast_Parser_error(this, "folding failed for expression");
            }
        }

        result = combine(this, result, localResult, userData);
    }

    /* Clean-up list */
    ast_Expression_cleanList(lvalueList);
    ast_Expression_cleanList(rvalueList);
    lvalueList = NULL;
    rvalueList = NULL;

    return result;
error:
    return NULL;
}

ast_Expression ast_Parser_resolve(ast_Parser this, cx_id id) {
    ast_Expression result = NULL;
    cx_object object;
    cx_char *ptr, ch;
    cx_id buffer;
    cx_char *bptr;

    if (strchr(id, ':')) {
        ptr = id;
        bptr = buffer;
        do {
            object = cx_resolve(this->scope, id);
            if (object){
                result = ast_Expression(ast_ObjectCreate(object));
                ast_Parser_collect(this, result);
                cx_release(object);
                break;
            } else {
                if (*ptr) {
                    while((ch=*ptr) && (ch != ':')) {
                        *bptr = ch;
                        bptr++;
                        ptr++;
                    }
                    *bptr = '\0';
                    cx_load(buffer, 0, NULL);
                    while((ch=*ptr) && (ch == ':')) {
                        *bptr = ch;
                        bptr++;
                        ptr++;
                    }
                    *bptr = '\0';
                } else {
                    goto error;
                }
            }
        }while(!object);
    } else {
        object = cx_resolve(this->scope, id);
        if (!object){
            cx_object rvalueType = ast_Parser_getLvalueType(this, FALSE);
            if (rvalueType && cx_checkAttr(rvalueType, CX_ATTR_SCOPED)) {
                object = cx_resolve(rvalueType, id);
            }
        }
        if (object) {
            result = ast_Expression(ast_ObjectCreate(object));
            ast_Parser_collect(this, result);
            cx_release(object);
        }
    }

    return result;
error:
    ast_Parser_error(this, "unresolved identifier '%s'", id);
    fast_err;
    return NULL;
}

/* Create an observer */
ast_Storage ast_Parser_observerCreate(ast_Parser this, cx_string id, ast_Expression object, cx_eventMask mask, ast_Object dispatcherVar) {
    ast_Storage result = NULL;
    cx_observer observer;
    cx_object observable = NULL;
    cx_object parent;
    cx_object dispatcher = NULL;

    /* If object is zero, this indicates either a template local or an expression during the 1st pass. TODO: how to handle
     * declaring expressions in the 1st pass - possible solution is setting the expression in the 2nd pass but then how can
     * the observer be identified?
     */

    parent = this->scope;
    if (!cx_class_instanceof(cx_type_o, parent)) {
        parent = NULL;
    }

    if (dispatcherVar) {
        dispatcher = ast_Object(dispatcherVar)->value;
    }

    if (object && (ast_Node(object)->kind == Ast_StorageExpr)) {
        switch(ast_Storage(object)->kind) {
        case Ast_ObjectStorage:
            observable = ast_Object(object)->value;
            break;
        case Ast_TemplateStorage:
            /* In case of template ('this') leave observable zero */
            break;
        default:
            break;
        }
    }

    /* If VALUE is not selected, set METAVALUE bit so VALUE won't be added
     * automatically. */
    if (!(mask & CX_ON_VALUE)) {
        mask |= CX_ON_METAVALUE;
    }

    /* Create observer */
    if (!id) {
        observer = cx_observerDeclare();
        if (!observer) {
            goto error;
        }

        /* Set values of observer - but don't yet define it. It will be defined when
         * the observer is bound to the implementation */
        cx_setref(&observer->observable, observable);
        observer->mask = mask;
        cx_setref(&observer->dispatcher, dispatcher);

        cx_attach(this->scope, observer);

        /* If observer is a template observer, manually attach */
        if (parent) {
            cx_class_bindObserver(cx_class(parent), observer);
        }
    } else {
        observer = cx_observerDeclareChild(this->scope, id);
        if (!observer) {
            goto error;
        }

        if (cx_observerDefine(observer, observable, mask, dispatcher, NULL)) {
            goto error;
        }
    }

    /* Create and collect result */
    result = (ast_Storage)ast_ObjectCreate(observer);
    ast_Parser_collect(this, result);

    return result;
error:
    fast_err;
    return NULL;
}

/* Declare a delegate type */
ast_Storage ast_Parser_declareDelegate(ast_Parser this, cx_type returnType, cx_string id, cx_bool returnsReference) {
    cx_delegate delegate;
    cx_parameterseq parameters;
    cx_id name;

    /* Translate from name to arguments */
    parameters = cx_function_stringToParameterSeq(id, this->scope);

    /* Obtain name */
    cx_signatureName(id, name);

    /* Declare and define delegate */
    delegate = cx_delegateDeclareChild(this->scope, name);
    if(!delegate) {
        goto error;
    }

    if(cx_delegateDefine(delegate, cx_type(returnType), returnsReference, parameters)) {
        goto error;
    }

    return ast_Storage(ast_ObjectCreate(delegate));
error:
    return NULL;
}

/* $end */

/* ::corto::ast::Parser::addStatement(ast::Node statement) */
cx_void _ast_Parser_addStatement(ast_Parser this, ast_Node statement) {
/* $begin(::corto::ast::Parser::addStatement) */
    ast_CHECK_ERRSET(this);

    /* Process staged declarations that do not have initializers (for example, enum Color:: RED, YELLOW, GREEN, BLUE;) */
    if (!this->pass && !statement) {
        if (this->stagingAllowed) {
            ast_Parser_initDeclareStaged(this, NULL);
        }
    }

    /* If this is the first pass and a comma expression is encountered, report error. Comma expressions
     * shouldn't be used by themselves. */
    if (!this->pass && statement) {
        if (statement->kind == Ast_CommaExpr) {
            ast_Parser_error(this, "invalid usage of comma expression");
            goto error;
        }
    /* If a comma expression is encountered in the second pass it could be the result of an expanded
     * comma expression. Only add if the expression has side effects. If it doesn't have side effects
     * it is likely the result of a staged declaration */
    } else if (this->pass && statement &&
              (statement->kind == Ast_CommaExpr) &&
              (!ast_Expression_hasSideEffects(ast_Expression(statement)))) {
        return;
    }

    if (statement) {
        if (this->block && (ast_Node(this->block->_while) != statement)) {
            if (this->block->_while) {
                ast_Parser_error(this, "invalid statement after while");
                goto error;
            }
            if (!((statement->kind == Ast_LiteralExpr) && (ast_Literal(statement)->kind == Ast_Text))) {
                ast_Block_addStatement(this->block, statement);
                if (cx_instanceof(cx_type(ast_Expression_o), statement)) {
                    if (!ast_Expression_hasSideEffects(ast_Expression(statement))) {
                        /* TODO: ast_Parser_warning(this, "computed value is not used (%s)", cx_nameof(cx_typeof(statement))); */
                    }
                }
            } else if (this->pass) {
                /* If statement is a string, insert println function */
                if (!this->repl) {
                    ast_Expression println = ast_Parser_lookup(this, "io::println(string)");
                    ast_Comma args = ast_CommaCreate();
                    ast_Comma_addExpression(args, ast_Expression(statement));
                    ast_Expression callExpr = ast_Parser_callExpr(this, println, ast_Expression(args));
                    ast_Block_addStatement(this->block, ast_Node(callExpr));
                    ast_Parser_collect(this, args);
                } else {
                    ast_Block_addStatement(this->block, statement);
                }
            }
        }
    }

    return;
error:
    fast_err;
/* $end */
}

/* ::corto::ast::Parser::argumentToString(type type,string id,bool reference) */
cx_string _ast_Parser_argumentToString(ast_Parser this, cx_type type, cx_string id, cx_bool reference) {
/* $begin(::corto::ast::Parser::argumentToString) */
    cx_string str;
    cx_string result;
    ast_CHECK_ERRSET(this);

    /* 1st pass & 2nd pass are equal */
    if (!type) {
        if (this->lastFailedResolve) {
            ast_Parser_error(this, "unresolved type '%s'", this->lastFailedResolve);
        } else {
            /* Cause is most likely an already reported error */
        }
        goto error;
    }

    if (!cx_class_instanceof(cx_type_o, type)) {
        cx_id id;
        ast_Parser_error(this, "object '%s' used in parameter expression is not a type", ast_Parser_id(type, id));
        goto error;
    }

    if (cx_checkAttr(type, CX_ATTR_SCOPED)) {
        cx_id id;
        if ((cx_parentof(type) == corto_o) || (cx_parentof(type) == corto_lang_o)) {
            str = strdup(cx_nameof(type));
        } else {
            str = strdup(ast_Parser_id(type, id));
        }
    } else {
        struct cx_serializer_s s;
        cx_string_ser_t walkData;

        memset(&walkData, 0, sizeof(walkData));
        s = cx_string_ser(CX_LOCAL, CX_NOT, CX_SERIALIZER_TRACE_NEVER);

        walkData.compactNotation = TRUE;
        walkData.prefixType = TRUE;

        if (cx_serialize(&s, type, &walkData)) {
            goto error;
        }
        str = walkData.buffer;
    }

    result = cx_alloc(strlen(str) + 1 + strlen(id) + 1 + 1);

    if (reference) {
        sprintf(result, "%s& %s", str, id);
    } else {
        sprintf(result, "%s %s", str, id);
    }

    cx_dealloc(str);

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::ast::Parser::binaryExpr(ast::Expression lvalues,ast::Expression rvalues,operatorKind operator) */
ast_Node _ast_Parser_binaryExpr(ast_Parser this, ast_Expression lvalues, ast_Expression rvalues, cx_operatorKind operator) {
/* $begin(::corto::ast::Parser::binaryExpr) */
    ast_Node result = NULL;
    ast_CHECK_ERRSET(this);

    this->stagingAllowed = FALSE;

    if (lvalues && rvalues && (this->pass || ((this->initializerCount >= 0) && this->initializers[this->initializerCount]))) {
        ast_ExpandAction combine = ast_Parser_combineComma;

        switch(operator) {
        case CX_ASSIGN_UPDATE: {
            cx_ll exprList = ast_Expression_toList(lvalues);

            /* Begin update (lock objects) */
            result = ast_Node(ast_UpdateCreate(exprList, NULL, NULL, Ast_UpdateBegin));
            if (!result) {
                goto error;
            }
            ast_Parser_addStatement(this, ast_Node(result));
            ast_Parser_collect(this, result);

            /* Insert assignment */
            if (!(result = ast_Parser_binaryExpr(this, lvalues, rvalues, CX_ASSIGN))) {
                goto error;
            }
            ast_Parser_addStatement(this, ast_Node(result));

            /* End expression (update in reverse order) */
            result = ast_Node(ast_UpdateCreate(exprList, NULL, NULL, Ast_UpdateEnd));
            if (!result) {
                goto error;
            }
            break;
        }
        case CX_COND_EQ:
        case CX_COND_NEQ:
        case CX_COND_AND:
        case CX_COND_OR:
        case CX_COND_GT:
        case CX_COND_LT:
        case CX_COND_GTEQ:
        case CX_COND_LTEQ:
            combine = ast_Parser_combineConditionalExpr;
        /* fallthrough */
        default:
            if (!(result = ast_Node(
                ast_Parser_expandComma(this, lvalues, rvalues, ast_Parser_expandBinary, combine, &operator)))) {
                goto error;
            }
            break;
        }
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::ast::Parser::bind(ast::Storage function,ast::Block block) */
cx_int16 _ast_Parser_bind(ast_Parser this, ast_Storage function, ast_Block block) {
/* $begin(::corto::ast::Parser::bind) */
    ast_Binding *binding;
    ast_CHECK_ERRSET(this);

    if (this->pass && function) {
        if (function->kind == Ast_ObjectStorage) {
            binding = cx_calloc(sizeof(ast_Binding));
            cx_setref(&binding->function, ast_Object(function)->value);
            cx_setref(&binding->impl, block);
            cx_assert(this->bindings != NULL, "initialization failed");
            cx_llAppend(this->bindings, binding);
        }
    }

    return 0;
/* $end */
}

/* ::corto::ast::Parser::bindOneliner(ast::Storage function,ast::Block block,ast::Expression expr) */
cx_int16 _ast_Parser_bindOneliner(ast_Parser this, ast_Storage function, ast_Block block, ast_Expression expr) {
/* $begin(::corto::ast::Parser::bindOneliner) */
    ast_CHECK_ERRSET(this);

    if (this->pass) {
        ast_Expression returnLocal;
        cx_id functionName;

        /* Add oneliner to block */
        cx_signatureName(cx_nameof(ast_Object(function)->value), functionName);
        returnLocal = ast_Block_lookup(block, functionName);
         if (returnLocal) {
            ast_Expression returnAssign;

            /* In one-liners, a reference returnvalue is always addressed by reference */
            if (!ast_Expression(returnLocal)->type->reference && ast_Expression(returnLocal)->isReference) {
                returnLocal = ast_Parser_unaryExpr(this, returnLocal, CX_AND);
            }

            returnAssign = ast_Expression(ast_Parser_binaryExpr(this, returnLocal, expr, CX_ASSIGN));
            if (returnAssign) {
                ast_Block_addStatement(block, ast_Node(returnAssign));
            } else {
                goto error;
            }
        } else {
            ast_Parser_error(this, "invalid assignment to function with no returntype");
            goto error;
        }

        /* Bind function */
        ast_Parser_bind(this, function, block);
    }

    return 0;
error:
    fast_err;
    return -1;
/* $end */
}

/* ::corto::ast::Parser::blockPop() */
cx_void _ast_Parser_blockPop(ast_Parser this) {
/* $begin(::corto::ast::Parser::blockPop) */
    ast_CHECK_ERRSET(this);

    this->blockCount--;

    /* Blocks are parsed only in 2nd pass */
    if (this->pass) {
        if (this->block) {
            cx_setref(&this->block, this->block->parent);
        } else {
            /* Got confused by earlier errors */
            ast_Parser_error(this, "unable to continue parsing due to previous errors");
            this->abort = TRUE;
        }
    }
    this->blockPreset = FALSE;

/* $end */
}

/* ::corto::ast::Parser::blockPush(bool presetBlock) */
ast_Block _ast_Parser_blockPush(ast_Parser this, cx_bool presetBlock) {
/* $begin(::corto::ast::Parser::blockPush) */
    ast_CHECK_ERRSET(this);

    if (!this->blockPreset || presetBlock) {
        this->blockCount++;
    }

    /* Blocks are parsed only in 2nd pass */
    if (this->pass) {
        ast_Block newBlock;

        newBlock = NULL;

        if (!this->blockPreset || presetBlock) {
            newBlock = ast_BlockCreate(this->block);
            ast_Parser_collect(this, newBlock);
            cx_setref(&this->block, newBlock);
        }

        this->blockPreset = presetBlock;
        return newBlock;
    } else {
        this->blockPreset = presetBlock;
        return NULL;
    }
/* $end */
}

/* ::corto::ast::Parser::callExpr(ast::Expression function,ast::Expression arguments) */
ast_Expression _ast_Parser_callExpr(ast_Parser this, ast_Expression function, ast_Expression arguments) {
/* $begin(::corto::ast::Parser::callExpr) */
    ast_Expression result = NULL;

    this->stagingAllowed = FALSE;

    if (function && this->pass) {
        cx_object o = NULL;
        ast_ExpressionList functions = function ? ast_Expression_toList(function) : NULL;
        ast_ExpressionList args = arguments ? ast_Expression_toList(arguments) : NULL;

        if (functions) {ast_ExpressionListForeach(functions, f)
            ast_Expression expr;
            if ((ast_Node(f)->kind == Ast_StorageExpr) && (ast_Storage(f)->kind == Ast_ObjectStorage)) {
                o = ast_Object(f)->value;
            }
            /* If function is a type, insert cast */
            if (o && cx_instanceof(cx_type(cx_type_o), o)) {
                cx_ll exprs = ast_Expression_toList(arguments);
                if (cx_llSize(exprs) != 1) {
                    ast_Parser_error(this, "invalid number of parameters for cast (expected 1)");
                    ast_Expression_cleanList(exprs);
                    goto error;
                }
                expr = ast_Parser_castExpr(this, o, cx_llGet(exprs, 0));
                ast_Expression_cleanList(exprs);
                ast_Parser_collect(this, expr);
            } else {
                expr = ast_Expression(ast_createCallFromExpr(f, arguments));
            }
            if (!expr) {
                goto error;
            }
            result = ast_Comma_addOrCreate(result, expr);
        }}

        /* Cleanup initializer arguments */
        if (args) {ast_ExpressionListForeach(args, a)
            if (ast_Node(a)->kind == Ast_InitializerExpr) {
                ast_Expression var = ast_Initializer(a)->variables[0].object;
                if (ast_Storage(var)->kind == Ast_TemporaryStorage) {
                    ast_Deinit deinit = ast_DeinitCreate(ast_Storage(var));
                    result = ast_Comma_addOrCreate(result, ast_Expression(deinit));
                    ast_Parser_collect(this, deinit);
                }
            }
        }}
        
        ast_Expression_cleanList(functions);
        ast_Expression_cleanList(args);
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::ast::Parser::castExpr(type lvalue,ast::Expression rvalue) */
ast_Expression _ast_Parser_castExpr(ast_Parser this, cx_type lvalue, ast_Expression rvalue) {
/* $begin(::corto::ast::Parser::castExpr) */
    ast_Expression result = NULL;

    this->stagingAllowed = FALSE;

    if (this->pass) {
        cx_type rvalueType;
        cx_bool castRequired = TRUE;

        rvalueType = ast_Expression_getType(rvalue);

        if (lvalue == rvalueType) {
            cx_id id;
            ast_Parser_warning(this, "casting to value of the same type (%s)", ast_Parser_id(lvalue, id));
            castRequired = FALSE;
        } else {
            if ((lvalue->kind == CX_COMPOSITE) && (rvalueType->kind == CX_COMPOSITE)) {
                if (cx_type_castable(lvalue, rvalueType)) {
                    cx_id id1, id2;
                    castRequired = FALSE;
                    ast_Parser_warning(this, "upcasting from '%s' to '%s' does not require an explicit cast",
                            ast_Parser_id(rvalueType, id1), ast_Parser_id(lvalue, id2));
                }
            } else if (ast_Node(rvalue)->kind == Ast_LiteralExpr) {
                result = ast_Expression_cast(rvalue, lvalue, FALSE);
                castRequired = FALSE;
            }
        }

        if (castRequired) {
            result = ast_Expression(ast_CastCreate(lvalue, rvalue, FALSE));
            if (!result) {
                goto error;
            }
            ast_Parser_collect(this, result);
        } else if (!result) {
            result = rvalue;
        }
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::ast::Parser::collect(object o) */
cx_void _ast_Parser_collect(ast_Parser this, cx_object o) {
/* $begin(::corto::ast::Parser::collect) */
    /* 1st pass & 2nd pass are equal */

    cx_assert(this->collected != NULL, "initialization failed");
    cx_llInsert(this->collected, o);

/* $end */
}

/* ::corto::ast::Parser::collectHeap(word addr) */
cx_void _ast_Parser_collectHeap(ast_Parser this, cx_word addr) {
/* $begin(::corto::ast::Parser::collectHeap) */
    ast_CHECK_ERRSET(this);

    /* 1st pass & 2nd pass are equal */
    cx_assert(this->heapCollected != NULL, "initialization failed");
    cx_llInsert(this->heapCollected, (void*)addr);

/* $end */
}

/* ::corto::ast::Parser::construct() */
cx_int16 _ast_Parser_construct(ast_Parser this) {
/* $begin(::corto::ast::Parser::construct) */
    CX_UNUSED(this);
    ast_Parser_reset(this);
    cx_threadTlsSet(ast_PARSER_KEY, this);
    return 0;
/* $end */
}

/* ::corto::ast::Parser::declaration(type type,string id,bool isReference) */
ast_Storage _ast_Parser_declaration(ast_Parser this, cx_type type, cx_string id, cx_bool isReference) {
/* $begin(::corto::ast::Parser::declaration) */
    ast_Storage result = NULL;
    ast_CHECK_ERRSET(this);

    if (!this->block) {
        goto error;
    }

    this->stagingAllowed = FALSE;

    /* If block is not root or local-keyword is used, declare local */
    if (this->blockCount || this->isLocal) {
        if (this->pass) {
            if (!type) {
                if (this->lastFailedResolve) {
                    ast_Parser_error(this, "unresolved type '%s'", this->lastFailedResolve);
                    goto error;
                } else {
                    cx_assert(type != NULL, "no type provided for declaration");
                }
            }
            cx_assert(this->block != NULL, "no valid code-block set in parser context.");

            /* If the variable is declared in the global scope, verify that its name doesn't clash with an object */
            if (!this->block->parent) {
                cx_object o;
                if ((o = cx_resolve(this->scope, id))) {
                    ast_Parser_error(this, "object '%s' is redeclared as a variable", id);
                    cx_release(o);
                    goto error;
                }
            }

            /* Redundant reference specifier if the type is also a reference */
            if (type->reference && isReference) {
                cx_id id;
                ast_Parser_error(yparser(), "redundant '&' in declaration of '%s', type '%s' is already a reference type",
                    id, ast_Parser_id(type, id));
                goto error;
            }

            result = ast_Storage(ast_Block_declare(this->block, id, type, FALSE, isReference));
            this->variables[this->variableCount] = result;
            this->variableCount++;
        } else {
            /* Variables are declared in 2nd pass */
            this->variables[this->variableCount] = NULL;
            this->variableCount++;
        }
    } else {
        cx_object o;
        if (!type) {
            if (this->lastFailedResolve) {
                ast_Parser_error(this, "unresolved type '%s'", this->lastFailedResolve);
                goto error;
            } else {
                cx_assert(type != NULL, "no type provided for declaration");
            }
        }
        cx_assert(this->block != NULL, "no valid code-block set in parser context.");

        if (!this->pass) {
            o = cx_declareChild(this->scope, id, type);
            if (!o) {
                cx_id id1;
                ast_Parser_error(this, "declare of '%s' of type '%s' failed",
                        id,
                        ast_Parser_id(type, id1));
                goto error;
            }
        } else {
            o = cx_lookup(this->scope, id);
            cx_assert(o != NULL, "object disappeared in 2nd pass");
            cx_release(o);
        }
        if (o) {
            result = ast_Storage(ast_ObjectCreate(o));
            ast_Parser_collect(this, result);
            this->variables[this->variableCount] = result;
            this->variableCount++;
        }
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::ast::Parser::declareFunction(type returnType,string id,type kind,bool returnsReference) */
ast_Storage _ast_Parser_declareFunction(ast_Parser this, cx_type returnType, cx_string id, cx_type kind, cx_bool returnsReference) {
/* $begin(::corto::ast::Parser::declareFunction) */
    cx_function function;
    cx_object o;
    cx_type functionType = cx_type(kind);
    ast_Storage result = NULL;
    cx_int32 distance;
    ast_CHECK_ERRSET(this);

    if (!this->pass) {
        cx_id functionName;

        if (!returnType) {
            if (this->lastFailedResolve) {
                ast_Parser_error(this, "unresolved type '%s'", this->lastFailedResolve);
                goto error;
            } else {
                cx_assert(returnType != NULL, "no type provided for declaration");
            }
        }

        /* Obtain name of function */
        cx_signatureName(id, functionName);

        /* Resolve identifier first to verify whether it is not already in use as non-function object */
        if ((o = cx_lookup(this->scope, functionName))) {
            if (!cx_instanceof(cx_type(cx_function_o), o)) {
                cx_id id2;
                // todo changed here
                ast_Parser_error(this, "cannot redeclare '%s' of type '%s' as function",
                    id, ast_Parser_id(cx_typeof(o), id2));
                goto error;
            }
            cx_release(o);
        }

        /* This could be an implementation after a forward declaration so try to resolve
         * function first. */
        if (!((function = cx_lookupFunction(this->scope, id, &distance)) && !distance)) {
            if (!functionType) {
                if (cx_class_instanceof(cx_interface_o, this->scope)) {
                    functionType = cx_type(cx_method_o);
                } else {
                    functionType = cx_type(cx_function_o);
                }
            } else {
                /* Check whether declaration is a delegate */
                if(cx_interface_baseof(cx_interface(kind), cx_interface(cx_delegate_o))) {
                    result = ast_Parser_declareDelegate(
                        this,
                        returnType,
                        id,
                        returnsReference);
                }
            }

            if (!result) {
                if (!cx_class_instanceof(cx_type_o, returnType)) {
                    cx_id id;
                    ast_Parser_error(this, "object '%s' specified as returntype is not a type.", ast_Parser_id(returnType, id));
                    goto error;
                }

                function = cx_declareChild(this->scope, id, functionType);
                if (!function) {
                    ast_Parser_error(this, "declare of '%s' failed",
                                      functionName);
                    goto error;
                }

                cx_setref(&function->returnType, returnType);
                function->returnsReference = returnsReference;
            }
        } else {
            cx_release(function);
        }

        if (!result) {
            result = ast_Storage(ast_ObjectCreate(function));
            ast_Parser_collect(this, result);
        }
    } else {
        if(!kind || (cx_interface(kind)->kind == CX_PROCEDURE)) {
            cx_id query;
            cx_char *ptr, *bptr, ch;

            /* If there are references in the function id, transform them into forced references so that the correct function
             * is resolved */
            ptr = id;
            bptr = query;
            while ((ch = *ptr)) {
                *bptr = ch;
                if (ch == '&') {
                    bptr++;
                    *bptr = '&'; /* && will enforce selection of a function that accepts a reference */
                }
                bptr++;
                ptr++;
            }
            *bptr = '\0';

            cx_object function = cx_resolve(this->scope, query);
            cx_assert(function != NULL, "object should still be there in 2nd pass");

            result = ast_Storage(ast_ObjectCreate(function));
            ast_Parser_collect(this, result);
            cx_release(function);
        }
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::ast::Parser::declareFunctionParams(Storage function) */
ast_Block _ast_Parser_declareFunctionParams(ast_Parser this, ast_Storage function) {
/* $begin(::corto::ast::Parser::declareFunctionParams) */
    cx_function function_o;
    cx_parameter *param;
    ast_Block result = NULL;
    unsigned int i;
    ast_CHECK_ERRSET(this);

    if (this->pass && function) {
        result = ast_Parser_blockPush(this, TRUE);

        function_o = ast_Object(function)->value;
        ast_Block_setFunction(result, function_o);

        /* If function is a method, include 'this' pointer */
        if (cx_procedure(cx_typeof(function_o))->kind == CX_METHOD) {
            cx_object parent;

            if (!cx_instanceof(cx_type(cx_interface_o), cx_parentof(function_o))) {
                parent = cx_typeof(cx_parentof(function_o));
            } else {
                parent = cx_parentof(function_o);
            }

            if (!cx_instanceof(cx_type(cx_interface_o), parent)) {
                cx_id id;
                ast_Parser_error(this, "parent of '%s' is not an interface nor of an interface type",
                    ast_Parser_id(function_o, id));
                goto error;
            }

            ast_Block_declare(result, "this", parent, TRUE, FALSE);

            /* If this-type of method has a base, include super */
            if (cx_interface(parent)->base) {
                ast_Block_declare(result, "super", cx_type(cx_interface(parent)->base), TRUE, FALSE);
            }
        }

        for(i=0; i<function_o->parameters.length; i++) {
            param = &function_o->parameters.buffer[i];
            ast_Block_declare(result, param->name, param->type, TRUE, param->passByReference);
        }

        /* If function has a returntype, include name of function */
        if (function_o->returnType && ((function_o->returnType->kind != CX_VOID) || function_o->returnType->reference)) {
            ast_Block_declareReturnVariable(result, function_o);
        }
    }

    return result;
error:
    return NULL;
/* $end */
}

/* ::corto::ast::Parser::define() */
cx_int16 _ast_Parser_define(ast_Parser this) {
/* $begin(::corto::ast::Parser::define) */
    ast_CHECK_ERRSET(this);

    if ((this->initializerCount >= 0) && this->initializers[this->initializerCount]) {
        if (ast_Initializer_define(this->initializers[this->initializerCount])) {
            goto error;
        }
        cx_setref(&this->initializers[this->initializerCount], NULL);
        this->initializerCount--;
    }

    return 0;
error:
    fast_err;
    return -1;
/* $end */
}

/* ::corto::ast::Parser::defineScope() */
cx_int16 _ast_Parser_defineScope(ast_Parser this) {
/* $begin(::corto::ast::Parser::defineScope) */
    ast_CHECK_ERRSET(this);

    if (!this->pass) {
        if (!this->scope) {
            ast_Parser_error(this, "invalid scope expression");
            goto error;
        }

        if (cx_instanceof(cx_type(cx_type_o), this->scope)) {
            if (cx_define(this->scope)) {
                cx_id id;
                ast_Parser_error(this, "failed to define scope '%s'", ast_Parser_id(this->scope, id));
                goto error;
            }
        } else {
            ast_Define defineExpr = ast_DefineCreate(ast_Expression(ast_ObjectCreate(this->scope)));
            ast_Parser_addStatement(this, ast_Node(defineExpr));
            ast_Parser_collect(this, defineExpr);
        }
    }

    return 0;
error:
    fast_err;
    return -1;
/* $end */
}

/* ::corto::ast::Parser::defineVariable(Storage object) */
cx_int16 _ast_Parser_defineVariable(ast_Parser this, ast_Storage object) {
/* $begin(::corto::ast::Parser::defineVariable) */
    cx_int16 result = 0;
    CX_UNUSED(this);
    ast_CHECK_ERRSET(this);

    if ((ast_Node(object)->kind == Ast_StorageExpr) && (ast_Storage(object)->kind == Ast_ObjectStorage)) {
        if (cx_define(ast_Object(object)->value)) {
            cx_id id1, id2;
            ast_Parser_error(this, "define of variable '%s' of type '%s' failed",
                    ast_Parser_id(ast_Object(object)->value, id1),
                    ast_Parser_id(cx_typeof(ast_Object(object)->value), id2));
            goto error;
        }
    } else {
        ast_Define defineStmt;
        defineStmt = ast_DefineCreate((ast_Expression)object);
        ast_Parser_collect(this, defineStmt);
        ast_Parser_addStatement(this, ast_Node(defineStmt));
    }

    return result;
error:
    fast_err;
    return -1;
/* $end */
}

/* ::corto::ast::Parser::destruct() */
cx_void _ast_Parser_destruct(ast_Parser this) {
/* $begin(::corto::ast::Parser::destruct) */
    cx_iter iter;

    if (this->heapCollected) {
        iter = cx_llIter(this->heapCollected);
        while(cx_iterHasNext(&iter)) {
            cx_dealloc(cx_iterNext(&iter));
        }
        cx_llFree(this->heapCollected);
    }

    this->heapCollected = NULL;
    cx_setref(&this->scope, NULL);

    memset(this->variables, 0, sizeof(this->variables));
/* $end */
}

/* ::corto::ast::Parser::elementExpr(ast::Expression lvalue,ast::Expression rvalue) */
ast_Expression _ast_Parser_elementExpr(ast_Parser this, ast_Expression lvalue, ast_Expression rvalue) {
/* $begin(::corto::ast::Parser::elementExpr) */
    ast_Expression result = NULL;

    /* Expand element expression with comma-expressions */
    if (this->pass) {
        cx_type t = ast_Expression_getType(lvalue);
        /* If the left value is a composite type then translate element expression to members */
        if (t) {
            if (t->kind == CX_COMPOSITE) {
                if (!(result = ast_Parser_explodeComma(this, lvalue, rvalue, ast_Parser_expandMember, NULL))) {
                    goto error;
                }
            } else {
                if (!(result = ast_Parser_explodeComma(this, lvalue, rvalue, ast_Parser_expandElement, NULL))) {
                    goto error;
                }
            }
        } else {
            ast_Parser_error(this, "cannot resolve element, left-hand of expression has no type");
            goto error;
        }
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::ast::Parser::finalize(ic::program program) */
cx_int16 _ast_Parser_finalize(ast_Parser this, ic_program program) {
/* $begin(::corto::ast::Parser::finalize) */
    ic_scope scope = NULL;
    ic_storage returnValue = NULL;
    ast_Binding *binding;
    cx_iter bindingIter;

    /* Parse functions */
    if (this->bindings) {
        bindingIter = cx_llIter(this->bindings);
        while(cx_iterHasNext(&bindingIter)) {
            ic_op ret;
            binding = cx_iterNext(&bindingIter);
            ic_program_pushFunction(program, binding->function);
            scope = (ic_scope)ast_Block_toIc(binding->impl, program, NULL, FALSE);
            if (this->errors) {
                goto error;
            }
            if (binding->function->returnType && ((binding->function->returnType->kind != CX_VOID) || (binding->function->returnType->reference))) {
                cx_id name;
                cx_signatureName(cx_nameof(binding->function), name);
                returnValue = ic_scope_lookupStorage(scope, name, TRUE);
                ret = IC_1_OP(this->line, ic_ret, returnValue, IC_DEREF_VALUE, FALSE);
                if (binding->function->returnsReference || binding->function->returnType->reference) {
                    ((ic_storage)returnValue)->isReference = TRUE;
                    ((ic_op)ret)->s1Deref = IC_DEREF_ADDRESS;
                }else {
                    ((ic_op)ret)->s1Deref = IC_DEREF_VALUE;
                }
            } else {
                ret = IC_1_OP(this->line, ic_stop, NULL, IC_DEREF_VALUE, FALSE);
            }

            ic_scope_add(scope, ic_node(ret));
            ic_program_popScope(program);

            cx_release(binding->function);
            cx_release(binding->impl);
            cx_dealloc(binding);
        }
        cx_llFree(this->bindings);
        this->bindings = NULL;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::ast::Parser::foreach(string loopId,ast::Expression collection) */
cx_int16 _ast_Parser_foreach(ast_Parser this, cx_string loopId, ast_Expression collection) {
/* $begin(::corto::ast::Parser::foreach) */
    CX_UNUSED(this);
    CX_UNUSED(loopId);
    CX_UNUSED(collection);
    return 0;
/* $end */
}

/* ::corto::ast::Parser::getComplexType() */
cx_type _ast_Parser_getComplexType(ast_Parser this) {
/* $begin(::corto::ast::Parser::getComplexType) */
    cx_type result = NULL;

    if (this->complexTypeSp > 0) {
        result = this->complexType[this->complexTypeSp-1];
        if (result && (result->kind != CX_COMPOSITE)) {
            result = NULL;
        }
    }

    return result;
/* $end */
}

/* ::corto::ast::Parser::getLvalue(bool assignment) */
ast_Expression _ast_Parser_getLvalue(ast_Parser this, cx_bool assignment) {
/* $begin(::corto::ast::Parser::getLvalue) */
    ast_Expression result = NULL;

    if (this->lvalueSp > 0) {
        result = this->lvalue[this->lvalueSp-1].expr;
        if (assignment) {
            if (!this->lvalue[this->lvalueSp-1].isAssignment) {
                result = NULL;
            }
        }
    }

    return result;
/* $end */
}

/* ::corto::ast::Parser::getLvalueType(bool assignment) */
cx_type _ast_Parser_getLvalueType(ast_Parser this, cx_bool assignment) {
/* $begin(::corto::ast::Parser::getLvalueType) */
    cx_type result = NULL;

    /* Check if the parser set an lvalue */
    if ((this->lvalueSp > 0) && this->lvalue[this->lvalueSp-1].expr) {
        result = ast_Expression_getType(this->lvalue[this->lvalueSp-1].expr);
    }

    /* If no lvalue is set, check if there is an active initializer */
    if (!result) {
        if ((this->initializerCount >= 0) && (this->initializers[this->initializerCount])) {
            result = ast_Initializer_currentType(this->initializers[this->initializerCount]);
        }
    }

    if (assignment) {
        if (!this->lvalue[this->lvalueSp-1].isAssignment) {
            result = NULL;
        }
    }

    return result;
/* $end */
}

/* ::corto::ast::Parser::ifStatement(ast::Expression condition,ast::Block trueBranch,ast::If falseBranch) */
ast_Node _ast_Parser_ifStatement(ast_Parser this, ast_Expression condition, ast_Block trueBranch, ast_If falseBranch) {
/* $begin(::corto::ast::Parser::ifStatement) */
    ast_Node result = NULL;

    if (this->pass) {
        result = ast_Node(ast_IfCreate(condition, trueBranch, falseBranch));
        if (!result) {
            goto error;
        }
        ast_Parser_collect(this, result);
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::ast::Parser::initDeclareStaged(ast::Expression expr) */
cx_void _ast_Parser_initDeclareStaged(ast_Parser this, ast_Expression expr) {
/* $begin(::corto::ast::Parser::initDeclareStaged) */
    cx_uint32 i;

    this->variableCount = 0;

    if (expr) {
        cx_ll exprList = ast_Expression_toList(expr);
        cx_iter iter = cx_llIter(exprList);

        if (this->stagedCount) {
            ast_Parser_error(this, "invalid declaration");
            goto error;
        }

        while(cx_iterHasNext(&iter)) {
            this->variables[this->variableCount] = cx_iterNext(&iter);
            this->variableCount++;
        }

        ast_Expression_cleanList(exprList);
    } else {
        for(i=0; i<this->stagedCount; i++) {
            if (cx_instanceof(cx_type(cx_type_o), this->scope)) {
                cx_type defaultType;
                cx_type scopeType = cx_type(this->scope);
                if (scopeType->defaultType) {
                    defaultType = scopeType->defaultType;
                } else {
                    defaultType = cx_any_o;
                }

                /* Add variable to parser-list for initialization */
                ast_Parser_declaration(this, defaultType, this->staged[i].name, FALSE);

                cx_dealloc(this->staged[i].name);
                this->staged[i].name = NULL;
            }
        }
    }

    this->stagedCount = 0;
    return;
error:
    fast_err;
/* $end */
}

/* ::corto::ast::Parser::initKeyValuePop() */
cx_int16 _ast_Parser_initKeyValuePop(ast_Parser this) {
/* $begin(::corto::ast::Parser::initKeyValuePop) */
    if ((this->initializerCount >= 0) && this->initializers[this->initializerCount]) {
        if (ast_Initializer_popKey(this->initializers[this->initializerCount])) {
            goto error;
        }
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::ast::Parser::initKeyValuePush() */
cx_int16 _ast_Parser_initKeyValuePush(ast_Parser this) {
/* $begin(::corto::ast::Parser::initKeyValuePush) */
    if ((this->initializerCount >= 0) && this->initializers[this->initializerCount]) {
        if (ast_Initializer_pushKey(this->initializers[this->initializerCount])) {
            goto error;
        }
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::ast::Parser::initKeyValueSet(ast::Expression expr) */
cx_int16 _ast_Parser_initKeyValueSet(ast_Parser this, ast_Expression expr) {
/* $begin(::corto::ast::Parser::initKeyValueSet) */
    if ((this->initializerCount >= 0) && this->initializers[this->initializerCount]) {
        if (ast_Initializer_valueKey(this->initializers[this->initializerCount], expr)) {
            goto error;
        }
    }

    return 0;
error:
    return -1;

/* $end */
}

/* ::corto::ast::Parser::initMember(string member) */
cx_int16 _ast_Parser_initMember(ast_Parser this, cx_string member) {
/* $begin(::corto::ast::Parser::initMember) */
    ast_CHECK_ERRSET(this);

    if ((this->initializerCount >= 0) && this->initializers[this->initializerCount]) {
        if (ast_Initializer_member(this->initializers[this->initializerCount], member)) {
            goto error;
        }
    }

    return 0;
error:
    fast_err;
    return -1;
/* $end */
}

/* ::corto::ast::Parser::initPop() */
cx_int16 _ast_Parser_initPop(ast_Parser this) {
/* $begin(::corto::ast::Parser::initPop) */
    ast_CHECK_ERRSET(this);

    /* Primitive values are not pushed/pop'd */
    if ((this->initializerCount >= 0) && this->initializers[this->initializerCount]) {
        if (ast_Initializer_pop(this->initializers[this->initializerCount])) {
            goto error;
        }
    }

    return 0;
error:
    fast_err;
    return -1;
/* $end */
}

/* ::corto::ast::Parser::initPush() */
cx_int16 _ast_Parser_initPush(ast_Parser this) {
/* $begin(::corto::ast::Parser::initPush) */
    ast_CHECK_ERRSET(this);

    if (!this->variablePushed) {
        if ((this->initializerCount>=0) && this->initializers[this->initializerCount]) {
            if (ast_Initializer_push(this->initializers[this->initializerCount])) {
                ast_Parser_error(this, "invalid initializer scope");
                goto error;
            }
        }
    } else {
        this->variablePushed = FALSE;
    }

    return 0;
error:
    fast_err;
    return -1;
/* $end */
}

/* ::corto::ast::Parser::initPushExpression() */
ast_Expression _ast_Parser_initPushExpression(ast_Parser this) {
/* $begin(::corto::ast::Parser::initPushExpression) */
    ast_Initializer initializer = NULL;

    this->initializerCount++;

    if (this->pass) {
        ast_InitializerVariableArray64 variables;

        memset(variables, 0, sizeof(variables));

        /* Create initializer */
        initializer = ast_Initializer(Ast_InitializerExpressionCreate(variables, 1, TRUE));
        cx_setref(&this->initializers[this->initializerCount], initializer);
        ast_Parser_collect(this, initializer);
        this->variablePushed = TRUE;
    }

    return ast_Expression(initializer);
/* $end */
}

/* ::corto::ast::Parser::initPushIdentifier(Expression type) */
ast_Expression _ast_Parser_initPushIdentifier(ast_Parser this, ast_Expression type) {
/* $begin(::corto::ast::Parser::initPushIdentifier) */
    cx_object o;
    cx_type t;
    cx_bool isDynamic = TRUE;
    cx_bool forceStatic = FALSE;
    ast_InitializerVariableArray64 variables;
    memset(variables, 0, sizeof(variables));

    CX_UNUSED(this);
    CX_UNUSED(type);

    if (!type) {
        if (this->lastFailedResolve) {
            ast_Parser_error(this, "unresolved identifier '%s'", this->lastFailedResolve);
            goto error;
        } else {
            ast_Parser_error(this, "invalid expression");
            goto error;
        }
    }

    o = cx_type(ast_Object(type)->value);
    if (!cx_instanceof(cx_type(cx_type_o), o)) {
        cx_id id;
        ast_Parser_error(this, "invalid expression, '%s' is not a type", ast_Parser_id(o, id));
        goto error;
    }

    t = o;

    if (this->initializerCount >= 0) {
        ast_Initializer initializer = this->initializers[this->initializerCount];
        if (initializer) {
            if (!cx_instanceof(cx_type(ast_DynamicInitializer_o), initializer) &&
                !cx_instanceof(cx_type(Ast_InitializerExpression_o), initializer)) {
                isDynamic = FALSE; /* A previous initializer is static, so this initializer will be static as well */
            }
        } else if (this->pass) {
            isDynamic = FALSE; /* If initializer is NULL and parser is in second pass initializer must be static */
        }
    }

    this->initializerCount++;

    /* The first pass will always create a static initializer when t is a type. This is required for declarations with anonymous
     * types. The parser can't determine upfront whether an anonymous object will be used in a declaration so this is determined
     * afterwards. */
    if (cx_instanceof(cx_type(cx_interface_o), t) && cx_interface_baseof(cx_interface(t), cx_interface(cx_type_o))) {
        forceStatic = TRUE;
    }

    /* Static initializers are executed during first pass */
    if ((!this->pass && !isDynamic) || forceStatic) {
        cx_object o;
        o = cx_declare(t);
        cx_setref(&variables[0].object, ast_Expression(ast_ObjectCreate(o)));
        this->initializers[this->initializerCount] = ast_Initializer(ast_StaticInitializerCreate(variables, 1));
        this->variablePushed = TRUE;
    } else if (this->pass && isDynamic && !forceStatic) {
        ast_Expression newExpr, assignExpr, var, refVar;
        cx_type type_o = cx_type(ast_Object(type)->value);
        refVar = var = ast_Expression(ast_TemporaryCreate(ast_Object(type)->value, TRUE));
        newExpr = ast_Expression(ast_NewCreate(ast_Object(type)->value,0));
        ast_Parser_collect(this, newExpr);
        if (!type_o->reference) {
            refVar = ast_Parser_unaryExpr(this, var, CX_AND);
            ast_Parser_collect(yparser(), refVar);
        }
        assignExpr = ast_Expression(ast_BinaryCreate(refVar, newExpr, CX_ASSIGN));
        ast_Parser_collect(this, assignExpr);
        ast_Parser_addStatement(this, ast_Node(assignExpr));

        cx_setref(&variables[0].object, var);
        this->initializers[this->initializerCount] = ast_Initializer(ast_DynamicInitializerCreate(variables, 1, FALSE));
        this->variablePushed = TRUE;
    } else {
        cx_setref(&this->initializers[this->initializerCount], NULL);
        this->variablePushed = TRUE;
    }

    return variables[0].object;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::ast::Parser::initPushStatic() */
cx_int16 _ast_Parser_initPushStatic(ast_Parser this) {
/* $begin(::corto::ast::Parser::initPushStatic) */
    cx_bool isLocal = this->isLocal;
    ast_InitializerVariableArray64 variables;
    ast_Initializer initializer;
    cx_uint32 i;

    this->initializerCount++;

    if (!isLocal && this->variableCount) {
        if (ast_Storage(this->variables[0])->kind != Ast_ObjectStorage) {
            isLocal = TRUE;
        }
    }

    /* Initializers are invalid for local variables - use assignments for these. */
    if (isLocal) {
        ast_Parser_error(this, "usage of initializer invalid for local variables (use assignment instead)");
        goto error;
    }

    if (!this->variableCount) {
        ast_Parser_error(this, "invalid initializer");
        goto error;
    }

    memset(variables, 0, sizeof(variables));

    /* Copy variables from parser to initializer structure */
    for(i=0; i<this->variableCount; i++) {
        cx_setref(&variables[i].object, ast_Expression(this->variables[i]));
        variables[i].key = 0;
        variables[i].offset = 0;
    }

    if (!this->pass) {
        /* Create initializer */
        initializer = ast_Initializer(ast_StaticInitializerCreate(variables, this->variableCount));
        cx_setref(&this->initializers[this->initializerCount], initializer);
        ast_Parser_collect(this, initializer);
    } else {
        /* Create dummy initializer */
        initializer = ast_InitializerCreate(variables, this->variableCount);
        cx_setref(&this->initializers[this->initializerCount], initializer);
        ast_Parser_collect(this, initializer);
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::ast::Parser::initStage(string id,bool found) */
cx_void _ast_Parser_initStage(ast_Parser this, cx_string id, cx_bool found) {
/* $begin(::corto::ast::Parser::initStage) */

    this->staged[this->stagedCount].name = cx_strdup(id);
    this->staged[this->stagedCount].line = this->line;
    this->staged[this->stagedCount].column = this->column;
    this->staged[this->stagedCount].found = found;
    this->stagedCount++;

/* $end */
}

/* ::corto::ast::Parser::initValue(Expression expr) */
cx_int16 _ast_Parser_initValue(ast_Parser this, ast_Expression expr) {
/* $begin(::corto::ast::Parser::initValue) */
    ast_CHECK_ERRSET(this);

    if ((this->initializerCount >= 0) && this->initializers[this->initializerCount]) {
        if (ast_Initializer_value(this->initializers[this->initializerCount], expr)) {
            goto error;
        }
    }

    return 0;
error:
    fast_err;
    return -1;

/* $end */
}

/* ::corto::ast::Parser::isAbortSet() */
cx_bool _ast_Parser_isAbortSet(ast_Parser this) {
/* $begin(::corto::ast::Parser::isAbortSet) */
    cx_bool result = this->abort;
    this->abort = FALSE;
    return result;
/* $end */
}

/* ::corto::ast::Parser::isErrSet() */
cx_bool _ast_Parser_isErrSet(ast_Parser this) {
/* $begin(::corto::ast::Parser::isErrSet) */
    cx_bool result = this->errSet;
    this->errSet = FALSE;
    return result;
/* $end */
}

/* ::corto::ast::Parser::lookup(string id) */
ast_Expression _ast_Parser_lookup(ast_Parser this, cx_string id) {
/* $begin(::corto::ast::Parser::lookup) */
    ast_Expression result = NULL;
    ast_CHECK_ERRSET(this);

    if (this->pass) {
        /* If complexType is set, this resolve is ran within a [] expression */
        cx_type complexType = ast_Parser_getComplexType(this);
        if (complexType) {
            if (cx_interface_resolveMember(cx_interface(complexType), id)) {
                result = ast_Expression(ast_StringCreate(id));
            }
        }
        if (this->block && !result) {
            result = ast_Expression(ast_Block_resolve(this->block, id));
        }
    }
    if (!result) {
        result = ast_Parser_resolve(this, id);
    }

    /* If either doing a static initializer or parser is
     * doing the 2nd pass all variables should be resolvable */
    if (!result) {
        if (this->pass ||
            ((this->initializerCount >= 0) &&
             this->initializers[this->initializerCount] &&
            cx_instanceof(cx_type(ast_StaticInitializer_o), this->initializers[this->initializerCount]))) {
            ast_Parser_error(this, "unresolved identifier '%s'", id);
            fast_err;
        }

        if (this->lastFailedResolve) {
            cx_dealloc(this->lastFailedResolve);
        }
        this->lastFailedResolve = cx_strdup(id);
    }
    ast_Parser_initStage(this, id, result != NULL);

    return result;
/* $end */
}

/* ::corto::ast::Parser::memberExpr(ast::Expression lvalue,ast::Expression rvalue) */
ast_Expression _ast_Parser_memberExpr(ast_Parser this, ast_Expression lvalue, ast_Expression rvalue) {
/* $begin(::corto::ast::Parser::memberExpr) */
    ast_Expression result = NULL;

    this->stagingAllowed = FALSE;

    if (this->pass) {
        cx_type t = ast_Expression_getType(lvalue);
        if (t) {
            if (!(result = ast_Parser_explodeComma(this, lvalue, rvalue, ast_Parser_expandMember, NULL))) {
                goto error;
            }
        } else {
            ast_Parser_error(this, "cannot resolve member, left-hand of expression has no type");
            goto error;
        }
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::ast::Parser::observerDeclaration(string id,ast::Expression object,eventMask mask,ast::Object dispatcher) */
ast_Storage _ast_Parser_observerDeclaration(ast_Parser this, cx_string id, ast_Expression object, cx_eventMask mask, ast_Object dispatcher) {
/* $begin(::corto::ast::Parser::observerDeclaration) */
    CX_UNUSED(object);
    CX_UNUSED(mask);
    ast_CHECK_ERRSET(this);

    this->stagingAllowed = FALSE;

    ast_Storage result = NULL;
    cx_bool isTemplate = cx_class_instanceof(cx_type_o, this->scope);

    if (!(mask & CX_ON_SCOPE)) {
        mask |= CX_ON_SELF;
    }

    /* Observers come in two flavors. The first is the 'ordinary' observer. This observer is created and defined in the 2nd phase. The
     * second flavor is the template observer. This observer is attached to a class and is instantiated for each instance of that class.
     * Because this observer must be bound to the class when the class is defined (or rather: before any objects are created with that
     * class) these observers are created in the first pass and then the implementation is bound to it in the 2nd pass.
     */
    if (!this->pass) {
        /* If observer is a template observer (it is defined within the scope of a type) create it in the first pass */
        if (isTemplate) {
            result = ast_Parser_observerCreate(this, id, object, mask, dispatcher);
            if (!result) {
                ast_Parser_error(this, "failed to create template observer");
                goto error;
            }
        }
    } else {
        ast_Block block;
        cx_observer observer;
        cx_object observable = NULL;
        cx_uint32 i;

        /* Find observable */
        switch(ast_Storage(object)->kind) {
        case Ast_ObjectStorage:
            observable = ast_Object(object)->value;
            break;
        case Ast_TemplateStorage:
            /* In case of template ('this') leave observable zero */
            break;
        default:
            break;
        }

        /* Find or create observer depending on whether it is a template observer or not */
        if (isTemplate) {
            block = this->block; /* If observer is a template the block has already been pushed by Parser::observerPush */
            /* Template observers have been created in the first pass. Look up the created observer */
            observer = cx_class_findObserver(cx_class(this->scope), observable);
            result = ast_Storage(ast_ObjectCreate(observer));
            ast_Parser_collect(this, result);
        } else {
            block = ast_Parser_blockPush(this, TRUE); /* Push new block on stack */

            /* If observer is not a template it has not yet been created, so create it now */
            result = ast_Parser_observerCreate(this, id, object, mask, dispatcher);
            if (!result) {
                ast_Parser_error(this, "failed to create observer");
                goto error;
            }
            observer = ast_Object(result)->value;
        }

        /* Declare this */
        if (!ast_Block_resolve(block, "this")) {
            ast_Block_declare(block, "this", cx_object_o, TRUE, FALSE);
        }

        /* Loop parameters of observable, insert locals */
        for(i=0; i<cx_function(observer)->parameters.length; i++) {
            cx_parameter *p = &cx_function(observer)->parameters.buffer[i];
            ast_Block_declare(block, p->name, p->type, TRUE, TRUE); /* Observable parameter are references */
        }

        /* Bind observer and block */
        ast_Parser_bind(this, result, block);
        ast_Block_setFunction(block, cx_function(observer));
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::ast::Parser::observerPush() */
cx_void _ast_Parser_observerPush(ast_Parser this) {
/* $begin(::corto::ast::Parser::observerPush) */
    ast_CHECK_ERRSET(this);

    /* Observer-implementations are parsed in the 2nd pass */
    if (this->pass) {
        if (cx_class_instanceof(cx_type_o, this->scope)) {
            ast_Block block;
            block = ast_Parser_blockPush(this, TRUE);
            ast_Block_declareTemplate(block, "this", this->scope, TRUE, FALSE);
        }
    }

/* $end */
}

/* ::corto::ast::Parser::parse(sequence{string} argv) */
cx_uint32 _ast_Parser_parse(ast_Parser this, cx_stringSeq argv) {
/* $begin(::corto::ast::Parser::parse) */
    ast_CHECK_ERRSET(this);

    this->pass = 0;
    if ( fast_yparse(this, 1, 1)) {
        cx_print("%s: parsed with errors (%d errors, %d warnings)", this->filename, this->errors, this->warnings);
        goto error;
    }

    /* Reset parser-state so 2nd pass starts clean */
    ast_Parser_reset(this);
    cx_setref(&this->scope, NULL);

    this->pass = 1;
    if ( fast_yparse(this, 1, 1)) {
        cx_print("%s: parsed with errors (%d errors, %d warnings)", this->filename, this->errors, this->warnings);
        goto error;
    }

    /* Parse to corto intermediate code */
    if ( ast_Parser_toIc(this, argv)) {
        cx_print("%s: parsed with errors (%d errors, %d warnings)", this->filename, this->errors, this->warnings);
        goto error;
    }

    return 0;
error:
    fast_err;
    return -1;
/* $end */
}

/* ::corto::ast::Parser::parseExpression(string expr,ast::Block block,object scope,uint32 line,uint32 column) */
ast_Expression _ast_Parser_parseExpression(ast_Parser this, cx_string expr, ast_Block block, cx_object scope, cx_uint32 line, cx_uint32 column) {
/* $begin(::corto::ast::Parser::parseExpression) */
    ast_Expression result = NULL;
    cx_string exprFinalized;

    CX_UNUSED(scope);

    if (this->source) {
        cx_dealloc(this->source);
    }

    exprFinalized = cx_alloc(strlen(expr) + 2);
    sprintf(exprFinalized, "%s\n", expr);

    this->source = exprFinalized;

    cx_setref(&this->block, block);
    cx_setref(&this->scope, scope);

    // Give expression its own block
    ast_Parser_blockPush(this, FALSE);
    if (fast_yparse(this, line, column)) {
        cx_print("%s: expression '%s' parsed with errors", this->filename, expr);
        ast_Parser_blockPop(this);
        goto error;
    }

    /* Extract expression */
    block = this->block;
    ast_Parser_blockPop(this);
    if (block) {
        /* Block should contain exactly one expression */
        if (block->statements) {
            if (cx_llSize(block->statements) == 1) {
                ast_Node node;
                node = cx_llGet(block->statements, 0);
                if (cx_instanceof(cx_type(ast_Expression_o), node)) {
                    result = ast_Expression(node);
                } else {
                    cx_id id;
                    cx_print("%s: '%s' does not resolve to a valid expression (found %s).",
                            this->filename, expr, ast_Parser_id(cx_typeof(node), id));
                    goto error;
                }
            } else {
                cx_print("%s: expression '%s' is not allowed to contain multiple statements", this->filename, expr);
                goto error;
            }
        } else {
            cx_print("%s: expression '%s' did not result in a statement", this->filename, expr);
            goto error;
        }
    } else {
        cx_print("parser error: no block set in parser after parsing expression.");
        goto error;
    }

    return result;
error:
    return NULL;
/* $end */
}

/* ::corto::ast::Parser::parseLine(string expr,object scope,word value) */
cx_int16 _ast_Parser_parseLine(cx_string expr, cx_object scope, cx_word value) {
/* $begin(::corto::ast::Parser::parseLine) */
    ast_Parser parser = ast_ParserCreate(expr, NULL);
    ic_program program = ic_programCreate(parser->filename);
    ast_Expression result = NULL; /* Resulting ast-expression of 'exr' */
    ic_scope icScope; /* Parsed intermediate-code program */
    ic_storage returnValue = NULL; /* Intermediate representation of return value */
    cx_type returnType = NULL; /* Return type */
    ic_op ret = NULL; /* ret or stop instruction */
    cx_value *v = (cx_value*)value;

    parser->repl = TRUE;

    parser->pass = 0;
    cx_setref(&parser->scope, scope);
    if ( fast_yparse(parser, 1, 1)) {
        goto error;
    }

    if (parser->errors) {
        goto error;
    }

    /* Reset parser-state so 2nd pass starts clean */
    ast_Parser_reset(parser);

    parser->pass = 1;
    cx_setref(&parser->scope, scope);
    if (fast_yparse(parser, 1, 1)) {
        goto error;
    }

    /* Find last executed expression */
    if (parser->block) {
        if (cx_llSize(parser->block->statements)) {
            ast_Node lastNode = cx_llLast(parser->block->statements);

            /* If node is an expression, store expression in variable so it can be resolved later */
            if (cx_instanceof(cx_type(ast_Expression_o), lastNode) && (lastNode->kind != Ast_CommaExpr)) {
                ast_Local resultLocal;
                ast_Binary assignment;
                result = ast_Expression(lastNode);

                if (result->type) {
                    returnType = cx_type(ast_Expression_getType(result));
                    if ((returnType->kind != CX_VOID) || (result->deref == Ast_ByReference)) {
                        resultLocal = ast_Block_declare(parser->block, "<result>", result->type, FALSE,
                            result->isReference);
                        ast_Expression(resultLocal)->deref = result->isReference ? Ast_ByReference : Ast_ByValue;
                        if (!resultLocal) {
                            goto error;
                        }
                        resultLocal->kind = Ast_LocalReturn;
                        assignment = ast_BinaryCreate(ast_Expression(resultLocal), result, CX_ASSIGN);
                        cx_llReplace(parser->block->statements, lastNode, assignment);
                    }
                } else {
                    ast_Parser_error(parser, "invalid expression");
                    goto error;
                }
            }
        }
    }

    /* Parse root-block */
    icScope = (ic_scope)ast_Block_toIc(parser->block, program, NULL, FALSE);
    if (parser->errors) {
        goto error;
    }

    /* Finalize functions */
    if (ast_Parser_finalize(parser, program)) {
        goto error;
    }

    returnValue = ic_scope_lookupStorage(icScope, "<result>", TRUE);
    if (returnValue) {
        ret = IC_1_OP(parser->line, ic_ret, returnValue, IC_DEREF_VALUE, FALSE);
        if (result->isReference) {
            ((ic_storage)returnValue)->isReference = TRUE;
            ((ic_op)ret)->s1Deref = IC_DEREF_ADDRESS;
        }else {
            ((ic_op)ret)->s1Deref = IC_DEREF_VALUE;
        }
    } else {
        ret = IC_1_OP(parser->line, ic_stop, NULL, IC_DEREF_VALUE, FALSE);
    }

    ic_program_add(program, ic_node(ret));

#ifdef IC_TRACING
    extern cx_bool CX_DEBUG_ENABLED;
    if (CX_DEBUG_ENABLED) {
        printf("=====\n%s\n\n", ic_program_toString(program));
    }
#endif

    /* Translate program to vm code */
    ic_program_assemble(program);

    /* Run vm program */
    if (returnValue) {
        if (result->isReference) {
            cx_object o = NULL;
            ic_program_run(program, (cx_word)&o, CX_SEQUENCE_EMPTY(cx_stringSeq));
            if (o) {
                cx_valueObjectInit(v, o, NULL);
            } else {
                v->is.value.storage = 0;
                cx_valueValueInit(v, NULL, cx_object_o, &v->is.value.storage);
            }
        } else {
            if(returnType->kind == CX_PRIMITIVE) {
                cx_valueValueInit(v, NULL, returnType, &v->is.value.storage);
                ic_program_run(program, (cx_word)&v->is.value.storage, CX_SEQUENCE_EMPTY(cx_stringSeq));
            } else {
                void *ptr = cx_alloc(cx_type_sizeof(returnType));
                ic_program_run(program, (cx_word)&ptr, CX_SEQUENCE_EMPTY(cx_stringSeq));
                if (ptr) {
                    cx_valueValueInit(v, NULL, returnType, ptr);
                } else {
                    v->is.value.storage = 0;
                    cx_valueValueInit(v, NULL, cx_object_o, &v->is.value.storage);
                }
            }
        }
    } else {
        ic_program_run(program, 0, CX_SEQUENCE_EMPTY(cx_stringSeq));
        if (v) {
            cx_valueValueInit(v, NULL, cx_type(cx_void_o), NULL);
        }
    }

    /* Free program */
    cx_release(program);

    /* Free parser */
    cx_release(parser);

    return 0;
error:
    cx_release(program);
    return -1;
/* $end */
}

/* ::corto::ast::Parser::popComplexType() */
cx_void _ast_Parser_popComplexType(ast_Parser this) {
/* $begin(::corto::ast::Parser::popComplexType) */

    this->complexTypeSp--;
    if (this->complexTypeSp < 0) {
        ast_Parser_error(this, "parser error: complexType stack pointer below zero");
        abort();
    }

/* $end */
}

/* ::corto::ast::Parser::popLvalue() */
cx_void _ast_Parser_popLvalue(ast_Parser this) {
/* $begin(::corto::ast::Parser::popLvalue) */

    this->lvalueSp--;
    if (this->lvalueSp < 0) {
        ast_Parser_error(this, "parser error: lvalue stack pointer below zero");
        abort();
    }

/* $end */
}

/* ::corto::ast::Parser::popScope(object previous) */
cx_void _ast_Parser_popScope(ast_Parser this, cx_object previous) {
/* $begin(::corto::ast::Parser::popScope) */
    ast_CHECK_ERRSET(this);

    /* Restore scope */
    cx_setref(&this->scope, previous);
/* $end */
}

/* ::corto::ast::Parser::postfixExpr(ast::Expression lvalue,operatorKind operator) */
ast_Expression _ast_Parser_postfixExpr(ast_Parser this, ast_Expression lvalue, cx_operatorKind operator) {
/* $begin(::corto::ast::Parser::postfixExpr) */
    ast_Expression result = NULL;

    this->stagingAllowed = FALSE;

    if (this->pass) {
        result = ast_Expression(ast_PostFixCreate(lvalue, operator));
        if (!result) {
            goto error;
        }
        ast_Parser_collect(this, result);
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::ast::Parser::pushComplexType(ast::Expression lvalue) */
cx_void _ast_Parser_pushComplexType(ast_Parser this, ast_Expression lvalue) {
/* $begin(::corto::ast::Parser::pushComplexType) */

    if (lvalue) {
        cx_setref(&this->complexType[this->complexTypeSp], ast_Expression_getType(lvalue));
    } else {
        cx_setref(&this->complexType[this->complexTypeSp], NULL);
    }
    this->complexTypeSp++;

/* $end */
}

/* ::corto::ast::Parser::pushLvalue(ast::Expression lvalue,bool isAssignment) */
cx_void _ast_Parser_pushLvalue(ast_Parser this, ast_Expression lvalue, cx_bool isAssignment) {
/* $begin(::corto::ast::Parser::pushLvalue) */

    cx_setref(&this->lvalue[this->lvalueSp].expr, lvalue);
    this->lvalue[this->lvalueSp].isAssignment = isAssignment;
    this->lvalueSp++;

/* $end */
}

/* ::corto::ast::Parser::pushPackage(string name) */
cx_int16 _ast_Parser_pushPackage(ast_Parser this, cx_string name) {
/* $begin(::corto::ast::Parser::pushPackage) */
    char ch, *ptr, *bptr;
    cx_id buffer;

    if (this->scope && (this->scope != root_o)) {
        ast_Parser_error(this, "#package may only be used in the root scope");
        goto error;
    }

    cx_setref(&this->scope, root_o);
    if (!memcmp(name, "::", 2)) {
        name += 2;
    } else {
        ast_Parser_error(this, "packages must be specified using fully qualified names");
        goto error;
    }

    /* Check for package nesting */
    ptr = name;
    bptr = buffer;
    while ((ch = *ptr)) {
        if (ch == ':') {
            if (ptr[1] == ':') {
                *bptr = '\0';
                ptr++;
                cx_object o = cx_resolve(this->scope, buffer);
                if (!o) {
                    /* Declare package */
                    ast_Parser_declaration(this, cx_type(cx_package_o), buffer, FALSE);

                    /* Push package as scope */
                    ast_Parser_pushScope(this);

                    /* Define package */
                    ast_Parser_defineScope(this);
                } else {
                    cx_setref(&this->scope, o);
                    cx_release(o);
                }
                bptr = buffer;
            } else {
                ast_Parser_error(this, "invalid package name '%s'", name);
                goto error;
            }
        } else {
            *bptr = ch;
            bptr++;
        }
        ptr++;
    }
    *bptr = '\0';

    /* Declare package */
    ast_Parser_declaration(this, cx_type(cx_package_o), buffer, FALSE);

    /* Push package as scope */
    ast_Parser_pushScope(this);

    /* Define package */
    ast_Parser_defineScope(this);

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::ast::Parser::pushReturnAsLvalue(function function) */
cx_void _ast_Parser_pushReturnAsLvalue(ast_Parser this, cx_function function) {
/* $begin(::corto::ast::Parser::pushReturnAsLvalue) */
    ast_Expression result = NULL;

    if (this->pass) {
        if (function->returnType) {
            cx_id id;
            cx_signatureName(cx_nameof(function), id);
            result = ast_Expression(ast_Block_resolve(this->block, id));
            if (!result) {
                ast_Parser_error(this, "parser error: can't find result variable '%s'", id);
                goto error;
            }
        }
    }

    ast_Parser_pushLvalue(this, result, TRUE);

    return;
error:
    fast_err;
/* $end */
}

/* ::corto::ast::Parser::pushScope() */
cx_object _ast_Parser_pushScope(ast_Parser this) {
/* $begin(::corto::ast::Parser::pushScope) */
    cx_object oldScope = NULL;

    ast_CHECK_ERRSET(this);

    oldScope = this->scope;
    if (!this->variableCount) {
        /* This is the result of a previous error */
        goto error;
    }

    if (this->variables[0]) {
        cx_setref(&this->scope, ast_Object(this->variables[0])->value);
        ast_Parser_reset(this);
    } else {
        goto error;
    }

    return oldScope;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::ast::Parser::reset() */
cx_void _ast_Parser_reset(ast_Parser this) {
/* $begin(::corto::ast::Parser::reset) */
    cx_uint32 i;

    this->variableCount = 0;
    this->variablesInitialized = FALSE;
    this->isLocal = FALSE;
    this->lvalueSp = 0;
    this->complexTypeSp = 0;
    this->initializerCount = -1;
    this->stagingAllowed = TRUE;

    if (this->pass) {
        for(i=0; i<this->stagedCount; i++) {
            if (!this->staged[i].found) {
                ast_Parser_error(this, "unresolved identifier '%s'", this->staged[i].name);
                fast_err;
            }
            cx_dealloc(this->staged[i].name);
            this->staged[i].name = NULL;
        }
    }
    this->stagedCount = 0;

/* $end */
}

/* ::corto::ast::Parser::ternaryExpr(ast::Expression cond,ast::Expression iftrue,ast::Expression iffalse) */
ast_Expression _ast_Parser_ternaryExpr(ast_Parser this, ast_Expression cond, ast_Expression iftrue, ast_Expression iffalse) {
/* $begin(::corto::ast::Parser::ternaryExpr) */
    ast_Expression result = NULL;

    if (this->pass) {
        ast_Expression lvalue = ast_Parser_getLvalue(this, TRUE);

        if (!lvalue) {
            lvalue = ast_Expression(ast_TemporaryCreate(iftrue->type, FALSE));
        }
        result = ast_Expression(ast_TernaryCreate(cond, iftrue, iffalse, lvalue));
        if (!result) {
            goto error;
        }
        ast_Parser_collect(this, result);
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::ast::Parser::unaryExpr(ast::Expression lvalue,operatorKind operator) */
ast_Expression _ast_Parser_unaryExpr(ast_Parser this, ast_Expression lvalue, cx_operatorKind operator) {
/* $begin(::corto::ast::Parser::unaryExpr) */
    ast_Expression result = NULL;

    this->stagingAllowed = FALSE;

    if (lvalue) {
        if (operator == CX_SUB) {
            cx_type lvalueType = ast_Expression_getType(lvalue);

            if (lvalueType->kind == CX_PRIMITIVE) {
                switch(cx_primitive(lvalueType)->kind) {
                case CX_INTEGER:
                    if (ast_Node(lvalue)->kind == Ast_LiteralExpr) {
                        result = ast_Expression(Ast_IntegerCreate(Ast_Integer(lvalue)->value * -1));
                        ast_Parser_collect(this, result);
                        break;
                    }
                    /* no break */
                case CX_UINTEGER:
                    if (ast_Node(lvalue)->kind == Ast_LiteralExpr) {
                        result = ast_Expression(Ast_SignedIntegerCreate(Ast_Integer(lvalue)->value * -1));
                        ast_Parser_collect(this, result);
                        break;
                    }
                    /* no break */
                case CX_FLOAT:
                    if (ast_Node(lvalue)->kind == Ast_LiteralExpr) {
                        result = ast_Expression(Ast_FloatingPointCreate(Ast_FloatingPoint(lvalue)->value * -1));
                        ast_Parser_collect(this, result);
                    } else {
                        if (this->pass) {
                            Ast_SignedInteger minusOne = Ast_SignedIntegerCreate(-1);
                            ast_Parser_collect(this, minusOne);
                            result = ast_Expression(ast_BinaryCreate(lvalue, ast_Expression(minusOne), CX_MUL));
                            ast_Parser_collect(this, result);
                        }
                    }
                    break;
                default: {
                    cx_id id;
                    ast_Parser_error(this, "unary operator - not applicable to type '%s'", ast_Parser_id(lvalueType, id));
                    goto error;
                }
                }
            } else {
                cx_id id;
                ast_Parser_error(this, "unary operator - not applicable to non-primitive type '%s'", ast_Parser_id(lvalueType, id));
                goto error;
            }
        } else if (operator == CX_AND) {
            if (ast_Node(lvalue)->kind == Ast_StorageExpr) {
                if (lvalue->isReference) {
                    if (cx_copy((cx_object*)&result, lvalue)) {
                        ast_Parser_error(this, "parser error: failed to take reference (copy failed)");
                    }
                    result->deref = Ast_ByReference;
                    ast_Node(result)->line = this->line;
                    ast_Node(result)->column = this->column;

                    /* Ensure that copies of temporaries point to the same storage */
                    if (ast_Storage(result)->kind == Ast_TemporaryStorage) {
                        ast_Temporary_setProxy(result, lvalue);
                    }
                } else {
                    ast_Parser_error(this, "cannot take reference from non-reference variable");
                    goto error;
                }
            } else {
                lvalue->deref = Ast_ByReference;
                result = lvalue;
            }
        } else {
            if (this->pass) {
                result = ast_Expression(ast_UnaryCreate(lvalue, operator));
                if (!result) {
                    goto error;
                }
                ast_Parser_collect(this, result);
            }
        }
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::ast::Parser::updateStatement(ast::Expression expr,ast::Block block) */
ast_Node _ast_Parser_updateStatement(ast_Parser this, ast_Expression expr, ast_Block block) {
/* $begin(::corto::ast::Parser::updateStatement) */
    ast_Node result = NULL;

    this->stagingAllowed = FALSE;

    if (this->pass) {
        ast_Block functionBlock;
        ast_Expression from = NULL;
        cx_function function;
        cx_procedureKind procedureKind;
        cx_ll exprList;

        if (!expr) { /* Can only happen due to a previous error */
            goto error;
        }

        /* If update is being done from a method or template observer do the update
         * from the corresponding object (set 'from' to this). Search for a function-block */
        functionBlock = this->block;
        while(functionBlock && !(function = functionBlock->function)) {
            functionBlock = functionBlock->parent;
        }

        if (functionBlock) {
            procedureKind = cx_procedure(cx_typeof(function))->kind;
            if (functionBlock) {
                if ((procedureKind == CX_METHOD) || ((procedureKind == CX_OBSERVER) && cx_observer(function)->template)) {
                    from = ast_Parser_lookup(this, "this");
                }
            }
        }

        /* Keep argument expressions */
        exprList = ast_Expression_toList(expr);
        result = ast_Node(ast_UpdateCreate(exprList, block, from, Ast_UpdateDefault));
        ast_Parser_collect(this, result);
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::ast::Parser::waitExpr(ast::Expression expr,ast::Expression timeout) */
ast_Expression _ast_Parser_waitExpr(ast_Parser this, ast_Expression expr, ast_Expression timeout) {
/* $begin(::corto::ast::Parser::waitExpr) */
    ast_Expression result = NULL;

    this->stagingAllowed = FALSE;

    if (this->pass) {
        cx_ll exprList = ast_Expression_toList(expr);

        result = ast_Expression(ast_WaitCreate(exprList, timeout));
        ast_Parser_collect(this, result);
    }

    return result;
/* $end */
}

/* ::corto::ast::Parser::whileStatement(ast::Expression condition,ast::Block trueBranch,bool isUntil) */
ast_Node _ast_Parser_whileStatement(ast_Parser this, ast_Expression condition, ast_Block trueBranch, cx_bool isUntil) {
/* $begin(::corto::ast::Parser::whileStatement) */
    ast_Node result = NULL;

    this->stagingAllowed = FALSE;

    if (this->pass) {
        if (isUntil && this->block->isRoot) {
            ast_Parser_error(yparser(), "invalid do-while in root block");
            goto error;
        }
        result = ast_Node(ast_WhileCreate(condition, trueBranch, isUntil));
        if (!result) {
            goto error;
        }
        ast_Parser_collect(this, result);

        if (isUntil) {
            cx_setref(&this->block->_while, result);
        }
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}
