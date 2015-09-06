/* Fast_Call.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_Fast_LIB
#include "Fast.h"

/* $header() */
#include "Fast__private.h"

/* Insert implicit casts when argument-expressions do not match */
cx_int16 Fast_Call_insertCasts(Fast_Call this) {
    cx_iter argumentIter;
    Fast_Expression argument;
    cx_uint32 i = 0;
    cx_type parameterType, argumentType;

    if (this->arguments) {
        cx_ll arguments = Fast_Expression_toList(this->arguments);
        argumentIter = cx_llIter(arguments);
        while(cx_iterHasNext(&argumentIter)) {
            argument = cx_iterNext(&argumentIter);
            parameterType = this->parameters.buffer[i].type;
            argumentType = Fast_Expression_getType(argument);

            if (this->parameters.buffer[i].passByReference) {
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
                    expr = Fast_Expression_cast(argument, parameterType, this->parameters.buffer[i].passByReference);
                    if (expr) {
                        cx_claim(expr);
                        cx_llReplace(arguments, argument, expr);
                        cx_release(argument);
                    }
                }
            }

            i++;
        }
        cx_setref(&this->arguments, Fast_Expression_fromList(arguments));
        Fast_Expression_cleanList(arguments);
    }

    return 0;
error:
    return -1;
}

/* $end */

/* ::corto::Fast::Call::construct() */
cx_int16 _Fast_Call_construct(Fast_Call this) {
/* $begin(::corto::Fast::Call::construct) */
    Fast_Node(this)->kind = Fast_CallExpr;

    /* Insert casts based on expression list and arguments */
    if (Fast_Call_insertCasts(this)) {
        goto error;
    }

    cx_setref(&Fast_Expression(this)->type, this->returnType);
    Fast_Expression(this)->isReference =
        this->returnsReference || this->returnType->reference;

    Fast_Expression(this)->deref = this->returnType->reference ? Fast_ByReference : Fast_ByValue;

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::Fast::Call::hasReturnedResource() */
cx_bool _Fast_Call_hasReturnedResource_v(Fast_Call this) {
/* $begin(::corto::Fast::Call::hasReturnedResource) */

    return this->returnType->reference || 
        this->returnsReference || 
        ((this->returnType->kind == CX_PRIMITIVE) && (cx_primitive(this->returnType)->kind == CX_TEXT));

/* $end */
}

/* ::corto::Fast::Call::hasSideEffects() */
cx_bool _Fast_Call_hasSideEffects_v(Fast_Call this) {
/* $begin(::corto::Fast::Call::hasSideEffects) */
    CX_UNUSED(this);
    return TRUE;
/* $end */
}

/* ::corto::Fast::Call::setParameters(function function) */
cx_void _Fast_Call_setParameters(Fast_Call this, cx_function function) {
/* $begin(::corto::Fast::Call::setParameters) */
    cx_uint32 i;

    /* Set parameters */
    cx_setref(&this->returnType, function->returnType);
    this->returnsReference = function->returnsReference;

    cx_parameterSeqSize(&this->parameters, function->parameters.length);

    for (i = 0; i < function->parameters.length; i++) {
        cx_setref(&this->parameters.buffer[i].type, function->parameters.buffer[i].type);
        this->parameters.buffer[i].name = cx_strdup(function->parameters.buffer[i].name);
        this->parameters.buffer[i].passByReference = function->parameters.buffer[i].passByReference;
    }
/* $end */
}

/* ::corto::Fast::Call::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Call_toIc_v(Fast_Call this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::Fast::Call::toIc) */
    ic_storage result = NULL;
    ic_node function;
    Fast_Expression argument = NULL;
    ic_op *pushIcs = NULL; /* Cache push instructions before inserting in program to avoid issues with nested calls */
    cx_int32 argumentId = 0, argumentCount = 0;
    cx_type thisType = Fast_Expression_getType(Fast_Expression(this));
    cx_ll arguments = NULL;
    cx_uint32 argumentStorageCount = 0;
    cx_int32 i = 0;

    CX_UNUSED(stored);

    if (storage && (storage->type == thisType)) {
        result = storage;
        result->holdsReturn = TRUE;
    } else {
        result = (ic_storage)ic_program_pushAccumulator(
            program, thisType, this->returnsReference || this->returnType->reference, TRUE);
    }

    /* Convert arguments to iterable list */
    if (this->arguments) {
        arguments = Fast_Expression_toList(this->arguments);
        if (arguments) {
            argumentCount = cx_llSize(arguments);
        }
    }

    /* Push 'this' if function is a method or metaprocedure */
    if (this->instanceExpr) {
        ic_node thisIc = Fast_Node_toIc(Fast_Node(this->instanceExpr), program, NULL, TRUE);
        argumentCount += 1;
        pushIcs = alloca(argumentCount * sizeof(ic_op));
        pushIcs[argumentId] = IC_1_OP(Fast_Node(this)->line, ic_push, thisIc, IC_DEREF_ADDRESS, this->instanceIsAny);
        argumentId++;
    } else {
        if (this->arguments) {
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
                    this->parameters.buffer[i].passByReference || this->parameters.buffer[i].type->reference,
                    FALSE);
                argumentStorageCount++;
            }

            paramType = this->parameters.buffer[i].type;
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
                if (!this->parameters.buffer[i].passByReference || (paramType->kind != CX_PRIMITIVE)) {
                    /* Void references can't be passed as value */
                    if ((exprType->kind != CX_VOID) && (paramType->kind != CX_VOID)) {
                        deref = IC_DEREF_VALUE;
                    }
                }
            }

            argumentIc = Fast_Node_toIc(Fast_Node(argument), program, argumentStorage, TRUE);
            pushIcs[argumentId] = IC_1_OP(
                Fast_Node(this)->line,
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

    function = Fast_Node_toIc(Fast_Node(this->functionExpr), program, storage, stored);

    IC_3(program, Fast_Node(this)->line, ic_call, result, function, NULL,
        (this->returnType->reference || this->returnsReference) ? IC_DEREF_ADDRESS : IC_DEREF_VALUE, 
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
