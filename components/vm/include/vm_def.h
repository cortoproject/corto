
#ifndef CORTO_VM_DEF_H_
#define CORTO_VM_DEF_H_

#include "vm_expansion.h"

#ifdef __cplusplus
extern "C" {
#endif

/** Instruction width postfixes
 * B    byte   (8 byte)
 * S    short  (16 bit)
 * L    long   (32 bit)
 * D    double (64 bit)
 * W    word   (32 or 64 bit)
 *
 ** Instruction operand postfixes
 * V    value
 * R    register (addressed by 16 bit operand)
 * P    pointer  (word)
 * Q    pointer  (stored in registry, addressed by 16 bit)
 * A    address  (similar to V, but always word size)
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

#define OPS_EXP(expand)\
    OPS_EXP_EXT(expand,,)

#define OPS_EXP_EXT(expand, typeAction, opAction)\
    OP2_EXP(expand##2, SET, BSLD, PQR, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, SETX, W, R, R, typeAction, opAction)\
    OP2_EXP(expand##2, SETREF, W, PQR, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, SETSTRDUP, W, PQR, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, ZERO, W, R, V, typeAction, opAction)\
    OP2_EXP(expand##2, INIT, W, R, V, typeAction, opAction)\
    OP2_EXP(expand##2, DEINIT, W, R, V, typeAction, opAction)\
    OP1_EXP(expand##1, INC, BSLD, PQR, typeAction, opAction)\
    OP1_EXP(expand##1, DEC, BSLD, PQR, typeAction, opAction)\
    OP2_EXP(expand##2, ADDI, BSLD, PQR, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, SUBI, BSLD, PQR, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, MULI, BSLD, PQR, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, DIVI, BSLD, PQR, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, MODI, BSLD, PQR, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, ADDF, LD, PQR, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, SUBF, LD, PQR, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, MULF, LD, PQR, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, DIVF, LD, PQR, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, AND, BSLD, PQR, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, XOR, BSLD, PQR, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, OR, BSLD, PQR, PQRV, typeAction, opAction)\
    OP1_EXP(expand##1, NOT, BSLD, PQR, typeAction, opAction)\
    OP2_EXP(expand##2, SHIFT_LEFT, BSLD, PQR, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, SHIFT_RIGHT, BSLD, PQR, PQRV, typeAction, opAction)\
    OP1_EXP(expand##1, STAGE1, BSLD, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, STAGE2, BSLD, PQRV, PQRV, typeAction, opAction)\
    OP1_EXP(expand##1_COND, CAND, B, PQR, typeAction, opAction)\
    OP1_EXP(expand##1_COND, COR, B, PQR, typeAction, opAction)\
    OP1_EXP(expand##1_COND, CNOT, B, PQR, typeAction, opAction)\
    OP1_EXP(expand##1_COND, CEQ, B, PQR, typeAction, opAction)\
    OP1_EXP(expand##1_COND, CNEQ, B, PQR, typeAction, opAction)\
    OP1_EXP(expand##1_COND, CGTU, B, PQR, typeAction, opAction)\
    OP1_EXP(expand##1_COND, CLTU, B, PQR, typeAction, opAction)\
    OP1_EXP(expand##1_COND, CGTEQU, B, PQR, typeAction, opAction)\
    OP1_EXP(expand##1_COND, CLTEQU, B, PQR, typeAction, opAction)\
    OP1_EXP(expand##1_COND, CGTI, B, PQR, typeAction, opAction)\
    OP1_EXP(expand##1_COND, CLTI, B, PQR, typeAction, opAction)\
    OP1_EXP(expand##1_COND, CGTEQI, B, PQR, typeAction, opAction)\
    OP1_EXP(expand##1_COND, CLTEQI, B, PQR, typeAction, opAction)\
    OP1_EXP(expand##1_COND_LD, CGTF, B, PQR, typeAction, opAction)\
    OP1_EXP(expand##1_COND_LD, CLTF, B, PQR, typeAction, opAction)\
    OP1_EXP(expand##1_COND_LD, CGTEQF, B, PQR, typeAction, opAction)\
    OP1_EXP(expand##1_COND_LD, CLTEQF, B, PQR, typeAction, opAction)\
    OP1_EXP(expand##1, CEQSTR, B, PQR, typeAction, opAction)\
    OP1_EXP(expand##1, CNEQSTR, B, PQR, typeAction, opAction)\
    OP2_EXP(expand##2, JEQ, BSLD, PQR, A, typeAction, opAction)\
    OP2_EXP(expand##2, JNEQ, BSLD, PQR, A, typeAction, opAction)\
    OP1_EXP(expand##1, JUMP, W, A, typeAction, opAction)\
    OP0_EXP(expand##0, MEMBER)\
    OP2_EXP(expand##2, ELEMA, W, R, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, ELEMS, W, R, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, ELEML, W, R, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, ELEMLX, W, R, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, ELEMM, W, R, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, ELEMMX, W, R, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, ITER_SET, W, PQR, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, ITER_NEXT, W, PQR, PQRV, typeAction, opAction)\
    OP1_EXP(expand##1, PUSH, BSLD, PQRV, typeAction, opAction) /* Regular push */\
    OP1_EXP(expand##1, PUSHX, BSLD, R, typeAction, opAction) /* Push address of a register */\
    OP2_EXP(expand##2, PUSHANY, W, PQRV, A, typeAction, opAction) /* Push any value */\
    OP2_EXP(expand##2, PUSHANYX, BSLD, R, A, typeAction, opAction) /* Push address of a register as any */\
    OP2_EXP(expand##2, PUSHANYV, BSLD, V, A, typeAction, opAction) /* Push value as any */\
    OP1_EXP(expand##1, CALL, W, PQR, typeAction, opAction)\
    OP0_EXP(expand##0, CALLVOID)\
    OP1_EXP(expand##1, CALLVM, W, PQR, typeAction, opAction)\
    OP0_EXP(expand##0, CALLVMVOID)\
    OP2_EXP(expand##2, CALLPTR, W, PQR, PQR, typeAction, opAction)\
    OP1_EXP(expand##1, RET, BSLD, PQR, typeAction, opAction)\
    OP1_EXP(expand##1, RETCPY, L, PQR, typeAction, opAction)\
    OP2_EXP(expand##2, PCAST, BSLD, PQR, PQR, typeAction, opAction)\
    OP2_EXP(expand##2, CAST, W, PQR, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, STRCAT, W, PQRV, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, STRCPY, W, PQR, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, NEW, W, PQR, PQRV, typeAction, opAction)\
    OP1_EXP(expand##1, DEALLOC, W, PQRV, typeAction, opAction)\
    OP1_EXP(expand##1, KEEP, W, PQRV, typeAction, opAction)\
    OP1_EXP(expand##1, FREE, W, PQRV, typeAction, opAction)\
    OP1_EXP(expand##1, DEFINE, W, PQRV, typeAction, opAction)\
    OP1_EXP(expand##1, UPDATE, W, PQRV, typeAction, opAction)\
    OP1_EXP(expand##1, UPDATEBEGIN, W, PQRV, typeAction, opAction)\
    OP1_EXP(expand##1, UPDATEEND, W, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, UPDATEFROM, W, PQR, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, UPDATEENDFROM, W, PQR, PQRV, typeAction, opAction)\
    OP1_EXP(expand##1, UPDATECANCEL, W, PQRV, typeAction, opAction)\
    OP1_EXP(expand##1, WAITFOR, W, PQRV, typeAction, opAction)\
    OP2_EXP(expand##2, WAIT, W, PQR, PQRV, typeAction, opAction)\
    OP0_EXP(expand##0, STOP)

#ifdef __cplusplus
}
#endif

#endif
