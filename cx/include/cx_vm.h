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

/* ---- Macro's that expand into enumeration constants */
#define CONST0(arg)\
    CX_VM_##arg,

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

#define CONST1_ANY(type, arg, op1)\
    CX_VM_##arg##U##_##type##op1,\
    CX_VM_##arg##I##_##type##op1,\
    CX_VM_##arg##F##_##type##op1,    

#define CONST2(type, arg, op1, op2)\
    CX_VM_##arg##_##type##op1##op2,

#define CONST3(type, arg, op1, op2, op3)\
    CX_VM_##arg##_##type##op1##op2##op3,


/* ---- Enumeration containing all instruction constants */
typedef enum cx_vmOpKind {
    OPS_EXP(CONST)
} cx_vmOpKind;


/* ---- Instruction structure */
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


/* ---- Virtual machine API */
/* Callback to vm program, for usage with call API */
void cx_call_vm(cx_function f, cx_void* result, void* args);

/* Run a program */
int32_t cx_vm_run(cx_vmProgram program, void *result);

/* Convert a program to a string */
char *cx_vmProgram_toString(cx_vmProgram program, cx_vmOp *addr);

/* Create a new program */
cx_vmProgram cx_vmProgram_new(char *filename, cx_object function);

/* Free a program */
void cx_vmProgram_free(cx_vmProgram program);

/* Add instruction to an existing program */
cx_vmOp *cx_vmProgram_addOp(cx_vmProgram program, uint32_t line);

#ifdef __cplusplus
}
#endif

#endif /* CX_VM_H_ */
