/*
 * cortex.h
 *
 *  Created on: Aug 21, 2012
 *      Author: sander
 */

#ifndef CORTEX_H_
#define CORTEX_H_

#include "db__type.h"
#include "db__meta.h"
#include "db_object.h"
#include "db_mem.h"
#include "db_err.h"
#include "db_util.h"
#include "db_string.h"
#include "db_time.h"
#include "db_serializer.h"
#include "db_metawalk.h"
#include "db_convert.h"
#include "db_call.h"

#include "db_typedef.h"
#include "db_type.h"
#include "db_primitive.h"
#include "db_interface.h"
#include "db_struct.h"
#include "db_class.h"
#include "db_procedure.h"
#include "db_collection.h"

#ifdef __cplusplus
extern "C" {
#endif

int db_start(void);
void db_stop(void); /* Must be last statement of application. */
void db_onunload(void(*handler)(void*), void* userData);
void db_onexit(void(*handler)(void*), void* userData);

#ifdef __cplusplus
}
#endif

#endif /* CORTEX_H_ */
