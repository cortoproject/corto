/*
 * cx_vm.h
 *
 *  Created on: Aug 14, 2013
 *      Author: sander
 */

#ifndef CX_IC_H_
#define CX_IC_H_

#include "cx_type.h"
#include "cx_value.h"
#include "cx_vm.h"
#include "cx_def.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum cx_icOpKind {
    /* Set (assign) */
    CX_IC_SET,

    /* Cast */
    CX_IC_CAST,

    /* String concatenation */
    CX_IC_STRCAT,
    CX_IC_STRCPY,

    /* Memory management */
    CX_IC_NEW,
    CX_IC_DEFINE,
    CX_IC_FREE,
    CX_IC_KEEP,

    /* Notifications */
    CX_IC_UPDATE,
    CX_IC_UPDATEBEGIN,
    CX_IC_UPDATEEND,
    CX_IC_UPDATECANCEL,

    /* Waiting */
    CX_IC_WAITFOR,
    CX_IC_WAIT,

    /* Operators */
    CX_IC_ADD,
    CX_IC_SUB,
    CX_IC_MUL,
    CX_IC_DIV,
    CX_IC_MOD,
    CX_IC_INC,
    CX_IC_DEC,
    CX_IC_XOR,
    CX_IC_OR,
    CX_IC_AND,
    CX_IC_NOT,
    CX_IC_SHIFT_LEFT,
    CX_IC_SHIFT_RIGHT,
    CX_IC_STAGE1,
    CX_IC_STAGE2,
    CX_IC_COND_OR,
    CX_IC_COND_AND,
    CX_IC_COND_NOT,
    CX_IC_COND_EQ,
    CX_IC_COND_NEQ,
    CX_IC_COND_GT,
    CX_IC_COND_LT,
    CX_IC_COND_GTEQ,
    CX_IC_COND_LTEQ,

    /* Program control */
    CX_IC_JUMP,
    CX_IC_JEQ,
    CX_IC_JNEQ,
    CX_IC_STOP,

    /* Function calls */
    CX_IC_PUSH,
    CX_IC_CALL,
    CX_IC_RET
}cx_icOpKind;

/* Intermediate structures */
typedef enum cx_icKind {
    CX_IC_STORAGE,
    CX_IC_LITERAL,
    CX_IC_LABEL,
    CX_IC_FUNCTION,
    CX_IC_OP,
    CX_IC_SCOPE
}cx_icKind;

typedef enum cx_icStorageKind {
    CX_STORAGE_OBJECT,
    CX_STORAGE_LOCAL,
    CX_STORAGE_ACCUMULATOR,
    CX_STORAGE_MEMBER,
    CX_STORAGE_ELEMENT
}cx_icStorageKind;

typedef struct cx_ic_s *cx_ic;
typedef struct cx_icValue_s *cx_icValue;
typedef struct cx_icStorage_s *cx_icStorage;
typedef struct cx_icObject_s *cx_icObject;
typedef struct cx_icLocal_s *cx_icLocal;
typedef struct cx_icMember_s *cx_icMember;
typedef struct cx_icElement_s *cx_icElement;
typedef struct cx_icAccumulator_s *cx_icAccumulator;
typedef struct cx_icLiteral_s *cx_icLiteral;
typedef struct cx_icLabel_s *cx_icLabel;
typedef struct cx_icFunction_s *cx_icFunction;
typedef struct cx_icOp_s *cx_icOp;
typedef struct cx_icScope_s *cx_icScope;
typedef struct cx_icProgram_s *cx_icProgram;

typedef struct cx_ic_s {
    cx_icKind kind;
    cx_icProgram program;
    cx_uint32 line;
}cx_ic_s;

typedef struct cx_icValue_s {
    cx_ic_s _parent;
}cx_icValue_s;

typedef enum cx_icDerefMode {
    CX_IC_DEREF_VALUE = 0,
    CX_IC_DEREF_ADDRESS,
    CX_IC_DEREF_PUSH
}cx_icDerefMode;

typedef struct cx_icStorage_s {
    cx_icValue_s _parent;
    cx_icStorageKind kind;
    cx_string name;
    cx_type type;
    cx_bool isReference; /* Is the storage a reference */
    cx_uint32 used; /* Count how many times value is used in program */
    cx_bool holdsReturn; /* If accumulator holds returnvalue, it potentially holds resources */
}cx_icStorage_s;

typedef struct cx_icObject_s {
    cx_icStorage_s _parent;
    cx_object ptr;
}cx_icObject_s;

typedef struct cx_icLocal_s {
    cx_icStorage_s _parent;
    cx_bool isParameter;
    cx_bool isReturn; /* Return locals are special in that resources are not free'd when leaving scope */
}cx_icLocal_s;

typedef struct cx_icMember_s {
    cx_icStorage_s _parent;
    cx_icStorage base;
    cx_member member;
}cx_icMember_s;

