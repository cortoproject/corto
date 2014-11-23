/*
 * db_init_ser.h
 *
 *  Created on: July 12, 2014
 *      Author: sander
 */

#ifndef DB_INIT_SER_H_
#define DB_INIT_SER_H_

#include "db_serializer.h"

#ifdef __cplusplus
extern "C" {
#endif
    
struct db_serializer_s db_ser_init(db_modifier access, db_operatorKind accessKind, db_serializerTraceKind trace);

#ifdef __cplusplus
}
#endif

#endif /* DB_INIT_SER_H_ */
