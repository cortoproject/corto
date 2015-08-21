/* cx_array.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef cx_api_H
#define cx_api_H

#include "cortex.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct c_apiWalk_t {
    cx_generator g;
    g_file header;
    g_file source;
    cx_object current;
    cx_uint32 parameterCount;
    cx_ll memberCache;
    cx_ll collections;
} c_apiWalk_t;

cx_int16 c_apiTypeCreate(cx_type t, c_apiWalk_t *data);
cx_int16 c_apiTypeCreateChild(cx_type t, c_apiWalk_t *data);
cx_int16 c_apiTypeStr(cx_type t, c_apiWalk_t *data);

cx_int16 c_apiTypeDeclare(cx_type o, c_apiWalk_t *data);
cx_int16 c_apiTypeDeclareChild(cx_type o, c_apiWalk_t *data);
cx_int16 c_apiTypeDefine(cx_type o, c_apiWalk_t *data);
cx_int16 c_apiTypeUpdate(cx_type o, c_apiWalk_t *data);
cx_int16 c_apiTypeSet(cx_type t, c_apiWalk_t *data);
cx_int16 c_apiTypeStr(cx_type o, c_apiWalk_t *data);
cx_int16 c_apiTypeFromStr(cx_type o, c_apiWalk_t *data);
cx_int16 c_apiTypeCopy(cx_type o, c_apiWalk_t *data);
cx_int16 c_apiTypeCompare(cx_type o, c_apiWalk_t *data);

cx_int16 c_apiTypeInit(cx_type o, c_apiWalk_t *data);
cx_int16 c_apiTypeDeinit(cx_type o, c_apiWalk_t *data);

int c_apiCollectionWalk(void* o, void* userData);

#ifdef __cplusplus
}
#endif

#endif
