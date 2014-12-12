/*
 * cpp_load.c
 *
 *  Created on: Sep 20, 2012
 *      Author: sander
 */

#include "hyve.h"
#include "db_generatorDepWalk.h"
#include "cpp_common.h"
#include "db_string_ser.h"

typedef struct cpp_typeWalk_t {
    db_generator g;
    g_file header;
    g_file source;
    db_uint32 firstComma;
} cpp_typeWalk_t;

/* Resolve object */
static db_char* cpp_loadResolve(db_object o, db_char* out) {
	if (db_checkAttr(o, DB_ATTR_SCOPED)) {
		db_id id;
		sprintf(out, "::hyve::resolve(NULL, \"%s\")", db_fullname(o, id));
	} else {
		db_id ostr, id;
		struct db_serializer_s stringSer;
		db_string_ser_t data;

		/* Serialize object string */
		stringSer = db_string_ser(DB_LOCAL, DB_NOT, DB_SERIALIZER_TRACE_ON_FAIL);

		*ostr = '\0';
		data.compactNotation = TRUE;
		data.buffer = ostr;
		data.length = sizeof(ostr);
		data.maxlength = 0;
		data.prefixType = FALSE;
		if (db_serialize(&stringSer, o, &data)) {
			goto error;
		}

		sprintf(out, "::hyve::resolve(NULL, \"%s%s\")", db_fullname(db_typeof(o), id), ostr);
	}

	return out;
error:
	return NULL;
}

/* Get variable id */
static db_char* cpp_loadVarId(db_generator g, db_object o, db_char* out) {
	if (db_checkAttr(o, DB_ATTR_SCOPED)) {
		cpp_metaFullname(g, o, CPP_HANDLE, out);
	} else {
		db_id id;
		sprintf(out, "%s", cpp_loadResolve(o, id));
	}
    return out;
}

/* Get marshaller id (wrapper for member-functions) */
static db_char* cpp_loadMarshallId(db_generator g, db_function o, db_id id) {
	db_char *ptr;

	ptr = id;
	strcpy(ptr, "__cpp_");
	ptr += 6;

	cpp_metaName(g, o, CPP_DEFAULT, ptr);

	return id;
}

