/*
 * cx_string_ser.c
 *
 *  Created on: Aug 27, 2012
 *      Author: sander
 */

#include "cx_string.h"
#include "cortex.h"
#include "stdarg.h"

#define BLACK  "\033[1;30m"
#define RED    "\033[1;31m"
#define GREEN  "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE   "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN   "\033[1;36m"
#define WHITE  "\033[1;37m"
#define GREY  "\033[0;37m"
#define NORMAL "\033[0;49m"
#define BOLD   "\033[1;30m"

#define STRING (RED)
#define REFERENCE (BLUE)
#define BOOLEAN (GREEN)
#define NUMBER (GREEN)
#define CONSTANT (MAGENTA)
#define MEMBER (BOLD)

static cx_int16 cx_ser_object(cx_serializer s, cx_value* v, void* userData);

static cx_bool cx_ser_appendstrbuff(cx_string_ser_t* data, char* str) {
    if (!data->ptr) {
        data->ptr = data->buffer;
    }
    if (!data->ptr) {
        data->buffer = cx_strdup(str);
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

/* Append string to serializer-result */
static cx_bool cx_ser_appendstr(cx_string_ser_t* data, cx_string fmt, ...) {
    char alloc[1024];
    char *buff = alloc;
    va_list args;
    cx_uint32 memRequired;
    cx_uint32 result = TRUE;

    if (data) {
        va_start(args, fmt);
        memRequired = vsnprintf(buff, 1024, fmt, args);
        if (memRequired >= 1024) {
            buff = cx_malloc(memRequired + 1);
            vsprintf(buff, fmt, args);
        }
        va_end(args);

        result = cx_ser_appendstrbuff(data, buff);
        if (buff != alloc) {
            cx_dealloc(buff);
        }
    }

    return result;
}

/* Escape string */
static cx_bool cx_ser_appendstrEscape(cx_string_ser_t *data, cx_string str) {
    cx_char buffer[1024];
    cx_char *ptr, *bptr, ch;

    ptr = str;
    bptr = buffer;
    *bptr = '"';
    bptr++;
    while((ch = *ptr)) {
        bptr = chresc(bptr, ch, '"');
        ptr++;

        if ((bptr - buffer) == 1023) { /* Avoid allocating temporary strings by reusing buffer.
                                       * Keep buffer sufficiently large to no call appendstr too much. */
            *bptr = '\0';
            if (!cx_ser_appendstr(data, "%s", buffer)) {
                goto finished;
            }
            bptr = buffer;
        }
    }
    *bptr = '"';
    *(++bptr) = '\0';

    return cx_ser_appendstr(data, "%s", buffer);
finished:
    return 1;
}

/* Insert color if enabled */
static cx_bool cx_ser_appendColor(cx_string_ser_t *data, cx_string color) {
    cx_bool result = TRUE;
    if (data->enableColors) {
        result = cx_ser_appendstr(data, color);
    }
    return result;
}

/* Serialize primitive values */
static cx_int16 cx_ser_primitive(cx_serializer s, cx_value* v, void* userData) {
    cx_string_ser_t* data;
    cx_type t;
    void* o;
    char* result;

    CX_UNUSED(s);
    result = NULL;

    data = (cx_string_ser_t*)userData;
    t = cx_valueType(v);
    o = cx_valueValue(v);

    /* If src is string and value is null, put NULL in result. */
    if (cx_primitive(t)->kind == CX_TEXT) {
        if (*(cx_string*)o) {
            cx_ser_appendColor(data, STRING);
            if (!cx_ser_appendstrEscape(data, *(cx_string*)o)) {
                goto finished;
            }
        } else {
            cx_ser_appendColor(data, BOOLEAN);
            if (!cx_ser_appendstr(data, "null")) {
                goto finished;
            }
        }
        cx_ser_appendColor(data, NORMAL);
    } else if (cx_primitive(t)->kind == CX_CHARACTER) {
        cx_ser_appendColor(data, STRING);
        if (*(cx_char*)o) {
            if (!cx_ser_appendstr(data, "'%c'", *(cx_char*)o)) {
                goto finished;
            }
        } else {
            if (!cx_ser_appendstr(data, "''")) {
                goto finished;
            }
        }
        cx_ser_appendColor(data, STRING);
    } else {
        switch(cx_primitive(t)->kind) {
            case CX_ENUM:
            case CX_BITMASK:
                cx_ser_appendColor(data, CONSTANT);
                break;
            case CX_BOOLEAN:
                cx_ser_appendColor(data, BOOLEAN);
                break;
            case CX_INTEGER:
            case CX_UINTEGER:
            case CX_FLOAT:
            case CX_BINARY:
                cx_ser_appendColor(data, NUMBER);
                break;
            default:
                break;
        }
        /* Convert primitive value to string */
        cx_convert(cx_primitive(t), o, cx_primitive(cx_string_o), &result);

        /* Append conversionresult to serializer-result*/
        if (!cx_ser_appendstr(data, "%s", result)) {
            cx_dealloc(result);
            goto finished;
        }
        cx_dealloc(result);
        cx_ser_appendColor(data, NORMAL);
    }

    return 0;
finished:
    return 1;
}

/* Serialize references */
static cx_int16 cx_ser_reference(cx_serializer s, cx_value* v, void* userData) {
    cx_id id;
    void *o;
    cx_object object;
    char* str;
    cx_string_ser_t* data;

    data = userData;
    o = cx_valueValue(v);
    object = *(cx_object*)o;

    /* Obtain fully scoped name */
    if (object) {
        cx_ser_appendColor(data, REFERENCE);
        if (cx_checkAttr(object, CX_ATTR_SCOPED) || (cx_valueObject(v) == object)) {
            if (cx_parentof(object) == cortex_lang_o) {
                strcpy(id, cx_nameof(object));
                str = id;
            } else {
                str = (char*)cx_fullname(object, id);
            }
        } else {
            cx_string_ser_t walkData;
            int index = 0;

            if (!data->anonymousObjects) {
                data->anonymousObjects = cx_llNew();
            }

            if ((index = cx_llHasObject(data->anonymousObjects, object))) {
                sprintf(id, "<%d>", index);
                str = id;
            } else {
                cx_value v;

                walkData.buffer = NULL;
                walkData.length = 0;
                walkData.maxlength = data->maxlength;
                walkData.compactNotation = data->compactNotation;
                walkData.ptr = NULL;
                walkData.prefixType = TRUE;
                walkData.anonymousObjects = data->anonymousObjects;

                cx_llAppend(data->anonymousObjects, object);
                cx_ser_appendstr(userData, "<%d>", cx_llSize(data->anonymousObjects));

                v.kind = CX_OBJECT;
                v.is.o = object;
                v.parent = NULL;
                if (cx_ser_object(s, &v, &walkData)) {
                    goto error;
                }

                data->anonymousObjects = walkData.anonymousObjects;
                str = walkData.buffer;
            }
        }
    } else {
        cx_ser_appendColor(data, BOOLEAN);
        str = "null";
    }

    /* Append name to serializer-result */
    if (!cx_ser_appendstrbuff(userData, str)) {
        goto finished;
    }
    cx_ser_appendColor(data, NORMAL);

    return 0;
error:
    return -1;
finished:
    return 1;
}

/* For composite and collection objects */
static cx_int16 cx_ser_scope(cx_serializer s, cx_value* v, void* userData) {
    cx_int16 result;
    cx_string_ser_t *data, privateData;
    cx_type t;

    data = userData;
    t = cx_valueType(v);
    result = 0;

    /* Nested data has private itemCount, which prevents superfluous ',' to be added to the result. */
    privateData = *data;
    privateData.itemCount = 0;

    /* Serialize composite members */
    if (!cx_ser_appendstr(&privateData, "{")) {
        goto finished;
    }
    if (t->kind == CX_COMPOSITE) {
        result = cx_serializeMembers(s, v, &privateData);
    } else if (t->kind == CX_COLLECTION){
        result = cx_serializeElements(s, v, &privateData);
    } else {
        cx_assert(0, "cx_ser_scope: invalid typekind for function.");
    }
    if (!result) {
        if (!cx_ser_appendstr(&privateData, "}")) {
            goto finished;
        }
    }

    *data = privateData;

    return result;
finished:
    return 1;
}

/* Serialize item (can be either member or element) */
static cx_int16 cx_ser_item(cx_serializer s, cx_value* v, void* userData) {
    cx_string_ser_t* data;
    CX_UNUSED(s);

    data = userData;

    /* Append ',' if this is not the first item */
    if (data->itemCount) {
        if (!cx_ser_appendstr(data, ",")) {
            goto finished;
        }
    }

    if (!data->compactNotation) {
        if (v->kind == CX_MEMBER) {
            if (!cx_ser_appendColor(data, MEMBER)) goto finished;
            if (!cx_ser_appendstr(data, "%s", cx_nameof(v->is.member.t))) goto finished;
            if (!cx_ser_appendColor(data, NORMAL)) goto finished;
            if (!cx_ser_appendstr(data, "=")) goto finished;
        }
    }

    /* Serialize value of item */
    if (cx_serializeValue(s, v, userData)) {
        goto error;
    }

    data->itemCount++;

    return 0;
error:
    return -1;
finished:
    return 1;
}

static cx_int16 cx_ser_object(cx_serializer s, cx_value* v, void* userData) {
    cx_string_ser_t* data;
    data = userData;

    cx_serializeValue(s, v, userData);

    if (data->prefixType) {
        cx_id id;
        cx_object o;
        cx_string result = NULL;

        o = cx_valueObject(v);
        if (cx_checkAttr(cx_typeof(o), CX_ATTR_SCOPED) && cx_parentof(cx_typeof(o)) == cortex_lang_o) {
            strcpy(id, cx_nameof(cx_typeof(o)));
        } else {
            cx_fullname(cx_typeof(o), id);
        }

        if (cx_typeof(o)->kind != CX_PRIMITIVE) {
            if (data->buffer) {
                result = cx_malloc(strlen(data->buffer) + strlen(id) + 1);
                sprintf(result, "%s%s", id, data->buffer);
            } else {
                result = cx_strdup(id);
            }
        } else {
            if (data->buffer) {
                result = cx_malloc(strlen(data->buffer) + strlen(id) + 2 + 1);
                sprintf(result, "%s{%s}", id, data->buffer);
            } else {
                cx_critical("failed to serialize value to string");
            }
        }

        if (!data->length) {
            cx_dealloc(data->buffer); /* Serializer manages memory of buffer */
            data->buffer = result;
        } else { /* Application  manages memory of buffer */
            strcpy(data->buffer, result);
            cx_dealloc(result);
        }
    }

    return 0;
}

static cx_int16 cx_ser_construct(cx_serializer s, cx_value *info, void* userData) {
    CX_UNUSED(s);
    CX_UNUSED(info);
    
    cx_string_ser_t* data = userData;
    data->ptr = data->buffer;
    data->itemCount = 0;
    data->anonymousObjects = NULL;
    if (data->buffer) {
        *(data->buffer) = '\0';
        if (!data->length) {
            cx_error("buffer set without a length in string serializer");
            goto error;
        }
    }
    return 0;
error:
    return -1;
}

cx_int16 cx_ser_destruct(cx_serializer s, void* userData) {
    CX_UNUSED(s);
    
    cx_string_ser_t* data = userData;
    if (data->anonymousObjects) {
        cx_llFree(data->anonymousObjects);
    }
    return 0;
}

struct cx_serializer_s cx_string_ser(cx_modifier access, cx_operatorKind accessKind, cx_serializerTraceKind trace) {
    struct cx_serializer_s s;

    cx_serializerInit(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = trace;
    s.construct = cx_ser_construct;
    s.destruct = cx_ser_destruct;
    s.program[CX_VOID] = NULL;
    s.program[CX_PRIMITIVE] = cx_ser_primitive;
    s.program[CX_COMPOSITE] = cx_ser_scope;
    s.program[CX_COLLECTION] = cx_ser_scope;
    
    s.metaprogram[CX_MEMBER] = cx_ser_item;
    s.metaprogram[CX_BASE] = cx_serializeMembers;   /* Skip the scope-callback by directly calling serializeMembers. This will cause the extra
                                                     * '{ }' not to appear, which is required by this string format. */
    s.metaprogram[CX_ELEMENT] = cx_ser_item;
    s.metaprogram[CX_OBJECT] = cx_ser_object;
    s.metaprogram[CX_CONSTANT] = NULL;
    s.reference = cx_ser_reference;
    return s;
}
