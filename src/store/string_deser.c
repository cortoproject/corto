/* Copyright (c) 2010-2018 the corto developers
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

#include <corto/corto.h>
#include "src/store/object.h"

#ifdef CORTO_CONVERSIONS

struct corto_string_deserIndexInfo {
    corto_member m;
    corto_type type;
    corto_bool parsed;
};

/* Serialize members */
static corto_int16 corto_string_deserBuildIndexComposite(corto_walk_opt* s, corto_value* v, void* userData) {
    corto_int16 result = 0;

    /* Only serialize direct members of object or elements */
    if ((v->kind == CORTO_OBJECT) || (v->kind == CORTO_BASE)) {
        result = corto_walk_members(s, v, userData);
    }
    return result;
}

/* Insert info into index */
static void corto_string_deserIndexInsert(corto_string_deser_t* data, struct corto_string_deserIndexInfo* info) {
    if (!data->index) {
        data->index = corto_ll_new();
        data->current = 0;
    }
    corto_ll_append(data->index, info);
}

/* Lookup index */
static struct corto_string_deserIndexInfo* corto_string_deserIndexLookup(
    corto_string member,
    corto_string_deser_t* data)
{
    corto_iter iter;
    struct corto_string_deserIndexInfo* info;
    corto_bool found;

    info = NULL;
    found = FALSE;

    if (data->index) {
        iter = corto_ll_iter(data->index);

        /* Lookup member in index */
        while(corto_iter_hasNext(&iter)) {
            info = corto_iter_next(&iter);

            /* Ambiguous members must always be referenced from their own scope.
             * Even if the current scope does not have a member with the
             * specified name, implicit referencing is not allowed. */
            if (!strcmp(corto_idof(info->m), member) && (!info->parsed)) {
                found = TRUE;
                data->iterData = *(corto_ll_iter_s*)iter.ctx;
                data->currentIter = iter;
                data->currentIter.ctx = &data->iterData;
                break;
            }
        }
        if (!found) info = NULL;
    }

    return info;
}

/* Get next member */
static struct corto_string_deserIndexInfo* corto_string_deserIndexNext(corto_string_deser_t* data) {
    struct corto_string_deserIndexInfo* info;

    info = NULL;

    if (data->index) {
        if (corto_iter_hasNext(&data->currentIter)) {
            info = corto_iter_next(&data->currentIter);
        }
    }

    return info;
}

/* Free nodes from index */
int corto_string_deserWalkIndex(void* o, void* ctx) {
    CORTO_UNUSED(ctx);
    corto_dealloc(o);
    return 1;
}

/* Free index */
void corto_string_deserFreeIndex(corto_string_deser_t* data) {
    if (data->index) {
        corto_ll_walk(data->index, corto_string_deserWalkIndex, NULL);
        corto_ll_free(data->index);
    }
}

/* Add indexInfo to indextable for each primitive */
static corto_int16 corto_string_deserBuildIndexPrimitive(corto_walk_opt* s, corto_value* v, void* userData) {
    corto_string_deser_t* data;
    struct corto_string_deserIndexInfo *newInfo;
    corto_member m;

    CORTO_UNUSED(s);

    data = userData;

    /* Lookup member */
    m = v->is.member.t;

    /* Create new info-object */
    newInfo = corto_alloc(sizeof(struct corto_string_deserIndexInfo));
    newInfo->m = m;
    newInfo->type = m->type;
    newInfo->parsed = FALSE;

    /* Insert indexInfo into index */
    corto_string_deserIndexInsert(data, newInfo);

    return 0;
}

/* This function prevents doing unwanted deepwalks of types */
static corto_int16 corto_string_deserBuildIndexDummy(corto_walk_opt* s, corto_value* v, void* userData) {
    CORTO_UNUSED(s);
    CORTO_UNUSED(v);
    CORTO_UNUSED(userData);
    return 0;
}

