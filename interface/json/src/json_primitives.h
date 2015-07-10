
#include "parson.h"

#include "cortex.h"

cx_int16 serializeNumber(cx_value *value, cx_string *out);
cx_int16 serializeBinary(cx_value *value, cx_string *out);
cx_int16 serializeBitmask(cx_value *value, cx_string *out);
cx_int16 serializeEnum(cx_value *value, cx_string *out);
cx_int16 serializeBoolean(cx_value *value, cx_string *out);
cx_int16 serializeText(cx_value *value, cx_string *out);
cx_int16 serializeAlias(cx_value *value, cx_string *out);

void json_deserNumber(cx_object o, JSON_Value *value);
void json_deserBinary(cx_object o, JSON_Value *value);
void json_deserText(cx_object o, JSON_Value *value);
