/*
 * db_dl.c
 *
 *  Created on: Dec 27, 2010
 *      Author: sander
 */

#include "db_dl.h"
#include "dlfcn.h"
#include "stdio.h"
#include "string.h"
#include "stdint.h"
#include "db_err.h"

#include "db_err.h"

typedef void*(*dlproc)(void);

/* Link dynamic library */
db_dl db_dlOpen(const char* file) {
	db_dl dl;

	dl = (db_dl)dlopen(file, RTLD_NOW);

	return dl;
}

/* Close dynamic library */
void db_dlClose(db_dl dl) {
	dlclose(dl);
}

/* Lookup symbol in dynamic library */
void* db_dlSym(db_dl dl, const char* sym) {
	return dlsym(dl, sym);
}

/* Lookup procedure in dynamic library */
void*(*db_dlProc(db_dl dl, const char* proc))(void) {
	return (dlproc)(intptr_t)dlsym(dl, proc);
}

const char* db_dlError(void) {
	return dlerror();
}
