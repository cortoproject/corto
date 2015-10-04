#include "c_api.h"
#include "c_common.h"
#include "ctype.h"

/* Translate members to function parameters. */
static cx_int16 c_apiAssignMember(cx_serializer s, cx_value* v, void* userData) {
    c_apiWalk_t* data;
    cx_member m;
    cx_id memberIdTmp, memberParamId, memberId;

    CX_UNUSED(s);

    if (v->kind == CX_MEMBER) {
        m = v->is.member.t;
        data = userData;

        cx_genMemberName(data->g, data->memberCache, m, memberIdTmp);
        g_id(data->g, memberIdTmp, memberParamId);
        g_id(data->g, cx_nameof(m), memberId);

        /* If member is of array-type, use memcpy */
        if ((m->type->kind == CX_COLLECTION) && (cx_collection(m->type)->kind == CX_ARRAY)) {
            cx_id typeId, postfix;
            /* Get typespecifier */
            if (c_specifierId(data->g, m->type, typeId, NULL, postfix)) {
                goto error;
            }
            g_fileWrite(data->source, "memcpy(");

            /* Cast object to right type */
            if (data->current == cx_parentof(m)) {
                g_fileWrite(data->source, "this->%s",
                        memberId);
            } else {
                cx_id typeId;
                g_fileWrite(data->source, "%s(this)->%s",
                        g_fullOid(data->g, cx_parentof(m), typeId), memberId);
            }

            g_fileWrite(data->source, ", %s, sizeof(%s%s));\n", memberParamId, typeId, postfix);
        } else {
            if (m->type->reference) {
                g_fileWrite(data->source, "cx_setref(&");
            } else if ((m->type->kind == CX_PRIMITIVE) && (cx_primitive(m->type)->kind == CX_TEXT)) {
                g_fileWrite(data->source, "cx_setstr(&");
            }

            /* Cast object to right type */
            if (data->current == cx_parentof(m)) {
                g_fileWrite(data->source, "this->%s",
                        memberId);
            } else {
                if (cx_type(cx_parentof(m))->reference) {
                    cx_id typeId;
                    g_fileWrite(data->source, "%s(this)->%s",
                            g_fullOid(data->g, cx_parentof(m), typeId), memberId);
                } else {
                    cx_id typeId;
                    g_fileWrite(data->source, "((%s*)this)->%s",
                            g_fullOid(data->g, cx_parentof(m), typeId), memberId);                    
                }
            }

            /* Strdup strings */
            if ((m->type->kind == CX_PRIMITIVE) && (cx_primitive(m->type)->kind == CX_TEXT)) {
                g_fileWrite(data->source, ", %s);\n", memberParamId);
            } else if (m->type->reference) {
                if (m->type->kind != CX_VOID) {
                    cx_id id;
                    g_fileWrite(data->source, ", %s(%s));\n", g_fullOid(data->g, m->type, id), memberParamId);
                } else {
                    g_fileWrite(data->source, ", %s);\n", memberParamId);
                }
            } else {
                g_fileWrite(data->source, " = %s;\n", memberParamId);  
            }
        }

        data->parameterCount++;
    }

    return 0;
error:
    return -1;
}

/* Translate members to function parameters. */
static cx_int16 c_apiParamMember(cx_serializer s, cx_value* v, void* userData) {
    c_apiWalk_t* data;
    cx_member m;
    cx_id typeSpec, typePostfix, memberIdTmp, memberId;

    CX_UNUSED(s);

    if (v->kind == CX_MEMBER) {
        m = v->is.member.t;
        data = userData;

        if (data->parameterCount) {
            g_fileWrite(data->header, ", ");
            g_fileWrite(data->source, ", ");
        }

        /* Get type-specifier */
        c_specifierId(data->g, m->type, typeSpec, NULL, typePostfix);
        cx_genMemberName(data->g, data->memberCache, m, memberIdTmp);

        g_fileWrite(data->header, "%s%s %s",
               typeSpec, typePostfix, g_id(data->g, memberIdTmp, memberId));

        g_fileWrite(data->source, "%s%s %s",
                typeSpec, typePostfix, g_id(data->g, memberIdTmp, memberId));

        data->parameterCount++;
    }

    return 0;
}

/* Member parameter serializer */
static struct cx_serializer_s c_apiParamSerializer(void) {
    struct cx_serializer_s s;

