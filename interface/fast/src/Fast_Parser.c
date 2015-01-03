/* Fast_Parser.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"
#include "Fast__meta.h"

/* $header() */
#define FAST_CHECK_ERRSET(parser) cx_assert(!parser->errSet, "%s:%d:%d: parser did not check error-status set on line %d", _this->filename, _this->line, _this->column, _this->errLine)
/*#define FAST_PARSER_DEBUG*/
#define fast_err _this->errSet = TRUE; _this->errLine = __LINE__;

#include "cx.h"
#include "stdio.h"
#include "Fast__api.h"
#include "Fast__meta.h"
#include "Fast.h"
#include "cx_ll.h"
#include "cx_loader.h"
#include "Fast_Block.h"
#include "Fast_CommaExpr.h"
#include "Fast_Expression.h"
#include "Fast_Initializer.h"
#include "Fast_InitializerExpr.h"
#include "Fast_TernaryExpr.h"
#include "cx__api.h"
#include "cx_string_ser.h"
#include "cx_vm.h"
int fast_yparse(Fast_Parser parser, cx_uint32 line, cx_uint32 column);

void Fast_Parser_error(Fast_Parser _this, char* fmt, ... ) {
    va_list args;
    char msgbuff[1024];
    cx_id token;

    if (_this->token) {
        if (*_this->token == '\n') {
            sprintf(token, "end of line");
        } else {
            sprintf(token, "'%s'", _this->token);
        }
    } else {
        *token = '\0';
    }

    va_start(args, fmt);
    vsprintf(msgbuff, fmt, args);
    va_end(args);

#ifdef FAST_PARSER_DEBUG
    if (_this->initializerCount >= 0) {
        printf("%s:%d:%d (pass=%d, initCount=%d, initializer=%p) error: %s near %s\n",
               _this->filename, _this->line, _this->column,
               _this->pass, _this->initializerCount, _this->initializers[_this->initializerCount],
               msgbuff, token);
    } else {
        printf("%s:%d:%d (pass=%d, initCount=%d) error: %s near %s\n",
               _this->filename, _this->line, _this->column, _this->pass, _this->initializerCount,
               msgbuff, token);
    }
#else
    if (_this->token) {
        printf("%s:%d:%d error: %s near %s\n", _this->filename, _this->line, _this->column, msgbuff, token);
    } else {
        printf("%s:%d:%d error: %s\n", _this->filename, _this->line, _this->column, msgbuff);
    }
#endif
    
    _this->errors++;
}

void Fast_Parser_warning(Fast_Parser _this, char* fmt, ... ) {
    va_list args;
    char msgbuff[1024];

    va_start(args, fmt);
    vsprintf(msgbuff, fmt, args);
    va_end(args);

    if (_this->token) {
        printf("%s:%d:%d warning: %s near token '%s'\n", _this->filename, _this->line, _this->column, msgbuff, _this->token);
    } else {
        printf("%s:%d:%d warning: %s\n", _this->filename, _this->line, _this->column, msgbuff);
    }
    _this->warnings++;
}

/* Generate user-friendly id's for both scoped and unscoped objects */
static cx_string Fast_Parser_id(cx_object o, cx_id buffer) {
    if (cx_checkAttr(o, CX_ATTR_SCOPED)) {
        cx_fullname(o, buffer);
    } else {
        cx_id tmp;
        cx_string_ser_t serData;
        struct cx_serializer_s s;
        serData.buffer = tmp;
        serData.length = sizeof(cx_id);
        serData.maxlength = sizeof(cx_id)-strlen("<anonymous>");
        serData.compactNotation=TRUE;
        serData.prefixType = TRUE;
        s = cx_string_ser(CX_LOCAL, CX_NOT, CX_SERIALIZER_TRACE_NEVER);
        cx_serialize(&s, o, &serData);
        strcpy(buffer, tmp);
    }
    return buffer;
}

/* Translate result of parser to cortex intermediate bytecode */
cx_int16 Fast_Parser_toIc(Fast_Parser _this) {
    cx_icProgram program = cx_icProgram__create(_this->filename);
    Fast_Binding *binding;
    cx_iter bindingIter;
    cx_icScope scope;
    cx_icStorage returnValue = NULL;
    cx_vmProgram vmProgram;

    /* Parse root-block */
    Fast_Block_toIc(_this->block, program, NULL    , FALSE);
    if (_this->errors) {
        goto error;
    }

    /* Parse functions */
    if (_this->bindings) {
        bindingIter = cx_llIter(_this->bindings);
        while(cx_iterHasNext(&bindingIter)) {
            cx_ic ret;
            binding = cx_iterNext(&bindingIter);
            cx_icProgram_functionPush(program, Fast_Node(binding->impl)->line, binding->function);
            scope = (cx_icScope)Fast_Block_toIc(binding->impl, program, NULL, FALSE);
            if (_this->errors) {
                goto error;
            }
            if (binding->function->returnType && ((binding->function->returnType->real->kind != CX_VOID) || (binding->function->returnType->real->reference))) {
                cx_id name;
                cx_signatureName(cx_nameof(binding->function), name);
                returnValue = cx_icScope_lookupStorage(scope, name, TRUE);
                ret = (cx_ic)cx_icOp__create(program, _this->line, CX_IC_RET, (cx_icValue)returnValue, NULL, NULL);
                if (binding->function->returnsReference) {
                    ((cx_icStorage)returnValue)->isReference = TRUE;
                    ((cx_icOp)ret)->s1Deref = CX_IC_DEREF_ADDRESS;
                }else {
                    ((cx_icOp)ret)->s1Deref = CX_IC_DEREF_VALUE;
                }
            } else {
                ret = (cx_ic)cx_icOp__create(program, _this->line, CX_IC_STOP, NULL, NULL, NULL);
            }

            cx_icScope_addIc(scope, ret);
            cx_icProgram_scopePop(program, _this->line);

            cx_free_ext(_this, binding->function, "Free binding for function");
            cx_free_ext(_this, binding->impl, "Free binding for function (impl)");
            cx_dealloc(binding);
        }
        cx_llFree(_this->bindings);
        _this->bindings = NULL;
    }

    /* Print program */
#ifdef CX_IC_TRACING
    extern cx_bool CX_DEBUG_ENABLED;
    if (CX_DEBUG_ENABLED) {
        cx_string programStr;
        programStr = cx_icProgram_toString(program);
        printf("%s\n", programStr);
        cx_dealloc(programStr);
    }
#endif

    /* Translate program to vm code */
    vmProgram = cx_icProgram_toVm(program);

    /* Run vm program */
    if (vmProgram) {
        cx_vm_run(vmProgram, NULL);
    }
    
    /* Free program */
    cx_icProgram__free(program);
    cx_vmProgram_free(vmProgram);

    return 0;
error:
    return -1;
}

/* Get anonymous variable */
Fast_Expression Fast_Parser_getAnonymousLocal(Fast_Parser _this, Fast_Variable type, cx_bool isReference) {
    cx_id id;
    Fast_Expression result;
    sprintf(id, "<%d>", _this->initAnonymousId); _this->initAnonymousId++; /* Make sure to create a new local for each anonymous object */
    result = Fast_Expression(Fast_Block_declare(_this->block, id, Fast_Variable(type), FALSE, isReference));
    // Fast_Parser_collect(_this, result);
    return result;
}

/* Translate binary expressions on composite values to corresponding operations */
Fast_Expression Fast_Parser_binaryCompositeExpr(Fast_Parser _this, Fast_Expression operand1, Fast_Expression operand2, cx_operatorKind operator) {
    Fast_Expression result = NULL;

    if (operator == CX_ASSIGN) {
        if(Fast_Node(operand2)->kind == FAST_Initializer) {
            if (Fast_InitializerExpr_insert(Fast_InitializerExpr(operand2), operand1)) {
                goto error;
            }
            result = operand1;
        } else if (!(result = Fast_Expression(Fast_createCall(operand1, "copy", 1, operand2)))) {
            goto error;
        }
    } else {
        Fast_Parser_error(_this, "operator invalid for composite value");
        goto error;
    }

    return result;
error:
    return NULL;
}

