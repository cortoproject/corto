/*
 * c_api.c
 *
 *  Created on: Oct 10, 2012
 *      Author: sander
 */

#include "cortex.h"
#include "cx_generator.h"
#include "c_common.h"
#include "cx_serializer.h"
#include "cx_generatorDepWalk.h"

typedef struct c_apiWalk_t {
    cx_generator g;
    g_file header;
    g_file source;
    cx_object current;
    cx_uint32 parameterCount;
    cx_ll memberCache;
    cx_ll collections;
} c_apiWalk_t;

/* Translate members to function parameters. */
static cx_int16 c_apiAssignMember(cx_serializer s, cx_value* v, void* userData) {
    c_apiWalk_t* data;
    cx_member m;
    cx_id memberIdTmp, memberParamId, memberId;

    CX_UNUSED(s);

    if (v->kind == CX_MEMBER) {
        m = v->is.member.t;
        data = userData;

        cx_genMemberName(data->g, data->memberCache, m, memberIdTmp);
        g_id(data->g, memberIdTmp, memberParamId);
        g_id(data->g, cx_nameof(m), memberId);

        /* Keep references */
        if (m->type->reference) {
            if (!m->weak) {
                cx_id id;
                g_fileWrite(data->source, "%s ? cx_claim_ext(_this, %s, \"%s\") : 0;\n", memberParamId, memberParamId, cx_valueString(v,id, 256));
            }
        }

        /* If member is of array-type, use memcpy */
        if ((m->type->kind == CX_COLLECTION) && (cx_collection(m->type)->kind == CX_ARRAY)) {
            cx_id typeId, postfix;
            /* Get typespecifier */
            if (c_specifierId(data->g, m->type, typeId, NULL, postfix)) {
                goto error;
            }
            g_fileWrite(data->source, "memcpy(");

            /* Cast object to right type */
            if (data->current == cx_parentof(m)) {
                g_fileWrite(data->source, "_this->%s",
                        memberId);
            } else {
                cx_id typeId;
                g_fileWrite(data->source, "%s(_this)->%s",
                        g_fullOid(data->g, cx_parentof(m), typeId), memberId);
            }

            g_fileWrite(data->source, ", %s, sizeof(%s%s));\n", memberParamId, typeId, postfix);
        } else {
            /* Cast object to right type */
            if (data->current == cx_parentof(m)) {
                g_fileWrite(data->source, "_this->%s = ",
                        memberId);
            } else {
                cx_id typeId;
                g_fileWrite(data->source, "%s(_this)->%s = ",
                        g_fullOid(data->g, cx_parentof(m), typeId), memberId);
            }

            /* Strdup strings */
            if ((m->type->kind == CX_PRIMITIVE) && (cx_primitive(m->type)->kind == CX_TEXT)) {
                g_fileWrite(data->source, "(%s ? cx_strdup(%s) : NULL);\n", memberParamId, memberParamId);
            } else {
                /* If a non-void reference type, cast parameter */
                if (m->type->reference && !(m->type->kind == CX_VOID)) {
                    cx_id id;
                    g_fileWrite(data->source, "%s(%s);\n", g_fullOid(data->g, m->type, id), memberParamId);
                } else {
                    g_fileWrite(data->source, "%s;\n", memberParamId);
                }
            }
        }

        data->parameterCount++;
    }

    return 0;
error:
    return -1;
}

/* Translate members to function parameters. */
static cx_int16 c_apiParamMember(cx_serializer s, cx_value* v, void* userData) {
    c_apiWalk_t* data;
    cx_member m;
    cx_id typeSpec, typePostfix, memberIdTmp, memberId;

    CX_UNUSED(s);

    if (v->kind == CX_MEMBER) {
        m = v->is.member.t;
        data = userData;

        if (data->parameterCount) {
            g_fileWrite(data->header, ", ");
            g_fileWrite(data->source, ", ");
        }

        /* Get type-specifier */
        c_specifierId(data->g, m->type, typeSpec, NULL, typePostfix);
        cx_genMemberName(data->g, data->memberCache, m, memberIdTmp);

        g_fileWrite(data->header, "%s%s %s",
               typeSpec, typePostfix, g_id(data->g, memberIdTmp, memberId));

        g_fileWrite(data->source, "%s%s %s",
                typeSpec, typePostfix, g_id(data->g, memberIdTmp, memberId));

        data->parameterCount++;
    }

    return 0;
}

