/*
 * cpp_type.c
 *
 *  Created on: Sep 17, 2012
 *      Author: sander
 */

#include "cpp_type.h"
#include "cpp_common.h"
#include "cx_generatorTypeDepWalk.h"

typedef struct cpp_typeWalk_t {
    cx_generator g;
    g_file header;
    g_file source;
    cx_bool prefixComma; /* For printing members and constants */
}cpp_typeWalk_t;

/* Enumeration constant */
static cx_int16 cpp_typeConstant(cx_serializer s, cx_value* v, void* userData) {
    cpp_typeWalk_t* data;
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
        g_fileWrite(data->header, "%s = %d", cpp_constantId(data->g, v->is.constant.t, constantId), *v->is.constant.t);
        break;
    case CX_BITMASK:
        g_fileWrite(data->header, "extern int32_t %s;\n", cpp_constantId(data->g, v->is.constant.t, constantId));
        cpp_openScope(data->source, cx_parentof(cx_parentof(v->is.constant.t)));
        g_fileWrite(data->source, "int32_t %s = 0x%x;\n", cpp_constantId(data->g, v->is.constant.t, constantId), *v->is.constant.t);
        break;
    default:
        cx_error("cpp_typeConstant: invalid constant parent-type.");
        goto error;
        break;
    }

    return 0;
error:
    return -1;
}

/* Member */
static cx_int16 cpp_typeMember(cx_serializer s, cx_value* v, void* userData) {
    cpp_typeWalk_t* data;
    cx_member m;
    cx_id specifier, memberId;

    CX_UNUSED(s);

    if (v->kind == CX_MEMBER) {
        data = userData;
        m = v->is.member.t;

        /* Get typespecifier */
        if (!cpp_specifierId(data->g, m->type, specifier)) {
            goto error;
        }

        g_fileWrite(data->header, "%s %s;\n", specifier, g_id(data->g, cx_nameof(m), memberId));
    }

    return 0;
error:
    return -1;
}


/* Enumeration object */
static cx_int16 cpp_typePrimitiveEnum(cx_serializer s, cx_value* v, void* userData) {
    cpp_typeWalk_t* data;
    cx_enum t;
    cx_id id;

    CX_UNUSED(s);

    data = userData;
    t = cx_enum(cx_valueType(v));

    /* Write enumeration */
    g_fileWrite(data->header, "typedef enum %s {\n", g_oid(data->g, t, id));
    g_fileIndent(data->header);

    /* Write enumeration constants */
    if (cx_serializeConstants(s, v, userData)) {
        goto error;
    }

    g_fileDedent(data->header);
    g_fileWrite(data->header, "\n");
    g_fileWrite(data->header, "} %s;\n", g_oid(data->g, t, id));

    return 0;
error:
    return -1;
}

/* Bitmask object */
static cx_int16 cpp_typePrimitiveBitmask(cx_serializer s, cx_value* v, void* userData) {
    cpp_typeWalk_t* data;
    cx_enum t;
    cx_id id;

    CX_UNUSED(s);

    data = userData;
    t = cx_enum(cx_valueType(v));

    g_fileWrite(data->header, "CX_BITMASK(%s);\n", g_oid(data->g, t, id));

    /* Write enumeration constants */
    if (cx_serializeConstants(s, v, userData)) {
        goto error;
    }

    return 0;
error:
    return -1;
}

/* Any object */
static cx_int16 cpp_typeAny(cx_serializer s, cx_value* v, void* userData) {
    cx_type t;
    cpp_typeWalk_t* data;
    cx_id id;

    CX_UNUSED(s);

    t = cx_valueType(v)->real;
    data = userData;

    g_fileWrite(data->header, "struct %s{\n", g_oid(data->g, t, id));
    g_fileIndent(data->header);
    g_fileWrite(data->header, "cortex::lang::type type;\n");
    g_fileWrite(data->header, "void* value;\n");
    g_fileWrite(data->header, "cortex::lang::_bool owner;\n");
    g_fileDedent(data->header);
    g_fileWrite(data->header, "};\n");

    return 0;
}