    cx_serializerInit(&s);
    s.metaprogram[CX_MEMBER] = c_apiParamMember;
    s.access = CX_LOCAL|CX_READONLY|CX_PRIVATE|CX_HIDDEN;
    s.accessKind = CX_NOT;

    return s;
}

/* Member parameter serializer */
static struct cx_serializer_s c_apiAssignSerializer(void) {
    struct cx_serializer_s s;

    cx_serializerInit(&s);
    s.metaprogram[CX_MEMBER] = c_apiAssignMember;
    s.access = CX_LOCAL|CX_READONLY|CX_PRIVATE|CX_HIDDEN;
    s.accessKind = CX_NOT;

    return s;
}

cx_int16 c_apiTypeCreateIntern(cx_type t, c_apiWalk_t *data, cx_string func, cx_bool scoped, cx_bool define) {
    cx_id id;
    struct cx_serializer_s s;

    data->parameterCount = 0;
    g_fullOid(data->g, t, id);

    /* Function declaration */
    c_writeExport(data->g, data->header);
    g_fileWrite(data->header, "%s%s %s%s(", id, t->reference ? "" : "*", id, func);

    /* Function implementation */
    g_fileWrite(data->source, "%s%s %s%s(", id, t->reference ? "" : "*", id, func);

    if (scoped) {
        g_fileWrite(data->header, "cx_object _parent, cx_string _name");
    	g_fileWrite(data->source, "cx_object _parent, cx_string _name");
    	data->parameterCount = 2;
    }

    /* Write public members as arguments for source and header */
    if (define) {
	    if (t->kind == CX_COMPOSITE) {
		    s = c_apiParamSerializer();
		    cx_metaWalk(&s, cx_type(t), data);
		}

        if ((t->kind != CX_COMPOSITE) && (t->kind != CX_COLLECTION) && (t->kind != CX_VOID)) {
            if (data->parameterCount) {
                g_fileWrite(data->source, ", ");
                g_fileWrite(data->header, ", ");
            }
            g_fileWrite(data->source, "%s value", id);
            g_fileWrite(data->header, "%s value", id);
            data->parameterCount++;
        }

        if (cx_instanceof(cx_procedure_o, t)) {
            if (data->parameterCount) {
                g_fileWrite(data->source, ", ");
                g_fileWrite(data->header, ", ");
            }
            g_fileWrite(data->source, "void(*_impl)(cx_function f, void *result, void *args)");
            g_fileWrite(data->header, "void(*_impl)(cx_function f, void *result, void *args)");
            data->parameterCount++;
        }
	}

    /* If there are no parameters, write 'void' */
    if (!data->parameterCount) {
        g_fileWrite(data->header, "void");
        g_fileWrite(data->source, "void");
    }

    /* Write closing brackets for argumentlist in source and header */
    g_fileWrite(data->header, ");\n");
    g_fileWrite(data->source, ") {\n");

    g_fileIndent(data->source);
    g_fileWrite(data->source, "%s%s this;\n", id, t->reference ? "" : "*");
    if (scoped) {
		g_fileWrite(data->source, "this = cx_declareChild(_parent, _name, %s_o);\n", id);
    } else {
	    g_fileWrite(data->source, "this = cx_declare(%s_o);\n", id);
	}

    g_fileWrite(data->source, "if (!this) {\n");
    g_fileIndent(data->source);
    g_fileWrite(data->source, "return NULL;\n");
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n");

    if (define) {
	    /* Assignments */
        if ((t->kind != CX_COMPOSITE) && (t->kind != CX_COLLECTION) && (t->kind != CX_VOID)) {
            g_fileWrite(data->source, "*this = value;\n");
        } else {
    	    s = c_apiAssignSerializer();
    	    cx_metaWalk(&s, cx_type(t), data);

            if (cx_instanceof(cx_procedure_o, t)) {
                g_fileWrite(data->source, "cx_function(this)->impl = (cx_word)_impl;\n");
            }
        }
        if (t->kind != CX_VOID) {
            /* Define object */
            g_fileWrite(data->source, "if (this && cx_define(this)) {\n");
            g_fileIndent(data->source);
            g_fileWrite(data->source, "cx_release(this);\n");
            g_fileWrite(data->source, "this = NULL;\n");
            g_fileDedent(data->source);
            g_fileWrite(data->source, "}\n");            
        }
	}

    g_fileWrite(data->source, "return this;\n");
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");

    return 0;
}

cx_int16 c_apiTypeCreate(cx_type t, c_apiWalk_t *data) {
	return c_apiTypeCreateIntern(t, data, "Create", FALSE, TRUE);
}

