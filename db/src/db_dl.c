/*
 * cx_dl.c
 *
 *  Created on: Dec 27, 2010
 *      Author: sander
 */

#include "cx_dl.h"
#include "dlfcn.h"
#include "stdio.h"
#include "string.h"
#include "stdint.h"
#include "cx_err.h"

#include "cx_err.h"

typedef void*(*dlproc)(void);

/* Link dynamic library */
cx_dl cx_dlOpen(const char* file) {
	cx_dl dl;

	dl = (cx_dl)dlopen(file, RTLD_NOW);

	return dl;
}

/* Close dynamic library */
void cx_dlClose(cx_dl dl) {
	dlclose(dl);
}

/* Lookup symbol in dynamic library */
void* cx_dlSym(cx_dl dl, const char* sym) {
	return dlsym(dl, sym);
}

/* Lookup procedure in dynamic library */
void*(*cx_dlProc(cx_dl dl, const char* proc))(void) {
	return (dlproc)(intptr_t)dlsym(dl, proc);
}

const char* cx_dlError(void) {
	return dlerror();
}
