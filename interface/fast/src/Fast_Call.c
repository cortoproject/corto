/* Fast_Call.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"
#include "Fast__meta.h"

/* $header() */
#include "cx.h"
#include "Fast__api.h"
#include "Fast_Parser.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);

/* Insert implicit casts when argument-expressions do not match */
cx_int16 Fast_Call_insertCasts(Fast_Call _this) {
	cx_iter argumentIter;
	Fast_Expression argument;
	cx_uint32 i = 0;
	cx_function function;
	cx_type parameterType, argumentType;

	function = _this->actualFunction;
	if (_this->arguments) {
        cx_ll arguments = Fast_Expression_toList(_this->arguments);
        argumentIter = cx_llIter(arguments);
        while(cx_iterHasNext(&argumentIter)) {
            argument = cx_iterNext(&argumentIter);
            parameterType = function->parameters.buffer[i].type->real;
            argumentType = Fast_Expression_getType(argument);

            if (function->parameters.buffer[i].passByReference) {
            	if (!argument->isReference) {
            		Fast_Parser_error(yparser(), "cannot pass non-reference value as reference");
            		goto error;
            	}
            }
            
            /* If both types are not equal, insert cast */
            if (parameterType != argumentType) {
                Fast_Expression expr;

                /* Any types are handled in the translation to the target representation. It is often
                 * more efficient to push a value as any than to first cast it to any and then push it. */
                if (parameterType->kind != DB_ANY) {
                    expr = Fast_Expression_cast(argument, parameterType);
                    if (expr) {
                        cx_keep_ext(_this, expr, "Keep cast-expression as argument");
                        cx_llReplace(arguments, argument, expr);
                        cx_free_ext(_this, argument, "Free old (uncasted) expression from argumentlist");
                    }
                }
            }

            i++;
        }
        cx_set(&_this->arguments, Fast_Expression_fromList(arguments));
        Fast_Expression_cleanList(arguments);
    }

	return 0;
error:
	return -1;
}

