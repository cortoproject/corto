#include <inttypes.h>
#include <stdio.h>
#include <string.h>

#include "cx_generator.h"
#include "cx_serializer.h"
#include "cx_string.h"
#include "cortex.h"
#include "ser_sqlite.h"

/*
 * https://www.sqlite.org/lang_update.html
 */

/* agreed not to change anything except the first argument of the signature */
static cx_bool cx_ser_appendstrbuff(cx_sqlite_ser_t* data, char* str) {
    if (!data->ptr) {
        data->ptr = data->buffer;
    }
    if (!data->ptr) {
        data->buffer = strdup(str);
        data->ptr = data->buffer;
    } else {
        cx_uint32 length, bufferLength;

        if (!data->length) {
            data->buffer = cx_realloc(data->buffer, strlen(data->buffer) + strlen(str) + 1);
            data->ptr = data->buffer;
        }

        length = strlen(str);
        bufferLength = strlen(data->buffer);

        if (data->maxlength && ((bufferLength + length) >= data->maxlength)) {
            strncat(data->ptr, str, data->maxlength - bufferLength);
            goto maxreached;
        } else {
            strcat(data->ptr, str);
        }
    }

    return TRUE;
maxreached:
    return FALSE;
}

/* agreed not to change anything except the first argument of the signature */
/* Append string to serializer-result */
static cx_bool cx_ser_appendstr(cx_sqlite_ser_t* data, cx_string fmt, ...) {
    char alloc[1024];
    char *buff = alloc;
    va_list args;
    cx_uint32 memRequired;
    cx_uint32 result = TRUE;

    if (data) {
        va_list argcpy;
        va_copy(argcpy, args);
        va_start(args, fmt);
        memRequired = vsnprintf(buff, 1024, fmt, args);
        if (memRequired >= 1024) {
            buff = cx_malloc(memRequired + 1);
            vsprintf(buff, fmt, argcpy);
        }
        va_end(args);
        result = cx_ser_appendstrbuff(data, buff);
        if (buff != alloc) {
            cx_dealloc(buff);
        }
    }

    return result;
}

static cx_int16 cx_ser_primitive(cx_serializer s, cx_value *info, void *userData) {
    CX_UNUSED(s);
    cx_type type;
    cx_void *value;
    cx_string valueString = NULL;
    cx_sqlite_ser_t *data = userData;
    cx_int16 result;

    type = cx_valueType(info);
    value = cx_valueValue(info);
    cx_primitiveKind kind = cx_primitive(type)->kind;

    if (!cx_ser_appendstr(data, "(\"ObjectId\", \"Value\") VALUES (")) {
        goto finished;
    }

    if (!cx_ser_appendstr(data, "NULL, ")) {
        goto finished;
    }

    result = cx_convert(cx_primitive(type), value, cx_primitive(cx_string_o), &valueString);
    if (result) {
        goto error;
    }

    if (kind == CX_CHARACTER || (kind == CX_TEXT && (*(cx_string *)value))) {
        size_t length;
        cx_string escapedValueString = cx_malloc((length = stresc(NULL, 0, valueString)) + 1);
        stresc(escapedValueString, length, valueString);
        cx_dealloc(valueString);
        valueString = escapedValueString;
    }

    switch (cx_primitive(type)->kind) {
        case CX_BINARY:
            if (!cx_ser_appendstr(data, "%s", "0")) {
                goto finished;
            }
            break;
        case CX_BITMASK:
            if (!cx_ser_appendstr(data, "%s", "0")) {
                goto finished;
            }
            break;
        case CX_ENUM:
            if (!cx_ser_appendstr(data, "%s", "0")) {
                goto finished;
            }
            break;
        case CX_CHARACTER:
        case CX_TEXT:
            if (!*(cx_string *)value) {
                if (!cx_ser_appendstr(data, "NULL")) {
                    goto finished;
                }
            } else {
                if (!cx_ser_appendstr(data, "'")) {
                    goto finished;
                }
                size_t length = escsqlstr(NULL, 0, valueString);
                char *escapedString = cx_malloc(length + 1);
                escsqlstr(escapedString, length, valueString);
                if (!cx_ser_appendstr(data, escapedString)) {
                    goto finished;
                }
                cx_dealloc(escapedString);
                if (!cx_ser_appendstr(data, "'")) {
                    goto finished;
                }
            }
            break;
        case CX_INTEGER:
        case CX_FLOAT:
        case CX_BOOLEAN:
        case CX_UINTEGER:
            if (!cx_ser_appendstr(data, valueString)) {
                goto finished;
            }
            break;
        case CX_ALIAS:
            cx_critical("Cannot serialize alias");
            break;
    }
    cx_dealloc(valueString);
    if (!cx_ser_appendstr(data, ")")) {
        goto finished;
    }
    return 0;
finished:
    cx_dealloc(valueString);
    return 1;
error:
    return -1;
}

