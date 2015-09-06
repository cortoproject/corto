/*
 * c_interface.c
 *
 *  Created on: Oct 4, 2012
 *      Author: sander
 */

#include "corto.h"
#include "cx_generator.h"
#include "c_common.h"

typedef struct c_interfaceExisting {
    cx_string id;
    cx_string src;
} c_interfaceExisting;

typedef struct c_typeWalk_t {
    cx_generator g;
    g_file header;
    g_file source;
    g_file wrapper;
    g_file mainHeader;
    cx_uint16 firstComma;
    cx_bool generateHeader;
    cx_bool generateSource;
    cx_id sizeExpr;
} c_typeWalk_t;

/* Generate parameters for method */
static int c_interfaceParam(cx_parameter *o, void *userData) {
    c_typeWalk_t* data;
    cx_id specifier, postfix, name;

    data = userData;

    /* Write comma */
    if (data->firstComma) {
        if (data->generateSource) g_fileWrite(data->source, ", ");
        if (data->generateHeader) g_fileWrite(data->header, ", ");
    }

    if (c_specifierId(data->g, o->type, specifier, NULL, postfix)) {
        goto error;
    }

    if (data->generateSource) g_fileWrite(data->source, "%s ", specifier);
    if (data->generateHeader) g_fileWrite(data->header, "%s ", specifier);

    if (o->passByReference || ((o->type->kind == CX_COMPOSITE) && !o->type->reference)) {
        if (data->generateSource) g_fileWrite(data->source, "*");
        if (data->generateHeader) g_fileWrite(data->header, "*");
    }

    /* Write to source */
    if (data->generateSource) g_fileWrite(data->source, "%s%s", c_paramName(o->name, name), postfix);

    /* Write to header */
    if (data->generateHeader) g_fileWrite(data->header, "%s%s", c_paramName(o->name, name), postfix);

    data->firstComma++;

    return 1;
error:
    return 0;
}

static int c_interfaceParamNameSource(cx_parameter *o, void *userData) {
    c_typeWalk_t* data = userData;
    cx_id name;
    if (data->firstComma) {
        g_fileWrite(data->source, ", ");
    }
    g_fileWrite(data->source, "%s", c_paramName(o->name, name));
    data->firstComma++;
    return 1;
}

static int c_interfaceParamCastDef(cx_parameter *o, void *userData) {
    c_typeWalk_t* data = userData;
    if (*o->name != '$') {
        cx_id name;
        if (data->firstComma) {
            g_fileWrite(data->header, ", ");
        }
        g_fileWrite(data->header, "%s", c_paramName(o->name, name));
        data->firstComma++;
    }
    return 1;
}

/* Walk parameters of function */
static int c_interfaceParamWalk(cx_object _f, int(*action)(cx_parameter*, void*), void *userData) {
    cx_uint32 i;
    cx_function f = _f;
    for (i=0; i<f->parameters.length; i++) {
        if (!action(&(f->parameters.buffer[i]), userData)) {
            return 0;
        }
    }
    return 1;
}

/* Add this to parameter-list */
static void c_interfaceParamThis(cx_type parentType, c_typeWalk_t* data, cx_bool toSource, cx_bool toHeader) {
    cx_id classId;

    g_fullOid(data->g, parentType, classId);
    if (parentType->reference) {
        if (toSource) {
            g_fileWrite(data->source, "%s _this", classId);
        }
        if (toHeader) {
            g_fileWrite(data->header, "%s _this", classId);
        }
    } else {
        if (toSource) {
            g_fileWrite(data->source, "%s *_this", classId);
        }
        if (toHeader) {
            g_fileWrite(data->header, "%s *_this", classId);
        }
    }
}

