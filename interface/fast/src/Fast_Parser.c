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
#define FAST_CHECK_ERRSET(parser) db_assert(!parser->errSet, "%s:%d:%d: parser did not check error-status set on line %d", _this->filename, _this->line, _this->column, _this->errLine)
/*#define FAST_PARSER_DEBUG*/
#define fast_err _this->errSet = TRUE; _this->errLine = __LINE__;

#include "db.h"
#include "stdio.h"
#include "Fast__api.h"
#include "Fast__meta.h"
#include "Fast.h"
#include "db_ll.h"
#include "db_loader.h"
#include "Fast_Block.h"
#include "Fast_CommaExpr.h"
#include "Fast_Expression.h"
#include "Fast_Initializer.h"
#include "Fast_InitializerExpr.h"
#include "Fast_TernaryExpr.h"
#include "db__api.h"
#include "db_string_ser.h"
#include "db_vm.h"
int fast_yparse(Fast_Parser parser, db_uint32 line, db_uint32 column);

void Fast_Parser_error(Fast_Parser _this, char* fmt, ... ) {
	va_list args;
	char msgbuff[1024];

	va_start(args, fmt);
	vsprintf(msgbuff, fmt, args);
	va_end(args);

#ifdef FAST_PARSER_DEBUG
    if (_this->initializerCount >= 0) {
        printf("%s:%d:%d (pass=%d, initCount=%d, initializer=%p) error: %s near '%s'\n",
               _this->filename, _this->line, _this->column,
               _this->pass, _this->initializerCount, _this->initializers[_this->initializerCount],
               msgbuff, _this->token);
    } else {
        printf("%s:%d:%d (pass=%d, initCount=%d) error: %s near '%s'\n",
               _this->filename, _this->line, _this->column, _this->pass, _this->initializerCount,
               msgbuff, _this->token);
    }
#else
    if (_this->token) {
        printf("%s:%d:%d error: %s near '%s'\n", _this->filename, _this->line, _this->column, msgbuff, _this->token);
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
static db_string Fast_Parser_id(db_object o, db_id buffer) {
    if (db_checkAttr(o, DB_ATTR_SCOPED)) {
        db_fullname(o, buffer);
    } else {
        db_id tmp;
        db_string_ser_t serData;
        struct db_serializer_s s;
        serData.buffer = tmp;
        serData.length = sizeof(db_id);
        serData.maxlength = sizeof(db_id)-strlen("<anonymous>");
        serData.compactNotation=TRUE;
        serData.prefixType = TRUE;
        s = db_string_ser(DB_LOCAL, DB_NOT, DB_SERIALIZER_TRACE_NEVER);
        db_serialize(&s, o, &serData);
        strcpy(buffer, tmp);
    }
    return buffer;
}

/* Translate result of parser to hyve intermediate bytecode */
db_int16 Fast_Parser_toIc(Fast_Parser _this) {
	db_icProgram program = db_icProgram__create(_this->filename);
	Fast_Binding *binding;
	db_iter bindingIter;
	db_icScope scope;
	db_icStorage returnValue = NULL;
	db_vmProgram vmProgram;

	/* Parse root-block */
	Fast_Block_toIc(_this->block, program, NULL	, FALSE);
	if (_this->errors) {
		goto error;
	}

	/* Parse functions */
	if (_this->bindings) {
	    bindingIter = db_llIter(_this->bindings);
	    while(db_iterHasNext(&bindingIter)) {
	        db_ic ret;
	        binding = db_iterNext(&bindingIter);
	        db_icProgram_functionPush(program, Fast_Node(binding->impl)->line, binding->function);
	        scope = (db_icScope)Fast_Block_toIc(binding->impl, program, NULL, FALSE);
	        if (_this->errors) {
	        	goto error;
	        }
	        if (binding->function->returnType && ((binding->function->returnType->real->kind != DB_VOID) || (binding->function->returnType->real->reference))) {
	            db_id name;
	            db_signatureName(db_nameof(binding->function), name);
	            returnValue = db_icScope_lookupStorage(scope, name, TRUE);
	            ret = (db_ic)db_icOp__create(program, _this->line, DB_IC_RET, (db_icValue)returnValue, NULL, NULL);
                if (binding->function->returnsReference) {
                    ((db_icStorage)returnValue)->isReference = TRUE;
                    ((db_icOp)ret)->s1Deref = DB_IC_DEREF_ADDRESS;
                }else {
                    ((db_icOp)ret)->s1Deref = DB_IC_DEREF_VALUE;
                }
	        } else {
	            ret = (db_ic)db_icOp__create(program, _this->line, DB_IC_STOP, NULL, NULL, NULL);
	        }

	        db_icScope_addIc(scope, ret);
	        db_icProgram_scopePop(program, _this->line);

	        db_free_ext(_this, binding->function, "Free binding for function");
	        db_free_ext(_this, binding->impl, "Free binding for function (impl)");
	        db_dealloc(binding);
	    }
	    db_llFree(_this->bindings);
	    _this->bindings = NULL;
	}

	/* Print program */
#ifdef DB_IC_TRACING
    extern db_bool DB_DEBUG_ENABLED;
    if (DB_DEBUG_ENABLED) {
        db_string programStr;
        programStr = db_icProgram_toString(program);
        printf("%s\n", programStr);
        db_dealloc(programStr);
    }
#endif

	/* Translate program to vm code */
	vmProgram = db_icProgram_toVm(program);

	/* Run vm program */
    if (vmProgram) {
        db_vm_run(vmProgram, NULL);
    }
    
    /* Free program */
    db_icProgram__free(program);
    db_vmProgram_free(vmProgram);

	return 0;
error:
	return -1;
}

/* Get anonymous variable */
Fast_Expression Fast_Parser_getAnonymousLocal(Fast_Parser _this, Fast_Variable type, db_bool isReference) {
    db_id id;
    Fast_Expression result;
    sprintf(id, "<%d>", _this->initAnonymousId); _this->initAnonymousId++; /* Make sure to create a new local for each anonymous object */
    result = Fast_Expression(Fast_Block_declare(_this->block, id, Fast_Variable(type), FALSE, isReference));
    // Fast_Parser_collect(_this, result);
    return result;
}

/* Translate binary expressions on composite values to corresponding operations */
Fast_Expression Fast_Parser_binaryCompositeExpr(Fast_Parser _this, Fast_Expression operand1, Fast_Expression operand2, db_operatorKind operator) {
    Fast_Expression result = NULL;

    if (operator == DB_ASSIGN) {
        if(Fast_Node(operand2)->kind == FAST_Initializer) {
            if (Fast_InitializerExpr_insert(Fast_InitializerExpr(operand2), operand1)) {
                goto error;
            }
            result = operand1;
        } else if (!(result = Fast_Expression(Fast_createMethodCall(operand1, "copy", 1, operand2)))) {
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
Fast_Expression Fast_Parser_binaryCollectionExpr(Fast_Parser _this, Fast_Expression operand1, Fast_Expression operand2, db_operatorKind operator) {
    Fast_Expression result = NULL;
    db_type tleft = Fast_Expression_getType_expr(operand1, operand2);
    db_type tright = Fast_Expression_getType_expr(operand2, operand1);
    db_bool leftToRight = FALSE, rightToLeft = FALSE, equality = FALSE;

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
        if (tleft->kind == DB_COLLECTION) {
            if (db_type_castable(tleft, tright)) {
                equality = TRUE;
                rightToLeft = TRUE;
            }
            if (db_type_castable(db_collection(tleft)->elementType->real, tright)) {
                rightToLeft = TRUE;
            }
        }
    
        /* Both conditions can be true in case of recursive elementTypes, but rightToLeft takes precedence */
        if (tright->kind == DB_COLLECTION) { 
            if (db_type_castable(db_collection(tright)->elementType->real, tleft)) {
                leftToRight = TRUE;
            }
        }
    }

    if (!(rightToLeft || leftToRight || equality)) {
        db_id id1, id2;
        Fast_Parser_error(_this, "collection-expression types do not match (left: %s, right: %s)",
                          Fast_Parser_id(tleft, id1),
                          Fast_Parser_id(tright, id2));
        printf("   valid options:\n");
        if (tleft->kind == DB_COLLECTION) {
            printf("      left: %s right: %s\n", Fast_Parser_id(tleft, id1), Fast_Parser_id(db_collection(tleft)->elementType, id2));
            printf("      left: %s right: %s\n", Fast_Parser_id(tleft, id1), Fast_Parser_id(tleft, id1));
        }
        if (tright->kind == DB_COLLECTION) {
            printf("      left: %s right: %s\n", Fast_Parser_id(db_collection(tright)->elementType, id1), Fast_Parser_id(tright, id2));
            printf("      left: %s right: %s\n", Fast_Parser_id(tright, id1), Fast_Parser_id(tright, id1));
        }
        goto error;
    }
    
    Fast_Expression collection = rightToLeft ? operand1 : operand2;
    Fast_Expression operand = rightToLeft ? operand2 : operand1;
    Fast_Expression castedOperand = operand;
    db_collection collectionType = db_collection(Fast_Expression_getType(collection));
    
    switch(operator) {
        case DB_ASSIGN:
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
                if (!(result = Fast_Expression(Fast_createMethodCall(collection, "copy", 1, operand)))) {
                    goto error;
                }
                break;
            } else {
                if (!(result = Fast_Expression(Fast_createMethodCall(collection, "clear", 0)))) {
                    goto error;
                }
            }
        case DB_ASSIGN_ADD: {
            Fast_Expression localResult = NULL;
            
            /* Cast operand to elementType */
            if (!equality && Fast_Expression_getType(operand) != collectionType->elementType->real) {
                if (collectionType->elementType->real->reference || (collectionType->elementType->real->kind == DB_PRIMITIVE)) {
                    castedOperand = Fast_Expression_cast(operand, collectionType->elementType->real);
                    if (!castedOperand) {
                        castedOperand = operand;
                    }
                }
            } else {
                if (Fast_Node(collection)->kind == FAST_Initializer) {
                    castedOperand = Fast_Expression_cast(collection, tleft);
                    collection = operand;
                } else if (Fast_Node(operand)->kind == FAST_Initializer) {
                    castedOperand = Fast_Expression_cast(operand, tleft);
                } else {
                    castedOperand = operand;
                }
            }
            
            /* Create merge, insert or append */
            if (rightToLeft || (equality && (Fast_Node(operand)->kind != FAST_Initializer))) {
                if (!(localResult = Fast_Expression(Fast_createMethodCall(collection, "append", 1, castedOperand)))) {
                    goto error;
                }
            } else {
                if (!(localResult = Fast_Expression(Fast_createMethodCall(collection, "insert", 1, castedOperand)))) {
                    goto error;
                }
            }
            result = Fast_CommaExpr_addOrCreate(result, localResult);

            break;
        }
        case DB_DEC:
            break;
        case DB_COND_EQ:
            break;
        case DB_COND_NEQ:
            break;
        case DB_COND_LT:
            break;
        case DB_COND_GT:
            break;
        case DB_COND_LTEQ:
            break;
        case DB_COND_GTEQ:
            break;
        default:
            Fast_Parser_error(_this, "invalid operator %s for collection-operand",
                              db_nameof(db_enum_constant(db_operatorKind_o, operator)));
            goto error;
            break;
    }
    
    return result;
error:
    return NULL;
}


/* Use db_object as returntype as the actual type (Fast_Expression) causes macro-expansion */
typedef db_object (*Fast_ExpandAction)(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue, void *userData);

/* Combine results in new comma expression */
db_object Fast_Parser_combineCommaExpr(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue, void *userData) {
    DB_UNUSED(_this);
    DB_UNUSED(userData);
    return Fast_CommaExpr_addOrCreate(lvalue, rvalue);
}

/* Combine results as part of conditional expression */
db_object Fast_Parser_combineConditionalExpr(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue, void *userData) {
    db_operatorKind oper = *(db_operatorKind*)userData;
    db_operatorKind combineOper;
    Fast_Expression result;
    
    /* Default combine is AND, except the != operator, which inserts an OR */
    if (lvalue) {
        if (oper == DB_COND_NEQ) {
            combineOper = DB_COND_OR;
        } else {
            combineOper = DB_COND_AND;
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
Fast_Expression Fast_Parser_createBinaryTernaryExpr(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue, db_operatorKind operator) {
    Fast_Expression result = NULL;
    DB_UNUSED(_this);
    
    /* If the operation is an assignment, the ternary operator has already constructed the binary operation through an lvalue - see
     * the implementation of Fast_Parser_TernaryExpr. If the operation is not an assignment, create the binary expression. */
    switch(operator) {
    case DB_ASSIGN:
    case DB_ASSIGN_ADD:
    case DB_ASSIGN_SUB:
    case DB_ASSIGN_MUL:
    case DB_ASSIGN_DIV:
    case DB_ASSIGN_MOD:
    case DB_ASSIGN_OR: 
    case DB_ASSIGN_AND:
        Fast_TernaryExpr_setOperator(Fast_TernaryExpr(rvalue), operator);
        db_set_ext(NULL, &result, rvalue, "?? set rvalue to result value of function");
        break;
    default:
        result = Fast_Expression(Fast_BinaryExpr__create(lvalue, rvalue, operator));
        Fast_Parser_collect(_this, result);
        break;
    } 
    
    return result;
}

/* Callback function for expansion of binary expressions */
db_object Fast_Parser_expandBinaryExpr(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue, void *userData) {
    Fast_Expression result = NULL;
    db_type tleft, tright;
    db_bool isReference, forceReference;

    tleft = Fast_Expression_getType_expr(lvalue,rvalue);
    tright = Fast_Expression_getType_expr(rvalue,lvalue);

    forceReference = lvalue->forceReference || rvalue->forceReference;
    isReference = forceReference || (tleft && tleft->reference) || (tright && tright->reference);

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
        result = Fast_Parser_createBinaryTernaryExpr(_this, lvalue, rvalue, *(db_operatorKind*)userData);
    
    /* Binary expression with non-reference composite values */
    } else if (!isReference && ((tleft && (tleft->kind == DB_COMPOSITE)) && (tright && (tright->kind == DB_COMPOSITE)))) {
        result = Fast_Parser_binaryCompositeExpr(_this, lvalue, rvalue, *(db_operatorKind*)userData);

    /* Binary expression with non-reference collection values */
    } else if (!forceReference && ((tleft && (tleft->kind == DB_COLLECTION)) || (tright && (tright->kind == DB_COLLECTION)))) {
        result = Fast_Parser_binaryCollectionExpr(_this, lvalue, rvalue, *(db_operatorKind*)userData);

    /* Binary expression with primitive or reference values */
    } else {
        if (Fast_Node(rvalue)->kind == FAST_Initializer) {
            if (Fast_InitializerExpr_insert(Fast_InitializerExpr(rvalue), lvalue)) {
                goto error;
            }
            result = lvalue;  
        } else {
            result = Fast_Expression(Fast_BinaryExpr__create(lvalue, rvalue, *(db_operatorKind*)userData));

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
db_object Fast_Parser_expandMemberExpr(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue, void *userData) {
    DB_UNUSED(userData);
    DB_UNUSED(_this);
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
db_object Fast_Parser_expandElementExpr(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue, void *userData) {
    DB_UNUSED(_this);
    DB_UNUSED(userData);
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
    db_ll lvalueList, rvalueList;
    Fast_Expression result = NULL;
    Fast_Expression var = NULL;
    db_uint32 lvalueCount, rvalueCount;
    
    lvalueList = Fast_Expression_toList(lvalues);
    rvalueList = Fast_Expression_toList(rvalues);
    lvalueCount = db_llSize(lvalueList);
    rvalueCount = db_llSize(rvalueList);

    if ((rvalueCount > 1) && (lvalueCount == 1)) {
        /* Only temporarily store rvalue if it has side effects */
        if (Fast_Expression_hasSideEffects(Fast_Expression(db_llGet(lvalueList,0)))) {
            if (Fast_Node(rvalues)->kind != FAST_Initializer) {
                var = Fast_Parser_getAnonymousLocal(_this, lvalues->type, FALSE);
                Fast_Expression assign = Fast_Parser_binaryExpr(_this, var, lvalues, DB_ASSIGN);
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
    db_int16 lvalueCount, rvalueCount;
    db_ll lvalueList, rvalueList;
    db_iter lIter, rIter;
    db_type tleft, tright;
    Fast_Expression result = NULL, localResult = NULL;
    enum {
        EXPAND_LEFT,
        EXPAND_RIGHT,
        EXPAND_BOTH
    } expandMode = EXPAND_LEFT; /* Expand left, right or both */
    
    lvalueList = Fast_Expression_toList(lvalues);
    rvalueList = Fast_Expression_toList(rvalues);
    lvalueCount = db_llSize(lvalueList);
    rvalueCount = db_llSize(rvalueList);
    
    /* If there is more than one lvalue assign rvalue to temporary value first. This will assure that rvalue is evaluated
     * only once. */
    if ((lvalueCount > 1) && (rvalueCount == 1)) {
        /* Only temporarily store rvalue if it has side effects */
        if (Fast_Expression_hasSideEffects(Fast_Expression(db_llGet(rvalueList,0)))) {
            if (Fast_Node(rvalues)->kind != FAST_Initializer) {
                Fast_Expression var = Fast_Parser_getAnonymousLocal(_this, rvalues->type, FALSE);
                Fast_Expression assign = Fast_Parser_binaryExpr(_this, var, rvalues, DB_ASSIGN);
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
                          db_llSize(lvalueList), db_llSize(rvalueList));
        goto error;
    }
    
    /* Loop through lvalues */
    lIter = db_llIter(lvalueList);
    rIter = db_llIter(rvalueList);
    Fast_Expression lvalue = lvalues;
    while((((expandMode == EXPAND_LEFT)||(expandMode == EXPAND_BOTH)) && db_iterHasNext(&lIter)) || ((expandMode == EXPAND_RIGHT) && db_iterHasNext(&rIter))) {
        
        /* If rvalueList is greater than 1, loop through rvalues as well */
        switch(expandMode) {
            case EXPAND_BOTH:
                rvalues = db_iterNext(&rIter);
            case EXPAND_LEFT:
                lvalue = db_iterNext(&lIter);
                break;
            case EXPAND_RIGHT:
                rvalues = db_iterNext(&rIter);
                break;
        }
        
        /* Instantiate lvalue and rvalue into action-specific object */
        localResult = action(_this, lvalue, rvalues, userData);

        tleft = Fast_Expression_getType_expr(lvalue,rvalues);
        tright = Fast_Expression_getType_expr(rvalues,lvalue);
        if (!tleft || !tright) {
            db_id id;
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

Fast_Expression Fast_Parser_resolve(Fast_Parser _this, db_id id, db_object source) {
	Fast_Expression result = NULL;
	db_object object;
    db_object parent = _this->scope ? Fast_ObjectBase(_this->scope)->value : NULL;
    db_char *ptr, ch;
    db_id buffer;
    db_char *bptr;

    if (strchr(id, ':')) {
    	ptr = id;
    	bptr = buffer;
    	do {
			object = db_resolve_ext(source, parent, id, FALSE, NULL);
			if (object){
				result = Fast_Expression(Fast_Object__create(object));
				Fast_Parser_collect(_this, result);
				db_free_ext(source, object, NULL);
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
					oldEcho = db_toggleEcho(FALSE);
					db_load(buffer);
					db_toggleEcho(oldEcho);
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
		object = db_resolve_ext(source, parent, id, FALSE, NULL);
		if (!object){
            db_object rvalueType = Fast_Parser_getLvalueType(_this, FALSE);
			if (rvalueType && db_checkAttr(rvalueType, DB_ATTR_SCOPED)) {
				object = db_resolve_ext(source, rvalueType, id, FALSE, NULL);
			}
		}
		if (object) {
			result = Fast_Expression(Fast_Object__create(object));
			Fast_Parser_collect(_this, result);
			db_free_ext(source, object, NULL);
		}
    }

    return result;
error:
	Fast_Parser_error(_this, "unresolved identifier '%s'", id);
	fast_err;
	return NULL;
}

/* Create an observer */
Fast_Variable Fast_Parser_observerCreate(Fast_Parser _this, db_string id, Fast_Expression object, db_eventMask mask, db_string expr, Fast_Object dispatcherVar) {
	Fast_Variable result = NULL;
    db_observer observer;
    db_object observable = NULL;
    db_object parent;
    db_object dispatcher = NULL;

	/* If object is zero, this indicates either a template local or an expression during the 1st pass. TODO: how to handle
	 * declaring expressions in the 1st pass - possible solution is setting the expression in the 2nd pass but then how can
	 * the observer be identified?
	 */


	parent = Fast_ObjectBase(_this->scope)->value;
	if (!db_class_instanceof(db_type_o, parent)) {
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
	if (!(mask & DB_ON_VALUE)) {
		mask |= DB_ON_METAVALUE;
	}

	/* Create observer */
	if (!id) {
		observer = db_observer__create(observable, mask, expr, FALSE, dispatcher, NULL);
		if (!observer) {
			goto error;
		}
		db_attach(Fast_ObjectBase(_this->scope)->value, observer);

		/* If observer is a template observer, manually attach */
		if (parent) {
			db_class_bindObserver(db_class(parent), observer);
		}
	} else {
		observer = db_observer__declare(Fast_ObjectBase(_this->scope)->value, id);
		if (!observer) {
			goto error;
		}
		if (db_observer__define(observer, observable, mask, expr, FALSE, dispatcher, NULL)) {
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

/* $end */

/* ::hyve::Fast::Parser::addStatement(Fast::Node statement) */
void Fast_Parser_addStatement(Fast_Parser _this, Fast_Node statement) {
/* $begin(::hyve::Fast::Parser::addStatement) */
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
                if (db_instanceof(db_typedef(Fast_Expression_o), statement)) {
                    if (!Fast_Expression_hasSideEffects(Fast_Expression(statement))) {
                        /* TODO: Fast_Parser_warning(_this, "computed value is not used (%s)", db_nameof(db_typeof(statement))); */
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

/* ::hyve::Fast::Parser::argumentToString(Fast::Variable type,lang::string id,lang::bool reference) */
db_string Fast_Parser_argumentToString(Fast_Parser _this, Fast_Variable type, db_string id, db_bool reference) {
/* $begin(::hyve::Fast::Parser::argumentToString) */
	db_string str;
	db_object type_o;
	db_string result;
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

	if (!db_class_instanceof(db_typedef_o, type_o)) {
		db_id id;
		Fast_Parser_error(_this, "object '%s' used in parameter expression is not a type", Fast_Parser_id(type_o, id));
		goto error;
	}

	if (db_checkAttr(type_o, DB_ATTR_SCOPED)) {
		db_id id;
		str = strdup(Fast_Parser_id(type_o, id));
	} else {
		str = db_toString(type_o, 0);
	}

	result = db_malloc(strlen(str) + 1 + strlen(id) + 1 + 1);

	if (reference) {
		sprintf(result, "%s& %s", str, id);
	} else {
		sprintf(result, "%s %s", str, id);
	}

	db_dealloc(str);

	return result;
error:
    fast_err;
	return NULL;
/* $end */
}

/* ::hyve::Fast::Parser::binaryExpr(Fast::Expression lvalues,Fast::Expression rvalues,lang::operatorKind operator) */
Fast_Expression Fast_Parser_binaryExpr(Fast_Parser _this, Fast_Expression lvalues, Fast_Expression rvalues, db_operatorKind operator) {
/* $begin(::hyve::Fast::Parser::binaryExpr) */
    Fast_Expression result = NULL;
    FAST_CHECK_ERRSET(_this);
    
    _this->stagingAllowed = FALSE;
    
    if (lvalues && rvalues && (_this->pass || ((_this->initializerCount >= 0) && _this->initializers[_this->initializerCount]))) {
        Fast_ExpandAction combine = Fast_Parser_combineCommaExpr;
        switch(operator) {
        case DB_COND_EQ:
        case DB_COND_NEQ:
        case DB_COND_AND:
        case DB_COND_OR:
        case DB_COND_GT:
        case DB_COND_LT:
        case DB_COND_GTEQ:
        case DB_COND_LTEQ:
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

/* ::hyve::Fast::Parser::bind(Fast::Variable function,Fast::Block block) */
db_int16 Fast_Parser_bind(Fast_Parser _this, Fast_Variable function, Fast_Block block) {
/* $begin(::hyve::Fast::Parser::bind) */
    Fast_Binding *binding;
    FAST_CHECK_ERRSET(_this);

    if (_this->pass) {
        if (function->kind == FAST_Object) {
            binding = db_calloc(sizeof(Fast_Binding));
            binding->function = Fast_ObjectBase(function)->value; db_keep_ext(_this, binding->function, "Create binding for function");
            binding->impl = block; db_keep_ext(_this, block, "Create binding for function (impl)");
            db_assert(_this->bindings != NULL, "initialization failed");
            db_llAppend(_this->bindings, binding);
        }
    }

    return 0;
/* $end */
}

/* ::hyve::Fast::Parser::bindOneliner(Fast::Variable function,Fast::Block block,Fast::Expression expr) */
db_int16 Fast_Parser_bindOneliner(Fast_Parser _this, Fast_Variable function, Fast_Block block, Fast_Expression expr) {
/* $begin(::hyve::Fast::Parser::bindOneliner) */
    FAST_CHECK_ERRSET(_this);

	if (_this->pass) {
		Fast_Expression returnLocal;
		db_id functionName;

		/* Add oneliner to block */
		db_signatureName(db_nameof(Fast_ObjectBase(function)->value), functionName);
		returnLocal = Fast_Block_lookup(block, functionName);
 		if (returnLocal) {
			Fast_Expression returnAssign;
			returnAssign = Fast_Expression(Fast_Parser_binaryExpr(_this, returnLocal, expr, DB_ASSIGN));
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

/* ::hyve::Fast::Parser::blockPop() */
void Fast_Parser_blockPop(Fast_Parser _this) {
/* $begin(::hyve::Fast::Parser::blockPop) */
    FAST_CHECK_ERRSET(_this);

    /* Blocks are parsed only in 2nd pass */
    if (_this->pass) {
    	if (_this->block) {
			db_set_ext(_this, &_this->block, _this->block->parent, "pop block");
			_this->blockPreset = FALSE;
    	} else {
    		/* Got confused by earlier errors */
    	    Fast_Parser_error(_this, "unable to continue parsing due to previous errors");
    	    _this->abort = TRUE;
    	}
    }

/* $end */
}

/* ::hyve::Fast::Parser::blockPush(lang::bool presetBlock) */
Fast_Block Fast_Parser_blockPush(Fast_Parser _this, db_bool presetBlock) {
/* $begin(::hyve::Fast::Parser::blockPush) */
    FAST_CHECK_ERRSET(_this);

    /* Blocks are parsed only in 2nd pass */
    if (_this->pass) {
        Fast_Block newBlock;

        newBlock = NULL;

        if (!_this->blockPreset || presetBlock) {
            newBlock = Fast_Block__create(_this->block);
            Fast_Parser_collect(_this, newBlock);
            db_set_ext(_this, &_this->block, newBlock, "push block");
        }

        _this->blockPreset = presetBlock;

        return newBlock;
    } else {
        return NULL;
    }
/* $end */
}

/* ::hyve::Fast::Parser::callExpr(Fast::Expression function,Fast::Expression arguments) */
Fast_Expression Fast_Parser_callExpr(Fast_Parser _this, Fast_Expression function, Fast_Expression arguments) {
/* $begin(::hyve::Fast::Parser::callExpr) */
	Fast_Expression result = NULL;
    
    _this->stagingAllowed = FALSE;

    if (_this->pass) {
        db_object o = NULL;
        Fast_Expression_list functions = Fast_Expression_toList(function);

        Fast_Expression_list__foreach(functions, f)
            Fast_Expression expr;
        
            if ((Fast_Node(f)->kind == FAST_Variable) && (Fast_Variable(f)->kind == FAST_Object)) {
                o = Fast_ObjectBase(f)->value;
            }
            /* If function is a type, insert cast */
            if (o && db_instanceof(db_typedef(db_type_o), o)) {
                db_ll exprs = Fast_Expression_toList(arguments);
                if (db_llSize(exprs) != 1) {
                    Fast_Parser_error(_this, "invalid number of parameters for cast (expected 1)");
                    Fast_Expression_cleanList(exprs);
                    goto error;
                }
                expr = Fast_Parser_castExpr(_this, f, db_llGet(exprs, 0));
                Fast_Expression_cleanList(exprs);
            } else {
                expr = Fast_Expression(Fast_Call__create(f, arguments));
            }
            if (!expr) {
                goto error;
            }

            Fast_Parser_collect(_this, expr);

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

/* ::hyve::Fast::Parser::castExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
Fast_Expression Fast_Parser_castExpr(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue) {
/* $begin(::hyve::Fast::Parser::castExpr) */
	Fast_Expression result = NULL;
    
    _this->stagingAllowed = FALSE;

    if (_this->pass) {
        db_type lvalueType, rvalueType;
        db_bool castRequired = TRUE;

        /* If cast is an upcast, don't insert cast operation since these are always allowed */
        if ((Fast_Node(lvalue)->kind == FAST_Variable) && (Fast_Variable(lvalue)->kind == FAST_Object)) {
            lvalueType = Fast_ObjectBase(lvalue)->value;
        } else {
            Fast_Parser_error(_this, "casting to a dynamic type not yet supported");
            goto error;
        }
        rvalueType = Fast_Expression_getType(rvalue);

        if (lvalueType == rvalueType) {
            db_id id;
            Fast_Parser_warning(_this, "casting to value of the same type (%s)", Fast_Parser_id(lvalueType, id));
            castRequired = FALSE;
        } else {
            if ((lvalueType->kind == DB_COMPOSITE) && (rvalueType->kind == DB_COMPOSITE)) {
                if (db_type_castable(lvalueType, rvalueType)) {
                    db_id id1, id2;
                    castRequired = FALSE;
                    Fast_Parser_warning(_this, "upcasting from '%s' to '%s' does not require an explicit cast",
                            Fast_Parser_id(rvalueType, id1), Fast_Parser_id(lvalueType, id2));
                }
            } else if (Fast_Node(rvalue)->kind == FAST_Literal) {
                result = Fast_Expression_cast(rvalue, lvalueType);
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

/* ::hyve::Fast::Parser::collect(lang::object o) */
db_void Fast_Parser_collect(Fast_Parser _this, db_object o) {
/* $begin(::hyve::Fast::Parser::collect) */
    /* 1st pass & 2nd pass are equal */

    db_assert(_this->collected != NULL, "initialization failed");
    db_llInsert(_this->collected, o);

/* $end */
}

/* ::hyve::Fast::Parser::collectHeap(word addr) */
db_void Fast_Parser_collectHeap(Fast_Parser _this, db_word addr) {
/* $begin(::hyve::Fast::Parser::collectHeap) */
    FAST_CHECK_ERRSET(_this);

    /* 1st pass & 2nd pass are equal */
    db_assert(_this->heapCollected != NULL, "initialization failed");
    db_llInsert(_this->heapCollected, (void*)addr);

/* $end */
}

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::Parser::construct(Parser object) */
db_int16 Fast_Parser_construct(Fast_Parser object) {
/* $begin(::hyve::Fast::Parser::construct) */
    DB_UNUSED(object);
    Fast_Parser_reset(object);
    return 0;
/* $end */
}

/* ::hyve::Fast::Parser::declaration(Variable type,lang::string id,lang::bool isReference) */
Fast_Variable Fast_Parser_declaration(Fast_Parser _this, Fast_Variable type, db_string id, db_bool isReference) {
/* $begin(::hyve::Fast::Parser::declaration) */
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
        			db_assert(type != NULL, "no type provided for declaration");
        		}
        	}
        	db_assert(_this->block != NULL, "no valid code-block set in parser context.");

            /* If the variable is declared in the global scope, verify that its name doesn't clash with an object */
            if (!_this->block->parent) {
                db_object o;
                if ((o = db_resolve(Fast_ObjectBase(_this->scope)->value, id))) {
                    Fast_Parser_error(_this, "object '%s' is redeclared as a variable", id);
                    db_free(o);
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
        db_object parent = _this->scope ? Fast_ObjectBase(_this->scope)->value : NULL;
        db_object o;
    	if (!type) {
    		if (_this->lastFailedResolve) {
    			Fast_Parser_error(_this, "unresolved type '%s'", _this->lastFailedResolve);
    			goto error;
    		} else {
    			db_assert(type != NULL, "no type provided for declaration");
    		}
    	}
    	db_assert(_this->block != NULL, "no valid code-block set in parser context.");

        if (!_this->pass) {
            o = db_declare(parent, id, Fast_ObjectBase(type)->value);
            if (!o) {
                db_id id1;
                Fast_Parser_error(_this, "declare of '%s' of type '%s' failed",
                        id,
                        Fast_Parser_id(Fast_ObjectBase(type)->value, id1));
                goto error;
            }
        } else {
            o = db_resolve_ext(_this, parent, id, FALSE, "Resolve object in 2nd pass");
            db_assert(o != NULL, "object disappeared in 2nd pass");
            db_free_ext(_this, o, "Free object from resolve (2nd run)");
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

/* ::hyve::Fast::Parser::declareFunction(Variable returnType,lang::string id,lang::procedure kind,bool returnsReference) */
Fast_Variable Fast_Parser_declareFunction(Fast_Parser _this, Fast_Variable returnType, db_string id, db_procedure kind, db_bool returnsReference) {
/* $begin(::hyve::Fast::Parser::declareFunction) */
	db_function function;
    db_object o;
	db_typedef functionType = db_typedef(kind);
	db_object returnType_o;
	Fast_Variable result = NULL;
    db_int32 distance;
    FAST_CHECK_ERRSET(_this);
    
	if (!_this->pass) {
	    db_id functionName;
	    db_delegate delegate = NULL;

        if (!returnType) {
            if (_this->lastFailedResolve) {
                Fast_Parser_error(_this, "unresolved type '%s'", _this->lastFailedResolve);
                goto error;
            } else {
                db_assert(returnType != NULL, "no type provided for declaration");
            }
        }

        /* Obtain name of function */
        db_signatureName(id, functionName);

        /* Resolve identifier first to verify whether it is not already in use as non-function object */
        if ((o = db_lookup(Fast_ObjectBase(_this->scope)->value, functionName))) {
            if (!db_instanceof(db_typedef(db_function_o), o)) {
                db_id id2;
                Fast_Parser_error(_this, "cannot redeclare '%s' of type '%s' as function",
                    id, Fast_Parser_id(db_typeof(o), id2));
                goto error;
            }
            db_free(o);
        }
        
	    /* This could be an implementation after a forward declaration so try to resolve
	     * function first. */
	    if (!((function = db_lookupFunction(Fast_ObjectBase(_this->scope)->value, id, FALSE, &distance)) && !distance)) {
            
            if (!functionType) {
                if (db_class_instanceof(db_interface_o, Fast_ObjectBase(_this->scope)->value )) {
                    if (db_class_instanceof(db_class_o, Fast_ObjectBase(_this->scope)->value )) {
                        if ((delegate = db_class_resolveDelegate(db_class_o, functionName))) {
                            functionType = db_typedef(db_callback_o);
                        }
                    }
                    if (!functionType) {
                        functionType = db_typedef(db_method_o);
                    }
                } else {
                    functionType = db_typedef(db_function_o);
                }
            }
            
            returnType_o = Fast_ObjectBase(returnType)->value;
            if (!db_class_instanceof(db_typedef_o, returnType_o)) {
                db_id id;
                Fast_Parser_error(_this, "object '%s' specified as returntype is not a type.", Fast_Parser_id(returnType_o, id));
                goto error;
            }
            
            function = db_declare(Fast_ObjectBase(_this->scope)->value, id, functionType);
            if (!function) {
                db_id id1;
                Fast_Parser_error(_this, "declare of %s '%s' failed",
                                  id,
                                  Fast_Parser_id(functionType, id1));
                goto error;
            }
            function->returnType = db_typedef(returnType_o);
            function->returnsReference = returnsReference;
            db_keep_ext(function, returnType_o, "Keep returntype for function");

            if (delegate) {
                db_callback(function)->delegate = delegate;
                db_keep_ext(function, delegate, "Keep delegate for callback");
            }
	    } else {
	        db_free(function);
	    }
        
        result = Fast_Variable(Fast_Object__create(function));
        Fast_Parser_collect(_this, result);
	} else {
	    db_object function = db_resolve_ext(_this, Fast_ObjectBase(_this->scope)->value, id, FALSE, "Resolve function in 2nd pass");
	    db_assert(function != NULL, "object should still be there in 2nd pass");
        
	    result = Fast_Variable(Fast_Object__create(function));
	    Fast_Parser_collect(_this, result);
	    db_free_ext(_this, function, "Free function from resolve (2nd pass)");
	}
    
	return result;
error:
    fast_err;
	return NULL;
/* $end */
}

/* ::hyve::Fast::Parser::declareFunctionParams(Variable function) */
Fast_Block Fast_Parser_declareFunctionParams(Fast_Parser _this, Fast_Variable function) {
/* $begin(::hyve::Fast::Parser::declareFunctionParams) */
	db_function function_o;
	db_parameter *param;
	Fast_Object typeVariable;
	Fast_Block result = NULL;
	unsigned int i;
    FAST_CHECK_ERRSET(_this);

	if (_this->pass) {
        result = Fast_Parser_blockPush(_this, TRUE);

        function_o = Fast_ObjectBase(function)->value;
        Fast_Block_setFunction(result, function_o);

        /* If function is a method, include 'this' pointer */
        if (db_instanceof(db_typedef(db_method_o), function_o)) {
        	db_interface parent;

            typeVariable = Fast_Object__create(db_parentof(function_o));
            Fast_Block_declare(result, "this", Fast_Variable(typeVariable), TRUE, FALSE);
            Fast_Parser_collect(_this, typeVariable);

            /* If parent of method has a base, include super */
            parent = db_parentof(function_o);
            if (db_interface(parent)->base) {
            	Fast_Object superType = Fast_Object__create(db_interface(parent)->base);
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
        if (function_o->returnType && ((function_o->returnType->real->kind != DB_VOID) || function_o->returnType->real->reference)) {
        	Fast_Block_declareReturnVariable(result, function_o);
        }
	}

	return result;
/* $end */
}

/* ::hyve::Fast::Parser::define() */
db_int16 Fast_Parser_define(Fast_Parser _this) {
/* $begin(::hyve::Fast::Parser::define) */
    FAST_CHECK_ERRSET(_this);

	if ((_this->initializerCount >= 0) && _this->initializers[_this->initializerCount]) {
        if (Fast_Initializer_define(_this->initializers[_this->initializerCount])) {
            goto error;
        }
        db_set_ext(_this, &_this->initializers[_this->initializerCount], NULL, ".initializers[.initializerCount]");
        _this->initializerCount--;
	}

	return 0;
error:
    fast_err;
	return -1;
/* $end */
}

/* ::hyve::Fast::Parser::defineScope() */
db_int16 Fast_Parser_defineScope(Fast_Parser _this) {
/* $begin(::hyve::Fast::Parser::defineScope) */
    FAST_CHECK_ERRSET(_this);

    if (!_this->pass) {
        if (Fast_Variable(_this->scope)->kind == FAST_Object) {
            if (db_define(Fast_ObjectBase(_this->scope)->value)) {
                db_id id;
                Fast_Parser_error(_this, "failed to define scope '%s'", Fast_Parser_id(Fast_ObjectBase(_this->scope)->value, id));
                goto error;
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

/* ::hyve::Fast::Parser::defineVariable(Variable object) */
db_int16 Fast_Parser_defineVariable(Fast_Parser _this, Fast_Variable object) {
/* $begin(::hyve::Fast::Parser::defineVariable) */
    db_int16 result = 0;
    DB_UNUSED(_this);
    FAST_CHECK_ERRSET(_this);

	if ((Fast_Node(object)->kind == FAST_Variable) && (Fast_Variable(object)->kind == FAST_Object)) {
		if (db_define(Fast_ObjectBase(object)->value)) {
		    db_id id1, id2;
			Fast_Parser_error(_this, "define of variable '%s' of type '%s' failed",
			        Fast_Parser_id(Fast_ObjectBase(object)->value, id1),
			        Fast_Parser_id(db_typeof(Fast_ObjectBase(object)->value), id2));
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

/* callback ::hyve::lang::class::destruct(lang::object object) -> ::hyve::Fast::Parser::destruct(Parser object) */
void Fast_Parser_destruct(Fast_Parser object) {
/* $begin(::hyve::Fast::Parser::destruct) */
	db_iter iter;

	if (object->heapCollected) {
		iter = db_llIter(object->heapCollected);
		while(db_iterHasNext(&iter)) {
			db_dealloc(db_iterNext(&iter));
		}
		db_llFree(object->heapCollected);
	}

	object->heapCollected = NULL;
	object->scope = NULL;

	memset(object->variables, 0, sizeof(object->variables));
/* $end */
}

/* ::hyve::Fast::Parser::elementExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
Fast_Expression Fast_Parser_elementExpr(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue) {
/* $begin(::hyve::Fast::Parser::elementExpr) */
	Fast_Expression result = NULL;

    /* Expand element expression with comma-expressions */
    if (_this->pass) {
        db_type t = Fast_Expression_getType(lvalue);
        /* If the left value is a composite type then translate element expression to members */
        if (t) {
            if (t->kind == DB_COMPOSITE) {
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

/* ::hyve::Fast::Parser::foreach(lang::string loopId,Fast::Expression collection) */
db_int16 Fast_Parser_foreach(Fast_Parser _this, db_string loopId, Fast_Expression collection) {
/* $begin(::hyve::Fast::Parser::foreach) */
    if (_this->pass) {
        Fast_Block block;
        db_object type;
        db_typedef elementType;
        Fast_Variable elementTypeVar;
        FAST_CHECK_ERRSET(_this);

        if (collection->type->kind == FAST_Object) {
            type = Fast_ObjectBase(collection->type)->value;
        } else {
            /* TODO: what if type is local */
            type = NULL;
        }

        if (db_typedef(type)->real->kind != DB_COLLECTION) {
            Fast_Parser_error(_this, "expression does not resolve to a collection");
            goto error;
        }

        elementType = db_collection(db_typedef(type)->real)->elementType;
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

/* ::hyve::Fast::Parser::getComplexType() */
db_type Fast_Parser_getComplexType(Fast_Parser _this) {
/* $begin(::hyve::Fast::Parser::getComplexType) */
    db_type result = NULL;

    if (_this->complexTypeSp > 0) {
        result = _this->complexType[_this->complexTypeSp-1];
        if (result && (result->kind != DB_COMPOSITE)) {
            result = NULL;
        }
    }

    return result;
/* $end */
}

/* ::hyve::Fast::Parser::getLvalue(lang::bool assignment) */
Fast_Expression Fast_Parser_getLvalue(Fast_Parser _this, db_bool assignment) {
/* $begin(::hyve::Fast::Parser::getLvalue) */
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

/* ::hyve::Fast::Parser::getLvalueType(lang::bool assignment) */
db_type Fast_Parser_getLvalueType(Fast_Parser _this, db_bool assignment) {
/* $begin(::hyve::Fast::Parser::getLvalueType) */
    db_type result = NULL;

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

/* ::hyve::Fast::Parser::ifStatement(Fast::Expression condition,Fast::Block trueBranch,Fast::If falseBranch) */
Fast_Node Fast_Parser_ifStatement(Fast_Parser _this, Fast_Expression condition, Fast_Block trueBranch, Fast_If falseBranch) {
/* $begin(::hyve::Fast::Parser::ifStatement) */
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

/* ::hyve::Fast::Parser::initDeclareStaged(Fast::Expression expr) */
void Fast_Parser_initDeclareStaged(Fast_Parser _this, Fast_Expression expr) {
/* $begin(::hyve::Fast::Parser::initDeclareStaged) */
    db_uint32 i;
    
    _this->variableCount = 0;

    if (expr) {
        db_ll exprList = Fast_Expression_toList(expr);
        db_iter iter = db_llIter(exprList);

        if (_this->stagedCount) {
            Fast_Parser_error(_this, "invalid declaration");
            goto error;
        }
        
        while(db_iterHasNext(&iter)) {
            _this->variables[_this->variableCount] = db_iterNext(&iter);
            _this->variableCount++;
        }
        
        Fast_Expression_cleanList(exprList);
    } else {
        for(i=0; i<_this->stagedCount; i++) {
            if (Fast_Variable(_this->scope)->kind == FAST_Object) {
                db_object scope = Fast_ObjectBase(_this->scope)->value;
                if (db_instanceof(db_typedef(db_type_o), scope)) {
                    Fast_Variable defaultType;
                    db_typedef scopeType = db_typedef(scope);
                    if (scopeType->real->defaultType) {
                        defaultType = Fast_Variable(Fast_Object__create(scopeType->real->defaultType));
                    } else {
                        defaultType = Fast_Variable(Fast_Object__create(db_any_o));
                    }
                    
                    /* Add variable to parser-list for initialization */
                    Fast_Parser_declaration(_this, defaultType, _this->staged[i].name, FALSE);
                    
                    db_dealloc(_this->staged[i].name);
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

/* ::hyve::Fast::Parser::initKeyValuePop() */
db_int16 Fast_Parser_initKeyValuePop(Fast_Parser _this) {
/* $begin(::hyve::Fast::Parser::initKeyValuePop) */
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

/* ::hyve::Fast::Parser::initKeyValuePush() */
db_int16 Fast_Parser_initKeyValuePush(Fast_Parser _this) {
/* $begin(::hyve::Fast::Parser::initKeyValuePush) */
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

/* ::hyve::Fast::Parser::initKeyValueSet(Fast::Expression expr) */
db_int16 Fast_Parser_initKeyValueSet(Fast_Parser _this, Fast_Expression expr) {
/* $begin(::hyve::Fast::Parser::initKeyValueSet) */
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

/* ::hyve::Fast::Parser::initMember(lang::string member) */
db_int16 Fast_Parser_initMember(Fast_Parser _this, db_string member) {
/* $begin(::hyve::Fast::Parser::initMember) */
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

/* ::hyve::Fast::Parser::initPop() */
db_int16 Fast_Parser_initPop(Fast_Parser _this) {
/* $begin(::hyve::Fast::Parser::initPop) */
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

/* ::hyve::Fast::Parser::initPush() */
db_int16 Fast_Parser_initPush(Fast_Parser _this) {
/* $begin(::hyve::Fast::Parser::initPush) */
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

/* ::hyve::Fast::Parser::initPushExpression() */
Fast_Expression Fast_Parser_initPushExpression(Fast_Parser _this) {
/* $begin(::hyve::Fast::Parser::initPushExpression) */
    Fast_Initializer initializer = NULL;
    
    _this->initializerCount++;
    
    if (_this->pass) {
        Fast_InitializerVariable_array64 variables;
        
        memset(variables, 0, sizeof(variables));
        
        /* Create initializer */
        initializer = Fast_Initializer(Fast_InitializerExpr__create(variables, 1, TRUE));
        db_set_ext(_this, &_this->initializers[_this->initializerCount], initializer, ".initializers[.initializersCount]");
        Fast_Parser_collect(_this, initializer);
        _this->variablePushed = TRUE;
    }
    
    return Fast_Expression(initializer);
/* $end */
}

/* ::hyve::Fast::Parser::initPushIdentifier(Expression type) */
Fast_Expression Fast_Parser_initPushIdentifier(Fast_Parser _this, Fast_Expression type) {
/* $begin(::hyve::Fast::Parser::initPushIdentifier) */
    db_typedef t;
    db_bool isDynamic = TRUE;
    db_bool forceStatic = FALSE;
    Fast_InitializerVariable_array64 variables;
    memset(variables, 0, sizeof(variables));
   
    DB_UNUSED(_this);
    DB_UNUSED(type);
    
    if (!type) {
        Fast_Parser_error(_this, "unresolved identifier '%s'", _this->lastFailedResolve);
        goto error;
    }
    
    t = db_typedef(Fast_ObjectBase(type)->value);
    
    if (_this->initializerCount >= 0) {
        Fast_Initializer initializer = _this->initializers[_this->initializerCount];
        if (initializer) {
            if (!db_instanceof(db_typedef(Fast_DynamicInitializer_o), initializer)) {
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
    if (db_instanceof(db_typedef(db_interface_o), t) && db_interface_baseof(db_interface(t), db_interface(db_type_o))) {
        forceStatic = TRUE;
    }
    
    /* Static initializers are executed during first pass */
    if ((!_this->pass && !isDynamic) || forceStatic) {
        db_object o;
        o = db_new(t);
        db_set_ext(NULL, &variables[0].object, Fast_Expression(Fast_Object__create(o)), "keep object for initializer variable array");
        _this->initializers[_this->initializerCount] = Fast_Initializer(Fast_StaticInitializer__create(variables, 1));
        _this->variablePushed = TRUE;
    } else if (_this->pass && isDynamic && !forceStatic) {
        Fast_Expression newExpr, assignExpr, var;
        var = Fast_Parser_getAnonymousLocal(_this, Fast_Variable(type), TRUE);
		newExpr = Fast_Expression(Fast_NewExpr__create(type,0));
		Fast_Parser_collect(_this, newExpr);
        assignExpr = Fast_Expression(Fast_BinaryExpr__create(var, newExpr, DB_ASSIGN));
		Fast_Parser_collect(_this, assignExpr);
        Fast_Parser_addStatement(_this, Fast_Node(assignExpr));
        
        db_set_ext(NULL, &variables[0].object, var, "keep object for initializer variable array");
        _this->initializers[_this->initializerCount] = Fast_Initializer(Fast_DynamicInitializer__create(variables, 1, FALSE));
        _this->variablePushed = TRUE;
    } else {
        db_set_ext(_this, &_this->initializers[_this->initializerCount], NULL, ".initializers[.initializerCount]");
        _this->variablePushed = TRUE;
    }
    
    return variables[0].object;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::hyve::Fast::Parser::initPushStatic() */
db_int16 Fast_Parser_initPushStatic(Fast_Parser _this) {
/* $begin(::hyve::Fast::Parser::initPushStatic) */
    db_bool isLocal = _this->isLocal;
    Fast_InitializerVariable_array64 variables;
    Fast_Initializer initializer;
    db_uint32 i;
    
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
        db_set_ext(_this, &variables[i].object, Fast_Expression(_this->variables[i]), ".initializers[.initializerCount]");
        variables[i].key = 0;
        variables[i].offset = 0;
    }

    if (!_this->pass) {
        /* Create initializer */
        initializer = Fast_Initializer(Fast_StaticInitializer__create(variables, _this->variableCount));
        db_set_ext(_this, &_this->initializers[_this->initializerCount], initializer, ".initializers[.initializerCount]");
        Fast_Parser_collect(_this, initializer);
    } else {
        /* Create dummy initializer */
        initializer = Fast_Initializer__create(variables, _this->variableCount);
        db_set_ext(_this, &_this->initializers[_this->initializerCount], initializer, ".initializers[.initializerCount]");
        Fast_Parser_collect(_this, initializer);
    }
    
    return 0;
error:
    return -1;
/* $end */
}

/* ::hyve::Fast::Parser::initStage(lang::string id,bool found) */
void Fast_Parser_initStage(Fast_Parser _this, db_string id, db_bool found) {
/* $begin(::hyve::Fast::Parser::initStage) */
    
    _this->staged[_this->stagedCount].name = db_strdup(id);
    _this->staged[_this->stagedCount].line = _this->line;
    _this->staged[_this->stagedCount].column = _this->column;
    _this->staged[_this->stagedCount].found = found;
    _this->stagedCount++;

/* $end */
}

/* ::hyve::Fast::Parser::initValue(Expression expr) */
db_int16 Fast_Parser_initValue(Fast_Parser _this, Fast_Expression expr) {
/* $begin(::hyve::Fast::Parser::initValue) */
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

/* ::hyve::Fast::Parser::isAbortSet() */
db_bool Fast_Parser_isAbortSet(Fast_Parser _this) {
/* $begin(::hyve::Fast::Parser::isAbortSet) */
    db_bool result = _this->abort;
    _this->abort = FALSE;
    return result;
/* $end */
}

/* ::hyve::Fast::Parser::isErrSet() */
db_bool Fast_Parser_isErrSet(Fast_Parser _this) {
/* $begin(::hyve::Fast::Parser::isErrSet) */
    db_bool result = _this->errSet;
    _this->errSet = FALSE;
    return result;
/* $end */
}

/* ::hyve::Fast::Parser::lookup(lang::string id,lang::object source) */
Fast_Expression Fast_Parser_lookup(Fast_Parser _this, db_string id, db_object source) {
/* $begin(::hyve::Fast::Parser::lookup) */
    Fast_Expression result = NULL;
    FAST_CHECK_ERRSET(_this);

    if (_this->pass) {
        /* If complexType is set, this resolve is ran within a [] expression */
        db_type complexType = Fast_Parser_getComplexType(_this);
        if (complexType) {
            if (db_interface_resolveMember(db_interface(complexType), id)) {
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
            db_instanceof(db_typedef(Fast_StaticInitializer_o), _this->initializers[_this->initializerCount]))) {
            Fast_Parser_error(_this, "unresolved identifier '%s'", id);
            fast_err;
        }
        
        if (_this->lastFailedResolve) {
            db_dealloc(_this->lastFailedResolve);
        }
        _this->lastFailedResolve = db_strdup(id);
    }
    Fast_Parser_initStage(_this, id, result != NULL);

    return result;
/* $end */
}

/* ::hyve::Fast::Parser::memberExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
Fast_Expression Fast_Parser_memberExpr(Fast_Parser _this, Fast_Expression lvalue, Fast_Expression rvalue) {
/* $begin(::hyve::Fast::Parser::memberExpr) */
	Fast_Expression result = NULL;
    
    _this->stagingAllowed = FALSE;

	if (_this->pass) {
        db_type t = Fast_Expression_getType(lvalue);
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

/* ::hyve::Fast::Parser::observerDeclaration(lang::string id,Fast::Expression object,lang::eventMask mask,Fast::Object dispatcher) */
Fast_Variable Fast_Parser_observerDeclaration(Fast_Parser _this, db_string id, Fast_Expression object, db_eventMask mask, Fast_Object dispatcher) {
/* $begin(::hyve::Fast::Parser::observerDeclaration) */
    DB_UNUSED(object);
    DB_UNUSED(mask);
    FAST_CHECK_ERRSET(_this);
    
    _this->stagingAllowed = FALSE;
    
    Fast_Variable result = NULL;
    db_bool isTemplate = db_class_instanceof(db_type_o, Fast_ObjectBase(_this->scope)->value);
    db_string expr = NULL;
    
    if (!(mask & DB_ON_SCOPE)) {
        mask |= DB_ON_SELF;
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
    	db_observer observer;
    	db_object observable = NULL;
    	db_uint32 i;

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
    		observer = db_class_findObserver(db_class(Fast_ObjectBase(_this->scope)->value), observable, NULL);
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
    	for(i=0; i<db_function(observer)->parameters.length; i++) {
    	    db_parameter *p = &db_function(observer)->parameters.buffer[i];
    	    typeVar = (Fast_Variable)Fast_Object__create(p->type);
    	    Fast_Block_declare(block, p->name, typeVar, TRUE, TRUE); /* Observable parameter are references */
    	    Fast_Parser_collect(_this, typeVar);
    	}

        /* Bind observer and block */
        Fast_Parser_bind(_this, result, block);
        Fast_Block_setFunction(block, db_function(observer));
    }

	return result;
error:
    fast_err;
    return NULL;
/* $end */
}

/* ::hyve::Fast::Parser::observerPop() */
void Fast_Parser_observerPop(Fast_Parser _this) {
/* $begin(::hyve::Fast::Parser::observerPop) */
    FAST_CHECK_ERRSET(_this);

    /* Deprecated */

/* $end */
}

/* ::hyve::Fast::Parser::observerPush() */
void Fast_Parser_observerPush(Fast_Parser _this) {
/* $begin(::hyve::Fast::Parser::observerPush) */
    FAST_CHECK_ERRSET(_this);

    /* Observer-implementations are parsed in the 2nd pass */
    if (_this->pass) {
        if (_this->scope->kind == FAST_Object) {
            if (db_class_instanceof(db_type_o, Fast_ObjectBase(_this->scope)->value)) {
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

/* ::hyve::Fast::Parser::parse() */
db_uint32 Fast_Parser_parse(Fast_Parser _this) {
/* $begin(::hyve::Fast::Parser::parse) */
    FAST_CHECK_ERRSET(_this);

    _this->pass = 0;
    if ( fast_yparse(_this, 1, 1)) {
        printf("%s: parsed with errors (%d errors, %d warnings)\n", _this->filename, _this->errors, _this->warnings);
        goto error;
    }

    /* Reset parser-state so 2nd pass starts clean */
    Fast_Parser_reset(_this);

    /* Reset block */
    /*db_free_ext(_this, _this->block, "Free root-block");
    _this->block = NULL;*/

    _this->pass = 1;
    if ( fast_yparse(_this, 1, 1)) {
        printf("%s: parsed with errors (%d errors, %d warnings)\n", _this->filename, _this->errors, _this->warnings);
        goto error;
    }

    /* Parse to hyve intermediate code */
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

/* ::hyve::Fast::Parser::parseExpression(lang::string expr,Fast::Block block,Fast::Variable scope,uint32 line,uint32 column) */
Fast_Expression Fast_Parser_parseExpression(Fast_Parser _this, db_string expr, Fast_Block block, Fast_Variable scope, db_uint32 line, db_uint32 column) {
/* $begin(::hyve::Fast::Parser::parseExpression) */
	Fast_Expression result = NULL;
	db_string exprFinalized;

	DB_UNUSED(scope);

	if (_this->source) {
		db_dealloc(_this->source);
	}

	exprFinalized = db_malloc(strlen(expr) + 2);
	sprintf(exprFinalized, "%s;", expr);

	_this->source = exprFinalized;
    
    db_set_ext(_this, &_this->block, block, "Set rootblock for embedded expression");
    db_set_ext(_this, &_this->scope, scope, "Set scope for embedded expression");

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
			if (db_llSize(block->statements) == 1) {
				Fast_Node node;
				node = db_llGet(block->statements, 0);
				if (db_instanceof(db_typedef(Fast_Expression_o), node)) {
					result = Fast_Expression(node);
				} else {
					db_id id;
					printf("%s: '%s' does not resolve to a valid expression (found %s).\n",
							_this->filename, expr, Fast_Parser_id(db_typeof(node), id));
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

/* ::hyve::Fast::Parser::popComplexType() */
void Fast_Parser_popComplexType(Fast_Parser _this) {
/* $begin(::hyve::Fast::Parser::popComplexType) */

    _this->complexTypeSp--;
    if (_this->complexTypeSp < 0) {
        Fast_Parser_error(_this, "parser error: complexType stack pointer below zero");
        abort();
    }

/* $end */
}

/* ::hyve::Fast::Parser::popLvalue() */
void Fast_Parser_popLvalue(Fast_Parser _this) {
/* $begin(::hyve::Fast::Parser::popLvalue) */

    _this->lvalueSp--;
    if (_this->lvalueSp < 0) {
        Fast_Parser_error(_this, "parser error: lvalue stack pointer below zero");
        abort();
    }

/* $end */
}

/* ::hyve::Fast::Parser::popScope(Fast::Variable previous) */
void Fast_Parser_popScope(Fast_Parser _this, Fast_Variable previous) {
/* $begin(::hyve::Fast::Parser::popScope) */
    FAST_CHECK_ERRSET(_this);

    /* Restore scope */
    _this->scope = previous;
/* $end */
}

/* ::hyve::Fast::Parser::postfixExpr(Fast::Expression lvalue,lang::operatorKind operator) */
Fast_Expression Fast_Parser_postfixExpr(Fast_Parser _this, Fast_Expression lvalue, db_operatorKind operator) {
/* $begin(::hyve::Fast::Parser::postfixExpr) */
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

/* ::hyve::Fast::Parser::pushComplexType(Fast::Expression lvalue) */
void Fast_Parser_pushComplexType(Fast_Parser _this, Fast_Expression lvalue) {
/* $begin(::hyve::Fast::Parser::pushComplexType) */

    if (lvalue) {
        db_set(&_this->complexType[_this->complexTypeSp], Fast_Expression_getType(lvalue));
    } else {
        db_set(&_this->complexType[_this->complexTypeSp], NULL);
    }
    _this->complexTypeSp++;

/* $end */
}

/* ::hyve::Fast::Parser::pushLvalue(Fast::Expression lvalue,lang::bool isAssignment) */
void Fast_Parser_pushLvalue(Fast_Parser _this, Fast_Expression lvalue, db_bool isAssignment) {
/* $begin(::hyve::Fast::Parser::pushLvalue) */

    db_set_ext(_this, &_this->lvalue[_this->lvalueSp].expr, lvalue, ".lvalue[_this->lvalueSp]");
    _this->lvalue[_this->lvalueSp].isAssignment = isAssignment;
    _this->lvalueSp++;

/* $end */
}

/* ::hyve::Fast::Parser::pushReturnAsLvalue(lang::function function) */
void Fast_Parser_pushReturnAsLvalue(Fast_Parser _this, db_function function) {
/* $begin(::hyve::Fast::Parser::pushReturnAsLvalue) */
    Fast_Expression result = NULL;

    if (_this->pass) {
        if (function->returnType) {
            db_id id;
            db_signatureName(db_nameof(Fast_ObjectBase(function)->value), id);
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

/* ::hyve::Fast::Parser::pushScope() */
Fast_Variable Fast_Parser_pushScope(Fast_Parser _this) {
/* $begin(::hyve::Fast::Parser::pushScope) */
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

/* ::hyve::Fast::Parser::reset() */
void Fast_Parser_reset(Fast_Parser _this) {
/* $begin(::hyve::Fast::Parser::reset) */
    db_uint32 i;

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
            db_dealloc(_this->staged[i].name);
            _this->staged[i].name = NULL;
        }
    }
    _this->stagedCount = 0;

/* $end */
}

/* ::hyve::Fast::Parser::ternaryExpr(Fast::Expression cond,Fast::Expression iftrue,Fast::Expression iffalse) */
Fast_Expression Fast_Parser_ternaryExpr(Fast_Parser _this, Fast_Expression cond, Fast_Expression iftrue, Fast_Expression iffalse) {
/* $begin(::hyve::Fast::Parser::ternaryExpr) */
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

/* ::hyve::Fast::Parser::unaryExpr(Fast::Expression lvalue,lang::operatorKind operator) */
Fast_Expression Fast_Parser_unaryExpr(Fast_Parser _this, Fast_Expression lvalue, db_operatorKind operator) {
/* $begin(::hyve::Fast::Parser::unaryExpr) */
	Fast_Expression result = NULL;

    _this->stagingAllowed = FALSE;
    
	if (lvalue) {
        if (operator == DB_SUB) {
            db_type lvalueType = Fast_Expression_getType(lvalue);

            if (lvalueType->kind == DB_PRIMITIVE) {
                switch(db_primitive(lvalueType)->kind) {
                case DB_INTEGER:
                    if (Fast_Node(lvalue)->kind == FAST_Literal) {
                        result = Fast_Expression(Fast_Integer__create(Fast_Integer(lvalue)->value * -1));
                        Fast_Parser_collect(_this, result);
                        break;
                    }
                    /* no break */
                case DB_UINTEGER:
                    if (Fast_Node(lvalue)->kind == FAST_Literal) {
                        result = Fast_Expression(Fast_SignedInteger__create(Fast_Integer(lvalue)->value * -1));
                        Fast_Parser_collect(_this, result);
                        break;
                    }
                    /* no break */
                case DB_FLOAT:
                    if (Fast_Node(lvalue)->kind == FAST_Literal) {
                        result = Fast_Expression(Fast_FloatingPoint__create(Fast_FloatingPoint(lvalue)->value * -1));
                        Fast_Parser_collect(_this, result);
                    } else {
                        if (_this->pass) {
                            Fast_SignedInteger minusOne = Fast_SignedInteger__create(-1);
                            Fast_Parser_collect(_this, minusOne);
                            result = Fast_Expression(Fast_BinaryExpr__create(lvalue, Fast_Expression(minusOne), DB_MUL));
                            Fast_Parser_collect(_this, result);
                        }
                    }
                    break;
                default: {
                    db_id id;
                    Fast_Parser_error(_this, "unary operator - not applicable to type '%s'", Fast_Parser_id(lvalueType, id));
                    goto error;
                }
                }
            } else {
                db_id id;
                Fast_Parser_error(_this, "unary operator - not applicable to non-primitive type '%s'", Fast_Parser_id(lvalueType, id));
                goto error;
            }
        } else if (operator == DB_AND) {
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

/* ::hyve::Fast::Parser::updateStatement(Fast::Expression expr,Fast::Block block) */
Fast_Node Fast_Parser_updateStatement(Fast_Parser _this, Fast_Expression expr, Fast_Block block) {
/* $begin(::hyve::Fast::Parser::updateStatement) */
    Fast_Node result = NULL;
    
    _this->stagingAllowed = FALSE;

    if (_this->pass) {
    	Fast_Block functionBlock;
    	Fast_Expression from = NULL;
    	db_function function;
    	db_procedureKind procedureKind;
        db_ll exprList;
        
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
			procedureKind = db_procedure(db_typeof(function))->kind;
			if (functionBlock) {
				if ((procedureKind == DB_METHOD) || ((procedureKind == DB_OBSERVER) && db_observer(function)->template)) {
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

/* ::hyve::Fast::Parser::waitExpr(list{Fast::Expression} exprList,Fast::Expression timeout) */
Fast_Expression Fast_Parser_waitExpr(Fast_Parser _this, Fast_Expression_list exprList, Fast_Expression timeout) {
/* $begin(::hyve::Fast::Parser::waitExpr) */
    Fast_Expression result = NULL;
    
    _this->stagingAllowed = FALSE;

    if (_this->pass) {
        Fast_Expression expr;
        db_iter exprIter;

        /* Keep argument expressions */
        if (exprList) {
            exprIter = db_llIter(exprList);
            while(db_iterHasNext(&exprIter)) {
                expr = db_iterNext(&exprIter);
                if (expr) {
                    db_keep_ext(result, expr, "Keep expression for waitlist");
                }
            }
        }

        result = Fast_Expression(Fast_Wait__create(exprList, timeout));

        Fast_Parser_collect(_this, result);
    } else {
        if (exprList) {
            db_llFree(exprList);
        }
    }

    return result;
/* $end */
}

/* ::hyve::Fast::Parser::whileStatement(Fast::Expression condition,Fast::Block trueBranch,lang::bool isUntil) */
Fast_Node Fast_Parser_whileStatement(Fast_Parser _this, Fast_Expression condition, Fast_Block trueBranch, db_bool isUntil) {
/* $begin(::hyve::Fast::Parser::whileStatement) */
	Fast_Node result = NULL;
    
    _this->stagingAllowed = FALSE;

	if (_this->pass) {
		result = Fast_Node(Fast_While__create(condition, trueBranch, isUntil));
		if (!result) {
			goto error;
		}
		Fast_Parser_collect(_this, result);
        
        if (isUntil) {
            db_set_ext(_this->block, &_this->block->_while, result, "block->_while");
        }
	}

	return result;
error:
	fast_err;
	return NULL;
/* $end */
}
