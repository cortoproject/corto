/*
 * cx_mm.h
 *
 *  Created on: Sep 7, 2012
 *      Author: sander
 */

#ifndef DB_MM_H_
#define DB_MM_H_

#include "cx_object.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DB_MAX_CYCLE_DEPTH (256)

#define DB_MMNODE_INIT {FALSE, 0}
struct cx_mmNode {
    cx_uint8 marked;
    cx_uint16 cycles;
};

#ifdef __cplusplus
}
#endif

#endif /* DB_MM_H_ */
