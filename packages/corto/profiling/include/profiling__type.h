/* profiling__type.h
 *
 * Type definitions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef profiling__type_H
#define profiling__type_H

#include "corto.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define profiling_Profile(o) ((profiling_Profile *)cx_assertType((cx_type)profiling_Profile_o, o))

/* Type definitions */
/*  ::corto::profiling::Profile */
typedef struct profiling_Profile profiling_Profile;

struct profiling_Profile {
    cx_uint64 seconds;
    cx_uint64 nanoseconds;
    cx_uint64 callCount;
};

#ifdef __cplusplus
}
#endif
#endif