/* Generate implementation for virtual methods */
static int c_interfaceGenerateVirtual(cx_method o, c_typeWalk_t* data) {
    cx_id id, returnTypeId, classId, returnPostfix;
    cx_bool returnsValue;
    cx_id nameString;
    g_file originalSource = data->source;

    /* Replace the source with the wrapper so that all nested functions use the correct outputfile.
     * This file will be restored at the end of the function */
    data->source = data->wrapper;

    if (((cx_function)o)->returnType && (cx_function(o)->returnType->kind != CX_VOID)) {
        returnsValue = TRUE;
        c_specifierId(data->g, cx_function(o)->returnType, returnTypeId, NULL, returnPostfix);
    } else {
        returnsValue = FALSE;
        strcpy(returnTypeId, "void");
    }

    g_fullOid(data->g, cx_parentof(o), classId);

    /* Write to sourcefile */
    g_fileWrite(data->wrapper, "\n");
    g_fileWrite(data->wrapper, "/* virtual %s */\n", cx_fullname(o, id));
    g_fileWrite(data->wrapper, "%s %s(",
            returnTypeId,
            g_fullOid(data->g, o, id));

    g_fileWrite(data->header, "\n");
    g_fileWrite(data->header, "/* virtual %s */\n", cx_fullname(o, id));
    g_fileWrite(data->header, "%s %s(",
            returnTypeId,
            g_fullOid(data->g, o, id));

    /* Add 'this' parameter */
    c_interfaceParamThis(cx_type(cx_parentof(o)), data, TRUE, TRUE);
    data->firstComma = 1;
    data->generateHeader = TRUE;

    /* Walk parameters */
    if (!c_interfaceParamWalk(o, c_interfaceParam, data)) {
        goto error;
    }

    g_fileWrite(data->header, ");\n");

    /* Obtain string for function name */
    c_escapeString(cx_nameof(o), nameString);

    /* Begin of function */
    g_fileWrite(data->wrapper, ") {\n");
    g_fileIndent(data->wrapper);
    g_fileWrite(data->wrapper, "static cx_uint32 _methodId;\n");
    g_fileWrite(data->wrapper, "cx_method _method;\n");
    if (returnsValue) {
        g_fileWrite(data->wrapper, "%s _result;\n", returnTypeId);
    }
    g_fileWrite(data->wrapper, "cx_interface _abstract;\n\n");
    g_fileWrite(data->wrapper, "_abstract = cx_interface(cx_typeof(_this));\n\n");
    g_fileWrite(data->wrapper, "/* Determine methodId once, then cache it for subsequent calls. */\n");
    g_fileWrite(data->wrapper, "if (!_methodId) {\n");
    g_fileIndent(data->wrapper);
    g_fileWrite(data->wrapper, "_methodId = cx_interface_resolveMethodId(_abstract, \"%s\");\n", nameString);
    g_fileDedent(data->wrapper);
    g_fileWrite(data->wrapper, "}\n");
    g_fileWrite(data->wrapper, "cx_assert(_methodId, \"virtual method '%s' not found in abstract '%%s'\", cx_nameof(_abstract));\n\n", nameString);
    g_fileWrite(data->wrapper, "/* Lookup method-object. */\n");
    g_fileWrite(data->wrapper, "_method = cx_interface_resolveMethodById(_abstract, _methodId);\n");
    g_fileWrite(data->wrapper, "cx_assert(_method != NULL, \"unresolved method '%%s::%s@%%d'\", cx_nameof(_this), _methodId);\n\n", nameString);

    if (returnsValue) {
        g_fileWrite(data->wrapper, "cx_call(cx_function(_method), &_result, _this");
    } else {
        g_fileWrite(data->wrapper, "cx_call(cx_function(_method), NULL, _this");
    }
    data->firstComma = 3;
    if (!c_interfaceParamWalk(o, c_interfaceParamNameSource, data)) {
        goto error;
    }
    g_fileWrite(data->wrapper, ");\n");

    if (returnsValue) {
        g_fileWrite(data->wrapper, "\n");
        g_fileWrite(data->wrapper, "return _result;\n");
    }
    g_fileDedent(data->wrapper);
    g_fileWrite(data->wrapper, "}\n");

    data->source = originalSource;

    return 0;
error:
    return -1;
}

static char* c_functionName(cx_function o, cx_id id, c_typeWalk_t *data) {
    g_fullOid(data->g, o, id);
    if (cx_instanceof(cx_type(cx_method_o), o)) {
        if (cx_method(o)->virtual) {
            strcat(id, "_v");
        }
    }
    return id;
}