cx_int16 c_apiTypeCreateChild(cx_type t, c_apiWalk_t *data) {
	return c_apiTypeCreateIntern(t, data, "CreateChild", TRUE, TRUE);
}

cx_int16 c_apiTypeDeclare(cx_type t, c_apiWalk_t *data) {
	return c_apiTypeCreateIntern(t, data, "Declare", FALSE, FALSE);
}

cx_int16 c_apiTypeDeclareChild(cx_type t, c_apiWalk_t *data) {
	return c_apiTypeCreateIntern(t, data, "DeclareChild", TRUE, FALSE);
}

cx_int16 c_apiTypeDefineIntern(cx_type t, c_apiWalk_t *data, cx_bool isUpdate, cx_bool doUpdate) {
    cx_id id;
    struct cx_serializer_s s;
    cx_string func = isUpdate ? doUpdate ? "Update" : "Set" : "Define";

    data->parameterCount = 1;
    g_fullOid(data->g, t, id);

    c_writeExport(data->g, data->header);

    if (isUpdate) {
    	g_fileWrite(data->header, "void ");
    	g_fileWrite(data->source, "void ");
    } else {
    	g_fileWrite(data->header, "cx_int16 ");
    	g_fileWrite(data->source, "cx_int16 ");
    }

    /* Function declaration */
    g_fileWrite(data->header, "%s%s(%s%s this", id, func, id, t->reference ? "" : "*");

    /* Function implementation */
    g_fileWrite(data->source, "%s%s(%s%s this", id, func, id, t->reference ? "" : "*");

    /* Write public members as arguments for source and header */
    if (t->kind == CX_COMPOSITE) {
	    s = c_apiParamSerializer();
	    cx_metaWalk(&s, cx_type(t), data);
	}

    if ((data->parameterCount == 1) && (t->kind != CX_COMPOSITE)) {
        g_fileWrite(data->source, ", %s value", id);
        g_fileWrite(data->header, ", %s value", id);
    }

    if (cx_instanceof(cx_procedure_o, t) && !strcmp(func, "Define")) {
        if (data->parameterCount) {
            g_fileWrite(data->source, ", ");
            g_fileWrite(data->header, ", ");
        }
        g_fileWrite(data->source, "void(*_impl)(cx_function f, void *result, void *args)");
        g_fileWrite(data->header, "void(*_impl)(cx_function f, void *result, void *args)");
        data->parameterCount++;        
    }

    /* Write closing brackets for argumentlist in source and header */
    g_fileWrite(data->header, ");\n");
    g_fileWrite(data->source, ") {\n");
    g_fileIndent(data->source);

    if (isUpdate && doUpdate && (data->parameterCount > 1)) {
    	g_fileWrite(data->source, "cx_updateBegin(this);\n");
    }

    /* Member assignments */
    if (data->parameterCount > 1) {
        s = c_apiAssignSerializer();
        cx_metaWalk(&s, cx_type(t), data);
    } else if (t->kind != CX_COMPOSITE) {
        if (t->kind != CX_COLLECTION) {
            g_fileWrite(data->source, "*this = value;\n");
        } else {
            if (cx_collection(t)->kind == CX_SEQUENCE) {
                g_fileWrite(data->source, "cx_copyp(this, %s_o, &value);\n", id);
            } else {
                g_fileWrite(data->source, "cx_copyp(this, %s_o, value);\n", id);
            }
        }
    } else if (isUpdate && !doUpdate) {
        g_fileWrite(data->source, "CX_UNUSED(this);\n");
    }

    /* Define object */
    if (isUpdate && doUpdate) {
        if (data->parameterCount > 1) {
            g_fileWrite(data->source, "cx_updateEnd(this);\n");
        } else {
            g_fileWrite(data->source, "cx_update(this);\n");
        }
    } else if (!isUpdate) {
        if (cx_instanceof(cx_procedure_o, t)) {
            g_fileWrite(data->source, "cx_function(this)->impl = (cx_word)_impl;\n");
        }
	    g_fileWrite(data->source, "return cx_define(this);\n");
	}

    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");
    
    return 0;
}

cx_int16 c_apiTypeDefine(cx_type t, c_apiWalk_t *data) {
	return c_apiTypeDefineIntern(t, data, FALSE, FALSE);
}

cx_int16 c_apiTypeUpdate(cx_type t, c_apiWalk_t *data) {
	return c_apiTypeDefineIntern(t, data, TRUE, TRUE);
}

