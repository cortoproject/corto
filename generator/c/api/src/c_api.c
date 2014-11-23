/*
 * c_api.c
 *
 *  Created on: Oct 10, 2012
 *      Author: sander
 */

#include "hyve.h"
#include "db_generator.h"
#include "c_common.h"
#include "db_serializer.h"
#include "db_generatorDepWalk.h"

typedef struct c_apiWalk_t {
    db_generator g;
    g_file header;
    g_file source;
    db_object current;
    db_uint32 parameterCount;
    db_ll memberCache;
    db_ll collections;
}c_apiWalk_t;

/* Translate members to function parameters. */
static db_int16 c_apiAssignMember(db_serializer s, db_value* v, void* userData) {
    c_apiWalk_t* data;
    db_member m;
    db_id memberIdTmp, memberParamId, memberId;

    DB_UNUSED(s);

    if (v->kind == DB_MEMBER) {
        m = v->is.member.t;
        data = userData;

        db_genMemberName(data->g, data->memberCache, m, memberIdTmp);
        g_id(data->g, memberIdTmp, memberParamId);
        g_id(data->g, db_nameof(m), memberId);

        /* Keep references */
        if (m->type->real->reference) {
            if (!m->weak) {
                db_id id;
                g_fileWrite(data->source, "%s ? db_keep_ext(_this, %s, \"%s\") : 0; ", memberParamId, memberParamId, db_valueString(v,id, 256));
            }
        }

        /* If member is of array-type, use memcpy */
        if ((m->type->real->kind == DB_COLLECTION) && (db_collection(m->type->real)->kind == DB_ARRAY)) {
            db_id typeId, postfix;
    		/* Get typespecifier */
    		if (c_specifierId(data->g, m->type, typeId, NULL, postfix)) {
    			goto error;
    		}
            g_fileWrite(data->source, "memcpy(");

            /* Cast object to right type */
            if (data->current == db_parentof(m)) {
                g_fileWrite(data->source, "_this->%s",
                        db_nameof(m));
            } else {
                db_id typeId;
                g_fileWrite(data->source, "%s(_this)->%s",
                        g_fullOid(data->g, db_parentof(m), typeId), db_nameof(m));
            }

            g_fileWrite(data->source, ", %s, sizeof(%s%s));\n", memberParamId, typeId, postfix);
        } else {
            /* Cast object to right type */
            if (data->current == db_parentof(m)) {
                g_fileWrite(data->source, "_this->%s = ",
                        db_nameof(m));
            } else {
                db_id typeId;
                g_fileWrite(data->source, "%s(_this)->%s = ",
                        g_fullOid(data->g, db_parentof(m), typeId), db_nameof(m));
            }

            /* Strdup strings */
            if ((m->type->real->kind == DB_PRIMITIVE) && (db_primitive(m->type->real)->kind == DB_TEXT)) {
                g_fileWrite(data->source, "(%s ? db_strdup(%s) : NULL);\n", memberParamId, memberParamId);
            } else {
                g_fileWrite(data->source, "%s;\n", memberParamId);
            }
        }

        data->parameterCount++;
    }

    return 0;
error:
	return -1;
}

/* Translate members to function parameters. */
static db_int16 c_apiParamMember(db_serializer s, db_value* v, void* userData) {
    c_apiWalk_t* data;
    db_member m;
    db_id typeSpec, typePostfix, memberIdTmp, memberId;

    DB_UNUSED(s);

    if (v->kind == DB_MEMBER) {
        m = v->is.member.t;
        data = userData;

        if (data->parameterCount) {
            g_fileWrite(data->header, ", ");
            g_fileWrite(data->source, ", ");
        }

        /* Get type-specifier */
        c_specifierId(data->g, m->type, typeSpec, NULL, typePostfix);
        db_genMemberName(data->g, data->memberCache, m, memberIdTmp);

        g_fileWrite(data->header, "%s%s %s",
               typeSpec, typePostfix, g_id(data->g, memberIdTmp, memberId));

        g_fileWrite(data->source, "%s%s %s",
                typeSpec, typePostfix, g_id(data->g, memberIdTmp, memberId));

        data->parameterCount++;
    }

    return 0;
}

