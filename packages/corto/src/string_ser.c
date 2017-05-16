/* Copyright (c) 2010-2017 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "corto/corto.h"

#ifdef CORTO_CONVERSIONS

#define STRING (CORTO_RED)
#define REFERENCE (CORTO_CYAN)
#define BOOLEAN (CORTO_GREEN)
#define NUMBER (CORTO_GREEN)
#define CONSTANT (CORTO_MAGENTA)
#define MEMBER (CORTO_NORMAL)

static corto_int16 corto_ser_object(corto_walk_opt* s, corto_value* v, void* userData);

/* Insert color if enabled */
static corto_bool corto_ser_appendColor(corto_string_ser_t *data, corto_string color) {
    corto_bool result = TRUE;
    if (data->enableColors) {
        result = corto_buffer_append(&data->buffer, color);
    }
    return result;
}

/* Serialize any */
static corto_int16 corto_ser_any(corto_walk_opt* s, corto_value* v, void* userData) {
    corto_string_ser_t* data = userData;
    corto_any *this = corto_value_ptrof(v);
    corto_int16 result = 0;
    corto_id id;
    corto_value anyValue;
    anyValue = corto_value_value(this->value, this->type);

    if (!corto_buffer_append(&data->buffer, "{%s,", corto_fullpath(id, this->type))) {
        goto finished;
    }

    if ((result = corto_walk_value(s, &anyValue, data))) {
        return result;
    }

    if (!corto_buffer_append(&data->buffer, "}")) {
        goto finished;
    }

    return 0;
finished:
    return 0;
}

