#ifndef ic_vmStorage_H
#define ic_vmStorage_H

#include "ic_vm__types.h"

#ifdef __cplusplus
extern "C" {
#endif

ic_vmStorage *ic_vmStorage__create(ic_vmProgram *program, ic_storage acc, cx_uint32 firstUsed);
cx_bool ic_vmStorage_mustAllocate(ic_vmStorage *storage, ic_vmProgram *program);
cx_vmOp *ic_vmStorage_assemble(ic_storage icStorage, ic_vmProgram *program, cx_vmOp *vmOp);
void ic_vmStorageAddReferee(ic_vmStorage *accumulator, ic_vmProgram *program, void *referee);

#ifdef __cplusplus
}
#endif

#endif
