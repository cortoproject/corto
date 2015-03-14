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

static cx_int16 cx_ser_object(cx_serializer s, cx_value* v, void* userData) {
    CX_UNUSED(s);
    cx_object *o = cx_valueObject(v);
    cx_sqlite_ser_t *data = userData;
    // cx_string name = cx_nameof(o);
    int parentId = 0; /* todo obtain parent id */
    cx_string parentIdStr;
    {
        if (parentId != 0) {
            size_t length;
            length = snprintf(NULL, 0, "%d", parentId);
            if (length < 1) {
                goto error;
            }
            parentIdStr = cx_malloc(length + 1);
            sprintf(parentIdStr, "%d", parentId);
        } else {
            parentIdStr = cx_malloc(sizeof("NULL"));
            strcpy(parentIdStr, "NULL");
        }
    }
    if (!cx_ser_appendstr(data,
            "INSERT INTO \"Objects\" (\"Name\", \"Parent\") "
            "VALUES ('%s', %s);",
            cx_nameof(o),
            parentIdStr
        )) {
        goto finished;
    }
    return 0;
error:
    return -1;
finished:
    return 1;
}

struct cx_serializer_s cx_sqlite_declare_ser(cx_modifier access, cx_operatorKind accessKind, cx_serializerTraceKind trace) {
    struct cx_serializer_s s;
    cx_serializerInit(&s);
    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = trace;
    s.metaprogram[CX_OBJECT] = cx_ser_object;
    return s;
}
