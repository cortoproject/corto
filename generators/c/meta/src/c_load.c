/*
 * c_load.c
 *
 *  Created on: Sep 20, 2012
 *      Author: sander
 */

#include "corto.h"
#include "c_common.h"
#include "corto_string_ser.h"

typedef struct c_typeWalk_t {
    corto_generator g;
    g_file header;
    g_file source;
    corto_uint32 firstComma;
    corto_uint32 errorCount;
} c_typeWalk_t;

/* Resolve object */
static corto_char* c_loadResolve(corto_object o, corto_char* out, corto_char* src, corto_char* context) {
    if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
        corto_id id, escaped;
        corto_fullname(o, id);

        if (!(src || context)) {
            sprintf(out, "corto_resolve(NULL, \"%s\")", c_escapeString(id, escaped));
        } else {
            if (!src) {
                src = "NULL";
            }
            if (!context) {
                context = "NULL";
            }
            sprintf(out, "corto_resolve(NULL, \"%s\")", c_escapeString(id, escaped));
        }
    } else {
        corto_id ostr, id, escapedId, escapedOstr, escapedContextStr;
        struct corto_serializer_s stringSer;
        corto_string_ser_t data;

        /* Serialize object string */
        stringSer = corto_string_ser(CORTO_LOCAL, CORTO_NOT, CORTO_SERIALIZER_TRACE_ON_FAIL);

        *ostr = '\0';
        data.compactNotation = TRUE;
        data.buffer = id;
        data.length = sizeof(ostr);
        data.maxlength = 0;
        data.prefixType = FALSE;
        data.enableColors = FALSE;
        if (corto_serialize(&stringSer, o, &data)) {
            goto error;
        }
        c_escapeString(id, escapedOstr);

        corto_fullname(corto_typeof(o), id);
        c_escapeString(id, escapedId);

        if (!(src || context)) {
            sprintf(out, "corto_resolve(NULL, \"%s%s\")", escapedId, escapedOstr);
        } else {
            if (!src) {
                src = "NULL";
            }
            if (!context) {
                context = "NULL";
            }
            c_escapeString(context, escapedContextStr);
            sprintf(out, "corto_resolve(NULL, \"%s%s\")", escapedId, escapedOstr);
        }
    }

    return out;
error:
    return NULL;
}

/* Get variable id */
static corto_char* c_loadVarId(corto_generator g, corto_object o, corto_char* out) {
    if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
        if (o != root_o) {
            g_fullOid(g, o, out);
            strcat(out, "_o");
        } else {
            strcpy(out, "root_o");
        }
    } else {
        corto_id id;
        sprintf(out, "%s", c_loadResolve(o, id, NULL, NULL));
    }
    return out;
}

/* Get element id, for lists and maps. */
static corto_char* c_loadElementId(corto_value* v, corto_char* out, corto_int32 offset) {
    corto_uint32 i;
    corto_value* ptr;

    i = 0;
    ptr = v;

    do {
        if (ptr->kind == CORTO_ELEMENT) {
            i++;
        }
    } while((ptr = ptr->parent));

    sprintf(out, "_e%d_", i + offset);

    return out;
}

/* This function translates from a value-object to a valid C-string identifying a
 * part of the object that is being serialized. */
