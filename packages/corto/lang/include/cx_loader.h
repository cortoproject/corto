/*
 * cx_loader.h
 *
 *  Created on: Aug 30, 2012
 *      Author: sander
 */

#ifndef CX_LOADER_H_
#define CX_LOADER_H_

#include "cx__type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*cx_loadAction)(cx_string file, int argc, char* argv[], void* userData);

/* Load a package */
int cx_load(cx_string package, int argc, char* argv[]);

/* Load a component */
int cx_loadComponent(cx_string component, int argc, char* argv[]);

cx_ll cx_loadGetComponents(void);
void cx_loadFreeComponents(cx_ll packages);
cx_bool cx_loadRequiresComponent(cx_string package);

cx_ll cx_loadGetPackages(void);
void cx_loadFreePackages(cx_ll packages);
cx_bool cx_loadRequiresPackage(cx_string package);
int cx_loadPackages(void);

int cx_loaderRegister(cx_string ext, cx_loadAction handler, void* userData);

cx_string cx_locate(cx_string package);
cx_string cx_locateComponent(cx_string component);
cx_string cx_locateLibrary(cx_string lib);

#ifdef __cplusplus
}
#endif

#endif /* CX_LOADER_H_ */