/* Member parameter serializer */
static struct cx_serializer_s c_apiParamSerializer(void) {
    struct cx_serializer_s s;

    cx_serializerInit(&s);
    s.metaprogram[CX_MEMBER] = c_apiParamMember;
    s.access = CX_LOCAL|CX_READONLY|CX_PRIVATE;
    s.accessKind = CX_NOT;

    return s;
}

/* Member parameter serializer */
static struct cx_serializer_s c_apiAssignSerializer(void) {
    struct cx_serializer_s s;

    cx_serializerInit(&s);
    s.metaprogram[CX_MEMBER] = c_apiAssignMember;
    s.access = CX_LOCAL|CX_READONLY|CX_PRIVATE;
    s.accessKind = CX_NOT;

    return s;
}

/* Create new-function */
static cx_int16 c_apiTypeNew(cx_type o, c_apiWalk_t* data) {
    cx_id id;

    g_fullOid(data->g, o, id);

    /* Function declaration */
    g_fileWrite(data->header, "%s%s %s__new(void);\n", id, o->reference ? "" : "*", id);

    /* Function implementation */
    g_fileWrite(data->source, "%s%s %s__new(void) {\n", id, o->reference ? "" : "*", id);
    g_fileIndent(data->source);
    g_fileWrite(data->source, "return cx_create(cx_type(%s_o));\n", id);
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");

    return 0;
}

/* Create declare-function */
static cx_int16 c_apiTypeDeclare(cx_type o, c_apiWalk_t* data) {
    cx_id id;

    g_fullOid(data->g, o, id);

    /* Function declaration */
    g_fileWrite(data->header, "%s%s %s__declare(cx_object _parent, cx_string _name);\n", 
        id, o->reference ? "" : "*", id);

    /* Function implementation */
    g_fileWrite(data->source, "%s%s %s__declare(cx_object _parent, cx_string _name) {\n", 
        id, o->reference ? "" : "*", id);

    g_fileIndent(data->source);
    g_fileWrite(data->source, "return cx_declare(_parent, _name, cx_type(%s_o));\n", id);
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");

    return 0;
}

/* Create define-function */
static cx_int16 c_apiReferenceTypeDefine(cx_interface o, c_apiWalk_t* data) {
    cx_id id;
    struct cx_serializer_s s;

    g_fullOid(data->g, o, id);

    /* Function declaration */
    g_fileWrite(data->header, "int %s__define(%s _this", id, id);

    /* Function implementation */
    g_fileWrite(data->source, "int %s__define(%s _this", id, id);

    /* Write public members as arguments for source and header */
    data->parameterCount = 1;
    s = c_apiParamSerializer();
    cx_metaWalk(&s, cx_type(o), data);

    /* Write closing brackets for argumentlist in source and header */
    g_fileWrite(data->header, ");\n");
    g_fileWrite(data->source, ") {\n");
    g_fileIndent(data->source);

    /* Member assignments */
    s = c_apiAssignSerializer();
    cx_metaWalk(&s, cx_type(o), data);

    g_fileWrite(data->source, "return cx_define(_this);\n");
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");

    return 0;
}

