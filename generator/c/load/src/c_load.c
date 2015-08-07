/*
 * c_load.c
 *
 *  Created on: Sep 20, 2012
 *      Author: sander
 */

#include "cx.h"
#include "cx_generatorDepWalk.h"
#include "c_common.h"
#include "cx_string_ser.h"

typedef struct c_typeWalk_t {
    cx_generator g;
    g_file header;
    g_file source;
    cx_uint32 firstComma;
} c_typeWalk_t;

/* Resolve object */
static cx_char* c_loadResolve(cx_object o, cx_char* out, cx_char* src, cx_char* context) {
    if (cx_checkAttr(o, CX_ATTR_SCOPED)) {
        cx_id id, escaped;
        cx_fullname(o, id);

        if (!(src || context)) {
            sprintf(out, "cx_resolve(NULL, \"%s\")", c_escapeString(id, escaped));
        } else {
            if (!src) {
                src = "NULL";
            }
            if (!context) {
                context = "NULL";
            }
            sprintf(out, "cx_resolve(NULL, \"%s\")", c_escapeString(id, escaped));
        }
    } else {
        cx_id ostr, id, escapedId, escapedOstr, escapedContextStr;
        struct cx_serializer_s stringSer;
        cx_string_ser_t data;

        /* Serialize object string */
        stringSer = cx_string_ser(CX_LOCAL, CX_NOT, CX_SERIALIZER_TRACE_ON_FAIL);

        *ostr = '\0';
        data.compactNotation = TRUE;
        data.buffer = id;
        data.length = sizeof(ostr);
        data.maxlength = 0;
        data.prefixType = FALSE;
        data.enableColors = FALSE;
        if (cx_serialize(&stringSer, o, &data)) {
            goto error;
        }
        c_escapeString(id, escapedOstr);

        cx_fullname(cx_typeof(o), id);
        c_escapeString(id, escapedId);

        if (!(src || context)) {
            sprintf(out, "cx_resolve(NULL, \"%s%s\")", escapedId, escapedOstr);
        } else {
            if (!src) {
                src = "NULL";
            }
            if (!context) {
                context = "NULL";
            }
            c_escapeString(context, escapedContextStr);
            sprintf(out, "cx_resolve(NULL, \"%s%s\")", escapedId, escapedOstr);
        }
    }

    return out;
error:
    return NULL;
}

/* Get variable id */
static cx_char* c_loadVarId(cx_generator g, cx_object o, cx_char* out) {
    if (cx_checkAttr(o, CX_ATTR_SCOPED)) {
        if (o != root_o) {
            g_fullOid(g, o, out);
            strcat(out, "_o");
        } else {
            strcpy(out, "root_o");
        }
    } else {
        cx_id id;
        sprintf(out, "%s", c_loadResolve(o, id, NULL, NULL));
    }
    return out;
}

/* Get element id, for lists and maps. */
static cx_char* c_loadElementId(cx_value* v, cx_char* out, cx_int32 offset) {
    cx_uint32 i;
    cx_value* ptr;

    i = 0;
    ptr = v;

    do {
        if (ptr->kind == CX_ELEMENT) {
            i++;
        }
    } while((ptr = ptr->parent));

    sprintf(out, "_e%d_", i + offset);

    return out;
}

/* This function translates from a value-object to a valid C-string identifying a
 * part of the object that is being serialized. */
