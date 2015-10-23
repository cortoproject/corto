
#include "corto.h"
#include "c_api.h"
#include "c_common.h"

static corto_bool c_apiElementRequiresInit(corto_type elementType) {
    corto_bool result = FALSE;

    if ((elementType->kind != CORTO_PRIMITIVE) && !elementType->reference) {
        result = TRUE;
    }

    return result;
}

void corto_valueValueInit(corto_value* val, corto_object o, corto_type t, corto_void* v);

/* Initialize or deinitialize element */
static corto_int16 c_apiElementInit(corto_string elementType, corto_string element, corto_bool isInit, c_apiWalk_t* data) {
    g_fileWrite(data->source, "{\n");
    g_fileIndent(data->source);
    g_fileWrite(data->source, "corto_value v;\n");
    g_fileWrite(data->source, "corto_valueValueInit(&v, NULL, corto_type(%s_o), %s);\n", elementType, element);
    if (isInit) {
        g_fileWrite(data->source, "corto_initv(&v);\n");
    } else {
        g_fileWrite(data->source, "corto_deinitv(&v);\n");
    }
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n");
    
    return 0;
}

/* Create sequence foreach-macro */
static corto_int16 c_apiSequenceTypeForeach(corto_sequence o, c_apiWalk_t* data) {
    corto_id id, elementId;
    corto_bool prefix;
    corto_type elementType = corto_collection(o)->elementType;
    
    c_specifierId(data->g, corto_type(o), id, NULL, NULL);
    c_specifierId(data->g, corto_type(elementType), elementId, &prefix, NULL);
    
    /* Macro */
    g_fileWrite(data->header, "#define %sForeach(seq, elem) \\\n", id);
    g_fileIndent(data->header);
    g_fileWrite(data->header, "corto_uint32 elem##_iter;\\\n");
    g_fileWrite(data->header, "%s elem;\\\n", elementId);
    g_fileWrite(data->header, "for(elem##_iter=0; (seq).buffer ? elem = (seq).buffer[elem##_iter] : elem, elem##_iter<(seq).length; elem##_iter++)\\\n");
    g_fileDedent(data->header);
    g_fileWrite(data->header, "\n");
    
    return 0;
}

/* Create append-function */
static corto_int16 c_apiSequenceTypeAppendAlloc(corto_sequence o, c_apiWalk_t* data) {
    corto_id id, elementId;
    corto_bool prefix;
    corto_type elementType = corto_collection(o)->elementType;
    
    c_specifierId(data->g, corto_type(o), id, NULL, NULL);
    c_specifierId(data->g, corto_type(elementType), elementId, &prefix, NULL);

    /* Function declaration */
    c_writeExport(data->g, data->header);
    g_fileWrite(data->header, "%s* %sAppendAlloc(%s *seq);\n", elementId, id, id);
    
    /* Function implementation */
    g_fileWrite(data->source, "%s* %sAppendAlloc(%s *seq) {\n", elementId, id, id);
    
    g_fileIndent(data->source);
    g_fileWrite(data->source, "corto_uint32 size;\n");
    g_fileWrite(data->source, "seq->length++;\n");
    g_fileWrite(data->source, "seq->buffer = corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(%s_o))));\n", elementId);
    g_fileWrite(data->source, "memset(%sseq->buffer[seq->length-1], 0, size);\n", elementType->reference?"":"&");
    if (c_apiElementRequiresInit(elementType)) {
        if (!elementType->reference) {
            c_apiElementInit(elementId, "&seq->buffer[seq->length-1]", TRUE, data);
        }
    }
    g_fileWrite(data->source, "return &seq->buffer[seq->length-1];\n");
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");
    
    return 0;
}

