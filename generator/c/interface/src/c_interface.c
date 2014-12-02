/*
 * c_interface.c
 *
 *  Created on: Oct 4, 2012
 *      Author: sander
 */

#include "hyve.h"
#include "db_generator.h"
#include "c_common.h"

typedef struct c_interfaceExisting {
    db_string id;
    db_string src;
}c_interfaceExisting;

typedef struct c_typeWalk_t {
    db_generator g;
    g_file header;
    g_file source;
    g_file wrapper;
    g_file mainHeader;
    db_uint16 firstComma;
    db_bool generateHeader;
    db_bool generateSource;
    db_id sizeExpr;
} c_typeWalk_t;

/* Generate parameters for method */
static int c_interfaceMethodParameter(db_parameter* o, void* userData) {
    c_typeWalk_t* data;
    db_id specifier, postfix;

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

    if (o->passByReference || ((o->type->real->kind == DB_COMPOSITE) && !o->type->real->reference)) {
        if (data->generateSource) g_fileWrite(data->source, "*");
    	if (data->generateHeader) g_fileWrite(data->header, "*");
    }

	/* Write to source */
    if (data->generateSource) g_fileWrite(data->source, "%s%s", o->name, postfix);

    /* Write to header */
	if (data->generateHeader) g_fileWrite(data->header, "%s%s", o->name, postfix);

	data->firstComma++;

	return 1;
error:
	return 0;
}

/* Generate parameters for method */
static int c_interfaceMethodParameterName(db_parameter* o, void* userData) {
    c_typeWalk_t* data;

    data = userData;

    /* Write comma */
    if (data->firstComma) {
    	g_fileWrite(data->source, ", ");
    }

	/* Write to source */
	g_fileWrite(data->source, "%s",
			o->name);

	data->firstComma++;

	return 1;
}

/* Walk parameters of function */
static int c_interfaceParamWalk(db_object _f, int(*action)(db_parameter*, void*), void* userData) {
	db_uint32 i;
	db_function f = _f;
	for(i=0; i<f->parameters.length; i++) {
		if (!action(&(f->parameters.buffer[i]), userData)) {
			return 0;
		}
	}
	return 1;
}

/* Add this to parameter-list */
static void c_interfaceParamThis(db_type parentType, c_typeWalk_t* data, db_bool toSource, db_bool toHeader) {
	db_id classId;

	g_fullOid(data->g, parentType, classId);
    if ((parentType->kind == DB_COMPOSITE) && !parentType->reference) {
    	if (toSource) {
    		g_fileWrite(data->source, "%s *_this", classId);
    	}
    	if (toHeader) {
    		g_fileWrite(data->header, "%s *_this", classId);
    	}
    } else {
    	if (toSource) {
    		g_fileWrite(data->source, "%s _this", classId);
    	}
		if (toHeader) {
			g_fileWrite(data->header, "%s _this", classId);
		}
    }
}