/* Get element id, for lists and maps. */
static db_char* cpp_loadElementId(db_value* v, db_char* out, db_int32 offset) {
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
static db_char* cpp_loadMemberId(cpp_typeWalk_t* data, db_value* v, db_char* out, db_bool addMemberOperator) {
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
    	sprintf(id, "((%s)%s)",
    			g_fullOid(data->g, thisType, parentId),
                cpp_loadVarId(data->g, db_valueObject(v), objectId));
    	strcat(out, id);
    } else {
    	db_id objectId;
    	strcat(out, cpp_loadVarId(data->g, db_valueObject(v), objectId));
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
        case DB_MEMBER: {
        	db_id id;
        	/* When previous object is a reference, use -> operator. */
        	if (derefMemberOperator) {
        		strcat(out, "->");
        		derefMemberOperator = FALSE;
        	} else {
        		strcat(out, ".");
        	}

        	/* Reference member using it's name. */
            strcat(out, g_id(data->g, db_nameof(stack[count]->is.member.t), id));
            break;
        }

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
            		sprintf(out, "(*%s)", cpp_loadElementId(stack[count], elementId, 0));
            	} else {
            		sprintf(out, "%s", cpp_loadElementId(stack[count], elementId, 0));
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
static int cpp_loadDeclareWalk(db_object o, void* userData) {
    cpp_typeWalk_t* data;
    db_id specifier, objectId;
    db_typedef t;
    db_bool isClass;

    data = userData;
    t = db_typeof(o);

    if (!(db_typeof(db_parentof(o))->real->kind == DB_VOID)) {
    	cpp_openScope(data->header, db_parentof(db_parentof(o)));
    	cpp_openScope(data->source, db_parentof(db_parentof(o)));
    } else {
    	cpp_openScope(data->header, db_parentof(o));
    	cpp_openScope(data->source, db_parentof(o));
    }

    if (db_class_instanceof(db_interface_o, o) && db_type(o)->reference) {
    	isClass = TRUE;
    } else {
    	isClass = FALSE;
    }

    /* Get C++ typespecifier */
    if (!cpp_specifierId(data->g, t, specifier)) {
    	goto error;
    }

    /* Declare objects in headerfile and define in sourcefile */
    g_fileWrite(data->header, "\n");
    g_fileWrite(data->header, "/* %s */\n", db_fullname(o, objectId));

    if (!t->real->reference) {
        /* Looks counter-intuitive to put '*' in front of non-reftypes. However, it makes sense, since there apparently is an
         * object of a non-reftype (in other words, there is a ref to an object of a non-reftype) and since the type itself
         * is not a reftype, a '*' is required to make it a reference. */
        g_fileWrite(data->header, "extern %s *%s;\n", specifier, cpp_metaName(data->g, o, CPP_HANDLE, objectId));
        g_fileWrite(data->source, "%s *%s;\n", specifier, objectId);
		if (isClass) { /* Maybe someday extendables might become non-ref types, this code makes sure that this is covered. */
			g_setIdKind(data->g, DB_GENERATOR_ID_CLASS_UPPER);
		    /* Get upper-case typespecifier */
		    if (!cpp_specifierId(data->g, t, specifier)) {
		    	goto error;
		    }
			g_fileWrite(data->header, "extern %s %s;\n", specifier, cpp_metaName(data->g, o, CPP_OBJECT, objectId));
			g_fileWrite(data->source, "%s %s;\n", specifier, cpp_metaName(data->g, o, CPP_OBJECT, objectId));
			g_setIdKind(data->g, DB_GENERATOR_ID_CLASS_LOWER);
		}
    } else {
        /* Here, the type is already a reftype, therefore it's not required to put an '*' in front of the variable name */
        g_fileWrite(data->header, "extern %s %s;\n", specifier, cpp_metaName(data->g, o, CPP_HANDLE, objectId));
        g_fileWrite(data->source, "%s %s;\n", specifier, objectId);
		if (isClass) {
			g_setIdKind(data->g, DB_GENERATOR_ID_CLASS_UPPER);
		    /* Get upper-case typespecifier */
		    if (!cpp_specifierId(data->g, t, specifier)) {
		    	goto error;
		    }
			g_fileWrite(data->header, "extern %s (*%s);\n", specifier, cpp_metaName(data->g, o, CPP_OBJECT, objectId));
			g_fileWrite(data->source, "%s (*%s);\n", specifier, cpp_metaName(data->g, o, CPP_OBJECT, objectId));
			g_setIdKind(data->g, DB_GENERATOR_ID_CLASS_LOWER);
		}
    }

	return 1;
error:
	return 0;
}

/* Enumeration that indicates what kind of a proxy must be generated. */
typedef enum cpp_proxyKind {
	NO_PROXY, /* No proxy must be generated. */
	FUNCTION_PROXY, /* proxy without this, just arguments */
	STATIC_PROXY, /* Same as function proxy, but in the scope of a class */
	CLASS_PROXY, /* proxy with a this-pointer pointing to a class-instantiation */
	DELEGATE_PROXY /* proxy with a this-pointer pointing to the class-instantiation containing a callback's delegate */
}cpp_proxyKind;

/* Generate stubs for method */
static int cpp_loadMethodProxy(db_object o, void* userData) {
    if (db_class_instanceof(db_procedure_o, db_typeof(o)) && (db_procedure(db_typeof(o))->kind != DB_METAPROCEDURE)) {
		db_id specifier, id;
		cpp_typeWalk_t* data;
		db_uint32 i, paramCount;
		db_parameter* p;
		db_procedureKind kind;
		cpp_proxyKind proxyKind;
		db_object thisType;

		kind = db_procedure(db_typeof(o)->real)->kind;
		thisType = NULL;

		if ((kind == DB_METHOD) || (kind == DB_DELEGATE) || ((kind == DB_OBSERVER) && (db_class_instanceof(db_class_o, db_parentof(o))))) {
			proxyKind = CLASS_PROXY;
			thisType = db_parentof(o); /* Type of this is parent of procedure */
		} else if (kind == DB_CALLBACK) {
			if (db_checkState(o, DB_DEFINED)) {
				proxyKind = NO_PROXY;
			} else {
				proxyKind = DELEGATE_PROXY;
			}
		} else {
			if (db_class_instanceof(db_interface_o, db_parentof(o)) && db_type(db_parentof(o))->reference) {
				proxyKind = STATIC_PROXY;
			} else {
				proxyKind = FUNCTION_PROXY;
			}
		}

		if (proxyKind != NO_PROXY) {

			data = userData;
			paramCount = 0;

			/* Open correct scope (if parent is abstract, open scope of abstract) */
			if (!db_class_instanceof(db_interface_o, db_parentof(o)) && db_type(db_parentof(o))->reference) {
				cpp_openScope(data->source, db_parentof(o));
			} else {
				cpp_openScope(data->source, db_parentof(db_parentof(o)));
			}

			/* Obtain type-specifier for return-type, write function identifier */
			if (!cpp_specifierId(data->g, db_function(o)->returnType, specifier)) {
				goto error;
			}
			g_fileWrite(data->source, "%s %s(", specifier, cpp_loadMarshallId(data->g, o, id));

			/* Print '_this' */
			if (thisType) {
				g_fileWrite(data->source, "%s _this", g_fullOid(data->g, thisType, id));
				paramCount = 1;
			}

			/* Print arguments */
			for(i=0; i<db_function(o)->parameters.length; i++) {
				p = &db_function(o)->parameters.buffer[i];
				cpp_specifierId(data->g, p->type, specifier);
				if (paramCount) {
					g_fileWrite(data->source, ", ");
				}
				g_fileWrite(data->source, "%s %s", specifier, g_id(data->g, p->name, id));
				paramCount++;
			}

			/* Print implementation */
			g_fileWrite(data->source, ") {\n");
			g_fileIndent(data->source);
			g_setIdKind(data->g, DB_GENERATOR_ID_CLASS_UPPER);

			/* If procedure has this, create C++ proxy-object (this is always an abstract object) */
			if (thisType) {
				g_fileWrite(data->source, "%s proxy(_this,FALSE);\n", g_fullOid(data->g, thisType, id), id);
			}

			/* If there are parameters of abstract types, create C++ proxy-objects */
			for(i=0; i<db_function(o)->parameters.length; i++) {
				p = &db_function(o)->parameters.buffer[i];
				if ((db_class_instanceof(db_interface_o, p->type) && (p->type->real->reference)) || (p->type == db_typedef(db_object_o))) {
					db_id id2;
					g_fileWrite(data->source, "%s _%s(%s,FALSE);\n",
								g_fullOid(data->g, p->type, id),
								g_id(data->g, p->name, id2),
								g_id(data->g, p->name, id2));
				}
			}
			g_setIdKind(data->g, DB_GENERATOR_ID_CLASS_LOWER);

			/* If procedure has returnType, return */
			if (db_function(o)->returnType && ((db_function(o)->returnType->real->kind != DB_VOID) || db_function(o)->returnType->real->reference)) {
				g_fileWrite(data->source, "return ");
			}

			/* Call actual function - if CLASS_PROXY, invoke method on C++ class proxy */
			if (proxyKind == CLASS_PROXY) {
				g_fileWrite(data->source, "proxy.");

			/* If function is static class-member, prefix class-scope */
			} else if ((proxyKind == STATIC_PROXY) || (proxyKind == DELEGATE_PROXY)) {
				g_setIdKind(data->g, DB_GENERATOR_ID_CLASS_UPPER);
				g_fileWrite(data->source, "%s::", g_fullOid(data->g, db_parentof(o), id));
				g_setIdKind(data->g, DB_GENERATOR_ID_CLASS_LOWER);
			}

			paramCount = 0;
			if ((kind == DB_METHOD) && (db_method(o)->virtual)) {
				g_fileWrite(data->source, "%s_v(", cpp_procId(data->g, o, id));
			} else {
				g_fileWrite(data->source, "%s(", cpp_procId(data->g, o, id));
			}

			for(i=0; i<db_function(o)->parameters.length; i++) {
				p = &db_function(o)->parameters.buffer[i];
				if (paramCount) {
					g_fileWrite(data->source, ", ");
				}
				if ((db_class_instanceof(db_interface_o, p->type) && (p->type->real->reference)) || (p->type == db_typedef(db_object_o))) {
					g_fileWrite(data->source, "_%s", g_id(data->g, p->name, id));
				} else {
					g_fileWrite(data->source, "%s", g_id(data->g, p->name, id));
				}
				paramCount++;
			}
			g_fileWrite(data->source, ")");
			if ((db_class_instanceof(db_interface_o, db_function(o)->returnType->real) && db_function(o)->returnType->real->reference) || (db_function(o)->returnType == db_typedef(db_object_o))) {
				g_fileWrite(data->source, "._handle()");
			}
			g_fileWrite(data->source, ";\n");
			g_fileDedent(data->source);
			g_fileWrite(data->source, "}\n");
		}
    }

    return 1;
error:
    return 0;
}

/* Include files for classes */
static int cpp_loadIncludes(db_object o, void* userData) {

	/* Add object to list */
	if (db_class_instanceof(db_interface_o, o) && db_type(o)->reference) {
		if (!db_llHasObject(userData, o)) {
			db_llInsert(userData, o);
		}
	}

	/* Add type of object to list */
	if (db_class_instanceof(db_interface_o, db_typeof(o)) && db_type(db_typeof(o))->reference) {
		if (!db_llHasObject(userData, db_typeof(o))) {
			db_llInsert(userData, db_typeof(o));
		}
	}

	/* Add types of parameters and returntypes to list */
	if (db_class_instanceof(db_procedure_o, db_typeof(o))) {
		db_uint32 i;
		db_parameter *p;
		for(i=0; i<db_function(o)->parameters.length; i++) {
			p = &db_function(o)->parameters.buffer[i];
			if (!db_llHasObject(userData, p->type) && (db_class_instanceof(db_interface_o, p->type) && p->type->real->reference)) {
				db_llInsert(userData, p->type);
			}
		}
		if (!db_llHasObject(userData, db_function(o)->returnType) && (db_class_instanceof(db_interface_o, db_function(o)->returnType) && db_function(o)->returnType->real->reference)) {
			db_llInsert(userData, db_function(o)->returnType);
		}
	}

	return 1;
}

static int cpp_printIncludes(void* o, void* userData) {
    cpp_typeWalk_t* data;
    db_id path, id;

    data = userData;
    cpp_topath(db_parentof(o), path);
    g_setIdKind(data->g, DB_GENERATOR_ID_CLASS_UPPER);
    g_fileWrite(data->source, "#include \"%s/%s.hpp\"\n", path, g_oid(data->g, o, id));
    g_setIdKind(data->g, DB_GENERATOR_ID_CLASS_LOWER);
    return 1;
}

static int cpp_loadProxyWalk(db_object o, void* userData) {
    cpp_typeWalk_t* data;
	db_id className, h_var, o_var;

	data = userData;

	if (db_class_instanceof(db_interface_o, o) && db_type(o)->reference) {
		cpp_metaFullname(data->g, o, CPP_HANDLE, h_var);
		g_setIdKind(data->g, DB_GENERATOR_ID_CLASS_UPPER);
		cpp_metaFullname(data->g, o, CPP_OBJECT, o_var);
		g_fullOid(data->g, db_typeof(o), className);
		g_fileWrite(data->source, "%s = new %s(%s);\n", o_var, className, h_var);
	}

	return 1;
}

static int cpp_unloadProxyWalk(db_object o, void* userData) {
    cpp_typeWalk_t* data;
    db_id o_var;

    data = userData;

    if (db_class_instanceof(db_interface_o, o) && db_type(o)->reference) {
        g_setIdKind(data->g, DB_GENERATOR_ID_CLASS_UPPER);
        cpp_metaFullname(data->g, o, CPP_OBJECT, o_var);
        g_fileWrite(data->source, "delete %s;\n", o_var);
        g_setIdKind(data->g, DB_GENERATOR_ID_CLASS_LOWER);
    }

    return 1;
}

/* Open generator headerfile */
static g_file cpp_loadHeaderFileOpen(db_generator g) {
    g_file result;
    db_id headerFileName, path;

    cpp_topath(g_getCurrent(g), path);

    /* Create file */
    if (strlen(path)) {
    	sprintf(headerFileName, "include/%s/_meta.hpp", path);
    } else {
    	sprintf(headerFileName, "include/_meta.hpp");
    }
    result = g_fileOpen(g, headerFileName);
    if (!result) {
        db_error("failed to open file '%s'", headerFileName);
    } else {
        /* Print standard comments and includes */
        g_fileWrite(result, "/* %s\n", headerFileName);
        g_fileWrite(result, " *\n");
        g_fileWrite(result, " *  Generated on %s\n", __DATE__);
        g_fileWrite(result, " *    Loads objects in database.\n");
        g_fileWrite(result, " *    This file contains generated code. Do not modify!\n");
        g_fileWrite(result, " */\n\n");
        g_fileWrite(result, "#ifndef %s_META_H\n", g_getName(g));
        g_fileWrite(result, "#define %s_META_H\n\n", g_getName(g));
        g_fileWrite(result, "#include \"hyve.hpp\"\n\n");
        g_fileWrite(result, "#include \"%s/_type.hpp\"\n\n", path);
    }

    return result;
}

/* Close headerfile */
static void cpp_loadHeaderFileClose(db_generator g, g_file file) {

    /* Print standard comments and includes */
    g_fileWrite(file, "\n");
    g_fileWrite(file, "int load(void);", g);
    g_fileWrite(file, "\n");
    cpp_closeScope(file);
    g_fileWrite(file, "#endif\n\n");
}

/* Open generator sourcefile */
static g_file cpp_loadSourceFileOpen(db_generator g) {
    g_file result;
    db_id fileName, path;

    cpp_topath(g_getCurrent(g), path);

    /* Create file */
    if (strlen(path)) {
    	sprintf(fileName, "src/%s/_meta.cpp", path);
    } else {
    	sprintf(fileName, "src/_meta.cpp");
    }
    result = g_fileOpen(g, fileName);
    if (!result) {
        db_error("failed to open file '%s'", fileName);
    } else {
        /* Print standard comments and includes */
        g_fileWrite(result, "/* %s\n", fileName);
        g_fileWrite(result, " *\n");
        g_fileWrite(result, " *  Generated on %s\n", __DATE__);
        g_fileWrite(result, " *    Loads objects in database.\n");
        g_fileWrite(result, " *    This file contains generated code. Do not modify!\n");
        g_fileWrite(result, " */\n\n");
        g_fileWrite(result, "#include \"%s/_type.hpp\"\n", path, g_getName(g));
        g_fileWrite(result, "#include \"hyve.hpp\"\n\n");
    }

    return result;
}

/* Write starting comment of variable definitions */
static void cpp_sourceWriteVarDefStart(g_file file) {
    g_fileWrite(file, "/* Variable definitions */\n");
}

/* Write start of load-routine */
static void cpp_sourceWriteLoadStart(db_generator g, g_file file) {
	cpp_openScope(file, g_getCurrent(g));
    g_fileWrite(file, "\n");
    g_fileWrite(file, "/* Load objects in database */\n");
    g_fileWrite(file, "int load(void) {\n");
    g_fileIndent(file);
    g_fileWrite(file, "::hyve::lang::object _a_; /* Used for resolving anonymous objects */\n");
    g_fileWrite(file, "_a_ = NULL;\n\n");
}

/* Write end of load-routine */
static void cpp_sourceWriteLoadEnd(g_file file) {
	g_fileWrite(file, "if (_a_) {\n");
	g_fileIndent(file);
	g_fileWrite(file, "::hyve::free(NULL, _a_, \"load: free temporary reference.\");\n");
	g_fileDedent(file);
	g_fileWrite(file, "}\n\n");
    g_fileWrite(file, "return 0;\n");
    g_fileDedent(file);
    g_fileWrite(file, "error:\n");
    g_fileIndent(file);
    g_fileWrite(file, "return -1;\n");
    g_fileDedent(file);
    g_fileWrite(file, "}\n");
    cpp_closeScope(file);
}

/* Write start of unload-routine */
static void cpp_sourceWriteUnloadStart(db_generator g, g_file file) {
	cpp_openScope(file, g_getCurrent(g));
    g_fileWrite(file, "\n");
    g_fileWrite(file, "/* Load objects in database */\n");
    g_fileWrite(file, "void unload(void* udata) {\n");
    g_fileIndent(file);
    g_fileWrite(file, "(void)udata;\n");
}

/* Write end of unload-routine */
static void cpp_sourceWriteUnloadEnd(g_file file) {
    g_fileDedent(file);
    g_fileWrite(file, "}\n");
}

/* Declare object */
static int cpp_loadDeclare(db_object o, void* userData) {
    cpp_typeWalk_t* data;
    db_id id, parentId, typeId, specId, fullId;

    data = userData;

    /* Only declare scoped objects */
    if (db_checkAttr(o, DB_ATTR_SCOPED)) {

        /* Declaration */
        g_fileWrite(data->source, "/* Declare %s */\n", db_fullname(o, id));
        cpp_specifierId(data->g, db_typeof(o), specId);
        g_fileWrite(data->source, "if (!(%s = (%s%s)::hyve::resolve(NULL, NULL, \"%s\", \"load: check if object '%s' already exists.\"))) {\n",
                    cpp_loadVarId(data->g, o, id),
                    specId,
                    db_typeof(o)->real->reference ? "" : "*",
                    db_fullname(o, fullId),
                    db_fullname(o, fullId));
        g_fileIndent(data->source);

        if (!db_checkAttr(db_typeof(o), DB_ATTR_SCOPED)) {
			g_fileWrite(data->source, "%s = (%s%s)::hyve::declare(%s, \"%s\", (_a_ ? ::hyve::free(_a_) : 0, _a_ = ((::hyve::lang::_typedef)%s)));\n",
					cpp_loadVarId(data->g, o, id),
                    specId,
                    db_typeof(o)->real->reference ? "" : "*",
					cpp_loadVarId(data->g, db_parentof(o), parentId),
					db_nameof(o),
					cpp_loadVarId(data->g, db_typeof(o), typeId));
        } else {
			g_fileWrite(data->source, "%s = (%s%s)::hyve::declare(%s, \"%s\", ((::hyve::lang::_typedef)%s));\n",
					cpp_loadVarId(data->g, o, id),
                    specId,
                    db_typeof(o)->real->reference ? "" : "*",
					cpp_loadVarId(data->g, db_parentof(o), parentId),
					db_nameof(o),
					cpp_loadVarId(data->g, db_typeof(o), typeId));
        }

        /* Error checking */
        g_fileWrite(data->source, "if (!%s) {\n", cpp_loadVarId(data->g, o, id));
        g_fileIndent(data->source);
        g_fileWrite(data->source, "::hyve::error(\"%s_load: failed to declare object '%s'.\");\n",
                g_getName(data->g),
                db_fullname(o, id));
        g_fileWrite(data->source, "goto error;\n");
        g_fileDedent(data->source);
        g_fileWrite(data->source, "}\n");

        g_fileDedent(data->source);
        g_fileWrite(data->source, "} else {\n");
        g_fileIndent(data->source);
        g_fileWrite(data->source, "::hyve::free(%s);\n", cpp_loadVarId(data->g, o, id));
        g_fileDedent(data->source);
        g_fileWrite(data->source, "}\n\n");
    }

    return 1;
}

/* Print variable start */
static void cpp_varPrintStart(db_value* v, cpp_typeWalk_t* data) {
    db_id memberId;
    db_type t;

    t = db_valueType(v)->real;

    /* Only write an identifier if the object is a primitive type, or a reference. */
    if ((t->kind == DB_PRIMITIVE) || (t->reference && !(v->kind == DB_OBJECT))) {
        /* Print memberId if object is member */
		g_fileWrite(data->source, "%s = ",
				cpp_loadMemberId(data, v, memberId, FALSE));
    }
}

/* Print variable end */
static void cpp_varPrintEnd(db_value* v, cpp_typeWalk_t* data) {
    db_type t;

    /* Get member object */
    t = db_valueType(v)->real;
    if ((t->kind == DB_PRIMITIVE) || (t->reference && !(v->kind == DB_OBJECT))) {
        /* Print end of member-assignment */
        g_fileWrite(data->source, ";\n");
    }
}

/* cpp_initPrimitive */
static db_int16 cpp_initPrimitive(db_serializer s, db_value* v, void* userData) {
    void* ptr;
    db_type t;
    db_string str;
    cpp_typeWalk_t* data;
    DB_UNUSED(s);

    ptr = db_valueValue(v);
    t = db_valueType(v)->real;
    data = userData;
    str = NULL;

    cpp_varPrintStart(v, userData);

    /* Treat booleans separately, the default convert translates booleans to 'true' and 'false' while
     * the language mapping of C TRUE and FALSE is. */
    if (db_primitive(t)->kind == DB_BOOLEAN) {
    	if (*(db_bool*)ptr) {
    		str = db_strdup("TRUE");
    	} else {
    		str = db_strdup("FALSE");
    	}
    } else if (db_primitive(t)->kind == DB_ENUM) {
        db_id enumId, scopeId;
        db_constant *c;

        c = db_enum_constant(db_enum(t), *(db_uint32*)ptr);

        /* Constant id */
        cpp_constantId(data->g, c, enumId);

        /* Scope of enum */
        db_fullname(db_parentof(db_parentof(c)), scopeId);

        /* Convert constant-name to language id */
        str = db_malloc(strlen(enumId) + strlen(scopeId) + 2 + 1);
        sprintf(str, "%s::%s", scopeId, enumId);
    } else if (db_primitive(t)->kind == DB_BITMASK) {
        str = db_malloc(11);
        sprintf(str, "0x%x", *(db_uint32*)ptr);
    } else if (db_primitive(t)->kind == DB_TEXT) {
    	db_string v = *(db_string*)ptr;
    	if (v) {
    		str = malloc(strlen("::hyve::strdup()") + strlen(v) + 1);
    		sprintf(str, "::hyve::strdup(%s)", v);
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

	if (db_primitive(t)->width == DB_WIDTH_64) {
	    if (db_primitive(t)->kind == DB_UINTEGER) {
	        g_fileWrite(data->source, "ULL");
	    }
	}

    cpp_varPrintEnd(v, userData);

    return 0;
error:
    return -1;
}

/* cpp_initReference */
static db_int16 cpp_initReference(db_serializer s, db_value* v, void* userData) {
    db_object *optr, o;
    cpp_typeWalk_t* data;
    DB_UNUSED(s);

    data = userData;
    optr = db_valueValue(v);

    cpp_varPrintStart(v, userData);

    if ((o = *optr)) {
        db_id id, typeId;
        g_fileWrite(data->source, "((%s)%s)",
                g_fullOid(data->g, db_valueType(v), typeId),
                cpp_loadResolve(o, id));
    } else {
        g_fileWrite(data->source, "NULL");
    }

    cpp_varPrintEnd(v, userData);

    return 0;
}

/* cpp_initElement */
static db_int16 cpp_initElement(db_serializer s, db_value* v, void* userData) {
	db_collection t;
	cpp_typeWalk_t* data;

	/* Get collectionType */
	t = db_collection(db_valueType(v->parent)->real);
	data = userData;

	/* Allocate space for element */
	switch(t->kind) {
	case DB_LIST:
	case DB_MAP: {
		db_id elementId, specifier;
		g_fileWrite(data->source, "\n");

		cpp_specifierId(data->g, t->elementType, specifier);
		g_fileWrite(data->source, "%s = ::hyve::alloc(sizeof(%s));\n", cpp_loadElementId(v, elementId, 0), specifier);
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
		g_fileWrite(data->source, "%s->append(%s);\n",
				cpp_loadMemberId(data, v->parent, parentId, FALSE),
				cpp_loadElementId(v, elementId, 0));
		break;
	}
	case DB_MAP: /*{
		db_id parentId, elementId;
		g_fileWrite(data->source, "db_rbtreeSet(%s, %s)",
				cpp_loadMemberId(data->g, v->parent, parentId),
				cpp_loadElementId(v, elementId, 0));
		break;
	}*/
	default:
		break;
	}

	return 0;
error:
	return -1;
}

/* cpp_initCollection */
static db_int16 cpp_initCollection(db_serializer s, db_value* v, void* userData) {
    db_collection t;
    cpp_typeWalk_t* data;
    db_id memberId;
    db_uint32 size = 0;
    int result;
    void* ptr;

    ptr = db_valueValue(v);

    t = db_collection(db_valueType(v)->real);
    data = userData;

    switch(t->kind) {
    case DB_ARRAY:
        size = t->max;
        break;
    case DB_SEQUENCE: {
        db_uint32 length;
    	db_id specifier;

        size = length = *(db_uint32*)ptr;

        /* Set length of sequence */
        g_fileWrite(data->source, "%slength = %d;\n",
                cpp_loadMemberId(data, v, memberId, TRUE),
                length);

    	/* Get type-specifier */
    	cpp_specifierId(data->g, t->elementType, specifier);

        /* Allocate buffer */
        if (!length) {
            g_fileWrite(data->source, "%sbuffer = NULL;\n",
                    cpp_loadMemberId(data, v, memberId, TRUE));
        } else if (length == 1) {
            g_fileWrite(data->source, "%sbuffer = (%s*)::hyve::alloc(sizeof(%s));\n",
                    cpp_loadMemberId(data, v, memberId, TRUE),
                    specifier,
                    specifier);
        } else {
            g_fileWrite(data->source, "%sbuffer = (%s*)::hyve::alloc(sizeof(%s) * %d);\n",
                    cpp_loadMemberId(data, v, memberId, TRUE),
                    specifier,
                    specifier,
                    length);
        }
        break;
    }
    case DB_LIST:
        /* Create list object */
    	if (*(db_ll*)ptr) {
            size = db_llSize(*(db_ll*)ptr);
			g_fileWrite(data->source, "%s = new ::hyve::ll();\n",
					cpp_loadMemberId(data, v, memberId, FALSE));
    	} else {
    		g_fileWrite(data->source, "%s = NULL;\n", cpp_loadMemberId(data, v, memberId, FALSE));
    	}
        break;
    case DB_MAP: {
    	db_id keyId;
        /* Create map object */
    	if (*(db_rbtree*)ptr) {
            size = db_rbtreeSize(*(db_rbtree*)ptr);
			g_fileWrite(data->source, "%s = new ::hyve::rbtree();\n",
					cpp_loadMemberId(data, v, memberId, FALSE), g_fullOid(data->g, db_rbtreeKeyType(*(db_rbtree*)ptr), keyId));
    	} else {
    		g_fileWrite(data->source, "%s = NULL;\n", cpp_loadMemberId(data, v, memberId, FALSE));
    	}
        break;
    }
    }

	/* For the non-array types, allocate a member variable, if size of collection is not zero. */
    if (size) {
		switch(t->kind) {
		case DB_LIST:
		case DB_MAP: {
			db_id elementId, elementTypeId;
			g_fileWrite(data->source, "{\n");
			g_fileIndent(data->source);
			g_fileWrite(data->source, "%s* %s;\n", g_fullOid(data->g, t->elementType, elementTypeId), cpp_loadElementId(v, elementId, 1));
			break;
		}
		default:
			break;
		}
    }

    /* Serialize elements */
    result = db_serializeElements(s, v, userData);

    if (size) {
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

/* cpp_initObject */
static db_int16 cpp_initObject(db_serializer s, db_value* v, void* userData) {
    cpp_typeWalk_t* data;
    db_id id, id2;
    db_object o;
    db_bool isProcedure;

    data = userData;
    o = db_valueObject(v);
    isProcedure = FALSE;

    g_fileWrite(data->source, "/* Define %s */\n", db_fullname(o, id));
    g_fileWrite(data->source, "if (!::hyve::checkState((::hyve::lang::object)%s, ::hyve::lang::DEFINED)) {\n", cpp_loadVarId(data->g, o, id));
    g_fileIndent(data->source);

    /* Serialize object value */
    db_serializeValue(s, v, userData);

    /* If object is a procedure, set function implementation */
    if (db_class_instanceof(db_procedure_o, db_typeof(o)) && (db_procedure(db_typeof(o))->kind != DB_METAPROCEDURE)) {
    	isProcedure = TRUE;

    	/* C++ uses CDECL convention */
        g_fileWrite(data->source, "\n");
        g_fileWrite(data->source, "/* Bind %s with C++ function */\n", id);
        g_fileWrite(data->source, "((::hyve::lang::function)%s)->kind = DB_PROCEDURE_CDECL;\n", cpp_loadVarId(data->g, o, id));

        /* Bind function-object with marshall function */
		if (!(db_checkState(o, DB_DEFINED) && (db_procedure(db_typeof(o))->kind == DB_CALLBACK))) {
			g_fileWrite(data->source, "((::hyve::lang::function)%s)->impl = reinterpret_cast< ::hyve::lang::word>(%s);\n", id, cpp_loadMarshallId(data->g, o, id2));
		} else {
			/* Callback functions are not generated when they are defined while the load-routine was generated. This is because a callback
			 * method will never be called directly, only through it's corresponding delegate function. */
			g_fileWrite(data->source, "((::hyve::lang::function)%s)->impl = 0;\n", id);
		}

        g_setIdKind(data->g, DB_GENERATOR_ID_CLASS_LOWER);
    }

    /* Define object, but not if the object is a procedure and the parent is an abstract class, because these have no implementation. */
    if (!(isProcedure && (db_interface(db_parentof(o))->kind == DB_INTERFACE))) {
		g_fileWrite(data->source, "if (::hyve::define(%s)) {\n", cpp_loadVarId(data->g, o, id));
		g_fileIndent(data->source);
		g_fileWrite(data->source, "::hyve::error(\"%s_load: failed to define object '%s'.\");\n",
				g_getName(data->g),
				db_fullname(o, id));
		g_fileWrite(data->source, "goto error;\n");
		g_fileDedent(data->source);
		g_fileWrite(data->source, "}\n");
    }

    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n");

    return 0;
}

/* Create serializer that initializes object values */
static struct db_serializer_s cpp_initSerializer(void) {
    struct db_serializer_s s;

    db_serializerInit(&s);

    s.access = DB_LOCAL;
    s.accessKind = DB_NOT;
    s.traceKind = DB_SERIALIZER_TRACE_ON_FAIL;
    s.program[DB_PRIMITIVE] = cpp_initPrimitive;
    s.program[DB_COLLECTION] = cpp_initCollection;
    s.metaprogram[DB_OBJECT] = cpp_initObject;
    s.metaprogram[DB_ELEMENT] = cpp_initElement;
    s.reference = cpp_initReference;

    return s;
}

/* Define object */
static int cpp_loadDefine(db_object o, void* userData) {
    struct db_serializer_s s;

    if (db_checkAttr(o, DB_ATTR_SCOPED)) {
        /* Obtain serializer to initialize object values */
        s = cpp_initSerializer();

        /* Serialize object */
        db_serialize(&s, o, userData);
    }

    return 1;
}

/* Entry point for generator */
int hyve_genMain(db_generator g) {
    cpp_typeWalk_t walkData;
    db_ll headers;

    g_setIdKind(g, DB_GENERATOR_ID_CLASS_LOWER);

    /* Prepare walkData, create header- and sourcefile */
    walkData.g = g;
    walkData.header = cpp_loadHeaderFileOpen(g);
    walkData.source = cpp_loadSourceFileOpen(g);

    /* Collect headers for classes and types of objects */
    headers = db_llNew();
    g_walkRecursive(g, cpp_loadIncludes, headers);
    /* Print includes */
    db_llWalk(headers, cpp_printIncludes, &walkData);
    g_fileWrite(walkData.source, "\n");
    db_llFree(headers);

    /* Write comment indicating definitions in sourcefile */
    cpp_sourceWriteVarDefStart(walkData.source);

    /* Walk objects, declare variables in header and sourcefile */
    if (!g_walkRecursive(g, cpp_loadDeclareWalk, &walkData)) {
        goto error;
    }

    /* Generate proxy-functions for class methods */
    if (!g_walkRecursive(g, cpp_loadMethodProxy, &walkData)) {
        goto error;
    }

    /* Create unload routine */
    cpp_sourceWriteUnloadStart(g, walkData.source);

    /* Create C++ proxy objects */
    if (!g_walkRecursive(g, cpp_unloadProxyWalk, &walkData)) {
        goto error;
    }
    cpp_sourceWriteUnloadEnd(walkData.source);

    /* Create load-routine */
    cpp_sourceWriteLoadStart(g, walkData.source);

    /* Walk objects in dependency order */
    if (db_genDepWalk(g, cpp_loadDeclare, cpp_loadDefine, &walkData)) {
        db_trace("generation of load-routine failed while resolving dependencies.");
        goto error;
    }

    /* Create C++ proxy objects */
    if (!g_walkRecursive(g, cpp_loadProxyWalk, &walkData)) {
    	goto error;
    }

    /* Register exithandler */
    g_fileWrite(walkData.source, "hyve::onunload(unload, NULL);\n");

    /* Close load-routine */
    cpp_sourceWriteLoadEnd(walkData.source);

    /* Close headerfile */
    cpp_loadHeaderFileClose(g, walkData.header);

    return 0;
error:
    return -1;
}