/* Member parameter serializer */
static struct db_serializer_s c_apiParamSerializer(void) {
    struct db_serializer_s s;

    db_serializerInit(&s);
    s.metaprogram[DB_MEMBER] = c_apiParamMember;
    s.access = DB_LOCAL|DB_READONLY|DB_PRIVATE;
    s.accessKind = DB_NOT;

    return s;
}

/* Member parameter serializer */
static struct db_serializer_s c_apiAssignSerializer(void) {
    struct db_serializer_s s;

    db_serializerInit(&s);
    s.metaprogram[DB_MEMBER] = c_apiAssignMember;
    s.access = DB_LOCAL|DB_READONLY|DB_PRIVATE;
    s.accessKind = DB_NOT;

    return s;
}

/* Create new-function */
static db_int16 c_apiReferenceTypeNew(db_interface o, c_apiWalk_t* data) {
    db_id id;

    g_fullOid(data->g, o, id);

    /* Function declaration */
    g_fileWrite(data->header, "%s %s__new(void);\n", id, id);

    /* Function implementation */
    g_fileWrite(data->source, "%s %s__new(void) {\n", id, id);
    g_fileIndent(data->source);
    g_fileWrite(data->source, "return db_new(db_typedef(%s_o));\n", id);
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");

    return 0;
}

/* Create declare-function */
static db_int16 c_apiReferenceTypeDeclare(db_interface o, c_apiWalk_t* data) {
    db_id id;

    g_fullOid(data->g, o, id);

    /* Function declaration */
    g_fileWrite(data->header, "%s %s__declare(db_object _parent, db_string _name);\n", id, id);

    /* Function implementation */
    g_fileWrite(data->source, "%s %s__declare(db_object _parent, db_string _name) {\n", id, id);
    g_fileIndent(data->source);
    g_fileWrite(data->source, "return db_declare(_parent, _name, db_typedef(%s_o));\n", id);
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");

    return 0;
}

/* Create define-function */
static db_int16 c_apiReferenceTypeDefine(db_interface o, c_apiWalk_t* data) {
    db_id id;
    struct db_serializer_s s;

    g_fullOid(data->g, o, id);

    /* Function declaration */
    g_fileWrite(data->header, "int %s__define(%s _this", id, id);

    /* Function implementation */
    g_fileWrite(data->source, "int %s__define(%s _this", id, id);

    /* Write public members as arguments for source and header */
    data->parameterCount = 1;
    s = c_apiParamSerializer();
    db_metaWalk(&s, db_type(o), data);

    /* Write closing brackets for argumentlist in source and header */
    g_fileWrite(data->header, ");\n");
    g_fileWrite(data->source, ") {\n");
    g_fileIndent(data->source);

    /* Member assignments */
    s = c_apiAssignSerializer();
    db_metaWalk(&s, db_type(o), data);

    g_fileWrite(data->source, "return db_define(_this);\n");
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");

    return 0;
}

/* Create create-function */
static db_int16 c_apiReferenceTypeCreate(db_interface o, c_apiWalk_t* data) {
    db_id id;
    struct db_serializer_s s;

    g_fullOid(data->g, o, id);

    /* Function declaration */
    g_fileWrite(data->header, "%s %s__create(", id, id);

    /* Function implementation */
    g_fileWrite(data->source, "%s %s__create(", id, id);

    /* Write public members as arguments for source and header */
    data->parameterCount = 0;
    s = c_apiParamSerializer();
    db_metaWalk(&s, db_type(o), data);

    /* If there are no parameters, write 'void' */
    if (!data->parameterCount) {
        g_fileWrite(data->header, "void");
        g_fileWrite(data->source, "void");
    }

    /* Write closing brackets for argumentlist in source and header */
    g_fileWrite(data->header, ");\n");
    g_fileWrite(data->source, ") {\n");

    g_fileIndent(data->source);
    g_fileWrite(data->source, "%s _this;\n", id);
    g_fileWrite(data->source, "_this = db_new(db_typedef(%s_o));\n", id);

    /* Member assignments */
    s = c_apiAssignSerializer();
    db_metaWalk(&s, db_type(o), data);

    /* Define object */
    g_fileWrite(data->source, "if (db_define(_this)) {\n");
    g_fileIndent(data->source);
    g_fileWrite(data->source, "db_free(_this);\n");
    g_fileWrite(data->source, "_this = NULL;\n");
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n");

    g_fileWrite(data->source, "return _this;\n");
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");

    return 0;
}

