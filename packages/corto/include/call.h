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
CORTO_EXPORT void _corto_call(corto_function f, corto_void* result, ...);
CORTO_EXPORT void _corto_callv(corto_function f, corto_void* result, va_list args);
CORTO_EXPORT void _corto_callb(corto_function f, corto_void* result, void** argptrs);

/* Register binding */
CORTO_EXPORT int corto_callRegister(corto_callInit_f init, corto_callDeinit_f deinit);
CORTO_EXPORT int16_t corto_callInit(corto_function f);
CORTO_EXPORT void corto_callDeinit(corto_function f);

#define corto_call(f, ...) _corto_call(corto_function(f), __VA_ARGS__)
#define corto_callv(f, result, args) _corto_callv(corto_function(f), result, args)
#define corto_callb(f, result, argptrs) _corto_callb(corto_function(f), result, argptrs)

#ifdef __cplusplus
}
#endif

#endif /* CORTO_CALL_H_ */
