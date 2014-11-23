/*
 * db_valueue.c
 *
 *  Created on: Aug 23, 2012
 *      Author: sander
 */

/*
 * db_value.c
 *
 *  Created on: Apr 13, 2012
 *      Author: sander
 */

#include "db_object.h"
#include "db_value.h"
#include "db_err.h"
#include "db_struct.h"
#include "db_class.h"
#include "db__meta.h"
#include "db_mem.h"

#include "string.h"

db_typedef db_valueType(db_value* val) {
    db_typedef result;

    switch(val->kind) {
    case DB_OBJECT:
        result = db_typeof(val->is.o);
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
    		result = db_typedef(db_bool_o);
    		break;
    	case DB_LITERAL_CHARACTER:
    		result = db_typedef(db_char_o);
    		break;
    	case DB_LITERAL_INTEGER:
    		result = db_typedef(db_int64_o);
    		break;
    	case DB_LITERAL_UNSIGNED_INTEGER:
    		result = db_typedef(db_uint64_o);
    		break;
    	case DB_LITERAL_FLOATING_POINT:
    		result = db_typedef(db_float64_o);
    		break;
    	case DB_LITERAL_STRING:
    		result = db_typedef(db_string_o);
    		break;
    	default:
    		db_critical("db_valueType: invalid db_literalKind(%d)", val->is.literal.kind);
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
        result = db_valueType(val->parent);
        break;
    case DB_ELEMENT:
        result = val->is.element.t.type;
        break;
    case DB_MAP_ELEMENT:
    	result = val->is.mapElement.t.type;
    	break;
    default:
        db_critical("db_valueType: invalid db_valueKind(%d).", val->kind);
        result = NULL;
        break;
    }

    return result;
}

db_void* db_valueValue(db_value* val) {
    db_void* result;
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
        db_critical("db_valueValue: invalid db_valueKind(%d).", val->kind);
        result = NULL;
        break;
    }
    return result;
}

db_object db_valueObject(db_value* val) {
    db_object result;

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
        db_critical("db_valueObject: invalid db_valueKind(%d).", val->kind);
        result = NULL;
        break;
    }
    return result;
}

db_function db_valueFunction(db_value* val) {
    db_function result;

    switch(val->kind) {
    case DB_OBJECT:
        if (db_class_instanceof(db_procedure_o, db_typeof(val->is.o))) {
            result = val->is.o;
        } else {
            db_id id;
            db_error("object '%s' in value is not a function", db_fullname(val->is.o, id));
            result = NULL;
        }
        break;
    case DB_CALL:
        result = val->is.call.t;
        break;
    default:
       db_error("value does not represent a function");
       result = NULL;
       break;
    }

    return result;
}

db_uint32 db_valueIndex(db_value* val) {
    db_uint32 result = 0;
    switch(val->kind) {
    case DB_ELEMENT:
        result = val->is.element.t.index;
        break;
    default:
        db_error("cannot obtain index from non-element value");
        break;
    }
    return result;
}

db_void *db_valueThis(db_value* val) {
    db_void *result;

    switch(val->kind) {
    case DB_CALL:
        if (val->parent) {
            result = db_valueValue(val->parent);
        } else {
            db_critical("valuestack corrupt (cannot obtain this)");
            result = NULL;
        }
        break;
    default:
        db_error("value does not represent a method");
        result = NULL;
        break;
    }

    return result;
}

static char* db_valueKindString[DB_CONSTANT+1] = {"object", "base", "member", "constant", "element"};

char* db_valueString(db_value* v, char* buffer, unsigned int length) {
    db_id object_name;
    db_member m;
    db_value* parents[DB_MAX_TYPE_DEPTH];
    db_int32 parentCount, i;
    db_value* vptr;

    if (length < (strlen("ELEMENT") + 3)) {
        db_error("buffer passed to db_valueString is too short.");
        goto error;
    }

    /* Put label in buffer */
    sprintf(buffer, "%s ", db_valueKindString[v->kind]);

    /* Get name of object */
    db_fullname(db_valueObject(v), object_name);
    if ((strlen(buffer) + (strlen(object_name) + 2 + 1)) >= length) {
        db_error("buffer passed to db_valueString is too short for object name.");
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
            db_trace("db_valueString: unhandled '%s'", db_valueKindString[vptr->kind]);
            m = NULL;
            break;
        }
        if (m) {
            if ((strlen(buffer) + strlen(db_nameof(m)) + 1) >= length) {
                db_error("buffer passed to db_valueString is too short for member name");
            } else {
                strcat(buffer, ".");
                strcat(buffer, db_nameof(m));
            }
        }
    }

    return buffer;