/* Walk class */
static db_int16 c_apiWalkReferenceType(db_interface o, c_apiWalk_t* data) {
    db_id id;

    g_fileWrite(data->header, "/* %s */\n", db_fullname(o, id));

    data->current = o;

    /* Build nameconflict cache */
    data->memberCache = db_genMemberCacheBuild(o);

    /* Generate _new function */
    if (c_apiReferenceTypeNew(o, data)) {
        goto error;
    }

    /* Generate _declare function */
    if (c_apiReferenceTypeDeclare(o, data)) {
        goto error;
    }

    /* Generate _define function */
    if (c_apiReferenceTypeDefine(o, data)) {
        goto error;
    }

    /* Generate _create function */
    if (c_apiReferenceTypeCreate(o, data)) {
        goto error;
    }

    db_genMemberCacheClean(data->memberCache);

    g_fileWrite(data->header, "\n");

    return 0;
error:
    return -1;
}

static db_bool c_apiElementRequiresInit(db_type elementType) {
    db_bool result = FALSE;

    if ((elementType->kind != DB_PRIMITIVE) && !elementType->reference) {
        result = TRUE;
    }

    return result;
}

/* Initialize or deinitialize element */
static db_int16 c_apiElementInit(db_string elementType, db_string element, db_bool isInit, c_apiWalk_t* data) {
    g_fileWrite(data->source, "{\n");
    g_fileIndent(data->source);
    g_fileWrite(data->source, "db_value v;\n");
    g_fileWrite(data->source, "v.kind = DB_VALUE;\n");
    g_fileWrite(data->source, "v.is.value.o = NULL;\n");
    g_fileWrite(data->source, "v.is.value.t = db_typedef(%s_o);\n", elementType);
    g_fileWrite(data->source, "v.is.value.v = %s;\n", element);
    if (isInit) {
        g_fileWrite(data->source, "db_initValue(&v);\n");
    } else {
        g_fileWrite(data->source, "db_deinitValue(&v);\n");
    }
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n");
    
    return 0;
}

/* Create sequence foreach-macro */
static db_int16 c_apiSequenceTypeForeach(db_sequence o, c_apiWalk_t* data) {
    db_id id, elementId;
    db_bool prefix;
    db_type elementType = db_collection(o)->elementType->real;
    
    c_specifierId(data->g, db_typedef(o), id, NULL, NULL);
    c_specifierId(data->g, db_typedef(elementType), elementId, &prefix, NULL);
    
    /* Macro */
    g_fileWrite(data->header, "#define %s__foreach(seq, elem) \\\n", id);
    g_fileIndent(data->header);
    g_fileWrite(data->header, "db_uint32 elem##_iter;\\\n");
    g_fileWrite(data->header, "%s %selem;\\\n", elementId, prefix?"*":"");
    g_fileWrite(data->header, "for(elem##_iter=0; elem##_iter<seq.length; elem##_iter++) {\\\n");
    g_fileIndent(data->header);
    g_fileWrite(data->header, "elem = &seq.buffer[elem##_iter];\n");
    g_fileDedent(data->header);
    g_fileDedent(data->header);
    g_fileWrite(data->header, "\n");
    
    return 0;
}

