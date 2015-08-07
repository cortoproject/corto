/*
 * c_type.c
 *
 *  Created on: Sep 17, 2012
 *      Author: sander
 */

#include "c_type.h"
#include "c_common.h"
#include "cortex.h"

typedef struct c_typeWalk_t {
    cx_generator g;
    g_file header;
    cx_bool prefixComma; /* For printing members and constants */
}c_typeWalk_t;

/* Enumeration constant */
static cx_int16 c_typeConstant(cx_serializer s, cx_value* v, void* userData) {
    c_typeWalk_t* data;
    cx_id constantId;

    CX_UNUSED(s);

    data = userData;

    switch(cx_primitive(cx_parentof(v->is.constant.t))->kind) {
    case CX_ENUM:
        if (data->prefixComma) {
            g_fileWrite(data->header, ",\n");
        } else {
            data->prefixComma = TRUE;
        }
        g_fileWrite(data->header, "%s = %d", c_constantId(data->g, v->is.constant.t, constantId), *v->is.constant.t);
        break;
    case CX_BITMASK:
        g_fileWrite(data->header, "#define %s (0x%x)\n", c_constantId(data->g, v->is.constant.t, constantId), *v->is.constant.t);
        break;
    default:
        cx_error("c_typeConstant: invalid constant parent-type.");
        goto error;
        break;
    }

    return 0;
error:
    return -1;
}

/* Member */
static cx_int16 c_typeMember(cx_serializer s, cx_value* v, void* userData) {
    c_typeWalk_t* data;
    cx_member m;
    cx_id specifier, postfix, memberId;

    CX_UNUSED(s);

    if (v->kind == CX_MEMBER) {
        data = userData;
        m = v->is.member.t;

        /* Get typespecifier */
        if (c_specifierId(data->g, m->type, specifier, NULL, postfix)) {
            goto error;
        }

        if (m->id != (cx_uint32)-1) {
            g_fileWrite(data->header, "%s %s%s;\n", specifier, g_id(data->g, cx_nameof(m), memberId), postfix);
        } else {
            g_fileWrite(data->header, "%s _parent%s;\n", specifier, postfix);
        }
    }

    return 0;
error:
    return -1;
}


/* Enumeration object */
static cx_int16 c_typePrimitiveEnum(cx_serializer s, cx_value* v, void* userData) {
    c_typeWalk_t* data;
    cx_enum t;
    cx_id id;

    CX_UNUSED(s);

    data = userData;
    t = cx_enum(cx_valueType(v));

    /* Write enumeration */
    g_fileWrite(data->header, "typedef enum %s {\n", g_fullOid(data->g, t, id));
    g_fileIndent(data->header);

    /* Write enumeration constants */
    if (cx_serializeConstants(s, v, userData)) {
        goto error;
    }

    g_fileDedent(data->header);
    g_fileWrite(data->header, "\n");
    g_fileWrite(data->header, "} %s;\n\n", g_fullOid(data->g, t, id));

    return 0;
error:
    return -1;
}

/* Bitmask object */
static cx_int16 c_typePrimitiveBitmask(cx_serializer s, cx_value* v, void* userData) {
    c_typeWalk_t* data;
    cx_enum t;
    cx_id id;

    CX_UNUSED(s);

    data = userData;
    t = cx_enum(cx_valueType(v));

    g_fileWrite(data->header, "CX_BITMASK(%s);\n", g_fullOid(data->g, t, id));

    /* Write enumeration constants */
    g_fileIndent(data->header);
    if (cx_serializeConstants(s, v, userData)) {
        goto error;
    }
    g_fileDedent(data->header);
    g_fileWrite(data->header, "\n");

    return 0;
error:
    return -1;
}

