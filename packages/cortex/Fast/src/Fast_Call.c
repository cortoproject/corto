/* Fast_Call.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"

/* $header() */
#include "Fast__private.h"

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
            parameterType = _this->parameters.buffer[i].type;
            argumentType = Fast_Expression_getType(argument);

            if (_this->parameters.buffer[i].passByReference) {
                if (argumentType && !argument->isReference) {
                    Fast_Parser_error(yparser(), "cannot pass non-reference value as reference");
                    goto error;
                }
            }

            /* If both types are not equal, insert cast */
            if ((parameterType != argumentType) || ((argument->deref == Fast_ByReference) && !argumentType->reference)) {
                Fast_Expression expr;

                /* Any types are handled in the translation to the target representation. It is often
                 * more efficient to push a value as any than to first cast it to any and then push it. */
                if (parameterType->kind != CX_ANY) {
                    expr = Fast_Expression_cast(argument, parameterType, _this->parameters.buffer[i].passByReference);
                    if (expr) {
                        cx_claim(expr);
                        cx_llReplace(arguments, argument, expr);
                        cx_release(argument);
                    }
                }
            }

            i++;
        }
        cx_setref(&_this->arguments, Fast_Expression_fromList(arguments));
        Fast_Expression_cleanList(arguments);
    }

    return 0;
error:
    return -1;
}

/* $end */

