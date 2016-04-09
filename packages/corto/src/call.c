/*
 * corto_call.c
 *
 *  Created on: Oct 16, 2012
 *      Author: sander
 */

#include "corto/corto.h"

typedef struct bindingHandler {
    corto_callHandler function;
    corto_contextSwitchHandler onSwitch;
    corto_contextRestoreHandler onRestore;
    corto_callDestructHandler onDestruct;
}bindingHandler;

static int languageId = 1;
static bindingHandler bindings[CORTO_MAX_BINDINGS];

/* Register language */
int corto_callRegisterBinding(corto_callHandler handler, corto_contextSwitchHandler onSwitch, corto_contextRestoreHandler onRestore, corto_callDestructHandler onDestruct) {
    int nextId;

    nextId = corto_ainc(&languageId)-1;
    bindings[nextId].function = handler;
    bindings[nextId].onSwitch = onSwitch;
    bindings[nextId].onRestore = onRestore;
    bindings[nextId].onDestruct = onDestruct;

    return nextId;
}

struct corto_context_s {
    corto_object object;
    void* context[CORTO_MAX_BINDINGS];
};

corto_context corto_contextSwitch(corto_object object) {
    corto_context context;
    int i;

    /* Allocate context */
    context = corto_alloc(sizeof(struct corto_context_s));

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

corto_object corto_contextRestore(corto_context context) {
    int i;
    corto_object object;

    /* For each binding, call context restore */
    for(i=0; i<languageId; i++) {
        if (bindings[i].onRestore) {
            /* Restore binding-specific context information */
            bindings[i].onRestore(context->context[i]);
        }
    }

    /* Store object pointer before destroying context */
    object = context->object;
    corto_dealloc(context);

    /* Return object */
    return object;
}

void corto_callDestroy(corto_function f) {
    if (bindings[f->kind].onDestruct) {
        bindings[f->kind].onDestruct(f);
    }
}

/* Call with buffer (on most platforms this will be the same as corto_callv) */
static void corto_call_intern(corto_function f, corto_void* result, void* args) {
    /* If process does not own object, forward call */
    if (corto_instanceof(corto_method_o, f)) {
        corto_object instance = *(corto_object*)args;
        corto_object owner = corto_ownerof(instance);

        if (owner && corto_instanceof(corto_mount_o, owner)) {
            if (!(owner == corto_getOwner())) {
                corto_octetseq argbuff = {f->size, args};
                corto_mount_invoke(owner, instance, f, argbuff);
                return;
            } else {
                /* A mount invoking a method on an object it owns? That is
                 * odd. Don't do anything. */
                return;
            }
        }
    }

    ((void(*)(corto_function, void*, void*))f->impl)(f, result, args);
}

/* Call with variable argument list */
void corto_callv(corto_function f, corto_void* result, va_list args) {
    void *ptr, *buffer;
    corto_uint32 s = f->size;

    if(s % sizeof(corto_uint64)) {
        s = ((s / sizeof(corto_uint64)) + 1) * sizeof(corto_uint64);
    }
    ptr = buffer = alloca(s);

    while (s) {
        *(corto_uint64*)ptr = va_arg(args, corto_uint64);
        ptr = (void*)((corto_word)ptr + sizeof(corto_uint64));
        s -= sizeof(corto_uint64);
    }

    corto_call_intern(f, result, buffer);
}

/* Call with variable arguments */
void corto_call(corto_function f, corto_void* result, ...) {
    va_list list;

    va_start(list, result);
    corto_callv(f, result, list);
    va_end(list);
}

/* Call with array of values */
int corto_calla(corto_function f, corto_void* result, corto_uint32 argc, void* argv[]);

/* Call with buffer (on most platforms this will be the same as corto_callv) */
void corto_callb(corto_function f, corto_void* result, void* args) {
    corto_call_intern(f, result, args);
}
