/*
 * corto_mm.h
 *
 *  Created on: Sep 7, 2012
 *      Author: sander
 */

#ifndef CORTO_MM_H_
#define CORTO_MM_H_

#include "corto/object.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CORTO_MAX_CYCLE_DEPTH (256)

#define CORTO_MMNODE_INIT {FALSE, 0}
struct corto_mmNode {
    corto_uint8 marked;
    corto_uint16 cycles;
};

#ifdef __cplusplus
}
#endif

#endif /* CORTO_MM_H_ */