static corto_char* c_loadMemberId(c_typeWalk_t* data, corto_value* v, corto_char* out, corto_bool addMemberOperator) {
    corto_value* stack[CORTO_MAX_TYPE_DEPTH];
    corto_uint32 count;
    corto_value *ptr;
    corto_object o;
    corto_type thisType;
    corto_bool objectIsArray, derefMemberOperator;

    *out = '\0';

    /* Build serializer-stack */
    ptr = v;
    count = 0;
    while ((ptr->kind != CORTO_OBJECT) && (ptr->kind != CORTO_BASE)) {
        stack[count] = ptr;
        ptr = ptr->parent;
        count++;
    }
    stack[count] = ptr;

    /* Print object */
    o = corto_valueObject(v);

    /* If object is a collection or primtive, dereference object pointer */
    objectIsArray = 
        (corto_typeof(o)->kind == CORTO_PRIMITIVE) || 
        (corto_typeof(o)->kind == CORTO_COLLECTION);

    /* Use '->' operator whenever possible */
    if (!objectIsArray) {
        derefMemberOperator = TRUE;
    } else {
        derefMemberOperator = FALSE;
    }

    /* Start with a dereference */
    if (objectIsArray) {
        strcpy(out, "(*");
    }

    /* If the first found object-value in the value-stack is not of the type of the object,
     * cast it. This happens when using inheritance. */
    thisType = corto_valueType(ptr);
    if (corto_type(thisType) != corto_typeof(o)) {
        corto_id id, parentId, objectId;
        sprintf(id, "%s(%s)",
                g_fullOid(data->g, thisType, parentId),
                c_loadVarId(data->g, corto_valueObject(v), objectId));
        strcat(out, id);
    } else {
        corto_id objectId;
        strcat(out, c_loadVarId(data->g, corto_valueObject(v), objectId));
    }

    /* End bracket used for dereferencing object */
    if (objectIsArray) {
        strcat(out, ")");
    }

    /* Walk serializer stack */
    while (count) {
        count--;

        switch (stack[count]->kind) {

        /* Member */
        case CORTO_MEMBER:
            /* When previous object is a reference, use -> operator. */
            if (derefMemberOperator) {
                strcat(out, "->");
                derefMemberOperator = FALSE;
            } else {
                strcat(out, ".");
            }

            /* Reference member using it's name. */
            corto_id memberId;
            strcat(out, g_id(data->g, corto_nameof(stack[count]->is.member.t), memberId));
            break;

        /* Element */
        case CORTO_ELEMENT: {
            corto_collection t;
            corto_char arrayIndex[24];

            t = corto_collection(corto_valueType(stack[count+1]));

            switch (t->kind) {

            /* Array element, use array operator. */
            case CORTO_ARRAY:
                sprintf(arrayIndex, "[%d]", stack[count]->is.element.t.index);
                strcat(out, arrayIndex);
                break;

            /* Sequence element, use buffer-array */
            case CORTO_SEQUENCE:
                if (derefMemberOperator) {
                    strcat(out, "->");
                } else {
                    strcat(out, ".");
                }
                sprintf(arrayIndex, "buffer[%d]", stack[count]->is.element.t.index);
                strcat(out, arrayIndex);
                break;

            /* Use elementId's for non-array collections. */
            default: {
                corto_char elementId[9]; /* One-million nested collections should be adequate in most cases. */

                if ((corto_valueType(stack[count])->kind == CORTO_COLLECTION) && (corto_collection(corto_valueType(stack[count]))->kind == CORTO_ARRAY)) {
                    sprintf(out, "(*%s)", c_loadElementId(stack[count], elementId, 0));
                } else {
                    sprintf(out, "%s", c_loadElementId(stack[count], elementId, 0));
                    derefMemberOperator = TRUE;
                }
                break;
            }
            }
            break;
        }

        /* CORTO_OBJECT and CORTO_CONSTANT will not be encountered in this loop. */
        default:
            corto_assert(0, "invalid valueKind at this place.");
            break;
        }
    }

    if (addMemberOperator) {
        if (derefMemberOperator) {
            strcat(out, "->");
        } else {
            strcat(out, ".");
        }
    }

    return out;
}

/* Walk types */
static int c_loadDeclareWalk(corto_object o, void* userData) {
    c_typeWalk_t* data;
    corto_id specifier, postfix, objectId;
    corto_type t;
    corto_bool prefix;
    corto_object parent;

    data = userData;
    t = corto_typeof(o);

    parent = corto_parentof(o);
    if (parent && (parent != root_o) && (!g_mustParse(data->g, parent))) {
        c_loadDeclareWalk(corto_parentof(o), userData);
    }

    /* Get C typespecifier */
    if (c_specifierId(data->g, t, specifier, &prefix, postfix)) {
        goto error;
    }

    if (o != g_getCurrent(data->g)) {
        c_writeExport(data->g, data->header);        
    }

    /* Declare objects in headerfile and define in sourcefile */
    if (!prefix) {
        g_fileWrite(data->header, "extern %s %s%s;\n", specifier, c_loadVarId(data->g, o, objectId), postfix);
        g_fileWrite(data->source, "%s %s%s;\n", specifier, objectId, postfix);
    } else {
        g_fileWrite(data->header, "extern %s ___ (*%s)%s;\n", specifier, c_loadVarId(data->g, o, objectId), postfix);
        g_fileWrite(data->source, "%s ___ (*%s)%s;\n", specifier, objectId, postfix);
    }

    return 1;
error:
    return 0;
}

