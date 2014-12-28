/*
 * db_string_ser.c
 *
 *  Created on: Aug 27, 2012
 *      Author: sander
 */

#include "db_string_ser.h"
#include "db_convert.h"
#include "db__meta.h"
#include "db_err.h"
#include "db_util.h"
#include "db_mem.h"
#include "db_object.h"
#include "stdarg.h"

static db_int16 db_ser_object(db_serializer s, db_value* v, void* userData);

static db_bool db_ser_appendstrbuff(db_string_ser_t* data, char* str) {
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

/* Append string to serializer-result */
static db_bool db_ser_appendstr(db_string_ser_t* data, db_string fmt, ...) {
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
            vsprintf(buff, fmt, args);
        }
        va_end(args);

        result = db_ser_appendstrbuff(data, buff);
        if (buff != alloc) {
            db_dealloc(buff);
        }
    }

    return result;
}

/* Escape string */
static db_bool db_ser_appendstrEscape(db_string_ser_t *data, db_string str) {
    db_char buffer[1024];
    db_char *ptr, *bptr, ch;

    ptr = str;
    bptr = buffer;
    *bptr = '"';
    bptr++;
    while((ch = *ptr)) {
        bptr = schresc(ch, bptr, 1);
        ptr++;

        if ((bptr - buffer) == 1023) { /* Avoid allocating temporary strings by reusing buffer.
                                       * Keep buffer sufficiently large to no call appendstr too much. */
            *bptr = '\0';
            if (!db_ser_appendstr(data, "%s", buffer)) {
                goto finished;
            }
            bptr = buffer;
        }
    }
    *bptr = '"';
    *(++bptr) = '\0';

    return db_ser_appendstr(data, "%s", buffer);
finished:
    return 1;
}

/* Serialize primitive values */
static db_int16 db_ser_primitive(db_serializer s, db_value* v, void* userData) {
    db_string_ser_t* data;
    db_type t;
    void* o;
    char* result;

    DB_UNUSED(s);
    result = NULL;

    data = (db_string_ser_t*)userData;
    t = db_valueType(v)->real;
    o = db_valueValue(v);

    /* If src is string and value is null, put NULL in result. */
    if (db_primitive(t)->kind == DB_TEXT) {
        if (*(db_string*)o) {
            if (!db_ser_appendstrEscape(data, *(db_string*)o)) {
                goto finished;
            }
        } else {
            if (!db_ser_appendstr(data, "null")) {
                goto finished;
            }
        }
    } else if (db_primitive(t)->kind == DB_CHARACTER) {
        if (*(db_char*)o) {
            if (!db_ser_appendstr(data, "'%c'", *(db_char*)o)) {
                goto finished;
            }
        } else {
            if (!db_ser_appendstr(data, "''")) {
                goto finished;
            }
        }
    } else {
        /* Convert primitive value to string */
        db_convert(db_primitive(t), o, db_primitive(db_string_o), &result);

        /* Append conversionresult to serializer-result*/
        if (!db_ser_appendstr(data, "%s", result)) {
            db_dealloc(result);
            goto finished;
        }
        db_dealloc(result);
    }

    return 0;
finished:
    return 1;
}

