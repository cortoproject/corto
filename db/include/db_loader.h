/*
 * db_loader.h
 *
 *  Created on: Aug 30, 2012
 *      Author: sander
 */

#ifndef DB_LOADER_H_
#define DB_LOADER_H_

#include "db__type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*db_loadAction)(db_string file, void* userData);

int db_load(db_string file);
int db_loaderRegister(db_string ext, db_loadAction handler, void* userData);

#ifdef __cplusplus
}
#endif

#endif /* DB_LOADER_H_ */
