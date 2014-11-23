/*
 * db_member.h
 *
 *  Created on: Aug 9, 2012
 *      Author: sander
 */

#ifndef DB_MEMBER_H_
#define DB_MEMBER_H_

#include "db__type.h"

#ifdef __cplusplus
extern "C" {
#endif

db_int16 db_member_init(db_member object);
db_int16 db_member_construct(db_member object);

#ifdef __cplusplus
}
#endif

#endif /* DB_MEMBER_H_ */
