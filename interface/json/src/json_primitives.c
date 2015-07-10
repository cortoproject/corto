
#include "json_primitives.h"

static cx_primitiveKind json_primitiveKind(cx_object o) {
    cx_assert(cx_typeof(o)->kind == CX_PRIMITIVE, "not deserializing primitive kind");
    return cx_primitive(cx_typeof(o))->kind;
}

void json_deserNumber(cx_object o, JSON_Value *value) {
    cx_id id;
    cx_primitiveKind primitiveKind = json_primitiveKind(o);
    cx_assert(primitiveKind == CX_INTEGER || primitiveKind == CX_UINTEGER
        || primitiveKind == CX_FLOAT, "not deserializing uint, int, or float");
    if (json_value_get_type(value) != JSONNumber) {
        cx_error("not deserializing number");
        goto error;
    }
    cx_float64 number = json_value_get_number(value);
    cx_convert(cx_primitive(cx_float64_o), &number, cx_primitive(cx_typeof(o)), o);
error:;
}

void json_deserText(cx_object o, JSON_Value *value) {
    cx_primitiveKind primitiveKind = json_primitiveKind(o);
    cx_assert(primitiveKind == CX_TEXT, "not deserializing text");
    if (json_value_get_type(value) != JSONString) {
        goto error;
    }
    const char *s = json_value_get_string(value);
    *(cx_string *)o = strdup(s);
error:;
}
