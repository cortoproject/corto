/*
 * cpp_class.c
 *
 *  Created on: Dec 21, 2012
 *      Author: sander
 */

#include "cortex.h"
#include "cx_generator.h"
#include "cpp_common.h"
#include "cpp_impl.h"
#include "cx_serializer.h"

static cx_string cpp_escapeName(cx_string fullname, cx_id escaped) {
    cx_char *ptr, *bptr, ch;

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

static int cpp_headerWalk(cx_object o, void* userData) {
	/* Add types of parameters and returntypes to list */
	if (cx_class_instanceof(cx_procedure_o, cx_typeof(o))) {
		cx_uint32 i;
		cx_parameter *p;
		for(i=0; i<cx_function(o)->parameters.length; i++) {
			p = &cx_function(o)->parameters.buffer[i];
			if (!cx_llHasObject(userData, p->type) && (cx_class_instanceof(cx_interface_o, p->type) && p->type->real->reference)) {
				cx_llInsert(userData, p->type);
			}
		}
		if (!cx_llHasObject(userData, cx_function(o)->returnType) && (cx_class_instanceof(cx_interface_o, cx_function(o)->returnType) && cx_function(o)->returnType->real->reference)) {
			cx_llInsert(userData, cx_function(o)->returnType);
		}
	}
	return 1;
}

static g_file cpp_headerOpen(cx_interface o, cx_generator g) {
    g_file result;
    cx_id fullname, path, id;
    cx_id escaped, headerFileName;
    cx_ll headers;

    headers = cx_llNew();

    /* Get filename */
    cx_fullname(o, fullname);
    cpp_escapeName(fullname, escaped);
    cpp_topath(g_getCurrent(g), path);

    if (strlen(path)) {
    	sprintf(headerFileName, "include/%s/%s.hpp", path, g_oid(g, o, id));
    } else {
    	sprintf(headerFileName, "include/%s.hpp", g_oid(g, o, id));
    }

    result = g_fileOpen(g, headerFileName);
    if (!result) {
        cx_error("failed to open file '%s'", headerFileName);
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
        if (cx_class_instanceof(cx_struct_o, o)) {
            if (cx_interface(o)->base) {
            	cx_llAppend(headers, cx_interface(o)->base);
            } else {
                g_fileWrite(result, "#include \"cortex/lang/Object.hpp\"\n");
            }
        }

        /* Include implemented interfaces */
        if (cx_class_instanceof(cx_class_o, o)) {
        	cx_uint32 i;
        	cx_interface abstract;
        	for(i=0; i<cx_class(o)->implements.length; i++) {\
        		abstract = cx_class(o)->implements.buffer[i];
				cx_llAppend(headers, abstract);
        	}
        }

        /* Print headers */
        {
            cx_iter includeIter;
            includeIter = cx_llIter(headers);
            while(cx_iterHasNext(&includeIter)) {
                cx_object include = cx_iterNext(&includeIter);

                if (include != o) {
                    cpp_topath(cx_parentof(include), path);
                    g_fileWrite(result, "#include \"%s/%s.hpp\"\n", path, g_oid(g, include, id));
                }
            }
        }

        /* Print forward declarations for classes from parameters and returnTypes */
        cx_llFree(headers); headers = cx_llNew();
        cx_scopeWalk(o, cpp_headerWalk, headers);
        {
            cx_iter fwdIter;
            fwdIter = cx_llIter(headers);
            while(cx_iterHasNext(&fwdIter)) {
                cx_object fwd = cx_iterNext(&fwdIter);

                if (fwd != o) {
                    cpp_openScope(result, fwd);
                    g_fileWrite(result, "class %s;\n", g_oid(g, fwd, id));
                }
            }
        }
        cpp_closeScope(result);

        cx_llFree(headers);
        g_fileWrite(result, "\n");
    }

    return result;
}

static void cpp_headerClose(cx_interface class, g_file file) {
    DB_UNUSED(class);
    g_fileWrite(file, "\n");
    g_fileWrite(file, "#endif\n\n");
}

typedef struct cpp_scopeWalk_t {
	cx_generator g;
	g_file file;
	cx_bool methods;
	cx_bool members;
}cpp_scopeWalk_t;

/* Function declaration */
void cpp_functionDeclExt(cx_generator g, g_file file, cx_function o, cx_bool inlined, cx_bool virtualStub) {
	cx_id oid, id;
	cx_uint32 i;
	cx_bool callback;
	cx_parameter* p;

	callback = FALSE;

	if (inlined) {
		g_fileWrite(file, "public: ");
	}

	/* Callback functions are static as well as non-member functions in a class-scope */
	if ((cx_procedure(cx_typeof(o))->kind == DB_FUNCTION) || (cx_procedure(cx_typeof(o))->kind == DB_CALLBACK)) {
		if (inlined) {
			if (cx_class_instanceof(cx_interface_o, cx_typeof(cx_parentof(o)))) {
				g_fileWrite(file, "static ");
			}
		}
		callback = TRUE;
	}

	/* Function return-types are always return by value, including classes */
	g_fileWrite(file, "%s ", g_fullOid(g, cx_function(o)->returnType, oid));

	if (!inlined && cx_class_instanceof(cx_interface_o, cx_parentof(o))) {
		g_fileWrite(file, "%s::", g_oid(g, cx_parentof(o), id));
	}

	if (!virtualStub) {
		g_fileWrite(file, "%s(", cpp_procId(g, o, id));
	} else {
		g_fileWrite(file, "%s_v(", cpp_procId(g, o, id));
	}

	for(i=0; i<cx_function(o)->parameters.length; i++) {
	    cx_id specifier;

		if (i) {
			g_fileWrite(file, ", ");
		}
		p = &cx_function(o)->parameters.buffer[i];

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
void cpp_functionDecl(cx_generator g, g_file file, cx_function o, cx_bool inlined) {
	cpp_functionDeclExt(g, file, o, inlined, FALSE);
}

typedef struct cpp_member_t {
	cx_generator g;
	g_file file;
	cx_uint32 count;
	cx_ll memberCache;
}cpp_member_t;

static cx_int16 cpp_onMember(cx_serializer s, cx_value* v, void* userData) {
	cx_member m;
	cpp_member_t* data;

	data = userData;
	DB_UNUSED(s);

	/* Get member */
	if (v->kind == DB_MEMBER) {
		cx_id spec, member;
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
				cx_genMemberName(data->g, data->memberCache, m, member));
		data->count++;
	} else {
		cx_serializeMembers(s, v, userData);
	}

	return 0;
}

static cx_int16 cpp_onMemberCount(cx_serializer s, cx_value* v, void* userData) {
	DB_UNUSED(s);
	DB_UNUSED(v);
	(*(cx_uint32*)userData)++;
	return 0;
}

static struct cx_serializer_s cpp_memberSerializer(void) {
	struct cx_serializer_s result;
	cx_serializerInit(&result);
	result.access = DB_LOCAL|DB_PRIVATE;
	result.accessKind = DB_NOT;
	result.traceKind = DB_SERIALIZER_TRACE_ON_FAIL;
	result.metaprogram[DB_MEMBER] = cpp_onMember;
	return result;
}

struct cx_serializer_s cpp_memberCountSerializer(void) {
	struct cx_serializer_s result;
	cx_serializerInit(&result);
	result.access = DB_LOCAL|DB_PRIVATE;
	result.accessKind = DB_NOT;
	result.traceKind = DB_SERIALIZER_TRACE_ON_FAIL;
	result.metaprogram[DB_MEMBER] = cpp_onMemberCount;
	return result;
}

/* Constructor */
void cpp_constructorDecl(cx_generator g, g_file file, cx_interface o, cx_bool inlined) {
	cx_id id;
	cpp_member_t walkData;
	struct cx_serializer_s s;

	if (inlined) {
		g_fileWrite(file, "public: ");
	}

	if (!inlined) {
		g_fileWrite(file, "%s::", g_oid(g, o, id));
	}

	walkData.memberCache = cx_genMemberCacheBuild(o);

	g_fileWrite(file, "%s(", g_oid(g, o, id));
	walkData.g = g;
	walkData.file = file;
	walkData.count = 0;
	s = cpp_memberSerializer();
	cx_metaWalk(&s, cx_type(o), &walkData);

	cx_genMemberCacheClean(walkData.memberCache);

	g_fileWrite(file, ")");
}

/* Scoped constructor */
void cpp_constructorScopedDecl(cx_generator g, g_file file, cx_interface o, cx_bool inlined) {
	cx_id id;
	cpp_member_t walkData;
	struct cx_serializer_s s;

	if (inlined) {
		g_fileWrite(file, "public: ");
	}

	if (!inlined) {
		g_fileWrite(file, "%s::", g_oid(g, o, id));
	}

	walkData.memberCache = cx_genMemberCacheBuild(o);

	g_fileWrite(file, "%s(::cortex::lang::Object *_parent,\n", g_oid(g, o, id));
	g_fileWrite(file, "        ::cortex::lang::string _name");
	walkData.g = g;
	walkData.file = file;
	walkData.count = 2;
	s = cpp_memberSerializer();
	cx_metaWalk(&s, cx_type(o), &walkData);

	cx_genMemberCacheClean(walkData.memberCache);

	g_fileWrite(file, ")");
}

/* Handle constructor */
void cpp_constructorHandleDecl(cx_generator g, g_file file, cx_interface o, cx_bool inlined) {
	cx_id id, lowId;

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
void cpp_handleGetDecl(cx_generator g, g_file file, cx_interface o, cx_bool inlined) {
    cx_id id, lowId;

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
void cpp_memberGetter(cx_generator g, g_file file, cx_member o, cx_bool inlined) {
	cx_id typeId, memberId;

	if (inlined) {
	    g_fileWrite(file, "public: ");
	}
	g_fileWrite(file, "%s ",
	        cpp_specifierId(g, cx_member(o)->type, typeId));

	if (!inlined) {
		cx_id id;
		g_fileWrite(file, "%s::",
				g_oid(g, cx_parentof(o), id));
	}
	g_fileWrite(file, "%s() const",
			g_id(g, cx_nameof(o), memberId));
}

/* Setter declaration */
void cpp_memberSetter(cx_generator g, g_file file, cx_member o, cx_bool inlined) {
	cx_id typeId, memberId;

	if (inlined) {
		g_fileWrite(file, "public: ");
	}
	g_fileWrite(file, "void ");

	if (!inlined) {
		cx_id id;
		g_fileWrite(file, "%s::",
				g_oid(g, cx_parentof(o), id));
	}
	g_fileWrite(file, "%s(%s %s ",
			g_id(g, cx_nameof(o), memberId),
			o->type->real->reference ? "const" : "",
			cpp_specifierId(g, cx_member(o)->type, typeId));

	if (o->type->real->reference) {
		g_fileWrite(file, "&");
	}

	g_fileWrite(file, "v) const");
}

/* Walk scope of a class, process members and\or methods. */
static int cpp_scopeWalk(cx_object o, void* userData) {
	cpp_scopeWalk_t* data;
	data = userData;

	/* Check if o is a member */
	if (cx_class_instanceof(cx_member_o, o)) {
		if (data->members) {
			cx_id typeId;
			g_fileWrite(data->file, "\n");
			g_fileWrite(data->file, "// %s %s\n", cx_fullname(cx_member(o)->type, typeId), cx_nameof(o));

			/* Getter */
			cpp_memberGetter(data->g, data->file, o, TRUE);
			g_fileWrite(data->file, ";\n");

			/* Setter */
			cpp_memberSetter(data->g, data->file, o, TRUE);
			g_fileWrite(data->file, ";\n");
		}

	}/* Else, check if o is a procedure */
	else if (cx_class_instanceof(cx_procedure_o, cx_typeof(o)) && (cx_procedure(cx_typeof(o))->kind != DB_METAPROCEDURE)) {
		if (data->methods) {
			if (!(cx_checkState(o, DB_DEFINED) && cx_procedure(cx_typeof(o))->kind == DB_CALLBACK)) {
				g_fileWrite(data->file, "\n");
				g_fileWrite(data->file, "// %s\n", cx_nameof(o));
				cpp_functionDecl(data->g, data->file, cx_function(o), TRUE);
				g_fileWrite(data->file, ";\n");

				if (cx_instanceof(cx_typedef(cx_method_o), o)) {
					if (cx_method(o)->virtual) {
						/* Generate extra header for virtual method implementation */
						cpp_functionDeclExt(data->g, data->file, cx_function(o), TRUE, TRUE);
						g_fileWrite(data->file, ";\n");
					}
				}
			}
		}
	}

	return 1;
}

/* Process a class */
static int cpp_class(cx_interface class, cx_generator g) {
    g_file file;
    cx_id id;
    cpp_scopeWalk_t walkData;
    cx_string snippet;

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
    cpp_openScope(file, cx_parentof(class));

    /* Write class-definintion */
    g_fileWrite(file, "class %s", g_oid(g, class, id));
    if (cx_class_instanceof(cx_struct_o, class)) {
        if (cx_interface(class)->base) {
            cx_id base;
            g_fileWrite(file, " : public %s",
                    g_fullOid(g, cx_interface(class)->base, base));
        } else {
       		g_fileWrite(file, " : public ::cortex::lang::Object");
        }
    } else {
   		g_fileWrite(file, " : public ::cortex::lang::Object");
    }

    /*if (cx_class_instanceof(cx_class_o, class)) {
        cx_uint32 i;
    	cx_interface abstract;
    	for(i=0; i<cx_class(class)->implements.length; i++) {
    		abstract = cx_class(class)->implements.buffer[i];
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
    cx_scopeWalk(class, cpp_scopeWalk, &walkData);

    walkData.members = FALSE;
    walkData.methods = TRUE;
    cx_scopeWalk(class, cpp_scopeWalk, &walkData);

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

static int cpp_scope(cx_object o, cx_generator g) {
    g_file file;
    cpp_scopeWalk_t walkData;
    cx_string snippet;

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
    if (!cx_scopeWalk(o, cpp_scopeWalk, &walkData)) {
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
    if (cx_class_instanceof(cx_procedure_o, cx_typeof(o)->real)) {
        if (cx_procedure(cx_typeof(o))->kind != DB_CALLBACK) {
            return 0;
        }
    }
    return 1;
}

/* Walk classes */
static int cpp_implWalk(cx_object o, void* userData) {

    if (cx_class_instanceof(cx_interface_o, o) && cx_type(o)->reference) {
        if (cpp_class(cx_interface(o), userData)) {
            goto error;
        }
       	cpp_impl(o, userData);
    } else if (!cx_scopeWalk(o, cpp_checkProcedures, NULL) && (o != cx_object_o)) {
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
cx_int16 cortex_genMain(cx_generator g) {

	g_setIdKind(g, DB_GENERATOR_ID_CLASS_UPPER);

    /* Walk classes */
    if (!g_walkRecursive(g, cpp_implWalk, g)) {
        goto error;
    }

    return 0;
error:
    return -1;
}
