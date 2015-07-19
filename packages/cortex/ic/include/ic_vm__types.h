
#ifndef ic_vm__types_H
#define ic_vm__types_H

#include "ic.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ic_vmLabel {
    cx_uint32 id;
    cx_uint32 pc;
    void *referees[256]; /* The jumps to this label. At assemble-time, the exact address of the label is not yet known
                          * so this information is filled in after the program is assembled for each referee */
    cx_uint32 refereeCount;
}ic_vmLabel;

typedef struct ic_vmInlineFunction {
    cx_vmProgram program;
    cx_function function;
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

typedef struct ic_vmStorage ic_vmStorage;
struct ic_vmStorage {
    ic_storage ic;
    cx_uint32 firstUsed;
    cx_uint32 lastUsed;
    void *referees[512]; /* The jumps to this accumulator. At assemble-time, the exact address of the accumulator is not yet known
                          * so this information is filled in after the program is assembled for each referee */
    cx_uint32 refereeCount;
    cx_word addr;

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
    cx_bool allocated; /* Does the storage occupy space */
    cx_bool alwaysCompute; /* Does the storage needs to be computed regardless of base */
};

/* Administration that keeps track of claims accumulators have on the register */
typedef struct ic_registerClaim {
    ic_vmStorage *storage;
    cx_uint16 addr;
    cx_uint16 size;
    cx_uint32 start;
    cx_uint32 end;
}ic_registerClaim;

ic_vmOperand ic_getVmOperand(ic_vmProgram *program, ic_derefKind deref, cx_bool isArgument, ic_node node);

#ifdef __cplusplus
}
#endif

#endif
