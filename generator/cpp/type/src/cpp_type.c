/*
 * cpp_type.c
 *
 *  Created on: Sep 17, 2012
 *      Author: sander
 */

#include "cpp_type.h"
#include "cpp_common.h"
#include "db_generatorTypeDepWalk.h"

typedef struct cpp_typeWalk_t {
	db_generator g;
	g_file header;
	g_file source;
	db_bool prefixComma; /* For printing members and constants */
}cpp_typeWalk_t;

/* Enumeration constant */
static db_int16 cpp_typeConstant(db_serializer s, db_value* v, void* userData) {
    cpp_typeWalk_t* data;
    db_id constantId;

    DB_UNUSED(s);

    data = userData;

    switch(db_primitive(db_parentof(v->is.constant.t))->kind) {
    case DB_ENUM:
        if (data->prefixComma) {
            g_fileWrite(data->header, ",\n");
        } else {
            data->prefixComma = TRUE;
        }
        g_fileWrite(data->header, "%s = %d", cpp_constantId(data->g, v->is.constant.t, constantId), *v->is.constant.t);
        break;
    case DB_BITMASK:
        g_fileWrite(data->header, "extern int32_t %s;\n", cpp_constantId(data->g, v->is.constant.t, constantId));
        cpp_openScope(data->source, db_parentof(db_parentof(v->is.constant.t)));
        g_fileWrite(data->source, "int32_t %s = 0x%x;\n", cpp_constantId(data->g, v->is.constant.t, constantId), *v->is.constant.t);
        break;
    default:
        db_error("cpp_typeConstant: invalid constant parent-type.");
        goto error;
        break;
    }

    return 0;
error:
    return -1;
}

/* Member */
static db_int16 cpp_typeMember(db_serializer s, db_value* v, void* userData) {
    cpp_typeWalk_t* data;
    db_member m;
    db_id specifier, memberId;

    DB_UNUSED(s);

    if (v->kind == DB_MEMBER) {
		data = userData;
		m = v->is.member.t;

		/* Get typespecifier */
		if (!cpp_specifierId(data->g, m->type, specifier)) {
			goto error;
		}

		g_fileWrite(data->header, "%s %s;\n", specifier, g_id(data->g, db_nameof(m), memberId));
    }

    return 0;
error:
    return -1;
}


