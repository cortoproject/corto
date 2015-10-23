
#include "ic_assemble.h"
#include "ic_vmProgram.h"
#include "ic_vmStorage.h"

vm_opKind ic_getVmSETX(corto_type t, ic_vmType typeKind, ic_vmOperand op1, ic_vmOperand op2, ic_vmOperand op3);
vm_opKind ic_getVmSET(corto_type t, ic_vmType typeKind, ic_vmOperand op1, ic_vmOperand op2, ic_vmOperand op3);
vm_opKind ic_getVmMEMBER(corto_type t, ic_vmType typeKind, ic_vmOperand op1, ic_vmOperand op2, ic_vmOperand op3);
vm_opKind ic_getVmELEMA(corto_type t, ic_vmType typeKind, ic_vmOperand op1, ic_vmOperand op2, ic_vmOperand op3);
vm_opKind ic_getVmELEMS(corto_type t, ic_vmType typeKind, ic_vmOperand op1, ic_vmOperand op2, ic_vmOperand op3);
vm_opKind ic_getVmELEML(corto_type t, ic_vmType typeKind, ic_vmOperand op1, ic_vmOperand op2, ic_vmOperand op3);
vm_opKind ic_getVmELEMM(corto_type t, ic_vmType typeKind, ic_vmOperand op1, ic_vmOperand op2, ic_vmOperand op3);
vm_opKind ic_getVmELEMLX(corto_type t, ic_vmType typeKind, ic_vmOperand op1, ic_vmOperand op2, ic_vmOperand op3);
vm_opKind ic_getVmELEMMX(corto_type t, ic_vmType typeKind, ic_vmOperand op1, ic_vmOperand op2, ic_vmOperand op3);

static vm_op *ic_vmStorageAssembleNested(
    ic_storage icStorage, ic_vmProgram *program, vm_op *vmOp, corto_bool topLevel, ic_vmStorage *accIn, ic_vmStorage **accOut);

void ic_vmStorageAddReferee(ic_vmStorage *accumulator, ic_vmProgram *program, void *referee) {
    *(corto_word*)referee = accumulator->addr;
    accumulator->referees[accumulator->refereeCount] = CORTO_OFFSET(referee, -(intptr_t)program->program->program);
    corto_assert(accumulator->refereeCount < 256, "unsupported number of references to one accumulator (max is 256)");
    accumulator->refereeCount++;
}

ic_vmStorage *ic_vmStorageCreate(ic_vmProgram *program, ic_storage acc, corto_uint32 firstUsed) {
    ic_vmStorage *result;

    result = corto_calloc(sizeof(ic_vmStorage));
    result->ic = acc;
    result->firstUsed = firstUsed;
    result->allocated = FALSE;

    if (!acc->base) { /* Never overwrite storages which have no base */
        result->reusable = TRUE;
        result->assembled = TRUE;
        result->allocated = TRUE;
        if (acc->kind == IC_OBJECT) {
            result->addr = (corto_word)ic_object(acc)->ptr;
        }
    } else {
        result->base = ic_vmProgram_getStorage(program, acc->base);
        ic_vmStorage *firstReusableBase = result->base;

        if (acc->kind == IC_MEMBER) {
            result->offset = ic_member(acc)->member->offset;
        } else if (!((ic_element)acc)->variableIndex &&
            (acc->base->type->kind == CORTO_COLLECTION) &&
            (corto_collection(acc->base->type)->kind == CORTO_ARRAY) &&
            ((ic_element(acc))->index->kind == IC_LITERAL))
        {
            corto_collection type = corto_collection(acc->base->type);
            corto_uint32 index = *(corto_uint32*)ic_literal((ic_element(acc))->index)->value.value;
            result->offset = corto_type_sizeof(type->elementType) * index;
        } else {
            result->alwaysCompute = TRUE;
        }

        if (result->base->base && !ic_isReference(result->base->ic) && !result->base->alwaysCompute) {
            firstReusableBase = result->base->base;
        }
        if (result->base != firstReusableBase) {
            result->offset += result->base->offset;
        }

        if (!result->alwaysCompute) {
            result->alwaysCompute = firstReusableBase->alwaysCompute;
        }

        if ((!ic_isReference(firstReusableBase->ic) || (firstReusableBase->ic->kind == IC_OBJECT))) {
            if (!result->alwaysCompute && !firstReusableBase->alwaysCompute) {
                result->reusable = TRUE;
                result->assembled = TRUE;
                result->addr = firstReusableBase->addr + result->offset;
            }
        }

        result->base = firstReusableBase;

        /* Determine 'allocated' field */
        ic_vmStorage_mustAllocate(result);
    }

    return result;
}