/* Resolve correct function based on argumentlist, insert casts */
cx_int16 Fast_Call_finalize(Fast_Call _this, cx_function function) {
	cx_string signature;
	cx_id functionName;
	cx_iter argumentIter;
	Fast_Expression argument;
	cx_type argumentType;
    Fast_Expression instance = NULL;
    
	/* Get name from function signature */
	cx_signatureName(cx_nameof(function), functionName);

	/* Build request-signature */
	signature = cx_signatureOpen(functionName);

	if (_this->arguments) {
        cx_ll arguments = Fast_Expression_toList(_this->arguments);
        argumentIter = cx_llIter(arguments);
        while(cx_iterHasNext(&argumentIter)) {
            argument = cx_iterNext(&argumentIter);
            argumentType = Fast_Expression_getType(argument);

            /* If there is no type and the argument is an initializer, insert a wildcard */
            if (!argumentType && (Fast_Node(argument)->kind == FAST_Initializer)) {
            	signature = cx_signatureAddWildcard(signature, FALSE);

        	/* If function is overloaded, you have to explicitly specify whether an argument is a reference or not */
            } else if (function->overloaded) {
            	signature = cx_signatureAdd(signature, cx_typedef(argumentType), argument->forceReference);
            } else {
            	signature = cx_signatureAdd(signature, cx_typedef(argumentType), argument->isReference);
            }
        }
        Fast_Expression_cleanList(arguments);
	}

	/* Store signature for when a method needs to be resolved at runtime */
	signature = _this->signature = cx_signatureClose(signature);

    if (_this->function && (Fast_Node(_this->function)->kind == FAST_Member)) {
        instance = Fast_MemberExpr(_this->function)->lvalue;
    }

    if (!(function = Fast_Call_resolveActual(signature, cx_parentof(function), instance))) {
        goto error;
    } else {
        cx_set(&_this->actualFunction, function);
    }

    /* Walk arguments, insert casts if required */
    if (Fast_Call_insertCasts(_this)) {
        goto error;
    }

    return 0;
error:
    return -1;
}
/* $end */

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::Fast::Call::construct(Fast::Call object) */
cx_int16 Fast_Call_construct(Fast_Call object) {
/* $begin(::cortex::Fast::Call::construct) */
	cx_type functionType;
	cx_function function = NULL;
    Fast_nodeKind kind = Fast_Node(object->function)->kind;

	Fast_Node(object)->kind = FAST_Call;

	/* Retrieve returnType */
	switch(kind) {
	case FAST_Variable:
		switch(Fast_Variable(object->function)->kind) {
		case FAST_Object:
			/* Verify that called object is a function */
			functionType = Fast_Expression_getType(object->function);
			if (cx_class_instanceof(cx_procedure_o, functionType)) {
				function = Fast_ObjectBase(object->function)->value;
			} else {
				Fast_Parser_error(yparser(), "called object is not a function");
				goto error;
			}
			break;
		case FAST_Local: /* Recursive call */
			if (Fast_Local(object->function)->kind == FAST_LocalReturn) {
				Fast_Block block = yparser()->block;
				/* Find function that corresponds with current block */
				do {
					function = block->function;
				}while(!function && (block = block->parent));

				if (function) {
					/* If this is a recursive call to a method, replace the return-variable expression
					 * with a member-expression which includes the 'this'-variable. */
					if (cx_procedure(cx_typeof(function))->kind == DB_METHOD) {
						Fast_MemberExpr memberExpr;
						Fast_String methodStr;
						Fast_Expression thisVar = Fast_Parser_lookup(yparser(), "this", NULL);

						methodStr = Fast_String__create(cx_nameof(function));
						memberExpr = Fast_MemberExpr__create(thisVar, Fast_Expression(methodStr));
						Fast_Parser_collect(yparser(), methodStr);
						Fast_Parser_collect(yparser(), memberExpr);
						cx_set_ext(object, &object->function, memberExpr,
								"Replace returnVariable with member-expression for method call");
					}
				} else {
					Fast_Parser_error(yparser(), "parser error: found returnvariable in non-function scope");
					goto error;
				}
			} else {
				Fast_Parser_error(yparser(), "variable '%s' is not a callable object", Fast_Local(object->function)->name);
				goto error;
			}
			break;
		default:
			/* TODO: Variable function */
			Fast_Parser_error(yparser(), "run-time type resolving not yet supported");
			goto error;
			break;
		}
		break;
	case FAST_Member:
		/* Verify that called object is a function */
		functionType = cx_typeof(Fast_MemberExpr(object->function)->member)->real;
		if (cx_class_instanceof(cx_procedure_o, functionType)) {
			function = Fast_MemberExpr(object->function)->member;
		} else {
			cx_id id;
			Fast_Parser_error(yparser(), "called object is not a function (type=%s)",
					cx_fullname(functionType, id));
			goto error;
		}
		break;
	default:
		Fast_Parser_error(yparser(), "expression not supported for call (%s)", cx_nameof(cx_enum_constant(Fast_nodeKind_o, kind)));
		goto error;
		break;
	}

	/* Resolve actual method, based on arguments (overloading), taking into account inheritance (virtual methods) */
	if (Fast_Call_finalize(object, function)) {
		goto error;
    }

	cx_set(&Fast_Expression(object)->type, Fast_Variable(Fast_Object__create(object->actualFunction->returnType)));
    Fast_Parser_collect(yparser(), Fast_Expression(object)->type);
	Fast_Expression(object)->isReference = 
		object->actualFunction->returnsReference || object->actualFunction->returnType->real->reference;

    return 0;
error:
	return -1;
/* $end */
}

/* ::cortex::Fast::Call::hasSideEffects() */
cx_bool Fast_Call_hasSideEffects_v(Fast_Call _this) {
/* $begin(::cortex::Fast::Call::hasSideEffects) */
    DB_UNUSED(_this);
    return TRUE;
/* $end */
}

