/*
 * db_convert.h
 *
 *  Created on: Aug 23, 2012
 *      Author: sander
 *
 *      The database can perform implicit type-conversions between all primitive types. This is not the same as type transformations, which
 *      are more flexible, not limited to primitive types, but also more heavy-weight.
 */

#ifndef DB_CONVERT_H_
#define DB_CONVERT_H_

#include "db__type.h"

#ifdef __cplusplus
extern "C" {
#endif

void db_convertInit(void);
db_int16 db_convert(db_primitive fromType, void *from, db_primitive toType, void *to);

#ifdef __cplusplus
}
#endif

#endif /* DB_CONVERT_H_ */
