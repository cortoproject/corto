#ifndef json_primitives_H
#define json_primitives_H

#include "parson.h"

#include "cortex.h"

#ifdef __cplusplus
extern "C" {
#endif

cx_int16 serializeNumber(cx_value *value, cx_string *out);
cx_int16 serializeBinary(cx_value *value, cx_string *out);
cx_int16 serializeBitmask(cx_value *value, cx_string *out);
cx_int16 serializeEnum(cx_value *value, cx_string *out);
cx_int16 serializeBoolean(cx_value *value, cx_string *out);
cx_int16 serializeText(cx_value *value, cx_string *out);
cx_int16 serializeAlias(cx_value *value, cx_string *out);

cx_bool json_deserPrimitive(void* p, cx_type t, JSON_Value* v);

#ifdef __cplusplus
}
#endif
#endif
