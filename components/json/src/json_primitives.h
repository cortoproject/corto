#ifndef json_primitives_H
#define json_primitives_H

#include "parson.h"
#include "json.h"

#ifdef __cplusplus
extern "C" {
#endif

corto_int16 serializeNumber(corto_value *value, corto_string *out, corto_json_ser_t *data);
corto_int16 serializeBinary(corto_value *value, corto_string *out, corto_json_ser_t *data);
corto_int16 serializeBitmask(corto_value *value, corto_string *out, corto_json_ser_t *data);
corto_int16 serializeEnum(corto_value *value, corto_string *out, corto_json_ser_t *data);
corto_int16 serializeBoolean(corto_value *value, corto_string *out, corto_json_ser_t *data);
corto_int16 serializeText(corto_value *value, corto_string *out, corto_json_ser_t *data);

corto_bool json_deserPrimitive(void* p, corto_type t, JSON_Value* v);

#ifdef __cplusplus
}
#endif
#endif