/* Void object */
static cx_int16 c_typeVoid(cx_serializer s, cx_value* v, void* userData) {
    cx_type t;
    c_typeWalk_t* data;
    cx_id id;

    CX_UNUSED(s);

    t = cx_valueType(v);
    data = userData;

    g_fileWrite(data->header, "/* %s */\n", cx_fullname(t, id));
    if (t->reference) {
        g_fileWrite(data->header, "typedef void *%s;\n", g_fullOid(data->g, t, id));
    } else {
        g_fileWrite(data->header, "typedef void %s;\n", g_fullOid(data->g, t, id));
    }
    g_fileWrite(data->header, "\n");

    return 0;
}

/* Void object */
static cx_int16 c_typeAny(cx_serializer s, cx_value* v, void* userData) {
    cx_type t;
    c_typeWalk_t* data;
    cx_id id;

    CX_UNUSED(s);

    t = cx_valueType(v);
    data = userData;

    g_fileWrite(data->header, "/* %s */\n", cx_fullname(t, id));
    g_fileWrite(data->header, "CX_ANY(%s);\n\n", g_fullOid(data->g, t, id));

    return 0;
}

/* Primitive object */
static cx_int16 c_typePrimitive(cx_serializer s, cx_value* v, void* userData) {
    cx_char buff[16];
    cx_type t;
    cx_id id;
    c_typeWalk_t* data;

    CX_UNUSED(s);

    data = userData;
    t = cx_valueType(v);

    /* Obtain platform type-name for primitive */
    switch(cx_primitive(t)->kind) {
    case CX_ENUM:
        g_fileWrite(data->header, "/* %s */\n", cx_fullname(t, id));
        if (c_typePrimitiveEnum(s, v, userData)) {
            goto error;
        }
        break;
    case CX_BITMASK:
        g_fileWrite(data->header, "/* %s */\n", cx_fullname(t, id));
        if (c_typePrimitiveBitmask(s, v, userData)) {
            goto error;
        }
        break;
    case CX_ALIAS:
        /* Don't generate for alias types */
        break;
    default:
        if (!c_primitiveId(cx_primitive(t), buff)) {
            goto error;
        }

        /* Write typedef */
        if (cx_checkAttr(t, CX_ATTR_SCOPED)) {
            g_fileWrite(data->header, "/* %s */\n", cx_fullname(t, id));
            g_fileWrite(data->header, "typedef %s %s;\n\n", buff, g_fullOid(data->g, t, id));
        }
        break;
    }

    return 0;
error:
    return -1;
}

/* Struct object */
static cx_int16 c_typeStruct(cx_serializer s, cx_value* v, void* userData) {
    c_typeWalk_t* data;
    cx_id id;
    cx_type t;

    data = userData;
    t = cx_valueType(v);

    /* Open struct */
    g_fileWrite(data->header, "struct %s {\n", g_fullOid(data->g, t, id));
    
    /* Serialize members */
    g_fileIndent(data->header);

    /* Write base */
    if (cx_interface(t)->base && cx_type(cx_interface(t)->base)->alignment) {
        g_fileWrite(data->header, "%s _parent;\n", g_fullOid(data->g, cx_interface(t)->base, id));
    }

    if (cx_serializeMembers(s, v, userData)) {
        goto error;
    }
    g_fileDedent(data->header);

    /* Close struct */
    g_fileWrite(data->header, "};\n\n");


    return 0;
error:
    return -1;
}

/* Abstract object */
static cx_int16 c_typeAbstract(cx_serializer s, cx_value* v, void* userData) {
    CX_UNUSED(s);
    CX_UNUSED(v);
    CX_UNUSED(userData);

    return 0;
}

/* Class object */
static cx_int16 c_typeClass(cx_serializer s, cx_value* v, void* userData) {
    c_typeWalk_t* data;
    cx_id id;
    cx_type t;

    data = userData;
    t = cx_valueType(v);

    /* Open class */
    g_fileWrite(data->header, "CX_CLASS_DEF(%s) {\n", g_fullOid(data->g, t, id));
    g_fileIndent(data->header);

    /* Write base */
    if (cx_interface(t)->base) {
        g_fileWrite(data->header, "CX_EXTEND(%s);\n", g_fullOid(data->g, cx_interface(t)->base, id));
    }

    /* Serialize members */
    if (cx_serializeMembers(s, v, userData)) {
        goto error;
    }
    g_fileDedent(data->header);

    /* Close class */
    g_fileWrite(data->header, "};\n\n");

    return 0;
error:
    return -1;
}

