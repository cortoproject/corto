/* include/vm.h
 *
 * This file is generated. Do not modify.
 */

#ifndef vm_H
#define vm_H

#include "corto.h"
#ifdef __cplusplus
extern "C" {
#endif

/* $header() */
#include "stdint.h"
#include "vm_def.h"

extern int CORTO_PROCEDURE_VM;

/* ---- Macro's that expand into enumeration constants */
#define CONST0(arg)\
    CORTO_VM_##arg,

#define CONST1(type, arg, op1)\
    CORTO_VM_##arg##_##type##op1,

#define CONST1_COND(type, arg, op1)\
    CORTO_VM_##arg##B_##type##op1,\
    CORTO_VM_##arg##S_##type##op1,\
    CORTO_VM_##arg##L_##type##op1,\
    CORTO_VM_##arg##D_##type##op1,

#define CONST1_COND_LD(type, arg, op1)\
    CORTO_VM_##arg##L##_##type##op1,\
    CORTO_VM_##arg##D##_##type##op1,     

#define CONST2(type, arg, op1, op2)\
    CORTO_VM_##arg##_##type##op1##op2,

#define CONST3(type, arg, op1, op2, op3)\
    CORTO_VM_##arg##_##type##op1##op2##op3,


/* ---- Enumeration containing all instruction constants */
typedef enum vm_opKind {
    OPS_EXP(CONST) /* See corto_vm_def.h */
} vm_opKind;


/* ---- Instruction structure */
typedef union vm_parameter16 {
    struct {
        uint16_t _1;
        uint16_t _2;
    } b;
    uint16_t s;
    intptr_t w;
}vm_parameter16;

typedef union vm_parameter {
    vm_parameter16 s;
    intptr_t w;
}vm_parameter;

typedef struct vm_opAddr {
    uint16_t jump;
    vm_parameter16 p;
}vm_opAddr;

typedef struct vm_op {
    intptr_t op; /* direct jump to address of next operation */
    vm_parameter16 ic;
    vm_parameter lo;
    vm_parameter hi;
#ifdef CORTO_VM_DEBUG
    vm_opKind opKind; /* Actual operation kind. Only used for debugging purposes */
#endif
}vm_op;

typedef struct vm_debugInfo {
    uint32_t line;
}vm_debugInfo;
    
typedef struct vm_program_s *vm_program;
typedef struct vm_program_s {
    vm_op *program;
    vm_debugInfo *debugInfo;
    corto_object function;
    char *filename;
    uint32_t size;
    uint32_t maxSize;
    uint32_t storage;
    uint32_t stack;
    uint8_t translated;
} vm_program_s;

#ifndef corto_stringSeq_DEFINED
#define corto_stringSeq_DEFINED
CORTO_SEQUENCE(corto_stringSeq, corto_string,);
#endif

/* ---- Virtual machine API */
/* Callback to vm program, for usage with call API */
void vm_call(corto_function f, corto_void* result, void* args);

/* Run a program */
int32_t vm_run(vm_program program, corto_stringSeq argv, void *result);

/* Convert a program to a string */
char *vm_programToString(vm_program program, vm_op *addr);

/* Create a new program */
vm_program vm_programNew(char *filename, corto_object function);

/* Free a program */
void vm_programFree(vm_program program);

/* Add instruction to an existing program */
vm_op *vm_programAddOp(vm_program program, uint32_t line);

/* $end */

#ifdef __cplusplus
}
#endif
#endif

