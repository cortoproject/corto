/* profiling__api.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef profiling__API_H
#define profiling__API_H

#include "profiling__type.h"
#include "corto.h"

#ifdef __cplusplus
extern "C" {
#endif
/* ::corto::profiling::Profile */
profiling_Profile* profiling_Profile__create(cx_uint64 seconds, cx_uint64 nanoseconds, cx_uint64 callCount);
profiling_Profile* profiling_Profile__createChild(cx_object _parent, cx_string _name, cx_uint64 seconds, cx_uint64 nanoseconds, cx_uint64 callCount);

profiling_Profile* profiling_Profile__declare(void);
profiling_Profile* profiling_Profile__declareChild(cx_object _parent, cx_string _name);
cx_int16 profiling_Profile__define(profiling_Profile* _this, cx_uint64 seconds, cx_uint64 nanoseconds, cx_uint64 callCount);
void profiling_Profile__update(profiling_Profile* _this, cx_uint64 seconds, cx_uint64 nanoseconds, cx_uint64 callCount);
void profiling_Profile__set(profiling_Profile* _this, cx_uint64 seconds, cx_uint64 nanoseconds, cx_uint64 callCount);
cx_string profiling_Profile__str(profiling_Profile* value);
profiling_Profile* profiling_Profile__fromStr(profiling_Profile* value, cx_string str);
cx_int16 profiling_Profile__copy(profiling_Profile* *dst, profiling_Profile* src);
cx_int16 profiling_Profile__compare(profiling_Profile* dst, profiling_Profile* src);

cx_int16 profiling_Profile__init(profiling_Profile* value);
cx_int16 profiling_Profile__deinit(profiling_Profile* value);


#ifdef __cplusplus
}
#endif
#endif

