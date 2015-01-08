
#include <inttypes.h>
#include <stdio.h>
#include <string.h>

#include "cx_generator.h"
#include "cx_serializer.h"
#include "cx_string.h"
#include "cortex.h"
#include "json.h"

/* agreed not to change anything except the first argument of the signature */
static cx_bool cx_ser_appendstrbuff(cx_json_ser_t* data, char* str) {
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
static cx_bool cx_ser_appendstr(cx_json_ser_t* data, cx_string fmt, ...) {
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
        }
        vsprintf(buff, fmt, args);
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
    cx_typedef type;
    cx_void *value;
    cx_string valueString = NULL;
    cx_json_ser_t *data = userData;
    cx_int16 result;

    type = cx_valueType(info);
    value = cx_valueValue(info);
    cx_primitiveKind kind = cx_primitive(type->real)->kind;

    result = cx_convert(cx_primitive(type), value, cx_primitive(cx_string_o), &valueString);
    if (result) {
        goto error;
    }

    if (kind == CX_CHARACTER || (kind == CX_TEXT && (*(cx_string *)value))) {
        cx_string t;
        cx_string escapedValueString = cx_malloc(stresclen(valueString));
        stresc(valueString, escapedValueString, 0);
        t = valueString;
        valueString = escapedValueString;
        cx_dealloc(t);
    }

    switch (cx_primitive(type->real)->kind) {
        case CX_BINARY:
            if (!cx_ser_appendstr(data, "\"@B %s\"", valueString)) {
                goto finished;
            }
            break;
        case CX_BITMASK:
            if (!cx_ser_appendstr(data, "\"@M %s\"", valueString)) {
                goto finished;
            }
            break;
        case CX_ENUM:
            if (!cx_ser_appendstr(data, "\"@E %s\"", valueString)) {
                goto finished;
            }
            break;
        case CX_CHARACTER:
        case CX_TEXT:
            // TODO escape @'s and other characters
            if (!*(cx_string *)value) {
                if (!cx_ser_appendstr(data, "null")) {
                    goto finished;
                }
            } else {
                if (!cx_ser_appendstr(data, "\"")) {
                    goto finished;
                }
                if (*valueString == '@' && !cx_ser_appendstr(data, "@")) {
                    goto finished;
                }
                if (!cx_ser_appendstr(data, "%s\"", valueString)) {
                    goto finished;
                }
            }
            break;
        default:
            if (!cx_ser_appendstr(data, valueString)) {
                goto finished;
            }
            break;
    }

    cx_dealloc(valueString);
    return 0;
finished:
    cx_dealloc(valueString);
    return 1;
error:
    return -1;
}