static cx_int16 cx_ser_reference(cx_serializer s, cx_value *v, void *userData) {
    CX_UNUSED(s);
    CX_UNUSED(v);
    CX_UNUSED(userData);
    return 0;
}

static cx_int16 cx_ser_item(cx_serializer s, cx_value *v, void *userData) {
    CX_UNUSED(s);
    CX_UNUSED(v);
    CX_UNUSED(userData);
    return 0;
}

static cx_int16 cx_ser_composite(cx_serializer s, cx_value* v, void* userData) {
    cx_sqlite_ser_t data = *(cx_sqlite_ser_t*)userData;
    data.itemCount = 0;
    cx_type type = cx_valueType(v);

    if (type->kind == CX_COMPOSITE) {
        if (cx_serializeMembers(s, v, &data)) {
            goto error;
        }
    } else if (type->kind == CX_COLLECTION) {
        if (cx_serializeElements(s, v, &data)) {
            goto error;
        }
    } else {
        goto error;
    }
    ((cx_sqlite_ser_t*)userData)->buffer = data.buffer;
    ((cx_sqlite_ser_t*)userData)->ptr = data.ptr;
    return 0;
error:
    return -1;
}

static cx_int16 cx_ser_base(cx_serializer s, cx_value* v, void* userData) {
    CX_UNUSED(s);
    CX_UNUSED(v);
    CX_UNUSED(userData);
    return 0;
}

/*
 * It should be responsibility of the underlying value kind to add
 * "(column1, column2) VALUES (value1, value2)".
 */
static cx_int16 cx_ser_object(cx_serializer s, cx_value* v, void* userData) {
    cx_sqlite_ser_t *data = userData;
    cx_object *o = cx_valueObject(v);
    // TODO think about what to do with types... will we define types
    if (!cx_ser_appendstr(data, "INSERT INTO \"%s\"",
            cx_nameof(cx_valueType(v)))) {
        goto finished;
    }
    cx_serializeValue(s, v, data);
    if (!cx_ser_appendstr(data, ";")) {
        goto finished;
    }
    if (cx_instanceof(cx_typeof(cx_type_o), o)) {
        
    }
    return 0;
finished:
    return 1;
}

struct cx_serializer_s cx_sqlite_define_ser(cx_modifier access, cx_operatorKind accessKind, cx_serializerTraceKind trace) {
    struct cx_serializer_s s;
    cx_serializerInit(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = trace;
    s.program[CX_PRIMITIVE] = cx_ser_primitive;
    s.reference = cx_ser_reference;
    s.program[CX_COMPOSITE] = cx_ser_composite;
    // s.program[CX_COLLECTION] = cx_ser_complex;
    s.metaprogram[CX_ELEMENT] = cx_ser_item;
    s.metaprogram[CX_MEMBER] = cx_ser_item;
    s.metaprogram[CX_BASE] = cx_ser_base;
    s.metaprogram[CX_OBJECT] = cx_ser_object;
    return s;
}
