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

static cx_int16 cx_ser_reference(cx_serializer s, cx_value *v, void *userData) {
    CX_UNUSED(s);
    CX_UNUSED(v);
    CX_UNUSED(userData);
    return 0;
}

static cx_int16 cx_ser_item(cx_serializer s, cx_value *v, void *userData) {
    CX_UNUSED(s);
    cx_type type = cx_valueType(v);
    cx_sqlite_ser_t *data = userData;
    if (data->itemCount) {
        if (!cx_ser_appendstr(data, ", ")) {
            goto finished;
        }
    }
    cx_string memberName = cx_nameof(v->is.member.t);
    switch (type->kind) {
        case CX_PRIMITIVE:
            switch (cx_primitive(type)->kind) {
                case CX_CHARACTER:
                case CX_TEXT:
                    if (!cx_ser_appendstr(data, "\"%s\" TEXT", memberName)) {
                        goto finished;
                    }
                    break;
                case CX_BINARY:
                case CX_BITMASK:
                case CX_BOOLEAN:
                case CX_INTEGER:
                case CX_UINTEGER:
                    if (!cx_ser_appendstr(data, "\"%s\" INTEGER", memberName)) {
                        goto finished;
                    }
                    break;
                case CX_FLOAT:
                    if (!cx_ser_appendstr(data, "\"%s\" REAL", memberName)) {
                        goto finished;
                    }
                    break;
                case CX_ENUM:
                    if (!cx_ser_appendstr(data, "\"%s\" INTEGER REFERENCES \"%sConstant\"",
                            memberName, memberName)) {
                        goto finished;
                    }
                    break;
                case CX_ALIAS:
                    cx_critical("CX_ALIAS not supported");
                    break;
            }
            break;
        case CX_COMPOSITE:
            cx_serializeValue(s, v, userData);
            break;
        case CX_COLLECTION:
            break;
        case CX_VOID:
            break;
        case CX_ITERATOR:
            cx_warning("CX_ITERATOR not serializable");
            break;
        case CX_ANY:
            cx_critical("CX_ANY not serializable");
            break;
    }
    data->itemCount++;
    return 0;
finished:
    return 1;
}



static cx_int16 cx_ser_object(cx_serializer s, cx_value* v, void* userData) {
    cx_sqlite_ser_t *data = userData;
    cx_type type = cx_valueType(v);
    // TODO put fully scoped name with underscores
    if (!cx_ser_appendstr(data, "CREATE TABLE IF NOT EXISTS \"%s\" (",
            cx_nameof(cx_valueType(v)))) {
        goto finished;
    }
    switch (type->kind) {
        case CX_PRIMITIVE:
            switch (cx_primitive(type)->kind) {
                case CX_ENUM:
                    if (!cx_ser_appendstr(data, "\"Value\" INTEGER")) {
                        goto finished;
                    }
                    break;
                case CX_BITMASK:
                    if (!cx_ser_appendstr(data, "\"Value\" INTEGER")) {
                        goto finished;
                    }
                    break;
                default:
                    break;
            }
            break;
        case CX_COMPOSITE:
            cx_serializeValue(s, v, data);
            break;
        case CX_COLLECTION:
            cx_warning("collection serialization not yet supported");
            break;
        case CX_VOID:
            break;
        case CX_ANY:
            break;
        case CX_ITERATOR:
            cx_critical("CX_ITERATOR not serializable");
            break;
    }
    if (!cx_ser_appendstr(data, ");")) {
        goto finished;
    }
    return 0;
finished:
    return 1;
}

struct cx_serializer_s cx_type_ser(cx_modifier access, cx_operatorKind accessKind, cx_serializerTraceKind trace) {
    struct cx_serializer_s s;
    cx_serializerInit(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = trace;
    s.reference = cx_ser_reference;
    s.metaprogram[CX_ELEMENT] = cx_ser_item;
 
    s.metaprogram[CX_MEMBER] = cx_ser_item;
    // s.metaprogram[CX_BASE] = cx_ser_base;
    s.metaprogram[CX_OBJECT] = cx_ser_object;
    return s;
}