error:
    return NULL;
}

char* db_valueExpr(db_value* v, char* buffer, unsigned int length) {
    db_member m;
    db_value* parents[DB_MAX_TYPE_DEPTH];
    db_int32 parentCount, i;
    db_value* vptr;

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
            db_trace("db_valueExpr: unhandled '%s'", db_valueKindString[vptr->kind]);
            m = NULL;
            goto error;
        }
        if (m) {
            if ((strlen(buffer) + strlen(db_nameof(m)) + 1) >= length) {
                db_error("buffer passed to db_valueString is too short for member name");
            } else {
                strcat(buffer, ".");
                strcat(buffer, db_nameof(m));
            }
        }
    }

    return buffer;
error:
    return NULL;
}

void db_valueObjectInit(db_value* val, db_object o) {
    val->kind = DB_OBJECT;
    val->is.o = o;
}

void db_valueBaseInit(db_value* val, db_void *v, db_typedef t) {
    val->kind = DB_BASE;
    val->is.base.v = v;
    val->is.base.t = t;
}

void db_valueValueInit(db_value* val, db_object o, db_typedef t, db_void* v) {
    val->parent = NULL;
    val->kind = DB_VALUE;
    val->is.value.o = o;
    val->is.value.t = t;
    val->is.value.v = v;
}
void db_valueMemberInit(db_value* val, db_object o, db_member t, db_void* v) {
    val->kind = DB_MEMBER;
    val->is.member.o = o;
    val->is.member.t = t;
    val->is.member.v = v;
}
void db_valueCallInit(db_value* val, db_object o, db_function t) {
    val->kind = DB_CALL;
    val->is.call.o = o;
    val->is.call.t = t;
}
void db_valueConstantInit(db_value* val, db_object o, db_constant* t, db_void* v) {
    val->kind = DB_CONSTANT;
    val->is.constant.o = o;
    val->is.constant.t = t;
    val->is.constant.v = v;
}
void db_valueElementInit(db_value* val, db_object o, db_typedef t, db_uint32 index, db_void* v) {
    val->kind = DB_ELEMENT;
    val->is.element.o = o;
    val->is.element.t.type = t;
    val->is.element.t.index = index;
    val->is.element.v = v;
}

void db_valueMapElementInit(db_value* val, db_object o, db_typedef t, db_typedef keyType, db_void *key, db_void* v) {
    val->kind = DB_MAP_ELEMENT;
    val->is.mapElement.o = o;
    val->is.mapElement.t.type = t;
    val->is.mapElement.t.keyType = keyType;
    val->is.mapElement.t.key = key;
    val->is.mapElement.v = v;
}

void db_valueLiteralInit(db_value* val, db_literalKind kind, db_void* value) {
	val->kind = DB_LITERAL;
	val->is.literal.kind = kind;

	switch(kind) {
	case DB_LITERAL_BOOLEAN:
		val->is.literal.v._boolean = *(db_bool*)value;
		break;
	case DB_LITERAL_CHARACTER:
		val->is.literal.v._character = *(db_char*)value;
		break;
	case DB_LITERAL_INTEGER:
		val->is.literal.v._integer = *(db_int64*)value;
		break;
	case DB_LITERAL_UNSIGNED_INTEGER:
		val->is.literal.v._unsigned_integer = *(db_uint64*)value;
		break;
	case DB_LITERAL_FLOATING_POINT:
		val->is.literal.v._floating_point = *(db_float64*)value;
		break;
	case DB_LITERAL_STRING:
		if (*(db_string*)value) {
			val->is.literal.v._string = db_strdup(*(db_string*)value);
		} else {
			val->is.literal.v._string = NULL;
		}
		break;
	case DB_LITERAL_NULL:
		break;
	}
}

void db_valueSetValue(db_value* val, db_void* v) {
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
		db_assert(0, "db_valueSetValue: invalid valueKind %d.", val->kind);
		break;
	}
}

void db_valueFree(db_value* val) {
    switch(val->kind) {
    case DB_LITERAL:
        switch(val->is.literal.kind) {
        case DB_LITERAL_STRING:
            db_dealloc(val->is.literal.v._string);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

void db_valueStackFree(db_value* valueStack, db_uint32 count) {
    db_uint32 i;
    for(i=0; i<count; i++) {
        db_valueFree(&valueStack[i]);
    }
}

