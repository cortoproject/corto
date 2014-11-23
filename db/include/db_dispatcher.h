/*
 * db_dispatcher.h
 *
 *  Created on: Feb 9, 2013
 *      Author: sander
 */

#ifndef DB_DISPATCHER_H_
#define DB_DISPATCHER_H_

#include "db__type.h"

#ifdef __cplusplus
extern "C" {
#endif

void db_dispatcher_post(db_dispatcher _this, db_event event);
db_event db_dispatcher_getEvent(db_dispatcher _this, db_observer observer, db_object me, db_object observable, db_object source);
db_int16 db_event_uniqueKind(void);
void db_event_processed(db_event event);

#ifdef __cplusplus
}
#endif

#endif /* DB_DISPATCHER_H_ */