cx_int16 c_apiTypeSet(cx_type t, c_apiWalk_t *data) {
    return c_apiTypeDefineIntern(t, data, TRUE, FALSE);
}

cx_int16 c_apiTypeStr(cx_type t, c_apiWalk_t *data) {
    cx_id id;
    cx_bool pointer = (t->kind == CX_COMPOSITE) && !t->reference;

    g_fullOid(data->g, t, id);

    /* Function declaration */
    c_writeExport(data->g, data->header);
    g_fileWrite(data->header, "cx_string %sStr(%s%s value);\n", id, id, pointer ? "*" : "");

    /* Function implementation */
    g_fileWrite(data->source, "cx_string %sStr(%s%s value) {\n", id, id, pointer ? "*" : "");

    g_fileIndent(data->source);
    g_fileWrite(data->source, "cx_string result;\n", id);

    g_fileWrite(data->source, "cx_value v;\n", id);
    if (t->reference) {
        g_fileWrite(data->source, "cx_valueObjectInit(&v, value, cx_type(%s_o));\n", id);
    } else {
        g_fileWrite(data->source, "cx_valueValueInit(&v, NULL, cx_type(%s_o), &value);\n", id);
    }
    g_fileWrite(data->source, "result = cx_strv(&v, 0);\n");

    g_fileWrite(data->source, "return result;\n");
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");

    return 0;
}

static cx_int16 c_apiTypeInitIntern(cx_type t, c_apiWalk_t *data, cx_string func) {
    cx_id id, funcLower;

    g_fullOid(data->g, t, id);

    /* Function declaration */
    c_writeExport(data->g, data->header);
    g_fileWrite(data->header, "cx_int16 %s%s(%s%s value);\n", id, func, id, t->reference ? "" : "*");

    /* Function implementation */
    g_fileWrite(data->source, "cx_int16 %s%s(%s%s value) {\n", id, func, id, t->reference ? "" : "*");

    g_fileIndent(data->source);
    g_fileWrite(data->source, "cx_int16 result;\n", id);

    if (!strcmp(func, "Init")) {
        g_fileWrite(data->source, "memset(value, 0, cx_type(%s_o)->size);\n", id);
    }

    strcpy(funcLower, func);
    *funcLower = tolower(*funcLower);

    if (t->reference) {
        g_fileWrite(data->source, "result = cx_%s(value, 0);\n", funcLower);
    } else {
        g_fileWrite(data->source, "cx_value v;\n", id);
        g_fileWrite(data->source, "cx_valueValueInit(&v, NULL, cx_type(%s_o), value);\n", id);
        g_fileWrite(data->source, "result = cx_%sv(&v);\n", funcLower);
    }

    g_fileWrite(data->source, "return result;\n");
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");

    return 0;
}

cx_int16 c_apiTypeInit(cx_type t, c_apiWalk_t *data) {
	return c_apiTypeInitIntern(t, data, "Init");
}

cx_int16 c_apiTypeDeinit(cx_type t, c_apiWalk_t *data) {
	return c_apiTypeInitIntern(t, data, "Deinit");
}

cx_int16 c_apiTypeFromStr(cx_type t, c_apiWalk_t *data) {
    cx_id id;

    g_fullOid(data->g, t, id);

    /* Function declaration */
    c_writeExport(data->g, data->header);
    g_fileWrite(data->header, "%s%s %sFromStr(%s%s value, cx_string str);\n", 
    	id, t->reference ? "" : "*", id, id, t->reference ? "" : "*");

    /* Function implementation */
    g_fileWrite(data->source, "%s%s %sFromStr(%s%s value, cx_string str) {\n", 
    	id, t->reference ? "" : "*", id, id, t->reference ? "" : "*");

    g_fileIndent(data->source);
    g_fileWrite(data->source, "cx_fromStrp(&value, cx_type(%s_o), str);\n", id);
    g_fileWrite(data->source, "return value;\n");
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");

    return 0;
}

