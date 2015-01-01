/*
 * cx_string_deser.c
 *
 *  Created on: Sep 5, 2012
 *      Author: sander
 */

#include "cx_string_deser.h"
#include "cx_object.h"
#include "cx_err.h"
#include "cx_util.h"
#include "cx_mem.h"
#include "cx_metawalk.h" /* For building indices required for deserializing */
#include "cx_convert.h"
#include "cx__meta.h"

struct cx_string_deserIndexInfo {
    cx_member m;
    cx_type type;
    cx_bool parsed;
};

/* Serialize members */
static cx_int16 cx_string_deserBuildIndexComposite(cx_serializer s, cx_value* v, void* userData) {
    cx_int16 result = 0;

    /* Only serialize direct members of object or elements */
    if ((v->kind == DB_OBJECT) || (v->kind == DB_BASE)) {
        result = cx_serializeMembers(s, v, userData);
    }
    return result;
}

/* Insert info into index */
static void cx_string_deserIndexInsert(cx_string_deser_t* data, struct cx_string_deserIndexInfo* info) {
    if (!data->index) {
        data->index = cx_llNew();
        data->current = 0;
    }
    cx_llAppend(data->index, info);
}

/* Lookup index */
static struct cx_string_deserIndexInfo* cx_string_deserIndexLookup(cx_string member, cx_string_deser_t* data) {
    cx_iter iter;
    struct cx_string_deserIndexInfo* info;
    cx_bool found;

    info = NULL;
    found = FALSE;

    if (data->index) {
        iter = cx_llIter(data->index);

        /* Lookup member in index */
        while(cx_iterHasNext(&iter)) {
            info = cx_iterNext(&iter);

            /* Ambiguous members must always be referenced from their own scope. Even if the current scope does not have a member with the
             * specified name, implicit referencing is not allowed. */
            if (!strcmp(cx_nameof(info->m), member) && (!info->parsed)) {
                found = TRUE;
                break;
            }
        }
        if (!found) info = NULL;
    }

    return info;
}

/* Get next member */
static struct cx_string_deserIndexInfo* cx_string_deserIndexNext(cx_string_deser_t* data) {
    struct cx_string_deserIndexInfo* info;

    info = NULL;

    if (data->index) {
        if (cx_iterHasNext(&data->currentIter)) {
            info = cx_iterNext(&data->currentIter);
        }
    }

    return info;
}

/* Free nodes from index */
int cx_string_deserWalkIndex(void* o, void* udata) {
	DB_UNUSED(udata);
	cx_dealloc(o);
	return 1;
}

/* Free index */
void cx_string_deserFreeIndex(cx_string_deser_t* data) {
	if (data->index) {
		cx_llWalk(data->index, cx_string_deserWalkIndex, NULL);
		cx_llFree(data->index);
	}
}

/* Add indexInfo to indextable for each primitive */
static cx_int16 cx_string_deserBuildIndexPrimitive(cx_serializer s, cx_value* v, void* userData) {
    cx_string_deser_t* data;
    struct cx_string_deserIndexInfo *newInfo;
    cx_member m;

    DB_UNUSED(s);

    data = userData;

    /* Lookup member */
    m = v->is.member.t;

    /* Create new info-object */
    newInfo = cx_malloc(sizeof(struct cx_string_deserIndexInfo));
    newInfo->m = m;
    newInfo->type = m->type->real;
    newInfo->parsed = FALSE;

    /* Insert indexInfo into index */
    cx_string_deserIndexInsert(data, newInfo);

    return 0;
}

/* This function prevents doing unwanted deepwalks of types */
static cx_int16 cx_string_deserBuildIndexDummy(cx_serializer s, cx_value* v, void* userData) {
    DB_UNUSED(s);
    DB_UNUSED(v);
    DB_UNUSED(userData);
    return 0;
}

