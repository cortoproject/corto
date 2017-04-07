/*
 * corto_loader.h
 *
 *  Created on: Aug 30, 2012
 *      Author: sander
 */

#ifndef CORTO_LOADER_H_
#define CORTO_LOADER_H_

#include "corto/lang/_type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*corto_loadAction)(corto_string file, int argc, char* argv[], void* userData);

/* Load a package */
CORTO_EXPORT int corto_load(corto_string package, int argc, char* argv[]);

/* Load from a dynamic library */
CORTO_EXPORT corto_dl corto_loadValidLibrary(corto_string fileName, corto_string *build_out);
CORTO_EXPORT int corto_loadFromDl(corto_dl dl, char *fileName, int argc, char *argv[]);

/* Try loading a package (doesn't generate errors when not found) */
CORTO_EXPORT int corto_loadTry(corto_string str, int argc, char* argv[]);

CORTO_EXPORT corto_ll corto_loadGetDependencies(corto_string file);
CORTO_EXPORT corto_ll corto_loadGetPackages(void);
CORTO_EXPORT void corto_loadFreePackages(corto_ll packages);
CORTO_EXPORT corto_bool corto_loadRequiresPackage(corto_string package);
CORTO_EXPORT int corto_loadPackages(void);

CORTO_EXPORT int corto_loaderRegister(corto_string ext, corto_loadAction handler, void* userData);

CORTO_EXPORT void (*corto_loaderResolveProc(corto_string procName))(void);

typedef enum corto_loaderLocationKind {
    CORTO_LOCATION_ENV,
    CORTO_LOCATION_LIB,
    CORTO_LOCATION_LIBPATH,
    CORTO_LOCATION_INCLUDE,
    CORTO_LOCATION_NAME,
    CORTO_LOCATION_FULLNAME
} corto_loaderLocationKind;

CORTO_EXPORT corto_string corto_locate(corto_string package, corto_dl *dl_out, corto_loaderLocationKind kind);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_LOADER_H_ */