/* Generate implementation for virtual methods */
static int c_interfaceGenerateVirtual(db_method o, c_typeWalk_t* data) {
	db_id id, returnTypeId, classId, returnPostfix;
	db_bool returnsValue;
	db_id nameString;
    g_file originalSource = data->source;

    /* Replace the source with the wrapper so that all nested functions use the correct outputfile.
     * This file will be restored at the end of the function */
    data->source = data->wrapper;

	if (((db_function)o)->returnType && (db_function(o)->returnType->real->kind != DB_VOID)) {
		returnsValue = TRUE;
		c_specifierId(data->g, db_function(o)->returnType, returnTypeId, NULL, returnPostfix);
	} else {
		returnsValue = FALSE;
		strcpy(returnTypeId, "void");
	}

	g_fullOid(data->g, db_parentof(o), classId);

	/* Write to sourcefile */
	g_fileWrite(data->wrapper, "\n");
	g_fileWrite(data->wrapper, "/* virtual %s */\n", db_fullname(o, id));
	g_fileWrite(data->wrapper, "%s %s(",
			returnTypeId,
			g_fullOid(data->g, o, id));

    g_fileWrite(data->header, "\n");
    g_fileWrite(data->header, "/* virtual %s */\n", db_fullname(o, id));
    g_fileWrite(data->header, "%s %s(",
            returnTypeId,
            g_fullOid(data->g, o, id));

	/* Add 'this' parameter */
    c_interfaceParamThis(db_type(db_parentof(o)), data, TRUE, TRUE);
	data->firstComma = 1;
	data->generateHeader = TRUE;

	/* Walk parameters */
	if (!c_interfaceParamWalk(o, c_interfaceMethodParameter, data)) {
		goto error;
	}

	g_fileWrite(data->header, ");\n");

	/* Obtain string for function name */
	c_escapeString(db_nameof(o), nameString);

	/* Begin of function */
	g_fileWrite(data->wrapper, ") {\n");
	g_fileIndent(data->wrapper);
	g_fileWrite(data->wrapper, "static db_uint32 _methodId;\n");
	g_fileWrite(data->wrapper, "db_method _method;\n");
	if (returnsValue) {
		g_fileWrite(data->wrapper, "%s _result;\n", returnTypeId);
	}
	g_fileWrite(data->wrapper, "db_interface _abstract;\n\n");
	g_fileWrite(data->wrapper, "_abstract = db_interface(db_typeof(_this));\n\n");
	g_fileWrite(data->wrapper, "/* Determine methodId once, then cache it for subsequent calls. */\n");
	g_fileWrite(data->wrapper, "if (!_methodId) {\n");
	g_fileIndent(data->wrapper);
	g_fileWrite(data->wrapper, "_methodId = db_interface_resolveMethodId(_abstract, \"%s\");\n", nameString);
	g_fileDedent(data->wrapper);
	g_fileWrite(data->wrapper, "}\n");
	g_fileWrite(data->wrapper, "db_assert(_methodId, \"virtual method '%s' not found in abstract '%%s'\", db_nameof(_abstract));\n\n", nameString);
	g_fileWrite(data->wrapper, "/* Lookup method-object. */\n");
	g_fileWrite(data->wrapper, "_method = db_interface_resolveMethodById(_abstract, _methodId);\n");
	g_fileWrite(data->wrapper, "db_assert(_method != NULL, \"unresolved method '%%s::%s@%%d'\", db_nameof(_this), _methodId);\n\n", nameString);

	if (returnsValue) {
		g_fileWrite(data->wrapper, "db_call(db_function(_method), &_result, _this");
	} else {
		g_fileWrite(data->wrapper, "db_call(db_function(_method), NULL, _this");
	}
    data->firstComma = 3;
    if (!c_interfaceParamWalk(o, c_interfaceMethodParameterName, data)) {
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

/* Generate implementation for delegate methods */
static int c__interfaceGenerateDelegate(db_delegate o, c_typeWalk_t* data) {
    db_id id, returnTypeId, classId;
    db_bool returnsValue;

    g_file originalSource = data->source;

    /* Replace the source with the wrapper so that all nested functions use the correct outputfile.
     * This file will be restored at the end of the function */
    data->source = data->wrapper;

    if (((db_function)o)->returnType && (db_function(o)->returnType->real->kind != DB_VOID)) {
        g_fullOid(data->g, ((db_function)o)->returnType, returnTypeId);
        returnsValue = TRUE;
    } else {
        strcpy(returnTypeId, "void");
        returnsValue = FALSE;
    }

    g_fullOid(data->g, db_parentof(o), classId);

    /* Write to sourcefile */
    g_fileWrite(data->wrapper, "\n");
    g_fileWrite(data->wrapper, "/* delegate %s */\n", db_fullname(o, id));
    g_fileWrite(data->wrapper, "%s %s(",
            returnTypeId,
            g_fullOid(data->g, o, id));

    /* Add 'this' parameter */
    c_interfaceParamThis(db_type(db_parentof(o)), data, TRUE, FALSE);
    data->firstComma = 1;
    data->generateHeader = FALSE;
    data->generateSource = TRUE;

    /* Walk parameters */
    if (!c_interfaceParamWalk(o, c_interfaceMethodParameter, data)) {
        goto error;
    }

    /* Begin of function */
    g_fileWrite(data->wrapper, ") {\n");
    g_fileIndent(data->wrapper);
    g_fileWrite(data->wrapper, "db_callback _callback;\n");
    if (returnsValue) {
    	g_fileWrite(data->wrapper, "%s _result;\n", returnTypeId);
    }
    g_fileWrite(data->wrapper, "/* Lookup callback-object. */\n");
    g_fileWrite(data->wrapper, "_callback = db_class_resolveCallback(db_class(db_typeof(_this)), %s_o, _this);\n\n",
        g_fullOid(data->g, o, id));
    g_fileWrite(data->wrapper, "db_assert(_callback != NULL, \"no callback '%s' for object of type '%s' (call '%s_checkCallback' first)\");\n\n", 
        db_nameof(o), classId, g_fullOid(data->g, o, id));
	if (returnsValue) {
		g_fileWrite(data->wrapper, "db_call(db_function(_callback), &_result");
	} else {
		g_fileWrite(data->wrapper, "db_call(db_function(_callback), NULL");
	}
    data->firstComma = 2;
    if (!c_interfaceParamWalk(o, c_interfaceMethodParameterName, data)) {
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

/* Generate implementation for obtaining the callback for delegate methods */
static int c__interfaceGenerateDelegate_hasCallback(db_delegate o, c_typeWalk_t* data) {
    db_id id, classId;
    g_file originalSource = data->source;

    /* Replace the source with the wrapper so that all nested functions use the correct outputfile.
     * This file will be restored at the end of the function */
    data->source = data->wrapper;

    g_fullOid(data->g, db_parentof(o), classId);

    /* Write to sourcefile */
    g_fileWrite(data->wrapper, "\n");
    g_fileWrite(data->wrapper, "/* delegate %s, obtain callback */\n", db_fullname(o, id));
    g_fileWrite(data->wrapper, "db_bool %s_hasCallback(%s _this) {\n",
            g_fullOid(data->g, o, id),
            classId);

    /* Write to headerfile */
    g_fileWrite(data->header, "\n");
    g_fileWrite(data->header, "/* delegate %s, obtain callback */\n", db_fullname(o, id));
    g_fileWrite(data->header, "db_bool %s_hasCallback(%s _this);\n",
            g_fullOid(data->g, o, id),
            classId);

    g_fileIndent(data->wrapper);
    g_fileWrite(data->wrapper, "/* Lookup callback-object. */\n");
    g_fileWrite(data->wrapper, "return db_class_resolveCallback(db_class(db_typeof(_this)), %s_o, _this) != NULL;\n",
        g_fullOid(data->g, o, id));
    g_fileDedent(data->wrapper);
    g_fileWrite(data->wrapper, "}\n");

    data->source = originalSource;

    return 0;
}


/* Generate implementation for delegate methods */
static int c_interfaceGenerateDelegate(db_delegate o, c_typeWalk_t* data) {
    if (c__interfaceGenerateDelegate(o, data)) {
        goto error;
    }

    if (c__interfaceGenerateDelegate_hasCallback(o, data)) {
        goto error;
    }

    return 0;
error:
    return -1;
}

static char* c_functionName(db_function o, db_id id, c_typeWalk_t *data) {
    g_fullOid(data->g, o, id);
    if(db_instanceof(db_typedef(db_method_o), o)) {
        if(db_method(o)->virtual) {
            strcat(id, "_v");
        }
    }
    return id;
}

/* Add a type to the expression that determines the location of a parameter in a buffer */
void c_procedureAddToSizeExpr(db_type t, db_bool isReference, c_typeWalk_t *data) {
    db_id id, postfix;

    c_specifierId(data->g, db_typedef(t), id, NULL, postfix);
    if (isReference || ((t->kind == DB_COMPOSITE) && !t->reference)) {
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

    data->firstComma = TRUE;
}

int c_procedureWrapperParam(db_parameter* o, void* userData) {
    c_typeWalk_t* data;
    data = userData;

    /* Write comma */
    if (data->firstComma) {
        g_fileWrite(data->wrapper, ",\n");
    }

    /* Add type to size expression and add argument*/
    c_procedureAddToSizeExpr(o->type->real, o->passByReference, data);

    return 1;
}

/* Generate a wrapper for a procedure */
static int c_interfaceClassProcedureWrapper(db_function o, c_typeWalk_t *data) {
    db_id id, actualFunction;
    db_typedef returnType;
    db_id returnSpec, returnPostfix;

    *(data->sizeExpr) = '\0';
    data->firstComma = 0;

    /* Write wrapper signature */
    g_fileWrite(data->wrapper, "\n");
    g_fileWrite(data->wrapper, "void __%s(db_function f, void *result, void *args) {\n", c_functionName(o, id, data));
    g_fileIndent(data->wrapper);

    /* Obtain returntype string */
    g_fileWrite(data->wrapper, "DB_UNUSED(f);\n");
    if(!o->parameters.length) {
        g_fileWrite(data->wrapper, "DB_UNUSED(args);\n");
    }
    returnType = ((db_function)o)->returnType;
    if (returnType && db_type_sizeof(returnType->real)) {
        c_specifierId(data->g, returnType, returnSpec, NULL, returnPostfix);
        g_fileWrite(data->wrapper, "*(%s%s*)result = ", returnSpec, returnPostfix);
    }else {
        g_fileWrite(data->wrapper, "DB_UNUSED(result);\n");
    }

    /* Call function and assign result */
    g_fileWrite(data->wrapper, "%s(\n", c_functionName(o, actualFunction, data));
    g_fileIndent(data->wrapper);

    /* Add this */
    if (c_procedureHasThis(o)) {
        db_type parentType;
        if(db_procedure(db_typeof(o))->kind != DB_METAPROCEDURE) {
            parentType = db_parentof(o);
        }else {
            parentType = db_type(db_any_o);
        }
        c_procedureAddToSizeExpr(parentType, FALSE, data);
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

/* Generate methods for class */
static int c_interfaceClassProcedure(db_object o, void* userData) {
    c_typeWalk_t* data;
    db_bool defined = FALSE;

    data = userData;

    /* Only generate code for procedures */
    if (db_class_instanceof(db_procedure_o, db_typeof(o))) {
		db_id id, classId, returnSpec, returnPostfix;
		db_string snippet, header;
		db_bool delegate, callback;
		db_procedureKind kind;
		db_typedef returnType;
        db_string doStubs = gen_getAttribute(data->g, "stubs");

        delegate = FALSE;
        callback = FALSE;
        kind = db_procedure(db_typeof(o))->kind;
        defined = db_checkState(o, DB_DEFINED) && (db_function(o)->kind != DB_PROCEDURE_STUB);

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
        switch(kind) {
        case DB_DELEGATE:
            delegate = TRUE;
            c_interfaceGenerateDelegate(o, data);
            break;
        case DB_METHOD:
            if (db_method(o)->virtual) {
                c_interfaceGenerateVirtual(o, data);
            }
            break;
        case DB_CALLBACK:
            callback = TRUE;
            break;
        default:
            if (defined) {
                goto ok;
            }
            break;
        }

        /* Generate a wrapper for the function */
        if(!defined) {
            if(c_interfaceClassProcedureWrapper(db_function(o), data)) {
                goto error;
            }
        }

		/* Generate function-return type string */
        returnType = ((db_function)o)->returnType;
		if (returnType) {
			c_specifierId(data->g, returnType, returnSpec, NULL, returnPostfix);
		} else {
			strcpy(returnSpec, "void");
			*returnPostfix = '\0';
		}

		/* Write identifying comment to headerfile */
		g_fileWrite(data->header, "\n");
		if (callback) {
		    db_id did;
		    g_fileWrite(data->header, "/* callback %s -> %s */\n", db_fullname(db_callback(o)->delegate, did), db_fullname(o, id));
		} else {
		    g_fileWrite(data->header, "/* %s */\n", db_fullname(o, id));
		}

		/* Start of function */
		g_fileWrite(data->header, "%s%s %s",
				returnSpec,
				returnPostfix,
				c_functionName(o, id, data));

		/* Write to sourcefile */
		if (!delegate) {
            g_fileWrite(data->source, "\n");
            if (callback) {
                db_id did;
                g_fileWrite(data->source, "/* callback %s -> %s */\n", db_fullname(db_callback(o)->delegate, did), db_fullname(o, id));
            } else {
                g_fileWrite(data->source, "/* %s */\n", db_fullname(o, id));
            }

			if (db_function(o)->overloaded) {
				db_fullname(o, id);
			} else {
				db_id fullId;
				db_fullname(o, fullId);
				db_signatureName(fullId, id);
			}

            /* Lookup header for function */
            header = g_fileLookupHeader(data->source, id);
            if (header) {
                g_fileWrite(data->source, "/* $header(%s)", id);
                g_fileWrite(data->source, "%s", header);
                g_fileWrite(data->source, "$end */\n");
            }

            g_fileWrite(data->source, "%s%s %s",
                    returnSpec,
                    returnPostfix,
                    c_functionName(o, id, data));

            g_fileWrite(data->source, "(");
            g_fileWrite(data->header, "(");        
		} else {
		    g_fileWrite(data->header, "(");
		}

		/* Add 'this' parameter to methods */
		if (c_procedureHasThis(o)) {
            db_type thisType;
            if(db_procedure(db_typeof(o))->kind != DB_METAPROCEDURE) {
    		    thisType = db_parentof(o);
            }else {
                thisType = db_any_o;
            }
			c_interfaceParamThis(thisType, data, FALSE, TRUE);
			if (!delegate) c_interfaceParamThis(thisType, data, TRUE, FALSE);
			data->firstComma = 1;
		} else {
			data->firstComma = 0;
		}

		/* Walk parameters */
		data->generateHeader = TRUE;
		data->generateSource = !delegate;
		if (!c_interfaceParamWalk(o, c_interfaceMethodParameter, data)) {
			goto error;
		}

		/* Append void if the argumentlist was empty */
		if (!data->firstComma) {
			g_fileWrite(data->header, "void");
			if (!delegate) g_fileWrite(data->source, "void");
		}

		/* Begin of function */
		if (!delegate) {
			if (db_function(o)->overloaded) {
				db_fullname(o, id);
			} else {
				db_id fullId;
				db_fullname(o, fullId);
				db_signatureName(fullId, id);
			}

            g_fileWrite(data->source, ") {\n");
            g_fileWrite(data->source, "/* $begin(%s)", id);
            g_fileIndent(data->source);

            snippet = g_fileLookupSnippet(data->source, id);

            /* Support both short and full name when function is not overloaded */
            if (!snippet && (!db_function(o)->overloaded)) {
            	db_id fullId;
            	db_fullname(o, fullId);
            	snippet = g_fileLookupSnippet(data->source, fullId);
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
                db_id id;
                db_uint32 i;
                db_parameter *p;

                g_fileWrite(data->source, " */\n");

                if ((returnType->real->kind != DB_VOID) || (returnType->real->reference)) {
                    db_id specifier;
                    g_fullOid(data->g, returnType, specifier);
                    g_fileWrite(data->source, "%s _result;\n", specifier);
                } else {
                    returnType = NULL;
                }

                /* If function is already defined, it is already implemented. The generator will generate a stub instead. */
                g_fileWrite(data->source, "db_call(db_function(%s_o)", g_fullOid(data->g, o, id));
                if (returnType) {
                    g_fileWrite(data->source, ",&_result");
                } else {
                    g_fileWrite(data->source, ",NULL");
                }
                if (db_class_instanceof(db_interface_o, db_parentof(o))) {
                    if (db_procedure(db_typeof(o))->kind != DB_FUNCTION) {
                        if (callback) {
                            g_fileWrite(data->source, ",object", classId);
                        } else {
                            g_fileWrite(data->source, ",_this");
                        }
                    }
                }
                for(i=0; i<db_function(o)->parameters.length; i++) {
                    p = &db_function(o)->parameters.buffer[i];
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
		}

		/* End function in header */
		g_fileWrite(data->header, ");\n");

    }

ok:
    return 1;
error:
	return 0;
}

/* Check if there are procedures in the scope of an object. */
static int c_interfaceCheckProcedures(void* o, void* udata) {
    DB_UNUSED(udata);

    /* If the type of the type of the object is a procedure, return 0. */
    if (db_class_instanceof(db_procedure_o, db_typeof(o)->real)) {
        return 0;
    }
    return 1;
}

/* Open generator headerfile */
static g_file c_interfaceHeaderFileOpen(db_generator g, db_object o, c_typeWalk_t *data) {
    g_file result;
    db_id headerFileName, name;
    db_object topLevelObject = g_getCurrent(g);

    /* Create file */
    sprintf(headerFileName, "%s.h", g_fullOid(g, o, name));
    result = g_fileOpen(g, headerFileName);

    if (!result) {
        goto error;
    }

    if (!data->mainHeader) {
        db_id mainHeader, topLevelName;
        if (o == topLevelObject) {
            data->mainHeader = result;
        }else {
            sprintf(mainHeader, "%s.h", g_fullOid(g, topLevelObject, topLevelName));
            data->mainHeader = g_fileOpen(g, mainHeader);
            if(!result) {
                goto error;
            }
        }
    }

    if(o != topLevelObject) {
        g_fileWrite(data->mainHeader, "#include \"%s\"\n", headerFileName);
    }

    /* Print standard comments and includes */
    g_fileWrite(result, "/* %s\n", headerFileName);
    g_fileWrite(result, " *\n");
    g_fileWrite(result, " * This file contains generated code. Do not modify!\n");
    g_fileWrite(result, " */\n\n");
    g_fileWrite(result, "#ifndef %s_H\n", name);
    g_fileWrite(result, "#define %s_H\n\n", name);
    g_fileWrite(result, "#include \"hyve.h\"\n");

    /* If the class extends from another class, include header of baseclass */
    if (db_class_instanceof(db_class_o, o) && db_interface(o)->base) {
        db_id baseId;
        g_fileWrite(result, "#include \"%s.h\"\n", g_fullOid(g, db_interface(o)->base, baseId));
    }

    g_fileWrite(result, "#include \"%s__type.h\"\n\n", g_getName(g));
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

static g_file c_interfaceWrapperFileOpen(db_generator g) {
    g_file result;
    db_char fileName[512];
    db_id id, name;

    db_object o = g_getCurrent(g);
    sprintf(fileName, "%s__wrapper.c", g_fullOid(g, o, name));
    result = g_fileOpen(g, fileName);
    if(!result) {
        goto error;
    }

    /* Print standard comments and includes */
    g_fileWrite(result, "/* %s\n", fileName);
    g_fileWrite(result, " *\n");
    g_fileWrite(result, " * This file contains wrapper functions for %s.\n", db_fullname(o, id));
    g_fileWrite(result, " */\n\n");
    g_fileWrite(result, "#include \"%s.h\"\n", name);
    g_fileWrite(result, "#include \"%s__meta.h\"\n", name);

    return result;
error:
    return NULL;
}

/* Generate name for sourcefile */
static db_string c_interfaceSourceFileName(db_string name, db_char* buffer) {
    /* Create file */
    sprintf(buffer, "%s.c", name);

    return buffer;
}

/* Open generator sourcefile */
static g_file c_interfaceSourceFileOpen(db_generator g, db_string name) {
    g_file result;
    db_char fileName[512];
    db_id topLevelName;

    result = g_fileOpen(g, c_interfaceSourceFileName(name, fileName));
    if (!result) {
        goto error;
    }

    /* Print standard comments and includes */
    g_fileWrite(result, "/* %s\n", fileName);
    g_fileWrite(result, " *\n");
    g_fileWrite(result, " * This file contains the implementation for the generated interface.\n");
    g_fileWrite(result, " *\n");
    g_fileWrite(result, " *    Don't mess with the begin and end tags, since these will ensure that modified\n");
    g_fileWrite(result, " *    code in interface functions isn't replaced when code is re-generated.\n");
    g_fileWrite(result, " */\n\n");
    g_fileWrite(result, "#include \"%s.h\"\n", g_fullOid(g, g_getCurrent(g), topLevelName));
    g_fileWrite(result, "#include \"%s__meta.h\"\n", g_getName(g));

    return result;
error:
    return NULL;
}

/* Generate interface for class */
static db_int16 c_interfaceObject(db_object o, c_typeWalk_t* data) {
    db_id id;
    db_string snippet;
    int hasProcedures;
    db_bool isInterface;

    hasProcedures = !db_scopeWalk(o, c_interfaceCheckProcedures, NULL);
    isInterface = db_class_instanceof(db_interface_o, o);

    /* Always generate header for interfaces */
    if (hasProcedures || isInterface) {
        data->header = c_interfaceHeaderFileOpen(data->g, o, data);
        if (!data->header) {
            goto error;
        }
    }
    
    /* An interface implementation file is generated when the object is
     * an interface and has procedures. When the object is not an interface
     * but does have procedures (typical example is callbacks or static functions)
     * these are appended to the header of the first scope in the hierarchy. */
    if (hasProcedures) {

        /* Create a wrapper file if it was not already created */
        if(!data->wrapper) {
            data->wrapper = c_interfaceWrapperFileOpen(data->g);
            if(!data->wrapper) {
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
        if (!db_scopeWalk(o, c_interfaceClassProcedure, data)) {
            goto error;
        }
    }

    /* Close */
    if (hasProcedures || isInterface) {
    	c_interfaceHeaderFileClose(data->header);
    }

    return 0;
error:
    return 1;
}

/* Walk interfaces */
static int c_interfaceWalk(db_object o, void* userData) {
    c_typeWalk_t* data;

    data = userData;

    /* Parse interfaces */
    if (c_interfaceObject(o, data)) {
        goto error;
    }

    /* Walk scope of object */
    if (!db_scopeWalk(o, c_interfaceWalk, data)) {
        goto error;
    }

    return 1;
error:
    return 0;
}

/* Entry point for generator */
int hyve_genMain(db_generator g) {
    c_typeWalk_t walkData;

	/* Default prefixes for hyve namespaces */
	gen_parse(g, hyve_o, FALSE, FALSE, "");
    gen_parse(g, hyve_lang_o, FALSE, FALSE, "db");

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

    return 0;
error:
    return -1;
}