cx_int16 c_apiTypeCopyIntern(cx_type t, c_apiWalk_t *data, cx_string func, cx_bool outParam) {
    cx_id id, funcLower;

    g_fullOid(data->g, t, id);

    /* Function declaration */
    c_writeExport(data->g, data->header);
    g_fileWrite(data->header, "cx_int16 %s%s(%s%s %sdst, %s%s src);\n", 
    	id, func, id, t->reference ? "" : "*", outParam ? "*" : "", id, t->reference ? "" : "*");

    /* Function implementation */
    g_fileWrite(data->source, "cx_int16 %s%s(%s%s %sdst, %s%s src) {\n", 
    	id, func, id, t->reference ? "" : "*", outParam ? "*" : "", id, t->reference ? "" : "*");

    g_fileIndent(data->source);

    strcpy(funcLower, func);
    *funcLower = tolower(*funcLower);

	if (t->reference) {
		g_fileWrite(data->source, "return cx_%s(%sdst, src);\n", funcLower, outParam ? "(cx_object*)" : "");
	} else {
		g_fileWrite(data->source, "cx_value v1, v2;\n", id);
	    g_fileWrite(data->source, "cx_valueValueInit(&v1, NULL, cx_type(%s_o), dst);\n", id);
	    g_fileWrite(data->source, "cx_valueValueInit(&v2, NULL, cx_type(%s_o), src);\n", id);
	    g_fileWrite(data->source, "return cx_%sv(&v1, &v2);\n", funcLower);
	}

	g_fileDedent(data->source);
	g_fileWrite(data->source, "}\n\n");

	return 0;
}

cx_int16 c_apiTypeCopy(cx_type t, c_apiWalk_t *data) {
	return c_apiTypeCopyIntern(t, data, "Copy", TRUE);
}

cx_int16 c_apiTypeCompare(cx_type t, c_apiWalk_t *data) {
	return c_apiTypeCopyIntern(t, data, "Compare", FALSE);	
}

cx_int16 c_apiDelegateCall(cx_delegate t, c_apiWalk_t *data) {
    cx_id returnId, id, paramType, paramName;
    g_fullOid(data->g, t->returnType, returnId);
    g_fullOid(data->g, t, id);
    cx_bool hasReturn = t->returnType->reference || (t->returnType->kind != CX_VOID);

    g_fileWrite(data->header, "cx_int16 %sCall(%s *_delegate", id, id);
    g_fileWrite(data->source, "cx_int16 %sCall(%s *_delegate", id, id);

    if (hasReturn) {
        g_fileWrite(data->header, ", %s* _result", returnId);
        g_fileWrite(data->source, ", %s* _result", returnId);
    }

    {cx_parameterseqForeach(t->parameters, p) {
        g_fullOid(data->g, p.type, paramType);
        g_id(data->g, p.name, paramName);
        g_fileWrite(data->header, ", %s%s %s", paramType, p.passByReference ? "&" : "", paramName);
        g_fileWrite(data->source, ", %s%s %s", paramType, p.passByReference ? "&" : "", paramName);
    }}

    g_fileWrite(data->header, ");\n");
    g_fileWrite(data->source, ") {\n");
    g_fileIndent(data->source);

    g_fileWrite(data->source, "if (_delegate->_parent.procedure) {\n");
    g_fileIndent(data->source);
    g_fileWrite(data->source, "if (_delegate->_parent.instance) {\n");
    g_fileIndent(data->source);
    if (hasReturn) {
        g_fileWrite(data->source, "cx_call(_delegate->_parent.procedure, _result, _delegate->_parent.instance");
    } else {
        g_fileWrite(data->source, "cx_call(_delegate->_parent.procedure, NULL, _delegate->_parent.instance");        
    }
    {cx_parameterseqForeach(t->parameters, p) {
        g_fullOid(data->g, p.type, paramType);
        g_id(data->g, p.name, paramName);
        g_fileWrite(data->source, ", %s", paramName);
    }}
    g_fileWrite(data->source, ");\n");
    g_fileDedent(data->source);
    g_fileWrite(data->source, "} else {\n");
    g_fileIndent(data->source);
    if (hasReturn) {
        g_fileWrite(data->source, "cx_call(_delegate->_parent.procedure, _result");
    } else {
        g_fileWrite(data->source, "cx_call(_delegate->_parent.procedure, NULL");        
    }
    {cx_parameterseqForeach(t->parameters, p) {
        g_fullOid(data->g, p.type, paramType);
        g_id(data->g, p.name, paramName);
        g_fileWrite(data->source, ", %s", paramName);
    }}
    g_fileWrite(data->source, ");\n");
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n");
    g_fileDedent(data->source);
    g_fileWrite(data->source, "} else {\n");
    g_fileIndent(data->source);
    g_fileWrite(data->source, "return -1;\n");
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n");
    g_fileWrite(data->source, "return 0;\n");
    g_fileDedent(data->source);
    g_fileWrite(data->source, "}\n\n");

    return 0;
}