/* Serializer that builds indices from type */
static struct cx_serializer_s cx_string_deserBuildIndex_s;
cx_serializer cx_string_deserBuildIndex(void) {
	cx_serializerInit(&cx_string_deserBuildIndex_s);
    /* Add an indexInfo object for each primitive. */
    cx_string_deserBuildIndex_s.program[DB_VOID] = cx_string_deserBuildIndexDummy;
    cx_string_deserBuildIndex_s.program[DB_PRIMITIVE] = cx_string_deserBuildIndexDummy;
    cx_string_deserBuildIndex_s.program[DB_COLLECTION] = cx_string_deserBuildIndexDummy;
    cx_string_deserBuildIndex_s.metaprogram[DB_OBJECT] = cx_string_deserBuildIndexComposite;
    cx_string_deserBuildIndex_s.metaprogram[DB_BASE] = cx_string_deserBuildIndexComposite;
    cx_string_deserBuildIndex_s.metaprogram[DB_MEMBER] = cx_string_deserBuildIndexPrimitive;
    cx_string_deserBuildIndex_s.access = DB_LOCAL;
    cx_string_deserBuildIndex_s.accessKind = DB_NOT;
    cx_string_deserBuildIndex_s.traceKind = DB_SERIALIZER_TRACE_ON_FAIL;
    return &cx_string_deserBuildIndex_s;
}

static cx_string cx_string_deserParse(cx_string str, struct cx_string_deserIndexInfo* info, cx_string_deser_t* data);

/* Parse scope */
static cx_string cx_string_deserParseScope(cx_string str, struct cx_string_deserIndexInfo* info, cx_string_deser_t* data) {
    cx_string_deser_t privateData;
    struct cx_string_deserIndexInfo rootInfo;
    cx_typeKind kind;

    /* Prepare privateData */
    privateData.current = 0;
    privateData.index = NULL;
    privateData.out = data->out;
    privateData.scope = data->scope;
    privateData.anonymousObjects = data->anonymousObjects;

    /* Offset the scope-members with the current offset */
    if (info) {
        privateData.ptr = DB_OFFSET(data->ptr, info->m->offset);
    } else {
        privateData.ptr = data->ptr;
    }

    /* Open scope of type */
    if (!info) {
        if (!data->type) {
            rootInfo.type = cx_typeof(data->out)->real;
        } else {
            rootInfo.type = data->type;
        }
        rootInfo.m = NULL;
        rootInfo.parsed = FALSE;
        info = &rootInfo;
    }

    /* Check if type is composite or collection */
    kind = info->type->kind;
    if ((kind != DB_COMPOSITE) && (kind != DB_COLLECTION)) {
        cx_id id;
        cx_error("cx_string_deserParseScope: open-scope not valid for type '%s'", cx_fullname(info->type, id));
        goto error;
    }

    /* Build index for type */
    if (info->type->kind == DB_COMPOSITE) {
        if (cx_metaWalk(cx_string_deserBuildIndex(), info->type, &privateData)) {
            goto error;
        }

        /* Create iterator for index */
        if (privateData.index) {
            privateData.currentIter = cx_llIter(privateData.index);
        }
    /* If type is a collection, build index with one node for element */
    } else {
        struct cx_string_deserIndexInfo *elementNode;
        elementNode = cx_malloc(sizeof(struct cx_string_deserIndexInfo));
        elementNode->m = NULL;
        elementNode->parsed = FALSE;
        elementNode->type = cx_collection(info->type)->elementType->real;

        /* Insert indexInfo into index */
        cx_string_deserIndexInsert(&privateData, elementNode);

        /* Create iterator for index */
        privateData.currentIter = cx_llIter(privateData.index);
    }

    /* Parse scope */
    if (!(str = cx_string_deserParse(str+1, info, &privateData))) {
        goto error;
    }

    cx_string_deserFreeIndex(&privateData);

    data->anonymousObjects = privateData.anonymousObjects;

    return str;
error:
    return NULL;
}

