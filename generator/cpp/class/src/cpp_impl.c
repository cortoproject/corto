/*
 * cpp_impl.c
 *
 *  Created on: Dec 27, 2012
 *      Author: sander
 */

#include "cpp_impl.h"
#include "cpp_common.h"

typedef struct cpp_implWalk_t {
    db_generator g;
    g_file file;
    db_uint16 firstComma;
} cpp_implWalk_t;

static void cpp_implStub(db_function o, db_string metaFunction, cpp_implWalk_t* data) {
	db_uint32 i;
	db_id id;
	db_parameter* p;
	db_typedef returnType;

	/* Returnvalue */
	returnType = o->returnType;
	if ((returnType->real->kind != DB_VOID) || (returnType->real->reference)) {
		db_id specifier;
		g_setIdKind(data->g, DB_GENERATOR_ID_CLASS_LOWER);
	    cpp_specifierId(data->g, returnType, specifier);
		g_fileWrite(data->file, "%s _result;\n", specifier);
		g_setIdKind(data->g, DB_GENERATOR_ID_CLASS_UPPER);
	} else {
		returnType = NULL;
	}

	/* Call implemented function */
	g_fileWrite(data->file, "::cortex::call((::cortex::lang::function)(%s)", metaFunction);
	if (returnType) {
		g_fileWrite(data->file, ",&_result");
	} else {
		g_fileWrite(data->file, ",NULL");
	}
	if (db_class_instanceof(db_interface_o, db_parentof(o))) {
		if (db_procedure(db_typeof(o))->kind != DB_FUNCTION) {
			g_fileWrite(data->file, ",this->__handle");
		}
	}
	for(i=0; i<o->parameters.length; i++) {
		p = &o->parameters.buffer[i];
		g_fileWrite(data->file, ",%s", g_id(data->g, p->name, id));
		if (p->type->real->reference) {
			g_fileWrite(data->file, "._handle()");
		}
	}
	g_fileWrite(data->file, ");\n");
	if (returnType) {
	    if (db_class_instanceof(db_interface_o, returnType)) {
			if (db_class_instanceof(db_interface_o, returnType)) {
				db_id specifier;
				cpp_specifierId(data->g, returnType, specifier);
				g_fileWrite(data->file, "%s ", specifier);
			}
	    	g_fileWrite(data->file, "__result(_result);\n");
	        g_fileWrite(data->file, "return __result;\n");
	    } else {
	        g_fileWrite(data->file, "return _result;\n");
	    }
	}
}

/* Generate convenience method for virtual calls */
static int cpp_implVirtual(db_method o, cpp_implWalk_t *data) {
    db_id id;

	g_fileWrite(data->file, "\n");
	g_fileWrite(data->file, "/* virtual %s */\n", db_fullname(o, id));

	cpp_functionDecl(data->g, data->file, db_function(o), FALSE);

	g_fileWrite(data->file, " {\n");
	g_fileIndent(data->file);
	g_fileWrite(data->file, "cortex::lang::Class _type((cortex::lang::_class)this->_typeof()._handle());\n");
	g_fileWrite(data->file, "static cortex::lang::uint32 _actualMethodId;\n");
	g_fileWrite(data->file, "\n");
	g_fileWrite(data->file, "if (!_actualMethodId) {\n");
	g_fileIndent(data->file);
	g_fileWrite(data->file, "_actualMethodId = _type.resolveMethodId((cortex::lang::string)\"%s\");\n", db_nameof(o));
	g_fileDedent(data->file);
	g_fileWrite(data->file, "}\n");
	g_fileWrite(data->file, "cortex::lang::Method _actualMethod = _type.resolveMethodById(_actualMethodId);\n");

	/* Insert stub code */
	cpp_implStub(db_function(o), "(cortex::lang::function)_actualMethod._handle()", data);

	g_fileDedent(data->file);
	g_fileWrite(data->file, "}\n");

    return 1;
}

