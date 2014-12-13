/*
 * c_type.c
 *
 *  Created on: Sep 17, 2012
 *      Author: sander
 */

#include "c_type.h"
#include "c_common.h"
#include "db_generatorTypeDepWalk.h"

typedef struct c_typeWalk_t {
	db_generator g;
	g_file header;
	db_bool prefixComma; /* For printing members and constants */
}c_typeWalk_t;

/* Enumeration constant */
static db_int16 c_typeConstant(db_serializer s, db_value* v, void* userData) {
    c_typeWalk_t* data;
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
        g_fileWrite(data->header, "%s = %d", c_constantId(data->g, v->is.constant.t, constantId), *v->is.constant.t);
        break;
    case DB_BITMASK:
        g_fileWrite(data->header, "#define %s (0x%x)\n", c_constantId(data->g, v->is.constant.t, constantId), *v->is.constant.t);
        break;
    default:
        db_error("c_typeConstant: invalid constant parent-type.");
        goto error;
        break;
    }

    return 0;
error:
    return -1;
}

/* Member */
static db_int16 c_typeMember(db_serializer s, db_value* v, void* userData) {
    c_typeWalk_t* data;
    db_member m;
    db_id specifier, postfix, memberId;

    DB_UNUSED(s);

    if (v->kind == DB_MEMBER) {
		data = userData;
		m = v->is.member.t;

		/* Get typespecifier */
		if (c_specifierId(data->g, m->type, specifier, NULL, postfix)) {
			goto error;
		}

		if (m->id != (db_uint32)-1) {
		    g_fileWrite(data->header, "%s %s%s;\n", specifier, g_id(data->g, db_nameof(m), memberId), postfix);
		} else {
		    g_fileWrite(data->header, "%s _parent%s;\n", specifier, postfix);
		}
    }

    return 0;
error:
    return -1;
}


/* Enumeration object */
static db_int16 c_typePrimitiveEnum(db_serializer s, db_value* v, void* userData) {
    c_typeWalk_t* data;
    db_enum t;
    db_id id;

    DB_UNUSED(s);

    data = userData;
    t = db_enum(db_valueType(v));

    /* Write enumeration */
    g_fileWrite(data->header, "typedef enum %s {\n", g_fullOid(data->g, t, id));
    g_fileIndent(data->header);

    /* Write enumeration constants */
    if (db_serializeConstants(s, v, userData)) {
        goto error;
    }

    g_fileDedent(data->header);
    g_fileWrite(data->header, "\n");
    g_fileWrite(data->header, "} %s;\n", g_fullOid(data->g, t, id));

    return 0;
error:
    return -1;
}

/* Bitmask object */
static db_int16 c_typePrimitiveBitmask(db_serializer s, db_value* v, void* userData) {
    c_typeWalk_t* data;
    db_enum t;
    db_id id;

    DB_UNUSED(s);

    data = userData;
    t = db_enum(db_valueType(v));

    g_fileWrite(data->header, "DB_BITMASK(%s);\n", g_fullOid(data->g, t, id));

    /* Write enumeration constants */
    if (db_serializeConstants(s, v, userData)) {
        goto error;
    }

    return 0;
error:
    return -1;
}

/* Void object */
static db_int16 c_typeVoid(db_serializer s, db_value* v, void* userData) {
	db_type t;
    c_typeWalk_t* data;
    db_id id;

    DB_UNUSED(s);

	t = db_valueType(v)->real;
    data = userData;

	if (t->reference) {
		g_fileWrite(data->header, "typedef db_object %s;\n", g_fullOid(data->g, t, id));
	} else {
		g_fileWrite(data->header, "typedef void %s;\n", g_fullOid(data->g, t, id));
	}

	return 0;
}

