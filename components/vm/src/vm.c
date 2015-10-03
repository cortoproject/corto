/*
 * cx_vm.c
 *
 *  Created on: Aug 16, 2013
 *      Author: sander
 */

#include "corto.h"

#include "vm.h"
#include "vm_operands.h"
#include "cx_convert.h"
#include "cx_err.h"
#include "cx_string.h"
#include "cx_util.h"
#include "cx_call.h"
#include "cx_mem.h"
#include "cx_type.h"
#include "cx_async.h"
#include "cx_def.h"
#include "cx__meta.h"
#include "inttypes.h"

#include "alloca.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-pedantic"
#pragma GCC diagnostic ignored "-Wstrict-aliasing"

#include "signal.h"

static cx_threadKey cx_stringConcatCacheKey;
static cx_threadKey cx_currentProgramKey;
typedef struct cx_vm_context cx_vm_context;

int CX_PROCEDURE_VM;

/* TLS structure for cx_currentProgramKey, used for debugging */
typedef struct cx_currentProgramData {
    vm_program stack[64];
    cx_vm_context *c[64];
    cx_uint32 sp;
}cx_currentProgramData;

/* TLS structure for cx_stringConcatCacheKey */
typedef struct cx_stringConcatCacheNode {
    vm_program program;
    cx_string str;
    cx_uint32 length;
}cx_stringConcatCacheNode;

typedef struct cx_stringConcatCache {
    cx_stringConcatCacheNode staged[256]; /* Limit the amount of allocations required for a
                                             stringconcatenation involving multiple elements
                                             with a factor 256 */
    cx_uint32 count;
    cx_uint32 length;
}cx_stringConcatCache;

/* Translation */
#define toJump(in) (((intptr_t)&&in))

/* Program control */
#define go() goto *(void*)(c.pc->op);
#define next() c.pc++; go()
#define jump(r) c.pc = (vm_op*)r; go()
#define fetchIc() c.ic = c.pc->ic
#define fetchLo() c.lo = c.pc->lo
#define fetchHi() c.hi = c.pc->hi
#define fetchDbl() c.dbl = *(cx_int64*)&c.pc->lo

/* Instruction implementation templates */
#define fetchOp1(op,code)\
        fetch_##code;\

#define fetchOp2(op,code)\
        fetch_##code;\
        fetch1_##code;\
        fetch2_##code;\

#define fetchOp3(op,code)\
        fetch_##code;\
        fetch1_##code;\
        fetch2_##code;\
        fetch3_##code;\


/* ---- Instruction implementations */
/* Set */
#define SET(type, code)\
    SET_##code:\
        fetchOp2(SET,code);\
        op1_##code = op2_##code;\
        next();

#define SETREF(type, code)\
    SETREF_##code:{\
        fetchOp2(SETREF,code);\
        cx_setref((cx_object*)&op1_##code, (cx_object)op2_##code);\
    }\
    next();