/* Generate methods for class */
static int c_implProcedure(db_object o, void* userData) {
    cpp_implWalk_t* data;
    db_bool defined;
    db_bool isVirtual = FALSE;

    data = userData;

    /* Only generate code for procedures */
    if (db_class_instanceof(db_procedure_o, db_typeof(o)) && (db_procedure(db_typeof(o))->kind != DB_METAPROCEDURE)) { /* TODO: Metaprocedures are not yet mapped to C++ */
        defined = db_checkState(o, DB_DEFINED) && (db_function(o)->kind != DB_PROCEDURE_STUB);

    	/* Do not generate code for defined callbacks - these will never be called
    	 * directly, so generating a stub for them makes no sense. */
    	if (!((db_procedure(db_typeof(o))->kind == DB_CALLBACK) && defined)) {
			db_string snippet;
			db_id id;
			db_bool isMethod = db_instanceof(db_typedef(db_method_o), o);

			g_fileWrite(data->file, "\n");
			g_fileWrite(data->file, "/* %s */\n", db_fullname(o, id));

			if (isMethod) {
				isVirtual = db_method(o)->virtual;
				cpp_functionDeclExt(data->g, data->file, o, FALSE, isVirtual);
			} else {
				cpp_functionDecl(data->g, data->file, o, FALSE);
			}

			g_fileWrite(data->file, " {\n");

			/* If function is defined, create stub */
			if (defined) {
				g_fileIndent(data->file);
				cpp_implStub(o, cpp_metaFullname(data->g, o, CPP_HANDLE, id), data);
				g_fileDedent(data->file);
			} else {
				g_fileWrite(data->file, "/* $begin(%s)", db_fullname(o, id));
				g_fileIndent(data->file);

				/* Look for existing code-snippets */
				snippet = g_fileLookupSnippet(data->file, id);
				if (!snippet && !db_function(o)->overloaded) {
					db_char* ptr;
					ptr = strchr(id, '(');
					if (ptr) {
						*ptr = '\0';
						/* Non-overloaded functions may have snippets without argumentlists */
						snippet = g_fileLookupSnippet(data->file, id);
					} else {
						if (db_procedure(db_typeof(o))->kind != DB_OBSERVER) {
							db_warning("function '%s' has no argumentlist.", db_nameof(o));
						}
					}
				}

				/* If snippet is not found, insert default body */
				if (!snippet) {
					g_fileWrite(data->file, " */\n\n");
					g_fileWrite(data->file, "/* << Insert implementation >> */\n\n");
					g_fileDedent(data->file);
					g_fileWrite(data->file, "/* ");

				/* Else, insert snippet */
				} else {
					g_fileDedent(data->file);
					g_fileWrite(data->file, "%s", snippet);
				}

				g_fileWrite(data->file, "$end */\n");
			}
			g_fileWrite(data->file, "}\n");
    	}
    }

    if (isVirtual) {
    	cpp_implVirtual(db_method(o), data);
    }

    return 1;
}

typedef struct cpp_member_t {
	db_generator g;
	g_file file;
}cpp_member_t;

static db_int16 cpp_onMember(db_serializer s, db_value* v, void* userData) {
	db_member m;
	cpp_member_t* data;
	db_id id;

	data = userData;
	DB_UNUSED(s);

	/* Get member */
	if (v->kind == DB_MEMBER) {
		m = v->is.member.t;
		g_fileWrite(data->file, "this->%s(%s);\n",
				g_id(data->g, db_nameof(m), id),
				id);
	} else {
		db_serializeMembers(s, v, userData);
	}

	return 0;
}

static struct db_serializer_s cpp_memberSerializer(void) {
	struct db_serializer_s result;
	db_serializerInit(&result);
	result.access = DB_LOCAL|DB_PRIVATE;
	result.accessKind = DB_NOT;
	result.traceKind = DB_SERIALIZER_TRACE_ON_FAIL;
	result.metaprogram[DB_MEMBER] = cpp_onMember;
	return result;
}

static void cpp_implConstructor(db_generator g, g_file file, db_interface o) {
	struct db_serializer_s s;
	cpp_member_t walkData;
    db_object base;
    db_id id, id2;

    if (db_class_instanceof(db_struct_o, o)) {
        base = db_interface(o)->base;
        if (!base) {
            base = db_object_o;
        }
    } else {
        base = NULL;
    }

	s = cpp_memberSerializer();

	g_fileWrite(file, "\n");
	g_fileWrite(file, "// Constructor\n");
	cpp_constructorDecl(g, file, o, FALSE);
	if (base) {
	    g_fileWrite(file, " : %s((%s)NULL)", g_fullOid(g, base, id), g_fullOidExt(g, base, id2, DB_GENERATOR_ID_CLASS_LOWER));
	}
	g_fileWrite(file, " {\n");
	g_fileIndent(file);

	/* Create object */
	g_fileWrite(file, "this->__handle = ::cortex::_new((::cortex::lang::_typedef)%s);\n",
			cpp_metaFullname(g, o, CPP_HANDLE, id));

	walkData.g = g;
	walkData.file = file;
	db_metaWalk(&s, db_type(o), &walkData);

	/* Define object */
	g_fileWrite(file, "this->define();\n");

	g_fileDedent(file);
	g_fileWrite(file, "}\n");
}