/* Primitive object */
static db_int16 c_typePrimitive(db_serializer s, db_value* v, void* userData) {
    db_char buff[16];
    db_type t;
    db_id id;
    c_typeWalk_t* data;

    DB_UNUSED(s);

    data = userData;
    t = db_valueType(v)->real;

    /* Obtain platform type-name for primitive */
    switch(db_primitive(t)->kind) {
    case DB_ENUM:
    	g_fileWrite(data->header, "/* %s */\n", db_fullname(t, id));
        if (c_typePrimitiveEnum(s, v, userData)) {
            goto error;
        }
        break;
    case DB_BITMASK:
    	g_fileWrite(data->header, "/* %s */\n", db_fullname(t, id));
        if (c_typePrimitiveBitmask(s, v, userData)) {
            goto error;
        }
        break;
    case DB_ALIAS:
    	/* Don't generate for alias types */
    	break;
    default:
        if (!c_primitiveId(db_primitive(t), buff)) {
            goto error;
        }

        /* Write typedef */
        if (db_checkAttr(t, DB_ATTR_SCOPED)) {
        	g_fileWrite(data->header, "typedef %s %s;\n", buff, g_fullOid(data->g, t, id));
        }
        break;
    }

    return 0;
error:
    return -1;
}

/* Struct object */
static db_int16 c_typeStruct(db_serializer s, db_value* v, void* userData) {
    c_typeWalk_t* data;
    db_id id;
    db_type t;

    data = userData;
    t = db_valueType(v)->real;

    /* Open struct */
    g_fileWrite(data->header, "struct %s {\n", g_fullOid(data->g, t, id));


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
static db_int16 c_typeAbstract(db_serializer s, db_value* v, void* userData) {
    DB_UNUSED(s);
    DB_UNUSED(v);
    DB_UNUSED(userData);

    return 0;
}

/* Class object */
static db_int16 c_typeClass(db_serializer s, db_value* v, void* userData) {
    c_typeWalk_t* data;
    db_id id;
    db_type t;

    data = userData;
    t = db_valueType(v)->real;

    /* Open class */
    if (t->alignment) {
        g_fileWrite(data->header, "DB_CLASS_DEF(%s) {\n", g_fullOid(data->g, t, id));
        g_fileIndent(data->header);

        /* Write base */
        if (db_interface(t)->base && db_type(db_interface(t)->base)->alignment) {
            g_fileWrite(data->header, "DB_EXTEND(%s);\n", g_fullOid(data->g, db_interface(t)->base, id));
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
static db_int16 c_typeComposite(db_serializer s, db_value* v, void* userData) {
    db_type t;

    t = db_valueType(v)->real;
    switch(db_interface(t)->kind) {
    case DB_STRUCT:
        if (c_typeStruct(s, v, userData)) {
            goto error;
        }
        break;
    case DB_INTERFACE:
    	if (c_typeAbstract(s, v, userData)) {
    		goto error;
    	}
    	break;
    case DB_CLASS:
    	if (c_typeClass(s, v, userData)) {
    		goto error;
    	}
    	break;
    default:
        break;
    }

    return 0;
error:
    return -1;
}

/* Array object */
static db_int16 c_typeArray(db_serializer s, db_value* v, void* userData) {
	db_type t;
	c_typeWalk_t* data;
	db_id id, id3, postfix, postfix2;

	DB_UNUSED(s);
	DB_UNUSED(v);

	data = userData;
	t = db_valueType(v)->real;
	c_specifierId(data->g, db_typedef(t), id, NULL, postfix);
	c_specifierId(data->g, db_typedef(db_collection(t)->elementType), id3, NULL, postfix2);
	g_fileWrite(data->header, "typedef %s %s[%d];\n",
			id3,
			id,
			db_collection(t)->max);

	return 0;
}

/* Sequence object */
static db_int16 c_typeSequence(db_serializer s, db_value* v, void* userData) {
	db_type t;
	c_typeWalk_t* data;
	db_id id, id3, postfix, postfix2;

	DB_UNUSED(s);
	DB_UNUSED(v);

	data = userData;
	t = db_valueType(v)->real;
	c_specifierId(data->g, db_typedef(t), id, NULL, postfix);
	c_specifierId(data->g, db_typedef(db_collection(t)->elementType), id3, NULL, postfix2);
	g_fileWrite(data->header, "DB_SEQUENCE(%s, %s,);\n",
			id,
			id3);

	return 0;
}

/* List object */
static db_int16 c_typeList(db_serializer s, db_value* v, void* userData) {
	db_type t;
	c_typeWalk_t* data;
	db_id id, postfix;

	DB_UNUSED(s);
	DB_UNUSED(v);

	data = userData;
	t = db_valueType(v)->real;
	c_specifierId(data->g, db_typedef(t), id, NULL, postfix);
	g_fileWrite(data->header, "DB_LIST(%s);\n",
			id);

	return 0;
}

/* Collection object */
static db_int16 c_typeCollection(db_serializer s, db_value* v, void* userData) {
	db_type t;

	t = db_valueType(v)->real;
	switch(db_collection(t)->kind) {
	case DB_ARRAY:
		if (c_typeArray(s, v, userData)) {
			goto error;
		}
		break;
	case DB_SEQUENCE:
		if (c_typeSequence(s, v, userData)) {
			goto error;
		}
		break;
	case DB_LIST:
		if (c_typeList(s, v, userData)) {
			goto error;
		}
		break;
	case DB_MAP:
		break;
	}

	return 0;
error:
	return -1;
}

/* Type object */
static db_int16 c_typeObject(db_serializer s, db_value* v, void* userData) {
    c_typeWalk_t* data;
    db_type t;
    db_int16 result;

    data = userData;
    t = db_type(db_valueType(v));

    /* Reset prefixComma */
    data->prefixComma = FALSE;

    /* Forward to specific type-functions */
    switch(t->kind) {
    case DB_VOID:
    	result = c_typeVoid(s, v, userData);
    	break;
    case DB_PRIMITIVE:
        result = c_typePrimitive(s, v, userData);
        break;
    case DB_COMPOSITE:
        result = c_typeComposite(s, v, userData);
        break;
    case DB_COLLECTION:
    	result = c_typeCollection(s, v, userData);
        break;
    default:
        db_error("c_typeObject: typeKind '%s' not handled by code-generator.", db_nameof(db_enum_constant(db_typeKind_o, t->kind)));
        goto error;
        break;
    }

    return result;
error:
    return -1;
}

/* Metawalk-serializer for types */
struct db_serializer_s c_typeSerializer(void) {
    struct db_serializer_s s;

    /* Initialize serializer */
    db_serializerInit(&s);
    s.metaprogram[DB_OBJECT] = c_typeObject;
    s.metaprogram[DB_BASE] = c_typeMember;
    s.metaprogram[DB_MEMBER] = c_typeMember;
    s.metaprogram[DB_CONSTANT] = c_typeConstant;
    s.access = DB_GLOBAL;
    s.accessKind = DB_XOR;
    s.traceKind = DB_SERIALIZER_TRACE_ON_FAIL;

    return s;
}

/* Print class-cast macro's */
static int c_typeClassCastWalk(db_object o, void* userData) {
    c_typeWalk_t* data;
    db_id id;

    data = userData;

    if (db_class_instanceof(db_class_o, o)) {
        g_fileWrite(data->header, "#define %s(o) ((%s)o)\n",
                g_fullOid(data->g, o, id),
                g_fullOid(data->g, o, id));
    }

    return 1;
}

/* Open headerfile, write standard header. */
static g_file c_typeHeaderFileOpen(db_generator g) {
	g_file result;
	db_id headerFileName;
	db_id path;
	db_iter importIter;
	db_object import;
	db_string headerSnippet;

	/* Create file */
	sprintf(headerFileName, "%s__type.h", g_getName(g));
	result = g_fileOpen(g, headerFileName);
	if (!result) {
		goto error;
	}

	/* Print standard comments and includes */
	g_fileWrite(result, "/* %s\n", headerFileName);
	g_fileWrite(result, " *\n");
    g_fileWrite(result, " *    Type-definitions for C-language.\n");
	g_fileWrite(result, " *    This file contains generated code. Do not modify!\n");
	g_fileWrite(result, " */\n\n");
	g_fileWrite(result, "#ifndef %s__type_H\n", g_getName(g));
	g_fileWrite(result, "#define %s__type_H\n\n", g_getName(g));
	g_fileWrite(result, "#include \"hyve.h\"\n");

	/* Include imports */
	if (g->imports) {
		importIter = db_llIter(g->imports);
		while(db_iterHasNext(&importIter)) {
			import = db_iterNext(&importIter);
			c_topath(import, path);
			g_fileWrite(result, "#include \"%s/%s__type.h\"\n", path, db_nameof(import));
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
    g_fileWrite(file, "\n");
	g_fileWrite(file, "#ifdef __cplusplus\n");
	g_fileWrite(file, "}\n");
	g_fileWrite(file, "#endif\n");
	g_fileWrite(file, "#endif\n\n");
}

static int c_typeDeclare(db_object o, void* userData) {
    db_id id;
    db_type t;
    c_typeWalk_t* data;

    data = userData;
    t = o;

    if (db_checkAttr(o, DB_ATTR_SCOPED)) {
        g_fileWrite(data->header, "\n");
        g_fileWrite(data->header, "/*  %s */\n", db_fullname(t, id));

        switch(t->kind) {
        case DB_COMPOSITE:
            switch(db_interface(t)->kind) {
            case DB_STRUCT:
                g_fileWrite(data->header, "typedef struct %s %s;\n", g_fullOid(data->g, t, id), g_fullOid(data->g, t, id));
                break;
            case DB_CLASS:
                g_fileWrite(data->header, "DB_CLASS(%s);\n", g_fullOid(data->g, t, id));
                break;
            case DB_INTERFACE:
                g_fileWrite(data->header, "DB_INTERFACE(%s);\n", g_fullOid(data->g, t, id));
                break;
            case DB_PROCEDURE:
                break;
            }
            break;
        default:
            db_error("c_typeDeclare: only composite types can be forward declared.");
            goto error;
            break;
        }
    }

    return 0;
error:
    return -1;
}

static int c_typeDefine(db_object o, void* userData) {
    struct db_serializer_s s;
    int result;

    result = 0;

    /* Serialize typedef */
    if (db_typedef(o)->real != o) {
        c_typeWalk_t* data;
        db_typedef t;

        data = userData;
        t = o;

        /* Serialize a typedef */
        db_id spec, postfix, id2;

        c_specifierId(data->g, t->type, spec, NULL, postfix);

        /* Serialize typedef */
        g_fileWrite(data->header, "typedef %s %s%s;\n", spec, g_fullOid(data->g, t, id2), postfix);

    /* Serialize type */
    } else {

        /* Get type-serializer */
        s = c_typeSerializer();

        /* Do metawalk on type */
        result = db_metaWalk(&s, db_type(o), userData);
    }


    return result;
}

/* Generator main */
db_int16 hyve_genMain(db_generator g) {
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

	/* Default prefixes for hyve namespaces */
	gen_parse(g, hyve_o, FALSE, FALSE, "");
	gen_parse(g, hyve_lang_o, FALSE, FALSE, "db");

	/* Walk classes, print cast-macro's */
	g_fileWrite(walkData.header, "\n");
	g_fileWrite(walkData.header, "/* Casting macro's for classes */\n");
	if (!g_walkRecursive(g, c_typeClassCastWalk, &walkData)) {
	    goto error;
	}

	g_fileWrite(walkData.header, "\n");
	g_fileWrite(walkData.header, "/* Type definitions */\n\n");

	/* Walk objects */
	if (db_genTypeDepWalk(g, c_typeDeclare, c_typeDefine, &walkData)) {
	    goto error;
	}

	/* Close headerfile */
	c_typeHeaderFileClose(walkData.header);

	return 0;
error:
    return -1;
}
