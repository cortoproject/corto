/*
 * db_string_deser.c
 *
 *  Created on: Sep 5, 2012
 *      Author: sander
 */

#include "db_string_deser.h"
#include "db_object.h"
#include "db_err.h"
#include "db_util.h"
#include "db_mem.h"
#include "db_metawalk.h" /* For building indices required for deserializing */
#include "db_convert.h"
#include "db__meta.h"

struct db_string_deserIndexInfo {
    db_member m;
    db_type type;
    db_bool parsed;
};

/* Serialize members */
static db_int16 db_string_deserBuildIndexComposite(db_serializer s, db_value* v, void* userData) {
    db_int16 result = 0;

    /* Only serialize direct members of object or elements */
    if ((v->kind == DB_OBJECT) || (v->kind == DB_BASE)) {
        result = db_serializeMembers(s, v, userData);
    }
    return result;
}

/* Insert info into index */
static void db_string_deserIndexInsert(db_string_deser_t* data, struct db_string_deserIndexInfo* info) {
    if (!data->index) {
        data->index = db_llNew();
        data->current = 0;
    }
    db_llAppend(data->index, info);
}

/* Lookup index */
static struct db_string_deserIndexInfo* db_string_deserIndexLookup(db_string member, db_string_deser_t* data) {
    db_iter iter;
    struct db_string_deserIndexInfo* info;
    db_bool found;

    info = NULL;
    found = FALSE;

    if (data->index) {
        iter = db_llIter(data->index);

        /* Lookup member in index */
        while(db_iterHasNext(&iter)) {
            info = db_iterNext(&iter);

            /* Ambiguous members must always be referenced from their own scope. Even if the current scope does not have a member with the
             * specified name, implicit referencing is not allowed. */
            if (!strcmp(db_nameof(info->m), member) && (!info->parsed)) {
                found = TRUE;
                break;
            }
        }
        if (!found) info = NULL;
    }

    return info;
}

/* Get next member */
static struct db_string_deserIndexInfo* db_string_deserIndexNext(db_string_deser_t* data) {
    struct db_string_deserIndexInfo* info;

    info = NULL;

    if (data->index) {
        if (db_iterHasNext(&data->currentIter)) {
            info = db_iterNext(&data->currentIter);
        }
    }

    return info;
}

/* Free nodes from index */
int db_string_deserWalkIndex(void* o, void* udata) {
	DB_UNUSED(udata);
	db_dealloc(o);
	return 1;
}

/* Free index */
void db_string_deserFreeIndex(db_string_deser_t* data) {
	if (data->index) {
		db_llWalk(data->index, db_string_deserWalkIndex, NULL);
		db_llFree(data->index);
	}
}

/* Add indexInfo to indextable for each primitive */
static db_int16 db_string_deserBuildIndexPrimitive(db_serializer s, db_value* v, void* userData) {
    db_string_deser_t* data;
    struct db_string_deserIndexInfo *newInfo;
    db_member m;

    DB_UNUSED(s);

    data = userData;

    /* Lookup member */
    m = v->is.member.t;

    /* Create new info-object */
    newInfo = db_malloc(sizeof(struct db_string_deserIndexInfo));
    newInfo->m = m;
    newInfo->type = m->type->real;
    newInfo->parsed = FALSE;

    /* Insert indexInfo into index */
    db_string_deserIndexInsert(data, newInfo);

    return 0;
}

/* This function prevents doing unwanted deepwalks of types */
static db_int16 db_string_deserBuildIndexDummy(db_serializer s, db_value* v, void* userData) {
    DB_UNUSED(s);
    DB_UNUSED(v);
    DB_UNUSED(userData);
    return 0;
}