/* Create append-function */
static db_int16 c_apiSequenceTypeAppend(db_sequence o, c_apiWalk_t* data) {
    db_id id, elementId;
    db_bool prefix;
    db_type elementType = db_collection(o)->elementType->real;
    
    c_specifierId(data->g, db_typedef(o), id, NULL, NULL);
    c_specifierId(data->g, db_typedef(elementType), elementId, &prefix, NULL);

    /* Function declaration */
    g_fileWrite(data->header, "%s%s %s__append(%s *seq);\n", elementId, prefix?"*":"", id, id);
    
    /* Function implementation */
    g_fileWrite(data->source, "%s%s %s__append(%s *seq) {\n", elementId, prefix?"*":"", id, id);
    
    g_fileIndent(data->source);
    g_fileWrite(data->source, "db_uint32 size;\n");
    g_fileWrite(data->source, "seq->length++;\n");
    g_fileWrite(data->source, "seq->buffer = db_realloc(seq->buffer, seq->length * (size=db_type_sizeof(db_type(%s_o))));\n", elementId);
    g_fileWrite(data->source, "memset(%sseq->buffer[seq->length-1], 0, size);\n", elementType->reference?"":"&");
    if (c_apiElementRequiresInit(elementType)) {
        if (elementType->reference) {
            c_apiElementInit(elementId, "seq->buffer[seq->length-1]", TRUE, data);
        } else {
            c_apiElementInit(elementId, "&seq->buffer[seq->length-1]", TRUE, data);
        }
    }
    g_fileWrite(data->source, "return %sseq->buffer[seq->length-1];\n", elementType->reference?"":"&");
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");
    
    return 0;
}

/* Create size-function */
static db_int16 c_apiSequenceTypeSize(db_sequence o, c_apiWalk_t* data) {
    db_id id, elementId;
    db_bool prefix;
    db_type elementType = db_collection(o)->elementType->real;
    
    c_specifierId(data->g, db_typedef(o), id, NULL, NULL);
    c_specifierId(data->g, db_typedef(elementType), elementId, &prefix, NULL);
    
    /* Function declaration */
    g_fileWrite(data->header, "void %s__size(%s *seq, db_uint32 length);\n", id, id);
    
    /* Function implementation */
    g_fileWrite(data->source, "void %s__size(%s *seq, db_uint32 length) {\n", id, id);
    g_fileIndent(data->source);
    g_fileWrite(data->source, "db_uint32 size;\n");
    
    /* Deinitialize old elements if new size is smaller than old size - only valid for non-primitive types */
    if (c_apiElementRequiresInit(elementType)) {
        g_fileWrite(data->source, "if (length < seq->length) {\n");
        g_fileIndent(data->source);
        g_fileWrite(data->source, "db_uint32 i;\n");
        g_fileWrite(data->source, "for(i=length; i<seq->length; i++) {\n");
        g_fileIndent(data->source);
        c_apiElementInit(elementId, "&seq->buffer[i]", FALSE, data);
        g_fileDedent(data->source);
        g_fileWrite(data->source, "}\n");
        g_fileDedent(data->source);
        g_fileWrite(data->source, "}\n");
    }
    
    /* Resize buffer */
    g_fileWrite(data->source, "seq->buffer = db_realloc(seq->buffer, length * (size=db_type_sizeof(db_type(%s_o))));\n", elementId);
    
    /* Initialize new elements */
    g_fileWrite(data->source, "if (length > seq->length) {\n");
    g_fileIndent(data->source);
    if (elementType->kind != DB_PRIMITIVE) {
        g_fileWrite(data->source, "db_uint32 i;\n");
    }
    g_fileWrite(data->source, "memset(&seq->buffer[seq->length], 0, size * (length - seq->length));\n");
    if (elementType->kind != DB_PRIMITIVE) {
        g_fileWrite(data->source, "for(i=seq->length; i<length; i++) {\n");
        g_fileIndent(data->source);
        c_apiElementInit(elementId, "&seq->buffer[i]", FALSE, data);
        g_fileDedent(data->source);
        g_fileWrite(data->source, "}\n");
    }
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n");
    
    /* Set new length */
    g_fileWrite(data->source, "seq->length = length;\n");
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");
    
    return 0;
}

