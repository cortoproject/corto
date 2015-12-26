/*
 * corto_string_ser.c
 *
 *  Created on: Aug 27, 2012
 *      Author: sander
 */

#include "corto/corto.h"

#ifdef CORTO_CONVERSIONS

#define BLACK   "\033[1;30m"
#define RED     "\033[1;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"
#define GREY    "\033[0;37m"
#define NORMAL  "\033[0;49m"
#define BOLD    "\033[1;49m"

#define STRING (RED)
#define REFERENCE (CYAN)
#define BOOLEAN (GREEN)
#define NUMBER (GREEN)
#define CONSTANT (MAGENTA)
#define MEMBER (NORMAL)

static corto_int16 corto_ser_object(corto_serializer s, corto_value* v, void* userData);

static corto_bool corto_ser_appendstrbuff(corto_string_ser_t* data, char* str) {
    if (!data->ptr) {
        data->ptr = data->buffer;
    }
    if (!data->ptr) {
        data->buffer = corto_strdup(str);
        data->ptr = data->buffer;
    } else {
        corto_uint32 length, bufferLength;

        if (!data->length) {
            data->buffer = corto_realloc(data->buffer, strlen(data->buffer) + strlen(str) + 1);
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
static corto_bool corto_ser_appendstr(corto_string_ser_t* data, corto_string fmt, ...) {
    char alloc[1024];
    char *buff = alloc;
    va_list args;
    corto_uint32 memRequired;
    corto_uint32 result = TRUE;

    if (data) {
        va_start(args, fmt);
        memRequired = vsnprintf(buff, 1024, fmt, args);
        if (memRequired >= 1024) {
            buff = corto_alloc(memRequired + 1);
            vsprintf(buff, fmt, args);
        }
        va_end(args);

        result = corto_ser_appendstrbuff(data, buff);
        if (buff != alloc) {
            corto_dealloc(buff);
        }
    }

    return result;
}

/* Insert color if enabled */
static corto_bool corto_ser_appendColor(corto_string_ser_t *data, corto_string color) {
    corto_bool result = TRUE;
    if (data->enableColors) {
        result = corto_ser_appendstr(data, color);
    }
    return result;
}

/* Serialize primitive values */
static corto_int16 corto_ser_primitive(corto_serializer s, corto_value* v, void* userData) {
    corto_string_ser_t* data;
    corto_type t;
    void* o;
    char* result;

    CORTO_UNUSED(s);
    result = NULL;

    data = (corto_string_ser_t*)userData;
    t = corto_valueType(v);
    o = corto_valueValue(v);

    /* If src is string and value is null, put NULL in result. */
    if (corto_primitive(t)->kind == CORTO_TEXT) {
        corto_ser_appendColor(data, STRING);
        if (*(corto_string*)o) {
            if (!corto_ser_appendstr(data, "\"%s\"", *(corto_string*)o)) {
                goto finished;
            }
        } else {
            if (!corto_ser_appendstr(data, "null")) {
                goto finished;
            }
        }
        corto_ser_appendColor(data, NORMAL);
    } else if (corto_primitive(t)->kind == CORTO_CHARACTER) {
        corto_ser_appendColor(data, STRING);
        if (*(corto_char*)o) {
            if (!corto_ser_appendstr(data, "'%c'", *(corto_char*)o)) {
                goto finished;
            }
        } else {
            if (!corto_ser_appendstr(data, "''")) {
                goto finished;
            }
        }
        corto_ser_appendColor(data, STRING);
    } else {
        switch(corto_primitive(t)->kind) {
            case CORTO_ENUM:
            case CORTO_BITMASK:
                corto_ser_appendColor(data, CONSTANT);
                break;
            case CORTO_BOOLEAN:
                corto_ser_appendColor(data, BOOLEAN);
                break;
            case CORTO_INTEGER:
            case CORTO_UINTEGER:
            case CORTO_FLOAT:
            case CORTO_BINARY:
                corto_ser_appendColor(data, NUMBER);
                break;
            default:
                break;
        }
        /* Convert primitive value to string */
        corto_convert(corto_primitive(t), o, corto_primitive(corto_string_o), &result);

        /* Append conversionresult to serializer-result*/
        if (!corto_ser_appendstr(data, "%s", result)) {
            corto_dealloc(result);
            goto finished;
        }
        corto_dealloc(result);
        corto_ser_appendColor(data, NORMAL);
    }

    return 0;
finished:
    return 1;
}

/* Serialize references */
static corto_int16 corto_ser_reference(corto_serializer s, corto_value* v, void* userData) {
    corto_id id;
    void *o;
    corto_object object;
    char* str;
    corto_string_ser_t* data;

    data = userData;
    o = corto_valueValue(v);
    object = *(corto_object*)o;

    /* Obtain fully scoped name */
    corto_ser_appendColor(data, REFERENCE);
    if (object) {
        if (corto_checkAttr(object, CORTO_ATTR_SCOPED) || (corto_valueObject(v) == object)) {
            if (corto_parentof(object) == corto_lang_o) {
                strcpy(id, corto_nameof(object));
                str = id;
            } else {
                str = (char*)corto_fullpath(id, object);
            }
        } else {
            corto_string_ser_t walkData;
            int index = 0;

            if (!data->anonymousObjects) {
                data->anonymousObjects = corto_llNew();
            }

            if ((index = corto_llHasObject(data->anonymousObjects, object))) {
                sprintf(id, "<%d>", index);
                str = id;
            } else {
                corto_value v;

                walkData.buffer = NULL;
                walkData.length = 0;
                walkData.maxlength = data->maxlength;
                walkData.compactNotation = data->compactNotation;
                walkData.ptr = NULL;
                walkData.prefixType = TRUE;
                walkData.anonymousObjects = data->anonymousObjects;
                walkData.enableColors = data->enableColors;

                corto_llAppend(data->anonymousObjects, object);
                corto_ser_appendstr(userData, "<%d>", corto_llSize(data->anonymousObjects));

                corto_valueObjectInit(&v, object, NULL);
                if (corto_ser_object(s, &v, &walkData)) {
                    goto error;
                }

                data->anonymousObjects = walkData.anonymousObjects;
                str = walkData.buffer;
            }
        }
    } else {
        str = "null";
    }

    /* Append name to serializer-result */
    if (!corto_ser_appendstrbuff(userData, str)) {
        goto finished;
    }
    corto_ser_appendColor(data, NORMAL);

    return 0;
error:
    return -1;
finished:
    return 1;
}

/* For composite and collection objects */
static corto_int16 corto_ser_scope(corto_serializer s, corto_value* v, void* userData) {
    corto_int16 result;
    corto_string_ser_t *data, privateData;
    corto_type t;

    data = userData;
    t = corto_valueType(v);
    result = 0;

    /* Nested data has private itemCount, which prevents superfluous ',' to be added to the result. */
    privateData = *data;
    privateData.itemCount = 0;

    /* Serialize composite members */
    if (!corto_ser_appendColor(&privateData, BOLD)) goto finished;
    if (!corto_ser_appendstr(&privateData, "{")) {
        goto finished;
    }
    if (!corto_ser_appendColor(&privateData, NORMAL)) goto finished;
    if (t->kind == CORTO_COMPOSITE) {
        result = corto_serializeMembers(s, v, &privateData);
    } else if (t->kind == CORTO_COLLECTION){
        result = corto_serializeElements(s, v, &privateData);
    } else {
        corto_assert(0, "corto_ser_scope: invalid typekind for function.");
    }
    if (!result) {
        if (!corto_ser_appendColor(&privateData, BOLD)) goto finished;
        if (!corto_ser_appendstr(&privateData, "}")) {
            goto finished;
        }
        if (!corto_ser_appendColor(&privateData, NORMAL)) goto finished;
    }

    *data = privateData;

    return result;
finished:
    return 1;
}

/* Serialize item (can be either member or element) */
static corto_int16 corto_ser_item(corto_serializer s, corto_value* v, void* userData) {
    corto_string_ser_t* data;
    CORTO_UNUSED(s);

    data = userData;

    /* Append ',' if this is not the first item */
    if (data->itemCount) {
        if (!data->compactNotation) {
            if (!corto_ser_appendstr(data, " ")) {
                goto finished;
            }
        } else {
            if (!corto_ser_appendstr(data, ",")) {
                goto finished;
            }
        }
    }

    if (!data->compactNotation) {
        if (v->kind == CORTO_MEMBER) {
            if (!corto_ser_appendColor(data, MEMBER)) goto finished;
            if (!corto_ser_appendstr(data, "%s", corto_nameof(v->is.member.t))) goto finished;
            if (!corto_ser_appendColor(data, BOLD)) goto finished;
            if (!corto_ser_appendstr(data, "=")) goto finished;
            if (!corto_ser_appendColor(data, NORMAL)) goto finished;
        }
    }

    /* Serialize value of item */
    if (corto_serializeValue(s, v, userData)) {
        goto error;
    }

    data->itemCount++;

    return 0;
error:
    return -1;
finished:
    return 1;
}

static corto_int16 corto_ser_object(corto_serializer s, corto_value* v, void* userData) {
    corto_string_ser_t* data;
    data = userData;

    corto_serializeValue(s, v, userData);

    if (data->prefixType) {
        corto_id id;
        corto_object o;
        corto_string result = NULL;

        o = corto_valueObject(v);
        if (corto_checkAttr(corto_typeof(o), CORTO_ATTR_SCOPED) && corto_parentof(corto_typeof(o)) == corto_lang_o) {
            strcpy(id, corto_nameof(corto_typeof(o)));
        } else {
            corto_fullpath(id, corto_typeof(o));
        }

        if (corto_typeof(o)->kind != CORTO_PRIMITIVE) {
            if (data->buffer) {
                result = corto_alloc(strlen(data->buffer) + strlen(id) + 1);
                sprintf(result, "%s%s", id, data->buffer);
            } else {
                result = corto_strdup(id);
            }
        } else {
            if (data->buffer) {
                result = corto_alloc(strlen(data->buffer) + strlen(id) + 2 + 1);
                sprintf(result, "%s{%s}", id, data->buffer);
            } else {
                corto_critical("failed to serialize value to string");
            }
        }

        if (!data->length) {
            corto_dealloc(data->buffer); /* Serializer manages memory of buffer */
            data->buffer = result;
        } else { /* Application  manages memory of buffer */
            strcpy(data->buffer, result);
            corto_dealloc(result);
        }
    }

    return 0;
}

static corto_int16 corto_ser_construct(corto_serializer s, corto_value *info, void* userData) {
    CORTO_UNUSED(s);
    CORTO_UNUSED(info);

    corto_string_ser_t* data = userData;
    data->ptr = data->buffer;
    data->itemCount = 0;
    data->anonymousObjects = NULL;
    if (data->buffer) {
        *(data->buffer) = '\0';
        if (!data->length) {
            corto_error("buffer set without a length in string serializer");
            goto error;
        }
    }
    return 0;
error:
    return -1;
}

corto_int16 corto_ser_destruct(corto_serializer s, void* userData) {
    CORTO_UNUSED(s);

    corto_string_ser_t* data = userData;
    if (data->anonymousObjects) {
        corto_llFree(data->anonymousObjects);
    }
    return 0;
}

struct corto_serializer_s corto_string_ser(corto_modifier access, corto_operatorKind accessKind, corto_serializerTraceKind trace) {
    struct corto_serializer_s s;

    corto_serializerInit(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = trace;
    s.construct = corto_ser_construct;
    s.destruct = corto_ser_destruct;
    s.program[CORTO_VOID] = NULL;
    s.program[CORTO_PRIMITIVE] = corto_ser_primitive;
    s.program[CORTO_COMPOSITE] = corto_ser_scope;
    s.program[CORTO_COLLECTION] = corto_ser_scope;

    s.metaprogram[CORTO_MEMBER] = corto_ser_item;
    s.metaprogram[CORTO_BASE] = corto_serializeMembers;   /* Skip the scope-callback by directly calling serializeMembers. This will cause the extra
                                                     * '{ }' not to appear, which is required by this string format. */
    s.metaprogram[CORTO_ELEMENT] = corto_ser_item;
    s.metaprogram[CORTO_OBJECT] = corto_ser_object;
    s.metaprogram[CORTO_CONSTANT] = NULL;
    s.reference = corto_ser_reference;
    return s;
}
#else
struct corto_serializer_s corto_string_ser(corto_modifier access, corto_operatorKind accessKind, corto_serializerTraceKind trace) {
    struct corto_serializer_s s;
    CORTO_UNUSED(access);
    CORTO_UNUSED(accessKind);
    CORTO_UNUSED(trace);
    corto_serializerInit(&s);
    return s;
}
#endif