/* Composite object */
static cx_int16 c_typeComposite(cx_serializer s, cx_value* v, void* userData) {
    cx_type t;

    t = cx_valueType(v);
    switch(cx_interface(t)->kind) {
    case CX_DELEGATE:
    case CX_STRUCT:
        if (c_typeStruct(s, v, userData)) {
            goto error;
        }
        break;
    case CX_INTERFACE:
        if (c_typeAbstract(s, v, userData)) {
            goto error;
        }
        break;
    case CX_PROCEDURE:
    case CX_CLASS:
        if (c_typeClass(s, v, userData)) {
            goto error;
        }
        break;
    }

    return 0;
error:
    return -1;
}

/* Array object */
static cx_int16 c_typeArray(cx_serializer s, cx_value* v, void* userData) {
    cx_type t;
    c_typeWalk_t* data;
    cx_id id, id3, postfix, postfix2;

    CX_UNUSED(s);
    CX_UNUSED(v);

    data = userData;
    t = cx_valueType(v);
    c_specifierId(data->g, cx_type(t), id, NULL, postfix);
    c_specifierId(data->g, cx_type(cx_collection(t)->elementType), id3, NULL, postfix2);
    g_fileWrite(data->header, "typedef %s %s[%d];\n\n",
            id3,
            id,
            cx_collection(t)->max);

    return 0;
}

/* Sequence object */
static cx_int16 c_typeSequence(cx_serializer s, cx_value* v, void* userData) {
    cx_type t;
    c_typeWalk_t* data;
    cx_id id, id3, postfix, postfix2;

    CX_UNUSED(s);
    CX_UNUSED(v);

    data = userData;
    t = cx_valueType(v);
    c_specifierId(data->g, cx_type(t), id, NULL, postfix);
    c_specifierId(data->g, cx_type(cx_collection(t)->elementType), id3, NULL, postfix2);
    g_fileWrite(data->header, "CX_SEQUENCE(%s, %s,);\n\n",
            id,
            id3);

    return 0;
}

/* List object */
static cx_int16 c_typeList(cx_serializer s, cx_value* v, void* userData) {
    cx_type t;
    c_typeWalk_t* data;
    cx_id id, postfix;

    CX_UNUSED(s);
    CX_UNUSED(v);

    data = userData;
    t = cx_valueType(v);
    c_specifierId(data->g, cx_type(t), id, NULL, postfix);
    g_fileWrite(data->header, "CX_LIST(%s);\n\n",
            id);

    return 0;
}

/* Collection object */
static cx_int16 c_typeCollection(cx_serializer s, cx_value* v, void* userData) {
    cx_type t;

    t = cx_valueType(v);
    switch(cx_collection(t)->kind) {
    case CX_ARRAY:
        if (c_typeArray(s, v, userData)) {
            goto error;
        }
        break;
    case CX_SEQUENCE:
        if (c_typeSequence(s, v, userData)) {
            goto error;
        }
        break;
    case CX_LIST:
        if (c_typeList(s, v, userData)) {
            goto error;
        }
        break;
    case CX_MAP:
        break;
    }

    return 0;
error:
    return -1;
}

/* Iterator object */
static cx_int16 c_typeIterator(cx_serializer s, cx_value* v, void* userData) {
    cx_type t;

    CX_UNUSED(s);
    CX_UNUSED(v);
    
    c_typeWalk_t* data;
    cx_id id, postfix;

    data = userData;
    t = cx_valueType(v);
    c_specifierId(data->g, cx_type(t), id, NULL, postfix);
    g_fileWrite(data->header, "CX_ITERATOR(%s);\n\n",
            id);

    return 0;
}