/* Create sequence clear-function */
static db_int16 c_apiSequenceTypeClear(db_sequence o, c_apiWalk_t* data) {
    db_id id, elementId;
    db_bool prefix;
    db_type elementType = db_collection(o)->elementType->real;
    
    c_specifierId(data->g, db_typedef(o), id, NULL, NULL);
    c_specifierId(data->g, db_typedef(elementType), elementId, &prefix, NULL);
    
    /* Function declaration */
    g_fileWrite(data->header, "void %s__clear(%s *seq);\n", id, id);
    
    /* Function implementation */
    g_fileWrite(data->source, "void %s__clear(%s *seq) {\n", id, id);
    g_fileIndent(data->source);
    g_fileWrite(data->source, "%s__size(seq, 0);\n", id);
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");
    
    return 0;
}

/* Walk sequence */
static db_int16 c_apiWalkSequence(db_sequence o, c_apiWalk_t* data) {
    db_id id;
    
    g_fileWrite(data->header, "\n/* %s */\n", db_fullname(o, id));
    
    data->current = o;
    
    /* Generate foreach */
    if (c_apiSequenceTypeForeach(o, data)) {
        goto error;
    }
    
    /* Generate append */
    if (c_apiSequenceTypeAppend(o, data)) {
        goto error;
    }
    
    /* Generate size */
    if (c_apiSequenceTypeSize(o, data)) {
        goto error;
    }
    
    /* Generate clear */
    if (c_apiSequenceTypeClear(o, data)) {
        goto error;
    }

    return 0;
error:
    return -1;
}

/* Create list foreach-macro */
static db_int16 c_apiListTypeForeach(db_list o, c_apiWalk_t* data) {
    db_id id, elementId;
    db_bool prefix;
    db_type elementType = db_collection(o)->elementType->real;
    
    c_specifierId(data->g, db_typedef(o), id, NULL, NULL);
    c_specifierId(data->g, db_typedef(elementType), elementId, &prefix, NULL);

    /* Macro */
    g_fileWrite(data->header, "#define %s__foreach(list, elem) \\\n", id);
    g_fileIndent(data->header);
    g_fileWrite(data->header, "db_iter elem##_iter = db_llIter(list);\\\n");
    g_fileWrite(data->header, "%s %selem;\\\n", elementId, prefix?"*":"");
    g_fileWrite(data->header, "while(db_iterHasNext(&elem##_iter)) {\\\n");
    g_fileIndent(data->header);
    g_fileWrite(data->header, "elem = db_iterNext(&elem##_iter);\n");
    g_fileDedent(data->header);
    g_fileDedent(data->header);
    g_fileWrite(data->header, "\n");
    
    return 0;
}

static db_string db_operationToApi(db_string operation, db_id id) {
    sprintf(id, "db_ll%s", operation);
    id[5] -= 32; /* Capitalize first letter of operation */
    return id;
}

/* Create insert function for types that require allocation */
static db_int16 c_apiListTypeInsertAlloc(db_list o, db_string operation, c_apiWalk_t* data) {
    db_id id, elementId, api;
    db_bool prefix;
    db_type elementType = db_collection(o)->elementType->real;
    
    c_specifierId(data->g, db_typedef(o), id, NULL, NULL);
    c_specifierId(data->g, db_typedef(elementType), elementId, &prefix, NULL);
    
    /* Function declaration */
    g_fileWrite(data->header, "%s* %s__%s(%s list);\n", elementId, id, operation, id);
    
    /* Function implementation */
    g_fileWrite(data->source, "%s* %s__%s(%s list) {\n", elementId, id, operation, id);
    
    g_fileIndent(data->source);
    g_fileWrite(data->source, "%s* result;\n", elementId);
    g_fileWrite(data->source, "result = db_calloc(db_type_sizeof(db_type(%s_o)));\n", elementId);
    
    /* Initialize element */
    c_apiElementInit(elementId, "result", TRUE, data);
    
    /* Insert element to list */
    g_fileWrite(data->source, "%s(list, result);\n", db_operationToApi(operation, api));
    
    /* Return new element */
    g_fileWrite(data->source, "return result;\n");
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");
    
    return 0;
}

