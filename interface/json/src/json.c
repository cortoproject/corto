
#include <stdio.h>
#include <inttypes.h>

#include "db_generator.h"
#include "db_serializer.h"
#include "hyve.h"
#include "json.h"

/* agreed not to change anything except the first argument of the signature */
static db_bool db_ser_appendstrbuff(db_json_ser_t* data, char* str) {
    if (!data->ptr) {
        data->ptr = data->buffer;
    }
    if (!data->ptr) {
        data->buffer = strdup(str);
        data->ptr = data->buffer;
    } else {
        db_uint32 length, bufferLength;

        if (!data->length) {
            data->buffer = db_realloc(data->buffer, strlen(data->buffer) + strlen(str) + 1);
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
static db_bool db_ser_appendstr(db_json_ser_t* data, db_string fmt, ...) {
    char alloc[1024];
    char *buff = alloc;
    va_list args;
    db_uint32 memRequired;
    db_uint32 result = TRUE;

    if (data) {
        va_start(args, fmt);
        memRequired = vsnprintf(buff, 1024, fmt, args);
        if (memRequired >= 1024) {
            buff = db_malloc(memRequired + 1);
        }
        vsprintf(buff, fmt, args);
        va_end(args);
        result = db_ser_appendstrbuff(data, buff);
        if (buff != alloc) {
            db_dealloc(buff);
        }
    }

    return result;
}


static db_int16 db_ser_primitive(db_serializer s, db_value *info, void *userData) {
    DB_UNUSED(s);
    db_typedef type;
    db_void *value;
    db_string valueString = NULL;
    db_json_ser_t *data = userData;

    type = db_valueType(info);
    value = db_valueValue(info);

    db_convert(db_primitive(type), value, db_primitive(db_string_o), &valueString);
    if(!db_ser_appendstr(data, valueString)) {
        goto finished;
    }
    db_dealloc(valueString);

    return 0;
finished:
    return 1;
}

static db_int16 db_ser_member(db_serializer s, db_value *info, void *userData) {
    db_json_ser_t *data = userData;
    db_member member = info->is.member.t;
    db_string name = db_nameof(member);


    if (data->itemCount && !db_ser_appendstr(data, ",")) {
        goto finished;
    }

    if (!db_ser_appendstr(data, "\"%s\":", name)) {
        goto finished;
    }

    if (db_serializeValue(s, info, userData)) {
        goto error;
    }


    data->itemCount += 1;

    return 0;
error:
    return -1;
finished:
    return 1;
}

static db_int16 db_ser_composite(db_serializer s, db_value* v, void* userData) {
    db_json_ser_t *data = userData;
    if (!db_ser_appendstr(data, "{")) {
        goto finished;
    }

    if (db_serializeMembers(s, v, userData)) {
        goto error;
    }


    if (!db_ser_appendstr(data, "}")) {
        goto finished;
    }

    return 0;
error:
    return -1;
finished:
    return 1;
}

static db_int16 db_ser_meta(db_serializer s, db_value* v, void* userData) {
    db_json_ser_t *data = userData;
    db_object object = db_valueValue(v);
    
    if (!data->serializeMeta) {
        goto error;
    }

    if (!db_ser_appendstr(data, "{")) {
        goto finished;
    }

    db_string name = db_nameof(object);
    if (!db_ser_appendstr(data, "\"name\":\"%s\",", name)) {
        goto finished;
    }

    db_id type_fullname;
    db_fullname(db_typeof(object), type_fullname);
    if (!db_ser_appendstr(data, "\"type\":\"%s\",", type_fullname)) {
        goto finished;
    }


    db_id parent_fullname;
    db_fullname(db_parentof(object), parent_fullname);
    if (!db_ser_appendstr(data, "\"parent\":\"%s\",", parent_fullname)) {
        goto finished;
    }

    db_uint32 scopeSize = db_scopeSize(object);
    if (!db_ser_appendstr(data, "\"childCount\":%"PRId32"", scopeSize)) {
        goto finished;
    }

    if (!db_ser_appendstr(data, "}")) {
        goto finished;
    }


    return 0;
error:
    return -1;
finished:
    return 1;
}

static db_int16 db_ser_object(db_serializer s, db_value* v, void* userData) {
    db_json_ser_t *data = userData;
    unsigned int c = 0;

    if (!db_ser_appendstr(data, "{")) {
        goto finished;
    }

    if (data->serializeValue) {
        if (!db_ser_appendstr(data, "\"value\":")) {
            goto finished;
        }
        if (db_serializeValue(s, v, userData)) {
            goto error;
        }

        c += 1;
    }

    if (data->serializeMeta) {
        if (c && !db_ser_appendstr(data, ",")) {
            goto finished;
        }
        if (!db_ser_appendstr(data, "\"meta\":")) {
            goto finished;
        }
        if (db_ser_meta(s, v, userData)) {
            goto error;
        }
        c += 1;
    }

    if (data->serializeScope) {
        if (c && !db_ser_appendstr(data, ",")) {
            goto finished;
        }
        if (!db_ser_appendstr(data, "\"scope\":")) {
            goto finished;
        }
        /* tODO magic */
    }

    if (!db_ser_appendstr(data, "}")) {
        goto finished;
    }

    return 0;
error:
    return -1;
finished:
    return 1;
}

struct db_serializer_s db_json_ser(db_modifier access, db_operatorKind accessKind, db_serializerTraceKind trace) {
    struct db_serializer_s s;

    db_serializerInit(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = trace;
    s.program[DB_PRIMITIVE] = db_ser_primitive;
    s.program[DB_COMPOSITE] = db_ser_composite;
    /* s.program[DB_COLLECTION] = db_ser_scope; */
    s.metaprogram[DB_MEMBER] = db_ser_member;
    /* s.metaprogram[DB_BASE] = db_serializeMembers */;   /* Skip the scope-callback by directly calling serializeMembers. This will cause the extra
                                                     * '{ }' not to appear, which is required by this string format. */
    s.metaprogram[DB_OBJECT] = db_ser_object;
    return s;
}

