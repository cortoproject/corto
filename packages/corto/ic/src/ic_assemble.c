#include "ic_node.h"
#include "corto.h"
#include "vm_operands.h"
#include "ic_vmProgram.h"
#include "ic_vmStorage.h"

corto_string ic_vmOperandStr(ic_vmOperand op) {
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

/* Determine whether storage is of a reference type or passed by reference. */
corto_bool ic_isReference(ic_storage storage) {
    corto_bool result = FALSE;

    if (storage->isReference) {
        result = TRUE;
    } else {
        if (storage->kind == IC_VARIABLE) {
            if (ic_variable(storage)->isParameter) {
                if (storage->type->kind != CORTO_PRIMITIVE) {
                    result = TRUE;
                }
            }
        }
    }

    return result;
}

static ic_vmLabel *ic_vmLabelNew(corto_uint32 id) {
    ic_vmLabel *result;

    result = corto_alloc(sizeof(ic_vmLabel));
    result->id = id;
    result->pc = 0;
    result->refereeCount = 0;

    return result;
}

static ic_vmLabel *ic_vmLabelGet(ic_vmProgram *program, corto_uint32 id) {
    corto_iter labelIter;
    ic_vmLabel *label = NULL;

    if (program->labels) {
        labelIter = corto_llIter(program->labels);
        while(corto_iterHasNext(&labelIter)) {
            label = corto_iterNext(&labelIter);
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
            program->labels = corto_llNew();
        }
        corto_llAppend(program->labels, label);
    }

    return label;
}

static void ic_vmLabelAddReferee(ic_vmProgram *program, ic_vmLabel *label, void *referee) {
    label->referees[label->refereeCount] = CORTO_OFFSET(referee, -(intptr_t)program->program->program);;
    corto_assert(label->refereeCount < 256, "unsupported number of references to one label (max is 256)");
    label->refereeCount++;
}

corto_type ic_valueType(ic_node s) {
    corto_type t = NULL;

    switch(s->kind) {
    case IC_LITERAL:
        t = ((ic_literal)s)->value.type;
        break;
    case IC_STORAGE:
        t = ((ic_storage)s)->type;
        break;
    default:
        corto_assert(0, "invalid operand type");
        break;
    }

    return t;
}

corto_void *ic_valueValue_width(ic_vmProgram *program, ic_node s, void* truncated, int width) {
    void *result = NULL;

    switch(s->kind) {
    case IC_LITERAL: {
        corto_any *v = &((ic_literal)s)->value;
        switch(v->type->kind) {
        case CORTO_PRIMITIVE:
            switch(corto_primitive(v->type)->kind) {
            case CORTO_BOOLEAN:
                *(corto_uint16*)truncated = *(corto_bool*)v->value;
                result = truncated;
                break;
            case CORTO_FLOAT:
                if (width == sizeof(corto_float32)) {
                    if (truncated) {
                        *(corto_float32*)truncated = *(corto_float64*)v->value;
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
            break;
        case CORTO_VOID:
            *(corto_word*)truncated = 0;
            result = truncated;
            break;
        default:
            corto_assert(0, "invalid ic_value type");
            break;
        }
        if (!result) {
            *(corto_word*)truncated = 0;
            result = truncated;
        }
        break;
    }

    case IC_STORAGE:
        switch(((ic_storage)s)->kind) {
        case IC_OBJECT:
            result = &((ic_object)s)->ptr;
            break;
        case IC_VARIABLE:
            corto_assert(0, "variable cannot be interpreted as a value");
            result = NULL;
            break;
        case IC_ACCUMULATOR:
            corto_assert(0, "accumulator cannot be interpreted as a value");
            result = NULL;
            break;
        case IC_MEMBER:
            if (((ic_storage)s)->base->kind == IC_OBJECT) {
                ic_vmStorage *vmStorage = ic_vmProgram_getStorage(program, (ic_storage)s);
                corto_object obj = ((ic_object)vmStorage->base->ic)->ptr;
                *(void**)truncated = CORTO_OFFSET(obj, ((ic_member)s)->member->offset);
                result = truncated;
            } else {
                corto_assert(0, "local/non reusable member '%s' cannot be interpreted as a value", ((ic_storage)s)->name);
            }
            break;
        case IC_ELEMENT:
            if (!((ic_element)s)->variableIndex) {
                ic_vmStorage *vmStorage = ic_vmProgram_getStorage(program, (ic_storage)s);
                corto_object obj = ((ic_object)vmStorage->base->ic)->ptr;
                *(void**)truncated = CORTO_OFFSET(obj, vmStorage->offset);
                result = truncated;
            } else {
                corto_assert(0, "local/non reusable member '%s' cannot be interpreted as a value", ((ic_storage)s)->name);
            }
            break;
        default:
            corto_assert(0, "invalid storage kind");
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
        corto_assert(0, "invalid operand type");
        break;
    }

    return result;
}

ic_vmType ic_getVmType(ic_node s, ic_derefKind deref) {
    ic_vmType result = IC_VMTYPE_B;
    corto_type t = ic_valueType(s);

    /* Determine VM type based on width of a type. If the value is
     * a storage and derefMode is value, the value is considered a
     * pointer and thus the type is W */
    if ((((ic_node)s)->kind == IC_STORAGE) && (deref == IC_DEREF_ADDRESS)) {
        result = IC_VMTYPE_W;
    } else {
        if (t->kind == CORTO_PRIMITIVE) {
            switch(corto_primitive(t)->width) {
            case CORTO_WIDTH_8:
                result = IC_VMTYPE_B;
                break;
            case CORTO_WIDTH_16:
                result = IC_VMTYPE_S;
                break;
            case CORTO_WIDTH_32:
                result = IC_VMTYPE_L;
                break;
            case CORTO_WIDTH_64:
                result = IC_VMTYPE_D;
                break;
            case CORTO_WIDTH_WORD:
                /* Reserve usage of W for pointer/string types */
                if (corto_primitive(t)->kind == CORTO_TEXT) {
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

ic_vmOperand ic_getVmOperand(ic_vmProgram *program, ic_derefKind deref, corto_bool isArgument, ic_node node) {
    ic_vmOperand result = IC_VMOPERAND_V;

    switch(node->kind) {
    case IC_LABEL:
    case IC_ADDRESS:
        result = IC_VMOPERAND_A;
        break;
    case IC_LITERAL:
        result = IC_VMOPERAND_V;
        break;
    case IC_STORAGE: {
        ic_storage s = ic_storage(node);
        ic_vmStorage *vmS = ic_vmProgram_getStorage(program, s);
        ic_storage base = vmS->base ? vmS->base->ic : NULL;
        corto_bool isPrimitive = s->type->kind == CORTO_PRIMITIVE;
        corto_bool isParameter = (s->kind == IC_VARIABLE) && (ic_variable(s)->isParameter);
        corto_bool baseIsParameter = base ? (base->kind == IC_VARIABLE) && (ic_variable(base)->isParameter) : FALSE;

        if (vmS->alwaysCompute) {
            if (isArgument && !isPrimitive) {
                result = IC_VMOPERAND_R;
            } else {
                result = IC_VMOPERAND_Q;
            }
        } else {
            switch(deref) {
            case IC_DEREF_ADDRESS:
                switch(s->kind) {
                case IC_OBJECT:
                    result = IC_VMOPERAND_V; /* var uint32& v = &object */
                    break;
                case IC_VARIABLE:
                case IC_ACCUMULATOR:
                    if (s->isReference || isParameter) {
                        result = IC_VMOPERAND_R; /* var uint32& w = &v */
                    } else {
                        result = IC_VMOPERAND_X;
                    }
                    break;
                case IC_MEMBER:
                case IC_ELEMENT:
                    if (base->kind == IC_OBJECT) {
                        if (!s->isReference) {
                            result = IC_VMOPERAND_V;
                        } else {
                            result = IC_VMOPERAND_P;
                        }
                    } else {
                        if (base->isReference || baseIsParameter) {
                            result = IC_VMOPERAND_Q;
                        } else {
                            result = IC_VMOPERAND_R;
                        }
                    }
                    break;
                }
                break;
            case IC_DEREF_VALUE:
                switch(s->kind) {
                case IC_OBJECT:
                    if (!isArgument || isPrimitive) {
                        result = IC_VMOPERAND_P; /* var uint32 v = object */
                    } else {
                        result = IC_VMOPERAND_V;
                    }
                    break;
                case IC_VARIABLE:
                case IC_ACCUMULATOR:
                    if (!isArgument) {
                        if (s->isReference) {
                            result = IC_VMOPERAND_Q; /* var uint32& v = ...; v = object */
                        } else {
                            result = IC_VMOPERAND_R; /* var uint32 v = 10 */
                        }
                    } else {
                        if (!s->isReference && !isPrimitive && !isParameter) {
                            result = IC_VMOPERAND_X;
                        } else if (s->isReference && isPrimitive) {
                            result = IC_VMOPERAND_Q;
                        } else {
                            result = IC_VMOPERAND_R;
                        }                        
                    }
                    break;
                case IC_MEMBER:
                case IC_ELEMENT:
                    if (base->kind == IC_OBJECT) {
                        if (!isArgument || isPrimitive) {
                            result = IC_VMOPERAND_P;
                        } else {
                            result = IC_VMOPERAND_V;
                        }
                    } else if (isArgument && !isPrimitive) {
                        if (base->isReference || baseIsParameter) {
                            result = IC_VMOPERAND_R;
                        } else {
                            result = IC_VMOPERAND_X;
                        }
                    } else {
                        if (base->isReference || baseIsParameter) {
                            result = IC_VMOPERAND_Q;
                        } else {
                            result = IC_VMOPERAND_R;
                        }                        
                    }
                }
                break;
            default:
                break;
            }
        }
        break;

        default:
            corto_assert(0, "invalid value-kind (%s)", ic_kindStr(node->kind));
            break;
        }
    }

    return result;
}

corto_void *ic_valueValue(ic_vmProgram *program, ic_node s) {
    return ic_valueValue_width(program, s, NULL, 0);
}

#define GET_Q(op, code)\
    reg = c.qreg;\
    marker = (corto_word) & op##_##code;\
    reg = NULL;\
    marker = ((corto_uint32)marker == 0x1000000) ? 1 : ((corto_uint32)marker == 0x10000) ? 2 : -1

#define GET_P(op, code) marker = (corto_word) & op##_##code
#define GET_R(op, code) marker = (corto_word) & op##_##code
#define GET_V(op, code) marker = (corto_word) op##_##code
#define GET_A(op, code) marker = (corto_word) op##_##code

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
    corto_uint64 dbl;
    corto_uint32 qreg[2];
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
    vm_op *op,
    corto_word marker,
    corto_uint32 size,
    ic_vmOperand opKind,
    ic_node v) {

    void *addr = NULL;

    /* Obtain operand address */
    switch ((corto_word)marker) {
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
        corto_assert(0, "operand resolver returned invalid marker (%u)", marker);
        break;
    }

    /* Initialize operand to zero */
    memset(addr, 0, size);

    /* Set operand address */
    switch(opKind) {
    case IC_VMOPERAND_A:
        if (((ic_node)v)->kind == IC_LABEL) {
            ic_vmLabel *label;
            label = ic_vmLabelGet(program, *(corto_uint32*)ic_valueValue(program, v));
            ic_vmLabelAddReferee(program, label, addr);
            break;
        }
    case IC_VMOPERAND_V:{
        corto_float32 truncated;
        memcpy(addr, ic_valueValue_width(program, v, &truncated, size), size);
        break;
    }
    case IC_VMOPERAND_P:
        /* If storage is an object, copy address, otherwise calculate pointer + offset */
        if (((ic_storage)v)->kind == IC_OBJECT) {
            *(corto_object*)addr = *(corto_object*)ic_valueValue(program, v);
        } else {
            ic_vmStorage *acc;
            acc = ic_vmProgram_getStorage(program, ic_storage(v));
            *(corto_object*)addr = (corto_object)acc->addr;
        }
        break;
    case IC_VMOPERAND_Q:
    case IC_VMOPERAND_R:
    case IC_VMOPERAND_X:
        if (v->kind == IC_STORAGE) {
            if (((ic_storage)v)->kind == IC_VARIABLE) {
                ic_vmStorage *local;
                local = ic_vmProgram_getStorage(program, (ic_storage)v);
                *(corto_uint16*)addr = local->addr;
            } else if (((ic_storage)v)->kind == IC_ACCUMULATOR){
                ic_vmStorage *accumulator;
                accumulator = ic_vmProgram_getStorage(program, (ic_storage)v);
                ic_vmStorageAddReferee(accumulator, program, addr);
            } else if ((((ic_storage)v)->kind == IC_MEMBER) || (((ic_storage)v)->kind == IC_ELEMENT)){
                ic_vmStorage *accumulator;
                accumulator = ic_vmProgram_getStorage(program, (ic_storage)v);
                switch(accumulator->base->ic->kind) {
                case IC_VARIABLE:
                    if (accumulator->reusable && !ic_isReference(accumulator->base->ic)) {
                        *(corto_uint16*)addr = accumulator->base->addr + accumulator->offset;
                        break;
                    }

                case IC_ACCUMULATOR:
                case IC_MEMBER:
                case IC_ELEMENT:
                default:
                    ic_vmStorageAddReferee(accumulator, program, addr);
                    break;
                }
            }
        }
        break;
    default:
        corto_assert(0, "invalid operand kind");
        break;
    }
}

corto_uint32 ic_vmOpSize(ic_vmType typeKind, ic_vmOperand operand) {
    corto_uint32 result = 0;
    switch(typeKind) {
    case IC_VMTYPE_B: result = 1; break;
    case IC_VMTYPE_S: result = 2; break;
    case IC_VMTYPE_L: result = 4; break;
    case IC_VMTYPE_W: result = sizeof(corto_word); break;
    case IC_VMTYPE_D: result = 8; break;
    }

    switch(operand) {
    case IC_VMOPERAND_P: result = sizeof(corto_word); break;
    case IC_VMOPERAND_R: result = sizeof(corto_uint16); break;
    case IC_VMOPERAND_Q: result = sizeof(corto_uint16); break;
    case IC_VMOPERAND_A: result = sizeof(void*); break;
    default:
        break;
    }

    return result;
}

/* Set operands for 1 operand instructions */
static void ic_vmSetOp1Addr(ic_vmProgram *program, vm_op *op, ic_vmType typeKind, ic_vmOperand op1Kind, ic_node v1) {
    ic_dummyEnv c = ic_getDummyEnv();
    corto_uint32 *reg = NULL;
    corto_word marker = 0;
    op1Kind = op1Kind == IC_VMOPERAND_X ? IC_VMOPERAND_R : op1Kind;
    OP1_EXP(GETOPADDR1, 1, BSLDW, PQRV,,)
    OP1_EXP(GETOPADDR1, 1, W, A,,)
    ic_vmSetOp(program, op, marker, ic_vmOpSize(typeKind, op1Kind), op1Kind, v1);

}

/* Set operands for 2 operand instructions */
void ic_vmSetOp2Addr(ic_vmProgram *program, vm_op *op, ic_vmType typeKind, ic_vmOperand op1Kind, ic_vmOperand op2Kind, ic_node v1, ic_node v2) {
    ic_dummyEnv c = ic_getDummyEnv();
    corto_uint32 *reg = NULL;
    corto_word marker = 0;

    op1Kind = op1Kind == IC_VMOPERAND_X ? IC_VMOPERAND_R : op1Kind;
    op2Kind = op2Kind == IC_VMOPERAND_X ? IC_VMOPERAND_R : op2Kind;
    OP2_EXP(GETOPADDR2, 1, BSLDW, PQRV, PQRVA,,)
    ic_vmSetOp(program, op, marker, ic_vmOpSize(typeKind, op1Kind), op1Kind, v1);

    OP2_EXP(GETOPADDR2, 2, BSLDW, PQRV, PQRVA,,)
    ic_vmSetOp(program, op, marker, ic_vmOpSize(typeKind, op2Kind), op2Kind, v2);
}

/* Set operands for 3 operand instructions */
void ic_vmSetOp3Addr(ic_vmProgram *program, vm_op *op, ic_vmType typeKind, ic_vmOperand op1Kind, ic_vmOperand op2Kind, ic_vmOperand op3Kind, ic_node v1, ic_node v2, ic_node v3) {
    ic_dummyEnv c = ic_getDummyEnv();
    corto_uint32 *reg = NULL;
    corto_word marker = 0;
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

static ic_vmInlineFunction *ic_vmInlineFunctionNew(vm_program program, corto_function function) {
    ic_vmInlineFunction *result;

    result = corto_alloc(sizeof(ic_vmInlineFunction));
    result->program = program;
    result->function = function;

    return result;
}

static void ic_vmInlineFunctionMark(ic_vmProgram *program, vm_program vmProgram, corto_function function) {
    corto_iter inlineFunctionIter;
    ic_vmInlineFunction *inlineFunction = NULL;

    if (program->labels) {
        inlineFunctionIter = corto_llIter(program->labels);
        while(corto_iterHasNext(&inlineFunctionIter)) {
            inlineFunction = corto_iterNext(&inlineFunctionIter);
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
            program->inlineFunctions = corto_llNew();
        }
        corto_llAppend(program->inlineFunctions, inlineFunction);
    }
}


/* --- GETOP pre & post actions */
#define TYPE_PRE(macro, arg, type, op1modes, op2modes, op3modes, n)\
vm_opKind ic_getVm##arg(corto_type t, ic_vmType typeKind, ic_vmOperand op1, ic_vmOperand op2, ic_vmOperand op3) {\
    vm_opKind result = CORTO_VM_STOP;\
    CORTO_UNUSED(t);\
    CORTO_UNUSED(typeKind);\
    CORTO_UNUSED(op1);\
    CORTO_UNUSED(op2);\
    CORTO_UNUSED(op3);

#define TYPE_POST(macro, arg, type, op1modes, op2modes, op3modes, n)\
    return result;\
}
/* ---- */

/* ---- GETOP instruction selection expansions */
#define GETOP0(arg)\
vm_opKind ic_getVm##arg(corto_type t, ic_vmType typeKind, ic_vmOperand op1, ic_vmOperand op2, ic_vmOperand op3) {\
    CORTO_UNUSED(t);\
    CORTO_UNUSED(typeKind);\
    CORTO_UNUSED(op1);\
    CORTO_UNUSED(op2);\
    CORTO_UNUSED(op3);\
    return CORTO_VM_##arg;\
}

#define GETOP1(type, arg, _op1)\
    if ((typeKind == IC_VMTYPE_##type) && (op1 == IC_VMOPERAND_##_op1)) {\
        result = CORTO_VM_##arg##_##type##_op1;\
    }

#define GETOP1_COND(type, arg, _op1)\
    if ((typeKind == IC_VMTYPE_B) && (op1 == IC_VMOPERAND_##_op1)) {\
        result = CORTO_VM_##arg##B_##type##_op1;\
    }\
    if ((typeKind == IC_VMTYPE_S) && (op1 == IC_VMOPERAND_##_op1)) {\
        result = CORTO_VM_##arg##S_##type##_op1;\
    }\
    if ((typeKind == IC_VMTYPE_L) && (op1 == IC_VMOPERAND_##_op1)) {\
        result = CORTO_VM_##arg##L_##type##_op1;\
    }\
    if ((typeKind == IC_VMTYPE_D) && (op1 == IC_VMOPERAND_##_op1)) {\
        result = CORTO_VM_##arg##D_##type##_op1;\
    }

#define GETOP1_COND_LD(type, arg, _op1)\
    if ((typeKind == IC_VMTYPE_L) && (op1 == IC_VMOPERAND_##_op1)) {\
        result = CORTO_VM_##arg##L_##type##_op1;\
    }\
    if ((typeKind == IC_VMTYPE_D) && (op1 == IC_VMOPERAND_##_op1)) {\
        result = CORTO_VM_##arg##D_##type##_op1;\
    }


#define GETOP2(type, arg, _op1, _op2)\
    if ((IC_VMTYPE_##type == typeKind) && (IC_VMOPERAND_##_op1 == op1) && (IC_VMOPERAND_##_op2 == op2)) {\
        result = CORTO_VM_##arg##_##type##_op1##_op2;\
    }

#define GETOP3(type, arg, _op1, _op2, _op3)\
    if ((IC_VMTYPE_##type == typeKind) && (IC_VMOPERAND_##_op1 == op1) && (IC_VMOPERAND_##_op2 == op2) && (IC_VMOPERAND_##_op3 == op3)) {\
        CORTO_VM_##arg##_##type##_op1##_op2##_op3;\
    }
/* ---- */

/* ---- Expand instruction selection functions */
OPS_EXP_EXT(GETOP, TYPE,)

/* Returns which operations have support for the W-operand type */
static corto_bool ic_supportsVmWordType(ic_opKind kind) {
    corto_bool result = FALSE;
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

static ic_vmType corto_vmTranslateVmType(ic_opKind kind, ic_vmType type) {
    if (!ic_supportsVmWordType(kind) && (type == IC_VMTYPE_W)) {
        if (sizeof(intptr_t) == 4) {
            type = IC_VMTYPE_L;
        } else if (sizeof(intptr_t) == 8) {
            type = IC_VMTYPE_D;
        }else {
            corto_assert(0, "Architecture not supported");
        }
    }
    return type;
}

static vm_opKind ic_getVmCast(ic_vmProgram *program, ic_op op, corto_type t, ic_vmType typeKind, ic_vmOperand storage, ic_vmOperand op1) {
    corto_type srcType, dstType;
    vm_opKind result = ic_getVmSTOP(NULL, 0, 0, 0, 0);

    CORTO_UNUSED(op);
    CORTO_UNUSED(t);

    dstType = *(corto_type*)ic_valueValue(program, op->s3);
    srcType = ic_valueType(op->s2);

    if (srcType->kind == dstType->kind) {
        if (srcType->kind == CORTO_PRIMITIVE) {
            result = ic_getVmPCAST(t, typeKind, storage, op1, 0);
        } else {
            if (srcType->reference) {
                result = ic_getVmCAST(t, IC_VMTYPE_W, storage, IC_VMOPERAND_V, 0);
            } else {
                /* No cast for non-reference types */
            }
        }

    } else if ((dstType->kind == CORTO_PRIMITIVE) && (corto_primitive(dstType)->kind == CORTO_BOOLEAN)) {
        if (((ic_storage)op->s3)->isReference) {
            if (!ic_storage(op->s1)->isReference) {
                result = ic_getVmPCAST(t, typeKind, storage, op1, 0);
            } else {
                result = ic_getVmCAST(t, IC_VMTYPE_W, IC_VMOPERAND_R, IC_VMOPERAND_V, 0);
            }
        }
    } else if ((srcType->kind == CORTO_VOID) && srcType->reference) {
        result = ic_getVmCAST(t, IC_VMTYPE_W, storage, IC_VMOPERAND_V, 0);
    }
    {
        corto_id id1, id2;
        corto_assert(result != CORTO_VM_STOP, "no cast-instruction found from type '%s' to '%s'", corto_fullname(srcType, id1), corto_fullname(dstType, id2));
    }

    return result;
}

static vm_opKind ic_getVmFree(ic_op op, corto_type t, ic_vmType typeKind, ic_vmOperand op1) {
    vm_opKind result = CORTO_VM_STOP;
    CORTO_UNUSED(t);
    CORTO_UNUSED(typeKind);

    if (((ic_storage)op->s1)->isReference) {
        result = ic_getVmFREE(t, IC_VMTYPE_W, op1, 0, 0);
    } else {
        result = ic_getVmDEALLOC(t, IC_VMTYPE_W, op1, 0, 0);
    }

    return result;
}

/* Return correct SET instruction. Selects between
 * normal, string and reference assignments. */
static vm_opKind ic_getVmSet(
    ic_vmProgram *program,
    corto_type t,
    ic_storage op,
    ic_vmType *typeKind,
    ic_vmOperand *op1,
    ic_vmOperand *op2,
    ic_derefKind deref1,
    ic_derefKind deref2) {
    vm_opKind result;
    ic_vmStorage *s = ic_vmProgram_getStorage(program, op);

    CORTO_UNUSED(deref2);

    /* Accummulators are only meant as temporary storage and therefore don't do resource management */
    if ((op->kind == IC_ACCUMULATOR) || (s->base && (s->base->ic->kind == IC_ACCUMULATOR))) {
        /* Translate type - it can be W */
        *typeKind = corto_vmTranslateVmType(ic_set, *typeKind);
        result = ic_getVmSET(t, *typeKind, *op1, *op2, 0);
    } else {
        if ((deref1 == IC_DEREF_ADDRESS) || (deref2 == IC_DEREF_ADDRESS)) {
            *typeKind = IC_VMTYPE_W;
            if (*op1 == IC_VMOPERAND_V) {
                *op1 = IC_VMOPERAND_P;
            }
            result = ic_getVmSETREF(t, *typeKind, *op1, *op2, 0);
        } else {
            if ((t->kind == CORTO_PRIMITIVE) && (corto_primitive(t)->kind == CORTO_TEXT)) {
                *typeKind = IC_VMTYPE_W;
                result = ic_getVmSETSTRDUP(t, *typeKind, *op1, *op2, 0);
            } else if (t->kind == CORTO_ITERATOR) {
                *typeKind = IC_VMTYPE_W;
                result = ic_getVmITER_SET(t, *typeKind, *op1, *op2, 0);
            } else {
                result = ic_getVmSET(t, *typeKind, *op1, *op2, 0);
            }
        }
    }

    return result;
}

static corto_bool ic_operandIsComposite(ic_storage s, corto_compositeKind kind) {
    corto_bool result = FALSE;
    if (s->type->kind == CORTO_COMPOSITE) {
        if (corto_interface(s->type)->kind == kind) {
            result = TRUE;
        }
    }
    return result;
}

/* Return correct CALL instruction. Selects between
 * normal, VM and delegate calls */
static vm_opKind ic_getVmCall(ic_op op, ic_vmOperand op1, ic_vmOperand op2) {
    vm_opKind result = CORTO_VM_STOP;
    ic_storage ic_function = ((ic_storage)op->s2);

    if (ic_operandIsComposite(ic_function, CORTO_DELEGATE)) {
        result = ic_getVmCALLPTR(NULL, IC_VMTYPE_W, op1, op2, 0);
    } else if (ic_operandIsComposite(ic_function, CORTO_PROCEDURE)) {
        corto_function f = ((ic_object)op->s2)->ptr;
        if (f->kind == CORTO_PROCEDURE_VM) {
            if ((f->returnType->kind == CORTO_VOID) &&
                (!f->returnType->reference)) {
                result = ic_getVmCALLVMVOID(NULL, 0, 0, 0, 0);
            } else {
                result = ic_getVmCALLVM(NULL, IC_VMTYPE_W, op1, 0, 0);
            }
        } else {
            if ((f->returnType->kind == CORTO_VOID) &&
                (!f->returnType->reference)) {
                result = ic_getVmCALLVOID(NULL, 0, 0, 0, 0);
            } else {
                result = ic_getVmCALL(NULL, IC_VMTYPE_W, op1, 0, 0);
            }
        }
    }

    return result;
}

static vm_opKind ic_getVmPush(ic_op op, corto_type t, ic_vmType *typeKind, ic_vmOperand *op1, ic_vmOperand *op2) {
    vm_opKind result = CORTO_VM_STOP;

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
    if (t->kind == CORTO_PRIMITIVE) {\
        switch(corto_primitive(t)->kind) {\
        case CORTO_ENUM:\
        case CORTO_INTEGER:\
        case CORTO_BINARY:\
        case CORTO_CHARACTER:\
        case CORTO_UINTEGER:\
            result = ic_getVm##op##I(t, typeKind, op1, op2, 0);\
            break;\
        case CORTO_FLOAT:\
            result = ic_getVm##op##F(t, typeKind, op1, op2, 0);\
            break;\
        default:{\
            corto_id id;\
            corto_assert(0, "conditional operation " #op " works only for numeric primitives (got %s)", corto_fullname(t, id));\
            break;\
        }\
        }\
    } else {\
        corto_assert(0, "conditional operation " #op " works only for primitive types");\
    }\
}

#define ic_getVmSign(op, t, typeKind, op1)\
{\
    if (t->kind == CORTO_PRIMITIVE) {\
        switch(corto_primitive(t)->kind) {\
        case CORTO_ENUM:\
        case CORTO_INTEGER:\
            result = ic_getVm##op##I(t, typeKind, op1, 0, 0);\
            break;\
        case CORTO_BINARY:\
        case CORTO_CHARACTER:\
        case CORTO_UINTEGER:\
            result = ic_getVm##op##U(t, typeKind, op1, 0, 0);\
            break;\
        case CORTO_FLOAT:\
            result = ic_getVm##op##F(t, typeKind, op1, 0, 0);\
            break;\
        default:{\
            corto_id id;\
            corto_assert(0, "conditional operation " #op " works only for INTEGER, UINTEGER and FLOAT primitives (got %s)", corto_fullname(t, id));\
            break;\
        }\
        }\
    } else {\
        corto_assert(0, "conditional operation " #op " works only for primitive types");\
    }\
}

static vm_opKind ic_getVmInc(ic_op op, corto_type t, ic_vmType *typeKind, ic_vmOperand *op1, ic_vmOperand *op2) {
    vm_opKind result = CORTO_VM_STOP;

    if (((ic_storage)op->s1)->type->kind == CORTO_ITERATOR) {
        *typeKind = IC_VMTYPE_W;
        result = ic_getVmITER_NEXT(t, *typeKind, *op2, *op1, 0);
    } else {
        result = ic_getVmINC(t, *typeKind, *op1, 0, 0);
    }
    return result;
}

static vm_opKind ic_getVmOpKind(ic_vmProgram *program, ic_op op, ic_node storage, corto_type t, ic_vmType *typeKind_out, ic_vmOperand *op1_out, ic_vmOperand *op2_out, ic_derefKind deref1, ic_derefKind deref2) {
    vm_opKind result = CORTO_VM_STOP;
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
    typeKind = corto_vmTranslateVmType(op->kind, typeKind);

    switch(op->kind) {
    case ic_set: result = ic_getVmSet(program, t, (ic_storage)storage, &typeKind, &op1, &op2, deref1, deref2); break;
    case ic_cast:
        result = ic_getVmCast(program, op, t, typeKind,
                ic_getVmOperand(program, op->s1Deref, FALSE, op->s1),
                ic_getVmOperand(program, op->s2Deref, FALSE, op->s2));
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
        if ((t->kind == CORTO_PRIMITIVE) && (corto_primitive(t)->kind == CORTO_TEXT)) {
            result = ic_getVmCEQSTR(t, IC_VMTYPE_B, op1, 0, 0);
        } else {
            result = ic_getVmCEQ(t, typeKind, op1, 0, 0);
        }
        break;
    }
    case ic_cond_neq: {
        if ((t->kind == CORTO_PRIMITIVE) && (corto_primitive(t)->kind == CORTO_TEXT)) {
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
    case ic_stop: result = CORTO_VM_STOP; break;
    case ic_push: result = ic_getVmPush(op, t, &typeKind, &op1, &op2); break;
    case ic_call: result = ic_getVmCall(op, op1, op2); break;

    case ic_ret:
        if (corto_type_sizeof(t) <= 8) {
            if (corto_type_sizeof(t) == 8) {
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
    case ic_init: result = ic_getVmINIT(t, IC_VMTYPE_W, op1, op2, 0); break;
    case ic_deinit: result = ic_getVmDEINIT(t, IC_VMTYPE_W, op1, op2, 0); break;
    default:
        corto_assert(0, "invalid intermediate op-code");
        break;
    }

    if ((result == CORTO_VM_STOP) && (op->kind != ic_stop)) {
        corto_error("%s:%d: instruction lookup failed for => %s %s %s",
            program->icProgram->filename, op->line,
            ic_opKindStr(op->kind),
            ic_derefKindStr(deref1),
            ic_derefKindStr(deref2));
        fprintf(stderr, "   type:      ");
        switch(typeKind) {
        case IC_VMTYPE_B: fprintf(stderr, "B"); break;
        case IC_VMTYPE_S: fprintf(stderr, "S"); break;
        case IC_VMTYPE_L: fprintf(stderr, "L"); break;
        case IC_VMTYPE_W: fprintf(stderr, "W"); break;
        case IC_VMTYPE_D: fprintf(stderr, "D"); break;
        }
        switch(op1) {
        case IC_VMOPERAND_P: fprintf(stderr, "P"); break;
        case IC_VMOPERAND_Q: fprintf(stderr, "Q"); break;
        case IC_VMOPERAND_R: fprintf(stderr, "R"); break;
        case IC_VMOPERAND_V: fprintf(stderr, "V"); break;
        case IC_VMOPERAND_A: fprintf(stderr, "A"); break;
        case IC_VMOPERAND_X: fprintf(stderr, "X"); break;
        case IC_VMOPERAND_NONE: fprintf(stderr, "-"); break;
        }
        switch(op2) {
        case IC_VMOPERAND_P: fprintf(stderr, "P"); break;
        case IC_VMOPERAND_Q: fprintf(stderr, "Q"); break;
        case IC_VMOPERAND_R: fprintf(stderr, "R"); break;
        case IC_VMOPERAND_V: fprintf(stderr, "V"); break;
        case IC_VMOPERAND_A: fprintf(stderr, "A"); break;
        case IC_VMOPERAND_X: fprintf(stderr, "X"); break;
        case IC_VMOPERAND_NONE: fprintf(stderr, "-"); break;

        }
        printf("\n");
        if (op->s1) {
            corto_error("   operand 1: %s", ic_nodeStr(op->s1));
        }
        if (op->s2) {
            corto_error("   operand 2: %s", ic_nodeStr(op->s2));
        }
        if (op->s3) {
            corto_error("   operand 3: %s", ic_nodeStr(op->s3));
        }
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
static vm_op* corto_vmGetTypeAndAssemble(

    /* In parameters */
    ic_vmProgram *program,
    ic_op op,
    vm_op *vmOp,
    corto_bool threeOperands,
    ic_node storage,
    ic_node op1,
    ic_node op2,
    ic_derefKind storageDeref,
    ic_derefKind opDeref1,
    ic_derefKind opDeref2,

    /* Out parameters */
    corto_type *t,
    ic_vmType *type,
    ic_vmOperand *storageKind,
    ic_vmOperand *opKind1,
    ic_vmOperand *opKind2) {

    if (op1) {
        corto_bool isPush = op ? op->kind == ic_push ? TRUE : FALSE : FALSE;
        *opKind1 = ic_getVmOperand(program, opDeref1, isPush, op1);
        *t = ic_valueType(op1);

        if (!threeOperands) {
            *type = ic_getVmType(op1, opDeref1);
        } else {
            *type = IC_VMTYPE_W;
        }
        if (((ic_node)op1)->kind == IC_STORAGE) {
            vmOp = ic_vmStorage_assemble((ic_storage)op1, program, vmOp);
        }
    }
    if (op2) {
        if (((ic_node)op2)->kind == IC_STORAGE) {
            if (op2 != op1) {
                vmOp = ic_vmStorage_assemble((ic_storage)op2, program, vmOp);
            }
        }
        *opKind2 = ic_getVmOperand(program, opDeref2, FALSE, op2);
    }
    if (storage) {
        if (((ic_node)storage)->kind == IC_STORAGE) {
            if ((storage != op1) && (storage != op2))
                vmOp = ic_vmStorage_assemble((ic_storage)storage, program, vmOp);
        }
        *storageKind = ic_getVmOperand(program, storageDeref, FALSE, storage);
    }

    return vmOp;
}

/* Instruction without operands */
static void vm_op0(ic_vmProgram *program, vm_op *vmOp, ic_op op, ic_node op1, ic_derefKind opDeref1) {
    corto_type t;
    ic_vmType type;
    ic_vmOperand opKind1;
    vmOp = corto_vmGetTypeAndAssemble(program, op, vmOp, FALSE, NULL, op1, NULL, 0, opDeref1, 0,  &t, &type, NULL, &opKind1, NULL);
    vmOp->op = ic_getVmOpKind(program, op, op1, NULL, NULL, NULL, NULL, 0, 0);
}

/* Instruction with one operand */
static void vm_op1(ic_vmProgram *program, vm_op *vmOp, ic_op op, ic_node op1, ic_derefKind opDeref1) {
    corto_type t;
    ic_vmType type;
    ic_vmOperand opKind1;
    vmOp = corto_vmGetTypeAndAssemble(program, op, vmOp, FALSE, NULL, op1, NULL, 0, opDeref1, 0,  &t, &type, NULL, &opKind1, NULL);
    vmOp->op = ic_getVmOpKind(program, op, op1, t, &type, &opKind1, NULL, opDeref1, 0);

    /* Set size of type in case return instruction needs to do a memcpy */
    if (op->kind == ic_ret) {
        vmOp->hi.w = corto_type_sizeof(t);
    }

    ic_vmSetOp1Addr(program, vmOp, type, opKind1, op1);
}

/* Instruction with one operand and one staged operand
 * Create extra operation. This will contain the actual operation while vmOp (it is first)
 * will contain a stage, which will stage the values for the conditional operation. The
 * reason to do this with a stage rather than with a set is that a conditional operation has
 * a boolean value as a result, which can be of a different size than the operands.
 */
static void vm_op1Staged(ic_vmProgram *program, vm_op *vmOp, ic_op op, ic_node storage, ic_node op1, ic_derefKind storageDeref, ic_derefKind opDeref1) {
    vm_op *vmStoredOp;
    corto_type t;
    ic_vmType type;
    ic_vmOperand opKind1, storageKind;

    vmOp = corto_vmGetTypeAndAssemble(program, op, vmOp, FALSE, storage, op1, NULL, storageDeref, opDeref1, 0,  &t, &type, &storageKind, &opKind1, NULL);
    type = corto_vmTranslateVmType(op->kind, type);
    vmOp->op = ic_getVmSTAGE1(t, type, opKind1, 0, 0);
    ic_vmSetOp1Addr(program, vmOp, type, opKind1, op1);

    vmStoredOp = vm_programAddOp(program->program, op->line);
    vmStoredOp->op = ic_getVmOpKind(program, op, op1, t, &type, &storageKind, &opKind1, storageDeref, opDeref1);
    ic_vmSetOp1Addr(program, vmStoredOp, type, storageKind, storage);
}

/* Instruction with two operands */
static void vm_op2(ic_vmProgram *program, vm_op *vmOp, ic_op op, ic_node op1, ic_node op2, ic_derefKind opDeref1, ic_derefKind opDeref2) {
    corto_type t;
    ic_vmType type;
    ic_vmOperand opKind1, opKind2;

    vmOp = corto_vmGetTypeAndAssemble(program, op, vmOp, FALSE, NULL, op1, op2, 0, opDeref1, opDeref2,  &t, &type, NULL, &opKind1, &opKind2);
    vmOp->op = ic_getVmOpKind(program, op, op1, t, &type, &opKind1, &opKind2, opDeref1, opDeref2);
    ic_vmSetOp2Addr(program, vmOp, type, opKind1, opKind2, op1, op2);
}

/* Instruction with two operands */
static void vm_op3(ic_vmProgram *program, vm_op *vmOp, ic_op op, ic_node op1, ic_node op2, ic_node op3, ic_derefKind opDeref1, ic_derefKind opDeref2, ic_derefKind opDeref3) {
    corto_type t;
    ic_vmType type;
    ic_vmOperand opKind1, opKind2;
    CORTO_UNUSED(opDeref3);

    vmOp = corto_vmGetTypeAndAssemble(program, op, vmOp, FALSE, NULL, op1, op2, 0, opDeref1, opDeref2,  &t, &type, NULL, &opKind1, &opKind2);

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
static void vm_op2Storage(ic_vmProgram *program, vm_op *vmOp, ic_op op, ic_node storage, ic_node op1, ic_node op2, ic_derefKind storageDeref, ic_derefKind opDeref1, ic_derefKind opDeref2) {
    vm_op *vmStoredOp;
    corto_type t;
    ic_vmType type;
    ic_vmOperand opKind1, opKind2, storageKind;

    vmOp = corto_vmGetTypeAndAssemble(program, op, vmOp, FALSE, storage, op1, op2, storageDeref, opDeref1, opDeref2,  &t, &type, &storageKind, &opKind1, &opKind2);
    vmOp->op = ic_getVmSet(program, t, (ic_storage)storage, &type, &storageKind, &opKind1, storageDeref, opDeref1);
    ic_vmSetOp2Addr(program, vmOp, type, storageKind, opKind1, storage, op1);

    vmStoredOp = vm_programAddOp(program->program, op->line);
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
static void vm_op2Set(ic_vmProgram *program, vm_op *vmOp, ic_op op, ic_node storage, ic_node op1, ic_node op2, ic_derefKind storageDeref, ic_derefKind opDeref1, ic_derefKind opDeref2) {
    vm_op *vmStoredOp;
    corto_type t;
    ic_vmType type;
    ic_vmOperand opKind1, opKind2, storageKind;

    vmOp = corto_vmGetTypeAndAssemble(program, op, vmOp, FALSE, storage, op1, op2, storageDeref, opDeref1, opDeref2,  &t, &type, &storageKind, &opKind1, &opKind2);
    vmOp->op = ic_getVmSet(program, t, (ic_storage)op1, &type, &opKind1, &opKind2, opDeref1, opDeref2);
    ic_vmSetOp2Addr(program, vmOp, type, opKind1, opKind2, op1, op2);

    vmStoredOp = vm_programAddOp(program->program, op->line);
    vmStoredOp->op = ic_getVmSet(program, t, (ic_storage)storage, &type, &storageKind, &opKind1, storageDeref, opDeref1);
    ic_vmSetOp2Addr(program, vmStoredOp, type, storageKind, opKind1, storage, op1);
}

/* Instruction with two operands and two staged
 * Create extra operation. This will contain the actual operation while vmOp (it is first)
 * will contain a stage, which will stage the values for the conditional operation. The
 * reason to do this with a stage rather than with a set is that a conditional operation has
 * a boolean value as a result, which can be of a different size than the operands.
 */
static void vm_op2Staged(ic_vmProgram *program, vm_op *vmOp, ic_op op, ic_node storage, ic_node op1, ic_node op2, ic_derefKind storageDeref, ic_derefKind opDeref1, ic_derefKind opDeref2) {
    vm_op *vmStoredOp;
    corto_type t;
    ic_vmType type;
    ic_vmOperand opKind1, opKind2, storageKind;

    vmOp = corto_vmGetTypeAndAssemble(program, op, vmOp, FALSE, storage, op1, op2, storageDeref, opDeref1, opDeref2,  &t, &type, &storageKind, &opKind1, &opKind2);
    type = corto_vmTranslateVmType(op->kind, type);

    vmOp->op = ic_getVmSTAGE2(t, type, opKind1, opKind2, 0);
    ic_vmSetOp2Addr(program, vmOp, type, opKind1, opKind2, op1, op2);

    vmStoredOp = vm_programAddOp(program->program, op->line);
    vmStoredOp->op = ic_getVmOpKind(program, op, storage, t, &type, &storageKind, &opKind1, storageDeref, opDeref1);
    ic_vmSetOp1Addr(program, vmStoredOp, type, storageKind, storage);
}

/* Cast instruction with either a reference cast or two staged types, a source and storage */
static void vm_op2Cast(ic_vmProgram *program, vm_op *vmOp, ic_op op, ic_node storage, ic_node op1, ic_node op2, ic_derefKind storageDeref, ic_derefKind opDeref1, ic_derefKind opDeref2) {
    vm_op *vmStoredOp;
    corto_type sourceType, destinationType;
    ic_vmType type;
    ic_vmOperand opKind1, opKind2, storageKind;

    destinationType = ic_valueType(storage);

    /* If destinationType is a reference, insert regular 2-operand instruction */
    if (ic_storage(storage)->isReference) {
        vm_op2Storage(program, vmOp, op, storage, op1, op2, storageDeref, opDeref1, opDeref2);
    /* If destinationType is not a reference, stage types and insert primitive cast */
    } else {
        vmOp = corto_vmGetTypeAndAssemble(program, op, vmOp, FALSE, storage, op1, op2, storageDeref, opDeref1, opDeref2,  &sourceType, &type, &storageKind, &opKind1, &opKind2);
        type = corto_vmTranslateVmType(op->kind, type);

        if (sizeof(intptr_t) == 4) {
            vmOp->op = CORTO_VM_STAGE2_LVV;
        } else if (sizeof(intptr_t) == 8) {
            vmOp->op = CORTO_VM_STAGE2_DVV;
        }

        if (op->s2Deref == IC_DEREF_ADDRESS) {
            vmOp->lo.w = (corto_word)corto_object_o;
        } else {
            vmOp->lo.w = (corto_word)sourceType;
        }
        vmOp->hi.w = (corto_word)destinationType;

        vmStoredOp = vm_programAddOp(program->program, op->line);
        vmStoredOp->op = ic_getVmOpKind(program, op, storage, sourceType, &type, &storageKind, &opKind1, storageDeref, opDeref1);
        ic_vmSetOp2Addr(program, vmStoredOp, type, storageKind, opKind1, storage, op1);
    }
}

static void ic_getVmOp(ic_vmProgram *program, ic_op op) {
    ic_derefKind opDeref1 = 0, opDeref2 = 0, opDeref3 = 0, storageDeref = 0;
    ic_node op1 = NULL, op2 = NULL, op3 = NULL, storage = NULL;
    vm_op *vmOp;
    corto_bool stageOperands = FALSE;
    corto_bool castOperands = FALSE;

    /* Allocate operation */
    vmOp = vm_programAddOp(program->program, op->line);

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
        corto_type t = ((ic_storage)op->s1)->type;
        if (t->kind == CORTO_ITERATOR) {
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
            op2 = (ic_node)ic_addressCreate((corto_word)ic_valueType(op->s1));
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
        label = ic_vmLabelGet(program, *(corto_uint32*)ic_valueValue(program, op->s1));
        ic_vmLabelAddReferee(program, label, &vmOp->lo.w);
        op1 = NULL;
        op2 = NULL;
        storage = NULL;
        break;
    }

    case ic_init:
    case ic_deinit: {
        op1 = op->s1;
        op2 = (ic_node)ic_objectCreate(ic_storage(op->s1)->type);
        opDeref1 = IC_DEREF_VALUE;
        opDeref2 = IC_DEREF_ADDRESS;
        break;
    }

    case ic_set:
        if (ic_storage(op->s2)->type->kind == CORTO_ITERATOR) {
            op1 = op->s2;
            op2 = op->s3;
            op3 = (ic_node)ic_objectCreate(ic_storage(op->s3)->type);
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
        if (ic_operandIsComposite((ic_storage)op->s2, CORTO_DELEGATE)) {
            op1 = op->s1;
            op2 = op->s2;
            opDeref1 = op->s1Deref;
            storage = NULL;
        } else {
            op1 = op->s1;
            storage = NULL;
            vmOp->hi.w = (corto_word)((ic_object)op->s2)->ptr;
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
                vm_op3(program, vmOp, op, op1, op2, op3, opDeref1, opDeref2, opDeref3);
            } else if (storage && (storage != op1)) {
                /* If operation has a storage-operand, insert set-operation */
                if (op->kind == ic_set) {
                    vm_op2Set(program, vmOp, op, storage, op1, op2, storageDeref, opDeref1, opDeref2);
                } else {
                    if (!stageOperands) {
                        if (castOperands) {
                            vm_op2Cast(program, vmOp, op, storage, op1, op2, storageDeref, opDeref1, opDeref2);
                        } else {
                            vm_op2Storage(program, vmOp, op, storage, op1, op2, storageDeref, opDeref1, opDeref2);
                        }
                    } else {
                        vm_op2Staged(program, vmOp, op, storage, op1, op2, storageDeref, opDeref1, opDeref2);
                    }
                }
            } else {
                vm_op2(program, vmOp, op, op1, op2, opDeref1, opDeref2);
            }
        /* Operation has one operand */
        } else {
            if (!stageOperands) {
                vm_op1(program, vmOp, op, op1, opDeref1);
            } else {
                vm_op1Staged(program, vmOp, op, storage, op1, storageDeref, opDeref1);
            }
        }
    } else {
        vm_op0(program, vmOp, op, storage, storageDeref);
    }
}

static corto_int16 ic_op_toVm(ic_op op, ic_vmProgram *program) {
    CORTO_UNUSED(program);

    if (!program->program) {
        program->program = vm_programNew(program->icProgram->filename, program->function->function);
    }

    /* If operation is push, increase stack-size */
    if (op->kind == ic_push) {
        if(op->s1Any) {
            program->stackSize += sizeof(corto_any);
        }else {
            corto_type t = ic_valueType(op->s1);
            program->stackSize += corto_type_sizeof(t);
        }
        if (program->stackSize > program->maxStackSize) {
            program->maxStackSize = program->stackSize;
        }
    }

    if (op->kind == ic_call) {
        corto_function f;

        /* When the function is a vm-function the vm will directly invoke the function
         * without using corto_call. To avoid memcpy'ing between the stack of the calling
         * function and the storage of the called function the stack is made as big as the
         * largest storage of all called functions.
         *
         * Because the storage-size of the function is not known when the function is not
         * yet defined, setting the stack-size is in this case delayed until all functions
         * are assembled.
         */
        if (((ic_storage)op->s2)->kind == IC_OBJECT) {
            corto_object o = ((ic_object)op->s2)->ptr;
            corto_type t = corto_typeof(o);
            if ((t->kind == CORTO_COMPOSITE) && (corto_interface(t)->kind == CORTO_PROCEDURE)) {
                f = o;
                if (f->kind == CORTO_PROCEDURE_VM) {
                    if (corto_checkState(f, CORTO_DEFINED)) {
                        vm_program inlineProgram = (vm_program)f->implData;
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

static void icZeroLocal(ic_vmProgram *program, corto_uint16 initStart, corto_uint16 size) {
    vm_op *vmOp;

    vmOp = vm_programAddOp(program->program, 0);

    switch(size) {
    case sizeof(corto_uint8):
        vmOp->op = CORTO_VM_SET_BRV;
        vmOp->ic.b._1 = initStart;
        vmOp->ic.b._2 = 0;
        break;
    case sizeof(corto_uint16):
        vmOp->op = CORTO_VM_SET_SRV;
        vmOp->ic.b._1 = initStart;
        vmOp->ic.b._2 = 0;
        break;
    case sizeof(corto_uint32):
        vmOp->op = CORTO_VM_SET_LRV;
        vmOp->ic.b._1 = initStart;
        vmOp->lo.w = 0;
        break;
    case sizeof(corto_uint64):
        vmOp->op = CORTO_VM_SET_DRV;
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

static void icInitLocal(ic_vmProgram *program, corto_uint16 localAddr, corto_type type) {
    vm_op *vmOp;

    vmOp = vm_programAddOp(program->program, 0);

    vmOp->op = ic_getVmINIT(NULL, IC_VMTYPE_W, IC_VMOPERAND_R, IC_VMOPERAND_V, 0);;
    vmOp->ic.b._1 = localAddr;
    vmOp->lo.w = (corto_word)type;
}

static corto_int16 ic_label_toVm(ic_label label, ic_vmProgram *program) {
    ic_vmLabel *lbl;

    if (program->program) {
        lbl = ic_vmLabelGet(program, label->id);
        lbl->pc = program->program->size;
    } else {
        corto_error("cannot add label to non-existing program");
        goto error;
    }

    return 0;
error:
    return -1;
}

corto_int16 ic_vmProgram_scopeToVm(ic_vmProgram *program, ic_scope scope) {
    corto_iter programIter, localIter;
    ic_node ic;
    corto_int16 result = 0;
    ic_storage storage = NULL, local = NULL;
    corto_uint16 size, initStart;
    ic_vmStorage *thisLocal = NULL;

    /* Push a new scope to the program. This manages an administration
     * which keeps track of how much memory each scope requires. */
    size = ic_vmProgram_push(program);

    /* Add locals to program */
    localIter = corto_llIter(scope->storages);
    initStart = size;
    while(corto_iterHasNext(&localIter)) {
        storage = corto_iterNext(&localIter);
        if (storage->kind == IC_VARIABLE) {
            ic_vmStorage *vmLocal;
            corto_bool zeroLocal = TRUE;
            local = storage;

            /* Lookup local in program */
            vmLocal = ic_vmProgram_getStorage(program, local);

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
                } else if (!local->isReference && (local->type->kind == CORTO_COLLECTION) && (corto_collection(local->type)->kind == CORTO_LIST)) {
                    icZeroLocal(program, initStart, size - initStart);
                    icInitLocal(program, size, local->type);
                    zeroLocal = FALSE;
                }

                /* Increase size */
                if (ic_isReference(local)) {
                    size += sizeof(corto_word);
                } else {
                    size += corto_type_sizeof(local->type);
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

    programIter = corto_llIter(scope->program);
    while(!result && corto_iterHasNext(&programIter)) {
        ic = corto_iterNext(&programIter);
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
            result = ic_vmProgram_scopeToVm(program, (ic_scope)ic);
            break;
        case IC_OP:
            result = ic_op_toVm((ic_op)ic, program);
            break;
        }
    }

    ic_vmProgram_pop(program);

    return result;
}

vm_program ic_vmAssemble(ic_program program) {
    ic_vmProgram vmProgram;
    corto_iter functionIter;
    corto_function function;
    corto_iter inlineFunctionIter;
    ic_vmInlineFunction *inlineFunction;

    if (!program->errors) {
        /* Parse main-program */
        vmProgram.icProgram = program;
        vmProgram.main = vm_programNew(program->filename, NULL);
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
        functionIter = corto_llIter(program->functions);
        while(corto_iterHasNext(&functionIter)) {
            function = ((ic_function)corto_iterNext(&functionIter))->function;
            function->kind = CORTO_PROCEDURE_VM;
        }

        /* Start assembling */
        if (ic_vmProgram_scopeToVm(&vmProgram, program->scope)) {
            goto error;
        }

        /* Finalize last program */
        ic_vmProgram_finalize(&vmProgram);

        /* Correct stack-sizes for inline functions that have been finalized
         * after they were encountered */
        if (vmProgram.inlineFunctions) {
            inlineFunctionIter = corto_llIter(vmProgram.inlineFunctions);
            while(corto_iterHasNext(&inlineFunctionIter)) {
                vm_program program;
                inlineFunction = corto_iterNext(&inlineFunctionIter);
                program = (vm_program)inlineFunction->function->implData;
                if (program->storage > inlineFunction->program->stack) {
                    inlineFunction->program->stack = program->storage;
                }
                corto_dealloc(inlineFunction);
            }
            corto_llFree(vmProgram.inlineFunctions);
        }
    } else {
        printf("%s: program contains errors, cannot compile.\n", program->filename);
        goto error;
    }

    return vmProgram.main;
error:
    return NULL;
}
