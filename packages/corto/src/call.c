/*
 * corto_call.c
 *
 *  Created on: Oct 16, 2012
 *      Author: sander
 */

#include "corto/corto.h"

/* Keep include local because of clashing macro's with other libraries (yacc) */
#ifdef __MACH__
#include "ffi/ffi.h"
#else
#include "ffi.h"
#endif

typedef struct corto_callHandler {
    corto_callInit_f init;
    corto_callDeinit_f deinit;
} corto_callHandler;

corto_int16 corto_stubInit(corto_function f) {
    CORTO_UNUSED(f);
    return 0;
}
void corto_stubDeinit(corto_function f) {
    CORTO_UNUSED(f);
}

static int languageId = 1;
static corto_callHandler handlers[CORTO_MAX_BINDINGS] =
{
  {corto_stubInit, corto_stubDeinit}
};

/* Register language */
int corto_callRegister(corto_callInit_f init, corto_callDeinit_f deinit) {
    int nextId;

    nextId = corto_ainc(&languageId)-1;
    handlers[nextId].init = init;
    handlers[nextId].deinit = deinit;

    return nextId;
}

corto_int16 corto_callInit(corto_function f) {
    return handlers[f->kind].init(f);
}

void corto_callDeinit(corto_function f) {
    handlers[f->kind].deinit(f);
}

#define CORTO_CALL \
    /* If process does not own object, forward call */\
    if (corto_instanceof(corto_method_o, f)) {\
        corto_object instance = *(corto_object*)argptrs[0];\
        corto_object owner = corto_ownerof(instance);\
        if (owner \
            && corto_instanceof(corto_mount_o, owner) \
            && (corto_mount(owner)->kind != CORTO_SINK)) \
        {\
            if (!(owner == corto_getOwner())) {\
                corto_mount_invoke(owner, instance, f, (corto_word)argptrs);\
                return;\
            } else {\
                /* Odd */\
                return;\
            }\
        }\
    }\
    ((corto_callInvoke)f->impl)((void*)f->fdata, (void*)f->fptr, result, argptrs);

#define argcpytype(args, dst, src) \
  ptr = alloca(sizeof(dst)), *(dst*)ptr = va_arg(args, src), ptr

#define argcpyint(args, dst) argcpytype(args, dst, int)
#define argcpy(args, type) argcpytype(args, type, type)

/* Implement as macro to limit the number of frames on the stack (otherwise call
 * would have to rely on the public callv function) */
#define CORTO_CALLV \
    corto_int32 i, arg = 0;\
    void **argptrs = alloca((f->parameters.length + 1) * sizeof(void*));\
    void *ptr;\
    /* Add this */\
    if (f->kind != CORTO_FUNCTION) {\
        if (f->kind == CORTO_METAPROCEDURE) {\
            argptrs[arg] = argcpy(args, corto_any);\
        } else {\
            argptrs[arg] = argcpy(args, void*);\
        }\
        arg++;\
    }\
    for (i = 0; i < f->parameters.length; i ++, arg ++) {\
        corto_parameter *p = &f->parameters.buffer[i];\
        if (p->type->reference) {\
            argptrs[arg] = argcpy(args, void*);\
        } else {\
            switch(p->type->kind) {\
            case CORTO_VOID:\
                break;\
            case CORTO_ANY:\
                argptrs[arg] = argcpy(args, corto_any);\
                break;\
            case CORTO_ITERATOR:\
                argptrs[arg] = argcpy(args, corto_iter);\
                break;\
            case CORTO_PRIMITIVE:\
                switch(corto_primitive(p->type)->width) {\
                case CORTO_WIDTH_8: argptrs[arg] = argcpyint(args, corto_uint8); break;\
                case CORTO_WIDTH_16: argptrs[arg] = argcpyint(args, corto_uint16); break;\
                case CORTO_WIDTH_32: argptrs[arg] = argcpyint(args, corto_uint32); break;\
                case CORTO_WIDTH_64: argptrs[arg] = argcpy(args, corto_uint64); break;\
                case CORTO_WIDTH_WORD: argptrs[arg] = argcpy(args, corto_word); break;\
                    break;\
                }\
                break;\
            case CORTO_COMPOSITE:\
                argptrs[arg] = argcpy(args, void*);\
                break;\
            case CORTO_COLLECTION:\
                if(corto_collection(p->type)->kind == CORTO_SEQUENCE) {\
                    argptrs[arg] = argcpy(args, corto_objectseq);\
                } else {\
                    argptrs[arg] = argcpy(args, void*);\
                }\
                break;\
            }\
        }\
    }\
    CORTO_CALL

/* Call with variable argument list */
void corto_callv(corto_function f, corto_void* result, va_list args) {
    CORTO_CALLV
}

/* Call with variable arguments */
void corto_call(corto_function f, corto_void* result, ...) {
    va_list args;

    va_start(args, result);
    CORTO_CALLV
    va_end(args);
}

/* Call with buffer */
void corto_callb(corto_function f, corto_void* result, void** argptrs) {
    CORTO_CALL
}