/* Translate binary expressions on collections to corresponding operations */
Fast_Expression Fast_Parser_binaryCollectionExpr(Fast_Parser _this, Fast_Expression operand1, Fast_Expression operand2, cx_operatorKind operator) {
    Fast_Expression result = NULL;
    cx_type tleft = Fast_Expression_getType_expr(operand1, operand2);
    cx_type tright = Fast_Expression_getType_expr(operand2, operand1);
    cx_bool leftToRight = FALSE, rightToLeft = FALSE, equality = FALSE;

    if (!tleft) { 
        tleft = tright;
        leftToRight = TRUE;
        equality = TRUE;
    } else if (!tright) { 
        tright = tleft; 
        rightToLeft = TRUE;
        equality = TRUE;
    } else { 
        /* Determine the direction of a collection expression */
        if (tleft->kind == CX_COLLECTION) {
            if (cx_type_castable(tleft, tright)) {
                equality = TRUE;
                rightToLeft = TRUE;
            }
            if (cx_type_castable(cx_collection(tleft)->elementType->real, tright)) {
                rightToLeft = TRUE;
            }
        }
    
        /* Both conditions can be true in case of recursive elementTypes, but rightToLeft takes precedence */
        if (tright->kind == CX_COLLECTION) { 
            if (cx_type_castable(cx_collection(tright)->elementType->real, tleft)) {
                leftToRight = TRUE;
            }
        }
    }

    if (!(rightToLeft || leftToRight || equality)) {
        cx_id id1, id2;
        Fast_Parser_error(_this, "collection-expression types do not match (left: %s, right: %s)",
                          Fast_Parser_id(tleft, id1),
                          Fast_Parser_id(tright, id2));
        printf("   valid options:\n");
        if (tleft->kind == CX_COLLECTION) {
            printf("      left: %s right: %s\n", Fast_Parser_id(tleft, id1), Fast_Parser_id(cx_collection(tleft)->elementType, id2));
            printf("      left: %s right: %s\n", Fast_Parser_id(tleft, id1), Fast_Parser_id(tleft, id1));
        }
        if (tright->kind == CX_COLLECTION) {
            printf("      left: %s right: %s\n", Fast_Parser_id(cx_collection(tright)->elementType, id1), Fast_Parser_id(tright, id2));
            printf("      left: %s right: %s\n", Fast_Parser_id(tright, id1), Fast_Parser_id(tright, id1));
        }
        goto error;
    }
    
    Fast_Expression collection = rightToLeft ? operand1 : operand2;
    Fast_Expression operand = rightToLeft ? operand2 : operand1;
    Fast_Expression castedOperand = operand;
    cx_collection collectionType = cx_collection(Fast_Expression_getType(collection));
    
    switch(operator) {
        case CX_ASSIGN:
            /* If operand is an initializer, insert initializer instructions. */
            if(Fast_Node(operand2)->kind == FAST_Initializer) {
                if (Fast_InitializerExpr_insert(Fast_InitializerExpr(operand2), operand1)) {
                    goto error;
                }
                result = operand1; 
                break;
            }

            /* If operand is a collection, insert copy-function. Otherwise fallthrough. */
            if (equality) {
                if (!(result = Fast_Expression(Fast_createCall(collection, "copy", 1, operand)))) {
                    goto error;
                }
                break;
            } else {
                if (!(result = Fast_Expression(Fast_createCall(collection, "clear", 0)))) {
                    goto error;
                }
            }
        case CX_ASSIGN_ADD: {
            Fast_Expression localResult = NULL;
            
            /* Cast operand to elementType */
            if (!equality && Fast_Expression_getType(operand) != collectionType->elementType->real) {
                if (collectionType->elementType->real->reference || (collectionType->elementType->real->kind == CX_PRIMITIVE)) {
                    castedOperand = Fast_Expression_cast(operand, collectionType->elementType->real, FALSE);
                    if (!castedOperand) {
                        castedOperand = operand;
                    }
                }
            } else {
                if (Fast_Node(collection)->kind == FAST_Initializer) {
                    castedOperand = Fast_Expression_cast(collection, tleft, FALSE);
                    collection = operand;
                } else if (Fast_Node(operand)->kind == FAST_Initializer) {
                    castedOperand = Fast_Expression_cast(operand, tleft, FALSE);
                } else {
                    castedOperand = operand;
                }
            }
            
            /* Create merge, insert or append */
            if (rightToLeft || (equality && (Fast_Node(operand)->kind != FAST_Initializer))) {
                if (!(localResult = Fast_Expression(Fast_createCall(collection, "append", 1, castedOperand)))) {
                    goto error;
                }
            } else {
                if (!(localResult = Fast_Expression(Fast_createCall(collection, "insert", 1, castedOperand)))) {
                    goto error;
                }
            }
            result = Fast_CommaExpr_addOrCreate(result, localResult);

            break;
        }
        case CX_DEC:
        case CX_COND_EQ:
        case CX_COND_NEQ:
        case CX_COND_LT:
        case CX_COND_GT:
        case CX_COND_LTEQ:
        case CX_COND_GTEQ:
        default:
            Fast_Parser_error(_this, "invalid operator %s for collection-operand",
                              cx_nameof(cx_enum_constant(cx_operatorKind_o, operator)));
            goto error;
            break;
    }
    
    return result;
error:
    return NULL;
}


/* Use cx_object as returntype as the actual type (Fast_Expression) causes macro-expansion */
typedef cx_object (*Fast_ExpandAction)(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue, void *userData);

/* Combine results in new comma expression */
cx_object Fast_Parser_combineCommaExpr(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue, void *userData) {
    CX_UNUSED(_this);
    CX_UNUSED(userData);
    return Fast_CommaExpr_addOrCreate(lvalue, rvalue);
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

        result = Fast_Expression(Fast_BinaryExpr__create(lvalue, rvalue, combineOper));
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
Fast_Expression Fast_Parser_createBinaryTernaryExpr(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue, cx_operatorKind operator) {
    Fast_Expression result = NULL;
    CX_UNUSED(_this);
    
    /* If the operation is an assignment, the ternary operator has already constructed the binary operation through an lvalue - see
     * the implementation of Fast_Parser_TernaryExpr. If the operation is not an assignment, create the binary expression. */
    switch(operator) {
    case CX_ASSIGN:
    case CX_ASSIGN_ADD:
    case CX_ASSIGN_SUB:
    case CX_ASSIGN_MUL:
    case CX_ASSIGN_DIV:
    case CX_ASSIGN_MOD:
    case CX_ASSIGN_OR: 
    case CX_ASSIGN_AND:
        Fast_TernaryExpr_setOperator(Fast_TernaryExpr(rvalue), operator);
        cx_set_ext(NULL, &result, rvalue, "?? set rvalue to result value of function");
        break;
    default:
        result = Fast_Expression(Fast_BinaryExpr__create(lvalue, rvalue, operator));
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
            cx_fullname(t1, id1),
            isRef1 ? "&" : "",
            cx_fullname(t2, id3),
            isRef2 ? "&" : "",
            cx_fullname(t2, id4));
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
    Fast_InitializerExpr result = NULL;
    cx_string signature = NULL;
    cx_procptr type = NULL;
    Fast_InitializerVariable_array64 variables;
    Fast_CallBuilder builder;
    Fast_Call tempCall = NULL;

    memset(variables, 0, sizeof(variables));

    /* Validate whether rvalue is an object */
    if ((Fast_Node(rvalue)->kind == FAST_Variable) && (Fast_Variable(rvalue)->kind == FAST_Object)) {
        cx_signatureName(cx_nameof(Fast_ObjectBase(rvalue)->value), functionName);
    } else if (Fast_Node(rvalue)->kind == FAST_Member) {
        instance = Fast_MemberExpr(rvalue)->lvalue;
        strcpy(functionName, Fast_String(Fast_MemberExpr(rvalue)->rvalue)->value);
    } else {
        Fast_Parser_error(_this, "dynamic delegate assignments are not yet supported");
        goto error;
    }

    type = cx_procptr(Fast_Expression_getType(lvalue));

    /* Build request-signature */
    signature = cx_signatureOpen(functionName);
    for (i = 0; i < type->parameters.length; i++) {
        cx_parameter *p = &type->parameters.buffer[i];
        signature = cx_signatureAdd(signature, p->type, p->passByReference ? CX_PARAMETER_FORCEREFERENCE : 0);
    }
    signature = cx_signatureClose(signature);

    /* Resolve function */
    Fast_CallBuilder__init(
        &builder,
        signature, 
        NULL, 
        instance, 
        Fast_ObjectBase(yparser()->scope)->value, 
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
        type->returnType->real,
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
            p1->type->real,
            p1->passByReference,
            p2->type->real,
            p2->passByReference)) {
            goto error;
        }
    }

    functionExpr = tempCall->functionExpr;

    /* If procedure is compatible with delegate type, do a complex assignment */
    cx_set_ext(NULL, &variables[0].object, lvalue, "keep object for initializer variable array");
    result = Fast_InitializerExpr__create(variables, 1, TRUE);
    if (instance) {
        Fast_InitializerExpr_member(result, "instance");
        Fast_InitializerExpr_value(result, instance);
    }
    Fast_InitializerExpr_member(result, "procedure");
    Fast_InitializerExpr_value(result, functionExpr);
    Fast_InitializerExpr_pop(result);
    Fast_InitializerExpr_define(result);
    Fast_Parser_collect(_this, result);

    cx_dealloc(signature);
    cx_free(tempCall);

    return Fast_Expression(result);
error:
    if(signature) {
        cx_dealloc(signature);
    }
    return NULL;
}