/* Serializer that builds indices from type */
corto_walk_opt corto_string_deserBuildIndex(void) {
    corto_walk_opt result;
    corto_walk_init(&result);
    /* Add an indexInfo object for each primitive. */
    result.program[CORTO_VOID] = corto_string_deserBuildIndexDummy;
    result.program[CORTO_PRIMITIVE] = corto_string_deserBuildIndexDummy;
    result.program[CORTO_COLLECTION] = corto_string_deserBuildIndexDummy;
    result.metaprogram[CORTO_OBJECT] = corto_string_deserBuildIndexComposite;
    result.metaprogram[CORTO_BASE] = corto_string_deserBuildIndexComposite;
    result.metaprogram[CORTO_MEMBER] = corto_string_deserBuildIndexPrimitive;
    result.access = CORTO_LOCAL|CORTO_PRIVATE|CORTO_READONLY;
    result.accessKind = CORTO_NOT;
    result.traceKind = CORTO_WALK_TRACE_ON_FAIL;
    return result;
}

static corto_string corto_string_deserParse(corto_string str, struct corto_string_deserIndexInfo* info, corto_string_deser_t* data);

void* corto_string_deserAllocAny(void *ptr, corto_string_deser_t *data) {
    void *result = NULL;
    if (!data->current) {
        result = ptr;
    } else {
        corto_any *a = ptr;
        corto_type t = a->type;
        struct corto_string_deserIndexInfo *anyNode = data->allocUdata;
        anyNode->type = t;
        a->owner = TRUE;
        if (t->kind == CORTO_PRIMITIVE) {
            a->value = corto_calloc(corto_type_sizeof(t));
            result = a->value;
        } else {
            result = &a->value;
        }
    }
    return result;
}

void* corto_string_deserAllocElem(void *ptr, corto_string_deser_t *data) {
    corto_collection t = corto_collection(data->allocUdata);
    corto_int32 size = corto_type_sizeof(t->elementType);
    void *result = NULL;

    if (ptr) {
        switch(t->kind) {
        case CORTO_SEQUENCE: {
            corto_objectseq *seq = ptr; /* Use random built-in sequence type */
            seq->buffer = corto_realloc(seq->buffer, (data->current + 1) * size);
            seq->length = data->current + 1;
            ptr = seq->buffer;
            memset(CORTO_OFFSET(ptr, size * data->current), 0, size);
        }
        case CORTO_ARRAY:
            result = CORTO_OFFSET(ptr, size * data->current);
            break;
        case CORTO_LIST: {
            corto_ll list = *(corto_ll*)ptr;
            if (corto_collection_requiresAlloc(t->elementType)) {
                result = corto_calloc(size);
                corto_ll_append(list, result);
            } else {
                corto_ll_append(list, NULL);
                result = corto_ll_getPtr(list, corto_ll_count(list) - 1);
            }
            break;
        default:
            break;
        }
        }
    }

    return result;
}