/* Serialize primitive values */
static corto_int16 corto_ser_primitive(corto_walk_opt* s, corto_value* v, void* userData) {
    corto_string_ser_t* data;
    corto_type t;
    void* o;
    char* result;

    CORTO_UNUSED(s);
    result = NULL;

    data = (corto_string_ser_t*)userData;
    t = corto_value_typeof(v);
    o = corto_value_ptrof(v);

    /* If src is string and value is null, put NULL in result. */
    if (corto_primitive(t)->kind == CORTO_TEXT) {
        corto_ser_appendColor(data, STRING);
        if (*(corto_string*)o) {
            size_t length = stresc(NULL, 0, *(corto_string*)o);
            corto_string out = corto_alloc(length + 1);
            stresc(out, length + 1, *(corto_string*)o);
            if (!corto_buffer_append(&data->buffer, "\"%s\"", out)) {
                corto_dealloc(out);
                goto finished;
            }
            corto_dealloc(out);
        } else {
            if (!corto_buffer_append(&data->buffer, "null")) {
                goto finished;
            }
        }
        corto_ser_appendColor(data, CORTO_NORMAL);
    } else if (corto_primitive(t)->kind == CORTO_CHARACTER) {
        corto_ser_appendColor(data, STRING);
        if (*(corto_char*)o) {
            if (!corto_buffer_append(&data->buffer, "'%c'", *(corto_char*)o)) {
                goto finished;
            }
        } else {
            if (!corto_buffer_append(&data->buffer, "''")) {
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
        corto_ptr_cast(corto_primitive(t), o, corto_primitive(corto_string_o), &result);

        /* Append conversionresult to serializer-result*/
        if (!corto_buffer_append(&data->buffer, "%s", result)) {
            corto_dealloc(result);
            goto finished;
        }
        corto_dealloc(result);
        corto_ser_appendColor(data, CORTO_NORMAL);
    }

    return 0;
finished:
    return 1;
}

/* Serialize references */
static corto_int16 corto_ser_reference(corto_walk_opt* s, corto_value* v, void* userData) {
    corto_id id;
    void *o;
    corto_object object;
    char* str;
    corto_bool allocated = FALSE;
    corto_string_ser_t* data;

    data = userData;
    o = corto_value_ptrof(v);
    object = *(corto_object*)o;

    /* Obtain fully scoped name */
    corto_ser_appendColor(data, REFERENCE);
    if (object) {
        if (corto_checkAttr(object, CORTO_ATTR_NAMED)) {
            if (corto_parentof(object) == corto_lang_o) {
                strcpy(id, corto_idof(object));
                str = id;
            } else {
                str = (char*)corto_fullpath(id, object);
            }
        } else {
            corto_string_ser_t walkData;
            int index = 0;

            if (!data->anonymousObjects) {
                data->anonymousObjects = corto_ll_new();
            }

            if (object == corto_value_objectof(v)) {
                sprintf(id, "<0>");
                str = id;
            }else if ((index = corto_ll_hasObject(data->anonymousObjects, object))) {
                sprintf(id, "<%d>", index);
                str = id;
            } else {
                corto_value v;

                walkData.buffer = CORTO_BUFFER_INIT;
                walkData.buffer.max = data->buffer.max;
                walkData.compactNotation = data->compactNotation;
                walkData.ptr = NULL;
                walkData.prefixType = TRUE;
                walkData.anonymousObjects = data->anonymousObjects;
                walkData.enableColors = data->enableColors;

                corto_ll_append(data->anonymousObjects, object);
                if (!corto_buffer_append(&data->buffer, "<%d>", corto_ll_size(data->anonymousObjects))) {
                    goto finished;
                }

                v = corto_value_object(object, NULL);
                if (corto_ser_object(s, &v, &walkData)) {
                    goto error;
                }

                data->anonymousObjects = walkData.anonymousObjects;
                str = corto_buffer_str(&walkData.buffer);
                allocated = TRUE;
            }
        }
    } else {
        str = "null";
    }

    /* Append name to serializer-result */
    if (!corto_buffer_append(&data->buffer, "%s", str)) {
        goto finished;
    }
    corto_ser_appendColor(data, CORTO_NORMAL);

    if (allocated) {
        corto_dealloc(str);
    }

    return 0;
error:
    return -1;
finished:
    return 1;
}

/* For composite and collection objects */
static corto_int16 corto_ser_scope(corto_walk_opt* s, corto_value* v, void* userData) {
    corto_int16 result;
    corto_string_ser_t *data, privateData;
    corto_type t;

    data = userData;
    t = corto_value_typeof(v);
    result = 0;

    /* Nested data has private itemCount, which prevents superfluous ',' to be added to the result. */
    privateData.ptr = data->ptr;
    privateData.anonymousObjects = data->anonymousObjects;
    privateData.buffer = CORTO_BUFFER_INIT;
    privateData.itemCount = 0;
    privateData.enableColors = data->enableColors;
    privateData.compactNotation = data->compactNotation;

    /* Serialize composite members */
    if (!corto_ser_appendColor(&privateData, CORTO_BOLD)) goto finished;
    if (!corto_buffer_append(&privateData.buffer, "{")) {
        goto finished;
    }
    if (!corto_ser_appendColor(&privateData, CORTO_NORMAL)) goto finished;
    if (t->kind == CORTO_COMPOSITE) {
        if (corto_interface(t)->kind == CORTO_UNION) {
            void *ptr = corto_value_ptrof(v);
            char *d;
            if (corto_ptr_cast(corto_union(t)->discriminator, ptr, corto_string_o, &d)) {
                corto_seterr("invalid discriminator value '%d' for union '%s'",
                  *(corto_int32*)ptr,
                  corto_fullpath(NULL, t));
                  goto finished;
            }
            if (!corto_buffer_appendstr(&privateData.buffer, d)) {
                goto finished;
            }
            corto_dealloc(d);
            privateData.itemCount = 1;
        }
        result = corto_walk_members(s, v, &privateData);
    } else if (t->kind == CORTO_COLLECTION){
        result = corto_walk_elements(s, v, &privateData);
    } else {
        corto_assert(0, "corto_ser_scope: invalid typekind for function.");
    }
    if (!result) {
        if (!corto_ser_appendColor(&privateData, CORTO_BOLD)) goto finished;
        if (!corto_buffer_append(&privateData.buffer, "}")) {
            goto finished;
        }
        if (!corto_ser_appendColor(&privateData, CORTO_NORMAL)) goto finished;
    }

    data->anonymousObjects = privateData.anonymousObjects;
    data->ptr = privateData.ptr;
    data->itemCount = privateData.itemCount;

    corto_string str = corto_buffer_str(&privateData.buffer);
    if (!corto_buffer_append(&data->buffer, str)) {
        goto finished;
    }
    corto_dealloc(str);

    return result;
finished:
    return 1;
}

/* Serialize item (can be either member or element) */
static corto_int16 corto_ser_item(corto_walk_opt* s, corto_value* v, void* userData) {
    corto_string_ser_t* data;
    CORTO_UNUSED(s);

    data = userData;

    /* Append ',' if this is not the first item */
    if (data->itemCount) {
        if (!data->compactNotation) {
            if (!corto_buffer_append(&data->buffer, " ")) {
                goto finished;
            }
        } else {
            if (!corto_buffer_append(&data->buffer, ",")) {
                goto finished;
            }
        }
    }

    if (v->kind == CORTO_MEMBER) {
        if (!data->compactNotation) {
            if (!corto_ser_appendColor(data, MEMBER)) goto finished;
            if (!corto_buffer_append(&data->buffer, "%s", corto_idof(v->is.member.t))) goto finished;
            if (!corto_ser_appendColor(data, CORTO_BOLD)) goto finished;
            if (!corto_buffer_append(&data->buffer, "=")) goto finished;
            if (!corto_ser_appendColor(data, CORTO_NORMAL)) goto finished;
        }
    }

    /* Serialize value of item */
    if (corto_walk_value(s, v, userData)) {
        goto error;
    }

    data->itemCount++;

    return 0;
error:
    return -1;
finished:
    return 1;
}

static corto_int16 corto_ser_object(corto_walk_opt* s, corto_value* v, void* userData) {
    corto_string_ser_t* data;
    data = userData;

    corto_walk_value(s, v, userData);

    if (data->prefixType) {
        corto_id buffer;
        char *typeId = buffer;
        corto_object o;
        corto_string result = NULL;
        corto_string str = corto_buffer_str(&data->buffer);

        if (str) {
            o = corto_value_objectof(v);
            if (corto_checkAttr(corto_typeof(o), CORTO_ATTR_NAMED)) {
                corto_fullpath(typeId, corto_typeof(o));
            } else {
                corto_walk_opt typeSer;
                corto_string_ser_t data;

                /* Serialize type to string */
                typeSer = corto_string_ser(CORTO_LOCAL|CORTO_READONLY|CORTO_PRIVATE, CORTO_NOT, CORTO_WALK_TRACE_ON_FAIL);
                data.compactNotation = TRUE;
                data.buffer = CORTO_BUFFER_INIT;
                data.buffer.buf = NULL;
                data.buffer.max = 0;
                data.prefixType = TRUE;
                data.enableColors = FALSE;
                if (corto_walk(&typeSer, corto_typeof(o), &data)) {
                    goto error;
                }

                typeId = corto_buffer_str(&data.buffer);
                corto_walk_deinit(&typeSer, &data);
            }

            if (corto_typeof(o)->kind != CORTO_PRIMITIVE) {
                if (str) {
                    result = corto_alloc(strlen(str) + strlen(typeId) + 1);
                    sprintf(result, "%s%s", typeId, str);
                } else {
                    result = corto_strdup(typeId);
                }
            } else {
                if (str) {
                    result = corto_alloc(strlen(str) + strlen(typeId) + 2 + 1);
                    sprintf(result, "%s{%s}", typeId, str);
                } else {
                    corto_critical("failed to serialize value to string");
                }
            }

            if (!data->buffer.buf) {
                corto_buffer_appendstr(&data->buffer, result);
                corto_dealloc(result);
            } else { /* Application  manages memory of buffer */
                strncpy(data->buffer.buf, result, data->buffer.max - 1);
                data->buffer.buf[data->buffer.max] = '\0';
                corto_dealloc(result);
            }

            corto_dealloc(str);
            if (typeId != buffer) {
                corto_dealloc(typeId);
            }
        }
    }

    return 0;
error:
    return -1;
}

static corto_int16 corto_ser_construct(corto_walk_opt* s, corto_value *info, void* userData) {
    CORTO_UNUSED(s);
    CORTO_UNUSED(info);

    corto_string_ser_t* data = userData;
    data->itemCount = 0;
    data->anonymousObjects = NULL;
    if (data->buffer.buf) {
        *(data->buffer.buf) = '\0';
    }
    return 0;
}

corto_int16 corto_ser_destruct(corto_walk_opt* s, void* userData) {
    CORTO_UNUSED(s);
    corto_string_ser_t* data = userData;
    if (data->anonymousObjects) {
        corto_ll_free(data->anonymousObjects);
        data->anonymousObjects = NULL;
    }
    return 0;
}

corto_walk_opt corto_string_ser(corto_modifier access, corto_operatorKind accessKind, corto_walk_traceKind trace) {
    corto_walk_opt s;

    corto_walk_init(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.aliasAction = CORTO_WALK_ALIAS_IGNORE;
    s.traceKind = trace;
    s.construct = corto_ser_construct;
    s.destruct = corto_ser_destruct;
    s.program[CORTO_VOID] = NULL;
    s.program[CORTO_ANY] = corto_ser_any;
    s.program[CORTO_PRIMITIVE] = corto_ser_primitive;
    s.program[CORTO_COMPOSITE] = corto_ser_scope;
    s.program[CORTO_COLLECTION] = corto_ser_scope;

    s.metaprogram[CORTO_MEMBER] = corto_ser_item;
    s.metaprogram[CORTO_BASE] = corto_walk_members;   /* Skip the scope-callback by directly calling serializeMembers. This will cause the extra
                                                     * '{ }' not to appear, which is required by this string format. */
    s.metaprogram[CORTO_ELEMENT] = corto_ser_item;
    s.metaprogram[CORTO_OBJECT] = corto_ser_object;
    s.metaprogram[CORTO_CONSTANT] = NULL;
    s.reference = corto_ser_reference;
    return s;
}
#else
corto_walk_opt corto_string_ser(corto_modifier access, corto_operatorKind accessKind, corto_walk_traceKind trace) {
    corto_walk_opt s;
    CORTO_UNUSED(access);
    CORTO_UNUSED(accessKind);
    CORTO_UNUSED(trace);
    corto_walk_init(&s);
    return s;
}
#endif
