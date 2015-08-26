
#ifndef IC_ASSEMBLE_H
#define IC_ASSEMBLE_H

#include "ic.h"
#include "ic_vmProgram.h"
#include "ic_vmStorage.h"

#ifdef __cplusplus
extern "C" {
#endif

vm_program ic_vmAssemble(ic_program program);
void ic_vmSetOp2Addr(ic_vmProgram *program, vm_op *op, ic_vmType typeKind, ic_vmOperand op1Kind, ic_vmOperand op2Kind, ic_node v1, ic_node v2);
void ic_vmSetOp3Addr(ic_vmProgram *program, vm_op *op, ic_vmType typeKind, ic_vmOperand op1Kind, ic_vmOperand op2Kind, ic_vmOperand op3Kind, ic_node v1, ic_node v2, ic_node v3);
cx_bool ic_isReference(ic_storage storage);

#ifdef __cplusplus
}
#endif
#endif
