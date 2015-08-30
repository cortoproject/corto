/* Fast_Parser.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"

/* $header() */
#include "Fast__private.h"

#define Fast_CHECK_ERRSET(parser) cx_assert(!parser->errSet, "%s:%d:%d: parser did not check error-status set on line %d", _this->filename, _this->line, _this->column, _this->errLine)
/*#define Fast_PARSER_DEBUG*/
#define fast_err _this->errSet = TRUE; _this->errLine = __LINE__;

extern cx_threadKey Fast_PARSER_KEY;

void Fast_Parser_error(Fast_Parser _this, char* fmt, ... ) {
    va_list args;
    char msgbuff[1024];
    cx_id token;
    int line = _this->line;

    if (_this->token) {
        if (*_this->token == '\n') {
            sprintf(token, "end of line");
            line--;
        } else {
            sprintf(token, "'%s'", _this->token);
        }
    } else {
        *token = '\0';
    }

    va_start(args, fmt);
    vsprintf(msgbuff, fmt, args);
    va_end(args);

    Fast_reportError(_this->filename, _this->column ? line : line - 1, _this->column, msgbuff, token);

    _this->errors++;
}

void Fast_Parser_warning(Fast_Parser _this, char* fmt, ... ) {
    va_list args;
    char msgbuff[1024];
    cx_id token;
    int line = _this->line;

    if (_this->token) {
        if (*_this->token == '\n') {
            sprintf(token, "end of line");
            line--;
        } else {
            sprintf(token, "'%s'", _this->token);
        }
    } else {
        *token = '\0';
    }

    va_start(args, fmt);
    vsprintf(msgbuff, fmt, args);
    va_end(args);

    Fast_reportWarning(_this->filename, line, _this->column, msgbuff, token);

    _this->warnings++;
}

