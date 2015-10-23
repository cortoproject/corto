
#include "json_primitives.h"
#include "parson.h"

corto_int16 serializeNumber(corto_value *value, corto_string *out, corto_json_ser_t *data) {
    CORTO_UNUSED(data);

    corto_type t = corto_valueType(value);

    /* JSON doesn't support hex notation, so convert to integer */
    if (corto_primitive(t)->kind == CORTO_BINARY) {
        t = corto_type(corto_uint64_o);
    }

    corto_void  *v = corto_valueValue(value);
    corto_int16 result = corto_convert(corto_primitive(t), v, corto_primitive(corto_string_o), out);
    return result;
}

static corto_int16 serializeNumericWithPrefix(corto_value *value, corto_string *out, const char *prefix, corto_json_ser_t *data) {
    corto_string raw;
    corto_void *v = corto_valueValue(value);
    if (corto_convert(corto_primitive(corto_valueType(value)), v, corto_primitive(corto_string_o), &raw)) {
        goto error;
    }

    if (data->serializePrefix) {
        corto_asprintf(out, "\"%s %s\"", prefix, raw);
    } else {
        corto_asprintf(out, "\"%s\"", raw);
    }

    corto_dealloc(raw);

    return 0;
error:
    corto_dealloc(raw);
    return -1;
}

corto_int16 serializeBinary(corto_value *value, corto_string *out, corto_json_ser_t *data) {
    return serializeNumber(value, out, data);
}

corto_int16 serializeBitmask(corto_value *value, corto_string *out, corto_json_ser_t *data) {
    return serializeNumericWithPrefix(value, out, "@M", data);
}

corto_int16 serializeEnum(corto_value *value, corto_string *out, corto_json_ser_t *data) {
    return serializeNumericWithPrefix(value, out, "@E", data);
}

corto_int16 serializeBoolean(corto_value *value, corto_string *out, corto_json_ser_t *data) {
    CORTO_UNUSED(data);
    corto_bool b = *(corto_bool *)corto_valueValue(value);
    if (b) {
        *out = corto_alloc(sizeof("true"));
        strcpy(*out, "true");
    } else {
        *out = corto_alloc(sizeof("false"));
        strcpy(*out, "false");
    }
    return 0;
}

corto_int16 serializeText(corto_value *value, corto_string *out, corto_json_ser_t *data) {
    CORTO_UNUSED(data);
    corto_type type = corto_valueType(value);
    corto_void *v = corto_valueValue(value);
    corto_primitiveKind kind = corto_primitive(type)->kind;
    if (kind == CORTO_CHARACTER || (kind == CORTO_TEXT && (*(corto_string *)v))) {
        corto_string raw;
        size_t length;
        int needEscape = 0;
        if (corto_convert(corto_primitive(type), v, corto_primitive(corto_string_o), &raw)) {
            goto error;
        }
        if (*raw == '@') {
            needEscape = 1;
        }
        length = stresc(NULL, 0, raw);
        *out = corto_alloc(length + 3 + needEscape);
        (*out)[0] = '"';
        (*out)[1] = '@';
        stresc(*out + 1 + needEscape, length, raw);
        (*out)[length + needEscape + 1] = '"';
        (*out)[length + needEscape + 2] = '\0';
        corto_dealloc(raw);
    } else {
        *out = corto_alloc(sizeof("null"));
        strcpy(*out, "null");
    }
    return 0;
error:
    return -1;
}

static corto_bool json_deserBoolean(void* o, corto_type t, JSON_Value* v) {
    corto_primitiveKind kind = corto_primitive(t)->kind;
    corto_assert(kind == CORTO_BOOLEAN, "not deserializing boolean");
    if (json_value_get_type(v) != JSONBoolean) {
        corto_error("no deserializing JSON boolean");
        goto error;
    }
    *(corto_bool *)o = json_value_get_boolean(v);
    return FALSE;
error:
    return TRUE;
}

static corto_bool json_deserNumber(void* o, corto_type t, JSON_Value* v) {
    corto_primitiveKind kind = corto_primitive(t)->kind;
    corto_assert(kind == CORTO_INTEGER || kind == CORTO_UINTEGER
        || kind == CORTO_FLOAT, "not deserializing uint, int, or float");
    if (json_value_get_type(v) != JSONNumber) {
        corto_error("not deserializing JSON number");
        goto error;
    }
    corto_float64 number = json_value_get_number(v);
    corto_convert(corto_primitive(corto_float64_o), &number, corto_primitive(t), o);
    return FALSE;
error:
    return TRUE;
}

static corto_bool json_deserText(void* p, corto_type t, JSON_Value *v) {
    corto_primitiveKind kind = corto_primitive(t)->kind;
    corto_assert(kind == CORTO_TEXT, "not deserializing text");
    const char *s = json_value_get_string(v);
    if (!s) {
        corto_error("not deserializing JSON text");
        goto error;
    }
    *(corto_string *)p = strdup(s);
    return FALSE;
error:
    return TRUE;
}

corto_bool json_deserPrimitive(void* p, corto_type t, JSON_Value* v) {
    corto_assert(t->kind == CORTO_PRIMITIVE, "not deserializing primitive");
    corto_bool error = FALSE;
    switch (corto_primitive(t)->kind) {
        case CORTO_BINARY:
            break;
        case CORTO_BOOLEAN:
            error = json_deserBoolean(p, t, v);
            break;
        case CORTO_CHARACTER:
            break;
        case CORTO_INTEGER:
        case CORTO_UINTEGER:
        case CORTO_FLOAT:
            error = json_deserNumber(p, t, v);
            break;
        case CORTO_TEXT:
            error = json_deserText(p, t, v);
            break;
        case CORTO_ENUM:
            break;
        case CORTO_BITMASK:
            break;
    }
    return error;
}