/* Create insert function for types that require no allocation */
static db_int16 c_apiListTypeInsertNoAlloc(db_list o, db_string operation, c_apiWalk_t* data) {
    db_id id, elementId, api;
    db_bool prefix;
    db_type elementType = db_collection(o)->elementType->real;
    
    c_specifierId(data->g, db_typedef(o), id, NULL, NULL);
    c_specifierId(data->g, db_typedef(elementType), elementId, &prefix, NULL);
    
    /* Function declaration */
    g_fileWrite(data->header, "void %s__%s(%s list, %s element);\n", id, operation, id, elementId);
    
    /* Function implementation */
    g_fileWrite(data->source, "void %s__%s(%s list, %s element) {\n", id, operation, id, elementId);
    g_fileIndent(data->source);
    
    /* Insert element to list */
    g_fileWrite(data->source, "%s(list, (void*)element);\n", db_operationToApi(operation, api));
    
    /* Return new element */
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");
    
    return 0;
}

/* Create insert-function */
static db_int16 c_apiListTypeInsert(db_list o, db_string operation, c_apiWalk_t* data) {
    db_int16 result;
    
    if (db_collection_elementRequiresAlloc(db_collection(o))) {
        result = c_apiListTypeInsertAlloc(o, operation, data);
    } else {
        result = c_apiListTypeInsertNoAlloc(o, operation, data);
    }
    
    return result;
}

/* Create take function for types that require allocation */
static db_int16 c_apiListTypeTake(db_list o, db_string operation, c_apiWalk_t* data) {
    db_id id, elementId, api;
    db_bool prefix;
    db_type elementType = db_collection(o)->elementType->real;
    db_bool allocRequired = db_collection_elementRequiresAlloc(db_collection(o));
    
    c_specifierId(data->g, db_typedef(o), id, NULL, NULL);
    c_specifierId(data->g, db_typedef(elementType), elementId, &prefix, NULL);
    
    /* Function declaration */
    g_fileWrite(data->header, "%s%s %s__%s(%s list);\n", elementId, allocRequired?"*":"", id, operation, id);
    
    /* Function implementation */
    g_fileWrite(data->source, "%s%s %s__%s(%s list) {\n", elementId, allocRequired?"*":"", id, operation, id);
    g_fileIndent(data->source);
    
    /* Insert element to list */
    g_fileWrite(data->source, "return (%s%s)%s(list);\n", elementId, allocRequired?"*":"", db_operationToApi(operation, api));

    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");
    
    return 0;
}

/* Create clear function for types that require allocation */
static db_int16 c_apiListTypeClear(db_list o, c_apiWalk_t* data) {
    db_id id, elementId;
    db_bool prefix;
    db_type elementType = db_collection(o)->elementType->real;
    db_bool allocRequired = db_collection_elementRequiresAlloc(db_collection(o));
    
    c_specifierId(data->g, db_typedef(o), id, NULL, NULL);
    c_specifierId(data->g, db_typedef(elementType), elementId, &prefix, NULL);
    
    /* Function declaration */
    g_fileWrite(data->header, "void %s__clear(%s list);\n", id, id);
    
    /* Function implementation */
    g_fileWrite(data->source, "void %s__clear(%s list) {\n", id, id);
    g_fileIndent(data->source);
    g_fileWrite(data->source, "void *element;\n\n");
    g_fileWrite(data->source, "while((element = db_llTakeFirst(list))) {\n");
    g_fileIndent(data->source);
    if (allocRequired) {
        c_apiElementInit(elementId, "element", FALSE, data);
        g_fileWrite(data->source, "db_dealloc(element);\n");
    } else if (elementType->reference) {
        g_fileWrite(data->source, "db_free(element);\n");
    }
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n");
    
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");
    
    return 0;
}

/* Create get function for types that require allocation */
static db_int16 c_apiListTypeGet(db_list o, c_apiWalk_t* data) {
    db_id id, elementId;
    db_bool prefix;
    db_type elementType = db_collection(o)->elementType->real;
    db_bool allocRequired = db_collection_elementRequiresAlloc(db_collection(o));
    
    c_specifierId(data->g, db_typedef(o), id, NULL, NULL);
    c_specifierId(data->g, db_typedef(elementType), elementId, &prefix, NULL);
    
    /* Function declaration */
    g_fileWrite(data->header, "%s%s %s__get(%s list, db_uint32 index);\n", elementId, allocRequired?"*":"", id, id);
    
    /* Function implementation */
    g_fileWrite(data->source, "%s%s %s__get(%s list, db_uint32 index) {\n", elementId, allocRequired?"*":"", id, id);
    g_fileIndent(data->source);
    
    /* Insert element to list */
    g_fileWrite(data->source, "return (%s%s)db_llGet(list, index);\n", elementId, allocRequired?"*":"");
    
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");
    
    return 0;
}