static void cpp_implConstructorScoped(db_generator g, g_file file, db_interface o) {
	struct db_serializer_s s;
	cpp_member_t walkData;
    db_object base;
    db_id id, id2;

    if (db_class_instanceof(db_struct_o, o)) {
        base = db_interface(o)->base;
        if (!base) {
            base = db_object_o;
        }
    } else {
        base = NULL;
    }

	s = cpp_memberSerializer();

	g_fileWrite(file, "\n");
	g_fileWrite(file, "// Constructor (declare & define)\n");
	cpp_constructorScopedDecl(g, file, o, FALSE);
	if (base) {
	    g_fileWrite(file, " : %s((%s)NULL)", g_fullOid(g, base, id), g_fullOidExt(g, base, id2, DB_GENERATOR_ID_CLASS_LOWER));
	}
	g_fileWrite(file, " {\n");
	g_fileIndent(file);

	/* Create object */
	g_fileWrite(file, "this->__handle = ::cortex::declare(_parent->_handle(), _name, (::cortex::lang::_typedef)%s);\n",
			cpp_metaFullname(g, o, CPP_HANDLE, id));

	walkData.g = g;
	walkData.file = file;
	db_metaWalk(&s, db_type(o), &walkData);

	/* Define object */
	g_fileWrite(file, "this->define();\n");

	g_fileDedent(file);
	g_fileWrite(file, "}\n");
}

static void cpp_implConstructorHandle(db_generator g, g_file file, db_interface o) {
    db_object base;
    db_id id, id2;

    if (db_class_instanceof(db_struct_o, o)) {
        base = db_interface(o)->base;
        if (!base) {
            base = db_object_o;
        }
    } else {
        if (db_class_instanceof(db_interface_o, o)) {
            base = db_object_o;
        } else {
            base = NULL;
        }
    }

	g_fileWrite(file, "\n");
	g_fileWrite(file, "// Construct from handle\n");
	cpp_constructorHandleDecl(g, file, o, FALSE);
	if (base) {
	    g_fileWrite(file, " : %s((%s)handle, owner)", g_fullOid(g, base, id), g_fullOidExt(g, base, id2, DB_GENERATOR_ID_CLASS_LOWER));
	}
	g_fileWrite(file, " {\n");
	g_fileIndent(file);
	g_fileWrite(file, "// Handle is set and keep'd by Object::Object(object handle)\n");
	g_fileDedent(file);
	g_fileWrite(file, "}\n");
}

static void cpp_implHandleGet(db_generator g, g_file file, db_interface o) {
    db_id id;

    g_fileWrite(file, "\n");
    g_fileWrite(file, "// Get handle\n");
    cpp_handleGetDecl(g, file, o, FALSE);
    g_fileWrite(file, " {\n");
    g_fileIndent(file);

    /* Create object */
    g_fileWrite(file, "return (%s)this->__handle;\n", g_fullOidExt(g, o, id, DB_GENERATOR_ID_CLASS_LOWER));

    g_fileDedent(file);
    g_fileWrite(file, "}\n");
}

static void cpp_implGetter(db_generator g, g_file file, db_member m) {
	db_id id, memberId, refId;

	/* Getter declaration */
	cpp_memberGetter(g, file, m, FALSE);
	g_fileWrite(file, " {\n");
	g_fileIndent(file);

	/* Return value */
	if (!m->type->real->reference) {
		g_fileWrite(file, "return ((%s)this->__handle)->%s;\n",
				g_fullOidExt(g, db_parentof(m), id, DB_GENERATOR_ID_CLASS_LOWER),
				g_id(g, db_nameof(m), memberId));
	} else {
		g_fileWrite(file, "%s result(((%s)this->__handle)->%s);\n",
				g_fullOid(g, m->type, refId),
				g_fullOidExt(g, db_parentof(m), id, DB_GENERATOR_ID_CLASS_LOWER),
				g_id(g, db_nameof(m), memberId));
		g_fileWrite(file, "return result;\n");
	}

	g_fileDedent(file);
	g_fileWrite(file, "}\n");
}

