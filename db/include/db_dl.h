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

typedef struct db_dl_s* db_dl;

/* Link dynamic library */
db_dl db_dlOpen(const char* file);

/* Close dynamic library */
void db_dlClose(db_dl dl);

/* Lookup symbol in dynamic library */
void* db_dlSym(db_dl dl, const char* sym);

/* Lookup procedure in dynamic library */
void*(*db_dlProc(db_dl dl, const char* proc))(void);

/* Return error code */
const char* db_dlError(void);

#ifdef __cplusplus
}
#endif

#endif /* C_DL_H_ */