static cx_bool c_interfaceParamRequiresCast(cx_type t, cx_bool isReference) {
    if ((isReference || t->reference) && (t->kind != CX_VOID) && (t->kind != CX_ANY)) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/* Add a type to the expression that determines the location of a parameter in a buffer */
void c_procedureAddToSizeExpr(cx_type t, cx_bool isReference, c_typeWalk_t *data) {
    cx_id id, postfix;

    if (c_interfaceParamRequiresCast(t, isReference)) {
        cx_id specifier;
        c_specifierId(data->g, t, specifier, NULL, NULL);
        g_fileWrite(data->wrapper, "%s(", specifier);
    }

    c_specifierId(data->g, cx_type(t), id, NULL, postfix);
    if (isReference || ((t->kind == CX_COMPOSITE) && !t->reference)) {
        strcpy(id, "void*");
    }

    if(data->firstComma) {
        g_fileWrite(data->wrapper, "*(%s*)((intptr_t)args + %s)", id, data->sizeExpr);
        strcat(data->sizeExpr, " + ");
    } else {
        g_fileWrite(data->wrapper, "*(%s*)args", id);
    }

    strcat(data->sizeExpr, "sizeof(");
    strcat(data->sizeExpr, id);
    strcat(data->sizeExpr, ")");

    if (c_interfaceParamRequiresCast(t, isReference)) {
        g_fileWrite(data->wrapper, ")");
    }

    data->firstComma = TRUE;
}

int c_procedureWrapperParam(cx_parameter *o, void *userData) {
    c_typeWalk_t* data;
    data = userData;

    /* Write comma */
    if (data->firstComma) {
        g_fileWrite(data->wrapper, ",\n");
    }

    /* Add type to size expression and add argument*/
    c_procedureAddToSizeExpr(o->type, o->passByReference, data);

    return 1;
}

/* Generate a wrapper for a procedure */
static int c_interfaceClassProcedureWrapper(cx_function o, c_typeWalk_t *data) {
    cx_id id, actualFunction;
    cx_type returnType;
    cx_id returnSpec, returnPostfix;

    *(data->sizeExpr) = '\0';
    data->firstComma = 0;

    /* Write wrapper signature */
    g_fileWrite(data->wrapper, "\n");
    g_fileWrite(data->wrapper, "void __%s(cx_function f, void *result, void *args) {\n", c_functionName(o, id, data));
    g_fileIndent(data->wrapper);

    /* Obtain returntype string */
    g_fileWrite(data->wrapper, "CX_UNUSED(f);\n");
    if (!o->parameters.length) {
        g_fileWrite(data->wrapper, "CX_UNUSED(args);\n");
    }
    returnType = ((cx_function)o)->returnType;
    if (returnType && cx_type_sizeof(returnType)) {
        c_specifierId(data->g, returnType, returnSpec, NULL, returnPostfix);
        g_fileWrite(data->wrapper, "*(%s%s*)result = ", returnSpec, returnPostfix);
    } else {
        g_fileWrite(data->wrapper, "CX_UNUSED(result);\n");
    }

    /* Call function and assign result */
    g_fileWrite(data->wrapper, "_%s(\n", c_functionName(o, actualFunction, data));
    g_fileIndent(data->wrapper);

    /* Add this */
    if (c_procedureHasThis(o)) {
        if(cx_procedure(cx_typeof(o))->kind != CX_METAPROCEDURE) {
            c_procedureAddToSizeExpr(cx_parentof(o), TRUE, data);
        }else {
            c_procedureAddToSizeExpr(cx_type(cx_any_o), FALSE, data);
        }
        data->firstComma = TRUE;
    }

    /* Add parameters */
    c_interfaceParamWalk(o, c_procedureWrapperParam, data);

    g_fileWrite(data->wrapper, ");\n");
    g_fileDedent(data->wrapper);

    g_fileDedent(data->wrapper);
    g_fileWrite(data->wrapper, "}\n");
    return 0;
}

static int c_interfaceParamCastWalk(cx_parameter *o, void *userData) {
    c_typeWalk_t* data = userData;
    cx_id specifier, postfix, name;

    if (data->firstComma) {
        g_fileWrite(data->header, ", ");
    }

    if (c_specifierId(data->g, o->type, specifier, NULL, postfix)) {
        goto error;
    }

    /* If parameter is a meta argument, stringify it */
    if (*o->name == '$') {
        g_fileWrite(data->header, "#%s", o->name + 1);
    } else {
        if (c_interfaceParamRequiresCast(o->type, o->passByReference)) {
            g_fileWrite(data->header, "%s(%s)", specifier, o->name);
        } else {
            g_fileWrite(data->header, "%s", c_paramName(o->name, name));
        }
    }

    data->firstComma = TRUE;

    return 1;
error:
    return 0;
}

static int c_interfaceCastMacro(cx_function o, cx_string functionName, c_typeWalk_t *data) {
    data->firstComma = FALSE;
    
    g_fileWrite(data->header, "#define %s(", functionName, functionName);
    
    if (c_procedureHasThis(o)) {
        g_fileWrite(data->header, "_this");
        data->firstComma = TRUE;
    }
    
    if (!c_interfaceParamWalk(o, c_interfaceParamCastDef, data)) {
        goto error;
    }
    
    g_fileWrite(data->header, ") _%s(", functionName);
    
    if (c_procedureHasThis(o)) {
        if (cx_procedure(cx_typeof(o))->kind != CX_METAPROCEDURE) {
            cx_id classId;
            cx_type parentType = cx_parentof(o);
            g_fullOid(data->g, parentType, classId);
            if (parentType->reference) {
                g_fileWrite(data->header, "%s(_this)", classId);
            } else {
                g_fileWrite(data->header, "_this", classId);
            }
        } else {
            g_fileWrite(data->header, "_this");
        }
        data->firstComma = TRUE;
    } else {
        data->firstComma = FALSE;
    }
    
    if (!c_interfaceParamWalk(o, c_interfaceParamCastWalk, data)) {
        goto error;
    }
    
    g_fileWrite(data->header, ")\n");

    return 0;
error:
    return -1;   
}

/* Generate methods for class */
static int c_interfaceClassProcedure(cx_object o, void *userData) {
    c_typeWalk_t* data;
    cx_bool defined = FALSE;

    data = userData;

    /* Only generate code for procedures */
    if (cx_class_instanceof(cx_procedure_o, cx_typeof(o))) {
        cx_id fullname, functionName, signatureName, returnSpec, returnPostfix;
        cx_string snippet, header;
        cx_procedureKind kind;
        cx_type returnType;
        cx_string doStubs = gen_getAttribute(data->g, "stubs");

        kind = cx_procedure(cx_typeof(o))->kind;
        defined = cx_checkState(o, CX_DEFINED) && (cx_function(o)->kind != CX_PROCEDURE_STUB);

        /* Check whether generation of stubs must be forced */
        if (doStubs) {
            if (!strcmp(doStubs, "true")) {
                defined = TRUE;
            } else if(!strcmp(doStubs, "false")) {
                defined = FALSE;
            }
        }

        /* If procedure is a delegate, generate delegate forwarding-function. Nothing
         * further needs to be generated in the sourcefile for a delegate. */
        switch (kind) {
        case CX_METHOD:
            if (cx_method(o)->virtual) {
                c_interfaceGenerateVirtual(o, data);
            }
            break;
        default:
            if (defined) {
                goto ok;
            }
            break;
        }

        /* Generate a wrapper for the function */
        if (!defined) {
            if (c_interfaceClassProcedureWrapper(cx_function(o), data)) {
                goto error;
            }
        }

        /* Generate function-return type string */
        returnType = ((cx_function)o)->returnType;
        if (returnType) {
            c_specifierId(data->g, returnType, returnSpec, NULL, returnPostfix);
        } else {
            strcpy(returnSpec, "void");
            *returnPostfix = '\0';
        }

        cx_fullname(o, fullname);
        c_functionName(o, functionName, data);
        if (cx_function(o)->overloaded) {
            strcpy(signatureName, fullname);
        } else {
            cx_signatureName(fullname, signatureName);
        }

        /* Write identifying comment to headerfile */
        g_fileWrite(data->header, "\n");
        g_fileWrite(data->header, "/* %s */\n", fullname);

        /* Start of function */
        g_fileWrite(data->header, "%s%s _%s", returnSpec, returnPostfix,
            functionName);

        /* Write to sourcefile */
        g_fileWrite(data->source, "\n");
        g_fileWrite(data->source, "/* %s */\n", fullname);

        /* Lookup header for function */
        header = g_fileLookupHeader(data->source, signatureName);
        if (header) {
            g_fileWrite(data->source, "/* $header(%s)", signatureName);
            g_fileWrite(data->source, "%s", header);
            g_fileWrite(data->source, "$end */\n");
        }

        g_fileWrite(data->source, "%s%s _%s", returnSpec, returnPostfix,
            functionName);

        g_fileWrite(data->source, "(");
        g_fileWrite(data->header, "(");

        /* Add 'this' parameter to methods */
        if (c_procedureHasThis(o)) {
            if (cx_procedure(cx_typeof(o))->kind != CX_METAPROCEDURE) {
                c_interfaceParamThis(cx_parentof(o), data, TRUE, TRUE);
            } else {
                g_fileWrite(data->source, "cx_any _this");
                g_fileWrite(data->header, "cx_any _this");
            }
            data->firstComma = 1;
        } else {
            data->firstComma = 0;
        }

        /* Walk parameters */
        data->generateHeader = TRUE;
        data->generateSource = TRUE;
        if (!c_interfaceParamWalk(o, c_interfaceParam, data)) {
            goto error;
        }

        /* Append void if the argumentlist was empty */
        if (!data->firstComma) {
            g_fileWrite(data->header, "void");
            g_fileWrite(data->source, "void");
        }

        /* Begin of function */
        g_fileWrite(data->source, ") {\n");
        g_fileWrite(data->source, "/* $begin(%s)", signatureName);
        g_fileIndent(data->source);

        /* Support both short and full name when function is not overloaded */
        snippet = g_fileLookupSnippet(data->source, signatureName);
        if (!snippet && (!cx_function(o)->overloaded)) {
            snippet = g_fileLookupSnippet(data->source, fullname);
        }

        /* Lookup if there is an existing implementation. */
        if (!defined) {
            if (!snippet) {
                g_fileWrite(data->source, " */\n\n");
                g_fileWrite(data->source, "/* << Insert implementation >> */\n\n");
                g_fileDedent(data->source);
                g_fileWrite(data->source, "/* ");
            } else {
                g_fileDedent(data->source);
                g_fileWrite(data->source, "%s", snippet);
            }
        } else {
            cx_id id;
            cx_uint32 i;
            cx_parameter *p;

            g_fileWrite(data->source, " */\n");

            if ((returnType->kind != CX_VOID) || (returnType->reference)) {
                cx_id specifier;
                g_fullOid(data->g, returnType, specifier);
                g_fileWrite(data->source, "%s _result;\n", specifier);
            } else {
                returnType = NULL;
            }

            /* If function is already defined, it is already implemented. The generator will generate a stub instead. */
            g_fileWrite(data->source, "cx_call(cx_function(%s_o)", g_fullOid(data->g, o, id));
            if (returnType) {
                g_fileWrite(data->source, ",&_result");
            } else {
                g_fileWrite(data->source, ",NULL");
            }
            if (cx_class_instanceof(cx_interface_o, cx_parentof(o))) {
                if (cx_procedure(cx_typeof(o))->kind != CX_FUNCTION) {
                    g_fileWrite(data->source, ",_this");
                }
            }
            for (i=0; i<cx_function(o)->parameters.length; i++) {
                p = &cx_function(o)->parameters.buffer[i];
                g_fileWrite(data->source, ",%s", g_id(data->g, p->name, id));
            }
            g_fileWrite(data->source, ");\n");
            if (returnType) {
                g_fileWrite(data->source, "return _result;\n");
            }
            g_fileDedent(data->source);
            g_fileWrite(data->source, "/* ");
        }

        g_fileWrite(data->source, "$end */\n");
        g_fileWrite(data->source, "}\n");

        /* End function in header */
        g_fileWrite(data->header, ");\n");

        /* Write the macro wrapper for automatic casting of parameter types */
        c_interfaceCastMacro(o, functionName, data);
    }

ok:
    return 1;
error:
    return 0;
}

/* Check if there are procedures in the scope of an object. */
static int c_interfaceCheckProcedures(void *o, void *udata) {
    CX_UNUSED(udata);

    /* If the type of the type of the object is a procedure, return 0. */
    if (cx_class_instanceof(cx_procedure_o, cx_typeof(o))) {
        return 0;
    }
    return 1;
}

/* Open generator headerfile */
static g_file c_interfaceHeaderFileOpen(cx_generator g, cx_object o, c_typeWalk_t *data) {
    g_file result;
    cx_id headerFileName, name;
    cx_object topLevelObject = g_getCurrent(g);
    cx_id path;

    /* Create file */
    sprintf(headerFileName, "%s.h", g_fullOid(g, o, name));
    result = g_fileOpen(g, headerFileName);

    if (!result) {
        goto error;
    }

    if (!data->mainHeader) {
        cx_id mainHeader, topLevelName;
        if (o == topLevelObject) {
            data->mainHeader = result;
        } else {
            sprintf(mainHeader, "%s.h", g_fullOid(g, topLevelObject, topLevelName));
            data->mainHeader = g_fileOpen(g, mainHeader);
            if (!result) {
                goto error;
            }
        }
    }

    if (o != topLevelObject) {
        g_fileWrite(data->mainHeader, "#include \"%s\"\n", headerFileName);
    }

    /* Print standard comments and includes */
    g_fileWrite(result, "/* %s\n", headerFileName);
    g_fileWrite(result, " *\n");
    g_fileWrite(result, " * This file contains generated code. Do not modify!\n");
    g_fileWrite(result, " */\n\n");
    g_fileWrite(result, "#ifndef %s_H\n", c_topath(o, path, '_'));
    g_fileWrite(result, "#define %s_H\n\n", c_topath(o, path, '_'));
    g_fileWrite(result, "#include \"corto.h\"\n");

    /* If the class extends from another class, include header of baseclass */
    if (cx_class_instanceof(cx_class_o, o) && cx_interface(o)->base) {
        cx_id baseId;
        if (g_mustParse(g, cx_interface(o)->base)) {
           g_fileWrite(result, "#include \"%s.h\"\n", g_fullOid(g, cx_interface(o)->base, baseId));
        } else {
            cx_id path;
            g_fileWrite(result, "#include \"%s/%s.h\"\n", 
                c_topath(cx_parentof(cx_interface(o)->base), path, '/'),
                g_fullOid(g, cx_interface(o)->base, baseId));
        }
    }

    g_fileWrite(result, "#ifdef %s_LIB\n", c_topath(g_getCurrent(g), path, '_'));
    g_fileWrite(result, "#include \"%s__type.h\"\n", g_getName(g));
    g_fileWrite(result, "#include \"%s__api.h\"\n", g_getName(g));
    g_fileWrite(result, "#include \"%s__meta.h\"\n", g_getName(g));
    g_fileWrite(result, "#else\n");
    g_fileWrite(result, "#include \"%s/%s__type.h\"\n", c_topath(g_getCurrent(g), path, '/'), g_getName(g));
    g_fileWrite(result, "#include \"%s/%s__api.h\"\n", c_topath(g_getCurrent(g), path, '/'), g_getName(g));
    g_fileWrite(result, "#include \"%s/%s__meta.h\"\n", c_topath(g_getCurrent(g), path, '/'), g_getName(g));
    g_fileWrite(result, "#endif\n\n");


    g_fileWrite(result, "#ifdef __cplusplus\n");
    g_fileWrite(result, "extern \"C\" {\n");
    g_fileWrite(result, "#endif\n");

    return result;
error:
    return NULL;
}

/* Close headerfile */
static void c_interfaceHeaderFileClose(g_file file) {

    /* Print standard comments and includes */
    g_fileWrite(file, "\n");
    g_fileWrite(file, "#ifdef __cplusplus\n");
    g_fileWrite(file, "}\n");
    g_fileWrite(file, "#endif\n");
    g_fileWrite(file, "#endif\n\n");
}

static g_file c_interfaceWrapperFileOpen(cx_generator g) {
    g_file result;
    cx_char fileName[512];
    cx_id id, name, path;

    cx_object o = g_getCurrent(g);
    sprintf(fileName, "%s__wrapper.c", g_getName(g));

    if (!strcmp(gen_getAttribute(g, "bootstrap"), "true")) {
        result = g_fileOpen(g, fileName);
    } else {
        result = g_hiddenFileOpen(g, fileName);
    }

    if(!result) {
        goto error;
    }

    /* Print standard comments and includes */
    g_fileWrite(result, "/* %s\n", fileName);
    g_fileWrite(result, " *\n");
    g_fileWrite(result, " * This file contains wrapper functions for %s.\n", cx_fullname(o, id));
    g_fileWrite(result, " */\n\n");
    g_fileWrite(result, "#define %s_LIB\n", c_topath(g_getCurrent(g), path, '_'));
    g_fileWrite(result, "#include \"%s.h\"\n", g_fullOid(g, o, name));
    g_fileWrite(result, "#include \"%s__meta.h\"\n", g_getName(g));

    return result;
error:
    return NULL;
}

/* Generate name for sourcefile */
static cx_string c_interfaceSourceFileName(cx_string name, cx_char* buffer) {
    /* Create file */
    sprintf(buffer, "%s.c", name);

    return buffer;
}

/* Open generator sourcefile */
static g_file c_interfaceSourceFileOpen(cx_generator g, cx_string name) {
    g_file result;
    cx_char fileName[512];
    cx_id topLevelName, path;

    result = g_fileOpen(g, c_interfaceSourceFileName(name, fileName));
    if (!result) {
        goto error;
    }

    /* Print standard comments and includes */
    g_fileWrite(result, "/* %s\n", fileName);
    g_fileWrite(result, " *\n");
    g_fileWrite(result, " * This file contains the implementation for the generated interface.\n");
    g_fileWrite(result, " *\n");
    g_fileWrite(result, " * Don't mess with the begin and end tags, since these will ensure that modified\n");
    g_fileWrite(result, " * code in interface functions isn't replaced when code is re-generated.\n");
    g_fileWrite(result, " */\n\n");
    g_fileWrite(result, "#define %s_LIB\n", c_topath(g_getCurrent(g), path, '_'));
    g_fileWrite(result, "#include \"%s.h\"\n", g_fullOid(g, g_getCurrent(g), topLevelName));

    return result;
error:
    return NULL;
}

/* Generate interface for class */
static cx_int16 c_interfaceObject(cx_object o, c_typeWalk_t* data) {
    cx_id id;
    cx_string snippet;
    int hasProcedures;
    cx_bool isInterface;
    cx_bool isTopLevelObject;
    cx_bool isBootstrap = !strcmp(gen_getAttribute(data->g, "bootstrap"), "true");

    hasProcedures = !cx_scopeWalk(o, c_interfaceCheckProcedures, NULL);
    isInterface = cx_class_instanceof(cx_interface_o, o);
    isTopLevelObject = o == g_getCurrent(data->g);

    /* Always generate header for interfaces */
    if (hasProcedures || isInterface || isTopLevelObject) {
        data->header = c_interfaceHeaderFileOpen(data->g, o, data);
        if (!data->header) {
            goto error;
        }
    }

    /* An interface implementation file is generated when the object is
     * an interface and has procedures. When the object is not an interface
     * but does have procedures (typical example is callbacks or static functions)
     * these are appended to the header of the first scope in the hierarchy. */
    if (hasProcedures || (isTopLevelObject && !isBootstrap)) {

        /* Create a wrapper file if it was not already created */
        if (!data->wrapper) {
            data->wrapper = c_interfaceWrapperFileOpen(data->g);
            if (!data->wrapper) {
                goto error;
            }
        }

        /* If a header exists, write it */
        if ((snippet = g_fileLookupHeader(data->header, ""))) {
            g_fileWrite(data->header, "\n");
            g_fileWrite(data->header, "/* $header()");
            g_fileWrite(data->header, "%s", snippet);
            g_fileWrite(data->header, "$end */\n");
        }

        /* Obtain language identifier for object */
        g_fullOid(data->g, o, id);

        /* Open sourcefile */
        data->source = c_interfaceSourceFileOpen(data->g, id);
        if (!data->source) {
            goto error;
        }

        /* If a header exists, write it */
        if ((snippet = g_fileLookupHeader(data->source, ""))) {
            g_fileWrite(data->source, "\n");
            g_fileWrite(data->source, "/* $header()");
            g_fileWrite(data->source, "%s", snippet);
            g_fileWrite(data->source, "$end */\n");
        }

        /* Walk scope */
        if (!cx_scopeWalk(o, c_interfaceClassProcedure, data)) {
            goto error;
        }

        /* If top level file, generate main function */
        if (isTopLevelObject) {
            g_fileWrite(data->source, "\n");
            g_fileWrite(data->source, "int %sMain(int argc, char* argv[]) {\n", cx_nameof(o));
            g_fileWrite(data->source, "/* $begin(main)");
            g_fileIndent(data->source);
            if ((snippet = g_fileLookupSnippet(data->source, "main"))) {
                g_fileWrite(data->source, "%s", snippet);
                g_fileWrite(data->source, "$end */\n");
                g_fileDedent(data->source);
            } else {
                g_fileWrite(data->source, " */\n");
                g_fileWrite(data->source, "/* Insert code that must be run when component is loaded */\n");
                g_fileWrite(data->source, "CX_UNUSED(argc);\n");
                g_fileWrite(data->source, "CX_UNUSED(argv);\n");
                g_fileWrite(data->source, "return 0;\n");
                g_fileDedent(data->source);
                g_fileWrite(data->source, "/* $end */\n");
            }
            g_fileWrite(data->source, "}\n");
        }
    }

    /* Close */
    if (hasProcedures || isInterface || isTopLevelObject) {
        c_interfaceHeaderFileClose(data->header);
    }

    return 0;
error:
    return 1;
}

/* Walk interfaces */
static int c_interfaceWalk(cx_object o, void *userData) {
    c_typeWalk_t* data;

    data = userData;

    /* Parse interfaces */
    if (c_interfaceObject(o, data)) {
        goto error;
    }

    /* Walk scope of object */
    if (!cx_scopeWalk(o, c_interfaceWalk, data)) {
        goto error;
    }

    return 1;
error:
    return 0;
}

/* Entry point for generator */
int corto_genMain(cx_generator g) {
    c_typeWalk_t walkData;
    cx_ll packages = NULL;

    /* Create source and include directories */
    cx_mkdir("src");
    cx_mkdir("include");

    if (strcmp(gen_getAttribute(g, "bootstrap"), "true")) {
        cx_mkdir(".corto");
    }

    /* Default prefixes for corto namespaces */
    gen_parse(g, corto_o, FALSE, FALSE, "");
    gen_parse(g, corto_lang_o, FALSE, FALSE, "cx");

    /* Prepare walkData, create header- and sourcefile */
    walkData.g = g;
    walkData.header = NULL;
    walkData.source = NULL;
    walkData.wrapper = NULL;
    walkData.mainHeader = NULL;

    /* Walk objects, generate procedures and class members */
    if (!g_walkNoScope(g, c_interfaceWalk, &walkData)) {
        goto error;
    }

    /* Add header files for dependent packages */
    packages = cx_loadGetPackages();
    if (packages) {
        cx_iter iter = cx_llIter(packages);
        while (cx_iterHasNext(&iter)) {
            cx_string package = cx_iterNext(&iter);
            cx_object o = cx_resolve(NULL, package);
            if (!o) {
                cx_error("package '%s' not found", package);
                goto error;
            }
            cx_id path;
            g_fileWrite(walkData.mainHeader, "#include \"%s/%s.h\"\n", c_topath(o, path, '/'), cx_nameof(o));
        }
        cx_loadFreePackages(packages);
    }

    return 0;
error:
    return -1;
}
