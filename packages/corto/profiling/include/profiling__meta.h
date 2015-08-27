/* profiling__meta.h
 *
 * Loads objects in object store.
 * This file contains generated code. Do not modify!
 */

#ifndef profiling_META_H
#define profiling_META_H

#include "corto.h"

#include "profiling__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto */
extern cx_package _o;

/* ::corto::profiling */
extern cx_package profiling_o;

/* ::corto::profiling::Profile */
extern cx_struct profiling_Profile_o;

/* ::corto::profiling::Profile::callCount */
extern cx_member profiling_Profile_callCount_o;

/* ::corto::profiling::Profile::nanoseconds */
extern cx_member profiling_Profile_nanoseconds_o;

/* ::corto::profiling::Profile::seconds */
extern cx_member profiling_Profile_seconds_o;

/* ::corto::profiling::start(string name) */
extern cx_function profiling_start_o;

/* ::corto::profiling::stop() */
extern cx_function profiling_stop_o;

int profiling_load(void);
#ifdef __cplusplus
}
#endif
#endif