corto_bool ic_vmStorage_mustAllocate(ic_vmStorage *storage) {
    corto_bool result = FALSE;

    if (!storage->reusable || 
       (storage->ic->kind == IC_ACCUMULATOR)) {
        result = TRUE;
        storage->allocated = result;
    }

    if (!storage->refereeCount) {
        result = FALSE;
    }

    return result;
}

#define ic_vmStorageGetSet(kind) sizeof(corto_word) == 4 ? CORTO_VM_SET_L##kind : CORTO_VM_SET_D##kind

static vm_op *ic_vmStorageAssembleElement(
    ic_vmStorage *storage,
    ic_vmProgram *program,
    vm_op *vmOp,
    corto_bool topLevel,
    ic_vmStorage *acc,
    ic_vmStorage *accOut)
{
    corto_type type = storage->ic->base->type;

    if (type->kind == CORTO_ITERATOR) {
        ic_vmOperand baseKind = ic_getVmOperand(program, IC_DEREF_VALUE, FALSE, ic_node(storage->ic->base));
        vmOp->op = ic_getVmSET(type, IC_VMTYPE_D, IC_VMOPERAND_R, baseKind, 0);
        ic_vmSetOp2Addr(program, vmOp, IC_VMTYPE_W, IC_VMOPERAND_R, baseKind,
            ic_node(storage->ic), ic_node(storage->ic->base));
    } else if (type->kind == CORTO_COLLECTION) {
        ic_node ic_elementSize;
        corto_uint64 elementSize;
        corto_collection collection = corto_collection(type);
        ic_vmOperand indexKind = ic_getVmOperand(program, IC_DEREF_VALUE, FALSE, ic_element(storage->ic)->index);

        if ((storage->base->ic != storage->ic->base) && (storage->ic->base->kind == IC_ELEMENT)) {
            ic_vmStorage *vmBase = ic_vmProgram_getStorage(program, storage->ic->base);
            vmOp = ic_vmStorageAssembleElement(vmBase, program, vmOp, topLevel, acc, accOut);
        } else if (acc != accOut) {
            if (accOut->ic->kind == IC_OBJECT) {
                vmOp->op = ic_vmStorageGetSet(RV);
                ic_vmSetOp2Addr(program, vmOp, IC_VMTYPE_W, IC_VMOPERAND_R, IC_VMOPERAND_P, ic_node(acc->ic), ic_node(accOut->ic));
                vmOp = vm_programAddOp(program->program, 0);
            } else {
                if (ic_isReference(accOut->ic) || accOut->alwaysCompute) {
                    vmOp->op = ic_vmStorageGetSet(RR);
                    ic_vmSetOp2Addr(program, vmOp, IC_VMTYPE_W, IC_VMOPERAND_R, IC_VMOPERAND_R, ic_node(acc->ic), ic_node(accOut->ic));
                    vmOp = vm_programAddOp(program->program, 0);
                } else {
                    vmOp->op = CORTO_VM_SETX_WRR;
                    ic_vmSetOp2Addr(program, vmOp, IC_VMTYPE_W, IC_VMOPERAND_R, IC_VMOPERAND_R, ic_node(acc->ic), ic_node(accOut->ic));
                    vmOp = vm_programAddOp(program->program, 0);
                }
            }
        }

        /* Create value for elementSize */
        elementSize = corto_type_sizeof(collection->elementType);
        ic_elementSize = (ic_node)ic_literalCreate((corto_any){corto_type(corto_uint32_o), &elementSize, FALSE});

        switch(collection->kind) {
        case CORTO_ARRAY:
            vmOp->op = ic_getVmELEMA(type, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, 0);
            ic_vmSetOp3Addr(program, vmOp, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, IC_VMOPERAND_V, ic_node(acc->ic), ic_element(storage->ic)->index, ic_elementSize);
            break;
        case CORTO_SEQUENCE:
            vmOp->op = ic_getVmELEMS(type, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, 0);
            ic_vmSetOp3Addr(program, vmOp, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, IC_VMOPERAND_V, ic_node(acc->ic), ic_element(storage->ic)->index, ic_elementSize);
            break;
        case CORTO_LIST:
            if (corto_collection_elementRequiresAlloc(collection)) {
                vmOp->op = ic_getVmELEML(type, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, 0);
            } else {
                vmOp->op = ic_getVmELEMLX(type, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, 0);
            }
            ic_vmSetOp2Addr(program, vmOp, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, ic_node(acc->ic), ((ic_element)storage->ic)->index);
            break;
        case CORTO_MAP:
            if (corto_collection_elementRequiresAlloc(collection)) {
                vmOp->op = ic_getVmELEMM(type, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, 0);
            } else {
                vmOp->op = ic_getVmELEMMX(type, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, 0);
            }
            ic_vmSetOp2Addr(program, vmOp, IC_VMTYPE_W, IC_VMOPERAND_R, indexKind, ic_node(acc->ic), ((ic_element)storage->ic)->index);
            break;
        }
    }

    return vm_programAddOp(program->program, 0);
}

