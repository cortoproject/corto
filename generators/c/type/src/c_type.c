/*
 * c_type.c
 *
 *  Created on: Sep 17, 2012
 *      Author: sander
 */

#include "c_type.h"
#include "c_common.h"
#include "corto.h"

typedef struct c_typeWalk_t {
    corto_generator g;
    g_file header;
    corto_bool prefixComma; /* For printing members and constants */
}c_typeWalk_t;

/* Enumeration constant */
static corto_int16 c_typeConstant(corto_serializer s, corto_value* v, void* userData) {
    c_typeWalk_t* data;
    corto_id constantId;

    CORTO_UNUSED(s);

    data = userData;

    switch(corto_primitive(corto_parentof(v->is.constant.t))->kind) {
    case CORTO_ENUM:
        if (data->prefixComma) {
            g_fileWrite(data->header, ",\n");
        } else {
            data->prefixComma = TRUE;
        }
        g_fileWrite(data->header, "%s = %d", c_constantId(data->g, v->is.constant.t, constantId), *v->is.constant.t);
        break;
    case CORTO_BITMASK:
        g_fileWrite(data->header, "#define %s (0x%x)\n", c_constantId(data->g, v->is.constant.t, constantId), *v->is.constant.t);
        break;
    default:
        corto_error("c_typeConstant: invalid constant parent-type.");
        goto error;
        break;
    }

    return 0;
error:
    return -1;
}

/* Member */
static corto_int16 c_typeMember(corto_serializer s, corto_value* v, void* userData) {
    c_typeWalk_t* data;
    corto_member m;
    corto_id specifier, postfix, memberId;

    CORTO_UNUSED(s);

    if (v->kind == CORTO_MEMBER) {
        data = userData;
        m = v->is.member.t;

        /* Get typespecifier */
        if (c_specifierId(data->g, m->type, specifier, NULL, postfix)) {
            goto error;
        }

        if (m->id != (corto_uint32)-1) {
            g_fileWrite(data->header, "%s %s%s;\n", specifier, g_id(data->g, corto_nameof(m), memberId), postfix);
        } else {
            g_fileWrite(data->header, "%s _parent%s;\n", specifier, postfix);
        }
    }

    return 0;
error:
    return -1;
}


