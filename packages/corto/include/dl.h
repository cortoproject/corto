/*
 * c_dl.h
 *
 *  Created on: Dec 27, 2010
 *      Author: sander
 */

#ifndef CORE_DL_H_
#define CORE_DL_H_

#ifdef __cplusplus
extern "C" {
#endif

#define CORE_SO_EXTENSION "so"

typedef struct corto_dl_s* corto_dl;

/* Link dynamic library */
corto_dl corto_dlOpen(const char* file);

/* Close dynamic library */
void corto_dlClose(corto_dl dl);

/* Lookup symbol in dynamic library */
void* corto_dlSym(corto_dl dl, const char* sym);

/* Lookup procedure in dynamic library */
void*(*corto_dlProc(corto_dl dl, const char* proc))(void);

/* Return error code */
const char* corto_dlError(void);

#ifdef __cplusplus
}
#endif

#endif /* C_DL_H_ */