typedef struct cx_icElement_s {
    cx_icStorage_s _parent;
    cx_icStorage base;
    cx_icValue index;
    cx_collection collectionType;
    cx_bool dynamic; /* If TRUE, index-expression is not a literal and element needs to be calculated at runtime */
}cx_icElement_s;

typedef struct cx_icAccumulator_s {
    cx_icStorage_s _parent;
    cx_uint32 accumulatorId;
}cx_icAccumulator_s;

typedef struct cx_icLiteral_s {
    cx_icValue_s _parent;
    cx_value value;
    cx_type type;
}cx_icLiteral_s;

typedef struct cx_icLabel_s {
    cx_icValue_s _parent;
    cx_uint32 id;
}cx_icLabel_s;

typedef struct cx_icFunction_s {
    cx_icValue_s _parent;
    cx_function function;
}cx_icFunction_s;

typedef struct cx_icOp_s {
    cx_ic_s _parent;
    cx_icOpKind kind;
    cx_icValue s1;
    cx_icValue s2;
    cx_icValue s3;
    /* If VALUE, storage will be interpreted as value. PVALUE will interpret value of storage. PPVALUE will interpret value of address in storage. */
    cx_icDerefMode s1Deref;
    cx_icDerefMode s2Deref;
    cx_icDerefMode s3Deref;
    /* If s1Any, treat s1 as an any-value */
    cx_bool s1Any;
}cx_icOp_s;

typedef struct cx_icScope_s {
    cx_ic_s _parent;
    cx_icScope parent;
    cx_ll storages; /* Stores accumulators and local variables */
    cx_ll program;
    cx_bool isFunction;
}cx_icScope_s;

typedef struct cx_icProgram_s {
    cx_ll storages; /* Stores objects */
    cx_ll scopes;
    cx_ll labels;
    cx_ll functions;
    cx_ll literals;
    cx_ll ops;
    cx_string filename;
    cx_uint32 labelCount;
    cx_uint32 accumulatorId;
    cx_icAccumulator accumulatorStack[256];
    cx_icScope scope;
    cx_int32 errors;
}cx_icProgram_s;

/* Intermediate program */
cx_icProgram cx_icProgram__create(cx_string filename);
void cx_icProgram__free(cx_icProgram program);
void cx_icProgram_addIc(cx_icProgram program, cx_ic ic);
cx_icAccumulator cx_icProgram_accumulatorPush(cx_icProgram _this, cx_uint32 line, cx_type type, cx_bool isReference);
void cx_icProgram_accumulatorPop(cx_icProgram _this, cx_uint32 line);
cx_icScope cx_icProgram_scopePush(cx_icProgram _this, cx_uint32 line);
cx_icScope cx_icProgram_functionPush(cx_icProgram _this, cx_uint32 line, cx_function function);
void cx_icProgram_scopePop(cx_icProgram _this, cx_uint32 line);
cx_string cx_icProgram_toString(cx_icProgram program);
cx_vmProgram cx_icProgram_toVm(cx_icProgram program);

/* Storages */
void cx_icStorage_init(
        cx_icStorage storage,
        cx_icProgram program,
        cx_uint32 line,
        cx_icStorageKind kind,
        cx_string name,
        cx_type type);
cx_icObject cx_icObject__create(cx_icProgram program, cx_uint32 line, cx_object object);
cx_icLocal cx_icLocal__create(cx_icProgram program, cx_uint32 line, cx_string name, cx_type type, cx_bool isParameter, cx_bool isReturn, cx_bool declare);
cx_icAccumulator cx_icAccumulator__create(cx_icProgram program, cx_uint32 line, cx_type type, cx_uint32 accumulatorId);
cx_icMember cx_icMember__create(cx_icProgram program, cx_uint32 line, cx_icStorage base, cx_member member);
cx_icElement cx_icElement__create(cx_icProgram program, cx_uint32 line, cx_type type, cx_icStorage base, cx_icValue index);

/* Values */
cx_icLiteral cx_icLiteral__create(cx_icProgram program, cx_uint32 line, cx_value value, cx_type type);
cx_icLabel cx_icLabel__create(cx_icProgram program, cx_uint32 line);
cx_icFunction cx_icFunction__create(cx_icProgram program, cx_uint32 line, cx_function function);

/* Scopes */
cx_icScope cx_icScope__create(cx_icProgram program, cx_uint32 line, cx_icScope parent, cx_bool isFunction);
void cx_icScope_addIc(cx_icScope scope, cx_ic ic);
cx_icStorage cx_icScope_lookupStorage(cx_icScope scope, cx_string name, cx_bool recursive);

/* Create operation */
cx_icOp cx_icOp__create(cx_icProgram program, cx_uint32 line, cx_icOpKind kind, cx_icValue s1, cx_icValue s2, cx_icValue s3);

/* Utility */
cx_icOpKind cx_icOpKindFromOperator(cx_operatorKind operator);

#ifdef __cplusplus
}
#endif

#endif /* CX_IC_H_ */