static cx_int16 cx_ser_reference(cx_serializer s, cx_value *v, void *userData) {
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
            cx_fullname(object, id);
            if (!cx_ser_appendstr(data, "\"@R %s\"", id)) {
                goto finished;
            }
        } else {
            // TODO anonymous
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

static cx_int16 cx_ser_item(cx_serializer s, cx_value *info, void *userData) {
    cx_json_ser_t *data = userData;
    cx_member member = info->is.member.t;
    cx_string name = cx_nameof(member);

    if (data->itemCount && !cx_ser_appendstr(data, ",")) {
        goto finished;
    }
    if (info->kind == CX_MEMBER) {
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

static cx_int16 cx_ser_complex(cx_serializer s, cx_value* v, void* userData) {
    cx_json_ser_t *data = userData;
    cx_type type = cx_valueType(v)->real;
    cx_bool useCurlyBraces = FALSE;

    if (type->kind == CX_COMPOSITE || cx_collection(type)->kind == CX_MAP) {
        useCurlyBraces = TRUE;
    }

    if (!cx_ser_appendstr(data, (useCurlyBraces ? "{" : "["))) {
        goto finished;
    }
    if (type->kind == CX_COMPOSITE) {
        if (cx_serializeMembers(s, v, userData)) {
            goto error;
        }
    } else if (type->kind == CX_COLLECTION) {
        if (cx_serializeElements(s, v, userData)) {
            goto error;
        }
    } else {
        goto error;
    }

    if (!cx_ser_appendstr(data, (useCurlyBraces ? "}" : "]"))) {
        goto finished;
    }
    return 0;
error:
    return -1;
finished:
    return 1;
}

static cx_int16 cx_ser_base(cx_serializer s, cx_value* v, void* userData) {
    cx_json_ser_t *data = userData;
    if (!cx_ser_appendstr(data, "\"@base\":{")) {
        goto finished;
    }
    if (cx_serializeMembers(s, v, userData)) {
        goto error;
    }
    if (!cx_ser_appendstr(data, "}")) {
        goto finished;
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
        }
    }
    return buff;
}

static cx_int16 cx_ser_meta(cx_serializer s, cx_value* v, void* userData) {
    CX_UNUSED(s);
    cx_json_ser_t *data = userData;
    cx_object object = cx_valueValue(v);
    
    if (!data->serializeMeta) {
        goto error;
    }

    if (!cx_ser_appendstr(data, "{")) {
        goto finished;
    }

    cx_string name = cx_nameof(object);
    if (!cx_ser_appendstr(data, "\"name\":\"%s\",", name)) {
        goto finished;
    }

    cx_id type_fullname;
    cx_fullname(cx_typeof(object), type_fullname);
    if (!cx_ser_appendstr(data, "\"type\":\"%s\",", type_fullname)) {
        goto finished;
    }

    char states[sizeof("V|DCL|DEF")];
    dbsh_stateStr(object, states);
    if (!cx_ser_appendstr(data, "\"states\":\"%s\",", states)) {
        goto finished;
    }

    char attributes[sizeof("S|W|O")];
    dbsh_attrStr(object, attributes);
    if (!cx_ser_appendstr(data, "\"attributes\":\"%s\",", attributes)) {
        goto finished;
    }

    cx_id parent_fullname;
    cx_fullname(cx_parentof(object), parent_fullname);
    if (!cx_ser_appendstr(data, "\"parent\":\"%s\",", parent_fullname)) {
        goto finished;
    }

    cx_uint32 scopeSize = cx_scopeSize(object);
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

static int cx_walkScopeAction_ser_meta(cx_object o, void* userData) {
    if (!cx_ser_appendstr(userData, "{")) {
        goto finished;
    }

    cx_string name = cx_nameof(o);
    if (!cx_ser_appendstr(userData, "\"name\":\"%s\",", name)) {
        goto finished;
    }

    cx_id type_fullname;
    cx_fullname(cx_typeof(o), type_fullname);
    if (!cx_ser_appendstr(userData, "\"type\":\"%s\",", type_fullname)) {
        goto finished;
    }

    char states[sizeof("V|DCL|DEF")];
    dbsh_stateStr(o, states);
    if (!cx_ser_appendstr(userData, "\"states\":\"%s\",", states)) {
        goto finished;
    }

    char attributes[sizeof("S|W|O")];
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

static cx_int16 cx_ser_scope_meta(cx_serializer s, cx_value* v, void* userData) {
    CX_UNUSED(s); /* should we receive s for scalability or should we dismiss it? */
    int last;
    size_t sizeBefore, sizeAfter;
    cx_json_ser_t *data = userData;
    sizeBefore = strlen(data->buffer);
    cx_object object = cx_valueValue(v);
    last = cx_scopeWalk(object, cx_walkScopeAction_ser_meta, userData);
    sizeAfter = strlen(data->buffer);
    if (sizeAfter && sizeBefore < sizeAfter) {
        data->buffer[sizeAfter - 1] = '\0';
    }
    return last;
}



static cx_int16 cx_ser_object(cx_serializer s, cx_value* v, void* userData) {
    cx_json_ser_t *data = userData;
    cx_uint8 c = 0;

    if (!cx_ser_appendstr(data, "{")) {
        goto finished;
    }

    if (data->serializeMeta) {
        if (!cx_ser_appendstr(data, "\"meta\":")) {
            goto finished;
        }
        if (cx_ser_meta(s, v, userData)) {
            goto error;
        }
        c += 1;
    }

    if (data->serializeValue) {
        if (cx_valueType(v)->real->kind != CX_VOID) {
            if (c && !cx_ser_appendstr(data, ",")) {
                goto finished;
            }
            if (!cx_ser_appendstr(data, "\"value\":")) {
                goto finished;
            }
            if (cx_serializeValue(s, v, userData)) {
                goto error;
            }
            c += 1;
         }
    }

    if (data->serializeScope) {
        if (c && !cx_ser_appendstr(data, ",")) {
            goto finished;
        }
        if (!cx_ser_appendstr(data, "\"scope\":[")) {
            goto finished;
        }
        if (!cx_ser_scope_meta(s, v, data)) {
            goto error;
        }
        if (!cx_ser_appendstr(data, "]")) {
            goto finished;
        }
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

struct cx_serializer_s cx_json_ser(cx_modifier access, cx_operatorKind accessKind, cx_serializerTraceKind trace) {
    struct cx_serializer_s s;

    cx_serializerInit(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = trace;
    s.program[CX_PRIMITIVE] = cx_ser_primitive;
    s.reference = cx_ser_reference;
    s.program[CX_COMPOSITE] = cx_ser_complex;
    s.program[CX_COLLECTION] = cx_ser_complex;
    s.metaprogram[CX_ELEMENT] = cx_ser_item;
    s.metaprogram[CX_MEMBER] = cx_ser_item;
    s.metaprogram[CX_BASE] = cx_ser_base;
    s.metaprogram[CX_OBJECT] = cx_ser_object;
    return s;
}