static cx_char* c_loadMemberId(c_typeWalk_t* data, cx_value* v, cx_char* out, cx_bool addMemberOperator) {
    cx_value* stack[CX_MAX_TYPE_DEPTH];
    cx_uint32 count;
    cx_value *ptr;
    cx_object o;
    cx_type thisType;
    cx_bool objectIsArray, derefMemberOperator;

    *out = '\0';

    /* Build serializer-stack */
    ptr = v;
    count = 0;
    while ((ptr->kind != CX_OBJECT) && (ptr->kind != CX_BASE)) {
        stack[count] = ptr;
        ptr = ptr->parent;
        count++;
    }
    stack[count] = ptr;

    /* Print object */
    o = cx_valueObject(v);

    /* If object is a collection or primtive, dereference object pointer */
    objectIsArray = 
        (cx_typeof(o)->kind == CX_PRIMITIVE) || 
        (cx_typeof(o)->kind == CX_COLLECTION);

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
    thisType = cx_valueType(ptr);
    if (cx_type(thisType) != cx_typeof(o)) {
        cx_id id, parentId, objectId;
        sprintf(id, "%s(%s)",
                g_fullOid(data->g, thisType, parentId),
                c_loadVarId(data->g, cx_valueObject(v), objectId));
        strcat(out, id);
    } else {
        cx_id objectId;
        strcat(out, c_loadVarId(data->g, cx_valueObject(v), objectId));
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
        case CX_MEMBER:
            /* When previous object is a reference, use -> operator. */
            if (derefMemberOperator) {
                strcat(out, "->");
                derefMemberOperator = FALSE;
            } else {
                strcat(out, ".");
            }

            /* Reference member using it's name. */
            strcat(out, cx_nameof(stack[count]->is.member.t));
            break;

        /* Element */
        case CX_ELEMENT: {
            cx_collection t;
            cx_char arrayIndex[24];

            t = cx_collection(cx_valueType(stack[count+1]));

            switch (t->kind) {

            /* Array element, use array operator. */
            case CX_ARRAY:
                sprintf(arrayIndex, "[%d]", stack[count]->is.element.t.index);
                strcat(out, arrayIndex);
                break;

            /* Sequence element, use buffer-array */
            case CX_SEQUENCE:
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
                cx_char elementId[9]; /* One-million nested collections should be adequate in most cases. */

                if ((cx_valueType(stack[count])->kind == CX_COLLECTION) && (cx_collection(cx_valueType(stack[count]))->kind == CX_ARRAY)) {
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

        /* CX_OBJECT and CX_CONSTANT will not be encountered in this loop. */
        default:
            cx_assert(0, "invalid valueKind at this place.");
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
static int c_loadDeclareWalk(cx_object o, void* userData) {
    c_typeWalk_t* data;
    cx_id specifier, postfix, objectId;
    cx_type t;
    cx_bool prefix;
    cx_object parent;

    data = userData;
    t = cx_typeof(o);

    parent = cx_parentof(o);
    if (parent && (parent != root_o) && (!g_mustParse(data->g, parent))) {
        c_loadDeclareWalk(cx_parentof(o), userData);
    }

    /* Get C typespecifier */
    if (c_specifierId(data->g, t, specifier, &prefix, postfix)) {
        goto error;
    }

    /* Declare objects in headerfile and define in sourcefile */
    g_fileWrite(data->header, "\n");
    g_fileWrite(data->header, "/* %s */\n", cx_fullname(o, objectId));
    if (!prefix) {
        g_fileWrite(data->header, "extern %s %s%s;\n", specifier, c_loadVarId(data->g, o, objectId), postfix);
        g_fileWrite(data->source, "%s %s%s;\n", specifier, objectId, postfix);
    } else {
        g_fileWrite(data->header, "extern %s (*%s)%s;\n", specifier, c_loadVarId(data->g, o, objectId), postfix);
        g_fileWrite(data->source, "%s (*%s)%s;\n", specifier, objectId, postfix);
    }

    return 1;
error:
    return 0;
}

/* Open generator headerfile */
static g_file c_loadHeaderFileOpen(cx_generator g) {
    g_file result;
    cx_id headerFileName;

    /* Create file */
    sprintf(headerFileName, "%s__meta.h", g_getName(g));
    result = g_fileOpen(g, headerFileName);

    /* Print standard comments and includes */
    g_fileWrite(result, "/* %s\n", headerFileName);
    g_fileWrite(result, " *\n");
    g_fileWrite(result, " * Loads objects in object store.\n");
    g_fileWrite(result, " * This file contains generated code. Do not modify!\n");
    g_fileWrite(result, " */\n\n");
    g_fileWrite(result, "#ifndef %s_META_H\n", g_getName(g));
    g_fileWrite(result, "#define %s_META_H\n\n", g_getName(g));
    g_fileWrite(result, "#include \"cortex.h\"\n\n");
    g_fileWrite(result, "#include \"%s__type.h\"\n\n", g_getName(g));
    g_fileWrite(result, "#ifdef __cplusplus\n");
    g_fileWrite(result, "extern \"C\" {\n");
    g_fileWrite(result, "#endif\n");

    return result;
}

/* Close headerfile */
static void c_loadHeaderFileClose(cx_generator g, g_file file) {

    /* Print standard comments and includes */
    g_fileWrite(file, "\n");
    g_fileWrite(file, "int %s_load(void);", g_getName(g));
    g_fileWrite(file, "\n");
    g_fileWrite(file, "#ifdef __cplusplus\n");
    g_fileWrite(file, "}\n");
    g_fileWrite(file, "#endif\n");
    g_fileWrite(file, "#endif\n\n");
}

/* Open generator sourcefile */
static g_file c_loadSourceFileOpen(cx_generator g) {
    g_file result;
    cx_id headerFileName;
    cx_id topLevelName;

    /* Create file */
    sprintf(headerFileName, "%s__meta.c", g_getName(g));
    result = g_fileOpen(g, headerFileName);

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
static void c_sourceWriteLoadStart(cx_generator g, g_file file) {
    g_fileWrite(file, "\n");
    g_fileWrite(file, "/* Load objects in object store. */\n");
    g_fileWrite(file, "int %s_load(void) {\n", g_getName(g));
    g_fileIndent(file);
    g_fileWrite(file, "cx_object _a_; /* Used for resolving anonymous objects */\n");
    g_fileWrite(file, "_a_ = NULL;\n\n");
}

/* Write end of load-routine */
static void c_sourceWriteLoadEnd(g_file file) {
    g_fileWrite(file, "if (_a_) {\n");
    g_fileIndent(file);
    g_fileWrite(file, "cx_release(_a_);\n");
    g_fileDedent(file);
    g_fileWrite(file, "}\n\n");
    g_fileWrite(file, "return 0;\n");
    g_fileDedent(file);
    g_fileWrite(file, "error:\n");
    g_fileIndent(file);
    g_fileWrite(file, "return -1;\n");
    g_fileDedent(file);
    g_fileWrite(file, "}\n");
}

/* Print variable start */
static void c_varPrintStart(cx_value* v, c_typeWalk_t* data) {
    cx_id memberId;
    cx_type t;

    t = cx_valueType(v);

    /* Only write an identifier if the object is a primitive type, or a reference. */
    if ((t->kind == CX_PRIMITIVE) || (t->reference && !(v->kind == CX_OBJECT))) {
        /* Print memberId if object is member */
        g_fileWrite(data->source, "%s = ",
                c_loadMemberId(data, v, memberId, FALSE));
    }
}

/* Print variable end */
static void c_varPrintEnd(cx_value* v, c_typeWalk_t* data) {
    cx_type t;

    /* Get member object */
    t = cx_valueType(v);
    if ((t->kind == CX_PRIMITIVE) || (t->reference && !(v->kind == CX_OBJECT))) {
        /* Print end of member-assignment */
        g_fileWrite(data->source, ";\n");
    }
}

/* c_initPrimitive */
static cx_int16 c_initPrimitive(cx_serializer s, cx_value* v, void* userData) {
    void* ptr;
    cx_type t;
    cx_string str;
    c_typeWalk_t* data;
    CX_UNUSED(s);

    ptr = cx_valueValue(v);
    t = cx_valueType(v);
    data = userData;
    str = NULL;

    c_varPrintStart(v, userData);

    /* Treat booleans separately, the default convert translates booleans to 'true' and 'false' while
     * the language mapping of C TRUE and FALSE is. */
    if (cx_primitive(t)->kind == CX_BOOLEAN) {
        if (*(cx_bool*)ptr) {
            str = cx_strdup("TRUE");
        } else {
            str = cx_strdup("FALSE");
        }
    } else if (cx_primitive(t)->kind == CX_ENUM) {
        cx_id enumId;

        /* Convert constant-name to language id */
        str = cx_strdup(c_constantId(data->g, cx_enum_constant(cx_enum(t), *(cx_uint32*)ptr), enumId));
    } else if (cx_primitive(t)->kind == CX_BITMASK) {
        str = cx_alloc(11);
        sprintf(str, "0x%x", *(cx_uint32*)ptr);
    } else if (cx_primitive(t)->kind == CX_TEXT) {
        cx_string v = *(cx_string*)ptr;
        if (v) {
            size_t n = stresc(NULL, 0, v);
            str = malloc(strlen("cx_strdup(\"\")") + n + 1);
            strcpy(str, "cx_strdup(\"");
            stresc(str + strlen("cx_strdup(\""), n + 1, v);
            strcat(str, "\")");
        } else {
            str = cx_strdup("NULL");
        }
    } else if (cx_primitive(t)->kind == CX_CHARACTER) {
        cx_char v = *(cx_char*)ptr;
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
        if (cx_convert(cx_primitive(t), ptr, cx_primitive(cx_string_o), &str)) {
            goto error;
        }
    }

    g_fileWrite(data->source, "%s", str);
    cx_dealloc(str);

    c_varPrintEnd(v, userData);

    return 0;
error:
    return -1;
}

/* c_initReference */
static cx_int16 c_initReference(cx_serializer s, cx_value* v, void* userData) {
    cx_object *optr, o;
    c_typeWalk_t* data;
    CX_UNUSED(s);

    data = userData;
    optr = cx_valueValue(v);

    c_varPrintStart(v, userData);

    if ((o = *optr)) {
        cx_id id, src, context;
        c_loadVarId(data->g, cx_valueObject(v), src);
        cx_strving(v, context, 256);
        g_fileWrite(data->source, "%s", c_loadResolve(o, id, src, context));
    } else {
        g_fileWrite(data->source, "NULL");
    }

    c_varPrintEnd(v, userData);

    return 0;
}

/* c_initElement */
static cx_int16 c_initElement(cx_serializer s, cx_value* v, void* userData) {
    c_typeWalk_t* data = userData;
    cx_collection t = cx_collection(cx_valueType(v->parent));
    cx_bool requiresAlloc = cx_collection_elementRequiresAlloc(t);

    /* Allocate space for element */
    switch (t->kind) {
    case CX_LIST:
    case CX_MAP: {
        cx_id elementId, specifier, postfix;
        g_fileWrite(data->source, "\n");

        if (requiresAlloc) {
            c_specifierId(data->g, t->elementType, specifier, NULL, postfix);
            g_fileWrite(data->source, "%s = cx_alloc(sizeof(%s%s));\n", c_loadElementId(v, elementId, 0), specifier, postfix);
        }
        break;
    }
    default:
        break;
    }

    /* Serialize value */
    if (cx_serializeValue(s, v, data)) {
        goto error;
    }

    switch (t->kind) {
    case CX_LIST: {
        cx_id parentId, elementId;
        g_fileWrite(data->source, "cx_llAppend(%s, %s%s);\n",
                c_loadMemberId(data, v->parent, parentId, FALSE),
                requiresAlloc ? "" : "(void*)", c_loadElementId(v, elementId, 0));
        break;
    }
    case CX_MAP: /*{
        cx_id parentId, elementId;
        g_fileWrite(data->source, "cx_rbtreeSet(%s, %s)",
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
static cx_int16 c_initCollection(cx_serializer s, cx_value* v, void* userData) {
    cx_collection t;
    c_typeWalk_t* data;
    cx_id memberId;
    int result;
    void* ptr;
    cx_uint32 size = 0;

    ptr = cx_valueValue(v);

    t = cx_collection(cx_valueType(v));
    data = userData;

    switch (t->kind) {
    case CX_ARRAY:
        size = t->max;
        break;
    case CX_SEQUENCE: {
        cx_uint32 length;
        cx_id specifier, postfix;

        length = *(cx_uint32*)ptr;
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
            g_fileWrite(data->source, "%sbuffer = cx_alloc(sizeof(%s%s));\n",
                    c_loadMemberId(data, v, memberId, TRUE),
                    specifier, postfix);
        } else {
            g_fileWrite(data->source, "%sbuffer = cx_alloc(sizeof(%s%s) * %d);\n",
                    c_loadMemberId(data, v, memberId, TRUE),
                    specifier, postfix,
                    length);
        }
        break;
    }
    case CX_LIST:
        /* Create list object */
        if (*(cx_ll*)ptr) {
            g_fileWrite(data->source, "%s = cx_llNew();\n",
                    c_loadMemberId(data, v, memberId, FALSE));
        } else {
            g_fileWrite(data->source, "%s = NULL;\n", c_loadMemberId(data, v, memberId, FALSE));
        }
        size = cx_llSize(*(cx_ll*)ptr);
        break;
    case CX_MAP: {
        cx_id keyId;
        /* Create map object */
        if (*(cx_rbtree*)ptr) {
            g_fileWrite(data->source, "%s = cx_rbtreeNew(%s);\n",
                    c_loadMemberId(data, v, memberId, FALSE), g_fullOid(data->g, cx_rbtreeKeyType(*(cx_rbtree*)ptr), keyId));
        } else {
            g_fileWrite(data->source, "%s = NULL;\n", c_loadMemberId(data, v, memberId, FALSE));
        }
        size = cx_rbtreeSize(*(cx_rbtree*)ptr);
        break;
    }
    }

    /* For the non-array types, allocate a member variable, if size of collection is not zero. */
    if (size) {
        switch (t->kind) {
        case CX_LIST:
        case CX_MAP: {
            cx_id elementId, elementTypeId;
            g_fileWrite(data->source, "{\n");
            g_fileIndent(data->source);

            g_fileWrite(
                data->source, 
                "%s%s %s;\n", 
                g_fullOid(data->g, t->elementType, elementTypeId), 
                cx_collection_elementRequiresAlloc(t) ? "*" : "",
                c_loadElementId(v, elementId, 1));

            break;
        }
        default:
            break;
        }
    }

    /* Serialize elements */
    result = cx_serializeElements(s, v, userData);

    if (size) {
        switch (t->kind) {
        case CX_LIST:
        case CX_MAP: {
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
static int c_loadCFunction(cx_function o, c_typeWalk_t* data, cx_id name) {

    /* Print name */
    g_fullOid(data->g, o, name);
    if (c_procedureHasThis(o)) {
        if (cx_instanceof(cx_type(cx_method_o), o) && cx_method(o)->virtual) {
            strcat(name, "_v");
        }
    }

    return 0;
}

/* Create serializer that initializes object values */
static struct cx_serializer_s c_initSerializer(void) {
    struct cx_serializer_s s;

    cx_serializerInit(&s);

    s.access = CX_LOCAL;
    s.accessKind = CX_NOT;
    s.traceKind = CX_SERIALIZER_TRACE_ON_FAIL;
    s.program[CX_PRIMITIVE] = c_initPrimitive;
    s.program[CX_COLLECTION] = c_initCollection;
    s.metaprogram[CX_ELEMENT] = c_initElement;
    s.reference = c_initReference;

    return s;
}

/* Declare object */
static int c_loadDeclare(cx_object o, void* userData) {
    c_typeWalk_t* data;
    cx_id id, parentId, typeId, escapedName;

    data = userData;

    /* Only declare scoped objects */
    if (cx_checkAttr(o, CX_ATTR_SCOPED)) {
        c_escapeString(cx_nameof(o), escapedName);

        /* Declaration */
        g_fileWrite(data->source, "/* Declare %s */\n", cx_fullname(o, id));

        if (!cx_checkAttr(cx_typeof(o), CX_ATTR_SCOPED)) {
            g_fileWrite(data->source, "%s = cx_declare(%s, \"%s\", (_a_ ? cx_release(_a_) : 0, _a_ = cx_type(%s)));\n",
                    c_loadVarId(data->g, o, id),
                    c_loadVarId(data->g, cx_parentof(o), parentId),
                    escapedName,
                    c_loadVarId(data->g, cx_typeof(o), typeId));
        } else {
            g_fileWrite(data->source, "%s = cx_declare(%s, \"%s\", cx_type(%s));\n",
                    c_loadVarId(data->g, o, id),
                    c_loadVarId(data->g, cx_parentof(o), parentId),
                    escapedName,
                    c_loadVarId(data->g, cx_typeof(o), typeId));
        }

        /* Error checking */
        g_fileWrite(data->source, "if (!%s) {\n", c_loadVarId(data->g, o, id));
        g_fileIndent(data->source);
        c_escapeString(cx_fullname(o, id), escapedName);
        g_fileWrite(data->source, "cx_error(\"%s_load: failed to declare object '%s'.\");\n",
                g_getName(data->g),
                escapedName);
        g_fileWrite(data->source, "goto error;\n");
        g_fileDedent(data->source);

        g_fileWrite(data->source, "}\n\n");
    }

    return 1;
}

/* Define object */
static int c_loadDefine(cx_object o, void* userData) {
    struct cx_serializer_s s;

    if (cx_checkAttr(o, CX_ATTR_SCOPED)) {
        c_typeWalk_t* data;
        cx_id escapedId, fullname, varId, typeId;

        data = userData;

        cx_fullname(o, fullname);
        c_loadVarId(data->g, o, varId);
        g_fullOid(data->g, o, typeId);

        g_fileWrite(data->source, "/* Define %s */\n", fullname);
        g_fileWrite(data->source, "if (!cx_checkState(%s, CX_DEFINED)) {\n", varId);
        g_fileIndent(data->source);

        /* Serialize object if object is not a primitive */
        s = c_initSerializer();
        cx_serialize(&s, o, userData);

        /* If object is a procedure, set function implementation */
        if (cx_class_instanceof(cx_procedure_o, cx_typeof(o))) {
            cx_id name;
            g_fileWrite(data->source, "\n");
            if (!cx_function(o)->impl) {
                g_fileWrite(data->source, "/* Bind %s with C-function */\n", fullname);
                g_fileWrite(data->source, "cx_function(%s)->kind = CX_PROCEDURE_CDECL;\n", varId);
                c_loadCFunction(o, data, name);
                g_fileWrite(data->source, "void __%s(void *args, void *result);\n", name);
                g_fileWrite(data->source, "cx_function(%s)->impl = (cx_word)__%s;\n", varId, name);
            }
        }

        /* Define object */
        g_fileWrite(data->source, "if (cx_define(%s)) {\n", varId);
        g_fileIndent(data->source);
        g_fileWrite(data->source, "cx_error(\"%s_load: failed to define object '%s'.\");\n",
                g_getName(data->g),
                c_escapeString(fullname, escapedId));
        g_fileWrite(data->source, "goto error;\n");
        g_fileDedent(data->source);
        g_fileWrite(data->source, "}\n");
        g_fileDedent(data->source);
        g_fileWrite(data->source, "}\n\n");

        /* Do size validation - this makes porting to other platforms easier */
        if (cx_instanceof(cx_type(cx_type_o), o)) {
            if (cx_type(o)->reference) {
                g_fileWrite(data->source, "if (cx_type(%s)->size != sizeof(struct %s_s)) {\n", 
                    varId,
                    typeId);
                g_fileIndent(data->source);
                g_fileWrite(data->source, 
                    "cx_error(\"%s_load: calculated size '%%d' of type '%s' doesn't match C-type size '%%d'\", cx_type(%s)->size, sizeof(struct %s_s));\n", 
                    g_getName(data->g),
                    fullname,
                    varId,
                    typeId);
            } else {
                g_fileWrite(data->source, "if (cx_type(%s)->size != sizeof(%s)) {\n", 
                    varId,
                    typeId);
                g_fileIndent(data->source);
                g_fileWrite(data->source, 
                    "cx_error(\"%s_load: calculated size '%%d' of type '%s' doesn't match C-type size '%%d'\", cx_type(%s)->size, sizeof(%s));\n", 
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
int cortex_genMain(cx_generator g) {
    c_typeWalk_t walkData;

    /* Default prefixes for cortex namespaces */
    gen_parse(g, cortex_o, FALSE, FALSE, "");
    gen_parse(g, cortex_lang_o, FALSE, FALSE, "cx");

    /* Prepare walkData, create header- and sourcefile */
    walkData.g = g;
    walkData.header = c_loadHeaderFileOpen(g);
    walkData.source = c_loadSourceFileOpen(g);

    /* Write comment indicating definitions in sourcefile */
    c_sourceWriteVarDefStart(walkData.source);

    /* Walk objects, declare variables in header and sourcefile */
    if (!g_walkRecursive(g, c_loadDeclareWalk, &walkData)) {
        goto error;
    }

    /* Create load-routine */
    c_sourceWriteLoadStart(g, walkData.source);

    /* Walk objects in dependency order */
    if (cx_genDepWalk(g, c_loadDeclare, c_loadDefine, &walkData)) {
        cx_trace("generation of load-routine failed while resolving dependencies.");
        goto error;
    }

    /* Close load-routine */
    c_sourceWriteLoadEnd(walkData.source);

    /* Close headerfile */
    c_loadHeaderFileClose(g, walkData.header);

    return 0;
error:
    return -1;
}
