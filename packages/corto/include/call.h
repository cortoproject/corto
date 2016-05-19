/*
 * corto_call.h
 *
 *  Created on: Apr 27, 2012
 *      Author: sander
 */

#ifndef CORTO_CALL_H_
#define CORTO_CALL_H_

#include "corto/object.h"
#include "corto/lang/_type.h"
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ffi_call compatible signature */
typedef void (*corto_callInvoke)(void *fdata, void *fptr, corto_void *rvalue, void **args);

typedef corto_int16 ___ (*corto_callInit_f)(corto_function f);
typedef void (*corto_callDeinit_f)(corto_function f);

/* Call API */
void corto_call(corto_function f, corto_void* result, ...);
void corto_callv(corto_function f, corto_void* result, va_list args);
void corto_callb(corto_function f, corto_void* result, void** argptrs);

/* Register binding */
int corto_callRegister(corto_callInit_f init, corto_callDeinit_f deinit);
corto_int16 corto_callInit(corto_function f);
void corto_callDeinit(corto_function f);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_CALL_H_ */