/* Open generator headerfile */
static g_file c_loadHeaderFileOpen(corto_generator g) {
    g_file result;
    corto_id headerFileName, path;

    /* Create file */
    sprintf(headerFileName, "%s__meta.h", g_getName(g));
    result = g_fileOpen(g, headerFileName);

    /* Print standard comments and includes */
    g_fileWrite(result, "/* %s\n", headerFileName);
    g_fileWrite(result, " *\n");
    g_fileWrite(result, " * Loads objects in object store.\n");
    g_fileWrite(result, " * This file contains generated code. Do not modify!\n");
    g_fileWrite(result, " */\n\n");
    g_fileWrite(result, "#ifndef %s_META_H\n", c_topath(g_getCurrent(g), path, '_'));
    g_fileWrite(result, "#define %s_META_H\n\n", c_topath(g_getCurrent(g), path, '_'));
    g_fileWrite(result, "#include \"corto.h\"\n");
    g_fileWrite(result, "#include \"%s__interface.h\"\n\n", g_getName(g));
    g_fileWrite(result, "#ifdef __cplusplus\n");
    g_fileWrite(result, "extern \"C\" {\n");
    g_fileWrite(result, "#endif\n\n");

    return result;
}

/* Close headerfile */
static void c_loadHeaderFileClose(corto_generator g, g_file file) {
    CORTO_UNUSED(g);

    /* Print standard comments and includes */
    g_fileWrite(file, "\n");
    g_fileWrite(file, "#ifdef __cplusplus\n");
    g_fileWrite(file, "}\n");
    g_fileWrite(file, "#endif\n");
    g_fileWrite(file, "#endif\n\n");
}

/* Open generator sourcefile */
static g_file c_loadSourceFileOpen(corto_generator g) {
    g_file result;
    corto_id headerFileName;
    corto_id topLevelName;

    /* Create file */
    sprintf(headerFileName, "%s__meta.c", g_getName(g));
    result = g_hiddenFileOpen(g, headerFileName);

    /* Print standard comments and includes */
    g_fileWrite(result, "/* %s\n", headerFileName);
    g_fileWrite(result, " *\n");
    g_fileWrite(result, " * Loads objects in object store.\n");
    g_fileWrite(result, " * This file contains generated code. Do not modify!\n");
    g_fileWrite(result, " */\n\n");
    g_fileWrite(result, "#include \"%s.h\"\n\n", g_fullOid(g, g_getCurrent(g), topLevelName));

    return result;
}

/* Write starting comment of variable definitions */
static void c_sourceWriteVarDefStart(g_file file) {
    g_fileWrite(file, "/* Variable definitions */\n");
}

/* Write start of load-routine */
static void c_sourceWriteLoadStart(corto_generator g, g_file file) {
    g_fileWrite(file, "\n");
    g_fileWrite(file, "/* Load objects in object store. */\n");
    g_fileWrite(file, "int %s_load(void) {\n", g_getName(g));
    g_fileIndent(file);
    g_fileWrite(file, "corto_object _a_; /* Used for resolving anonymous objects */\n");
    g_fileWrite(file, "_a_ = NULL;\n\n");
}

/* Write end of load-routine */
static void c_sourceWriteLoadEnd(g_file file, c_typeWalk_t *data) {
    g_fileWrite(file, "if (_a_) {\n");
    g_fileIndent(file);
    g_fileWrite(file, "corto_release(_a_);\n");
    g_fileDedent(file);
    g_fileWrite(file, "}\n\n");
    g_fileWrite(file, "return 0;\n");
    if (data->errorCount) {
        g_fileDedent(file);
        g_fileWrite(file, "error:\n");
        g_fileIndent(file);
        g_fileWrite(file, "if (_a_) {\n");
        g_fileIndent(file);
        g_fileWrite(file, "corto_release(_a_);\n");
        g_fileDedent(file);
        g_fileWrite(file, "}\n\n");
        g_fileWrite(file, "return -1;\n");
    }
    g_fileDedent(file);
    g_fileWrite(file, "}\n");
}