static void cpp_implSetter(db_generator g, g_file file, db_member m) {
	db_id id, memberId;

	/* Getter declaration */
	cpp_memberSetter(g, file, m, FALSE);
	g_fileWrite(file, " {\n");
	g_fileIndent(file);

	/* Set value */
	if (!m->type->real->reference) {
	    if ((m->type->real->kind == DB_PRIMITIVE) && (db_primitive(m->type->real)->kind == DB_TEXT)) {
            g_fileWrite(file, "if (((%s)this->__handle)->%s) {\n",
                    g_fullOidExt(g, db_parentof(m), id, DB_GENERATOR_ID_CLASS_LOWER),
                    g_id(g, db_nameof(m), memberId));
            g_fileIndent(file);
            g_fileWrite(file, "cortex::dealloc(((%s)this->__handle)->%s);\n",
                    g_fullOidExt(g, db_parentof(m), id, DB_GENERATOR_ID_CLASS_LOWER),
                    g_id(g, db_nameof(m), memberId));
            g_fileDedent(file);
            g_fileWrite(file, "};\n");
            g_fileWrite(file, "((%s)this->__handle)->%s = v ? cortex::strdup(v) : NULL;\n",
                    g_fullOidExt(g, db_parentof(m), id, DB_GENERATOR_ID_CLASS_LOWER),
                    g_id(g, db_nameof(m), memberId));
	    } else {
            g_fileWrite(file, "((%s)this->__handle)->%s = v;\n",
                    g_fullOidExt(g, db_parentof(m), id, DB_GENERATOR_ID_CLASS_LOWER),
                    g_id(g, db_nameof(m), memberId));
	    }
	} else {
		g_fileWrite(file, "if (v) {\n");
		g_fileIndent(file);
		g_fileWrite(file, "cortex::set((cortex::lang::object*)&((%s)this->__handle)->%s, v._handle());\n",
				g_fullOidExt(g, db_parentof(m), id, DB_GENERATOR_ID_CLASS_LOWER),
				g_id(g, db_nameof(m), memberId));
		g_fileDedent(file);
		g_fileWrite(file, "} else {\n");
		g_fileIndent(file);
		g_fileWrite(file, "cortex::set((cortex::lang::object*)&((%s)this->__handle)->%s, NULL);\n",
						g_fullOidExt(g, db_parentof(m), id, DB_GENERATOR_ID_CLASS_LOWER),
						g_id(g, db_nameof(m), memberId));
		g_fileDedent(file);
		g_fileWrite(file, "}\n");
	}

	g_fileDedent(file);
	g_fileWrite(file, "}\n");
}



/* Generate getters & setters */
static void cpp_implClass(db_generator g, g_file file, db_interface o) {
	db_uint32 i;
	db_member m;
	db_id id;

	/* Constructors */
	cpp_implConstructor(g, file, o);
	cpp_implConstructorScoped(g, file, o);
	cpp_implConstructorHandle(g, file, o);
	cpp_implHandleGet(g, file, o);

	for(i=0; i<db_interface(o)->members.length; i++) {
		m = db_interface(o)->members.buffer[i];

		g_fileWrite(file, "\n");
		g_fileWrite(file, "// %s %s\n", db_fullname(db_member(m)->type, id), db_nameof(m));
		cpp_implGetter(g, file, m);
		cpp_implSetter(g, file, m);
	}
}

/* Find all reference-types in members and procedures */
static int cpp_findReferences(db_object o, void* userData) {
	if (db_class_instanceof(db_member_o, o)) {
		if (db_member(o)->type->real->reference) {
			if (!db_llHasObject(userData, db_member(o)->type->real)) {
				db_llInsert(userData, db_member(o)->type->real);
			}
		}
	} else if (db_class_instanceof(db_procedure_o, db_typeof(o))) {
		db_uint32 i;
		db_parameter* p;

		/* Check returnType */
		if (db_function(o)->returnType->real->reference) {
			if (!db_llHasObject(userData, db_function(o)->returnType->real)) {
				db_llInsert(userData, db_function(o)->returnType->real);
			}
		}

		/* Walk parameters */
		for(i=0; i<db_function(o)->parameters.length; i++) {
			p = &db_function(o)->parameters.buffer[i];
			if (p->type->real->reference) {
				if (!db_llHasObject(userData, p->type->real)) {
					db_llInsert(userData, p->type->real);
				}
			}
		}
	}
	return 1;
}

/* Collect class-headerfiles that must be included in sourcefile. */
static db_ll cpp_findHeaders(db_interface a) {
	db_ll refs;
	refs = db_llNew();
	db_scopeWalk(a, cpp_findReferences, refs);
	return refs;
}

