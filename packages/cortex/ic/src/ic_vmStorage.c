
#include "ic_assemble.h"
#include "ic_vmProgram.h"
#include "ic_vmStorage.h"

cx_vmOpKind ic_getVmSETX(cx_type t, ic_vmType typeKind, ic_vmOperand op1, ic_vmOperand op2, ic_vmOperand op3);
cx_vmOpKind ic_getVmSET(cx_type t, ic_vmType typeKind, ic_vmOperand op1, ic_vmOperand op2, ic_vmOperand op3);
cx_vmOpKind ic_getVmMEMBER(cx_type t, ic_vmType typeKind, ic_vmOperand op1, ic_vmOperand op2, ic_vmOperand op3);
cx_vmOpKind ic_getVmELEMA(cx_type t, ic_vmType typeKind, ic_vmOperand op1, ic_vmOperand op2, ic_vmOperand op3);
cx_vmOpKind ic_getVmELEMS(cx_type t, ic_vmType typeKind, ic_vmOperand op1, ic_vmOperand op2, ic_vmOperand op3);
cx_vmOpKind ic_getVmELEML(cx_type t, ic_vmType typeKind, ic_vmOperand op1, ic_vmOperand op2, ic_vmOperand op3);
cx_vmOpKind ic_getVmELEMM(cx_type t, ic_vmType typeKind, ic_vmOperand op1, ic_vmOperand op2, ic_vmOperand op3);
cx_vmOpKind ic_getVmELEMLX(cx_type t, ic_vmType typeKind, ic_vmOperand op1, ic_vmOperand op2, ic_vmOperand op3);
cx_vmOpKind ic_getVmELEMMX(cx_type t, ic_vmType typeKind, ic_vmOperand op1, ic_vmOperand op2, ic_vmOperand op3);

static cx_vmOp *ic_vmStorageAssembleNested(
    ic_storage icStorage, ic_vmProgram *program, cx_vmOp *vmOp, cx_bool topLevel, ic_vmStorage *accIn, ic_vmStorage **accOut);

void ic_vmStorageAddReferee(ic_vmStorage *accumulator, ic_vmProgram *program, void *referee) {
    accumulator->referees[accumulator->refereeCount] = CX_OFFSET(referee, -(intptr_t)program->program->program);
    cx_assert(accumulator->refereeCount < 256, "unsupported number of references to one accumulator (max is 256)");
    accumulator->refereeCount++;
}

ic_vmStorage *ic_vmStorage__create(ic_vmProgram *program, ic_storage acc, cx_uint32 firstUsed) {
    ic_vmStorage *result;

    result = cx_calloc(sizeof(ic_vmStorage));
    result->ic = acc;
    result->firstUsed = firstUsed;
    result->allocated = FALSE;

    if (!acc->base) { /* Never overwrite storages which have no base */
        result->reusable = TRUE;
        result->assembled = TRUE;
        result->allocated = TRUE;
    } else {
        result->base = ic_vmProgram_getStorage(program, acc->base);
        ic_vmStorage *firstReusableBase = result->base;
        if (result->base->base && !result->base->ic->isReference) {
            firstReusableBase = result->base->base;
        }

        if (acc->kind == IC_MEMBER) {
            result->offset += ic_member(acc)->member->offset;
            if (result->base != firstReusableBase) {
                result->offset += result->base->offset;
            }
            if (!firstReusableBase->ic->isReference || (firstReusableBase->ic->kind == IC_OBJECT)) {
                result->reusable = TRUE;
                result->assembled = TRUE;
            } else if (firstReusableBase->ic->kind == IC_ACCUMULATOR) {
                result->reusable = TRUE;
            }
        } else if (!((ic_element)acc)->variableIndex && 
            acc->type->kind == CX_COLLECTION && (cx_collection(acc->type)->kind == CX_ARRAY)) {
            cx_collection type = cx_collection(acc->type);
            cx_uint32 index = *(cx_uint32*)ic_literal(((ic_element)acc)->index)->value.value;
            result->offset = cx_type_sizeof(type->elementType) * index + result->base->offset;
            if (!result->base->ic->isReference) {
                result->reusable = TRUE;
                result->assembled = TRUE;
            }
        }
        result->base = firstReusableBase;
        
        /* Determine 'allocated' field */
        ic_vmStorage_mustAllocate(result, program);
    }

    return result;
}

/* This function determines whether a storage must be allocated in register memory. 
 * Variables are allocated (in order) by other parts of the assembler. This function also
 * determines whether member/element storages should reuse the base-address. This happens
 * when either the offset of a reusable storage is zero, or when the address of the base is
 * not reusable. In the latter case, when assembling a storage, the base address will always 
 * have to be recomputed along with the storage, therefore the storage address can be stored
 * in the same register that stores the base address.
 */
cx_bool ic_vmStorage_mustAllocate(ic_vmStorage *storage, ic_vmProgram *program) {
    cx_bool result = FALSE;

    if (!storage->reusable || (storage->ic->kind == IC_ACCUMULATOR) || (storage->base && (storage->base->ic->kind == IC_ACCUMULATOR))) {
        result = TRUE;

        if ((storage->ic->kind == IC_MEMBER) || (storage->ic->kind == IC_ELEMENT)) {
            cx_bool accumulate; /* Use storage as accumulator address for dependent storages */

            if ((storage->base->reusable && !storage->reusable) || !storage->base->allocated) {
                accumulate = TRUE;
            } else {
                accumulate = FALSE;
            }

            if ((!storage->offset && (storage->reusable || (storage->base->reusable && storage->base->allocated))) || 
                (!storage->reusable && !accumulate)) {
                cx_uint32 referee;
                result = FALSE;
                storage->addr = storage->base->addr;
                for(referee=0; referee < storage->refereeCount; referee++) {
                    *(cx_uint16*)CX_OFFSET(storage->referees[referee], program->program->program) = storage->base->addr;
                }
            }
        }

        storage->allocated = result;
    }

    if (!storage->refereeCount) {
        result = FALSE;
    }

    return result;
}

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

