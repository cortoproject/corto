/*
 * cortex.h
 *
 *  Created on: Aug 21, 2012
 *      Author: sander
 */

#ifndef CORTEX_H_
#define CORTEX_H_

#include "cx.h"
#include "cx__type.h"
#include "cx__meta.h"
#include "cx_call.h"
#include "cx_convert.h"
#include "cx_dl.h"
#include "cx_err.h"
#include "cx_files.h"
#include "cx_loader.h"
#include "cx_ll.h"
#include "cx_mem.h"
#include "cx_metawalk.h"
#include "cx_object.h"
#include "cx_rbtree.h"
#include "cx_serializer.h"
#include "cx_string_deser.h"
#include "cx_string_ser.h"
#include "cx_string.h"
#include "cx_time.h"
#include "cx_util.h"

#ifdef __cplusplus
extern "C" {
#endif

int cx_start(void);
void cx_stop(void); /* Must be last statement of application. */
cx_bool cx_isbuiltin(cx_object o);
void cx_onunload(void(*handler)(void*), void* userData);
void cx_onexit(void(*handler)(void*), void* userData);

#ifdef __cplusplus
}
#endif

#endif /* CORTEX_H_ */