/* Type object */
static cx_int16 c_typeObject(cx_serializer s, cx_value* v, void* userData) {
    c_typeWalk_t* data;
    cx_type t;
    cx_int16 result;

    data = userData;
    t = cx_type(cx_valueType(v));

    /* Reset prefixComma */
    data->prefixComma = FALSE;

    /* Forward to specific type-functions */
    switch(t->kind) {
    case CX_VOID:
        result = c_typeVoid(s, v, userData);
        break;
    case CX_ANY:
        result = c_typeAny(s, v, userData);
        break;
    case CX_PRIMITIVE:
        result = c_typePrimitive(s, v, userData);
        break;
    case CX_COMPOSITE:
        result = c_typeComposite(s, v, userData);
        break;
    case CX_COLLECTION:
        result = c_typeCollection(s, v, userData);
        break;
    case CX_ITERATOR:
        result = c_typeIterator(s, v, userData);
        break;
    default:
        cx_error("c_typeObject: typeKind '%s' not handled by code-generator.", cx_nameof(cx_enum_constant(cx_typeKind_o, t->kind)));
        goto error;
        break;
    }

    return result;
error:
    return -1;
}

/* Metawalk-serializer for types */
struct cx_serializer_s c_typeSerializer(void) {
    struct cx_serializer_s s;

    /* Initialize serializer */
    cx_serializerInit(&s);
    s.metaprogram[CX_OBJECT] = c_typeObject;
    s.metaprogram[CX_BASE] = c_typeMember;
    s.metaprogram[CX_MEMBER] = c_typeMember;
    s.metaprogram[CX_CONSTANT] = c_typeConstant;
    s.access = CX_GLOBAL;
    s.accessKind = CX_XOR;
    s.traceKind = CX_SERIALIZER_TRACE_ON_FAIL;

    return s;
}

/* Print class-cast macro's */
static int c_typeClassCastWalk(cx_object o, void* userData) {
    c_typeWalk_t* data;
    cx_id id;

    data = userData;

    if (cx_class_instanceof(cx_interface_o, o)) {
        cx_string fullOid = g_fullOid(data->g, o, id);
        if (cx_type(o)->reference) {
            g_fileWrite(data->header, "#define %s(o) ((%s)cx_assertType((cx_type)%s_o, o))\n",
                fullOid, fullOid, fullOid);
        } else {
            g_fileWrite(data->header, "#define %s(o) ((%s *)cx_assertType((cx_type)%s_o, &o))\n",
                fullOid, fullOid, fullOid);
        }
    }

    return 1;
}

/* Open headerfile, write standard header. */
static g_file c_typeHeaderFileOpen(cx_generator g) {
    g_file result;
    cx_id headerFileName;
    cx_iter importIter;
    cx_object import;
    cx_string headerSnippet;
    cx_string bootstrap = gen_getAttribute(g, "bootstrap");

    /* Create file */
    sprintf(headerFileName, "%s__type.h", g_getName(g));
    result = g_fileOpen(g, headerFileName);
    if (!result) {
        goto error;
    }

    /* Print standard comments and includes */
    g_fileWrite(result, "/* %s\n", headerFileName);
    g_fileWrite(result, " *\n");
    g_fileWrite(result, " * Type definitions for C-language.\n");
    g_fileWrite(result, " * This file contains generated code. Do not modify!\n");
    g_fileWrite(result, " */\n\n");
    g_fileWrite(result, "#ifndef %s__type_H\n", g_getName(g));
    g_fileWrite(result, "#define %s__type_H\n\n", g_getName(g));

    /* Don't include this file when generating for the bootstrap */
    if (!bootstrap || strcmp(bootstrap, "true")) {
        g_fileWrite(result, "#include \"cortex.h\"\n\n");
    } else {
        g_fileWrite(result, "#include \"cx_def.h\"\n\n");
    }

    /* Include imports */
    if (g->imports) {
        importIter = cx_llIter(g->imports);
        while(cx_iterHasNext(&importIter)) {
            import = cx_iterNext(&importIter);
            g_fileWrite(result, "#include \"%s__type.h\"\n", cx_nameof(import));
        }
        g_fileWrite(result, "\n");
    }

    headerSnippet = g_fileLookupHeader(result, "");
    if (headerSnippet) {
        g_fileWrite(result, "\n/* $header()%s$end */\n\n", headerSnippet);
    }

    g_fileWrite(result, "#ifdef __cplusplus\n");
    g_fileWrite(result, "extern \"C\" {\n");
    g_fileWrite(result, "#endif\n");

    return result;
error:
    return NULL;
}