#define SETSTR(type, code)\
    SETSTR_##code:\
        fetchOp2(SETSTR,code);\
        if (op1_##code) cx_dealloc((cx_string)op1_##code);\
        op1_##code = op2_##code;\
        next();

#define SETSTRDUP(type, code)\
    SETSTRDUP_##code:\
        fetchOp2(SETSTRDUP,code);\
        if (op1_##code) cx_dealloc((cx_string)op1_##code);\
        if (op2_##code) {\
            op1_##code = (W_t)cx_strdup((cx_string)op2_##code);\
        } else {\
            op1_##code = 0;\
        }\
        next();

#define SETX(type, code)\
    SETX_##code:\
        fetchOp2(SETX, code)\
        op1_##code = (W_t)&op2_##code;\
        next();

#define ZERO(type, code)\
    ZERO_##code:\
        fetchOp2(ZERO, code)\
        memset(&op1_WRV,0,op2_WRV);\
        next();

#define INIT(type, code)\
    INIT_##code: {\
        fetchOp2(INIT, code)\
        cx_value v;\
        cx_valueValueInit(&v, NULL, (cx_type)op2_##code, &op1_##code);\
        cx_initv(&v);\
        next();\
    }

#define DEINIT(type, code)\
    DEINIT_##code: {\
        fetchOp2(DEINIT, code)\
        cx_value v;\
        cx_valueValueInit(&v, NULL, (cx_type)op2_##code, &op1_##code);\
        cx_deinitv(&v);\
        next();\
    }

/* Inc & dec */
#define INC(type,code)\
    INC_##code:\
        fetchOp1(INC,code);\
        ++ op1_##code;\
        next();\

#define DEC(type,code)\
    DEC_##code:\
        fetchOp1(DEC,code);\
        -- op1_##code;\
        next();\

/* Integer arithmetic */
#define ADDI(type,code)\
    ADDI_##code:\
        fetchOp2(ADDI,code);\
        op1_##code += op2_##code;\
        next();\

#define SUBI(type,code)\
    SUBI_##code:\
        fetchOp2(SUBI,code);\
        op1_##code -= op2_##code;\
        next();\

#define MULI(type,code)\
    MULI_##code:\
        fetchOp2(MULI,code);\
        op1_##code *= op2_##code;\
        next();\

#define DIVI(type,code)\
    DIVI_##code:\
        fetchOp2(DIVI,code);\
        op1_##code /= op2_##code;\
        next();\

#define MODI(type,code)\
    MODI_##code:\
        fetchOp2(MODI,code);\
        op1_##code %= op2_##code;\
        next();\

/* Floating point arithmetic */
typedef float Lf_t;
typedef double Df_t;

/* Union for converting between int-operand and float */
typedef union Li2f_t {
    L_t _i;
    Lf_t _f;
}Li2f_t;

typedef union Di2f_t {
    D_t _i;
    Df_t _f;
}Di2f_t;

#define ADDF(type,code)\
    ADDF_##code: {\
        type##i2f_t u;\
        fetchOp2(ADDF,code);\
        u._i = op2_##code;\
        *(type##f_t*)&op1_##code += u._f;\
        next();\
    }\

#define SUBF(type,code)\
    SUBF_##code: {\
        type##i2f_t u;\
        fetchOp2(SUBF,code);\
        u._i = op2_##code;\
        *(type##f_t*)&op1_##code -= u._f;\
        next();\
    }\

#define MULF(type,code)\
    MULF_##code: {\
        type##i2f_t u;\
        fetchOp2(MULF,code);\
        u._i = op2_##code;\
        *(type##f_t*)&op1_##code *= u._f;\
        next();\
}\

#define DIVF(type,code)\
    DIVF_##code: {\
        type##i2f_t u;\
        fetchOp2(DIVF,code);\
        u._i = op2_##code;\
        *(type##f_t*)&op1_##code /= u._f;\
        next();\
    }\

/* Bitwise operators */
#define AND(type,code)\
    AND_##code:\
        fetchOp2(AND,code);\
        op1_##code &= op2_##code;\
        next();\

#define XOR(type,code)\
    XOR_##code:\
        fetchOp2(XOR,code);\
        op1_##code ^= op2_##code;\
        next();\

#define OR(type,code)\
    OR_##code:\
        fetchOp2(OR,code);\
        op1_##code |= op2_##code;\
        next();\

#define NOT(type,code)\
    NOT_##code:\
        fetchOp1(NOT,code);\
        op1_##code = ~op1_##code;\
        next();\

#define SHIFT_LEFT(type, code)\
    SHIFT_LEFT_##code:\
        fetchOp2(SHIFT_LEFT, code);\
        op1_##code <<= op2_##code;\
        next();\

#define SHIFT_RIGHT(type, code)\
    SHIFT_RIGHT_##code:\
        fetchOp2(SHIFT_RIGHT, code);\
        op1_##code >>= op2_##code;\
        next();\

/* Staging */
#define STAGE1(type,code)\
    STAGE1_##code:\
        fetchOp1(STAGE1,code);\
        stage1_##type = op1_##code;\
        next();\

#define STAGE2(type,code)\
    STAGE2_##code: {\
        fetchOp2(STAGE2,code);\
        type##_t tmp1 = op1_##code;\
        stage2_##type = op2_##code;\
        stage1_##type = tmp1;\
        next();\
    }\


/* Expand compare operators for all stagetypes */
#define COND_OP_STAGETYPE(op, type, code, stageType, operator, cast)\
    op##_##code: \
        fetchOp1(op,code);\
        op1_##code = (cast)stage1_##stageType operator (cast)stage2_##stageType;\
        next();\

#define COND_OP_LD(op,type,code,operator,sign)\
    COND_OP_STAGETYPE(op##L,type,code,L,operator,L##sign##_t)\
    COND_OP_STAGETYPE(op##D,type,code,D,operator,D##sign##_t)

#define COND_OP(op,type,code,operator,sign)\
    COND_OP_STAGETYPE(op##B,type,code,B,operator,B##sign##_t)\
    COND_OP_STAGETYPE(op##S,type,code,S,operator,S##sign##_t)\
    COND_OP_LD(op,type,code,operator,sign)\


#define COND_OP1_STAGETYPE(op, type, code, stageType, operator)\
    op##_##code:\
        fetchOp1(op,code);\
        op1_##code = operator stage1_##stageType;\
        next();\

#define COND_OP1(op,type,code,operator)\
    COND_OP1_STAGETYPE(op##B,type,code,B,operator)\
    COND_OP1_STAGETYPE(op##S,type,code,S,operator)\
    COND_OP1_STAGETYPE(op##L,type,code,L,operator)\
    COND_OP1_STAGETYPE(op##D,type,code,D,operator)

/* Compare operators */
#define CAND(type,code) COND_OP(CAND,type,code,&&,)
#define COR(type,code) COND_OP(COR,type,code,||,)
#define CNOT(type,code) COND_OP1(CNOT,type,code,!)
#define CEQ(type,code) COND_OP(CEQ,type,code,==,)
#define CNEQ(type,code) COND_OP(CNEQ,type,code,!=,)

/* Signed comparisons */
#define CGTI(type,code) COND_OP(CGTI,type,code,>,s)
#define CLTI(type,code) COND_OP(CLTI,type,code,<,s)
#define CGTEQI(type,code) COND_OP(CGTEQI,type,code,>=,s)
#define CLTEQI(type,code) COND_OP(CLTEQI,type,code,<=,s)

/* Unsigned comparisons */
#define CGTU(type,code) COND_OP(CGTU,type,code,>,)
#define CLTU(type,code) COND_OP(CLTU,type,code,<,)
#define CGTEQU(type,code) COND_OP(CGTEQU,type,code,>=,)
#define CLTEQU(type,code) COND_OP(CLTEQU,type,code,<=,)

/* Floating point comparisons */
#define CGTF(type,code) COND_OP_LD(CGTF,type,code,>,f)
#define CLTF(type,code) COND_OP_LD(CLTF,type,code,<,f)
#define CGTEQF(type,code) COND_OP_LD(CGTEQF,type,code,>=,f)
#define CLTEQF(type,code) COND_OP_LD(CLTEQF,type,code,<=,f)

#define CEQSTR(type,code)\
    CEQSTR_##code:\
        fetchOp1(CEQSTR,code);\
        if (stage1_W && stage2_W) {\
            op1_##code = !strcmp((cx_string)stage1_W, (cx_string)stage2_W);\
        } else {\
            op1_##code = stage1_W == stage2_W;\
        }\
        next();

#define CNEQSTR(type,code)\
    CNEQSTR_##code:\
        fetchOp1(CNEQSTR,code);\
        if (stage1_W && stage2_W) {\
            op1_##code = strcmp((cx_string)stage1_W, (cx_string)stage2_W) != 0;\
        } else {\
            op1_##code = stage1_W != stage2_W;\
        }\
        next();

#define JEQ(type,code)\
    JEQ_##code:\
        fetch_##code;\
        fetch1_##code;\
        if (op1_##code) {\
            fetch2_##code;\
            jump(op2_##code);\
        }\
        next();\

#define JNEQ(type,code)\
    JNEQ_##code:\
        fetch_##code;\
        fetch1_##code;\
        if (op1_##code) {\
            next();\
        }\
        fetch2_##code;\
        jump(op2_##code);\

#define PUSH(type,code)\
    PUSH_##code:\
        fetchOp1(PUSH,code);\
        *(type##_t*)c.sp = op1_##code;\
        c.sp = CX_OFFSET(c.sp, sizeof(type##_t));\
        next();\

#define PUSHX(type,code)\
    PUSHX_##code:\
        fetchOp1(PUSHX,code);\
        *(cx_word*)c.sp = (cx_word)&op1_##code;\
        c.sp = CX_OFFSET(c.sp, sizeof(cx_word));\
        next();\

#define _PUSHANY(opx,_type,code,deref,_pc,v)\
    PUSHANY##opx##_##code:\
    fetchOp2(PUSHANY,code);\
    ((cx_any*)c.sp)->type = (cx_type)op2_##code;\
    ((cx_any*)c.sp)->value = (void*)deref _pc op1##v##_##code;\
    ((cx_any*)c.sp)->owner = FALSE;\
    c.sp = CX_OFFSET(c.sp, sizeof(cx_any));\
    next();\

#define PUSHANYX(_type,code)  _PUSHANY(X,_type,code,&,,)
#define PUSHANYV(_type,code)  _PUSHANY(V,_type,code,&,c.pc->,x)
#define PUSHANY(_type,code)   _PUSHANY(,_type,code,(cx_word),,)

#define CALL(type,code)\
    CALL_##code:\
        fetchOp1(CALL,code);\
        fetchHi();\
        cx_callb((cx_function)c.hi.w, &op1_##code, c.stack);\
        c.sp = c.stack; /* Reset stack pointer */\
        next();\

#define CALLVM(type,code)\
    CALLVM_##code:\
        fetchOp1(CALLVM,code);\
        fetchHi();\
        cx_vm_run_w_storage((vm_program)((cx_function)c.hi.w)->implData, c.stack, &op1_##code);\
        c.sp = c.stack; /* Reset stack pointer */\
        next();\

#define CALLVOID()\
    CALLVOID:\
        fetchHi();\
        cx_callb((cx_function)c.hi.w, NULL, c.stack);\
        c.sp = c.stack; /* Reset stack pointer */\
        next();\

#define CALLVMVOID()\
    CALLVMVOID:\
        fetchHi();\
        cx_vm_run_w_storage((vm_program)((cx_function)c.hi.w)->implData, c.stack, NULL);\
        c.sp = c.stack; /* Reset stack pointer */\
        next();\

#define CALLPTR(type,code)\
    CALLPTR_##code: {\
        fetchOp2(CALLPTR,code);\
        cx_delegatedata *ptr = (cx_delegatedata*)&op2_##code;\
        void *stackptr = c.stack;\
        if (!ptr->instance) {\
            stackptr = CX_OFFSET(stackptr, sizeof(cx_word));\
        }\
        cx_callb((cx_function)ptr->procedure, &op1_##code, stackptr);\
        c.sp = c.stack; /* Reset stack pointer */ \
        next();\
    }\

#define RET(type,code)\
    RET_##code:\
        fetchOp1(RET,code);\
        *(type##_t*)result = op1_##code;\
        goto STOP;

#define RETCPY(type,code)\
    RETCPY_##code:\
        fetchOp1(RETCPY,code);\
        fetchHi();\
        memcpy((type##_t*)result, &op1_##code, c.hi.w);\
        goto STOP;

#define CAST(type,code)\
    CAST_##code:\
        fetchOp2(CAST,code)\
        if (op1_##code) {\
            if (!cx_instanceof((cx_type)op2_##code, (cx_object)op1_##code)) {\
                cx_id id1,id2;\
                printf("Exception: invalid cast from type '%s' to '%s'\n", \
                    cx_fullname((cx_object)op2_##code, id1), \
                    cx_fullname(cx_typeof((cx_object)op1_##code), id2));\
                    goto STOP;\
            }\
        }\
        next();\

#define PCAST(type,code)\
    PCAST_##code: {\
        fetchOp2(PCAST,code)\
        cx_type fromType = (cx_type)stage1_W;\
        if (fromType->reference) {\
            fromType = (cx_type)cx_word_o;\
        }\
        cx_convert((cx_primitive)fromType, &op2_##code, (cx_primitive)stage2_W, &op1_##code);\
        next();\
    }

#define STRCAT(type,code)\
    STRCAT_##code:\
    {\
        cx_string str1,str2;\
        fetchOp2(STRCAT,code)\
        if ((str1 = (cx_string)op1_##code)) {\
            c.strcache->length += c.strcache->staged[c.strcache->count].length = strlen(str1);\
            c.strcache->staged[c.strcache->count].str = str1;\
            c.strcache->count++;\
        }\
        if ((str2 = (cx_string)op2_##code)) {\
            c.strcache->length += c.strcache->staged[c.strcache->count].length = strlen(str2);\
            c.strcache->staged[c.strcache->count].str = str2;\
            c.strcache->count++;\
        }\
        next();\
    }\

#define STRCPY(type,code)\
    STRCPY_##code:\
    {\
        cx_string result, ptr, str;\
        cx_uint32 i;\
        fetchOp2(STRCPY,code);\
        cx_uint32 length=0;\
        if ((str = (cx_string)op2_##code)) {\
            c.strcache->length += c.strcache->staged[c.strcache->count].length = strlen(str);\
            c.strcache->staged[c.strcache->count].str = str;\
            c.strcache->count++;\
        }\
        result = cx_alloc(c.strcache->length + 1);\
        ptr = result;\
        for(i=0; i<c.strcache->count; i++) {\
            length = c.strcache->staged[i].length;\
            memcpy(ptr, c.strcache->staged[i].str, length);\
            ptr += length;\
        }\
        *ptr = '\0';\
        c.strcache->count = 0;\
        c.strcache->length = 0;\
        op1_##code = (W_t)result;\
        next();\
    }\

#define NEW(type,code)\
    NEW_##code:\
        fetchOp2(NEW,code);\
        op1_##code = (cx_word)cx_declare((cx_object)op2_##code);\
        next();\

#define DEALLOC(type,code)\
    DEALLOC_##code:\
        fetchOp1(DEALLOC,code);\
        cx_dealloc((void*)op1_##code);\
        next();\

#define KEEP(type,code)\
    KEEP_##code:\
        fetchOp1(KEEP,code);\
        if (op1_##code) {\
            cx_claim((cx_object)op1_##code);\
        }\
        next();\

#define FREE(type,code)\
    FREE_##code:\
        fetchOp1(FREE,code);\
        if (op1_##code) {\
            cx_release((cx_object)op1_##code);\
        }\
        next();\

#define DEFINE(type,code)\
    DEFINE_##code:\
        fetchOp1(DEFINE,code);\
        if (!op1_##code) {\
            cx_error("Exception: null dereference in define");\
            goto STOP;\
        }\
        cx_define((cx_object)op1_##code);\
        next();\

#define UPDATE(type,code)\
    UPDATE_##code:\
        fetchOp1(UPDATE,code);\
        if (!op1_##code) {\
            cx_error("Exception: null dereference in updateFrom");\
            goto STOP;\
        }\
        if (cx_update((cx_object)op1_##code)) {\
            cx_error("Exception: %s", cx_lasterr());\
            goto error;\
        }\
        next();\

#define UPDATEBEGIN(type,code)\
    UPDATEBEGIN_##code:\
        fetchOp1(UPDATEBEGIN,code);\
        if (!op1_##code) {\
            cx_error("Exception: null dereference in updateBegin");\
            goto STOP;\
        }\
        if (cx_updateBegin((cx_object)op1_##code)) {\
            cx_error("Exception: %s", cx_lasterr());\
            goto error;\
        }\
        next();\

#define UPDATEEND(type,code)\
    UPDATEEND_##code:\
        fetchOp1(UPDATEEND,code);\
        if (!op1_##code) {\
            cx_error("Exception: null dereference in updateEnd");\
            goto STOP;\
        }\
        cx_updateEnd((cx_object)op1_##code);\
        next();\

#define UPDATEFROM(type,code)\
    UPDATEFROM_##code:\
        fetchOp2(UPDATEFROM, code);\
        if (!op1_##code) {\
            printf("Exception: null dereference in updateFrom\n");\
            goto STOP;\
        }\
        {\
            cx_object prev = cx_setOwner((cx_object)op2_##code);\
            cx_update((cx_object)op1_##code);\
            cx_setOwner(prev);\
        }\
        next();\

#define UPDATEENDFROM(type,code)\
    UPDATEENDFROM_##code:\
        fetchOp2(UPDATEENDFROM,code);\
        if (!op1_##code) {\
            printf("Exception: null dereference in updateEndFrom\n");\
            abort();\
            goto STOP;\
        }\
        {\
            cx_object prev = cx_setOwner((cx_object)op2_##code);\
            cx_updateEnd((cx_object)op1_##code);\
            cx_setOwner(prev);\
        }\
        next();\

#define UPDATECANCEL(type,code)\
    UPDATECANCEL_##code:\
        fetchOp1(UPDATECANCEL,code);\
        if (!op1_##code) {\
            printf("Exception: null dereference in updateCancel\n");\
            abort();\
            goto STOP;\
        }\
        cx_updateCancel((cx_object)op1_##code);\
        next();\

#define WAITFOR(type, code)\
    WAITFOR_##code:\
        fetchOp1(WAITFOR,code);\
        if (!op1_##code) {\
            printf("Exception: null dereference in waitfor");\
            abort();\
            goto STOP;\
        }\
        cx_waitfor((cx_object)op1_##code);\
        next();\

#define WAIT(type,code)\
    WAIT_##code:\
        fetchOp2(WAIT,code);\
        op1_##code = (W_t)cx_wait(0,0);\
        next();\

#ifdef CX_VM_BOUNDSCHECK
#define CHECK_BOUNDS(size, index)\
    if ((int)size <= (int)index) {\
        printf("Exception: element [%" PRIdPTR "] is out of bounds (collection size is %" PRId32 ")\n", index, size);\
        abort();\
        goto STOP;\
    }
#else
#define CHECK_BOUNDS(size, index)
#endif

#define ELEMA(type,code)\
    ELEMA_##code:\
        fetchOp3(ELEMA,code##V);\
        op1_##code##V += (L_t)op2_##code##V * op3_##code##V;\
        next();\

#define ELEMS(type,code)\
    ELEMS_##code:\
        fetchOp3(ELEMS,code##V);\
        {\
            cx_objectseq* seq = (cx_objectseq*)op1_##code##V;\
            CHECK_BOUNDS(seq->length, op2_##code##V);\
            op1_##code##V = (W_t)CX_OFFSET(seq->buffer, (L_t)op2_##code##V * op3_##code##V);\
        }\
        next();\

#define ELEML(type,code)\
    ELEML_##code:\
        fetchOp2(ELEML, code);\
        CHECK_BOUNDS(cx_llSize(*(cx_ll*)op1_##code), op2_##code)\
        op1_##code = (W_t)cx_llGet(*(cx_ll*)op1_##code, op2_##code);\
        next();

#define ELEMLX(type,code)\
    ELEMLX_##code:\
        fetchOp2(ELEMLX, code);\
        CHECK_BOUNDS(cx_llSize(*(cx_ll*)op1_##code), op2_##code)\
        op1_##code = (W_t)cx_llGetPtr(*(cx_ll*)op1_##code, op2_##code);\
        next();\

#define ELEMM(type,code)\
    ELEMM_##code:\
        fetchOp2(ELEMM, code);\
        op1_##code = (W_t)cx_rbtreeGet(*(cx_rbtree*)op1_##code, (void*)&op2_##code);\
        next();\

#define ELEMMX(type,code)\
    ELEMMX_##code:\
        fetchOp2(ELEMMX, code);\
        op1_##code = (W_t)cx_rbtreeGetPtr(*(cx_rbtree*)op1_##code, (void*)&op2_##code);\
        next();\

#define ITER_SET(type,code)\
    ITER_SET_##code:\
        fetchOp3(ITER_SET, code##V);\
        cx_iterator_set((void*)&op1_##code##V, (void*)&op2_##code##V, (void*)op3_##code##V);\
        next();\

/* op1 is hasNext, op2 is the result of next and op3 is the iterator */
#define ITER_NEXT(type,code)\
    ITER_NEXT_##code:\
        fetchOp2(ITER_NEXT, code);\
        op1_##code = (W_t)cx_iterator_next((void*)op2_##code);\
        next();\

#define JUMP(type, code)\
    JUMP_##code:\
        fetchOp1(JUMP, code);\
        jump(op1_##code);

#define MEMBER()\
    MEMBER:\
        fetch_LRR;\
        fetch1_LRR;\
        fetch2_LRR;\
        fetchLo();\
        if (!op2_LRR) {\
            printf("Error: dereferencing null\n");\
        }\
        op1_WRR = op2_WRR + c.lo.w;\
        next();

#define STOP()\
    STOP:\
        cx_vm_popSignalHandler();\
        return 0;\

/* ---- */

/* ---- Instruction expansion macro's */
#define INSTR0(arg)\
    arg()

#define INSTR1(type, arg, op1)\
    arg(type, type##op1)

#define INSTR1_COND(type, arg, op1)\
    arg(type, type##op1)

#define INSTR1_COND_LD(type, arg, op1)\
    arg(type, type##op1)

#define INSTR2(type, arg, op1, op2)\
    arg(type, type##op1##op2)

#define INSTR3(type, arg, op1, op2, op3)\
    arg(type, type##op1##op2##op3)
/* ---- */

/* ---- Jump expansion macro's */
#define JUMP0(arg)\
    case CX_VM_##arg: p[i].op = toJump(arg); break;

#define JUMP1(type, arg, op1)\
    case CX_VM_##arg##_##type##op1: p[i].op = toJump(arg##_##type##op1); break;

#define JUMP1_COND(type, arg, op1)\
    case CX_VM_##arg##B_##type##op1: p[i].op = toJump(arg##B_##type##op1); break;\
    case CX_VM_##arg##S_##type##op1: p[i].op = toJump(arg##S_##type##op1); break;\
    case CX_VM_##arg##L_##type##op1: p[i].op = toJump(arg##L_##type##op1); break;\
    case CX_VM_##arg##D_##type##op1: p[i].op = toJump(arg##D_##type##op1); break;

#define JUMP1_COND_LD(type, arg, op1)\
    case CX_VM_##arg##L_##type##op1: p[i].op = toJump(arg##L_##type##op1); break;\
    case CX_VM_##arg##D_##type##op1: p[i].op = toJump(arg##D_##type##op1); break;

#define JUMP2(type, arg, op1, op2)\
    case CX_VM_##arg##_##type##op1##op2: p[i].op = toJump(arg##_##type##op1##op2); break;

#define JUMP3(type, arg, op1, op2, op3)\
    case CX_VM_##arg##_##type##op1##op2##op3: p[i].op = toJump(arg##_##type##op1##op2##op3); break;
/* ---- */

/* ---- Jump expansion macro's */
#define STRING0(arg)\
    case CX_VM_##arg: result = vm_opToString(result, &p[i], #arg, "", "", "", ""); break;\

#define STRING1(type, arg, op1)\
    case CX_VM_##arg##_##type##op1: result = vm_opToString(result, &p[i], #arg, #type, #op1, "", ""); break;\

#define STRING1_COND(type, arg, op1)\
    case CX_VM_##arg##B_##type##op1: result = vm_opToString(result, &p[i], #arg "B", #type, #op1, "", ""); break;\
    case CX_VM_##arg##S_##type##op1: result = vm_opToString(result, &p[i], #arg "S", #type, #op1, "", ""); break;\
    case CX_VM_##arg##L_##type##op1: result = vm_opToString(result, &p[i], #arg "L", #type, #op1, "", ""); break;\
    case CX_VM_##arg##D_##type##op1: result = vm_opToString(result, &p[i], #arg "D", #type, #op1, "", ""); break;\

#define STRING1_COND_LD(type, arg, op1)\
    case CX_VM_##arg##L_##type##op1: result = vm_opToString(result, &p[i], #arg "L", #type, #op1, "", ""); break;\
    case CX_VM_##arg##D_##type##op1: result = vm_opToString(result, &p[i], #arg "D", #type, #op1, "", ""); break;\

#define STRING2(type, arg, op1, op2)\
    case CX_VM_##arg##_##type##op1##op2: result = vm_opToString(result, &p[i], #arg, #type, #op1, #op2, ""); break;\

#define STRING3(type, arg, op1, op2, op3)\
    case CX_VM_##arg##_##type##op1##op2##op3: result = vm_opToString(result, &p[i], #arg, #type, #op1, #op2, #op3); break;\
/* ---- */

struct cx_vm_context {
    vm_op *pc; /* Instruction counter */
    vm_parameter16 ic; /* First parameter */
    vm_parameter lo; /* Lo parameter */
    vm_parameter hi; /* Hi parameter */
    cx_uint64 dbl; /* Double parameter */
    cx_uint64 dbl2;
    vm_parameter stage1;
    vm_parameter stage2;
    void *stack, *sp;
    cx_stringConcatCache *strcache;

    /* Reserved space for interrupt program in case of SIGINT */
    vm_op interrupt[2];
};

#ifdef CX_VM_DEBUG
typedef void (*sigfunc)(int sig);
static sigfunc prevSegfaultHandler;
static sigfunc prevAbortHandler;
static sigfunc prevInterruptHandler;

sigfunc safe_signal (int sig, sigfunc h) {
    struct sigaction sa;
    struct sigaction osa;
    sa.sa_handler = h;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(sig, &sa, &osa) < 0) {
        return SIG_ERR;
    }
    return osa.sa_handler;
}

static void cx_vm_sigHardAbort(int sig) {
    CX_UNUSED(sig);
    exit(-1);
}

/* The VM signal handler */
static void cx_vm_sig(int sig) {
    cx_int32 sp;

    /* Unblock all signals */
    sigset_t mask_set, old_set;
    sigfillset(&mask_set);
    sigprocmask(SIG_UNBLOCK, &mask_set, &old_set);

    /* If any signal occurs again, do a hard abort */
    int i;
    for (i = 1; i < 35; i++) {
        signal(i, cx_vm_sigHardAbort);
    }

    cx_currentProgramData *programData = cx_threadTlsGet(cx_currentProgramKey);

    if ((sig == SIGSEGV) || (sig == SIGBUS)) {
        printf("Access violation (%d)\n", sig);
    }
    if (sig == SIGABRT) {
        printf("Abort\n");
    }
    if (sig == SIGINT) {
        for(sp = programData->sp-1; sp>=0; sp--) {
            vm_program program = programData->stack[sp];
            programData->c[sp]->interrupt[0].op = program->program[program->size-1].op;
            programData->c[sp]->interrupt[1].op = program->program[program->size-1].op;
            programData->c[sp]->pc = programData->c[sp]->interrupt;
        }
        return;
    }

    /* Walk the stack, print frames */
    for(sp = programData->sp-1; sp>=0; sp--) {
        cx_id id, file;
        vm_program program = programData->stack[sp];

        cx_uint32 line = program->debugInfo[((cx_word)programData->c[sp]->pc - (cx_word)program->program)/sizeof(vm_op)].line;

        if (program->filename) {
            sprintf(file, "%s:", program->filename);
        } else {
            *file = '\0';
        }
        if (program->function) {
            printf("[%d] %s (%s%d)\n", sp+1, cx_fullname(program->function, id), file, line);
        } else {
            printf("[%d] <main> (%s%d)\n", sp+1, file, line);
        }

        /* Print program with location of crash */
#ifdef CX_IC_TRACING
        if(sp == (cx_int32)programData->sp-1) {
            cx_string str = vm_programToString(program, programData->c[sp]->pc);
            printf("\n%s\n", str);
            cx_dealloc(str);
        }
#endif
    }

    printf("\n");
    exit(-1);
}

/* Push a program to the exception stack (see pushSignalHandler) */
static void cx_vm_pushCurrentProgram(vm_program program, cx_vm_context *c) {
    cx_currentProgramData *data = NULL;
    if (!cx_currentProgramKey) {
        cx_threadTlsKey(&cx_currentProgramKey, NULL);
    }
    data = cx_threadTlsGet(cx_currentProgramKey);
    if (!data) {
        data = cx_alloc(sizeof(cx_currentProgramData));
        data->sp = 0;
        cx_threadTlsSet(cx_currentProgramKey, data);
    }
    data->stack[data->sp] = program;
    data->c[data->sp] = c;
    data->sp++;
}

/* Pop a program from the exception stack */
static void cx_vm_popCurrentProgram(void) {
    cx_currentProgramData *data = cx_threadTlsGet(cx_currentProgramKey);
    data->sp--;
}

/* Push a program to the signal handler stack. This will allow backtracing the
 * stack when an error occurs. */
static void cx_vm_pushSignalHandler(vm_program program, cx_vm_context *c) {
    sigfunc result = safe_signal(SIGSEGV, cx_vm_sig);
    if (result == SIG_ERR) {
        cx_error("failed to install signal handler for SIGSEGV");
    } else {
        prevSegfaultHandler = result;
    }

    result = safe_signal(SIGBUS, cx_vm_sig);
    if (result == SIG_ERR) {
        cx_error("failed to install signal handler for SIGSEGV");
    } else {
        prevSegfaultHandler = result;
    }

    result = safe_signal(SIGABRT, cx_vm_sig);
    if (result == SIG_ERR) {
        cx_error("failed to install signal handler for SIGABRT");
    } else {
        prevAbortHandler = result;
    }

    result = safe_signal(SIGINT, cx_vm_sig);
    if (result == SIG_ERR) {
        cx_error("failed to install signal handler for SIGINT");
    } else {
        prevInterruptHandler = result;
    }

    /* Store current program in TLS */
    cx_vm_pushCurrentProgram(program, c);
}

/* Pop a program from the signal handler stack */
static void cx_vm_popSignalHandler(void) {
    if (safe_signal(SIGSEGV, prevSegfaultHandler) == SIG_ERR) {
        cx_error("failed to uninstall signal handler for SIGSEGV");
    } else {
        prevSegfaultHandler = NULL;
    }
    if (safe_signal(SIGABRT, prevAbortHandler) == SIG_ERR) {
        cx_error("failed to uninstall signal handler for SIGABRT");
    } else {
        prevAbortHandler = NULL;
    }
    if (safe_signal(SIGINT, prevInterruptHandler) == SIG_ERR) {
        cx_error("failed to uninstall signal handler for SIGINT");
    } else {
        prevInterruptHandler = NULL;
    }

    cx_vm_popCurrentProgram();
}
#else
#define cx_vm_pushSignalHandler(p,c)
#define cx_vm_popSignalHandler()
#endif

static int32_t cx_vm_run_w_storage(vm_program program, void* reg, void *result) {
    cx_vm_context c;
    c.strcache = cx_threadTlsGet(cx_stringConcatCacheKey);

    /* The signal handler will catch any exceptions and report when (and where)
     * an error is occurring */
    cx_vm_pushSignalHandler(program, &c);

    /* Translate program if required
     * This will translate from the VM instruction codes (the constants from
     * the cx_vm_opKind enumeration) to the actual addresses of the
     * implementations. This allows the execution of code to jump directly
     * from one instruction to the next, thereby skipping the overhead of
     * an evaluation-then-jump construction like a switch statement. */
    if (!program->translated)  {
        uint32_t size = program->size;
        vm_op *p = program->program;
        uint32_t i;
        for(i=0; i<size;i++) {
#ifdef CX_VM_DEBUG
            p[i].opKind = p[i].op; /* Cache actual opKind for debugging purposes */
#endif
            switch(p[i].op) {
                /* ---- Expand jump macro's */
                OPS_EXP(JUMP)
                default:
                    cx_assert(0, "invalid instruction in sequence %d @ %d", p[i].op, i);
                    break;
            }
        }
        program->translated = TRUE;
    }

    /* Prepare context */
    c.stack = alloca(program->stack);
    c.sp = c.stack;
    c.pc = program->program;

    /* Run program */
    go();

    /* ---- Expand instruction macro's */
    OPS_EXP(INSTR);

error:
    return -1;
}

/* Delete a string concatenation cache (cleanup function for thread
 * specific memory) */
static void cx_stringConcatCacheClean(void *data) {
    cx_dealloc(data);
}

/* Create a string concatenation cache */
static void cx_stringConcatCacheCreate(void) {
    cx_stringConcatCache *concatCache;
    if (!cx_stringConcatCacheKey) {
        cx_threadTlsKey(&cx_stringConcatCacheKey, cx_stringConcatCacheClean);
    }

    concatCache = cx_threadTlsGet(cx_stringConcatCacheKey);
    if (!concatCache) {
        concatCache = cx_alloc(sizeof(cx_stringConcatCache));
        memset(concatCache, 0, sizeof(cx_stringConcatCache));
        cx_threadTlsSet(cx_stringConcatCacheKey, concatCache);
    }
}

/* Execute a program */
int32_t vm_run(vm_program program, cx_stringSeq argv, void *result) {
    void *storage = NULL;
    if (program->storage) {
        storage = alloca(program->storage);
    }
    *(void**)storage = &argv;
    cx_stringConcatCacheCreate();
    return cx_vm_run_w_storage(program, storage, result);
}

/* This function converts a single instruction to a string */
#ifdef CX_IC_TRACING
char * vm_opToString(
    char * string, vm_op *instr, const char *op, const char *type, const char *lvalue, const char *rvalue, const char* fetch) {
    char *result = string;

    if (fetch && strlen(fetch)) {
        result = strappend(
            result,
            "%s_%s%s%s_%s %u %u %u %u\n",
            op, type, lvalue, rvalue, fetch, instr->ic.b._1, instr->ic.b._2, instr->lo.w, instr->hi.w);
    } else {
        result = strappend(
            result,
            "%s_%s%s%s %hu %hu %u %u\n",
            op, type, lvalue, rvalue, instr->ic.b._1, instr->ic.b._2, instr->lo.w, instr->hi.w);
    }

    return result;
}
#endif

/* Convert an instruction sequence to a string */
char * vm_programToString(vm_program program, vm_op *addr) {
    char * result = NULL;
    cx_int32 shown = 4;
    CX_UNUSED(program);

/* Since these strings can occupy a lot of space, they're only compiled in
 * when these two macros are enabled */
#ifdef CX_IC_TRACING
    vm_op *p = program->program;
    uint32_t i;

#ifndef CX_VM_DEBUG
    if (!program->translated) {
        printf("cannot convert active program to string with non-debug version\n");
        abort();
    }
#endif
    /* Prefix '...' to string if the code section is not at the start */
    if (addr && ((addr - p) > shown)) {
        result = strappend(result, "  ...\n");
    }

    /* Loop instructions, prefix address */
    for(i=0; i<program->size;i++) {
        cx_int32 diff = addr - &p[i];
        if (!addr || ((diff <= shown) && (diff >= -shown))) {
            vm_opKind kind;

            if (addr) {
                if (addr == &p[i]) {
                    result = strappend(result, "> %u: ", &p[i]);
                } else {
                    result = strappend(result, "  %u: ", &p[i]);
                }
            } else {
                result = strappend(result, "%u: ", &p[i]);
            }
    #ifdef CX_VM_DEBUG
            if (program->translated) {
                kind = p[i].opKind;
            } else {
                kind = p[i].op;
            }
    #else
            kind = p[i].op;
    #endif
            switch(kind) {
                /* ---- Expand string conversion macro's */
                OPS_EXP(STRING)
                default:
                    cx_assert(0, "invalid instruction %d in sequence @ %d", p[i].op, i);
                    break;
            }
        }
    }
    /* Append '...' to string if the code section is not at the end */
    if (addr && ((&p[program->size-1] - addr) > 5)) {
        result = strappend(result, "  ...\n");
    }
#endif
    return result;
}

#pragma GCC diagnostic pop

/* Create a new VM program */
vm_program vm_programNew(char *filename, cx_object function) {
    vm_program result;

    result = cx_alloc(sizeof(vm_program_s));
    result->program = NULL;
    result->debugInfo = NULL;
    result->filename = filename ? cx_strdup(filename) : NULL;
    result->function = function;
    result->size = 0;
    result->maxSize = 0;
    result->stack = 0;
    result->storage = 0;
    result->translated = FALSE;

    return result;
}

/* Free a VM program */
void vm_programFree(vm_program program) {
    if (program) {
        if (program->program) {
            cx_dealloc(program->program);
        }
        cx_dealloc(program);
    }
}

/* Add new instruction to a VM program */
vm_op *vm_programAddOp(vm_program program, uint32_t line) {
    /* Try to be smart with memory allocations, don't allocate new memory
     * every time an instruction is added. */
    if (!program->size) {
        program->size = 1;
        program->maxSize = 8;
    } else {
        program->size ++;
        if (program->size > program->maxSize) {
            program->maxSize *= 2;
        }
    }
    program->program = cx_realloc(program->program, program->maxSize * sizeof(vm_op));
    program->debugInfo = cx_realloc(program->debugInfo, program->maxSize * sizeof(vm_debugInfo));

    /* Initialize instruction and debug data to zero */
    memset(&program->program[program->size-1], 0, sizeof(vm_op));
    memset(&program->debugInfo[program->size-1], 0, sizeof(vm_debugInfo));
    program->debugInfo[program->size-1].line = line;

    /* Return potentially reallocd program */
    return &program->program[program->size-1];
}

/* Language binding function that calls a VM function */
void vm_call(cx_function f, cx_void* result, void* args) {
    vm_program program;
    void *storage = NULL;

    /* Obtain instruction sequence */
    program = (vm_program)f->implData;

    /* Allocate a storage for a program. This memory will
     * store all local variables, and space required to
     * prepare a stack for calling functions */
    storage = alloca(program->storage);
    memcpy(storage, args, f->size); /* Copy parameters into storage */

    /* Thread specific cache that speeds up string concatenations */
    cx_stringConcatCacheCreate();

    /* Execute the instructions */
    cx_vm_run_w_storage(program, storage, result);
}

/* Language binding function that frees a VM function */
void vm_callDestruct(cx_function f) {
    vm_programFree((vm_program)f->implData);
}

int vmMain(int argc, char* argv[]) {
    CX_UNUSED(argc);
    CX_UNUSED(argv);
    CX_PROCEDURE_VM = cx_callRegisterBinding(vm_call, NULL, NULL, (cx_callDestructHandler)vm_callDestruct);
    return 0;
}

