
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

#define OPS_EXP(expand)\
    OP2_EXP(expand##2, SET, BSLD, PQR, PQRV)\
    OP2_EXP(expand##2, SETX, W, R, R)\
    OP2_EXP(expand##2, SETREF, W, PQR, PQRV)\
    OP2_EXP(expand##2, SETSTR, W, PQR, PQRV)\
    OP2_EXP(expand##2, SETSTRDUP, W, PQR, PQRV)\
    OP2_EXP(expand##2, ZERO, W, R, V)\
    OP2_EXP(expand##2, INIT, W, R, V)\
    OP1_EXP(expand##1, INC, BSLD, PQR)\
    OP1_EXP(expand##1, DEC, BSLD, PQR)\
    OP2_EXP(expand##2, ADDI, BSLD, PQR, PQRV)\
    OP2_EXP(expand##2, SUBI, BSLD, PQR, PQRV)\
    OP2_EXP(expand##2, MULI, BSLD, PQR, PQRV)\
    OP2_EXP(expand##2, DIVI, BSLD, PQR, PQRV)\
    OP2_EXP(expand##2, MODI, BSLD, PQR, PQRV)\
    OP2_EXP(expand##2, ADDF, LD, PQR, PQRV)\
    OP2_EXP(expand##2, SUBF, LD, PQR, PQRV)\
    OP2_EXP(expand##2, MULF, LD, PQR, PQRV)\
    OP2_EXP(expand##2, DIVF, LD, PQR, PQRV)\
    OP2_EXP(expand##2, AND, BSLD, PQR, PQRV)\
    OP2_EXP(expand##2, XOR, BSLD, PQR, PQRV)\
    OP2_EXP(expand##2, OR, BSLD, PQR, PQRV)\
    OP1_EXP(expand##1, NOT, BSLD, PQR)\
    OP2_EXP(expand##2, SHIFT_LEFT, BSLD, PQR, PQRV)\
    OP2_EXP(expand##2, SHIFT_RIGHT, BSLD, PQR, PQRV)\
    OP1_EXP(expand##1, STAGE1, BSLD, PQRV)\
    OP2_EXP(expand##2, STAGE2, BSLD, PQRV, PQRV)\
    OP1_EXP(expand##1_COND, CAND, B, PQR)\
    OP1_EXP(expand##1_COND, COR, B, PQR)\
    OP1_EXP(expand##1_COND, CNOT, B, PQR)\
    OP1_EXP(expand##1_COND, CEQ, B, PQR)\
    OP1_EXP(expand##1_COND, CNEQ, B, PQR)\
    OP1_EXP(expand##1_COND, CGTU, B, PQR)\
    OP1_EXP(expand##1_COND, CLTU, B, PQR)\
    OP1_EXP(expand##1_COND, CGTEQU, B, PQR)\
    OP1_EXP(expand##1_COND, CLTEQU, B, PQR)\
    OP1_EXP(expand##1_COND, CGTI, B, PQR)\
    OP1_EXP(expand##1_COND, CLTI, B, PQR)\
    OP1_EXP(expand##1_COND, CGTEQI, B, PQR)\
    OP1_EXP(expand##1_COND, CLTEQI, B, PQR)\
    OP1_EXP(expand##1_COND_LD, CGTF, B, PQR)\
    OP1_EXP(expand##1_COND_LD, CLTF, B, PQR)\
    OP1_EXP(expand##1_COND_LD, CGTEQF, B, PQR)\
    OP1_EXP(expand##1_COND_LD, CLTEQF, B, PQR)\
    OP1_EXP(expand##1, CEQSTR, B, PQR)\
    OP1_EXP(expand##1, CNEQSTR, B, PQR)\
    OP1_EXP(expand##1, JEQ, BSLD, PQR)\
    OP1_EXP(expand##1, JNEQ, BSLD, PQR)\
    OP0_EXP(expand##0, JUMP)\
    OP0_EXP(expand##0, MEMBER) /* destination(1), base(2), offset(3) */\
    OP2_EXP(expand##2, ELEMA, W, R, PQRV)   /* Takes register(1), elementsize(3) and index variable(2) */\
    OP2_EXP(expand##2, ELEMS, W, R, PQRV)   /* Takes register(1), elementsize(3) and index variable(2) */\
    OP2_EXP(expand##2, ELEML, W, R, PQRV)   /* Takes register(1) and index variable(2) */\
    OP2_EXP(expand##2, ELEMLX, W, R, PQRV)  /* Takes register(1) and index variable(2) - obtains pointer to listnode */\
    OP2_EXP(expand##2, ELEMM, W, R, PQRV)   /* Takes register(1) and index variable(2) */\
    OP2_EXP(expand##2, ELEMMX, W, R, PQRV)  /* Takes register(1) and index variable(2) - obtains pointer to mapnode */\
    OP2_EXP(expand##2, ITER_SET, W, PQR, PQRV)        /* Iter set:  iterator(1), collection(2) */\
    OP3_EXP(expand##3, ITER_NEXT, W, PQR, PQR, PQRV)  /* Iter next: hasNext(1), next(2), iterator(3)*/\
    OP1_EXP(expand##1, PUSH, BSLD, PQRV) /* Push value */\
    OP1_EXP(expand##1, PUSHX, BSLD, PQR) /* Push address of register: TODO - do we need P and Q? */\
    OP1_EXP(expand##1, PUSHANY, W, PQRV)\
    OP1_EXP(expand##1, PUSHANYX, BSLD, PQR)\
    OP1_EXP(expand##1, PUSHANYXO, BSL, V)\
    OP1_EXP(expand##1_ANY, PUSHANYXO, D, V)\
    OP1_EXP(expand##1, CALL, W, PQR)     /* Call function with returnvalue */\
    OP0_EXP(expand##0, CALLVOID)         /* Call function with void returnvalue */\
    OP1_EXP(expand##1, CALLVM, W, PQR)   /* Call vm function with returnvalue */\
    OP0_EXP(expand##0, CALLVMVOID)       /* Call vm function with void returnvalue */\
    OP2_EXP(expand##2, CALLPTR, W, PQR, PQR)   /* Call a delegate */\
    OP1_EXP(expand##1, RET, BSLD, PQR)   /* Return value smaller or equal than 8 bytes */\
    OP1_EXP(expand##1, RETCPY, L, PQR)   /* Return value larger than 8 bytes */\
    OP2_EXP(expand##2, PCAST, BSLD, PQR, PQR)\
    OP2_EXP(expand##2, CAST, W, PQR, PQRV)\
    OP2_EXP(expand##2, STRCAT, W, PQRV, PQRV)\
    OP2_EXP(expand##2, STRCPY, W, PQR, PQRV)\
    OP2_EXP(expand##2, NEW, W, PQR, PQRV)\
    OP1_EXP(expand##1, DEALLOC, W, PQRV)\
    OP1_EXP(expand##1, KEEP, W, PQRV)\
    OP1_EXP(expand##1, FREE, W, PQRV)\
    OP1_EXP(expand##1, DEFINE, W, PQRV)\
    OP1_EXP(expand##1, UPDATE, W, PQRV)\
    OP1_EXP(expand##1, UPDATEBEGIN, W, PQRV)\
    OP1_EXP(expand##1, UPDATEEND, W, PQRV)\
    OP2_EXP(expand##2, UPDATEFROM, W, PQR, PQRV)\
    OP2_EXP(expand##2, UPDATEENDFROM, W, PQR, PQRV)\
    OP1_EXP(expand##1, UPDATECANCEL, W, PQRV)\
    OP1_EXP(expand##1, WAITFOR, W, PQRV)    /* Add objects to wait-queue */\
    OP2_EXP(expand##2, WAIT, W, PQR, PQRV)  /* Do the wait */\
    OP0_EXP(expand##0, STOP) /* Stop the current program */