/* Close headerfile */
static void c_typeHeaderFileClose(g_file file) {

    /* Print standard comments and includes */
    g_fileWrite(file, "#ifdef __cplusplus\n");
    g_fileWrite(file, "}\n");
    g_fileWrite(file, "#endif\n");
    g_fileWrite(file, "#endif\n\n");
}

static int c_typeDeclare(cx_object o, void* userData) {
    cx_id id;
    cx_type t;
    c_typeWalk_t* data;

    data = userData;
    t = o;

    if (cx_checkAttr(o, CX_ATTR_SCOPED)) {
        g_fileWrite(data->header, "/*  %s */\n", cx_fullname(t, id));

        switch(t->kind) {
        case CX_COMPOSITE:
            switch(cx_interface(t)->kind) {
            case CX_DELEGATE:
            case CX_STRUCT:
                g_fileWrite(data->header, "typedef struct %s %s;\n\n", g_fullOid(data->g, t, id), g_fullOid(data->g, t, id));
                break;
            case CX_CLASS:
                g_fileWrite(data->header, "CX_CLASS(%s);\n\n", g_fullOid(data->g, t, id));
                break;
            case CX_INTERFACE:
                g_fileWrite(data->header, "CX_INTERFACE(%s);\n\n", g_fullOid(data->g, t, id));
                break;
            case CX_PROCEDURE:
                g_fileWrite(data->header, "CX_CLASS(%s);\n\n", g_fullOid(data->g, t, id));
                break;
            }
            break;
        default:
            cx_error("c_typeDeclare: only composite types can be forward declared.");
            goto error;
            break;
        }
    }

    return 0;
error:
    return -1;
}

static int c_typeDefine(cx_object o, void* userData) {
    struct cx_serializer_s s;
    int result;

    result = 0;
    
    /* Get type-serializer */
    s = c_typeSerializer();

    /* Do metawalk on type */
    result = cx_metaWalk(&s, cx_type(o), userData);

    return result;
}

/* Generator main */
cx_int16 cortex_genMain(cx_generator g) {
    c_typeWalk_t walkData;

    /* Resolve imports so include files for external can be added. */
    g_resolveImports(g);

    /* Prepare walkdata, open headerfile */
    walkData.header = c_typeHeaderFileOpen(g);
    if (!walkData.header) {
        goto error;
    }

    walkData.g = g;
    walkData.prefixComma = FALSE;

    /* Default prefixes for cortex namespaces */
    gen_parse(g, cortex_o, FALSE, FALSE, "");
    gen_parse(g, cortex_lang_o, FALSE, FALSE, "cx");

    /* Walk classes, print cast-macro's */
    g_fileWrite(walkData.header, "\n");
    g_fileWrite(walkData.header, "/* Casting macro's for classes */\n");
    if (!g_walkRecursive(g, c_typeClassCastWalk, &walkData)) {
        goto error;
    }

    g_fileWrite(walkData.header, "\n");
    g_fileWrite(walkData.header, "/* Type definitions */\n");

    /* Walk objects */
    if (cx_genTypeDepWalk(g, c_typeDeclare, c_typeDefine, &walkData)) {
        goto error;
    }

    /* Close headerfile */
    c_typeHeaderFileClose(walkData.header);

    return 0;
error:
    return -1;
}
