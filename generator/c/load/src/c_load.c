/*
 * c_load.c
 *
 *  Created on: Sep 20, 2012
 *      Author: sander
 */

#include "hyve.h"
#include "db_generatorDepWalk.h"
#include "c_common.h"
#include "db_string_ser.h"

typedef struct c_typeWalk_t {
    db_generator g;
    g_file header;
    g_file source;
    db_uint32 firstComma;
} c_typeWalk_t;

/* Resolve object */
static db_char* c_loadResolve(db_object o, db_char* out, db_char* src, db_char* context) {
	if (db_checkAttr(o, DB_ATTR_SCOPED)) {
		db_id id, escaped, escapedContextStr;
		db_fullname(o, id);

		if (!(src || context)) {
		    sprintf(out, "db_resolve(NULL, \"%s\")", c_escapeString(id, escaped));
		} else {
		    if (!src) {
		        src = "NULL";
		    }
		    if (!context) {
		        context = "NULL";
		    }
		    sprintf(out, "db_resolve_ext(%s, NULL, \"%s\", FALSE, \"%s\")", src, c_escapeString(id, escaped), c_escapeString(context, escapedContextStr));
		}
	} else {
		db_id ostr, id, escapedId, escapedOstr, escapedContextStr;
		struct db_serializer_s stringSer;
		db_string_ser_t data;

		/* Serialize object string */
		stringSer = db_string_ser(DB_LOCAL, DB_NOT, DB_SERIALIZER_TRACE_ON_FAIL);

		*ostr = '\0';
		data.compactNotation = TRUE;
		data.buffer = id;
		data.length = sizeof(ostr);
		data.maxlength = 0;
		data.prefixType = FALSE;
		if (db_serialize(&stringSer, o, &data)) {
			goto error;
		}
		c_escapeString(id, escapedOstr);

		db_fullname(db_typeof(o), id);
		c_escapeString(id, escapedId);

        if (!(src || context)) {
            sprintf(out, "db_resolve(NULL, \"%s%s\")", escapedId, escapedOstr);
        } else {
            if (!src) {
                src = "NULL";
            }
            if (!context) {
                context = "NULL";
            }
            c_escapeString(context, escapedContextStr);
            sprintf(out, "db_resolve_ext(%s, NULL, \"%s%s\", FALSE, \"%s\")", src, escapedId, escapedOstr, escapedContextStr);
        }
	}

	return out;
error:
	return NULL;
}

/* Get variable id */
static db_char* c_loadVarId(db_generator g, db_object o, db_char* out) {
	if (db_checkAttr(o, DB_ATTR_SCOPED)) {
		if (o != root_o) {
			g_fullOid(g, o, out);
			strcat(out, "_o");
		} else {
			strcpy(out, "root_o");
		}
	} else {
		db_id id;
		sprintf(out, "%s", c_loadResolve(o, id, NULL, NULL));
	}
    return out;
}

/* Get element id, for lists and maps. */
static db_char* c_loadElementId(db_value* v, db_char* out, db_int32 offset) {
	db_uint32 i;
	db_value* ptr;

	i = 0;
	ptr = v;

	do {
		if (ptr->kind == DB_ELEMENT) {
			i++;
		}
	}while((ptr = ptr->parent));

	sprintf(out, "_e%d_", i + offset);

	return out;
}

/* This function translates from a value-object to a valid C-string identifying a
 * part of the object that is being serialized. */
