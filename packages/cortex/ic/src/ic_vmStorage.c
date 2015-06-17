
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
    *(cx_word*)referee = accumulator->addr;
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
        if (acc->kind == IC_OBJECT) {
            result->addr = (cx_word)ic_object(acc)->ptr;
        }
    } else {
        result->base = ic_vmProgram_getStorage(program, acc->base);
        ic_vmStorage *firstReusableBase = result->base;

        if (acc->kind == IC_MEMBER) {
            result->offset = ic_member(acc)->member->offset;
        } else if (!((ic_element)acc)->variableIndex && 
            acc->base->type->kind == CX_COLLECTION && (cx_collection(acc->base->type)->kind == CX_ARRAY)) {
            cx_collection type = cx_collection(acc->base->type);
            cx_uint32 index = *(cx_uint32*)ic_literal(((ic_element)acc)->index)->value.value;
            result->offset = cx_type_sizeof(type->elementType) * index;
        }

        if (result->base->base && !result->base->ic->isReference) {
            firstReusableBase = result->base->base;
        }
        if (result->base != firstReusableBase) {
            result->offset += result->base->offset;
        }

        if ((!firstReusableBase->ic->isReference || (firstReusableBase->ic->kind == IC_OBJECT))) {
            result->reusable = TRUE;
            result->assembled = TRUE;
            result->addr = firstReusableBase->addr + result->offset;
        }

        result->base = firstReusableBase;
        
        /* Determine 'allocated' field */
        ic_vmStorage_mustAllocate(result);
    }

    return result;
}

cx_bool ic_vmStorage_mustAllocate(ic_vmStorage *storage) {
    cx_bool result = FALSE;

    if (!storage->reusable || (storage->ic->kind == IC_ACCUMULATOR) || (storage->base && (storage->base->ic->kind == IC_ACCUMULATOR))) {
        result = TRUE;
        storage->allocated = result;
    }

    if (!storage->refereeCount) {
        result = FALSE;
    }

    return result;
}

#define ic_vmStorageGetSet(kind) sizeof(cx_word) == 4 ? CX_VM_SET_L##kind : CX_VM_SET_D##kind

static cx_vmOp *ic_vmStorageAssembleElement(
    ic_vmStorage *storage, 
    ic_vmProgram *program, 
    cx_vmOp *vmOp, 
    cx_bool topLevel,
    ic_vmStorage *acc,
    ic_vmStorage *accOut) 
{
    cx_type type = storage->ic->base->type;

    /* Obtain kind for index */
    if (type->kind == CX_ITERATOR) {
        ic_vmOperand baseKind = ic_getVmOperand(program, IC_DEREF_VALUE, ic_node(storage->ic->base));
        vmOp->op = ic_getVmSET(type, IC_VMTYPE_D, IC_VMOPERAND_R, baseKind, 0);
        ic_vmSetOp2Addr(program, vmOp, IC_VMTYPE_W, IC_VMOPERAND_R, baseKind, 
            ic_node(storage->ic), ic_node(storage->ic->base));
    } else if (type->kind == CX_COLLECTION) {
        ic_node ic_elementSize;
        cx_uint64 elementSize;
        cx_collection collection = cx_collection(type);
        ic_vmOperand indexKind = ic_getVmOperand(program, IC_DEREF_VALUE, ic_element(storage->ic)->index);

        if ((storage->base->ic != storage->ic->base) && (storage->ic->base->kind == IC_ELEMENT)) {
            ic_vmStorage *vmBase = ic_vmProgram_getStorage(program, storage->ic->base);
            vmOp = ic_vmStorageAssembleElement(vmBase, program, vmOp, topLevel, acc, accOut);
        } else if (acc != accOut) {
            vmOp->op = ic_vmStorageGetSet(RR);
            ic_vmSetOp2Addr(program, vmOp, IC_VMTYPE_W, IC_VMOPERAND_R, IC_VMOPERAND_R, ic_node(acc->ic), ic_node(accOut->ic));
            vmOp = cx_vmProgram_addOp(program->program, 0);  
        }

        /* Create value for elementSize */
        elementSize = cx_type_sizeof(collection->elementType);
        ic_elementSize = (ic_node)ic_literal__create((cx_any){cx_type(cx_uint32_o), &elementSize, FALSE});

        switch(collection->kind) {
        case CX_ARRAY:
            vmOp->op = ic_getVmELEMA(type, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, 0);
            ic_vmSetOp3Addr(program, vmOp, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, IC_VMOPERAND_V, ic_node(acc->ic), ic_element(storage->ic)->index, ic_elementSize);
            break;
        case CX_SEQUENCE:
            vmOp->op = ic_getVmELEMS(type, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, 0);
            ic_vmSetOp3Addr(program, vmOp, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, IC_VMOPERAND_V, ic_node(storage->ic), ((ic_element)storage->ic)->index, ic_elementSize);
            break;
        case CX_LIST:
            if (cx_collection_elementRequiresAlloc(collection) || !topLevel) {
                vmOp->op = ic_getVmELEML(type, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, 0);
            } else {
                vmOp->op = ic_getVmELEMLX(type, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, 0);
            }
            ic_vmSetOp2Addr(program, vmOp, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, ic_node(storage->ic), ((ic_element)storage->ic)->index);
            break;
        case CX_MAP:
            if (cx_collection_elementRequiresAlloc(collection) || !topLevel) {
                vmOp->op = ic_getVmELEMM(type, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, 0);
            } else {
                vmOp->op = ic_getVmELEMMX(type, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, 0);
            }
            ic_vmSetOp2Addr(program, vmOp, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, ic_node(storage->ic), ((ic_element)storage->ic)->index);
            break;
        }
    }

    return cx_vmProgram_addOp(program->program, 0);
}

