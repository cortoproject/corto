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
#include "vm_def.h"
#include "cx_crc.h"

#ifdef __cplusplus
extern "C" {
#endif

extern int CX_PROCEDURE_VM;

/* ---- Macro's that expand into enumeration constants */
#define CONST0(arg)\
    CX_VM_##arg,

#define CONST1(type, arg, op1)\
    CX_VM_##arg##_##type##op1,

#define CONST1_COND(type, arg, op1)\
    CX_VM_##arg##B_##type##op1,\
    CX_VM_##arg##S_##type##op1,\
    CX_VM_##arg##L_##type##op1,\
    CX_VM_##arg##D_##type##op1,

#define CONST1_COND_LD(type, arg, op1)\
    CX_VM_##arg##L##_##type##op1,\
    CX_VM_##arg##D##_##type##op1,     

#define CONST2(type, arg, op1, op2)\
    CX_VM_##arg##_##type##op1##op2,

#define CONST3(type, arg, op1, op2, op3)\
    CX_VM_##arg##_##type##op1##op2##op3,


/* ---- Enumeration containing all instruction constants */
typedef enum vm_opKind {
    OPS_EXP(CONST) /* See cx_vm_def.h */
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
#ifdef CX_VM_DEBUG
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
    cx_object function;
    char *filename;
    uint32_t size;
    uint32_t maxSize;
    uint32_t storage;
    uint32_t stack;
    uint8_t translated;
} vm_program_s;


/* ---- Virtual machine API */
/* Callback to vm program, for usage with call API */
void vm_call(cx_function f, cx_void* result, void* args);

/* Run a program */
int32_t vm_run(vm_program program, void *result);

/* Convert a program to a string */
char *vm_programToString(vm_program program, vm_op *addr);

/* Create a new program */
vm_program vm_programNew(char *filename, cx_object function);

/* Free a program */
void vm_programFree(vm_program program);

/* Add instruction to an existing program */
vm_op *vm_programAddOp(vm_program program, uint32_t line);

#ifdef __cplusplus
}
#endif

#endif /* CX_VM_H_ */
