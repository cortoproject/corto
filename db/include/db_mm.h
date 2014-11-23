/*
 * db_mm.h
 *
 *  Created on: Sep 7, 2012
 *      Author: sander
 */

#ifndef DB_MM_H_
#define DB_MM_H_

#include "db_object.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DB_MAX_CYCLE_DEPTH (256)

#define DB_MMNODE_INIT {FALSE, 0}
struct db_mmNode {
    db_uint8 marked;
    db_uint16 cycles;
};

#ifdef __cplusplus
}
#endif

#endif /* DB_MM_H_ */