/* Callback function for expansion of binary expressions */
cx_object Fast_Parser_expandBinaryExpr(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue, void *userData) {
    Fast_Expression result = NULL;
    cx_type tleft, tright;
    cx_bool isReference, forceReference;

    tleft = Fast_Expression_getType_expr(lvalue,rvalue);
    tright = Fast_Expression_getType_expr(rvalue,lvalue);

    forceReference = lvalue->forceReference || rvalue->forceReference;
    isReference = forceReference || (tleft && tleft->reference) || (tright && tright->reference);

    if (tleft && (tleft->kind == CX_COMPOSITE) && (cx_interface(tleft)->kind == CX_PROCPTR)) {
        rvalue = Fast_Parser_delegateAssignment(_this, lvalue, rvalue);
        if(!rvalue) {
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
    if (Fast_Node(rvalue)->kind == FAST_Ternary) {
        result = Fast_Parser_createBinaryTernaryExpr(_this, lvalue, rvalue, *(cx_operatorKind*)userData);
    
    /* Binary expression with non-reference composite values */
    } else if (!isReference && ((tleft && (tleft->kind == CX_COMPOSITE)) && (tright && (tright->kind == CX_COMPOSITE)))) {
        result = Fast_Parser_binaryCompositeExpr(_this, lvalue, rvalue, *(cx_operatorKind*)userData);

    /* Binary expression with non-reference collection values */
    } else if (!forceReference && ((tleft && (tleft->kind == CX_COLLECTION)) || (tright && (tright->kind == CX_COLLECTION)))) {
        result = Fast_Parser_binaryCollectionExpr(_this, lvalue, rvalue, *(cx_operatorKind*)userData);

    /* Binary expression with primitive or reference values */
    } else {
        if (Fast_Node(rvalue)->kind == FAST_Initializer) {
            if (Fast_InitializerExpr_insert(Fast_InitializerExpr(rvalue), lvalue)) {
                goto error;
            }
            result = lvalue;  
        } else {
            result = Fast_Expression(Fast_BinaryExpr__create(lvalue, rvalue, *(cx_operatorKind*)userData));

            /* Fold expression */
            if (result) {
                result = Fast_Expression_fold(result);
                if (!result) {
                    Fast_Parser_error(_this, "folding failed for expression");
                    goto error;
                }
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
cx_object Fast_Parser_expandMemberExpr(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue, void *userData) {
    CX_UNUSED(userData);
    CX_UNUSED(_this);
    Fast_Expression result = NULL;
    
    /* Create member expression */
    result = Fast_Expression(Fast_MemberExpr__create(lvalue, rvalue));
    if (!result) {
        goto error;
    }

    return result;
error:
    return NULL;
}


/* Callback function for expansion of element expressions */
cx_object Fast_Parser_expandElementExpr(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue, void *userData) {
    CX_UNUSED(_this);
    CX_UNUSED(userData);
    Fast_Expression result = (Fast_Expression)Fast_ElementExpr__create(lvalue, rvalue);
    if (!result) {
        goto error;
    }
    
    return result;
error:
    return NULL;
}

/* Generic function to "explode" comma-expressions. This results in (ln * rn) expressions */
Fast_Expression Fast_Parser_explodeCommaExpr(Fast_Parser _this, Fast_Expression lvalues, Fast_Expression rvalues, Fast_ExpandAction action, void *userData) {
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
            if (Fast_Node(rvalues)->kind != FAST_Initializer) {
                var = Fast_Parser_getAnonymousLocal(_this, lvalues->type, FALSE);
                Fast_Expression assign = Fast_Parser_binaryExpr(_this, var, lvalues, CX_ASSIGN);
                Fast_Parser_addStatement(_this, Fast_Node(assign));
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
            result = Fast_CommaExpr_addOrCreate(result, e);
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
Fast_Expression Fast_Parser_expandCommaExpr(Fast_Parser _this, Fast_Expression lvalues, Fast_Expression rvalues, Fast_ExpandAction action, Fast_ExpandAction combine, void *userData) {
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
            if (Fast_Node(rvalues)->kind != FAST_Initializer) {
                Fast_Expression var = Fast_Parser_getAnonymousLocal(_this, rvalues->type, FALSE);
                Fast_Expression assign = Fast_Parser_binaryExpr(_this, var, rvalues, CX_ASSIGN);
                Fast_Parser_addStatement(_this, Fast_Node(assign));
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

        tleft = Fast_Expression_getType_expr(lvalue,rvalues);
        tright = Fast_Expression_getType_expr(rvalues,lvalue);
        if (!tleft || !tright) {
            cx_id id;
            Fast_Parser_error(_this, "invalid usage of null in expression with type '%s'",
                              tleft ? Fast_Parser_id(tleft, id) : Fast_Parser_id(tright, id));
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

Fast_Expression Fast_Parser_resolve(Fast_Parser _this, cx_id id, cx_object source) {
    Fast_Expression result = NULL;
    cx_object object;
    cx_object parent = _this->scope ? Fast_ObjectBase(_this->scope)->value : NULL;
    cx_char *ptr, ch;
    cx_id buffer;
    cx_char *bptr;

    if (strchr(id, ':')) {
        ptr = id;
        bptr = buffer;
        do {
            object = cx_resolve_ext(source, parent, id, FALSE, NULL);
            if (object){
                result = Fast_Expression(Fast_Object__create(object));
                Fast_Parser_collect(_this, result);
                cx_free_ext(source, object, NULL);
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
        object = cx_resolve_ext(source, parent, id, FALSE, NULL);
        if (!object){
            cx_object rvalueType = Fast_Parser_getLvalueType(_this, FALSE);
            if (rvalueType && cx_checkAttr(rvalueType, CX_ATTR_SCOPED)) {
                object = cx_resolve_ext(source, rvalueType, id, FALSE, NULL);
            }
        }
        if (object) {
            result = Fast_Expression(Fast_Object__create(object));
            Fast_Parser_collect(_this, result);
            cx_free_ext(source, object, NULL);
        }
    }

    return result;
error:
    Fast_Parser_error(_this, "unresolved identifier '%s'", id);
    fast_err;
    return NULL;
}

/* Create an observer */
Fast_Variable Fast_Parser_observerCreate(Fast_Parser _this, cx_string id, Fast_Expression object, cx_eventMask mask, cx_string expr, Fast_Object dispatcherVar) {
    Fast_Variable result = NULL;
    cx_observer observer;
    cx_object observable = NULL;
    cx_object parent;
    cx_object dispatcher = NULL;

    /* If object is zero, this indicates either a template local or an expression during the 1st pass. TODO: how to handle
     * declaring expressions in the 1st pass - possible solution is setting the expression in the 2nd pass but then how can
     * the observer be identified?
     */


    parent = Fast_ObjectBase(_this->scope)->value;
    if (!cx_class_instanceof(cx_type_o, parent)) {
        parent = NULL;
    }

    if (dispatcherVar) {
        dispatcher = Fast_ObjectBase(dispatcherVar)->value;
    }

    if (object && (Fast_Node(object)->kind == FAST_Variable)) {
        switch(Fast_Variable(object)->kind) {
        case FAST_Object:
            observable = Fast_ObjectBase(object)->value;
            expr = NULL;
            break;
        case FAST_Template:
            expr = NULL;
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
        observer = cx_observer__create(observable, mask, expr, FALSE, dispatcher, NULL);
        if (!observer) {
            goto error;
        }
        cx_attach(Fast_ObjectBase(_this->scope)->value, observer);

        /* If observer is a template observer, manually attach */
        if (parent) {
            cx_class_bindObserver(cx_class(parent), observer);
        }
    } else {
        observer = cx_observer__declare(Fast_ObjectBase(_this->scope)->value, id);
        if (!observer) {
            goto error;
        }
        if (cx_observer__define(observer, observable, mask, expr, FALSE, dispatcher, NULL)) {
            goto error;
        }
    }

    /* Create and collect result */
    result = (Fast_Variable)Fast_Object__create(observer);
    Fast_Parser_collect(_this, result);


    return result;
error:
    fast_err;
    return NULL;
}

/* Declare a delegate type */
Fast_Variable Fast_Parser_declareDelegate(Fast_Parser _this, cx_type returnType, cx_string id, cx_bool returnsReference) {
    cx_procptr delegate;
    cx_parameterSeq parameters;
    cx_id name;

    /* Translate from name to arguments */
    parameters = cx_function_stringToParameterSeq(id, Fast_ObjectBase(_this->scope)->value);

    /* Obtain name */
    cx_signatureName(id, name);

    /* Declare and define delegate */
    delegate = cx_procptr__declare(Fast_ObjectBase(_this->scope)->value, name);
    if(!delegate) {
        goto error;
    }

    if(cx_procptr__define(delegate, cx_typedef(returnType), returnsReference, parameters)) {
        goto error;
    }

    return Fast_Variable(Fast_Object__create(delegate));
error:
    return NULL;
}

/* $end */

/* ::cortex::Fast::Parser::addStatement(Fast::Node statement) */
void Fast_Parser_addStatement(Fast_Parser _this, Fast_Node statement) {
/* $begin(::cortex::Fast::Parser::addStatement) */
    FAST_CHECK_ERRSET(_this);
    
    /* Process staged declarations that do not have initializers (for example, enum Color:: RED, YELLOW, GREEN, BLUE;) */
    if (!_this->pass && !statement) {
        if (_this->stagingAllowed) {
            Fast_Parser_initDeclareStaged(_this, NULL);
        }
    }

    if (statement) {
        if (_this->block && (Fast_Node(_this->block->_while) != statement)) {
            if (_this->block->_while) {
                Fast_Parser_error(_this, "invalid statement after while");
                goto error;
            }
            if (!((statement->kind == FAST_Literal) && (Fast_Literal(statement)->kind == FAST_String))) {
                Fast_Block_addStatement(_this->block, statement);
                if (cx_instanceof(cx_typedef(Fast_Expression_o), statement)) {
                    if (!Fast_Expression_hasSideEffects(Fast_Expression(statement))) {
                        /* TODO: Fast_Parser_warning(_this, "computed value is not used (%s)", cx_nameof(cx_typeof(statement))); */
                    }
                }
            } else if (_this->pass) {
                /* If statement is a string, insert println function */
                Fast_Expression println = Fast_Parser_lookup(_this, "io::println", NULL);
                Fast_CommaExpr args = Fast_CommaExpr__create();
                Fast_CommaExpr_addExpression(args, Fast_Expression(statement));
                Fast_Expression callExpr = Fast_Parser_callExpr(_this, println, Fast_Expression(args));
                Fast_Block_addStatement(_this->block, Fast_Node(callExpr));
                Fast_Parser_collect(_this, args);
            }
        }
    }
    
    return;
error:
    fast_err;
/* $end */
}

/* ::cortex::Fast::Parser::argumentToString(Fast::Variable type,lang::string id,lang::bool reference) */
cx_string Fast_Parser_argumentToString(Fast_Parser _this, Fast_Variable type, cx_string id, cx_bool reference) {
/* $begin(::cortex::Fast::Parser::argumentToString) */
    cx_string str;
    cx_object type_o;
    cx_string result;
    FAST_CHECK_ERRSET(_this);

    /* 1st pass & 2nd pass are equal */
    if (!type) {
        if (_this->lastFailedResolve) {
            Fast_Parser_error(_this, "unresolved type '%s'", _this->lastFailedResolve);  
        } else {
            /* Cause is most likely an already reported error */
        }
        goto error;
    }

    type_o = Fast_ObjectBase(type)->value;

    if (!cx_class_instanceof(cx_typedef_o, type_o)) {
        cx_id id;
        Fast_Parser_error(_this, "object '%s' used in parameter expression is not a type", Fast_Parser_id(type_o, id));
        goto error;
    }

    if (cx_checkAttr(type_o, CX_ATTR_SCOPED)) {
        cx_id id;
        str = strdup(Fast_Parser_id(type_o, id));
    } else {
        struct cx_serializer_s s;
        cx_string_ser_t walkData;

        memset(&walkData, 0, sizeof(walkData));
        s = cx_string_ser(CX_LOCAL, CX_NOT, CX_SERIALIZER_TRACE_NEVER);

        walkData.compactNotation = TRUE;
        walkData.prefixType = TRUE;

        if (cx_serialize(&s, type_o, &walkData)) {
            goto error;
        }
        str = walkData.buffer;
    }

    result = cx_malloc(strlen(str) + 1 + strlen(id) + 1 + 1);

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

/* ::cortex::Fast::Parser::binaryExpr(Fast::Expression lvalues,Fast::Expression rvalues,lang::operatorKind operator) */
Fast_Expression Fast_Parser_binaryExpr(Fast_Parser _this, Fast_Expression lvalues, Fast_Expression rvalues, cx_operatorKind operator) {
/* $begin(::cortex::Fast::Parser::binaryExpr) */
    Fast_Expression result = NULL;
    FAST_CHECK_ERRSET(_this);
    
    _this->stagingAllowed = FALSE;
    
    if (lvalues && rvalues && (_this->pass || ((_this->initializerCount >= 0) && _this->initializers[_this->initializerCount]))) {
        Fast_ExpandAction combine = Fast_Parser_combineCommaExpr;
        switch(operator) {
        case CX_COND_EQ:
        case CX_COND_NEQ:
        case CX_COND_AND:
        case CX_COND_OR:
        case CX_COND_GT:
        case CX_COND_LT:
        case CX_COND_GTEQ:
        case CX_COND_LTEQ:
            combine = Fast_Parser_combineConditionalExpr;
            break;
        default:
            break;
        }
        if (!(result = Fast_Parser_expandCommaExpr(_this, lvalues, rvalues, Fast_Parser_expandBinaryExpr, combine, &operator))) {
            goto error;
        }    
    }
    
    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::cortex::Fast::Parser::bind(Fast::Variable function,Fast::Block block) */
cx_int16 Fast_Parser_bind(Fast_Parser _this, Fast_Variable function, Fast_Block block) {
/* $begin(::cortex::Fast::Parser::bind) */
    Fast_Binding *binding;
    FAST_CHECK_ERRSET(_this);

    if (_this->pass && function) {
        if (function->kind == FAST_Object) {
            binding = cx_calloc(sizeof(Fast_Binding));
            binding->function = Fast_ObjectBase(function)->value; cx_keep_ext(_this, binding->function, "Create binding for function");
            binding->impl = block; cx_keep_ext(_this, block, "Create binding for function (impl)");
            cx_assert(_this->bindings != NULL, "initialization failed");
            cx_llAppend(_this->bindings, binding);
        }
    }

    return 0;
/* $end */
}

/* ::cortex::Fast::Parser::bindOneliner(Fast::Variable function,Fast::Block block,Fast::Expression expr) */
cx_int16 Fast_Parser_bindOneliner(Fast_Parser _this, Fast_Variable function, Fast_Block block, Fast_Expression expr) {
/* $begin(::cortex::Fast::Parser::bindOneliner) */
    FAST_CHECK_ERRSET(_this);

    if (_this->pass) {
        Fast_Expression returnLocal;
        cx_id functionName;

        /* Add oneliner to block */
        cx_signatureName(cx_nameof(Fast_ObjectBase(function)->value), functionName);
        returnLocal = Fast_Block_lookup(block, functionName);
         if (returnLocal) {
            Fast_Expression returnAssign;
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

/* ::cortex::Fast::Parser::blockPop() */
void Fast_Parser_blockPop(Fast_Parser _this) {
/* $begin(::cortex::Fast::Parser::blockPop) */
    FAST_CHECK_ERRSET(_this);

    /* Blocks are parsed only in 2nd pass */
    if (_this->pass) {
        if (_this->block) {
            cx_set_ext(_this, &_this->block, _this->block->parent, "pop block");
            _this->blockPreset = FALSE;
        } else {
            /* Got confused by earlier errors */
            Fast_Parser_error(_this, "unable to continue parsing due to previous errors");
            _this->abort = TRUE;
        }
    }

/* $end */
}

/* ::cortex::Fast::Parser::blockPush(lang::bool presetBlock) */
Fast_Block Fast_Parser_blockPush(Fast_Parser _this, cx_bool presetBlock) {
/* $begin(::cortex::Fast::Parser::blockPush) */
    FAST_CHECK_ERRSET(_this);

    /* Blocks are parsed only in 2nd pass */
    if (_this->pass) {
        Fast_Block newBlock;

        newBlock = NULL;

        if (!_this->blockPreset || presetBlock) {
            newBlock = Fast_Block__create(_this->block);
            Fast_Parser_collect(_this, newBlock);
            cx_set_ext(_this, &_this->block, newBlock, "push block");
        }

        _this->blockPreset = presetBlock;

        return newBlock;
    } else {
        return NULL;
    }
/* $end */
}

/* ::cortex::Fast::Parser::callExpr(Fast::Expression function,Fast::Expression arguments) */
Fast_Expression Fast_Parser_callExpr(Fast_Parser _this, Fast_Expression function, Fast_Expression arguments) {
/* $begin(::cortex::Fast::Parser::callExpr) */
    Fast_Expression result = NULL;
    
    _this->stagingAllowed = FALSE;

    if (_this->pass) {
        cx_object o = NULL;
        Fast_Expression_list functions = Fast_Expression_toList(function);

        Fast_Expression_list__foreach(functions, f)
            Fast_Expression expr;    
            if ((Fast_Node(f)->kind == FAST_Variable) && (Fast_Variable(f)->kind == FAST_Object)) {
                o = Fast_ObjectBase(f)->value;
            }
            /* If function is a type, insert cast */
            if (o && cx_instanceof(cx_typedef(cx_type_o), o)) {
                cx_ll exprs = Fast_Expression_toList(arguments);
                if (cx_llSize(exprs) != 1) {
                    Fast_Parser_error(_this, "invalid number of parameters for cast (expected 1)");
                    Fast_Expression_cleanList(exprs);
                    goto error;
                }
                expr = Fast_Parser_castExpr(_this, f, cx_llGet(exprs, 0));
                Fast_Expression_cleanList(exprs);
                Fast_Parser_collect(_this, expr);
            } else {
                expr = Fast_Expression(Fast_createCallFromExpr(f, arguments));
            }
            if (!expr) {
                goto error;
            }
            result = Fast_CommaExpr_addOrCreate(result, expr);
        }
        Fast_Expression_cleanList(functions);
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::cortex::Fast::Parser::castExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
Fast_Expression Fast_Parser_castExpr(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue) {
/* $begin(::cortex::Fast::Parser::castExpr) */
    Fast_Expression result = NULL;
    
    _this->stagingAllowed = FALSE;

    if (_this->pass) {
        cx_type lvalueType, rvalueType;
        cx_bool castRequired = TRUE;

        /* If cast is an upcast, don't insert cast operation since these are always allowed */
        if ((Fast_Node(lvalue)->kind == FAST_Variable) && (Fast_Variable(lvalue)->kind == FAST_Object)) {
            lvalueType = Fast_ObjectBase(lvalue)->value;
        } else {
            Fast_Parser_error(_this, "casting to a dynamic type not yet supported");
            goto error;
        }
        rvalueType = Fast_Expression_getType(rvalue);

        if (lvalueType == rvalueType) {
            cx_id id;
            Fast_Parser_warning(_this, "casting to value of the same type (%s)", Fast_Parser_id(lvalueType, id));
            castRequired = FALSE;
        } else {
            if ((lvalueType->kind == CX_COMPOSITE) && (rvalueType->kind == CX_COMPOSITE)) {
                if (cx_type_castable(lvalueType, rvalueType)) {
                    cx_id id1, id2;
                    castRequired = FALSE;
                    Fast_Parser_warning(_this, "upcasting from '%s' to '%s' does not require an explicit cast",
                            Fast_Parser_id(rvalueType, id1), Fast_Parser_id(lvalueType, id2));
                }
            } else if (Fast_Node(rvalue)->kind == FAST_Literal) {
                result = Fast_Expression_cast(rvalue, lvalueType, lvalue->isReference);
                castRequired = FALSE;
            }
        }

        if (castRequired) {
            result = Fast_Expression(Fast_CastExpr__create(lvalue, rvalue));
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

/* ::cortex::Fast::Parser::collect(lang::object o) */
cx_void Fast_Parser_collect(Fast_Parser _this, cx_object o) {
/* $begin(::cortex::Fast::Parser::collect) */
    /* 1st pass & 2nd pass are equal */

    cx_assert(_this->collected != NULL, "initialization failed");
    cx_llInsert(_this->collected, o);

/* $end */
}

/* ::cortex::Fast::Parser::collectHeap(word addr) */
cx_void Fast_Parser_collectHeap(Fast_Parser _this, cx_word addr) {
/* $begin(::cortex::Fast::Parser::collectHeap) */
    FAST_CHECK_ERRSET(_this);

    /* 1st pass & 2nd pass are equal */
    cx_assert(_this->heapCollected != NULL, "initialization failed");
    cx_llInsert(_this->heapCollected, (void*)addr);

/* $end */
}

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::Fast::Parser::construct(Parser object) */
cx_int16 Fast_Parser_construct(Fast_Parser object) {
/* $begin(::cortex::Fast::Parser::construct) */
    CX_UNUSED(object);
    Fast_Parser_reset(object);
    return 0;
/* $end */
}

/* ::cortex::Fast::Parser::declaration(Variable type,lang::string id,lang::bool isReference) */
Fast_Variable Fast_Parser_declaration(Fast_Parser _this, Fast_Variable type, cx_string id, cx_bool isReference) {
/* $begin(::cortex::Fast::Parser::declaration) */
    Fast_Variable result = NULL;
    FAST_CHECK_ERRSET(_this);

    if (!_this->block) {
        goto error;
    }

    _this->stagingAllowed = FALSE;

    /* If block is not root or local-keyword is used, declare local */
    if (_this->block->parent || _this->isLocal) {
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
                if ((o = cx_resolve(Fast_ObjectBase(_this->scope)->value, id))) {
                    Fast_Parser_error(_this, "object '%s' is redeclared as a variable", id);
                    cx_free(o);
                    goto error;
                }
            }

            result = Fast_Variable(Fast_Block_declare(_this->block, id, type, FALSE, isReference));
            _this->variables[_this->variableCount] = result;
            _this->variableCount++;
        } else {
            /* Variables are declared in 2nd pass */
            _this->variables[_this->variableCount] = NULL;
            _this->variableCount++;
        }
    } else if (!_this->scope || _this->scope->kind == FAST_Object) {
        cx_object parent = _this->scope ? Fast_ObjectBase(_this->scope)->value : NULL;
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
            o = cx_declare(parent, id, Fast_ObjectBase(type)->value);
            if (!o) {
                cx_id id1;
                Fast_Parser_error(_this, "declare of '%s' of type '%s' failed",
                        id,
                        Fast_Parser_id(Fast_ObjectBase(type)->value, id1));
                goto error;
            }
        } else {
            o = cx_resolve_ext(_this, parent, id, FALSE, "Resolve object in 2nd pass");
            cx_assert(o != NULL, "object disappeared in 2nd pass");
            cx_free_ext(_this, o, "Free object from resolve (2nd run)");
        }
        if (o) {
            result = Fast_Variable( Fast_Object__create(o));
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

/* ::cortex::Fast::Parser::declareFunction(Variable returnType,lang::string id,lang::type kind,bool returnsReference) */
Fast_Variable Fast_Parser_declareFunction(Fast_Parser _this, Fast_Variable returnType, cx_string id, cx_type kind, cx_bool returnsReference) {
/* $begin(::cortex::Fast::Parser::declareFunction) */
    cx_function function;
    cx_object o;
    cx_typedef functionType = cx_typedef(kind);
    cx_object returnType_o;
    Fast_Variable result = NULL;
    cx_int32 distance;
    FAST_CHECK_ERRSET(_this);

    if (!_this->pass) {
        cx_id functionName;
        cx_delegate delegate = NULL;

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
        if ((o = cx_lookup(Fast_ObjectBase(_this->scope)->value, functionName))) {
            if (!cx_instanceof(cx_typedef(cx_function_o), o)) {
                cx_id id2;
                Fast_Parser_error(_this, "cannot redeclare '%s' of type '%s' as function",
                    id, Fast_Parser_id(cx_typeof(o), id2));
                goto error;
            }
            cx_free(o);
        }
        
        /* This could be an implementation after a forward declaration so try to resolve
         * function first. */
        if (!((function = cx_lookupFunction(Fast_ObjectBase(_this->scope)->value, id, FALSE, &distance)) && !distance)) {
            if (!functionType) {
                if (cx_class_instanceof(cx_interface_o, Fast_ObjectBase(_this->scope)->value)) {
                    if (cx_class_instanceof(cx_class_o, Fast_ObjectBase(_this->scope)->value)) {
                        if ((delegate = cx_class_resolveDelegate(cx_class_o, functionName))) {
                            functionType = cx_typedef(cx_callback_o);
                        }
                    }
                    if (!functionType) {
                        functionType = cx_typedef(cx_method_o);
                    }
                } else {
                    functionType = cx_typedef(cx_function_o);
                }
            } else {
                /* Check whether declaration is a delegate */
                if(cx_interface_baseof(cx_interface(kind), cx_interface(cx_procptr_o))) {
                    result = Fast_Parser_declareDelegate(
                        _this, 
                        returnType ? Fast_ObjectBase(returnType)->value : NULL, 
                        id, 
                        returnsReference);
                }
            }

            if (!result) {
                returnType_o = Fast_ObjectBase(returnType)->value;
                if (!cx_class_instanceof(cx_typedef_o, returnType_o)) {
                    cx_id id;
                    Fast_Parser_error(_this, "object '%s' specified as returntype is not a type.", Fast_Parser_id(returnType_o, id));
                    goto error;
                }

                function = cx_declare(Fast_ObjectBase(_this->scope)->value, id, functionType);
                if (!function) {
                    Fast_Parser_error(_this, "declare of '%s' failed",
                                      functionName);
                    goto error;
                }

                function->returnType = cx_typedef(returnType_o);
                function->returnsReference = returnsReference;
                cx_keep_ext(function, returnType_o, "Keep returntype for function");

                if (delegate) {
                    cx_callback(function)->delegate = delegate;
                    cx_keep_ext(function, delegate, "Keep delegate for callback");
                }
            }
        } else {
            cx_free(function);
        }
        
        if (!result) {        
            result = Fast_Variable(Fast_Object__create(function));
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

            cx_object function = cx_resolve_ext(_this, Fast_ObjectBase(_this->scope)->value, query, FALSE, "Resolve function in 2nd pass");
            cx_assert(function != NULL, "object should still be there in 2nd pass");
            
            result = Fast_Variable(Fast_Object__create(function));
            Fast_Parser_collect(_this, result);
            cx_free_ext(_this, function, "Free function from resolve (2nd pass)");
        }
    }
    
    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::cortex::Fast::Parser::declareFunctionParams(Variable function) */
Fast_Block Fast_Parser_declareFunctionParams(Fast_Parser _this, Fast_Variable function) {
/* $begin(::cortex::Fast::Parser::declareFunctionParams) */
    cx_function function_o;
    cx_parameter *param;
    Fast_Object typeVariable;
    Fast_Block result = NULL;
    unsigned int i;
    FAST_CHECK_ERRSET(_this);

    if (_this->pass && function) {
        result = Fast_Parser_blockPush(_this, TRUE);

        function_o = Fast_ObjectBase(function)->value;
        Fast_Block_setFunction(result, function_o);

        /* If function is a method, include 'this' pointer */
        if (cx_instanceof(cx_typedef(cx_method_o), function_o)) {
            cx_interface parent;

            typeVariable = Fast_Object__create(cx_parentof(function_o));
            Fast_Block_declare(result, "this", Fast_Variable(typeVariable), TRUE, FALSE);
            Fast_Parser_collect(_this, typeVariable);

            /* If parent of method has a base, include super */
            parent = cx_parentof(function_o);
            if (cx_interface(parent)->base) {
                Fast_Object superType = Fast_Object__create(cx_interface(parent)->base);
                Fast_Parser_collect(_this, superType);
                Fast_Block_declare(result, "super", Fast_Variable(superType), TRUE, FALSE);
            }
        }

        for(i=0; i<function_o->parameters.length; i++) {
            param = &function_o->parameters.buffer[i];

            typeVariable = Fast_Object__create(param->type);
            Fast_Block_declare(result, param->name, Fast_Variable(typeVariable), TRUE, param->passByReference);
            Fast_Parser_collect(_this, typeVariable);
        }

        /* If function has a returntype, include name of function */
        if (function_o->returnType && ((function_o->returnType->real->kind != CX_VOID) || function_o->returnType->real->reference)) {
            Fast_Block_declareReturnVariable(result, function_o);
        }
    }

    return result;
/* $end */
}

/* ::cortex::Fast::Parser::define() */
cx_int16 Fast_Parser_define(Fast_Parser _this) {
/* $begin(::cortex::Fast::Parser::define) */
    FAST_CHECK_ERRSET(_this);

    if ((_this->initializerCount >= 0) && _this->initializers[_this->initializerCount]) {
        if (Fast_Initializer_define(_this->initializers[_this->initializerCount])) {
            goto error;
        }
        cx_set_ext(_this, &_this->initializers[_this->initializerCount], NULL, ".initializers[.initializerCount]");
        _this->initializerCount--;
    }

    return 0;
error:
    fast_err;
    return -1;
/* $end */
}

/* ::cortex::Fast::Parser::defineScope() */
cx_int16 Fast_Parser_defineScope(Fast_Parser _this) {
/* $begin(::cortex::Fast::Parser::defineScope) */
    FAST_CHECK_ERRSET(_this);

    if (!_this->pass) {
        if (Fast_Variable(_this->scope)->kind == FAST_Object) {
            cx_object o = Fast_ObjectBase(_this->scope)->value;
            if (cx_instanceof(cx_typedef(cx_type_o), o)) {
                if (cx_define(o)) {
                    cx_id id;
                    Fast_Parser_error(_this, "failed to define scope '%s'", Fast_Parser_id(Fast_ObjectBase(_this->scope)->value, id));
                    goto error;
                }
            } else {
                Fast_Define defineExpr = Fast_Define__create(Fast_Expression(_this->scope));
                Fast_Parser_addStatement(_this, Fast_Node(defineExpr));
                Fast_Parser_collect(_this, defineExpr);
            }
        } else {
            Fast_Parser_error(_this, "variables as scope are not yet supported.");
            fast_err;
        }
    }

    return 0;
error:
    fast_err;
    return -1;
/* $end */
}

/* ::cortex::Fast::Parser::defineVariable(Variable object) */
cx_int16 Fast_Parser_defineVariable(Fast_Parser _this, Fast_Variable object) {
/* $begin(::cortex::Fast::Parser::defineVariable) */
    cx_int16 result = 0;
    CX_UNUSED(_this);
    FAST_CHECK_ERRSET(_this);

    if ((Fast_Node(object)->kind == FAST_Variable) && (Fast_Variable(object)->kind == FAST_Object)) {
        if (cx_define(Fast_ObjectBase(object)->value)) {
            cx_id id1, id2;
            Fast_Parser_error(_this, "define of variable '%s' of type '%s' failed",
                    Fast_Parser_id(Fast_ObjectBase(object)->value, id1),
                    Fast_Parser_id(cx_typeof(Fast_ObjectBase(object)->value), id2));
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

/* callback ::cortex::lang::class::destruct(lang::object object) -> ::cortex::Fast::Parser::destruct(Parser object) */
void Fast_Parser_destruct(Fast_Parser object) {
/* $begin(::cortex::Fast::Parser::destruct) */
    cx_iter iter;

    if (object->heapCollected) {
        iter = cx_llIter(object->heapCollected);
        while(cx_iterHasNext(&iter)) {
            cx_dealloc(cx_iterNext(&iter));
        }
        cx_llFree(object->heapCollected);
    }

    object->heapCollected = NULL;
    object->scope = NULL;

    memset(object->variables, 0, sizeof(object->variables));
/* $end */
}

/* ::cortex::Fast::Parser::elementExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
Fast_Expression Fast_Parser_elementExpr(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue) {
/* $begin(::cortex::Fast::Parser::elementExpr) */
    Fast_Expression result = NULL;

    /* Expand element expression with comma-expressions */
    if (_this->pass) {
        cx_type t = Fast_Expression_getType(lvalue);
        /* If the left value is a composite type then translate element expression to members */
        if (t) {
            if (t->kind == CX_COMPOSITE) {
                if (!(result = Fast_Parser_explodeCommaExpr(_this, lvalue, rvalue, Fast_Parser_expandMemberExpr, NULL))) {
                    goto error;
                }
            } else {
                if (!(result = Fast_Parser_explodeCommaExpr(_this, lvalue, rvalue, Fast_Parser_expandElementExpr, NULL))) {
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

/* ::cortex::Fast::Parser::foreach(lang::string loopId,Fast::Expression collection) */
cx_int16 Fast_Parser_foreach(Fast_Parser _this, cx_string loopId, Fast_Expression collection) {
/* $begin(::cortex::Fast::Parser::foreach) */
    if (_this->pass) {
        Fast_Block block;
        cx_object type;
        cx_typedef elementType;
        Fast_Variable elementTypeVar;
        FAST_CHECK_ERRSET(_this);

        if (collection->type->kind == FAST_Object) {
            type = Fast_ObjectBase(collection->type)->value;
        } else {
            /* TODO: what if type is local */
            type = NULL;
        }

        if (cx_typedef(type)->real->kind != CX_COLLECTION) {
            Fast_Parser_error(_this, "expression does not resolve to a collection");
            goto error;
        }

        elementType = cx_collection(cx_typedef(type)->real)->elementType;
        elementTypeVar = Fast_Variable(Fast_Object__create(elementType));
        Fast_Parser_collect(_this, elementTypeVar);

        /* Push block, declare loop variable */
        block = Fast_Parser_blockPush(_this, TRUE);
        Fast_Block_declare(block, loopId, elementTypeVar, TRUE, FALSE);
    }

    return 0;
error:
    fast_err;
    return -1;
/* $end */
}

/* ::cortex::Fast::Parser::getComplexType() */
cx_type Fast_Parser_getComplexType(Fast_Parser _this) {
/* $begin(::cortex::Fast::Parser::getComplexType) */
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

/* ::cortex::Fast::Parser::getLvalue(lang::bool assignment) */
Fast_Expression Fast_Parser_getLvalue(Fast_Parser _this, cx_bool assignment) {
/* $begin(::cortex::Fast::Parser::getLvalue) */
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

/* ::cortex::Fast::Parser::getLvalueType(lang::bool assignment) */
cx_type Fast_Parser_getLvalueType(Fast_Parser _this, cx_bool assignment) {
/* $begin(::cortex::Fast::Parser::getLvalueType) */
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

/* ::cortex::Fast::Parser::ifStatement(Fast::Expression condition,Fast::Block trueBranch,Fast::If falseBranch) */
Fast_Node Fast_Parser_ifStatement(Fast_Parser _this, Fast_Expression condition, Fast_Block trueBranch, Fast_If falseBranch) {
/* $begin(::cortex::Fast::Parser::ifStatement) */
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

/* ::cortex::Fast::Parser::initDeclareStaged(Fast::Expression expr) */
void Fast_Parser_initDeclareStaged(Fast_Parser _this, Fast_Expression expr) {
/* $begin(::cortex::Fast::Parser::initDeclareStaged) */
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
            if (Fast_Variable(_this->scope)->kind == FAST_Object) {
                cx_object scope = Fast_ObjectBase(_this->scope)->value;
                if (cx_instanceof(cx_typedef(cx_type_o), scope)) {
                    Fast_Variable defaultType;
                    cx_typedef scopeType = cx_typedef(scope);
                    if (scopeType->real->defaultType) {
                        defaultType = Fast_Variable(Fast_Object__create(scopeType->real->defaultType));
                    } else {
                        defaultType = Fast_Variable(Fast_Object__create(cx_any_o));
                    }
                    
                    /* Add variable to parser-list for initialization */
                    Fast_Parser_declaration(_this, defaultType, _this->staged[i].name, FALSE);
                    
                    cx_dealloc(_this->staged[i].name);
                    _this->staged[i].name = NULL;
                    Fast_Parser_collect(_this, defaultType);
                }
            }
        }
    }

    _this->stagedCount = 0;
    return;
error:
    fast_err;
/* $end */
}

/* ::cortex::Fast::Parser::initKeyValuePop() */
cx_int16 Fast_Parser_initKeyValuePop(Fast_Parser _this) {
/* $begin(::cortex::Fast::Parser::initKeyValuePop) */
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

/* ::cortex::Fast::Parser::initKeyValuePush() */
cx_int16 Fast_Parser_initKeyValuePush(Fast_Parser _this) {
/* $begin(::cortex::Fast::Parser::initKeyValuePush) */
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

/* ::cortex::Fast::Parser::initKeyValueSet(Fast::Expression expr) */
cx_int16 Fast_Parser_initKeyValueSet(Fast_Parser _this, Fast_Expression expr) {
/* $begin(::cortex::Fast::Parser::initKeyValueSet) */
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

/* ::cortex::Fast::Parser::initMember(lang::string member) */
cx_int16 Fast_Parser_initMember(Fast_Parser _this, cx_string member) {
/* $begin(::cortex::Fast::Parser::initMember) */
    FAST_CHECK_ERRSET(_this);

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

/* ::cortex::Fast::Parser::initPop() */
cx_int16 Fast_Parser_initPop(Fast_Parser _this) {
/* $begin(::cortex::Fast::Parser::initPop) */
    FAST_CHECK_ERRSET(_this);

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

/* ::cortex::Fast::Parser::initPush() */
cx_int16 Fast_Parser_initPush(Fast_Parser _this) {
/* $begin(::cortex::Fast::Parser::initPush) */
    FAST_CHECK_ERRSET(_this);

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

/* ::cortex::Fast::Parser::initPushExpression() */
Fast_Expression Fast_Parser_initPushExpression(Fast_Parser _this) {
/* $begin(::cortex::Fast::Parser::initPushExpression) */
    Fast_Initializer initializer = NULL;
    
    _this->initializerCount++;
    
    if (_this->pass) {
        Fast_InitializerVariable_array64 variables;
        
        memset(variables, 0, sizeof(variables));
        
        /* Create initializer */
        initializer = Fast_Initializer(Fast_InitializerExpr__create(variables, 1, TRUE));
        cx_set_ext(_this, &_this->initializers[_this->initializerCount], initializer, ".initializers[.initializersCount]");
        Fast_Parser_collect(_this, initializer);
        _this->variablePushed = TRUE;
    }
    
    return Fast_Expression(initializer);
/* $end */
}

/* ::cortex::Fast::Parser::initPushIdentifier(Expression type) */
Fast_Expression Fast_Parser_initPushIdentifier(Fast_Parser _this, Fast_Expression type) {
/* $begin(::cortex::Fast::Parser::initPushIdentifier) */
    cx_typedef t;
    cx_bool isDynamic = TRUE;
    cx_bool forceStatic = FALSE;
    Fast_InitializerVariable_array64 variables;
    memset(variables, 0, sizeof(variables));
   
    CX_UNUSED(_this);
    CX_UNUSED(type);
    
    if (!type) {
        Fast_Parser_error(_this, "unresolved identifier '%s'", _this->lastFailedResolve);
        goto error;
    }
    
    t = cx_typedef(Fast_ObjectBase(type)->value);
    
    if (_this->initializerCount >= 0) {
        Fast_Initializer initializer = _this->initializers[_this->initializerCount];
        if (initializer) {
            if (!cx_instanceof(cx_typedef(Fast_DynamicInitializer_o), initializer)) {
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
    if (cx_instanceof(cx_typedef(cx_interface_o), t) && cx_interface_baseof(cx_interface(t), cx_interface(cx_type_o))) {
        forceStatic = TRUE;
    }
    
    /* Static initializers are executed during first pass */
    if ((!_this->pass && !isDynamic) || forceStatic) {
        cx_object o;
        o = cx_new(t);
        cx_set_ext(NULL, &variables[0].object, Fast_Expression(Fast_Object__create(o)), "keep object for initializer variable array");
        _this->initializers[_this->initializerCount] = Fast_Initializer(Fast_StaticInitializer__create(variables, 1));
        _this->variablePushed = TRUE;
    } else if (_this->pass && isDynamic && !forceStatic) {
        Fast_Expression newExpr, assignExpr, var;
        var = Fast_Parser_getAnonymousLocal(_this, Fast_Variable(type), TRUE);
        newExpr = Fast_Expression(Fast_NewExpr__create(type,0));
        Fast_Parser_collect(_this, newExpr);
        assignExpr = Fast_Expression(Fast_BinaryExpr__create(var, newExpr, CX_ASSIGN));
        Fast_Parser_collect(_this, assignExpr);
        Fast_Parser_addStatement(_this, Fast_Node(assignExpr));
        
        cx_set_ext(NULL, &variables[0].object, var, "keep object for initializer variable array");
        _this->initializers[_this->initializerCount] = Fast_Initializer(Fast_DynamicInitializer__create(variables, 1, FALSE));
        _this->variablePushed = TRUE;
    } else {
        cx_set_ext(_this, &_this->initializers[_this->initializerCount], NULL, ".initializers[.initializerCount]");
        _this->variablePushed = TRUE;
    }
    
    return variables[0].object;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::cortex::Fast::Parser::initPushStatic() */
cx_int16 Fast_Parser_initPushStatic(Fast_Parser _this) {
/* $begin(::cortex::Fast::Parser::initPushStatic) */
    cx_bool isLocal = _this->isLocal;
    Fast_InitializerVariable_array64 variables;
    Fast_Initializer initializer;
    cx_uint32 i;
    
    _this->initializerCount++;
    
    if (!isLocal && _this->variableCount) {
        if (Fast_Variable(_this->variables[0])->kind != FAST_Object) {
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
        cx_set_ext(_this, &variables[i].object, Fast_Expression(_this->variables[i]), ".initializers[.initializerCount]");
        variables[i].key = 0;
        variables[i].offset = 0;
    }

    if (!_this->pass) {
        /* Create initializer */
        initializer = Fast_Initializer(Fast_StaticInitializer__create(variables, _this->variableCount));
        cx_set_ext(_this, &_this->initializers[_this->initializerCount], initializer, ".initializers[.initializerCount]");
        Fast_Parser_collect(_this, initializer);
    } else {
        /* Create dummy initializer */
        initializer = Fast_Initializer__create(variables, _this->variableCount);
        cx_set_ext(_this, &_this->initializers[_this->initializerCount], initializer, ".initializers[.initializerCount]");
        Fast_Parser_collect(_this, initializer);
    }
    
    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::Parser::initStage(lang::string id,bool found) */
void Fast_Parser_initStage(Fast_Parser _this, cx_string id, cx_bool found) {
/* $begin(::cortex::Fast::Parser::initStage) */
    
    _this->staged[_this->stagedCount].name = cx_strdup(id);
    _this->staged[_this->stagedCount].line = _this->line;
    _this->staged[_this->stagedCount].column = _this->column;
    _this->staged[_this->stagedCount].found = found;
    _this->stagedCount++;

/* $end */
}

/* ::cortex::Fast::Parser::initValue(Expression expr) */
cx_int16 Fast_Parser_initValue(Fast_Parser _this, Fast_Expression expr) {
/* $begin(::cortex::Fast::Parser::initValue) */
    FAST_CHECK_ERRSET(_this);

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

/* ::cortex::Fast::Parser::isAbortSet() */
cx_bool Fast_Parser_isAbortSet(Fast_Parser _this) {
/* $begin(::cortex::Fast::Parser::isAbortSet) */
    cx_bool result = _this->abort;
    _this->abort = FALSE;
    return result;
/* $end */
}

/* ::cortex::Fast::Parser::isErrSet() */
cx_bool Fast_Parser_isErrSet(Fast_Parser _this) {
/* $begin(::cortex::Fast::Parser::isErrSet) */
    cx_bool result = _this->errSet;
    _this->errSet = FALSE;
    return result;
/* $end */
}

/* ::cortex::Fast::Parser::lookup(lang::string id,lang::object source) */
Fast_Expression Fast_Parser_lookup(Fast_Parser _this, cx_string id, cx_object source) {
/* $begin(::cortex::Fast::Parser::lookup) */
    Fast_Expression result = NULL;
    FAST_CHECK_ERRSET(_this);

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
        if (!_this->scope || _this->scope->kind == FAST_Object) {
            result = Fast_Parser_resolve(_this, id, source);
        }
    }
   
    /* If either doing a static initializer or parser is
     * doing the 2nd pass all variables should be resolvable */
    if (!result) {
        if (_this->pass || 
            ((_this->initializerCount >= 0) &&
             _this->initializers[_this->initializerCount] &&    
            cx_instanceof(cx_typedef(Fast_StaticInitializer_o), _this->initializers[_this->initializerCount]))) {
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

/* ::cortex::Fast::Parser::memberExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
Fast_Expression Fast_Parser_memberExpr(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue) {
/* $begin(::cortex::Fast::Parser::memberExpr) */
    Fast_Expression result = NULL;
    
    _this->stagingAllowed = FALSE;

    if (_this->pass) {
        cx_type t = Fast_Expression_getType(lvalue);
        if (t) {
            if (!(result = Fast_Parser_explodeCommaExpr(_this, lvalue, rvalue, Fast_Parser_expandMemberExpr, NULL))) {
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

/* ::cortex::Fast::Parser::observerDeclaration(lang::string id,Fast::Expression object,lang::eventMask mask,Fast::Object dispatcher) */
Fast_Variable Fast_Parser_observerDeclaration(Fast_Parser _this, cx_string id, Fast_Expression object, cx_eventMask mask, Fast_Object dispatcher) {
/* $begin(::cortex::Fast::Parser::observerDeclaration) */
    CX_UNUSED(object);
    CX_UNUSED(mask);
    FAST_CHECK_ERRSET(_this);
    
    _this->stagingAllowed = FALSE;
    
    Fast_Variable result = NULL;
    cx_bool isTemplate = cx_class_instanceof(cx_type_o, Fast_ObjectBase(_this->scope)->value);
    cx_string expr = NULL;
    
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
            result = Fast_Parser_observerCreate(_this, id, object, mask, expr, dispatcher);
            if (!result) {
                Fast_Parser_error(_this, "failed to create template observer");
                goto error;
            }
        }
    } else {
        Fast_Block block;
        Fast_Variable typeVar;
        cx_observer observer;
        cx_object observable = NULL;
        cx_uint32 i;

        /* Find observable */
        switch(Fast_Variable(object)->kind) {
        case FAST_Object:
            observable = Fast_ObjectBase(object)->value;
            break;
        case FAST_Template:
            /* In case of template ('this') leave observable zero */
            break;
        default:
            break;
        }

        /* Find or create observer depending on whether it is a template observer or not */
        if (isTemplate) {
            block = _this->block; /* If observer is a template the block has already been pushed by Parser::observerPush */
            /* Template observers have been created in the first pass. Look up the created observer */
            observer = cx_class_findObserver(cx_class(Fast_ObjectBase(_this->scope)->value), observable, NULL);
            result = Fast_Variable(Fast_Object__create(observer));
            Fast_Parser_collect(_this, result);
        } else {
            block = Fast_Parser_blockPush(_this, TRUE); /* Push new block on stack */

            /* If observer is not a template it has not yet been created, so create it now */
            result = Fast_Parser_observerCreate(_this, id, object, mask, expr, dispatcher);
            if (!result) {
                Fast_Parser_error(_this, "failed to create observer");
                goto error;
            }
            observer = Fast_ObjectBase(result)->value;
        }

        /* Loop parameters of observable, insert locals */
        for(i=0; i<cx_function(observer)->parameters.length; i++) {
            cx_parameter *p = &cx_function(observer)->parameters.buffer[i];
            typeVar = (Fast_Variable)Fast_Object__create(p->type);
            Fast_Block_declare(block, p->name, typeVar, TRUE, TRUE); /* Observable parameter are references */
            Fast_Parser_collect(_this, typeVar);
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

/* ::cortex::Fast::Parser::observerPop() */
void Fast_Parser_observerPop(Fast_Parser _this) {
/* $begin(::cortex::Fast::Parser::observerPop) */
    FAST_CHECK_ERRSET(_this);

    /* Deprecated */

/* $end */
}

/* ::cortex::Fast::Parser::observerPush() */
void Fast_Parser_observerPush(Fast_Parser _this) {
/* $begin(::cortex::Fast::Parser::observerPush) */
    FAST_CHECK_ERRSET(_this);

    /* Observer-implementations are parsed in the 2nd pass */
    if (_this->pass) {
        if (_this->scope->kind == FAST_Object) {
            if (cx_class_instanceof(cx_type_o, Fast_ObjectBase(_this->scope)->value)) {
                Fast_Block block;
                block = Fast_Parser_blockPush(_this, TRUE);
                Fast_Block_declareTemplate(block, "this", _this->scope, TRUE, FALSE);
            }
        } else {
            /* TODO: what if scope is variable */
        }
    }

/* $end */
}

/* ::cortex::Fast::Parser::parse() */
cx_uint32 Fast_Parser_parse(Fast_Parser _this) {
/* $begin(::cortex::Fast::Parser::parse) */
    FAST_CHECK_ERRSET(_this);

    _this->pass = 0;
    if ( fast_yparse(_this, 1, 1)) {
        printf("%s: parsed with errors (%d errors, %d warnings)\n", _this->filename, _this->errors, _this->warnings);
        goto error;
    }

    /* Reset parser-state so 2nd pass starts clean */
    Fast_Parser_reset(_this);

    /* Reset block */
    /*cx_free_ext(_this, _this->block, "Free root-block");
    _this->block = NULL;*/

    _this->pass = 1;
    if ( fast_yparse(_this, 1, 1)) {
        printf("%s: parsed with errors (%d errors, %d warnings)\n", _this->filename, _this->errors, _this->warnings);
        goto error;
    }

    /* Parse to cortex intermediate code */
    if ( Fast_Parser_toIc(_this)) {
        printf("%s: parsed with errors (%d errors, %d warnings)\n", _this->filename, _this->errors, _this->warnings);
        goto error;
    }

    return 0;
error:
    fast_err;
    return -1;
/* $end */
}

/* ::cortex::Fast::Parser::parseExpression(lang::string expr,Fast::Block block,Fast::Variable scope,uint32 line,uint32 column) */
Fast_Expression Fast_Parser_parseExpression(Fast_Parser _this, cx_string expr, Fast_Block block, Fast_Variable scope, cx_uint32 line, cx_uint32 column) {
/* $begin(::cortex::Fast::Parser::parseExpression) */
    Fast_Expression result = NULL;
    cx_string exprFinalized;

    CX_UNUSED(scope);

    if (_this->source) {
        cx_dealloc(_this->source);
    }

    exprFinalized = cx_malloc(strlen(expr) + 2);
    sprintf(exprFinalized, "%s\n", expr);

    _this->source = exprFinalized;
    
    cx_set_ext(_this, &_this->block, block, "Set rootblock for embedded expression");
    cx_set_ext(_this, &_this->scope, scope, "Set scope for embedded expression");

    // Give expression its own block 
    Fast_Parser_blockPush(_this, FALSE);
    if (fast_yparse(_this, line, column)) {
        printf("%s: expression '%s' parsed with errors\n", _this->filename, expr);
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
                if (cx_instanceof(cx_typedef(Fast_Expression_o), node)) {
                    result = Fast_Expression(node);
                } else {
                    cx_id id;
                    printf("%s: '%s' does not resolve to a valid expression (found %s).\n",
                            _this->filename, expr, Fast_Parser_id(cx_typeof(node), id));
                    goto error;
                }
            } else {
                printf("%s: expression '%s' is not allowed to contain multiple statements\n", _this->filename, expr);
                goto error;
            }
        } else {
            printf("%s: expression '%s' did not result in a statement\n", _this->filename, expr);
            goto error;
        }
    } else {
        printf("parser error: no block set in parser after parsing expression.\n");
        goto error;
    }

    return result;
error:
    return NULL;
/* $end */
}

/* ::cortex::Fast::Parser::popComplexType() */
void Fast_Parser_popComplexType(Fast_Parser _this) {
/* $begin(::cortex::Fast::Parser::popComplexType) */

    _this->complexTypeSp--;
    if (_this->complexTypeSp < 0) {
        Fast_Parser_error(_this, "parser error: complexType stack pointer below zero");
        abort();
    }

/* $end */
}

/* ::cortex::Fast::Parser::popLvalue() */
void Fast_Parser_popLvalue(Fast_Parser _this) {
/* $begin(::cortex::Fast::Parser::popLvalue) */

    _this->lvalueSp--;
    if (_this->lvalueSp < 0) {
        Fast_Parser_error(_this, "parser error: lvalue stack pointer below zero");
        abort();
    }

/* $end */
}

/* ::cortex::Fast::Parser::popScope(Fast::Variable previous) */
void Fast_Parser_popScope(Fast_Parser _this, Fast_Variable previous) {
/* $begin(::cortex::Fast::Parser::popScope) */
    FAST_CHECK_ERRSET(_this);

    /* Restore scope */
    _this->scope = previous;
/* $end */
}

/* ::cortex::Fast::Parser::postfixExpr(Fast::Expression lvalue,lang::operatorKind operator) */
Fast_Expression Fast_Parser_postfixExpr(Fast_Parser _this, Fast_Expression lvalue, cx_operatorKind operator) {
/* $begin(::cortex::Fast::Parser::postfixExpr) */
    Fast_Expression result = NULL;
    
    _this->stagingAllowed = FALSE;

    if (_this->pass) {
        result = Fast_Expression(Fast_PostfixExpr__create(lvalue, operator));
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

/* ::cortex::Fast::Parser::pushComplexType(Fast::Expression lvalue) */
void Fast_Parser_pushComplexType(Fast_Parser _this, Fast_Expression lvalue) {
/* $begin(::cortex::Fast::Parser::pushComplexType) */

    if (lvalue) {
        cx_set(&_this->complexType[_this->complexTypeSp], Fast_Expression_getType(lvalue));
    } else {
        cx_set(&_this->complexType[_this->complexTypeSp], NULL);
    }
    _this->complexTypeSp++;

/* $end */
}

/* ::cortex::Fast::Parser::pushLvalue(Fast::Expression lvalue,lang::bool isAssignment) */
void Fast_Parser_pushLvalue(Fast_Parser _this, Fast_Expression lvalue, cx_bool isAssignment) {
/* $begin(::cortex::Fast::Parser::pushLvalue) */

    cx_set_ext(_this, &_this->lvalue[_this->lvalueSp].expr, lvalue, ".lvalue[_this->lvalueSp]");
    _this->lvalue[_this->lvalueSp].isAssignment = isAssignment;
    _this->lvalueSp++;

/* $end */
}

/* ::cortex::Fast::Parser::pushReturnAsLvalue(lang::function function) */
void Fast_Parser_pushReturnAsLvalue(Fast_Parser _this, cx_function function) {
/* $begin(::cortex::Fast::Parser::pushReturnAsLvalue) */
    Fast_Expression result = NULL;

    if (_this->pass) {
        if (function->returnType) {
            cx_id id;
            cx_signatureName(cx_nameof(Fast_ObjectBase(function)->value), id);
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

/* ::cortex::Fast::Parser::pushScope() */
Fast_Variable Fast_Parser_pushScope(Fast_Parser _this) {
/* $begin(::cortex::Fast::Parser::pushScope) */
    Fast_Variable oldScope = NULL;

    FAST_CHECK_ERRSET(_this);

    oldScope = _this->scope;
    if (!_this->variableCount) {
        /* This is the result of a previous error */
        goto error;
    }

    _this->scope = _this->variables[0];
    Fast_Parser_reset(_this);

    return oldScope;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::cortex::Fast::Parser::reset() */
void Fast_Parser_reset(Fast_Parser _this) {
/* $begin(::cortex::Fast::Parser::reset) */
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
                printf("%s:%d:%d error: unresolved identifier '%s'\n",
                       _this->filename, _this->staged[i].line, _this->staged[i].column, _this->staged[i].name);
                fast_err;
            }
            cx_dealloc(_this->staged[i].name);
            _this->staged[i].name = NULL;
        }
    }
    _this->stagedCount = 0;

/* $end */
}

/* ::cortex::Fast::Parser::ternaryExpr(Fast::Expression cond,Fast::Expression iftrue,Fast::Expression iffalse) */
Fast_Expression Fast_Parser_ternaryExpr(Fast_Parser _this, Fast_Expression cond, Fast_Expression iftrue, Fast_Expression iffalse) {
/* $begin(::cortex::Fast::Parser::ternaryExpr) */
    Fast_Expression result = NULL;

    if (_this->pass) {
        Fast_Expression lvalue = Fast_Parser_getLvalue(_this, TRUE);

        if (!lvalue) {
            lvalue = Fast_Parser_getAnonymousLocal(_this, iftrue->type, FALSE);
        }
        result = Fast_Expression(Fast_TernaryExpr__create(cond, iftrue, iffalse, lvalue));
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

/* ::cortex::Fast::Parser::unaryExpr(Fast::Expression lvalue,lang::operatorKind operator) */
Fast_Expression Fast_Parser_unaryExpr(Fast_Parser _this, Fast_Expression lvalue, cx_operatorKind operator) {
/* $begin(::cortex::Fast::Parser::unaryExpr) */
    Fast_Expression result = NULL;

    _this->stagingAllowed = FALSE;
    
    if (lvalue) {
        if (operator == CX_SUB) {
            cx_type lvalueType = Fast_Expression_getType(lvalue);

            if (lvalueType->kind == CX_PRIMITIVE) {
                switch(cx_primitive(lvalueType)->kind) {
                case CX_INTEGER:
                    if (Fast_Node(lvalue)->kind == FAST_Literal) {
                        result = Fast_Expression(Fast_Integer__create(Fast_Integer(lvalue)->value * -1));
                        Fast_Parser_collect(_this, result);
                        break;
                    }
                    /* no break */
                case CX_UINTEGER:
                    if (Fast_Node(lvalue)->kind == FAST_Literal) {
                        result = Fast_Expression(Fast_SignedInteger__create(Fast_Integer(lvalue)->value * -1));
                        Fast_Parser_collect(_this, result);
                        break;
                    }
                    /* no break */
                case CX_FLOAT:
                    if (Fast_Node(lvalue)->kind == FAST_Literal) {
                        result = Fast_Expression(Fast_FloatingPoint__create(Fast_FloatingPoint(lvalue)->value * -1));
                        Fast_Parser_collect(_this, result);
                    } else {
                        if (_this->pass) {
                            Fast_SignedInteger minusOne = Fast_SignedInteger__create(-1);
                            Fast_Parser_collect(_this, minusOne);
                            result = Fast_Expression(Fast_BinaryExpr__create(lvalue, Fast_Expression(minusOne), CX_MUL));
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
            if (Fast_Node(lvalue)->kind == FAST_Variable) {
                if (lvalue->isReference) {
                    if (Fast_Variable(lvalue)->kind == FAST_Local) {
                        Fast_Local local = Fast_Local(lvalue);
                        result = Fast_Expression(Fast_Local__create(
                            local->name,
                            local->type,
                            local->kind == FAST_LocalParameter,
                            local->isReference));
                        result->forceReference = TRUE;
                    } else if (Fast_Variable(lvalue)->kind == FAST_Object) {
                        Fast_Object object = Fast_Object(lvalue);
                        result = Fast_Expression(Fast_Object__create(Fast_ObjectBase(object)->value));
                        result->forceReference = TRUE;
                    }
                } else {
                    Fast_Parser_error(_this, "cannot take reference from non-reference variable");
                    goto error;
                }
            } else {
                lvalue->forceReference = TRUE;
                result = lvalue;
            }
        } else {
            if (_this->pass) {
                result = Fast_Expression(Fast_UnaryExpr__create(lvalue, operator));
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

/* ::cortex::Fast::Parser::updateStatement(Fast::Expression expr,Fast::Block block) */
Fast_Node Fast_Parser_updateStatement(Fast_Parser _this, Fast_Expression expr, Fast_Block block) {
/* $begin(::cortex::Fast::Parser::updateStatement) */
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
                    from = Fast_Parser_lookup(_this, "this", NULL);
                }
            }
        }

        /* Keep argument expressions */
        exprList = Fast_Expression_toList(expr);
        result = Fast_Node(Fast_Update__create(exprList, block, from));
        Fast_Parser_collect(_this, result);
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::cortex::Fast::Parser::waitExpr(list{Fast::Expression} exprList,Fast::Expression timeout) */
Fast_Expression Fast_Parser_waitExpr(Fast_Parser _this, Fast_Expression_list exprList, Fast_Expression timeout) {
/* $begin(::cortex::Fast::Parser::waitExpr) */
    Fast_Expression result = NULL;
    
    _this->stagingAllowed = FALSE;

    if (_this->pass) {
        Fast_Expression expr;
        cx_iter exprIter;

        /* Keep argument expressions */
        if (exprList) {
            exprIter = cx_llIter(exprList);
            while(cx_iterHasNext(&exprIter)) {
                expr = cx_iterNext(&exprIter);
                if (expr) {
                    cx_keep_ext(result, expr, "Keep expression for waitlist");
                }
            }
        }

        result = Fast_Expression(Fast_Wait__create(exprList, timeout));

        Fast_Parser_collect(_this, result);
    } else {
        if (exprList) {
            cx_llFree(exprList);
        }
    }

    return result;
/* $end */
}

/* ::cortex::Fast::Parser::whileStatement(Fast::Expression condition,Fast::Block trueBranch,lang::bool isUntil) */
Fast_Node Fast_Parser_whileStatement(Fast_Parser _this, Fast_Expression condition, Fast_Block trueBranch, cx_bool isUntil) {
/* $begin(::cortex::Fast::Parser::whileStatement) */
    Fast_Node result = NULL;
    
    _this->stagingAllowed = FALSE;

    if (_this->pass) {
        result = Fast_Node(Fast_While__create(condition, trueBranch, isUntil));
        if (!result) {
            goto error;
        }
        Fast_Parser_collect(_this, result);
        
        if (isUntil) {
            cx_set_ext(_this->block, &_this->block->_while, result, "block->_while");
        }
    }

    return result;
error:
    fast_err;
    return NULL;
/* $end */
}