/* Parse scope */
static corto_string corto_string_deserParseScope(corto_string str, struct corto_string_deserIndexInfo* info, corto_string_deser_t* data) {
    struct corto_string_deserIndexInfo rootInfo;
    corto_typeKind kind;
    void *ptr = data->ptr;

    if (data->allocValue) {
        ptr = data->allocValue(ptr, data);
    }

    /* Prepare privateData */
    corto_string_deser_t privateData = {
        .out = data->out,
        .scope = data->scope,
        .anonymousObjects = data->anonymousObjects,
        .type = data->type,
        .isObject = data->isObject,
        .members = {0, NULL}
    };

    /* Offset the scope-members with the current offset */
    if (info && info->m) {
        ptr = corto_getMemberPtr(data->isObject ? data->out : NULL, ptr, info->m);
    }
    privateData.ptr = ptr;

    /* Open scope of type */
    if (!info) {
        if (!data->type) {
            rootInfo.type = corto_typeof(data->out);
        } else {
            rootInfo.type = data->type;
        }
        rootInfo.m = NULL;
        rootInfo.parsed = FALSE;
        info = &rootInfo;
    }

    /* Check if type is any, composite or collection */
    kind = info->type->kind;

    if ((kind != CORTO_COMPOSITE) && (kind != CORTO_COLLECTION) && (kind != CORTO_ANY)) {
        corto_throw("'{' unexpected for type '%s'",
            corto_fullpath(NULL, info->type));
        goto error;
    }

    /* Build index for type */
    if (info->type->kind == CORTO_COMPOSITE) {
        if (corto_interface(info->type)->kind == CORTO_UNION) {
            /* Parse discriminator */
            struct corto_string_deserIndexInfo dInfo;
            dInfo.type = (corto_type)corto_int32_o;
            dInfo.parsed = FALSE;
            dInfo.m = NULL;
            str = corto_string_deserParse(str + 1, &dInfo, &privateData);
            if (!str) {
                goto error;
            }

            /* Find corresponding union case */
            corto_int32 d = *(corto_int32*)ptr;
            corto_member m = safe_corto_union_findCase(info->type, d);
            if (!m) {
                corto_throw("discriminator '%d' invalid for union '%s'",
                    d, corto_fullpath(NULL, info->type));
                goto error;
            }

            /* Build index for one member */
            struct corto_string_deserIndexInfo *caseInfo =
                corto_alloc(sizeof(struct corto_string_deserIndexInfo));
            caseInfo->type = m->type;
            caseInfo->parsed = FALSE;
            caseInfo->m = m;
            corto_string_deserIndexInsert(&privateData, caseInfo);
        } else {
            corto_walk_opt s = corto_string_deserBuildIndex();
            s.members = data->members;
            if (s.members.length) {
                s.access = 0;
            }
            if (corto_metawalk(&s, info->type, &privateData)) {
                goto error;
            }
        }

        /* Create iterator for index */
        if (privateData.index) {
            privateData.currentIter = _corto_ll_iter(privateData.index, &privateData.iterData);
        }
    /* If type is a collection, build index with one node for element */
    } else if (info->type->kind == CORTO_COLLECTION) {
        struct corto_string_deserIndexInfo *elementNode;
        elementNode = corto_alloc(sizeof(struct corto_string_deserIndexInfo));
        elementNode->m = NULL;
        elementNode->parsed = FALSE;
        elementNode->type = corto_collection(info->type)->elementType;
        corto_string_deserIndexInsert(&privateData, elementNode);

        /* Create iterator for index */
        privateData.currentIter = _corto_ll_iter(privateData.index, &privateData.iterData);
        privateData.allocValue = corto_string_deserAllocElem;
        privateData.allocUdata = info->type;

        if (ptr) {
            switch(corto_collection(info->type)->kind) {
            case CORTO_ARRAY:
            case CORTO_SEQUENCE:
                break;
            case CORTO_LIST:
                if (!*(corto_ll*)ptr) {
                    *(corto_ll*)ptr = corto_ll_new();
                } else {
                    corto_ll_clear(*(corto_ll*)ptr);
                }
                privateData.ptr = ptr;
                break;
            default:
                break;
            }
        }
    } else if (info->type->kind == CORTO_ANY) {
          struct corto_string_deserIndexInfo *anyNode;
          anyNode = corto_alloc(sizeof(struct corto_string_deserIndexInfo));
          anyNode->m = NULL;
          anyNode->parsed = FALSE;
          anyNode->type = corto_type(corto_type_o);
          corto_string_deserIndexInsert(&privateData, anyNode);
          privateData.currentIter = _corto_ll_iter(privateData.index, &privateData.iterData);
          privateData.allocValue = corto_string_deserAllocAny;
          privateData.allocUdata = anyNode;
    }

    /* Parse scope */
    if (!(str = corto_string_deserParse(str+1, info, &privateData))) {
        goto error;
    }

    corto_string_deserFreeIndex(&privateData);

    data->anonymousObjects = privateData.anonymousObjects;

    return str;
error:
    return NULL;
}

