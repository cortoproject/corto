/*
 * db_memory_ser.h
 *
 *  Created on: Sep 7, 2012
 *      Author: sander
 */

#ifndef DB_MEMORY_SER_H_
#define DB_MEMORY_SER_H_

#include "db_serializer.h"

#ifdef __cplusplus
extern "C" {
#endif

struct db_serializer_s db_ser_keep(db_modifier access, db_operatorKind accessKind, db_serializerTraceKind trace);
struct db_serializer_s db_ser_free(db_modifier access, db_operatorKind accessKind, db_serializerTraceKind trace);
struct db_serializer_s db_ser_freeResources(db_modifier access, db_operatorKind accessKind, db_serializerTraceKind trace);

#ifdef __cplusplus
}
#endif

#endif /* DB_MEMORY_SER_H_ */