static cx_vmOp *ic_vmStorageAssembleMember(
    ic_vmStorage *storage, 
    ic_vmProgram *program, 
    cx_vmOp *vmOp, 
    cx_bool topLevel, 
    ic_vmStorage *accIn,
    ic_vmStorage **accOut) 
{
    ic_storage base = storage->base->ic;
    cx_uint32 offset = storage->offset;
    ic_vmStorage *acc = storage->allocated ? storage : accIn ? accIn : storage;
    ic_vmStorage *baseAccOut = NULL;

    vmOp = ic_vmStorageAssembleNested(base, program, vmOp, FALSE, storage->allocated ? storage : accIn, &baseAccOut);
    if (!baseAccOut) {
        baseAccOut = storage->base;
    }

    if (storage->offset) {
        vmOp->op = ic_getVmMEMBER(NULL, 0, 0, 0, 0);
        ic_vmStorageAddReferee(acc, program, &vmOp->ic.b._1);
        if (base->kind == IC_VARIABLE) {
            vmOp->ic.b._2 = storage->base->addr;
        } else {
            ic_vmStorageAddReferee(baseAccOut, program, &vmOp->ic.b._2);
        }
        vmOp->lo.w = offset;
        vmOp = cx_vmProgram_addOp(program->program, 0);
        if (accOut) *accOut = acc;

        if (!topLevel) {
            vmOp->op = CX_VM_SET_LRQ;
            ic_vmStorageAddReferee(acc, program, &vmOp->ic.b._1);
            ic_vmStorageAddReferee(acc, program, &vmOp->ic.b._2);
            vmOp = cx_vmProgram_addOp(program->program, 0);
        }
    } else if (!topLevel) {
        vmOp->op = CX_VM_SET_LRQ;
        if (storage->ic->kind == IC_VARIABLE) {
            vmOp->ic.b._1 = storage->addr;
            if (accOut) *accOut = storage;
        } else {
            ic_vmStorageAddReferee(acc, program, &vmOp->ic.b._1);  
            if (accOut) *accOut = acc;                 
        }

        if (storage->base->ic->kind == IC_VARIABLE) {
            vmOp->ic.b._2 = storage->base->addr;
        } else {
            ic_vmStorageAddReferee(storage->base, program, &vmOp->ic.b._2);
        }
        vmOp = cx_vmProgram_addOp(program->program, 0);
    }

    return vmOp; 
}

static cx_vmOp *ic_vmStorageAssembleNested(
    ic_storage icStorage,       /* The storage to be assembled */
    ic_vmProgram *program,      /* The program in which the storage is active */
    cx_vmOp *vmOp,              /* The entry point for the program */
    cx_bool topLevel,           /* Whether this is the first call or a recursive call */
    ic_vmStorage *accIn,        /* Override recursive storage with this storage if base is not assembled */
    ic_vmStorage **accOut)        
{
    
    ic_vmStorage *storage = ic_vmProgram_getStorage(program, icStorage);

    if (!storage->assembled || !storage->reusable) {
        if (storage->ic->kind == IC_MEMBER) {
            vmOp = ic_vmStorageAssembleMember(storage, program, vmOp, topLevel, accIn, accOut);
        } else if (storage->ic->kind == IC_ELEMENT) {
            ic_storage base = storage->base->ic;
            ic_vmStorage *vmStorage = ic_vmProgram_getStorage(program, icStorage);

            /* Assemble base */
            vmOp = ic_vmStorageAssembleNested(base, program, vmOp, FALSE, accIn, accOut);

            /* If element is reusable the address can be determined at compile-time. When the element
             * is not reusable the address will be calculated at runtime. */
            if (!storage->reusable || ic_isReference(storage->base->ic)) {
                /* If the base is an object store the address in the accumulator */
                if (base->type->kind != CX_ITERATOR) {
                    if (base->kind == IC_OBJECT) {
                        vmOp->op = sizeof(intptr_t) == 4 ? CX_VM_SET_LRV : CX_VM_SET_DRV;
                        ic_vmStorageAddReferee(vmStorage, program, &vmOp->ic.b._1);
                        vmOp->lo.w = (intptr_t)((ic_object)base)->ptr;
                        if (storage->offset) {
                            vmOp->lo.w += storage->offset;
                        }
                        vmOp = cx_vmProgram_addOp(program->program, 0);

                    /* If the base is a local store the address of the local in the accumulator */
                    } else if (base->kind == IC_VARIABLE) {
                        if (!ic_isReference(storage->base->ic)) {
                            vmOp->op = ic_getVmSETX(NULL, IC_VMTYPE_W, IC_VMOPERAND_R, IC_VMOPERAND_R, 0);
                            ic_vmStorageAddReferee(vmStorage, program, &vmOp->ic.b._1);
                            vmOp->ic.b._2 = storage->base->addr;
                            if (storage->offset) {
                                vmOp->ic.b._2 += storage->offset;
                            }
                            vmOp = cx_vmProgram_addOp(program->program, 0);
                        } else {
                            vmOp->op = sizeof(intptr_t) == 4 ? CX_VM_SET_LRR : CX_VM_SET_DRR;
                            ic_vmStorageAddReferee(vmStorage, program, &vmOp->ic.b._1);
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

cx_vmOp *ic_vmStorage_assemble(ic_storage icStorage, ic_vmProgram *program, cx_vmOp *vmOp) {
    return ic_vmStorageAssembleNested(icStorage, program, vmOp, TRUE, NULL, NULL);
}

