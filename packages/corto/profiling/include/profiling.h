/* profiling.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef profiling_H
#define profiling_H

#include "corto.h"
#include "profiling__type.h"
#include "profiling__api.h"
#include "profiling__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::profiling::start(string name) */
cx_void _profiling_start(cx_string name);
#define profiling_start(name) _profiling_start(name)

/* ::corto::profiling::stop() */
cx_void _profiling_stop(void);
#define profiling_stop() _profiling_stop()

#ifdef __cplusplus
}
#endif
#endif

#include "profiling_Profile.h"
