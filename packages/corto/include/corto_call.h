/*
 * corto_call.h
 *
 *  Created on: Apr 27, 2012
 *      Author: sander
 */

#ifndef CORTO_CALL_H_
#define CORTO_CALL_H_

#include "corto_object.h"
#include "corto/lang/lang__type.h"
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*corto_callHandler)(corto_function f, corto_void* result, void* args);
typedef void (*corto_callDestructHandler)(corto_function f);
typedef void* (*corto_contextSwitchHandler)(void);
typedef void (*corto_contextRestoreHandler)(void*);
typedef struct corto_context_s* corto_context;

/* Register binding */
int corto_callRegisterBinding(corto_callHandler handler, corto_contextSwitchHandler onSwitch, corto_contextRestoreHandler onRestore, corto_callDestructHandler onDestruct);

/* Call functions */
void corto_call(corto_function f, corto_void* result, ...);
void corto_callv(corto_function f, corto_void* result, va_list args);
int corto_calla(corto_function f, corto_void* result, corto_uint32 argc, void* argv[]);
void corto_callb(corto_function f, corto_void* result, void* args);

/* Binding-specific context-switches */
corto_context corto_contextSwitch(corto_object object);
corto_object corto_contextRestore(corto_context context);

void corto_callDestroy(corto_function f);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_CALL_H_ */
