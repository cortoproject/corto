/*
 * cx_vm.h
 *
 *  Created on: Aug 16, 2013
 *      Author: sander
 */

#ifndef CX_VM_H_
#define CX_VM_H_

#include "stdint.h"
#include "cx_object.h"

#ifdef __cplusplus
extern "C" {
#endif

/** Instruction width postfixes
 * B    byte   (8 byte)
 * S    short  (16 bit)
 * L    long   (32 bit)
 * D    double (64 bit)
 *
 ** Instruction operand postfixes
 * V    value
 * R    register (addressed by 16 bit operand)
 * P    pointer  (word)
 * Q    pointer  (stored in registry, addressed by 16 bit)
 *
 ** Instruction type postfixes
 * I    signed integer
 * U    unsigned integer
 * F    floating point
 * S    string
 *
 ** Instruction type postfixes for collections
 * A    array
 * S    sequence
 * L    list
 * M    map
 */

#define VM_OPERAND(op,code)\
    CX_VM_##op##_##code\

#define VM_OPERAND_PQRV(op,type,lvalue)\
    VM_OPERAND(op, type##lvalue##V),\
    VM_OPERAND(op, type##lvalue##R),\
    VM_OPERAND(op ,type##lvalue##P),\
    VM_OPERAND(op, type##lvalue##Q)

#define VM_OPERAND_PQR(op,type,lvalue)\
    VM_OPERAND(op, type##lvalue##R),\
    VM_OPERAND(op ,type##lvalue##P),\
    VM_OPERAND(op, type##lvalue##Q)

#define VM_1OP_PQRV(op)\
    VM_OPERAND_PQR(op,B,),\
    VM_OPERAND_PQR(op,S,),\
    VM_OPERAND_PQR(op,L,),\
    VM_OPERAND_PQR(op,D,),\
    VM_OPERAND(op,BV),\
    VM_OPERAND(op,SV),\
    VM_OPERAND(op,LV),\
    VM_OPERAND(op,DV)

#define VM_1OP_ANY(op)\
    VM_OPERAND_PQR(op,B,),\
    VM_OPERAND_PQR(op,S,),\
    VM_OPERAND_PQR(op,L,),\
    VM_OPERAND_PQR(op,D,),\
    VM_OPERAND(op,BV),\
    VM_OPERAND(op,SV),\
    VM_OPERAND(op,LV),\
    /* Double values cannot be encoded together with a type for the any. Therefore the only three \
     * types that can occur with DV are hard-encoded in the following three instructions. */\
    VM_OPERAND(op,DVU),\
    VM_OPERAND(op,DVI),\
    VM_OPERAND(op,DVF)

#define VM_1OP(op)\
    VM_OPERAND_PQR(op,B,),\
    VM_OPERAND_PQR(op,S,),\
    VM_OPERAND_PQR(op,L,),\
    VM_OPERAND_PQR(op,D,)

/* Expand operations for every type to match staged values */
#define VM_1OP_COND(op)\
    VM_OPERAND_PQR(op##B,B,),\
    VM_OPERAND_PQR(op##S,B,),\
    VM_OPERAND_PQR(op##L,B,),\
    VM_OPERAND_PQR(op##D,B,)

#define VM_1OP_COND_LD(op)\
    VM_OPERAND_PQR(op##L,B,),\
    VM_OPERAND_PQR(op##D,B,)

#define VM_LVALUE(op,type,postfix)\
    VM_OPERAND_##postfix(op,type,R),\
    VM_OPERAND_##postfix(op,type,P),\
    VM_OPERAND_##postfix(op,type,Q)

#define VM_LVALUE_V(op,type,postfix)\
    VM_LVALUE(op,type,postfix),\
    VM_OPERAND_##postfix(op,type,V)

#define VM_2OP(op,postfix)\
    VM_LVALUE(op,B,postfix),\
    VM_LVALUE(op,S,postfix),\
    VM_LVALUE(op,L,postfix),\
    VM_LVALUE(op,D,postfix)

#define VM_2OP_V(op,postfix)\
    VM_LVALUE_V(op,B,postfix),\
    VM_LVALUE_V(op,S,postfix),\
    VM_LVALUE_V(op,L,postfix),\
    VM_LVALUE_V(op,D,postfix)

#define VM_2OP_SLD(op,postfix)\
    VM_LVALUE(op,S,postfix),\
    VM_LVALUE(op,L,postfix),\
    VM_LVALUE(op,D,postfix)

#define VM_2OP_BLD(op,postfix)\
    VM_LVALUE(op,B,postfix),\
    VM_LVALUE(op,L,postfix),\
    VM_LVALUE(op,D,postfix)

#define VM_2OP_BSD(op,postfix)\
    VM_LVALUE(op,B,postfix),\
    VM_LVALUE(op,S,postfix),\
    VM_LVALUE(op,D,postfix)

#define VM_2OP_BSL(op,postfix)\
    VM_LVALUE(op,B,postfix),\
    VM_LVALUE(op,S,postfix),\
    VM_LVALUE(op,L,postfix)

#define VM_2OP_LD(op,postfix)\
    VM_LVALUE(op,L,postfix),\
    VM_LVALUE(op,D,postfix)

#define VM_2OP_L(op,postfix)\
    VM_LVALUE(op,L,postfix)

#define VM_2OP_W(op,postfix)\
    VM_LVALUE(op,W,postfix)

#define VM_2OP_D(op,postfix)\
    VM_LVALUE(op,D,postfix)

#define VM_2OPV_W(op,postfix)\
    VM_OPERAND_##postfix(op,W,V),\
    VM_LVALUE(op,W,postfix)

// #define VM_3OP_W(op)\ // TODO

typedef enum cx_vmOpKind {

    /* Copy a value to a variable/object */
    VM_2OP(SET,PQRV),

    /* Special set instruction that takes the address of a register so calculations can be performed on it.
     * This is useful when calculating dynamic offsets, for example when using arrays i.c.w. a variable index. */
    CX_VM_SET_WRX,

    /* Specialized SET for references */
    VM_2OP_W(SETREF,PQRV),

    /* Specialized SET for strings */
    VM_2OP_W(SETSTR,PQRV),
    VM_2OP_W(SETSTRDUP,PQRV),

    /* Initialize register-memory to zero */
    CX_VM_ZERO,

    /* Call initializer */
    CX_VM_INIT,

    /* Inc & dec */
    VM_1OP(INC),
    VM_1OP(DEC),

    /* Integer operations */
    VM_2OP(ADDI,PQRV),
    VM_2OP(SUBI,PQRV),
    VM_2OP(MULI,PQRV),
    VM_2OP(DIVI,PQRV),
    VM_2OP(MODI,PQRV),

    /* Float operations */
    VM_2OP_LD(ADDF,PQRV),
    VM_2OP_LD(SUBF,PQRV),
    VM_2OP_LD(MULF,PQRV),
    VM_2OP_LD(DIVF,PQRV),

    /* Logical operators */
    VM_2OP(AND,PQRV),
    VM_2OP(XOR,PQRV),
    VM_2OP(OR,PQRV),
    VM_1OP(NOT),

    /* Shift operators */
    VM_2OP(SHIFT_LEFT,PQRV),
    VM_2OP(SHIFT_RIGHT,PQRV),

    /* Stage 1 operand */
    VM_1OP_PQRV(STAGE1),

    /* Stage 2 operands */
    VM_2OP_V(STAGE2,PQRV),
    
    /* Stage 1 double operand in stage variable 2 */
    CX_VM_STAGE12_DP,
    CX_VM_STAGE12_DV,
    
    /* Comparisons */
    VM_1OP_COND(CAND),
    VM_1OP_COND(COR),
    VM_1OP_COND(CNOT),
    VM_1OP_COND(CEQ),
    VM_1OP_COND(CNEQ),

    /* Signed comparisons */
    VM_1OP_COND(CGTI),
    VM_1OP_COND(CLTI),
    VM_1OP_COND(CGTEQI),
    VM_1OP_COND(CLTEQI),

    /* Unsigned comparisons */
    VM_1OP_COND(CGTU),
    VM_1OP_COND(CLTU),
    VM_1OP_COND(CGTEQU),
    VM_1OP_COND(CLTEQU),

    /* Float comparisons */
    VM_1OP_COND_LD(CGTF),
    VM_1OP_COND_LD(CLTF),
    VM_1OP_COND_LD(CGTEQF),
    VM_1OP_COND_LD(CLTEQF),

    /* String comparisons */
    VM_OPERAND_PQR(CEQSTR,B,),
    VM_OPERAND_PQR(CNEQSTR,B,),

    /* Program control */
    VM_1OP(JEQ),
    VM_1OP(JNEQ),
    CX_VM_JUMP,

    /* Calculate member-address from register base */
    CX_VM_MEMBER, /* Takes destination register, base register and offset */

    /* Collections */
    VM_OPERAND_PQRV(ELEMA,W,R),  /* Takes register(1), elementsize(3) and index variable(2) */
    VM_OPERAND_PQRV(ELEMS,W,R),  /* Takes register(1), elementsize(3) and index variable(2) */
    VM_OPERAND_PQRV(ELEML,W,R),  /* Takes register(1) and index variable(2) */
    VM_OPERAND_PQRV(ELEMLX,W,R), /* Takes register(1) and index variable(2) - obtains pointer to listnode */
    VM_OPERAND_PQRV(ELEMM,W,R),  /* Takes register(1) and index variable(2) */
    VM_OPERAND_PQRV(ELEMMX,W,R), /* Takes register(1) and index variable(2) - obtains pointer to mapnode */

    VM_2OP_W(ITER_SET,PQRV),     /* Assign iterator */
    VM_2OP_W(ITER_NEXT,PQRV),

    
    /* Calls */
    VM_1OP_PQRV(PUSH),
    VM_1OP(PUSHX),                    /* Push address of value */
    VM_OPERAND_PQRV(PUSHANY,W,),      /* Push value as any */
    VM_1OP_ANY(PUSHANYX),             /* Push address of value as any */

    VM_OPERAND_PQR(CALL,W,),          /* Call function with returnvalue */
    CX_VM_CALLVOID,                   /* Call function with void returnvalue */
    VM_OPERAND_PQR(CALLVM,W,),        /* Call vm function with returnvalue */
    CX_VM_CALLVMVOID,                 /* Call vm function with void returnvalue */
    VM_2OP_W(CALLPTR,PQRV),           /* Call a delegate */
    VM_1OP(RET),                      /* Return value smaller than 8 bytes */
    VM_OPERAND_PQR(RETCPY,L,),        /* Return value larger than 8 bytes */

    /* Casts */
    VM_2OP(I2FL,PQRV),
    VM_2OP(I2FD,PQRV),
    VM_2OP_LD(F2IB,PQRV),
    VM_2OP_LD(F2IS,PQRV),
    VM_2OP_LD(F2IL,PQRV),
    VM_2OP_LD(F2ID,PQRV),
    VM_2OP(I2S,PQRV),
    VM_2OP(U2S,PQRV),
    VM_2OP_LD(F2S,PQRV),
    
    /* Primitive casts */
    VM_2OP(PCAST,PQR),

    /* Reference casting */
    VM_2OP_W(CAST,PQRV),

    /* String manipulations */
    VM_2OPV_W(STRCAT,PQRV),
    VM_2OP_W(STRCPY,PQRV),

    /* Memory management */
    VM_LVALUE(NEW,W,PQRV),
    VM_OPERAND_PQRV(DEALLOC,W,),
    VM_OPERAND_PQRV(KEEP,W,),
    VM_OPERAND_PQRV(FREE,W,),

    /* Object state */
    VM_OPERAND_PQRV(DEFINE,W,),

    /* Notifications */
    VM_OPERAND_PQRV(UPDATE,W,),
    VM_OPERAND_PQRV(UPDATEBEGIN,W,),
    VM_OPERAND_PQRV(UPDATEEND,W,),
    VM_2OP_W(UPDATEFROM,PQR),
    VM_2OP_W(UPDATEENDFROM,PQR),
    VM_OPERAND_PQRV(UPDATECANCEL,W,),

    /* Waiting */
    VM_OPERAND_PQRV(WAITFOR,W,), /* Add objects to wait-queue */
    VM_2OP_W(WAIT,PQRV), /* Do the actual wait */

    CX_VM_STOP /* Stop the current program (or function) */
} cx_vmOpKind;

typedef union cx_vmParameter16 {
    struct {
        uint16_t _1;
        uint16_t _2;
    } b;
    uint16_t s;
    intptr_t w;
}cx_vmParameter16;

typedef union cx_vmParameter {
    cx_vmParameter16 s;
    intptr_t w;
}cx_vmParameter;

typedef struct cx_vmOpAddr {
    uint16_t jump;
    cx_vmParameter16 p;
}cx_vmOpAddr;

typedef struct cx_vmOp {
    intptr_t op; /* direct jump to address of next operation */
    cx_vmParameter16 ic;
    cx_vmParameter lo;
    cx_vmParameter hi;
#ifdef CX_VM_DEBUG
    cx_vmOpKind opKind; /* Actual operation kind. Only used for debugging purposes */
#endif
}cx_vmOp;

typedef struct cx_vmDebugInfo {
    uint32_t line;
}cx_vmDebugInfo;
    
typedef struct cx_vmProgram_s *cx_vmProgram;
typedef struct cx_vmProgram_s {
    cx_vmOp *program;
    cx_vmDebugInfo *debugInfo;
    cx_object function;
    char *filename;
    uint32_t size;
    uint32_t maxSize;
    uint32_t storage;
    uint32_t stack;
    uint8_t translated;
}cx_vmProgram_s;

void cx_call_vm(cx_function f, cx_void* result, void* args);
int32_t cx_vm_run(cx_vmProgram program, void *result);
char *cx_vmProgram_toString(cx_vmProgram program, cx_vmOp *addr);
cx_vmProgram cx_vmProgram_new(char *filename, cx_object function);
void cx_vmProgram_free(cx_vmProgram program);
cx_vmOp *cx_vmProgram_addOp(cx_vmProgram program, uint32_t line);

#ifdef __cplusplus
}
#endif

#endif /* CX_VM_H_ */
