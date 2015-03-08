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
#include "cx_vm_expansion.h"

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

#define CONST1(type, arg, op1)\
    CX_VM_##arg##_##type##op1,

#define CONST1_COND(type, arg, op1)\
    CX_VM_##arg##B##_##type##op1,\
    CX_VM_##arg##S##_##type##op1,\
    CX_VM_##arg##L##_##type##op1,\
    CX_VM_##arg##D##_##type##op1,

#define CONST1_COND_LD(type, arg, op1)\
    CX_VM_##arg##L##_##type##op1,\
    CX_VM_##arg##D##_##type##op1,    

#define CONST2(type, arg, op1, op2)\
    CX_VM_##arg##_##type##op1##op2,

#define CONST3(type, arg, op1, op2, op3)\
    CX_VM_##arg##_##type##op1##op2##op3,

typedef enum cx_vmOpKind {

    /* Copy a value to a variable/object */
    OP2_EXP(CONST2, SET, BSLD, PQR, PQRV)

    /* Special set instruction that takes the address of a register so calculations can be performed on it.
     * This is useful when calculating dynamic offsets, for example when using arrays i.c.w. a variable index. */
    CX_VM_SET_WRX,

    /* Specialized SET for references */
    OP2_EXP(CONST2, SETREF, W, PQR, PQRV)

    /* Specialized SET for strings */
    OP2_EXP(CONST2, SETSTR, W, PQR, PQRV)
    OP2_EXP(CONST2, SETSTRDUP, W, PQR, PQRV)

    /* Initialize register-memory to zero */
    CX_VM_ZERO,

    /* Call initializer */
    CX_VM_INIT,

    /* Inc & dec */
    OP1_EXP(CONST1, INC, BSLD, PQR)
    OP1_EXP(CONST1, DEC, BSLD, PQR)

    /* Integer operations */
    OP2_EXP(CONST2, ADDI, BSLD, PQR, PQRV)
    OP2_EXP(CONST2, SUBI, BSLD, PQR, PQRV)
    OP2_EXP(CONST2, MULI, BSLD, PQR, PQRV)
    OP2_EXP(CONST2, DIVI, BSLD, PQR, PQRV)
    OP2_EXP(CONST2, MODI, BSLD, PQR, PQRV)

    /* Float operations */
    OP2_EXP(CONST2, ADDF, LD, PQR, PQRV)
    OP2_EXP(CONST2, SUBF, LD, PQR, PQRV)
    OP2_EXP(CONST2, MULF, LD, PQR, PQRV)
    OP2_EXP(CONST2, DIVF, LD, PQR, PQRV)

    /* Logical operators */
    OP2_EXP(CONST2, AND, BSLD, PQR, PQRV)
    OP2_EXP(CONST2, XOR, BSLD, PQR, PQRV)
    OP2_EXP(CONST2, OR, BSLD, PQR, PQRV)
    OP1_EXP(CONST1, NOT, BSLD, PQR)

    /* Shift operators */
    OP2_EXP(CONST2, SHIFT_LEFT, BSLD, PQR, PQRV)
    OP2_EXP(CONST2, SHIFT_RIGHT, BSLD, PQR, PQRV)

    /* Stage 1 operand */
    OP1_EXP(CONST1, STAGE1, BSLD, PQRV)

    /* Stage 2 operands */
    OP2_EXP(CONST2, STAGE2, BSLD, PQRV, PQRV)
    
    /* Stage 1 double operand in stage variable 2 */
    CX_VM_STAGE12_DP,
    CX_VM_STAGE12_DV,
    
    /* Comparisons (uses staged operands) */
    OP1_EXP(CONST1_COND, CAND, B, PQR)
    OP1_EXP(CONST1_COND, COR, B, PQR)
    OP1_EXP(CONST1_COND, CNOT, B, PQR)
    OP1_EXP(CONST1_COND, CEQ, B, PQR)
    OP1_EXP(CONST1_COND, CNEQ, B, PQR)

    /* Unsigned comparisons (uses staged operands) */
    OP1_EXP(CONST1_COND, CGTU, B, PQR)
    OP1_EXP(CONST1_COND, CLTU, B, PQR)
    OP1_EXP(CONST1_COND, CGTEQU, B, PQR)
    OP1_EXP(CONST1_COND, CLTEQU, B, PQR)

    /* Signed comparisons (uses staged operands) */
    OP1_EXP(CONST1_COND, CGTI, B, PQR)
    OP1_EXP(CONST1_COND, CLTI, B, PQR)
    OP1_EXP(CONST1_COND, CGTEQI, B, PQR)
    OP1_EXP(CONST1_COND, CLTEQI, B, PQR)

    /* Float comparisons (uses staged operands) */
    OP1_EXP(CONST1_COND_LD, CGTF, B, PQR)
    OP1_EXP(CONST1_COND_LD, CLTF, B, PQR)
    OP1_EXP(CONST1_COND_LD, CGTEQF, B, PQR)
    OP1_EXP(CONST1_COND_LD, CLTEQF, B, PQR)

    /* String comparisons (uses staged operands) */
    OP1_EXP(CONST1, CEQSTR, B, PQR)
    OP1_EXP(CONST1, CNEQSTR, B, PQR)

    /* Program control */
    OP1_EXP(CONST1, JEQ, BSLD, PQR)
    OP1_EXP(CONST1, JNEQ, BSLD, PQR)
    CX_VM_JUMP,

    /* Calculate member-address from register base */
    CX_VM_MEMBER, /* destination(1), base(2), offset(3) */

    /* Collections */
    OP2_EXP(CONST2, ELEMA, W, R, PQRV)   /* Takes register(1), elementsize(3) and index variable(2) */
    OP2_EXP(CONST2, ELEMS, W, R, PQRV)   /* Takes register(1), elementsize(3) and index variable(2) */
    OP2_EXP(CONST2, ELEML, W, R, PQRV)   /* Takes register(1) and index variable(2) */
    OP2_EXP(CONST2, ELEMLX, W, R, PQRV)  /* Takes register(1) and index variable(2) - obtains pointer to listnode */
    OP2_EXP(CONST2, ELEMM, W, R, PQRV)   /* Takes register(1) and index variable(2) */
    OP2_EXP(CONST2, ELEMMX, W, R, PQRV)  /* Takes register(1) and index variable(2) - obtains pointer to mapnode */

    OP2_EXP(CONST2, ITER_SET, W, PQR, PQRV)        /* Iter set:  iterator(1), collection(2) */
    OP3_EXP(CONST3, ITER_NEXT, W, PQR, PQR, PQRV)  /* Iter next: hasNext(1), next(2), iterator(3)*/
    
    /* Push data on stack */
    OP1_EXP(CONST1, PUSH, BSLD, PQRV) /* Push value */
    OP1_EXP(CONST1, PUSHX, BSLD, PQR) /* Push address of register: TODO - do we need P and Q? */
    OP1_EXP(CONST1, PUSHANY, W, PQRV)
    OP1_EXP(CONST1, PUSHANYX, BSL, PQRV)
    OP1_EXP(CONST1, PUSHANYX, D, PQR)
    CX_VM_PUSHANYX_DVI,
    CX_VM_PUSHANYX_DVU,
    CX_VM_PUSHANYX_DVF,

    /* Call function */
    OP1_EXP(CONST1, CALL, W, PQR)     /* Call function with returnvalue */   
    CX_VM_CALLVOID,                   /* Call function with void returnvalue */
    OP1_EXP(CONST1, CALLVM, W, PQR)   /* Call vm function with returnvalue */
    CX_VM_CALLVMVOID,                 /* Call vm function with void returnvalue */
    OP2_EXP(CONST2, CALLPTR, W, PQR, PQRV)   /* Call a delegate */
    OP1_EXP(CONST1, RET, BSLD, PQR)   /* Return value smaller or equal than 8 bytes */
    OP1_EXP(CONST1, RETCPY, L, PQR)   /* Return value larger than 8 bytes */

    /* Casts */
    OP2_EXP(CONST2, I2FL, BSLD, PQR, PQRV)
    OP2_EXP(CONST2, I2FD, BSLD, PQR, PQRV)
    OP2_EXP(CONST2, F2IB, LD, PQR, PQRV)
    OP2_EXP(CONST2, F2IS, LD, PQR, PQRV)
    OP2_EXP(CONST2, F2IL, LD, PQR, PQRV)
    OP2_EXP(CONST2, F2ID, LD, PQR, PQRV)

    OP2_EXP(CONST2, I2S, BSLD, PQR, PQRV)
    OP2_EXP(CONST2, U2S, BSLD, PQR, PQRV)
    OP2_EXP(CONST2, F2S, LD, PQR, PQRV)
    
    /* Primitive casts */
    OP2_EXP(CONST2, PCAST, BSLD, PQR, PQR)

    /* Reference casting */
    OP2_EXP(CONST2, CAST, W, PQR, PQRV)

    /* String manipulations */
    OP2_EXP(CONST2, STRCAT, W, PQRV, PQRV)
    OP2_EXP(CONST2, STRCPY, W, PQR, PQRV)

    /* Memory management */
    OP2_EXP(CONST2, NEW, W, PQR, PQRV)
    OP1_EXP(CONST1, DEALLOC, W, PQRV)
    OP1_EXP(CONST1, KEEP, W, PQRV)
    OP1_EXP(CONST1, FREE, W, PQRV)

    /* Object state */
    OP1_EXP(CONST1, DEFINE, W, PQRV)

    /* Notifications */
    OP1_EXP(CONST1, UPDATE, W, PQRV)
    OP1_EXP(CONST1, UPDATEBEGIN, W, PQRV)
    OP1_EXP(CONST1, UPDATEEND, W, PQRV)
    OP2_EXP(CONST2, UPDATEFROM, W, PQR, PQRV)
    OP2_EXP(CONST2, UPDATEENDFROM, W, PQR, PQRV)
    OP1_EXP(CONST1, UPDATECANCEL, W, PQRV)

    /* Waiting */
    OP1_EXP(CONST1, WAITFOR, W, PQRV)    /* Add objects to wait-queue */
    OP2_EXP(CONST2, WAIT, W, PQR, PQRV)  /* Do the wait */

    CX_VM_STOP /* Stop the current program */
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