/* Create init-function */
static cx_int16 c_apiTypeInit(cx_interface o, c_apiWalk_t* data) {
    cx_id id;
    struct cx_serializer_s s;

    g_fullOid(data->g, o, id);

    /* Function declaration */
    g_fileWrite(data->header, "void %s__init(%s *_this", id, id, id);

    /* Function implementation */
    g_fileWrite(data->source, "void %s__init(%s *_this", id, id, id);

    /* Write public members as arguments for source and header */
    data->parameterCount = 1;
    s = c_apiParamSerializer();
    cx_metaWalk(&s, cx_type(o), data);

    /* Write closing brackets for argumentlist in source and header */
    g_fileWrite(data->header, ");\n");
    g_fileWrite(data->source, ") {\n");
    g_fileIndent(data->source);

    /* Initialize value */
    g_fileWrite(data->source, "cx_value v;\n");
    g_fileWrite(data->source, "memset(_this, 0, sizeof(*_this));\n");
    g_fileWrite(data->source, "cx_valueValueInit(&v, NULL, cx_type(%s_o), _this);\n", id);
    g_fileWrite(data->source, "cx_initValue(&v);\n");

    /* Member assignments */
    s = c_apiAssignSerializer();
    cx_metaWalk(&s, cx_type(o), data);

    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");

    return 0;
}

/* Create deinit-function */
static cx_int16 c_apiTypeDeinit(cx_interface o, c_apiWalk_t* data) {
    cx_id id;

    g_fullOid(data->g, o, id);

    /* Function declaration */
    g_fileWrite(data->header, "void %s__deinit(%s *_this);\n", id, id, id);

    /* Function implementation */
    g_fileWrite(data->source, "void %s__deinit(%s *_this) {\n", id, id, id);
    g_fileIndent(data->source);

    g_fileWrite(data->source, "cx_value v;\n");
    g_fileWrite(data->source, "cx_valueValueInit(&v, NULL, cx_type(%s_o), _this);\n", id);
    g_fileWrite(data->source, "cx_deinitValue(&v);\n");

    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");

    return 0;
}


static cx_int16 c_apiReferenceTypeCreate(cx_interface o, c_apiWalk_t* data) {
    cx_id id;
    struct cx_serializer_s s;

    g_fullOid(data->g, o, id);

    /* Function declaration */
    g_fileWrite(data->header, "%s %s__create(", id, id);

    /* Function implementation */
    g_fileWrite(data->source, "%s %s__create(", id, id);

    /* Write public members as arguments for source and header */
    data->parameterCount = 0;
    s = c_apiParamSerializer();
    cx_metaWalk(&s, cx_type(o), data);

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
    g_fileWrite(data->source, "_this = cx_create(cx_type(%s_o));\n", id);

    /* Member assignments */
    s = c_apiAssignSerializer();
    cx_metaWalk(&s, cx_type(o), data);

    /* Define object */
    g_fileWrite(data->source, "if (cx_define(_this)) {\n");
    g_fileIndent(data->source);
    g_fileWrite(data->source, "cx_release(_this);\n");
    g_fileWrite(data->source, "_this = NULL;\n");
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n");

    g_fileWrite(data->source, "return _this;\n");
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");

    return 0;
}

static cx_int16 c_apiTypeStr(cx_type t, c_apiWalk_t* data) {
    if (t->kind != CX_VOID) {
        cx_id id;

        g_fullOid(data->g, t, id);

        /* Function declaration */
        g_fileWrite(data->header, "cx_string %s__str(%s value);\n", id, id);

        /* Function implementation */
        g_fileWrite(data->source, "cx_string %s__str(%s value) {\n", id, id);

        g_fileIndent(data->source);
        g_fileWrite(data->source, "cx_string result;\n", id);

        if (t->reference) {
            g_fileWrite(data->source, "result = cx_toString(value, 0);\n");
        } else {
            g_fileWrite(data->source, "cx_value v;\n", id);
            g_fileWrite(data->source, "cx_valueValueInit(&v, NULL, cx_type(%s_o), &value);\n", id);
            g_fileWrite(data->source, "result = cx_valueToString(&v, 0);\n");
        }

        g_fileWrite(data->source, "return result;\n");
        g_fileDedent(data->source);
        g_fileWrite(data->source, "}\n\n");
    }
    return 0;
}

/* Walk reference interface */
static cx_int16 c_apiWalkReferenceInterface(cx_interface o, c_apiWalk_t* data) {

    /* Build nameconflict cache */
    data->memberCache = cx_genMemberCacheBuild(o);

    /* Generate _define function */
    if (c_apiReferenceTypeDefine(o, data)) {
        goto error;
    }

    /* Generate _create function */
    if (c_apiReferenceTypeCreate(o, data)) {
        goto error;
    }

    cx_genMemberCacheClean(data->memberCache);

    return 0;
error:
    return -1;
}