/* Create append-function */
static corto_int16 c_apiSequenceTypeAppend(corto_sequence o, c_apiWalk_t* data) {
    corto_id id, elementId;
    corto_bool prefix;
    corto_type elementType = corto_collection(o)->elementType;
    
    c_specifierId(data->g, corto_type(o), id, NULL, NULL);
    c_specifierId(data->g, corto_type(elementType), elementId, &prefix, NULL);

    /* Function declaration */
    c_writeExport(data->g, data->header);
    g_fileWrite(data->header, "%s* %sAppend(%s *seq, %s element);\n", elementId, id, id, elementId);
    
    /* Function implementation */
    g_fileWrite(data->source, "%s* %sAppend(%s *seq, %s element) {\n", elementId, id, id, elementId);
    
    g_fileIndent(data->source);
    g_fileWrite(data->source, "corto_uint32 size;\n");
    g_fileWrite(data->source, "seq->length++;\n");
    g_fileWrite(data->source, "seq->buffer = corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(%s_o))));\n", elementId);
    g_fileWrite(data->source, "memset(%sseq->buffer[seq->length-1], 0, size);\n", elementType->reference?"":"&");
    if (c_apiElementRequiresInit(elementType)) {
        if (!elementType->reference) {
            c_apiElementInit(elementId, "&seq->buffer[seq->length-1]", TRUE, data);
        }
    }
    if (elementType->reference) {
        g_fileWrite(data->source, "corto_setref(&seq->buffer[seq->length-1], element);\n");
    } else {
        g_fileWrite(data->source, "corto_copyp(&seq->buffer[seq->length-1], %s_o, &element);\n", elementId);
    }

    g_fileWrite(data->source, "return &seq->buffer[seq->length-1];\n");
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");
    
    return 0;
}

