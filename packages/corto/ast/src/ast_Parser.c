/* ast_Parser.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "ast.h"

/* $header() */
#include "ast__private.h"

#define ast_CHECK_ERRSET(parser) corto_assert(!parser->errSet, "%s:%d:%d: parser did not check error-status set on line %d", this->filename, this->line, this->column, this->errLine)
/*#define ast_PARSER_DEBUG*/
#define fast_err this->errSet = TRUE; this->errLine = __LINE__;

extern corto_threadKey ast_PARSER_KEY;

void ast_Parser_error(ast_Parser this, char* fmt, ... ) {
    va_list args;
    char msgbuff[1024];
    corto_id token;
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
    corto_id token;
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
corto_string ast_Parser_id(corto_object o, corto_id buffer) {
    if (!o) {
        sprintf(buffer, "null");
    } else if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
        if (corto_parentof(o) == corto_lang_o) {
            strcpy(buffer, corto_nameof(o));
        } else {
            corto_fullname(o, buffer);
        }
    } else {
        corto_id tmp;
        corto_string_ser_t serData;
        struct corto_serializer_s s;
        serData.buffer = tmp;
        serData.length = sizeof(corto_id);
        serData.maxlength = sizeof(corto_id)-strlen("<anonymous>");
        serData.compactNotation=TRUE;
        serData.prefixType = TRUE;
        serData.enableColors = FALSE;
        s = corto_string_ser(CORTO_LOCAL, CORTO_NOT, CORTO_SERIALIZER_TRACE_NEVER);
        corto_serialize(&s, o, &serData);
        strcpy(buffer, tmp);
    }
    return buffer;
}

/* Translate result of parser to corto intermediate bytecode */
corto_int16 ast_Parser_toIc(ast_Parser this, corto_stringSeq argv) {
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
    extern corto_bool CORTO_DEBUG_ENABLED;
    if (CORTO_DEBUG_ENABLED) {
        corto_string programStr = ic_program_toString(program);
        corto_print("%s", programStr);
        corto_dealloc(programStr);
    }
#endif

    ic_program_assemble(program);
    ic_program_run(program, 0, argv);

    /* Free program */
    corto_release(program);

    return 0;
error:
    corto_release(program);
    return -1;
}

/* Use corto_object as returntype as the actual type (ast_Expression) causes macro-expansion */
typedef corto_object (*ast_ExpandAction)(ast_Parser this, ast_Expression lvalue, ast_Expression rvalue, void *userData);

/* Combine results in new comma expression */
corto_object ast_Parser_combineComma(ast_Parser this, ast_Expression lvalue, ast_Expression rvalue, void *userData) {
    CORTO_UNUSED(this);
    CORTO_UNUSED(userData);
    return ast_Comma_addOrCreate(lvalue, rvalue);
}

