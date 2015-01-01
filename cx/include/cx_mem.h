/*
 * cx_mem.h
 *
 *  Created on: Apr 9, 2012
 *      Author: sander
 */

#ifndef DB_MEM_H_
#define DB_MEM_H_

#include <stdlib.h>
#include <string.h>
#include "cx_err.h"

#ifdef __cplusplus
extern "C" {
#endif

#define cx_calloc(n) calloc(n, 1)
#define cx_malloc(n) malloc(n);
#define cx_dealloc free
#define cx_realloc realloc
#define cx_strdup strdup

#ifdef __cplusplus
}
#endif

#endif /* DB_MEM_H_ */
