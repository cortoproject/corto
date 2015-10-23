#ifndef ic_vmStorage_H
#define ic_vmStorage_H

#include "ic_vm__types.h"

#ifdef __cplusplus
extern "C" {
#endif

ic_vmStorage *ic_vmStorageCreate(ic_vmProgram *program, ic_storage acc, corto_uint32 firstUsed);
corto_bool ic_vmStorage_mustAllocate(ic_vmStorage *storage);
vm_op *ic_vmStorage_assemble(ic_storage icStorage, ic_vmProgram *program, vm_op *vmOp);
void ic_vmStorageAddReferee(ic_vmStorage *accumulator, ic_vmProgram *program, void *referee);

#ifdef __cplusplus
}
#endif

#endif