/* ::cortex::Fast::Call::construct() */
cx_int16 _Fast_Call_construct(Fast_Call _this) {
/* $begin(::cortex::Fast::Call::construct) */
    Fast_Node(_this)->kind = Fast_CallExpr;

    /* Insert casts based on expression list and arguments */
    if (Fast_Call_insertCasts(_this)) {
        goto error;
    }

    cx_setref(&Fast_Expression(_this)->type, _this->returnType);
    Fast_Expression(_this)->isReference =
        _this->returnsReference || _this->returnType->reference;

    Fast_Expression(_this)->deref = _this->returnType->reference ? Fast_ByReference : Fast_ByValue;

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::Call::hasReturnedResource() */
cx_bool Fast_Call_hasReturnedResource_v(Fast_Call _this) {
/* $begin(::cortex::Fast::Call::hasReturnedResource) */

    return _this->returnType->reference || 
        _this->returnsReference || 
        ((_this->returnType->kind == CX_PRIMITIVE) && (cx_primitive(_this->returnType)->kind == CX_TEXT));

/* $end */
}

/* ::cortex::Fast::Call::hasSideEffects() */
cx_bool _Fast_Call_hasSideEffects_v(Fast_Call _this) {
/* $begin(::cortex::Fast::Call::hasSideEffects) */
    CX_UNUSED(_this);
    return TRUE;
/* $end */
}

/* ::cortex::Fast::Call::setParameters(function function) */
cx_void _Fast_Call_setParameters(Fast_Call _this, cx_function function) {
/* $begin(::cortex::Fast::Call::setParameters) */
    cx_uint32 i;

    /* Set parameters */
    cx_setref(&_this->returnType, function->returnType);
    _this->returnsReference = function->returnsReference;

    cx_parameter_seq__size(&_this->parameters, function->parameters.length);

    for (i = 0; i < function->parameters.length; i++) {
        cx_setref(&_this->parameters.buffer[i].type, function->parameters.buffer[i].type);
        _this->parameters.buffer[i].name = cx_strdup(function->parameters.buffer[i].name);
        _this->parameters.buffer[i].passByReference = function->parameters.buffer[i].passByReference;
    }
/* $end */
}

/* ::cortex::Fast::Call::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Call_toIc_v(Fast_Call _this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::cortex::Fast::Call::toIc) */
    ic_storage result = NULL;
    ic_node function;
    Fast_Expression argument = NULL;
    ic_op *pushIcs = NULL; /* Cache push instructions before inserting in program to avoid issues with nested calls */
    cx_int32 argumentId = 0, argumentCount = 0;
    cx_type _thisType = Fast_Expression_getType(Fast_Expression(_this));
    cx_ll arguments = NULL;
    cx_uint32 argumentStorageCount = 0;
    cx_int32 i = 0;

    CX_UNUSED(stored);

    if (storage && (storage->type == _thisType)) {
        result = storage;
        result->holdsReturn = TRUE;
    } else {
        result = (ic_storage)ic_program_pushAccumulator(
            program, _thisType, _this->returnsReference, TRUE);
    }

    /* Convert arguments to iterable list */
    if (_this->arguments) {
        arguments = Fast_Expression_toList(_this->arguments);
        if (arguments) {
            argumentCount = cx_llSize(arguments);
        }
    }

    /* Push 'this' if function is a method or metaprocedure */
    if (_this->instanceExpr) {
        ic_node thisIc = Fast_Node_toIc(Fast_Node(_this->instanceExpr), program, NULL, TRUE);
        argumentCount += 1;
        pushIcs = alloca(argumentCount * sizeof(ic_op));
        pushIcs[argumentId] = IC_1_OP(Fast_Node(_this)->line, ic_push, thisIc, IC_DEREF_ADDRESS, _this->instanceIsAny);
        argumentId++;
    } else {
        if (_this->arguments) {
            pushIcs = alloca(argumentCount * sizeof(ic_op));
        }
    }

    /* Push arguments */
    if (arguments) {
        cx_iter argumentIter;
        ic_node argumentIc = NULL;
        ic_storage argumentStorage = NULL;

        /* Temporary storage for push-instructions required for pushing the arguments of this function */
        argumentIter = cx_llIter(arguments);
        while(cx_iterHasNext(&argumentIter)) {
            cx_type paramType, exprType;
            ic_derefKind deref = IC_DEREF_ADDRESS;
            cx_bool isAny = FALSE;

            argument = cx_iterNext(&argumentIter);
            if (!argumentStorage ||
              (argumentIc == (ic_node)argumentStorage) ||
              (Fast_Expression_getType(argument) != argumentStorage->type)) {
                argumentStorage = (ic_storage)ic_program_pushAccumulator(
                    program,
                    Fast_Expression_getType(argument),
                    _this->parameters.buffer[i].passByReference || _this->parameters.buffer[i].type->reference,
                    FALSE);
                argumentStorageCount++;
            }

            paramType = _this->parameters.buffer[i].type;
            exprType = Fast_Expression_getType(argument);

            if (paramType->kind == CX_ANY) {
                if (exprType && (exprType->kind != CX_ANY)) {
                    isAny = TRUE;
                } else if (!exprType) {
                    isAny = TRUE;
                }
            } else {
                if (!exprType) {
                    exprType = paramType;
                }
            }

            if (!isAny && Fast_Expression(argument)->deref == Fast_ByValue) {
                /* If argument is pass by value or argument is not a primitive, pass by value */
                if (!_this->parameters.buffer[i].passByReference || (paramType->kind != CX_PRIMITIVE)) {
                    /* Void references can't be passed as value */
                    if ((exprType->kind != CX_VOID) && (paramType->kind != CX_VOID)) {
                        deref = IC_DEREF_VALUE;
                    }
                }
            }

            argumentIc = Fast_Node_toIc(Fast_Node(argument), program, argumentStorage, TRUE);
            pushIcs[argumentId] = IC_1_OP(
                Fast_Node(_this)->line,
                ic_push, argumentIc,
                deref,
                isAny);
            i++;
            argumentId++;
        }
        Fast_Expression_cleanList(arguments);
    }

    for(i = 0; i < argumentCount; i++) {
        ic_program_add(program, (ic_node)pushIcs[i]);
    }

    function = Fast_Node_toIc(Fast_Node(_this->functionExpr), program, storage, stored);

    IC_3(program, Fast_Node(_this)->line, ic_call, result, function, NULL,
        (_this->returnType->reference || _this->returnsReference) ? IC_DEREF_ADDRESS : IC_DEREF_VALUE, 
        IC_DEREF_VALUE, 
        IC_DEREF_VALUE);

    while(argumentStorageCount) {
        ic_program_popAccumulator(program);
        argumentStorageCount--;
    }

    if (storage != result) {
        ic_program_popAccumulator(program);
    }

    return (ic_node)result;
/* $end */
}
