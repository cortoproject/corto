#include "ic_node.h"
#include "cortex.h"
#include "cx_vm_operands.h"

typedef struct ic_vmLabel {
    cx_uint32 id;
    cx_uint32 pc;
    void *referees[256]; /* The jumps to this label. At assemble-time, the exact address of the label is not yet known
                          * so this information is filled in after the program is assembled for each referee */
    cx_uint32 refereeCount;
}ic_vmLabel;

typedef struct ic_vmStorage ic_vmStorage;
struct ic_vmStorage {
    ic_storage ic;
    cx_uint32 firstUsed;
    cx_uint32 lastUsed;
    void *referees[256]; /* The jumps to this accumulator. At assemble-time, the exact address of the accumulator is not yet known
                          * so this information is filled in after the program is assembled for each referee */
    cx_uint32 refereeCount;
    cx_uint16 addr;

    /* Member & element accumulators have a base and offset */
    cx_uint16 offset;
    ic_vmStorage *base;
    cx_bool assembled; /* Offsets of multiple member-operations are accumulated into one register so that
                        * instead of calculating multiple offsets at runtime, only one operation is required. This
                        * variable remains FALSE until the storage is used after which an operation is inserted
                        * to calculate the accumulated offset.
                        * This is only applicable for access to dynamically allocated objects or storages with dynamic
                        * components (elements with variable indexes). By default this value is TRUE. */
    cx_bool reusable;  /* A non-reusable storage needs to be assembled each time it is evaluated because the storage depends
                        * on the value of other storages, for example the index-expression of an element storage. */
};

typedef struct ic_vmInlineFunction {
    cx_vmProgram program;
    cx_function function;
}ic_vmInlineFunction;

typedef struct ic_vmProgram {
    ic_program icProgram;
    cx_vmProgram main; /* Keep track of what is the main-module of a program (where the program starts) */
    cx_vmProgram program;
    ic_function function;
    cx_ll labels;
    cx_ll storages;
    cx_ll inlineFunctions;
    cx_uint16 scopeSize[256];
    cx_uint32 scope;
    cx_uint32 maxScopeSize; /* The maximum scope-size is where accumulators are allocated (thus after the locals) */
    cx_uint32 stackSize;
    cx_uint32 maxStackSize; /* The maximum stack-size is the maximum amount of space a call needs for its arguments */
}ic_vmProgram;

typedef enum ic_vmType {
    IC_VMTYPE_B,
    IC_VMTYPE_S,
    IC_VMTYPE_L,
    IC_VMTYPE_W,
    IC_VMTYPE_D
}ic_vmType;

typedef enum ic_vmOperand {
    IC_VMOPERAND_NONE,
    IC_VMOPERAND_V,
    IC_VMOPERAND_R,
    IC_VMOPERAND_P,
    IC_VMOPERAND_Q,
    IC_VMOPERAND_X,
    IC_VMOPERAND_A
}ic_vmOperand;

cx_string ic_vmOperandStr(ic_vmOperand op) {
    switch(op) {
        case IC_VMOPERAND_NONE: return "none";
        case IC_VMOPERAND_V: return "V";
        case IC_VMOPERAND_R: return "R";
        case IC_VMOPERAND_P: return "P";
        case IC_VMOPERAND_Q: return "Q";
        case IC_VMOPERAND_X: return "X";
        case IC_VMOPERAND_A: return "A";
    };
    return "<?>";
}

static ic_vmStorage *ic_vmStorageGet(ic_vmProgram *program, ic_storage ic_accumulator);

