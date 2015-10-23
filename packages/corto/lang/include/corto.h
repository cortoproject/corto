/*
 * corto.h
 *
 *  Created on: Aug 21, 2012
 *      Author: sander
 */

#ifndef CORTO_H_
#define CORTO_H_

#include "_corto.h"
#include "corto__type.h"
#include "corto__meta.h"
#include "corto_arg.h"
#include "corto_async.h"
#include "corto_call.h"
#include "corto_compare_ser.h"
#include "corto_convert.h"
#include "corto_copy_ser.h"
#include "corto_crc.h"
#include "corto_depresolver.h"
#include "corto_dl.h"
#include "corto_env.h"
#include "corto_err.h"
#include "corto_file.h"
#include "corto_files.h"
#include "corto_generator.h"
#include "corto_generatorDepWalk.h"
#include "corto_generatorTypeDepWalk.h"
#include "corto_init_ser.h"
#include "corto_loader.h"
#include "corto_iter.h"
#include "corto_ll.h"
#include "corto_loader.h"
#include "corto_mem.h"
#include "corto_memory_ser.h"
#include "corto_metawalk.h"
#include "corto_mm.h"
#include "corto_object.h"
#include "corto_operator.h"
#include "corto_overload.h"
#include "corto_platform.h"
#include "corto_rbtree.h"
#include "corto_serializer.h"
#include "corto_string.h"
#include "corto_string_deser.h"
#include "corto_string_ser.h"
#include "corto_string.h"
#include "corto_time.h"
#include "corto_util.h"
#include "corto_value.h"

#include "cxstr.h"

#ifdef __cplusplus
extern "C" {
#endif

int corto_start(void);
void corto_stop(void); /* Must be last statement of application. */
corto_bool corto_isbuiltin(corto_object o);
void corto_onunload(void(*handler)(void*), void* userData);
void corto_onexit(void(*handler)(void*), void* userData);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_H_ */