/* Parse value */
static cx_int16 cx_string_deserParseValue(cx_string value, struct cx_string_deserIndexInfo* info, cx_string_deser_t* data) {

    /* No more elements where available in the index, meaning an excess element */
    if (!info) {
        cx_error("cx_string_deserParseValue: excess elements in scope.");
        goto error;
    }

    /* Can typically occur when mixing short with default notation. */
    if (info->parsed) {
        cx_error("cx_string_deserParseValue: member '%s' is already parsed.");
    }

    /* Only parse references and primitives */
    if (info->type->reference) {
        cx_object o = NULL;

        /* Check if object is anonymous in which case it is prefixed with <[id]> */
        if (*value == '<') {
            char buf[15], *ptr, *bptr, ch;
            int index;

            ptr = value;
            bptr = buf;
            while((ch = *ptr) && (ch != '>')) {
                *bptr = ch;
                bptr++;
                ptr++;
            }
            *bptr = '\0';
            ptr++;

            index = atoi(buf);
            if (data->anonymousObjects && (index <= cx_llSize(data->anonymousObjects))) {
                o = cx_llGet(data->anonymousObjects, index-1);
                cx_assert(cx_llSize(data->anonymousObjects) == index, "objects are not ordered equal to ordering in serializer");
            }
            value = ptr;
        }

        if (!o) {
            /* Resolve object */
            o = cx_resolve_ext(NULL, data->scope, value, FALSE, "Resolve object for anonymous object");
        }

        if (o) {
            cx_set_ext(data->out, DB_OFFSET(data->ptr, info->m->offset), o, "Set object for anonymous object");
            cx_free_ext(NULL, o, "Free object for anonymous object");
        } else {
            cx_id id;
            cx_error("cx_string_deserParseValue: unresolved reference to '%s' for member '%s'", value, cx_fullname(info->m, id));
            goto error;
        }

        if (!data->anonymousObjects) {
            data->anonymousObjects = cx_llNew();
            cx_llAppend(data->anonymousObjects, o);
        }
    } else

    /* Convert string to primitive value */
    if (info->type->kind == DB_PRIMITIVE) {
        void *offset;

        if (info->m) {
            offset = DB_OFFSET(data->ptr, info->m->offset);
        } else {
            offset = DB_OFFSET(data->ptr, data->current * info->type->size);
        }

    	if (cx_primitive(info->type)->kind != DB_TEXT) {
			if (cx_convert(cx_primitive(cx_string_o), &value, cx_primitive(info->type), offset)) {
				goto error;
			}
    	} else {
    		cx_uint32 length;
    		cx_string deserialized;

    		if (strcmp(value, "null")) {
				length = strlen(value);
				deserialized = cx_malloc(length+1);
				memcpy(deserialized, value, length);
				deserialized[length] = '\0';
    		} else {
    			deserialized = NULL;
    		}

    		if (*(cx_string*)offset) {
    		    cx_dealloc(*(cx_string*)offset);
    		}
    		*(cx_string*)offset = deserialized;
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
static cx_string cx_string_deserParseCharacter(cx_string ptr, cx_char *bptr) {
    if (*ptr == '\\') {
        switch(*(++ptr)) {
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
        case '\'':
            *bptr = '\'';
            break;
        case '"':
            *bptr = '"';
            break;
        case '\\':
            *bptr = '\\';
            break;
        case '?':
            *bptr = '?';
            break;
        default:
            printf("cx_string_deserParseString: invalid escape sequence '%c'",  *ptr);
            goto error;
            break;
        }
    } else {
        *bptr = *ptr;
    }
    ptr++;

    return ptr;
error:
    return NULL;
}

/* Parse string literal */
static cx_string cx_string_deserParseString(cx_string ptr, cx_string buffer, cx_string *bufferPtr) {
    cx_char ch, *bptr;

    ptr++; /* Skip first '"' */
    bptr = buffer;
    while((ch = *ptr) && (ch != '"')) {
        ptr = cx_string_deserParseCharacter(ptr, bptr);
        bptr++;
    }
    if (ch) {
        ptr++; /* Skip last '"' */
    }

    *bptr = '\0';

    *bufferPtr = bptr;

    return ptr;
}

/* Parse string */
static cx_string cx_string_deserParse(cx_string str, struct cx_string_deserIndexInfo* info, cx_string_deser_t* data) {
    cx_char ch;
    cx_char *ptr, *bptr;
    cx_char buffer[DB_STRING_DESER_TOKEN_MAX];
    cx_bool proceed;
    struct cx_string_deserIndexInfo* memberInfo;

    DB_UNUSED(info);

    ptr = str;
    bptr = buffer;
    proceed = TRUE;
    memberInfo = NULL;

    if (info) {
        /* Get first member or element */
        memberInfo = cx_string_deserIndexNext(data);
    }

    /* If ptr == NULL, an error has occurred. If proceed == FALSE, this function has finished processing the
     * current value. */
    while(ptr && (ch=*ptr) && proceed) {
        switch(ch) {
        case '\n':
        case '\t':
            break; /* Whitespaces are ignored */

        case '=': /* Explicit member assignment */
            *bptr = '\0';
            memberInfo = cx_string_deserIndexLookup(buffer, data);
            bptr = buffer;
            if (!memberInfo) {
                cx_error("cx_string_deserParse: member '%s' not found.", buffer);
                goto error;
            }
            break;

        case '{': /* Scope open */

        	/* If a value is being parsed, the '{' is part of a nested anonymous
        	 * object. Parse up until the '}' */
        	if (bptr == buffer) {
        		ptr = cx_string_deserParseScope(ptr, memberInfo, data);
        	} else {
        		cx_uint32 count;
        		count = 0;

        		/* Parse until matching '} */
        		do {
        			*bptr = ch;
        			bptr++;
        			ptr++;
        			if (ch == '{') {
        				count++;
        			} else if (ch == '}') {
        				count--;
        			}
        		}while((ch = *ptr) && count);
        		ptr--;

        		/* ptr must always end with a '}' */
        		if (*ptr != '}') {
        			cx_error("cx_string_deser: missing '}' in string '%s'", str);
        			goto error;
        		}
        	}
            break;
        case '"':
            if (!(ptr = cx_string_deserParseString(ptr, buffer, &bptr))) {
                goto error;
            }
            ptr--;
            break;
        case '\'':
            if (!(ptr = cx_string_deserParseCharacter(ptr+1, buffer))) {
                goto error;
            }
            *(++bptr) = '\0';
            break;
        case '}': /* Scope close and end of value*/
            *bptr = '\0';
            if (cx_string_deserParseValue(buffer, memberInfo, data)) {
                goto error;
            }
            proceed = FALSE;
            break;
        case ',': /* End of value */
            *bptr = '\0';
            if (cx_string_deserParseValue(buffer, memberInfo, data)) {
                goto error;
            }
            bptr = buffer;

            /* If memberInfo contains a member, get next member, otherwise it contains
             * an element. The same information applies to each element therefore it is only present
             * once in the index. */
            if (memberInfo->m) {
                memberInfo = cx_string_deserIndexNext(data);
            }
            data->current++;
            break;
        default:
            *bptr = ch;
            bptr++;
            break;
        }
        if (ptr && *ptr) ptr++;
    }

    return ptr;
error:
    return NULL;
}

/* Deserialize string in object */
cx_string cx_string_deser(cx_string str, cx_string_deser_t* data) {
    cx_char *ptr;
    {
        cx_id buffer;
        cx_char *bptr, ch;

        /* Parse typename that potentially precedes string */
        bptr = buffer;
        ptr = str;
        while((ch = *ptr) && (ch != '{')) {
            *bptr = ch;
            bptr++;
            ptr++;
        }
        *bptr = '\0';

        if (!data->out) {
            cx_object type;

            /* If no out is provided create an object of the specified type */
            type = cx_resolve(NULL, buffer);
            if (type) {
                if (cx_instanceof(cx_typedef(cx_typedef_o), type)) {
                    data->out = cx_new(cx_typedef(type));
                } else {
                    cx_error("cx_string_deser: specified type-identifier '%s' is not a type", buffer);
                    cx_free(type);
                    goto error;
                }
                cx_free(type);
            } else {
                cx_error("cx_string_deser: cannot resolve specified type-identifier '%s'", buffer);
                goto error;
            }
        }
    }

    data->current = 0;
    data->index = NULL;
    data->ptr = data->out;
    data->anonymousObjects = NULL;

    /* Start parsing string */
    if (!(ptr = cx_string_deserParse(ptr, NULL, data))) {
        goto error;
    }

    if (data->anonymousObjects) {
        cx_llFree(data->anonymousObjects);
    }

    return str;
error:
    cx_error("failed to deserialize '%s'", str);
    if (data->out) {
        cx_free(data->out);
        data->out = NULL;
    }
    return NULL;
}
