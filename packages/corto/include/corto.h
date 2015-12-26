/*
 * corto.h
 *
 *  Created on: Aug 21, 2012
 *      Author: sander
 */

#ifndef CORTO_H
#define CORTO_H

#include "lang/lang.h"
#include "core/core.h"

#include "corto/arg.h"
#include "corto/async.h"
#include "corto/call.h"
#include "corto/compare_ser.h"
#include "corto/convert.h"
#include "corto/copy_ser.h"
#include "corto/crc.h"
#include "corto/depresolver.h"
#include "corto/dl.h"
#include "corto/env.h"
#include "corto/err.h"
#include "corto/file.h"
#include "corto/files.h"
#include "corto/generator.h"
#include "corto/generatorDepWalk.h"
#include "corto/generatorTypeDepWalk.h"
#include "corto/init_ser.h"
#include "corto/loader.h"
#include "corto/iter.h"
#include "corto/ll.h"
#include "corto/loader.h"
#include "corto/mem.h"
#include "corto/memory_ser.h"
#include "corto/metawalk.h"
#include "corto/mm.h"
#include "corto/object.h"
#include "corto/operator.h"
#include "corto/overload.h"
#include "corto/platform.h"
#include "corto/rbtree.h"
#include "corto/serializer.h"
#include "corto/string.h"
#include "corto/string_deser.h"
#include "corto/string_ser.h"
#include "corto/string.h"
#include "corto/time.h"
#include "corto/util.h"
#include "corto/value.h"

#include "cxstr.h"

#ifdef __cplusplus
extern "C" {
#endif

int corto_start(void);
int corto_stop(void);
corto_string corto_getBuild(void); /* Used for catching library conflicts */
corto_bool corto_isbuiltin(corto_object o);
void corto_onunload(void(*handler)(void*), void* userData);
void corto_onexit(void(*handler)(void*), void* userData);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_H_ */
