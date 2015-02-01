/*
 * cx_ic_assemble.c
 *
 *  Created on: Aug 28, 2013
 *      Author: sander
 */

#include "cx_ic.h"
#include "cx_ll.h"
#include "cx_mem.h"
#include "cx_util.h"
#include "cx_err.h"
#include "cx__meta.h"
#include "cx_value.h"
#include "cx__vm_operands.h"
#include "cx_object.h"
#include "cx_struct.h"

typedef struct cx_ic_vmLabel {
    cx_uint32 id;
    cx_uint32 pc;
    void *referees[256]; /* The jumps to this label. At assemble-time, the exact address of the label is not yet known
                          * so this information is filled in after the program is assembled for each referee */
    cx_uint32 refereeCount;
}cx_ic_vmLabel;

typedef struct cx_ic_vmStorage cx_ic_vmStorage;
struct cx_ic_vmStorage {
    cx_icStorage accumulator;
    cx_uint32 firstUsed;
    cx_uint32 lastUsed;
    void *referees[256]; /* The jumps to this accumulator. At assemble-time, the exact address of the accumulator is not yet known
                          * so this information is filled in after the program is assembled for each referee */
    cx_uint32 refereeCount;
    cx_uint16 addr;

    /* Member & element accumulators have a base and offset */
    cx_uint16 offset;
    cx_ic_vmStorage *base;
    cx_bool assembled; /* Offsets of multiple member-operations are accumulated into one register so that
                        * instead of calculating multiple offsets at runtime, only one operation is required. This
                        * variable remains FALSE until the storage is used after which an operation is inserted
                        * to calculate the accumulated offset.
                        * This is only applicable for access to dynamically allocated objects or storages with dynamic
                        * components (elements with variable indexes). By default this value is TRUE. */
    cx_bool dynamic;   /* A dynamic storage needs to be assembled each time it is evaluated because the storage depends
                        * on the value of other storages, for example the index-expression of an element storage. */
};

typedef struct cx_ic_vmInlineFunction {
    cx_vmProgram program;
    cx_function function;
}cx_ic_vmInlineFunction;

typedef struct cx_ic_vmProgram {
    cx_icProgram icProgram;
    cx_vmProgram main; /* Keep track of what is the main-module of a program (where the program starts) */
    cx_vmProgram program;
    cx_icFunction function;
    cx_ll labels;
    cx_ll accumulators;
    cx_ll inlineFunctions;
    cx_uint16 scopeSize[256];
    cx_uint32 scope;
    cx_uint32 maxScopeSize; /* The maximum scope-size is where accumulators are allocated (thus after the locals) */
    cx_uint32 stackSize;
    cx_uint32 maxStackSize; /* The maximum stack-size is the maximum amount of space a call needs for its arguments */
}cx_ic_vmProgram;

typedef enum cx_ic_vmType {
    CX_IC_VMTYPE_B,
    CX_IC_VMTYPE_S,
    CX_IC_VMTYPE_L,
    CX_IC_VMTYPE_W,
    CX_IC_VMTYPE_D
}cx_ic_vmType;

typedef enum cx_ic_vmOperand {
    CX_IC_VMOPERAND_NONE,
    CX_IC_VMOPERAND_V,
    CX_IC_VMOPERAND_R,
    CX_IC_VMOPERAND_P,
    CX_IC_VMOPERAND_Q,
    CX_IC_VMOPERAND_X,
    CX_IC_VMOPERAND_L
}cx_ic_vmOperand;

cx_string cx_ic_vmOperandStr(cx_ic_vmOperand op) {
    switch(op) {
        case CX_IC_VMOPERAND_NONE: return "none";
        case CX_IC_VMOPERAND_V: return "V";
        case CX_IC_VMOPERAND_R: return "R";
        case CX_IC_VMOPERAND_P: return "P";
        case CX_IC_VMOPERAND_Q: return "Q";
        case CX_IC_VMOPERAND_X: return "X";
        case CX_IC_VMOPERAND_L: return "L";
    };
    return "<?>";
}

static cx_ic_vmStorage *cx_ic_vmStorageGet(cx_ic_vmProgram *program, cx_icStorage icAccumulator);

static void cx_ic_vmProgram_fillInLabels(cx_ic_vmProgram *program) {
    cx_iter labelIter;
    cx_ic_vmLabel *label;
    cx_uint32 referee;

    if (program->labels) {
        labelIter = cx_llIter(program->labels);
        while(cx_iterHasNext(&labelIter)) {
            label = cx_iterNext(&labelIter);
            for(referee=0; referee < label->refereeCount; referee++) {
                *(void**)CX_OFFSET(label->referees[referee], program->program->program) = &program->program->program[label->pc];
            }

            /* Free label */
            cx_dealloc(label);
        }

        /* Free label list */
        cx_llFree(program->labels);
        program->labels = NULL;
    }
}

/* Administration that keeps track of claims accumulators have on the register */
typedef struct cx_ic_registerClaim {
    cx_ic_vmStorage *accumulator;
    cx_uint16 addr;
    cx_uint16 size;
    cx_uint32 start;
    cx_uint32 end;
}cx_ic_registerClaim;

/* Determine whether storage is of a reference type or passed by reference. */
cx_bool cx_ic_isReference(cx_icStorage storage) {
    cx_type t = storage->type;
    cx_bool result = FALSE;

    if (storage->isReference) {
        result = TRUE;
    } else {
        if (storage->kind == CX_STORAGE_LOCAL) {
            if (((cx_icLocal)storage)->isParameter) {
                if (t->kind != CX_PRIMITIVE) {
                    result = TRUE;
                }
            }
        }
    }

    return result;
}

/* Determine whether for a storage space must be allocated or whether a storage is pointing
 * directly to an object\local. */
cx_bool cx_ic_storageMustAllocate(cx_ic_vmProgram *program, cx_ic_vmStorage *accumulator, cx_bool *collapsed) {
    cx_bool result = FALSE;

    /* Accumulator must be referred otherwise it should not take up space */
    if (accumulator->refereeCount) {
        cx_icStorageKind kind = accumulator->accumulator->kind;

        /* Accumulators must always be allocated */
        if (kind == CX_STORAGE_ACCUMULATOR) {
            result = TRUE;
        } else {
            if (accumulator->base && ((kind == CX_STORAGE_MEMBER) || (kind == CX_STORAGE_ELEMENT))) {
                cx_bool collapse = FALSE;
                cx_icStorage base = accumulator->base->accumulator;

                /* Determine whether accumulator must be collapsed with base because its offset
                 * is zero. Only applicable for member-storages and element-storages of which the
                 * collection-type is an ARRAY. In these cases the calculated address with offset
                 * zero is equal to the base-address. */
                if (!accumulator->offset) {
                    if (kind == CX_STORAGE_MEMBER) {
                        collapse = TRUE;
                    } else {
                        cx_collection type = cx_collection(accumulator->accumulator->type);
                        switch(type->kind) {
                        case CX_ARRAY:
                            collapse = TRUE;
                            break;
                        default:
                            break;
                        }
                    }
                }
                if (collapsed) {
                    *collapsed = collapse;
                }

                /* If the base is of a reference type and the base is not an object, address
                 * is stored in an accumulator for which space must be allocated. If the offset of the
                 * member is zero do not allocate the accumulator, instead use the base (see below). */
                if (!collapse && (cx_ic_isReference(base) && (base->kind != CX_STORAGE_OBJECT))) {
                    result = TRUE;

                /* If storage is dynamic, address must be temporarily stored in an accumulator
                 * for which space must be allocated. */
                } else if (accumulator->dynamic) {
                    result = TRUE;
                } else {
                    cx_uint32 referee;
                    /* If base is dynamic or offset is 0 (meaning address is equal to base), collapse this accumulator into the base. */
                    for(referee=0; referee < accumulator->refereeCount; referee++) {
                        *(cx_uint16*)CX_OFFSET(accumulator->referees[referee], program->program->program) = accumulator->base->addr;
                        if(!accumulator->base->dynamic) {
                            *(cx_uint16*)CX_OFFSET(accumulator->referees[referee], program->program->program) += accumulator->offset;
                        }
                    }
                    /* No need to allocate this accumulator */
                    result = FALSE;
                }
            }
        }
    }

    return result;
}

static void cx_ic_vmProgram_allocateAccumulators(cx_ic_vmProgram *program) {
    cx_iter accumulatorIter;
    cx_ic_vmStorage *accumulator;
    cx_uint16 offset;
    cx_ic_registerClaim claims[256];
    cx_ic_registerClaim *claim;
    cx_uint32 i, referee;
    cx_bool overlap;

    memset(claims, 0, sizeof(claims));
    offset = program->maxScopeSize;

    if (program->accumulators) {
        accumulatorIter = cx_llIter(program->accumulators);
        while(cx_iterHasNext(&accumulatorIter)) {
            accumulator = cx_iterNext(&accumulatorIter);

            if (cx_ic_storageMustAllocate(program, accumulator, NULL)) {
                /* Find lfree claim */
                claim = claims;
                while(claim->accumulator) {
                    if (claim->end < accumulator->firstUsed) { /* Accumulators are chronologically ordered, so this is valid */
                        break;
                    }
                    claim++;
                }

                claim->accumulator = accumulator;
                claim->start = accumulator->firstUsed;
                claim->end = accumulator->lastUsed;
                claim->addr = offset;
                
                /* If accumulator has to be allocated and it has a base, accumulator represents a member address */
                if (accumulator->base) {
                    claim->size = sizeof(cx_word);
                } else {
                    claim->size = cx_type_sizeof(accumulator->accumulator->type);
                }
                /* Find free register */
                do {
                    overlap = FALSE;
                    for(i=0; i<256; i++) {
                        /* If claim has expired, remove from list */
                        if (claims[i].end < claim->start) {
                            claims[i].end = 0;
                            continue;
                        }

                        /* Check if claim overlaps with this claim */
                        if ( (claim != &claims[i]) && ((claims[i].end >= claim->start) || (claims[i].start <= claim->end)) ) {
                            /* Check if claim overlaps address */
                            if ( ((claims[i].addr + claims[i].size) > claim->addr) && (claims[i].addr < (claim->addr + claim->size)) ) {
                                /* Choose new address and try again */
                                claim->addr = claims[i].addr + claims[i].size;
                                overlap = TRUE;
                                break;
                            }
                        }
                    }
                }while (overlap);

                if ((claim->addr + claim->size) > program->maxScopeSize) {
                    program->maxScopeSize = claim->addr + claim->size;
                }

                /* Walk referees */
                for(referee=0; referee < accumulator->refereeCount; referee++) {
                    *(cx_uint16*)CX_OFFSET(accumulator->referees[referee], program->program->program) = claim->addr;
                }
                accumulator->addr = claim->addr;
            }
        }

        /* Free resources */
        accumulatorIter = cx_llIter(program->accumulators);
        while(cx_iterHasNext(&accumulatorIter)) {
            accumulator = cx_iterNext(&accumulatorIter);
            cx_dealloc(accumulator);
        }
        cx_llFree(program->accumulators);
        program->accumulators = NULL;
    }
}

void cx_ic_vmProgram_clean(cx_ic_vmProgram *vmProgram) {
    /* Reset values */
    vmProgram->scope = 0;
    vmProgram->maxScopeSize = 0;
    vmProgram->stackSize = 0;
    vmProgram->maxStackSize = 0;
    vmProgram->program = NULL;
}

extern cx_bool CX_DEBUG_ENABLED;

void cx_ic_vmProgram_finalize(cx_ic_vmProgram *vmProgram) {
    cx_vmOp  *stop;

    /* Add STOP instruction if this is the main-module */
    if (vmProgram->main == vmProgram->program) {
        stop = cx_vmProgram_addOp(vmProgram->program, 0);
        stop->op = CX_VM_STOP;
    }

    /* Fill in labels */
    cx_ic_vmProgram_fillInLabels(vmProgram);

    /* Allocate and fill in accumulators */
    cx_ic_vmProgram_allocateAccumulators(vmProgram);

    /* Set size of program */
    vmProgram->program->storage = vmProgram->maxScopeSize;
    vmProgram->program->stack = vmProgram->maxStackSize;

    /* If program is a function, set the function-implementation to the program */
    if (vmProgram->function) {
        cx_function function = vmProgram->function->function;
        function->impl = (cx_word)cx_call_vm;
        function->implData = (cx_word)vmProgram->program;
        cx_define(function);

#ifdef CX_IC_TRACING
        if (CX_DEBUG_ENABLED)
        {
            cx_id id;
            cx_string programStr = cx_vmProgram_toString(vmProgram->program, NULL);
            printf("%s %s\n%s\n", cx_nameof(cx_typeof(function)), cx_fullname(function, id), programStr);
            cx_dealloc(programStr);
        }
#endif
    }

#ifdef CX_IC_TRACING
    if (CX_DEBUG_ENABLED) {
        if (vmProgram->main == vmProgram->program) {
            cx_string programStr = cx_vmProgram_toString(vmProgram->program, NULL);
            printf("main\n%s\n", programStr);
            cx_dealloc(programStr);
        }
    }
#endif

    /* Clean resources */
    cx_ic_vmProgram_clean(vmProgram);
}

static cx_ic_vmLabel *cx_ic_vmLabelNew(cx_uint32 id) {
    cx_ic_vmLabel *result;

    result = cx_malloc(sizeof(cx_ic_vmLabel));
    result->id = id;
    result->pc = 0;
    result->refereeCount = 0;

    return result;
}

static cx_ic_vmLabel *cx_ic_vmLabelGet(cx_ic_vmProgram *program, cx_uint32 id) {
    cx_iter labelIter;
    cx_ic_vmLabel *label = NULL;

    if (program->labels) {
        labelIter = cx_llIter(program->labels);
        while(cx_iterHasNext(&labelIter)) {
            label = cx_iterNext(&labelIter);
            if (label->id == id) {
                break;
            } else {
                label = NULL;
            }
        }
    }

    if (!label) {
        label = cx_ic_vmLabelNew(id);
        if (!program->labels) {
            program->labels = cx_llNew();
        }
        cx_llAppend(program->labels, label);
    }

    return label;
}

static void cx_ic_vmLabelAddReferee(cx_ic_vmProgram *program, cx_ic_vmLabel *label, void *referee) {
    label->referees[label->refereeCount] = CX_OFFSET(referee, -(intptr_t)program->program->program);;
    cx_assert(label->refereeCount < 256, "unsupported number of references to one label (max is 256)");
    label->refereeCount++;
}