/* ::cortex::Fast::Call::resolveActual(string signature,lang::object scope,Fast::Expression instance) */
cx_function Fast_Call_resolveActual(cx_string signature, cx_object scope, Fast_Expression instance) {
/* $begin(::cortex::Fast::Call::resolveActual) */
    cx_function actualFunction = NULL;

    if (!instance) {
        /* Resolve overloaded function, allow casting */
        actualFunction = cx_resolve_ext(NULL, scope, signature, TRUE, NULL);
        if (!actualFunction) {
            cx_id id;
            Fast_Parser_error(yparser(), "no function in scope '%s' that matches signature '%s'",
                    cx_fullname(scope, id), signature);
            goto error;
        }
    } else {
        cx_type lvalueType = Fast_Expression_getType(instance);
        actualFunction = (cx_function)cx_type_resolveProcedure(lvalueType, signature);
        if (actualFunction) {
            switch(cx_procedure(cx_typeof(actualFunction))->kind) {
            case DB_METHOD:
                break;
            case DB_METAPROCEDURE:
                /* Validate whether metaprocedure only accepts references, and whether lvalue is a reference */
                if(cx_metaprocedure(actualFunction)->referenceOnly && !instance->isReference) {
                    cx_id id;
                    Fast_Parser_error(yparser(), "metaprocedure '%s' accepts only reference values",
                        cx_fullname(actualFunction, id));
                    goto error;
                }
                break;
            default:
                Fast_Parser_error(yparser(), "can only call metaprocedures and methods on instances");
                goto error;
                break;
            }
        } else {
            cx_id id;
            Fast_Parser_error(yparser(), "no method in interface '%s' that matches signature '%s'",
                    cx_fullname(scope, id), signature);
            goto error;           
        }
    }

    if(!actualFunction) {
        goto error;
    }

    return actualFunction;
error:
    return NULL;
/* $end */
}