static db_char* c_loadMemberId(c_typeWalk_t* data, db_value* v, db_char* out, db_bool addMemberOperator) {
    db_value* stack[DB_MAX_TYPE_DEPTH];
    db_uint32 count;
    db_value *ptr;
    db_object o;
    db_typedef thisType;
    db_bool objectIsArray, derefMemberOperator;

    *out = '\0';

    /* Build serializer-stack */
    ptr = v;
    count = 0;
    while((ptr->kind != DB_OBJECT) && (ptr->kind != DB_BASE)) {
        stack[count] = ptr;
        ptr = ptr->parent;
        count++;
    }
    stack[count] = ptr;

    /* Print object */
    o = db_valueObject(v);

    /* If object is an array, dereference object, so the '[ ]' operator can be used on object. Same for primtives, primitive-objects are pointers to primitive values. */
    objectIsArray = (db_typeof(o)->real->kind == DB_PRIMITIVE) || ((db_typeof(o)->real->kind == DB_COLLECTION) && (db_collection(db_typeof(o)->real)->kind == DB_ARRAY));

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
    thisType = db_valueType(ptr);
    if (db_typedef(thisType) != db_typeof(o)) {
    	db_id id, parentId, objectId;
    	sprintf(id, "%s(%s)",
    			g_fullOid(data->g, thisType, parentId),
                c_loadVarId(data->g, db_valueObject(v), objectId));
    	strcat(out, id);
    } else {
    	db_id objectId;
    	strcat(out, c_loadVarId(data->g, db_valueObject(v), objectId));
    }

    /* End bracket used for dereferencing object */
    if (objectIsArray) {
    	strcat(out, ")");
    }

    /* Walk serializer stack */
    while(count) {
        count--;

        switch(stack[count]->kind) {

        /* Member */
        case DB_MEMBER:
        	/* When previous object is a reference, use -> operator. */
        	if (derefMemberOperator) {
        		strcat(out, "->");
        		derefMemberOperator = FALSE;
        	} else {
        		strcat(out, ".");
        	}

        	/* Reference member using it's name. */
            strcat(out, db_nameof(stack[count]->is.member.t));
            break;

        /* Element */
        case DB_ELEMENT: {
            db_collection t;
            db_char arrayIndex[24];

            t = db_collection(db_valueType(stack[count+1])->real);

            switch(t->kind) {

            /* Array element, use array operator. */
            case DB_ARRAY:
                sprintf(arrayIndex, "[%d]", stack[count]->is.element.t.index);
                strcat(out, arrayIndex);
                break;

            /* Sequence element, use buffer-array */
            case DB_SEQUENCE:
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
            	db_char elementId[9]; /* One-million nested collections should be adequate in most cases. */

            	if ((db_valueType(stack[count])->real->kind == DB_COLLECTION) && (db_collection(db_valueType(stack[count])->real)->kind == DB_ARRAY)) {
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

        /* DB_OBJECT and DB_CONSTANT will not be encountered in this loop. */
        default:
        	db_assert(0, "invalid valueKind at this place.");
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
static int c_loadDeclareWalk(db_object o, void* userData) {
    c_typeWalk_t* data;
    db_id specifier, postfix, objectId;
    db_typedef t;
    db_bool prefix;
    db_object parent;

    data = userData;
    t = db_typeof(o);

    parent = db_parentof(o);
    if (parent && (parent != root_o) && (!g_mustParse(data->g, parent))) {
        c_loadDeclareWalk(db_parentof(o), userData);
    }

    /* Get C typespecifier */
    if (c_specifierId(data->g, t, specifier, &prefix, postfix)) {
    	goto error;
    }

    /* Declare objects in headerfile and define in sourcefile */
    g_fileWrite(data->header, "\n");
    g_fileWrite(data->header, "/* %s */\n", db_fullname(o, objectId));
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
static g_file c_loadHeaderFileOpen(db_generator g) {
    g_file result;
    db_id headerFileName;

    /* Create file */
    sprintf(headerFileName, "%s__meta.h", g_getName(g));
    result = g_fileOpen(g, headerFileName);

    /* Print standard comments and includes */
    g_fileWrite(result, "/* %s\n", headerFileName);
    g_fileWrite(result, " *\n");
    g_fileWrite(result, " * Loads objects in database.\n");
    g_fileWrite(result, " * This file contains generated code. Do not modify!\n");
    g_fileWrite(result, " */\n\n");
    g_fileWrite(result, "#ifndef %s_META_H\n", g_getName(g));
    g_fileWrite(result, "#define %s_META_H\n\n", g_getName(g));
    g_fileWrite(result, "#include \"hyve.h\"\n\n");
    g_fileWrite(result, "#include \"%s__type.h\"\n\n", g_getName(g));
    g_fileWrite(result, "#ifdef __cplusplus\n");
    g_fileWrite(result, "extern \"C\" {\n");
    g_fileWrite(result, "#endif\n");

    return result;
}

/* Close headerfile */
static void c_loadHeaderFileClose(db_generator g, g_file file) {

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
static g_file c_loadSourceFileOpen(db_generator g) {
    g_file result;
    db_id headerFileName;

    /* Create file */
    sprintf(headerFileName, "%s__meta.c", g_getName(g));
    result = g_fileOpen(g, headerFileName);

    /* Print standard comments and includes */
    g_fileWrite(result, "/* %s\n", headerFileName);
    g_fileWrite(result, " *\n");
    g_fileWrite(result, " * Loads objects in database.\n");
    g_fileWrite(result, " * This file contains generated code. Do not modify!\n");
    g_fileWrite(result, " */\n\n");
    g_fileWrite(result, "#include \"%s__type.h\"\n\n", g_getName(g));

    return result;
}

/* Write starting comment of variable definitions */
static void c_sourceWriteVarDefStart(g_file file) {
    g_fileWrite(file, "/* Variable definitions */\n");
}

/* Write start of load-routine */
static void c_sourceWriteLoadStart(db_generator g, g_file file) {
    g_fileWrite(file, "\n");
    g_fileWrite(file, "/* Load objects in database */\n");
    g_fileWrite(file, "int %s_load(void) {\n", g_getName(g));
    g_fileIndent(file);
    g_fileWrite(file, "db_object _a_; /* Used for resolving anonymous objects */\n");
    g_fileWrite(file, "_a_ = NULL;\n\n");
}

/* Write end of load-routine */
static void c_sourceWriteLoadEnd(g_file file) {
	g_fileWrite(file, "if (_a_) {\n");
	g_fileIndent(file);
	g_fileWrite(file, "db_free(_a_);\n");
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

/* Declare object */
static int c_loadDeclare(db_object o, void* userData) {
    c_typeWalk_t* data;
    db_id id, parentId, typeId, escapedName;

    data = userData;

    /* Only declare scoped objects */
    if (db_checkAttr(o, DB_ATTR_SCOPED)) {
    	c_escapeString(db_nameof(o), escapedName);

        /* Declaration */
        g_fileWrite(data->source, "/* Declare %s */\n", db_fullname(o, id));

        if (!db_checkAttr(db_typeof(o), DB_ATTR_SCOPED)) {
			g_fileWrite(data->source, "%s = db_declare(%s, \"%s\", (_a_ ? db_free(_a_) : 0, _a_ = db_typedef(%s)));\n",
					c_loadVarId(data->g, o, id),
					c_loadVarId(data->g, db_parentof(o), parentId),
					escapedName,
					c_loadVarId(data->g, db_typeof(o), typeId));
        } else {
			g_fileWrite(data->source, "%s = db_declare(%s, \"%s\", db_typedef(%s));\n",
					c_loadVarId(data->g, o, id),
					c_loadVarId(data->g, db_parentof(o), parentId),
					escapedName,
					c_loadVarId(data->g, db_typeof(o), typeId));
        }

        /* Error checking */
        g_fileWrite(data->source, "if (!%s) {\n", c_loadVarId(data->g, o, id));
        g_fileIndent(data->source);
        c_escapeString(db_fullname(o, id), escapedName);
        g_fileWrite(data->source, "db_error(\"%s_load: failed to declare object '%s'.\");\n",
                g_getName(data->g),
                escapedName);
        g_fileWrite(data->source, "goto error;\n");
        g_fileDedent(data->source);
        g_fileWrite(data->source, "}\n\n");
    }

    return 1;
}

/* Print variable start */
static void c_varPrintStart(db_value* v, c_typeWalk_t* data) {
    db_id memberId;
    db_type t;

    t = db_valueType(v)->real;

    /* Only write an identifier if the object is a primitive type, or a reference. */
    if ((t->kind == DB_PRIMITIVE) || (t->reference && !(v->kind == DB_OBJECT))) {
        /* Print memberId if object is member */
		g_fileWrite(data->source, "%s = ",
				c_loadMemberId(data, v, memberId, FALSE));
    }
}

/* Print variable end */
static void c_varPrintEnd(db_value* v, c_typeWalk_t* data) {
    db_type t;

    /* Get member object */
    t = db_valueType(v)->real;
    if ((t->kind == DB_PRIMITIVE) || (t->reference && !(v->kind == DB_OBJECT))) {
        /* Print end of member-assignment */
        g_fileWrite(data->source, ";\n");
    }
}

/* c_initPrimitive */
static db_int16 c_initPrimitive(db_serializer s, db_value* v, void* userData) {
    void* ptr;
    db_type t;
    db_string str;
    c_typeWalk_t* data;
    DB_UNUSED(s);

    ptr = db_valueValue(v);
    t = db_valueType(v)->real;
    data = userData;
    str = NULL;

    c_varPrintStart(v, userData);

    /* Treat booleans separately, the default convert translates booleans to 'true' and 'false' while
     * the language mapping of C TRUE and FALSE is. */
    if (db_primitive(t)->kind == DB_BOOLEAN) {
    	if (*(db_bool*)ptr) {
    		str = db_strdup("TRUE");
    	} else {
    		str = db_strdup("FALSE");
    	}
    } else if (db_primitive(t)->kind == DB_ENUM) {
        db_id enumId;

        /* Convert constant-name to language id */
        str = db_strdup(c_constantId(data->g, db_enum_constant(db_enum(t), *(db_uint32*)ptr), enumId));
    } else if (db_primitive(t)->kind == DB_BITMASK) {
        str = db_malloc(11);
        sprintf(str, "0x%x", *(db_uint32*)ptr);
    } else if (db_primitive(t)->kind == DB_TEXT) {
        db_string v = *(db_string*)ptr;
        if (v) {
            str = malloc(strlen("db_strdup()") + strlen(v) + 1 + 2);
            sprintf(str, "db_strdup(\"%s\")", v);
        } else {
            str = db_strdup("NULL");
        }
    } else {
        /* Convert primitive value to string using built-in conversion */
        if (db_convert(db_primitive(t), ptr, db_primitive(db_string_o), &str)) {
            goto error;
        }
    }

    g_fileWrite(data->source, "%s", str);
    db_dealloc(str);

    c_varPrintEnd(v, userData);

    return 0;
error:
    return -1;
}

/* c_initReference */
static db_int16 c_initReference(db_serializer s, db_value* v, void* userData) {
    db_object *optr, o;
    c_typeWalk_t* data;
    DB_UNUSED(s);

    data = userData;
    optr = db_valueValue(v);

    c_varPrintStart(v, userData);

    if ((o = *optr)) {
        db_id id, src, context;
        c_loadVarId(data->g, db_valueObject(v), src);
        db_valueString(v, context, 256);
        g_fileWrite(data->source, "%s", c_loadResolve(o, id, src, context));
    } else {
        g_fileWrite(data->source, "NULL");
    }

    c_varPrintEnd(v, userData);

    return 0;
}

/* c_initElement */
static db_int16 c_initElement(db_serializer s, db_value* v, void* userData) {
	db_collection t;
	c_typeWalk_t* data;

	/* Get collectionType */
	t = db_collection(db_valueType(v->parent)->real);
	data = userData;

	/* Allocate space for element */
	switch(t->kind) {
	case DB_LIST:
	case DB_MAP: {
		db_id elementId, specifier, postfix;
		g_fileWrite(data->source, "\n");

		c_specifierId(data->g, t->elementType, specifier, NULL, postfix);
		g_fileWrite(data->source, "%s = db_malloc(sizeof(%s%s));\n", c_loadElementId(v, elementId, 0), specifier, postfix);
		break;
	}
	default:
		break;
	}

	/* Serialize value */
	if (db_serializeValue(s, v, data)) {
		goto error;
	}

	switch(t->kind) {
	case DB_LIST: {
		db_id parentId, elementId;
		g_fileWrite(data->source, "db_llAppend(%s, %s);\n",
				c_loadMemberId(data, v->parent, parentId, FALSE),
				c_loadElementId(v, elementId, 0));
		break;
	}
	case DB_MAP: /*{
		db_id parentId, elementId;
		g_fileWrite(data->source, "db_rbtreeSet(%s, %s)",
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
static db_int16 c_initCollection(db_serializer s, db_value* v, void* userData) {
    db_collection t;
    c_typeWalk_t* data;
    db_id memberId;
    int result;
    void* ptr;

    ptr = db_valueValue(v);

    t = db_collection(db_valueType(v)->real);
    data = userData;

    switch(t->kind) {
    case DB_ARRAY:
        break;
    case DB_SEQUENCE: {
        db_uint32 length;
    	db_id specifier, postfix;

        length = *(db_uint32*)ptr;

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
            g_fileWrite(data->source, "%sbuffer = db_malloc(sizeof(%s%s));\n",
                    c_loadMemberId(data, v, memberId, TRUE),
                    specifier, postfix);
        } else {
            g_fileWrite(data->source, "%sbuffer = db_malloc(sizeof(%s%s) * %d);\n",
                    c_loadMemberId(data, v, memberId, TRUE),
                    specifier, postfix,
                    length);
        }
        break;
    }
    case DB_LIST:
        /* Create list object */
    	if (*(db_ll*)ptr) {
			g_fileWrite(data->source, "%s = db_llNew();\n",
					c_loadMemberId(data, v, memberId, FALSE));
    	} else {
    		g_fileWrite(data->source, "%s = NULL;\n", c_loadMemberId(data, v, memberId, FALSE));
    	}
        break;
    case DB_MAP: {
    	db_id keyId;
        /* Create map object */
    	if (*(db_rbtree*)ptr) {
			g_fileWrite(data->source, "%s = db_rbtreeNew(%s);\n",
					c_loadMemberId(data, v, memberId, FALSE), g_fullOid(data->g, db_rbtreeKeyType(*(db_rbtree*)ptr), keyId));
    	} else {
    		g_fileWrite(data->source, "%s = NULL;\n", c_loadMemberId(data, v, memberId, FALSE));
    	}
        break;
    }
    }

	/* For the non-array types, allocate a member variable, if size of collection is not zero. */
    if (db_size(t, ptr)) {
		switch(t->kind) {
		case DB_LIST:
		case DB_MAP: {
			db_id elementId, elementTypeId;
			g_fileWrite(data->source, "{\n");
			g_fileIndent(data->source);
			g_fileWrite(data->source, "%s* %s;\n", g_fullOid(data->g, t->elementType, elementTypeId), c_loadElementId(v, elementId, 1));
			break;
		}
		default:
			break;
		}
    }

    /* Serialize elements */
    result = db_serializeElements(s, v, userData);

    if (db_size(t, ptr)) {
		switch(t->kind) {
		case DB_LIST:
		case DB_MAP: {
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
static int c_loadCFunction(db_function o, c_typeWalk_t* data, db_id name) {

    /* Print name */
    g_fullOid(data->g, o, name);
    if (c_procedureHasThis(o)) {
        if (db_instanceof(db_typedef(db_method_o), o) && db_method(o)->virtual) {
            strcat(name, "_v");
        }
    }

    return 0;
}

/* c_initObject */
static db_int16 c_initObject(db_serializer s, db_value* v, void* userData) {
    c_typeWalk_t* data;
    db_id id, escapedId;
    db_object o;

    data = userData;
    o = db_valueObject(v);

    g_fileWrite(data->source, "/* Define %s */\n", db_fullname(o, id));
    g_fileWrite(data->source, "if (!db_checkState(%s, DB_DEFINED)) {\n", c_loadVarId(data->g, o, id));
    g_fileIndent(data->source);

    /* Serialize object value */
    db_serializeValue(s, v, userData);

    /* If object is a procedure, set function implementation */
    if (db_class_instanceof(db_procedure_o, db_typeof(o))) {
        db_id name;
        g_fileWrite(data->source, "\n");
        if (!db_function(o)->impl) {
            g_fileWrite(data->source, "/* Bind %s with C-function */\n", id);
            g_fileWrite(data->source, "db_function(%s)->kind = DB_PROCEDURE_CDECL;\n", c_loadVarId(data->g, o, id));
            c_loadCFunction(o, data, name);
            g_fileWrite(data->source, "void __%s(void *args, void *result);\n", name);
            g_fileWrite(data->source, "db_function(%s)->impl = (db_word)__%s;\n", id, name);
        }
    }

    /* Define object */
    g_fileWrite(data->source, "if (db_define(%s)) {\n", c_loadVarId(data->g, o, id));
    g_fileIndent(data->source);
    g_fileWrite(data->source, "db_error(\"%s_load: failed to define object '%s'.\");\n",
            g_getName(data->g),
            c_escapeString(db_fullname(o, id), escapedId));
    g_fileWrite(data->source, "goto error;\n");
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n");
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n");

    return 0;
}

/* Create serializer that initializes object values */
static struct db_serializer_s c_initSerializer(void) {
    struct db_serializer_s s;

    db_serializerInit(&s);

    s.access = DB_LOCAL;
    s.accessKind = DB_NOT;
    s.traceKind = DB_SERIALIZER_TRACE_ON_FAIL;
    s.program[DB_PRIMITIVE] = c_initPrimitive;
    s.program[DB_COLLECTION] = c_initCollection;
    s.metaprogram[DB_OBJECT] = c_initObject;
    s.metaprogram[DB_ELEMENT] = c_initElement;
    s.reference = c_initReference;

    return s;
}

/* Define object */
static int c_loadDefine(db_object o, void* userData) {
    struct db_serializer_s s;

    if (db_checkAttr(o, DB_ATTR_SCOPED)) {
        /* Obtain serializer to initialize object values */
        s = c_initSerializer();

        /* Serialize object */
        db_serialize(&s, o, userData);
    }

    return 1;
}

/* Entry point for generator */
int hyve_genMain(db_generator g) {
    c_typeWalk_t walkData;

	/* Default prefixes for hyve namespaces */
	gen_parse(g, hyve_o, FALSE, FALSE, "");
    gen_parse(g, hyve_lang_o, FALSE, FALSE, "db");

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
    if (db_genDepWalk(g, c_loadDeclare, c_loadDefine, &walkData)) {
        db_trace("generation of load-routine failed while resolving dependencies.");
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