/* Enumeration object */
static corto_int16 c_typePrimitiveEnum(corto_serializer s, corto_value* v, void* userData) {
    c_typeWalk_t* data;
    corto_enum t;
    corto_id id;

    CORTO_UNUSED(s);

    data = userData;
    t = corto_enum(corto_valueType(v));

    /* Write enumeration */
    g_fileWrite(data->header, "typedef enum %s {\n", g_fullOid(data->g, t, id));
    g_fileIndent(data->header);

    /* Write enumeration constants */
    if (corto_serializeConstants(s, v, userData)) {
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
static corto_int16 c_typePrimitiveBitmask(corto_serializer s, corto_value* v, void* userData) {
    c_typeWalk_t* data;
    corto_enum t;
    corto_id id;

    CORTO_UNUSED(s);

    data = userData;
    t = corto_enum(corto_valueType(v));

    g_fileWrite(data->header, "CORTO_BITMASK(%s);\n", g_fullOid(data->g, t, id));

    /* Write enumeration constants */
    g_fileIndent(data->header);
    if (corto_serializeConstants(s, v, userData)) {
        goto error;
    }
    g_fileDedent(data->header);
    g_fileWrite(data->header, "\n");

    return 0;
error:
    return -1;
}

/* Void object */
static corto_int16 c_typeVoid(corto_serializer s, corto_value* v, void* userData) {
    corto_type t;
    c_typeWalk_t* data;
    corto_id id;

    CORTO_UNUSED(s);

    t = corto_valueType(v);
    data = userData;

    g_fileWrite(data->header, "/* %s */\n", corto_fullname(t, id));
    if (t->reference) {
        g_fileWrite(data->header, "typedef void *%s;\n", g_fullOid(data->g, t, id));
    } else {
        g_fileWrite(data->header, "typedef void %s;\n", g_fullOid(data->g, t, id));
    }
    g_fileWrite(data->header, "\n");

    return 0;
}

/* Void object */
static corto_int16 c_typeAny(corto_serializer s, corto_value* v, void* userData) {
    corto_type t;
    c_typeWalk_t* data;
    corto_id id;

    CORTO_UNUSED(s);

    t = corto_valueType(v);
    data = userData;

    g_fileWrite(data->header, "/* %s */\n", corto_fullname(t, id));
    g_fileWrite(data->header, "CORTO_ANY(%s);\n\n", g_fullOid(data->g, t, id));

    return 0;
}

/* Primitive object */
static corto_int16 c_typePrimitive(corto_serializer s, corto_value* v, void* userData) {
    corto_char buff[16];
    corto_type t;
    corto_id id;
    c_typeWalk_t* data;

    CORTO_UNUSED(s);

    data = userData;
    t = corto_valueType(v);

    /* Obtain platform type-name for primitive */
    switch(corto_primitive(t)->kind) {
    case CORTO_ENUM:
        g_fileWrite(data->header, "/* %s */\n", corto_fullname(t, id));
        if (c_typePrimitiveEnum(s, v, userData)) {
            goto error;
        }
        break;
    case CORTO_BITMASK:
        g_fileWrite(data->header, "/* %s */\n", corto_fullname(t, id));
        if (c_typePrimitiveBitmask(s, v, userData)) {
            goto error;
        }
        break;
    default:
        if (!c_primitiveId(corto_primitive(t), buff)) {
            goto error;
        }

        /* Write typedef */
        if (corto_checkAttr(t, CORTO_ATTR_SCOPED)) {
            g_fileWrite(data->header, "/* %s */\n", corto_fullname(t, id));
            g_fileWrite(data->header, "typedef %s %s;\n\n", buff, g_fullOid(data->g, t, id));
        }
        break;
    }

    return 0;
error:
    return -1;
}

/* Struct object */
static corto_int16 c_typeStruct(corto_serializer s, corto_value* v, void* userData) {
    c_typeWalk_t* data;
    corto_id id;
    corto_type t;

    data = userData;
    t = corto_valueType(v);

    /* Open struct */
    g_fileWrite(data->header, "struct %s {\n", g_fullOid(data->g, t, id));

    /* Serialize members */
    g_fileIndent(data->header);

    /* Write base */
    if (corto_interface(t)->base && corto_type(corto_interface(t)->base)->alignment) {
        g_fileWrite(data->header, "%s _parent;\n", g_fullOid(data->g, corto_interface(t)->base, id));
    }

    if (corto_serializeMembers(s, v, userData)) {
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
static corto_int16 c_typeAbstract(corto_serializer s, corto_value* v, void* userData) {
    CORTO_UNUSED(s);
    CORTO_UNUSED(v);
    CORTO_UNUSED(userData);

    return 0;
}

/* Class object */
static corto_int16 c_typeClass(corto_serializer s, corto_value* v, void* userData) {
    c_typeWalk_t* data;
    corto_id id;
    corto_type t;

    data = userData;
    t = corto_valueType(v);

    /* Open class */
    g_fileWrite(data->header, "CORTO_CLASS_DEF(%s) {\n", g_fullOid(data->g, t, id));
    g_fileIndent(data->header);

    /* Write base */
    if (corto_interface(t)->base) {
        g_fileWrite(data->header, "CORTO_EXTEND(%s);\n", g_fullOid(data->g, corto_interface(t)->base, id));
    }

    /* Serialize members */
    if (corto_serializeMembers(s, v, userData)) {
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
static corto_int16 c_typeComposite(corto_serializer s, corto_value* v, void* userData) {
    corto_type t;

    t = corto_valueType(v);
    switch(corto_interface(t)->kind) {
    case CORTO_DELEGATE:
    case CORTO_STRUCT:
        if (c_typeStruct(s, v, userData)) {
            goto error;
        }
        break;
    case CORTO_INTERFACE:
        if (c_typeAbstract(s, v, userData)) {
            goto error;
        }
        break;
    case CORTO_PROCEDURE:
    case CORTO_CLASS:
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
static corto_int16 c_typeArray(corto_serializer s, corto_value* v, void* userData) {
    corto_type t;
    c_typeWalk_t* data;
    corto_id id, id3, postfix, postfix2;

    CORTO_UNUSED(s);
    CORTO_UNUSED(v);

    data = userData;
    t = corto_valueType(v);
    c_specifierId(data->g, corto_type(t), id, NULL, postfix);
    c_specifierId(data->g, corto_type(corto_collection(t)->elementType), id3, NULL, postfix2);
    g_fileWrite(data->header, "typedef %s %s[%d];\n\n",
            id3,
            id,
            corto_collection(t)->max);

    return 0;
}

/* Sequence object */
static corto_int16 c_typeSequence(corto_serializer s, corto_value* v, void* userData) {
    corto_type t;
    c_typeWalk_t* data;
    corto_id id, id3, postfix, postfix2;

    CORTO_UNUSED(s);
    CORTO_UNUSED(v);

    data = userData;
    t = corto_valueType(v);
    c_specifierId(data->g, corto_type(t), id, NULL, postfix);
    c_specifierId(data->g, corto_type(corto_collection(t)->elementType), id3, NULL, postfix2);

    if (corto_checkAttr(t, CORTO_ATTR_SCOPED)) {
        g_fileWrite(data->header, "CORTO_SEQUENCE(%s, %s,);\n",
                id,
                id3);
    } else {
        g_fileWrite(data->header, "#ifndef %s_DEFINED\n", id);
        g_fileWrite(data->header, "#define %s_DEFINED\n", id);
        g_fileWrite(data->header, "CORTO_SEQUENCE(%s, %s,);\n",
                id,
                id3);
        g_fileWrite(data->header, "#endif\n");
    }
    g_fileWrite(data->header, "\n");

    return 0;
}

/* List object */
static corto_int16 c_typeList(corto_serializer s, corto_value* v, void* userData) {
    corto_type t;
    c_typeWalk_t* data;
    corto_id id, postfix;

    CORTO_UNUSED(s);
    CORTO_UNUSED(v);

    data = userData;
    t = corto_valueType(v);
    c_specifierId(data->g, corto_type(t), id, NULL, postfix);
    g_fileWrite(data->header, "CORTO_LIST(%s);\n\n",
            id);

    return 0;
}

/* Collection object */
static corto_int16 c_typeCollection(corto_serializer s, corto_value* v, void* userData) {
    corto_type t;

    t = corto_valueType(v);
    switch(corto_collection(t)->kind) {
    case CORTO_ARRAY:
        if (c_typeArray(s, v, userData)) {
            goto error;
        }
        break;
    case CORTO_SEQUENCE:
        if (c_typeSequence(s, v, userData)) {
            goto error;
        }
        break;
    case CORTO_LIST:
        if (c_typeList(s, v, userData)) {
            goto error;
        }
        break;
    case CORTO_MAP:
        break;
    }

    return 0;
error:
    return -1;
}

/* Iterator object */
static corto_int16 c_typeIterator(corto_serializer s, corto_value* v, void* userData) {
    corto_type t;

    CORTO_UNUSED(s);
    CORTO_UNUSED(v);

    c_typeWalk_t* data;
    corto_id id, postfix;

    data = userData;
    t = corto_valueType(v);
    c_specifierId(data->g, corto_type(t), id, NULL, postfix);
    g_fileWrite(data->header, "CORTO_ITERATOR(%s);\n\n",
            id);

    return 0;
}

/* Type object */
static corto_int16 c_typeObject(corto_serializer s, corto_value* v, void* userData) {
    c_typeWalk_t* data;
    corto_type t;
    corto_int16 result;

    data = userData;
    t = corto_type(corto_valueType(v));

    /* Reset prefixComma */
    data->prefixComma = FALSE;

    /* Forward to specific type-functions */
    switch(t->kind) {
    case CORTO_VOID:
        result = c_typeVoid(s, v, userData);
        break;
    case CORTO_ANY:
        result = c_typeAny(s, v, userData);
        break;
    case CORTO_PRIMITIVE:
        result = c_typePrimitive(s, v, userData);
        break;
    case CORTO_COMPOSITE:
        result = c_typeComposite(s, v, userData);
        break;
    case CORTO_COLLECTION:
        result = c_typeCollection(s, v, userData);
        break;
    case CORTO_ITERATOR:
        result = c_typeIterator(s, v, userData);
        break;
    default:
        corto_error("c_typeObject: typeKind '%s' not handled by code-generator.", corto_nameof(corto_enum_constant(corto_typeKind_o, t->kind)));
        goto error;
        break;
    }

    return result;
error:
    return -1;
}

/* Metawalk-serializer for types */
struct corto_serializer_s c_typeSerializer(void) {
    struct corto_serializer_s s;

    /* Initialize serializer */
    corto_serializerInit(&s);
    s.metaprogram[CORTO_OBJECT] = c_typeObject;
    s.metaprogram[CORTO_BASE] = c_typeMember;
    s.metaprogram[CORTO_MEMBER] = c_typeMember;
    s.metaprogram[CORTO_CONSTANT] = c_typeConstant;
    s.access = CORTO_GLOBAL;
    s.accessKind = CORTO_XOR;
    s.aliasAction = CORTO_SERIALIZER_ALIAS_IGNORE;
    s.traceKind = CORTO_SERIALIZER_TRACE_ON_FAIL;

    return s;
}

/* Print class-cast macro's */
static int c_typeClassCastWalk(corto_object o, void* userData) {
    c_typeWalk_t* data;
    corto_id id;

    data = userData;

    if (corto_class_instanceof(corto_type_o, o)) {
        if ((corto_type(o)->kind != CORTO_VOID) && (corto_type(o)->kind != CORTO_ANY)) {
            corto_string fullOid = g_fullOid(data->g, o, id);
            if (corto_type(o)->reference) {
                g_fileWrite(data->header, "#define %s(o) ((%s)corto_assertType((corto_type)%s_o, o))\n",
                    fullOid, fullOid, fullOid);
            } else {
                g_fileWrite(data->header, "#define %s(o) ((%s *)corto_assertType((corto_type)%s_o, o))\n",
                    fullOid, fullOid, fullOid);
            }
        }
    }

    return 1;
}

/* Open headerfile, write standard header. */
static g_file c_typeHeaderFileOpen(corto_generator g) {
    g_file result;
    corto_id headerFileName, path;
    corto_iter importIter;
    corto_object import;
    corto_string headerSnippet;
    corto_string bootstrap = gen_getAttribute(g, "bootstrap");

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
    g_fileWrite(result, "#ifndef %s__type_H\n", c_topath(g_getCurrent(g), path, '_'));
    g_fileWrite(result, "#define %s__type_H\n\n", c_topath(g_getCurrent(g), path, '_'));

    /* Don't include this file when generating for the bootstrap */
    if (!bootstrap || strcmp(bootstrap, "true")) {
        g_fileWrite(result, "#include \"corto.h\"\n");
    } else {
        g_fileWrite(result, "#include \"corto_def.h\"\n\n");
    }

    /* Include imports */
    if (g->imports) {
        corto_id path;
        importIter = corto_llIter(g->imports);
        while(corto_iterHasNext(&importIter)) {
            import = corto_iterNext(&importIter);
            g_fileWrite(result, "#include \"%s/%s__type.h\"\n", c_topath(import, path, '/'), corto_nameof(import));
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

static int c_typeDeclare(corto_object o, void* userData) {
    corto_id id;
    corto_type t;
    c_typeWalk_t* data;

    data = userData;
    t = o;

    if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
        g_fileWrite(data->header, "/*  %s */\n", corto_fullname(t, id));

        switch(t->kind) {
        case CORTO_COMPOSITE:
            switch(corto_interface(t)->kind) {
            case CORTO_DELEGATE:
            case CORTO_STRUCT:
                g_fileWrite(data->header, "typedef struct %s %s;\n\n", g_fullOid(data->g, t, id), g_fullOid(data->g, t, id));
                break;
            case CORTO_CLASS:
                g_fileWrite(data->header, "CORTO_CLASS(%s);\n\n", g_fullOid(data->g, t, id));
                break;
            case CORTO_INTERFACE:
                g_fileWrite(data->header, "CORTO_INTERFACE(%s);\n\n", g_fullOid(data->g, t, id));
                break;
            case CORTO_PROCEDURE:
                g_fileWrite(data->header, "CORTO_CLASS(%s);\n\n", g_fullOid(data->g, t, id));
                break;
            }
            break;
        default:
            corto_error("c_typeDeclare: only composite types can be forward declared.");
            goto error;
            break;
        }
    }

    return 0;
error:
    return -1;
}

static int c_typeDefine(corto_object o, void* userData) {
    struct corto_serializer_s s;
    int result;

    result = 0;

    /* Get type-serializer */
    s = c_typeSerializer();

    /* Do metawalk on type */
    result = corto_metaWalk(&s, corto_type(o), userData);

    return result;
}

/* Generator main */
corto_int16 corto_genMain(corto_generator g) {
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

    /* Default prefixes for corto namespaces */
    gen_parse(g, corto_o, FALSE, FALSE, "");
    gen_parse(g, corto_lang_o, FALSE, FALSE, "corto");

    /* Walk classes, print cast-macro's */
    g_fileWrite(walkData.header, "\n");
    g_fileWrite(walkData.header, "/* Casting macro's for classes */\n");
    if (!g_walkRecursive(g, c_typeClassCastWalk, &walkData)) {
        goto error;
    }

    g_fileWrite(walkData.header, "\n");
    g_fileWrite(walkData.header, "/* Type definitions */\n");

    /* Walk objects */
    if (corto_genTypeDepWalk(g, c_typeDeclare, c_typeDefine, &walkData)) {
        goto error;
    }

    /* Close headerfile */
    c_typeHeaderFileClose(walkData.header);

    return 0;
error:
    return -1;
}