/* Get pointer to current destination value */
corto_int16 corto_string_getDestinationPtr(
    struct corto_string_deserIndexInfo* info,
    corto_string_deser_t* data,
    void **ptr_out)
{
    void *result = data->ptr;

    *ptr_out = NULL;

    if (!info) {
        corto_throw("excess elements in string");
        goto error;
    }

    if (data->allocValue) {
        result = data->allocValue(result, data);
    }

    if (info->m) {
        result = corto_getMemberPtr(data->isObject ? data->out : NULL, data->ptr, info->m);
    }

    *ptr_out = result;

    return 0;
error:
    return -1;
}

static corto_string corto_string_deserParseAnonymousId (
    corto_string str,
    corto_uint32 *out)
{
    char *ptr = str;
    if (*ptr == '<') {
        char buf[15], *bptr, ch;

        bptr = buf;
        ptr++;
        while((ch = *ptr) && (ch != '>')) {
            *bptr = ch;
            bptr++;
            ptr++;
        }
        *bptr = '\0';
        ptr++;

        /* Check if index points to an existing anonymous object */
        if (out) {
            *out = atoi(buf);
        }
    } else {
        return NULL;
    }

    return ptr;
}

/* Parse value */
static corto_int16 corto_string_deserParseValue(
    corto_string value,
    struct corto_string_deserIndexInfo* info,
    corto_string_deser_t* data)
{
    void *offset;
    if (corto_string_getDestinationPtr(info, data, &offset)) {
        corto_throw("cannot deserialize %s", value);
        goto error;
    }

    /* No more elements where available in the index, meaning an excess element */
    if (!info) {
        corto_throw("excess elements in scope @ '%s'", value);
        goto error;
    }

    /* Can typically occur when mixing short with default notation. */
    if (info->parsed) {
        corto_throw("member '%s' is already parsed", corto_idof(info->m));
        goto error;
    }

    /* Only parse references and primitives */
    if (info->type->reference) {
        corto_object o = NULL;
        corto_uint32 index = 0;

        /* Resolve object */
        if (corto_string_deserParseAnonymousId(value, &index)) {
            if (!index) {
                if (data->isObject) {
                    o = data->out;
                    corto_claim(o);
                } else {
                    corto_throw("cannot refer to self (<0>), not deserializing an object");
                    goto error;
                }
            } else if (data->anonymousObjects && (index <= corto_ll_count(data->anonymousObjects))) {
                o = corto_ll_get(data->anonymousObjects, index - 1);
                corto_claim(o);
            } else {
                corto_throw("undefined anonymous identifier '%s'", value);
                goto error;
            }
        } else {
            o = corto_resolve(data->scope, value);
        }

        if (o || !strcmp(value, "null")) {
            if (offset) corto_ptr_setref(offset, o);
            if (o) corto_release(o);
        } else {
            corto_throw("unresolved reference to '%s' for member '%s'", value,
                corto_fullpath(NULL, info->m));
            goto error;
        }
    } else

    /* Convert string to primitive value */
    if (offset && (info->type->kind == CORTO_PRIMITIVE)) {
        if (corto_primitive(info->type)->kind != CORTO_TEXT) {
            if (corto_ptr_cast(corto_primitive(corto_string_o), &value, corto_primitive(info->type), offset)) {
                goto error;
            }
        } else {
            corto_uint32 length;
            corto_string deserialized;

            if (strcmp(value, "null")) {
                length = strlen(value);
                deserialized = corto_alloc(length+1);
                memcpy(deserialized, value, length);
                deserialized[length] = '\0';
            } else {
                deserialized = NULL;
            }

            corto_ptr_setstr(offset, deserialized);
        }
    }

    /* Members are only parsed once */
    if (info->m) {
        info->parsed = TRUE;
    }

    return 0;
error:
    return -1;
}

