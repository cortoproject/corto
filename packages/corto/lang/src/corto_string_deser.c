/*
 * corto_string_deser.c
 *
 *  Created on: Sep 5, 2012
 *      Author: sander
 */

#define corto_lang_LIB
#include "corto_string_deser.h"
#include "corto_collection.h"
#include "corto_object.h"
#include "corto_err.h"
#include "corto_util.h"
#include "corto_mem.h"
#include "corto_metawalk.h" /* For building indices required for deserializing */
#include "corto_convert.h"
#include "corto__meta.h"

#ifdef CORTO_CONVERSIONS

struct corto_string_deserIndexInfo {
    corto_member m;
    corto_type type;
    corto_bool parsed;
};

/* Serialize members */
static corto_int16 corto_string_deserBuildIndexComposite(corto_serializer s, corto_value* v, void* userData) {
    corto_int16 result = 0;

    /* Only serialize direct members of object or elements */
    if ((v->kind == CORTO_OBJECT) || (v->kind == CORTO_BASE)) {
        result = corto_serializeMembers(s, v, userData);
    }
    return result;
}

/* Insert info into index */
static void corto_string_deserIndexInsert(corto_string_deser_t* data, struct corto_string_deserIndexInfo* info) {
    if (!data->index) {
        data->index = corto_llNew();
        data->current = 0;
    }
    corto_llAppend(data->index, info);
}

/* Lookup index */
static struct corto_string_deserIndexInfo* corto_string_deserIndexLookup(corto_string member, corto_string_deser_t* data) {
    corto_iter iter;
    struct corto_string_deserIndexInfo* info;
    corto_bool found;

    info = NULL;
    found = FALSE;