static cx_ic_vmStorage *cx_ic_vmStorageNew(cx_ic_vmProgram *program, cx_icStorage accumulator, cx_uint32 firstUsed) {
    cx_ic_vmStorage *result;

    result = cx_malloc(sizeof(cx_ic_vmStorage));
    result->accumulator = accumulator;
    result->refereeCount = 0;
    result->firstUsed = firstUsed;
    result->addr = 0;
    result->offset = 0;
    result->base = NULL;
    result->dynamic = FALSE;
    result->assembled = TRUE;

    if (accumulator->kind == CX_STORAGE_MEMBER) {
        cx_icMember member = ((cx_icMember)accumulator);
        result->assembled = FALSE;

        if (member->base) {
            result->base = cx_ic_vmStorageGet(program, member->base);
            if (member->member) {
                result->offset = result->base->offset + member->member->offset;
            }

            if (!result->base->dynamic && result->base->base) {
                result->base = result->base->base;
            }
           }
    } else if (accumulator->kind == CX_STORAGE_ELEMENT) {
        cx_icElement element = ((cx_icElement)accumulator);
        result->assembled = FALSE;

        if (element->base) {
            result->base = cx_ic_vmStorageGet(program, element->base);

            /* If element is an array and index-expression is a literal, offset is determined at compile-time. */
            if (element->index->_parent.kind == CX_IC_LITERAL) {
                if (element->collectionType->kind == CX_ARRAY) {
                    cx_uint32 index = ((cx_icLiteral)element->index)->value.is.literal.v._unsigned_integer;
                    result->offset = index * cx_type_sizeof(element->collectionType->elementType);
                    result->dynamic = FALSE;
                } else {
                    result->dynamic = TRUE;
                }
            } else {
                result->dynamic = TRUE;

                /* Inherit the offset of the base. The actual offset is determined at runtime but this static offset will be added at
                 * compile-time. Setting this offset on a dynamic storage negates the need to set base to any member\element storages
                 * rather than just the dynamic storages and variable storages. */
                result->offset = result->base->offset;
            }
            
            result->offset += result->base->offset;

             if (!result->base->dynamic && result->base->base) {
                result->base = result->base->base;
            }
        }
     }
    
    /* Now the base of a member or element always points to either the variable or the first encountered dynamic storage.
     * Storages which are itself dynamic or storages with a dynamic base must always be evaluated for accumulator-allocation. */

    return result;
}

static void cx_ic_vmStorageAddReferee(cx_ic_vmProgram *program, cx_ic_vmStorage *accumulator, void *referee) {
    accumulator->referees[accumulator->refereeCount] = CX_OFFSET(referee, -(intptr_t)program->program->program);
    cx_assert(accumulator->refereeCount < 256, "unsupported number of references to one accumulator (max is 256)");
    accumulator->refereeCount++;
}

static cx_ic_vmStorage *cx_ic_vmStorageGet(cx_ic_vmProgram *program, cx_icStorage icAccumulator) {
    cx_iter accumulatorIter;
    cx_ic_vmStorage *accumulator = NULL;

    if (program->accumulators) {
        accumulatorIter = cx_llIter(program->accumulators);
        while(cx_iterHasNext(&accumulatorIter)) {
            accumulator = cx_iterNext(&accumulatorIter);
            if (accumulator->accumulator == icAccumulator) {
                break;
            } else {
                accumulator = NULL;
            }
        }
    }

    if (!accumulator) {
        if (!program->program) {
            program->program = cx_vmProgram_new(program->icProgram->filename, program->function->function);
        }
        accumulator = cx_ic_vmStorageNew(program, icAccumulator, program->program->size);
        if (!program->accumulators) {
            program->accumulators = cx_llNew();
        }
        cx_llAppend(program->accumulators, accumulator);
    }

    /* Keep track of where an accumulator is last used */
    accumulator->lastUsed = program->program->size;

    return accumulator;
}

cx_type cx_ic_valueType(cx_icValue s) {
    cx_type t = NULL;

    switch(s->_parent.kind) {
    case CX_IC_LITERAL:
        t = ((cx_icLiteral)s)->type;
        break;
    case CX_IC_STORAGE:
        t = ((cx_icStorage)s)->type;
        break;
    default:
        cx_assert(0, "invalid operand type");
        break;
    }

    return t;
}

cx_void *cx_ic_valueValue_width(cx_ic_vmProgram *program, cx_icValue s, void* truncated, int width) {
    void *result = NULL;

    switch(s->_parent.kind) {
    case CX_IC_LITERAL: {
        cx_value *v = &((cx_icLiteral)s)->value;
        switch(v->is.literal.kind) {
        case CX_LITERAL_BOOLEAN:
            *(cx_uint16*)truncated = *(cx_bool*)cx_valueValue(v);
            result = truncated;
            break;
        case CX_LITERAL_FLOATING_POINT:
            if (width == sizeof(cx_float32)) {
                if (truncated) {
                    *(cx_float32*)truncated = *(cx_float64*)cx_valueValue(v);
                    result = truncated;
                } else {
                    result = cx_valueValue(v);
                }
            } else {
                result = cx_valueValue(v);
            }
            break;
        case CX_LITERAL_NULL:
            *(cx_word*)truncated = 0;
            result = truncated;
            break;
        default:
            result = cx_valueValue(v);
            break;
        }
        break;
    }
    case CX_IC_STORAGE:
        switch(((cx_icStorage)s)->kind) {
        case CX_STORAGE_OBJECT:
            result = &((cx_icObject)s)->ptr;
            break;
        case CX_STORAGE_LOCAL:
            cx_assert(0, "local cannot be interpreted as a value");
            result = NULL;
            break;
        case CX_STORAGE_ACCUMULATOR:
            result = &((cx_icAccumulator)s)->accumulatorId;
            break;
        case CX_STORAGE_MEMBER:
            if (((cx_icMember)s)->base->kind == CX_STORAGE_OBJECT) {
                cx_ic_vmStorage *vmStorage = cx_ic_vmStorageGet(program, (cx_icStorage)s);
                cx_object obj = ((cx_icObject)vmStorage->base->accumulator)->ptr;
                *(void**)truncated = CX_OFFSET(obj, ((cx_icMember)s)->member->offset);
                result = truncated;
            } else {
                cx_assert(0, "local/dynamic member '%s' cannot be interpreted as a value", ((cx_icStorage)s)->name);
            }
            break;
        case CX_STORAGE_ELEMENT:
            if (!((cx_icElement)s)->dynamic) {
                cx_ic_vmStorage *vmStorage = cx_ic_vmStorageGet(program, (cx_icStorage)s);
                cx_object obj = ((cx_icObject)vmStorage->base->accumulator)->ptr;
                *(void**)truncated = CX_OFFSET(obj, vmStorage->offset);
                result = truncated;
            } else {
                cx_assert(0, "local/dynamic member '%s' cannot be interpreted as a value", ((cx_icStorage)s)->name);
            }
            break;
        default:
            cx_assert(0, "invalid storage kind");
            break;
        }
        break;
    case CX_IC_LABEL:
        result = &((cx_icLabel)s)->id;
        break;
    default:
        cx_assert(0, "invalid operand type");
        break;
    }

    return result;
}

cx_ic_vmType cx_ic_getVmType(cx_icValue s, cx_icDerefMode deref) {
    cx_ic_vmType result = CX_IC_VMTYPE_B;
    cx_type t = cx_ic_valueType(s);

    /* Determine VM type based on width of a type. If the value is
     * a storage and derefMode is value, the value is considered a
     * pointer and thus the type is W */
    if ((((cx_ic)s)->kind == CX_IC_STORAGE) && (deref == CX_IC_DEREF_ADDRESS)) {
        result = CX_IC_VMTYPE_W;
    } else {
        if (t->kind == CX_PRIMITIVE) {
            switch(cx_primitive(t)->width) {
            case CX_WIDTH_8:
                result = CX_IC_VMTYPE_B;
                break;
            case CX_WIDTH_16:
                result = CX_IC_VMTYPE_S;
                break;
            case CX_WIDTH_32:
                result = CX_IC_VMTYPE_L;
                break;
            case CX_WIDTH_64:
                result = CX_IC_VMTYPE_D;
                break;
            case CX_WIDTH_WORD:
                /* Reserve usage of W for pointer/string types */
                if (cx_primitive(t)->kind == CX_TEXT) {
                    result = CX_IC_VMTYPE_W;
                } else {
                    if (sizeof(intptr_t) == 4) {
                        result = CX_IC_VMTYPE_L;
                    }else {
                        result = CX_IC_VMTYPE_D;
                    }
                }
                break;
            }
        /* If type is not primitive instruction will take the address of the operand */
        } else {
            result = CX_IC_VMTYPE_W;
        }
    }

    return result;
}

cx_ic_vmOperand cx_ic_getVmOperand(cx_ic_vmProgram *program, cx_icDerefMode deref, cx_icValue s) {
    cx_ic_vmOperand result = CX_IC_VMOPERAND_V;

    switch(s->_parent.kind) {
    case CX_IC_LABEL:
        result = CX_IC_VMOPERAND_L;
        break;
    case CX_IC_LITERAL:
        result = CX_IC_VMOPERAND_V;
        break;
    case CX_IC_STORAGE: {
        cx_ic_vmStorage *acc = cx_ic_vmStorageGet(program, (cx_icStorage)s);
        cx_icStorage base = acc->base ? acc->base->accumulator : NULL;
        cx_icStorageKind kind = ((cx_icStorage)s)->kind;
        cx_bool isReference = base ? cx_ic_isReference(base) : cx_ic_isReference((cx_icStorage)s);
        cx_bool isRefType = ((cx_icStorage)s)->type->reference;
        cx_bool isPrimitiveType = ((cx_icStorage)s)->type->kind == CX_PRIMITIVE;
        cx_bool isObject = kind == CX_STORAGE_OBJECT;
        cx_bool isStatic = !acc->dynamic && (!base || !acc->base->dynamic);
        cx_bool collapse = FALSE;
        cx_ic_storageMustAllocate(program, acc, &collapse);

        if (!acc->dynamic && base && !acc->base->dynamic) {
            isObject = base->kind == CX_STORAGE_OBJECT;
        }
 
        switch(deref) {
        case CX_IC_DEREF_ADDRESS:
            if (isObject) {
                if (!(base && isRefType)) {
                    result = CX_IC_VMOPERAND_V;
                } else {
                    result = CX_IC_VMOPERAND_P;
                }
            } else {
                if (isReference) {
                    if (base) {
                        if (!isRefType) {
                            result = CX_IC_VMOPERAND_R;
                        } else {
                            result = CX_IC_VMOPERAND_Q;
                        }
                    } else {
                        result = CX_IC_VMOPERAND_R;
                    }
                } else {
                    if (isRefType) {
                        if (isStatic) {
                            result = CX_IC_VMOPERAND_R;
                        } else {
                            result = CX_IC_VMOPERAND_Q;
                        }
                    } else {
                        result = CX_IC_VMOPERAND_X;
                    }
                }
            }
            break;
        case CX_IC_DEREF_PUSH:
        case CX_IC_DEREF_VALUE:
            if (isObject) {
                /* When pushing either objects of a reference type or a non-primitive type,
                 * push object-address. */
                if ((deref == CX_IC_DEREF_PUSH) && (isRefType || !isPrimitiveType)) {
                    result = CX_IC_VMOPERAND_V;

                /* When accessing non-reference primitive values, obtain value of object. */
                } else {
                    result = CX_IC_VMOPERAND_P;
                }
            } else {
                if ((deref == CX_IC_DEREF_PUSH) && !isPrimitiveType && !isReference) {
                    if (isStatic) {
                        /* If value is not a primitive it must always be passed as reference. If the object is
                         * not already a reference, take the address of the register/local. */
                        result = CX_IC_VMOPERAND_X;
                    } else {
                        result = CX_IC_VMOPERAND_R;
                    }
                } else {
                    if (isStatic) {
                        if (!isRefType && isReference && isPrimitiveType) {
                            result = CX_IC_VMOPERAND_Q; /* When a primitive type is a reference, it must have been passed as a reference
                                                         * parameter. Use Q to directly obtain the value of the reference. */
                        } else {
                            if (!collapse && base && cx_ic_isReference(base) && ((deref != CX_IC_DEREF_PUSH) || isRefType)) {
                                result = CX_IC_VMOPERAND_Q;
                            } else {
                                result = CX_IC_VMOPERAND_R;
                            }
                        }
                    } else {
                        /* When getting value of a non-static value (for example, member of a local) use Q */
                        result = CX_IC_VMOPERAND_Q;
                    }
                }
            }
            break;
        }
        break;
    }
    default:
        cx_assert(0, "invalid value-kind");
        break;
    }

    return result;
}

static cx_int16 cx_icLabel_toVm(cx_icLabel label, cx_ic_vmProgram *program) {
    cx_ic_vmLabel *lbl;

    if (program->program) {
        lbl = cx_ic_vmLabelGet(program, label->id);
        lbl->pc = program->program->size;
    } else {
        cx_error("cannot add label to non-existing program");
        goto error;
    }

    return 0;
error:
    return -1;
}

cx_void *cx_ic_valueValue(cx_ic_vmProgram *program, cx_icValue s) {
    return cx_ic_valueValue_width(program, s, NULL, 0);
}

/* Retrieve operand-addresses by using the operand-macros from the VM. Though the code is somewhat complex it negates the need
 * to duplicate all knowledge about which operands are used for every permutation of operand-kinds. */