/* Parse character literal */
static corto_string corto_string_deserParseCharacter(corto_string ptr, corto_char *bptr) {

    if (*ptr == '\\') {
        ptr ++;
        switch(*ptr) {
        case 'a':
            *bptr = '\a';
            break;
        case 'b':
            *bptr = '\b';
            break;
        case 'f':
            *bptr = '\f';
            break;
        case 'n':
            *bptr = '\n';
            break;
        case 'r':
            *bptr = '\r';
            break;
        case 't':
            *bptr = '\t';
            break;
        case 'v':
            *bptr = '\v';
            break;
        case '0':
            *bptr = '\0';
            break;
        case '\\':
            *bptr = '\\';
            break;
        case '\"':
            *bptr = '\"';
            break;
        case '\'':
            *bptr = '\'';
            break;
        }
    } else {
        *bptr = *ptr;
    }

    ptr++;

    return ptr;
}

/* Parse string literal */
static corto_string corto_string_deserParseString(corto_string ptr, corto_string buffer, corto_string *bufferPtr) {
    corto_char ch, *bptr;

    ptr++; /* Skip first '"' */
    bptr = buffer;
    while((ch = *ptr) && (ch != '"')) {
        ptr = corto_string_deserParseCharacter(ptr, bptr);
        bptr++;
    }
    if (ch) {
        ptr++; /* Skip last '"' */
    }

    *bptr = '\0';

    *bufferPtr = bptr;

    return ptr;
}

static corto_string corto_string_parseAnonymous(
    corto_string str,
    corto_string value,
    struct corto_string_deserIndexInfo *info,
    corto_string_deser_t *data)
{
    corto_object o = NULL;
    char *ptr = str;
    char *valuePtr = value;
    corto_uint32 index = 0;
    void *offset;

    if (corto_string_getDestinationPtr(info, data, &offset)) {
        corto_throw("cannot deserialize %s", str);
        goto error;
    }

    /* Check if this is a 'named' anonymous object in which case it is
     * prefixed with <[id]> */
    if ((valuePtr = corto_string_deserParseAnonymousId(valuePtr, &index))) {
        if (data->anonymousObjects && (index <= corto_ll_count(data->anonymousObjects))) {
            if (!*valuePtr) {
                o = corto_ll_get(data->anonymousObjects, index - 1);
                corto_claim(o);
            } else {
                /* If the <n> is followed up with more data, a new anonymous
                 * object is being created while one existed already with the
                 * specified number */
                corto_throw("identifier <%d> is already defined (%s)", index, value);
                goto error;
            }
        }
    } else {
        valuePtr = value;
    }

    /* If no object has been referenced, create an anonymous object */
    if (!o && *valuePtr) {
        corto_object type = corto_resolve(NULL, valuePtr);
        if (!type) {
            corto_throw("unresolved type '%s'", valuePtr);
            goto error;
        }

        if (offset) {
            o = *(corto_object*)offset;
            if (!o || (type != corto_typeof(o))) {
                if (!corto_instanceof(corto_type_o, type)) {
                    corto_throw("'%s' is not a type", corto_fullpath(NULL, type));
                    goto error;
                }

                o = corto_declare(type);
                if (!o) {
                    corto_throw("failed to declare %s", value);
                    goto error;
                }
            } else {
                corto_claim(o);
            }
        }

        corto_string_deser_t privateData = {
            .out = data->out, // Preserve original out to determine ownership
            .ptr = o,
            .type = type,
            .anonymousObjects = data->anonymousObjects,
            .scope = data->scope,
            .isObject = data->isObject
        };

        if (corto_type(type)->kind == CORTO_PRIMITIVE) {
            ptr ++;
            if (!(ptr = corto_string_deserParse(ptr, NULL, &privateData))) {
                goto error;
            }
        } else {
            if (!(ptr = corto_string_deserParseScope(ptr, NULL, &privateData))) {
                goto error;
            }
        }

        if (o) {
            if (corto_define(o)) {
                goto error;
            }
            data->anonymousObjects = privateData.anonymousObjects;

            if (!data->anonymousObjects) {
                data->anonymousObjects = corto_ll_new();
            }

            corto_ll_append(data->anonymousObjects, o);
        }
    }

    if (offset) corto_ptr_setref(offset, o);
    if (o) corto_release(o);

    return ptr;
error:
    if (o) corto_release(o);
    return NULL;
}