/* Serializer that builds indices from type */
static struct db_serializer_s db_string_deserBuildIndex_s;
db_serializer db_string_deserBuildIndex(void) {
	db_serializerInit(&db_string_deserBuildIndex_s);
    /* Add an indexInfo object for each primitive. */
    db_string_deserBuildIndex_s.program[DB_VOID] = db_string_deserBuildIndexDummy;
    db_string_deserBuildIndex_s.program[DB_PRIMITIVE] = db_string_deserBuildIndexDummy;
    db_string_deserBuildIndex_s.program[DB_COLLECTION] = db_string_deserBuildIndexDummy;
    db_string_deserBuildIndex_s.metaprogram[DB_OBJECT] = db_string_deserBuildIndexComposite;
    db_string_deserBuildIndex_s.metaprogram[DB_BASE] = db_string_deserBuildIndexComposite;
    db_string_deserBuildIndex_s.metaprogram[DB_MEMBER] = db_string_deserBuildIndexPrimitive;
    db_string_deserBuildIndex_s.access = DB_LOCAL;
    db_string_deserBuildIndex_s.accessKind = DB_NOT;
    db_string_deserBuildIndex_s.traceKind = DB_SERIALIZER_TRACE_ON_FAIL;
    return &db_string_deserBuildIndex_s;
}

static db_string db_string_deserParse(db_string str, struct db_string_deserIndexInfo* info, db_string_deser_t* data);

/* Parse scope */
static db_string db_string_deserParseScope(db_string str, struct db_string_deserIndexInfo* info, db_string_deser_t* data) {
    db_string_deser_t privateData;
    struct db_string_deserIndexInfo rootInfo;
    db_typeKind kind;

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
            rootInfo.type = db_typeof(data->out)->real;
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
        db_id id;
        db_error("db_string_deserParseScope: open-scope not valid for type '%s'", db_fullname(info->type, id));
        goto error;
    }

    /* Build index for type */
    if (info->type->kind == DB_COMPOSITE) {
        if (db_metaWalk(db_string_deserBuildIndex(), info->type, &privateData)) {
            goto error;
        }

        /* Create iterator for index */
        if (privateData.index) {
            privateData.currentIter = db_llIter(privateData.index);
        }
    /* If type is a collection, build index with one node for element */
    } else {
        struct db_string_deserIndexInfo *elementNode;
        elementNode = db_malloc(sizeof(struct db_string_deserIndexInfo));
        elementNode->m = NULL;
        elementNode->parsed = FALSE;
        elementNode->type = db_collection(info->type)->elementType->real;

        /* Insert indexInfo into index */
        db_string_deserIndexInsert(&privateData, elementNode);

        /* Create iterator for index */
        privateData.currentIter = db_llIter(privateData.index);
    }

    /* Parse scope */
    if (!(str = db_string_deserParse(str+1, info, &privateData))) {
        goto error;
    }

    db_string_deserFreeIndex(&privateData);

    data->anonymousObjects = privateData.anonymousObjects;

    return str;
error:
    return NULL;
}

