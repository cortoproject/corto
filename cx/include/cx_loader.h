/*
 * cx_loader.h
 *
 *  Created on: Aug 30, 2012
 *      Author: sander
 */

#ifndef DB_LOADER_H_
#define DB_LOADER_H_

#include "cx__type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*cx_loadAction)(cx_string file, void* userData);

int cx_load(cx_string file);
int cx_loaderRegister(cx_string ext, cx_loadAction handler, void* userData);

#ifdef __cplusplus
}
#endif

#endif /* DB_LOADER_H_ */