/* Parse string */
static corto_string corto_string_deserParse(
    corto_string str,
    struct corto_string_deserIndexInfo* info,
    corto_string_deser_t* data)
{
    corto_char ch;
    corto_char *ptr, *bptr, *nonWs;
    corto_char buffer[CORTO_STRING_DESER_TOKEN_MAX]; /* TODO: dangerous in a recursive function */
    corto_bool proceed, excess;
    struct corto_string_deserIndexInfo* memberInfo;

    CORTO_UNUSED(info);

    ptr = str;
    bptr = buffer;
    nonWs = bptr;
    proceed = TRUE;
    excess = FALSE;
    memberInfo = NULL;

    if (info) {
        memberInfo = corto_string_deserIndexNext(data);
    }

    /* If ptr == NULL, an error has occurred. If proceed == FALSE, this function
     * has finished processing the current value. */
    while(ptr && (ch = *ptr) && proceed) {
        switch(ch) {
        case '=': /* Explicit member assignment */
            excess = FALSE;
            if (buffer == bptr) {
                corto_throw("missing member identifier");
                goto error;
            } else {
                *nonWs = '\0';
                memberInfo = corto_string_deserIndexLookup(buffer, data);
                bptr = buffer;
                nonWs = bptr;
                if (!memberInfo) {
                    corto_throw("member '%s' not found in type '%s'", buffer, corto_fullpath(NULL, data->type));
                    goto error;
                }
                break;
            }

        case '{': /* Scope open */
            if (bptr == buffer) {
                if (!(ptr = corto_string_deserParseScope(
                    ptr,
                    memberInfo,
                    data))) {
                    goto error;
                }
            } else {
                *bptr = '\0';
                if (!(ptr = corto_string_parseAnonymous(
                    ptr,
                    buffer,
                    memberInfo,
                    data))) {
                    goto error;
                }
                bptr = buffer;
            }
            break;

        case '}': /* Scope close and end of value */
            if (buffer != bptr) {
                *nonWs = '\0';
                if (memberInfo && (data->type->kind != CORTO_PRIMITIVE)) {
                    if (corto_string_deserParseValue(buffer, memberInfo, data)) {
                        goto error;
                    }
                    bptr = buffer;
                    nonWs = bptr;
                }
            }
            proceed = FALSE;
            ptr--;
            break;

        case '(':
            /* If a value is being parsed, the '(' is part of an argument list.
             * Parse up until the matching ')' */
            if (bptr != buffer) {
                char *start = ptr;

                /* Parse until matching '} */
                do {
                    *bptr = ch;
                    bptr++;
                    ptr++;
                } while((ch = *ptr) && (ch == ')'));

                ptr--;
                nonWs = bptr;

                /* ptr must always end with a '}' */
                if (*ptr != ')') {
                    corto_throw("missing ')' at '%s' (%s)", start, ptr);
                    goto error;
                }
            }


        case '"':
            if (!(ptr = corto_string_deserParseString(ptr, buffer, &bptr))) {
                goto error;
            }
            nonWs = bptr;
            ptr--;
            break;
        case '\'':
            if (!(ptr = corto_string_deserParseCharacter(ptr+1, buffer))) {
                goto error;
            }
            *(++bptr) = '\0';
            nonWs = bptr;
            break;

        case '\n':
        case '\t':
        case ' ':
            if (bptr != buffer) {
                *bptr = ch;
                bptr++;
            }
            break;

        case ',': /* End of value */
            if (buffer != bptr) {
                *nonWs = '\0';
                if (corto_string_deserParseValue(buffer, memberInfo ? memberInfo : info, data)) {
                    goto error;
                }
                bptr = buffer;
                nonWs = bptr;
            }

            /* If memberInfo contains a member, get next member, otherwise it contains
             * an element. The same information applies to each element therefore it is only present
             * once in the index. */
            if (memberInfo) {
                if (memberInfo->m) {
                    memberInfo = corto_string_deserIndexNext(data);
                    if (!memberInfo) {
                        excess = TRUE;
                    }
                }
                data->current++;
            } else {
                /* A comma without memberInfo means that a discriminator of a
                 * union was parsed */
                proceed = FALSE;
            }
            break;
        default:
            *bptr = ch;
            bptr++;
            nonWs = bptr;
            break;
        }
        if (ptr && *ptr) ptr++;
    }

    if (bptr != buffer) {
        struct corto_string_deserIndexInfo info;
        *nonWs = '\0';
        info.type = data->type;
        info.parsed = FALSE;
        info.m = NULL;
        if (corto_string_deserParseValue(buffer, &info, data)) {
            goto error;
        }
    }

    if (excess) {
        corto_throw("excess elements in string");
        goto error;
    }

    return ptr;
error:
    return NULL;
}

