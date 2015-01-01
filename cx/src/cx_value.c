/*
 * cx_valueue.c
 *
 *  Created on: Aug 23, 2012
 *      Author: sander
 */

/*
 * cx_value.c
 *
 *  Created on: Apr 13, 2012
 *      Author: sander
 */

#include "cx_object.h"
#include "cx_value.h"
#include "cx_err.h"
#include "cx_struct.h"
#include "cx_class.h"
#include "cx__meta.h"
#include "cx_mem.h"

#include "string.h"

cx_typedef cx_valueType(cx_value* val) {
    cx_typedef result;

    switch(val->kind) {
    case DB_OBJECT:
        result = cx_typeof(val->is.o);
        break;
    case DB_BASE:
        result = val->is.base.t;
        break;
    case DB_VALUE:
        result = val->is.value.t;
        break;
    case DB_LITERAL:
    	switch(val->is.literal.kind) {
    	case DB_LITERAL_BOOLEAN:
    		result = cx_typedef(cx_bool_o);
    		break;
    	case DB_LITERAL_CHARACTER:
    		result = cx_typedef(cx_char_o);
    		break;
    	case DB_LITERAL_INTEGER:
    		result = cx_typedef(cx_int64_o);
    		break;
    	case DB_LITERAL_UNSIGNED_INTEGER:
    		result = cx_typedef(cx_uint64_o);
    		break;
    	case DB_LITERAL_FLOATING_POINT:
    		result = cx_typedef(cx_float64_o);
    		break;
    	case DB_LITERAL_STRING:
    		result = cx_typedef(cx_string_o);
    		break;
    	default:
    		cx_critical("cx_valueType: invalid cx_literalKind(%d)", val->is.literal.kind);
    		result = NULL;
    		break;
    	}
    	break;
    case DB_MEMBER:
        result = val->is.member.t->type;
        break;
    case DB_CALL:
    	result = val->is.call.t->returnType;
    	break;
    case DB_CONSTANT:
        result = cx_valueType(val->parent);
        break;
    case DB_ELEMENT:
        result = val->is.element.t.type;
        break;
    case DB_MAP_ELEMENT:
    	result = val->is.mapElement.t.type;
    	break;
    default:
        cx_critical("cx_valueType: invalid cx_valueKind(%d).", val->kind);
        result = NULL;
        break;
    }

    return result;
}

cx_void* cx_valueValue(cx_value* val) {
    cx_void* result;
    switch(val->kind) {
    case DB_OBJECT:
        result = val->is.o;
        break;
    case DB_BASE:
        result = val->is.base.v;
        break;
    case DB_LITERAL:
    	result = &val->is.literal.v;
    	break;
    case DB_VALUE:
        result = val->is.value.v;
        break;
    case DB_MEMBER:
        result = val->is.member.v;
        break;
    case DB_CALL:
    	result = NULL; /* A call has no value */
    	break;
    case DB_CONSTANT:
        result = val->is.constant.v;
        break;
    case DB_ELEMENT:
        result = val->is.element.v;
        break;
    case DB_MAP_ELEMENT:
    	result = val->is.mapElement.v;
    	break;
    default:
        cx_critical("cx_valueValue: invalid cx_valueKind(%d).", val->kind);
        result = NULL;
        break;
    }
    return result;
}

cx_object cx_valueObject(cx_value* val) {
    cx_object result;

    switch(val->kind) {
    case DB_OBJECT:
        result = val->is.o;
        break;
    case DB_BASE:
        result = val->is.base.o;
        break;
    case DB_LITERAL:
    	result = NULL;
    	break;
    case DB_VALUE:
        result = val->is.value.o;
        break;
    case DB_MEMBER:
        result = val->is.member.o;
        break;
    case DB_CALL:
    	result = val->is.call.o;
    	break;
    case DB_CONSTANT:
        result = val->is.constant.o;
        break;
    case DB_ELEMENT:
        result = val->is.element.o;
        break;
    case DB_MAP_ELEMENT:
    	result = val->is.mapElement.o;
    	break;
    default:
        cx_critical("cx_valueObject: invalid cx_valueKind(%d).", val->kind);
        result = NULL;
        break;
    }
    return result;
}

cx_function cx_valueFunction(cx_value* val) {
    cx_function result;

    switch(val->kind) {
    case DB_OBJECT:
        if (cx_class_instanceof(cx_procedure_o, cx_typeof(val->is.o))) {
            result = val->is.o;
        } else {
            cx_id id;
            cx_error("object '%s' in value is not a function", cx_fullname(val->is.o, id));
            result = NULL;
        }
        break;
    case DB_CALL:
        result = val->is.call.t;
        break;
    default:
       cx_error("value does not represent a function");
       result = NULL;
       break;
    }

    return result;
}

