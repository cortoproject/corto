/*
 * cortex.h
 *
 *  Created on: Aug 21, 2012
 *      Author: sander
 */

#ifndef CORTEX_H_
#define CORTEX_H_

#include "cx__type.h"
#include "cx__meta.h"
#include "cx_object.h"
#include "cx_mem.h"
#include "cx_err.h"
#include "cx_util.h"
#include "cx_string.h"
#include "cx_time.h"
#include "cx_serializer.h"
#include "cx_metawalk.h"
#include "cx_convert.h"
#include "cx_call.h"

#include "cx_typedef.h"
#include "cx_type.h"
#include "cx_primitive.h"
#include "cx_interface.h"
#include "cx_struct.h"
#include "cx_class.h"
#include "cx_procedure.h"
#include "cx_collection.h"

#ifdef __cplusplus
extern "C" {
#endif

int cx_start(void);
void cx_stop(void); /* Must be last statement of application. */
void cx_onunload(void(*handler)(void*), void* userData);
void cx_onexit(void(*handler)(void*), void* userData);

#ifdef __cplusplus
}
#endif

#endif /* CORTEX_H_ */
