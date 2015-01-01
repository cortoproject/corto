/*
 * cpp_class.c
 *
 *  Created on: Dec 21, 2012
 *      Author: sander
 */

#include "cortex.h"
#include "db_generator.h"
#include "cpp_common.h"
#include "cpp_impl.h"
#include "db_serializer.h"

static db_string cpp_escapeName(db_string fullname, db_id escaped) {
    db_char *ptr, *bptr, ch;

    ptr = fullname;
    bptr = escaped;

    while((ch = *ptr)) {
        if (ch == ':') {
            *bptr = '_';
            ptr++;
        } else {
            *bptr = ch;
        }
        bptr++;
        ptr++;
    }
    *bptr = '\0';

    return escaped;
}

static int cpp_headerWalk(db_object o, void* userData) {
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

static g_file cpp_headerOpen(db_interface o, db_generator g) {
    g_file result;
    db_id fullname, path, id;
    db_id escaped, headerFileName;
    db_ll headers;

    headers = db_llNew();

    /* Get filename */
    db_fullname(o, fullname);
    cpp_escapeName(fullname, escaped);
    cpp_topath(g_getCurrent(g), path);

    if (strlen(path)) {
    	sprintf(headerFileName, "include/%s/%s.hpp", path, g_oid(g, o, id));
    } else {
    	sprintf(headerFileName, "include/%s.hpp", g_oid(g, o, id));
    }

    result = g_fileOpen(g, headerFileName);
    if (!result) {
        db_error("failed to open file '%s'", headerFileName);
    } else {

        /* Print standard comments and includes */
        g_fileWrite(result, "/* %s\n", headerFileName);
        g_fileWrite(result, " *\n");
        g_fileWrite(result, " *  Generated on %s\n", __DATE__);
        g_fileWrite(result, " *    C++ definitions for %s.\n", fullname);
        g_fileWrite(result, " *    This file contains generated code. Do not modify!\n");
        g_fileWrite(result, " */\n\n");
        g_fileWrite(result, "#ifndef %s_H\n", escaped+1);
        g_fileWrite(result, "#define %s_H\n\n", escaped+1);
        g_fileWrite(result, "#include \"cortex.hpp\"\n");
        g_fileWrite(result, "#include \"%s/_type.hpp\"\n", path);

        /* If there is a base-class, include that file too. */
        if (db_class_instanceof(db_struct_o, o)) {
            if (db_interface(o)->base) {
            	db_llAppend(headers, db_interface(o)->base);
            } else {
                g_fileWrite(result, "#include \"cortex/lang/Object.hpp\"\n");
            }
        }

        /* Include implemented interfaces */
        if (db_class_instanceof(db_class_o, o)) {
        	db_uint32 i;
        	db_interface abstract;
        	for(i=0; i<db_class(o)->implements.length; i++) {\
        		abstract = db_class(o)->implements.buffer[i];
				db_llAppend(headers, abstract);
        	}
        }

        /* Print headers */
        {
            db_iter includeIter;
            includeIter = db_llIter(headers);
            while(db_iterHasNext(&includeIter)) {
                db_object include = db_iterNext(&includeIter);

                if (include != o) {
                    cpp_topath(db_parentof(include), path);
                    g_fileWrite(result, "#include \"%s/%s.hpp\"\n", path, g_oid(g, include, id));
                }
            }
        }

        /* Print forward declarations for classes from parameters and returnTypes */
        db_llFree(headers); headers = db_llNew();
        db_scopeWalk(o, cpp_headerWalk, headers);
        {
            db_iter fwdIter;
            fwdIter = db_llIter(headers);
            while(db_iterHasNext(&fwdIter)) {
                db_object fwd = db_iterNext(&fwdIter);

                if (fwd != o) {
                    cpp_openScope(result, fwd);
                    g_fileWrite(result, "class %s;\n", g_oid(g, fwd, id));
                }
            }
        }
        cpp_closeScope(result);

        db_llFree(headers);
        g_fileWrite(result, "\n");
    }

    return result;
}

static void cpp_headerClose(db_interface class, g_file file) {
    DB_UNUSED(class);
    g_fileWrite(file, "\n");
    g_fileWrite(file, "#endif\n\n");
}

typedef struct cpp_scopeWalk_t {
	db_generator g;
	g_file file;
	db_bool methods;
	db_bool members;
}cpp_scopeWalk_t;

/* Function declaration */
void cpp_functionDeclExt(db_generator g, g_file file, db_function o, db_bool inlined, db_bool virtualStub) {
	db_id oid, id;
	db_uint32 i;
	db_bool callback;
	db_parameter* p;

	callback = FALSE;

	if (inlined) {
		g_fileWrite(file, "public: ");
	}

	/* Callback functions are static as well as non-member functions in a class-scope */
	if ((db_procedure(db_typeof(o))->kind == DB_FUNCTION) || (db_procedure(db_typeof(o))->kind == DB_CALLBACK)) {
		if (inlined) {
			if (db_class_instanceof(db_interface_o, db_typeof(db_parentof(o)))) {
				g_fileWrite(file, "static ");
			}
		}
		callback = TRUE;
	}

	/* Function return-types are always return by value, including classes */
	g_fileWrite(file, "%s ", g_fullOid(g, db_function(o)->returnType, oid));

	if (!inlined && db_class_instanceof(db_interface_o, db_parentof(o))) {
		g_fileWrite(file, "%s::", g_oid(g, db_parentof(o), id));
	}

	if (!virtualStub) {
		g_fileWrite(file, "%s(", cpp_procId(g, o, id));
	} else {
		g_fileWrite(file, "%s_v(", cpp_procId(g, o, id));
	}

	for(i=0; i<db_function(o)->parameters.length; i++) {
	    db_id specifier;

		if (i) {
			g_fileWrite(file, ", ");
		}
		p = &db_function(o)->parameters.buffer[i];

		if (p->type->real->reference) {
			g_fileWrite(file, "const ");
		}

		cpp_specifierId(g, p->type, specifier);

		g_fileWrite(file, "%s ",
				specifier);

		if (p->type->real->reference) {
			g_fileWrite(file, "&");
		}

		g_fileWrite(file, "%s",
				g_id(g, p->name, id));
	}

	g_fileWrite(file, ")");
	if (!callback) {
		g_fileWrite(file, " const");
	}
}

/* Function declaration */
void cpp_functionDecl(db_generator g, g_file file, db_function o, db_bool inlined) {
	cpp_functionDeclExt(g, file, o, inlined, FALSE);
}

typedef struct cpp_member_t {
	db_generator g;
	g_file file;
	db_uint32 count;
	db_ll memberCache;
}cpp_member_t;

static db_int16 cpp_onMember(db_serializer s, db_value* v, void* userData) {
	db_member m;
	cpp_member_t* data;

	data = userData;
	DB_UNUSED(s);

	/* Get member */
	if (v->kind == DB_MEMBER) {
		db_id spec, member;
		m = v->is.member.t;

		if (data->count) {
			g_fileWrite(data->file, ",\n");
			g_fileWrite(data->file, "        ");
		}
		cpp_specifierId(data->g, m->type, spec);

		g_fileWrite(data->file, "%s %s %s%s",
				m->type->real->reference ? "const" : "",
				spec,
				m->type->real->reference ? "&" : "",
				db_genMemberName(data->g, data->memberCache, m, member));
		data->count++;
	} else {
		db_serializeMembers(s, v, userData);
	}

	return 0;
}

static db_int16 cpp_onMemberCount(db_serializer s, db_value* v, void* userData) {
	DB_UNUSED(s);
	DB_UNUSED(v);
	(*(db_uint32*)userData)++;
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

struct db_serializer_s cpp_memberCountSerializer(void) {
	struct db_serializer_s result;
	db_serializerInit(&result);
	result.access = DB_LOCAL|DB_PRIVATE;
	result.accessKind = DB_NOT;
	result.traceKind = DB_SERIALIZER_TRACE_ON_FAIL;
	result.metaprogram[DB_MEMBER] = cpp_onMemberCount;
	return result;
}

/* Constructor */
void cpp_constructorDecl(db_generator g, g_file file, db_interface o, db_bool inlined) {
	db_id id;
	cpp_member_t walkData;
	struct db_serializer_s s;

	if (inlined) {
		g_fileWrite(file, "public: ");
	}

	if (!inlined) {
		g_fileWrite(file, "%s::", g_oid(g, o, id));
	}

	walkData.memberCache = db_genMemberCacheBuild(o);

	g_fileWrite(file, "%s(", g_oid(g, o, id));
	walkData.g = g;
	walkData.file = file;
	walkData.count = 0;
	s = cpp_memberSerializer();
	db_metaWalk(&s, db_type(o), &walkData);

	db_genMemberCacheClean(walkData.memberCache);

	g_fileWrite(file, ")");
}

/* Scoped constructor */
void cpp_constructorScopedDecl(db_generator g, g_file file, db_interface o, db_bool inlined) {
	db_id id;
	cpp_member_t walkData;
	struct db_serializer_s s;

	if (inlined) {
		g_fileWrite(file, "public: ");
	}

	if (!inlined) {
		g_fileWrite(file, "%s::", g_oid(g, o, id));
	}

	walkData.memberCache = db_genMemberCacheBuild(o);

	g_fileWrite(file, "%s(::cortex::lang::Object *_parent,\n", g_oid(g, o, id));
	g_fileWrite(file, "        ::cortex::lang::string _name");
	walkData.g = g;
	walkData.file = file;
	walkData.count = 2;
	s = cpp_memberSerializer();
	db_metaWalk(&s, db_type(o), &walkData);

	db_genMemberCacheClean(walkData.memberCache);

	g_fileWrite(file, ")");
}

/* Handle constructor */
void cpp_constructorHandleDecl(db_generator g, g_file file, db_interface o, db_bool inlined) {
	db_id id, lowId;

	if (inlined) {
		g_fileWrite(file, "public: ");
	}

	if (!inlined) {
		g_fileWrite(file, "%s::", g_oid(g, o, id));
	}

	if (!inlined) {
		g_fileWrite(file, "%s(%s handle, bool owner)", g_oid(g, o, id), g_fullOidExt(g, o, lowId, DB_GENERATOR_ID_CLASS_LOWER));
	} else {
		g_fileWrite(file, "%s(%s handle, bool owner = TRUE)", g_oid(g, o, id), g_fullOidExt(g, o, lowId, DB_GENERATOR_ID_CLASS_LOWER));
	}
}

/* Get handle */
void cpp_handleGetDecl(db_generator g, g_file file, db_interface o, db_bool inlined) {
    db_id id, lowId;

    if (inlined) {
        g_fileWrite(file, "public: ");
    }

    g_fileWrite(file, "%s ", g_fullOidExt(g, o, lowId, DB_GENERATOR_ID_CLASS_LOWER));

    if (!inlined) {
        g_fileWrite(file, "%s::", g_oid(g, o, id));
    }

    g_fileWrite(file, "_handle() const");
}

/* Getter declaration */
void cpp_memberGetter(db_generator g, g_file file, db_member o, db_bool inlined) {
	db_id typeId, memberId;

	if (inlined) {
	    g_fileWrite(file, "public: ");
	}
	g_fileWrite(file, "%s ",
	        cpp_specifierId(g, db_member(o)->type, typeId));

	if (!inlined) {
		db_id id;
		g_fileWrite(file, "%s::",
				g_oid(g, db_parentof(o), id));
	}
	g_fileWrite(file, "%s() const",
			g_id(g, db_nameof(o), memberId));
}

/* Setter declaration */
void cpp_memberSetter(db_generator g, g_file file, db_member o, db_bool inlined) {
	db_id typeId, memberId;

	if (inlined) {
		g_fileWrite(file, "public: ");
	}
	g_fileWrite(file, "void ");

	if (!inlined) {
		db_id id;
		g_fileWrite(file, "%s::",
				g_oid(g, db_parentof(o), id));
	}
	g_fileWrite(file, "%s(%s %s ",
			g_id(g, db_nameof(o), memberId),
			o->type->real->reference ? "const" : "",
			cpp_specifierId(g, db_member(o)->type, typeId));

	if (o->type->real->reference) {
		g_fileWrite(file, "&");
	}

	g_fileWrite(file, "v) const");
}

/* Walk scope of a class, process members and\or methods. */
static int cpp_scopeWalk(db_object o, void* userData) {
	cpp_scopeWalk_t* data;
	data = userData;

	/* Check if o is a member */
	if (db_class_instanceof(db_member_o, o)) {
		if (data->members) {
			db_id typeId;
			g_fileWrite(data->file, "\n");
			g_fileWrite(data->file, "// %s %s\n", db_fullname(db_member(o)->type, typeId), db_nameof(o));

			/* Getter */
			cpp_memberGetter(data->g, data->file, o, TRUE);
			g_fileWrite(data->file, ";\n");

			/* Setter */
			cpp_memberSetter(data->g, data->file, o, TRUE);
			g_fileWrite(data->file, ";\n");
		}

	}/* Else, check if o is a procedure */
	else if (db_class_instanceof(db_procedure_o, db_typeof(o)) && (db_procedure(db_typeof(o))->kind != DB_METAPROCEDURE)) {
		if (data->methods) {
			if (!(db_checkState(o, DB_DEFINED) && db_procedure(db_typeof(o))->kind == DB_CALLBACK)) {
				g_fileWrite(data->file, "\n");
				g_fileWrite(data->file, "// %s\n", db_nameof(o));
				cpp_functionDecl(data->g, data->file, db_function(o), TRUE);
				g_fileWrite(data->file, ";\n");

				if (db_instanceof(db_typedef(db_method_o), o)) {
					if (db_method(o)->virtual) {
						/* Generate extra header for virtual method implementation */
						cpp_functionDeclExt(data->g, data->file, db_function(o), TRUE, TRUE);
						g_fileWrite(data->file, ";\n");
					}
				}
			}
		}
	}

	return 1;
}

/* Process a class */
static int cpp_class(db_interface class, db_generator g) {
    g_file file;
    db_id id;
    cpp_scopeWalk_t walkData;
    db_string snippet;

    /* Create file */
    file = cpp_headerOpen(class, g);

    /* If a header exists, write it (before opening scope) */
     if ((snippet = g_fileLookupSnippet(file, "$header"))) {
         g_fileWrite(file, "/* $begin($header)");
         g_fileWrite(file, "%s", snippet);
         g_fileWrite(file, "$end */\n");
         g_fileWrite(file, "\n");
     }

    /* Open module */
    cpp_openScope(file, db_parentof(class));

    /* Write class-definintion */
    g_fileWrite(file, "class %s", g_oid(g, class, id));
    if (db_class_instanceof(db_struct_o, class)) {
        if (db_interface(class)->base) {
            db_id base;
            g_fileWrite(file, " : public %s",
                    g_fullOid(g, db_interface(class)->base, base));
        } else {
       		g_fileWrite(file, " : public ::cortex::lang::Object");
        }
    } else {
   		g_fileWrite(file, " : public ::cortex::lang::Object");
    }

    /*if (db_class_instanceof(db_class_o, class)) {
        db_uint32 i;
    	db_interface abstract;
    	for(i=0; i<db_class(class)->implements.length; i++) {
    		abstract = db_class(class)->implements.buffer[i];
    		g_fileWrite(file, ", public %s", g_fullOid(g, abstract, id));
    	}
    }*/

	/* Allow users to add inheritance relations to generated classes. */
	if ((snippet = g_fileLookupSnippet(file, "$classinherits"))) {
		g_fileWrite(file, "/* $begin($classinherits)");
		g_fileWrite(file, "%s", snippet);
		g_fileWrite(file, "$end */\n");
	}

    g_fileWrite(file, " {\n");
    g_fileIndent(file);

    /* If a classheader exists, write it (before opening scope) */
     if ((snippet = g_fileLookupSnippet(file, "$classheader"))) {
         g_fileWrite(file, "/* $begin($classheader)");
         g_fileWrite(file, "%s", snippet);
         g_fileWrite(file, "$end */\n");
     }

    /* Constructor (new,define) */
	g_fileWrite(file, "\n");
	g_fileWrite(file, "// Constructor (new,define)\n");
	cpp_constructorDecl(g, file, class, TRUE);
	g_fileWrite(file, ";\n");

	/* Scoped constructor (declare,define) */
	g_fileWrite(file, "\n");
	g_fileWrite(file, "// Scoped constructor (declare,define)\n");
	cpp_constructorScopedDecl(g, file, class, TRUE);
	g_fileWrite(file, ";\n");

	/* Handle constructor */
	g_fileWrite(file, "\n");
	g_fileWrite(file, "// Handle constructor\n");
	cpp_constructorHandleDecl(g, file, class, TRUE);
	g_fileWrite(file, ";\n");

	/* Return typed handle to database object */
	g_fileWrite(file, "\n");
	g_fileWrite(file, "// Obtain handle\n");
	cpp_handleGetDecl(g, file, class, TRUE);
	g_fileWrite(file, ";\n");

    /* Walk scope of class */
    walkData.g = g;
    walkData.file = file;
    walkData.members = TRUE;
    walkData.methods = FALSE;
    db_scopeWalk(class, cpp_scopeWalk, &walkData);

    walkData.members = FALSE;
    walkData.methods = TRUE;
    db_scopeWalk(class, cpp_scopeWalk, &walkData);

	/* Allow users to add extra operations to class-implementations. */
	if ((snippet = g_fileLookupSnippet(file, "$classfooter"))) {
		g_fileWrite(file, "/* $begin($classfooter)");
		g_fileWrite(file, "%s", snippet);
		g_fileWrite(file, "$end */\n");
	}

    g_fileDedent(file);

    g_fileWrite(file, "};\n");

    cpp_closeScope(file);

    /* Close file */
    cpp_headerClose(class, file);

    return 0;
}

static int cpp_scope(db_object o, db_generator g) {
    g_file file;
    cpp_scopeWalk_t walkData;
    db_string snippet;

    /* Create file */
    file = cpp_headerOpen(o, g);

    /* If a header exists, write it (before opening scope) */
     if ((snippet = g_fileLookupSnippet(file, "$header"))) {
         g_fileWrite(file, "/* $begin($header)");
         g_fileWrite(file, "%s", snippet);
         g_fileWrite(file, "$end */\n");
         g_fileWrite(file, "\n");
     }

    /* Open module */
    cpp_openScope(file, o);

    /* Walk procedures of scope */
    walkData.g = g;
    walkData.file = file;
    walkData.methods = TRUE;
    walkData.members = FALSE;
    if (!db_scopeWalk(o, cpp_scopeWalk, &walkData)) {
    	goto error;
    }

    cpp_closeScope(file);

    cpp_headerClose(o, file);

    return 0;
error:
	return -1;
}

/* Check if there are procedures in the scope of an object. */
static int cpp_checkProcedures(void* o, void* udata) {
    DB_UNUSED(udata);

    /* If the type of the type of the object is a procedure, return 0. */
    if (db_class_instanceof(db_procedure_o, db_typeof(o)->real)) {
        if (db_procedure(db_typeof(o))->kind != DB_CALLBACK) {
            return 0;
        }
    }
    return 1;
}

/* Walk classes */
static int cpp_implWalk(db_object o, void* userData) {

    if (db_class_instanceof(db_interface_o, o) && db_type(o)->reference) {
        if (cpp_class(db_interface(o), userData)) {
            goto error;
        }
       	cpp_impl(o, userData);
    } else if (!db_scopeWalk(o, cpp_checkProcedures, NULL) && (o != db_object_o)) {
    	if (cpp_scope(o, userData)) {
    		goto error;
    	}
    	cpp_impl(o, userData);
    }

    return 1;
error:
    return 0;
}

/* Generator main */
db_int16 cortex_genMain(db_generator g) {

	g_setIdKind(g, DB_GENERATOR_ID_CLASS_UPPER);

    /* Walk classes */
    if (!g_walkRecursive(g, cpp_implWalk, g)) {
        goto error;
    }

    return 0;
error:
    return -1;
}