/* Walk non-reference interface */
static cx_int16 c_apiWalkValueInterface(cx_interface o, c_apiWalk_t* data) {

    data->memberCache = cx_genMemberCacheBuild(o);

    if (c_apiTypeInit(o, data)) {
        goto error;
    }

    if (c_apiTypeDeinit(o, data)) {
        goto error;
    }

    cx_genMemberCacheClean(data->memberCache);

    return 0;
error:
    return -1;
}

/* Walk all types */
static cx_int16 c_apiWalkType(cx_type o, c_apiWalk_t* data) {

    /* Generate _new function */
    if (c_apiTypeNew(o, data)) {
        goto error;
    }

    /* Generate _declare function */
    if (c_apiTypeDeclare(o, data)) {
        goto error;
    }

    /* Generate _str function */
    if (c_apiTypeStr(o, data)) {
        goto error;
    }

    g_fileWrite(data->header, "\n");

    return 0;
error:
    return -1;
}

static cx_bool c_apiElementRequiresInit(cx_type elementType) {
    cx_bool result = FALSE;

    if ((elementType->kind != CX_PRIMITIVE) && !elementType->reference) {
        result = TRUE;
    }

    return result;
}
void cx_valueValueInit(cx_value* val, cx_object o, cx_type t, cx_void* v);
/* Initialize or deinitialize element */
static cx_int16 c_apiElementInit(cx_string elementType, cx_string element, cx_bool isInit, c_apiWalk_t* data) {
    g_fileWrite(data->source, "{\n");
    g_fileIndent(data->source);
    g_fileWrite(data->source, "cx_value v;\n");
    g_fileWrite(data->source, "cx_valueValueInit(&v, NULL, cx_type(%s_o), %s);\n", elementType, element);
    if (isInit) {
        g_fileWrite(data->source, "cx_initValue(&v);\n");
    } else {
        g_fileWrite(data->source, "cx_deinitValue(&v);\n");
    }
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n");
    
    return 0;
}