/* Generate user-friendly id's for both scoped and unscoped objects */
cx_string Fast_Parser_id(cx_object o, cx_id buffer) {
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
cx_int16 Fast_Parser_toIc(Fast_Parser _this) {
    ic_program program = ic_program__create(_this->filename);

    /* Parse root-block */
    Fast_Block_toIc(_this->block, program, NULL, FALSE);
    if (_this->errors) {
        goto error;
    }

    /* Bind function implementations to function objects */
    if (Fast_Parser_finalize(_this, program)) {
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
    ic_program_run(program, 0);

    /* Free program */
    cx_release(program);

    return 0;
error:
    cx_release(program);
    return -1;
}

/* Use cx_object as returntype as the actual type (Fast_Expression) causes macro-expansion */
typedef cx_object (*Fast_ExpandAction)(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue, void *userData);

/* Combine results in new comma expression */
cx_object Fast_Parser_combineComma(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue, void *userData) {
    CX_UNUSED(_this);
    CX_UNUSED(userData);
    return Fast_Comma_addOrCreate(lvalue, rvalue);
}

/* Combine results as part of conditional expression */
cx_object Fast_Parser_combineConditionalExpr(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue, void *userData) {
    cx_operatorKind oper = *(cx_operatorKind*)userData;
    cx_operatorKind combineOper;
    Fast_Expression result;

    /* Default combine is AND, except the != operator, which inserts an OR */
    if (lvalue) {
        if (oper == CX_COND_NEQ) {
            combineOper = CX_COND_OR;
        } else {
            combineOper = CX_COND_AND;
        }

        result = Fast_Expression(Fast_Binary__create(lvalue, rvalue, combineOper));
        Fast_Parser_collect(_this, result);

        /* Fold expression where possible */
        result = Fast_Expression_fold(result);
        if (!result) {
            Fast_Parser_error(_this, "folding failed for expression");
        }
    } else {
        result = rvalue;
    }

    return result;
}

/* Create binary expression with ternary operand */
Fast_Expression Fast_Parser_createBinaryTernary(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue, cx_operatorKind operator) {
    Fast_Expression result = NULL;
    CX_UNUSED(_this);

    /* If the operation is an assignment, the ternary operator has already constructed the binary operation through an lvalue - see
     * the implementation of Fast_Parser_Ternary. If the operation is not an assignment, create the binary expression. */
    switch(operator) {
    case CX_ASSIGN:
    case CX_ASSIGN_ADD:
    case CX_ASSIGN_SUB:
    case CX_ASSIGN_MUL:
    case CX_ASSIGN_DIV:
    case CX_ASSIGN_MOD:
    case CX_ASSIGN_OR:
    case CX_ASSIGN_AND:
        Fast_Ternary_setOperator(Fast_Ternary(rvalue), operator);
        cx_setref(&result, rvalue);
        break;
    default:
        result = Fast_Expression(Fast_Binary__create(lvalue, rvalue, operator));
        Fast_Parser_collect(_this, result);
        break;
    }

    return result;
}

/* Match parameter */
cx_bool Fast_Parser_matchDelegateParameter(
    Fast_Parser _this,
    cx_string name,
    cx_type t1,
    cx_bool isRef1,
    cx_type t2,
    cx_bool isRef2) {

    if ((t1 != t2) || (isRef1 && !isRef2)) {
        cx_id id1, id3, id4;

        Fast_Parser_error(_this, "%s %s '%s%s' of procedure doesn't match '%s%s' of delegate '%s'",
            name ? "parameter" : "",
            name ? name : "returntype",
            Fast_Parser_id(t1, id1),
            isRef1 ? "&" : "",
            Fast_Parser_id(t2, id3),
            isRef2 ? "&" : "",
            Fast_Parser_id(t2, id4));
        goto error;
    }

    return TRUE;
error:
    return FALSE;
}

/* Create and validate delegate assignment */
Fast_Expression Fast_Parser_delegateAssignment(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue) {
    cx_uint32 i;
    Fast_Expression instance = NULL;
    Fast_Expression functionExpr = NULL;
    cx_id functionName;
    Fast_InitializerExpression result = NULL;
    cx_string signature = NULL;
    cx_delegate type = NULL;
    Fast_InitializerVariable_array64 variables;
    Fast_CallBuilder builder;
    Fast_Call tempCall = NULL;

    memset(variables, 0, sizeof(variables));

    /* Validate whether rvalue is an object */
    if ((Fast_Node(rvalue)->kind == Fast_StorageExpr) && (Fast_Storage(rvalue)->kind == Fast_ObjectStorage)) {
        cx_signatureName(cx_nameof(Fast_Object(rvalue)->value), functionName);
    } else if ((Fast_Node(rvalue)->kind == Fast_StorageExpr) && (Fast_Storage(rvalue)->kind == Fast_MemberStorage)) {
        instance = Fast_Member(rvalue)->lvalue;
        strcpy(functionName, Fast_String(Fast_Member(rvalue)->rvalue)->value);
    } else {
        Fast_Parser_error(_this, "dynamic delegate assignments are not yet supported");
        goto error;
    }

    type = cx_delegate(Fast_Expression_getType(lvalue));

    /* Build request-signature */
    signature = cx_signatureOpen(functionName);
    for (i = 0; i < type->parameters.length; i++) {
        cx_parameter *p = &type->parameters.buffer[i];
        signature = cx_signatureAdd(signature, p->type, p->passByReference ? CX_PARAMETER_FORCEREFERENCE : 0);
    }
    signature = cx_signatureClose(signature);

    /* Resolve function */
    Fast_CallBuilder__init(&builder);
    Fast_CallBuilder__set(
        &builder,
        signature,
        NULL,
        instance,
        _this->scope,
        yparser()->block);
    tempCall = Fast_CallBuilder_build(&builder);
    Fast_CallBuilder__deinit(&builder);

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
    if (!Fast_Parser_matchDelegateParameter(
        _this,
        NULL,
        type->returnType,
        type->returnsReference,
        tempCall->returnType,
        tempCall->returnsReference)) {
        goto error;
    }

    /* Validate number of parameters */
    if (type->parameters.length != tempCall->parameters.length) {
        Fast_Parser_error(_this, "number of procedure parameters(%d) doesn't match delegate (%d)",
            tempCall->parameters.length,
            type->parameters.length);
        goto error;
    }

    /* Validate parameters */
    for (i=0; i<type->parameters.length; i++) {
        cx_parameter *p1, *p2;
        p1 = &type->parameters.buffer[i];
        p2 = &tempCall->parameters.buffer[i];

        if (!Fast_Parser_matchDelegateParameter(
            _this,
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
    result = Fast_InitializerExpression__create(variables, 1, TRUE);
    Fast_InitializerExpression_push(result);
    if (instance) {
        Fast_InitializerExpression_member(result, "instance");
        Fast_InitializerExpression_value(result, instance);
    }
    Fast_InitializerExpression_member(result, "procedure");
    Fast_InitializerExpression_value(result, functionExpr);
    Fast_InitializerExpression_pop(result);
    Fast_InitializerExpression_define(result);
    Fast_Parser_collect(_this, result);

    cx_dealloc(signature);
    cx_release(tempCall);

    return Fast_Expression(result);
error:
    if(signature) {
        cx_dealloc(signature);
    }
    return NULL;
}

/* Callback function for expansion of binary expressions */
cx_object Fast_Parser_expandBinary(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue, void *userData) {
    Fast_Expression result = NULL;
    cx_type tleft, tright;
    cx_operatorKind operator = *(cx_operatorKind*)userData;

    if (!(tleft = Fast_Expression_getType_expr(lvalue, rvalue))) {
        goto error;
    }

    if (!(tright = Fast_Expression_getType_expr(rvalue, lvalue))) {
        goto error;
    }

    if (tleft && (tleft->kind == CX_COMPOSITE) && (cx_interface(tleft)->kind == CX_DELEGATE)) {
        if (*(cx_operatorKind*)userData == CX_ASSIGN) {
            rvalue = Fast_Parser_delegateAssignment(_this, lvalue, rvalue);
            if(!rvalue) {
                goto error;
            }
        } else {
            Fast_Parser_error(_this, "operators other than assign not valid for delegates");
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
    if (Fast_Node(rvalue)->kind == Fast_TernaryExpr) {
        result = Fast_Parser_createBinaryTernary(_this, lvalue, rvalue, operator);

    /* Binary expression with iterator value on the left-hand side */
    } else if (tleft && tleft->kind == CX_ITERATOR) {
        result = Fast_Expression(Fast_Binary__create(lvalue, rvalue, operator));

    /* Binary expression with primitive or reference values */
    } else {
        result = Fast_Expression(Fast_Binary__create(lvalue, rvalue, operator));

        /* Fold expression */
        if (result) {
            result = Fast_Expression_fold(result);
            if (!result) {
                Fast_Parser_error(_this, "folding failed for expression");
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
cx_object Fast_Parser_expandMember(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue, void *userData) {
    CX_UNUSED(userData);
    CX_UNUSED(_this);
    Fast_Expression result = NULL;

    /* Create member expression */
    result = Fast_Expression(Fast_Member__create(lvalue, rvalue));
    if (!result) {
        goto error;
    }

    return result;
error:
    return NULL;
}


/* Callback function for expansion of element expressions */
cx_object Fast_Parser_expandElement(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue, void *userData) {
    CX_UNUSED(_this);
    CX_UNUSED(userData);
    Fast_Expression result = (Fast_Expression)Fast_Element__create(lvalue, rvalue);
    if (!result) {
        goto error;
    }

    return result;
error:
    return NULL;
}

/* Generic function to "explode" comma-expressions. This results in (ln * rn) expressions */
Fast_Expression Fast_Parser_explodeComma(Fast_Parser _this, Fast_Expression lvalues, Fast_Expression rvalues, Fast_ExpandAction action, void *userData) {
    cx_ll lvalueList, rvalueList;
    Fast_Expression result = NULL;
    Fast_Expression var = NULL;
    cx_uint32 lvalueCount, rvalueCount;

    lvalueList = Fast_Expression_toList(lvalues);
    rvalueList = Fast_Expression_toList(rvalues);
    lvalueCount = cx_llSize(lvalueList);
    rvalueCount = cx_llSize(rvalueList);

    if ((rvalueCount > 1) && (lvalueCount == 1)) {
        /* Only temporarily store rvalue if it has side effects */
        if (Fast_Expression_hasSideEffects(Fast_Expression(cx_llGet(lvalueList,0)))) {
            if (Fast_Node(rvalues)->kind != Fast_InitializerExpr) {
                var = Fast_Expression(Fast_Temporary__create(lvalues->type, lvalues->isReference));
                Fast_Parser_addStatement(_this, Fast_Parser_binaryExpr(_this, var, lvalues, CX_ASSIGN));
                rvalues = var;
            }
        }
    }

    Fast_Expression_list__foreach(lvalueList, l)
        Fast_Expression_list__foreach(rvalueList, r)
            Fast_Expression e = action(_this, var ? var : l, r, userData);
            if (!e) {
                goto error;
            }
            Fast_Parser_collect(_this, e);
            result = Fast_Comma_addOrCreate(result, e);
        }
    }

    /* Clean-up list */
    Fast_Expression_cleanList(lvalueList);
    Fast_Expression_cleanList(rvalueList);

    return result;
error:
    return NULL;
}

/* Generic function to expand comma-expressions */
Fast_Expression Fast_Parser_expandComma(Fast_Parser _this, Fast_Expression lvalues, Fast_Expression rvalues, Fast_ExpandAction action, Fast_ExpandAction combine, void *userData) {
    cx_int16 lvalueCount, rvalueCount;
    cx_ll lvalueList, rvalueList;
    cx_iter lIter, rIter;
    cx_type tleft, tright;
    Fast_Expression result = NULL, localResult = NULL;
    enum {
        EXPAND_LEFT,
        EXPAND_RIGHT,
        EXPAND_BOTH
    } expandMode = EXPAND_LEFT; /* Expand left, right or both */

    lvalueList = Fast_Expression_toList(lvalues);
    rvalueList = Fast_Expression_toList(rvalues);
    lvalueCount = cx_llSize(lvalueList);
    rvalueCount = cx_llSize(rvalueList);

    /* If there is more than one lvalue assign rvalue to temporary value first. This will assure that rvalue is evaluated
     * only once. */
    if ((lvalueCount > 1) && (rvalueCount == 1)) {
        /* Only temporarily store rvalue if it has side effects */
        if (Fast_Expression_hasSideEffects(Fast_Expression(cx_llGet(rvalueList,0)))) {
            if (Fast_Node(rvalues)->kind != Fast_InitializerExpr) {
                Fast_Expression var = Fast_Expression(Fast_Temporary__create(rvalues->type, FALSE));
                Fast_Parser_addStatement(_this, Fast_Parser_binaryExpr(_this, var, rvalues, CX_ASSIGN));
                rvalues = var;
            }
        }
        expandMode = EXPAND_LEFT;
    } else if ((rvalueCount > 1) && (lvalueCount == 1)) {
        expandMode = EXPAND_RIGHT;
    } else if (lvalueCount == rvalueCount) {
        expandMode = EXPAND_BOTH;
    } else {
        Fast_Parser_error(_this, "mismatch in expression count of binary operation (left = %d, right = %d)",
                          cx_llSize(lvalueList), cx_llSize(rvalueList));
        goto error;
    }

    /* Loop through lvalues */
    lIter = cx_llIter(lvalueList);
    rIter = cx_llIter(rvalueList);
    Fast_Expression lvalue = lvalues;
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
        localResult = action(_this, lvalue, rvalues, userData);
        if (!localResult) {
            goto error;
        }

        if (!(tleft = Fast_Expression_getType_expr(lvalue,rvalues))) {
            goto error;
        }

        if (!(tright = Fast_Expression_getType_expr(rvalues,lvalue))) {
            goto error;
        }

        if (localResult) {
            localResult = Fast_Expression_fold(localResult);
            if (!localResult) {
                Fast_Parser_error(_this, "folding failed for expression");
            }
        }

        result = combine(_this, result, localResult, userData);
    }

    /* Clean-up list */
    Fast_Expression_cleanList(lvalueList);
    Fast_Expression_cleanList(rvalueList);
    lvalueList = NULL;
    rvalueList = NULL;

    return result;
error:
    return NULL;
}

Fast_Expression Fast_Parser_resolve(Fast_Parser _this, cx_id id) {
    Fast_Expression result = NULL;
    cx_object object;
    cx_char *ptr, ch;
    cx_id buffer;
    cx_char *bptr;

    if (strchr(id, ':')) {
        ptr = id;
        bptr = buffer;
        do {
            object = cx_resolve(_this->scope, id);
            if (object){
                result = Fast_Expression(Fast_Object__create(object));
                Fast_Parser_collect(_this, result);
                cx_release(object);
                break;
            } else {
                if (*ptr) {
                    int oldEcho;
                    while((ch=*ptr) && (ch != ':')) {
                        *bptr = ch;
                        bptr++;
                        ptr++;
                    }
                    *bptr = '\0';
                    oldEcho = cx_toggleEcho(FALSE);
                    cx_load(buffer);
                    cx_toggleEcho(oldEcho);
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
        object = cx_resolve(_this->scope, id);
        if (!object){
            cx_object rvalueType = Fast_Parser_getLvalueType(_this, FALSE);
            if (rvalueType && cx_checkAttr(rvalueType, CX_ATTR_SCOPED)) {
                object = cx_resolve(rvalueType, id);
            }
        }
        if (object) {
            result = Fast_Expression(Fast_Object__create(object));
            Fast_Parser_collect(_this, result);
            cx_release(object);
        }
    }

    return result;
error:
    Fast_Parser_error(_this, "unresolved identifier '%s'", id);
    fast_err;
    return NULL;
}

/* Create an observer */
Fast_Storage Fast_Parser_observerCreate(Fast_Parser _this, cx_string id, Fast_Expression object, cx_eventMask mask, Fast_Object dispatcherVar) {
    Fast_Storage result = NULL;
    cx_observer observer;
    cx_object observable = NULL;
    cx_object parent;
    cx_object dispatcher = NULL;

    /* If object is zero, this indicates either a template local or an expression during the 1st pass. TODO: how to handle
     * declaring expressions in the 1st pass - possible solution is setting the expression in the 2nd pass but then how can
     * the observer be identified?
     */

    parent = _this->scope;
    if (!cx_class_instanceof(cx_type_o, parent)) {
        parent = NULL;
    }

    if (dispatcherVar) {
        dispatcher = Fast_Object(dispatcherVar)->value;
    }

    if (object && (Fast_Node(object)->kind == Fast_StorageExpr)) {
        switch(Fast_Storage(object)->kind) {
        case Fast_ObjectStorage:
            observable = Fast_Object(object)->value;
            break;
        case Fast_TemplateStorage:
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
        observer = cx_observer__declare();
        if (!observer) {
            goto error;
        }

        /* Set values of observer - but don't yet define it. It will be defined when
         * the observer is bound to the implementation */
        cx_setref(&observer->observable, observable);
        observer->mask = mask;
        cx_setref(&observer->dispatcher, dispatcher);

        cx_attach(_this->scope, observer);

        /* If observer is a template observer, manually attach */
        if (parent) {
            cx_class_bindObserver(cx_class(parent), observer);
        }
    } else {
        observer = cx_observer__declareChild(_this->scope, id);
        if (!observer) {
            goto error;
        }

        if (cx_observer__define(observer, observable, mask, dispatcher, NULL)) {
            goto error;
        }
    }

    /* Create and collect result */
    result = (Fast_Storage)Fast_Object__create(observer);
    Fast_Parser_collect(_this, result);

    return result;
error:
    fast_err;
    return NULL;
}

/* Declare a delegate type */
Fast_Storage Fast_Parser_declareDelegate(Fast_Parser _this, cx_type returnType, cx_string id, cx_bool returnsReference) {
    cx_delegate delegate;
    cx_parameterSeq parameters;
    cx_id name;

    /* Translate from name to arguments */
    parameters = cx_function_stringToParameterSeq(id, _this->scope);

    /* Obtain name */
    cx_signatureName(id, name);

    /* Declare and define delegate */
    delegate = cx_delegate__declareChild(_this->scope, name);
    if(!delegate) {
        goto error;
    }

    if(cx_delegate__define(delegate, cx_type(returnType), returnsReference, parameters)) {
        goto error;
    }

    return Fast_Storage(Fast_Object__create(delegate));
error:
    return NULL;
}

/* $end */

/* ::corto::Fast::Parser::addStatement(Fast::Node statement) */
cx_void _Fast_Parser_addStatement(Fast_Parser _this, Fast_Node statement) {
/* $begin(::corto::Fast::Parser::addStatement) */
    Fast_CHECK_ERRSET(_this);

    /* Process staged declarations that do not have initializers (for example, enum Color:: RED, YELLOW, GREEN, BLUE;) */
    if (!_this->pass && !statement) {
        if (_this->stagingAllowed) {
            Fast_Parser_initDeclareStaged(_this, NULL);
        }
    }

    /* If this is the first pass and a comma expression is encountered, report error. Comma expressions
     * shouldn't be used by themselves. */
    if (!_this->pass && statement) {
        if (statement->kind == Fast_CommaExpr) {
            Fast_Parser_error(_this, "invalid usage of comma expression");
            goto error;
        }
    /* If a comma expression is encountered in the second pass it could be the result of an expanded
     * comma expression. Only add if the expression has side effects. If it doesn't have side effects
     * it is likely the result of a staged declaration */
    } else if (_this->pass && statement &&
              (statement->kind == Fast_CommaExpr) &&
              (!Fast_Expression_hasSideEffects(Fast_Expression(statement)))) {
        return;
    }

    if (statement) {
        if (_this->block && (Fast_Node(_this->block->_while) != statement)) {
            if (_this->block->_while) {
                Fast_Parser_error(_this, "invalid statement after while");
                goto error;
            }
            if (!((statement->kind == Fast_LiteralExpr) && (Fast_Literal(statement)->kind == Fast_Text))) {
                Fast_Block_addStatement(_this->block, statement);
                if (cx_instanceof(cx_type(Fast_Expression_o), statement)) {
                    if (!Fast_Expression_hasSideEffects(Fast_Expression(statement))) {
                        /* TODO: Fast_Parser_warning(_this, "computed value is not used (%s)", cx_nameof(cx_typeof(statement))); */
                    }
                }
            } else if (_this->pass) {
                /* If statement is a string, insert println function */
                if (!_this->repl) {
                    Fast_Expression println = Fast_Parser_lookup(_this, "io::println(string)");
                    Fast_Comma args = Fast_Comma__create();
                    Fast_Comma_addExpression(args, Fast_Expression(statement));
                    Fast_Expression callExpr = Fast_Parser_callExpr(_this, println, Fast_Expression(args));
                    Fast_Block_addStatement(_this->block, Fast_Node(callExpr));
                    Fast_Parser_collect(_this, args);
                } else {
                    Fast_Block_addStatement(_this->block, statement);
                }
            }
        }
    }

    return;
error:
    fast_err;
/* $end */
}

/* ::corto::Fast::Parser::argumentToString(type type,string id,bool reference) */
cx_string _Fast_Parser_argumentToString(Fast_Parser _this, cx_type type, cx_string id, cx_bool reference) {
/* $begin(::corto::Fast::Parser::argumentToString) */
    cx_string str;
    cx_string result;
    Fast_CHECK_ERRSET(_this);

    /* 1st pass & 2nd pass are equal */
    if (!type) {
        if (_this->lastFailedResolve) {
            Fast_Parser_error(_this, "unresolved type '%s'", _this->lastFailedResolve);
        } else {
            /* Cause is most likely an already reported error */
        }
        goto error;
    }

    if (!cx_class_instanceof(cx_type_o, type)) {
        cx_id id;
        Fast_Parser_error(_this, "object '%s' used in parameter expression is not a type", Fast_Parser_id(type, id));
        goto error;
    }

    if (cx_checkAttr(type, CX_ATTR_SCOPED)) {
        cx_id id;
        if ((cx_parentof(type) == corto_o) || (cx_parentof(type) == corto_lang_o)) {
            str = strdup(cx_nameof(type));
        } else {
            str = strdup(Fast_Parser_id(type, id));
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

/* ::corto::Fast::Parser::binaryExpr(Fast::Expression lvalues,Fast::Expression rvalues,operatorKind operator) */
Fast_Node _Fast_Parser_binaryExpr(Fast_Parser _this, Fast_Expression lvalues, Fast_Expression rvalues, cx_operatorKind operator) {
/* $begin(::corto::Fast::Parser::binaryExpr) */
    Fast_Node result = NULL;
    Fast_CHECK_ERRSET(_this);

    _this->stagingAllowed = FALSE;

    if (lvalues && rvalues && (_this->pass || ((_this->initializerCount >= 0) && _this->initializers[_this->initializerCount]))) {
        Fast_ExpandAction combine = Fast_Parser_combineComma;

        switch(operator) {
        case CX_ASSIGN_UPDATE: {
            cx_ll exprList = Fast_Expression_toList(lvalues);

            /* Begin update (lock objects) */
            result = Fast_Node(Fast_Update__create(exprList, NULL, NULL, Fast_UpdateBegin));
            if (!result) {
                goto error;
            }
            Fast_Parser_addStatement(_this, Fast_Node(result));
            Fast_Parser_collect(_this, result);

            /* Insert assignment */
            if (!(result = Fast_Parser_binaryExpr(_this, lvalues, rvalues, CX_ASSIGN))) {
                goto error;
            }
            Fast_Parser_addStatement(_this, Fast_Node(result));

            /* End expression (update in reverse order) */
            result = Fast_Node(Fast_Update__create(exprList, NULL, NULL, Fast_UpdateEnd));
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
            combine = Fast_Parser_combineConditionalExpr;
        /* fallthrough */
        default:
            if (!(result = Fast_Node(
                Fast_Parser_expandComma(_this, lvalues, rvalues, Fast_Parser_expandBinary, combine, &operator)))) {
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

/* ::corto::Fast::Parser::bind(Fast::Storage function,Fast::Block block) */
cx_int16 _Fast_Parser_bind(Fast_Parser _this, Fast_Storage function, Fast_Block block) {
/* $begin(::corto::Fast::Parser::bind) */
    Fast_Binding *binding;
    Fast_CHECK_ERRSET(_this);

    if (_this->pass && function) {
        if (function->kind == Fast_ObjectStorage) {
            binding = cx_calloc(sizeof(Fast_Binding));
            cx_setref(&binding->function, Fast_Object(function)->value);
            cx_setref(&binding->impl, block);
            cx_assert(_this->bindings != NULL, "initialization failed");
            cx_llAppend(_this->bindings, binding);
        }
    }

    return 0;
/* $end */
}

/* ::corto::Fast::Parser::bindOneliner(Fast::Storage function,Fast::Block block,Fast::Expression expr) */
cx_int16 _Fast_Parser_bindOneliner(Fast_Parser _this, Fast_Storage function, Fast_Block block, Fast_Expression expr) {
/* $begin(::corto::Fast::Parser::bindOneliner) */
    Fast_CHECK_ERRSET(_this);

    if (_this->pass) {
        Fast_Expression returnLocal;
        cx_id functionName;

        /* Add oneliner to block */
        cx_signatureName(cx_nameof(Fast_Object(function)->value), functionName);
        returnLocal = Fast_Block_lookup(block, functionName);
         if (returnLocal) {
            Fast_Expression returnAssign;

            /* In one-liners, a reference returnvalue is always addressed by reference */
            if (!Fast_Expression(returnLocal)->type->reference && Fast_Expression(returnLocal)->isReference) {
                returnLocal = Fast_Parser_unaryExpr(_this, returnLocal, CX_AND);
            }

            returnAssign = Fast_Expression(Fast_Parser_binaryExpr(_this, returnLocal, expr, CX_ASSIGN));
            if (returnAssign) {
                Fast_Block_addStatement(block, Fast_Node(returnAssign));
            } else {
                goto error;
            }
        } else {
            Fast_Parser_error(_this, "invalid assignment to function with no returntype");
            goto error;
        }

        /* Bind function */
        Fast_Parser_bind(_this, function, block);
    }

    return 0;
error:
    fast_err;
    return -1;
/* $end */
}

/* ::corto::Fast::Parser::blockPop() */
cx_void _Fast_Parser_blockPop(Fast_Parser _this) {
/* $begin(::corto::Fast::Parser::blockPop) */
    Fast_CHECK_ERRSET(_this);

    _this->blockCount--;

    /* Blocks are parsed only in 2nd pass */
    if (_this->pass) {
        if (_this->block) {
            cx_setref(&_this->block, _this->block->parent);
        } else {
            /* Got confused by earlier errors */
            Fast_Parser_error(_this, "unable to continue parsing due to previous errors");
            _this->abort = TRUE;
        }
    }
    _this->blockPreset = FALSE;

/* $end */
}

/* ::corto::Fast::Parser::blockPush(bool presetBlock) */
Fast_Block _Fast_Parser_blockPush(Fast_Parser _this, cx_bool presetBlock) {
/* $begin(::corto::Fast::Parser::blockPush) */
    Fast_CHECK_ERRSET(_this);

    if (!_this->blockPreset || presetBlock) {
        _this->blockCount++;
    }

    /* Blocks are parsed only in 2nd pass */
    if (_this->pass) {
        Fast_Block newBlock;

        newBlock = NULL;

        if (!_this->blockPreset || presetBlock) {
            newBlock = Fast_Block__create(_this->block);
            Fast_Parser_collect(_this, newBlock);
            cx_setref(&_this->block, newBlock);
        }

        _this->blockPreset = presetBlock;
        return newBlock;
    } else {
        _this->blockPreset = presetBlock;
        return NULL;
    }
/* $end */
}

/* ::corto::Fast::Parser::callExpr(Fast::Expression function,Fast::Expression arguments) */
Fast_Expression _Fast_Parser_callExpr(Fast_Parser _this, Fast_Expression function, Fast_Expression arguments) {
/* $begin(::corto::Fast::Parser::callExpr) */
    Fast_Expression result = NULL;

    _this->stagingAllowed = FALSE;

    if (function && _this->pass) {
        cx_object o = NULL;
        Fast_Expression_list functions = function ? Fast_Expression_toList(function) : NULL;
        Fast_Expression_list args = arguments ? Fast_Expression_toList(arguments) : NULL;

        if (functions) {Fast_Expression_list__foreach(functions, f)
            Fast_Expression expr;
            if ((Fast_Node(f)->kind == Fast_StorageExpr) && (Fast_Storage(f)->kind == Fast_ObjectStorage)) {
                o = Fast_Object(f)->value;
            }
            /* If function is a type, insert cast */
            if (o && cx_instanceof(cx_type(cx_type_o), o)) {
                cx_ll exprs = Fast_Expression_toList(arguments);
                if (cx_llSize(exprs) != 1) {
                    Fast_Parser_error(_this, "invalid number of parameters for cast (expected 1)");
                    Fast_Expression_cleanList(exprs);
                    goto error;
                }
                expr = Fast_Parser_castExpr(_this, o, cx_llGet(exprs, 0));
                Fast_Expression_cleanList(exprs);
                Fast_Parser_collect(_this, expr);
            } else {
                expr = Fast_Expression(Fast_createCallFromExpr(f, arguments));
            }
            if (!expr) {
                goto error;
            }
            result = Fast_Comma_addOrCreate(result, expr);
        }}

        /* Cleanup initializer arguments */
        if (args) {Fast_Expression_list__foreach(args, a)
            if (Fast_Node(a)->kind == Fast_InitializerExpr) {
                Fast_Expression var = Fast_Initializer(a)->variables[0].object;
                if (Fast_Storage(var)->kind == Fast_TemporaryStorage) {
                    Fast_Deinit deinit = Fast_Deinit__create(Fast_Storage(var));
                    result = Fast_Comma_addOrCreate(result, Fast_Expression(deinit));
                    Fast_Parser_collect(_this, deinit);
                }
            }
        }}
        
        Fast_Expression_cleanList(functions);
        Fast_Expression_cleanList(args);
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::Fast::Parser::castExpr(type lvalue,Fast::Expression rvalue) */
Fast_Expression _Fast_Parser_castExpr(Fast_Parser _this, cx_type lvalue, Fast_Expression rvalue) {
/* $begin(::corto::Fast::Parser::castExpr) */
    Fast_Expression result = NULL;

    _this->stagingAllowed = FALSE;

    if (_this->pass) {
        cx_type rvalueType;
        cx_bool castRequired = TRUE;

        rvalueType = Fast_Expression_getType(rvalue);

        if (lvalue == rvalueType) {
            cx_id id;
            Fast_Parser_warning(_this, "casting to value of the same type (%s)", Fast_Parser_id(lvalue, id));
            castRequired = FALSE;
        } else {
            if ((lvalue->kind == CX_COMPOSITE) && (rvalueType->kind == CX_COMPOSITE)) {
                if (cx_type_castable(lvalue, rvalueType)) {
                    cx_id id1, id2;
                    castRequired = FALSE;
                    Fast_Parser_warning(_this, "upcasting from '%s' to '%s' does not require an explicit cast",
                            Fast_Parser_id(rvalueType, id1), Fast_Parser_id(lvalue, id2));
                }
            } else if (Fast_Node(rvalue)->kind == Fast_LiteralExpr) {
                result = Fast_Expression_cast(rvalue, lvalue, FALSE);
                castRequired = FALSE;
            }
        }

        if (castRequired) {
            result = Fast_Expression(Fast_Cast__create(lvalue, rvalue, FALSE));
            if (!result) {
                goto error;
            }
            Fast_Parser_collect(_this, result);
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

/* ::corto::Fast::Parser::collect(object o) */
cx_void _Fast_Parser_collect(Fast_Parser _this, cx_object o) {
/* $begin(::corto::Fast::Parser::collect) */
    /* 1st pass & 2nd pass are equal */

    cx_assert(_this->collected != NULL, "initialization failed");
    cx_llInsert(_this->collected, o);

/* $end */
}

/* ::corto::Fast::Parser::collectHeap(word addr) */
cx_void _Fast_Parser_collectHeap(Fast_Parser _this, cx_word addr) {
/* $begin(::corto::Fast::Parser::collectHeap) */
    Fast_CHECK_ERRSET(_this);

    /* 1st pass & 2nd pass are equal */
    cx_assert(_this->heapCollected != NULL, "initialization failed");
    cx_llInsert(_this->heapCollected, (void*)addr);

/* $end */
}

/* ::corto::Fast::Parser::construct() */
cx_int16 _Fast_Parser_construct(Fast_Parser _this) {
/* $begin(::corto::Fast::Parser::construct) */
    CX_UNUSED(_this);
    Fast_Parser_reset(_this);
    cx_threadTlsSet(Fast_PARSER_KEY, _this);
    return 0;
/* $end */
}

/* ::corto::Fast::Parser::declaration(type type,string id,bool isReference) */
Fast_Storage _Fast_Parser_declaration(Fast_Parser _this, cx_type type, cx_string id, cx_bool isReference) {
/* $begin(::corto::Fast::Parser::declaration) */
    Fast_Storage result = NULL;
    Fast_CHECK_ERRSET(_this);

    if (!_this->block) {
        goto error;
    }

    _this->stagingAllowed = FALSE;

    /* If block is not root or local-keyword is used, declare local */
    if (_this->blockCount || _this->isLocal) {
        if (_this->pass) {
            if (!type) {
                if (_this->lastFailedResolve) {
                    Fast_Parser_error(_this, "unresolved type '%s'", _this->lastFailedResolve);
                    goto error;
                } else {
                    cx_assert(type != NULL, "no type provided for declaration");
                }
            }
            cx_assert(_this->block != NULL, "no valid code-block set in parser context.");

            /* If the variable is declared in the global scope, verify that its name doesn't clash with an object */
            if (!_this->block->parent) {
                cx_object o;
                if ((o = cx_resolve(_this->scope, id))) {
                    Fast_Parser_error(_this, "object '%s' is redeclared as a variable", id);
                    cx_release(o);
                    goto error;
                }
            }

            /* Redundant reference specifier if the type is also a reference */
            if (type->reference && isReference) {
                cx_id id;
                Fast_Parser_error(yparser(), "redundant '&' in declaration of '%s', type '%s' is already a reference type",
                    id, Fast_Parser_id(type, id));
                goto error;
            }

            result = Fast_Storage(Fast_Block_declare(_this->block, id, type, FALSE, isReference));
            _this->variables[_this->variableCount] = result;
            _this->variableCount++;
        } else {
            /* Variables are declared in 2nd pass */
            _this->variables[_this->variableCount] = NULL;
            _this->variableCount++;
        }
    } else {
        cx_object o;
        if (!type) {
            if (_this->lastFailedResolve) {
                Fast_Parser_error(_this, "unresolved type '%s'", _this->lastFailedResolve);
                goto error;
            } else {
                cx_assert(type != NULL, "no type provided for declaration");
            }
        }
        cx_assert(_this->block != NULL, "no valid code-block set in parser context.");

        if (!_this->pass) {
            o = cx_declareChild(_this->scope, id, type);
            if (!o) {
                cx_id id1;
                Fast_Parser_error(_this, "declare of '%s' of type '%s' failed",
                        id,
                        Fast_Parser_id(type, id1));
                goto error;
            }
        } else {
            o = cx_lookup(_this->scope, id);
            cx_assert(o != NULL, "object disappeared in 2nd pass");
            cx_release(o);
        }
        if (o) {
            result = Fast_Storage(Fast_Object__create(o));
            Fast_Parser_collect(_this, result);
            _this->variables[_this->variableCount] = result;
            _this->variableCount++;
        }
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::Fast::Parser::declareFunction(type returnType,string id,type kind,bool returnsReference) */
Fast_Storage _Fast_Parser_declareFunction(Fast_Parser _this, cx_type returnType, cx_string id, cx_type kind, cx_bool returnsReference) {
/* $begin(::corto::Fast::Parser::declareFunction) */
    cx_function function;
    cx_object o;
    cx_type functionType = cx_type(kind);
    Fast_Storage result = NULL;
    cx_int32 distance;
    Fast_CHECK_ERRSET(_this);

    if (!_this->pass) {
        cx_id functionName;

        if (!returnType) {
            if (_this->lastFailedResolve) {
                Fast_Parser_error(_this, "unresolved type '%s'", _this->lastFailedResolve);
                goto error;
            } else {
                cx_assert(returnType != NULL, "no type provided for declaration");
            }
        }

        /* Obtain name of function */
        cx_signatureName(id, functionName);

        /* Resolve identifier first to verify whether it is not already in use as non-function object */
        if ((o = cx_lookup(_this->scope, functionName))) {
            if (!cx_instanceof(cx_type(cx_function_o), o)) {
                cx_id id2;
                // todo changed here
                Fast_Parser_error(_this, "cannot redeclare '%s' of type '%s' as function",
                    id, Fast_Parser_id(cx_typeof(o), id2));
                goto error;
            }
            cx_release(o);
        }

        /* This could be an implementation after a forward declaration so try to resolve
         * function first. */
        if (!((function = cx_lookupFunction(_this->scope, id, &distance)) && !distance)) {
            if (!functionType) {
                if (cx_class_instanceof(cx_interface_o, _this->scope)) {
                    functionType = cx_type(cx_method_o);
                } else {
                    functionType = cx_type(cx_function_o);
                }
            } else {
                /* Check whether declaration is a delegate */
                if(cx_interface_baseof(cx_interface(kind), cx_interface(cx_delegate_o))) {
                    result = Fast_Parser_declareDelegate(
                        _this,
                        returnType,
                        id,
                        returnsReference);
                }
            }

            if (!result) {
                if (!cx_class_instanceof(cx_type_o, returnType)) {
                    cx_id id;
                    Fast_Parser_error(_this, "object '%s' specified as returntype is not a type.", Fast_Parser_id(returnType, id));
                    goto error;
                }

                function = cx_declareChild(_this->scope, id, functionType);
                if (!function) {
                    Fast_Parser_error(_this, "declare of '%s' failed",
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
            result = Fast_Storage(Fast_Object__create(function));
            Fast_Parser_collect(_this, result);
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

            cx_object function = cx_resolve(_this->scope, query);
            cx_assert(function != NULL, "object should still be there in 2nd pass");

            result = Fast_Storage(Fast_Object__create(function));
            Fast_Parser_collect(_this, result);
            cx_release(function);
        }
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::Fast::Parser::declareFunctionParams(Storage function) */
Fast_Block _Fast_Parser_declareFunctionParams(Fast_Parser _this, Fast_Storage function) {
/* $begin(::corto::Fast::Parser::declareFunctionParams) */
    cx_function function_o;
    cx_parameter *param;
    Fast_Block result = NULL;
    unsigned int i;
    Fast_CHECK_ERRSET(_this);

    if (_this->pass && function) {
        result = Fast_Parser_blockPush(_this, TRUE);

        function_o = Fast_Object(function)->value;
        Fast_Block_setFunction(result, function_o);

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
                Fast_Parser_error(_this, "parent of '%s' is not an interface nor of an interface type",
                    Fast_Parser_id(function_o, id));
                goto error;
            }

            Fast_Block_declare(result, "this", parent, TRUE, FALSE);

            /* If this-type of method has a base, include super */
            if (cx_interface(parent)->base) {
                Fast_Block_declare(result, "super", cx_type(cx_interface(parent)->base), TRUE, FALSE);
            }
        }

        for(i=0; i<function_o->parameters.length; i++) {
            param = &function_o->parameters.buffer[i];
            Fast_Block_declare(result, param->name, param->type, TRUE, param->passByReference);
        }

        /* If function has a returntype, include name of function */
        if (function_o->returnType && ((function_o->returnType->kind != CX_VOID) || function_o->returnType->reference)) {
            Fast_Block_declareReturnVariable(result, function_o);
        }
    }

    return result;
error:
    return NULL;
/* $end */
}

/* ::corto::Fast::Parser::define() */
cx_int16 _Fast_Parser_define(Fast_Parser _this) {
/* $begin(::corto::Fast::Parser::define) */
    Fast_CHECK_ERRSET(_this);

    if ((_this->initializerCount >= 0) && _this->initializers[_this->initializerCount]) {
        if (Fast_Initializer_define(_this->initializers[_this->initializerCount])) {
            goto error;
        }
        cx_setref(&_this->initializers[_this->initializerCount], NULL);
        _this->initializerCount--;
    }

    return 0;
error:
    fast_err;
    return -1;
/* $end */
}

/* ::corto::Fast::Parser::defineScope() */
cx_int16 _Fast_Parser_defineScope(Fast_Parser _this) {
/* $begin(::corto::Fast::Parser::defineScope) */
    Fast_CHECK_ERRSET(_this);

    if (!_this->pass) {
        if (!_this->scope) {
            Fast_Parser_error(_this, "invalid scope expression");
            goto error;
        }

        if (cx_instanceof(cx_type(cx_type_o), _this->scope)) {
            if (cx_define(_this->scope)) {
                cx_id id;
                Fast_Parser_error(_this, "failed to define scope '%s'", Fast_Parser_id(_this->scope, id));
                goto error;
            }
        } else {
            Fast_Define defineExpr = Fast_Define__create(Fast_Expression(Fast_Object__create(_this->scope)));
            Fast_Parser_addStatement(_this, Fast_Node(defineExpr));
            Fast_Parser_collect(_this, defineExpr);
        }
    }

    return 0;
error:
    fast_err;
    return -1;
/* $end */
}

/* ::corto::Fast::Parser::defineVariable(Storage object) */
cx_int16 _Fast_Parser_defineVariable(Fast_Parser _this, Fast_Storage object) {
/* $begin(::corto::Fast::Parser::defineVariable) */
    cx_int16 result = 0;
    CX_UNUSED(_this);
    Fast_CHECK_ERRSET(_this);

    if ((Fast_Node(object)->kind == Fast_StorageExpr) && (Fast_Storage(object)->kind == Fast_ObjectStorage)) {
        if (cx_define(Fast_Object(object)->value)) {
            cx_id id1, id2;
            Fast_Parser_error(_this, "define of variable '%s' of type '%s' failed",
                    Fast_Parser_id(Fast_Object(object)->value, id1),
                    Fast_Parser_id(cx_typeof(Fast_Object(object)->value), id2));
            goto error;
        }
    } else {
        Fast_Define defineStmt;
        defineStmt = Fast_Define__create((Fast_Expression)object);
        Fast_Parser_collect(_this, defineStmt);
        Fast_Parser_addStatement(_this, Fast_Node(defineStmt));
    }

    return result;
error:
    fast_err;
    return -1;
/* $end */
}

/* ::corto::Fast::Parser::destruct() */
cx_void _Fast_Parser_destruct(Fast_Parser _this) {
/* $begin(::corto::Fast::Parser::destruct) */
    cx_iter iter;

    if (_this->heapCollected) {
        iter = cx_llIter(_this->heapCollected);
        while(cx_iterHasNext(&iter)) {
            cx_dealloc(cx_iterNext(&iter));
        }
        cx_llFree(_this->heapCollected);
    }

    _this->heapCollected = NULL;
    cx_setref(&_this->scope, NULL);

    memset(_this->variables, 0, sizeof(_this->variables));
/* $end */
}

/* ::corto::Fast::Parser::elementExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
Fast_Expression _Fast_Parser_elementExpr(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue) {
/* $begin(::corto::Fast::Parser::elementExpr) */
    Fast_Expression result = NULL;

    /* Expand element expression with comma-expressions */
    if (_this->pass) {
        cx_type t = Fast_Expression_getType(lvalue);
        /* If the left value is a composite type then translate element expression to members */
        if (t) {
            if (t->kind == CX_COMPOSITE) {
                if (!(result = Fast_Parser_explodeComma(_this, lvalue, rvalue, Fast_Parser_expandMember, NULL))) {
                    goto error;
                }
            } else {
                if (!(result = Fast_Parser_explodeComma(_this, lvalue, rvalue, Fast_Parser_expandElement, NULL))) {
                    goto error;
                }
            }
        } else {
            Fast_Parser_error(_this, "cannot resolve element, left-hand of expression has no type");
            goto error;
        }
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::Fast::Parser::finalize(ic::program program) */
cx_int16 _Fast_Parser_finalize(Fast_Parser _this, ic_program program) {
/* $begin(::corto::Fast::Parser::finalize) */
    ic_scope scope = NULL;
    ic_storage returnValue = NULL;
    Fast_Binding *binding;
    cx_iter bindingIter;

    /* Parse functions */
    if (_this->bindings) {
        bindingIter = cx_llIter(_this->bindings);
        while(cx_iterHasNext(&bindingIter)) {
            ic_op ret;
            binding = cx_iterNext(&bindingIter);
            ic_program_pushFunction(program, binding->function);
            scope = (ic_scope)Fast_Block_toIc(binding->impl, program, NULL, FALSE);
            if (_this->errors) {
                goto error;
            }
            if (binding->function->returnType && ((binding->function->returnType->kind != CX_VOID) || (binding->function->returnType->reference))) {
                cx_id name;
                cx_signatureName(cx_nameof(binding->function), name);
                returnValue = ic_scope_lookupStorage(scope, name, TRUE);
                ret = IC_1_OP(_this->line, ic_ret, returnValue, IC_DEREF_VALUE, FALSE);
                if (binding->function->returnsReference || binding->function->returnType->reference) {
                    ((ic_storage)returnValue)->isReference = TRUE;
                    ((ic_op)ret)->s1Deref = IC_DEREF_ADDRESS;
                }else {
                    ((ic_op)ret)->s1Deref = IC_DEREF_VALUE;
                }
            } else {
                ret = IC_1_OP(_this->line, ic_stop, NULL, IC_DEREF_VALUE, FALSE);
            }

            ic_scope_add(scope, ic_node(ret));
            ic_program_popScope(program);

            cx_release(binding->function);
            cx_release(binding->impl);
            cx_dealloc(binding);
        }
        cx_llFree(_this->bindings);
        _this->bindings = NULL;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::Fast::Parser::foreach(string loopId,Fast::Expression collection) */
cx_int16 _Fast_Parser_foreach(Fast_Parser _this, cx_string loopId, Fast_Expression collection) {
/* $begin(::corto::Fast::Parser::foreach) */
    CX_UNUSED(_this);
    CX_UNUSED(loopId);
    CX_UNUSED(collection);
    return 0;
/* $end */
}

/* ::corto::Fast::Parser::getComplexType() */
cx_type _Fast_Parser_getComplexType(Fast_Parser _this) {
/* $begin(::corto::Fast::Parser::getComplexType) */
    cx_type result = NULL;

    if (_this->complexTypeSp > 0) {
        result = _this->complexType[_this->complexTypeSp-1];
        if (result && (result->kind != CX_COMPOSITE)) {
            result = NULL;
        }
    }

    return result;
/* $end */
}

/* ::corto::Fast::Parser::getLvalue(bool assignment) */
Fast_Expression _Fast_Parser_getLvalue(Fast_Parser _this, cx_bool assignment) {
/* $begin(::corto::Fast::Parser::getLvalue) */
    Fast_Expression result = NULL;

    if (_this->lvalueSp > 0) {
        result = _this->lvalue[_this->lvalueSp-1].expr;
        if (assignment) {
            if (!_this->lvalue[_this->lvalueSp-1].isAssignment) {
                result = NULL;
            }
        }
    }

    return result;
/* $end */
}

/* ::corto::Fast::Parser::getLvalueType(bool assignment) */
cx_type _Fast_Parser_getLvalueType(Fast_Parser _this, cx_bool assignment) {
/* $begin(::corto::Fast::Parser::getLvalueType) */
    cx_type result = NULL;

    /* Check if the parser set an lvalue */
    if ((_this->lvalueSp > 0) && _this->lvalue[_this->lvalueSp-1].expr) {
        result = Fast_Expression_getType(_this->lvalue[_this->lvalueSp-1].expr);
    }

    /* If no lvalue is set, check if there is an active initializer */
    if (!result) {
        if ((_this->initializerCount >= 0) && (_this->initializers[_this->initializerCount])) {
            result = Fast_Initializer_currentType(_this->initializers[_this->initializerCount]);
        }
    }

    if (assignment) {
        if (!_this->lvalue[_this->lvalueSp-1].isAssignment) {
            result = NULL;
        }
    }

    return result;
/* $end */
}

/* ::corto::Fast::Parser::ifStatement(Fast::Expression condition,Fast::Block trueBranch,Fast::If falseBranch) */
Fast_Node _Fast_Parser_ifStatement(Fast_Parser _this, Fast_Expression condition, Fast_Block trueBranch, Fast_If falseBranch) {
/* $begin(::corto::Fast::Parser::ifStatement) */
    Fast_Node result = NULL;

    if (_this->pass) {
        result = Fast_Node(Fast_If__create(condition, trueBranch, falseBranch));
        if (!result) {
            goto error;
        }
        Fast_Parser_collect(_this, result);
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::Fast::Parser::initDeclareStaged(Fast::Expression expr) */
cx_void _Fast_Parser_initDeclareStaged(Fast_Parser _this, Fast_Expression expr) {
/* $begin(::corto::Fast::Parser::initDeclareStaged) */
    cx_uint32 i;

    _this->variableCount = 0;

    if (expr) {
        cx_ll exprList = Fast_Expression_toList(expr);
        cx_iter iter = cx_llIter(exprList);

        if (_this->stagedCount) {
            Fast_Parser_error(_this, "invalid declaration");
            goto error;
        }

        while(cx_iterHasNext(&iter)) {
            _this->variables[_this->variableCount] = cx_iterNext(&iter);
            _this->variableCount++;
        }

        Fast_Expression_cleanList(exprList);
    } else {
        for(i=0; i<_this->stagedCount; i++) {
            if (cx_instanceof(cx_type(cx_type_o), _this->scope)) {
                cx_type defaultType;
                cx_type scopeType = cx_type(_this->scope);
                if (scopeType->defaultType) {
                    defaultType = scopeType->defaultType;
                } else {
                    defaultType = cx_any_o;
                }

                /* Add variable to parser-list for initialization */
                Fast_Parser_declaration(_this, defaultType, _this->staged[i].name, FALSE);

                cx_dealloc(_this->staged[i].name);
                _this->staged[i].name = NULL;
            }
        }
    }

    _this->stagedCount = 0;
    return;
error:
    fast_err;
/* $end */
}

/* ::corto::Fast::Parser::initKeyValuePop() */
cx_int16 _Fast_Parser_initKeyValuePop(Fast_Parser _this) {
/* $begin(::corto::Fast::Parser::initKeyValuePop) */
    if ((_this->initializerCount >= 0) && _this->initializers[_this->initializerCount]) {
        if (Fast_Initializer_popKey(_this->initializers[_this->initializerCount])) {
            goto error;
        }
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::Fast::Parser::initKeyValuePush() */
cx_int16 _Fast_Parser_initKeyValuePush(Fast_Parser _this) {
/* $begin(::corto::Fast::Parser::initKeyValuePush) */
    if ((_this->initializerCount >= 0) && _this->initializers[_this->initializerCount]) {
        if (Fast_Initializer_pushKey(_this->initializers[_this->initializerCount])) {
            goto error;
        }
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::Fast::Parser::initKeyValueSet(Fast::Expression expr) */
cx_int16 _Fast_Parser_initKeyValueSet(Fast_Parser _this, Fast_Expression expr) {
/* $begin(::corto::Fast::Parser::initKeyValueSet) */
    if ((_this->initializerCount >= 0) && _this->initializers[_this->initializerCount]) {
        if (Fast_Initializer_valueKey(_this->initializers[_this->initializerCount], expr)) {
            goto error;
        }
    }

    return 0;
error:
    return -1;

/* $end */
}

/* ::corto::Fast::Parser::initMember(string member) */
cx_int16 _Fast_Parser_initMember(Fast_Parser _this, cx_string member) {
/* $begin(::corto::Fast::Parser::initMember) */
    Fast_CHECK_ERRSET(_this);

    if ((_this->initializerCount >= 0) && _this->initializers[_this->initializerCount]) {
        if (Fast_Initializer_member(_this->initializers[_this->initializerCount], member)) {
            goto error;
        }
    }

    return 0;
error:
    fast_err;
    return -1;
/* $end */
}

/* ::corto::Fast::Parser::initPop() */
cx_int16 _Fast_Parser_initPop(Fast_Parser _this) {
/* $begin(::corto::Fast::Parser::initPop) */
    Fast_CHECK_ERRSET(_this);

    /* Primitive values are not pushed/pop'd */
    if ((_this->initializerCount >= 0) && _this->initializers[_this->initializerCount]) {
        if (Fast_Initializer_pop(_this->initializers[_this->initializerCount])) {
            goto error;
        }
    }

    return 0;
error:
    fast_err;
    return -1;
/* $end */
}

/* ::corto::Fast::Parser::initPush() */
cx_int16 _Fast_Parser_initPush(Fast_Parser _this) {
/* $begin(::corto::Fast::Parser::initPush) */
    Fast_CHECK_ERRSET(_this);

    if (!_this->variablePushed) {
        if ((_this->initializerCount>=0) && _this->initializers[_this->initializerCount]) {
            if (Fast_Initializer_push(_this->initializers[_this->initializerCount])) {
                Fast_Parser_error(_this, "invalid initializer scope");
                goto error;
            }
        }
    } else {
        _this->variablePushed = FALSE;
    }

    return 0;
error:
    fast_err;
    return -1;
/* $end */
}

/* ::corto::Fast::Parser::initPushExpression() */
Fast_Expression _Fast_Parser_initPushExpression(Fast_Parser _this) {
/* $begin(::corto::Fast::Parser::initPushExpression) */
    Fast_Initializer initializer = NULL;

    _this->initializerCount++;

    if (_this->pass) {
        Fast_InitializerVariable_array64 variables;

        memset(variables, 0, sizeof(variables));

        /* Create initializer */
        initializer = Fast_Initializer(Fast_InitializerExpression__create(variables, 1, TRUE));
        cx_setref(&_this->initializers[_this->initializerCount], initializer);
        Fast_Parser_collect(_this, initializer);
        _this->variablePushed = TRUE;
    }

    return Fast_Expression(initializer);
/* $end */
}

/* ::corto::Fast::Parser::initPushIdentifier(Expression type) */
Fast_Expression _Fast_Parser_initPushIdentifier(Fast_Parser _this, Fast_Expression type) {
/* $begin(::corto::Fast::Parser::initPushIdentifier) */
    cx_object o;
    cx_type t;
    cx_bool isDynamic = TRUE;
    cx_bool forceStatic = FALSE;
    Fast_InitializerVariable_array64 variables;
    memset(variables, 0, sizeof(variables));

    CX_UNUSED(_this);
    CX_UNUSED(type);

    if (!type) {
        if (_this->lastFailedResolve) {
            Fast_Parser_error(_this, "unresolved identifier '%s'", _this->lastFailedResolve);
            goto error;
        } else {
            Fast_Parser_error(_this, "invalid expression");
            goto error;
        }
    }

    o = cx_type(Fast_Object(type)->value);
    if (!cx_instanceof(cx_type(cx_type_o), o)) {
        cx_id id;
        Fast_Parser_error(_this, "invalid expression, '%s' is not a type", Fast_Parser_id(o, id));
        goto error;
    }

    t = o;

    if (_this->initializerCount >= 0) {
        Fast_Initializer initializer = _this->initializers[_this->initializerCount];
        if (initializer) {
            if (!cx_instanceof(cx_type(Fast_DynamicInitializer_o), initializer) &&
                !cx_instanceof(cx_type(Fast_InitializerExpression_o), initializer)) {
                isDynamic = FALSE; /* A previous initializer is static, so this initializer will be static as well */
            }
        } else if (_this->pass) {
            isDynamic = FALSE; /* If initializer is NULL and parser is in second pass initializer must be static */
        }
    }

    _this->initializerCount++;

    /* The first pass will always create a static initializer when t is a type. This is required for declarations with anonymous
     * types. The parser can't determine upfront whether an anonymous object will be used in a declaration so this is determined
     * afterwards. */
    if (cx_instanceof(cx_type(cx_interface_o), t) && cx_interface_baseof(cx_interface(t), cx_interface(cx_type_o))) {
        forceStatic = TRUE;
    }

    /* Static initializers are executed during first pass */
    if ((!_this->pass && !isDynamic) || forceStatic) {
        cx_object o;
        o = cx_declare(t);
        cx_setref(&variables[0].object, Fast_Expression(Fast_Object__create(o)));
        _this->initializers[_this->initializerCount] = Fast_Initializer(Fast_StaticInitializer__create(variables, 1));
        _this->variablePushed = TRUE;
    } else if (_this->pass && isDynamic && !forceStatic) {
        Fast_Expression newExpr, assignExpr, var, refVar;
        cx_type type_o = cx_type(Fast_Object(type)->value);
        refVar = var = Fast_Expression(Fast_Temporary__create(Fast_Object(type)->value, TRUE));
        newExpr = Fast_Expression(Fast_New__create(Fast_Object(type)->value,0));
        Fast_Parser_collect(_this, newExpr);
        if (!type_o->reference) {
            refVar = Fast_Parser_unaryExpr(_this, var, CX_AND);
            Fast_Parser_collect(yparser(), refVar);
        }
        assignExpr = Fast_Expression(Fast_Binary__create(refVar, newExpr, CX_ASSIGN));
        Fast_Parser_collect(_this, assignExpr);
        Fast_Parser_addStatement(_this, Fast_Node(assignExpr));

        cx_setref(&variables[0].object, var);
        _this->initializers[_this->initializerCount] = Fast_Initializer(Fast_DynamicInitializer__create(variables, 1, FALSE));
        _this->variablePushed = TRUE;
    } else {
        cx_setref(&_this->initializers[_this->initializerCount], NULL);
        _this->variablePushed = TRUE;
    }

    return variables[0].object;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::Fast::Parser::initPushStatic() */
cx_int16 _Fast_Parser_initPushStatic(Fast_Parser _this) {
/* $begin(::corto::Fast::Parser::initPushStatic) */
    cx_bool isLocal = _this->isLocal;
    Fast_InitializerVariable_array64 variables;
    Fast_Initializer initializer;
    cx_uint32 i;

    _this->initializerCount++;

    if (!isLocal && _this->variableCount) {
        if (Fast_Storage(_this->variables[0])->kind != Fast_ObjectStorage) {
            isLocal = TRUE;
        }
    }

    /* Initializers are invalid for local variables - use assignments for these. */
    if (isLocal) {
        Fast_Parser_error(_this, "usage of initializer invalid for local variables (use assignment instead)");
        goto error;
    }

    if (!_this->variableCount) {
        Fast_Parser_error(_this, "invalid initializer");
        goto error;
    }

    memset(variables, 0, sizeof(variables));

    /* Copy variables from parser to initializer structure */
    for(i=0; i<_this->variableCount; i++) {
        cx_setref(&variables[i].object, Fast_Expression(_this->variables[i]));
        variables[i].key = 0;
        variables[i].offset = 0;
    }

    if (!_this->pass) {
        /* Create initializer */
        initializer = Fast_Initializer(Fast_StaticInitializer__create(variables, _this->variableCount));
        cx_setref(&_this->initializers[_this->initializerCount], initializer);
        Fast_Parser_collect(_this, initializer);
    } else {
        /* Create dummy initializer */
        initializer = Fast_Initializer__create(variables, _this->variableCount);
        cx_setref(&_this->initializers[_this->initializerCount], initializer);
        Fast_Parser_collect(_this, initializer);
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::Fast::Parser::initStage(string id,bool found) */
cx_void _Fast_Parser_initStage(Fast_Parser _this, cx_string id, cx_bool found) {
/* $begin(::corto::Fast::Parser::initStage) */

    _this->staged[_this->stagedCount].name = cx_strdup(id);
    _this->staged[_this->stagedCount].line = _this->line;
    _this->staged[_this->stagedCount].column = _this->column;
    _this->staged[_this->stagedCount].found = found;
    _this->stagedCount++;

/* $end */
}

/* ::corto::Fast::Parser::initValue(Expression expr) */
cx_int16 _Fast_Parser_initValue(Fast_Parser _this, Fast_Expression expr) {
/* $begin(::corto::Fast::Parser::initValue) */
    Fast_CHECK_ERRSET(_this);

    if ((_this->initializerCount >= 0) && _this->initializers[_this->initializerCount]) {
        if (Fast_Initializer_value(_this->initializers[_this->initializerCount], expr)) {
            goto error;
        }
    }

    return 0;
error:
    fast_err;
    return -1;

/* $end */
}

/* ::corto::Fast::Parser::isAbortSet() */
cx_bool _Fast_Parser_isAbortSet(Fast_Parser _this) {
/* $begin(::corto::Fast::Parser::isAbortSet) */
    cx_bool result = _this->abort;
    _this->abort = FALSE;
    return result;
/* $end */
}

/* ::corto::Fast::Parser::isErrSet() */
cx_bool _Fast_Parser_isErrSet(Fast_Parser _this) {
/* $begin(::corto::Fast::Parser::isErrSet) */
    cx_bool result = _this->errSet;
    _this->errSet = FALSE;
    return result;
/* $end */
}

/* ::corto::Fast::Parser::lookup(string id) */
Fast_Expression _Fast_Parser_lookup(Fast_Parser _this, cx_string id) {
/* $begin(::corto::Fast::Parser::lookup) */
    Fast_Expression result = NULL;
    Fast_CHECK_ERRSET(_this);

    if (_this->pass) {
        /* If complexType is set, this resolve is ran within a [] expression */
        cx_type complexType = Fast_Parser_getComplexType(_this);
        if (complexType) {
            if (cx_interface_resolveMember(cx_interface(complexType), id)) {
                result = Fast_Expression(Fast_String__create(id));
            }
        }
        if (_this->block && !result) {
            result = Fast_Expression(Fast_Block_resolve(_this->block, id));
        }
    }
    if (!result) {
        result = Fast_Parser_resolve(_this, id);
    }

    /* If either doing a static initializer or parser is
     * doing the 2nd pass all variables should be resolvable */
    if (!result) {
        if (_this->pass ||
            ((_this->initializerCount >= 0) &&
             _this->initializers[_this->initializerCount] &&
            cx_instanceof(cx_type(Fast_StaticInitializer_o), _this->initializers[_this->initializerCount]))) {
            Fast_Parser_error(_this, "unresolved identifier '%s'", id);
            fast_err;
        }

        if (_this->lastFailedResolve) {
            cx_dealloc(_this->lastFailedResolve);
        }
        _this->lastFailedResolve = cx_strdup(id);
    }
    Fast_Parser_initStage(_this, id, result != NULL);

    return result;
/* $end */
}

/* ::corto::Fast::Parser::memberExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
Fast_Expression _Fast_Parser_memberExpr(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue) {
/* $begin(::corto::Fast::Parser::memberExpr) */
    Fast_Expression result = NULL;

    _this->stagingAllowed = FALSE;

    if (_this->pass) {
        cx_type t = Fast_Expression_getType(lvalue);
        if (t) {
            if (!(result = Fast_Parser_explodeComma(_this, lvalue, rvalue, Fast_Parser_expandMember, NULL))) {
                goto error;
            }
        } else {
            Fast_Parser_error(_this, "cannot resolve member, left-hand of expression has no type");
            goto error;
        }
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::Fast::Parser::observerDeclaration(string id,Fast::Expression object,eventMask mask,Fast::Object dispatcher) */
Fast_Storage _Fast_Parser_observerDeclaration(Fast_Parser _this, cx_string id, Fast_Expression object, cx_eventMask mask, Fast_Object dispatcher) {
/* $begin(::corto::Fast::Parser::observerDeclaration) */
    CX_UNUSED(object);
    CX_UNUSED(mask);
    Fast_CHECK_ERRSET(_this);

    _this->stagingAllowed = FALSE;

    Fast_Storage result = NULL;
    cx_bool isTemplate = cx_class_instanceof(cx_type_o, _this->scope);

    if (!(mask & CX_ON_SCOPE)) {
        mask |= CX_ON_SELF;
    }

    /* Observers come in two flavors. The first is the 'ordinary' observer. This observer is created and defined in the 2nd phase. The
     * second flavor is the template observer. This observer is attached to a class and is instantiated for each instance of that class.
     * Because this observer must be bound to the class when the class is defined (or rather: before any objects are created with that
     * class) these observers are created in the first pass and then the implementation is bound to it in the 2nd pass.
     */
    if (!_this->pass) {
        /* If observer is a template observer (it is defined within the scope of a type) create it in the first pass */
        if (isTemplate) {
            result = Fast_Parser_observerCreate(_this, id, object, mask, dispatcher);
            if (!result) {
                Fast_Parser_error(_this, "failed to create template observer");
                goto error;
            }
        }
    } else {
        Fast_Block block;
        cx_observer observer;
        cx_object observable = NULL;
        cx_uint32 i;

        /* Find observable */
        switch(Fast_Storage(object)->kind) {
        case Fast_ObjectStorage:
            observable = Fast_Object(object)->value;
            break;
        case Fast_TemplateStorage:
            /* In case of template ('this') leave observable zero */
            break;
        default:
            break;
        }

        /* Find or create observer depending on whether it is a template observer or not */
        if (isTemplate) {
            block = _this->block; /* If observer is a template the block has already been pushed by Parser::observerPush */
            /* Template observers have been created in the first pass. Look up the created observer */
            observer = cx_class_findObserver(cx_class(_this->scope), observable);
            result = Fast_Storage(Fast_Object__create(observer));
            Fast_Parser_collect(_this, result);
        } else {
            block = Fast_Parser_blockPush(_this, TRUE); /* Push new block on stack */

            /* If observer is not a template it has not yet been created, so create it now */
            result = Fast_Parser_observerCreate(_this, id, object, mask, dispatcher);
            if (!result) {
                Fast_Parser_error(_this, "failed to create observer");
                goto error;
            }
            observer = Fast_Object(result)->value;
        }

        /* Declare this */
        if (!Fast_Block_resolve(block, "this")) {
            Fast_Block_declare(block, "this", cx_object_o, TRUE, FALSE);
        }

        /* Loop parameters of observable, insert locals */
        for(i=0; i<cx_function(observer)->parameters.length; i++) {
            cx_parameter *p = &cx_function(observer)->parameters.buffer[i];
            Fast_Block_declare(block, p->name, p->type, TRUE, TRUE); /* Observable parameter are references */
        }

        /* Bind observer and block */
        Fast_Parser_bind(_this, result, block);
        Fast_Block_setFunction(block, cx_function(observer));
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::Fast::Parser::observerPush() */
cx_void _Fast_Parser_observerPush(Fast_Parser _this) {
/* $begin(::corto::Fast::Parser::observerPush) */
    Fast_CHECK_ERRSET(_this);

    /* Observer-implementations are parsed in the 2nd pass */
    if (_this->pass) {
        if (cx_class_instanceof(cx_type_o, _this->scope)) {
            Fast_Block block;
            block = Fast_Parser_blockPush(_this, TRUE);
            Fast_Block_declareTemplate(block, "this", _this->scope, TRUE, FALSE);
        }
    }

/* $end */
}

/* ::corto::Fast::Parser::parse() */
cx_uint32 _Fast_Parser_parse(Fast_Parser _this) {
/* $begin(::corto::Fast::Parser::parse) */
    Fast_CHECK_ERRSET(_this);

    _this->pass = 0;
    if ( fast_yparse(_this, 1, 1)) {
        cx_print("%s: parsed with errors (%d errors, %d warnings)", _this->filename, _this->errors, _this->warnings);
        goto error;
    }

    /* Reset parser-state so 2nd pass starts clean */
    Fast_Parser_reset(_this);
    cx_setref(&_this->scope, NULL);

    _this->pass = 1;
    if ( fast_yparse(_this, 1, 1)) {
        cx_print("%s: parsed with errors (%d errors, %d warnings)", _this->filename, _this->errors, _this->warnings);
        goto error;
    }

    /* Parse to corto intermediate code */
    if ( Fast_Parser_toIc(_this)) {
        cx_print("%s: parsed with errors (%d errors, %d warnings)", _this->filename, _this->errors, _this->warnings);
        goto error;
    }

    return 0;
error:
    fast_err;
    return -1;
/* $end */
}

/* ::corto::Fast::Parser::parseExpression(string expr,Fast::Block block,object scope,uint32 line,uint32 column) */
Fast_Expression _Fast_Parser_parseExpression(Fast_Parser _this, cx_string expr, Fast_Block block, cx_object scope, cx_uint32 line, cx_uint32 column) {
/* $begin(::corto::Fast::Parser::parseExpression) */
    Fast_Expression result = NULL;
    cx_string exprFinalized;

    CX_UNUSED(scope);

    if (_this->source) {
        cx_dealloc(_this->source);
    }

    exprFinalized = cx_alloc(strlen(expr) + 2);
    sprintf(exprFinalized, "%s\n", expr);

    _this->source = exprFinalized;

    cx_setref(&_this->block, block);
    cx_setref(&_this->scope, scope);

    // Give expression its own block
    Fast_Parser_blockPush(_this, FALSE);
    if (fast_yparse(_this, line, column)) {
        cx_print("%s: expression '%s' parsed with errors", _this->filename, expr);
        Fast_Parser_blockPop(_this);
        goto error;
    }

    /* Extract expression */
    block = _this->block;
    Fast_Parser_blockPop(_this);
    if (block) {
        /* Block should contain exactly one expression */
        if (block->statements) {
            if (cx_llSize(block->statements) == 1) {
                Fast_Node node;
                node = cx_llGet(block->statements, 0);
                if (cx_instanceof(cx_type(Fast_Expression_o), node)) {
                    result = Fast_Expression(node);
                } else {
                    cx_id id;
                    cx_print("%s: '%s' does not resolve to a valid expression (found %s).",
                            _this->filename, expr, Fast_Parser_id(cx_typeof(node), id));
                    goto error;
                }
            } else {
                cx_print("%s: expression '%s' is not allowed to contain multiple statements", _this->filename, expr);
                goto error;
            }
        } else {
            cx_print("%s: expression '%s' did not result in a statement", _this->filename, expr);
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

/* ::corto::Fast::Parser::parseLine(string expr,object scope,word value) */
cx_int16 _Fast_Parser_parseLine(cx_string expr, cx_object scope, cx_word value) {
/* $begin(::corto::Fast::Parser::parseLine) */
    Fast_Parser parser = Fast_Parser__create(expr, NULL);
    ic_program program = ic_program__create(parser->filename);
    Fast_Expression result = NULL; /* Resulting ast-expression of 'exr' */
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
    Fast_Parser_reset(parser);

    parser->pass = 1;
    cx_setref(&parser->scope, scope);
    if (fast_yparse(parser, 1, 1)) {
        goto error;
    }

    /* Find last executed expression */
    if (parser->block) {
        if (cx_llSize(parser->block->statements)) {
            Fast_Node lastNode = cx_llLast(parser->block->statements);

            /* If node is an expression, store expression in variable so it can be resolved later */
            if (cx_instanceof(cx_type(Fast_Expression_o), lastNode) && (lastNode->kind != Fast_CommaExpr)) {
                Fast_Local resultLocal;
                Fast_Binary assignment;
                result = Fast_Expression(lastNode);

                if (result->type) {
                    returnType = cx_type(Fast_Expression_getType(result));
                    if ((returnType->kind != CX_VOID) || (result->deref == Fast_ByReference)) {
                        resultLocal = Fast_Block_declare(parser->block, "<result>", result->type, FALSE,
                            result->isReference);
                        Fast_Expression(resultLocal)->deref = result->isReference ? Fast_ByReference : Fast_ByValue;
                        if (!resultLocal) {
                            goto error;
                        }
                        resultLocal->kind = Fast_LocalReturn;
                        assignment = Fast_Binary__create(Fast_Expression(resultLocal), result, CX_ASSIGN);
                        cx_llReplace(parser->block->statements, lastNode, assignment);
                    }
                } else {
                    Fast_Parser_error(parser, "invalid expression");
                    goto error;
                }
            }
        }
    }

    /* Parse root-block */
    icScope = (ic_scope)Fast_Block_toIc(parser->block, program, NULL, FALSE);
    if (parser->errors) {
        goto error;
    }

    /* Finalize functions */
    if (Fast_Parser_finalize(parser, program)) {
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
            ic_program_run(program, (cx_word)&o);
            if (o) {
                cx_valueObjectInit(v, o, NULL);
            } else {
                v->is.value.storage = 0;
                cx_valueValueInit(v, NULL, cx_object_o, &v->is.value.storage);
            }
        } else {
            if(returnType->kind == CX_PRIMITIVE) {
                cx_valueValueInit(v, NULL, returnType, &v->is.value.storage);
                ic_program_run(program, (cx_word)&v->is.value.storage);
            } else {
                void *ptr = cx_alloc(cx_type_sizeof(returnType));
                ic_program_run(program, (cx_word)&ptr);
                if (ptr) {
                    cx_valueValueInit(v, NULL, returnType, ptr);
                } else {
                    v->is.value.storage = 0;
                    cx_valueValueInit(v, NULL, cx_object_o, &v->is.value.storage);
                }
            }
        }
    } else {
        ic_program_run(program, 0);
        cx_valueValueInit(v, NULL, cx_type(cx_void_o), NULL);
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

/* ::corto::Fast::Parser::popComplexType() */
cx_void _Fast_Parser_popComplexType(Fast_Parser _this) {
/* $begin(::corto::Fast::Parser::popComplexType) */

    _this->complexTypeSp--;
    if (_this->complexTypeSp < 0) {
        Fast_Parser_error(_this, "parser error: complexType stack pointer below zero");
        abort();
    }

/* $end */
}

/* ::corto::Fast::Parser::popLvalue() */
cx_void _Fast_Parser_popLvalue(Fast_Parser _this) {
/* $begin(::corto::Fast::Parser::popLvalue) */

    _this->lvalueSp--;
    if (_this->lvalueSp < 0) {
        Fast_Parser_error(_this, "parser error: lvalue stack pointer below zero");
        abort();
    }

/* $end */
}

/* ::corto::Fast::Parser::popScope(object previous) */
cx_void _Fast_Parser_popScope(Fast_Parser _this, cx_object previous) {
/* $begin(::corto::Fast::Parser::popScope) */
    Fast_CHECK_ERRSET(_this);

    /* Restore scope */
    cx_setref(&_this->scope, previous);
/* $end */
}

/* ::corto::Fast::Parser::postfixExpr(Fast::Expression lvalue,operatorKind operator) */
Fast_Expression _Fast_Parser_postfixExpr(Fast_Parser _this, Fast_Expression lvalue, cx_operatorKind operator) {
/* $begin(::corto::Fast::Parser::postfixExpr) */
    Fast_Expression result = NULL;

    _this->stagingAllowed = FALSE;

    if (_this->pass) {
        result = Fast_Expression(Fast_PostFix__create(lvalue, operator));
        if (!result) {
            goto error;
        }
        Fast_Parser_collect(_this, result);
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::Fast::Parser::pushComplexType(Fast::Expression lvalue) */
cx_void _Fast_Parser_pushComplexType(Fast_Parser _this, Fast_Expression lvalue) {
/* $begin(::corto::Fast::Parser::pushComplexType) */

    if (lvalue) {
        cx_setref(&_this->complexType[_this->complexTypeSp], Fast_Expression_getType(lvalue));
    } else {
        cx_setref(&_this->complexType[_this->complexTypeSp], NULL);
    }
    _this->complexTypeSp++;

/* $end */
}

/* ::corto::Fast::Parser::pushLvalue(Fast::Expression lvalue,bool isAssignment) */
cx_void _Fast_Parser_pushLvalue(Fast_Parser _this, Fast_Expression lvalue, cx_bool isAssignment) {
/* $begin(::corto::Fast::Parser::pushLvalue) */

    cx_setref(&_this->lvalue[_this->lvalueSp].expr, lvalue);
    _this->lvalue[_this->lvalueSp].isAssignment = isAssignment;
    _this->lvalueSp++;

/* $end */
}

/* ::corto::Fast::Parser::pushPackage(string name) */
cx_int16 _Fast_Parser_pushPackage(Fast_Parser _this, cx_string name) {
/* $begin(::corto::Fast::Parser::pushPackage) */
    char ch, *ptr, *bptr;
    cx_id buffer;

    if (_this->scope && (_this->scope != root_o)) {
        Fast_Parser_error(_this, "#package may only be used in the root scope");
        goto error;
    }

    cx_setref(&_this->scope, root_o);
    if (!memcmp(name, "::", 2)) {
        name += 2;
    } else {
        Fast_Parser_error(_this, "packages must be specified using fully qualified names");
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
                cx_object o = cx_resolve(_this->scope, buffer);
                if (!o) {
                    /* Declare package */
                    Fast_Parser_declaration(_this, cx_type(cx_package_o), buffer, FALSE);

                    /* Push package as scope */
                    Fast_Parser_pushScope(_this);

                    /* Define package */
                    Fast_Parser_defineScope(_this);
                } else {
                    cx_setref(&_this->scope, o);
                    cx_release(o);
                }
                bptr = buffer;
            } else {
                Fast_Parser_error(_this, "invalid package name '%s'", name);
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
    Fast_Parser_declaration(_this, cx_type(cx_package_o), buffer, FALSE);

    /* Push package as scope */
    Fast_Parser_pushScope(_this);

    /* Define package */
    Fast_Parser_defineScope(_this);

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::Fast::Parser::pushReturnAsLvalue(function function) */
cx_void _Fast_Parser_pushReturnAsLvalue(Fast_Parser _this, cx_function function) {
/* $begin(::corto::Fast::Parser::pushReturnAsLvalue) */
    Fast_Expression result = NULL;

    if (_this->pass) {
        if (function->returnType) {
            cx_id id;
            cx_signatureName(cx_nameof(function), id);
            result = Fast_Expression(Fast_Block_resolve(_this->block, id));
            if (!result) {
                Fast_Parser_error(_this, "parser error: can't find result variable '%s'", id);
                goto error;
            }
        }
    }

    Fast_Parser_pushLvalue(_this, result, TRUE);

    return;
error:
    fast_err;
/* $end */
}

/* ::corto::Fast::Parser::pushScope() */
cx_object _Fast_Parser_pushScope(Fast_Parser _this) {
/* $begin(::corto::Fast::Parser::pushScope) */
    cx_object oldScope = NULL;

    Fast_CHECK_ERRSET(_this);

    oldScope = _this->scope;
    if (!_this->variableCount) {
        /* This is the result of a previous error */
        goto error;
    }

    if (_this->variables[0]) {
        cx_setref(&_this->scope, Fast_Object(_this->variables[0])->value);
        Fast_Parser_reset(_this);
    } else {
        goto error;
    }

    return oldScope;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::Fast::Parser::reset() */
cx_void _Fast_Parser_reset(Fast_Parser _this) {
/* $begin(::corto::Fast::Parser::reset) */
    cx_uint32 i;

    _this->variableCount = 0;
    _this->variablesInitialized = FALSE;
    _this->isLocal = FALSE;
    _this->lvalueSp = 0;
    _this->complexTypeSp = 0;
    _this->initializerCount = -1;
    _this->stagingAllowed = TRUE;

    if (_this->pass) {
        for(i=0; i<_this->stagedCount; i++) {
            if (!_this->staged[i].found) {
                Fast_Parser_error(_this, "unresolved identifier '%s'", _this->staged[i].name);
                fast_err;
            }
            cx_dealloc(_this->staged[i].name);
            _this->staged[i].name = NULL;
        }
    }
    _this->stagedCount = 0;

/* $end */
}

/* ::corto::Fast::Parser::ternaryExpr(Fast::Expression cond,Fast::Expression iftrue,Fast::Expression iffalse) */
Fast_Expression _Fast_Parser_ternaryExpr(Fast_Parser _this, Fast_Expression cond, Fast_Expression iftrue, Fast_Expression iffalse) {
/* $begin(::corto::Fast::Parser::ternaryExpr) */
    Fast_Expression result = NULL;

    if (_this->pass) {
        Fast_Expression lvalue = Fast_Parser_getLvalue(_this, TRUE);

        if (!lvalue) {
            lvalue = Fast_Expression(Fast_Temporary__create(iftrue->type, FALSE));
        }
        result = Fast_Expression(Fast_Ternary__create(cond, iftrue, iffalse, lvalue));
        if (!result) {
            goto error;
        }
        Fast_Parser_collect(_this, result);
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::Fast::Parser::unaryExpr(Fast::Expression lvalue,operatorKind operator) */
Fast_Expression _Fast_Parser_unaryExpr(Fast_Parser _this, Fast_Expression lvalue, cx_operatorKind operator) {
/* $begin(::corto::Fast::Parser::unaryExpr) */
    Fast_Expression result = NULL;

    _this->stagingAllowed = FALSE;

    if (lvalue) {
        if (operator == CX_SUB) {
            cx_type lvalueType = Fast_Expression_getType(lvalue);

            if (lvalueType->kind == CX_PRIMITIVE) {
                switch(cx_primitive(lvalueType)->kind) {
                case CX_INTEGER:
                    if (Fast_Node(lvalue)->kind == Fast_LiteralExpr) {
                        result = Fast_Expression(Fast_Integer__create(Fast_Integer(lvalue)->value * -1));
                        Fast_Parser_collect(_this, result);
                        break;
                    }
                    /* no break */
                case CX_UINTEGER:
                    if (Fast_Node(lvalue)->kind == Fast_LiteralExpr) {
                        result = Fast_Expression(Fast_SignedInteger__create(Fast_Integer(lvalue)->value * -1));
                        Fast_Parser_collect(_this, result);
                        break;
                    }
                    /* no break */
                case CX_FLOAT:
                    if (Fast_Node(lvalue)->kind == Fast_LiteralExpr) {
                        result = Fast_Expression(Fast_FloatingPoint__create(Fast_FloatingPoint(lvalue)->value * -1));
                        Fast_Parser_collect(_this, result);
                    } else {
                        if (_this->pass) {
                            Fast_SignedInteger minusOne = Fast_SignedInteger__create(-1);
                            Fast_Parser_collect(_this, minusOne);
                            result = Fast_Expression(Fast_Binary__create(lvalue, Fast_Expression(minusOne), CX_MUL));
                            Fast_Parser_collect(_this, result);
                        }
                    }
                    break;
                default: {
                    cx_id id;
                    Fast_Parser_error(_this, "unary operator - not applicable to type '%s'", Fast_Parser_id(lvalueType, id));
                    goto error;
                }
                }
            } else {
                cx_id id;
                Fast_Parser_error(_this, "unary operator - not applicable to non-primitive type '%s'", Fast_Parser_id(lvalueType, id));
                goto error;
            }
        } else if (operator == CX_AND) {
            if (Fast_Node(lvalue)->kind == Fast_StorageExpr) {
                if (lvalue->isReference) {
                    if (cx_copy((cx_object*)&result, lvalue)) {
                        Fast_Parser_error(_this, "parser error: failed to take reference (copy failed)");
                    }
                    result->deref = Fast_ByReference;
                    Fast_Node(result)->line = _this->line;
                    Fast_Node(result)->column = _this->column;

                    /* Ensure that copies of temporaries point to the same storage */
                    if (Fast_Storage(result)->kind == Fast_TemporaryStorage) {
                        Fast_Temporary_setProxy(result, lvalue);
                    }
                } else {
                    Fast_Parser_error(_this, "cannot take reference from non-reference variable");
                    goto error;
                }
            } else {
                lvalue->deref = Fast_ByReference;
                result = lvalue;
            }
        } else {
            if (_this->pass) {
                result = Fast_Expression(Fast_Unary__create(lvalue, operator));
                if (!result) {
                    goto error;
                }
                Fast_Parser_collect(_this, result);
            }
        }
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::Fast::Parser::updateStatement(Fast::Expression expr,Fast::Block block) */
Fast_Node _Fast_Parser_updateStatement(Fast_Parser _this, Fast_Expression expr, Fast_Block block) {
/* $begin(::corto::Fast::Parser::updateStatement) */
    Fast_Node result = NULL;

    _this->stagingAllowed = FALSE;

    if (_this->pass) {
        Fast_Block functionBlock;
        Fast_Expression from = NULL;
        cx_function function;
        cx_procedureKind procedureKind;
        cx_ll exprList;

        if (!expr) { /* Can only happen due to a previous error */
            goto error;
        }

        /* If update is being done from a method or template observer do the update
         * from the corresponding object (set 'from' to this). Search for a function-block */
        functionBlock = _this->block;
        while(functionBlock && !(function = functionBlock->function)) {
            functionBlock = functionBlock->parent;
        }

        if (functionBlock) {
            procedureKind = cx_procedure(cx_typeof(function))->kind;
            if (functionBlock) {
                if ((procedureKind == CX_METHOD) || ((procedureKind == CX_OBSERVER) && cx_observer(function)->template)) {
                    from = Fast_Parser_lookup(_this, "this");
                }
            }
        }

        /* Keep argument expressions */
        exprList = Fast_Expression_toList(expr);
        result = Fast_Node(Fast_Update__create(exprList, block, from, Fast_UpdateDefault));
        Fast_Parser_collect(_this, result);
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::corto::Fast::Parser::waitExpr(Fast::Expression expr,Fast::Expression timeout) */
Fast_Expression _Fast_Parser_waitExpr(Fast_Parser _this, Fast_Expression expr, Fast_Expression timeout) {
/* $begin(::corto::Fast::Parser::waitExpr) */
    Fast_Expression result = NULL;

    _this->stagingAllowed = FALSE;

    if (_this->pass) {
        cx_ll exprList = Fast_Expression_toList(expr);

        result = Fast_Expression(Fast_Wait__create(exprList, timeout));
        Fast_Parser_collect(_this, result);
    }

    return result;
/* $end */
}

/* ::corto::Fast::Parser::whileStatement(Fast::Expression condition,Fast::Block trueBranch,bool isUntil) */
Fast_Node _Fast_Parser_whileStatement(Fast_Parser _this, Fast_Expression condition, Fast_Block trueBranch, cx_bool isUntil) {
/* $begin(::corto::Fast::Parser::whileStatement) */
    Fast_Node result = NULL;

    _this->stagingAllowed = FALSE;

    if (_this->pass) {
        if (isUntil && _this->block->isRoot) {
            Fast_Parser_error(yparser(), "invalid do-while in root block");
            goto error;
        }
        result = Fast_Node(Fast_While__create(condition, trueBranch, isUntil));
        if (!result) {
            goto error;
        }
        Fast_Parser_collect(_this, result);

        if (isUntil) {
            cx_setref(&_this->block->_while, result);
        }
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}
