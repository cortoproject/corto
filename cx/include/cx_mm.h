/*
 * cx_mm.h
 *
 *  Created on: Sep 7, 2012
 *      Author: sander
 */

#ifndef CX_MM_H_
#define CX_MM_H_

#include "cx_object.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CX_MAX_CYCLE_DEPTH (256)

#define CX_MMNODE_INIT {FALSE, 0}
struct cx_mmNode {
    cx_uint8 marked;
    cx_uint16 cycles;
};

#ifdef __cplusplus
}
#endif

#endif /* CX_MM_H_ */
