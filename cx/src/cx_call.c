/*
 * cx_call.c
 *
 *  Created on: Oct 16, 2012
 *      Author: sander
 */

#include "cx_call.h"
#include "stdarg.h"
#include "cx_err.h"
#include "cx_util.h"
#include "cx_mem.h"

typedef struct bindingHandler {
    cx_callHandler function;
    cx_contextSwitchHandler onSwitch;
    cx_contextRestoreHandler onRestore;
    cx_callDestructHandler onDestruct;
}bindingHandler;

static int languageId = 1;
static bindingHandler bindings[DB_MAX_BINDINGS];

/* Register language */
int cx_callRegisterBinding(cx_callHandler handler, cx_contextSwitchHandler onSwitch, cx_contextRestoreHandler onRestore, cx_callDestructHandler onDestruct) {
    int nextId;

    nextId = cx_ainc(&languageId)-1;
    bindings[nextId].function = handler;
    bindings[nextId].onSwitch = onSwitch;
    bindings[nextId].onRestore = onRestore;
    bindings[nextId].onDestruct = onDestruct;

    return nextId;
}

struct cx_context_s {
    cx_object object;
    void* context[DB_MAX_BINDINGS];
};

cx_context cx_contextSwitch(cx_object object) {
    cx_context context;
    int i;

    /* Allocate context */
    context = cx_malloc(sizeof(struct cx_context_s));

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

cx_object cx_contextRestore(cx_context context) {
    int i;
    cx_object object;

    /* For each binding, call context restore */
    for(i=0; i<languageId; i++) {
        if (bindings[i].onRestore) {
            /* Restore binding-specific context information */
            bindings[i].onRestore(context->context[i]);
        }
    }

    /* Store object pointer before destroying context */
    object = context->object;
    cx_dealloc(context);

    /* Return object */
    return object;
}

void cx_callDestroy(cx_function f) {
    if (bindings[f->kind].onDestruct) {
        bindings[f->kind].onDestruct(f);
    }
}

/* Call with buffer (on most platforms this will be the same as cx_callv) */
static void cx_call_intern(cx_function f, cx_void* result, void* args) {
    ((void(*)(cx_function, void*, void*))f->impl)(f, result, args);
}

/* Call with variable argument list */
void cx_callv(cx_function f, cx_void* result, va_list args) {
    void *ptr, *buffer;
    cx_uint32 s = f->size;

    if(s % sizeof(cx_uint64)) {
        s = ((s / sizeof(cx_uint64)) + 1) * sizeof(cx_uint64);
    }
    ptr = buffer = alloca(s);

    while (s) {
        *(cx_uint64*)ptr = va_arg(args, cx_uint64);
        ptr = (void*)((cx_word)ptr + sizeof(cx_uint64));
        s -= sizeof(cx_uint64);
    }

    cx_call_intern(f, result, buffer);
}

/* Call with variable arguments */
void cx_call(cx_function f, cx_void* result, ...) {
    va_list list;

    va_start(list, result);
    cx_callv(f, result, list);
    va_end(list);
}

/* Call with array of values */
int cx_calla(cx_function f, cx_void* result, cx_uint32 argc, void* argv[]);

/* Call with buffer (on most platforms this will be the same as cx_callv) */
void cx_callb(cx_function f, cx_void* result, void* args) {
    cx_call_intern(f, result, args);
}