/* Create insert function for types that require allocation */
static db_int16 c_apiListTypeSize(db_list o, c_apiWalk_t* data) {
    db_id id, elementId;
    db_bool prefix;
    db_type elementType = db_collection(o)->elementType->real;
    
    c_specifierId(data->g, db_typedef(o), id, NULL, NULL);
    c_specifierId(data->g, db_typedef(elementType), elementId, &prefix, NULL);
    
    /* Function declaration */
    g_fileWrite(data->header, "db_uint32 %s__size(%s list);\n", id, id);
    
    /* Function implementation */
    g_fileWrite(data->source, "db_uint32 %s__size(%s list) {\n", id, id);
    g_fileIndent(data->source);
    
    /* Insert element to list */
    g_fileWrite(data->source, "return db_llSize(list);\n");
    
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");
    
    return 0;
}

/* Walk list */
static db_int16 c_apiWalkList(db_list o, c_apiWalk_t* data) {
    db_id id;
    
    g_fileWrite(data->header, "\n/* %s */\n", db_fullname(o, id));
    
    data->current = o;
    
    /* Generate foreach */
    if (c_apiListTypeForeach(o, data)) {
        goto error;
    }
    
    /* Generate insert */
    if (c_apiListTypeInsert(o, "insert", data)) {
        goto error;
    }
    
    /* Generate append */
    if (c_apiListTypeInsert(o, "append", data)) {
        goto error;
    }
    
    /* Generate take */
    if (c_apiListTypeTake(o, "takeFirst", data)) {
        goto error;
    }
    
    /* Generate last */
    if (c_apiListTypeTake(o, "last", data)) {
        goto error;
    }
    
    /* Generate clear */
    if (c_apiListTypeClear(o, data)) {
        goto error;
    }
    
    /* Generate get */
    if (c_apiListTypeGet(o, data)) {
        goto error;
    }
    
    /* Generate size */
    if (c_apiListTypeSize(o, data)) {
        goto error;
    }
    
    return 0;
error:
    return -1;
}

/* Forward objects for which code will be generated. */
static int c_apiWalk(db_object o, void* userData) {

    /* Forward interfaces */
    if (db_class_instanceof(db_interface_o, o) && db_type(o)->reference) {
        if (c_apiWalkReferenceType(db_interface(o), userData)) {
            goto error;
        }
    }

    return 1;
error:
    return 0;
}

/* Forward collection objects for which code will be generated */
static int c_apiCollectionWalk(void* o, void* userData) {
    
    /* Forward sequences, lists and maps */
    switch(db_collection(o)->kind) {
        case DB_SEQUENCE:
            if (c_apiWalkSequence(db_sequence(o), userData)) {
                goto error;
            }
            break;
        case DB_LIST:
            if (c_apiWalkList(db_list(o), userData)) {
                goto error;
            }
            break;
        case DB_MAP:
            /*if (c_apiWalkMap(db_map(o), userData)) {
             goto error;
             }*/
            break;
        default:
            break;
    }

    
    return 1;
error:
    return 0;
}