/* Enumeration object */
static db_int16 cpp_typePrimitiveEnum(db_serializer s, db_value* v, void* userData) {
    cpp_typeWalk_t* data;
    db_enum t;
    db_id id;

    DB_UNUSED(s);

    data = userData;
    t = db_enum(db_valueType(v));

    /* Write enumeration */
    g_fileWrite(data->header, "typedef enum %s {\n", g_oid(data->g, t, id));
    g_fileIndent(data->header);

    /* Write enumeration constants */
    if (db_serializeConstants(s, v, userData)) {
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
static db_int16 cpp_typePrimitiveBitmask(db_serializer s, db_value* v, void* userData) {
    cpp_typeWalk_t* data;
    db_enum t;
    db_id id;

    DB_UNUSED(s);

    data = userData;
    t = db_enum(db_valueType(v));

    g_fileWrite(data->header, "DB_BITMASK(%s);\n", g_oid(data->g, t, id));

    /* Write enumeration constants */
    if (db_serializeConstants(s, v, userData)) {
        goto error;
    }

    return 0;
error:
    return -1;
}

/* Any object */
static db_int16 cpp_typeAny(db_serializer s, db_value* v, void* userData) {
    db_type t;
    cpp_typeWalk_t* data;
    db_id id;

    DB_UNUSED(s);

    t = db_valueType(v)->real;
    data = userData;

    g_fileWrite(data->header, "struct %s{\n", g_oid(data->g, t, id));
    g_fileIndent(data->header);
    g_fileWrite(data->header, "hyve::lang::type type;\n");
    g_fileWrite(data->header, "void* value;\n");
    g_fileWrite(data->header, "hyve::lang::_bool owner;\n");
    g_fileDedent(data->header);
    g_fileWrite(data->header, "};\n");

    return 0;
}

/* Void object */
static db_int16 cpp_typeVoid(db_serializer s, db_value* v, void* userData) {
	db_type t;
    cpp_typeWalk_t* data;
    db_id id;

    DB_UNUSED(s);

	t = db_valueType(v)->real;
    data = userData;

	if (t->reference) {
		g_fileWrite(data->header, "typedef void* %s;\n", g_oid(data->g, t, id));
	} else {
		g_fileWrite(data->header, "typedef void %s;\n", g_oid(data->g, t, id));
	}

	return 0;
}

/* Primitive object */
static db_int16 cpp_typePrimitive(db_serializer s, db_value* v, void* userData) {
    db_char buff[16];
    db_type t;
    db_id id;
    cpp_typeWalk_t* data;

    DB_UNUSED(s);

    data = userData;
    t = db_valueType(v)->real;

    /* Obtain platform type-name for primitive */
    if (db_checkAttr(t, DB_ATTR_SCOPED)) {
        /* Only parse scoped primitive types, anonymous primitives will always
         * refer to the base platform primtives. */
        switch(db_primitive(t)->kind) {
        case DB_ENUM:
            g_fileWrite(data->header, "\n");
            g_fileWrite(data->header, "/* %s */\n", db_fullname(t, id));
            if (cpp_typePrimitiveEnum(s, v, userData)) {
                goto error;
            }
            break;
        case DB_BITMASK:
            g_fileWrite(data->header, "\n");
            g_fileWrite(data->header, "/* %s */\n", db_fullname(t, id));
            if (cpp_typePrimitiveBitmask(s, v, userData)) {
                goto error;
            }
            break;
        default:
            if (!cpp_primitiveId(db_primitive(t), buff)) {
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
static db_int16 cpp_typeStruct(db_serializer s, db_value* v, void* userData) {
    cpp_typeWalk_t* data;
    db_id id;
    db_type t;

    data = userData;
    t = db_valueType(v)->real;

    /* Open struct */
    g_fileWrite(data->header, "struct %s {\n", g_oid(data->g, t, id));


    /* Serialize members */
    g_fileIndent(data->header);
    if (db_serializeMembers(s, v, userData)) {
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
static db_int16 cpp_typeAbstract(db_serializer s, db_value* v, void* userData) {
    DB_UNUSED(s);
    DB_UNUSED(v);
    DB_UNUSED(userData);

    return 0;
}

/* Class object */
static db_int16 cpp_typeClass(db_serializer s, db_value* v, void* userData) {
    cpp_typeWalk_t* data;
    db_id id;
    db_type t;

    data = userData;
    t = db_valueType(v)->real;

    /* Open class */
    if (t->alignment) {
        g_fileWrite(data->header, "DB_CLASS_DEF(%s) {\n", g_oid(data->g, t, id));
        g_fileIndent(data->header);

        /* Write base */
        if (db_interface(t)->base && db_type(db_interface(t)->base)->alignment) {
            g_fileWrite(data->header, "DB_EXTEND(%s);\n", cpp_specifierId(data->g, db_typedef(db_interface(t)->base), id));
        }

        /* Serialize members */
        if (db_serializeMembers(s, v, userData)) {
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
static db_int16 cpp_typeProcedure(db_serializer s, db_value* v, void* userData) {
    cpp_typeWalk_t* data;
    db_id id;
    db_type t;

    data = userData;
    t = db_valueType(v)->real;

    /* Open class */
    if (t->alignment) {
        g_fileWrite(data->header, "DB_PROCEDURE_DEF(%s) {\n", g_oid(data->g, t, id));
        g_fileIndent(data->header);

        /* Write base */
        if (db_interface(t)->base && db_type(db_interface(t)->base)->alignment) {
            g_fileWrite(data->header, "DB_EXTEND(%s);\n", g_oid(data->g, db_interface(t)->base, id));
        }

        /* Serialize members */
        if (db_serializeMembers(s, v, userData)) {
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
static db_int16 cpp_typeComposite(db_serializer s, db_value* v, void* userData) {
    db_type t;

    t = db_valueType(v)->real;
    switch(db_interface(t)->kind) {
    case DB_STRUCT:
        if (cpp_typeStruct(s, v, userData)) {
            goto error;
        }
        break;
    case DB_INTERFACE:
    	if (cpp_typeAbstract(s, v, userData)) {
    		goto error;
    	}
    	break;
    case DB_CLASS:
    	if (cpp_typeClass(s, v, userData)) {
    		goto error;
    	}
    	break;
    case DB_PROCEDURE:
    	if (cpp_typeProcedure(s, v, userData)) {
    		goto error;
    	}
    	break;
    default: {
    	db_id id;
        db_error("cpp_typeComposite: invalid composite-kind for type '%s' (%d)", db_fullname(t, id), db_interface(t)->kind);
        break;
    }
    }

    return 0;
error:
    return -1;
}

/* Array object */
static db_int16 cpp_typeArray(db_serializer s, db_value* v, void* userData) {
	db_type t;
	cpp_typeWalk_t* data;
	db_id id, id2;

	DB_UNUSED(s);
	DB_UNUSED(v);

	data = userData;
	t = db_valueType(v)->real;

    g_fileWrite(data->header, "typedef %s %s[%d];\n",
            g_fullOid(data->g, db_collection(t)->elementType, id),
            cpp_specifierDecl(data->g, db_typedef(t), id2),
            db_collection(t)->max);


	return 0;
}

/* Sequence object */
static db_int16 cpp_typeSequence(db_serializer s, db_value* v, void* userData) {
	db_type t;
	cpp_typeWalk_t* data;
	db_id id, id2;

	DB_UNUSED(s);
	DB_UNUSED(v);

	data = userData;
	t = db_valueType(v)->real;


	g_fileWrite(data->header, "DB_SEQUENCE(%s, %s,/* No postfix */);\n",
	        cpp_specifierDecl(data->g, db_typedef(t), id),
			g_fullOid(data->g, db_collection(t)->elementType, id2));

	return 0;
}

/* Collection object */
static db_int16 cpp_typeCollection(db_serializer s, db_value* v, void* userData) {
	db_type t;

	t = db_valueType(v)->real;

	switch(db_collection(t)->kind) {
	case DB_ARRAY:
		if (cpp_typeArray(s, v, userData)) {
			goto error;
		}
		break;
	case DB_SEQUENCE:
		if (cpp_typeSequence(s, v, userData)) {
			goto error;
		}
		break;
	case DB_LIST:
		break;
	case DB_MAP:
		break;
	}

	return 0;
error:
	return -1;
}

/* Type object */
static db_int16 cpp_typeObject(db_serializer s, db_value* v, void* userData) {
    cpp_typeWalk_t* data;
    db_type t;
    db_int16 result;

    data = userData;
    t = db_type(db_valueType(v));

    /* Reset prefixComma */
    data->prefixComma = FALSE;

    /* Open scope */
    if (db_checkAttr(t, DB_ATTR_SCOPED)) {
        cpp_openScope(data->header, db_parentof(t));
    } else {
        /* Place anonymous collection-types in the scope of the elementType */
        if (t->kind == DB_COLLECTION) {
            /* Anonymous lists and maps are mapped directly to hyve::ll or hyve::rbtree, so
             * no need to open a scope for them. */
            switch(db_collection(t)->kind) {
            case DB_ARRAY:
            case DB_SEQUENCE:
                cpp_openScope(data->header, db_collection(t)->elementType);
                break;
            default:
                break;
            }
        }
    }

    /* Forward to specific type-functions */
    switch(t->kind) {
    case DB_ANY:
        result = cpp_typeAny(s, v, userData);
        break;
    case DB_VOID:
    	result = cpp_typeVoid(s, v, userData);
    	break;
    case DB_PRIMITIVE:
        result = cpp_typePrimitive(s, v, userData);
        break;
    case DB_COMPOSITE:
        result = cpp_typeComposite(s, v, userData);
        break;
    case DB_COLLECTION:
    	result = cpp_typeCollection(s, v, userData);
        break;
    default:
        db_error("cpp_typeObject: typeKind '%s' not handled by code-generator.", db_nameof(db_enum_constant(db_typeKind_o, t->kind)));
        goto error;
        break;
    }

    return result;
error:
    return -1;
}

/* Metawalk-serializer for types */
struct db_serializer_s cpp_typeSerializer(void) {
    struct db_serializer_s s;

    /* Initialize serializer */
    db_serializerInit(&s);
    s.metaprogram[DB_OBJECT] = cpp_typeObject;
    s.metaprogram[DB_MEMBER] = cpp_typeMember;
    s.metaprogram[DB_BASE] = cpp_typeMember;
    s.metaprogram[DB_CONSTANT] = cpp_typeConstant;
    s.access = DB_GLOBAL;
    s.accessKind = DB_XOR;
    s.traceKind = DB_SERIALIZER_TRACE_ON_FAIL;

    return s;
}

/* Open headerfile, write standard header. */
static g_file cpp_typeHeaderFileOpen(db_generator g) {
	g_file result;
	db_id headerFileName, path;

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
        if (g_getCurrent(g) != hyve_lang_o) {
            g_fileWrite(result, "#include \"hyve.hpp\"\n");
        }
        g_fileWrite(result, "#include \"hyve/def.hpp\"\n\n");
	} else {
	    db_error("cpp_typeHeaderFileOpen: failed to open file '%s'", headerFileName);
	}

	return result;
}

/* Open sourcefile, write standard source. */
static g_file cpp_typeSourceFileOpen(db_generator g) {
    g_file result;
    db_id sourceFileName, headerFileName, path;

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


static int cpp_typeDeclare(db_object o, void* userData) {
    db_id id;
    db_type t;
    cpp_typeWalk_t* data;

    data = userData;
    t = o;

    /* Open scope */
    cpp_openScope(data->header, db_parentof(o));

    g_fileWrite(data->header, "\n");
    g_fileWrite(data->header, "/*  %s */\n", db_fullname(t, id));

    switch(t->kind) {
    case DB_COMPOSITE:
        switch(db_interface(t)->kind) {
        case DB_STRUCT:
            g_fileWrite(data->header, "typedef struct %s %s;\n", g_oid(data->g, t, id), g_oid(data->g, t, id));
            break;
        case DB_CLASS:
            g_fileWrite(data->header, "DB_CLASS(%s);\n", g_oid(data->g, t, id));
            break;
        case DB_INTERFACE:
            g_fileWrite(data->header, "DB_INTERFACE(%s);\n", g_oid(data->g, t, id));
            break;
        case DB_PROCEDURE:
        	g_fileWrite(data->header, "DB_PROCEDURE(%s);\n", g_oid(data->g, t, id));
        	break;
        }
        break;
    default:
        db_error("cpp_typeDeclare: only composite types can be forward declared.");
        goto error;
        break;
    }

    return 0;
error:
    return -1;
}

static int cpp_typeDefine(db_object o, void* userData) {
	cpp_typeWalk_t* data;
    int result;

    result = 0;
	data = userData;

    /* Serialize typedef */
    if (db_typedef(o)->real != o) {
    	db_typedef t;
        db_id spec, id2;
    	t = o;

        /* Open scope */
        cpp_openScope(data->header, db_parentof(o));

    	/* Serialize a typedef */
		cpp_specifierId(data->g, t->type, spec);

		/* Serialize typedef */
		g_fileWrite(data->header, "typedef %s %s;\n", spec, g_oid(data->g, t, id2));

    /* Serialize type */
    } else {
        struct db_serializer_s s;

		/* Get type-serializer */
		s = cpp_typeSerializer();

		/* Do metawalk on type */
		result = db_metaWalk(&s, db_type(o), userData);
    }

    return result;
}

static int cpp_classWalk(db_object o, void* userData) {
	cpp_typeWalk_t* data;
	db_id id;

	data = userData;

	/* Forward declaration of classes */
	if (db_class_instanceof(db_interface_o, o) && db_type(o)->reference) {
		cpp_openScope(data->header, db_parentof(o));
		g_fileWrite(data->header, "class %s;\n", g_oid(data->g, o, id));
	}

	return 1;
}

/* Generator main */
db_int16 hyve_genMain(db_generator g) {
	cpp_typeWalk_t walkData;

	/* Prepare walkdata, open headerfile */
	walkData.header = cpp_typeHeaderFileOpen(g);
	walkData.source = cpp_typeSourceFileOpen(g);
	walkData.g = g;
	walkData.prefixComma = FALSE;

	/* Predeclare all classes */
	g_setIdKind(g, DB_GENERATOR_ID_CLASS_UPPER);
	g_walkRecursive(g, cpp_classWalk, &walkData);

	/* Generate hyve-types */
	g_setIdKind(g, DB_GENERATOR_ID_CLASS_LOWER);

	/* Walk objects */
	if (db_genTypeDepWalk(g, cpp_typeDeclare, cpp_typeDefine, &walkData)) {
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
