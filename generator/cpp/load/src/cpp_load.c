/*
 * cpp_load.c
 *
 *  Created on: Sep 20, 2012
 *      Author: sander
 */

#include "cortex.h"
#include "cx_generatorDepWalk.h"
#include "cpp_common.h"
#include "cx_string_ser.h"

typedef struct cpp_typeWalk_t {
    cx_generator g;
    g_file header;
    g_file source;
    cx_uint32 firstComma;
} cpp_typeWalk_t;

/* Resolve object */
static cx_char* cpp_loadResolve(cx_object o, cx_char* out) {
    if (cx_checkAttr(o, CX_ATTR_SCOPED)) {
        cx_id id;
        sprintf(out, "::cortex::resolve(NULL, \"%s\")", cx_fullname(o, id));
    } else {
        cx_id ostr, id;
        struct cx_serializer_s stringSer;
        cx_string_ser_t data;

        /* Serialize object string */
        stringSer = cx_string_ser(CX_LOCAL, CX_NOT, CX_SERIALIZER_TRACE_ON_FAIL);

        *ostr = '\0';
        data.compactNotation = TRUE;
        data.buffer = ostr;
        data.length = sizeof(ostr);
        data.maxlength = 0;
        data.prefixType = FALSE;
        if (cx_serialize(&stringSer, o, &data)) {
            goto error;
        }

        sprintf(out, "::cortex::resolve(NULL, \"%s%s\")", cx_fullname(cx_typeof(o), id), ostr);
    }

    return out;
error:
    return NULL;
}

/* Get variable id */
static cx_char* cpp_loadVarId(cx_generator g, cx_object o, cx_char* out) {
    if (cx_checkAttr(o, CX_ATTR_SCOPED)) {
        cpp_metaFullname(g, o, CPP_HANDLE, out);
    } else {
        cx_id id;
        sprintf(out, "%s", cpp_loadResolve(o, id));
    }
    return out;
}

/* Get marshaller id (wrapper for member-functions) */
static cx_char* cpp_loadMarshallId(cx_generator g, cx_function o, cx_id id) {
    cx_char *ptr;

    ptr = id;
    strcpy(ptr, "__cpp_");
    ptr += 6;

    cpp_metaName(g, o, CPP_DEFAULT, ptr);

    return id;
}

/* Get element id, for lists and maps. */
static cx_char* cpp_loadElementId(cx_value* v, cx_char* out, cx_int32 offset) {
    cx_uint32 i;
    cx_value* ptr;

    i = 0;
    ptr = v;

    do {
        if (ptr->kind == CX_ELEMENT) {
            i++;
        }
    }while((ptr = ptr->parent));

    sprintf(out, "_e%d_", i + offset);

    return out;
}

/* This function translates from a value-object to a valid C-string identifying a
 * part of the object that is being serialized. */
