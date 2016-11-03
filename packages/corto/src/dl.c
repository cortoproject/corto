/*
 * corto_dl.c
 *
 *  Created on: Dec 27, 2010
 *      Author: sander
 */

#include "corto/corto.h"

typedef void*(*dlproc)(void);

/* Link dynamic library */
corto_dl corto_dlOpen(const char* file) {
    corto_dl dl;

    dl = (corto_dl)dlopen(file, RTLD_NOW);

    return dl;
}

/* Close dynamic library */
void corto_dlClose(corto_dl dl) {
    dlclose(dl);
}

/* Lookup symbol in dynamic library */
void* corto_dlSym(corto_dl dl, const char* sym) {
    return dlsym(dl, sym);
}

/* Lookup procedure in dynamic library */
void*(*corto_dlProc(corto_dl dl, const char* proc))(void) {
    return (dlproc)(intptr_t)dlsym(dl, proc);
}

const char* corto_dlError(void) {
    return dlerror();
}