/* Serialize references */
static db_int16 db_ser_reference(db_serializer s, db_value* v, void* userData) {
    db_id id;
    void *o;
    db_object object;
    char* str;
    db_string_ser_t* data;

    data = userData;
    o = db_valueValue(v);
    object = *(db_object*)o;

    /* Obtain fully scoped name */
    if (object) {
        if (db_checkAttr(object, DB_ATTR_SCOPED) || (db_valueObject(v) == object)) {
            str = (char*)db_fullname(object, id);
        } else {
            db_string_ser_t walkData;
            int index = 0;

            if (!data->anonymousObjects) {
                data->anonymousObjects = db_llNew();
            }

            if ((index = db_llHasObject(data->anonymousObjects, object))) {
                sprintf(id, "<%d>", index);
                str = id;
            } else {
                db_value v;

                walkData.buffer = NULL;
                walkData.length = 0;
                walkData.maxlength = data->maxlength;
                walkData.compactNotation = data->compactNotation;
                walkData.ptr = NULL;
                walkData.prefixType = TRUE;
                walkData.anonymousObjects = data->anonymousObjects;

                db_llAppend(data->anonymousObjects, object);
                db_ser_appendstr(userData, "<%d>", db_llSize(data->anonymousObjects));

                v.kind = DB_OBJECT;
                v.is.o = object;
                v.parent = NULL;
                if (db_ser_object(s, &v, &walkData)) {
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
    if (!db_ser_appendstrbuff(userData, str)) {
        goto finished;
    }

    return 0;
error:
    return -1;
finished:
    return 1;
}

/* For composite and collection objects */
static db_int16 db_ser_scope(db_serializer s, db_value* v, void* userData) {
    db_int16 result;
    db_string_ser_t *data, privateData;
    db_type t;

    data = userData;
    t = db_valueType(v)->real;
    result = 0;

    /* Nested data has private itemCount, which prevents superfluous ',' to be added to the result. */
    privateData = *data;
    privateData.itemCount = 0;

    /* Serialize composite members */
    if (!db_ser_appendstr(&privateData, "{")) {
        goto finished;
    }
    if (t->kind == DB_COMPOSITE) {
        result = db_serializeMembers(s, v, &privateData);
    } else if (t->kind == DB_COLLECTION){
        result = db_serializeElements(s, v, &privateData);
    } else {
        db_assert(0, "db_ser_scope: invalid typekind for function.");
    }
    if (!result) {
        if (!db_ser_appendstr(&privateData, "}")) {
            goto finished;
        }
    }

    *data = privateData;

    return result;
finished:
    return 1;
}

/* Serialize item (can be either member or element) */
static db_int16 db_ser_item(db_serializer s, db_value* v, void* userData) {
    db_string_ser_t* data;
    DB_UNUSED(s);

    data = userData;

    /* Append ',' if this is not the first item */
    if (data->itemCount) {
        if (!db_ser_appendstr(data, ",")) {
            goto finished;
        }
    }

    if (!data->compactNotation) {
        if (v->kind == DB_MEMBER) {
            if (!db_ser_appendstr(data, "%s=", db_nameof(v->is.member.t))) {
                goto finished;
            }
        }
    }

    /* Serialize value of item */
    if (db_serializeValue(s, v, userData)) {
        goto error;
    }

    data->itemCount++;

    return 0;
error:
    return -1;
finished:
    return 1;
}

static db_int16 db_ser_object(db_serializer s, db_value* v, void* userData) {
    db_string_ser_t* data;
    data = userData;

    db_serializeValue(s, v, userData);

    if (data->prefixType) {
        db_id id;
        db_object o;
        db_string result = NULL;

        o = db_valueObject(v);
        db_fullname(db_typeof(o), id);

        if (db_typeof(o)->real->kind != DB_PRIMITIVE) {
            if (data->buffer) {
                result = db_malloc(strlen(data->buffer) + strlen(id) + 1);
                sprintf(result, "%s%s", id, data->buffer);
            } else {
                result = db_strdup(id);
            }
        } else {
            if (data->buffer) {
                result = db_malloc(strlen(data->buffer) + strlen(id) + 2 + 1);
                sprintf(result, "%s{%s}", id, data->buffer);
            } else {
                db_critical("failed to serialize value to string");
            }
        }

        if (!data->length) {
            db_dealloc(data->buffer); /* Serializer manages memory of buffer */
            data->buffer = result;
        } else { /* Application  manages memory of buffer */
            strcpy(data->buffer, result);
            db_dealloc(result);
        }
    }

    return 0;
}

static db_int16 db_ser_construct(db_serializer s, db_value *info, void* userData) {
    DB_UNUSED(s);
    DB_UNUSED(info);
    
    db_string_ser_t* data = userData;
    data->ptr = data->buffer;
    data->itemCount = 0;
    data->anonymousObjects = NULL;
    if (data->buffer) {
        *(data->buffer) = '\0';
    }
    return 0;
}

db_int16 db_ser_destruct(db_serializer s, void* userData) {
    DB_UNUSED(s);
    
    db_string_ser_t* data = userData;
    if (data->anonymousObjects) {
        db_llFree(data->anonymousObjects);
    }
    return 0;
}

struct db_serializer_s db_string_ser(db_modifier access, db_operatorKind accessKind, db_serializerTraceKind trace) {
    struct db_serializer_s s;

    db_serializerInit(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = trace;
    s.construct = db_ser_construct;
    s.destruct = db_ser_destruct;
    s.program[DB_VOID] = NULL;
    s.program[DB_PRIMITIVE] = db_ser_primitive;
    s.program[DB_COMPOSITE] = db_ser_scope;
    s.program[DB_COLLECTION] = db_ser_scope;
    s.metaprogram[DB_MEMBER] = db_ser_item;
    s.metaprogram[DB_BASE] = db_serializeMembers;   /* Skip the scope-callback by directly calling serializeMembers. This will cause the extra
                                                     * '{ }' not to appear, which is required by this string format. */
    s.metaprogram[DB_ELEMENT] = db_ser_item;
    s.metaprogram[DB_OBJECT] = db_ser_object;
    s.metaprogram[DB_CONSTANT] = NULL;
    s.reference = db_ser_reference;
    return s;
}
