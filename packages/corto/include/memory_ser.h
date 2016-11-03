/*
 * corto_memory_ser.h
 *
 *  Created on: Sep 7, 2012
 *      Author: sander
 */

#ifndef CORTO_MEMORY_SER_H_
#define CORTO_MEMORY_SER_H_

#include "corto/serializer.h"

#ifdef __cplusplus
extern "C" {
#endif

struct corto_serializer_s corto_ser_keep(corto_modifier access, corto_operatorKind accessKind, corto_serializerTraceKind trace);
struct corto_serializer_s corto_ser_free(corto_modifier access, corto_operatorKind accessKind, corto_serializerTraceKind trace);
struct corto_serializer_s corto_ser_freeResources(corto_modifier access, corto_operatorKind accessKind, corto_serializerTraceKind trace);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_MEMORY_SER_H_ */
