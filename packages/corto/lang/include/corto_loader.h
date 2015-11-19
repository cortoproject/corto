/*
 * corto_loader.h
 *
 *  Created on: Aug 30, 2012
 *      Author: sander
 */

#ifndef CORTO_LOADER_H_
#define CORTO_LOADER_H_

#include "corto__type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*corto_loadAction)(corto_string file, int argc, char* argv[], void* userData);

/* Load a package */
int corto_load(corto_string package, int argc, char* argv[]);

/* Load a component */
int corto_loadComponent(corto_string component, int argc, char* argv[]);

corto_ll corto_loadGetComponents(void);
void corto_loadFreeComponents(corto_ll packages);
corto_bool corto_loadRequiresComponent(corto_string package);

corto_ll corto_loadGetPackages(void);
void corto_loadFreePackages(corto_ll packages);
corto_bool corto_loadRequiresPackage(corto_string package);
int corto_loadPackages(void);

int corto_loaderRegister(corto_string ext, corto_loadAction handler, void* userData);

corto_string corto_locate(corto_string package);
corto_string corto_locateComponent(corto_string component);
corto_string corto_locateGenerator(corto_string component);
corto_string corto_locateLibrary(corto_string lib);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_LOADER_H_ */
