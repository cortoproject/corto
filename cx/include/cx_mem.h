/*
 * cx_mem.h
 *
 *  Created on: Apr 9, 2012
 *      Author: sander
 */

#ifndef CX_MEM_H_
#define CX_MEM_H_

#include <stdlib.h>
#include <string.h>
#include "cx_err.h"
#include "cx_string.h"

#ifdef __cplusplus
extern "C" {
#endif

#define cx_calloc(n) calloc(n, 1)
#define cx_malloc(n) malloc(n);
#define cx_dealloc free
#define cx_realloc realloc

#ifdef __cplusplus
}
#endif

#endif /* CX_MEM_H_ */
