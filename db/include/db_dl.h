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

typedef struct cx_dl_s* cx_dl;

/* Link dynamic library */
cx_dl cx_dlOpen(const char* file);

/* Close dynamic library */
void cx_dlClose(cx_dl dl);

/* Lookup symbol in dynamic library */
void* cx_dlSym(cx_dl dl, const char* sym);

/* Lookup procedure in dynamic library */
void*(*cx_dlProc(cx_dl dl, const char* proc))(void);

/* Return error code */
const char* cx_dlError(void);

#ifdef __cplusplus
}
#endif

#endif /* C_DL_H_ */
