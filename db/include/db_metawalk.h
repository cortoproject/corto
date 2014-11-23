/*
 * db_metawalk.h
 *
 *  Created on: Aug 28, 2012
 *      Author: sander
 */

#ifndef DB_METAWALK_H_
#define DB_METAWALK_H_

#include "db_serializer.h"

#ifdef __cplusplus
extern "C" {
#endif

db_int16 db_metaWalk(db_serializer s, db_type type, void* userData);
db_int16 db_serializeConstants(db_serializer s, db_value* v, void* userData);

#ifdef __cplusplus
}
#endif

#endif /* DB_METAWALK_H_ */
