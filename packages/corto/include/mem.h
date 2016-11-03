/*
 * corto_mem.h
 *
 *  Created on: Apr 9, 2012
 *      Author: sander
 */

#ifndef CORTO_MEM_H_
#define CORTO_MEM_H_

#include <stdlib.h>
#include <string.h>
#include "corto/err.h"
#include "corto/string.h"

#ifdef __cplusplus
extern "C" {
#endif

#define corto_calloc(n) calloc(n, 1)
#define corto_alloc(n) malloc(n)
#define corto_dealloc free
#define corto_realloc realloc

#ifdef __cplusplus
}
#endif

#endif /* CORTO_MEM_H_ */