/* Create size-function */
static corto_int16 c_apiSequenceTypeSize(corto_sequence o, c_apiWalk_t* data) {
    corto_id id, elementId;
    corto_bool prefix;
    corto_type elementType = corto_collection(o)->elementType;
    
    c_specifierId(data->g, corto_type(o), id, NULL, NULL);
    c_specifierId(data->g, corto_type(elementType), elementId, &prefix, NULL);
    
    /* Function declaration */
    c_writeExport(data->g, data->header);
    g_fileWrite(data->header, "void %sSize(%s *seq, corto_uint32 length);\n", id, id);
    
    /* Function implementation */
    g_fileWrite(data->source, "void %sSize(%s *seq, corto_uint32 length) {\n", id, id);
    g_fileIndent(data->source);
    g_fileWrite(data->source, "corto_uint32 size;\n");
    
    /* Deinitialize old elements if new size is smaller than old size - only valid for non-primitive types */
    if (c_apiElementRequiresInit(elementType)) {
        g_fileWrite(data->source, "if (length < seq->length) {\n");
        g_fileIndent(data->source);
        g_fileWrite(data->source, "corto_uint32 i;\n");
        g_fileWrite(data->source, "for(i=length; i<seq->length; i++) {\n");
        g_fileIndent(data->source);
        c_apiElementInit(elementId, "&seq->buffer[i]", FALSE, data);
        g_fileDedent(data->source);
        g_fileWrite(data->source, "}\n");
        g_fileDedent(data->source);
        g_fileWrite(data->source, "}\n");
    }
    
    /* Resize buffer */
    g_fileWrite(data->source, "seq->buffer = corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(%s_o))));\n", elementId);
    
    /* Initialize new elements */
    g_fileWrite(data->source, "if (length > seq->length) {\n");
    g_fileIndent(data->source);
    if (elementType->kind != CORTO_PRIMITIVE) {
        g_fileWrite(data->source, "corto_uint32 i;\n");
    }
    g_fileWrite(data->source, "memset(&seq->buffer[seq->length], 0, size * (length - seq->length));\n");
    if (elementType->kind != CORTO_PRIMITIVE) {
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
static corto_int16 c_apiSequenceTypeClear(corto_sequence o, c_apiWalk_t* data) {
    corto_id id, elementId;
    corto_bool prefix;
    corto_type elementType = corto_collection(o)->elementType;
    
    c_specifierId(data->g, corto_type(o), id, NULL, NULL);
    c_specifierId(data->g, corto_type(elementType), elementId, &prefix, NULL);
    
    /* Function declaration */
    c_writeExport(data->g, data->header);
    g_fileWrite(data->header, "void %sClear(%s *seq);\n", id, id);
    
    /* Function implementation */
    g_fileWrite(data->source, "void %sClear(%s *seq) {\n", id, id);
    g_fileIndent(data->source);
    g_fileWrite(data->source, "%sSize(seq, 0);\n", id);
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");
    
    return 0;
}

/* Walk sequence */
static corto_int16 c_apiWalkSequence(corto_sequence o, c_apiWalk_t* data) {
    corto_id id;
    
    g_fileWrite(data->header, "\n/* %s */\n", corto_fullname(o, id));
    
    data->current = o;
    
    /* Generate foreach */
    if (c_apiSequenceTypeForeach(o, data)) {
        goto error;
    }
    
    /* Generate append */
    if (c_apiSequenceTypeAppend(o, data)) {
        goto error;
    }

    /* Generate append that just returns allocated sequence */
    if (c_apiSequenceTypeAppendAlloc(o, data)) {
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
static corto_int16 c_apiListTypeForeach(corto_list o, c_apiWalk_t* data) {
    corto_id id, elementId;
    corto_bool prefix, requiresAlloc = corto_collection_elementRequiresAlloc(o);
    corto_type elementType = corto_collection(o)->elementType;
    
    c_specifierId(data->g, corto_type(o), id, NULL, NULL);
    c_specifierId(data->g, corto_type(elementType), elementId, &prefix, NULL);

    /* Macro */
    g_fileWrite(data->header, "#define %sForeach(list, elem) \\\n", id);
    g_fileIndent(data->header);
    g_fileWrite(data->header, "corto_iter elem##_iter = corto_llIter(list);\\\n");
    g_fileWrite(data->header, "%s %selem;\\\n", elementId, requiresAlloc?"*":"");
    g_fileWrite(data->header, "while(corto_iterHasNext(&elem##_iter) ? ");
    if (!elementType->reference && !requiresAlloc) {
        g_fileWrite(data->header, "elem = (%s%s)(corto_word)corto_iterNext(&elem##_iter), TRUE", elementId, requiresAlloc?"*":"");
    } else {
        g_fileWrite(data->header, "elem = corto_iterNext(&elem##_iter), TRUE");        
    }
    g_fileWrite(data->header, " : FALSE)\n");
    g_fileDedent(data->header);
    g_fileWrite(data->header, "\n");
    
    return 0;
}

static corto_string corto_operationToApi(corto_string operation, corto_id id) {
    sprintf(id, "corto_ll%s", operation);
    return id;
}

/* Create insert function for types that require allocation */
static corto_int16 c_apiListTypeInsertAlloc(corto_list o, corto_string operation, c_apiWalk_t* data) {
    corto_id id, elementId, api;
    corto_bool prefix;
    corto_type elementType = corto_collection(o)->elementType;
    
    c_specifierId(data->g, corto_type(o), id, NULL, NULL);
    c_specifierId(data->g, corto_type(elementType), elementId, &prefix, NULL);
    
    /* Function declaration */
    c_writeExport(data->g, data->header);
    g_fileWrite(data->header, "%s* %s%sAlloc(%s list);\n", elementId, id, operation, id);
    
    /* Function implementation */
    g_fileWrite(data->source, "%s* %s%sAlloc(%s list) {\n", elementId, id, operation, id);
    
    g_fileIndent(data->source);
    g_fileWrite(data->source, "%s* result;\n", elementId);
    g_fileWrite(data->source, "result = corto_calloc(corto_type_sizeof(corto_type(%s_o)));\n", elementId);
    
    /* Initialize element */
    c_apiElementInit(elementId, "result", TRUE, data);
    
    /* Insert element to list */
    g_fileWrite(data->source, "%s(list, result);\n", corto_operationToApi(operation, api));
    
    /* Return new element */
    g_fileWrite(data->source, "return result;\n");
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");
    
    return 0;
}

/* Create insert function for types that require no allocation */
static corto_int16 c_apiListTypeInsertNoAlloc(corto_list o, corto_string operation, c_apiWalk_t* data) {
    corto_id id, elementId, api;
    corto_bool prefix;
    corto_type elementType = corto_collection(o)->elementType;
    corto_bool requiresAlloc = corto_collection_elementRequiresAlloc(corto_collection(o));
    
    c_specifierId(data->g, corto_type(o), id, NULL, NULL);
    c_specifierId(data->g, corto_type(elementType), elementId, &prefix, NULL);

    c_writeExport(data->g, data->header);

    if (requiresAlloc) {
        g_fileWrite(data->header, "%s* ", elementId);
        g_fileWrite(data->source, "%s* ", elementId);
    } else {
        g_fileWrite(data->header, "void ");
        g_fileWrite(data->source, "void ");
    }
    
    /* Function declaration */
    g_fileWrite(data->header, "%s%s(%s list, %s%s element);\n", 
        id, operation, id, elementId, requiresAlloc ? "*" : "");
    
    /* Function implementation */
    g_fileWrite(data->source, "%s%s(%s list, %s%s element) {\n", 
        id, operation, id, elementId, requiresAlloc ? "*" : "");

    g_fileIndent(data->source);
    
    /* Insert element to list */
    if (requiresAlloc) {
        g_fileWrite(data->source, "%s *result = %s%sAlloc(list);\n", elementId, id, operation);
        g_fileWrite(data->source, "corto_copyp(result, %s_o, element);\n", elementId);
    } else {
        g_fileWrite(data->source, "%s(list, (void*)(corto_word)element);\n", corto_operationToApi(operation, api));
        if (elementType->reference) {
            g_fileWrite(data->source, "corto_claim(element);\n");
        }
    }

    if (requiresAlloc) {
        g_fileWrite(data->source, "return result;\n");
    }
    
    /* Return new element */
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");
    
    return 0;
}

/* Create insert-function */
static corto_int16 c_apiListTypeInsert(corto_list o, corto_string operation, c_apiWalk_t* data) {
    corto_int16 result;
    
    if (corto_collection_elementRequiresAlloc(corto_collection(o))) {
        result = c_apiListTypeInsertAlloc(o, operation, data);
        result = c_apiListTypeInsertNoAlloc(o, operation, data);
    } else {
        result = c_apiListTypeInsertNoAlloc(o, operation, data);
    }
    
    return result;
}

/* Create take function for types that require allocation */
static corto_int16 c_apiListTypeTake(corto_list o, corto_string operation, c_apiWalk_t* data) {
    corto_id id, elementId, api;
    corto_bool prefix;
    corto_type elementType = corto_collection(o)->elementType;
    corto_bool allocRequired = corto_collection_elementRequiresAlloc(corto_collection(o));
    
    c_specifierId(data->g, corto_type(o), id, NULL, NULL);
    c_specifierId(data->g, corto_type(elementType), elementId, &prefix, NULL);
    
    /* Function declaration */
    c_writeExport(data->g, data->header);
    g_fileWrite(data->header, "%s%s %s%s(%s list);\n", elementId, allocRequired?"*":"", id, operation, id);
    
    /* Function implementation */
    g_fileWrite(data->source, "%s%s %s%s(%s list) {\n", elementId, allocRequired?"*":"", id, operation, id);
    g_fileIndent(data->source);
    
    /* Insert element to list */
    g_fileWrite(data->source, "return (%s%s)(corto_word)%s(list);\n", elementId, allocRequired?"*":"", corto_operationToApi(operation, api));

    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");
    
    return 0;
}

/* Create clear function for types that require allocation */
static corto_int16 c_apiListTypeClear(corto_list o, c_apiWalk_t* data) {
    corto_id id, elementId;
    corto_bool prefix;
    corto_type elementType = corto_collection(o)->elementType;
    corto_bool allocRequired = corto_collection_elementRequiresAlloc(corto_collection(o));
    
    c_specifierId(data->g, corto_type(o), id, NULL, NULL);
    c_specifierId(data->g, corto_type(elementType), elementId, &prefix, NULL);
    
    /* Function declaration */
    c_writeExport(data->g, data->header);
    g_fileWrite(data->header, "void %sClear(%s list);\n", id, id);
    
    /* Function implementation */
    g_fileWrite(data->source, "void %sClear(%s list) {\n", id, id);
    g_fileIndent(data->source);
    g_fileWrite(data->source, "void *element;\n\n");
    g_fileWrite(data->source, "while((element = corto_llTakeFirst(list))) {\n");
    g_fileIndent(data->source);
    if (allocRequired) {
        c_apiElementInit(elementId, "element", FALSE, data);
        g_fileWrite(data->source, "corto_dealloc(element);\n");
    } else if (elementType->reference) {
        g_fileWrite(data->source, "corto_release(element);\n");
    }
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n");
    
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");
    
    return 0;
}

/* Create get function for types that require allocation */
static corto_int16 c_apiListTypeGet(corto_list o, c_apiWalk_t* data) {
    corto_id id, elementId;
    corto_bool prefix;
    corto_type elementType = corto_collection(o)->elementType;
    corto_bool allocRequired = corto_collection_elementRequiresAlloc(corto_collection(o));
    
    c_specifierId(data->g, corto_type(o), id, NULL, NULL);
    c_specifierId(data->g, corto_type(elementType), elementId, &prefix, NULL);
    
    /* Function declaration */
    c_writeExport(data->g, data->header);
    g_fileWrite(data->header, "%s%s %sGet(%s list, corto_uint32 index);\n", elementId, allocRequired?"*":"", id, id);
    
    /* Function implementation */
    g_fileWrite(data->source, "%s%s %sGet(%s list, corto_uint32 index) {\n", elementId, allocRequired?"*":"", id, id);
    g_fileIndent(data->source);
    
    /* Insert element to list */
    g_fileWrite(data->source, "return (%s%s)(corto_word)corto_llGet(list, index);\n", elementId, allocRequired?"*":"");
    
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");
    
    return 0;
}

/* Create insert function for types that require allocation */
static corto_int16 c_apiListTypeSize(corto_list o, c_apiWalk_t* data) {
    corto_id id, elementId;
    corto_bool prefix;
    corto_type elementType = corto_collection(o)->elementType;
    
    c_specifierId(data->g, corto_type(o), id, NULL, NULL);
    c_specifierId(data->g, corto_type(elementType), elementId, &prefix, NULL);
    
    /* Function declaration */
    c_writeExport(data->g, data->header);
    g_fileWrite(data->header, "corto_uint32 %sSize(%s list);\n", id, id);
    
    /* Function implementation */
    g_fileWrite(data->source, "corto_uint32 %sSize(%s list) {\n", id, id);
    g_fileIndent(data->source);
    
    /* Insert element to list */
    g_fileWrite(data->source, "return corto_llSize(list);\n");
    
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");
    
    return 0;
}

/* Walk list */
static corto_int16 c_apiWalkList(corto_list o, c_apiWalk_t* data) {
    corto_id id;
    
    g_fileWrite(data->header, "\n/* %s */\n", corto_fullname(o, id));
    
    data->current = o;
    
    if (c_apiListTypeForeach(o, data)) {
        goto error;
    }
    
    if (c_apiListTypeInsert(o, "Insert", data)) {
        goto error;
    }
    
    if (c_apiListTypeInsert(o, "Append", data)) {
        goto error;
    }

    if (c_apiListTypeTake(o, "TakeFirst", data)) {
        goto error;
    }
    
    if (c_apiListTypeTake(o, "Last", data)) {
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
    switch(corto_collection(o)->kind) {
        case CORTO_SEQUENCE:
            if (c_apiWalkSequence(corto_sequence(o), userData)) {
                goto error;
            }
            break;
        case CORTO_LIST:
            if (c_apiWalkList(corto_list(o), userData)) {
                goto error;
            }
            break;
        case CORTO_MAP:
            /*if (c_apiWalkMap(corto_map(o), userData)) {
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