/* Open headerfile, write standard header. */
static g_file c_apiHeaderOpen(db_generator g) {
    g_file result;
    db_id headerFileName;

    /* Create file */
    sprintf(headerFileName, "%s__api.h", g_getName(g));
    result = g_fileOpen(g, headerFileName);

    /* Print standard comments and includes */
    g_fileWrite(result, "/* %s\n", headerFileName);
    g_fileWrite(result, " *\n");
    g_fileWrite(result, " *  Generated on %s\n", __DATE__);
    g_fileWrite(result, " *    API convenience functions for C-language.\n");
    g_fileWrite(result, " *    This file contains generated code. Do not modify!\n");
    g_fileWrite(result, " */\n\n");
    g_fileWrite(result, "#ifndef %s__API_H\n", g_getName(g));
    g_fileWrite(result, "#define %s__API_H\n\n", g_getName(g));
    g_fileWrite(result, "#include \"%s__type.h\"\n", g_getName(g));
    g_fileWrite(result, "#include \"hyve.h\"\n\n");
    g_fileWrite(result, "#ifdef __cplusplus\n");
    g_fileWrite(result, "extern \"C\" {\n");
    g_fileWrite(result, "#endif\n");

    return result;
}

/* Close headerfile */
static void c_apiHeaderClose(g_file file) {

    /* Print standard comments and includes */
    g_fileWrite(file, "\n");
    g_fileWrite(file, "#ifdef __cplusplus\n");
    g_fileWrite(file, "}\n");
    g_fileWrite(file, "#endif\n");
    g_fileWrite(file, "#endif\n\n");
}

/* Open sourcefile */
static g_file c_apiSourceOpen(db_generator g) {
    g_file result;
    db_id headerFileName;

    /* Create file */
    sprintf(headerFileName, "%s__api.c", g_getName(g));
    result = g_fileOpen(g, headerFileName);

    /* Print standard comments and includes */
    g_fileWrite(result, "/* %s\n", headerFileName);
    g_fileWrite(result, " *\n");
    g_fileWrite(result, " *  Generated on %s\n", __DATE__);
    g_fileWrite(result, " *    API convenience functions for C-language.\n");
    g_fileWrite(result, " *    This file contains generated code. Do not modify!\n");
    g_fileWrite(result, " */\n\n");
    g_fileWrite(result, "#include \"%s__meta.h\"\n", g_getName(g));
    g_fileWrite(result, "#include \"%s__api.h\"\n\n", g_getName(g));

    return result;
}

static db_equalityKind c_apiCompareCollections(db_collection c1, db_collection c2) {
    db_equalityKind result = DB_EQ;
    if (c1->kind != c2->kind) {
        result = DB_NEQ;
    } else if (c1->elementType != c2->elementType) {
        result = DB_NEQ;
    } else if (c1->max != c2->max) {
        result = DB_NEQ ;
    } else if (c1->kind == DB_MAP) {
        if (db_map(c1)->keyType != db_map(c2)->keyType) {
            result = DB_NEQ;
        }
    }
    return result;
}

static int c_apiCheckDuplicates(void* o, void* userData) {
    if (db_checkAttr(o, DB_ATTR_SCOPED)) {
        return 1;
    } else {
        return c_apiCompareCollections(db_collection(o), db_collection(userData)) != DB_EQ;
    }
}

static int c_apiFindCollections(db_object o, void* userData) {
    c_apiWalk_t* data = userData;
    
    if (db_instanceof(db_typedef(db_collection_o), o)) {
        if (!db_llSize(data->collections) || db_llWalk(data->collections, c_apiCheckDuplicates, o)) {
            db_llAppend(data->collections, o);
        }
    }
    
    return 0;
}

/* Generator main */
db_int16 hyve_genMain(db_generator g) {
    c_apiWalk_t walkData;

	/* Default prefixes for hyve namespaces */
	gen_parse(g, hyve_o, FALSE, FALSE, "");
    gen_parse(g, hyve_lang_o, FALSE, FALSE, "db");

    walkData.g = g;
    walkData.header = c_apiHeaderOpen(g);
    walkData.source = c_apiSourceOpen(g);
    walkData.collections = db_llNew();

    g_walkRecursive(g, c_apiWalk, &walkData);
    
    /* Do a dependency walk over scope to find all collection objects, including anonymous */
    if (db_genDepWalk(g, c_apiFindCollections, NULL, &walkData)) {
        db_trace("generation of api-routines failed while resolving collections.");
        return -1;
    }
    
    db_llWalk(walkData.collections, c_apiCollectionWalk, &walkData);

    c_apiHeaderClose(walkData.header);
    db_llFree(walkData.collections);

    return 0;
}