/* Void object */
static cx_int16 cpp_typeVoid(cx_serializer s, cx_value* v, void* userData) {
    cx_type t;
    cpp_typeWalk_t* data;
    cx_id id;

    CX_UNUSED(s);

    t = cx_valueType(v)->real;
    data = userData;

    if (t->reference) {
        g_fileWrite(data->header, "typedef void* %s;\n", g_oid(data->g, t, id));
    } else {
        g_fileWrite(data->header, "typedef void %s;\n", g_oid(data->g, t, id));
    }

    return 0;
}

/* Primitive object */
static cx_int16 cpp_typePrimitive(cx_serializer s, cx_value* v, void* userData) {
    cx_char buff[16];
    cx_type t;
    cx_id id;
    cpp_typeWalk_t* data;

    CX_UNUSED(s);

    data = userData;
    t = cx_valueType(v)->real;

    /* Obtain platform type-name for primitive */
    if (cx_checkAttr(t, CX_ATTR_SCOPED)) {
        /* Only parse scoped primitive types, anonymous primitives will always
         * refer to the base platform primtives. */
        switch(cx_primitive(t)->kind) {
        case CX_ENUM:
            g_fileWrite(data->header, "\n");
            g_fileWrite(data->header, "/* %s */\n", cx_fullname(t, id));
            if (cpp_typePrimitiveEnum(s, v, userData)) {
                goto error;
            }
            break;
        case CX_BITMASK:
            g_fileWrite(data->header, "\n");
            g_fileWrite(data->header, "/* %s */\n", cx_fullname(t, id));
            if (cpp_typePrimitiveBitmask(s, v, userData)) {
                goto error;
            }
            break;
        default:
            if (!cpp_primitiveId(cx_primitive(t), buff)) {
                goto error;
            }

            /* Write typedef */
            g_fileWrite(data->header, "typedef %s %s;\n", buff, g_oid(data->g, t, id));
            break;
        }
    }

    return 0;
error:
    return -1;
}

/* Struct object */
static cx_int16 cpp_typeStruct(cx_serializer s, cx_value* v, void* userData) {
    cpp_typeWalk_t* data;
    cx_id id;
    cx_type t;

    data = userData;
    t = cx_valueType(v)->real;

    /* Open struct */
    g_fileWrite(data->header, "struct %s {\n", g_oid(data->g, t, id));


    /* Serialize members */
    g_fileIndent(data->header);
    if (cx_serializeMembers(s, v, userData)) {
        goto error;
    }
    g_fileDedent(data->header);

    /* Close struct */
    g_fileWrite(data->header, "};\n");


    return 0;
error:
    return -1;
}

/* Abstract object */
static cx_int16 cpp_typeAbstract(cx_serializer s, cx_value* v, void* userData) {
    CX_UNUSED(s);
    CX_UNUSED(v);
    CX_UNUSED(userData);

    return 0;
}

/* Class object */
static cx_int16 cpp_typeClass(cx_serializer s, cx_value* v, void* userData) {
    cpp_typeWalk_t* data;
    cx_id id;
    cx_type t;

    data = userData;
    t = cx_valueType(v)->real;

    /* Open class */
    if (t->alignment) {
        g_fileWrite(data->header, "CX_CLASS_DEF(%s) {\n", g_oid(data->g, t, id));
        g_fileIndent(data->header);

        /* Write base */
        if (cx_interface(t)->base && cx_type(cx_interface(t)->base)->alignment) {
            g_fileWrite(data->header, "CX_EXTEND(%s);\n", cpp_specifierId(data->g, cx_typedef(cx_interface(t)->base), id));
        }

        /* Serialize members */
        if (cx_serializeMembers(s, v, userData)) {
            goto error;
        }
        g_fileDedent(data->header);

        /* Close class */
        g_fileWrite(data->header, "};\n");
    }

    return 0;
error:
    return -1;
}

