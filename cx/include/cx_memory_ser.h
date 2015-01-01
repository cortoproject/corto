/*
 * cx_memory_ser.h
 *
 *  Created on: Sep 7, 2012
 *      Author: sander
 */

#ifndef DB_MEMORY_SER_H_
#define DB_MEMORY_SER_H_

#include "cx_serializer.h"

#ifdef __cplusplus
extern "C" {
#endif

struct cx_serializer_s cx_ser_keep(cx_modifier access, cx_operatorKind accessKind, cx_serializerTraceKind trace);
struct cx_serializer_s cx_ser_free(cx_modifier access, cx_operatorKind accessKind, cx_serializerTraceKind trace);
struct cx_serializer_s cx_ser_freeResources(cx_modifier access, cx_operatorKind accessKind, cx_serializerTraceKind trace);

#ifdef __cplusplus
}
#endif

#endif /* DB_MEMORY_SER_H_ */