/* Combine results as part of conditional expression */
corto_object ast_Parser_combineConditionalExpr(ast_Parser this, ast_Expression lvalue, ast_Expression rvalue, void *userData) {
    corto_operatorKind oper = *(corto_operatorKind*)userData;
    corto_operatorKind combineOper;
    ast_Expression result;

    /* Default combine is AND, except the != operator, which inserts an OR */
    if (lvalue) {
        if (oper == CORTO_COND_NEQ) {
            combineOper = CORTO_COND_OR;
        } else {
            combineOper = CORTO_COND_AND;
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
ast_Expression ast_Parser_createBinaryTernary(ast_Parser this, ast_Expression lvalue, ast_Expression rvalue, corto_operatorKind operator) {
    ast_Expression result = NULL;
    CORTO_UNUSED(this);

    /* If the operation is an assignment, the ternary operator has already constructed the binary operation through an lvalue - see
     * the implementation of ast_Parser_Ternary. If the operation is not an assignment, create the binary expression. */
    switch(operator) {
    case CORTO_ASSIGN:
    case CORTO_ASSIGN_ADD:
    case CORTO_ASSIGN_SUB:
    case CORTO_ASSIGN_MUL:
    case CORTO_ASSIGN_DIV:
    case CORTO_ASSIGN_MOD:
    case CORTO_ASSIGN_OR:
    case CORTO_ASSIGN_AND:
        ast_Ternary_setOperator(ast_Ternary(rvalue), operator);
        corto_setref(&result, rvalue);
        break;
    default:
        result = ast_Expression(ast_BinaryCreate(lvalue, rvalue, operator));
        ast_Parser_collect(this, result);
        break;
    }

    return result;
}

/* Match parameter */
corto_bool ast_Parser_matchDelegateParameter(
    ast_Parser this,
    corto_string name,
    corto_type t1,
    corto_bool isRef1,
    corto_type t2,
    corto_bool isRef2) {

    if ((t1 != t2) || (isRef1 && !isRef2)) {
        corto_id id1, id3, id4;

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
    corto_uint32 i;
    ast_Expression instance = NULL;
    ast_Expression functionExpr = NULL;
    corto_id functionName;
    ast_InitializerExpression result = NULL;
    corto_string signature = NULL;
    corto_delegate type = NULL;
    ast_InitializerVariableArray64 variables;
    ast_CallBuilder builder;
    ast_Call tempCall = NULL;

    memset(variables, 0, sizeof(variables));

    /* Validate whether rvalue is an object */
    if ((ast_Node(rvalue)->kind == Ast_StorageExpr) && (ast_Storage(rvalue)->kind == Ast_ObjectStorage)) {
        corto_signatureName(corto_nameof(ast_Object(rvalue)->value), functionName);
    } else if ((ast_Node(rvalue)->kind == Ast_StorageExpr) && (ast_Storage(rvalue)->kind == Ast_MemberStorage)) {
        instance = ast_Member(rvalue)->lvalue;
        strcpy(functionName, ast_String(ast_Member(rvalue)->rvalue)->value);
    } else {
        ast_Parser_error(this, "dynamic delegate assignments are not yet supported");
        goto error;
    }

    type = corto_delegate(ast_Expression_getType(lvalue));

    /* Build request-signature */
    signature = corto_signatureOpen(functionName);
    for (i = 0; i < type->parameters.length; i++) {
        corto_parameter *p = &type->parameters.buffer[i];
        signature = corto_signatureAdd(signature, p->type, p->passByReference ? CORTO_PARAMETER_FORCEREFERENCE : 0);
    }
    signature = corto_signatureClose(signature);

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
        corto_parameter *p1, *p2;
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
    corto_setref(&variables[0].object, lvalue);
    result = ast_InitializerExpressionCreate(variables, 1, TRUE);
    ast_InitializerExpression_push(result);
    if (instance) {
        ast_InitializerExpression_member(result, "instance");
        ast_InitializerExpression_value(result, instance);
    }
    ast_InitializerExpression_member(result, "procedure");
    ast_InitializerExpression_value(result, functionExpr);
    ast_InitializerExpression_pop(result);
    ast_InitializerExpression_define(result);
    ast_Parser_collect(this, result);

    corto_dealloc(signature);
    corto_release(tempCall);

    return ast_Expression(result);
error:
    if(signature) {
        corto_dealloc(signature);
    }
    return NULL;
}

/* Callback function for expansion of binary expressions */
corto_object ast_Parser_expandBinary(ast_Parser this, ast_Expression lvalue, ast_Expression rvalue, void *userData) {
    ast_Expression result = NULL;
    corto_type tleft, tright;
    corto_operatorKind operator = *(corto_operatorKind*)userData;

    if (!(tleft = ast_Expression_getType_expr(lvalue, rvalue))) {
        goto error;
    }

    if (!(tright = ast_Expression_getType_expr(rvalue, lvalue))) {
        goto error;
    }

    if (tleft && (tleft->kind == CORTO_COMPOSITE) && (corto_interface(tleft)->kind == CORTO_DELEGATE)) {
        if (*(corto_operatorKind*)userData == CORTO_ASSIGN) {
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
    } else if (tleft && tleft->kind == CORTO_ITERATOR) {
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
corto_object ast_Parser_expandMember(ast_Parser this, ast_Expression lvalue, ast_Expression rvalue, void *userData) {
    CORTO_UNUSED(userData);
    CORTO_UNUSED(this);
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
corto_object ast_Parser_expandElement(ast_Parser this, ast_Expression lvalue, ast_Expression rvalue, void *userData) {
    CORTO_UNUSED(this);
    CORTO_UNUSED(userData);
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
    corto_ll lvalueList, rvalueList;
    ast_Expression result = NULL;
    ast_Expression var = NULL;
    corto_uint32 lvalueCount, rvalueCount;

    lvalueList = ast_Expression_toList(lvalues);
    rvalueList = ast_Expression_toList(rvalues);
    lvalueCount = corto_llSize(lvalueList);
    rvalueCount = corto_llSize(rvalueList);

    if ((rvalueCount > 1) && (lvalueCount == 1)) {
        /* Only temporarily store rvalue if it has side effects */
        if (ast_Expression_hasSideEffects(ast_Expression(corto_llGet(lvalueList,0)))) {
            if (ast_Node(rvalues)->kind != Ast_InitializerExpr) {
                var = ast_Expression(ast_TemporaryCreate(lvalues->type, lvalues->isReference));
                ast_Parser_addStatement(this, ast_Parser_binaryExpr(this, var, lvalues, CORTO_ASSIGN));
                rvalues = var;
            }
        }
    }

    ast_ExpressionListForeach(lvalueList, l) {
        ast_ExpressionListForeach(rvalueList, r) {
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
    corto_int16 lvalueCount, rvalueCount;
    corto_ll lvalueList, rvalueList;
    corto_iter lIter, rIter;
    corto_type tleft, tright;
    ast_Expression result = NULL, localResult = NULL;
    enum {
        EXPAND_LEFT,
        EXPAND_RIGHT,
        EXPAND_BOTH
    } expandMode = EXPAND_LEFT; /* Expand left, right or both */

    lvalueList = ast_Expression_toList(lvalues);
    rvalueList = ast_Expression_toList(rvalues);
    lvalueCount = corto_llSize(lvalueList);
    rvalueCount = corto_llSize(rvalueList);

    /* If there is more than one lvalue assign rvalue to temporary value first. This will assure that rvalue is evaluated
     * only once. */
    if ((lvalueCount > 1) && (rvalueCount == 1)) {
        /* Only temporarily store rvalue if it has side effects */
        if (ast_Expression_hasSideEffects(ast_Expression(corto_llGet(rvalueList,0)))) {
            if (ast_Node(rvalues)->kind != Ast_InitializerExpr) {
                ast_Expression var = ast_Expression(ast_TemporaryCreate(rvalues->type, FALSE));
                ast_Parser_addStatement(this, ast_Parser_binaryExpr(this, var, rvalues, CORTO_ASSIGN));
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
                          corto_llSize(lvalueList), corto_llSize(rvalueList));
        goto error;
    }

    /* Loop through lvalues */
    lIter = corto_llIter(lvalueList);
    rIter = corto_llIter(rvalueList);
    ast_Expression lvalue = lvalues;
    while((((expandMode == EXPAND_LEFT)||(expandMode == EXPAND_BOTH)) && corto_iterHasNext(&lIter)) || ((expandMode == EXPAND_RIGHT) && corto_iterHasNext(&rIter))) {

        /* If rvalueList is greater than 1, loop through rvalues as well */
        switch(expandMode) {
            case EXPAND_BOTH:
                rvalues = corto_iterNext(&rIter);
            case EXPAND_LEFT:
                lvalue = corto_iterNext(&lIter);
                break;
            case EXPAND_RIGHT:
                rvalues = corto_iterNext(&rIter);
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

ast_Expression ast_Parser_resolve(ast_Parser this, corto_id id) {
    ast_Expression result = NULL;
    corto_object object;
    corto_char *ptr, ch;
    corto_id buffer;
    corto_char *bptr;

    if (strchr(id, ':')) {
        ptr = id;
        bptr = buffer;
        do {
            object = corto_resolve(this->scope, id);
            if (object){
                result = ast_Expression(ast_ObjectCreate(object));
                ast_Parser_collect(this, result);
                corto_release(object);
                break;
            } else {
                if (*ptr) {
                    while((ch=*ptr) && (ch != ':')) {
                        *bptr = ch;
                        bptr++;
                        ptr++;
                    }
                    *bptr = '\0';
                    corto_load(buffer, 0, NULL);
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
        object = corto_resolve(this->scope, id);
        if (!object){
            corto_object rvalueType = ast_Parser_getLvalueType(this, FALSE);
            if (rvalueType && corto_checkAttr(rvalueType, CORTO_ATTR_SCOPED)) {
                object = corto_resolve(rvalueType, id);
            }
        }
        if (object) {
            result = ast_Expression(ast_ObjectCreate(object));
            ast_Parser_collect(this, result);
            corto_release(object);
        }
    }

    return result;
error:
    ast_Parser_error(this, "unresolved identifier '%s'", id);
    fast_err;
    return NULL;
}

/* Create an observer */
ast_Storage ast_Parser_observerCreate(ast_Parser this, corto_string id, ast_Expression object, corto_eventMask mask, ast_Object dispatcherVar) {
    ast_Storage result = NULL;
    corto_observer observer;
    corto_object observable = NULL;
    corto_object parent;
    corto_object dispatcher = NULL;

    /* If object is zero, this indicates either a template local or an expression during the 1st pass. TODO: how to handle
     * declaring expressions in the 1st pass - possible solution is setting the expression in the 2nd pass but then how can
     * the observer be identified?
     */

    parent = this->scope;
    if (!corto_class_instanceof(corto_type_o, parent)) {
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
    if (!(mask & CORTO_ON_VALUE)) {
        mask |= CORTO_ON_METAVALUE;
    }

    /* Create observer */
    if (!id) {
        observer = corto_observerDeclare();
        if (!observer) {
            goto error;
        }

        /* Set values of observer - but don't yet define it. It will be defined when
         * the observer is bound to the implementation */
        corto_setref(&observer->observable, observable);
        observer->mask = mask;
        corto_setref(&observer->dispatcher, dispatcher);

        corto_attach(this->scope, observer);

        /* If observer is a template observer, manually attach */
        if (parent) {
            corto_class_bindObserver(corto_class(parent), observer);
        }
    } else {
        observer = corto_observerDeclareChild(this->scope, id);
        if (!observer) {
            goto error;
        }
        corto_setref(&observer->dispatcher, dispatcher);

        if (corto_observerDefine(observer, mask, observable, NULL)) {
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
ast_Storage ast_Parser_declareDelegate(ast_Parser this, corto_type returnType, corto_string id, corto_bool returnsReference) {
    corto_delegate delegate;
    corto_parameterseq parameters;
    corto_id name;

    /* Translate from name to arguments */
    parameters = corto_function_stringToParameterSeq(id, this->scope);

    /* Obtain name */
    corto_signatureName(id, name);

    /* Declare and define delegate */
    delegate = corto_delegateDeclareChild(this->scope, name);
    if(!delegate) {
        goto error;
    }

    if(corto_delegateDefine(delegate, corto_type(returnType), returnsReference, parameters)) {
        goto error;
    }

    return ast_Storage(ast_ObjectCreate(delegate));
error:
    return NULL;
}

/* $end */

/* ::corto::ast::Parser::addStatement(ast::Node statement) */
corto_void _ast_Parser_addStatement(ast_Parser this, ast_Node statement) {
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
                if (corto_instanceof(corto_type(ast_Expression_o), statement)) {
                    if (!ast_Expression_hasSideEffects(ast_Expression(statement))) {
                        /* TODO: ast_Parser_warning(this, "computed value is not used (%s)", corto_nameof(corto_typeof(statement))); */
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
corto_string _ast_Parser_argumentToString(ast_Parser this, corto_type type, corto_string id, corto_bool reference) {
/* $begin(::corto::ast::Parser::argumentToString) */
    corto_string str;
    corto_string result;
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

    if (!corto_class_instanceof(corto_type_o, type)) {
        corto_id id;
        ast_Parser_error(this, "object '%s' used in parameter expression is not a type", ast_Parser_id(type, id));
        goto error;
    }

    if (corto_checkAttr(type, CORTO_ATTR_SCOPED)) {
        corto_id id;
        if ((corto_parentof(type) == corto_o) || (corto_parentof(type) == corto_lang_o)) {
            str = strdup(corto_nameof(type));
        } else {
            str = strdup(ast_Parser_id(type, id));
        }
    } else {
        struct corto_serializer_s s;
        corto_string_ser_t walkData;

        memset(&walkData, 0, sizeof(walkData));
        s = corto_string_ser(CORTO_LOCAL, CORTO_NOT, CORTO_SERIALIZER_TRACE_NEVER);

        walkData.compactNotation = TRUE;
        walkData.prefixType = TRUE;

        if (corto_serialize(&s, type, &walkData)) {
            goto error;
        }
        str = walkData.buffer;
    }

    result = corto_alloc(strlen(str) + 1 + strlen(id) + 1 + 1);

    if (reference) {
        sprintf(result, "%s& %s", str, id);
    } else {
        sprintf(result, "%s %s", str, id);
    }

    corto_dealloc(str);

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::ast::Parser::binaryExpr(ast::Expression lvalues,ast::Expression rvalues,operatorKind operator) */
ast_Node _ast_Parser_binaryExpr(ast_Parser this, ast_Expression lvalues, ast_Expression rvalues, corto_operatorKind _operator) {
/* $begin(::corto::ast::Parser::binaryExpr) */
    ast_Node result = NULL;
    ast_CHECK_ERRSET(this);

    this->stagingAllowed = FALSE;

    if (lvalues && rvalues && (this->pass || ((this->initializerCount >= 0) && this->initializers[this->initializerCount]))) {
        ast_ExpandAction combine = ast_Parser_combineComma;

        switch(_operator) {
        case CORTO_ASSIGN_UPDATE: {
            corto_ll exprList = ast_Expression_toList(lvalues);

            /* Begin update (lock objects) */
            result = ast_Node(ast_UpdateCreate(exprList, NULL, NULL, Ast_UpdateBegin));
            if (!result) {
                goto error;
            }
            ast_Parser_addStatement(this, ast_Node(result));
            ast_Parser_collect(this, result);

            /* Insert assignment */
            if (!(result = ast_Parser_binaryExpr(this, lvalues, rvalues, CORTO_ASSIGN))) {
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
        case CORTO_COND_EQ:
        case CORTO_COND_NEQ:
        case CORTO_COND_AND:
        case CORTO_COND_OR:
        case CORTO_COND_GT:
        case CORTO_COND_LT:
        case CORTO_COND_GTEQ:
        case CORTO_COND_LTEQ:
            combine = ast_Parser_combineConditionalExpr;
        /* fallthrough */
        default:
            if (!(result = ast_Node(
                ast_Parser_expandComma(this, lvalues, rvalues, ast_Parser_expandBinary, combine, &_operator)))) {
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
corto_int16 _ast_Parser_bind(ast_Parser this, ast_Storage function, ast_Block block) {
/* $begin(::corto::ast::Parser::bind) */
    ast_Binding *binding;
    ast_CHECK_ERRSET(this);

    if (this->pass && function) {
        if (function->kind == Ast_ObjectStorage) {
            binding = corto_calloc(sizeof(ast_Binding));
            corto_setref(&binding->function, ast_Object(function)->value);
            corto_setref(&binding->impl, block);
            corto_assert(this->bindings != NULL, "initialization failed");
            corto_llAppend(this->bindings, binding);
        }
    }

    return 0;
/* $end */
}

/* ::corto::ast::Parser::bindOneliner(ast::Storage function,ast::Block block,ast::Expression expr) */
corto_int16 _ast_Parser_bindOneliner(ast_Parser this, ast_Storage function, ast_Block block, ast_Expression expr) {
/* $begin(::corto::ast::Parser::bindOneliner) */
    ast_CHECK_ERRSET(this);

    if (this->pass) {
        ast_Expression returnLocal;
        corto_id functionName;

        /* Add oneliner to block */
        corto_signatureName(corto_nameof(ast_Object(function)->value), functionName);
        returnLocal = ast_Block_lookup(block, functionName);
         if (returnLocal) {
            ast_Expression returnAssign;

            /* In one-liners, a reference returnvalue is always addressed by reference */
            if (!ast_Expression(returnLocal)->type->reference && ast_Expression(returnLocal)->isReference) {
                returnLocal = ast_Parser_unaryExpr(this, returnLocal, CORTO_AND);
            }

            returnAssign = ast_Expression(ast_Parser_binaryExpr(this, returnLocal, expr, CORTO_ASSIGN));
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
corto_void _ast_Parser_blockPop(ast_Parser this) {
/* $begin(::corto::ast::Parser::blockPop) */
    ast_CHECK_ERRSET(this);

    this->blockCount--;

    /* Blocks are parsed only in 2nd pass */
    if (this->pass) {
        if (this->block) {
            corto_setref(&this->block, this->block->parent);
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
ast_Block _ast_Parser_blockPush(ast_Parser this, corto_bool presetBlock) {
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
            corto_setref(&this->block, newBlock);
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
        corto_object o = NULL;
        ast_ExpressionList functions = function ? ast_Expression_toList(function) : NULL;
        ast_ExpressionList args = arguments ? ast_Expression_toList(arguments) : NULL;

        if (functions) {ast_ExpressionListForeach(functions, f) {
            ast_Expression expr;
            if ((ast_Node(f)->kind == Ast_StorageExpr) && (ast_Storage(f)->kind == Ast_ObjectStorage)) {
                o = ast_Object(f)->value;
            }
            /* If function is a type, insert cast */
            if (o && corto_instanceof(corto_type(corto_type_o), o)) {
                corto_ll exprs = ast_Expression_toList(arguments);
                if (corto_llSize(exprs) != 1) {
                    ast_Parser_error(this, "invalid number of parameters for cast (expected 1)");
                    ast_Expression_cleanList(exprs);
                    goto error;
                }
                expr = ast_Parser_castExpr(this, o, corto_llGet(exprs, 0));
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
        if (args) {ast_ExpressionListForeach(args, a) {
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
ast_Expression _ast_Parser_castExpr(ast_Parser this, corto_type lvalue, ast_Expression rvalue) {
/* $begin(::corto::ast::Parser::castExpr) */
    ast_Expression result = NULL;

    this->stagingAllowed = FALSE;

    if (this->pass) {
        corto_type rvalueType;
        corto_bool castRequired = TRUE;

        rvalueType = ast_Expression_getType(rvalue);

        if (lvalue == rvalueType) {
            corto_id id;
            ast_Parser_warning(this, "casting to value of the same type (%s)", ast_Parser_id(lvalue, id));
            castRequired = FALSE;
        } else {
            if ((lvalue->kind == CORTO_COMPOSITE) && (rvalueType->kind == CORTO_COMPOSITE)) {
                if (corto_type_castable(lvalue, rvalueType)) {
                    corto_id id1, id2;
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
corto_void _ast_Parser_collect(ast_Parser this, corto_object o) {
/* $begin(::corto::ast::Parser::collect) */
    /* 1st pass & 2nd pass are equal */

    corto_assert(this->collected != NULL, "initialization failed");
    corto_llInsert(this->collected, o);

/* $end */
}

/* ::corto::ast::Parser::collectHeap(word addr) */
corto_void _ast_Parser_collectHeap(ast_Parser this, corto_word addr) {
/* $begin(::corto::ast::Parser::collectHeap) */
    ast_CHECK_ERRSET(this);

    /* 1st pass & 2nd pass are equal */
    corto_assert(this->heapCollected != NULL, "initialization failed");
    corto_llInsert(this->heapCollected, (void*)addr);

/* $end */
}

/* ::corto::ast::Parser::construct() */
corto_int16 _ast_Parser_construct(ast_Parser this) {
/* $begin(::corto::ast::Parser::construct) */
    CORTO_UNUSED(this);
    ast_Parser_reset(this);
    corto_threadTlsSet(ast_PARSER_KEY, this);
    return 0;
/* $end */
}

/* ::corto::ast::Parser::declaration(type type,string id,bool isReference) */
ast_Storage _ast_Parser_declaration(ast_Parser this, corto_type type, corto_string id, corto_bool isReference) {
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
                    corto_assert(type != NULL, "no type provided for declaration");
                }
            }
            corto_assert(this->block != NULL, "no valid code-block set in parser context.");

            /* If the variable is declared in the global scope, verify that its name doesn't clash with an object */
            if (!this->block->parent) {
                corto_object o;
                if ((o = corto_resolve(this->scope, id))) {
                    ast_Parser_error(this, "object '%s' is redeclared as a variable", id);
                    corto_release(o);
                    goto error;
                }
            }

            /* Redundant reference specifier if the type is also a reference */
            if (type->reference && isReference) {
                corto_id id;
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
        corto_object o;
        if (!type) {
            if (this->lastFailedResolve) {
                ast_Parser_error(this, "unresolved type '%s'", this->lastFailedResolve);
                goto error;
            } else {
                corto_assert(type != NULL, "no type provided for declaration");
            }
        }
        corto_assert(this->block != NULL, "no valid code-block set in parser context.");

        if (!this->pass) {
            o = corto_declareChild(this->scope, id, type);
            if (!o) {
                corto_id id1;
                ast_Parser_error(this, "declare of '%s' of type '%s' failed",
                        id,
                        ast_Parser_id(type, id1));
                goto error;
            }
        } else {
            o = corto_lookup(this->scope, id);
            corto_assert(o != NULL, "object disappeared in 2nd pass");
            corto_release(o);
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
ast_Storage _ast_Parser_declareFunction(ast_Parser this, corto_type returnType, corto_string id, corto_type kind, corto_bool returnsReference) {
/* $begin(::corto::ast::Parser::declareFunction) */
    corto_function function;
    corto_object o;
    ast_Storage result = NULL;
    corto_int32 distance;
    ast_CHECK_ERRSET(this);

    if (!this->pass) {
        corto_id functionName;

        if (!returnType) {
            if (this->lastFailedResolve) {
                ast_Parser_error(this, "unresolved type '%s'", this->lastFailedResolve);
                goto error;
            } else {
                corto_assert(returnType != NULL, "no type provided for declaration");
            }
        }

        /* Obtain name of function */
        corto_signatureName(id, functionName);

        /* Resolve identifier first to verify whether it is not already in use as non-function object */
        if ((o = corto_lookup(this->scope, functionName))) {
            if (!corto_instanceof(corto_type(corto_function_o), o)) {
                corto_id id2;
                // todo changed here
                ast_Parser_error(this, "cannot redeclare '%s' of type '%s' as function",
                    id, ast_Parser_id(corto_typeof(o), id2));
                goto error;
            }
            corto_release(o);
        }

        /* This could be an implementation after a forward declaration so try to resolve
         * function first. */
        if (!((function = corto_lookupFunction(this->scope, id, &distance)) && !distance)) {
            if (!kind) {
                kind = corto_typeof(this->scope)->defaultProcedureType;
                if (!kind) {
                    kind = corto_type(corto_function_o);
                }
            } else {
                /* Check whether declaration is a delegate */
                if(corto_interface_baseof(corto_interface(kind), corto_interface(corto_delegate_o))) {
                    result = ast_Parser_declareDelegate(
                        this,
                        returnType,
                        id,
                        returnsReference);
                }
            }

            if (!result) {
                if (!corto_class_instanceof(corto_type_o, returnType)) {
                    corto_id id;
                    ast_Parser_error(this, "object '%s' specified as returntype is not a type.", ast_Parser_id(returnType, id));
                    goto error;
                }

                function = corto_declareChild(this->scope, id, kind);
                if (!function) {
                    ast_Parser_error(this, "declare of '%s' failed",
                                      functionName);
                    goto error;
                }

                corto_setref(&function->returnType, returnType);
                function->returnsReference = returnsReference;
            }
        } else {
            if (strcmp(id, corto_nameof(function))) {
                ast_Parser_error(this, "overloaded function '%s' conflicts with '%s'",
                    id, corto_nameof(function));
                goto error;
            }
            corto_release(function);
        }

        if (!result) {
            result = ast_Storage(ast_ObjectCreate(function));
            ast_Parser_collect(this, result);
        }
    } else {
        if(!kind || (corto_interface(kind)->kind == CORTO_PROCEDURE)) {
            corto_id query;
            corto_char *ptr, *bptr, ch;

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

            corto_object function = corto_resolve(this->scope, query);
            corto_assert(function != NULL, "object should still be there in 2nd pass (%s)", corto_lasterr());

            result = ast_Storage(ast_ObjectCreate(function));
            ast_Parser_collect(this, result);
            corto_release(function);
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
    corto_function function_o;
    corto_parameter *param;
    ast_Block result = NULL;
    unsigned int i;
    ast_CHECK_ERRSET(this);

    if (this->pass && function) {
        result = ast_Parser_blockPush(this, TRUE);

        function_o = ast_Object(function)->value;
        ast_Block_setFunction(result, function_o);

        /* If function is a method, include 'this' pointer */
        if (corto_procedure(corto_typeof(function_o))->kind == CORTO_METHOD) {
            corto_object parent;

            if (!corto_instanceof(corto_type(corto_interface_o), corto_parentof(function_o))) {
                parent = corto_typeof(corto_parentof(function_o));
            } else {
                parent = corto_parentof(function_o);
            }

            if (!corto_instanceof(corto_type(corto_interface_o), parent)) {
                corto_id id;
                ast_Parser_error(this, "parent of '%s' is not an interface nor of an interface type",
                    ast_Parser_id(function_o, id));
                goto error;
            }

            ast_Block_declare(result, "this", parent, TRUE, FALSE);

            /* If this-type of method has a base, include super */
            if (corto_interface(parent)->base) {
                ast_Block_declare(result, "super", corto_type(corto_interface(parent)->base), TRUE, FALSE);
            }
        }

        for(i=0; i<function_o->parameters.length; i++) {
            param = &function_o->parameters.buffer[i];
            ast_Block_declare(result, param->name, param->type, TRUE, param->passByReference);
        }

        /* If function has a returntype, include name of function */
        if (function_o->returnType && ((function_o->returnType->kind != CORTO_VOID) || function_o->returnType->reference)) {
            ast_Block_declareReturnVariable(result, function_o);
        }
    }

    return result;
error:
    return NULL;
/* $end */
}

/* ::corto::ast::Parser::define() */
corto_int16 _ast_Parser_define(ast_Parser this) {
/* $begin(::corto::ast::Parser::define) */
    ast_CHECK_ERRSET(this);

    if ((this->initializerCount >= 0) && this->initializers[this->initializerCount]) {
        if (ast_Initializer_define(this->initializers[this->initializerCount])) {
            goto error;
        }
        corto_setref(&this->initializers[this->initializerCount], NULL);
        this->initializerCount--;
    }

    return 0;
error:
    fast_err;
    return -1;
/* $end */
}

/* ::corto::ast::Parser::defineScope() */
corto_int16 _ast_Parser_defineScope(ast_Parser this) {
/* $begin(::corto::ast::Parser::defineScope) */
    ast_CHECK_ERRSET(this);

    if (!this->pass) {
        if (!this->scope) {
            ast_Parser_error(this, "invalid scope expression");
            goto error;
        }

        if (corto_instanceof(corto_type(corto_type_o), this->scope)) {
            if (corto_define(this->scope)) {
                corto_id id;
                ast_Parser_error(this, "failed to define scope '%s' (%s)", ast_Parser_id(this->scope, id), corto_lasterr());
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
corto_int16 _ast_Parser_defineVariable(ast_Parser this, ast_Storage object) {
/* $begin(::corto::ast::Parser::defineVariable) */
    corto_int16 result = 0;
    CORTO_UNUSED(this);
    ast_CHECK_ERRSET(this);

    if ((ast_Node(object)->kind == Ast_StorageExpr) && (ast_Storage(object)->kind == Ast_ObjectStorage)) {
        if (corto_define(ast_Object(object)->value)) {
            corto_id id1, id2;
            ast_Parser_error(this, "define of variable '%s' of type '%s' failed",
                    ast_Parser_id(ast_Object(object)->value, id1),
                    ast_Parser_id(corto_typeof(ast_Object(object)->value), id2));
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
corto_void _ast_Parser_destruct(ast_Parser this) {
/* $begin(::corto::ast::Parser::destruct) */
    corto_iter iter;

    if (this->heapCollected) {
        iter = corto_llIter(this->heapCollected);
        while(corto_iterHasNext(&iter)) {
            corto_dealloc(corto_iterNext(&iter));
        }
        corto_llFree(this->heapCollected);
    }

    this->heapCollected = NULL;
    corto_setref(&this->scope, NULL);

    memset(this->variables, 0, sizeof(this->variables));
/* $end */
}

/* ::corto::ast::Parser::elementExpr(ast::Expression lvalue,ast::Expression rvalue) */
ast_Expression _ast_Parser_elementExpr(ast_Parser this, ast_Expression lvalue, ast_Expression rvalue) {
/* $begin(::corto::ast::Parser::elementExpr) */
    ast_Expression result = NULL;

    /* Expand element expression with comma-expressions */
    if (this->pass) {
        corto_type t = ast_Expression_getType(lvalue);
        /* If the left value is a composite type then translate element expression to members */
        if (t) {
            if (t->kind == CORTO_COMPOSITE) {
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
corto_int16 _ast_Parser_finalize(ast_Parser this, ic_program program) {
/* $begin(::corto::ast::Parser::finalize) */
    ic_scope scope = NULL;
    ic_storage returnValue = NULL;
    ast_Binding *binding;
    corto_iter bindingIter;

    /* Parse functions */
    if (this->bindings) {
        bindingIter = corto_llIter(this->bindings);
        while(corto_iterHasNext(&bindingIter)) {
            ic_op ret;
            binding = corto_iterNext(&bindingIter);
            ic_program_pushFunction(program, binding->function);
            scope = (ic_scope)ast_Block_toIc(binding->impl, program, NULL, FALSE);
            if (this->errors) {
                goto error;
            }
            if (binding->function->returnType && ((binding->function->returnType->kind != CORTO_VOID) || (binding->function->returnType->reference))) {
                corto_id name;
                corto_signatureName(corto_nameof(binding->function), name);
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

            corto_release(binding->function);
            corto_release(binding->impl);
            corto_dealloc(binding);
        }
        corto_llFree(this->bindings);
        this->bindings = NULL;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::ast::Parser::foreach(string loopId,ast::Expression collection) */
corto_int16 _ast_Parser_foreach(ast_Parser this, corto_string loopId, ast_Expression collection) {
/* $begin(::corto::ast::Parser::foreach) */
    CORTO_UNUSED(this);
    CORTO_UNUSED(loopId);
    CORTO_UNUSED(collection);
    return 0;
/* $end */
}

/* ::corto::ast::Parser::getComplexType() */
corto_type _ast_Parser_getComplexType(ast_Parser this) {
/* $begin(::corto::ast::Parser::getComplexType) */
    corto_type result = NULL;

    if (this->complexTypeSp > 0) {
        result = this->complexType[this->complexTypeSp-1];
        if (result && (result->kind != CORTO_COMPOSITE)) {
            result = NULL;
        }
    }

    return result;
/* $end */
}

/* ::corto::ast::Parser::getLvalue(bool assignment) */
ast_Expression _ast_Parser_getLvalue(ast_Parser this, corto_bool assignment) {
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
corto_type _ast_Parser_getLvalueType(ast_Parser this, corto_bool assignment) {
/* $begin(::corto::ast::Parser::getLvalueType) */
    corto_type result = NULL;

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
corto_void _ast_Parser_initDeclareStaged(ast_Parser this, ast_Expression expr) {
/* $begin(::corto::ast::Parser::initDeclareStaged) */
    corto_uint32 i;

    this->variableCount = 0;

    if (expr) {
        corto_ll exprList = ast_Expression_toList(expr);
        corto_iter iter = corto_llIter(exprList);

        if (this->stagedCount) {
            ast_Parser_error(this, "invalid declaration");
            goto error;
        }

        while(corto_iterHasNext(&iter)) {
            this->variables[this->variableCount] = corto_iterNext(&iter);
            this->variableCount++;
        }

        ast_Expression_cleanList(exprList);
    } else {
        for(i=0; i<this->stagedCount; i++) {
            if (corto_instanceof(corto_type(corto_type_o), this->scope)) {
                corto_type defaultType;
                corto_type scopeType = corto_type(corto_typeof(this->scope));
                if (scopeType->defaultType) {
                    defaultType = scopeType->defaultType;
                } else {
                    defaultType = corto_any_o;
                }

                /* Add variable to parser-list for initialization */
                ast_Parser_declaration(this, defaultType, this->staged[i].name, FALSE);

                corto_dealloc(this->staged[i].name);
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
corto_int16 _ast_Parser_initKeyValuePop(ast_Parser this) {
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
corto_int16 _ast_Parser_initKeyValuePush(ast_Parser this) {
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
corto_int16 _ast_Parser_initKeyValueSet(ast_Parser this, ast_Expression expr) {
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
corto_int16 _ast_Parser_initMember(ast_Parser this, corto_string member) {
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
corto_int16 _ast_Parser_initPop(ast_Parser this) {
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
corto_int16 _ast_Parser_initPush(ast_Parser this) {
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
        initializer = ast_Initializer(ast_InitializerExpressionCreate(variables, 1, TRUE));
        corto_setref(&this->initializers[this->initializerCount], initializer);
        ast_Parser_collect(this, initializer);
        this->variablePushed = TRUE;
    }

    return ast_Expression(initializer);
/* $end */
}

/* ::corto::ast::Parser::initPushIdentifier(Expression type) */
ast_Expression _ast_Parser_initPushIdentifier(ast_Parser this, ast_Expression type) {
/* $begin(::corto::ast::Parser::initPushIdentifier) */
    corto_object o;
    corto_type t;
    corto_bool isDynamic = TRUE;
    corto_bool forceStatic = FALSE;
    ast_InitializerVariableArray64 variables;
    memset(variables, 0, sizeof(variables));

    CORTO_UNUSED(this);
    CORTO_UNUSED(type);

    if (!type) {
        if (this->lastFailedResolve) {
            ast_Parser_error(this, "unresolved identifier '%s'", this->lastFailedResolve);
            goto error;
        } else {
            ast_Parser_error(this, "invalid expression");
            goto error;
        }
    }

    o = corto_type(ast_Object(type)->value);
    if (!corto_instanceof(corto_type(corto_type_o), o)) {
        corto_id id;
        ast_Parser_error(this, "invalid expression, '%s' is not a type", ast_Parser_id(o, id));
        goto error;
    }

    t = o;

    if (this->initializerCount >= 0) {
        ast_Initializer initializer = this->initializers[this->initializerCount];
        if (initializer) {
            if (!corto_instanceof(corto_type(ast_DynamicInitializer_o), initializer) &&
                !corto_instanceof(corto_type(ast_InitializerExpression_o), initializer)) {
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
    if (corto_instanceof(corto_type(corto_interface_o), t) && corto_interface_baseof(corto_interface(t), corto_interface(corto_type_o))) {
        forceStatic = TRUE;
    }

    /* Static initializers are executed during first pass */
    if ((!this->pass && !isDynamic) || forceStatic) {
        corto_object o;
        o = corto_declare(t);
        corto_setref(&variables[0].object, ast_Expression(ast_ObjectCreate(o)));
        this->initializers[this->initializerCount] = ast_Initializer(ast_StaticInitializerCreate(variables, 1));
        this->variablePushed = TRUE;
    } else if (this->pass && isDynamic && !forceStatic) {
        ast_Expression newExpr, assignExpr, var, refVar;
        corto_type type_o = corto_type(ast_Object(type)->value);
        refVar = var = ast_Expression(ast_TemporaryCreate(ast_Object(type)->value, TRUE));
        newExpr = ast_Expression(ast_NewCreate(ast_Object(type)->value,0));
        ast_Parser_collect(this, newExpr);
        if (!type_o->reference) {
            refVar = ast_Parser_unaryExpr(this, var, CORTO_AND);
            ast_Parser_collect(yparser(), refVar);
        }
        assignExpr = ast_Expression(ast_BinaryCreate(refVar, newExpr, CORTO_ASSIGN));
        ast_Parser_collect(this, assignExpr);
        ast_Parser_addStatement(this, ast_Node(assignExpr));

        corto_setref(&variables[0].object, var);
        this->initializers[this->initializerCount] = ast_Initializer(ast_DynamicInitializerCreate(variables, 1, FALSE));
        this->variablePushed = TRUE;
    } else {
        corto_setref(&this->initializers[this->initializerCount], NULL);
        this->variablePushed = TRUE;
    }

    return variables[0].object;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::ast::Parser::initPushStatic() */
corto_int16 _ast_Parser_initPushStatic(ast_Parser this) {
/* $begin(::corto::ast::Parser::initPushStatic) */
    corto_bool isLocal = this->isLocal;
    ast_InitializerVariableArray64 variables;
    ast_Initializer initializer;
    corto_uint32 i;

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
        corto_setref(&variables[i].object, ast_Expression(this->variables[i]));
        variables[i].key = 0;
        variables[i].offset = 0;
    }

    if (!this->pass) {
        /* Create initializer */
        initializer = ast_Initializer(ast_StaticInitializerCreate(variables, this->variableCount));
        corto_setref(&this->initializers[this->initializerCount], initializer);
        ast_Parser_collect(this, initializer);
    } else {
        /* Create dummy initializer */
        initializer = ast_InitializerCreate(variables, this->variableCount);
        corto_setref(&this->initializers[this->initializerCount], initializer);
        ast_Parser_collect(this, initializer);
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::ast::Parser::initStage(string id,bool found) */
corto_void _ast_Parser_initStage(ast_Parser this, corto_string id, corto_bool found) {
/* $begin(::corto::ast::Parser::initStage) */

    this->staged[this->stagedCount].name = corto_strdup(id);
    this->staged[this->stagedCount].line = this->line;
    this->staged[this->stagedCount].column = this->column;
    this->staged[this->stagedCount].found = found;
    this->stagedCount++;

/* $end */
}

/* ::corto::ast::Parser::initValue(Expression expr) */
corto_int16 _ast_Parser_initValue(ast_Parser this, ast_Expression expr) {
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
corto_bool _ast_Parser_isAbortSet(ast_Parser this) {
/* $begin(::corto::ast::Parser::isAbortSet) */
    corto_bool result = this->abort;
    this->abort = FALSE;
    return result;
/* $end */
}

/* ::corto::ast::Parser::isErrSet() */
corto_bool _ast_Parser_isErrSet(ast_Parser this) {
/* $begin(::corto::ast::Parser::isErrSet) */
    corto_bool result = this->errSet;
    this->errSet = FALSE;
    return result;
/* $end */
}

/* ::corto::ast::Parser::lookup(string id) */
ast_Expression _ast_Parser_lookup(ast_Parser this, corto_string id) {
/* $begin(::corto::ast::Parser::lookup) */
    ast_Expression result = NULL;
    ast_CHECK_ERRSET(this);

    if (this->pass) {
        /* If complexType is set, this resolve is ran within a [] expression */
        corto_type complexType = ast_Parser_getComplexType(this);
        if (complexType) {
            if (corto_interface_resolveMember(corto_interface(complexType), id)) {
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
            corto_instanceof(corto_type(ast_StaticInitializer_o), this->initializers[this->initializerCount]))) {
            ast_Parser_error(this, "unresolved identifier '%s'", id);
            fast_err;
        }

        if (this->lastFailedResolve) {
            corto_dealloc(this->lastFailedResolve);
        }
        this->lastFailedResolve = corto_strdup(id);
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
        corto_type t = ast_Expression_getType(lvalue);
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
ast_Storage _ast_Parser_observerDeclaration(ast_Parser this, corto_string id, ast_Expression object, corto_eventMask mask, ast_Object dispatcher) {
/* $begin(::corto::ast::Parser::observerDeclaration) */
    CORTO_UNUSED(object);
    CORTO_UNUSED(mask);
    ast_CHECK_ERRSET(this);

    this->stagingAllowed = FALSE;

    ast_Storage result = NULL;
    corto_bool isTemplate = corto_class_instanceof(corto_type_o, this->scope);

    if (!(mask & CORTO_ON_SCOPE)) {
        mask |= CORTO_ON_SELF;
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
        corto_observer observer;
        corto_object observable = NULL;
        corto_uint32 i;

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
            observer = corto_class_findObserver(corto_class(this->scope), observable);
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
            ast_Block_declare(block, "this", corto_object_o, TRUE, FALSE);
        }

        /* Loop parameters of observable, insert locals */
        for(i=0; i<corto_function(observer)->parameters.length; i++) {
            corto_parameter *p = &corto_function(observer)->parameters.buffer[i];
            ast_Block_declare(block, p->name, p->type, TRUE, TRUE); /* Observable parameter are references */
        }

        /* Bind observer and block */
        ast_Parser_bind(this, result, block);
        ast_Block_setFunction(block, corto_function(observer));
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::ast::Parser::observerPush() */
corto_void _ast_Parser_observerPush(ast_Parser this) {
/* $begin(::corto::ast::Parser::observerPush) */
    ast_CHECK_ERRSET(this);

    /* Observer-implementations are parsed in the 2nd pass */
    if (this->pass) {
        if (corto_class_instanceof(corto_type_o, this->scope)) {
            ast_Block block;
            block = ast_Parser_blockPush(this, TRUE);
            ast_Block_declareTemplate(block, "this", this->scope, TRUE, FALSE);
        }
    }

/* $end */
}

/* ::corto::ast::Parser::parse(sequence{string} argv) */
corto_uint32 _ast_Parser_parse(ast_Parser this, corto_stringSeq argv) {
/* $begin(::corto::ast::Parser::parse) */
    ast_CHECK_ERRSET(this);

    this->pass = 0;
    if ( fast_yparse(this, 1, 1)) {
        corto_print("%s: parsed with errors (%d errors, %d warnings)", this->filename, this->errors, this->warnings);
        goto error;
    }

    /* Reset parser-state so 2nd pass starts clean */
    ast_Parser_reset(this);
    corto_setref(&this->scope, NULL);

    this->pass = 1;
    if ( fast_yparse(this, 1, 1)) {
        corto_print("%s: parsed with errors (%d errors, %d warnings)", this->filename, this->errors, this->warnings);
        goto error;
    }

    /* Parse to corto intermediate code */
    if ( ast_Parser_toIc(this, argv)) {
        corto_print("%s: parsed with errors (%d errors, %d warnings)", this->filename, this->errors, this->warnings);
        goto error;
    }

    return 0;
error:
    fast_err;
    return -1;
/* $end */
}

/* ::corto::ast::Parser::parseExpression(string expr,ast::Block block,object scope,uint32 line,uint32 column) */
ast_Expression _ast_Parser_parseExpression(ast_Parser this, corto_string expr, ast_Block block, corto_object scope, corto_uint32 line, corto_uint32 column) {
/* $begin(::corto::ast::Parser::parseExpression) */
    ast_Expression result = NULL;
    corto_string exprFinalized;

    CORTO_UNUSED(scope);

    if (this->source) {
        corto_dealloc(this->source);
    }

    exprFinalized = corto_alloc(strlen(expr) + 2);
    sprintf(exprFinalized, "%s\n", expr);

    this->source = exprFinalized;

    corto_setref(&this->block, block);
    corto_setref(&this->scope, scope);

    // Give expression its own block
    ast_Parser_blockPush(this, FALSE);
    if (fast_yparse(this, line, column)) {
        corto_print("%s: expression '%s' parsed with errors", this->filename, expr);
        ast_Parser_blockPop(this);
        goto error;
    }

    /* Extract expression */
    block = this->block;
    ast_Parser_blockPop(this);
    if (block) {
        /* Block should contain exactly one expression */
        if (block->statements) {
            if (corto_llSize(block->statements) == 1) {
                ast_Node node;
                node = corto_llGet(block->statements, 0);
                if (corto_instanceof(corto_type(ast_Expression_o), node)) {
                    result = ast_Expression(node);
                } else {
                    corto_id id;
                    corto_print("%s: '%s' does not resolve to a valid expression (found %s).",
                            this->filename, expr, ast_Parser_id(corto_typeof(node), id));
                    goto error;
                }
            } else {
                corto_print("%s: expression '%s' is not allowed to contain multiple statements", this->filename, expr);
                goto error;
            }
        } else {
            corto_print("%s: expression '%s' did not result in a statement", this->filename, expr);
            goto error;
        }
    } else {
        corto_print("parser error: no block set in parser after parsing expression.");
        goto error;
    }

    return result;
error:
    return NULL;
/* $end */
}

/* ::corto::ast::Parser::parseLine(string expr,object scope,word value) */
corto_int16 _ast_Parser_parseLine(corto_string expr, corto_object scope, corto_word value) {
/* $begin(::corto::ast::Parser::parseLine) */
    ast_Parser parser = ast_ParserCreate(expr, NULL);
    ic_program program = ic_programCreate(parser->filename);
    ast_Expression result = NULL; /* Resulting ast-expression of 'exr' */
    ic_scope icScope; /* Parsed intermediate-code program */
    ic_storage returnValue = NULL; /* Intermediate representation of return value */
    corto_type returnType = NULL; /* Return type */
    ic_op ret = NULL; /* ret or stop instruction */
    corto_value *v = (corto_value*)value;

    parser->repl = TRUE;

    parser->pass = 0;
    corto_setref(&parser->scope, scope);
    if ( fast_yparse(parser, 1, 1)) {
        goto error;
    }

    if (parser->errors) {
        goto error;
    }

    /* Reset parser-state so 2nd pass starts clean */
    ast_Parser_reset(parser);

    parser->pass = 1;
    corto_setref(&parser->scope, scope);
    if (fast_yparse(parser, 1, 1)) {
        goto error;
    }

    /* Find last executed expression */
    if (parser->block) {
        if (corto_llSize(parser->block->statements)) {
            ast_Node lastNode = corto_llLast(parser->block->statements);

            /* If node is an expression, store expression in variable so it can be resolved later */
            if (corto_instanceof(corto_type(ast_Expression_o), lastNode) && (lastNode->kind != Ast_CommaExpr)) {
                ast_Local resultLocal;
                ast_Binary assignment;
                result = ast_Expression(lastNode);

                if (result->type) {
                    returnType = corto_type(ast_Expression_getType(result));
                    if ((returnType->kind != CORTO_VOID) || (result->deref == Ast_ByReference)) {
                        resultLocal = ast_Block_declare(parser->block, "<result>", result->type, FALSE,
                            result->isReference);
                        ast_Expression(resultLocal)->deref = result->isReference ? Ast_ByReference : Ast_ByValue;
                        if (!resultLocal) {
                            goto error;
                        }
                        resultLocal->kind = Ast_LocalReturn;
                        assignment = ast_BinaryCreate(ast_Expression(resultLocal), result, CORTO_ASSIGN);
                        corto_llReplace(parser->block->statements, lastNode, assignment);
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
    extern corto_bool CORTO_DEBUG_ENABLED;
    if (CORTO_DEBUG_ENABLED) {
        printf("=====\n%s\n\n", ic_program_toString(program));
    }
#endif

    /* Translate program to vm code */
    ic_program_assemble(program);

    /* Run vm program */
    if (returnValue) {
        if (result->isReference) {
            corto_object o = NULL;
            ic_program_run(program, (corto_word)&o, CORTO_SEQUENCE_EMPTY(corto_stringSeq));
            if (o) {
                corto_valueObjectInit(v, o, NULL);
            } else {
                v->is.value.storage = 0;
                corto_valueValueInit(v, NULL, corto_object_o, &v->is.value.storage);
            }
        } else {
            if(returnType->kind == CORTO_PRIMITIVE) {
                corto_valueValueInit(v, NULL, returnType, &v->is.value.storage);
                ic_program_run(program, (corto_word)&v->is.value.storage, CORTO_SEQUENCE_EMPTY(corto_stringSeq));
            } else {
                void *ptr = corto_alloc(corto_type_sizeof(returnType));
                ic_program_run(program, (corto_word)&ptr, CORTO_SEQUENCE_EMPTY(corto_stringSeq));
                if (ptr) {
                    corto_valueValueInit(v, NULL, returnType, ptr);
                } else {
                    v->is.value.storage = 0;
                    corto_valueValueInit(v, NULL, corto_object_o, &v->is.value.storage);
                }
            }
        }
    } else {
        ic_program_run(program, 0, CORTO_SEQUENCE_EMPTY(corto_stringSeq));
        if (v) {
            corto_valueValueInit(v, NULL, corto_type(corto_void_o), NULL);
        }
    }

    /* Free program */
    corto_release(program);

    /* Free parser */
    corto_release(parser);

    return 0;
error:
    corto_release(program);
    return -1;
/* $end */
}

/* ::corto::ast::Parser::popComplexType() */
corto_void _ast_Parser_popComplexType(ast_Parser this) {
/* $begin(::corto::ast::Parser::popComplexType) */

    this->complexTypeSp--;
    if (this->complexTypeSp < 0) {
        ast_Parser_error(this, "parser error: complexType stack pointer below zero");
        abort();
    }

/* $end */
}

/* ::corto::ast::Parser::popLvalue() */
corto_void _ast_Parser_popLvalue(ast_Parser this) {
/* $begin(::corto::ast::Parser::popLvalue) */

    this->lvalueSp--;
    if (this->lvalueSp < 0) {
        ast_Parser_error(this, "parser error: lvalue stack pointer below zero");
        abort();
    }

/* $end */
}

/* ::corto::ast::Parser::popScope(object previous) */
corto_void _ast_Parser_popScope(ast_Parser this, corto_object previous) {
/* $begin(::corto::ast::Parser::popScope) */
    ast_CHECK_ERRSET(this);

    /* Restore scope */
    corto_setref(&this->scope, previous);
/* $end */
}

/* ::corto::ast::Parser::postfixExpr(ast::Expression lvalue,operatorKind operator) */
ast_Expression _ast_Parser_postfixExpr(ast_Parser this, ast_Expression lvalue, corto_operatorKind _operator) {
/* $begin(::corto::ast::Parser::postfixExpr) */
    ast_Expression result = NULL;

    this->stagingAllowed = FALSE;

    if (this->pass) {
        result = ast_Expression(ast_PostFixCreate(lvalue, _operator));
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
corto_void _ast_Parser_pushComplexType(ast_Parser this, ast_Expression lvalue) {
/* $begin(::corto::ast::Parser::pushComplexType) */

    if (lvalue) {
        corto_setref(&this->complexType[this->complexTypeSp], ast_Expression_getType(lvalue));
    } else {
        corto_setref(&this->complexType[this->complexTypeSp], NULL);
    }
    this->complexTypeSp++;

/* $end */
}

/* ::corto::ast::Parser::pushLvalue(ast::Expression lvalue,bool isAssignment) */
corto_void _ast_Parser_pushLvalue(ast_Parser this, ast_Expression lvalue, corto_bool isAssignment) {
/* $begin(::corto::ast::Parser::pushLvalue) */

    corto_setref(&this->lvalue[this->lvalueSp].expr, lvalue);
    this->lvalue[this->lvalueSp].isAssignment = isAssignment;
    this->lvalueSp++;

/* $end */
}

/* ::corto::ast::Parser::pushPackage(string name) */
corto_int16 _ast_Parser_pushPackage(ast_Parser this, corto_string name) {
/* $begin(::corto::ast::Parser::pushPackage) */
    char ch, *ptr, *bptr;
    corto_id buffer;

    if (this->scope && (this->scope != root_o)) {
        ast_Parser_error(this, "#package may only be used in the root scope");
        goto error;
    }

    corto_setref(&this->scope, root_o);
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
                corto_object o = corto_resolve(this->scope, buffer);
                if (!o) {
                    /* Declare package */
                    ast_Parser_declaration(this, corto_type(corto_package_o), buffer, FALSE);

                    /* Push package as scope */
                    ast_Parser_pushScope(this);

                    /* Define package */
                    ast_Parser_defineScope(this);
                } else {
                    corto_setref(&this->scope, o);
                    corto_release(o);
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
    ast_Parser_declaration(this, corto_type(corto_package_o), buffer, FALSE);

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
corto_void _ast_Parser_pushReturnAsLvalue(ast_Parser this, corto_function function) {
/* $begin(::corto::ast::Parser::pushReturnAsLvalue) */
    ast_Expression result = NULL;

    if (this->pass) {
        if (function->returnType) {
            corto_id id;
            corto_signatureName(corto_nameof(function), id);
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
corto_object _ast_Parser_pushScope(ast_Parser this) {
/* $begin(::corto::ast::Parser::pushScope) */
    corto_object oldScope = NULL;

    ast_CHECK_ERRSET(this);

    oldScope = this->scope;
    if (!this->variableCount) {
        /* This is the result of a previous error */
        goto error;
    }

    if (this->variables[0]) {
        corto_setref(&this->scope, ast_Object(this->variables[0])->value);
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
corto_void _ast_Parser_reset(ast_Parser this) {
/* $begin(::corto::ast::Parser::reset) */
    corto_uint32 i;

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
            corto_dealloc(this->staged[i].name);
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
ast_Expression _ast_Parser_unaryExpr(ast_Parser this, ast_Expression lvalue, corto_operatorKind _operator) {
/* $begin(::corto::ast::Parser::unaryExpr) */
    ast_Expression result = NULL;

    this->stagingAllowed = FALSE;

    if (lvalue) {
        if (_operator == CORTO_SUB) {
            corto_type lvalueType = ast_Expression_getType(lvalue);

            if (lvalueType->kind == CORTO_PRIMITIVE) {
                switch(corto_primitive(lvalueType)->kind) {
                case CORTO_INTEGER:
                    if (ast_Node(lvalue)->kind == Ast_LiteralExpr) {
                        result = ast_Expression(ast_IntegerCreate(ast_Integer(lvalue)->value * -1));
                        ast_Parser_collect(this, result);
                        break;
                    }
                    /* no break */
                case CORTO_UINTEGER:
                    if (ast_Node(lvalue)->kind == Ast_LiteralExpr) {
                        result = ast_Expression(ast_SignedIntegerCreate(ast_Integer(lvalue)->value * -1));
                        ast_Parser_collect(this, result);
                        break;
                    }
                    /* no break */
                case CORTO_FLOAT:
                    if (ast_Node(lvalue)->kind == Ast_LiteralExpr) {
                        result = ast_Expression(ast_FloatingPointCreate(ast_FloatingPoint(lvalue)->value * -1));
                        ast_Parser_collect(this, result);
                    } else {
                        if (this->pass) {
                            ast_SignedInteger minusOne = ast_SignedIntegerCreate(-1);
                            ast_Parser_collect(this, minusOne);
                            result = ast_Expression(ast_BinaryCreate(lvalue, ast_Expression(minusOne), CORTO_MUL));
                            ast_Parser_collect(this, result);
                        }
                    }
                    break;
                default: {
                    corto_id id;
                    ast_Parser_error(this, "unary operator - not applicable to type '%s'", ast_Parser_id(lvalueType, id));
                    goto error;
                }
                }
            } else {
                corto_id id;
                ast_Parser_error(this, "unary operator - not applicable to non-primitive type '%s'", ast_Parser_id(lvalueType, id));
                goto error;
            }
        } else if (_operator == CORTO_AND) {
            if (ast_Node(lvalue)->kind == Ast_StorageExpr) {
                if (lvalue->isReference) {
                    if (corto_copy((corto_object*)&result, lvalue)) {
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
                result = ast_Expression(ast_UnaryCreate(lvalue, _operator));
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
        corto_function function;
        corto_procedureKind procedureKind;
        corto_ll exprList;

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
            procedureKind = corto_procedure(corto_typeof(function))->kind;
            if (functionBlock) {
                if ((procedureKind == CORTO_METHOD) || ((procedureKind == CORTO_OBSERVER) && corto_observer(function)->_template)) {
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
        corto_ll exprList = ast_Expression_toList(expr);

        result = ast_Expression(ast_WaitCreate(exprList, timeout));
        ast_Parser_collect(this, result);
    }

    return result;
/* $end */
}

/* ::corto::ast::Parser::whileStatement(ast::Expression condition,ast::Block trueBranch,bool isUntil) */
ast_Node _ast_Parser_whileStatement(ast_Parser this, ast_Expression condition, ast_Block trueBranch, corto_bool isUntil) {
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
            corto_setref(&this->block->_while, result);
        }
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}
