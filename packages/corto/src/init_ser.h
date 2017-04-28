/*
 * corto_init_ser.h
 *
 *  Created on: July 12, 2014
 *      Author: sander
 */

#ifndef CORTO_INIT_SER_H_
#define CORTO_INIT_SER_H_

#include "corto/walk.h"

#ifdef __cplusplus
extern "C" {
#endif

corto_walk_opt corto_ser_init(corto_modifier access, corto_operatorKind accessKind, corto_walk_traceKind trace);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_INIT_SER_H_ */