/* Print variable start */
static void c_varPrintStart(corto_value* v, c_typeWalk_t* data) {
    corto_id memberId;
    corto_type t;

    t = corto_valueType(v);

    /* Only write an identifier if the object is a primitive type, or a reference. */
    if ((t->kind == CORTO_PRIMITIVE) || (t->reference && !(v->kind == CORTO_OBJECT))) {
        /* Print memberId if object is member */
        g_fileWrite(data->source, "%s = ",
                c_loadMemberId(data, v, memberId, FALSE));
    }
}

/* Print variable end */
static void c_varPrintEnd(corto_value* v, c_typeWalk_t* data) {
    corto_type t;

    /* Get member object */
    t = corto_valueType(v);
    if ((t->kind == CORTO_PRIMITIVE) || (t->reference && !(v->kind == CORTO_OBJECT))) {
        /* Print end of member-assignment */
        g_fileWrite(data->source, ";\n");
    }
}

/* c_initPrimitive */
static corto_int16 c_initPrimitive(corto_serializer s, corto_value* v, void* userData) {
    void* ptr;
    corto_type t;
    corto_string str;
    c_typeWalk_t* data;
    CORTO_UNUSED(s);

    ptr = corto_valueValue(v);
    t = corto_valueType(v);
    data = userData;
    str = NULL;

    c_varPrintStart(v, userData);

    /* Treat booleans separately, the default convert translates booleans to 'true' and 'false' while
     * the language mapping of C TRUE and FALSE is. */
    if (corto_primitive(t)->kind == CORTO_BOOLEAN) {
        if (*(corto_bool*)ptr) {
            str = corto_strdup("TRUE");
        } else {
            str = corto_strdup("FALSE");
        }
    } else if (corto_primitive(t)->kind == CORTO_ENUM) {
        corto_id enumId;

        /* Convert constant-name to language id */
        str = corto_strdup(c_constantId(data->g, corto_enum_constant(corto_enum(t), *(corto_uint32*)ptr), enumId));
    } else if (corto_primitive(t)->kind == CORTO_BITMASK) {
        str = corto_alloc(11);
        sprintf(str, "0x%x", *(corto_uint32*)ptr);
    } else if (corto_primitive(t)->kind == CORTO_TEXT) {
        corto_string v = *(corto_string*)ptr;
        if (v) {
            size_t n = stresc(NULL, 0, v);
            str = malloc(strlen("corto_strdup(\"\")") + n + 1);
            strcpy(str, "corto_strdup(\"");
            stresc(str + strlen("corto_strdup(\""), n + 1, v);
            strcat(str, "\")");
        } else {
            str = corto_strdup("NULL");
        }
    } else if (corto_primitive(t)->kind == CORTO_CHARACTER) {
        corto_char v = *(corto_char*)ptr;
        char buff[3];
        str = malloc(strlen(buff) + 1 + 2);
        if (v) {
            chresc(buff, v, '\'')[0] = '\0';
            sprintf(str, "'%s'", buff);
        } else {
            sprintf(str, "'\\0'");
        }
    } else {
        /* Convert primitive value to string using built-in conversion */
        if (corto_convert(corto_primitive(t), ptr, corto_primitive(corto_string_o), &str)) {
            goto error;
        }
    }

    g_fileWrite(data->source, "%s", str);
    corto_dealloc(str);

    c_varPrintEnd(v, userData);

    return 0;
error:
    return -1;
}

/* c_initReference */
static corto_int16 c_initReference(corto_serializer s, corto_value* v, void* userData) {
    corto_object *optr, o;
    c_typeWalk_t* data;
    CORTO_UNUSED(s);

    data = userData;
    optr = corto_valueValue(v);

    c_varPrintStart(v, userData);

    if ((o = *optr)) {
        corto_id id, src, context;
        c_loadVarId(data->g, corto_valueObject(v), src);
        corto_strving(v, context, 256);
        g_fileWrite(data->source, "%s", c_loadResolve(o, id, src, context));
    } else {
        g_fileWrite(data->source, "NULL");
    }

    c_varPrintEnd(v, userData);

    return 0;
}

