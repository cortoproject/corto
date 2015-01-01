/*
 * cx_call.h
 *
 *  Created on: Apr 27, 2012
 *      Author: sander
 */

#ifndef CX_CALL_H_
#define CX_CALL_H_

#include "cx_object.h"
#include "cx__type.h"
#include "stdarg.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*cx_callHandler)(cx_function f, cx_void* result, void* args);
typedef void (*cx_callDestructHandler)(cx_function f);
typedef void* (*cx_contextSwitchHandler)(void);
typedef void (*cx_contextRestoreHandler)(void*);
typedef struct cx_context_s* cx_context;

/* Register binding */
int cx_callRegisterBinding(cx_callHandler handler, cx_contextSwitchHandler onSwitch, cx_contextRestoreHandler onRestore, cx_callDestructHandler onDestruct);

/* Call functions */
void cx_call(cx_function f, cx_void* result, ...);
void cx_callv(cx_function f, cx_void* result, va_list args);
int cx_calla(cx_function f, cx_void* result, cx_uint32 argc, void* argv[]);
void cx_callb(cx_function f, cx_void* result, void* args);

/* Binding-specific context-switches */
cx_context cx_contextSwitch(cx_object object);
cx_object cx_contextRestore(cx_context context);

void cx_callDestroy(cx_function f);

#ifdef __cplusplus
}
#endif

#endif /* CX_CALL_H_ */