cx_uint32 cx_valueIndex(cx_value* val) {
    cx_uint32 result = 0;
    switch(val->kind) {
    case DB_ELEMENT:
        result = val->is.element.t.index;
        break;
    default:
        cx_error("cannot obtain index from non-element value");
        break;
    }
    return result;
}

cx_void *cx_valueThis(cx_value* val) {
    cx_void *result;

    switch(val->kind) {
    case DB_CALL:
        if (val->parent) {
            result = cx_valueValue(val->parent);
        } else {
            cx_critical("valuestack corrupt (cannot obtain this)");
            result = NULL;
        }
        break;
    default:
        cx_error("value does not represent a method");
        result = NULL;
        break;
    }

    return result;
}

static char* cx_valueKindString[DB_CONSTANT+1] = {"object", "base", "member", "constant", "element"};

char* cx_valueString(cx_value* v, char* buffer, unsigned int length) {
    cx_id object_name;
    cx_member m;
    cx_value* parents[DB_MAX_TYPE_DEPTH];
    cx_int32 parentCount, i;
    cx_value* vptr;

    if (length < (strlen("ELEMENT") + 3)) {
        cx_error("buffer passed to cx_valueString is too short.");
        goto error;
    }

    /* Put label in buffer */
    sprintf(buffer, "%s ", cx_valueKindString[v->kind]);

    /* Get name of object */
    cx_fullname(cx_valueObject(v), object_name);
    if ((strlen(buffer) + (strlen(object_name) + 2 + 1)) >= length) {
        cx_error("buffer passed to cx_valueString is too short for object name.");
        goto error;
    }

    /* Put objectname in buffer */
    strcat(buffer, object_name);

    /* Collect parents */
    parentCount = 0;
    vptr = v;
    do{
        if (vptr->kind != DB_OBJECT) {
            parents[parentCount] = vptr;
            parentCount++;
        }
    }while((vptr = vptr->parent));

    /* Put name of member or branch in buffer */
    for(i=parentCount-1; i>=0; i--) {
        vptr = parents[i];
        m = NULL;
        switch(vptr->kind) {
        case DB_LITERAL:
        case DB_VALUE:
            /* Nothing to add for just a value */
            break;
        case DB_BASE:
            break;
        case DB_MEMBER:
            m = vptr->is.member.t;
            break;
        case DB_ELEMENT:
            sprintf(buffer, "%s[%d]", buffer, vptr->is.element.t.index);
            m = NULL;
            break;
        default:
            cx_trace("cx_valueString: unhandled '%s'", cx_valueKindString[vptr->kind]);
            m = NULL;
            break;
        }
        if (m) {
            if ((strlen(buffer) + strlen(cx_nameof(m)) + 1) >= length) {
                cx_error("buffer passed to cx_valueString is too short for member name");
            } else {
                strcat(buffer, ".");
                strcat(buffer, cx_nameof(m));
            }
        }
    }

    return buffer;
error:
    return NULL;
}

char* cx_valueExpr(cx_value* v, char* buffer, unsigned int length) {
    cx_member m;
    cx_value* parents[DB_MAX_TYPE_DEPTH];
    cx_int32 parentCount, i;
    cx_value* vptr;

    *buffer = '\0';

    /* Collect parents */
    parentCount = 0;
    vptr = v;
    do{
        if (vptr->kind != DB_OBJECT) {
            parents[parentCount] = vptr;
            parentCount++;
        }
    }while((vptr = vptr->parent));

    /* Put name of member or branch in buffer */
    for(i=parentCount-1; i>=0; i--) {
        vptr = parents[i];
        m = NULL;
        switch(vptr->kind) {
        case DB_LITERAL:
        case DB_VALUE:
            break;
        case DB_BASE:
            break;
        case DB_MEMBER:
            m = vptr->is.member.t;
            break;
        case DB_ELEMENT:
            sprintf(buffer, "%s[%d]", buffer, vptr->is.element.t.index);
            m = NULL;
            break;
        default:
            cx_trace("cx_valueExpr: unhandled '%s'", cx_valueKindString[vptr->kind]);
            m = NULL;
            goto error;
        }
        if (m) {
            if ((strlen(buffer) + strlen(cx_nameof(m)) + 1) >= length) {
                cx_error("buffer passed to cx_valueString is too short for member name");
            } else {
                strcat(buffer, ".");
                strcat(buffer, cx_nameof(m));
            }
        }
    }

    return buffer;
error:
    return NULL;
}

