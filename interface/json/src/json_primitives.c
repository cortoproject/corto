
#include "json_primitives.h"

cx_int16 serializeNumber(cx_value *value, cx_string *out) {
    cx_type t = cx_valueType(value);
    cx_void  *v = cx_valueValue(value);
    cx_int16 result = cx_convert(cx_primitive(t), v, cx_primitive(cx_string_o), out);
    return result;
}

static cx_int16 serializeNumericWithPrefix(cx_value *value, cx_string *out, const char *prefix) {
    cx_string raw;
    cx_void *v = cx_valueValue(value);
    if (cx_convert(cx_primitive(cx_valueType(value)), v, cx_primitive(cx_string_o), &raw)) {
        goto error;
    }
    int length = snprintf(NULL, 0, "\"%s %s\"", prefix, raw);
    if (length < 0) {
        goto error;
    }
    *out = cx_malloc(length + 1);
    if (sprintf(*out, "\"%s %s\"", prefix, raw) < 0) {
        goto error;
    }
    cx_dealloc(raw);
    return 0;
error:
    cx_dealloc(raw);
    return -1;
}

cx_int16 serializeBinary(cx_value *value, cx_string *out) {
    return serializeNumericWithPrefix(value, out, "@B");
}

cx_int16 serializeBitmask(cx_value *value, cx_string *out) {
    return serializeNumericWithPrefix(value, out, "@M");
}

cx_int16 serializeEnum(cx_value *value, cx_string *out) {
    return serializeNumericWithPrefix(value, out, "@E");
}

cx_int16 serializeBoolean(cx_value *value, cx_string *out) {
    cx_bool b = *(cx_bool *)cx_valueValue(value);
    if (b) {
        *out = cx_malloc(sizeof("true"));
        strcpy(*out, "true");
    } else {
        *out = cx_malloc(sizeof("false"));
        strcpy(*out, "false");
    }
    return 0;
}

cx_int16 serializeText(cx_value *value, cx_string *out) {
    cx_type type = cx_valueType(value);
    cx_void *v = cx_valueValue(value);
    cx_primitiveKind kind = cx_primitive(type)->kind;
    if (kind == CX_CHARACTER || (kind == CX_TEXT && (*(cx_string *)v))) {
        cx_string raw;
        size_t length;
        int needEscape = 0;
        if (cx_convert(cx_primitive(type), v, cx_primitive(cx_string_o), &raw)) {
            goto error;
        }
        if (*raw == '@') {
            needEscape = 1;
        }
        length = stresc(NULL, 0, raw);
        *out = cx_malloc(length + 3 + needEscape);
        (*out)[0] = '"';
        (*out)[1] = '@';
        stresc(*out + 1 + needEscape, length, raw);
        (*out)[length + needEscape + 1] = '"';
        (*out)[length + needEscape + 2] = '\0';
        cx_dealloc(raw);
    } else {
        *out = cx_malloc(sizeof("null"));
        strcpy(*out, "null");
    }
    return 0;
error:
    return -1;
}

cx_int16 serializeAlias(cx_value *value, cx_string *out) {
    CX_UNUSED(value);
    *out = cx_malloc(sizeof("null"));
    strcpy(*out, "null");
    return 0;
}

static void json_deserNumber(void* o, cx_type t, JSON_Value *value) {
    cx_primitiveKind kind = cx_primitive(t)->kind;
    cx_assert(kind == CX_INTEGER || kind == CX_UINTEGER
        || kind == CX_FLOAT, "not deserializing uint, int, or float");
    if (json_value_get_type(value) != JSONNumber) {
        cx_error("not deserializing number");
        goto error;
    }
    cx_float64 number = json_value_get_number(value);
    cx_convert(cx_primitive(cx_float64_o), &number, cx_primitive(t), o);
error:;
}

static void json_deserText(void* p, cx_type t, JSON_Value *v) {
    cx_primitiveKind kind = cx_primitive(t)->kind;
    cx_assert(kind == CX_TEXT, "not deserializing text");
    const char *s = json_value_get_string(v);
    if (!s) {
        cx_error("could not deserialize text");
        goto error;
    }
    *(cx_string *)p = strdup(s);
error:;
}

cx_bool json_deserPrimitive(void* p, cx_type t, JSON_Value* v) {
    cx_assert(t->kind == CX_PRIMITIVE, "not deserializing primitive");
    cx_bool error = FALSE;
    switch (cx_primitive(t)->kind) {
        case CX_BINARY:
            break;
        case CX_BOOLEAN:
            break;
        case CX_CHARACTER:
            break;
        case CX_INTEGER:
        case CX_UINTEGER:
        case CX_FLOAT:
            json_deserNumber(p, t, v);
            break;
        case CX_TEXT:
            json_deserText(p, t, v);
            break;
        case CX_ENUM:
            break;
        case CX_BITMASK:
            break;
        case CX_ALIAS:
            cx_critical("alias type not supported");
            break;
    }
    return error;
}
