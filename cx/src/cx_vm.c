/*
 * cx_vm.c
 *
 *  Created on: Aug 16, 2013
 *      Author: sander
 */

#include "cx_vm.h"
#include "cx__vm_operands.h"
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

cx_bool CX_DEBUG_ENABLED = 0;

#include "signal.h"

static cx_threadKey cx_stringConcatCacheKey;
static cx_threadKey cx_currentProgramKey;
typedef struct cx_vm_context cx_vm_context;

/* TLS structure for cx_currentProgramKey, used for debugging */
typedef struct cx_currentProgramData {
    cx_vmProgram stack[64];
    cx_vm_context *c[64];
    cx_uint32 sp;
}cx_currentProgramData;

/* TLS structure for cx_stringConcatCacheKey */
typedef struct cx_stringConcatCacheNode {
    cx_vmProgram program;
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
#define jump(r) c.pc = (cx_vmOp*)r; go()
#define fetchIc() c.ic = c.pc->ic
#define fetchLo() c.lo = c.pc->lo
#define fetchHi() c.hi = c.pc->hi
#define fetchDbl() c.dbl = *(cx_int64*)&c.pc->lo

/** Instruction postfixes
 * B    byte   (8 byte)
 * S    short  (16 bit)
 * L    long   (word)
 * D    double (64 bit)
 *
 * V    value
 * R    register (addressed by 8 bit operand)
 * P    pointer  (word)
 * Q    pointer  (stored in registry, addressed by 8 bit operand)
 * L    label     (only used in jump-instructions)
 */

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

/* Set */
#define SET(type,code)\
    SET_##code:\
        fetchOp2(SET,code);\
        op1_##code = op2_##code;\
        next();\

#define SETREF(type,code)\
    SETREF_##code:{\
        fetchOp2(SETREF,code);\
        cx_set((cx_object*)&op1_##code, (cx_object)op2_##code);\
    }\
    next();\

#define SETSTR(type,code)\
    SETSTR_##code:\
        fetchOp2(SETSTR,code);\
        if (op1_##code) cx_dealloc((cx_string)op1_##code);\
        op1_##code = op2_##code;\
        next();\

#define SETSTRDUP(type,code)\
    SETSTRDUP_##code:\
        fetchOp2(SETSTRDUP,code);\
        if (op1_##code) cx_dealloc((cx_string)op1_##code);\
        if (op2_##code) {\
            op1_##code = (W_t)cx_strdup((cx_string)op2_##code);\
        } else {\
            op1_##code = 0;\
        }\
        next();\

/* Inc & dec */
#define INC(type,code)\
    INC_##code:\
        fetchOp1(INC,code);\
        ++ op_##code;\
        next();\

#define DEC(type,code)\
    DEC_##code:\
        fetchOp1(DEC,code);\
        -- op_##code;\
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
        op_##code = ~op_##code;\
        next();\

/* Staging */
#define STAGE1(type,code)\
    STAGE1_##code:\
        fetchOp1(STAGE1,code);\
        stage1_##type = op_##code;\
        next();\

/* Staging */
#define STAGE12(type,code)\
    STAGE12_##code: {\
        uint64_t tmp = c.dbl;\
        fetchOp1(STAGE12,code);\
        stage2_##type = op_##code;\
        c.dbl = tmp;\
        next();\
    }\

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
        op_##code = (cast)stage1_##stageType operator (cast)stage2_##stageType;\
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
        op_##code = operator stage1_##stageType;\
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
            op_##code = !strcmp((cx_string)stage1_W, (cx_string)stage2_W);\
        } else {\
            op_##code = stage1_W == stage2_W;\
        }\
        next();

#define CNEQSTR(type,code)\
    CNEQSTR_##code:\
        fetchOp1(CNEQSTR,code);\
        if (stage1_W && stage2_W) {\
            op_##code = strcmp((cx_string)stage1_W, (cx_string)stage2_W);\
        } else {\
            op_##code = stage1_W != stage2_W;\
        }\
        next();

#define JEQ(type,code)\
    JEQ_##code:\
        fetch_##code##L;\
        fetch1_##code##L;\
        if (op1_##code##L) {\
            fetch2_##code##L;\
            jump(op2_##code##L);\
        }\
        next();\

#define JNEQ(type,code)\
    JNEQ_##code:\
        fetch_##code##L;\
        fetch1_##code##L;\
        if (op1_##code##L) {\
            next();\
        }\
        fetch2_##code##L;\
        jump(op2_##code##L);\

#define PUSH(type,code)\
    PUSH_##code:\
        fetchOp1(PUSH,code);\
        *(type##_t*)c.sp = op_##code;\
        c.sp = CX_OFFSET(c.sp, sizeof(type##_t));\
        next();\

#define PUSHX(type,code)\
    PUSHX_##code:\
        fetchOp1(PUSHX,code);\
        *(cx_word*)c.sp = (cx_word)&op_##code;\
        c.sp = CX_OFFSET(c.sp, sizeof(cx_word));\
        next();\

#define _PUSHANY(opx,_type,code,postfix,deref,typearg,_pc,v)\
    PUSHANY##opx##_##code##postfix:\
    fetchOp1(PUSHANY,code);\
    fetchHi();\
    ((cx_any*)c.sp)->type = (cx_type)typearg;\
    ((cx_any*)c.sp)->value = (void*)deref _pc op##v##_##code;\
    ((cx_any*)c.sp)->owner = FALSE;\
    c.sp = CX_OFFSET(c.sp, sizeof(cx_any));\
    next();\

#define PUSHANYX(_type,code)    _PUSHANY(X,_type,code,,&,c.hi.w,,)
#define PUSHANYX_U(_type,code)  _PUSHANY(X,_type,code,U,&,cx_uint64_o,,)
#define PUSHANYX_I(_type,code)  _PUSHANY(X,_type,code,I,&,cx_int64_o,,)
#define PUSHANYX_F(_type,code)  _PUSHANY(X,_type,code,F,&,cx_float64_o,,)

#define PUSHANYX_V(_type,code)  _PUSHANY(X,_type,code,,&,c.hi.w,c.pc->,x)
#define PUSHANYX_VU(_type,code) _PUSHANY(X,_type,code,U,&,cx_uint64_o,c.pc->,x)
#define PUSHANYX_VI(_type,code) _PUSHANY(X,_type,code,I,&,cx_int64_o,c.pc->,x)
#define PUSHANYX_VF(_type,code) _PUSHANY(X,_type,code,F,&,cx_float64_o,c.pc->,x)

#define PUSHANY(_type,code)     _PUSHANY(,_type,code,,(cx_word),c.hi.w,,)
#define PUSHANY_U(_type,code)   _PUSHANY(,_type,code,U,(cx_word),cx_uint64_o,,)
#define PUSHANY_I(_type,code)   _PUSHANY(,_type,code,I,(cx_word),cx_int64_o,,)
#define PUSHANY_F(_type,code)   _PUSHANY(,_type,code,F,(cx_word),cx_float64_o,,)

#define CALL(type,code)\
    CALL_##code:\
        fetchOp1(CALL,code);\
        fetchHi();\
        cx_callb((cx_function)c.hi.w, &op_##code, c.stack);\
        c.sp = c.stack; /* Reset stack pointer */\
        next();\

#define CALLVM(type,code)\
    CALLVM_##code:\
        fetchOp1(CALLVM,code);\
        fetchHi();\
        cx_vm_run_w_storage((cx_vmProgram)((cx_function)c.hi.w)->implData, c.stack, &op_##code);\
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
        cx_vm_run_w_storage((cx_vmProgram)((cx_function)c.hi.w)->implData, c.stack, NULL);\
        c.sp = c.stack; /* Reset stack pointer */\
        next();\

#define CALLPTR(type,code)\
    CALLPTR_##code: {\
        fetchOp2(CALLPTR,code);\
        cx_procptrdata *ptr = (cx_procptrdata*)&op2_##code;\
        void *stackptr = c.stack;\
        if (!ptr->instance) {\
            stackptr = ((cx_word*)stackptr) + 1;\
        }\
        cx_callb((cx_function)ptr->procedure, &op1_##code, stackptr);\
        c.sp = c.stack; /* Reset stack pointer */ \
        next();\
    }\

#define RET(type,code)\
    RET_##code:\
        fetchOp1(RET,code);\
        *(type##_t*)result = op_##code;\
        goto STOP;

#define RETCPY(type,code)\
    RETCPY_##code:\
        fetchOp1(RETCPY,code);\
        fetchHi();\
        memcpy((type##_t*)result, &op_##code, c.hi.w);\
        goto STOP;

#define CAST(type,code)\
    CAST_##code:\
        fetchOp2(CAST,code)\
        if (!op1_##code) {\
            printf("Exception: null dereference in cast\n");\
            abort();\
            goto STOP;\
        }\
        if (!cx_instanceof((cx_typedef)op2_##code, (cx_object)op1_##code)) {\
            cx_id id1,id2;\
            printf("Exception: invalid cast from type '%s' to '%s'\n", \
                cx_fullname((cx_object)op2_##code, id1), \
                cx_fullname(cx_typeof((cx_object)op1_##code), id2));\
                goto STOP;\
        }\
        next();\

#define PCAST(type,code)\
    PCAST_##code:\
        fetchOp2(PCAST,code)\
        cx_convert(cx_primitive(stage1_W), &op2_##code, cx_primitive(stage2_W), &op1_##code);\
        next();

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
        result = cx_malloc(c.strcache->length + 1);\
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
        fetchOp1(NEW,code);\
        fetchOp2(NEW,code);\
        op1_##code = (cx_word)cx_new((cx_typedef)op2_##code);\
        next();\

#define DEALLOC(type,code)\
    DEALLOC_##code:\
        fetchOp1(DEALLOC,code);\
        cx_dealloc((void*)op_##code);\
        next();\

#define KEEP(type,code)\
    KEEP_##code:\
        fetchOp1(KEEP,code);\
        if (op_##code) {\
            cx_keep_ext(NULL, (cx_object)op_##code, "KEEP(vm)");\
        }\
        next();\

#define FREE(type,code)\
    FREE_##code:\
        fetchOp1(FREE,code);\
        if (op_##code) {\
            cx_free_ext(NULL, (cx_object)op_##code, "FREE(vm)");\
        }\
        next();\

#define DEFINE(type,code)\
    DEFINE_##code:\
        fetchOp1(DEFINE,code);\
        if (!op_##code) {\
            printf("Exception: null dereference in define\n");\
            abort();\
            goto STOP;\
        }\
        cx_define((cx_object)op_##code);\
        next();\

#define UPDATE(type,code)\
    UPDATE_##code:\
        fetchOp1(UPDATE,code);\
        if (!op_##code) {\
            printf("Exception: null dereference in updateFrom\n");\
            abort();\
            goto STOP;\
        }\
        cx_updateFrom((cx_object)op_##code,NULL);\
        next();\

#define UPDATEBEGIN(type,code)\
    UPDATEBEGIN_##code:\
        fetchOp1(UPDATEBEGIN,code);\
        if (!op_##code) {\
            printf("Exception: null dereference in updateBegin\n");\
            abort();\
            goto STOP;\
        }\
        cx_updateBegin((cx_object)op_##code);\
        next();\

#define UPDATEEND(type,code)\
    UPDATEEND_##code:\
        fetchOp1(UPDATEEND,code);\
        if (!op_##code) {\
            printf("Exception: null dereference in updateEnd\n");\
            abort();\
            goto STOP;\
        }\
        cx_updateEndFrom((cx_object)op_##code,NULL);\
        next();\

#define UPDATEFROM(type,code)\
    UPDATEFROM_##code:\
        fetchOp2(UPDATEFROM, code);\
        if (!op1_##code) {\
            printf("Exception: null dereference in updateFrom\n");\
            abort();\
            goto STOP;\
        }\
        cx_updateFrom((cx_object)op1_##code,(cx_object)op2_##code);\
        next();\

#define UPDATEENDFROM(type,code)\
    UPDATEENDFROM_##code:\
        fetchOp2(UPDATEENDFROM,code);\
        if (!op1_##code) {\
            printf("Exception: null dereference in updateEndFrom\n");\
            abort();\
            goto STOP;\
        }\
        cx_updateEndFrom((cx_object)op1_##code,(cx_object)op2_##code);\
        next();\

#define UPDATECANCEL(type,code)\
    UPDATECANCEL_##code:\
        fetchOp1(UPDATECANCEL,code);\
        if (!op_##code) {\
            printf("Exception: null dereference in updateCancel\n");\
            abort();\
            goto STOP;\
        }\
        cx_updateCancel((cx_object)op_##code);\
        next();\

#define WAITFOR(type, code)\
    WAITFOR_##code:\
        fetchOp1(WAITFOR,code);\
        if (!op_##code) {\
            printf("Exception: null dereference in waitfor");\
            abort();\
            goto STOP;\
        }\
        cx_waitfor((cx_object)op_##code);\
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
        op1_##code##V += op2_##code##V * op3_##code##V;\
        next();\

#define ELEMS(type,code)\
    ELEMS_##code:\
        fetchOp3(ELEMS,code##V);\
        {\
            cx_objectSeq* seq = (cx_objectSeq*)op1_##code##V;\
            CHECK_BOUNDS(seq->length, op2_##code##V);\
            op1_##code##V = (W_t)CX_OFFSET(seq->buffer,op2_##code##V * op3_##code##V);\
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

/* Instruction implementation expansions */
#define OPERAND_PQRV(op,type,lvalue)\
    op(type,type##lvalue##V)\
    op(type,type##lvalue##R)\
    op(type,type##lvalue##P)\
    op(type,type##lvalue##Q)

#define OPERAND_PQR(op,type,lvalue)\
    op(type,type##lvalue##R)\
    op(type,type##lvalue##P)\
    op(type,type##lvalue##Q)

#define OP_LVALUE(op,type,postfix)\
    OPERAND_##postfix(op,type,P)\
    OPERAND_##postfix(op,type,R)\
    OPERAND_##postfix(op,type,Q)

#define OP_LVALUE_V(op,type,postfix)\
    OP_LVALUE(op,type,postfix)\
    OPERAND_##postfix(op,type,V)

#define OP_LVALUE_FLOAT(op,type,postfix)\
    OPERAND_##postfix(op,type,P)\
    OPERAND_##postfix(op,type,R)\
    OPERAND_##postfix(op,type,Q)

#define OP_LVALUE_FLOAT_V(op,type,postfix)\
    OP_LVALUE_FLOAT(op,type,postfix)\
    op(type,type##VR)\
    op(type,type##VP)\
    op(type,type##VQ)\

#define OP1(op)\
    OPERAND_PQR(op,B,)\
    OPERAND_PQR(op,S,)\
    OPERAND_PQR(op,L,)\
    OPERAND_PQR(op,D,)

#define OP1_COND(op)\
    OPERAND_PQR(op,B,)

#define OP1_PQRV(op)\
    OPERAND_PQRV(op,B,)\
    OPERAND_PQRV(op,S,)\
    OPERAND_PQRV(op,L,)\
    OPERAND_PQRV(op,D,)\

#define OP1_ANYV(op)\
    op##_V(L,LV)\
    op##_VU(D,DV)\
    op##_VI(D,DV)\
    op##_VF(D,DV)\

#define OP1_ANY(op)\
    OPERAND_PQR(op,L,)\
    OPERAND_PQR(op,D,)\

#define OP2(op, postfix)\
    OP_LVALUE(op,B, postfix)\
    OP_LVALUE(op,S, postfix)\
    OP_LVALUE(op,L, postfix)\
    OP_LVALUE_FLOAT(op,D, postfix)\

#define OP2_V(op, postfix)\
    OP_LVALUE_V(op,B, postfix)\
    OP_LVALUE_V(op,S, postfix)\
    OP_LVALUE_V(op,L, postfix)\
    OP_LVALUE_FLOAT_V(op,D, postfix)\

#define OP2_SLD(op, postfix)\
    OP_LVALUE(op,S, postfix)\
    OP_LVALUE(op,L, postfix)\
    OP_LVALUE_FLOAT(op,D, postfix)\

#define OP2_BLD(op, postfix)\
    OP_LVALUE(op,B, postfix)\
    OP_LVALUE(op,L, postfix)\
    OP_LVALUE_FLOAT(op,D, postfix)\

#define OP2_BSD(op, postfix)\
    OP_LVALUE(op,B, postfix)\
    OP_LVALUE(op,S, postfix)\
    OP_LVALUE_FLOAT(op,D, postfix)\

#define OP2_BSL(op, postfix)\
    OP_LVALUE(op, B, postfix)\
    OP_LVALUE(op, S, postfix)\
    OP_LVALUE(op, L, postfix)\

#define OP2_LD(op, postfix)\
    OP_LVALUE(op, L, postfix)\
    OP_LVALUE_FLOAT(op, D, postfix)

#define OP2_L(op, postfix)\
    OP_LVALUE(op, L, postfix)

#define OP2_W(op, postfix)\
    OP_LVALUE(op, W, postfix)

#define OP2_D(op, postfix)\
    OP_LVALUE(op, D, postfix)

#define OP2V_W(op, postfix)\
    OPERAND_##postfix(op, W, V)\
    OP_LVALUE(op, W, postfix)\

/* Translation from opcode-id to address */
#define TOJMP_OPERAND(_op,type,lvalue,rvalue)\
    case CX_VM_##_op##_##type##lvalue##rvalue: p[i].op = toJump(_op##_##type##lvalue##rvalue); break;\

#define TOJMP_OPERAND_PQRV(_op,type,lvalue)\
    TOJMP_OPERAND(_op,type,lvalue,V)\
    TOJMP_OPERAND(_op,type,lvalue,R)\
    TOJMP_OPERAND(_op,type,lvalue,P)\
    TOJMP_OPERAND(_op,type,lvalue,Q)\

#define TOJMP_OPERAND_PQR(_op,type,lvalue)\
    TOJMP_OPERAND(_op,type,lvalue,R)\
    TOJMP_OPERAND(_op,type,lvalue,P)\
    TOJMP_OPERAND(_op,type,lvalue,Q)\

#define TOJMP_LVALUE(op,type,postfix)\
    TOJMP_OPERAND_##postfix(op,type,P)\
    TOJMP_OPERAND_##postfix(op,type,R)\
    TOJMP_OPERAND_##postfix(op,type,Q)\

#define TOJMP_LVALUE_V(op,type,postfix)\
    TOJMP_LVALUE(op,type,postfix)\
    TOJMP_OPERAND_##postfix(op,type,V)\

#define TOJMP_LVALUE_FLOAT(_op,type,postfix)\
    TOJMP_OPERAND_##postfix(_op,type,P);\
    TOJMP_OPERAND_##postfix(_op,type,R);\
    TOJMP_OPERAND_##postfix(_op,type,Q);\

#define TOJMP_LVALUE_FLOAT_V(_op,type,postfix)\
    TOJMP_LVALUE_FLOAT(_op,type,postfix)\
    TOJMP_OPERAND(_op,type,V,R)\
    TOJMP_OPERAND(_op,type,V,P)\
    TOJMP_OPERAND(_op,type,V,Q)\

#define TOJMP_OP1(op)\
    TOJMP_OPERAND_PQR(op,B,)\
    TOJMP_OPERAND_PQR(op,S,)\
    TOJMP_OPERAND_PQR(op,L,)\
    TOJMP_OPERAND_PQR(op,D,)\

#define TOJMP_OP1_COND(op)\
    TOJMP_OPERAND_PQR(op##B,B,)\
    TOJMP_OPERAND_PQR(op##S,B,)\
    TOJMP_OPERAND_PQR(op##L,B,)\
    TOJMP_OPERAND_PQR(op##D,B,)

#define TOJMP_OP1_COND_LD(op)\
    TOJMP_OPERAND_PQR(op##L,B,)\
    TOJMP_OPERAND_PQR(op##D,B,)

#define TOJMP_OP1_PQRV(_op)\
    TOJMP_OPERAND_PQRV(_op,B,)\
    TOJMP_OPERAND_PQRV(_op,S,)\
    TOJMP_OPERAND_PQRV(_op,L,)\
    TOJMP_OPERAND_PQRV(_op,D,)\

#define TOJMP_OP1_ANY(_op)\
    TOJMP_OPERAND_PQR(_op,L,)\
    TOJMP_OPERAND_PQR(_op,D,)\
    TOJMP_OPERAND(_op,L,V,)\
    TOJMP_OPERAND(_op,D,VU,)\
    TOJMP_OPERAND(_op,D,VI,)\
    TOJMP_OPERAND(_op,D,VF,)\

#define TOJMP_OP2(op,postfix)\
    TOJMP_LVALUE(op,B,postfix)\
    TOJMP_LVALUE(op,S,postfix)\
    TOJMP_LVALUE(op,L,postfix)\
    TOJMP_LVALUE(op,D,postfix)\

#define TOJMP_OP2_V(op,postfix)\
    TOJMP_LVALUE_V(op,B,postfix)\
    TOJMP_LVALUE_V(op,S,postfix)\
    TOJMP_LVALUE_V(op,L,postfix)\
    TOJMP_LVALUE_FLOAT_V(op,D,postfix)\

#define TOJMP_OP2_SLD(op,postfix)\
    TOJMP_LVALUE(op,S,postfix)\
    TOJMP_LVALUE(op,L,postfix)\
    TOJMP_LVALUE_FLOAT(op,D,postfix)\

#define TOJMP_OP2_BLD(op,postfix)\
    TOJMP_LVALUE(op,B,postfix)\
    TOJMP_LVALUE(op,L,postfix)\
    TOJMP_LVALUE_FLOAT(op,D,postfix)\

#define TOJMP_OP2_BSD(op,postfix)\
    TOJMP_LVALUE(op,B,postfix)\
    TOJMP_LVALUE(op,S,postfix)\
    TOJMP_LVALUE_FLOAT(op,D,postfix)\

#define TOJMP_OP2_BSL(op,postfix)\
    TOJMP_LVALUE(op,B,postfix)\
    TOJMP_LVALUE(op,S,postfix)\
    TOJMP_LVALUE(op,L,postfix)\

#define TOJMP_OP2_LD(op,postfix)\
    TOJMP_LVALUE(op,L,postfix)\
    TOJMP_LVALUE_FLOAT(op,D,postfix)\

#define TOJMP_OP2_L(op,postfix)\
    TOJMP_LVALUE(op,L,postfix)

#define TOJMP_OP2_W(op,postfix)\
    TOJMP_LVALUE(op,W,postfix)

#define TOJMP_OP2_D(op,postfix)\
    TOJMP_LVALUE(op,D,postfix)

#define TOJMP_OP2V_W(op,postfix)\
    TOJMP_OPERAND_##postfix(op,W,V)\
    TOJMP_LVALUE(op,W,postfix)

/* Translation from opcode-id to string */
#define TOSTR_OPERAND(_op,type,lvalue,rvalue)\
    case CX_VM_##_op##_##type##lvalue##rvalue: result = cx_vmOp_toString(result, &p[i], #_op, #type, #lvalue, #rvalue, ""); break;\

#define TOSTR_OPERAND_PQRV(_op,type,lvalue)\
    TOSTR_OPERAND(_op,type,lvalue,V)\
    TOSTR_OPERAND(_op,type,lvalue,R)\
    TOSTR_OPERAND(_op,type,lvalue,P)\
    TOSTR_OPERAND(_op,type,lvalue,Q)\

#define TOSTR_OPERAND_PQR(_op,type,lvalue)\
    TOSTR_OPERAND(_op,type,lvalue,R)\
    TOSTR_OPERAND(_op,type,lvalue,P)\
    TOSTR_OPERAND(_op,type,lvalue,Q)\

#define TOSTR_LVALUE(op,type,postfix)\
    TOSTR_OPERAND_##postfix(op,type,P)\
    TOSTR_OPERAND_##postfix(op,type,R)\
    TOSTR_OPERAND_##postfix(op,type,Q)\

#define TOSTR_LVALUE_V(op,type,postfix)\
    TOSTR_LVALUE(op,type,postfix)\
    TOSTR_OPERAND_##postfix(op,type,V)\

#define TOSTR_LVALUE_FLOAT(_op,type,postfix)\
    TOSTR_OPERAND(_op,type,P,R);\
    TOSTR_OPERAND(_op,type,P,P);\
    TOSTR_OPERAND(_op,type,P,Q);\
    TOSTR_OPERAND_##postfix(_op,type,R);\
    TOSTR_OPERAND_##postfix(_op,type,Q);\

#define TOSTR_LVALUE_FLOAT_V(_op,type,postfix)\
    TOSTR_LVALUE_FLOAT(_op,type,postfix)\
    TOSTR_OPERAND(_op,type,V,R);\
    TOSTR_OPERAND(_op,type,V,P);\
    TOSTR_OPERAND(_op,type,V,Q);\

#define TOSTR_OP1(op)\
    TOSTR_OPERAND_PQR(op,B,)\
    TOSTR_OPERAND_PQR(op,S,)\
    TOSTR_OPERAND_PQR(op,L,)\
    TOSTR_OPERAND_PQR(op,D,)\

#define TOSTR_OP1_DV(op)\
    TOSTR_OPERAND_PQR(op,B,)\
    TOSTR_OPERAND_PQR(op,S,)\
    TOSTR_OPERAND_PQR(op,L,)\
    TOSTR_OPERAND_PQR(op,D,)\
    TOSTR_OPERAND(op,D,V,)\

#define TOSTR_OP1_COND(op)\
    TOSTR_OPERAND_PQR(op##B,B,)\
    TOSTR_OPERAND_PQR(op##S,B,)\
    TOSTR_OPERAND_PQR(op##L,B,)\
    TOSTR_OPERAND_PQR(op##D,B,)\

#define TOSTR_OP1_COND_LD(op)\
    TOSTR_OPERAND_PQR(op##L,B,)\
    TOSTR_OPERAND_PQR(op##D,B,)\

#define TOSTR_OP1_PQRV(op)\
    TOSTR_OPERAND_PQRV(op,B,)\
    TOSTR_OPERAND_PQRV(op,S,)\
    TOSTR_OPERAND_PQRV(op,L,)\
    TOSTR_OPERAND_PQRV(op,D,)\

#define TOSTR_OP1_ANY(op)\
    TOSTR_OPERAND_PQR(op,L,)\
    TOSTR_OPERAND_PQR(op,D,)\
    TOSTR_OPERAND(op,L,,V)\
    TOSTR_OPERAND(op,D,,VU)\
    TOSTR_OPERAND(op,D,,VI)\
    TOSTR_OPERAND(op,D,,VF)\

#define TOSTR_OP2(op,postfix)\
    TOSTR_LVALUE(op,B,postfix)\
    TOSTR_LVALUE(op,S,postfix)\
    TOSTR_LVALUE(op,L,postfix)\
    TOSTR_LVALUE(op,D,postfix)\

#define TOSTR_OP2_V(op,postfix)\
    TOSTR_LVALUE_V(op,B,postfix)\
    TOSTR_LVALUE_V(op,S,postfix)\
    TOSTR_LVALUE_V(op,L,postfix)\
    TOSTR_LVALUE_FLOAT_V(op,D,postfix)\

#define TOSTR_OP2_SLD(op,postfix)\
    TOSTR_LVALUE(op,S,postfix)\
    TOSTR_LVALUE(op,L,postfix)\
    TOSTR_LVALUE_FLOAT(op,D,postfix)\

#define TOSTR_OP2_BLD(op,postfix)\
    TOSTR_LVALUE(op,B,postfix)\
    TOSTR_LVALUE(op,L,postfix)\
    TOSTR_LVALUE_FLOAT(op,D,postfix)\

#define TOSTR_OP2_BSD(op,postfix)\
    TOSTR_LVALUE(op,B,postfix)\
    TOSTR_LVALUE(op,S,postfix)\
    TOSTR_LVALUE_FLOAT(op,D,postfix)\

#define TOSTR_OP2_BSL(op,postfix)\
    TOSTR_LVALUE(op,B,postfix)\
    TOSTR_LVALUE(op,S,postfix)\
    TOSTR_LVALUE(op,L,postfix)\

#define TOSTR_OP2_LD(op,postfix)\
    TOSTR_LVALUE(op,L,postfix)\
    TOSTR_LVALUE_FLOAT(op,D,postfix)\

#define TOSTR_OP2_L(op,postfix)\
    TOSTR_LVALUE(op,L,postfix)\

#define TOSTR_OP2_W(op,postfix)\
    TOSTR_LVALUE(op,W,postfix)\

#define TOSTR_OP2_D(op,postfix)\
    TOSTR_LVALUE(op,D,postfix)\

#define TOSTR_OP2V_W(op,postfix)\
    TOSTR_LVALUE(op,W,postfix)\
    TOSTR_OPERAND_##postfix(op,W,V)

struct cx_vm_context {
    cx_vmOp *pc; /* Instruction counter */
    cx_vmParameter16 ic;    /* First (16-bit) parameter */
    cx_vmParameter lo; /* Lo parameter */
    cx_vmParameter hi; /* Hi parameter */
    cx_uint64 dbl; /* Double parameter */
    cx_uint64 dbl2;
    cx_vmParameter stage1;
    cx_vmParameter stage2;
    void *stack, *sp;
    cx_stringConcatCache *strcache;
};

#ifdef CX_VM_DEBUG
typedef void(*sigfunc)(int);
static sigfunc prevSegfaultHandler;
static sigfunc prevAbortHandler;

/* The VM signal handler */
static void cx_vm_sig(int sig) {
    cx_int32 sp;
    cx_currentProgramData *programData = cx_threadTlsGet(cx_currentProgramKey);
    
    if (sig == SIGSEGV) {
        printf("Access violation\n");
    }
    if (sig == SIGABRT) {
        printf("Abort\n");
    }

    /* Walk the stack, print frames */
    for(sp = programData->sp-1; sp>=0; sp--) {
        cx_id id, file;
        cx_vmProgram program = programData->stack[sp];
        cx_uint32 line = program->debugInfo[((cx_word)programData->c[sp]->pc - (cx_word)program->program)/sizeof(cx_vmOp)].line;
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
            cx_string str = cx_vmProgram_toString(program, programData->c[sp]->pc);
            printf("\n%s\n", str);
            cx_dealloc(str);
        }
#endif
    }
    printf("\n");
    exit(-1);
}

/* Push a program to the exception stack (see pushSignalHandler) */
static void cx_vm_pushCurrentProgram(cx_vmProgram program, cx_vm_context *c) {
    cx_currentProgramData *data = NULL;
    if (!cx_currentProgramKey) {
        cx_threadTlsKey(&cx_currentProgramKey, NULL);
    }
    data = cx_threadTlsGet(cx_currentProgramKey);
    if (!data) {
        data = cx_malloc(sizeof(cx_currentProgramData));
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
static void cx_vm_pushSignalHandler(cx_vmProgram program, cx_vm_context *c) {
    sigfunc result = signal(SIGSEGV, cx_vm_sig);
    if (result == SIG_ERR) {
        cx_error("failed to install signal handler for SIGSEGV");
    } else {
        prevSegfaultHandler = result;
    }
    result = signal(SIGABRT, cx_vm_sig);
    if (result == SIG_ERR) {
        cx_error("failed to install signal handler for SIGABRT");
    } else {
        prevAbortHandler = result;
    }
    
    /* Store current program in TLS */
    cx_vm_pushCurrentProgram(program, c);
}

/* Pop a program from the signal handler stack */
static void cx_vm_popSignalHandler(void) {
    if (signal(SIGSEGV, prevSegfaultHandler) == SIG_ERR) {
        cx_error("failed to uninstall signal handler for SIGSEGV");
    } else {
        prevSegfaultHandler = NULL;
    }
    if (signal(SIGABRT, prevAbortHandler) == SIG_ERR) {
        cx_error("failed to uninstall signal handler for SIGABRT");
    } else {
        prevSegfaultHandler = NULL;
    }
    
    cx_vm_popCurrentProgram();
}
#else
#define cx_vm_pushSignalHandler(p,c)
#define cx_vm_popSignalHandler()
#endif

static int32_t cx_vm_run_w_storage(cx_vmProgram program, void* reg, void *result) {
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
        cx_vmOp *p = program->program;
        uint32_t i;
        for(i=0; i<size;i++) {
#ifdef CX_VM_DEBUG
            p[i].opKind = p[i].op; /* Cache actual opKind for debugging purposes */
#endif
            switch(p[i].op) {
                TOJMP_OP2(SET,PQRV);
                case CX_VM_SET_WRX: p[i].op = toJump(SET_WRX); break;
                TOJMP_OP2_W(SETREF,PQRV);
                TOJMP_OP2_W(SETSTR,PQRV);
                TOJMP_OP2_W(SETSTRDUP,PQRV);
                case CX_VM_ZERO: p[i].op = toJump(ZERO); break;
                case CX_VM_INIT: p[i].op = toJump(INIT); break;

                TOJMP_OP1(INC);
                TOJMP_OP1(DEC);

                TOJMP_OP2(ADDI,PQRV);
                TOJMP_OP2(SUBI,PQRV);
                TOJMP_OP2(MULI,PQRV);
                TOJMP_OP2(DIVI,PQRV);
                TOJMP_OP2(MODI,PQRV);

                TOJMP_OP2_LD(ADDF,PQRV);
                TOJMP_OP2_LD(SUBF,PQRV);
                TOJMP_OP2_LD(MULF,PQRV);
                TOJMP_OP2_LD(DIVF,PQRV);

                TOJMP_OP2(AND,PQRV);
                TOJMP_OP2(XOR,PQRV);
                TOJMP_OP2(OR,PQRV);
                TOJMP_OP1(NOT);

                TOJMP_OP1_PQRV(STAGE1);
                case CX_VM_STAGE12_DP: p[i].op = toJump(STAGE12_DP); break;
                case CX_VM_STAGE12_DV: p[i].op = toJump(STAGE12_DV); break;
                TOJMP_OP2_V(STAGE2,PQRV);
                case CX_VM_STAGE2_DVV: p[i].op = toJump(STAGE2_DVV); break;

                TOJMP_OP1_COND(CAND);
                TOJMP_OP1_COND(COR);
                TOJMP_OP1_COND(CNOT);
                TOJMP_OP1_COND(CEQ);
                TOJMP_OP1_COND(CNEQ);

                TOJMP_OP1_COND(CGTI);
                TOJMP_OP1_COND(CLTI);
                TOJMP_OP1_COND(CGTEQI);
                TOJMP_OP1_COND(CLTEQI);

                TOJMP_OP1_COND(CGTU);
                TOJMP_OP1_COND(CLTU);
                TOJMP_OP1_COND(CGTEQU);
                TOJMP_OP1_COND(CLTEQU);

                TOJMP_OP1_COND_LD(CGTF);
                TOJMP_OP1_COND_LD(CLTF);
                TOJMP_OP1_COND_LD(CGTEQF);
                TOJMP_OP1_COND_LD(CLTEQF);

                TOJMP_OPERAND_PQR(CEQSTR,B,);
                TOJMP_OPERAND_PQR(CNEQSTR,B,);

                TOJMP_OP1(JEQ);
                TOJMP_OP1(JNEQ);
                case CX_VM_JUMP: p[i].op = toJump(JUMP); break;

                case CX_VM_MEMBER: p[i].op = toJump(MEMBER); break;

                TOJMP_OPERAND_PQRV(ELEMA,W,R);
                TOJMP_OPERAND_PQRV(ELEMS,W,R);
                TOJMP_OPERAND_PQRV(ELEML,W,R);
                TOJMP_OPERAND_PQRV(ELEMLX,W,R);
                TOJMP_OPERAND_PQRV(ELEMM,W,R);
                TOJMP_OPERAND_PQRV(ELEMMX,W,R);

                TOJMP_OP1_PQRV(PUSH);
                TOJMP_OP1(PUSHX);
                TOJMP_OPERAND_PQRV(PUSHANY,W,);
                TOJMP_OP1_ANY(PUSHANYX);

                TOJMP_OPERAND_PQR(CALL,L,);
                TOJMP_OPERAND_PQR(CALLVM,L,);
                case CX_VM_CALLVOID: p[i].op = toJump(CALLVOID); break;
                case CX_VM_CALLVMVOID: p[i].op = toJump(CALLVMVOID); break;
                TOJMP_OP2_W(CALLPTR,PQR)
                TOJMP_OP1(RET);
                TOJMP_OPERAND_PQR(RETCPY,L,);

                TOJMP_OP2_W(CAST,PQRV);
                TOJMP_OP2(PCAST,PQR);

                TOJMP_OP2V_W(STRCAT,PQRV);
                TOJMP_OP2_W(STRCPY,PQRV);

                TOJMP_LVALUE(NEW,W,PQRV);
                TOJMP_OPERAND_PQRV(DEALLOC,W,);
                TOJMP_OPERAND_PQRV(KEEP,W,);
                TOJMP_OPERAND_PQRV(FREE,W,);

                TOJMP_OPERAND_PQRV(DEFINE,W,);

                TOJMP_OPERAND_PQRV(UPDATE,W,);
                TOJMP_OPERAND_PQRV(UPDATEBEGIN,W,);
                TOJMP_OPERAND_PQRV(UPDATEEND,W,);
                TOJMP_OP2_W(UPDATEFROM,PQR);
                TOJMP_OP2_W(UPDATEENDFROM,PQR);
                TOJMP_OPERAND_PQRV(UPDATECANCEL,W,);

                TOJMP_OPERAND_PQRV(WAITFOR,W,);
                TOJMP_OP2_W(WAIT,PQRV);

                case CX_VM_STOP: p[i].op = toJump(STOP); break;
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

    /* Instruction implementations
     * Most of these lines are macro's which are expanded into the appropriate
     * actual instructions. For example, OP1(FOO) expands into:
     *  - CX_VM_FOO_BP <- byte operations (8 bit)
     *  - CX_VM_FOO_BR
     *  - CX_VM_FOO_BQ
     *  - CX_VM_FOO_SP <- short operations (16 bit)
     *  - CX_VM_FOO_SR
     *  - CX_VM_FOO_SQ
     *  - CX_VM_FOO_LP <- long operations (32 bit)
     *  - CX_VM_FOO_LR
     *  - CX_VM_FOO_LQ
     *  - CX_VM_FOO_DP <- double operations (64 bit)
     *  - CX_VM_FOO_DR
     *  - CX_VM_FOO_DQ
     */
    OP2(SET,PQRV);
    
    OP2_W(SETREF,PQRV);
    OP2_W(SETSTR,PQRV);
    OP2_W(SETSTRDUP,PQRV);

    SET_WRX:
        fetch_WRR;
        fetch1_WRR;
        fetch2_WRR;
        op1_WRR = (W_t)&op2_WRR;
        next();

    ZERO:
        fetch_WRV;
        fetch1_WRV;
        fetch2_WRV;
        memset(&op1_WRV,0,op2_WRV);
        next();
    
    INIT: {
        fetch_WRV;
        fetch1_WRV;
        fetch2_WRV;
        cx_value v;
        cx_valueValueInit(&v, NULL, (cx_typedef)op2_WRV, &op1_WRV);
        cx_initValue(&v);
        next();
    }

    OP1(INC);
    OP1(DEC);

    OP2(ADDI,PQRV);
    OP2(SUBI,PQRV);
    OP2(MULI,PQRV);
    OP2(DIVI,PQRV);
    OP2(MODI,PQRV);

    OP2_LD(ADDF,PQRV);
    OP2_LD(SUBF,PQRV);
    OP2_LD(MULF,PQRV);
    OP2_LD(DIVF,PQRV);

    OP2(AND,PQRV);
    OP2(XOR,PQRV);
    OP2(OR,PQRV);
    OP1(NOT);

    OP1_PQRV(STAGE1);
    STAGE12(D,DP);
    STAGE12(D,DV);
    OP2_V(STAGE2,PQRV)
    STAGE2(D, DVV);

    OP1_COND(CAND);
    OP1_COND(COR);
    OP1_COND(CNOT);
    OP1_COND(CEQ);
    OP1_COND(CNEQ);

    OP1_COND(CGTI);
    OP1_COND(CLTI);
    OP1_COND(CGTEQI);
    OP1_COND(CLTEQI);

    OP1_COND(CGTU);
    OP1_COND(CLTU);
    OP1_COND(CGTEQU);
    OP1_COND(CLTEQU);

    OP1_COND(CGTF);
    OP1_COND(CLTF);
    OP1_COND(CGTEQF);
    OP1_COND(CLTEQF);

    OPERAND_PQR(CEQSTR,B,);
    OPERAND_PQR(CNEQSTR,B,);
    
    OP1(JEQ);
    OP1(JNEQ);

    JUMP:
        fetchLo();
        jump(c.lo.w);

    MEMBER:
        fetch_LRR;
        fetch1_LRR;
        fetch2_LRR;
        fetchLo();
        if (!op2_LRR) {
            printf("Error: dereferencing null\n");
            goto STOP;
        }
        op1_WRR = op2_WRR + c.lo.w;
        next();

    OPERAND_PQRV(ELEMA,W,R);
    OPERAND_PQRV(ELEMS,W,R);
    OPERAND_PQRV(ELEML,W,R);
    OPERAND_PQRV(ELEMLX,W,R);
    OPERAND_PQRV(ELEMM,W,R);
    OPERAND_PQRV(ELEMMX,W,R);

    OP1_PQRV(PUSH);
    OP1(PUSHX);
    OPERAND_PQRV(PUSHANY,W,);
    OP1_ANY(PUSHANYX);
    OP1_ANYV(PUSHANYX);

    OPERAND_PQR(CALL,L,);
    OPERAND_PQR(CALLVM,L,);
    CALLVOID();
    CALLVMVOID();
    OP2_W(CALLPTR,PQR)
    OP1(RET);
    OPERAND_PQR(RETCPY,L,);

    OP2_W(CAST,PQRV);
    OP2(PCAST,PQR);
    OP2V_W(STRCAT,PQRV);
    OP2_W(STRCPY,PQRV);

    OP_LVALUE(NEW,W,PQRV);
    OPERAND_PQRV(DEALLOC,W,);
    OPERAND_PQRV(KEEP,W,);
    OPERAND_PQRV(FREE,W,);

    OPERAND_PQRV(DEFINE,W,);

    OPERAND_PQRV(UPDATE,W,);
    OPERAND_PQRV(UPDATEBEGIN,W,);
    OPERAND_PQRV(UPDATEEND,W,);
    OP2_W(UPDATEFROM,PQR);
    OP2_W(UPDATEENDFROM,PQR);
    OPERAND_PQRV(UPDATECANCEL,W,);

    OPERAND_PQRV(WAITFOR,W,);
    OP2_W(WAIT,PQRV);

STOP:
    cx_vm_popSignalHandler();
    return 0;
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
        concatCache = cx_malloc(sizeof(cx_stringConcatCache));
        memset(concatCache, 0, sizeof(cx_stringConcatCache));
        cx_threadTlsSet(cx_stringConcatCacheKey, concatCache);
    }
}

/* Execute a program */
int32_t cx_vm_run(cx_vmProgram program, void *result) {
    void *storage;

    storage = alloca(program->storage);
    cx_stringConcatCacheCreate();

    return cx_vm_run_w_storage(program, storage, result);
}

/* This function converts a single instruction to a string */
#ifdef CX_IC_TRACING
char * cx_vmOp_toString(char * string, cx_vmOp *instr, const char *op, const char *type, const char *lvalue, const char *rvalue, const char* fetch) {
    char *result = string;

    if (fetch && strlen(fetch)) {
        result = strappend(result, "%s_%s%s%s_%s %u %u %u %u\n", op, type, lvalue, rvalue, fetch, instr->ic.b._1, instr->ic.b._2, instr->lo.w, instr->hi.w);
    } else {
        result = strappend(result, "%s_%s%s%s %hu %hu %u %u\n", op, type, lvalue, rvalue, instr->ic.b._1, instr->ic.b._2, instr->lo.w, instr->hi.w);
    }

    return result;
}
#endif

/* Convert an instruction sequence to a string */
char * cx_vmProgram_toString(cx_vmProgram program, cx_vmOp *addr) {
    char * result = NULL;
    cx_int32 shown = 4;
    CX_UNUSED(program);

/* Since these strings can occupy a lot of space, they're only compiled in
 * when these two macros are enabled */
#ifdef CX_IC_TRACING
    cx_vmOp *p = program->program;
    uint32_t i;
    
#ifndef CX_VM_DEBUG
    if (!program->translated) {
        printf("cannot convert active program to string with non-debug version\n");
        abort();
    }
#endif
    if (addr && ((addr - p) > shown)) {
        result = strappend(result, "  ...\n");
    }
    
    for(i=0; i<program->size;i++) {
        cx_int32 diff = addr - &p[i];
        if (!addr || ((diff <= shown) && (diff >= -shown))) {
            cx_vmOpKind kind;
   
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
                TOSTR_OP2(SET,PQRV);
                TOSTR_OP2_W(SETREF,PQRV);
                TOSTR_OP2_W(SETSTR,PQRV);
                TOSTR_OP2_W(SETSTRDUP,PQRV);
                case CX_VM_SET_WRX: result = strappend(result, "SET_WRX %u %u\n", p[i].ic.b._1, p[i].ic.b._2); break;
                case CX_VM_ZERO: result = strappend(result, "ZERO %u %u\n", p[i].ic.b._1, p[i].lo.w); break;
                case CX_VM_INIT: result = strappend(result, "INIT %u %u\n", p[i].ic.b._1, p[i].lo.w); break;

                TOSTR_OP1(INC);
                TOSTR_OP1(DEC);

                TOSTR_OP2(ADDI,PQRV);
                TOSTR_OP2(SUBI,PQRV);
                TOSTR_OP2(MULI,PQRV);
                TOSTR_OP2(DIVI,PQRV);
                TOSTR_OP2(MODI,PQRV);

                TOSTR_OP2_LD(ADDF,PQRV);
                TOSTR_OP2_LD(SUBF,PQRV);
                TOSTR_OP2_LD(MULF,PQRV);
                TOSTR_OP2_LD(DIVF,PQRV);

                TOSTR_OP2(AND,PQRV);
                TOSTR_OP2(XOR,PQRV);
                TOSTR_OP2(OR,PQRV);
                TOSTR_OP1(NOT);

                TOSTR_OP1_DV(STAGE1);
                case CX_VM_STAGE12_DP: result = strappend(result, "STAGE12_DP %u\n", p[i].lo.w); break;
                case CX_VM_STAGE12_DV: result = strappend(result, "STAGE12_DV %u\n", *(D_t*)&p[i].lo.w); break;
                TOSTR_OP2_V(STAGE2,PQRV);
                case CX_VM_STAGE2_DVV: result = strappend(result, "STAGE2_DVV %u %u\n", p[i].lo.w, p[i].hi.w); break;

                TOSTR_OP1_COND(CAND);
                TOSTR_OP1_COND(COR);
                TOSTR_OP1_COND(CNOT);
                TOSTR_OP1_COND(CEQ);
                TOSTR_OP1_COND(CNEQ);

                TOSTR_OP1_COND(CGTI);
                TOSTR_OP1_COND(CLTI);
                TOSTR_OP1_COND(CGTEQI);
                TOSTR_OP1_COND(CLTEQI);

                TOSTR_OP1_COND(CGTU);
                TOSTR_OP1_COND(CLTU);
                TOSTR_OP1_COND(CGTEQU);
                TOSTR_OP1_COND(CLTEQU);

                TOSTR_OP1_COND_LD(CGTF);
                TOSTR_OP1_COND_LD(CLTF);
                TOSTR_OP1_COND_LD(CGTEQF);
                TOSTR_OP1_COND_LD(CLTEQF);

                TOSTR_OPERAND_PQR(CEQSTR,B,);
                TOSTR_OPERAND_PQR(CNEQSTR,B,);

                TOSTR_OP1(JEQ);
                TOSTR_OP1(JNEQ);
                case CX_VM_JUMP: result = strappend(result, "JUMP %u\n", p[i].lo.w); break;

                case CX_VM_MEMBER: result = strappend(result, "MEMBER %u %u %u\n", p[i].ic.b._1, p[i].ic.b._2, p[i].lo.w); break;
                TOSTR_OPERAND_PQRV(ELEMA,W,R);
                TOSTR_OPERAND_PQRV(ELEMS,W,R);
                TOSTR_OPERAND_PQRV(ELEML,W,R);
                TOSTR_OPERAND_PQRV(ELEMLX,W,R);
                TOSTR_OPERAND_PQRV(ELEMM,W,R);
                TOSTR_OPERAND_PQRV(ELEMMX,W,R);
                    
                TOSTR_OP1_PQRV(PUSH);
                TOSTR_OP1(PUSHX);
                TOSTR_OPERAND_PQRV(PUSHANY,W,);
                TOSTR_OP1_ANY(PUSHANYX);

                TOSTR_OPERAND_PQR(CALL,L,);
                TOSTR_OPERAND_PQR(CALLVM,L,);
                case CX_VM_CALLVOID: result = strappend(result, "CX_VM_CALLVOID %u\n", p[i].hi.w); break;
                case CX_VM_CALLVMVOID: result = strappend(result, "CX_VM_CALLVMVOID %u\n", p[i].hi.w); break;
                TOSTR_OP2_W(CALLPTR,PQR);
                TOSTR_OP1(RET);
                TOSTR_OPERAND_PQR(RETCPY,L,);

                TOSTR_OP2_W(CAST,PQRV);
                TOSTR_OP2(PCAST,PQR);
                TOSTR_OP2V_W(STRCAT,PQRV);
                TOSTR_OP2_W(STRCPY,PQRV);

                TOSTR_LVALUE(NEW,W,PQRV);
                TOSTR_OPERAND_PQR(DEALLOC,W,);
                TOSTR_OPERAND_PQR(KEEP,W,);
                TOSTR_OPERAND_PQR(FREE,W,);

                TOSTR_OPERAND_PQRV(DEFINE,W,);

                TOSTR_OPERAND_PQRV(UPDATE,W,);
                TOSTR_OPERAND_PQRV(UPDATEBEGIN,W,);
                TOSTR_OPERAND_PQRV(UPDATEEND,W,);
                TOSTR_OP2_W(UPDATEFROM,PQR);
                TOSTR_OP2_W(UPDATEENDFROM,PQR);
                TOSTR_OPERAND_PQRV(UPDATECANCEL,W,);

                TOSTR_OPERAND_PQRV(WAITFOR,W,);
                TOSTR_OP2_W(WAIT,PQRV);

                case CX_VM_STOP: result = strappend(result, "STOP\n"); break;
                default:
                    cx_assert(0, "invalid instruction %d in sequence @ %d", p[i].op, i);
                    break;
            }
        }
    }
    if (addr && ((&p[program->size-1] - addr) > 5)) {
        result = strappend(result, "  ...\n");
    }
#endif
    return result;
}

#pragma GCC diagnostic pop

/* Create a new VM program */
cx_vmProgram cx_vmProgram_new(char *filename, cx_object function) {
    cx_vmProgram result;

    result = cx_malloc(sizeof(cx_vmProgram_s));
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
void cx_vmProgram_free(cx_vmProgram program) {
    if (program) {
        if (program->program) {
            cx_dealloc(program->program);
        }
        cx_dealloc(program);
    }
}

/* Add new instruction to a VM program */
cx_vmOp *cx_vmProgram_addOp(cx_vmProgram program, uint32_t line) {
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
    program->program = cx_realloc(program->program, program->maxSize * sizeof(cx_vmOp));
    program->debugInfo = cx_realloc(program->debugInfo, program->maxSize * sizeof(cx_vmDebugInfo));

    /* Initialize instruction and debug data to zero */
    memset(&program->program[program->size-1], 0, sizeof(cx_vmOp));
    memset(&program->debugInfo[program->size-1], 0, sizeof(cx_vmDebugInfo));
    program->debugInfo[program->size-1].line = line;
    
    /* Return potentially realloc'd program */
    return &program->program[program->size-1];
}

/* Language binding function that calls a VM function */
void cx_call_vm(cx_function f, cx_void* result, void* args) {
    cx_vmProgram program;
    void *storage = NULL;

    /* Obtain instruction sequence */
    program = (cx_vmProgram)f->implData;

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
void cx_callDestruct_vm(cx_function f) {
    cx_vmProgram_free((cx_vmProgram)f->implData);
}