void cx_valueObjectInit(cx_value* val, cx_object o) {
    val->kind = DB_OBJECT;
    val->is.o = o;
}

void cx_valueBaseInit(cx_value* val, cx_void *v, cx_typedef t) {
    val->kind = DB_BASE;
    val->is.base.v = v;
    val->is.base.t = t;
}

void cx_valueValueInit(cx_value* val, cx_object o, cx_typedef t, cx_void* v) {
    val->parent = NULL;
    val->kind = DB_VALUE;
    val->is.value.o = o;
    val->is.value.t = t;
    val->is.value.v = v;
}
void cx_valueMemberInit(cx_value* val, cx_object o, cx_member t, cx_void* v) {
    val->kind = DB_MEMBER;
    val->is.member.o = o;
    val->is.member.t = t;
    val->is.member.v = v;
}
void cx_valueCallInit(cx_value* val, cx_object o, cx_function t) {
    val->kind = DB_CALL;
    val->is.call.o = o;
    val->is.call.t = t;
}
void cx_valueConstantInit(cx_value* val, cx_object o, cx_constant* t, cx_void* v) {
    val->kind = DB_CONSTANT;
    val->is.constant.o = o;
    val->is.constant.t = t;
    val->is.constant.v = v;
}
void cx_valueElementInit(cx_value* val, cx_object o, cx_typedef t, cx_uint32 index, cx_void* v) {
    val->kind = DB_ELEMENT;
    val->is.element.o = o;
    val->is.element.t.type = t;
    val->is.element.t.index = index;
    val->is.element.v = v;
}

void cx_valueMapElementInit(cx_value* val, cx_object o, cx_typedef t, cx_typedef keyType, cx_void *key, cx_void* v) {
    val->kind = DB_MAP_ELEMENT;
    val->is.mapElement.o = o;
    val->is.mapElement.t.type = t;
    val->is.mapElement.t.keyType = keyType;
    val->is.mapElement.t.key = key;
    val->is.mapElement.v = v;
}

void cx_valueLiteralInit(cx_value* val, cx_literalKind kind, cx_void* value) {
	val->kind = DB_LITERAL;
	val->is.literal.kind = kind;

	switch(kind) {
	case DB_LITERAL_BOOLEAN:
		val->is.literal.v._boolean = *(cx_bool*)value;
		break;
	case DB_LITERAL_CHARACTER:
		val->is.literal.v._character = *(cx_char*)value;
		break;
	case DB_LITERAL_INTEGER:
		val->is.literal.v._integer = *(cx_int64*)value;
		break;
	case DB_LITERAL_UNSIGNED_INTEGER:
		val->is.literal.v._unsigned_integer = *(cx_uint64*)value;
		break;
	case DB_LITERAL_FLOATING_POINT:
		val->is.literal.v._floating_point = *(cx_float64*)value;
		break;
	case DB_LITERAL_STRING:
		if (*(cx_string*)value) {
			val->is.literal.v._string = cx_strdup(*(cx_string*)value);
		} else {
			val->is.literal.v._string = NULL;
		}
		break;
	case DB_LITERAL_NULL:
		break;
	}
}

void cx_valueSetValue(cx_value* val, cx_void* v) {
	switch(val->kind) {
	case DB_OBJECT:
		val->is.o = v; /* Dangerous, but allowed */
		break;
	case DB_BASE:
	    val->is.base.v = v;
	    break;
	case DB_MEMBER:
		val->is.member.v = v;
		break;
	case DB_CONSTANT:
		val->is.constant.v = v;
		break;
	case DB_ELEMENT:
		val->is.element.v = v;
		break;
	case DB_MAP_ELEMENT:
		val->is.mapElement.v = v;
		break;
	default:
		cx_assert(0, "cx_valueSetValue: invalid valueKind %d.", val->kind);
		break;
	}
}

void cx_valueFree(cx_value* val) {
    switch(val->kind) {
    case DB_LITERAL:
        switch(val->is.literal.kind) {
        case DB_LITERAL_STRING:
            cx_dealloc(val->is.literal.v._string);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

void cx_valueStackFree(cx_value* valueStack, cx_uint32 count) {
    cx_uint32 i;
    for(i=0; i<count; i++) {
        cx_valueFree(&valueStack[i]);
    }
}