/* ::cortex::Fast::Call::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
cx_ic Fast_Call_toIc_v(Fast_Call _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::Call::toIc) */
	cx_icStorage function, result = NULL, argumentStorage = NULL;
	cx_uint32 argumentStorageCount = 0;
	cx_ic argumentIc = NULL;
	cx_icOp call;
	cx_iter argumentIter;
	Fast_Expression argument;
	cx_icOp *pushIcs = NULL;
	cx_int32 argumentId = 0, argumentCount = 0;
	cx_type _thisType = Fast_Expression_getType(Fast_Expression(_this));
    cx_ll arguments = NULL;
	DB_UNUSED(stored);
	DB_UNUSED(storage);
    
	if (storage && (storage->type == _thisType)) {
		result = storage;
	} else {
		result = (cx_icStorage)cx_icProgram_accumulatorPush(program, Fast_Node(_this)->line, _thisType, _this->actualFunction->returnsReference);
	}
    
    /* Signal that storage will hold return value */
    result->holdsReturn = TRUE;
    
    if (_this->arguments) {
        arguments = Fast_Expression_toList(_this->arguments);
    }
	if (arguments) {
		argumentCount = cx_llSize(arguments);
    }
    

	/* Obtain function */
	function = (cx_icStorage)cx_icObject__create(program, Fast_Node(_this)->line, _this->actualFunction);
    
	/* Push 'this' if function is a method or metaprocedure */
	switch(cx_procedure(cx_typeof(_this->actualFunction))->kind) {
	case DB_METHOD:
	case DB_METAPROCEDURE: {
		cx_ic thisIc;
		cx_assert(Fast_Node(_this->function)->kind == FAST_Member, "method-call expects member expression");
		thisIc = Fast_Node_toIc(Fast_Node(Fast_MemberExpr(_this->function)->lvalue), program, NULL, TRUE);
		argumentCount += 1;
	    pushIcs = alloca(argumentCount * sizeof(cx_icOp));
	    pushIcs[argumentId] = cx_icOp__create(program, Fast_Node(_this)->line, DB_IC_PUSH, (cx_icValue)thisIc, NULL, NULL);
	    pushIcs[argumentId]->s1Deref = DB_IC_DEREF_ADDRESS;
	    argumentId++;

	    /* If function is a metaprocedure, push 'this' as an any value, conform metaprocedure signatures */
	    if (cx_procedure(cx_typeof(_this->actualFunction))->kind == DB_METAPROCEDURE) {
	    	pushIcs[argumentId-1]->s1Any = TRUE;
	    }
		break;
	}
	default:
		if (_this->arguments) {
			pushIcs = alloca(argumentCount * sizeof(cx_icOp));
		}
		break;
	}

	/* Push arguments */
	if (_this->arguments) {
	    cx_uint32 i = 0;

	    /* Temporary storage for push-instructions required for pushing the arguments of this function */
        argumentIter = cx_llIter(arguments);
        while(cx_iterHasNext(&argumentIter)) {
            cx_type paramType, exprType;
            argument = cx_iterNext(&argumentIter);
            if (!argumentStorage ||
              (argumentIc == (cx_ic)argumentStorage) ||
              (Fast_Expression_getType(argument) != argumentStorage->type)) {
                argumentStorage = (cx_icStorage)cx_icProgram_accumulatorPush(
                	program, 
                	Fast_Node(_this)->line, 
                	Fast_Expression_getType(argument),
                	argument->isReference);
                argumentStorageCount++;
            }
            argumentIc = Fast_Node_toIc(Fast_Node(argument), program, argumentStorage, TRUE);
            pushIcs[argumentId] = cx_icOp__create(program, Fast_Node(_this)->line, DB_IC_PUSH, (cx_icValue)argumentIc, NULL, NULL);
            argumentId++;

            /* If parameterType is any and argument is not, push value as any */
            paramType = _this->actualFunction->parameters.buffer[i].type->real;
            exprType = Fast_Expression_getType(argument);

            if (paramType->kind == DB_ANY) {
                if (exprType && (exprType->kind != DB_ANY)) {
                    pushIcs[argumentId-1]->s1Any = TRUE;
                } else if (!exprType) {
                    pushIcs[argumentId-1]->s1Any = TRUE;
                }
                pushIcs[argumentId-1]->s1Deref = DB_IC_DEREF_ADDRESS;
            } else {
                if (!exprType) {
                    exprType = paramType;
                }
            	if (_this->actualFunction->parameters.buffer[i].passByReference || (paramType->reference && !exprType->reference)) {
            		pushIcs[argumentId-1]->s1Deref = DB_IC_DEREF_ADDRESS;
            	} else {
            		pushIcs[argumentId-1]->s1Deref = DB_IC_DEREF_PUSH;
            	}
            }
            i++;
        }
	}

    /* Add push-instructions just before doing the call so it doesn't interfere with call-expressions in
     * the argument list */
    for(argumentId = 0; argumentId < argumentCount; argumentId++) {
        cx_icProgram_addIc(program, (cx_ic)pushIcs[argumentId]);
    }

	/* Do call */
	call = cx_icOp__create(program, Fast_Node(_this)->line, DB_IC_CALL, (cx_icValue)result, (cx_icValue)function, NULL);
	cx_icProgram_addIc(program, (cx_ic)call);

	if (_this->actualFunction->returnsReference) {
		call->s1Deref = DB_IC_DEREF_ADDRESS;
	}

	while(argumentStorageCount) {
	    cx_icProgram_accumulatorPop(program, Fast_Node(_this)->line);
	    argumentStorageCount--;
	}

	if (storage != result) {
		cx_icProgram_accumulatorPop(program, Fast_Node(_this)->line);
	}
    
    Fast_Expression_cleanList(arguments);
    
	return (cx_ic)result;
/* $end */
}
