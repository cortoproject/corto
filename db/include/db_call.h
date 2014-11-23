/*
 * db_call.h
 *
 *  Created on: Apr 27, 2012
 *      Author: sander
 */

#ifndef DB_CALL_H_
#define DB_CALL_H_

#include "db_object.h"
#include "db__type.h"
#include "stdarg.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*db_callHandler)(db_function f, db_void* result, void* args);
typedef void (*db_callDestructHandler)(db_function f);
typedef void* (*db_contextSwitchHandler)(void);
typedef void (*db_contextRestoreHandler)(void*);
typedef struct db_context_s* db_context;

/* Register binding */
int db_callRegisterBinding(db_callHandler handler, db_contextSwitchHandler onSwitch, db_contextRestoreHandler onRestore, db_callDestructHandler onDestruct);

/* Call functions */
void db_call(db_function f, db_void* result, ...);
void db_callv(db_function f, db_void* result, va_list args);
int db_calla(db_function f, db_void* result, db_uint32 argc, void* argv[]);
void db_callb(db_function f, db_void* result, void* args);

/* Binding-specific context-switches */
db_context db_contextSwitch(db_object object);
db_object db_contextRestore(db_context context);

void db_callDestroy(db_function f);

#ifdef __cplusplus
}
#endif

#endif /* DB_CALL_H_ */

