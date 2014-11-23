/*
 * db_typedef.h
 *
 *  Created on: Aug 5, 2012
 *      Author: sander
 */

#ifndef DB_TYPEDEF_H_
#define DB_TYPEDEF_H_

#include "db__type.h"

#ifdef __cplusplus
extern "C" {
#endif

db_int16 db_typedef_init(db_typedef object);
db_int16 db_typedef_construct(db_typedef object);
void db_typedef_destruct(db_typedef object);
db_type db_typedef_realType(db_typedef _this);

#ifdef __cplusplus
}
#endif

#endif /* DB_TYPEDEF_H_ */