/* Create sequence foreach-macro */
static cx_int16 c_apiSequenceTypeForeach(cx_sequence o, c_apiWalk_t* data) {
    cx_id id, elementId;
    cx_bool prefix;
    cx_type elementType = cx_collection(o)->elementType;
    
    c_specifierId(data->g, cx_type(o), id, NULL, NULL);
    c_specifierId(data->g, cx_type(elementType), elementId, &prefix, NULL);
    
    /* Macro */
    g_fileWrite(data->header, "#define %s__foreach(seq, elem) \\\n", id);
    g_fileIndent(data->header);
    g_fileWrite(data->header, "cx_uint32 elem##_iter;\\\n");
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
static cx_int16 c_apiSequenceTypeAppend(cx_sequence o, c_apiWalk_t* data) {
    cx_id id, elementId;
    cx_bool prefix;
    cx_type elementType = cx_collection(o)->elementType;
    
    c_specifierId(data->g, cx_type(o), id, NULL, NULL);
    c_specifierId(data->g, cx_type(elementType), elementId, &prefix, NULL);

    /* Function declaration */
    g_fileWrite(data->header, "%s%s %s__append(%s *seq);\n", elementId, prefix?"*":"", id, id);
    
    /* Function implementation */
    g_fileWrite(data->source, "%s%s %s__append(%s *seq) {\n", elementId, prefix?"*":"", id, id);
    
    g_fileIndent(data->source);
    g_fileWrite(data->source, "cx_uint32 size;\n");
    g_fileWrite(data->source, "seq->length++;\n");
    g_fileWrite(data->source, "seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(%s_o))));\n", elementId);
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
static cx_int16 c_apiSequenceTypeSize(cx_sequence o, c_apiWalk_t* data) {
    cx_id id, elementId;
    cx_bool prefix;
    cx_type elementType = cx_collection(o)->elementType;
    
    c_specifierId(data->g, cx_type(o), id, NULL, NULL);
    c_specifierId(data->g, cx_type(elementType), elementId, &prefix, NULL);
    
    /* Function declaration */
    g_fileWrite(data->header, "void %s__size(%s *seq, cx_uint32 length);\n", id, id);
    
    /* Function implementation */
    g_fileWrite(data->source, "void %s__size(%s *seq, cx_uint32 length) {\n", id, id);
    g_fileIndent(data->source);
    g_fileWrite(data->source, "cx_uint32 size;\n");
    
    /* Deinitialize old elements if new size is smaller than old size - only valid for non-primitive types */
    if (c_apiElementRequiresInit(elementType)) {
        g_fileWrite(data->source, "if (length < seq->length) {\n");
        g_fileIndent(data->source);
        g_fileWrite(data->source, "cx_uint32 i;\n");
        g_fileWrite(data->source, "for(i=length; i<seq->length; i++) {\n");
        g_fileIndent(data->source);
        c_apiElementInit(elementId, "&seq->buffer[i]", FALSE, data);
        g_fileDedent(data->source);
        g_fileWrite(data->source, "}\n");
        g_fileDedent(data->source);
        g_fileWrite(data->source, "}\n");
    }
    
    /* Resize buffer */
    g_fileWrite(data->source, "seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(%s_o))));\n", elementId);
    
    /* Initialize new elements */
    g_fileWrite(data->source, "if (length > seq->length) {\n");
    g_fileIndent(data->source);
    if (elementType->kind != CX_PRIMITIVE) {
        g_fileWrite(data->source, "cx_uint32 i;\n");
    }
    g_fileWrite(data->source, "memset(&seq->buffer[seq->length], 0, size * (length - seq->length));\n");
    if (elementType->kind != CX_PRIMITIVE) {
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
static cx_int16 c_apiSequenceTypeClear(cx_sequence o, c_apiWalk_t* data) {
    cx_id id, elementId;
    cx_bool prefix;
    cx_type elementType = cx_collection(o)->elementType;
    
    c_specifierId(data->g, cx_type(o), id, NULL, NULL);
    c_specifierId(data->g, cx_type(elementType), elementId, &prefix, NULL);
    
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
static cx_int16 c_apiWalkSequence(cx_sequence o, c_apiWalk_t* data) {
    cx_id id;
    
    g_fileWrite(data->header, "\n/* %s */\n", cx_fullname(o, id));
    
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
static cx_int16 c_apiListTypeForeach(cx_list o, c_apiWalk_t* data) {
    cx_id id, elementId;
    cx_bool prefix;
    cx_type elementType = cx_collection(o)->elementType;
    
    c_specifierId(data->g, cx_type(o), id, NULL, NULL);
    c_specifierId(data->g, cx_type(elementType), elementId, &prefix, NULL);

    /* Macro */
    g_fileWrite(data->header, "#define %s__foreach(list, elem) \\\n", id);
    g_fileIndent(data->header);
    g_fileWrite(data->header, "cx_iter elem##_iter = cx_llIter(list);\\\n");
    g_fileWrite(data->header, "%s %selem;\\\n", elementId, prefix?"*":"");
    g_fileWrite(data->header, "while(cx_iterHasNext(&elem##_iter)) {\\\n");
    g_fileIndent(data->header);
    g_fileWrite(data->header, "elem = cx_iterNext(&elem##_iter);\n");
    g_fileDedent(data->header);
    g_fileDedent(data->header);
    g_fileWrite(data->header, "\n");
    
    return 0;
}

static cx_string cx_operationToApi(cx_string operation, cx_id id) {
    sprintf(id, "cx_ll%s", operation);
    id[5] -= 32; /* Capitalize first letter of operation */
    return id;
}

/* Create insert function for types that require allocation */
static cx_int16 c_apiListTypeInsertAlloc(cx_list o, cx_string operation, c_apiWalk_t* data) {
    cx_id id, elementId, api;
    cx_bool prefix;
    cx_type elementType = cx_collection(o)->elementType;
    
    c_specifierId(data->g, cx_type(o), id, NULL, NULL);
    c_specifierId(data->g, cx_type(elementType), elementId, &prefix, NULL);
    
    /* Function declaration */
    g_fileWrite(data->header, "%s* %s__%s(%s list);\n", elementId, id, operation, id);
    
    /* Function implementation */
    g_fileWrite(data->source, "%s* %s__%s(%s list) {\n", elementId, id, operation, id);
    
    g_fileIndent(data->source);
    g_fileWrite(data->source, "%s* result;\n", elementId);
    g_fileWrite(data->source, "result = cx_calloc(cx_type_sizeof(cx_type(%s_o)));\n", elementId);
    
    /* Initialize element */
    c_apiElementInit(elementId, "result", TRUE, data);
    
    /* Insert element to list */
    g_fileWrite(data->source, "%s(list, result);\n", cx_operationToApi(operation, api));
    
    /* Return new element */
    g_fileWrite(data->source, "return result;\n");
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");
    
    return 0;
}

/* Create insert function for types that require no allocation */
static cx_int16 c_apiListTypeInsertNoAlloc(cx_list o, cx_string operation, c_apiWalk_t* data) {
    cx_id id, elementId, api;
    cx_bool prefix;
    cx_type elementType = cx_collection(o)->elementType;
    
    c_specifierId(data->g, cx_type(o), id, NULL, NULL);
    c_specifierId(data->g, cx_type(elementType), elementId, &prefix, NULL);
    
    /* Function declaration */
    g_fileWrite(data->header, "void %s__%s(%s list, %s element);\n", id, operation, id, elementId);
    
    /* Function implementation */
    g_fileWrite(data->source, "void %s__%s(%s list, %s element) {\n", id, operation, id, elementId);
    g_fileIndent(data->source);
    
    /* Insert element to list */
    g_fileWrite(data->source, "%s(list, (void*)element);\n", cx_operationToApi(operation, api));
    
    /* Return new element */
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");
    
    return 0;
}

/* Create insert-function */
static cx_int16 c_apiListTypeInsert(cx_list o, cx_string operation, c_apiWalk_t* data) {
    cx_int16 result;
    
    if (cx_collection_elementRequiresAlloc(cx_collection(o))) {
        result = c_apiListTypeInsertAlloc(o, operation, data);
    } else {
        result = c_apiListTypeInsertNoAlloc(o, operation, data);
    }
    
    return result;
}

/* Create take function for types that require allocation */
static cx_int16 c_apiListTypeTake(cx_list o, cx_string operation, c_apiWalk_t* data) {
    cx_id id, elementId, api;
    cx_bool prefix;
    cx_type elementType = cx_collection(o)->elementType;
    cx_bool allocRequired = cx_collection_elementRequiresAlloc(cx_collection(o));
    
    c_specifierId(data->g, cx_type(o), id, NULL, NULL);
    c_specifierId(data->g, cx_type(elementType), elementId, &prefix, NULL);
    
    /* Function declaration */
    g_fileWrite(data->header, "%s%s %s__%s(%s list);\n", elementId, allocRequired?"*":"", id, operation, id);
    
    /* Function implementation */
    g_fileWrite(data->source, "%s%s %s__%s(%s list) {\n", elementId, allocRequired?"*":"", id, operation, id);
    g_fileIndent(data->source);
    
    /* Insert element to list */
    g_fileWrite(data->source, "return (%s%s)%s(list);\n", elementId, allocRequired?"*":"", cx_operationToApi(operation, api));

    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");
    
    return 0;
}

/* Create clear function for types that require allocation */
static cx_int16 c_apiListTypeClear(cx_list o, c_apiWalk_t* data) {
    cx_id id, elementId;
    cx_bool prefix;
    cx_type elementType = cx_collection(o)->elementType;
    cx_bool allocRequired = cx_collection_elementRequiresAlloc(cx_collection(o));
    
    c_specifierId(data->g, cx_type(o), id, NULL, NULL);
    c_specifierId(data->g, cx_type(elementType), elementId, &prefix, NULL);
    
    /* Function declaration */
    g_fileWrite(data->header, "void %s__clear(%s list);\n", id, id);
    
    /* Function implementation */
    g_fileWrite(data->source, "void %s__clear(%s list) {\n", id, id);
    g_fileIndent(data->source);
    g_fileWrite(data->source, "void *element;\n\n");
    g_fileWrite(data->source, "while((element = cx_llTakeFirst(list))) {\n");
    g_fileIndent(data->source);
    if (allocRequired) {
        c_apiElementInit(elementId, "element", FALSE, data);
        g_fileWrite(data->source, "cx_dealloc(element);\n");
    } else if (elementType->reference) {
        g_fileWrite(data->source, "cx_release(element);\n");
    }
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n");
    
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");
    
    return 0;
}

/* Create get function for types that require allocation */
static cx_int16 c_apiListTypeGet(cx_list o, c_apiWalk_t* data) {
    cx_id id, elementId;
    cx_bool prefix;
    cx_type elementType = cx_collection(o)->elementType;
    cx_bool allocRequired = cx_collection_elementRequiresAlloc(cx_collection(o));
    
    c_specifierId(data->g, cx_type(o), id, NULL, NULL);
    c_specifierId(data->g, cx_type(elementType), elementId, &prefix, NULL);
    
    /* Function declaration */
    g_fileWrite(data->header, "%s%s %s__get(%s list, cx_uint32 index);\n", elementId, allocRequired?"*":"", id, id);
    
    /* Function implementation */
    g_fileWrite(data->source, "%s%s %s__get(%s list, cx_uint32 index) {\n", elementId, allocRequired?"*":"", id, id);
    g_fileIndent(data->source);
    
    /* Insert element to list */
    g_fileWrite(data->source, "return (%s%s)cx_llGet(list, index);\n", elementId, allocRequired?"*":"");
    
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");
    
    return 0;
}

/* Create insert function for types that require allocation */
static cx_int16 c_apiListTypeSize(cx_list o, c_apiWalk_t* data) {
    cx_id id, elementId;
    cx_bool prefix;
    cx_type elementType = cx_collection(o)->elementType;
    
    c_specifierId(data->g, cx_type(o), id, NULL, NULL);
    c_specifierId(data->g, cx_type(elementType), elementId, &prefix, NULL);
    
    /* Function declaration */
    g_fileWrite(data->header, "cx_uint32 %s__size(%s list);\n", id, id);
    
    /* Function implementation */
    g_fileWrite(data->source, "cx_uint32 %s__size(%s list) {\n", id, id);
    g_fileIndent(data->source);
    
    /* Insert element to list */
    g_fileWrite(data->source, "return cx_llSize(list);\n");
    
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");
    
    return 0;
}

/* Walk list */
static cx_int16 c_apiWalkList(cx_list o, c_apiWalk_t* data) {
    cx_id id;
    
    g_fileWrite(data->header, "\n/* %s */\n", cx_fullname(o, id));
    
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
static int c_apiWalk(cx_object o, void* userData) {
    c_apiWalk_t* data = userData;
    cx_id id;

    if (cx_class_instanceof(cx_type_o, o)) {
        g_fileWrite(data->header, "/* %s */\n", cx_fullname(o, id));

        data->current = o;

        /* Forward interfaces */
        if (cx_class_instanceof(cx_interface_o, o)) {
            if (cx_type(o)->reference) {
                if (c_apiWalkReferenceInterface(cx_interface(o), userData)) {
                    goto error;
                }
            } else {
                if (c_apiWalkValueInterface(cx_interface(o), userData)) {
                    goto error;
                }
            }
        }

        if (c_apiWalkType(cx_type(o), userData)) {
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
    switch(cx_collection(o)->kind) {
        case CX_SEQUENCE:
            if (c_apiWalkSequence(cx_sequence(o), userData)) {
                goto error;
            }
            break;
        case CX_LIST:
            if (c_apiWalkList(cx_list(o), userData)) {
                goto error;
            }
            break;
        case CX_MAP:
            /*if (c_apiWalkMap(cx_map(o), userData)) {
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
static g_file c_apiHeaderOpen(cx_generator g) {
    g_file result;
    cx_id headerFileName;

    /* Create file */
    sprintf(headerFileName, "%s__api.h", g_getName(g));
    result = g_fileOpen(g, headerFileName);

    /* Print standard comments and includes */
    g_fileWrite(result, "/* %s\n", headerFileName);
    g_fileWrite(result, " *\n");
    g_fileWrite(result, " * API convenience functions for C-language.\n");
    g_fileWrite(result, " * This file contains generated code. Do not modify!\n");
    g_fileWrite(result, " */\n\n");
    g_fileWrite(result, "#ifndef %s__API_H\n", g_getName(g));
    g_fileWrite(result, "#define %s__API_H\n\n", g_getName(g));
    g_fileWrite(result, "#include \"%s__type.h\"\n", g_getName(g));
    g_fileWrite(result, "#include \"cortex.h\"\n\n");
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
static g_file c_apiSourceOpen(cx_generator g) {
    g_file result;
    cx_id headerFileName;
    cx_id topLevelName;

    /* Create file */
    sprintf(headerFileName, "%s__api.c", g_getName(g));
    result = g_fileOpen(g, headerFileName);

    /* Print standard comments and includes */
    g_fileWrite(result, "/* %s\n", headerFileName);
    g_fileWrite(result, " *\n");
    g_fileWrite(result, " * API convenience functions for C-language.\n");
    g_fileWrite(result, " * This file contains generated code. Do not modify!\n");
    g_fileWrite(result, " */\n\n");
    g_fileWrite(result, "#include \"%s.h\"\n\n", g_fullOid(g, g_getCurrent(g), topLevelName));

    return result;
}

static cx_equalityKind c_apiCompareCollections(cx_collection c1, cx_collection c2) {
    cx_equalityKind result = CX_EQ;
    if (c1->kind != c2->kind) {
        result = CX_NEQ;
    } else if (c1->elementType != c2->elementType) {
        result = CX_NEQ;
    } else if (c1->max != c2->max) {
        result = CX_NEQ ;
    } else if (c1->kind == CX_MAP) {
        if (cx_map(c1)->keyType != cx_map(c2)->keyType) {
            result = CX_NEQ;
        }
    }
    return result;
}

static int c_apiCheckDuplicates(void* o, void* userData) {
    if (cx_checkAttr(o, CX_ATTR_SCOPED)) {
        return 1;
    } else {
        return c_apiCompareCollections(cx_collection(o), cx_collection(userData)) != CX_EQ;
    }
}

static int c_apiFindCollections(cx_object o, void* userData) {
    c_apiWalk_t* data = userData;
    
    if (cx_instanceof(cx_type(cx_collection_o), o)) {
        if (!cx_llSize(data->collections) || cx_llWalk(data->collections, c_apiCheckDuplicates, o)) {
            cx_llAppend(data->collections, o);
        }
    }
    
    return 0;
}

/* Generator main */
cx_int16 cortex_genMain(cx_generator g) {
    c_apiWalk_t walkData;

    /* Default prefixes for cortex namespaces */
    gen_parse(g, cortex_o, FALSE, FALSE, "");
    gen_parse(g, cortex_lang_o, FALSE, FALSE, "cx");

    walkData.g = g;
    walkData.header = c_apiHeaderOpen(g);
    walkData.source = c_apiSourceOpen(g);
    walkData.collections = cx_llNew();

    g_walkRecursive(g, c_apiWalk, &walkData);
    
    /* Do a dependency walk over scope to find all collection objects, including anonymous */
    if (cx_genDepWalk(g, c_apiFindCollections, NULL, &walkData)) {
        cx_trace("generation of api-routines failed while resolving collections.");
        return -1;
    }
    
    cx_llWalk(walkData.collections, c_apiCollectionWalk, &walkData);

    c_apiHeaderClose(walkData.header);
    cx_llFree(walkData.collections);

    return 0;
}
