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
    cx_type parameterType, argumentType;

    if (_this->arguments) {
        cx_ll arguments = Fast_Expression_toList(_this->arguments);
        argumentIter = cx_llIter(arguments);
        while(cx_iterHasNext(&argumentIter)) {
            argument = cx_iterNext(&argumentIter);
            parameterType = _this->parameters.buffer[i].type->real;
            argumentType = Fast_Expression_getType(argument);

            if (_this->parameters.buffer[i].passByReference) {
                if (argumentType && !argument->isReference) {
                    Fast_Parser_error(yparser(), "cannot pass non-reference value as reference");
                    goto error;
                }
            }
            
            /* If both types are not equal, insert cast */
            if ((parameterType != argumentType) || (argument->forceReference && !argumentType->reference)) {
                Fast_Expression expr;

                /* Any types are handled in the translation to the target representation. It is often
                 * more efficient to push a value as any than to first cast it to any and then push it. */
                if (parameterType->kind != CX_ANY) {
                    expr = Fast_Expression_cast(argument, parameterType, _this->parameters.buffer[i].passByReference);
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

/* $end */

/* ::cortex::Fast::Call::construct() */
cx_int16 Fast_Call_construct(Fast_Call _this) {
/* $begin(::cortex::Fast::Call::construct) */
    Fast_Expression returnTypeExpr;

    Fast_Node(object)->kind = FAST_Call;

    /* Insert casts based on expression list and arguments */
    if (Fast_Call_insertCasts(object)) {
        goto error;
    }

    returnTypeExpr = Fast_Expression(Fast_Object__create(object->returnType));
    Fast_Parser_collect(yparser(), returnTypeExpr);

    cx_set(&Fast_Expression(object)->type, returnTypeExpr);
    Fast_Expression(object)->isReference = 
        object->returnsReference || object->returnType->reference;

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::Call::hasSideEffects() */
cx_bool Fast_Call_hasSideEffects_v(Fast_Call _this) {
/* $begin(::cortex::Fast::Call::hasSideEffects) */
    CX_UNUSED(_this);
    return TRUE;
/* $end */
}

/* ::cortex::Fast::Call::setParameters(function function) */
cx_void Fast_Call_setParameters(Fast_Call _this, cx_function function) {
/* $begin(::cortex::Fast::Call::setParameters) */
    cx_uint32 i;

    /* Set parameters */
    cx_set(&_this->returnType, function->returnType);
    _this->returnsReference = function->returnsReference;

    cx_parameter_seq__size(&_this->parameters, function->parameters.length);

    for (i = 0; i < function->parameters.length; i++) {
        cx_set(&_this->parameters.buffer[i].type, function->parameters.buffer[i].type);
        _this->parameters.buffer[i].passByReference= function->parameters.buffer[i].passByReference;
    }
/* $end */
}

/* ::cortex::Fast::Call::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Call_toIc_v(Fast_Call _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::Call::toIc) */
    cx_icStorage result = NULL;
    cx_ic function;
    cx_icOp call = NULL;
    Fast_Expression argument = NULL;
    cx_icOp *pushIcs = NULL; /* Cache push instructions before inserting in program to avoid issues with nested calls */
    cx_int32 argumentId = 0, argumentCount = 0;
    cx_type _thisType = Fast_Expression_getType(Fast_Expression(_this));
    cx_ll arguments = NULL;
    cx_uint32 argumentStorageCount = 0;

    CX_UNUSED(stored);
    CX_UNUSED(storage);
    
    if (storage && (storage->type == _thisType)) {
        result = storage;
    } else {
        result = (cx_icStorage)cx_icProgram_accumulatorPush(
            program, Fast_Node(_this)->line, _thisType, _this->returnsReference);
    }
    
    /* Signal that storage will hold return value */
    result->holdsReturn = TRUE;
    
    /* Convert arguments to iterable list */
    if (_this->arguments) {
        arguments = Fast_Expression_toList(_this->arguments);
        if (arguments) {
            argumentCount = cx_llSize(arguments);
        }
    }
    
    /* Push 'this' if function is a method or metaprocedure */
    if (_this->instanceExpr) {
        cx_ic thisIc = Fast_Node_toIc(Fast_Node(_this->instanceExpr), program, NULL, TRUE);
        argumentCount += 1;
        pushIcs = alloca(argumentCount * sizeof(cx_icOp));
        pushIcs[argumentId] = cx_icOp__create(program, Fast_Node(_this)->line, CX_IC_PUSH, (cx_icValue)thisIc, NULL, NULL);
        pushIcs[argumentId]->s1Deref = CX_IC_DEREF_ADDRESS;
        pushIcs[argumentId]->s1Any = _this->instanceIsAny;
        argumentId++;
    } else {
        if (_this->arguments) {
            pushIcs = alloca(argumentCount * sizeof(cx_icOp));
        }
    }

    /* Push arguments */
    if (arguments) {
        cx_iter argumentIter;
        cx_ic argumentIc = NULL;
        cx_icStorage argumentStorage = NULL;
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
            pushIcs[argumentId] = cx_icOp__create(program, Fast_Node(_this)->line, CX_IC_PUSH, (cx_icValue)argumentIc, NULL, NULL);
            argumentId++;

            /* If parameterType is any and argument is not, push value as any */
            paramType = _this->parameters.buffer[i].type->real;
            exprType = Fast_Expression_getType(argument);

            if (paramType->kind == CX_ANY) {
                if (exprType && (exprType->kind != CX_ANY)) {
                    pushIcs[argumentId-1]->s1Any = TRUE;
                } else if (!exprType) {
                    pushIcs[argumentId-1]->s1Any = TRUE;
                }
                pushIcs[argumentId-1]->s1Deref = CX_IC_DEREF_ADDRESS;
            } else {
                if (!exprType) {
                    exprType = paramType;
                }
                if (_this->parameters.buffer[i].passByReference || 
                   (paramType->reference && !exprType->reference)) {
                    pushIcs[argumentId-1]->s1Deref = CX_IC_DEREF_ADDRESS;
                } else {
                    pushIcs[argumentId-1]->s1Deref = CX_IC_DEREF_PUSH;
                }
            }
            i++;
        }
        
        Fast_Expression_cleanList(arguments);
    }

    /* Add push-instructions just before doing the call so it doesn't interfere with call-expressions in
     * the argument list */
    for(argumentId = 0; argumentId < argumentCount; argumentId++) {
        cx_icProgram_addIc(program, (cx_ic)pushIcs[argumentId]);
    }

    /* Do call */
    function = Fast_Node_toIc(Fast_Node(_this->functionExpr), program, storage, stored);
    call = cx_icOp__create(program, Fast_Node(_this)->line, CX_IC_CALL, (cx_icValue)result, (cx_icValue)function, NULL);
    if (_this->returnsReference) {
        call->s1Deref = CX_IC_DEREF_ADDRESS;
    }

    cx_icProgram_addIc(program, (cx_ic)call);

    while(argumentStorageCount) {
        cx_icProgram_accumulatorPop(program, Fast_Node(_this)->line);
        argumentStorageCount--;
    }

    if (storage != result) {
        cx_icProgram_accumulatorPop(program, Fast_Node(_this)->line);
    }
    
    return (cx_ic)result;
/* $end */
}
