/*
 * db_call.c
 *
 *  Created on: Oct 16, 2012
 *      Author: sander
 */

#include "db_call.h"
#include "stdarg.h"
#include "db_err.h"
#include "db_util.h"
#include "db_mem.h"

typedef struct bindingHandler {
    db_callHandler function;
    db_contextSwitchHandler onSwitch;
    db_contextRestoreHandler onRestore;
    db_callDestructHandler onDestruct;
}bindingHandler;

static int languageId = 1;
static bindingHandler bindings[DB_MAX_BINDINGS];

/* Register language */
int db_callRegisterBinding(db_callHandler handler, db_contextSwitchHandler onSwitch, db_contextRestoreHandler onRestore, db_callDestructHandler onDestruct) {
    int nextId;

    nextId = db_ainc(&languageId)-1;
    bindings[nextId].function = handler;
    bindings[nextId].onSwitch = onSwitch;
    bindings[nextId].onRestore = onRestore;
    bindings[nextId].onDestruct = onDestruct;

    return nextId;
}

struct db_context_s {
    db_object object;
    void* context[DB_MAX_BINDINGS];
};

db_context db_contextSwitch(db_object object) {
    db_context context;
    int i;

    /* Allocate context */
    context = db_malloc(sizeof(struct db_context_s));

    /* Store object that effectuates the contextswitch in context */
    context->object = object;

    /* For each binding, call context switch */
    for(i=0; i<languageId; i++) {
        if (bindings[i].onSwitch) {
            /* Store binding-specific context information */
            context->context[i] = bindings[i].onSwitch();
        }
    }

    return context;
}

db_object db_contextRestore(db_context context) {
    int i;
    db_object object;

    /* For each binding, call context restore */
    for(i=0; i<languageId; i++) {
        if (bindings[i].onRestore) {
            /* Restore binding-specific context information */
            bindings[i].onRestore(context->context[i]);
        }
    }

    /* Store object pointer before destroying context */
    object = context->object;
    db_dealloc(context);

    /* Return object */
    return object;
}

void db_callDestroy(db_function f) {
    if (bindings[f->kind].onDestruct) {
        bindings[f->kind].onDestruct(f);
    }
}

/* Call with buffer (on most platforms this will be the same as db_callv) */
static void db_call_intern(db_function f, db_void* result, void* args) {
    ((void(*)(db_function, void*, void*))f->impl)(f, result, args);
}

/* Call with variable arguments */
void db_call(db_function f, db_void* result, ...) {
    va_list list;

    va_start(list, result);
    db_call_intern(f, result, list);
    va_end(list);
}

/* Call with variable argument list */
void db_callv(db_function f, db_void* result, va_list args) {
    db_call_intern(f, result, args);
}

/* Call with array of values */
int db_calla(db_function f, db_void* result, db_uint32 argc, void* argv[]);

/* Call with buffer (on most platforms this will be the same as db_callv) */
void db_callb(db_function f, db_void* result, void* args) {
    db_call_intern(f, result, args);
}