/* c_initElement */
static corto_int16 c_initElement(corto_serializer s, corto_value* v, void* userData) {
    c_typeWalk_t* data = userData;
    corto_collection t = corto_collection(corto_valueType(v->parent));
    corto_bool requiresAlloc = corto_collection_elementRequiresAlloc(t);

    /* Allocate space for element */
    switch (t->kind) {
    case CORTO_LIST:
    case CORTO_MAP: {
        corto_id elementId, specifier, postfix;
        g_fileWrite(data->source, "\n");

        if (requiresAlloc) {
            c_specifierId(data->g, t->elementType, specifier, NULL, postfix);
            g_fileWrite(data->source, "%s = corto_alloc(sizeof(%s%s));\n", c_loadElementId(v, elementId, 0), specifier, postfix);
        }
        break;
    }
    default:
        break;
    }

    /* Serialize value */
    if (corto_serializeValue(s, v, data)) {
        goto error;
    }

    switch (t->kind) {
    case CORTO_LIST: {
        corto_id parentId, elementId;
        g_fileWrite(data->source, "corto_llAppend(%s, %s%s);\n",
                c_loadMemberId(data, v->parent, parentId, FALSE),
                requiresAlloc ? "" : "(void*)", c_loadElementId(v, elementId, 0));
        break;
    }
    case CORTO_MAP: /*{
        corto_id parentId, elementId;
        g_fileWrite(data->source, "corto_rbtreeSet(%s, %s)",
                c_loadMemberId(data->g, v->parent, parentId),
                c_loadElementId(v, elementId, 0));
        break;
    }*/
    default:
        break;
    }

    return 0;
error:
    return -1;
}

/* c_initCollection */
static corto_int16 c_initCollection(corto_serializer s, corto_value* v, void* userData) {
    corto_collection t;
    c_typeWalk_t* data;
    corto_id memberId;
    int result;
    void* ptr;
    corto_uint32 size = 0;

    ptr = corto_valueValue(v);

    t = corto_collection(corto_valueType(v));
    data = userData;

    switch (t->kind) {
    case CORTO_ARRAY:
        size = t->max;
        break;
    case CORTO_SEQUENCE: {
        corto_uint32 length;
        corto_id specifier, postfix;

        length = *(corto_uint32*)ptr;
        size = length;

        /* Set length of sequence */
        g_fileWrite(data->source, "%slength = %d;\n",
                c_loadMemberId(data, v, memberId, TRUE),
                length);

        /* Get type-specifier */
        c_specifierId(data->g, t->elementType, specifier, NULL, postfix);

        /* Allocate buffer */
        if (!length) {
            g_fileWrite(data->source, "%sbuffer = NULL;\n",
                    c_loadMemberId(data, v, memberId, TRUE));
        } else if (length == 1) {
            g_fileWrite(data->source, "%sbuffer = corto_alloc(sizeof(%s%s));\n",
                    c_loadMemberId(data, v, memberId, TRUE),
                    specifier, postfix);
        } else {
            g_fileWrite(data->source, "%sbuffer = corto_alloc(sizeof(%s%s) * %d);\n",
                    c_loadMemberId(data, v, memberId, TRUE),
                    specifier, postfix,
                    length);
        }
        break;
    }
    case CORTO_LIST:
        /* Create list object */
        if (*(corto_ll*)ptr) {
            g_fileWrite(data->source, "%s = corto_llNew();\n",
                    c_loadMemberId(data, v, memberId, FALSE));
        } else {
            g_fileWrite(data->source, "%s = NULL;\n", c_loadMemberId(data, v, memberId, FALSE));
        }
        size = corto_llSize(*(corto_ll*)ptr);
        break;
    case CORTO_MAP: {
        corto_id keyId;
        /* Create map object */
        if (*(corto_rbtree*)ptr) {
            g_fileWrite(data->source, "%s = corto_rbtreeNew(%s);\n",
                    c_loadMemberId(data, v, memberId, FALSE), g_fullOid(data->g, corto_rbtreeKeyType(*(corto_rbtree*)ptr), keyId));
        } else {
            g_fileWrite(data->source, "%s = NULL;\n", c_loadMemberId(data, v, memberId, FALSE));
        }
        size = corto_rbtreeSize(*(corto_rbtree*)ptr);
        break;
    }
    }

    /* For the non-array types, allocate a member variable, if size of collection is not zero. */
    if (size) {
        switch (t->kind) {
        case CORTO_LIST:
        case CORTO_MAP: {
            corto_id elementId, elementTypeId;
            g_fileWrite(data->source, "{\n");
            g_fileIndent(data->source);

            g_fileWrite(
                data->source, 
                "%s%s %s;\n", 
                g_fullOid(data->g, t->elementType, elementTypeId), 
                corto_collection_elementRequiresAlloc(t) ? "*" : "",
                c_loadElementId(v, elementId, 1));

            break;
        }
        default:
            break;
        }
    }

    /* Serialize elements */
    result = corto_serializeElements(s, v, userData);

    if (size) {
        switch (t->kind) {
        case CORTO_LIST:
        case CORTO_MAP: {
            g_fileDedent(data->source);
            g_fileWrite(data->source, "}\n");
            break;
        }
        default:
            break;
        }
    }

    return result;
}

