
#include <inttypes.h>
#include <stdio.h>
#include <string.h>

#include "cx_serializer.h"
#include "cx_string.h"
#include "cortex.h"
#include "json.h"
#include "json_primitives.h"

/* agreed not to change anything except the first argument of the signature */
static cx_bool cx_ser_appendstrbuff(cx_json_ser_t* data, char* str) {
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

/* agreed not to change anything except the first argument of the signature */
/* Append string to serializer-result */
static cx_bool cx_ser_appendstr(cx_json_ser_t* data, cx_string fmt, ...) {
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
            buff = cx_alloc(memRequired + 1);
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

static cx_int16 serializePrimitive(cx_serializer s, cx_value *v, void *userData) {
    CX_UNUSED(s);
    cx_type type = cx_valueType(v);
    cx_json_ser_t *data = userData;
    cx_int16 result;
    cx_string valueString;

    switch (cx_primitive(type)->kind) {
        case CX_BINARY:
            result = serializeBinary(v, &valueString);
            break;
        case CX_BITMASK:
            result = serializeBitmask(v, &valueString);
            break;
        case CX_BOOLEAN:
            result = serializeBoolean(v, &valueString);
            break;
        case CX_ENUM:
            result = serializeEnum(v, &valueString);
            break;
        case CX_CHARACTER:
        case CX_TEXT:
            result = serializeText(v, &valueString);
            break;
        case CX_UINTEGER:
        case CX_INTEGER:
        case CX_FLOAT:
            result = serializeNumber(v, &valueString);
            break;
        case CX_ALIAS:
            result = serializeAlias(v, &valueString);
            break;
    }
    if (result) {
        goto error;
    }
    if (!cx_ser_appendstr(data, "%s", valueString)) {
        goto finished;
    }
    cx_dealloc(valueString);
    return 0;
finished:
    cx_dealloc(valueString);
    return 1;
error:
    return -1;
}

static cx_int16 serializeReference(cx_serializer s, cx_value *v, void *userData) {
    CX_UNUSED(s);

    cx_json_ser_t *data;
    void *o;
    cx_object object;
    cx_id id;

    data = userData;
    o = cx_valueValue(v);
    object = *(cx_object*)o;

    if (object) {
        if (cx_checkAttr(object, CX_ATTR_SCOPED) || (cx_valueObject(v) == object)) {
            cx_uint32 length;
            cx_fullname(object, id);

            /* Escape value */
            cx_string escapedValue = cx_alloc((length = stresc(NULL, 0, id)) + 1);
            stresc(escapedValue, length + 1, id);
            if (!cx_ser_appendstr(data, "\"@R %s\"", escapedValue)) {
                cx_dealloc(escapedValue);
                goto finished;
            }
            cx_dealloc(escapedValue);
        } else {
            cx_ser_appendstr(data, "\"anonymous\"");
        }
    } else {
        if (!cx_ser_appendstrbuff(data, "null")) {
            goto finished;
        }
    }
    return 0;
finished:
    return 1;
}

static cx_int16 serializeItem(cx_serializer s, cx_value *info, void *userData) {
    cx_json_ser_t *data = userData;

    if (data->itemCount && !cx_ser_appendstr(data, ",")) {
        goto finished;
    }
    if (info->kind == CX_MEMBER) {
        cx_member member = info->is.member.t;
        cx_string name = cx_nameof(member);
        if (!cx_ser_appendstr(data, "\"%s\":", name)) {
            goto finished;
        }
    }
    if (cx_serializeValue(s, info, userData)) {
        goto error;
    }

    data->itemCount += 1;

    return 0;
error:
    return -1;
finished:
    return 1;
}

static cx_int16 serializeComplex(cx_serializer s, cx_value* v, void* userData) {
    cx_json_ser_t data = *(cx_json_ser_t*)userData;
    cx_type type = cx_valueType(v);
    cx_bool useCurlyBraces = TRUE;

    data.itemCount = 0;

    if (type->kind == CX_COLLECTION && cx_collection(type)->kind != CX_MAP) {
        useCurlyBraces = FALSE;
    }

    if (!cx_ser_appendstr(&data, (useCurlyBraces ? "{" : "["))) {
        goto finished;
    }
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

    if (!cx_ser_appendstr(&data, (useCurlyBraces ? "}" : "]"))) {
        goto finished;
    }

    ((cx_json_ser_t*)userData)->buffer = data.buffer;
    ((cx_json_ser_t*)userData)->ptr = data.ptr;

    return 0;
error:
    return -1;
finished:
    return 1;
}

static cx_int16 serializeBase(cx_serializer s, cx_value* v, void* userData) {
    cx_json_ser_t *data = userData;
    cx_id id;
    if (!cx_ser_appendstr(data, "\"@%s\":", cx_fullname(cx_valueType(v), id))) {
        goto finished;
    }
    if (cx_serializeValue(s, v, userData)) {
        goto error;
    }
    data->itemCount += 1;
    return 0;
error:
    return -1;
finished:
    return 1;
}

/* TODO this is copy-past from dbsh.c */
static char* dbsh_stateStr(cx_object o, char* buff) {
    buff[0] = '\0';

    /* Get state */
    if (cx_checkState(o, CX_VALID)) {
       strcpy(buff, "V");
    }
    if (cx_checkState(o, CX_DECLARED)) {
       strcat(buff, "|DCL");
    }
    if (cx_checkState(o, CX_DEFINED)) {
       strcat(buff, "|DEF");
    }

    return buff;
}

/* TODO this is copy-paste from dbsh.c */
static char* dbsh_attrStr(cx_object o, char* buff) {
    cx_bool first;
    *buff = '\0';

    first = TRUE;
    if (cx_checkAttr(o, CX_ATTR_SCOPED)) {
        strcat(buff, "S");
        first = FALSE;
    }
    if (cx_checkAttr(o, CX_ATTR_WRITABLE)) {
        if (!first) {
            strcat(buff, "|W");
        } else {
            strcat(buff, "W");
            first = FALSE;
        }
    }
    if (cx_checkAttr(o, CX_ATTR_OBSERVABLE)) {
        if (!first) {
            strcat(buff, "|O");
        } else {
            strcat(buff, "O");
            first = FALSE;
        }
    }
    if (cx_checkAttr(o, CX_ATTR_PERSISTENT)) {
        if (!first) {
            strcat(buff, "|P");
        } else {
            strcat(buff, "P");
        }
    }
    return buff;
}

static int cx_appendStringAttr(cx_string key, cx_string value, void* userData) {
    size_t length;

    /* Escape value */
    cx_string escapedValue = cx_alloc((length = stresc(NULL, 0, value)) + 1);
    stresc(escapedValue, length + 1, value);

    if (!cx_ser_appendstr(userData, "\"%s\":\"%s\",", key, escapedValue)) {
        goto finished;
    }

    cx_dealloc(escapedValue);
    return 1;
finished:
    cx_dealloc(escapedValue);
    return 0;
}

static cx_int16 serializeMeta(cx_serializer s, cx_value* v, void* userData) {
    CX_UNUSED(s);
    cx_json_ser_t *data = userData;
    cx_object o = cx_valueValue(v);

    if (!data->serializeMeta) {
        goto error;
    }

    if (!cx_ser_appendstr(userData, "{")) {
        goto finished;
    }

    cx_string name = cx_nameof(o);
    if (name) {
        if (!cx_appendStringAttr("name", name, userData)) {
            goto finished;
        }
    } else {
        if (!cx_ser_appendstr(userData, "\"name\":\"%s\",", CX_JSON_ROOT_NAME)) {
            goto finished;
        }
    }

    cx_id type_fullname;
    cx_fullname(cx_typeof(o), type_fullname);
    if (!cx_appendStringAttr("type", type_fullname, userData)) {
        goto finished;
    }

    if (cx_checkAttr(o, CX_ATTR_PERSISTENT)) {
        cx_time t = cx_timestampof(o);
        if (!cx_ser_appendstr(data, "\"timestamp\":\"%d.%.9d\",", t.tv_sec, t.tv_nsec)) {
            goto finished;
        }
    }

    char states[sizeof("V|DCL|DEF")];
    dbsh_stateStr(o, states);
    if (!cx_ser_appendstr(data, "\"states\":\"%s\",", states)) {
        goto finished;
    }

    char attributes[sizeof("S|W|O|P")];
    dbsh_attrStr(o, attributes);
    if (!cx_ser_appendstr(data, "\"attributes\":\"%s\",", attributes)) {
        goto finished;
    }

    cx_id parent_fullname;
    cx_fullname(cx_parentof(o), parent_fullname);
    if (!cx_ser_appendstr(data, "\"parent\":\"%s\",", parent_fullname)) {
        goto finished;
    }

    cx_uint32 scopeSize = cx_scopeSize(o);
    if (!cx_ser_appendstr(data, "\"childCount\":%"PRId32"", scopeSize)) {
        goto finished;
    }

    if (!cx_ser_appendstr(data, "}")) {
        goto finished;
    }

    return 0;
error:
    return -1;
finished:
    return 1;
}

static int serializeMetaWalkScopeAction(cx_object o, void* userData) {
    if (!cx_ser_appendstr(userData, "{")) {
        goto finished;
    }

    cx_string name = cx_nameof(o);
    if (name) {
        if (!cx_appendStringAttr("name", name, userData)) {
            goto finished;
        }
    } else {
        if (!cx_ser_appendstr(userData, "\"name\":\"::\",")) {
            goto finished;
        }
    }

    cx_id type_fullname;
    cx_fullname(cx_typeof(o), type_fullname);
    if (!cx_appendStringAttr("type", type_fullname, userData)) {
        goto finished;
    }

    char states[sizeof("V|DCL|DEF")];
    dbsh_stateStr(o, states);
    if (!cx_appendStringAttr("states", states, userData)) {
        goto finished;
    }

    char attributes[sizeof("S|W|O|P")];
    dbsh_attrStr(o, attributes);
    if (!cx_ser_appendstr(userData, "\"attributes\":\"%s\",", attributes)) {
        goto finished;
    }

    cx_uint32 scopeSize = cx_scopeSize(o);
    if (!cx_ser_appendstr(userData, "\"childCount\":%"PRId32"", scopeSize)) {
        goto finished;
    }

    if (!cx_ser_appendstr(userData, "},")) {
        goto finished;
    }

    return 1;
finished:
    return 0;
}

static cx_int16 serializeScopeMeta(cx_serializer s, cx_value* v, void* userData) {
    CX_UNUSED(s); /* should we receive s for scalability or should we dismiss it? */
    int last;
    size_t sizeBefore, sizeAfter;
    cx_json_ser_t *data = userData;
    sizeBefore = strlen(data->buffer);
    cx_object object = cx_valueValue(v);
    last = cx_scopeWalk(object, serializeMetaWalkScopeAction, userData);
    sizeAfter = strlen(data->buffer);
    if (sizeAfter && sizeBefore < sizeAfter) {
        data->buffer[sizeAfter - 1] = '\0';
    }
    return last;
}



static cx_int16 serializeObject(cx_serializer s, cx_value* v, void* userData) {
    cx_json_ser_t *data = userData;
    cx_uint8 c = 0;
    cx_uint32 options = data->serializeMeta + data->serializeValue + data->serializeScope;

    /* If more than one option is provided, prefix with
     * 'meta', 'value' and 'scope' */

    if (data->alwaysIncludeHeaders || (options > 1)) {
        if (!cx_ser_appendstr(data, "{")) {
            goto finished;
        }
    }

    if (data->serializeMeta) {
        if (data->alwaysIncludeHeaders || (options > 1)) {
            if (!cx_ser_appendstr(data, "\"meta\":")) {
                goto finished;
            }
        }
        if (serializeMeta(s, v, userData)) {
            goto error;
        }
        c += 1;
    }

    if (data->serializeValue) {
        if (cx_valueType(v)->kind != CX_VOID) {
            if (data->alwaysIncludeHeaders || (options > 1)) {
                if (c && !cx_ser_appendstr(data, ",")) {
                    goto finished;
                }
                if (!cx_ser_appendstr(data, "\"value\":")) {
                    goto finished;
                }
            }
            if (cx_serializeValue(s, v, userData)) {
                goto error;
            }
            c += 1;
         }
    }

    if (data->serializeScope) {
        if (data->alwaysIncludeHeaders || (options > 1)) {
            if (c && !cx_ser_appendstr(data, ",")) {
                goto finished;
            }
            if (!cx_ser_appendstr(data, "\"scope\":")) {
                goto finished;
            }
        }
        if (!cx_ser_appendstr(data, "[")) {
            goto finished;
        }
        if (!serializeScopeMeta(s, v, data)) {
            goto error;
        }
        if (!cx_ser_appendstr(data, "]")) {
            goto finished;
        }
    }

    if (data->alwaysIncludeHeaders || (options > 1)) {
        if (!cx_ser_appendstr(data, "}")) {
            goto finished;
        }
    }

    return 0;
error:
    return -1;
finished:
    return 1;
}

struct cx_serializer_s cx_json_ser(cx_modifier access, cx_operatorKind accessKind, cx_serializerTraceKind trace) {
    struct cx_serializer_s s;

    cx_serializerInit(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = trace;
    s.program[CX_PRIMITIVE] = serializePrimitive;
    s.reference = serializeReference;
    s.program[CX_COMPOSITE] = serializeComplex;
    s.program[CX_COLLECTION] = serializeComplex;
    s.metaprogram[CX_ELEMENT] = serializeItem;
    s.metaprogram[CX_MEMBER] = serializeItem;
    s.metaprogram[CX_BASE] = serializeBase;
    s.metaprogram[CX_OBJECT] = serializeObject;
    return s;
}
