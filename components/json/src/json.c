
#include <inttypes.h>
#include <stdio.h>
#include <string.h>

#include "corto_serializer.h"
#include "corto_string.h"
#include "corto.h"
#include "json.h"
#include "json_primitives.h"

/* agreed not to change anything except the first argument of the signature */
static corto_bool corto_ser_appendstrbuff(corto_json_ser_t* data, char* str) {
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

/* agreed not to change anything except the first argument of the signature */
/* Append string to serializer-result */
static corto_bool corto_ser_appendstr(corto_json_ser_t* data, corto_string fmt, ...) {
    char alloc[1024];
    char *buff = alloc;
    va_list args;
    corto_uint32 memRequired;
    corto_uint32 result = TRUE;

    if (data) {
        va_list argcpy;
        va_copy(argcpy, args);
        va_start(args, fmt);
        memRequired = vsnprintf(buff, 1024, fmt, args);
        if (memRequired >= 1024) {
            buff = corto_alloc(memRequired + 1);
            vsprintf(buff, fmt, argcpy);
        }
        va_end(args);
        result = corto_ser_appendstrbuff(data, buff);
        if (buff != alloc) {
            corto_dealloc(buff);
        }
    }

    return result;
}

static corto_int16 serializePrimitive(corto_serializer s, corto_value *v, void *userData) {
    CORTO_UNUSED(s);
    corto_type type = corto_valueType(v);
    corto_json_ser_t *data = userData;
    corto_int16 result = 0;
    corto_string valueString;

    switch (corto_primitive(type)->kind) {
        case CORTO_BINARY:
            result = serializeBinary(v, &valueString, data);
            break;
        case CORTO_BITMASK:
            result = serializeBitmask(v, &valueString, data);
            break;
        case CORTO_BOOLEAN:
            result = serializeBoolean(v, &valueString, data);
            break;
        case CORTO_ENUM:
            result = serializeEnum(v, &valueString, data);
            break;
        case CORTO_CHARACTER:
        case CORTO_TEXT:
            result = serializeText(v, &valueString, data);
            break;
        case CORTO_UINTEGER:
        case CORTO_INTEGER:
        case CORTO_FLOAT:
            result = serializeNumber(v, &valueString, data);
            break;
    }
    if (result) {
        goto error;
    }
    if (!corto_ser_appendstr(data, "%s", valueString)) {
        goto finished;
    }
    corto_dealloc(valueString);
    return 0;
finished:
    corto_dealloc(valueString);
    return 1;
error:
    return -1;
}

static corto_int16 serializeReference(corto_serializer s, corto_value *v, void *userData) {
    CORTO_UNUSED(s);

    corto_json_ser_t *data;
    void *o;
    corto_object object;
    corto_id id;

    data = userData;
    o = corto_valueValue(v);
    object = *(corto_object*)o;

    if (object) {
        if (corto_checkAttr(object, CORTO_ATTR_SCOPED) || (corto_valueObject(v) == object)) {
            corto_uint32 length;
            corto_fullname(object, id);

            /* Escape value */
            corto_string escapedValue = corto_alloc((length = stresc(NULL, 0, id)) + 1);
            stresc(escapedValue, length + 1, id);
            if (data->serializePrefix) {
                if (!corto_ser_appendstr(data, "\"@R %s\"", escapedValue)) {
                    corto_dealloc(escapedValue);
                    goto finished;
                }
            } else {
                if (!corto_ser_appendstr(data, "\"%s\"", escapedValue)) {
                    corto_dealloc(escapedValue);
                    goto finished;
                }                
            }

            corto_dealloc(escapedValue);
        } else {
            if (corto_serialize(s, object, data)) {
                goto error;
            }
        }
    } else {
        if (!corto_ser_appendstrbuff(data, "null")) {
            goto finished;
        }
    }
    return 0;
finished:
    return 1;
error:
    return -1;
}

static corto_int16 serializeItem(corto_serializer s, corto_value *info, void *userData) {
    corto_json_ser_t *data = userData;

    if (data->itemCount && !corto_ser_appendstr(data, ",")) {
        goto finished;
    }
    if (info->kind == CORTO_MEMBER) {
        corto_member member = info->is.member.t;
        corto_string name = corto_nameof(member);
        if (!corto_ser_appendstr(data, "\"%s\":", name)) {
            goto finished;
        }
    }
    if (corto_serializeValue(s, info, userData)) {
        goto error;
    }

    data->itemCount += 1;

    return 0;
error:
    return -1;
finished:
    return 1;
}

static corto_int16 serializeComplex(corto_serializer s, corto_value* v, void* userData) {
    corto_json_ser_t data = *(corto_json_ser_t*)userData;
    corto_type type = corto_valueType(v);
    corto_bool useCurlyBraces = TRUE;

    data.itemCount = 0;

    if (type->kind == CORTO_COLLECTION && corto_collection(type)->kind != CORTO_MAP) {
        useCurlyBraces = FALSE;
    }

    if (!corto_ser_appendstr(&data, (useCurlyBraces ? "{" : "["))) {
        goto finished;
    }
    if (type->kind == CORTO_COMPOSITE) {
        if (corto_serializeMembers(s, v, &data)) {
            goto error;
        }
    } else if (type->kind == CORTO_COLLECTION) {
        if (corto_serializeElements(s, v, &data)) {
            goto error;
        }
    } else {
        goto error;
    }

    if (!corto_ser_appendstr(&data, (useCurlyBraces ? "}" : "]"))) {
        goto finished;
    }

    ((corto_json_ser_t*)userData)->buffer = data.buffer;
    ((corto_json_ser_t*)userData)->ptr = data.ptr;

    return 0;
error:
    return -1;
finished:
    return 1;
}

static corto_int16 serializeBase(corto_serializer s, corto_value* v, void* userData) {
    corto_json_ser_t *data = userData;
    corto_id id;

    if (data->serializePrefix) {
        if (!corto_ser_appendstr(data, "\"@%s\":", corto_fullname(corto_valueType(v), id))) {
            goto finished;
        }
    }
    if (corto_serializeValue(s, v, userData)) {
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
static char* dbsh_stateStr(corto_object o, char* buff) {
    buff[0] = '\0';

    /* Get state */
    if (corto_checkState(o, CORTO_VALID)) {
       strcpy(buff, "V");
    }
    if (corto_checkState(o, CORTO_DECLARED)) {
       strcat(buff, "|DCL");
    }
    if (corto_checkState(o, CORTO_DEFINED)) {
       strcat(buff, "|DEF");
    }

    return buff;
}

/* TODO this is copy-paste from dbsh.c */
static char* dbsh_attrStr(corto_object o, char* buff) {
    corto_bool first;
    *buff = '\0';

    first = TRUE;
    if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
        strcat(buff, "S");
        first = FALSE;
    }
    if (corto_checkAttr(o, CORTO_ATTR_WRITABLE)) {
        if (!first) {
            strcat(buff, "|W");
        } else {
            strcat(buff, "W");
            first = FALSE;
        }
    }
    if (corto_checkAttr(o, CORTO_ATTR_OBSERVABLE)) {
        if (!first) {
            strcat(buff, "|O");
        } else {
            strcat(buff, "O");
            first = FALSE;
        }
    }
    if (corto_checkAttr(o, CORTO_ATTR_PERSISTENT)) {
        if (!first) {
            strcat(buff, "|P");
        } else {
            strcat(buff, "P");
        }
    }
    return buff;
}

static int corto_appendStringAttr(corto_string key, corto_string value, void* userData) {
    size_t length;

    /* Escape value */
    corto_string escapedValue = corto_alloc((length = stresc(NULL, 0, value)) + 1);
    stresc(escapedValue, length + 1, value);

    if (!corto_ser_appendstr(userData, "\"%s\":\"%s\",", key, escapedValue)) {
        goto finished;
    }

    corto_dealloc(escapedValue);
    return 1;
finished:
    corto_dealloc(escapedValue);
    return 0;
}

static corto_int16 serializeMeta(corto_serializer s, corto_value* v, void* userData) {
    CORTO_UNUSED(s);
    corto_json_ser_t *data = userData;
    corto_object o = corto_valueValue(v);

    if (!data->serializeMeta) {
        goto error;
    }

    if (!corto_ser_appendstr(userData, "{")) {
        goto finished;
    }

    corto_string name = corto_nameof(o);
    if (name) {
        if (!corto_appendStringAttr("name", name, userData)) {
            goto finished;
        }
    } else {
        if (!corto_ser_appendstr(userData, "\"name\":\"%s\",", CORTO_JSON_ROOT_NAME)) {
            goto finished;
        }
    }

    corto_id type_fullname;
    corto_fullname(corto_typeof(o), type_fullname);
    if (!corto_appendStringAttr("type", type_fullname, userData)) {
        goto finished;
    }

    if (corto_checkAttr(o, CORTO_ATTR_PERSISTENT)) {
        corto_time t = corto_timestampof(o);
        if (!corto_ser_appendstr(data, "\"timestamp\":\"%d.%.9d\",", t.tv_sec, t.tv_nsec)) {
            goto finished;
        }
    }

    char states[sizeof("V|DCL|DEF")];
    dbsh_stateStr(o, states);
    if (!corto_ser_appendstr(data, "\"states\":\"%s\",", states)) {
        goto finished;
    }

    char attributes[sizeof("S|W|O|P")];
    dbsh_attrStr(o, attributes);
    if (!corto_ser_appendstr(data, "\"attributes\":\"%s\",", attributes)) {
        goto finished;
    }

    corto_id parent_fullname;
    corto_fullname(corto_parentof(o), parent_fullname);
    if (!corto_ser_appendstr(data, "\"parent\":\"%s\",", parent_fullname)) {
        goto finished;
    }

    corto_uint32 scopeSize = corto_scopeSize(o);
    if (!corto_ser_appendstr(data, "\"childCount\":%"PRId32"", scopeSize)) {
        goto finished;
    }

    if (!corto_ser_appendstr(data, "}")) {
        goto finished;
    }

    return 0;
error:
    return -1;
finished:
    return 1;
}

static int serializeMetaWalkScopeAction(corto_object o, void* userData) {
    if (!corto_ser_appendstr(userData, "{")) {
        goto finished;
    }

    corto_string name = corto_nameof(o);
    if (name) {
        if (!corto_appendStringAttr("name", name, userData)) {
            goto finished;
        }
    } else {
        if (!corto_ser_appendstr(userData, "\"name\":\"::\",")) {
            goto finished;
        }
    }

    corto_id type_fullname;
    corto_fullname(corto_typeof(o), type_fullname);
    if (!corto_appendStringAttr("type", type_fullname, userData)) {
        goto finished;
    }

    char states[sizeof("V|DCL|DEF")];
    dbsh_stateStr(o, states);
    if (!corto_appendStringAttr("states", states, userData)) {
        goto finished;
    }

    char attributes[sizeof("S|W|O|P")];
    dbsh_attrStr(o, attributes);
    if (!corto_ser_appendstr(userData, "\"attributes\":\"%s\",", attributes)) {
        goto finished;
    }

    corto_uint32 scopeSize = corto_scopeSize(o);
    if (!corto_ser_appendstr(userData, "\"childCount\":%"PRId32"", scopeSize)) {
        goto finished;
    }

    if (!corto_ser_appendstr(userData, "},")) {
        goto finished;
    }

    return 1;
finished:
    return 0;
}

static corto_int16 serializeScopeMeta(corto_serializer s, corto_value* v, void* userData) {
    CORTO_UNUSED(s); /* should we receive s for scalability or should we dismiss it? */
    int last;
    size_t sizeBefore, sizeAfter;
    corto_json_ser_t *data = userData;
    sizeBefore = strlen(data->buffer);
    corto_object object = corto_valueValue(v);
    last = corto_scopeWalk(object, serializeMetaWalkScopeAction, userData);
    sizeAfter = strlen(data->buffer);
    if (sizeAfter && sizeBefore < sizeAfter) {
        data->buffer[sizeAfter - 1] = '\0';
    }
    return last;
}



static corto_int16 serializeObject(corto_serializer s, corto_value* v, void* userData) {
    corto_json_ser_t *data = userData;
    corto_uint8 c = 0;
    corto_uint32 options = data->serializeMeta + data->serializeValue + data->serializeScope;

    /* If more than one option is provided, prefix with
     * 'meta', 'value' and 'scope' */

    if (data->alwaysIncludeHeaders || (options > 1)) {
        if (!corto_ser_appendstr(data, "{")) {
            goto finished;
        }
    }

    if (data->serializeMeta) {
        if (data->alwaysIncludeHeaders || (options > 1)) {
            if (!corto_ser_appendstr(data, "\"meta\":")) {
                goto finished;
            }
        }
        if (serializeMeta(s, v, userData)) {
            goto error;
        }
        c += 1;
    }

    if (data->serializeValue) {
        if (corto_valueType(v)->kind != CORTO_VOID) {
            if (data->alwaysIncludeHeaders || (options > 1)) {
                if (c && !corto_ser_appendstr(data, ",")) {
                    goto finished;
                }
                if (!corto_ser_appendstr(data, "\"value\":")) {
                    goto finished;
                }
            }
            if (corto_serializeValue(s, v, userData)) {
                goto error;
            }
            c += 1;
         }
    }

    if (data->serializeScope) {
        if (data->alwaysIncludeHeaders || (options > 1)) {
            if (c && !corto_ser_appendstr(data, ",")) {
                goto finished;
            }
            if (!corto_ser_appendstr(data, "\"scope\":")) {
                goto finished;
            }
        }
        if (!corto_ser_appendstr(data, "[")) {
            goto finished;
        }
        if (!serializeScopeMeta(s, v, data)) {
            goto error;
        }
        if (!corto_ser_appendstr(data, "]")) {
            goto finished;
        }
    }

    if (data->alwaysIncludeHeaders || (options > 1)) {
        if (!corto_ser_appendstr(data, "}")) {
            goto finished;
        }
    }

    return 0;
error:
    return -1;
finished:
    return 1;
}

struct corto_serializer_s corto_json_ser(corto_modifier access, corto_operatorKind accessKind, corto_serializerTraceKind trace) {
    struct corto_serializer_s s;

    corto_serializerInit(&s);
    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = trace;
    s.program[CORTO_PRIMITIVE] = serializePrimitive;
    s.reference = serializeReference;
    s.program[CORTO_COMPOSITE] = serializeComplex;
    s.program[CORTO_COLLECTION] = serializeComplex;
    s.metaprogram[CORTO_ELEMENT] = serializeItem;
    s.metaprogram[CORTO_MEMBER] = serializeItem;
    s.metaprogram[CORTO_BASE] = serializeBase;
    s.metaprogram[CORTO_OBJECT] = serializeObject;

    return s;
}

corto_string json_serialize(corto_object o) {
    struct corto_serializer_s serializer = corto_json_ser(CORTO_PRIVATE, CORTO_NOT, CORTO_SERIALIZER_TRACE_NEVER);
    corto_json_ser_t jsonData = {NULL, NULL, 0, 0, 0, FALSE, TRUE, FALSE, TRUE};
    corto_serialize(&serializer, o, &jsonData);
    return jsonData.buffer;
}

int jsonMain(int argc, char* argv[]) {
    CORTO_UNUSED(argc);
    CORTO_UNUSED(argv);
    return 0;
}
