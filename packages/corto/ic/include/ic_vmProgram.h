#ifndef ic_vmProgram_H
#define ic_vmProgram_H

#include "ic_vm__types.h"

#ifdef __cplusplus
extern "C" {
#endif

void ic_vmProgram_finalize(ic_vmProgram *vmProgram);
ic_vmStorage *ic_vmProgram_getStorage(ic_vmProgram *program, ic_storage icAccumulator);
corto_uint16 ic_vmProgram_push(ic_vmProgram *program);
void ic_vmProgram_setScopeSize(ic_vmProgram *program, corto_uint16 size);
void ic_vmProgram_pop(ic_vmProgram *program);
corto_int16 ic_vmProgram_scopeToVm(ic_vmProgram *program, ic_scope scope);
void ic_vmProgram_clean(ic_vmProgram *vmProgram);

#ifdef __cplusplus
}
#endif

#endif
