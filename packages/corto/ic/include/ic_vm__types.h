
#ifndef ic_vm__types_H
#define ic_vm__types_H

#include "ic.h"
#include "vm.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ic_vmLabel {
    corto_uint32 id;
    corto_uint32 pc;
    void *referees[256]; /* The jumps to this label. At assemble-time, the exact address of the label is not yet known
                          * so this information is filled in after the program is assembled for each referee */
    corto_uint32 refereeCount;
}ic_vmLabel;

typedef struct ic_vmInlineFunction {
    vm_program program;
    corto_function function;
}ic_vmInlineFunction;

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

typedef struct ic_vmProgram {
    ic_program icProgram;
    vm_program main; /* Keep track of what is the main-module of a program (where the program starts) */
    vm_program program;
    ic_function function;
    corto_ll labels;
    corto_ll storages;
    corto_ll inlineFunctions;
    corto_uint16 scopeSize[256];
    corto_uint32 scope;
    corto_uint32 maxScopeSize; /* The maximum scope-size is where accumulators are allocated (thus after the locals) */
    corto_uint32 stackSize;
    corto_uint32 maxStackSize; /* The maximum stack-size is the maximum amount of space a call needs for its arguments */
}ic_vmProgram;

typedef struct ic_vmStorage ic_vmStorage;
struct ic_vmStorage {
    ic_storage ic;
    corto_uint32 firstUsed;
    corto_uint32 lastUsed;
    void *referees[512]; /* The jumps to this accumulator. At assemble-time, the exact address of the accumulator is not yet known
                          * so this information is filled in after the program is assembled for each referee */
    corto_uint32 refereeCount;
    corto_word addr;

    /* Member & element accumulators have a base and offset */
    corto_uint16 offset;
    ic_vmStorage *base;
    corto_bool assembled; /* Offsets of multiple member-operations are accumulated into one register so that
                        * instead of calculating multiple offsets at runtime, only one operation is required. This
                        * variable remains FALSE until the storage is used after which an operation is inserted
                        * to calculate the accumulated offset.
                        * This is only applicable for access to dynamically allocated objects or storages with dynamic
                        * components (elements with variable indexes). By default this value is TRUE. */
    corto_bool reusable;  /* A non-reusable storage needs to be assembled each time it is evaluated because the storage depends
                        * on the value of other storages, for example the index-expression of an element storage. */
    corto_bool allocated; /* Does the storage occupy space */
    corto_bool alwaysCompute; /* Does the storage needs to be computed regardless of base */
};

/* Administration that keeps track of claims accumulators have on the register */
typedef struct ic_registerClaim {
    ic_vmStorage *storage;
    corto_uint16 addr;
    corto_uint16 size;
    corto_uint32 start;
    corto_uint32 end;
}ic_registerClaim;

ic_vmOperand ic_getVmOperand(ic_vmProgram *program, ic_derefKind deref, corto_bool isArgument, ic_node node);

#ifdef __cplusplus
}
#endif

#endif