/* Print headers for used reference-types */
static void cpp_printHeaders(db_generator g, g_file file, db_interface a) {
	db_ll refs;
	db_iter iter;

	refs = cpp_findHeaders(a);
	iter = db_llIter(refs);
	while(db_iterHasNext(&iter)) {
		db_id path, id;
		db_object o;

		o = db_iterNext(&iter);

		if (o != a) {
			cpp_topath(db_parentof(o), path);
			g_fileWrite(file, "#include \"%s/%s.hpp\"\n", path, g_oid(g, o, id));
		}
	}
	db_llFree(refs);
}

static g_file cpp_implOpen(db_object o, db_generator g) {
    g_file result;
    db_id fullname, path, id;
    db_id implFileName;

    /* Get filename */
    db_fullname(o, fullname);
    cpp_topath(g_getCurrent(g), path);

    if (strlen(path)) {
    	sprintf(implFileName, "src/%s/%s.cpp", path, g_oid(g, o, id));
    } else {
    	sprintf(implFileName, "src/%s.cpp", g_oid(g, o, id));
    }

    result = g_fileOpen(g, implFileName);
    if (!result) {
        db_error("failed to open file '%s'");
    } else {
        /* Print standard comments and includes */
        g_fileWrite(result, "/* %s\n", implFileName);
        g_fileWrite(result, " *\n");
        g_fileWrite(result, " *  Generated on %s\n", __DATE__);
        g_fileWrite(result, " *    C++ implementationfile for %s.\n", fullname);
        g_fileWrite(result, " *\n");
        g_fileWrite(result, " *    Don't mess with the begin and end tags, since these will ensure that modified\n");
        g_fileWrite(result, " *    code in interface functions isn't replaced when code is re-generated.\n");
        g_fileWrite(result, " */\n\n");
        g_fileWrite(result, "#include \"cortex/lang/Class.hpp\"\n", path, g_oid(g, o, id));
        g_fileWrite(result, "#include \"cortex/lang/Method.hpp\"\n", path, g_oid(g, o, id));
        g_fileWrite(result, "#include \"%s/%s.hpp\"\n", path, g_oid(g, o, id));
        g_fileWrite(result, "#include \"%s/_meta.hpp\"\n", path, g_oid(g, o, id));
        if (db_class_instanceof(db_interface_o, o)) {
            cpp_printHeaders(g, result, o);
        }

        g_fileWrite(result, "\n");
    }

    return result;
}

static void cpp_implClose(db_object o, g_file file) {
    DB_UNUSED(o);
    g_fileWrite(file, "\n");
}

int cpp_impl(db_object o, db_generator g) {
    db_string snippet;
    g_file source;
    cpp_implWalk_t walkData;

	/* Open headerfile */
	source = cpp_implOpen(o, g);
	db_assert(source != NULL, "failed to open source.");

   /* If a header exists, write it (before opening scope) */
    if ((snippet = g_fileLookupSnippet(source, "$header"))) {
        g_fileWrite(source, "/* $begin($header)");
        g_fileWrite(source, "%s", snippet);
        g_fileWrite(source, "$end */\n");
        g_fileWrite(source, "\n");
    }

	/* Open scope (do not open scope for classes and procedures) */
	if (db_class_instanceof(db_struct_o, o)) {
		cpp_openScope(source, db_parentof(o));
	} else {
		cpp_openScope(source, o);
	}

	/* If object is a class (abstract), generate getters & setters */
	if (db_class_instanceof(db_interface_o, o)) {
		cpp_implClass(g, source, o);
	}

	/* Walk scope */
	walkData.file = source;
	walkData.g = g;
	if (!db_scopeWalk(o, c_implProcedure, &walkData)) {
		goto error;
	}

   /* If a header exists, write it (before opening scope) */
	if ((snippet = g_fileLookupSnippet(source, "$classfooter"))) {
		g_fileWrite(source, "/* $begin($classfooter)");
		g_fileWrite(source, "%s", snippet);
		g_fileWrite(source, "$end */\n");
	}

	cpp_closeScope(source);

   /* If a footer exists, write it (before opening scope) */
	if ((snippet = g_fileLookupSnippet(source, "$footer"))) {
		g_fileWrite(source, "/* $begin($footer)");
		g_fileWrite(source, "%s", snippet);
		g_fileWrite(source, "$end */\n");
	}

	cpp_implClose(o, source);

    return 0;
error:
    return 1;
}