/* Deserialize string in object */
corto_string corto_string_deser(corto_string str, corto_string_deser_t* data) {
    corto_char *ptr;
    corto_bool createdNew = FALSE;

    {
        corto_id buffer;
        corto_char *bptr, ch;

        /* Parse typename that potentially precedes string */
        bptr = buffer;
        ptr = str;
        while((ch = *ptr) && (ch != '{')) {
            if (!((ch == ' ') || (ch == '\n') || (ch == '\t'))) {
                *bptr = ch;
                bptr++;
            }
            ptr++;
        }
        *bptr = '\0';

        /* If no type is found, reset ptr */
        if ((ch != '{') || (ptr == str)) {
            ptr = str;
        } else {
            corto_object type;

            /* If no out is provided create an object of the specified type */
            if ((bptr != buffer)) {
                type = corto_resolve(NULL, buffer);
                if (type) {
                    if (data->type && (type != data->type)) {
                        corto_throw(
                          "type of object ('%s') does not match string ('%s')",
                          corto_fullpath(NULL, data->type),
                          corto_fullpath(NULL, type));
                        corto_release(type);
                        goto error;
                    }
                    if (corto_instanceof(corto_type(corto_type_o), type)) {
                        if (!data->out) {
                            data->out = corto_declare(type);
                            createdNew = TRUE;
                        }
                        data->type = type;
                    } else {
                        corto_throw("'%s' is not a type", buffer);
                        corto_release(type);
                        goto error;
                    }
                    corto_release(type);
                } else {
                    corto_throw("unknown type '%s'", buffer);
                    goto error;
                }
            } else {
                type = data->type;
            }

            if (type && (corto_type(type)->kind == CORTO_PRIMITIVE)) {
                ptr++;
            }
        }
    }

    data->current = 0;
    data->index = NULL;
    data->ptr = data->out;
    data->anonymousObjects = NULL;
    data->allocValue = NULL;
    data->allocUdata = NULL;

    if (data->out && data->isObject) {
        if (!data->type) {
            data->type = corto_typeof(data->out);
        } else if (!corto_instanceofType(corto_typeof(data->out), data->type)) {
            corto_throw("object '%s' of type '%s' is not an instance of type '%s'",
                corto_fullpath(NULL, data->out),
                corto_fullpath(NULL, corto_typeof(data->out)),
                corto_fullpath(NULL, data->type));
            goto error;
        }
    }

    if (!data->type) {
        corto_throw("no type provided for '%s'", str);
        goto error;
    }
    
    if (data->type->kind == CORTO_PRIMITIVE) {
        ptr = corto_string_deserParse(ptr, NULL, data);
    } else {
        ptr = corto_string_deserParseScope(ptr, NULL, data);
        if (ptr) {
            ptr ++;
        }
    }

    if (!ptr) {
        corto_throw("failed to deserialize '%s'", str);
        goto error;
    }

    if (data->anonymousObjects) {
        corto_ll_free(data->anonymousObjects);
    }

    return ptr;
error:
    if (data->out) {
        if (createdNew) {
            corto_release(data->out);
        }
        data->out = NULL;
    }
    return NULL;
}
#else
corto_string corto_string_deser(corto_string str, corto_string_deser_t* data) {
    CORTO_UNUSED(str);
    CORTO_UNUSED(data);
    return NULL;
}
#endif