static cx_vmOp *ic_vmStorageAssembleMember(
    ic_vmStorage *storage, 
    ic_vmProgram *program, 
    cx_vmOp *vmOp,
    ic_vmStorage *acc,
    ic_vmStorage *accOut) 
{
    vmOp->op = ic_getVmMEMBER(NULL, 0, 0, 0, 0);
    ic_vmStorageAddReferee(acc, program, &vmOp->ic.b._1);
    ic_vmStorageAddReferee(accOut, program, &vmOp->ic.b._2);
    vmOp->lo.w = storage->offset;
    return cx_vmProgram_addOp(program->program, 0);
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

    if (!storage->assembled || !storage->reusable || (storage->base && storage->base->ic->isReference)) {
        ic_storage base = storage->base->ic;
        ic_vmStorage *acc = storage->allocated ? storage : accIn ? accIn : storage;
        ic_vmStorage *baseAccOut = NULL;

        vmOp = ic_vmStorageAssembleNested(base, program, vmOp, FALSE, storage->allocated ? storage : accIn, &baseAccOut);
        if (!baseAccOut) {
            baseAccOut = storage->base;
        }

        if (storage->base->ic->kind != IC_OBJECT) {
            if (storage->ic->kind == IC_MEMBER) {
                vmOp = ic_vmStorageAssembleMember(storage, program, vmOp, acc, baseAccOut);
            } else {
                vmOp = ic_vmStorageAssembleElement(storage, program, vmOp, topLevel, acc, baseAccOut);
            }
            if (accOut) *accOut = acc;
            if (!topLevel) {
                vmOp->op = ic_vmStorageGetSet(RQ);
                ic_vmStorageAddReferee(acc, program, &vmOp->ic.b._1);
                ic_vmStorageAddReferee(acc, program, &vmOp->ic.b._2);
                vmOp = cx_vmProgram_addOp(program->program, 0);
            }
        } else {
            if (!topLevel) {
                vmOp->op = ic_vmStorageGetSet(RP);
                ic_vmStorageAddReferee(acc, program, &vmOp->ic.b._1);
                vmOp->lo.w = storage->base->addr + storage->offset;
                vmOp = cx_vmProgram_addOp(program->program, 0);
                if (accOut) *accOut = acc;
            }
        }
    }

    return vmOp;
}

cx_vmOp *ic_vmStorage_assemble(ic_storage icStorage, ic_vmProgram *program, cx_vmOp *vmOp) {
    return ic_vmStorageAssembleNested(icStorage, program, vmOp, TRUE, NULL, NULL);
}