static vm_op *ic_vmStorageAssembleMember(
    ic_vmStorage *storage,
    ic_vmProgram *program,
    vm_op *vmOp,
    ic_vmStorage *acc,
    ic_vmStorage *accOut)
{
    vmOp->op = ic_getVmMEMBER(NULL, 0, 0, 0, 0);
    ic_vmStorageAddReferee(acc, program, &vmOp->ic.b._1);
    ic_vmStorageAddReferee(accOut, program, &vmOp->ic.b._2);
    vmOp->lo.w = storage->offset;
    return vm_programAddOp(program->program, 0);
}

static vm_op *ic_vmStorageAssembleNested(
    ic_storage icStorage,       /* The storage to be assembled */
    ic_vmProgram *program,      /* The program in which the storage is active */
    vm_op *vmOp,              /* The entry point for the program */
    corto_bool topLevel,           /* Whether this is the first call or a recursive call */
    ic_vmStorage *accIn,        /* Override recursive storage with this storage if base is not assembled */
    ic_vmStorage **accOut)
{
    ic_vmStorage *storage = ic_vmProgram_getStorage(program, icStorage);

    if (!storage->assembled || !storage->reusable || (storage->base && ic_isReference(storage->base->ic))) {
        ic_storage base = storage->base->ic;
        ic_vmStorage *acc = storage->allocated ? storage : accIn ? accIn : storage;
        ic_vmStorage *baseAccOut = NULL;

        vmOp = ic_vmStorageAssembleNested(base, program, vmOp, FALSE, storage->allocated ? storage : accIn, &baseAccOut);
        if (!baseAccOut) {
            baseAccOut = storage->base;
        }

        if ((storage->base->ic->kind != IC_OBJECT) || storage->alwaysCompute) {
            if (storage->ic->kind == IC_MEMBER) {
                vmOp = ic_vmStorageAssembleMember(storage, program, vmOp, acc, baseAccOut);
            } else {
                vmOp = ic_vmStorageAssembleElement(storage, program, vmOp, topLevel, acc, baseAccOut);
            }
            if (accOut) *accOut = acc;
            if (!topLevel && ic_isReference(storage->ic)) {
                vmOp->op = ic_vmStorageGetSet(RQ);
                ic_vmStorageAddReferee(acc, program, &vmOp->ic.b._1);
                ic_vmStorageAddReferee(acc, program, &vmOp->ic.b._2);
                vmOp = vm_programAddOp(program->program, 0);
            }
        } else {
            if (!topLevel) {
                vmOp->op = ic_vmStorageGetSet(RP);
                ic_vmStorageAddReferee(acc, program, &vmOp->ic.b._1);
                vmOp->lo.w = storage->base->addr + storage->offset;
                vmOp = vm_programAddOp(program->program, 0);
                if (accOut) *accOut = acc;
            }
        }
    }

    return vmOp;
}

vm_op *ic_vmStorage_assemble(ic_storage icStorage, ic_vmProgram *program, vm_op *vmOp) {
    return ic_vmStorageAssembleNested(icStorage, program, vmOp, TRUE, NULL, NULL);
}