/* Write forward-declaration to interface function, return name. */
static int c_loadCFunction(corto_function o, c_typeWalk_t* data, corto_id name) {

    /* Print name */
    g_fullOid(data->g, o, name);
    if (c_procedureHasThis(o)) {
        if (corto_instanceof(corto_type(corto_method_o), o) && corto_method(o)->_virtual) {
            strcat(name, "_v");
        }
    }

    return 0;
}

/* Create serializer that initializes object values */
static struct corto_serializer_s c_initSerializer(void) {
    struct corto_serializer_s s;

    corto_serializerInit(&s);

    s.access = CORTO_LOCAL;
    s.accessKind = CORTO_NOT;
    s.aliasAction = CORTO_SERIALIZER_ALIAS_IGNORE;
    s.traceKind = CORTO_SERIALIZER_TRACE_ON_FAIL;
    s.program[CORTO_PRIMITIVE] = c_initPrimitive;
    s.program[CORTO_COLLECTION] = c_initCollection;
    s.metaprogram[CORTO_ELEMENT] = c_initElement;
    s.reference = c_initReference;

    return s;
}

/* Declare object */
static int c_loadDeclare(corto_object o, void* userData) {
    c_typeWalk_t* data;
    corto_id id, parentId, typeId, escapedName;

    data = userData;

    /* Only declare scoped objects */
    if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
        c_escapeString(corto_nameof(o), escapedName);

        /* Declaration */
        g_fileWrite(data->source, "/* Declare %s */\n", corto_fullname(o, id));

        if (!corto_checkAttr(corto_typeof(o), CORTO_ATTR_SCOPED)) {
            g_fileWrite(data->source, "%s = corto_declareChild(%s, \"%s\", (_a_ ? corto_release(_a_) : 0, _a_ = %s));\n",
                    c_loadVarId(data->g, o, id),
                    c_loadVarId(data->g, corto_parentof(o), parentId),
                    escapedName,
                    c_loadVarId(data->g, corto_typeof(o), typeId));
        } else {
            g_fileWrite(data->source, "%s = corto_declareChild(%s, \"%s\", %s);\n",
                    c_loadVarId(data->g, o, id),
                    c_loadVarId(data->g, corto_parentof(o), parentId),
                    escapedName,
                    c_loadVarId(data->g, corto_typeof(o), typeId));
        }

        /* Error checking */
        g_fileWrite(data->source, "if (!%s) {\n", c_loadVarId(data->g, o, id));
        g_fileIndent(data->source);
        c_escapeString(corto_fullname(o, id), escapedName);
        g_fileWrite(data->source, "corto_error(\"%s_load: failed to declare '%s' (%%s)\", corto_lasterr());\n",
                g_getName(data->g),
                escapedName);
        g_fileWrite(data->source, "goto error;\n");
        data->errorCount++;
        g_fileDedent(data->source);

        g_fileWrite(data->source, "}\n\n");
    }

    return 1;
}