    if (data->index) {
        iter = corto_llIter(data->index);

        /* Lookup member in index */
        while(corto_iterHasNext(&iter)) {
            info = corto_iterNext(&iter);

            /* Ambiguous members must always be referenced from their own scope. Even if the current scope does not have a member with the
             * specified name, implicit referencing is not allowed. */
            if (!strcmp(corto_nameof(info->m), member) && (!info->parsed)) {
                found = TRUE;
                data->currentIter = iter;
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
        if (corto_iterHasNext(&data->currentIter)) {
            info = corto_iterNext(&data->currentIter);
        }
    }

    return info;
}

/* Free nodes from index */
int corto_string_deserWalkIndex(void* o, void* udata) {
    CORTO_UNUSED(udata);
    corto_dealloc(o);
    return 1;
}

/* Free index */
void corto_string_deserFreeIndex(corto_string_deser_t* data) {
    if (data->index) {
        corto_llWalk(data->index, corto_string_deserWalkIndex, NULL);
        corto_llFree(data->index);
    }
}

/* Add indexInfo to indextable for each primitive */
static corto_int16 corto_string_deserBuildIndexPrimitive(corto_serializer s, corto_value* v, void* userData) {
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
static corto_int16 corto_string_deserBuildIndexDummy(corto_serializer s, corto_value* v, void* userData) {
    CORTO_UNUSED(s);
    CORTO_UNUSED(v);
    CORTO_UNUSED(userData);
    return 0;
}

/* Serializer that builds indices from type */
static struct corto_serializer_s corto_string_deserBuildIndex_s;
corto_serializer corto_string_deserBuildIndex(void) {
    corto_serializerInit(&corto_string_deserBuildIndex_s);
    /* Add an indexInfo object for each primitive. */
    corto_string_deserBuildIndex_s.program[CORTO_VOID] = corto_string_deserBuildIndexDummy;
    corto_string_deserBuildIndex_s.program[CORTO_PRIMITIVE] = corto_string_deserBuildIndexDummy;
    corto_string_deserBuildIndex_s.program[CORTO_COLLECTION] = corto_string_deserBuildIndexDummy;
    corto_string_deserBuildIndex_s.metaprogram[CORTO_OBJECT] = corto_string_deserBuildIndexComposite;
    corto_string_deserBuildIndex_s.metaprogram[CORTO_BASE] = corto_string_deserBuildIndexComposite;
    corto_string_deserBuildIndex_s.metaprogram[CORTO_MEMBER] = corto_string_deserBuildIndexPrimitive;
    corto_string_deserBuildIndex_s.access = CORTO_LOCAL;
    corto_string_deserBuildIndex_s.accessKind = CORTO_NOT;
    corto_string_deserBuildIndex_s.traceKind = CORTO_SERIALIZER_TRACE_ON_FAIL;
    return &corto_string_deserBuildIndex_s;
}

static corto_string corto_string_deserParse(corto_string str, struct corto_string_deserIndexInfo* info, corto_string_deser_t* data);

void* corto_string_deserAllocElem(void *ptr, void *udata) {
    corto_collection t = udata;
    void *result = NULL;

    switch(t->kind) {
    case CORTO_LIST: {
        corto_ll list = *(corto_ll*)ptr;
        if (corto_collection_elementRequiresAlloc(t)) {
            result = corto_calloc(corto_type_sizeof(t->elementType));
            corto_llAppend(list, result);
        } else {
            corto_llAppend(list, NULL);
            result = corto_llGetPtr(list, corto_llSize(list) - 1);
        }
        break;
    default:
        break;
    }
    }

    return result;
}
/* Parse scope */
static corto_string corto_string_deserParseScope(corto_string str, struct corto_string_deserIndexInfo* info, corto_string_deser_t* data) {
    corto_string_deser_t privateData;
    struct corto_string_deserIndexInfo rootInfo;
    corto_typeKind kind;
    void *ptr = data->ptr;

    if (data->allocValue) {
        ptr = data->allocValue(ptr, data->allocUdata);
    }

    /* Prepare privateData */
    privateData.current = 0;
    privateData.index = NULL;
    privateData.out = data->out;
    privateData.scope = data->scope;
    privateData.anonymousObjects = data->anonymousObjects;
    privateData.type = data->type;
    privateData.allocValue = NULL;
    privateData.allocUdata = NULL;

    /* Offset the scope-members with the current offset */
    if (info && info->m) {
        ptr = CORTO_OFFSET(ptr, info->m->offset);
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

    /* Check if type is composite or collection */
    kind = info->type->kind;
    if ((kind != CORTO_COMPOSITE) && (kind != CORTO_COLLECTION)) {
        corto_id id;
        corto_seterr("'{' unexpected for type '%s'", corto_fullname(info->type, id));
        goto error;
    }

    /* Build index for type */
    if (info->type->kind == CORTO_COMPOSITE) {
        if (corto_metaWalk(corto_string_deserBuildIndex(), info->type, &privateData)) {
            goto error;
        }

        /* Create iterator for index */
        if (privateData.index) {
            privateData.currentIter = corto_llIter(privateData.index);
        }
    /* If type is a collection, build index with one node for element */
    } else {
        struct corto_string_deserIndexInfo *elementNode;
        elementNode = corto_alloc(sizeof(struct corto_string_deserIndexInfo));
        elementNode->m = NULL;
        elementNode->parsed = FALSE;
        elementNode->type = corto_collection(info->type)->elementType;

        /* Insert indexInfo into index */
        corto_string_deserIndexInsert(&privateData, elementNode);

        /* Create iterator for index */
        privateData.currentIter = corto_llIter(privateData.index);
        privateData.allocValue = corto_string_deserAllocElem;
        privateData.allocUdata = info->type;

        switch(corto_collection(info->type)->kind) {
        case CORTO_LIST:
            if (!*(corto_ll*)ptr) {
                *(corto_ll*)ptr = corto_llNew();
            } else {
                corto_llClear(*(corto_ll*)ptr);
            }
            privateData.ptr = ptr;
            break;
        default:
            break;
        }
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
void *corto_string_getDestinationPtr(
    struct corto_string_deserIndexInfo* info, 
    corto_string_deser_t* data) 
{
    void *result = data->ptr;

    if (data->allocValue) {
        result = data->allocValue(result, data->allocUdata);
    }

    if (info->m) {
        result = CORTO_OFFSET(result, info->m->offset);
    }

    return result;
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
    void *offset = corto_string_getDestinationPtr(info, data);

    /* No more elements where available in the index, meaning an excess element */
    if (!info) {
        corto_seterr("excess elements in scope @ '%s'", value);
        goto error;
    }

    /* Can typically occur when mixing short with default notation. */
    if (info->parsed) {
        corto_seterr("member '%s' is already parsed", corto_nameof(info->m));
        goto error;
    }

    /* Only parse references and primitives */
    if (info->type->reference) {
        corto_object o = NULL;
        corto_uint32 index = 0;

        /* Resolve object */
        if (corto_string_deserParseAnonymousId(value, &index)) {
            if (index <= corto_llSize(data->anonymousObjects)) {
                o = corto_llGet(data->anonymousObjects, index - 1);
            } else {
                corto_seterr("undefined anonymous identifier '%s'", value);
                goto error;
            }
        } else {
            o = corto_resolve(data->scope, value);
        }

        if (o || !strcmp(value, "null")) {
            corto_setref(offset, o);
            if (o) corto_release(o);
        } else {
            corto_id id;
            corto_seterr("unresolved reference to '%s' for member '%s'", value, corto_fullname(info->m, id));
            goto error;
        }
    } else

    /* Convert string to primitive value */
    if (info->type->kind == CORTO_PRIMITIVE) {

        if (corto_primitive(info->type)->kind != CORTO_TEXT) {
            if (corto_convert(corto_primitive(corto_string_o), &value, corto_primitive(info->type), offset)) {
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

            if (*(corto_string*)offset) {
                corto_dealloc(*(corto_string*)offset);
            }
            *(corto_string*)offset = deserialized;
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

    *bptr = *ptr;
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
    corto_string_deser_t privateData;
    char *ptr = str;
    char *valuePtr = value;
    corto_uint32 index = 0;

    /* Check if this is a 'named' anonymous object in which case it is 
     * prefixed with <[id]> */
    if ((valuePtr = corto_string_deserParseAnonymousId(valuePtr, &index))) {
        if (data->anonymousObjects && (index <= corto_llSize(data->anonymousObjects))) {
            if (!*valuePtr) {
                o = corto_llGet(data->anonymousObjects, index - 1);
                corto_claim(o);
            } else {
                /* If the <n> is followed up with more data, a new anonymous
                 * object is being created while one existed already with the
                 * specified number */
                corto_seterr("identifier <%d> is already defined (%s)", index, value);
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
            corto_seterr("unresolved type '%s'", valuePtr);
            goto error;
        }

        if (!corto_instanceof(corto_type_o, type)) {
            corto_id id;
            corto_seterr("'%s' is not a type", corto_fullname(type, id));
            goto error;
        }

        o = corto_declare(type);
        if (!o) {
            corto_seterr("failed to declare %s: %s", 
                value,
                corto_lasterr());
            goto error;
        }

        privateData.current = 0;
        privateData.index = NULL;
        privateData.ptr = o;
        privateData.type = type;
        privateData.anonymousObjects = data->anonymousObjects;
        privateData.allocValue = NULL;
        privateData.allocUdata = NULL;

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

        if (corto_define(o)) {
            goto error;
        }

        data->anonymousObjects = privateData.anonymousObjects;

        if (!data->anonymousObjects) {
            data->anonymousObjects = corto_llNew();
        }

        corto_llAppend(data->anonymousObjects, o);
    }

    void *offset = corto_string_getDestinationPtr(info, data);
    corto_setref(offset, o);

    return ptr;
error:
    return NULL;
}

/* Parse string */
static corto_string corto_string_deserParse(corto_string str, struct corto_string_deserIndexInfo* info, corto_string_deser_t* data) {
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
        /* Get first member or element */
        memberInfo = corto_string_deserIndexNext(data);
    }

    /* If ptr == NULL, an error has occurred. If proceed == FALSE, this function has finished processing the
     * current value. */
    while(ptr && (ch = *ptr) && proceed) {
        switch(ch) {
        case '=': /* Explicit member assignment */
            excess = FALSE;
            if (buffer == bptr) {
                corto_seterr("missing member identifier");
                goto error;
            } else {
                *nonWs = '\0';
                memberInfo = corto_string_deserIndexLookup(buffer, data);
                bptr = buffer;
                nonWs = bptr;
                if (!memberInfo) {
                    corto_seterr("member '%s' not found", buffer);
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
                    corto_seterr("missing ')' at '%s' (%s)", start, ptr);
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
        case '}': /* Scope close and end of value*/
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
                if (corto_string_deserParseValue(buffer, memberInfo, data)) {
                    goto error;
                }
                bptr = buffer;
                nonWs = bptr;
            }

            /* If memberInfo contains a member, get next member, otherwise it contains
             * an element. The same information applies to each element therefore it is only present
             * once in the index. */
            if (memberInfo->m) {
                memberInfo = corto_string_deserIndexNext(data);
                if (!memberInfo) {
                    excess = TRUE;
                }
            }
            data->current++;
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
        corto_seterr("excess elements in string");
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
        if ((ch != '{')) {
            ptr = str;
        } else {
            corto_object type;

            /* If no out is provided create an object of the specified type */
            if ((bptr != buffer)) {
                type = corto_resolve(NULL, buffer);
                if (type) {
                    if (data->type && (type != data->type)) {
                        corto_id id1, id2;
                        corto_seterr("type of object ('%s') does not match string ('%s')",
                            corto_fullname(data->type, id1),
                            corto_fullname(type, id2));
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
                        corto_seterr("'%s' is not a type", buffer);
                        corto_release(type);
                        goto error;
                    }
                    corto_release(type);
                } else {
                    corto_seterr("unknown type '%s'", buffer);
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

    if (!data->type) {
        corto_seterr("no type provided for '%s'", str);
        goto error;
    }

    if (!(ptr = corto_string_deserParse(ptr, NULL, data))) {
        if (!corto_lasterr()) {
            corto_seterr("failed to deserialize '%s'", str);
        }
        goto error;
    }

    if (data->anonymousObjects) {
        corto_llFree(data->anonymousObjects);
    }

    return str;
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