/* Procedure object */
static cx_int16 cpp_typeProcedure(cx_serializer s, cx_value* v, void* userData) {
    cpp_typeWalk_t* data;
    cx_id id;
    cx_type t;

    data = userData;
    t = cx_valueType(v)->real;

    /* Open class */
    if (t->alignment) {
        g_fileWrite(data->header, "CX_PROCEDURE_DEF(%s) {\n", g_oid(data->g, t, id));
        g_fileIndent(data->header);

        /* Write base */
        if (cx_interface(t)->base && cx_type(cx_interface(t)->base)->alignment) {
            g_fileWrite(data->header, "CX_EXTEND(%s);\n", g_oid(data->g, cx_interface(t)->base, id));
        }

        /* Serialize members */
        if (cx_serializeMembers(s, v, userData)) {
            goto error;
        }
        g_fileDedent(data->header);

        /* Close class */
        g_fileWrite(data->header, "};\n");
    }

    return 0;
error:
    return -1;
}

/* Composite object */
static cx_int16 cpp_typeComposite(cx_serializer s, cx_value* v, void* userData) {
    cx_type t;

    t = cx_valueType(v)->real;
    switch(cx_interface(t)->kind) {
    case CX_STRUCT:
        if (cpp_typeStruct(s, v, userData)) {
            goto error;
        }
        break;
    case CX_INTERFACE:
        if (cpp_typeAbstract(s, v, userData)) {
            goto error;
        }
        break;
    case CX_CLASS:
        if (cpp_typeClass(s, v, userData)) {
            goto error;
        }
        break;
    case CX_PROCEDURE:
        if (cpp_typeProcedure(s, v, userData)) {
            goto error;
        }
        break;
    default: {
        cx_id id;
        cx_error("cpp_typeComposite: invalid composite-kind for type '%s' (%d)", cx_fullname(t, id), cx_interface(t)->kind);
        break;
    }
    }

    return 0;
error:
    return -1;
}

/* Array object */
static cx_int16 cpp_typeArray(cx_serializer s, cx_value* v, void* userData) {
    cx_type t;
    cpp_typeWalk_t* data;
    cx_id id, id2;

    CX_UNUSED(s);
    CX_UNUSED(v);

    data = userData;
    t = cx_valueType(v)->real;

    g_fileWrite(data->header, "typedef %s %s[%d];\n",
            g_fullOid(data->g, cx_collection(t)->elementType, id),
            cpp_specifierDecl(data->g, cx_typedef(t), id2),
            cx_collection(t)->max);


    return 0;
}

/* Sequence object */
static cx_int16 cpp_typeSequence(cx_serializer s, cx_value* v, void* userData) {
    cx_type t;
    cpp_typeWalk_t* data;
    cx_id id, id2;

    CX_UNUSED(s);
    CX_UNUSED(v);

    data = userData;
    t = cx_valueType(v)->real;


    g_fileWrite(data->header, "CX_SEQUENCE(%s, %s,/* No postfix */);\n",
            cpp_specifierDecl(data->g, cx_typedef(t), id),
            g_fullOid(data->g, cx_collection(t)->elementType, id2));

    return 0;
}

/* Collection object */
static cx_int16 cpp_typeCollection(cx_serializer s, cx_value* v, void* userData) {
    cx_type t;

    t = cx_valueType(v)->real;

    switch(cx_collection(t)->kind) {
    case CX_ARRAY:
        if (cpp_typeArray(s, v, userData)) {
            goto error;
        }
        break;
    case CX_SEQUENCE:
        if (cpp_typeSequence(s, v, userData)) {
            goto error;
        }
        break;
    case CX_LIST:
        break;
    case CX_MAP:
        break;
    }

    return 0;
error:
    return -1;
}