/* Parse value */
static db_int16 db_string_deserParseValue(db_string value, struct db_string_deserIndexInfo* info, db_string_deser_t* data) {

    /* No more elements where available in the index, meaning an excess element */
    if (!info) {
        db_error("db_string_deserParseValue: excess elements in scope.");
        goto error;
    }

    /* Can typically occur when mixing short with default notation. */
    if (info->parsed) {
        db_error("db_string_deserParseValue: member '%s' is already parsed.");
    }

    /* Only parse references and primitives */
    if (info->type->reference) {
        db_object o = NULL;

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
            if (data->anonymousObjects && (index <= db_llSize(data->anonymousObjects))) {
                o = db_llGet(data->anonymousObjects, index-1);
                db_assert(db_llSize(data->anonymousObjects) == index, "objects are not ordered equal to ordering in serializer");
            }
            value = ptr;
        }

        if (!o) {
            /* Resolve object */
            o = db_resolve_ext(NULL, data->scope, value, FALSE, "Resolve object for anonymous object");
        }

        if (o) {
            db_set_ext(data->out, DB_OFFSET(data->ptr, info->m->offset), o, "Set object for anonymous object");
            db_free_ext(NULL, o, "Free object for anonymous object");
        } else {
            db_id id;
            db_error("db_string_deserParseValue: unresolved reference to '%s' for member '%s'", value, db_fullname(info->m, id));
            goto error;
        }

        if (!data->anonymousObjects) {
            data->anonymousObjects = db_llNew();
            db_llAppend(data->anonymousObjects, o);
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

    	if (db_primitive(info->type)->kind != DB_TEXT) {
			if (db_convert(db_primitive(db_string_o), &value, db_primitive(info->type), offset)) {
				goto error;
			}
    	} else {
    		db_uint32 length;
    		db_string deserialized;

    		if (strcmp(value, "null")) {
				length = strlen(value);
				deserialized = db_malloc(length+1);
				memcpy(deserialized, value, length);
				deserialized[length] = '\0';
    		} else {
    			deserialized = NULL;
    		}

    		if (*(db_string*)offset) {
    		    db_dealloc(*(db_string*)offset);
    		}
    		*(db_string*)offset = deserialized;
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
static db_string db_string_deserParseCharacter(db_string ptr, db_char *bptr) {
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
            printf("db_string_deserParseString: invalid escape sequence '%c'",  *ptr);
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
static db_string db_string_deserParseString(db_string ptr, db_string buffer, db_string *bufferPtr) {
    db_char ch, *bptr;

    ptr++; /* Skip first '"' */
    bptr = buffer;
    while((ch = *ptr) && (ch != '"')) {
        ptr = db_string_deserParseCharacter(ptr, bptr);
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
static db_string db_string_deserParse(db_string str, struct db_string_deserIndexInfo* info, db_string_deser_t* data) {
    db_char ch;
    db_char *ptr, *bptr;
    db_char buffer[DB_STRING_DESER_TOKEN_MAX];
    db_bool proceed;
    struct db_string_deserIndexInfo* memberInfo;

    DB_UNUSED(info);

    ptr = str;
    bptr = buffer;
    proceed = TRUE;
    memberInfo = NULL;

    if (info) {
        /* Get first member or element */
        memberInfo = db_string_deserIndexNext(data);
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
            memberInfo = db_string_deserIndexLookup(buffer, data);
            bptr = buffer;
            if (!memberInfo) {
                db_error("db_string_deserParse: member '%s' not found.", buffer);
                goto error;
            }
            break;

        case '{': /* Scope open */

        	/* If a value is being parsed, the '{' is part of a nested anonymous
        	 * object. Parse up until the '}' */
        	if (bptr == buffer) {
        		ptr = db_string_deserParseScope(ptr, memberInfo, data);
        	} else {
        		db_uint32 count;
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
        			db_error("db_string_deser: missing '}' in string '%s'", str);
        			goto error;
        		}
        	}
            break;
        case '"':
            if (!(ptr = db_string_deserParseString(ptr, buffer, &bptr))) {
                goto error;
            }
            ptr--;
            break;
        case '\'':
            if (!(ptr = db_string_deserParseCharacter(ptr+1, buffer))) {
                goto error;
            }
            *(++bptr) = '\0';
            break;
        case '}': /* Scope close and end of value*/
            *bptr = '\0';
            if (db_string_deserParseValue(buffer, memberInfo, data)) {
                goto error;
            }
            proceed = FALSE;
            break;
        case ',': /* End of value */
            *bptr = '\0';
            if (db_string_deserParseValue(buffer, memberInfo, data)) {
                goto error;
            }
            bptr = buffer;

            /* If memberInfo contains a member, get next member, otherwise it contains
             * an element. The same information applies to each element therefore it is only present
             * once in the index. */
            if (memberInfo->m) {
                memberInfo = db_string_deserIndexNext(data);
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
db_string db_string_deser(db_string str, db_string_deser_t* data) {
    db_char *ptr;
    {
        db_id buffer;
        db_char *bptr, ch;

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
            db_object type;

            /* If no out is provided create an object of the specified type */
            type = db_resolve(NULL, buffer);
            if (type) {
                if (db_instanceof(db_typedef(db_typedef_o), type)) {
                    data->out = db_new(db_typedef(type));
                } else {
                    db_error("db_string_deser: specified type-identifier '%s' is not a type", buffer);
                    db_free(type);
                    goto error;
                }
                db_free(type);
            } else {
                db_error("db_string_deser: cannot resolve specified type-identifier '%s'", buffer);
                goto error;
            }
        }
    }

    data->current = 0;
    data->index = NULL;
    data->ptr = data->out;
    data->anonymousObjects = NULL;

    /* Start parsing string */
    if (!(ptr = db_string_deserParse(ptr, NULL, data))) {
        goto error;
    }

    if (data->anonymousObjects) {
        db_llFree(data->anonymousObjects);
    }

    return str;
error:
    db_error("failed to deserialize '%s'", str);
    if (data->out) {
        db_free(data->out);
        data->out = NULL;
    }
    return NULL;
}
