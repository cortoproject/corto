/*
 * corto_init_ser.h
 *
 *  Created on: July 12, 2014
 *      Author: sander
 */

#ifndef CORTO_INIT_SER_H_
#define CORTO_INIT_SER_H_

#include "corto_serializer.h"

#ifdef __cplusplus
extern "C" {
#endif
    
struct corto_serializer_s corto_ser_init(corto_modifier access, corto_operatorKind accessKind, corto_serializerTraceKind trace);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_INIT_SER_H_ */
