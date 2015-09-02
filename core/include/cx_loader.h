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

typedef int (*cx_loadAction)(cx_string file, void* userData);

int cx_load(cx_string file);
cx_ll cx_loadGetPackages(void);
cx_bool cx_loadRequiresPackage(cx_string package);
void cx_loadFreePackages(cx_ll packages);
int cx_loadPackages(void);
int cx_loaderRegister(cx_string ext, cx_loadAction handler, void* userData);
cx_string cx_locateLib(cx_string lib);
cx_string cx_locate(cx_string package);

#ifdef __cplusplus
}
#endif

#endif /* CX_LOADER_H_ */