static void ic_vmProgram_fillInLabels(ic_vmProgram *program) {
    cx_iter labelIter;
    ic_vmLabel *label;
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
typedef struct ic_registerClaim {
    ic_vmStorage *storage;
    cx_uint16 addr;
    cx_uint16 size;
    cx_uint32 start;
    cx_uint32 end;
}ic_registerClaim;

/* Determine whether storage is of a reference type or passed by reference. */
cx_bool ic_isReference(ic_storage storage) {
    cx_type t = storage->type;
    cx_bool result = FALSE;

    if (storage->isReference) {
        result = TRUE;
    } else {
        if (storage->kind == IC_VARIABLE) {
            if (((ic_variable)storage)->isParameter) {
                if (t->kind != CX_PRIMITIVE) {
                    result = TRUE;
                }
            }
        }
    }

    return result;
}

static cx_bool ic_storageMustAllocate(ic_vmProgram *program, ic_vmStorage *storage) {
    cx_bool result = FALSE;

    if (storage->refereeCount && (!storage->reusable || (storage->ic->kind == IC_ACCUMULATOR))) {
        result = TRUE;

        if ((storage->ic->kind == IC_MEMBER) || (storage->ic->kind == IC_ELEMENT)) {
            if (!storage->offset) {
                cx_uint32 referee;
                result = FALSE;
                for(referee=0; referee < storage->refereeCount; referee++) {
                    *(cx_uint16*)CX_OFFSET(storage->referees[referee], program->program->program) = storage->base->addr;
                }
            }
        }
    }

    return result;
}

static void ic_vmProgram_allocateAccumulators(ic_vmProgram *program) {
    cx_iter accumulatorIter;
    ic_vmStorage *storage;
    cx_uint16 offset;
    ic_registerClaim claims[256];
    ic_registerClaim *claim;
    cx_uint32 i, referee;
    cx_bool overlap;

    memset(claims, 0, sizeof(claims));
    offset = program->maxScopeSize;

    if (program->storages) {
        accumulatorIter = cx_llIter(program->storages);
        while(cx_iterHasNext(&accumulatorIter)) {
            storage = cx_iterNext(&accumulatorIter);

            if (ic_storageMustAllocate(program, storage)) {

                /* Find lfree claim */
                claim = claims;
                while(claim->storage) {
                    if (claim->end < storage->firstUsed) { /* Accumulators are chronologically ordered, so this is valid */
                        break;
                    }
                    claim++;
                }

                claim->storage = storage;
                claim->start = storage->firstUsed;
                claim->end = storage->lastUsed;
                claim->addr = offset;
                
                /* If storage has to be allocated and it has a base, storage represents a member address */
                if (storage->base || storage->ic->isReference) {
                    claim->size = sizeof(cx_word);
                } else {
                    claim->size = cx_type_sizeof(storage->ic->type);
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

                for(referee=0; referee < storage->refereeCount; referee++) {
                    *(cx_uint16*)CX_OFFSET(storage->referees[referee], program->program->program) = claim->addr;
                }
                storage->addr = claim->addr;
            }
        }

        /* Free resources */
        accumulatorIter = cx_llIter(program->storages);
        while(cx_iterHasNext(&accumulatorIter)) {
            storage = cx_iterNext(&accumulatorIter);
            cx_dealloc(storage);
        }
        cx_llFree(program->storages);
        program->storages = NULL;
    }
}

void ic_vmProgram_clean(ic_vmProgram *vmProgram) {
    /* Reset values */
    vmProgram->scope = 0;
    vmProgram->maxScopeSize = 0;
    vmProgram->stackSize = 0;
    vmProgram->maxStackSize = 0;
    vmProgram->program = NULL;
}

extern cx_bool CX_DEBUG_ENABLED;

void ic_vmProgram_finalize(ic_vmProgram *vmProgram) {
    cx_vmOp  *stop;

    /* Add STOP instruction if this is the main-module */
    if (vmProgram->main == vmProgram->program) {
        stop = cx_vmProgram_addOp(vmProgram->program, 0);
        stop->op = CX_VM_STOP;
    }

    /* Fill in labels */
    ic_vmProgram_fillInLabels(vmProgram);

    /* Allocate and fill in accumulators */
    ic_vmProgram_allocateAccumulators(vmProgram);

    /* Set size of program */
    vmProgram->program->storage = vmProgram->maxScopeSize;
    vmProgram->program->stack = vmProgram->maxStackSize;

    /* If program is a function, set the function-implementation to the program */
    if (vmProgram->function) {
        cx_function function = vmProgram->function->function;
        function->impl = (cx_word)cx_call_vm;
        function->implData = (cx_word)vmProgram->program;
        cx_define(function);

#ifdef IC_TRACING
        if (CX_DEBUG_ENABLED)
        {
            cx_id id;
            cx_string programStr = cx_vmProgram_toString(vmProgram->program, NULL);
            printf("%s %s\n%s\n", cx_nameof(cx_typeof(function)), cx_fullname(function, id), programStr);
            cx_dealloc(programStr);
        }
#endif
    }

#ifdef IC_TRACING
    if (CX_DEBUG_ENABLED) {
        if (vmProgram->main == vmProgram->program) {
            cx_string programStr = cx_vmProgram_toString(vmProgram->program, NULL);
            printf("main\n%s\n", programStr);
            cx_dealloc(programStr);
        }
    }
#endif

    /* Clean resources */
    ic_vmProgram_clean(vmProgram);
}

static ic_vmLabel *ic_vmLabelNew(cx_uint32 id) {
    ic_vmLabel *result;

    result = cx_malloc(sizeof(ic_vmLabel));
    result->id = id;
    result->pc = 0;
    result->refereeCount = 0;

    return result;
}

static ic_vmLabel *ic_vmLabelGet(ic_vmProgram *program, cx_uint32 id) {
    cx_iter labelIter;
    ic_vmLabel *label = NULL;

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
        label = ic_vmLabelNew(id);
        if (!program->labels) {
            program->labels = cx_llNew();
        }
        cx_llAppend(program->labels, label);
    }

    return label;
}

static void ic_vmLabelAddReferee(ic_vmProgram *program, ic_vmLabel *label, void *referee) {
    label->referees[label->refereeCount] = CX_OFFSET(referee, -(intptr_t)program->program->program);;
    cx_assert(label->refereeCount < 256, "unsupported number of references to one label (max is 256)");
    label->refereeCount++;
}

static ic_vmStorage *ic_vmStorageNew(ic_vmProgram *program, ic_storage acc, cx_uint32 firstUsed) {
    ic_vmStorage *result;

    result = cx_calloc(sizeof(ic_vmStorage));
    result->ic = acc;
    result->firstUsed = firstUsed;

    if (!acc->base) { /* Never overwrite storages which have no base */
        result->reusable = TRUE;
        result->assembled = TRUE;
    } else {
        cx_bool staticBase;
        result->base = ic_vmStorageGet(program, acc->base);

        if (result->base->base) {
            staticBase = result->base->reusable;
        } else {
            staticBase = !acc->base->isReference;
        }

        if (acc->kind == IC_MEMBER) {
            result->offset = ((ic_member)acc)->member->offset += result->base->offset;
            if (staticBase) {
                result->reusable = TRUE;
                result->assembled = TRUE;
            }
        } else if (!((ic_element)acc)->variableIndex && 
            acc->type->kind == CX_COLLECTION && (cx_collection(acc->type)->kind == CX_ARRAY)) {
            cx_collection type = cx_collection(acc->type);
            cx_uint32 index = *(cx_uint32*)ic_literal(((ic_element)acc)->index)->value.value;
            result->offset = cx_type_sizeof(type->elementType) * index + result->base->offset;
            if (staticBase) {
                result->reusable = TRUE;
                result->assembled = TRUE;
            }
        }

        if (result->base->reusable && result->base->base) {
            result->base = result->base->base;
        }
    }

    return result;
}

static void ic_vmStorageAddReferee(ic_vmProgram *program, ic_vmStorage *accumulator, void *referee) {
    accumulator->referees[accumulator->refereeCount] = CX_OFFSET(referee, -(intptr_t)program->program->program);
    cx_assert(accumulator->refereeCount < 256, "unsupported number of references to one accumulator (max is 256)");
    accumulator->refereeCount++;
}

static ic_vmStorage *ic_vmStorageGet(ic_vmProgram *program, ic_storage ic_accumulator) {
    cx_iter accumulatorIter;
    ic_vmStorage *accumulator = NULL;

    if (program->storages) {
        accumulatorIter = cx_llIter(program->storages);
        while(cx_iterHasNext(&accumulatorIter)) {
            accumulator = cx_iterNext(&accumulatorIter);
            if (accumulator->ic == ic_accumulator) {
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
        accumulator = ic_vmStorageNew(program, ic_accumulator, program->program->size);
        if (!program->storages) {
            program->storages = cx_llNew();
        }
        cx_llAppend(program->storages, accumulator);
    }

    /* Keep track of where an accumulator is last used */
    accumulator->lastUsed = program->program->size;

    return accumulator;
}

cx_type ic_valueType(ic_node s) {
    cx_type t = NULL;

    switch(s->kind) {
    case IC_LITERAL:
        t = ((ic_literal)s)->value.type;
        break;
    case IC_STORAGE:
        t = ((ic_storage)s)->type;
        break;
    default:
        cx_assert(0, "invalid operand type");
        break;
    }

    return t;
}

cx_void *ic_valueValue_width(ic_vmProgram *program, ic_node s, void* truncated, int width) {
    void *result = NULL;

    switch(s->kind) {
    case IC_LITERAL: {
        cx_any *v = &((ic_literal)s)->value;
        switch(v->type->kind) {
        case CX_PRIMITIVE:
            switch(cx_primitive(v->type)->kind) {
            case CX_BOOLEAN:
                *(cx_uint16*)truncated = *(cx_bool*)v->value;
                result = truncated;
                break;
            case CX_FLOAT:
                if (width == sizeof(cx_float32)) {
                    if (truncated) {
                        *(cx_float32*)truncated = *(cx_float64*)v->value;
                        result = truncated;
                    } else {
                        result = v->value;
                    }
                } else {
                    result = v->value;
                }
                break;
            default:
                result = v->value;
                break;
            }
        case CX_VOID:
            *(cx_word*)truncated = 0;
            result = truncated;
            break;
        default:
            cx_assert(0, "invalid ic_value type");
            break;
        }
        break;
    }

    case IC_STORAGE:
        switch(((ic_storage)s)->kind) {
        case IC_OBJECT:
            result = &((ic_object)s)->ptr;
            break;
        case IC_VARIABLE:
            cx_assert(0, "variable cannot be interpreted as a value");
            result = NULL;
            break;
        case IC_ACCUMULATOR:
            cx_assert(0, "accumulator cannot be interpreted as a value");
            result = NULL;
            break;
        case IC_MEMBER:
            if (((ic_storage)s)->base->kind == IC_OBJECT) {
                ic_vmStorage *vmStorage = ic_vmStorageGet(program, (ic_storage)s);
                cx_object obj = ((ic_object)vmStorage->base->ic)->ptr;
                *(void**)truncated = CX_OFFSET(obj, ((ic_member)s)->member->offset);
                result = truncated;
            } else {
                cx_assert(0, "local/non reusable member '%s' cannot be interpreted as a value", ((ic_storage)s)->name);
            }
            break;
        case IC_ELEMENT:
            if (!((ic_element)s)->variableIndex) {
                ic_vmStorage *vmStorage = ic_vmStorageGet(program, (ic_storage)s);
                cx_object obj = ((ic_object)vmStorage->base->ic)->ptr;
                *(void**)truncated = CX_OFFSET(obj, vmStorage->offset);
                result = truncated;
            } else {
                cx_assert(0, "local/non reusable member '%s' cannot be interpreted as a value", ((ic_storage)s)->name);
            }
            break;
        default:
            cx_assert(0, "invalid storage kind");
            break;
        }
        break;
    case IC_ADDRESS:
        result = &((ic_address)s)->value;
        break;
    case IC_LABEL:
        result = &((ic_label)s)->id;
        break;
    default:
        cx_assert(0, "invalid operand type");
        break;
    }

    return result;
}

ic_vmType ic_getVmType(ic_node s, ic_derefKind deref) {
    ic_vmType result = IC_VMTYPE_B;
    cx_type t = ic_valueType(s);

    /* Determine VM type based on width of a type. If the value is
     * a storage and derefMode is value, the value is considered a
     * pointer and thus the type is W */
    if ((((ic_node)s)->kind == IC_STORAGE) && (deref == IC_DEREF_ADDRESS)) {
        result = IC_VMTYPE_W;
    } else {
        if (t->kind == CX_PRIMITIVE) {
            switch(cx_primitive(t)->width) {
            case CX_WIDTH_8:
                result = IC_VMTYPE_B;
                break;
            case CX_WIDTH_16:
                result = IC_VMTYPE_S;
                break;
            case CX_WIDTH_32:
                result = IC_VMTYPE_L;
                break;
            case CX_WIDTH_64:
                result = IC_VMTYPE_D;
                break;
            case CX_WIDTH_WORD:
                /* Reserve usage of W for pointer/string types */
                if (cx_primitive(t)->kind == CX_TEXT) {
                    result = IC_VMTYPE_W;
                } else {
                    if (sizeof(intptr_t) == 4) {
                        result = IC_VMTYPE_L;
                    }else {
                        result = IC_VMTYPE_D;
                    }
                }
                break;
            }
        /* If type is not primitive instruction will take the address of the operand */
        } else {
            result = IC_VMTYPE_W;
        }
    }

    return result;
}

ic_vmOperand ic_getVmOperand(ic_vmProgram *program, ic_derefKind deref, ic_node s) {
    ic_vmOperand result = IC_VMOPERAND_V;

    switch(s->kind) {
    case IC_LABEL:
    case IC_ADDRESS:
        result = IC_VMOPERAND_A;
        break;
    case IC_LITERAL:
        result = IC_VMOPERAND_V;
        break;
    case IC_STORAGE: {
        ic_vmStorage *acc = ic_vmStorageGet(program, (ic_storage)s);
        ic_storage base = acc->base ? acc->base->ic : NULL;
        ic_storageKind kind = ((ic_storage)s)->kind;
        cx_bool isReference = base ? ic_isReference(base) : ic_isReference((ic_storage)s);
        cx_bool isRefType = ((ic_storage)s)->type->reference;
        cx_bool isPrimitiveType = ((ic_storage)s)->type->kind == CX_PRIMITIVE;
        cx_bool isObject = kind == IC_OBJECT;
        cx_bool isStatic = acc->reusable && (!base || acc->base->reusable);

        if (acc->reusable && base && acc->base->reusable) {
            isObject = base->kind == IC_OBJECT;
        }
 
        switch(deref) {
        case IC_DEREF_ADDRESS:
            if (isObject) {
                if (!(base && isRefType)) {
                    result = IC_VMOPERAND_V;
                } else {
                    result = IC_VMOPERAND_P;
                }
            } else {
                if (isReference) {
                    if (base) {
                        if (!isRefType) {
                            result = IC_VMOPERAND_R;
                        } else {
                            result = IC_VMOPERAND_Q;
                        }
                    } else {
                        result = IC_VMOPERAND_R;
                    }
                } else {
                    if (isRefType) {
                        if (isStatic) {
                            result = IC_VMOPERAND_R;
                        } else {
                            result = IC_VMOPERAND_Q;
                        }
                    } else {
                        result = IC_VMOPERAND_X;
                    }
                }
            }
            break;
        case IC_DEREF_ARGUMENT:
        case IC_DEREF_VALUE:
            if (isObject) {
                /* When pushing either objects of a reference type or a non-primitive type,
                 * push object-address. */
                if ((deref == IC_DEREF_ARGUMENT) && (isRefType || !isPrimitiveType)) {
                    result = IC_VMOPERAND_V;

                /* When accessing non-reference primitive values, obtain value of object. */
                } else {
                    result = IC_VMOPERAND_P;
                }
            } else {
                if ((deref == IC_DEREF_ARGUMENT) && !isPrimitiveType && !isReference) {
                    if (isStatic) {
                        /* If value is not a primitive it must always be passed as reference. If the object is
                         * not already a reference, take the address of the register/local. */
                        result = IC_VMOPERAND_X;
                    } else {
                        result = IC_VMOPERAND_R;
                    }
                } else {
                    if (isStatic) {
                        if (!isRefType && isReference && isPrimitiveType) {
                            result = IC_VMOPERAND_Q; /* When a primitive type is a reference, it must have been passed as a reference
                                                         * parameter. Use Q to directly obtain the value of the reference. */
                        } else {
                            if (base && ic_isReference(base) && ((deref != IC_DEREF_ARGUMENT) || isRefType)) {
                                result = IC_VMOPERAND_Q;
                            } else {
                                result = IC_VMOPERAND_R;
                            }
                        }
                    } else {
                        /* When getting value of a non-static value (for example, member of a local) use Q */
                        result = IC_VMOPERAND_Q;
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

static cx_int16 ic_label_toVm(ic_label label, ic_vmProgram *program) {
    ic_vmLabel *lbl;

    if (program->program) {
        lbl = ic_vmLabelGet(program, label->id);
        lbl->pc = program->program->size;
    } else {
        cx_error("cannot add label to non-existing program");
        goto error;
    }

    return 0;
error:
    return -1;
}

cx_void *ic_valueValue(ic_vmProgram *program, ic_node s) {
    return ic_valueValue_width(program, s, NULL, 0);
}

#define GET_Q(op, code)\
    reg = c.qreg;\
    marker = (cx_word) & op##_##code;\
    reg = NULL;\
    marker = ((cx_uint32)marker == 0x1000000) ? 1 : ((cx_uint32)marker == 0x10000) ? 2 : -1

#define GET_P(op, code) marker = (cx_word) & op##_##code
#define GET_R(op, code) marker = (cx_word) & op##_##code
#define GET_V(op, code) marker = (cx_word) op##_##code
#define GET_A(op, code) marker = (cx_word) op##_##code

#define GETOPADDR1(type, arg, op1)\
    if ((IC_VMTYPE_##type == typeKind) && (IC_VMOPERAND_##op1 == op1Kind)) {\
        GET_##op1(op##arg, type##op1);\
    }

#define GETOPADDR2_1(type, _op1, _op2) GET_##_op1(op1, type##_op1##_op2)
#define GETOPADDR2_2(type, _op1, _op2) GET_##_op2(op2, type##_op1##_op2)
#define GETOPADDR2(type, arg, op1, op2)\
    if ((IC_VMTYPE_##type == typeKind) && (IC_VMOPERAND_##op1 == op1Kind) && (IC_VMOPERAND_##op2 == op2Kind)) {\
        GETOPADDR2_##arg(type, op1, op2);\
    }

#define GETOPADDR3_1(type, _op1, _op2, _op3) GET_##_op1(op1, type##_op1##_op2##_op3)
#define GETOPADDR3_2(type, _op1, _op2, _op3) GET_##_op2(op2, type##_op1##_op2##_op3)
#define GETOPADDR3_3(type, _op1, _op2, _op3) GET_##_op3(op3, type##_op1##_op2##_op3)
#define GETOPADDR3(type, arg, op1, op2, op3)\
    if ((IC_VMTYPE_##type == typeKind) && \
        (IC_VMOPERAND_##op1 == op1Kind) && \
        (IC_VMOPERAND_##op2 == op2Kind) && \
        (IC_VMOPERAND_##op3 == op3Kind)) {\
        GETOPADDR3_##arg(type, op1, op2, op3);\
    }

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

typedef struct ic_dummyEnv {
    _vmParameter16 ic;
    _vmParameter lo;
    _vmParameter hi;
    cx_uint64 dbl;
    cx_uint32 qreg[2];
} ic_dummyEnv;

/* Setup a dummy */
static ic_dummyEnv ic_getDummyEnv(void) {
    ic_dummyEnv c;
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
    c.qreg[0] = 0;
    c.qreg[1] = 1;
    return c;
}

/* Set operand */
static void ic_vmSetOp(
    ic_vmProgram *program, 
    cx_vmOp *op, 
    cx_word marker, 
    cx_uint32 size, 
    ic_vmOperand opKind, 
    ic_node v) {

    void *addr = NULL;

    /* Obtain operand address */
    switch ((cx_word)marker) {
    case 1: addr = &op->ic.b._1; break;
    case 2: addr = &op->ic.b._2; break;
    case 4: addr = &op->ic.s; break;
    case 7: addr = &op->lo.s.b._1; break;
    case 8: addr = &op->lo.s.b._2; break;
    case 11: addr = &op->hi.s.b._1; break;
    case 12: addr = &op->hi.s.b._2; break;
    case 13: addr = &op->lo; break;
    case 3: addr = &op->ic; break;
    case 5: addr = &op->lo.w; break;
    case 9: addr = &op->hi.w; break;
    default:
        cx_assert(0, "operand resolver returned invalid marker (%u)", marker);
        break;
    }

    /* Initialize operand to zero */
    memset(addr, 0, size);

    /* Set operand address */
    switch(opKind) {
    case IC_VMOPERAND_A:
        if (((ic_node)v)->kind == IC_LABEL) {
            ic_vmLabel *label;
            label = ic_vmLabelGet(program, *(cx_uint32*)ic_valueValue(program, v));
            ic_vmLabelAddReferee(program, label, addr);
            break;
        }
    case IC_VMOPERAND_V:{
        cx_float32 truncated;
        memcpy(addr, ic_valueValue_width(program, v, &truncated, size), size);
        break;
    }
    case IC_VMOPERAND_P:
        /* If storage is an object, copy address, otherwise calculate pointer + offset */
        if (((ic_storage)v)->kind == IC_OBJECT) {
            *(cx_object*)addr = *(cx_object*)ic_valueValue(program, v);
        } else {
            cx_object ptr;
            ic_vmStorage *acc;
            acc = ic_vmStorageGet(program, (ic_storage)v);
            ptr = ((ic_object)acc->base->ic)->ptr;
            *(cx_object*)addr = CX_OFFSET(ptr, acc->offset);
        }
        break;
    case IC_VMOPERAND_Q:
    case IC_VMOPERAND_R:
    case IC_VMOPERAND_X:
        if (v->kind == IC_STORAGE) {
            if (((ic_storage)v)->kind == IC_VARIABLE) {
                ic_vmStorage *local;
                local = ic_vmStorageGet(program, (ic_storage)v);
                *(cx_uint16*)addr = local->addr;
            } else if (((ic_storage)v)->kind == IC_ACCUMULATOR){
                ic_vmStorage *accumulator;
                accumulator = ic_vmStorageGet(program, (ic_storage)v);
                ic_vmStorageAddReferee(program, accumulator, addr);
            } else if ((((ic_storage)v)->kind == IC_MEMBER) || (((ic_storage)v)->kind == IC_ELEMENT)){
                ic_vmStorage *accumulator;
                accumulator = ic_vmStorageGet(program, (ic_storage)v);
                switch(accumulator->base->ic->kind) {
                case IC_VARIABLE:
                    if (accumulator->reusable && !ic_isReference(accumulator->base->ic)) {
                        *(cx_uint16*)addr = accumulator->base->addr + accumulator->offset;
                        break;
                    }

                case IC_MEMBER:
                case IC_ELEMENT:
                case IC_ACCUMULATOR:
                default:
                    ic_vmStorageAddReferee(program, accumulator, addr);
                    break;
                }
            }
        }
        break;
    default:
        cx_assert(0, "invalid operand kind");
        break;
    }
}

cx_uint32 ic_vmOpSize(ic_vmType typeKind, ic_vmOperand operand) {
    cx_uint32 result = 0;
    switch(typeKind) {
    case IC_VMTYPE_B: result = 1; break;
    case IC_VMTYPE_S: result = 2; break;
    case IC_VMTYPE_L: result = 4; break;
    case IC_VMTYPE_W: result = sizeof(cx_word); break;
    case IC_VMTYPE_D: result = 8; break;
    }

    switch(operand) {
    case IC_VMOPERAND_P: result = sizeof(cx_word); break;
    case IC_VMOPERAND_R: result = sizeof(cx_uint16); break;
    case IC_VMOPERAND_Q: result = sizeof(cx_uint16); break;
    case IC_VMOPERAND_A: result = sizeof(void*); break;
    default:
        break; 
    }

    return result;
}

/* Set operands for 1 operand instructions */
static void ic_vmSetOp1Addr(ic_vmProgram *program, cx_vmOp *op, ic_vmType typeKind, ic_vmOperand op1Kind, ic_node v1) {
    ic_dummyEnv c = ic_getDummyEnv();
    cx_uint32 *reg = NULL;
    cx_word marker = 0;
    op1Kind = op1Kind == IC_VMOPERAND_X ? IC_VMOPERAND_R : op1Kind;
    OP1_EXP(GETOPADDR1, 1, BSLDW, PQRV,,)
    OP1_EXP(GETOPADDR1, 1, W, A,,)
    ic_vmSetOp(program, op, marker, ic_vmOpSize(typeKind, op1Kind), op1Kind, v1);

}

/* Set operands for 2 operand instructions */
static void ic_vmSetOp2Addr(ic_vmProgram *program, cx_vmOp *op, ic_vmType typeKind, ic_vmOperand op1Kind, ic_vmOperand op2Kind, ic_node v1, ic_node v2) {
    ic_dummyEnv c = ic_getDummyEnv();
    cx_uint32 *reg = NULL;
    cx_word marker = 0;

    op1Kind = op1Kind == IC_VMOPERAND_X ? IC_VMOPERAND_R : op1Kind;
    op2Kind = op2Kind == IC_VMOPERAND_X ? IC_VMOPERAND_R : op2Kind;
    OP2_EXP(GETOPADDR2, 1, BSLDW, PQRV, PQRVA,,)
    ic_vmSetOp(program, op, marker, ic_vmOpSize(typeKind, op1Kind), op1Kind, v1);

    OP2_EXP(GETOPADDR2, 2, BSLDW, PQRV, PQRVA,,)
    ic_vmSetOp(program, op, marker, ic_vmOpSize(typeKind, op2Kind), op2Kind, v2);
}

/* Set operands for 3 operand instructions */
static void ic_vmSetOp3Addr(ic_vmProgram *program, cx_vmOp *op, ic_vmType typeKind, ic_vmOperand op1Kind, ic_vmOperand op2Kind, ic_vmOperand op3Kind, ic_node v1, ic_node v2, ic_node v3) {
    ic_dummyEnv c = ic_getDummyEnv();
    cx_uint32 *reg = NULL;
    cx_word marker = 0;
    op1Kind = op1Kind == IC_VMOPERAND_X ? IC_VMOPERAND_R : op1Kind;
    op2Kind = op2Kind == IC_VMOPERAND_X ? IC_VMOPERAND_R : op2Kind;
    op3Kind = op3Kind == IC_VMOPERAND_X ? IC_VMOPERAND_R : op3Kind;
    OP3_EXP(GETOPADDR3, 1, W, PQR, PQRV, PQRV,,)
    ic_vmSetOp(program, op, marker, ic_vmOpSize(typeKind, op1Kind), op1Kind, v1);
    OP3_EXP(GETOPADDR3, 2, W, PQR, PQRV, PQRV,,)
    ic_vmSetOp(program, op, marker, ic_vmOpSize(typeKind, op2Kind), op2Kind, v2);
    OP3_EXP(GETOPADDR3, 3, W, PQR, PQRV, PQRV,,)
    ic_vmSetOp(program, op, marker, ic_vmOpSize(typeKind, op3Kind), op3Kind, v3);
}

static ic_vmInlineFunction *ic_vmInlineFunctionNew(cx_vmProgram program, cx_function function) {
    ic_vmInlineFunction *result;

    result = cx_malloc(sizeof(ic_vmInlineFunction));
    result->program = program;
    result->function = function;

    return result;
}

static void ic_vmInlineFunctionMark(ic_vmProgram *program, cx_vmProgram vmProgram, cx_function function) {
    cx_iter inlineFunctionIter;
    ic_vmInlineFunction *inlineFunction = NULL;

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
        inlineFunction = ic_vmInlineFunctionNew(vmProgram, function);
        if (!program->inlineFunctions) {
            program->inlineFunctions = cx_llNew();
        }
        cx_llAppend(program->inlineFunctions, inlineFunction);
    }
}


/* --- GETOP pre & post actions */
#define TYPE_PRE(macro, arg, type, op1modes, op2modes, op3modes, n)\
static cx_vmOpKind ic_getVm##arg(cx_type t, ic_vmType typeKind, ic_vmOperand op1, ic_vmOperand op2, ic_vmOperand op3) {\
    cx_vmOpKind result = CX_VM_STOP;\
    CX_UNUSED(t);\
    CX_UNUSED(typeKind);\
    CX_UNUSED(op1);\
    CX_UNUSED(op2);\
    CX_UNUSED(op3);

#define TYPE_POST(macro, arg, type, op1modes, op2modes, op3modes, n)\
    return result;\
}
/* ---- */

/* ---- GETOP instruction selection expansions */
#define GETOP0(arg)\
static cx_vmOpKind ic_getVm##arg(cx_type t, ic_vmType typeKind, ic_vmOperand op1, ic_vmOperand op2, ic_vmOperand op3) {\
    CX_UNUSED(t);\
    CX_UNUSED(typeKind);\
    CX_UNUSED(op1);\
    CX_UNUSED(op2);\
    CX_UNUSED(op3);\
    return CX_VM_##arg;\
}

#define GETOP1(type, arg, _op1)\
    if ((typeKind == IC_VMTYPE_##type) && (op1 == IC_VMOPERAND_##_op1)) {\
        result = CX_VM_##arg##_##type##_op1;\
    }

#define GETOP1_COND(type, arg, _op1)\
    if ((typeKind == IC_VMTYPE_B) && (op1 == IC_VMOPERAND_##_op1)) {\
        result = CX_VM_##arg##B_##type##_op1;\
    }\
    if ((typeKind == IC_VMTYPE_S) && (op1 == IC_VMOPERAND_##_op1)) {\
        result = CX_VM_##arg##S_##type##_op1;\
    }\
    if ((typeKind == IC_VMTYPE_L) && (op1 == IC_VMOPERAND_##_op1)) {\
        result = CX_VM_##arg##L_##type##_op1;\
    }\
    if ((typeKind == IC_VMTYPE_D) && (op1 == IC_VMOPERAND_##_op1)) {\
        result = CX_VM_##arg##D_##type##_op1;\
    }

#define GETOP1_COND_LD(type, arg, _op1)\
    if ((typeKind == IC_VMTYPE_L) && (op1 == IC_VMOPERAND_##_op1)) {\
        result = CX_VM_##arg##L_##type##_op1;\
    }\
    if ((typeKind == IC_VMTYPE_D) && (op1 == IC_VMOPERAND_##_op1)) {\
        result = CX_VM_##arg##D_##type##_op1;\
    }


#define GETOP2(type, arg, _op1, _op2)\
    if ((IC_VMTYPE_##type == typeKind) && (IC_VMOPERAND_##_op1 == op1) && (IC_VMOPERAND_##_op2 == op2)) {\
        result = CX_VM_##arg##_##type##_op1##_op2;\
    }

#define GETOP3(type, arg, _op1, _op2, _op3)\
    if ((IC_VMTYPE_##type == typeKind) && (IC_VMOPERAND_##_op1 == op1) && (IC_VMOPERAND_##_op2 == op2) && (IC_VMOPERAND_##_op3 == op3)) {\
        CX_VM_##arg##_##type##_op1##_op2##_op3;\
    }
/* ---- */

/* ---- Expand instruction selection functions */
OPS_EXP_EXT(GETOP, TYPE,)


static cx_vmOp *ic_vmStorageAssembleElement(ic_storage storage, ic_vmProgram *program, cx_vmOp *vmOp, cx_bool topLevel) {
    cx_type type = storage->base->type;

    /* Obtain kind for index */
    if (type->kind == CX_ITERATOR) {
        ic_vmOperand baseKind = ic_getVmOperand(program, IC_DEREF_VALUE, ic_node(storage->base));
        vmOp->op = ic_getVmSET(type, IC_VMTYPE_D, IC_VMOPERAND_R, baseKind, 0);
        ic_vmSetOp2Addr(program, vmOp, IC_VMTYPE_W, IC_VMOPERAND_R, baseKind, 
            ic_node(storage), ic_node(storage->base));

    }else if (type->kind == CX_COLLECTION) {
        ic_node ic_elementSize;
        cx_uint64 elementSize;
        cx_collection collection = cx_collection(type);
        ic_vmOperand indexKind = ic_getVmOperand(program, IC_DEREF_VALUE, ((ic_element)storage)->index);

        /* Create value for elementSize */
        elementSize = cx_type_sizeof(collection->elementType);
        ic_elementSize = (ic_node)ic_literal__create((cx_any){cx_type(cx_uint32_o), &elementSize, FALSE});

        switch(collection->kind) {
        case CX_ARRAY:
            vmOp->op = ic_getVmELEMA(type, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, 0);
            ic_vmSetOp3Addr(program, vmOp, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, IC_VMOPERAND_V, ic_node(storage), ((ic_element)storage)->index, ic_elementSize);
            break;
        case CX_SEQUENCE:
            vmOp->op = ic_getVmELEMS(type, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, 0);
            ic_vmSetOp3Addr(program, vmOp, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, IC_VMOPERAND_V, ic_node(storage), ((ic_element)storage)->index, ic_elementSize);
            break;
        case CX_LIST:
            if (cx_collection_elementRequiresAlloc(collection) || !topLevel) {
                vmOp->op = ic_getVmELEML(type, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, 0);
            } else {
                vmOp->op = ic_getVmELEMLX(type, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, 0);
            }
            ic_vmSetOp2Addr(program, vmOp, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, ic_node(storage), ((ic_element)storage)->index);
            break;
        case CX_MAP:
            if (cx_collection_elementRequiresAlloc(collection) || !topLevel) {
                vmOp->op = ic_getVmELEMM(type, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, 0);
            } else {
                vmOp->op = ic_getVmELEMMX(type, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, 0);
            }
            ic_vmSetOp2Addr(program, vmOp, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, ic_node(storage), ((ic_element)storage)->index);
            break;
        }
    }

    return cx_vmProgram_addOp(program->program, 0);
}

static cx_vmOp *ic_vmStorageAssembleNested(ic_storage icStorage, ic_vmProgram *program, cx_vmOp *vmOp, cx_bool topLevel) {
    ic_vmStorage *storage = ic_vmStorageGet(program, icStorage);

    if (!storage->assembled && !storage->reusable) {
        if (storage->ic->kind == IC_MEMBER) {
            ic_storage base = storage->base->ic;
            cx_uint32 offset = storage->offset;

            /* Assemble base */
            vmOp = ic_vmStorageAssembleNested(base, program, vmOp, FALSE);

            if (storage->offset) {
                ic_vmStorage *vmBase = ic_vmStorageGet(program, base);

                if (vmBase->reusable) {
                    vmOp->op = ic_getVmMEMBER(NULL, 0, 0, 0, 0); /* Member instruction takes a destination, base and offset */
                    ic_vmStorageAddReferee(program, storage, &vmOp->ic.b._1);
                    if (base->kind == IC_VARIABLE) {
                        vmOp->ic.b._2 = storage->base->addr;
                    } else {
                        ic_vmStorageAddReferee(program, storage->base, &vmOp->ic.b._2);
                    }
                    vmOp->lo.w = offset;

                    /* todo : does the storage have to be reassembled */
                } else {
                    /* Calculate address at runtime by adding the offset to the base-address */
                    vmOp->op = CX_VM_ADDI_LRV;
                    if (storage->ic->kind == IC_VARIABLE) {
                        vmOp->ic.b._1 = storage->addr;
                    } else {
                        ic_vmStorageAddReferee(program, storage, &vmOp->ic.b._1);
                    }

                    vmOp->lo.w = offset;
                }

                /* Give new operation to assembler */
                vmOp = cx_vmProgram_addOp(program->program, 0);
            }
        } else if (storage->ic->kind == IC_ELEMENT) {
            ic_storage base = storage->base->ic;
            ic_vmStorage *vmStorage = ic_vmStorageGet(program, icStorage);

            /* Assemble base */
            vmOp = ic_vmStorageAssembleNested(base, program, vmOp, FALSE);

            /* If element is reusable the address can be determined at compile-time. When the element
             * is not reusable the address will be calculated at runtime. */
            if (!storage->reusable || ic_isReference(storage->base->ic)) {
                /* If the base is an object store the address in the accumulator */
                if (base->type->kind != CX_ITERATOR) {
                    if (base->kind == IC_OBJECT) {
                        vmOp->op = sizeof(intptr_t) == 4 ? CX_VM_SET_LRV : CX_VM_SET_DRV;
                        ic_vmStorageAddReferee(program, vmStorage, &vmOp->ic.b._1);
                        vmOp->lo.w = (intptr_t)((ic_object)base)->ptr;
                        if (storage->offset) {
                            vmOp->lo.w += storage->offset;
                        }
                        vmOp = cx_vmProgram_addOp(program->program, 0);

                    /* If the base is a local store the address of the local in the accumulator */
                    } else if (base->kind == IC_VARIABLE) {
                        if (!ic_isReference(storage->base->ic)) {
                            vmOp->op = ic_getVmSETX(NULL, IC_VMTYPE_W, IC_VMOPERAND_R, IC_VMOPERAND_R, 0);
                            ic_vmStorageAddReferee(program, vmStorage, &vmOp->ic.b._1);
                            vmOp->ic.b._2 = storage->base->addr;
                            if (storage->offset) {
                                vmOp->ic.b._2 += storage->offset;
                            }
                            vmOp = cx_vmProgram_addOp(program->program, 0);
                        } else {
                            vmOp->op = sizeof(intptr_t) == 4 ? CX_VM_SET_LRR : CX_VM_SET_DRR;
                            ic_vmStorageAddReferee(program, vmStorage, &vmOp->ic.b._1);
                            vmOp->ic.b._2 = storage->base->addr;
                            vmOp = cx_vmProgram_addOp(program->program, 0);
                        }
                    }
                }

                /* Insert element-instruction */
                vmOp = ic_vmStorageAssembleElement(icStorage, program, vmOp, topLevel);
            }
        }
    }

    return vmOp;
}

static cx_vmOp *ic_vmStorageAssemble(ic_storage icStorage, ic_vmProgram *program, cx_vmOp *vmOp) {
    return ic_vmStorageAssembleNested(icStorage, program, vmOp, TRUE);
}

/* Returns which operations have support for the W-operand type */
static cx_bool ic_supportsVmWordType(ic_opKind kind) {
    cx_bool result = FALSE;
    switch(kind) {
    case ic_strcat:
    case ic_strcpy:
    case ic_new: 
    case ic_free:
    case ic_keep:
    case ic_define:
    case ic_update:
    case ic_updateend:
    case ic_updatebegin: 
    case ic_updatecancel:
    case ic_waitfor:
    case ic_wait:
        result = TRUE;
        break;
    default:
        break;
    }
    return result;
}

static ic_vmType cx_vmTranslateVmType(ic_opKind kind, ic_vmType type) {
    if (!ic_supportsVmWordType(kind) && (type == IC_VMTYPE_W)) {
        if (sizeof(intptr_t) == 4) {
            type = IC_VMTYPE_L;
        } else if (sizeof(intptr_t) == 8) {
            type = IC_VMTYPE_D;
        }else {
            cx_assert(0, "Architecture not supported");
        }
    }
    return type;
}

static cx_vmOpKind ic_getVmCast(ic_vmProgram *program, ic_op op, cx_type t, ic_vmType typeKind, ic_vmOperand storage, ic_vmOperand op1) {
    cx_type srcType, dstType;
    cx_vmOpKind result = ic_getVmSTOP(NULL, 0, 0, 0, 0);

    CX_UNUSED(op);
    CX_UNUSED(t);

    dstType = *(cx_type*)ic_valueValue(program, op->s3);
    srcType = ic_valueType(op->s2);

    if (srcType->kind == dstType->kind) {
        if (srcType->kind == CX_PRIMITIVE) {
            result = ic_getVmPCAST(t, typeKind, storage, op1, 0);
        } else {
            if (srcType->reference) {
                result = ic_getVmCAST(t, IC_VMTYPE_W, storage, IC_VMOPERAND_V, 0);
            } else {
                /* No cast for non-reference types */
            }
        }

    } else if ((dstType->kind == CX_PRIMITIVE) && (cx_primitive(dstType)->kind == CX_BOOLEAN)) {
        if (((ic_storage)op->s3)->isReference) {
            result = ic_getVmPCAST(t, typeKind, storage, op1, 0);
        }
    } else if ((srcType->kind == CX_VOID) && srcType->reference) {
        result = ic_getVmCAST(t, IC_VMTYPE_W, storage, IC_VMOPERAND_V, 0);
    }
    {
        cx_id id1, id2;
        cx_assert(result != CX_VM_STOP, "no cast-instruction found from type '%s' to '%s'", cx_fullname(srcType, id1), cx_fullname(dstType, id2));
    }

    return result;
}

static cx_vmOpKind ic_getVmFree(ic_op op, cx_type t, ic_vmType typeKind, ic_vmOperand op1) {
    cx_vmOpKind result = CX_VM_STOP;
    CX_UNUSED(t);
    CX_UNUSED(typeKind);

    if (((ic_storage)op->s1)->isReference) {
        result = ic_getVmFREE(t, IC_VMTYPE_W, op1, 0, 0);
    } else {
        result = ic_getVmDEALLOC(t, IC_VMTYPE_W, op1, 0, 0);
    }

    return result;
}

/* Return correct SET instruction. Selects between 
 * normal, string and reference assignments. */
static cx_vmOpKind ic_getVmSet(
    cx_type t, 
    ic_storage op, 
    ic_vmType *typeKind, 
    ic_vmOperand *op1, 
    ic_vmOperand *op2, 
    ic_derefKind deref1, 
    ic_derefKind deref2) {
    cx_vmOpKind result;
    
    CX_UNUSED(deref2);

    /* Accummulators are only meant as temporary storage and therefore don't do resource management */
    if (op->kind == IC_ACCUMULATOR) {
        /* Translate type - it can be W */
        *typeKind = cx_vmTranslateVmType(ic_set, *typeKind);
        result = ic_getVmSET(t, *typeKind, *op1, *op2, 0);
    } else {
        /*printf("op1->isReference=%d, deref1==address=%d, deref2==address=%d, *typeKind=%d, *op1=%d, *op2=%d\n",
               op1->isReference, deref1==IC_DEREF_ADDRESS, deref2==IC_DEREF_ADDRESS, *typeKind, *op1, *op2);*/
        if ((deref1 == IC_DEREF_ADDRESS) || (deref2 == IC_DEREF_ADDRESS)) {
            *typeKind = IC_VMTYPE_W;
            result = ic_getVmSETREF(t, *typeKind, *op1, *op2, 0);
        } else {
            if ((t->kind == CX_PRIMITIVE) && (cx_primitive(t)->kind == CX_TEXT)) {
                *typeKind = IC_VMTYPE_W;
                result = ic_getVmSETSTRDUP(t, *typeKind, *op1, *op2, 0);
            } else if (t->kind == CX_ITERATOR) {
                *typeKind = IC_VMTYPE_W;
                result = ic_getVmITER_SET(t, *typeKind, *op1, *op2, 0);
            } else {
                result = ic_getVmSET(t, *typeKind, *op1, *op2, 0);
            }
        }
    }

    return result;
}

static cx_bool ic_operandIsComposite(ic_storage s, cx_compositeKind kind) {
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
static cx_vmOpKind ic_getVmCall(ic_op op, ic_vmOperand op1, ic_vmOperand op2) {
    cx_vmOpKind result = CX_VM_STOP;
    ic_storage ic_function = ((ic_storage)op->s2);

    if (ic_operandIsComposite(ic_function, CX_DELEGATE)) {
        result = ic_getVmCALLPTR(NULL, IC_VMTYPE_W, op1, op2, 0);
    } else if (ic_operandIsComposite(ic_function, CX_PROCEDURE)) {
        cx_function f = ((ic_object)op->s2)->ptr;
        if (f->kind == CX_PROCEDURE_VM) {
            if ((f->returnType->kind == CX_VOID) && 
                (!f->returnType->reference)) {
                result = ic_getVmCALLVMVOID(NULL, 0, 0, 0, 0);
            } else {
                result = ic_getVmCALLVM(NULL, IC_VMTYPE_W, op1, 0, 0);
            }
        } else {
            if ((f->returnType->kind == CX_VOID) && 
                (!f->returnType->reference)) {
                result = ic_getVmCALLVOID(NULL, 0, 0, 0, 0);
            } else {
                result = ic_getVmCALL(NULL, IC_VMTYPE_W, op1, 0, 0);
            }
        }
    }

    return result;   
}

static cx_vmOpKind ic_getVmPush(ic_op op, cx_type t, ic_vmType *typeKind, ic_vmOperand *op1, ic_vmOperand *op2) {
    cx_vmOpKind result = CX_VM_STOP;

    if (op->s1Any) {
        if (op->s1->kind == IC_LITERAL) {
            *op2 = IC_VMOPERAND_A;
            result = ic_getVmPUSHANYV(t, *typeKind, *op1, *op2, 0);
        } else if (*op1 == IC_VMOPERAND_X) {
            *op1 = *op1 == IC_VMOPERAND_X ? IC_VMOPERAND_R : *op1;
            *op2 = IC_VMOPERAND_A;
            result = ic_getVmPUSHANYX(t, *typeKind, *op1, *op2, 0);
        } else {
            *typeKind = IC_VMTYPE_W;
            *op2 = IC_VMOPERAND_A;
            result = ic_getVmPUSHANY(t, *typeKind, *op1, *op2, 0);
        }
    } else {
        if (*op1 != IC_VMOPERAND_X) {
            result = ic_getVmPUSH(t, *typeKind, *op1, 0, 0);
        } else {
            *op1 = IC_VMOPERAND_R;
            result = ic_getVmPUSHX(t, *typeKind, *op1, 0, 0);
        }
    }
    
    return result;
}

#define ic_getVmArith(op, t, typeKind, op1, op2)\
{\
    if (t->kind == CX_PRIMITIVE) {\
        switch(cx_primitive(t)->kind) {\
        case CX_ENUM:\
        case CX_INTEGER:\
        case CX_BINARY:\
        case CX_CHARACTER:\
        case CX_UINTEGER:\
            result = ic_getVm##op##I(t, typeKind, op1, op2, 0);\
            break;\
        case CX_FLOAT:\
            result = ic_getVm##op##F(t, typeKind, op1, op2, 0);\
            break;\
        default:{\
            cx_id id;\
            cx_assert(0, "conditional operation " #op " works only for numeric primitives (got %s)", cx_fullname(t, id));\
            break;\
        }\
        }\
    } else {\
        cx_assert(0, "conditional operation " #op " works only for primitive types");\
    }\
}

#define ic_getVmSign(op, t, typeKind, op1)\
{\
    if (t->kind == CX_PRIMITIVE) {\
        switch(cx_primitive(t)->kind) {\
        case CX_ENUM:\
        case CX_INTEGER:\
            result = ic_getVm##op##I(t, typeKind, op1, 0, 0);\
            break;\
        case CX_BINARY:\
        case CX_CHARACTER:\
        case CX_UINTEGER:\
            result = ic_getVm##op##U(t, typeKind, op1, 0, 0);\
            break;\
        case CX_FLOAT:\
            result = ic_getVm##op##F(t, typeKind, op1, 0, 0);\
            break;\
        default:{\
            cx_id id;\
            cx_assert(0, "conditional operation " #op " works only for INTEGER, UINTEGER and FLOAT primitives (got %s)", cx_fullname(t, id));\
            break;\
        }\
        }\
    } else {\
        cx_assert(0, "conditional operation " #op " works only for primitive types");\
    }\
}

static cx_vmOpKind ic_getVmInc(ic_op op, cx_type t, ic_vmType *typeKind, ic_vmOperand *op1, ic_vmOperand *op2) {
    cx_vmOpKind result = CX_VM_STOP;

    if (((ic_storage)op->s1)->type->kind == CX_ITERATOR) {
        *typeKind = IC_VMTYPE_W;
        result = ic_getVmITER_NEXT(t, *typeKind, *op2, *op1, 0);
    } else {
        result = ic_getVmINC(t, *typeKind, *op1, 0, 0);
    }
    return result;
}

static cx_vmOpKind ic_getVmOpKind(ic_vmProgram *program, ic_op op, ic_node storage, cx_type t, ic_vmType *typeKind_out, ic_vmOperand *op1_out, ic_vmOperand *op2_out, ic_derefKind deref1, ic_derefKind deref2) {
    cx_vmOpKind result = CX_VM_STOP;
    ic_vmType typeKind = IC_VMTYPE_D;
    ic_vmOperand op1 = IC_VMOPERAND_NONE, op2 = IC_VMOPERAND_NONE;

    if (typeKind_out) {
        typeKind = *typeKind_out;
    }
    if (op1_out) {
        op1 = *op1_out;
    }
    if (op2_out) {
        op2 = *op2_out;
    }

    /* When there is no dedicated W-operation, switch to L or D based on architecture */
    typeKind = cx_vmTranslateVmType(op->kind, typeKind);

    switch(op->kind) {
    case ic_set: result = ic_getVmSet(t, (ic_storage)storage, &typeKind, &op1, &op2, deref1, deref2); break;
    case ic_cast:
        result = ic_getVmCast(program, op, t, typeKind,
                ic_getVmOperand(program, op->s1Deref, op->s1),
                ic_getVmOperand(program, op->s2Deref, op->s2));
        break;

    case ic_strcat: result = ic_getVmSTRCAT(t, typeKind, op1, op2, 0); break;
    case ic_strcpy: result = ic_getVmSTRCPY(t, typeKind, op1, op2, 0); break;
    case ic_add: ic_getVmArith(ADD, t, typeKind, op1, op2); break;
    case ic_sub: ic_getVmArith(SUB, t, typeKind, op1, op2); break;
    case ic_mul: ic_getVmArith(MUL, t, typeKind, op1, op2); break;
    case ic_div: ic_getVmArith(DIV, t, typeKind, op1, op2); break;
    case ic_mod: result = ic_getVmMODI(t, typeKind, op1, op2, 0); break;
    case ic_inc: result = ic_getVmInc(op, t, &typeKind, &op1, &op2); break;
    case ic_dec: result = ic_getVmDEC(t, typeKind, op1, 0, 0); break;
    case ic_xor: result = ic_getVmXOR(t, typeKind, op1, op2, 0); break;
    case ic_or: result = ic_getVmOR(t, typeKind, op1, op2, 0); break;
    case ic_and: result = ic_getVmAND(t, typeKind, op1, op2, 0); break;
    case ic_not: result = ic_getVmNOT(t, typeKind, op1, 0, 0); break;
    case ic_shift_left: result = ic_getVmSHIFT_LEFT(t, typeKind, op1, op2, 0); break;
    case ic_shift_right: result = ic_getVmSHIFT_RIGHT(t, typeKind, op1, op2, 0); break;
    case ic_cond_or: result = ic_getVmCOR(t, typeKind, op1, 0, 0); break;
    case ic_cond_and: result = ic_getVmCAND(t, typeKind, op1, 0, 0); break;
    case ic_cond_not: result = ic_getVmCNOT(t, typeKind, op1, 0, 0); break;
    case ic_cond_eq: {
        if ((t->kind == CX_PRIMITIVE) && (cx_primitive(t)->kind == CX_TEXT)) {
            result = ic_getVmCEQSTR(t, IC_VMTYPE_B, op1, 0, 0);
        } else {
            result = ic_getVmCEQ(t, typeKind, op1, 0, 0);
        }
        break;
    }
    case ic_cond_neq: {
        if ((t->kind == CX_PRIMITIVE) && (cx_primitive(t)->kind == CX_TEXT)) {
            result = ic_getVmCNEQSTR(t, IC_VMTYPE_B, op1, 0, 0);
        } else {
            result = ic_getVmCNEQ(t, typeKind, op1, 0, 0);
        }
        break;
    }
    case ic_cond_gt: ic_getVmSign(CGT, t, typeKind, op1); break;
    case ic_cond_lt: ic_getVmSign(CLT, t, typeKind, op1); break;
    case ic_cond_gteq: ic_getVmSign(CGTEQ, t, typeKind, op1); break;
    case ic_cond_lteq: ic_getVmSign(CLTEQ, t, typeKind, op1); break;
    case ic_jump: result = ic_getVmJUMP(t, IC_VMTYPE_W, IC_VMOPERAND_A, 0, 0); break;
    case ic_jeq: result = ic_getVmJEQ(t, typeKind, op1, IC_VMOPERAND_A, 0); break;
    case ic_jneq: result = ic_getVmJNEQ(t, typeKind, op1, IC_VMOPERAND_A, 0); break;
    case ic_stop: result = CX_VM_STOP; break;
    case ic_push: result = ic_getVmPush(op, t, &typeKind, &op1, &op2); break;
    case ic_call: result = ic_getVmCall(op, op1, op2); break;

    case ic_ret:
        if (cx_type_sizeof(t) <= 8) {
            if (cx_type_sizeof(t) == 8) {
                result = ic_getVmRET(t, IC_VMTYPE_D, op1, 0, 0);
            } else {
                result = ic_getVmRET(t, typeKind, op1, 0, 0);
            }
        } else {
            result = ic_getVmRETCPY(t, IC_VMTYPE_L, op1, 0, 0);
        }
        break;

    case ic_new: result = ic_getVmNEW(t, typeKind, op1, op2, 0); break;
    case ic_free: result = ic_getVmFree(op, t, typeKind, op1); break;
    case ic_keep: result = ic_getVmKEEP(t, typeKind, op1, 0, 0); break;
    case ic_define: result = ic_getVmDEFINE(t, typeKind, op1, 0, 0); break;
    case ic_update:
        if (op->s2) {
            result = ic_getVmUPDATEFROM(t, typeKind, op1, op2, 0);
        } else {
            result = ic_getVmUPDATE(t, typeKind, op1, 0, 0);
        }
        break;

    case ic_updateend:
        if (op->s2) {
            result = ic_getVmUPDATEENDFROM(t, typeKind, op1, op2, 0);
        } else {
            result = ic_getVmUPDATEEND(t, typeKind, op1, 0, 0);
        }
        break;

    case ic_updatebegin: result = ic_getVmUPDATEBEGIN(t, typeKind, op1, 0, 0); break;
    case ic_updatecancel: result = ic_getVmUPDATECANCEL(t, typeKind, op1, 0, 0); break;
    case ic_waitfor: result = ic_getVmWAITFOR(t, typeKind, op1, 0, 0); break;
    case ic_wait: result = ic_getVmWAIT(t, typeKind, op1, op2, 0); break;
    default:
        cx_assert(0, "invalid intermediate op-code");
        break;
    }

    if ((result == CX_VM_STOP) && (op->kind != ic_stop)) {
        cx_error("%s:%d: invalid instruction generated => %s", 
            program->icProgram->filename, op->line, ic_op__str(op));
    }

    if (typeKind_out) {
        *typeKind_out = typeKind;
    }
    if (op1_out) {
        *op1_out = op1;
    }
    if (op2_out) {
        *op2_out = op2;
    }

    return result;
}

/* Get type and storage kind for operands and assemble operand when necessary (in case an
 * offset-instruction has to be inserted for a dynamically allocated object). */
static cx_vmOp* cx_vmGetTypeAndAssemble(

    /* In parameters */
    ic_vmProgram *program, 
    cx_vmOp *vmOp, 
    cx_bool threeOperands, 
    ic_node storage, 
    ic_node op1, 
    ic_node op2, 
    ic_derefKind storageDeref, 
    ic_derefKind opDeref1, 
    ic_derefKind opDeref2,

    /* Out parameters */
    cx_type *t, 
    ic_vmType *type, 
    ic_vmOperand *storageKind, 
    ic_vmOperand *opKind1, 
    ic_vmOperand *opKind2) {
    
    if (op1) {
        *opKind1 = ic_getVmOperand(program, opDeref1, op1);
        *t = ic_valueType(op1);
        
        if (!threeOperands) {
            *type = ic_getVmType(op1, opDeref1);
        } else {
            *type = IC_VMTYPE_W;
        }
        if (((ic_node)op1)->kind == IC_STORAGE) {
            vmOp = ic_vmStorageAssemble((ic_storage)op1, program, vmOp);
        }
    }
    if (op2) {
        if (((ic_node)op2)->kind == IC_STORAGE) {
            if (op2 != op1) {
                vmOp = ic_vmStorageAssemble((ic_storage)op2, program, vmOp);
            }
        }
        *opKind2 = ic_getVmOperand(program, opDeref2, op2);
    }
    if (storage) {
        if (((ic_node)storage)->kind == IC_STORAGE) {
            if ((storage != op1) && (storage != op2))
                vmOp = ic_vmStorageAssemble((ic_storage)storage, program, vmOp);
        }
        *storageKind = ic_getVmOperand(program, storageDeref, storage);
    }
    
    return vmOp;
}

/* Instruction without operands */
static void cx_vmOp0(ic_vmProgram *program, cx_vmOp *vmOp, ic_op op, ic_node op1, ic_derefKind opDeref1) {
    cx_type t;
    ic_vmType type;
    ic_vmOperand opKind1;
    vmOp = cx_vmGetTypeAndAssemble(program, vmOp, FALSE, NULL, op1, NULL, 0, opDeref1, 0,  &t, &type, NULL, &opKind1, NULL);
    vmOp->op = ic_getVmOpKind(program, op, op1, NULL, NULL, NULL, NULL, 0, 0);
}

/* Instruction with one operand */
static void cx_vmOp1(ic_vmProgram *program, cx_vmOp *vmOp, ic_op op, ic_node op1, ic_derefKind opDeref1) {
    cx_type t;
    ic_vmType type;
    ic_vmOperand opKind1;
    vmOp = cx_vmGetTypeAndAssemble(program, vmOp, FALSE, NULL, op1, NULL, 0, opDeref1, 0,  &t, &type, NULL, &opKind1, NULL);
    vmOp->op = ic_getVmOpKind(program, op, op1, t, &type, &opKind1, NULL, opDeref1, 0);

    /* Set size of type in case return instruction needs to do a memcpy */ 
    if (op->kind == ic_ret) {
        vmOp->hi.w = cx_type_sizeof(t);
    }

    ic_vmSetOp1Addr(program, vmOp, type, opKind1, op1);
}

/* Instruction with one operand and one staged operand
 * Create extra operation. This will contain the actual operation while vmOp (it is first)
 * will contain a stage, which will stage the values for the conditional operation. The
 * reason to do this with a stage rather than with a set is that a conditional operation has
 * a boolean value as a result, which can be of a different size than the operands.
 */
static void cx_vmOp1Staged(ic_vmProgram *program, cx_vmOp *vmOp, ic_op op, ic_node storage, ic_node op1, ic_derefKind storageDeref, ic_derefKind opDeref1) {
    cx_vmOp *vmStoredOp;
    cx_type t;
    ic_vmType type;
    ic_vmOperand opKind1, storageKind;

    vmOp = cx_vmGetTypeAndAssemble(program, vmOp, FALSE, storage, op1, NULL, storageDeref, opDeref1, 0,  &t, &type, &storageKind, &opKind1, NULL);
    type = cx_vmTranslateVmType(op->kind, type);
    vmOp->op = ic_getVmSTAGE1(t, type, opKind1, 0, 0);
    ic_vmSetOp1Addr(program, vmOp, type, opKind1, op1);
    
    vmStoredOp = cx_vmProgram_addOp(program->program, op->line);
    vmStoredOp->op = ic_getVmOpKind(program, op, op1, t, &type, &storageKind, &opKind1, storageDeref, opDeref1);
    ic_vmSetOp1Addr(program, vmStoredOp, type, storageKind, storage);
}

/* Instruction with two operands */
static void cx_vmOp2(ic_vmProgram *program, cx_vmOp *vmOp, ic_op op, ic_node op1, ic_node op2, ic_derefKind opDeref1, ic_derefKind opDeref2) {
    cx_type t;
    ic_vmType type;
    ic_vmOperand opKind1, opKind2;
    
    vmOp = cx_vmGetTypeAndAssemble(program, vmOp, FALSE, NULL, op1, op2, 0, opDeref1, opDeref2,  &t, &type, NULL, &opKind1, &opKind2);
    vmOp->op = ic_getVmOpKind(program, op, op1, t, &type, &opKind1, &opKind2, opDeref1, opDeref2);
    ic_vmSetOp2Addr(program, vmOp, type, opKind1, opKind2, op1, op2);
}

/* Instruction with two operands */
static void cx_vmOp3(ic_vmProgram *program, cx_vmOp *vmOp, ic_op op, ic_node op1, ic_node op2, ic_node op3, ic_derefKind opDeref1, ic_derefKind opDeref2, ic_derefKind opDeref3) {
    cx_type t;
    ic_vmType type;
    ic_vmOperand opKind1, opKind2;
    CX_UNUSED(opDeref3);
    
    vmOp = cx_vmGetTypeAndAssemble(program, vmOp, FALSE, NULL, op1, op2, 0, opDeref1, opDeref2,  &t, &type, NULL, &opKind1, &opKind2);

    vmOp->op = ic_getVmOpKind(program, op, op1, t, &type, &opKind1, &opKind2, opDeref1, opDeref2);
    ic_vmSetOp3Addr(program, vmOp, type, opKind1, opKind2, IC_VMOPERAND_V, op1, op2, op3);
}

/* Instruction with two operands and a storage
 * Create extra operation. This will contain the actual operation while vmOp (it is first)
 * will contain the set. The result of these two ops will look like:
 *
 * set  Storage Operand1 (vmOp)
 * [op] Storage Operand2 (vmStoredOp)
 * */
static void cx_vmOp2Storage(ic_vmProgram *program, cx_vmOp *vmOp, ic_op op, ic_node storage, ic_node op1, ic_node op2, ic_derefKind storageDeref, ic_derefKind opDeref1, ic_derefKind opDeref2) {
    cx_vmOp *vmStoredOp;
    cx_type t;
    ic_vmType type;
    ic_vmOperand opKind1, opKind2, storageKind;
    
    vmOp = cx_vmGetTypeAndAssemble(program, vmOp, FALSE, storage, op1, op2, storageDeref, opDeref1, opDeref2,  &t, &type, &storageKind, &opKind1, &opKind2);
    vmOp->op = ic_getVmSet(t, (ic_storage)storage, &type, &storageKind, &opKind1, storageDeref, opDeref1);
    ic_vmSetOp2Addr(program, vmOp, type, storageKind, opKind1, storage, op1);
    
    vmStoredOp = cx_vmProgram_addOp(program->program, op->line);
    vmStoredOp->op = ic_getVmOpKind(program, op, storage, t, &type, &storageKind, &opKind2, storageDeref, opDeref2);
    ic_vmSetOp2Addr(program, vmStoredOp, type, storageKind, opKind2, storage, op2);
}

/* Set-instruction with two operands and a storage
 * Create extra operation. This will contain a set-operation and an extra set-operation
 * to store the result of the first set in storage. The result of these two ops will look like:
 *
 * set  Operand1 Operand2 (vmOp)
 * set  Storage Operand1 (vmStoredOp)
 * */
static void cx_vmOp2Set(ic_vmProgram *program, cx_vmOp *vmOp, ic_op op, ic_node storage, ic_node op1, ic_node op2, ic_derefKind storageDeref, ic_derefKind opDeref1, ic_derefKind opDeref2) {
    cx_vmOp *vmStoredOp;
    cx_type t;
    ic_vmType type;
    ic_vmOperand opKind1, opKind2, storageKind;
    
    vmOp = cx_vmGetTypeAndAssemble(program, vmOp, FALSE, storage, op1, op2, storageDeref, opDeref1, opDeref2,  &t, &type, &storageKind, &opKind1, &opKind2);
    vmOp->op = ic_getVmSet(t, (ic_storage)op1, &type, &opKind1, &opKind2, opDeref1, opDeref2);
    ic_vmSetOp2Addr(program, vmOp, type, opKind1, opKind2, op1, op2);

    vmStoredOp = cx_vmProgram_addOp(program->program, op->line);
    vmStoredOp->op = ic_getVmSet(t, (ic_storage)storage, &type, &storageKind, &opKind1, storageDeref, opDeref1);
    ic_vmSetOp2Addr(program, vmStoredOp, type, storageKind, opKind1, storage, op1);
}

/* Instruction with two operands and two staged
 * Create extra operation. This will contain the actual operation while vmOp (it is first)
 * will contain a stage, which will stage the values for the conditional operation. The
 * reason to do this with a stage rather than with a set is that a conditional operation has
 * a boolean value as a result, which can be of a different size than the operands.
 */
static void cx_vmOp2Staged(ic_vmProgram *program, cx_vmOp *vmOp, ic_op op, ic_node storage, ic_node op1, ic_node op2, ic_derefKind storageDeref, ic_derefKind opDeref1, ic_derefKind opDeref2) {
    cx_vmOp *vmStoredOp;
    cx_type t;
    ic_vmType type;
    ic_vmOperand opKind1, opKind2, storageKind;
    
    vmOp = cx_vmGetTypeAndAssemble(program, vmOp, FALSE, storage, op1, op2, storageDeref, opDeref1, opDeref2,  &t, &type, &storageKind, &opKind1, &opKind2);
    type = cx_vmTranslateVmType(op->kind, type);

    vmOp->op = ic_getVmSTAGE2(t, type, opKind1, opKind2, 0);
    ic_vmSetOp2Addr(program, vmOp, type, opKind1, opKind2, op1, op2);
    
    vmStoredOp = cx_vmProgram_addOp(program->program, op->line);
    vmStoredOp->op = ic_getVmOpKind(program, op, storage, t, &type, &storageKind, &opKind1, storageDeref, opDeref1);
    ic_vmSetOp1Addr(program, vmStoredOp, type, storageKind, storage);
}

/* Cast instruction with either a reference cast or two staged types, a source and storage */
static void cx_vmOp2Cast(ic_vmProgram *program, cx_vmOp *vmOp, ic_op op, ic_node storage, ic_node op1, ic_node op2, ic_derefKind storageDeref, ic_derefKind opDeref1, ic_derefKind opDeref2) {
    cx_vmOp *vmStoredOp;
    cx_type sourceType, destinationType;
    ic_vmType type;
    ic_vmOperand opKind1, opKind2, storageKind;
    
    destinationType = ic_valueType(storage);
    
    /* If destinationType is a reference, insert regular 2-operand instruction */
    if (destinationType->reference) {
        cx_vmOp2Storage(program, vmOp, op, storage, op1, op2, storageDeref, opDeref1, opDeref2);
    /* If destinationType is not a reference, stage types and insert primitive cast */
    } else {
        vmOp = cx_vmGetTypeAndAssemble(program, vmOp, FALSE, storage, op1, op2, storageDeref, opDeref1, opDeref2,  &sourceType, &type, &storageKind, &opKind1, &opKind2);
        type = cx_vmTranslateVmType(op->kind, type);

        if (sizeof(intptr_t) == 4) {
            vmOp->op = CX_VM_STAGE2_LVV;
        } else if (sizeof(intptr_t) == 8) {
            vmOp->op = CX_VM_STAGE2_DVV;
        }

        if (op->s2Deref == IC_DEREF_ADDRESS) {
            vmOp->lo.w = (cx_word)cx_object_o;
        } else {
            vmOp->lo.w = (cx_word)sourceType;
        }
        vmOp->hi.w = (cx_word)destinationType;
        
        vmStoredOp = cx_vmProgram_addOp(program->program, op->line);
        vmStoredOp->op = ic_getVmOpKind(program, op, storage, sourceType, &type, &storageKind, &opKind1, storageDeref, opDeref1);
        ic_vmSetOp2Addr(program, vmStoredOp, type, storageKind, opKind1, storage, op1);
    }
}

static void ic_getVmOp(ic_vmProgram *program, ic_op op) {
    ic_derefKind opDeref1 = 0, opDeref2 = 0, opDeref3 = 0, storageDeref = 0;
    ic_node op1 = NULL, op2 = NULL, op3 = NULL, storage = NULL;
    cx_vmOp *vmOp;
    cx_bool stageOperands = FALSE;
    cx_bool castOperands = FALSE;

    /* Allocate operation */
    vmOp = cx_vmProgram_addOp(program->program, op->line);

    switch(op->kind) {
    /* Following operations do not have storage and one operand (op->s1 points to 1st operand) */
    case ic_update:
    case ic_updateend:
        /* Update-from parameter requires a 2nd operand */
        if (op->s2) {
            op2 = op->s2;
            opDeref2 = op->s2Deref;
        }
        /* no break */
    case ic_inc: {
        cx_type t = ((ic_storage)op->s1)->type;
        if (t->kind == CX_ITERATOR) {
            op2 = op->s2;
            op1 = op->s1;
            opDeref2 = op->s2Deref;
            opDeref1 = IC_DEREF_ADDRESS;
            storage = NULL;
            break;
        }
    }

    case ic_push:
        if (op->s1Any) {
            op2 = (ic_node)ic_address__create((cx_word)ic_valueType(op->s1));
            opDeref2 = IC_DEREF_ADDRESS;
        }
    case ic_define:
    case ic_dec:
    case ic_ret:
    case ic_free:
    case ic_keep:
    case ic_updatebegin:
    case ic_updatecancel:
    case ic_waitfor:
        op1 = op->s1;
        storage = NULL;
        opDeref1 = op->s1Deref;
        break;

    /* Following operations have one operand and a storage. This category is unusual but is used when the result has a different
     * type than the operands. */
    case ic_cond_not:
        stageOperands = TRUE;
        storage = op->s1;
        storageDeref = op->s1Deref;
        op1 = op->s2;
        opDeref1 = op->s2Deref;
        break;

    /* Following operations do not have storage and two operands (op->s1 to 1st, op->s2 to 2nd operand) */
    case ic_jeq:
    case ic_jneq:
    case ic_new:
    case ic_wait:
        op1 = op->s1;
        op2 = op->s2;
        storage = NULL;
        opDeref1 = op->s1Deref;
        opDeref2 = op->s2Deref;
        break;

    /* Jump sets jump address */
    case ic_jump: {
        ic_vmLabel *label;
        label = ic_vmLabelGet(program, *(cx_uint32*)ic_valueValue(program, op->s1));
        ic_vmLabelAddReferee(program, label, &vmOp->lo.w);
        op1 = NULL;
        op2 = NULL;
        storage = NULL;
        break;
    }

    case ic_set:
        if (ic_storage(op->s2)->type->kind == CX_ITERATOR) {
            ic_node op3value;
            op1 = op->s2;
            op2 = op->s3;
            op3value = (ic_node)ic_object__create(ic_storage(op->s3)->type);
            op3 = op3value;
            opDeref1 = op->s2Deref;
            opDeref2 = op->s3Deref;
            opDeref3 = IC_DEREF_ADDRESS;
        } else {
            op1 = op->s2;
            op2 = op->s3;
            storage = op->s1;
            opDeref1 = op->s2Deref;
            opDeref2 = op->s3Deref;
            storageDeref = op->s1Deref;
        }
        break;

    /* Call sets function address */
    case ic_call:
        if (ic_operandIsComposite((ic_storage)op->s2, CX_DELEGATE)) {
            op1 = op->s1;
            op2 = op->s2;
            opDeref1 = op->s1Deref;
            storage = NULL;
        } else {
            op1 = op->s1;
            storage = NULL;
            vmOp->hi.w = (cx_word)((ic_object)op->s2)->ptr;
            opDeref1 = op->s1Deref;
        }

        break;

    /* Cast */
    case ic_cast:
        castOperands = TRUE;

    /* no break */
    case ic_cond_or:
    case ic_cond_and:
    case ic_cond_eq:
    case ic_cond_neq:
    case ic_cond_gt:
    case ic_cond_gteq:
    case ic_cond_lt:
    case ic_cond_lteq:
        /* Conditional operations require staging */
        if (op->kind != ic_cast) {
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
            if (op3) {
                cx_vmOp3(program, vmOp, op, op1, op2, op3, opDeref1, opDeref2, opDeref3);
            } else if (storage && (storage != op1)) {
                /* If operation has a storage-operand, insert set-operation */
                if (op->kind == ic_set) {
                    cx_vmOp2Set(program, vmOp, op, storage, op1, op2, storageDeref, opDeref1, opDeref2);
                } else {
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

static cx_int16 ic_op_toVm(ic_op op, ic_vmProgram *program) {
    CX_UNUSED(program);

    if (!program->program) {
        program->program = cx_vmProgram_new(program->icProgram->filename, program->function->function);
    }

    /* If operation is push, increase stack-size */
    if (op->kind == ic_push) {
        if(op->s1Any) {
            program->stackSize += sizeof(cx_any);
        }else {
            cx_type t = ic_valueType(op->s1);
            program->stackSize += cx_type_sizeof(t);
        }
        if (program->stackSize > program->maxStackSize) {
            program->maxStackSize = program->stackSize;
        }
    }

    if (op->kind == ic_call) {
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
        if (((ic_storage)op->s2)->kind == IC_OBJECT) {
            cx_object o = ((ic_object)op->s2)->ptr;
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
                        ic_vmInlineFunctionMark(program, program->program, f);
                    }
                }
            }
        }

        /* Reset stacksize */
        program->stackSize = 0;
    }

    ic_getVmOp(program, op);

    return 0;
}

static cx_uint16 ic_vmProgram_push(ic_vmProgram *program) {
    cx_uint16 result = 0;

    if (program->scope) {
        result = program->scopeSize[program->scope - 1];
    }

    program->scope++;
    program->scopeSize[program->scope-1] = 0;

    return result;
}

static void ic_vmProgram_setScopeSize(ic_vmProgram *program, cx_uint16 size) {
    program->scopeSize[program->scope-1] = size;
    if (size > program->maxScopeSize) {
        program->maxScopeSize = size;
    }
}

static void ic_vmProgram_pop(ic_vmProgram *program) {
    program->scope--;
}

static void icZeroLocal(ic_vmProgram *program, cx_uint16 initStart, cx_uint16 size) {
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
        vmOp->op = ic_getVmZERO(NULL, IC_VMTYPE_W, IC_VMOPERAND_R, IC_VMOPERAND_V, 0);
        vmOp->ic.b._1 = initStart;
        vmOp->lo.w = size;
        break;
    }
}

static void icInitLocal(ic_vmProgram *program, cx_uint16 localAddr, cx_type type) {
    cx_vmOp *vmOp;
    
    vmOp = cx_vmProgram_addOp(program->program, 0);

    vmOp->op = ic_getVmINIT(NULL, IC_VMTYPE_W, IC_VMOPERAND_R, IC_VMOPERAND_V, 0);;
    vmOp->ic.b._1 = localAddr;
    vmOp->lo.w = (cx_word)type;
}

static cx_int16 ic_scope_toVm(ic_scope scope, ic_vmProgram *program) {
    cx_iter programIter, localIter;
    ic_node ic;
    cx_int16 result = 0;
    ic_storage storage = NULL, local = NULL;
    cx_uint16 size, initStart;
    ic_vmStorage *thisLocal = NULL;

    /* Push a new scope to the program. This manages an administration
     * which keeps track of how much memory each scope requires. */
    size = ic_vmProgram_push(program);

    /* Add locals to program */
    localIter = cx_llIter(scope->storages);
    initStart = size;
    while(cx_iterHasNext(&localIter)) {
        storage = cx_iterNext(&localIter);
        if (storage->kind == IC_VARIABLE) {
            ic_vmStorage *vmLocal;
            cx_bool zeroLocal = TRUE;
            local = storage;

            /* Lookup local in program */
            vmLocal = ic_vmStorageGet(program, local);

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

                if (((ic_variable)local)->isParameter) {
                    /* Parameters are not zero'd, so zero all locals up to this point */
                    if (initStart != size) {
                        icZeroLocal(program, initStart, size - initStart);
                    }
                    zeroLocal = FALSE;
                } else if (!local->isReference && (local->type->kind == CX_COLLECTION) && (cx_collection(local->type)->kind == CX_LIST)) {
                    icZeroLocal(program, initStart, size - initStart);
                    icInitLocal(program, size, local->type);
                    zeroLocal = FALSE;
                }

                /* Increase size */
                if (ic_isReference(local)) {
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
        if (!((ic_variable)local)->isParameter) {
            icZeroLocal(program, initStart, size - initStart);
        }
    }

    /* Set size of scope so that child-scopes know where there locals starts. */
    ic_vmProgram_setScopeSize(program, size);

    programIter = cx_llIter(scope->program);
    while(!result && cx_iterHasNext(&programIter)) {
        ic = cx_iterNext(&programIter);
        switch(ic->kind) {
        case IC_FUNCTION:
            ic_vmProgram_finalize(program);
            program->function = (ic_function)ic;
            break;
        case IC_STORAGE:
        case IC_LITERAL:
        case IC_ADDRESS:
            break;
        case IC_LABEL:
            result = ic_label_toVm((ic_label)ic, program);
            break;
        case IC_SCOPE:
            result = ic_scope_toVm((ic_scope)ic, program);
            break;
        case IC_OP:
            result = ic_op_toVm((ic_op)ic, program);
            break;
        }
    }

    ic_vmProgram_pop(program);

    return result;
}

cx_vmProgram ic_vmAssemble(ic_program program) {
    ic_vmProgram vmProgram;
    cx_iter functionIter;
    cx_function function;
    cx_iter inlineFunctionIter;
    ic_vmInlineFunction *inlineFunction;
    
    if (!program->errors) {
        /* Parse main-program */
        vmProgram.icProgram = program;
        vmProgram.main = cx_vmProgram_new(program->filename, NULL);
        vmProgram.program = vmProgram.main;
        vmProgram.function = NULL;
        vmProgram.labels = NULL;
        vmProgram.storages = NULL;
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
            function = ((ic_function)cx_iterNext(&functionIter))->function;
            function->kind = CX_PROCEDURE_VM;
        }

        /* Start assembling */
        if (ic_scope_toVm(program->scope, &vmProgram)) {
            goto error;
        }

        /* Finalize last program */
        ic_vmProgram_finalize(&vmProgram);

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



