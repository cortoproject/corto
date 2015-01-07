/*
 * cpp_impl.c
 *
 *  Created on: Dec 27, 2012
 *      Author: sander
 */

#include "cpp_impl.h"
#include "cpp_common.h"

typedef struct cpp_implWalk_t {
    cx_generator g;
    g_file file;
    cx_uint16 firstComma;
} cpp_implWalk_t;

static void cpp_implStub(cx_function o, cx_string metaFunction, cpp_implWalk_t* data) {
    cx_uint32 i;
    cx_id id;
    cx_parameter* p;
    cx_typedef returnType;

    /* Returnvalue */
    returnType = o->returnType;
    if ((returnType->real->kind != CX_VOID) || (returnType->real->reference)) {
        cx_id specifier;
        g_setIdKind(data->g, CX_GENERATOR_ID_CLASS_LOWER);
        cpp_specifierId(data->g, returnType, specifier);
        g_fileWrite(data->file, "%s _result;\n", specifier);
        g_setIdKind(data->g, CX_GENERATOR_ID_CLASS_UPPER);
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
    if (cx_class_instanceof(cx_interface_o, cx_parentof(o))) {
        if (cx_procedure(cx_typeof(o))->kind != CX_FUNCTION) {
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
        if (cx_class_instanceof(cx_interface_o, returnType)) {
            if (cx_class_instanceof(cx_interface_o, returnType)) {
                cx_id specifier;
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
static int cpp_implVirtual(cx_method o, cpp_implWalk_t *data) {
    cx_id id;

    g_fileWrite(data->file, "\n");
    g_fileWrite(data->file, "/* virtual %s */\n", cx_fullname(o, id));

    cpp_functionDecl(data->g, data->file, cx_function(o), FALSE);

    g_fileWrite(data->file, " {\n");
    g_fileIndent(data->file);
    g_fileWrite(data->file, "cortex::lang::Class _type((cortex::lang::_class)this->_typeof()._handle());\n");
    g_fileWrite(data->file, "static cortex::lang::uint32 _actualMethodId;\n");
    g_fileWrite(data->file, "\n");
    g_fileWrite(data->file, "if (!_actualMethodId) {\n");
    g_fileIndent(data->file);
    g_fileWrite(data->file, "_actualMethodId = _type.resolveMethodId((cortex::lang::string)\"%s\");\n", cx_nameof(o));
    g_fileDedent(data->file);
    g_fileWrite(data->file, "}\n");
    g_fileWrite(data->file, "cortex::lang::Method _actualMethod = _type.resolveMethodById(_actualMethodId);\n");

    /* Insert stub code */
    cpp_implStub(cx_function(o), "(cortex::lang::function)_actualMethod._handle()", data);

    g_fileDedent(data->file);
    g_fileWrite(data->file, "}\n");

    return 1;
}

/* Generate methods for class */
static int c_implProcedure(cx_object o, void* userData) {
    cpp_implWalk_t* data;
    cx_bool defined;
    cx_bool isVirtual = FALSE;

    data = userData;

    /* Only generate code for procedures */
    if (cx_class_instanceof(cx_procedure_o, cx_typeof(o)) && (cx_procedure(cx_typeof(o))->kind != CX_METAPROCEDURE)) { /* TODO: Metaprocedures are not yet mapped to C++ */
        defined = cx_checkState(o, CX_DEFINED) && (cx_function(o)->kind != CX_PROCEDURE_STUB);

        /* Do not generate code for defined callbacks - these will never be called
         * directly, so generating a stub for them makes no sense. */
        if (!((cx_procedure(cx_typeof(o))->kind == CX_CALLBACK) && defined)) {
            cx_string snippet;
            cx_id id;
            cx_bool isMethod = cx_instanceof(cx_typedef(cx_method_o), o);

            g_fileWrite(data->file, "\n");
            g_fileWrite(data->file, "/* %s */\n", cx_fullname(o, id));

            if (isMethod) {
                isVirtual = cx_method(o)->virtual;
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
                g_fileWrite(data->file, "/* $begin(%s)", cx_fullname(o, id));
                g_fileIndent(data->file);

                /* Look for existing code-snippets */
                snippet = g_fileLookupSnippet(data->file, id);
                if (!snippet && !cx_function(o)->overloaded) {
                    cx_char* ptr;
                    ptr = strchr(id, '(');
                    if (ptr) {
                        *ptr = '\0';
                        /* Non-overloaded functions may have snippets without argumentlists */
                        snippet = g_fileLookupSnippet(data->file, id);
                    } else {
                        if (cx_procedure(cx_typeof(o))->kind != CX_OBSERVER) {
                            cx_warning("function '%s' has no argumentlist.", cx_nameof(o));
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
        cpp_implVirtual(cx_method(o), data);
    }

    return 1;
}

typedef struct cpp_member_t {
    cx_generator g;
    g_file file;
}cpp_member_t;

static cx_int16 cpp_onMember(cx_serializer s, cx_value* v, void* userData) {
    cx_member m;
    cpp_member_t* data;
    cx_id id;

    data = userData;
    CX_UNUSED(s);

    /* Get member */
    if (v->kind == CX_MEMBER) {
        m = v->is.member.t;
        g_fileWrite(data->file, "this->%s(%s);\n",
                g_id(data->g, cx_nameof(m), id),
                id);
    } else {
        cx_serializeMembers(s, v, userData);
    }

    return 0;
}

static struct cx_serializer_s cpp_memberSerializer(void) {
    struct cx_serializer_s result;
    cx_serializerInit(&result);
    result.access = CX_LOCAL|CX_PRIVATE;
    result.accessKind = CX_NOT;
    result.traceKind = CX_SERIALIZER_TRACE_ON_FAIL;
    result.metaprogram[CX_MEMBER] = cpp_onMember;
    return result;
}

static void cpp_implConstructor(cx_generator g, g_file file, cx_interface o) {
    struct cx_serializer_s s;
    cpp_member_t walkData;
    cx_object base;
    cx_id id, id2;

    if (cx_class_instanceof(cx_struct_o, o)) {
        base = cx_interface(o)->base;
        if (!base) {
            base = cx_object_o;
        }
    } else {
        base = NULL;
    }

    s = cpp_memberSerializer();

    g_fileWrite(file, "\n");
    g_fileWrite(file, "// Constructor\n");
    cpp_constructorDecl(g, file, o, FALSE);
    if (base) {
        g_fileWrite(file, " : %s((%s)NULL)", g_fullOid(g, base, id), g_fullOidExt(g, base, id2, CX_GENERATOR_ID_CLASS_LOWER));
    }
    g_fileWrite(file, " {\n");
    g_fileIndent(file);

    /* Create object */
    g_fileWrite(file, "this->__handle = ::cortex::_new((::cortex::lang::_typedef)%s);\n",
            cpp_metaFullname(g, o, CPP_HANDLE, id));

    walkData.g = g;
    walkData.file = file;
    cx_metaWalk(&s, cx_type(o), &walkData);

    /* Define object */
    g_fileWrite(file, "this->define();\n");

    g_fileDedent(file);
    g_fileWrite(file, "}\n");
}

static void cpp_implConstructorScoped(cx_generator g, g_file file, cx_interface o) {
    struct cx_serializer_s s;
    cpp_member_t walkData;
    cx_object base;
    cx_id id, id2;

    if (cx_class_instanceof(cx_struct_o, o)) {
        base = cx_interface(o)->base;
        if (!base) {
            base = cx_object_o;
        }
    } else {
        base = NULL;
    }

    s = cpp_memberSerializer();

    g_fileWrite(file, "\n");
    g_fileWrite(file, "// Constructor (declare & define)\n");
    cpp_constructorScopedDecl(g, file, o, FALSE);
    if (base) {
        g_fileWrite(file, " : %s((%s)NULL)", g_fullOid(g, base, id), g_fullOidExt(g, base, id2, CX_GENERATOR_ID_CLASS_LOWER));
    }
    g_fileWrite(file, " {\n");
    g_fileIndent(file);

    /* Create object */
    g_fileWrite(file, "this->__handle = ::cortex::declare(_parent->_handle(), _name, (::cortex::lang::_typedef)%s);\n",
            cpp_metaFullname(g, o, CPP_HANDLE, id));

    walkData.g = g;
    walkData.file = file;
    cx_metaWalk(&s, cx_type(o), &walkData);

    /* Define object */
    g_fileWrite(file, "this->define();\n");

    g_fileDedent(file);
    g_fileWrite(file, "}\n");
}

static void cpp_implConstructorHandle(cx_generator g, g_file file, cx_interface o) {
    cx_object base;
    cx_id id, id2;

    if (cx_class_instanceof(cx_struct_o, o)) {
        base = cx_interface(o)->base;
        if (!base) {
            base = cx_object_o;
        }
    } else {
        if (cx_class_instanceof(cx_interface_o, o)) {
            base = cx_object_o;
        } else {
            base = NULL;
        }
    }

    g_fileWrite(file, "\n");
    g_fileWrite(file, "// Construct from handle\n");
    cpp_constructorHandleDecl(g, file, o, FALSE);
    if (base) {
        g_fileWrite(file, " : %s((%s)handle, owner)", g_fullOid(g, base, id), g_fullOidExt(g, base, id2, CX_GENERATOR_ID_CLASS_LOWER));
    }
    g_fileWrite(file, " {\n");
    g_fileIndent(file);
    g_fileWrite(file, "// Handle is set and keep'd by Object::Object(object handle)\n");
    g_fileDedent(file);
    g_fileWrite(file, "}\n");
}

static void cpp_implHandleGet(cx_generator g, g_file file, cx_interface o) {
    cx_id id;

    g_fileWrite(file, "\n");
    g_fileWrite(file, "// Get handle\n");
    cpp_handleGetDecl(g, file, o, FALSE);
    g_fileWrite(file, " {\n");
    g_fileIndent(file);

    /* Create object */
    g_fileWrite(file, "return (%s)this->__handle;\n", g_fullOidExt(g, o, id, CX_GENERATOR_ID_CLASS_LOWER));

    g_fileDedent(file);
    g_fileWrite(file, "}\n");
}

static void cpp_implGetter(cx_generator g, g_file file, cx_member m) {
    cx_id id, memberId, refId;

    /* Getter declaration */
    cpp_memberGetter(g, file, m, FALSE);
    g_fileWrite(file, " {\n");
    g_fileIndent(file);

    /* Return value */
    if (!m->type->real->reference) {
        g_fileWrite(file, "return ((%s)this->__handle)->%s;\n",
                g_fullOidExt(g, cx_parentof(m), id, CX_GENERATOR_ID_CLASS_LOWER),
                g_id(g, cx_nameof(m), memberId));
    } else {
        g_fileWrite(file, "%s result(((%s)this->__handle)->%s);\n",
                g_fullOid(g, m->type, refId),
                g_fullOidExt(g, cx_parentof(m), id, CX_GENERATOR_ID_CLASS_LOWER),
                g_id(g, cx_nameof(m), memberId));
        g_fileWrite(file, "return result;\n");
    }

    g_fileDedent(file);
    g_fileWrite(file, "}\n");
}

static void cpp_implSetter(cx_generator g, g_file file, cx_member m) {
    cx_id id, memberId;

    /* Getter declaration */
    cpp_memberSetter(g, file, m, FALSE);
    g_fileWrite(file, " {\n");
    g_fileIndent(file);

    /* Set value */
    if (!m->type->real->reference) {
        if ((m->type->real->kind == CX_PRIMITIVE) && (cx_primitive(m->type->real)->kind == CX_TEXT)) {
            g_fileWrite(file, "if (((%s)this->__handle)->%s) {\n",
                    g_fullOidExt(g, cx_parentof(m), id, CX_GENERATOR_ID_CLASS_LOWER),
                    g_id(g, cx_nameof(m), memberId));
            g_fileIndent(file);
            g_fileWrite(file, "cortex::dealloc(((%s)this->__handle)->%s);\n",
                    g_fullOidExt(g, cx_parentof(m), id, CX_GENERATOR_ID_CLASS_LOWER),
                    g_id(g, cx_nameof(m), memberId));
            g_fileDedent(file);
            g_fileWrite(file, "};\n");
            g_fileWrite(file, "((%s)this->__handle)->%s = v ? cortex::strdup(v) : NULL;\n",
                    g_fullOidExt(g, cx_parentof(m), id, CX_GENERATOR_ID_CLASS_LOWER),
                    g_id(g, cx_nameof(m), memberId));
        } else {
            g_fileWrite(file, "((%s)this->__handle)->%s = v;\n",
                    g_fullOidExt(g, cx_parentof(m), id, CX_GENERATOR_ID_CLASS_LOWER),
                    g_id(g, cx_nameof(m), memberId));
        }
    } else {
        g_fileWrite(file, "if (v) {\n");
        g_fileIndent(file);
        g_fileWrite(file, "cortex::set((cortex::lang::object*)&((%s)this->__handle)->%s, v._handle());\n",
                g_fullOidExt(g, cx_parentof(m), id, CX_GENERATOR_ID_CLASS_LOWER),
                g_id(g, cx_nameof(m), memberId));
        g_fileDedent(file);
        g_fileWrite(file, "} else {\n");
        g_fileIndent(file);
        g_fileWrite(file, "cortex::set((cortex::lang::object*)&((%s)this->__handle)->%s, NULL);\n",
                        g_fullOidExt(g, cx_parentof(m), id, CX_GENERATOR_ID_CLASS_LOWER),
                        g_id(g, cx_nameof(m), memberId));
        g_fileDedent(file);
        g_fileWrite(file, "}\n");
    }

    g_fileDedent(file);
    g_fileWrite(file, "}\n");
}



/* Generate getters & setters */
static void cpp_implClass(cx_generator g, g_file file, cx_interface o) {
    cx_uint32 i;
    cx_member m;
    cx_id id;

    /* Constructors */
    cpp_implConstructor(g, file, o);
    cpp_implConstructorScoped(g, file, o);
    cpp_implConstructorHandle(g, file, o);
    cpp_implHandleGet(g, file, o);

    for(i=0; i<cx_interface(o)->members.length; i++) {
        m = cx_interface(o)->members.buffer[i];

        g_fileWrite(file, "\n");
        g_fileWrite(file, "// %s %s\n", cx_fullname(cx_member(m)->type, id), cx_nameof(m));
        cpp_implGetter(g, file, m);
        cpp_implSetter(g, file, m);
    }
}

/* Find all reference-types in members and procedures */
static int cpp_findReferences(cx_object o, void* userData) {
    if (cx_class_instanceof(cx_member_o, o)) {
        if (cx_member(o)->type->real->reference) {
            if (!cx_llHasObject(userData, cx_member(o)->type->real)) {
                cx_llInsert(userData, cx_member(o)->type->real);
            }
        }
    } else if (cx_class_instanceof(cx_procedure_o, cx_typeof(o))) {
        cx_uint32 i;
        cx_parameter* p;

        /* Check returnType */
        if (cx_function(o)->returnType->real->reference) {
            if (!cx_llHasObject(userData, cx_function(o)->returnType->real)) {
                cx_llInsert(userData, cx_function(o)->returnType->real);
            }
        }

        /* Walk parameters */
        for(i=0; i<cx_function(o)->parameters.length; i++) {
            p = &cx_function(o)->parameters.buffer[i];
            if (p->type->real->reference) {
                if (!cx_llHasObject(userData, p->type->real)) {
                    cx_llInsert(userData, p->type->real);
                }
            }
        }
    }
    return 1;
}

/* Collect class-headerfiles that must be included in sourcefile. */
static cx_ll cpp_findHeaders(cx_interface a) {
    cx_ll refs;
    refs = cx_llNew();
    cx_scopeWalk(a, cpp_findReferences, refs);
    return refs;
}

/* Print headers for used reference-types */
static void cpp_printHeaders(cx_generator g, g_file file, cx_interface a) {
    cx_ll refs;
    cx_iter iter;

    refs = cpp_findHeaders(a);
    iter = cx_llIter(refs);
    while(cx_iterHasNext(&iter)) {
        cx_id path, id;
        cx_object o;

        o = cx_iterNext(&iter);

        if (o != a) {
            cpp_topath(cx_parentof(o), path);
            g_fileWrite(file, "#include \"%s/%s.hpp\"\n", path, g_oid(g, o, id));
        }
    }
    cx_llFree(refs);
}

static g_file cpp_implOpen(cx_object o, cx_generator g) {
    g_file result;
    cx_id fullname, path, id;
    cx_id implFileName;

    /* Get filename */
    cx_fullname(o, fullname);
    cpp_topath(g_getCurrent(g), path);

    if (strlen(path)) {
        sprintf(implFileName, "src/%s/%s.cpp", path, g_oid(g, o, id));
    } else {
        sprintf(implFileName, "src/%s.cpp", g_oid(g, o, id));
    }

    result = g_fileOpen(g, implFileName);
    if (!result) {
        cx_error("failed to open file '%s'");
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
        if (cx_class_instanceof(cx_interface_o, o)) {
            cpp_printHeaders(g, result, o);
        }

        g_fileWrite(result, "\n");
    }

    return result;
}

static void cpp_implClose(cx_object o, g_file file) {
    CX_UNUSED(o);
    g_fileWrite(file, "\n");
}

int cpp_impl(cx_object o, cx_generator g) {
    cx_string snippet;
    g_file source;
    cpp_implWalk_t walkData;

    /* Open headerfile */
    source = cpp_implOpen(o, g);
    cx_assert(source != NULL, "failed to open source.");

   /* If a header exists, write it (before opening scope) */
    if ((snippet = g_fileLookupSnippet(source, "$header"))) {
        g_fileWrite(source, "/* $begin($header)");
        g_fileWrite(source, "%s", snippet);
        g_fileWrite(source, "$end */\n");
        g_fileWrite(source, "\n");
    }

    /* Open scope (do not open scope for classes and procedures) */
    if (cx_class_instanceof(cx_struct_o, o)) {
        cpp_openScope(source, cx_parentof(o));
    } else {
        cpp_openScope(source, o);
    }

    /* If object is a class (abstract), generate getters & setters */
    if (cx_class_instanceof(cx_interface_o, o)) {
        cpp_implClass(g, source, o);
    }

    /* Walk scope */
    walkData.file = source;
    walkData.g = g;
    if (!cx_scopeWalk(o, c_implProcedure, &walkData)) {
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