#define CX_IC_OPADDR_GET_V(op,type,caseval,code)\
    case CX_IC_VMOPERAND_##caseval:\
        result = (void*) ((cx_word) op##_##type##code);\
        break;\

#define CX_IC_OPADDR_GET_RP(op,type,caseval,code)\
    case CX_IC_VMOPERAND_##caseval:\
        result = (void*) (& op##_##type##code);\
        break;\

#define CX_IC_OPADDR_GET_Q(op,type,caseval,code)\
    case CX_IC_VMOPERAND_##caseval:\
        reg = qreg;\
        result = (void*) (& op##_##type##code);\
        {\
            cx_uint32 v = (cx_uint32)(cx_word)result;\
            reg = NULL;\
            switch((cx_word)v) {\
            case 0x1000000:\
                result = (void*)1;\
                break;\
            case 0x10000:\
                result = (void*)2;\
                break;\
            default:\
                cx_assert(0, "Q-operand kind (%u - %x) invalid for " #op "_" #type #code " (expected %x or %x)\n",\
                    (cx_word)result, (cx_word)result, 0x1000000, 0x10000);\
                break;\
            }\
        }\
        break;\

/* Expand for one operand */
#define CX_IC_OPADDR_GET1(op_,type,n,prefix,rp,v,q)\
    switch(op##n##Kind) {\
    CX_IC_OPADDR_GET_##rp(op_,type,P,prefix##P)\
    CX_IC_OPADDR_GET_##q(op_,type,Q,prefix##Q)\
    CX_IC_OPADDR_GET_##rp(op_,type,R,prefix##R)\
    CX_IC_OPADDR_GET_##v(op_,type,V,prefix##V)\
    default:\
        cx_assert(0,"operand-kind other than PQRV not valid");\
        break;\
    }\

/* Expand for one operand (labels included) */
#define CX_IC_OPADDR_GET1_LABEL(op_,type,n,prefix,rp,v,q)\
    switch(op##n##Kind) {\
    CX_IC_OPADDR_GET_##rp(op_,type,P,prefix##P)\
    CX_IC_OPADDR_GET_##q(op_,type,Q,prefix##Q)\
    CX_IC_OPADDR_GET_##rp(op_,type,R,prefix##R)\
    CX_IC_OPADDR_GET_##v(op_,type,V,prefix##V)\
    CX_IC_OPADDR_GET_##v(op_,type,L,prefix##L)\
    default:\
        cx_assert(0,"invalid operand-kind");\
        break;\
    }\

/* Expand for one operand (V only) */
#define CX_IC_OPADDR_GET1_VONLY(op_,type,n,prefix,rp,v,q)\
    switch(op##n##Kind) {\
    CX_IC_OPADDR_GET_##v(op_,type,V,prefix##V)\
    default:\
        cx_error("operand other than V not valid for operand " #n " of type " #type " (%d)", op##n##Kind);\
        break;\
    }\
/*
 * op: op, op1, op2, op3
 * type: B,S,L,D
 * nX: actual operand being evaluated (used for opXKind)
 * prefix: for 2 & 3 ops, prefix the GET1-macro with previous operand codes
 * rp,v,q: select correct macro
 * op1func: select which operands are applicable (only V, labels included)
 */
#define CX_IC_OPADDR_GET1_(op,type,n2,prefix,rp,v,q,op1func) CX_IC_OPADDR_GET1##op1func(op,type,n2,prefix,rp,v,q)
#define CX_IC_OPADDR_GET1__LAST(op,type,n2,prefix,rp,v,q,op1func) CX_IC_OPADDR_GET1##op1func(op,type,n2,prefix,RP,V,Q)
#define CX_IC_OPADDR_GET1__RP(op,type,n2,prefix,rp,v,q,op1func) CX_IC_OPADDR_GET1##op1func(op,type,n2,prefix,RP,RP,RP)
#define CX_IC_OPADDR_GET1__Q(op,type,n2,prefix,rp,v,q,op1func) CX_IC_OPADDR_GET1##op1func(op,type,n2,prefix,Q,Q,Q)
#define CX_IC_OPADDR_GET1__V(op,type,n2,prefix,rp,v,q,op1func) CX_IC_OPADDR_GET1##op1func(op,type,n2,prefix,V,V,V)

/* Expand for 2 operands */
#define CX_IC_OPADDR_GET2(op_,type,n1,n2,prefix,func,op1func)\
    switch(op##n1##Kind) {\
    case CX_IC_VMOPERAND_P:\
        CX_IC_OPADDR_GET1_##func(op_,type,n2,prefix##P,RP,RP,RP,op1func)\
        break;\
    case CX_IC_VMOPERAND_Q:\
        CX_IC_OPADDR_GET1_##func(op_,type,n2,prefix##Q,Q,Q,Q,op1func)\
        break;\
    case CX_IC_VMOPERAND_R:\
        CX_IC_OPADDR_GET1_##func(op_,type,n2,prefix##R,RP,RP,RP,op1func)\
        break;\
    case CX_IC_VMOPERAND_V:\
        CX_IC_OPADDR_GET1_##func(op_,type,n2,prefix##V,V,V,V,op1func)\
        break;\
    default:\
        cx_assert(0,"invalid operand-kind");\
        break;\
    }

#define CX_IC_OPADDR_GET2_LAST(op,type,n1,n2,prefix,func,op1func) CX_IC_OPADDR_GET2(op,type,n1,n2,prefix,_LAST,op1func)
#define CX_IC_OPADDR_GET2_RP(op,type,n1,n2,prefix,func,op1func) CX_IC_OPADDR_GET2(op,type,n1,n2,prefix,_RP,op1func)
#define CX_IC_OPADDR_GET2_Q(op,type,n1,n2,prefix,func,op1func) CX_IC_OPADDR_GET2(op,type,n1,n2,prefix,_Q,op1func)
#define CX_IC_OPADDR_GET2_V(op,type,n1,n2,prefix,func,op1func) CX_IC_OPADDR_GET2(op,type,n1,n2,prefix,_V,op1func)

/* Expand for three operands */
#define CX_IC_OPADDR_GET3(op,type,func,rp,v,q)\
    switch(op1Kind) {\
    case CX_IC_VMOPERAND_P:\
        CX_IC_OPADDR_GET2##func(op,type,2,3,P,rp,_VONLY)\
        break;\
    case CX_IC_VMOPERAND_Q:\
        CX_IC_OPADDR_GET2##func(op,type,2,3,Q,q,_VONLY)\
        break;\
    case CX_IC_VMOPERAND_R:\
        CX_IC_OPADDR_GET2##func(op,type,2,3,R,rp,_VONLY)\
        break;\
    /*case CX_IC_VMOPERAND_V:\
        CX_IC_OPADDR_GET2##func(op,type,2,3,V,v)\
        break;\*/\
    default:\
        cx_assert(0,"operand-kind other than PQR not valid for first operand of 3-operand instruction");\
        break;\
    }\

#define CX_IC_OP1ADDR(type) case CX_IC_VMTYPE_##type: CX_IC_OPADDR_GET1(op,type,1,,RP,V,Q) break;
#define CX_IC_OP2ADDR1(type) case CX_IC_VMTYPE_##type: CX_IC_OPADDR_GET2(op1,type,1,2,,,_LABEL) break;
#define CX_IC_OP2ADDR2(type) case CX_IC_VMTYPE_##type: CX_IC_OPADDR_GET2(op2,type,1,2,,_LAST,_LABEL) break;

#define CX_IC_OP3ADDR1(type) case CX_IC_VMTYPE_##type: CX_IC_OPADDR_GET3(op1,type,,_RP,_V,_Q) break;
#define CX_IC_OP3ADDR2(type) case CX_IC_VMTYPE_##type: CX_IC_OPADDR_GET3(op2,type,,,,) break;
#define CX_IC_OP3ADDR3(type) case CX_IC_VMTYPE_##type: CX_IC_OPADDR_GET3(op3,type,_LAST,,,) break;

#define CX_IC_SWITCH_TYPE_ALL(macro)\
        macro(B)\
        macro(S)\
        macro(L)\
        macro(W)\
        macro(D)\

#define CX_IC_SWITCH_TYPE_W(macro)\
        macro(W)

#define CX_IC_ASSIGN_OPERAND(typeSwitch,macro,vId)\
        switch(typeKind) {\
        typeSwitch(macro)\
        default:\
            cx_error("type %d not valid for macro " #macro"\n",typeKind);\
            break;\
        }\
\
        switch((cx_word)result) {\
        case 1: vmOpAddr = &op->ic.b._1; break;\
        case 2: vmOpAddr = &op->ic.b._2; break;\
        case 4: vmOpAddr = &op->ic.s; break;\
        case 7: vmOpAddr = &op->lo.s.b._1; break;\
        case 8: vmOpAddr = &op->lo.s.b._2; break;\
        case 11: vmOpAddr = &op->hi.s.b._1; break;\
        case 12: vmOpAddr = &op->hi.s.b._2; break;\
        case 13: vmOpAddr = &op->lo; break;\
        case 3: vmOpAddr = &op->ic; break;\
        case 5: vmOpAddr = &op->lo.w; break;\
        case 9: vmOpAddr = &op->hi.w; break;\
        default:\
            cx_assert(0, "operand-macro " #macro " returned invalid value (%u) for operand " #vId " and type %d", (cx_word)result, typeKind);\
            break;\
        }\
\
        memset(vmOpAddr, 0, size);\
        switch(op##vId##Kind) {\
        case CX_IC_VMOPERAND_V:{\
            cx_float32 truncated;\
            memcpy(vmOpAddr, cx_ic_valueValue_width(program, v##vId, &truncated, size), size);\
            break;\
        }\
        case CX_IC_VMOPERAND_P:\
            /* If storage is an object, copy address, otherwise calculate pointer + offset */\
            if (((cx_icStorage)v##vId)->kind == CX_STORAGE_OBJECT) {\
                *(cx_object*)vmOpAddr = *(cx_object*)cx_ic_valueValue(program, v##vId);\
            } else {\
                cx_object ptr;\
                cx_ic_vmStorage *acc;\
                /*cx_assert(((cx_icStorage)v##vId)->kind == CX_STORAGE_MEMBER, "P operand without storage being either an object or a member");*/\
                acc = cx_ic_vmStorageGet(program, (cx_icStorage)v##vId);\
                ptr = ((cx_icObject)acc->base->accumulator)->ptr;\
                *(cx_object*)vmOpAddr = CX_OFFSET(ptr, acc->offset);\
            }\
            break;\
        case CX_IC_VMOPERAND_Q:\
        case CX_IC_VMOPERAND_R:\
        case CX_IC_VMOPERAND_X:\
            if (v##vId->_parent.kind == CX_IC_STORAGE) {\
                if (((cx_icStorage)v##vId)->kind == CX_STORAGE_LOCAL) {\
                    cx_ic_vmStorage *local;\
                    local = cx_ic_vmStorageGet(program, (cx_icStorage)v##vId);\
                    *(cx_uint16*)vmOpAddr = local->addr;\
                } else if (((cx_icStorage)v##vId)->kind == CX_STORAGE_ACCUMULATOR){\
                    cx_ic_vmStorage *accumulator;\
                    accumulator = cx_ic_vmStorageGet(program, (cx_icStorage)v##vId);\
                    cx_ic_vmStorageAddReferee(program, accumulator, vmOpAddr);\
                } else if ((((cx_icStorage)v##vId)->kind == CX_STORAGE_MEMBER) || (((cx_icStorage)v##vId)->kind == CX_STORAGE_ELEMENT)){\
                    cx_ic_vmStorage *accumulator;\
                    accumulator = cx_ic_vmStorageGet(program, (cx_icStorage)v##vId);\
                    switch(accumulator->base->accumulator->kind) {\
                    case CX_STORAGE_LOCAL:\
                        if (!accumulator->dynamic && !cx_ic_isReference(accumulator->base->accumulator)) {\
                            *(cx_uint16*)vmOpAddr = accumulator->base->addr + accumulator->offset;\
                            break;\
                        }\
                    /* If base is member or element it is a dynamic storage which requires allocation. */\
                    case CX_STORAGE_MEMBER:\
                    case CX_STORAGE_ELEMENT:\
                    case CX_STORAGE_ACCUMULATOR:\
                    default:\
                        cx_ic_vmStorageAddReferee(program, accumulator, vmOpAddr);\
                        break;\
                    }\
                }\
            }\
            break;\
        case CX_IC_VMOPERAND_L: {\
            cx_ic_vmLabel *label;\
            label = cx_ic_vmLabelGet(program, *(cx_uint32*)cx_ic_valueValue(program, v##vId));\
            cx_ic_vmLabelAddReferee(program, label, vmOpAddr);\
            break;\
        }\
        default:\
            cx_assert(0, "invalid operand kind %d", op##vId##Kind);\
            break;\
        }\

/* Define structs instead of unions for the simulated VM-environment. This will make identifying
 * the appropriate operands easier */
typedef struct _vmParameter16 {
    struct {
        uint16_t _1;
        uint16_t _2;
    } b;
    uint16_t s;
    uintptr_t w;
}_vmParameter16;

typedef struct _vmParameter {
    _vmParameter16 s;
    uintptr_t w;
}_vmParameter;

cx_uint32 cx_ic_vmTypeKindSize(cx_ic_vmType typeKind, cx_ic_vmOperand operand) {
    cx_uint32 result = 0;
    switch(typeKind) {
    case CX_IC_VMTYPE_B: result = 1; break;
    case CX_IC_VMTYPE_S: result = 2; break;
    case CX_IC_VMTYPE_L: result = 4; break;
    case CX_IC_VMTYPE_W: result = sizeof(cx_word); break;
    case CX_IC_VMTYPE_D: result = 8; break;
    }

    switch(operand) {
    case CX_IC_VMOPERAND_P: result = sizeof(cx_word); break;
    case CX_IC_VMOPERAND_R: result = sizeof(cx_uint16); break;
    case CX_IC_VMOPERAND_Q: result = sizeof(cx_uint16); break;
    default:
        break; 
    }

    return result;
}

static void cx_ic_vmSetOp1Addr(cx_ic_vmProgram *program, cx_vmOp *op, cx_ic_vmType typeKind, cx_ic_vmOperand op1Kind, cx_icValue v1) {
    cx_uint32 qreg[] = {0,1};
    struct {
        _vmParameter16 ic;
        _vmParameter lo;
        cx_uint64 dbl;
    } c;
    cx_uint32 *reg = NULL;
    void *result = NULL;
    void *vmOpAddr = NULL;
    cx_uint32 size = cx_ic_vmTypeKindSize(typeKind, op1Kind);

    CX_UNUSED(op);
    CX_UNUSED(typeKind);
    CX_UNUSED(op1Kind);
    CX_UNUSED(v1);

    /* Setup dummy environment for operand macros, give the operands unique masks so they can be identified
     * after executing the corresponding macro. */
    c.ic.w = 3;
    c.ic.s = 4;
    c.ic.b._1 = 1;
    c.ic.b._2 = 2;
    c.lo.w = 5;
    c.lo.s.s = 6;
    c.lo.s.b._1 = 7;
    c.lo.s.b._2 = 8;
    c.dbl = 13;

    op1Kind = op1Kind == CX_IC_VMOPERAND_X ? CX_IC_VMOPERAND_R : op1Kind;

    CX_IC_ASSIGN_OPERAND(CX_IC_SWITCH_TYPE_ALL,CX_IC_OP1ADDR,1)
}

static void cx_ic_vmSetOp2Addr(cx_ic_vmProgram *program, cx_vmOp *op, cx_ic_vmType typeKind, cx_ic_vmOperand op1Kind, cx_ic_vmOperand op2Kind, cx_icValue v1, cx_icValue v2) {
    cx_uint32 qreg[] = {0,1};
    struct {
        _vmParameter16 ic;
        _vmParameter lo, hi;
        cx_uint64 dbl;
    } c;
    cx_uint32 *reg = NULL;
    void *result = NULL;
    void *vmOpAddr = NULL;
    cx_uint32 size = cx_ic_vmTypeKindSize(typeKind, op1Kind);

    /* Setup dummy environment for operand macros, give the operands unique masks so they can be identified
     * after executing the corresponding macro. */
    c.ic.w = 3;
    c.ic.s = 4;
    c.ic.b._1 = 1;
    c.ic.b._2 = 2;
    c.lo.w = 5;
    c.lo.s.s = 6;
    c.lo.s.b._1 = 7;
    c.lo.s.b._2 = 8;
    c.hi.w = 9;
    c.hi.s.s = 10;
    c.hi.s.b._1 = 11;
    c.hi.s.b._2 = 12;
    c.dbl = 13;

    CX_IC_ASSIGN_OPERAND(CX_IC_SWITCH_TYPE_ALL,CX_IC_OP2ADDR1,1)

    size = cx_ic_vmTypeKindSize(typeKind, op2Kind);
    CX_IC_ASSIGN_OPERAND(CX_IC_SWITCH_TYPE_ALL,CX_IC_OP2ADDR2,2)
}

static void cx_ic_vmSetOp3Addr(cx_ic_vmProgram *program, cx_vmOp *op, cx_ic_vmType typeKind, cx_ic_vmOperand op1Kind, cx_ic_vmOperand op2Kind, cx_ic_vmOperand op3Kind, cx_icValue v1, cx_icValue v2, cx_icValue v3) {
    cx_word qreg[] = {0,1};
    struct {
        _vmParameter16 ic;
        _vmParameter lo;
        _vmParameter hi;
    } c;
    cx_word *reg = NULL;
    void *result = NULL;
    void *vmOpAddr = NULL;
    cx_uint32 size = cx_ic_vmTypeKindSize(typeKind, op1Kind);

    /* Setup dummy environment for operand macros, give the operands unique masks so they can be identified
     * after executing the corresponding macro. */
    c.ic.w = 3;
    c.ic.s = 4;
    c.ic.b._1 = 1;
    c.ic.b._2 = 2;
    c.lo.w = 5;
    c.lo.s.s = 6;
    c.lo.s.b._1 = 7;
    c.lo.s.b._2 = 8;
    c.hi.w = 9;
    c.hi.s.s = 10;
    c.hi.s.b._1 = 11;
    c.hi.s.b._2 = 12;

    CX_IC_ASSIGN_OPERAND(CX_IC_SWITCH_TYPE_W,CX_IC_OP3ADDR1,1)

    size = cx_ic_vmTypeKindSize(typeKind, op2Kind);
    CX_IC_ASSIGN_OPERAND(CX_IC_SWITCH_TYPE_W,CX_IC_OP3ADDR2,2)

    size = cx_ic_vmTypeKindSize(typeKind, op3Kind);
    CX_IC_ASSIGN_OPERAND(CX_IC_SWITCH_TYPE_W,CX_IC_OP3ADDR3,3)
}

static cx_ic_vmInlineFunction *cx_ic_vmInlineFunctionNew(cx_vmProgram program, cx_function function) {
    cx_ic_vmInlineFunction *result;

    result = cx_malloc(sizeof(cx_ic_vmInlineFunction));
    result->program = program;
    result->function = function;

    return result;
}

static void cx_ic_vmInlineFunctionMark(cx_ic_vmProgram *program, cx_vmProgram vmProgram, cx_function function) {
    cx_iter inlineFunctionIter;
    cx_ic_vmInlineFunction *inlineFunction = NULL;

    if (program->labels) {
        inlineFunctionIter = cx_llIter(program->labels);
        while(cx_iterHasNext(&inlineFunctionIter)) {
            inlineFunction = cx_iterNext(&inlineFunctionIter);
            if (inlineFunction->program == vmProgram) {
                if (inlineFunction->function == function) {
                    break;
                }
            } else {
                inlineFunction = NULL;
            }
        }
    }

    if (!inlineFunction) {
        inlineFunction = cx_ic_vmInlineFunctionNew(vmProgram, function);
        if (!program->inlineFunctions) {
            program->inlineFunctions = cx_llNew();
        }
        cx_llAppend(program->inlineFunctions, inlineFunction);
    }
}

#define CX_IC_OPERAND(op, code, operand)\
    case CX_IC_VMOPERAND_##operand:\
        result = CX_VM_##op##_##code;\
        break;\

#define CX_IC_OP2_PQRV(op, type, lvalue)\
    case CX_IC_VMOPERAND_##lvalue:\
        switch(op2) {\
            CX_IC_OPERAND(op,type##lvalue##V,V)\
            CX_IC_OPERAND(op,type##lvalue##R,R)\
            CX_IC_OPERAND(op,type##lvalue##P,P)\
            CX_IC_OPERAND(op,type##lvalue##Q,Q)\
            default:\
                cx_assert(0, "operand %s not valid for lvalue of " #op " operation of type " #type, cx_ic_vmOperandStr(op2));\
                break;\
        }\
        break;\

#define CX_IC_OP2_PQR(op, type, lvalue)\
    case CX_IC_VMOPERAND_##lvalue:\
        switch(op2) {\
            CX_IC_OPERAND(op,type##lvalue##R,R)\
            CX_IC_OPERAND(op,type##lvalue##P,P)\
            CX_IC_OPERAND(op,type##lvalue##Q,Q)\
            default:\
                cx_assert(0, "operand %s not valid for lvalue of " #op " operation of type " #type, cx_ic_vmOperandStr(op2));\
                break;\
        }\
        break;\

#define CX_IC_OP1_LVALUE_ANY(op, type, lvalue)\
        case CX_IC_VMOPERAND_##lvalue:\
            if (cx_primitive(t)->kind == CX_UINTEGER) {\
                result = CX_VM_##op##_##type##lvalue##U;\
            } else if (cx_primitive(t)->kind == CX_INTEGER) {\
                result = CX_VM_##op##_##type##lvalue##I;\
            } else if (cx_primitive(t)->kind == CX_FLOAT) {\
                result = CX_VM_##op##_##type##lvalue##F;\
            }\
            break;\

#define CX_IC_OP2_(op,type,postfix)\
case CX_IC_VMTYPE_##type:\
    switch(op1) {\
        CX_IC_OP2_##postfix(op,type,R)\
        CX_IC_OP2_##postfix(op,type,P)\
        CX_IC_OP2_##postfix(op,type,Q)\
        default:\
            cx_assert(0, "operand %s not valid for lvalue of " #op " operation of type " #type, cx_ic_vmOperandStr(op1));\
            break;\
    }\
    break;\

#define CX_IC_OP2V_(op,type,postfix)\
case CX_IC_VMTYPE_##type:\
    switch(op1) {\
        CX_IC_OP2_##postfix(op,type,R)\
        CX_IC_OP2_##postfix(op,type,P)\
        CX_IC_OP2_##postfix(op,type,Q)\
        CX_IC_OP2_##postfix(op,type,V)\
        default:\
            cx_assert(0, "operand %s not valid for lvalue of " #op " operation of type " #type, cx_ic_vmOperandStr(op1));\
            break;\
    }\
    break;\

#define CX_IC_OP2_R(op, type,postfix)\
case CX_IC_VMTYPE_##type:\
    switch(op1) {\
        CX_IC_OP2_##postfix(op,type, R)\
        default:\
            cx_assert(0, "operand %s not valid for lvalue of " #op " operation of type " #type, cx_ic_vmOperandStr(op1));\
            break;\
    }\
    break;\

#define CX_IC_OP1_ANY(op, type)\
case CX_IC_VMTYPE_##type:\
    switch(op1) {\
        CX_IC_OP1_LVALUE_ANY(op,type,V)\
        CX_IC_OPERAND(op,type##R,R)\
        CX_IC_OPERAND(op,type##P,P)\
        CX_IC_OPERAND(op,type##Q,Q)\
        default:\
            cx_assert(0, "operand %s not valid for lvalue of " #op " operation of type " #type, cx_ic_vmOperandStr(op1));\
            break;\
    }\
    break;\

#define CX_IC_OP1_PQRV(op, type)\
case CX_IC_VMTYPE_##type:\
    switch(op1) {\
        CX_IC_OPERAND(op,type##V,V)\
        CX_IC_OPERAND(op,type##R,R)\
        CX_IC_OPERAND(op,type##P,P)\
        CX_IC_OPERAND(op,type##Q,Q)\
        default:\
            cx_assert(0, "operand %s not valid for lvalue of " #op " operation of type " #type, cx_ic_vmOperandStr(op1));\
            break;\
    }\
    break;\

#define CX_IC_OP1_PQR(op, type)\
case CX_IC_VMTYPE_##type:\
    switch(op1) {\
        CX_IC_OPERAND(op,type##R,R)\
        CX_IC_OPERAND(op,type##P,P)\
        CX_IC_OPERAND(op,type##Q,Q)\
        default:\
            cx_assert(0, "operand %s not valid for lvalue of " #op " operation of type " #type, cx_ic_vmOperandStr(op1));\
            break;\
    }\
    break;\

#define CX_IC_GETOP1(op,postfix)\
static cx_vmOpKind cx_ic_getVm##op(cx_ic_vmType type, cx_ic_vmOperand op1) {\
    cx_vmOpKind result = CX_VM_STOP;\
    \
    switch(type) {\
        CX_IC_OP1_##postfix(op,B)\
        CX_IC_OP1_##postfix(op,S)\
        CX_IC_OP1_##postfix(op,L)\
        CX_IC_OP1_##postfix(op,D)\
    default:\
        cx_assert(0, "Type (%d) not applicable for " #op, type);\
        break;\
    }\
    \
    return result;\
}\

#define CX_IC_GETOP1_L(op,postfix)\
static cx_vmOpKind cx_ic_getVm##op(cx_ic_vmType type, cx_ic_vmOperand op1) {\
    cx_vmOpKind result = CX_VM_STOP;\
    \
    switch(type) {\
        CX_IC_OP1_##postfix(op,L)\
        default:\
            cx_assert(0, "Type other than L not valid for " #op);\
            break;\
    }\
    \
    return result;\
}\

#define CX_IC_GETOP1_W(op,postfix)\
static cx_vmOpKind cx_ic_getVm##op(cx_ic_vmType type, cx_ic_vmOperand op1) {\
    cx_vmOpKind result = CX_VM_STOP;\
    \
    switch(type) {\
        CX_IC_OP1_##postfix(op,W)\
        default:\
            cx_assert(0, "Type other than W not valid for " #op);\
            break;\
    }\
    \
    return result;\
}\

#define CX_IC_GETOP1_B(op,postfix)\
static cx_vmOpKind cx_ic_getVm##op(cx_ic_vmType type, cx_ic_vmOperand op1) {\
    cx_vmOpKind result = CX_VM_STOP;\
    \
    switch(type) {\
        CX_IC_OP1_##postfix(op,B)\
        default:\
            cx_assert(0, "Type other than B not valid for " #op);\
            break;\
    }\
    \
    return result;\
}\

#define CX_IC_GETOP1_COND(op, postfix)\
    CX_IC_GETOP1_B(op##B,postfix)\
    CX_IC_GETOP1_B(op##S,postfix)\
    CX_IC_GETOP1_B(op##L,postfix)\
    CX_IC_GETOP1_B(op##D,postfix)\
\
static cx_vmOpKind cx_ic_getVm##op(cx_type t, cx_ic_vmType op1Type, cx_ic_vmOperand op1) {\
    cx_vmOpKind result = CX_VM_STOP;\
    CX_UNUSED(t);\
    switch(op1Type) {\
    case CX_IC_VMTYPE_B:\
        result = cx_ic_getVm##op##B(CX_IC_VMTYPE_B, op1);\
        break;\
    case CX_IC_VMTYPE_S:\
        result = cx_ic_getVm##op##S(CX_IC_VMTYPE_B, op1);\
        break;\
    case CX_IC_VMTYPE_L:\
        result = cx_ic_getVm##op##L(CX_IC_VMTYPE_B, op1);\
        break;\
    case CX_IC_VMTYPE_D:\
        result = cx_ic_getVm##op##D(CX_IC_VMTYPE_B, op1);\
        break;\
    default:\
        cx_assert(0, "Type (%d) not applicable for " #op, op1Type);\
        break;\
    }\
    return result;\
}\

#define CX_IC_GETOP1_COND_LD(op, postfix)\
    CX_IC_GETOP1_B(op##L,postfix)\
    CX_IC_GETOP1_B(op##D,postfix)\
\
static cx_vmOpKind cx_ic_getVm##op(cx_type t, cx_ic_vmType op1Type, cx_ic_vmOperand op1) {\
    cx_vmOpKind result = CX_VM_STOP;\
    CX_UNUSED(t);\
    switch(op1Type) {\
    case CX_IC_VMTYPE_L:\
        result = cx_ic_getVm##op##L(CX_IC_VMTYPE_B, op1);\
        break;\
    case CX_IC_VMTYPE_D:\
        result = cx_ic_getVm##op##D(CX_IC_VMTYPE_B, op1);\
        break;\
    default:\
        cx_assert(0,"byte or short operands not valid for " #op);\
        break;\
    }\
    return result;\
}\

#define CX_IC_GETOP1_COND_SIGN(op, postfix)\
    CX_IC_GETOP1_COND(op##I,postfix)\
    CX_IC_GETOP1_COND(op##U,postfix)\
    CX_IC_GETOP1_COND_LD(op##F,postfix)\
static cx_vmOpKind cx_ic_getVm##op(cx_type t, cx_ic_vmType op1Type, cx_ic_vmOperand op1) {\
    cx_vmOpKind result = CX_VM_STOP;\
    if (t->kind == CX_PRIMITIVE) {\
        switch(cx_primitive(t)->kind) {\
        case CX_ENUM:\
        case CX_INTEGER:\
            result = cx_ic_getVm##op##I(t, op1Type, op1);\
            break;\
        case CX_BINARY:\
        case CX_CHARACTER:\
        case CX_UINTEGER:\
            result = cx_ic_getVm##op##U(t, op1Type, op1);\
            break;\
        case CX_FLOAT:\
            result = cx_ic_getVm##op##F(t, op1Type, op1);\
            break;\
        default:\
            cx_assert(0, "conditional operation " #op " works only for INTEGER, UINTEGER and FLOAT primitives (got %s)", cx_nameof(t));\
            break;\
        }\
    } else {\
        cx_assert(0, "conditional operation " #op " works only for primitive types");\
    }\
    return result;\
}\

#define CX_IC_GETOP2(op,lpostfix,rpostfix)\
static cx_vmOpKind cx_ic_getVm##op(cx_ic_vmType type, cx_ic_vmOperand op1, cx_ic_vmOperand op2) {\
    cx_vmOpKind result = CX_VM_STOP;\
    \
    switch(type) {\
        CX_IC_OP2_##lpostfix(op,B,rpostfix)\
        CX_IC_OP2_##lpostfix(op,S,rpostfix)\
        CX_IC_OP2_##lpostfix(op,L,rpostfix)\
        CX_IC_OP2_##lpostfix(op,D,rpostfix)\
        default:\
            cx_assert(0, "Type (%d) not valid for " #op, type);\
            break;\
    }\
    \
    return result;\
}\

#define CX_IC_GETOP2_V(op,lpostfix,rpostfix)\
static cx_vmOpKind cx_ic_getVm##op(cx_ic_vmType type, cx_ic_vmOperand op1, cx_ic_vmOperand op2) {\
    cx_vmOpKind result = CX_VM_STOP;\
    \
    switch(type) {\
        CX_IC_OP2V_##lpostfix(op,B,rpostfix)\
        CX_IC_OP2V_##lpostfix(op,S,rpostfix)\
        CX_IC_OP2V_##lpostfix(op,L,rpostfix)\
        CX_IC_OP2V_##lpostfix(op,D,rpostfix)\
        default:\
            cx_assert(0, "Type (%d) not valid for " #op, type);\
            break;\
    }\
    \
    return result;\
}\

#define CX_IC_GETOP2_TYPE(op, lpostfix, rpostfix, type)\
    static cx_vmOpKind cx_ic_getVm##op(cx_ic_vmType type, cx_ic_vmOperand op1, cx_ic_vmOperand op2) {\
        cx_vmOpKind result = CX_VM_STOP;\
        \
        switch(type) {\
            CX_IC_OP2_##lpostfix(op,type,rpostfix)\
            default:\
                cx_assert(0, "Type other than " #type " (%d) not valid for " #op, type);\
                break;\
        }\
        \
        return result;\
    }\

#define CX_IC_GETOP2_L(op,lpostfix,rpostfix) CX_IC_GETOP2_TYPE(op, lpostfix, rpostfix, L)
#define CX_IC_GETOP2_W(op,lpostfix,rpostfix) CX_IC_GETOP2_TYPE(op, lpostfix, rpostfix, W)
#define CX_IC_GETOP2_D(op,lpostfix,rpostfix) CX_IC_GETOP2_TYPE(op, lpostfix, rpostfix, D)

#define CX_IC_GETOP2V_W(op,lpostfix,rpostfix)\
static cx_vmOpKind cx_ic_getVm##op(cx_ic_vmType type, cx_ic_vmOperand op1, cx_ic_vmOperand op2) {\
    cx_vmOpKind result = CX_VM_STOP;\
    \
    switch(type) {\
        CX_IC_OP2V_##lpostfix(op,W,rpostfix)\
        default:\
            cx_assert(0, "Type other than W (%d) not valid for " #op, type);\
            break;\
    }\
    \
    return result;\
}\

#define CX_IC_GETOP2_LD(op,lpostfix,rpostfix)\
static cx_vmOpKind cx_ic_getVm##op(cx_ic_vmType type, cx_ic_vmOperand op1, cx_ic_vmOperand op2) {\
    cx_vmOpKind result = CX_VM_STOP;\
    \
    switch(type) {\
        CX_IC_OP2_##lpostfix(op,L,rpostfix)\
        CX_IC_OP2_##lpostfix(op,D,rpostfix)\
        default:\
            cx_assert(0, "type not applicable for floating point operation " # op);\
            break;\
    }\
    \
    return result;\
}\

#define CX_IC_GETOP2_SLD(op,lpostfix,rpostfix)\
static cx_vmOpKind cx_ic_getVm##op(cx_ic_vmType type, cx_ic_vmOperand op1, cx_ic_vmOperand op2) {\
    cx_vmOpKind result = CX_VM_STOP;\
    \
    switch(type) {\
        CX_IC_OP2_##lpostfix(op,S,rpostfix)\
        CX_IC_OP2_##lpostfix(op,L,rpostfix)\
        CX_IC_OP2_##lpostfix(op,D,rpostfix)\
        default:\
            cx_assert(0, "B not applicable for instruction " # op);\
            break;\
    }\
    \
    return result;\
}\

#define CX_IC_GETOP2_BLD(op,lpostfix,rpostfix)\
static cx_vmOpKind cx_ic_getVm##op(cx_ic_vmType type, cx_ic_vmOperand op1, cx_ic_vmOperand op2) {\
    cx_vmOpKind result = CX_VM_STOP;\
    \
    switch(type) {\
        CX_IC_OP2_##lpostfix(op,B,rpostfix)\
        CX_IC_OP2_##lpostfix(op,L,rpostfix)\
        CX_IC_OP2_##lpostfix(op,D,rpostfix)\
        default:\
            cx_assert(0, "S not applicable for instruction " # op);\
            break;\
    }\
    \
    return result;\
}\

#define CX_IC_GETOP2_BSD(op,lpostfix,rpostfix)\
static cx_vmOpKind cx_ic_getVm##op(cx_ic_vmType type, cx_ic_vmOperand op1, cx_ic_vmOperand op2) {\
    cx_vmOpKind result = CX_VM_STOP;\
    \
    switch(type) {\
        CX_IC_OP2_##lpostfix(op,B,rpostfix)\
        CX_IC_OP2_##lpostfix(op,S,rpostfix)\
        CX_IC_OP2_##lpostfix(op,D,rpostfix)\
        default:\
            cx_assert(0, "L not applicable for instruction " # op);\
            break;\
    }\
    \
    return result;\
}\

#define CX_IC_GETOP2_BSL(op,lpostfix,rpostfix)\
static cx_vmOpKind cx_ic_getVm##op(cx_ic_vmType type, cx_ic_vmOperand op1, cx_ic_vmOperand op2) {\
    cx_vmOpKind result = CX_VM_STOP;\
    \
    switch(type) {\
        CX_IC_OP2_##lpostfix(op,B,rpostfix)\
        CX_IC_OP2_##lpostfix(op,S,rpostfix)\
        CX_IC_OP2_##lpostfix(op,L,rpostfix)\
        default:\
            cx_assert(0, "D not applicable for instruction " # op);\
            break;\
    }\
    \
    return result;\
}\

#define CX_IC_GETOP1_ANY(op)\
static cx_vmOpKind cx_ic_getVm##op(cx_type t, cx_ic_vmType type, cx_ic_vmOperand op1) {\
    cx_vmOpKind result = CX_VM_STOP;\
    \
    if (op1 == CX_IC_VMOPERAND_V) {\
        if (t->kind == CX_PRIMITIVE) {\
            if (cx_primitive(t)->width == CX_WIDTH_64) {\
                type = CX_IC_VMTYPE_D;\
            } else {\
                type = CX_IC_VMTYPE_L;\
            }\
        }\
    }\
    switch(type) {\
        CX_IC_OP1_PQRV(op,L)\
        CX_IC_OP1_ANY(op,D)\
        default:\
            cx_assert(0, "B or S not applicable for instruction " #op);\
            break;\
    }\
    \
    return result;\
}\

/* Arithmic operations need to distinct between integer and floating point types */
#define CX_IC_GETOP2_ARITH(op,lpostfix,rpostfix)\
CX_IC_GETOP2(op##I,lpostfix,rpostfix)\
CX_IC_GETOP2_LD(op##F,lpostfix,rpostfix)\
static cx_vmOpKind cx_ic_getVm##op(cx_type t, cx_ic_vmType typeKind, cx_ic_vmOperand op1, cx_ic_vmOperand op2) {\
    cx_vmOpKind result = CX_VM_STOP;\
    \
    if (t->kind == CX_PRIMITIVE) {\
        switch(cx_primitive(t)->kind) {\
        case CX_INTEGER:\
        case CX_UINTEGER:\
        case CX_ENUM:\
        case CX_BINARY:\
        case CX_CHARACTER:\
            result = cx_ic_getVm##op##I(typeKind, op1, op2);\
            break;\
        case CX_FLOAT:\
            result = cx_ic_getVm##op##F(typeKind, op1, op2);\
            break;\
        default:\
            cx_assert(0, "invalid primitive-kind for operation " #op);\
            break;\
        }\
    } else {\
        cx_assert(0, "invalid type-kind for operation");\
    }\
    return result;\
}\

CX_IC_GETOP2(SET,,PQRV)
CX_IC_GETOP2_W(SETREF,,PQRV)
CX_IC_GETOP2_W(SETSTRDUP,,PQRV)

CX_IC_GETOP2_ARITH(ADD,,PQRV)
CX_IC_GETOP2_ARITH(SUB,,PQRV)
CX_IC_GETOP2_ARITH(MUL,,PQRV)
CX_IC_GETOP2_ARITH(DIV,,PQRV)
CX_IC_GETOP2(MODI,,PQRV)

CX_IC_GETOP1(INC,PQR)
CX_IC_GETOP1(DEC,PQR)

CX_IC_GETOP2(XOR,,PQRV)
CX_IC_GETOP2(OR,,PQRV)
CX_IC_GETOP2(AND,,PQRV)
CX_IC_GETOP1(NOT,PQR)
CX_IC_GETOP2(SHIFT_LEFT,,PQRV)
CX_IC_GETOP2(SHIFT_RIGHT,,PQRV)

CX_IC_GETOP1(STAGE1,PQRV)
CX_IC_GETOP2_V(STAGE2,,PQRV)

CX_IC_GETOP1_COND(COR,PQR)
CX_IC_GETOP1_COND(CAND,PQR)
CX_IC_GETOP1_COND(CNOT,PQR)
CX_IC_GETOP1_COND(CEQ,PQR)
CX_IC_GETOP1_COND(CNEQ,PQR)

CX_IC_GETOP1_B(CEQSTR,PQR)
CX_IC_GETOP1_B(CNEQSTR,PQR)

CX_IC_GETOP1_COND_SIGN(CGT,PQR)
CX_IC_GETOP1_COND_SIGN(CLT,PQR)
CX_IC_GETOP1_COND_SIGN(CGTEQ,PQR)
CX_IC_GETOP1_COND_SIGN(CLTEQ,PQR)

CX_IC_GETOP1(JEQ,PQR)
CX_IC_GETOP1(JNEQ,PQR)

CX_IC_GETOP2_W(ELEMA,R,PQRV)
CX_IC_GETOP2_W(ELEMS,R,PQRV)
CX_IC_GETOP2_W(ELEML,R,PQRV)
CX_IC_GETOP2_W(ELEMLX,R,PQRV)
CX_IC_GETOP2_W(ELEMM,R,PQRV)
CX_IC_GETOP2_W(ELEMMX,R,PQRV)

CX_IC_GETOP1(PUSH,PQRV)
CX_IC_GETOP1(PUSHX,PQR)
CX_IC_GETOP1_W(PUSHANY,PQRV)
CX_IC_GETOP1_ANY(PUSHANYX)
CX_IC_GETOP1_L(CALL,PQR)
CX_IC_GETOP1_L(CALLVM,PQR)
CX_IC_GETOP2_W(CALLPTR,,PQRV)
CX_IC_GETOP1(RET,PQR)
CX_IC_GETOP1_L(RETCPY,PQR)

CX_IC_GETOP2_W(CAST,,PQRV)
CX_IC_GETOP2(PCAST,,PQR)

CX_IC_GETOP2V_W(STRCAT,,PQRV)
CX_IC_GETOP2_W(STRCPY,,PQRV)

CX_IC_GETOP2_W(NEW,,PQRV)
CX_IC_GETOP1_W(DEALLOC,PQR)
CX_IC_GETOP1_W(KEEP,PQR)
CX_IC_GETOP1_W(FREE,PQR)

CX_IC_GETOP1_W(DEFINE,PQRV)

CX_IC_GETOP1_W(UPDATE,PQRV)
CX_IC_GETOP1_W(UPDATEBEGIN,PQRV)
CX_IC_GETOP1_W(UPDATEEND,PQRV)
CX_IC_GETOP2_W(UPDATEFROM,,PQR)
CX_IC_GETOP2_W(UPDATEENDFROM,,PQR)
CX_IC_GETOP1_W(UPDATECANCEL,PQRV)

CX_IC_GETOP1_W(WAITFOR,PQRV)
CX_IC_GETOP2_W(WAIT,,PQRV)

static cx_vmOp *cx_ic_vmStorageAssembleElement(cx_icStorage storage, cx_ic_vmProgram *program, cx_vmOp *vmOp, cx_icStorage topLevelStorage) {
    cx_ic_vmOperand indexKind;
    cx_icValue icElementSize;
    cx_collection type = cx_collection(((cx_icElement)storage)->base->type); /* Obtain collectiontype */
    cx_value elementSizeValue;
    cx_uint64 elementSize;

    /* Obtain kind for index */
    indexKind = cx_ic_getVmOperand(program, CX_IC_DEREF_VALUE, ((cx_icElement)storage)->index);

    /* Create value for elementSize */
    elementSize = cx_type_sizeof(type->elementType);
    cx_valueLiteralInit(&elementSizeValue, CX_LITERAL_UNSIGNED_INTEGER, &elementSize);
    icElementSize = (cx_icValue)cx_icLiteral__create(program->icProgram, ((cx_ic)storage)->line, elementSizeValue, (cx_type)cx_uint32_o);

    switch(type->kind) {
    case CX_ARRAY:
        vmOp->op = cx_ic_getVmELEMA(CX_IC_VMTYPE_W, CX_IC_VMOPERAND_R, indexKind);
        cx_ic_vmSetOp3Addr(program, vmOp, CX_IC_VMTYPE_W, CX_IC_VMOPERAND_R, indexKind, CX_IC_VMOPERAND_V, (cx_icValue)topLevelStorage, ((cx_icElement)storage)->index, icElementSize);
        break;
    case CX_SEQUENCE:
        vmOp->op = cx_ic_getVmELEMS(CX_IC_VMTYPE_W, CX_IC_VMOPERAND_R, indexKind);
        cx_ic_vmSetOp3Addr(program, vmOp, CX_IC_VMTYPE_W, CX_IC_VMOPERAND_R, indexKind, CX_IC_VMOPERAND_V, (cx_icValue)topLevelStorage, ((cx_icElement)storage)->index, icElementSize);
        break;
    case CX_LIST:
        if (cx_collection_elementRequiresAlloc(type)) {
            vmOp->op = cx_ic_getVmELEML(CX_IC_VMTYPE_W, CX_IC_VMOPERAND_R, indexKind);
        } else {
            vmOp->op = cx_ic_getVmELEMLX(CX_IC_VMTYPE_W, CX_IC_VMOPERAND_R, indexKind);
        }
        cx_ic_vmSetOp2Addr(program, vmOp, CX_IC_VMTYPE_W, CX_IC_VMOPERAND_R, indexKind, (cx_icValue)topLevelStorage, ((cx_icElement)storage)->index);
        break;
    case CX_MAP:
        if (cx_collection_elementRequiresAlloc(type)) {
            vmOp->op = cx_ic_getVmELEMM(CX_IC_VMTYPE_W, CX_IC_VMOPERAND_R, indexKind);
        } else {
            vmOp->op = cx_ic_getVmELEMMX(CX_IC_VMTYPE_W, CX_IC_VMOPERAND_R, indexKind);
        }
        cx_ic_vmSetOp2Addr(program, vmOp, CX_IC_VMTYPE_W, CX_IC_VMOPERAND_R, indexKind, (cx_icValue)topLevelStorage, ((cx_icElement)storage)->index);
        break;
    }

    return cx_vmProgram_addOp(program->program, ((cx_ic)storage)->line);
}

static cx_vmOp *cx_ic_vmStorageAssembleNested(cx_icStorage icStorage, cx_ic_vmProgram *program, cx_vmOp *vmOp, cx_icStorage icTopLevelStorage) {
    cx_ic_vmStorage *storage = cx_ic_vmStorageGet(program, icStorage);
    
    if (!storage->assembled && (storage->accumulator->used || storage->dynamic)) {
        if (storage->accumulator->kind == CX_STORAGE_MEMBER) {
            if ((storage->base->accumulator->kind != CX_STORAGE_OBJECT) && (cx_ic_isReference(storage->base->accumulator) || storage->base->dynamic)) {
                cx_icStorage base = storage->base->accumulator;
                cx_uint32 offset = storage->offset;

                /* Assemble base */
                vmOp = cx_ic_vmStorageAssembleNested(base, program, vmOp, base);

                if (storage->offset) {
                    cx_ic_vmStorage *vmBase = cx_ic_vmStorageGet(program, base);
                    /* Set the base-address in the accumulator, conserve the register value where the original
                     * address is stored. This conserved value can be used as base for other member-storages. If
                     * the base is dynamic this value doesn't need to be conserved because the storage it points
                     * to is not static. */
                    if (!vmBase->dynamic) {
                        vmOp->op = CX_VM_MEMBER; /* Member instruction takes a destination, base and offset */
                        cx_ic_vmStorageAddReferee(program, storage, &vmOp->ic.b._1);
                        if (base->kind == CX_STORAGE_LOCAL) {
                            vmOp->ic.b._2 = storage->base->addr;
                        } else {
                            cx_ic_vmStorageAddReferee(program, storage->base, &vmOp->ic.b._2);
                        }
                        vmOp->lo.w = offset;
                        
                        /* If base is a local and a reference, storage has to be recomputed each time */
                        if (!((base->kind == CX_STORAGE_LOCAL) && (base->isReference))) {
                            storage->assembled = TRUE;
                        }
                    } else {
                        /* Calculate address at runtime by adding the offset to the base-address */
                        vmOp->op = CX_VM_ADDI_LRV;
                        if (storage->accumulator->kind == CX_STORAGE_LOCAL) {
                            vmOp->ic.b._1 = storage->addr;
                        } else {
                            cx_ic_vmStorageAddReferee(program, storage, &vmOp->ic.b._1);
                        }

                        vmOp->lo.w = offset;
                    }

                    /* Give new operation to assembler */
                    vmOp = cx_vmProgram_addOp(program->program, ((cx_ic)icStorage)->line);
                }
            }
        } else if (storage->accumulator->kind == CX_STORAGE_ELEMENT) {
            cx_icStorage base = storage->base->accumulator;
            cx_ic_vmStorage *topLevelStorage = cx_ic_vmStorageGet(program, icTopLevelStorage);

            /* Assemble base */
            vmOp = cx_ic_vmStorageAssembleNested(base, program, vmOp, icTopLevelStorage);

            /* If element is not dynamic the address can be determined at compile-time. When the element
             * is dynamic the address will be calculated at runtime. */
            if (storage->dynamic || cx_ic_isReference(storage->base->accumulator)) {
                /* If the base is an object store the address in the accumulator */
                if (base->kind == CX_STORAGE_OBJECT) {
                    vmOp->op = sizeof(intptr_t) == 4 ? CX_VM_SET_LRV : CX_VM_SET_DRV;
                    cx_ic_vmStorageAddReferee(program, topLevelStorage, &vmOp->ic.b._1);
                    vmOp->lo.w = (intptr_t)((cx_icObject)base)->ptr;
                    if (storage->offset) {
                        vmOp->lo.w += storage->offset;
                    }
                    vmOp = cx_vmProgram_addOp(program->program, ((cx_ic)icStorage)->line);

                /* If the base is a local store the address of the local in the accumulator */
                } else if (base->kind == CX_STORAGE_LOCAL) {
                    if (!cx_ic_isReference(storage->base->accumulator)) {
                        vmOp->op = CX_VM_SET_WRX;
                        cx_ic_vmStorageAddReferee(program, topLevelStorage, &vmOp->ic.b._1);
                        vmOp->ic.b._2 = storage->base->addr;
                        if (storage->offset) {
                            vmOp->ic.b._2 += storage->offset;
                        }
                        vmOp = cx_vmProgram_addOp(program->program, ((cx_ic)icStorage)->line);
                    } else {
                        vmOp->op = sizeof(intptr_t) == 4 ? CX_VM_SET_LRR : CX_VM_SET_DRR;
                        cx_ic_vmStorageAddReferee(program, topLevelStorage, &vmOp->ic.b._1);
                        vmOp->ic.b._2 = storage->base->addr;
                        vmOp = cx_vmProgram_addOp(program->program, ((cx_ic)icStorage)->line);
                    }
                }

                /* Insert element-instruction */
                vmOp = cx_ic_vmStorageAssembleElement(icStorage, program, vmOp, icTopLevelStorage);
            }
        }
    }

    return vmOp;
}

static cx_vmOp *cx_ic_vmStorageAssemble(cx_icStorage icStorage, cx_ic_vmProgram *program, cx_vmOp *vmOp) {
    return cx_ic_vmStorageAssembleNested(icStorage, program, vmOp, icStorage);
}

/* Returns which operations have support for the W-operand type */
static cx_bool cx_ic_supportsVmWordType(cx_icOpKind kind) {
    cx_bool result = FALSE;
    switch(kind) {
    case CX_IC_SET:  /* SETREF supports W, but this is handled elsewhere in the code */
    case CX_IC_CAST:
    case CX_IC_ADD:
    case CX_IC_SUB:
    case CX_IC_MUL:
    case CX_IC_DIV:
    case CX_IC_MOD:
    case CX_IC_INC:
    case CX_IC_DEC:
    case CX_IC_XOR:
    case CX_IC_OR: 
    case CX_IC_AND:
    case CX_IC_NOT:
    case CX_IC_SHIFT_LEFT: 
    case CX_IC_SHIFT_RIGHT:
    case CX_IC_COND_OR:
    case CX_IC_COND_AND:
    case CX_IC_COND_NOT: 
    case CX_IC_COND_EQ:
    case CX_IC_COND_NEQ:
    case CX_IC_COND_GT:
    case CX_IC_COND_LT:
    case CX_IC_COND_GTEQ:
    case CX_IC_COND_LTEQ:
    case CX_IC_JUMP:
    case CX_IC_JEQ:
    case CX_IC_JNEQ:
    case CX_IC_STOP:
    case CX_IC_PUSH:
    case CX_IC_CALL:
    case CX_IC_RET:
        result = FALSE;
        break;

    case CX_IC_STRCAT:
    case CX_IC_STRCPY:
    case CX_IC_NEW: 
    case CX_IC_FREE:
    case CX_IC_KEEP:
    case CX_IC_DEFINE:
    case CX_IC_UPDATE:
    case CX_IC_UPDATEEND:
    case CX_IC_UPDATEBEGIN: 
    case CX_IC_UPDATECANCEL:
    case CX_IC_WAITFOR:
    case CX_IC_WAIT:
        result = TRUE;
        break;
    default:
        cx_assert(0, "invalid intermediate op-code");
        break;
    }
    return result;
}

static cx_ic_vmType cx_vmTranslateVmType(cx_icOpKind kind, cx_ic_vmType type) {
    if (!cx_ic_supportsVmWordType(kind) && (type == CX_IC_VMTYPE_W)) {
        if (sizeof(intptr_t) == 4) {
            type = CX_IC_VMTYPE_L;
        } else if (sizeof(intptr_t) == 8) {
            type = CX_IC_VMTYPE_D;
        }else {
            cx_assert(0, "Architecture not supported");
        }
    }
    return type;
}

static cx_vmOpKind cx_ic_getVmCast(cx_ic_vmProgram *program, cx_icOp op, cx_type t, cx_ic_vmType typeKind, cx_ic_vmOperand storage, cx_ic_vmOperand op1) {
    cx_type srcType, dstType;
    cx_vmOpKind result = CX_VM_STOP;

    CX_UNUSED(op);
    CX_UNUSED(t);

    dstType = *(cx_type*)cx_ic_valueValue(program, op->s3);
    srcType = cx_ic_valueType(op->s2);

    if (srcType->kind == dstType->kind) {
        if (srcType->kind == CX_PRIMITIVE) {
            result = cx_ic_getVmPCAST(typeKind, storage, op1);
        } else {
            if (srcType->reference) {
                result = cx_ic_getVmCAST(CX_IC_VMTYPE_W, storage, CX_IC_VMOPERAND_V);
            } else {
                /* No cast for non-reference types */
            }
        }

    } else if ((dstType->kind == CX_PRIMITIVE) && (cx_primitive(dstType)->kind == CX_BOOLEAN)) {
        if (((cx_icStorage)op->s3)->isReference) {
            result = cx_ic_getVmPCAST(typeKind, storage, op1);
        }
    } else if ((srcType->kind == CX_VOID) && srcType->reference) {
        result = cx_ic_getVmCAST(CX_IC_VMTYPE_W, storage, CX_IC_VMOPERAND_V);
    }

    cx_assert(result != CX_VM_STOP, "no cast-instruction found from type '%s' to '%s'", cx_nameof(srcType), cx_nameof(dstType));

    return result;
}

static cx_vmOpKind cx_ic_getVmFree(cx_icOp op, cx_type t, cx_ic_vmType typeKind, cx_ic_vmOperand op1) {
    cx_vmOpKind result = CX_VM_STOP;
    CX_UNUSED(t);
    CX_UNUSED(typeKind);

    if (((cx_icStorage)op->s1)->isReference) {
        result = cx_ic_getVmFREE(CX_IC_VMTYPE_W, op1);
    } else {
        result = cx_ic_getVmDEALLOC(CX_IC_VMTYPE_W, op1);
    }

    return result;
}

/* Return correct SET instruction. Selects between 
 * normal, string and reference assignments. */
static cx_vmOpKind cx_ic_getVmSet(
    cx_type type, 
    cx_icStorage op1, 
    cx_ic_vmType typeKind, 
    cx_ic_vmOperand opKind1, 
    cx_ic_vmOperand opKind2, 
    cx_icDerefMode deref1, 
    cx_icDerefMode deref2) {
    cx_vmOpKind result;
    
    CX_UNUSED(deref2);

    /* Accummulators are only meant as temporary storage and therefore don't do resource management */
    if (op1->kind == CX_STORAGE_ACCUMULATOR) {
        /* Translate type - it can be W */
        typeKind = cx_vmTranslateVmType(CX_IC_SET, typeKind);
        result = cx_ic_getVmSET(typeKind, opKind1, opKind2);
    } else {
        /*printf("op1->isReference=%d, deref1==address=%d, deref2==address=%d, typeKind=%d, opKind1=%d, opKind2=%d\n",
               op1->isReference, deref1==CX_IC_DEREF_ADDRESS, deref2==CX_IC_DEREF_ADDRESS, typeKind, opKind1, opKind2);*/
        if ((deref1 == CX_IC_DEREF_ADDRESS) || (deref2 == CX_IC_DEREF_ADDRESS)) {
            result = cx_ic_getVmSETREF(CX_IC_VMTYPE_W, opKind1, opKind2);
        } else {
            if ((type->kind == CX_PRIMITIVE) && (cx_primitive(type)->kind == CX_TEXT)) {
                result = cx_ic_getVmSETSTRDUP(CX_IC_VMTYPE_W, opKind1, opKind2);
            } else {
                result = cx_ic_getVmSET(typeKind, opKind1, opKind2);
            }
        }
    }

    return result;
}

static cx_bool cx_ic_operandIsComposite(cx_icStorage s, cx_compositeKind kind) {
    cx_bool result = FALSE;
    if (s->type->kind == CX_COMPOSITE) {
        if (cx_interface(s->type)->kind == kind) {
            result = TRUE;
        }
    }
    return result;
}

/* Return correct CALL instruction. Selects between 
 * normal, VM and delegate calls */
static cx_vmOpKind cx_ic_getVmCall(cx_icOp op, cx_ic_vmOperand op1, cx_ic_vmOperand op2) {
    cx_vmOpKind result = CX_VM_STOP;
    cx_icStorage icFunction = ((cx_icStorage)op->s2);

    if (cx_ic_operandIsComposite(icFunction, CX_DELEGATE)) {
        result = cx_ic_getVmCALLPTR(CX_IC_VMTYPE_W, op1, op2);
    } else if (cx_ic_operandIsComposite(icFunction, CX_PROCEDURE)) {
        cx_function f = ((cx_icObject)op->s2)->ptr;
        if (f->kind == CX_PROCEDURE_VM) {
            if ((f->returnType->kind == CX_VOID) && 
                (!f->returnType->reference)) {
                result = CX_VM_CALLVMVOID;
            } else {
                result = cx_ic_getVmCALLVM(CX_IC_VMTYPE_L, op1);
            }
        } else {
            if ((f->returnType->kind == CX_VOID) && 
                (!f->returnType->reference)) {
                result = CX_VM_CALLVOID;
            } else {
                result = cx_ic_getVmCALL(CX_IC_VMTYPE_L, op1);
            }
        }
    }

    return result;   
}

static cx_vmOpKind cx_ic_getVmOpKind(cx_ic_vmProgram *program, cx_icOp op, cx_icValue storage, cx_type t, cx_ic_vmType typeKind, cx_ic_vmOperand op1, cx_ic_vmOperand op2, cx_icDerefMode deref1, cx_icDerefMode deref2) {
    cx_vmOpKind result = CX_VM_STOP;

    /* When there is no dedicated W-operation, switch to L or D based on architecture */
    typeKind = cx_vmTranslateVmType(op->kind, typeKind);

    switch(op->kind) {
    /* Set (assign) */
    case CX_IC_SET:
        result = cx_ic_getVmSet(t, (cx_icStorage)storage, typeKind, op1, op2, deref1, deref2);
        break;

    /* Casting */
    case CX_IC_CAST:
        result = cx_ic_getVmCast(program, op, t, typeKind,
                cx_ic_getVmOperand(program, op->s1Deref, op->s1),
                cx_ic_getVmOperand(program, op->s2Deref, op->s2));
        break;

    /* String concatenation */
    case CX_IC_STRCAT: result = cx_ic_getVmSTRCAT(typeKind, op1, op2); break;
    case CX_IC_STRCPY: result = cx_ic_getVmSTRCPY(typeKind, op1, op2); break;

    /* Operators */
    case CX_IC_ADD: result = cx_ic_getVmADD(t, typeKind, op1, op2); break;
    case CX_IC_SUB: result = cx_ic_getVmSUB(t, typeKind, op1, op2); break;
    case CX_IC_MUL: result = cx_ic_getVmMUL(t, typeKind, op1, op2); break;
    case CX_IC_DIV: result = cx_ic_getVmDIV(t, typeKind, op1, op2); break;
    case CX_IC_MOD: result = cx_ic_getVmMODI(typeKind, op1, op2); break;
    case CX_IC_INC: result = cx_ic_getVmINC(typeKind, op1); break;
    case CX_IC_DEC: result = cx_ic_getVmDEC(typeKind, op1); break;
    case CX_IC_XOR: result = cx_ic_getVmXOR(typeKind, op1, op2); break;
    case CX_IC_OR: result = cx_ic_getVmOR(typeKind, op1, op2); break;
    case CX_IC_AND: result = cx_ic_getVmAND(typeKind, op1, op2); break;
    case CX_IC_NOT: result = cx_ic_getVmNOT(typeKind, op1); break;
    case CX_IC_SHIFT_LEFT: result = cx_ic_getVmSHIFT_LEFT(typeKind, op1, op2); break;
    case CX_IC_SHIFT_RIGHT: result = cx_ic_getVmSHIFT_RIGHT(typeKind, op1, op2); break;
    case CX_IC_COND_OR: result = cx_ic_getVmCOR(t, typeKind, op1); break;
    case CX_IC_COND_AND: result = cx_ic_getVmCAND(t, typeKind, op1); break;
    case CX_IC_COND_NOT: result = cx_ic_getVmCNOT(t, typeKind, op1); break;
    case CX_IC_COND_EQ: {
        if ((t->kind == CX_PRIMITIVE) && (cx_primitive(t)->kind == CX_TEXT)) {
            result = cx_ic_getVmCEQSTR(CX_IC_VMTYPE_B, op1);
        } else {
            result = cx_ic_getVmCEQ(t, typeKind, op1);
        }
        break;
    }
    case CX_IC_COND_NEQ: {
        if ((t->kind == CX_PRIMITIVE) && (cx_primitive(t)->kind == CX_TEXT)) {
            result = cx_ic_getVmCNEQSTR(CX_IC_VMTYPE_B, op1);
        } else {
            result = cx_ic_getVmCNEQ(t, typeKind, op1);
        }
        break;
    }
    case CX_IC_COND_GT: result = cx_ic_getVmCGT(t, typeKind, op1); break;
    case CX_IC_COND_LT: result = cx_ic_getVmCLT(t, typeKind, op1); break;
    case CX_IC_COND_GTEQ: result = cx_ic_getVmCGTEQ(t, typeKind, op1); break;
    case CX_IC_COND_LTEQ: result = cx_ic_getVmCLTEQ(t, typeKind, op1); break;

    /* Program control */
    case CX_IC_JUMP: result = CX_VM_JUMP; break;
    case CX_IC_JEQ: result = cx_ic_getVmJEQ(typeKind, op1); break;
    case CX_IC_JNEQ: result = cx_ic_getVmJNEQ(typeKind, op1); break;
    case CX_IC_STOP: result = CX_VM_STOP; break;

    /* Function calls */
    case CX_IC_PUSH: {
        if (op->s1Any) {
            if ((op1 != CX_IC_VMOPERAND_X) && (op->s1->_parent.kind != CX_IC_LITERAL) ) {
                result = cx_ic_getVmPUSHANY(CX_IC_VMTYPE_W, op1);
            } else {
                result = cx_ic_getVmPUSHANYX(t, typeKind, op1 == CX_IC_VMOPERAND_X ? CX_IC_VMOPERAND_R : op1);
            }
        } else {
            if (op1 != CX_IC_VMOPERAND_X) {
                result = cx_ic_getVmPUSH(typeKind, op1);
            } else {
                result = cx_ic_getVmPUSHX(typeKind, CX_IC_VMOPERAND_R);
            }
        }
        break;
    }

    case CX_IC_CALL: {
        result = cx_ic_getVmCall(op, op1, op2);
        break;
    }

    case CX_IC_RET:
        if (cx_type_sizeof(t) <= 8) {
            if (cx_type_sizeof(t) == 8) {
                result = cx_ic_getVmRET(CX_IC_VMTYPE_D, op1);
            } else {
                result = cx_ic_getVmRET(typeKind, op1);
            }
        } else {
            result = cx_ic_getVmRETCPY(CX_IC_VMTYPE_L, op1);
        }
        break;

    /* Memory management */
    case CX_IC_NEW: result = cx_ic_getVmNEW(typeKind, op1, op2); break;
    case CX_IC_FREE: result = cx_ic_getVmFree(op, t, typeKind, op1); break;
    case CX_IC_KEEP: result = cx_ic_getVmKEEP(typeKind, op1); break;

    case CX_IC_DEFINE: result = cx_ic_getVmDEFINE(typeKind, op1); break;

    /* Notifications */
    case CX_IC_UPDATE:
        if (op->s2) {
            result = cx_ic_getVmUPDATEFROM(typeKind, op1, op2);
        } else {
            result = cx_ic_getVmUPDATE(typeKind, op1);
        }
        break;

    case CX_IC_UPDATEEND:
        if (op->s2) {
            result = cx_ic_getVmUPDATEENDFROM(typeKind, op1, op2);
        } else {
            result = cx_ic_getVmUPDATEEND(typeKind, op1);
        }
        break;

    case CX_IC_UPDATEBEGIN: result = cx_ic_getVmUPDATEBEGIN(typeKind, op1); break;
    case CX_IC_UPDATECANCEL: result = cx_ic_getVmUPDATECANCEL(typeKind, op1); break;

    case CX_IC_WAITFOR: result = cx_ic_getVmWAITFOR(typeKind, op1); break;
    case CX_IC_WAIT: result = cx_ic_getVmWAIT(typeKind, op1, op2); break;

    default:
        cx_assert(0, "invalid intermediate op-code");
        break;
    }

    return result;
}

/* Get type and storage kind for operands and assemble operand when necessary (in case an
 * offset-instruction has to be inserted for a dynamically allocated object). */
static cx_vmOp* cx_vmGetTypeAndAssemble(

    /* In parameters */
    cx_ic_vmProgram *program, 
    cx_vmOp *vmOp, 
    cx_icOp op, 
    cx_bool threeOperands, 
    cx_icValue storage, 
    cx_icValue op1, 
    cx_icValue op2, 
    cx_icDerefMode storageDeref, 
    cx_icDerefMode opDeref1, 
    cx_icDerefMode opDeref2,

    /* Out parameters */
    cx_type *t, 
    cx_ic_vmType *type, 
    cx_ic_vmOperand *storageKind, 
    cx_ic_vmOperand *opKind1, 
    cx_ic_vmOperand *opKind2) {
    
    if (op1) {
        *opKind1 = cx_ic_getVmOperand(program, opDeref1, op1);
        *t = cx_ic_valueType(op1);
        
        if (!op->s1Any && !threeOperands) {
            *type = cx_ic_getVmType(op1, opDeref1);
        } else if (op->s1Any) {
            if (((op->s1->_parent.kind != CX_IC_LITERAL) || (((*t)->kind != CX_PRIMITIVE) || (cx_primitive(*t)->width != CX_WIDTH_64)))) {
                *type = CX_IC_VMTYPE_W;
            } else {
               *type = cx_ic_getVmType(op1, opDeref1);
            }
        } else {
            *type = CX_IC_VMTYPE_W;
        }
        if (((cx_ic)op1)->kind == CX_IC_STORAGE) {
            vmOp = cx_ic_vmStorageAssemble((cx_icStorage)op1, program, vmOp);
        }
    }
    if (op2) {
        if (((cx_ic)op2)->kind == CX_IC_STORAGE) {
            if (op2 != op1) {
                vmOp = cx_ic_vmStorageAssemble((cx_icStorage)op2, program, vmOp);
            }
        }
        *opKind2 = cx_ic_getVmOperand(program, opDeref2, op2);
    }
    if (storage) {
        if (((cx_ic)storage)->kind == CX_IC_STORAGE) {
            if ((storage != op1) && (storage != op2))
                vmOp = cx_ic_vmStorageAssemble((cx_icStorage)storage, program, vmOp);
        }
        *storageKind = cx_ic_getVmOperand(program, storageDeref, storage);
    }
    
    /* If storage is any, set hi to storage-type. However, don't set the type when the
     * operand is a literal and the value is 64 bit. In that case there is no space
     * for the type, and the assembler will select an instruction that hard-codes the type. */
    if (op1 && op->s1Any && !((((cx_ic)op1)->kind == CX_IC_LITERAL) &&
                       (*opKind1 == CX_IC_VMOPERAND_V) &&
                       (((*t)->kind == CX_PRIMITIVE) &&
                       (cx_primitive(*t)->width == CX_WIDTH_64)))) {
        vmOp->hi.w = (cx_word)cx_ic_valueType(op1);
    }
    
    return vmOp;
}

/* Instruction without operands */
static void cx_vmOp0(cx_ic_vmProgram *program, cx_vmOp *vmOp, cx_icOp op, cx_icValue op1, cx_icDerefMode opDeref1) {
    cx_type t;
    cx_ic_vmType type;
    cx_ic_vmOperand opKind1;
    vmOp = cx_vmGetTypeAndAssemble(program, vmOp, op, FALSE, NULL, op1, NULL, 0, opDeref1, 0,  &t, &type, NULL, &opKind1, NULL);
    vmOp->op = cx_ic_getVmOpKind(program, op, op1, NULL, 0, 0, 0, 0, 0);
}

/* Instruction with one operand */
static void cx_vmOp1(cx_ic_vmProgram *program, cx_vmOp *vmOp, cx_icOp op, cx_icValue op1, cx_icDerefMode opDeref1) {
    cx_type t;
    cx_ic_vmType type;
    cx_ic_vmOperand opKind1;
    vmOp = cx_vmGetTypeAndAssemble(program, vmOp, op, FALSE, NULL, op1, NULL, 0, opDeref1, 0,  &t, &type, NULL, &opKind1, NULL);
    vmOp->op = cx_ic_getVmOpKind(program, op, op1, t, type, opKind1, CX_IC_VMOPERAND_NONE, opDeref1, 0);

    /* Set size of type in case return instruction needs to do a memcpy */ 
    if (op->kind == CX_IC_RET) {
        vmOp->hi.w = cx_type_sizeof(t);
    }

    type = cx_vmTranslateVmType(op->kind, type);
    cx_ic_vmSetOp1Addr(program, vmOp, type, opKind1, op1);
}

/* Instruction with one operand and one staged operand
 * Create extra operation. This will contain the actual operation while vmOp (it is first)
 * will contain a stage, which will stage the values for the conditional operation. The
 * reason to do this with a stage rather than with a set is that a conditional operation has
 * a boolean value as a result, which can be of a different size than the operands.
 */
static void cx_vmOp1Staged(cx_ic_vmProgram *program, cx_vmOp *vmOp, cx_icOp op, cx_icValue storage, cx_icValue op1, cx_icDerefMode storageDeref, cx_icDerefMode opDeref1) {
    cx_vmOp *vmStoredOp;
    cx_type t;
    cx_ic_vmType type;
    cx_ic_vmOperand opKind1, storageKind;

    vmOp = cx_vmGetTypeAndAssemble(program, vmOp, op, FALSE, storage, op1, NULL, storageDeref, opDeref1, 0,  &t, &type, &storageKind, &opKind1, NULL);
    type = cx_vmTranslateVmType(op->kind, type);
    vmOp->op = cx_ic_getVmSTAGE1(type, opKind1);
    cx_ic_vmSetOp1Addr(program, vmOp, type, opKind1, op1);
    
    vmStoredOp = cx_vmProgram_addOp(program->program, ((cx_ic)op)->line);
    vmStoredOp->op = cx_ic_getVmOpKind(program, op, op1, t, type, storageKind, opKind1, storageDeref, opDeref1);
    cx_ic_vmSetOp1Addr(program, vmStoredOp, type, storageKind, storage);
}

/* Instruction with two operands */
static void cx_vmOp2(cx_ic_vmProgram *program, cx_vmOp *vmOp, cx_icOp op, cx_icValue op1, cx_icValue op2, cx_icDerefMode opDeref1, cx_icDerefMode opDeref2) {
    cx_type t;
    cx_ic_vmType type;
    cx_ic_vmOperand opKind1, opKind2;
    
    vmOp = cx_vmGetTypeAndAssemble(program, vmOp, op, FALSE, NULL, op1, op2, 0, opDeref1, opDeref2,  &t, &type, NULL, &opKind1, &opKind2);

    vmOp->op = cx_ic_getVmOpKind(program, op, op1, t, type, opKind1, opKind2, opDeref1, opDeref2);
    cx_ic_vmSetOp2Addr(program, vmOp, type, opKind1, opKind2, op1, op2);
}

/* Instruction with two operands and a storage
 * Create extra operation. This will contain the actual operation while vmOp (it is first)
 * will contain the set. The result of these two ops will look like:
 *
 * set  Storage Operand1 (vmOp)
 * [op] Storage Operand2 (vmStoredOp)
 * */
static void cx_vmOp2Storage(cx_ic_vmProgram *program, cx_vmOp *vmOp, cx_icOp op, cx_icValue storage, cx_icValue op1, cx_icValue op2, cx_icDerefMode storageDeref, cx_icDerefMode opDeref1, cx_icDerefMode opDeref2) {
    cx_vmOp *vmStoredOp;
    cx_type t;
    cx_ic_vmType type;
    cx_ic_vmOperand opKind1, opKind2, storageKind;
    
    vmOp = cx_vmGetTypeAndAssemble(program, vmOp, op, FALSE, storage, op1, op2, storageDeref, opDeref1, opDeref2,  &t, &type, &storageKind, &opKind1, &opKind2);
    vmOp->op = cx_ic_getVmSet(t, (cx_icStorage)storage, type, storageKind, opKind1, storageDeref, opDeref1);
    cx_ic_vmSetOp2Addr(program, vmOp, type, storageKind, opKind1, storage, op1);
    
    vmStoredOp = cx_vmProgram_addOp(program->program, ((cx_ic)op)->line);
    vmStoredOp->op = cx_ic_getVmOpKind(program, op, storage, t, type, storageKind, opKind2, storageDeref, opDeref2);
    cx_ic_vmSetOp2Addr(program, vmStoredOp, type, storageKind, opKind2, storage, op2);
}

/* Set-instruction with two operands and a storage
 * Create extra operation. This will contain a set-operation and an extra set-operation
 * to store the result of the first set in storage. The result of these two ops will look like:
 *
 * set  Operand1 Operand2 (vmOp)
 * set  Storage Operand1 (vmStoredOp)
 * */
static void cx_vmOp2Set(cx_ic_vmProgram *program, cx_vmOp *vmOp, cx_icOp op, cx_icValue storage, cx_icValue op1, cx_icValue op2, cx_icDerefMode storageDeref, cx_icDerefMode opDeref1, cx_icDerefMode opDeref2) {
    cx_vmOp *vmStoredOp;
    cx_type t;
    cx_ic_vmType type;
    cx_ic_vmOperand opKind1, opKind2, storageKind;
    
    vmOp = cx_vmGetTypeAndAssemble(program, vmOp, op, FALSE, storage, op1, op2, storageDeref, opDeref1, opDeref2,  &t, &type, &storageKind, &opKind1, &opKind2);
    vmOp->op = cx_ic_getVmSet(t, (cx_icStorage)op1, type, opKind1, opKind2, opDeref1, opDeref2);
    cx_ic_vmSetOp2Addr(program, vmOp, type, opKind1, opKind2, op1, op2);

    vmStoredOp = cx_vmProgram_addOp(program->program, ((cx_ic)op)->line);
    vmStoredOp->op = cx_ic_getVmSet(t, (cx_icStorage)storage, type, storageKind, opKind1, storageDeref, opDeref1);
    cx_ic_vmSetOp2Addr(program, vmStoredOp, type, storageKind, opKind1, storage, op1);
}

/* Instruction with two operands and two staged
 * Create extra operation. This will contain the actual operation while vmOp (it is first)
 * will contain a stage, which will stage the values for the conditional operation. The
 * reason to do this with a stage rather than with a set is that a conditional operation has
 * a boolean value as a result, which can be of a different size than the operands.
 */
static void cx_vmOp2Staged(cx_ic_vmProgram *program, cx_vmOp *vmOp, cx_icOp op, cx_icValue storage, cx_icValue op1, cx_icValue op2, cx_icDerefMode storageDeref, cx_icDerefMode opDeref1, cx_icDerefMode opDeref2) {
    cx_vmOp *vmStoredOp;
    cx_type t;
    cx_ic_vmType type;
    cx_ic_vmOperand opKind1, opKind2, storageKind;
    
    vmOp = cx_vmGetTypeAndAssemble(program, vmOp, op, FALSE, storage, op1, op2, storageDeref, opDeref1, opDeref2,  &t, &type, &storageKind, &opKind1, &opKind2);
    type = cx_vmTranslateVmType(op->kind, type);

    vmOp->op = cx_ic_getVmSTAGE2(type, opKind1, opKind2);
    cx_ic_vmSetOp2Addr(program, vmOp, type, opKind1, opKind2, op1, op2);
    
    vmStoredOp = cx_vmProgram_addOp(program->program, ((cx_ic)op)->line);
    vmStoredOp->op = cx_ic_getVmOpKind(program, op, storage, t, type, storageKind, opKind1, storageDeref, opDeref1);
    cx_ic_vmSetOp1Addr(program, vmStoredOp, type, storageKind, storage);
}

/* Cast instruction with either a reference cast or two staged types, a source and storage */
static void cx_vmOp2Cast(cx_ic_vmProgram *program, cx_vmOp *vmOp, cx_icOp op, cx_icValue storage, cx_icValue op1, cx_icValue op2, cx_icDerefMode storageDeref, cx_icDerefMode opDeref1, cx_icDerefMode opDeref2) {
    cx_vmOp *vmStoredOp;
    cx_type sourceType, destinationType;
    cx_ic_vmType type;
    cx_ic_vmOperand opKind1, opKind2, storageKind;
    
    destinationType = cx_ic_valueType(storage);
    
    /* If destinationType is a reference, insert regular 2-operand instruction */
    if (destinationType->reference) {
        cx_vmOp2Storage(program, vmOp, op, storage, op1, op2, storageDeref, opDeref1, opDeref2);
    /* If destinationType is not a reference, stage types and insert primitive cast */
    } else {
        vmOp = cx_vmGetTypeAndAssemble(program, vmOp, op, FALSE, storage, op1, op2, storageDeref, opDeref1, opDeref2,  &sourceType, &type, &storageKind, &opKind1, &opKind2);
        type = cx_vmTranslateVmType(op->kind, type);

        if (sizeof(intptr_t) == 4) {
            vmOp->op = CX_VM_STAGE2_LVV;
        } else if (sizeof(intptr_t) == 8) {
            vmOp->op = CX_VM_STAGE2_DPP;
        }
        vmOp->lo.w = (cx_word)sourceType;
        vmOp->hi.w = (cx_word)destinationType;
        
        vmStoredOp = cx_vmProgram_addOp(program->program, ((cx_ic)op)->line);
        vmStoredOp->op = cx_ic_getVmOpKind(program, op, storage, sourceType, type, storageKind, opKind1, storageDeref, opDeref1);
        cx_ic_vmSetOp2Addr(program, vmStoredOp, type, storageKind, opKind1, storage, op1);
    }
}

static void cx_ic_getVmOp(cx_ic_vmProgram *program, cx_icOp op) {
    cx_icDerefMode opDeref1=0, opDeref2=0, storageDeref=0;
    cx_icValue op1 = NULL, op2 = NULL, storage = NULL;
    cx_vmOp *vmOp;
    cx_bool stageOperands = FALSE;
    cx_bool castOperands = FALSE;

    /* Allocate operation */
    vmOp = cx_vmProgram_addOp(program->program, ((cx_ic)op)->line);

    switch(op->kind) {
    /* Following operations do not have storage and one operand (op->s1 points to 1st operand) */
    case CX_IC_UPDATE:
    case CX_IC_UPDATEEND:
        /* Update-from parameter requires a 2nd operand */
        if (op->s2) {
            op2 = op->s2;
            opDeref2 = op->s2Deref;
        }
        /* no break */
    case CX_IC_DEFINE:
    case CX_IC_INC:
    case CX_IC_DEC:
    case CX_IC_RET:
    case CX_IC_FREE:
    case CX_IC_KEEP:
    case CX_IC_UPDATEBEGIN:
    case CX_IC_UPDATECANCEL:
    case CX_IC_PUSH:
    case CX_IC_WAITFOR:
        op1 = op->s1;
        storage = NULL;
        opDeref1 = op->s1Deref;
        break;

    /* Following operations have one operand and a storage. This category is unusual but is used when the result has a different
     * type than the operands. */
    case CX_IC_COND_NOT:
        stageOperands = TRUE;
        storage = op->s1;
        storageDeref = op->s1Deref;
        op1 = op->s2;
        opDeref1 = op->s2Deref;
        break;

    /* Following operations do not have storage and two operands (op->s1 to 1st, op->s2 to 2nd operand) */
    case CX_IC_JEQ:
    case CX_IC_JNEQ:
    case CX_IC_NEW:
    case CX_IC_WAIT:
        op1 = op->s1;
        op2 = op->s2;
        storage = NULL;
        opDeref1 = op->s1Deref;
        opDeref2 = op->s2Deref;
        break;

    /* Jump sets jump address */
    case CX_IC_JUMP: {
        cx_ic_vmLabel *label;
        label = cx_ic_vmLabelGet(program, *(cx_uint32*)cx_ic_valueValue(program, op->s1));
        cx_ic_vmLabelAddReferee(program, label, &vmOp->lo.w);
        op1 = NULL;
        op2 = NULL;
        storage = NULL;
        break;
    }

    /* Call sets function address */
    case CX_IC_CALL:
        if (cx_ic_operandIsComposite((cx_icStorage)op->s2, CX_DELEGATE)) {
            op1 = op->s1;
            op2 = op->s2;
            opDeref1 = op->s1Deref;
            storage = NULL;
        } else {
            op1 = op->s1;
            storage = NULL;
            vmOp->hi.w = (cx_word)((cx_icObject)op->s2)->ptr;
            opDeref1 = op->s1Deref;            
        }

        break;

    /* Cast */
    case CX_IC_CAST:
        castOperands = TRUE;

    /* no break */
    case CX_IC_COND_OR:
    case CX_IC_COND_AND:
    case CX_IC_COND_EQ:
    case CX_IC_COND_NEQ:
    case CX_IC_COND_GT:
    case CX_IC_COND_GTEQ:
    case CX_IC_COND_LT:
    case CX_IC_COND_LTEQ:
        /* Conditional operations require staging */
        if (op->kind != CX_IC_CAST) {
            stageOperands = TRUE;
        }
    default:
        op1 = op->s2;
        op2 = op->s3;
        storage = op->s1;
        opDeref1 = op->s2Deref;
        opDeref2 = op->s3Deref;
        storageDeref = op->s1Deref;
        break;
    }

    /* Assemble the actual operation, differentiate between 1 and 2-operand operations */
    if (op1) {
        /* Operation has two operands */
        if (op2) {
            /* If operation has a storage-operand, insert set-operation */
            if (storage && (storage != op1)) {
                if (op->kind == CX_IC_SET) {
                    cx_vmOp2Set(program, vmOp, op, storage, op1, op2, storageDeref, opDeref1, opDeref2);
                } else{
                    if (!stageOperands) {
                        if (castOperands) {
                            cx_vmOp2Cast(program, vmOp, op, storage, op1, op2, storageDeref, opDeref1, opDeref2);
                        } else {
                            cx_vmOp2Storage(program, vmOp, op, storage, op1, op2, storageDeref, opDeref1, opDeref2);
                        }
                    } else {
                        cx_vmOp2Staged(program, vmOp, op, storage, op1, op2, storageDeref, opDeref1, opDeref2);
                    }
                }
            } else {
                cx_vmOp2(program, vmOp, op, op1, op2, opDeref1, opDeref2);
            }
        /* Operation has one operand */
        } else {
            if (!stageOperands) {
                cx_vmOp1(program, vmOp, op, op1, opDeref1);
            } else {
                cx_vmOp1Staged(program, vmOp, op, storage, op1, storageDeref, opDeref1);
            }
        }
    } else {
        cx_vmOp0(program, vmOp, op, storage, storageDeref);
    }
}

static cx_int16 cx_icOp_toVm(cx_icOp op, cx_ic_vmProgram *program) {
    CX_UNUSED(program);

    if (!program->program) {
        program->program = cx_vmProgram_new(program->icProgram->filename, program->function->function);
    }

    /* If operation is push, increase stack-size */
    if (op->kind == CX_IC_PUSH) {
        if(op->s1Any) {
            program->stackSize += sizeof(cx_any);
        }else {
            cx_type t = cx_ic_valueType(op->s1);
            program->stackSize += cx_type_sizeof(t);
        }
        if (program->stackSize > program->maxStackSize) {
            program->maxStackSize = program->stackSize;
        }
    }

    if (op->kind == CX_IC_CALL) {
        cx_function f;

        /* When the function is a vm-function the vm will directly invoke the function
         * without using cx_call. To avoid memcpy'ing between the stack of the calling
         * function and the storage of the called function the stack is made as big as the
         * largest storage of all called functions.
         *
         * Because the storage-size of the function is not known when the function is not
         * yet defined, setting the stack-size is in this case delayed until all functions
         * are assembled.
         */
        if (((cx_icStorage)op->s2)->kind == CX_STORAGE_OBJECT) {
            cx_object o = ((cx_icObject)op->s2)->ptr;
            cx_type t = cx_typeof(o);
            if ((t->kind == CX_COMPOSITE) && (cx_interface(t)->kind == CX_PROCEDURE)) {
                f = o;
                if (f->kind == CX_PROCEDURE_VM) {
                    if (cx_checkState(f, CX_DEFINED)) {
                        cx_vmProgram inlineProgram = (cx_vmProgram)f->implData;
                        if (inlineProgram->storage > program->maxStackSize) {
                            program->maxStackSize = inlineProgram->storage;
                        }
                    } else {
                        cx_ic_vmInlineFunctionMark(program, program->program, f);
                    }
                }
            }
        }

        /* Reset stacksize */
        program->stackSize = 0;
    }

    cx_ic_getVmOp(program, op);

    return 0;
}

static cx_uint16 cx_ic_vmProgram_push(cx_ic_vmProgram *program) {
    cx_uint16 result = 0;

    if (program->scope) {
        result = program->scopeSize[program->scope - 1];
    }

    program->scope++;
    program->scopeSize[program->scope-1] = 0;

    return result;
}

static void cx_ic_vmProgram_setScopeSize(cx_ic_vmProgram *program, cx_uint16 size) {
    program->scopeSize[program->scope-1] = size;
    if (size > program->maxScopeSize) {
        program->maxScopeSize = size;
    }
}

static void cx_ic_vmProgram_pop(cx_ic_vmProgram *program) {
    program->scope--;
}

static void cx_icZeroLocal(cx_ic_vmProgram *program, cx_uint16 initStart, cx_uint16 size) {
    cx_vmOp *vmOp;

    vmOp = cx_vmProgram_addOp(program->program, 0);

    switch(size) {
    case sizeof(cx_uint8):
        vmOp->op = CX_VM_SET_BRV;
        vmOp->ic.b._1 = initStart;
        vmOp->ic.b._2 = 0;
        break;
    case sizeof(cx_uint16):
        vmOp->op = CX_VM_SET_SRV;
        vmOp->ic.b._1 = initStart;
        vmOp->ic.b._2 = 0;
        break;
    case sizeof(cx_uint32):
        vmOp->op = CX_VM_SET_LRV;
        vmOp->ic.b._1 = initStart;
        vmOp->lo.w = 0;
        break;
    case sizeof(cx_uint64):
        vmOp->op = CX_VM_SET_DRV;
        vmOp->ic.b._1 = initStart;
        vmOp->lo.w = 0;
        break;
    default:
        vmOp->op = CX_VM_ZERO;
        vmOp->ic.b._1 = initStart;
        vmOp->lo.w = size;
        break;
    }
}

static void cx_icInitLocal(cx_ic_vmProgram *program, cx_uint16 localAddr, cx_type type) {
    cx_vmOp *vmOp;
    
    vmOp = cx_vmProgram_addOp(program->program, 0);

    vmOp->op = CX_VM_INIT;
    vmOp->ic.b._1 = localAddr;
    vmOp->lo.w = (cx_word)type;
}

static cx_int16 cx_icScope_toVm(cx_icScope scope, cx_ic_vmProgram *program) {
    cx_iter programIter, localIter;
    cx_ic ic;
    cx_int16 result = 0;
    cx_icStorage storage = NULL, local = NULL;
    cx_uint16 size, initStart;
    cx_ic_vmStorage *thisLocal = NULL;

    /* Push a new scope to the program. This manages an administration
     * which keeps track of how much memory each scope requires. */
    size = cx_ic_vmProgram_push(program);

    /* Add locals to program */
    localIter = cx_llIter(scope->storages);
    initStart = size;
    while(cx_iterHasNext(&localIter)) {
        storage = cx_iterNext(&localIter);
        if (storage->kind == CX_STORAGE_LOCAL) {
            cx_ic_vmStorage *vmLocal;
            cx_bool zeroLocal = TRUE;
            local = storage;

            /* Lookup local in program */
            vmLocal = cx_ic_vmStorageGet(program, local);

            /* The 'super' local is actually an alias for the 'this' local
             * with a different type. As such it doesn't need extra space and
             * the address is equal to this. */
            if (!strcmp(local->name, "super")) {
                if (thisLocal) {
                    vmLocal->addr = thisLocal->addr; /* Use address of this */
                }
            } else {
                vmLocal->addr = size;
                if (!strcmp(local->name, "this")) {
                    thisLocal = vmLocal;
                }

                if (((cx_icLocal)local)->isParameter) {
                    /* Parameters are not zero'd, so zero all locals up to this point */
                    if (initStart != size) {
                        cx_icZeroLocal(program, initStart, size - initStart);
                    }
                    zeroLocal = FALSE;
                } else if (!local->isReference && (local->type->kind == CX_COLLECTION) && (cx_collection(local->type)->kind == CX_LIST)) {
                    cx_icZeroLocal(program, initStart, size - initStart);
                    cx_icInitLocal(program, size, local->type);
                    zeroLocal = FALSE;
                }

                /* Increase size */
                if (cx_ic_isReference(local)) {
                    size += sizeof(cx_word);
                } else {
                    size += cx_type_sizeof(local->type);
                }

                if (!zeroLocal) {
                    initStart = size;
                }
            }
        }
    }

    if (size != initStart) {
        if (!((cx_icLocal)local)->isParameter) {
            cx_icZeroLocal(program, initStart, size - initStart);
        }
    }

    /* Set size of scope so that child-scopes know where there locals starts. */
    cx_ic_vmProgram_setScopeSize(program, size);

    programIter = cx_llIter(scope->program);
    while(!result && cx_iterHasNext(&programIter)) {
        ic = cx_iterNext(&programIter);
        switch(ic->kind) {
        case CX_IC_FUNCTION:
            cx_ic_vmProgram_finalize(program);
            program->function = (cx_icFunction)ic;
            break;
        case CX_IC_STORAGE:
        case CX_IC_LITERAL:
            break;
        case CX_IC_LABEL:
            result = cx_icLabel_toVm((cx_icLabel)ic, program);
            break;
        case CX_IC_SCOPE:
            result = cx_icScope_toVm((cx_icScope)ic, program);
            break;
        case CX_IC_OP:
            result = cx_icOp_toVm((cx_icOp)ic, program);
            break;
        }
    }

    cx_ic_vmProgram_pop(program);

    return result;
}

cx_vmProgram cx_icProgram_toVm(cx_icProgram program) {
    cx_ic_vmProgram vmProgram;
    cx_iter functionIter;
    cx_function function;
    cx_iter inlineFunctionIter;
    cx_ic_vmInlineFunction *inlineFunction;
    
    if (!program->errors) {
        /* Parse main-program */
        vmProgram.icProgram = program;
        vmProgram.main = cx_vmProgram_new(program->filename, NULL);
        vmProgram.program = vmProgram.main;
        vmProgram.function = NULL;
        vmProgram.labels = NULL;
        vmProgram.accumulators = NULL;
        vmProgram.inlineFunctions = NULL;
        vmProgram.scope = 0;
        vmProgram.maxScopeSize = 0;
        vmProgram.stackSize = 0;
        vmProgram.maxStackSize = 0;

        /* Set kind of functions to VM - that way they can be
         * recognized as such and make usage of optimzations available
         * when calling vm-to-vm functions. */
        functionIter = cx_llIter(program->functions);
        while(cx_iterHasNext(&functionIter)) {
            function = ((cx_icFunction)cx_iterNext(&functionIter))->function;
            function->kind = CX_PROCEDURE_VM;
        }

        /* Start assembling */
        if (cx_icScope_toVm(program->scope, &vmProgram)) {
            goto error;
        }

        /* Finalize last program */
        cx_ic_vmProgram_finalize(&vmProgram);

        /* Correct stack-sizes for inline functions that have been finalized
         * after they were encountered */
        if (vmProgram.inlineFunctions) {
            inlineFunctionIter = cx_llIter(vmProgram.inlineFunctions);
            while(cx_iterHasNext(&inlineFunctionIter)) {
                cx_vmProgram program;
                inlineFunction = cx_iterNext(&inlineFunctionIter);
                program = (cx_vmProgram)inlineFunction->function->implData;
                if (program->storage > inlineFunction->program->stack) {
                    inlineFunction->program->stack = program->storage;
                }
                cx_dealloc(inlineFunction);
            }
            cx_llFree(vmProgram.inlineFunctions);
        }
    } else {
        printf("%s: program contains errors, cannot compile.\n", program->filename);
        goto error;
    }

    return vmProgram.main;
error:
    return NULL;
}



