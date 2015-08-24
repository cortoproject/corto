
#include "cortex.h"
#include "c_api.h"
#include "c_common.h"

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
        g_fileWrite(data->source, "cx_initv(&v);\n");
    } else {
        g_fileWrite(data->source, "cx_deinitv(&v);\n");
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
    if (elementType->reference) {
        g_fileWrite(data->source, "cx_claim(element);\n");
    }
    
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
    
    if (c_apiListTypeForeach(o, data)) {
        goto error;
    }
    
    if (c_apiListTypeInsert(o, "insert", data)) {
        goto error;
    }
    
    if (c_apiListTypeInsert(o, "append", data)) {
        goto error;
    }

    if (c_apiListTypeTake(o, "takeFirst", data)) {
        goto error;
    }
    
    if (c_apiListTypeTake(o, "last", data)) {
        goto error;
    }
    
    if (c_apiListTypeClear(o, data)) {
        goto error;
    }
    
    if (c_apiListTypeGet(o, data)) {
        goto error;
    }
    
    if (c_apiListTypeSize(o, data)) {
        goto error;
    }
    
    return 0;
error:
    return -1;
}

/* Forward collection objects for which code will be generated */
int c_apiCollectionWalk(void* o, void* userData) {
    
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