/* Type object */
static cx_int16 cpp_typeObject(cx_serializer s, cx_value* v, void* userData) {
    cpp_typeWalk_t* data;
    cx_type t;
    cx_int16 result;

    data = userData;
    t = cx_type(cx_valueType(v));

    /* Reset prefixComma */
    data->prefixComma = FALSE;

    /* Open scope */
    if (cx_checkAttr(t, CX_ATTR_SCOPED)) {
        cpp_openScope(data->header, cx_parentof(t));
    } else {
        /* Place anonymous collection-types in the scope of the elementType */
        if (t->kind == CX_COLLECTION) {
            /* Anonymous lists and maps are mapped directly to cortex::ll or cortex::rbtree, so
             * no need to open a scope for them. */
            switch(cx_collection(t)->kind) {
            case CX_ARRAY:
            case CX_SEQUENCE:
                cpp_openScope(data->header, cx_collection(t)->elementType);
                break;
            default:
                break;
            }
        }
    }

    /* Forward to specific type-functions */
    switch(t->kind) {
    case CX_ANY:
        result = cpp_typeAny(s, v, userData);
        break;
    case CX_VOID:
        result = cpp_typeVoid(s, v, userData);
        break;
    case CX_PRIMITIVE:
        result = cpp_typePrimitive(s, v, userData);
        break;
    case CX_COMPOSITE:
        result = cpp_typeComposite(s, v, userData);
        break;
    case CX_COLLECTION:
        result = cpp_typeCollection(s, v, userData);
        break;
    default:
        cx_error("cpp_typeObject: typeKind '%s' not handled by code-generator.", cx_nameof(cx_enum_constant(cx_typeKind_o, t->kind)));
        goto error;
        break;
    }

    return result;
error:
    return -1;
}

/* Metawalk-serializer for types */
struct cx_serializer_s cpp_typeSerializer(void) {
    struct cx_serializer_s s;

    /* Initialize serializer */
    cx_serializerInit(&s);
    s.metaprogram[CX_OBJECT] = cpp_typeObject;
    s.metaprogram[CX_MEMBER] = cpp_typeMember;
    s.metaprogram[CX_BASE] = cpp_typeMember;
    s.metaprogram[CX_CONSTANT] = cpp_typeConstant;
    s.access = CX_GLOBAL;
    s.accessKind = CX_XOR;
    s.traceKind = CX_SERIALIZER_TRACE_ON_FAIL;

    return s;
}

/* Open headerfile, write standard header. */
static g_file cpp_typeHeaderFileOpen(cx_generator g) {
    g_file result;
    cx_id headerFileName, path;

    /* Translate current object to path */
    cpp_topath(g_getCurrent(g), path);

    /* Create file */
    if (strlen(path)) {
        sprintf(headerFileName, "include/%s/_type.hpp", path);
    } else {
        sprintf(headerFileName, "include/_type.hpp");
    }
    result = g_fileOpen(g, headerFileName);
    if (result) {
        /* Print standard comments and includes */
        g_fileWrite(result, "/* %s\n", headerFileName);
        g_fileWrite(result, " *\n");
        g_fileWrite(result, " *  Generated on %s\n", __DATE__);
        g_fileWrite(result, " *    Type-definitions for C++ language.\n");
        g_fileWrite(result, " *    This file contains generated code. Do not modify!\n");
        g_fileWrite(result, " */\n\n");
        g_fileWrite(result, "#ifndef %s__type_HPP\n", g_getName(g));
        g_fileWrite(result, "#define %s__type_HPP\n\n", g_getName(g));
        if (g_getCurrent(g) != cortex_lang_o) {
            g_fileWrite(result, "#include \"cortex.hpp\"\n");
        }
        g_fileWrite(result, "#include \"cortex/def.hpp\"\n\n");
    } else {
        cx_error("cpp_typeHeaderFileOpen: failed to open file '%s'", headerFileName);
    }

    return result;
}

/* Open sourcefile, write standard source. */
static g_file cpp_typeSourceFileOpen(cx_generator g) {
    g_file result;
    cx_id sourceFileName, headerFileName, path;

    /* Translate current object to path */
    cpp_topath(g_getCurrent(g), path);

    /* Create file */
    if (strlen(path)) {
        sprintf(sourceFileName, "src/%s/_type.cpp", path);
        sprintf(headerFileName, "%s/_type.hpp", path);
    } else {
        sprintf(sourceFileName, "src/_type.cpp");
        sprintf(headerFileName, "_type.hpp");
    }
    result = g_fileOpen(g, sourceFileName);

    /* Print standard comments and includes */
    g_fileWrite(result, "/* %s\n", sourceFileName);
    g_fileWrite(result, " *\n");
    g_fileWrite(result, " *  Generated on %s\n", __DATE__);
    g_fileWrite(result, " *    Type-definitions for C++ language.\n");
    g_fileWrite(result, " *    This file contains generated code. Do not modify!\n");
    g_fileWrite(result, " */\n\n");
    g_fileWrite(result, "#include \"%s\"\n\n", headerFileName);

    return result;
}