/* Define object */
static int c_loadDefine(corto_object o, void* userData) {
    struct corto_serializer_s s;

    if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
        c_typeWalk_t* data;
        corto_id escapedId, fullname, varId, typeId;

        data = userData;

        corto_fullname(o, fullname);
        c_loadVarId(data->g, o, varId);
        g_fullOid(data->g, o, typeId);

        g_fileWrite(data->source, "/* Define %s */\n", fullname);
        g_fileWrite(data->source, "if (!corto_checkState(%s, CORTO_DEFINED)) {\n", varId);
        g_fileIndent(data->source);

        /* Serialize object if object is not a primitive */
        s = c_initSerializer();
        corto_serialize(&s, o, userData);

        /* If object is a procedure, set function implementation */
        if (corto_class_instanceof(corto_procedure_o, corto_typeof(o))) {
            corto_id name;
            g_fileWrite(data->source, "\n");
            if (!corto_function(o)->impl) {
                g_fileWrite(data->source, "/* Bind %s with C-function */\n", fullname);
                g_fileWrite(data->source, "corto_function(%s)->kind = CORTO_PROCEDURE_CDECL;\n", varId);
                c_loadCFunction(o, data, name);
                g_fileWrite(data->source, "void __%s(void *args, void *result);\n", name);
                g_fileWrite(data->source, "corto_function(%s)->impl = (corto_word)__%s;\n", varId, name);
            }
        }

        /* Define object */
        g_fileWrite(data->source, "if (corto_define(%s)) {\n", varId);
        g_fileIndent(data->source);
        g_fileWrite(data->source, "corto_error(\"%s_load: failed to define '%s' (%%s)\", corto_lasterr());\n",
                g_getName(data->g),
                c_escapeString(fullname, escapedId));
        g_fileWrite(data->source, "goto error;\n");
        data->errorCount++;
        g_fileDedent(data->source);
        g_fileWrite(data->source, "}\n");
        g_fileDedent(data->source);
        g_fileWrite(data->source, "}\n\n");

        /* Do size validation - this makes porting to other platforms easier */
        if (corto_instanceof(corto_type(corto_type_o), o)) {
            if (corto_type(o)->reference) {
                g_fileWrite(data->source, "if (corto_type(%s)->size != sizeof(struct %s_s)) {\n", 
                    varId,
                    typeId);
                g_fileIndent(data->source);
                g_fileWrite(data->source, 
                    "corto_error(\"%s_load: calculated size '%%d' of type '%s' doesn't match C-type size '%%d'\", corto_type(%s)->size, sizeof(struct %s_s));\n", 
                    g_getName(data->g),
                    fullname,
                    varId,
                    typeId);
            } else {
                g_fileWrite(data->source, "if (corto_type(%s)->size != sizeof(%s)) {\n", 
                    varId,
                    typeId);
                g_fileIndent(data->source);
                g_fileWrite(data->source, 
                    "corto_error(\"%s_load: calculated size '%%d' of type '%s' doesn't match C-type size '%%d'\", corto_type(%s)->size, sizeof(%s));\n", 
                    g_getName(data->g),
                    fullname,
                    varId,
                    typeId);
            }
            g_fileDedent(data->source);
            g_fileWrite(data->source, "}\n\n");
        }
    }

    return 1;
}

/* Entry point for generator */
int corto_genMain(corto_generator g) {
    c_typeWalk_t walkData;

    /* Default prefixes for corto namespaces */
    gen_parse(g, corto_o, FALSE, FALSE, "");
    gen_parse(g, corto_lang_o, FALSE, FALSE, "corto");

    /* Prepare walkData, create header- and sourcefile */
    walkData.g = g;
    walkData.header = c_loadHeaderFileOpen(g);
    walkData.source = c_loadSourceFileOpen(g);
    walkData.errorCount = 0;

    /* Write comment indicating definitions in sourcefile */
    c_sourceWriteVarDefStart(walkData.source);

    /* Walk objects, declare variables in header and sourcefile */
    if (!g_walkRecursive(g, c_loadDeclareWalk, &walkData)) {
        goto error;
    }

    /* Create load-routine */
    c_sourceWriteLoadStart(g, walkData.source);

    /* Walk objects in dependency order */
    if (corto_genDepWalk(g, c_loadDeclare, c_loadDefine, &walkData)) {
        corto_trace("generation of load-routine failed while resolving dependencies.");
        goto error;
    }

    /* Close load-routine */
    c_sourceWriteLoadEnd(walkData.source, &walkData);

    /* Close headerfile */
    c_loadHeaderFileClose(g, walkData.header);

    return 0;
error:
    return -1;
}