static cx_char* cpp_loadMemberId(cpp_typeWalk_t* data, cx_value* v, cx_char* out, cx_bool addMemberOperator) {
    cx_value* stack[CX_MAX_TYPE_DEPTH];
    cx_uint32 count;
    cx_value *ptr;
    cx_object o;
    cx_typedef thisType;
    cx_bool objectIsArray, derefMemberOperator;

    *out = '\0';

    /* Build serializer-stack */
    ptr = v;
    count = 0;
    while((ptr->kind != CX_OBJECT) && (ptr->kind != CX_BASE)) {
        stack[count] = ptr;
        ptr = ptr->parent;
        count++;
    }
    stack[count] = ptr;

    /* Print object */
    o = cx_valueObject(v);

    /* If object is an array, dereference object, so the '[ ]' operator can be used on object. Same for primtives, primitive-objects are pointers to primitive values. */
    objectIsArray = (cx_typeof(o)->real->kind == CX_PRIMITIVE) || ((cx_typeof(o)->real->kind == CX_COLLECTION) && (cx_collection(cx_typeof(o)->real)->kind == CX_ARRAY));

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
    thisType = cx_valueType(ptr);
    if (cx_typedef(thisType) != cx_typeof(o)) {
        cx_id id, parentId, objectId;
        sprintf(id, "((%s)%s)",
                g_fullOid(data->g, thisType, parentId),
                cpp_loadVarId(data->g, cx_valueObject(v), objectId));
        strcat(out, id);
    } else {
        cx_id objectId;
        strcat(out, cpp_loadVarId(data->g, cx_valueObject(v), objectId));
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
        case CX_MEMBER: {
            cx_id id;
            /* When previous object is a reference, use -> operator. */
            if (derefMemberOperator) {
                strcat(out, "->");
                derefMemberOperator = FALSE;
            } else {
                strcat(out, ".");
            }

            /* Reference member using it's name. */
            strcat(out, g_id(data->g, cx_nameof(stack[count]->is.member.t), id));
            break;
        }

        /* Element */
        case CX_ELEMENT: {
            cx_collection t;
            cx_char arrayIndex[24];

            t = cx_collection(cx_valueType(stack[count+1])->real);

            switch(t->kind) {

            /* Array element, use array operator. */
            case CX_ARRAY:
                sprintf(arrayIndex, "[%d]", stack[count]->is.element.t.index);
                strcat(out, arrayIndex);
                break;

            /* Sequence element, use buffer-array */
            case CX_SEQUENCE:
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
                cx_char elementId[9]; /* One-million nested collections should be adequate in most cases. */

                if ((cx_valueType(stack[count])->real->kind == CX_COLLECTION) && (cx_collection(cx_valueType(stack[count])->real)->kind == CX_ARRAY)) {
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

        /* CX_OBJECT and CX_CONSTANT will not be encountered in this loop. */
        default:
            cx_assert(0, "invalid valueKind at this place.");
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
static int cpp_loadDeclareWalk(cx_object o, void* userData) {
    cpp_typeWalk_t* data;
    cx_id specifier, objectId;
    cx_typedef t;
    cx_bool isClass;

    data = userData;
    t = cx_typeof(o);

    if (!(cx_typeof(cx_parentof(o))->real->kind == CX_VOID)) {
        cpp_openScope(data->header, cx_parentof(cx_parentof(o)));
        cpp_openScope(data->source, cx_parentof(cx_parentof(o)));
    } else {
        cpp_openScope(data->header, cx_parentof(o));
        cpp_openScope(data->source, cx_parentof(o));
    }

    if (cx_class_instanceof(cx_interface_o, o) && cx_type(o)->reference) {
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
    g_fileWrite(data->header, "/* %s */\n", cx_fullname(o, objectId));

    if (!t->real->reference) {
        /* Looks counter-intuitive to put '*' in front of non-reftypes. However, it makes sense, since there apparently is an
         * object of a non-reftype (in other words, there is a ref to an object of a non-reftype) and since the type itself
         * is not a reftype, a '*' is required to make it a reference. */
        g_fileWrite(data->header, "extern %s *%s;\n", specifier, cpp_metaName(data->g, o, CPP_HANDLE, objectId));
        g_fileWrite(data->source, "%s *%s;\n", specifier, objectId);
        if (isClass) { /* Maybe someday extendables might become non-ref types, this code makes sure that this is covered. */
            g_setIdKind(data->g, CX_GENERATOR_ID_CLASS_UPPER);
            /* Get upper-case typespecifier */
            if (!cpp_specifierId(data->g, t, specifier)) {
                goto error;
            }
            g_fileWrite(data->header, "extern %s %s;\n", specifier, cpp_metaName(data->g, o, CPP_OBJECT, objectId));
            g_fileWrite(data->source, "%s %s;\n", specifier, cpp_metaName(data->g, o, CPP_OBJECT, objectId));
            g_setIdKind(data->g, CX_GENERATOR_ID_CLASS_LOWER);
        }
    } else {
        /* Here, the type is already a reftype, therefore it's not required to put an '*' in front of the variable name */
        g_fileWrite(data->header, "extern %s %s;\n", specifier, cpp_metaName(data->g, o, CPP_HANDLE, objectId));
        g_fileWrite(data->source, "%s %s;\n", specifier, objectId);
        if (isClass) {
            g_setIdKind(data->g, CX_GENERATOR_ID_CLASS_UPPER);
            /* Get upper-case typespecifier */
            if (!cpp_specifierId(data->g, t, specifier)) {
                goto error;
            }
            g_fileWrite(data->header, "extern %s (*%s);\n", specifier, cpp_metaName(data->g, o, CPP_OBJECT, objectId));
            g_fileWrite(data->source, "%s (*%s);\n", specifier, cpp_metaName(data->g, o, CPP_OBJECT, objectId));
            g_setIdKind(data->g, CX_GENERATOR_ID_CLASS_LOWER);
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
static int cpp_loadMethodProxy(cx_object o, void* userData) {
    if (cx_class_instanceof(cx_procedure_o, cx_typeof(o)) && (cx_procedure(cx_typeof(o))->kind != CX_METAPROCEDURE)) {
        cx_id specifier, id;
        cpp_typeWalk_t* data;
        cx_uint32 i, paramCount;
        cx_parameter* p;
        cx_procedureKind kind;
        cpp_proxyKind proxyKind;
        cx_object thisType;

        kind = cx_procedure(cx_typeof(o)->real)->kind;
        thisType = NULL;

        if ((kind == CX_METHOD) || (kind == CX_DELEGATE) || ((kind == CX_OBSERVER) && (cx_class_instanceof(cx_class_o, cx_parentof(o))))) {
            proxyKind = CLASS_PROXY;
            thisType = cx_parentof(o); /* Type of this is parent of procedure */
        } else if (kind == CX_CALLBACK) {
            if (cx_checkState(o, CX_DEFINED)) {
                proxyKind = NO_PROXY;
            } else {
                proxyKind = DELEGATE_PROXY;
            }
        } else {
            if (cx_class_instanceof(cx_interface_o, cx_parentof(o)) && cx_type(cx_parentof(o))->reference) {
                proxyKind = STATIC_PROXY;
            } else {
                proxyKind = FUNCTION_PROXY;
            }
        }

        if (proxyKind != NO_PROXY) {

            data = userData;
            paramCount = 0;

            /* Open correct scope (if parent is abstract, open scope of abstract) */
            if (!cx_class_instanceof(cx_interface_o, cx_parentof(o)) && cx_type(cx_parentof(o))->reference) {
                cpp_openScope(data->source, cx_parentof(o));
            } else {
                cpp_openScope(data->source, cx_parentof(cx_parentof(o)));
            }

            /* Obtain type-specifier for return-type, write function identifier */
            if (!cpp_specifierId(data->g, cx_function(o)->returnType, specifier)) {
                goto error;
            }
            g_fileWrite(data->source, "%s %s(", specifier, cpp_loadMarshallId(data->g, o, id));

            /* Print '_this' */
            if (thisType) {
                g_fileWrite(data->source, "%s _this", g_fullOid(data->g, thisType, id));
                paramCount = 1;
            }

            /* Print arguments */
            for(i=0; i<cx_function(o)->parameters.length; i++) {
                p = &cx_function(o)->parameters.buffer[i];
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
            g_setIdKind(data->g, CX_GENERATOR_ID_CLASS_UPPER);

            /* If procedure has this, create C++ proxy-object (this is always an abstract object) */
            if (thisType) {
                g_fileWrite(data->source, "%s proxy(_this,FALSE);\n", g_fullOid(data->g, thisType, id), id);
            }

            /* If there are parameters of abstract types, create C++ proxy-objects */
            for(i=0; i<cx_function(o)->parameters.length; i++) {
                p = &cx_function(o)->parameters.buffer[i];
                if ((cx_class_instanceof(cx_interface_o, p->type) && (p->type->real->reference)) || (p->type == cx_typedef(cx_object_o))) {
                    cx_id id2;
                    g_fileWrite(data->source, "%s _%s(%s,FALSE);\n",
                                g_fullOid(data->g, p->type, id),
                                g_id(data->g, p->name, id2),
                                g_id(data->g, p->name, id2));
                }
            }
            g_setIdKind(data->g, CX_GENERATOR_ID_CLASS_LOWER);

            /* If procedure has returnType, return */
            if (cx_function(o)->returnType && ((cx_function(o)->returnType->real->kind != CX_VOID) || cx_function(o)->returnType->real->reference)) {
                g_fileWrite(data->source, "return ");
            }

            /* Call actual function - if CLASS_PROXY, invoke method on C++ class proxy */
            if (proxyKind == CLASS_PROXY) {
                g_fileWrite(data->source, "proxy.");

            /* If function is static class-member, prefix class-scope */
            } else if ((proxyKind == STATIC_PROXY) || (proxyKind == DELEGATE_PROXY)) {
                g_setIdKind(data->g, CX_GENERATOR_ID_CLASS_UPPER);
                g_fileWrite(data->source, "%s::", g_fullOid(data->g, cx_parentof(o), id));
                g_setIdKind(data->g, CX_GENERATOR_ID_CLASS_LOWER);
            }

            paramCount = 0;
            if ((kind == CX_METHOD) && (cx_method(o)->virtual)) {
                g_fileWrite(data->source, "%s_v(", cpp_procId(data->g, o, id));
            } else {
                g_fileWrite(data->source, "%s(", cpp_procId(data->g, o, id));
            }

            for(i=0; i<cx_function(o)->parameters.length; i++) {
                p = &cx_function(o)->parameters.buffer[i];
                if (paramCount) {
                    g_fileWrite(data->source, ", ");
                }
                if ((cx_class_instanceof(cx_interface_o, p->type) && (p->type->real->reference)) || (p->type == cx_typedef(cx_object_o))) {
                    g_fileWrite(data->source, "_%s", g_id(data->g, p->name, id));
                } else {
                    g_fileWrite(data->source, "%s", g_id(data->g, p->name, id));
                }
                paramCount++;
            }
            g_fileWrite(data->source, ")");
            if ((cx_class_instanceof(cx_interface_o, cx_function(o)->returnType->real) && cx_function(o)->returnType->real->reference) || (cx_function(o)->returnType == cx_typedef(cx_object_o))) {
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
static int cpp_loadIncludes(cx_object o, void* userData) {

    /* Add object to list */
    if (cx_class_instanceof(cx_interface_o, o) && cx_type(o)->reference) {
        if (!cx_llHasObject(userData, o)) {
            cx_llInsert(userData, o);
        }
    }

    /* Add type of object to list */
    if (cx_class_instanceof(cx_interface_o, cx_typeof(o)) && cx_type(cx_typeof(o))->reference) {
        if (!cx_llHasObject(userData, cx_typeof(o))) {
            cx_llInsert(userData, cx_typeof(o));
        }
    }

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

static int cpp_printIncludes(void* o, void* userData) {
    cpp_typeWalk_t* data;
    cx_id path, id;

    data = userData;
    cpp_topath(cx_parentof(o), path);
    g_setIdKind(data->g, CX_GENERATOR_ID_CLASS_UPPER);
    g_fileWrite(data->source, "#include \"%s/%s.hpp\"\n", path, g_oid(data->g, o, id));
    g_setIdKind(data->g, CX_GENERATOR_ID_CLASS_LOWER);
    return 1;
}

static int cpp_loadProxyWalk(cx_object o, void* userData) {
    cpp_typeWalk_t* data;
    cx_id className, h_var, o_var;

    data = userData;

    if (cx_class_instanceof(cx_interface_o, o) && cx_type(o)->reference) {
        cpp_metaFullname(data->g, o, CPP_HANDLE, h_var);
        g_setIdKind(data->g, CX_GENERATOR_ID_CLASS_UPPER);
        cpp_metaFullname(data->g, o, CPP_OBJECT, o_var);
        g_fullOid(data->g, cx_typeof(o), className);
        g_fileWrite(data->source, "%s = new %s(%s);\n", o_var, className, h_var);
    }

    return 1;
}

static int cpp_unloadProxyWalk(cx_object o, void* userData) {
    cpp_typeWalk_t* data;
    cx_id o_var;

    data = userData;

    if (cx_class_instanceof(cx_interface_o, o) && cx_type(o)->reference) {
        g_setIdKind(data->g, CX_GENERATOR_ID_CLASS_UPPER);
        cpp_metaFullname(data->g, o, CPP_OBJECT, o_var);
        g_fileWrite(data->source, "delete %s;\n", o_var);
        g_setIdKind(data->g, CX_GENERATOR_ID_CLASS_LOWER);
    }

    return 1;
}

/* Open generator headerfile */
static g_file cpp_loadHeaderFileOpen(cx_generator g) {
    g_file result;
    cx_id headerFileName, path;

    cpp_topath(g_getCurrent(g), path);

    /* Create file */
    if (strlen(path)) {
        sprintf(headerFileName, "include/%s/_meta.hpp", path);
    } else {
        sprintf(headerFileName, "include/_meta.hpp");
    }
    result = g_fileOpen(g, headerFileName);
    if (!result) {
        cx_error("failed to open file '%s'", headerFileName);
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
        g_fileWrite(result, "#include \"cortex.hpp\"\n\n");
        g_fileWrite(result, "#include \"%s/_type.hpp\"\n\n", path);
    }

    return result;
}

/* Close headerfile */
static void cpp_loadHeaderFileClose(cx_generator g, g_file file) {

    /* Print standard comments and includes */
    g_fileWrite(file, "\n");
    g_fileWrite(file, "int load(void);", g);
    g_fileWrite(file, "\n");
    cpp_closeScope(file);
    g_fileWrite(file, "#endif\n\n");
}

/* Open generator sourcefile */
static g_file cpp_loadSourceFileOpen(cx_generator g) {
    g_file result;
    cx_id fileName, path;

    cpp_topath(g_getCurrent(g), path);

    /* Create file */
    if (strlen(path)) {
        sprintf(fileName, "src/%s/_meta.cpp", path);
    } else {
        sprintf(fileName, "src/_meta.cpp");
    }
    result = g_fileOpen(g, fileName);
    if (!result) {
        cx_error("failed to open file '%s'", fileName);
    } else {
        /* Print standard comments and includes */
        g_fileWrite(result, "/* %s\n", fileName);
        g_fileWrite(result, " *\n");
        g_fileWrite(result, " *  Generated on %s\n", __DATE__);
        g_fileWrite(result, " *    Loads objects in database.\n");
        g_fileWrite(result, " *    This file contains generated code. Do not modify!\n");
        g_fileWrite(result, " */\n\n");
        g_fileWrite(result, "#include \"%s/_type.hpp\"\n", path, g_getName(g));
        g_fileWrite(result, "#include \"cortex.hpp\"\n\n");
    }

    return result;
}

/* Write starting comment of variable definitions */
static void cpp_sourceWriteVarDefStart(g_file file) {
    g_fileWrite(file, "/* Variable definitions */\n");
}

/* Write start of load-routine */
static void cpp_sourceWriteLoadStart(cx_generator g, g_file file) {
    cpp_openScope(file, g_getCurrent(g));
    g_fileWrite(file, "\n");
    g_fileWrite(file, "/* Load objects in database */\n");
    g_fileWrite(file, "int load(void) {\n");
    g_fileIndent(file);
    g_fileWrite(file, "::cortex::lang::object _a_; /* Used for resolving anonymous objects */\n");
    g_fileWrite(file, "_a_ = NULL;\n\n");
}

/* Write end of load-routine */
static void cpp_sourceWriteLoadEnd(g_file file) {
    g_fileWrite(file, "if (_a_) {\n");
    g_fileIndent(file);
    g_fileWrite(file, "::cortex::free(NULL, _a_, \"load: free temporary reference.\");\n");
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
static void cpp_sourceWriteUnloadStart(cx_generator g, g_file file) {
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
static int cpp_loadDeclare(cx_object o, void* userData) {
    cpp_typeWalk_t* data;
    cx_id id, parentId, typeId, specId, fullId;

    data = userData;

    /* Only declare scoped objects */
    if (cx_checkAttr(o, CX_ATTR_SCOPED)) {

        /* Declaration */
        g_fileWrite(data->source, "/* Declare %s */\n", cx_fullname(o, id));
        cpp_specifierId(data->g, cx_typeof(o), specId);
        g_fileWrite(data->source, "if (!(%s = (%s%s)::cortex::resolve(NULL, NULL, \"%s\", \"load: check if object '%s' already exists.\"))) {\n",
                    cpp_loadVarId(data->g, o, id),
                    specId,
                    cx_typeof(o)->real->reference ? "" : "*",
                    cx_fullname(o, fullId),
                    cx_fullname(o, fullId));
        g_fileIndent(data->source);

        if (!cx_checkAttr(cx_typeof(o), CX_ATTR_SCOPED)) {
            g_fileWrite(data->source, "%s = (%s%s)::cortex::declare(%s, \"%s\", (_a_ ? ::cortex::free(_a_) : 0, _a_ = ((::cortex::lang::_typedef)%s)));\n",
                    cpp_loadVarId(data->g, o, id),
                    specId,
                    cx_typeof(o)->real->reference ? "" : "*",
                    cpp_loadVarId(data->g, cx_parentof(o), parentId),
                    cx_nameof(o),
                    cpp_loadVarId(data->g, cx_typeof(o), typeId));
        } else {
            g_fileWrite(data->source, "%s = (%s%s)::cortex::declare(%s, \"%s\", ((::cortex::lang::_typedef)%s));\n",
                    cpp_loadVarId(data->g, o, id),
                    specId,
                    cx_typeof(o)->real->reference ? "" : "*",
                    cpp_loadVarId(data->g, cx_parentof(o), parentId),
                    cx_nameof(o),
                    cpp_loadVarId(data->g, cx_typeof(o), typeId));
        }

        /* Error checking */
        g_fileWrite(data->source, "if (!%s) {\n", cpp_loadVarId(data->g, o, id));
        g_fileIndent(data->source);
        g_fileWrite(data->source, "::cortex::error(\"%s_load: failed to declare object '%s'.\");\n",
                g_getName(data->g),
                cx_fullname(o, id));
        g_fileWrite(data->source, "goto error;\n");
        g_fileDedent(data->source);
        g_fileWrite(data->source, "}\n");

        g_fileDedent(data->source);
        g_fileWrite(data->source, "} else {\n");
        g_fileIndent(data->source);
        g_fileWrite(data->source, "::cortex::free(%s);\n", cpp_loadVarId(data->g, o, id));
        g_fileDedent(data->source);
        g_fileWrite(data->source, "}\n\n");
    }

    return 1;
}

/* Print variable start */
static void cpp_varPrintStart(cx_value* v, cpp_typeWalk_t* data) {
    cx_id memberId;
    cx_type t;

    t = cx_valueType(v)->real;

    /* Only write an identifier if the object is a primitive type, or a reference. */
    if ((t->kind == CX_PRIMITIVE) || (t->reference && !(v->kind == CX_OBJECT))) {
        /* Print memberId if object is member */
        g_fileWrite(data->source, "%s = ",
                cpp_loadMemberId(data, v, memberId, FALSE));
    }
}

/* Print variable end */
static void cpp_varPrintEnd(cx_value* v, cpp_typeWalk_t* data) {
    cx_type t;

    /* Get member object */
    t = cx_valueType(v)->real;
    if ((t->kind == CX_PRIMITIVE) || (t->reference && !(v->kind == CX_OBJECT))) {
        /* Print end of member-assignment */
        g_fileWrite(data->source, ";\n");
    }
}

/* cpp_initPrimitive */
static cx_int16 cpp_initPrimitive(cx_serializer s, cx_value* v, void* userData) {
    void* ptr;
    cx_type t;
    cx_string str;
    cpp_typeWalk_t* data;
    CX_UNUSED(s);

    ptr = cx_valueValue(v);
    t = cx_valueType(v)->real;
    data = userData;
    str = NULL;

    cpp_varPrintStart(v, userData);

    /* Treat booleans separately, the default convert translates booleans to 'true' and 'false' while
     * the language mapping of C TRUE and FALSE is. */
    if (cx_primitive(t)->kind == CX_BOOLEAN) {
        if (*(cx_bool*)ptr) {
            str = cx_strdup("TRUE");
        } else {
            str = cx_strdup("FALSE");
        }
    } else if (cx_primitive(t)->kind == CX_ENUM) {
        cx_id enumId, scopeId;
        cx_constant *c;

        c = cx_enum_constant(cx_enum(t), *(cx_uint32*)ptr);

        /* Constant id */
        cpp_constantId(data->g, c, enumId);

        /* Scope of enum */
        cx_fullname(cx_parentof(cx_parentof(c)), scopeId);

        /* Convert constant-name to language id */
        str = cx_malloc(strlen(enumId) + strlen(scopeId) + 2 + 1);
        sprintf(str, "%s::%s", scopeId, enumId);
    } else if (cx_primitive(t)->kind == CX_BITMASK) {
        str = cx_malloc(11);
        sprintf(str, "0x%x", *(cx_uint32*)ptr);
    } else if (cx_primitive(t)->kind == CX_TEXT) {
        cx_string v = *(cx_string*)ptr;
        if (v) {
            str = malloc(strlen("::cortex::strdup()") + strlen(v) + 1);
            sprintf(str, "::cortex::strdup(%s)", v);
        } else {
            str = cx_strdup("NULL");
        }
    } else {
        /* Convert primitive value to string using built-in conversion */
        if (cx_convert(cx_primitive(t), ptr, cx_primitive(cx_string_o), &str)) {
            goto error;
        }
    }

    g_fileWrite(data->source, "%s", str);
    cx_dealloc(str);

    if (cx_primitive(t)->width == CX_WIDTH_64) {
        if (cx_primitive(t)->kind == CX_UINTEGER) {
            g_fileWrite(data->source, "ULL");
        }
    }

    cpp_varPrintEnd(v, userData);

    return 0;
error:
    return -1;
}

/* cpp_initReference */
static cx_int16 cpp_initReference(cx_serializer s, cx_value* v, void* userData) {
    cx_object *optr, o;
    cpp_typeWalk_t* data;
    CX_UNUSED(s);

    data = userData;
    optr = cx_valueValue(v);

    cpp_varPrintStart(v, userData);

    if ((o = *optr)) {
        cx_id id, typeId;
        g_fileWrite(data->source, "((%s)%s)",
                g_fullOid(data->g, cx_valueType(v), typeId),
                cpp_loadResolve(o, id));
    } else {
        g_fileWrite(data->source, "NULL");
    }

    cpp_varPrintEnd(v, userData);

    return 0;
}

/* cpp_initElement */
static cx_int16 cpp_initElement(cx_serializer s, cx_value* v, void* userData) {
    cx_collection t;
    cpp_typeWalk_t* data;

    /* Get collectionType */
    t = cx_collection(cx_valueType(v->parent)->real);
    data = userData;

    /* Allocate space for element */
    switch(t->kind) {
    case CX_LIST:
    case CX_MAP: {
        cx_id elementId, specifier;
        g_fileWrite(data->source, "\n");

        cpp_specifierId(data->g, t->elementType, specifier);
        g_fileWrite(data->source, "%s = ::cortex::alloc(sizeof(%s));\n", cpp_loadElementId(v, elementId, 0), specifier);
        break;
    }
    default:
        break;
    }

    /* Serialize value */
    if (cx_serializeValue(s, v, data)) {
        goto error;
    }

    switch(t->kind) {
    case CX_LIST: {
        cx_id parentId, elementId;
        g_fileWrite(data->source, "%s->append(%s);\n",
                cpp_loadMemberId(data, v->parent, parentId, FALSE),
                cpp_loadElementId(v, elementId, 0));
        break;
    }
    case CX_MAP: /*{
        cx_id parentId, elementId;
        g_fileWrite(data->source, "cx_rbtreeSet(%s, %s)",
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
static cx_int16 cpp_initCollection(cx_serializer s, cx_value* v, void* userData) {
    cx_collection t;
    cpp_typeWalk_t* data;
    cx_id memberId;
    cx_uint32 size = 0;
    int result;
    void* ptr;

    ptr = cx_valueValue(v);

    t = cx_collection(cx_valueType(v)->real);
    data = userData;

    switch(t->kind) {
    case CX_ARRAY:
        size = t->max;
        break;
    case CX_SEQUENCE: {
        cx_uint32 length;
        cx_id specifier;

        size = length = *(cx_uint32*)ptr;

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
            g_fileWrite(data->source, "%sbuffer = (%s*)::cortex::alloc(sizeof(%s));\n",
                    cpp_loadMemberId(data, v, memberId, TRUE),
                    specifier,
                    specifier);
        } else {
            g_fileWrite(data->source, "%sbuffer = (%s*)::cortex::alloc(sizeof(%s) * %d);\n",
                    cpp_loadMemberId(data, v, memberId, TRUE),
                    specifier,
                    specifier,
                    length);
        }
        break;
    }
    case CX_LIST:
        /* Create list object */
        if (*(cx_ll*)ptr) {
            size = cx_llSize(*(cx_ll*)ptr);
            g_fileWrite(data->source, "%s = new ::cortex::ll();\n",
                    cpp_loadMemberId(data, v, memberId, FALSE));
        } else {
            g_fileWrite(data->source, "%s = NULL;\n", cpp_loadMemberId(data, v, memberId, FALSE));
        }
        break;
    case CX_MAP: {
        cx_id keyId;
        /* Create map object */
        if (*(cx_rbtree*)ptr) {
            size = cx_rbtreeSize(*(cx_rbtree*)ptr);
            g_fileWrite(data->source, "%s = new ::cortex::rbtree();\n",
                    cpp_loadMemberId(data, v, memberId, FALSE), g_fullOid(data->g, cx_rbtreeKeyType(*(cx_rbtree*)ptr), keyId));
        } else {
            g_fileWrite(data->source, "%s = NULL;\n", cpp_loadMemberId(data, v, memberId, FALSE));
        }
        break;
    }
    }

    /* For the non-array types, allocate a member variable, if size of collection is not zero. */
    if (size) {
        switch(t->kind) {
        case CX_LIST:
        case CX_MAP: {
            cx_id elementId, elementTypeId;
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
    result = cx_serializeElements(s, v, userData);

    if (size) {
        switch(t->kind) {
        case CX_LIST:
        case CX_MAP: {
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
static cx_int16 cpp_initObject(cx_serializer s, cx_value* v, void* userData) {
    cpp_typeWalk_t* data;
    cx_id id, id2;
    cx_object o;
    cx_bool isProcedure;

    data = userData;
    o = cx_valueObject(v);
    isProcedure = FALSE;

    g_fileWrite(data->source, "/* Define %s */\n", cx_fullname(o, id));
    g_fileWrite(data->source, "if (!::cortex::checkState((::cortex::lang::object)%s, ::cortex::lang::DEFINED)) {\n", cpp_loadVarId(data->g, o, id));
    g_fileIndent(data->source);

    /* Serialize object value */
    cx_serializeValue(s, v, userData);

    /* If object is a procedure, set function implementation */
    if (cx_class_instanceof(cx_procedure_o, cx_typeof(o)) && (cx_procedure(cx_typeof(o))->kind != CX_METAPROCEDURE)) {
        isProcedure = TRUE;

        /* C++ uses CDECL convention */
        g_fileWrite(data->source, "\n");
        g_fileWrite(data->source, "/* Bind %s with C++ function */\n", id);
        g_fileWrite(data->source, "((::cortex::lang::function)%s)->kind = CX_PROCEDURE_CDECL;\n", cpp_loadVarId(data->g, o, id));

        /* Bind function-object with marshall function */
        if (!(cx_checkState(o, CX_DEFINED) && (cx_procedure(cx_typeof(o))->kind == CX_CALLBACK))) {
            g_fileWrite(data->source, "((::cortex::lang::function)%s)->impl = reinterpret_cast< ::cortex::lang::word>(%s);\n", id, cpp_loadMarshallId(data->g, o, id2));
        } else {
            /* Callback functions are not generated when they are defined while the load-routine was generated. This is because a callback
             * method will never be called directly, only through it's corresponding delegate function. */
            g_fileWrite(data->source, "((::cortex::lang::function)%s)->impl = 0;\n", id);
        }

        g_setIdKind(data->g, CX_GENERATOR_ID_CLASS_LOWER);
    }

    /* Define object, but not if the object is a procedure and the parent is an abstract class, because these have no implementation. */
    if (!(isProcedure && (cx_interface(cx_parentof(o))->kind == CX_INTERFACE))) {
        g_fileWrite(data->source, "if (::cortex::define(%s)) {\n", cpp_loadVarId(data->g, o, id));
        g_fileIndent(data->source);
        g_fileWrite(data->source, "::cortex::error(\"%s_load: failed to define object '%s'.\");\n",
                g_getName(data->g),
                cx_fullname(o, id));
        g_fileWrite(data->source, "goto error;\n");
        g_fileDedent(data->source);
        g_fileWrite(data->source, "}\n");
    }

    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n");

    return 0;
}

/* Create serializer that initializes object values */
static struct cx_serializer_s cpp_initSerializer(void) {
    struct cx_serializer_s s;

    cx_serializerInit(&s);

    s.access = CX_LOCAL;
    s.accessKind = CX_NOT;
    s.traceKind = CX_SERIALIZER_TRACE_ON_FAIL;
    s.program[CX_PRIMITIVE] = cpp_initPrimitive;
    s.program[CX_COLLECTION] = cpp_initCollection;
    s.metaprogram[CX_OBJECT] = cpp_initObject;
    s.metaprogram[CX_ELEMENT] = cpp_initElement;
    s.reference = cpp_initReference;

    return s;
}

/* Define object */
static int cpp_loadDefine(cx_object o, void* userData) {
    struct cx_serializer_s s;

    if (cx_checkAttr(o, CX_ATTR_SCOPED)) {
        /* Obtain serializer to initialize object values */
        s = cpp_initSerializer();

        /* Serialize object */
        cx_serialize(&s, o, userData);
    }

    return 1;
}

/* Entry point for generator */
int cortex_genMain(cx_generator g) {
    cpp_typeWalk_t walkData;
    cx_ll headers;

    g_setIdKind(g, CX_GENERATOR_ID_CLASS_LOWER);

    /* Prepare walkData, create header- and sourcefile */
    walkData.g = g;
    walkData.header = cpp_loadHeaderFileOpen(g);
    walkData.source = cpp_loadSourceFileOpen(g);

    /* Collect headers for classes and types of objects */
    headers = cx_llNew();
    g_walkRecursive(g, cpp_loadIncludes, headers);
    /* Print includes */
    cx_llWalk(headers, cpp_printIncludes, &walkData);
    g_fileWrite(walkData.source, "\n");
    cx_llFree(headers);

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
    if (cx_genDepWalk(g, cpp_loadDeclare, cpp_loadDefine, &walkData)) {
        cx_trace("generation of load-routine failed while resolving dependencies.");
        goto error;
    }

    /* Create C++ proxy objects */
    if (!g_walkRecursive(g, cpp_loadProxyWalk, &walkData)) {
        goto error;
    }

    /* Register exithandler */
    g_fileWrite(walkData.source, "cortex::onunload(unload, NULL);\n");

    /* Close load-routine */
    cpp_sourceWriteLoadEnd(walkData.source);

    /* Close headerfile */
    cpp_loadHeaderFileClose(g, walkData.header);

    return 0;
error:
    return -1;
}
