/*
 * db_mem.h
 *
 *  Created on: Apr 9, 2012
 *      Author: sander
 */

#ifndef DB_MEM_H_
#define DB_MEM_H_

#include "stdlib.h"
#include "string.h"
#include "db_err.h"

#ifdef __cplusplus
extern "C" {
#endif

#define db_calloc(n) calloc(n, 1)
#define db_malloc(n) malloc(n);
#define db_dealloc free
#define db_realloc realloc
#define db_strdup strdup

#ifdef __cplusplus
}
#endif

#endif /* DB_MEM_H_ */
