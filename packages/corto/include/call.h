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

/* Note: ffi_call compatible signature */
typedef void (*corto_callHandler)(void *fdata, void *fptr, corto_void *rvalue, void **args);

/* Call functions */
void corto_call(corto_function f, corto_void* result, ...);
void corto_callv(corto_function f, corto_void* result, va_list args);
void corto_callb(corto_function f, corto_void* result, void** argptrs);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_CALL_H_ */