/* Close headerfile */
static void cpp_typeHeaderFileClose(g_file file) {

    /* Print standard comments and includes */
    g_fileWrite(file, "\n");
    g_fileWrite(file, "#endif\n\n");
}

/* Close headerfile */
static void cpp_typeSourceFileClose(g_file file) {

    /* Close last opened scope */
    cpp_closeScope(file);
}


static int cpp_typeDeclare(cx_object o, void* userData) {
    cx_id id;
    cx_type t;
    cpp_typeWalk_t* data;

    data = userData;
    t = o;

    /* Open scope */
    cpp_openScope(data->header, cx_parentof(o));

    g_fileWrite(data->header, "\n");
    g_fileWrite(data->header, "/*  %s */\n", cx_fullname(t, id));

    switch(t->kind) {
    case CX_COMPOSITE:
        switch(cx_interface(t)->kind) {
        case CX_STRUCT:
            g_fileWrite(data->header, "typedef struct %s %s;\n", g_oid(data->g, t, id), g_oid(data->g, t, id));
            break;
        case CX_CLASS:
            g_fileWrite(data->header, "CX_CLASS(%s);\n", g_oid(data->g, t, id));
            break;
        case CX_INTERFACE:
            g_fileWrite(data->header, "CX_INTERFACE(%s);\n", g_oid(data->g, t, id));
            break;
        case CX_PROCEDURE:
            g_fileWrite(data->header, "CX_PROCEDURE(%s);\n", g_oid(data->g, t, id));
            break;
        }
        break;
    default:
        cx_error("cpp_typeDeclare: only composite types can be forward declared.");
        goto error;
        break;
    }

    return 0;
error:
    return -1;
}

static int cpp_typeDefine(cx_object o, void* userData) {
    cpp_typeWalk_t* data;
    int result;

    result = 0;
    data = userData;

    /* Serialize typedef */
    if (cx_typedef(o)->real != o) {
        cx_typedef t;
        cx_id spec, id2;
        t = o;

        /* Open scope */
        cpp_openScope(data->header, cx_parentof(o));

        /* Serialize a typedef */
        cpp_specifierId(data->g, t->type, spec);

        /* Serialize typedef */
        g_fileWrite(data->header, "typedef %s %s;\n", spec, g_oid(data->g, t, id2));

    /* Serialize type */
    } else {
        struct cx_serializer_s s;

        /* Get type-serializer */
        s = cpp_typeSerializer();

        /* Do metawalk on type */
        result = cx_metaWalk(&s, cx_type(o), userData);
    }

    return result;
}

static int cpp_classWalk(cx_object o, void* userData) {
    cpp_typeWalk_t* data;
    cx_id id;

    data = userData;

    /* Forward declaration of classes */
    if (cx_class_instanceof(cx_interface_o, o) && cx_type(o)->reference) {
        cpp_openScope(data->header, cx_parentof(o));
        g_fileWrite(data->header, "class %s;\n", g_oid(data->g, o, id));
    }

    return 1;
}

/* Generator main */
cx_int16 cortex_genMain(cx_generator g) {
    cpp_typeWalk_t walkData;

    /* Prepare walkdata, open headerfile */
    walkData.header = cpp_typeHeaderFileOpen(g);
    walkData.source = cpp_typeSourceFileOpen(g);
    walkData.g = g;
    walkData.prefixComma = FALSE;

    /* Predeclare all classes */
    g_setIdKind(g, CX_GENERATOR_ID_CLASS_UPPER);
    g_walkRecursive(g, cpp_classWalk, &walkData);

    /* Generate cortex-types */
    g_setIdKind(g, CX_GENERATOR_ID_CLASS_LOWER);

    /* Walk objects */
    if (cx_genTypeDepWalk(g, cpp_typeDeclare, cpp_typeDefine, &walkData)) {
        goto error;
    }

    cpp_closeScope(walkData.header);

    /* Close headerfile */
    cpp_typeHeaderFileClose(walkData.header);

    /* Close sourcefile */
    cpp_typeSourceFileClose(walkData.source);

    return 0;
error:
    return -1;
}
