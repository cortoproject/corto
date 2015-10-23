
/*
 * corto_value.c
 *
 *  Created on: Apr 13, 2012
 *      Author: sander
 */

#define corto_lang_LIB
#include "corto_object.h"
#include "corto_value.h"
#include "corto_err.h"
#include "corto_struct.h"
#include "corto_class.h"
#include "corto__meta.h"
#include "corto_mem.h"

#include "string.h"

corto_type corto_valueType(corto_value* val) {
    corto_type result;

    switch(val->kind) {
    case CORTO_OBJECT:
        result = val->is.object.t;
        break;
    case CORTO_BASE:
        result = val->is.base.t;
        break;
    case CORTO_VALUE:
        result = val->is.value.t;
        break;
    case CORTO_LITERAL:
        switch(val->is.literal.kind) {
        case CORTO_LITERAL_BOOLEAN:
            result = corto_type(corto_bool_o);
            break;
        case CORTO_LITERAL_CHARACTER:
            result = corto_type(corto_char_o);
            break;
        case CORTO_LITERAL_INTEGER:
            result = corto_type(corto_int64_o);
            break;
        case CORTO_LITERAL_UNSIGNED_INTEGER:
            result = corto_type(corto_uint64_o);
            break;
        case CORTO_LITERAL_FLOATING_POINT:
            result = corto_type(corto_float64_o);
            break;
        case CORTO_LITERAL_STRING:
            result = corto_type(corto_string_o);
            break;
        default:
            corto_critical("corto_valueType: invalid corto_literalKind(%d)", val->is.literal.kind);
            result = NULL;
            break;
        }
        break;
    case CORTO_MEMBER:
        result = val->is.member.t->type;
        break;
    case CORTO_CALL:
        result = val->is.call.t->returnType;
        break;
    case CORTO_CONSTANT:
        result = corto_valueType(val->parent);
        break;
    case CORTO_ELEMENT:
        result = val->is.element.t.type;
        break;
    case CORTO_MAP_ELEMENT:
        result = val->is.mapElement.t.type;
        break;
    default:
        corto_critical("corto_valueType: invalid corto_valueKind(%d).", val->kind);
        result = NULL;
        break;
    }

    return result;
}

corto_void* corto_valueValue(corto_value* val) {
    corto_void* result;
    switch(val->kind) {
    case CORTO_OBJECT:
        result = val->is.object.o;
        break;
    case CORTO_BASE:
        result = val->is.base.v;
        break;
    case CORTO_LITERAL:
        result = &val->is.literal.v;
        break;
    case CORTO_VALUE:
        result = val->is.value.v;
        break;
    case CORTO_MEMBER:
        result = val->is.member.v;
        break;
    case CORTO_CALL:
        result = NULL; /* A call has no value */
        break;
    case CORTO_CONSTANT:
        result = val->is.constant.v;
        break;
    case CORTO_ELEMENT:
        result = val->is.element.v;
        break;
    case CORTO_MAP_ELEMENT:
        result = val->is.mapElement.v;
        break;
    default:
        corto_critical("corto_valueValue: invalid corto_valueKind(%d).", val->kind);
        result = NULL;
        break;
    }
    return result;
}

corto_object corto_valueObject(corto_value* val) {
    corto_object result;

    switch(val->kind) {
    case CORTO_OBJECT:
        result = val->is.object.o;
        break;
    case CORTO_BASE:
        result = val->is.base.o;
        break;
    case CORTO_LITERAL:
        result = NULL;
        break;
    case CORTO_VALUE:
        result = val->is.value.o;
        break;
    case CORTO_MEMBER:
        result = val->is.member.o;
        break;
    case CORTO_CALL:
        result = val->is.call.o;
        break;
    case CORTO_CONSTANT:
        result = val->is.constant.o;
        break;
    case CORTO_ELEMENT:
        result = val->is.element.o;
        break;
    case CORTO_MAP_ELEMENT:
        result = val->is.mapElement.o;
        break;
    default:
        corto_critical("corto_valueObject: invalid corto_valueKind(%d).", val->kind);
        result = NULL;
        break;
    }
    return result;
}

corto_function corto_valueFunction(corto_value* val) {
    corto_function result;

    switch(val->kind) {
    case CORTO_OBJECT:
        if (corto_class_instanceof(corto_procedure_o, corto_typeof(val->is.object.o))) {
            result = val->is.object.o;
        } else {
            corto_id id;
            corto_error("object '%s' in value is not a function", corto_fullname(val->is.object.o, id));
            result = NULL;
        }
        break;
    case CORTO_CALL:
        result = val->is.call.t;
        break;
    default:
       corto_error("value does not represent a function");
       result = NULL;
       break;
    }

    return result;
}

corto_uint32 corto_valueIndex(corto_value* val) {
    corto_uint32 result = 0;
    switch(val->kind) {
    case CORTO_ELEMENT:
        result = val->is.element.t.index;
        break;
    default:
        corto_error("cannot obtain index from non-element value");
        break;
    }
    return result;
}

corto_void *corto_valueThis(corto_value* val) {
    corto_void *result;

    switch(val->kind) {
    case CORTO_CALL:
        if (val->parent) {
            result = corto_valueValue(val->parent);
        } else {
            corto_critical("valuestack corrupt (cannot obtain this)");
            result = NULL;
        }
        break;
    default:
        corto_error("value does not represent a method");
        result = NULL;
        break;
    }

    return result;
}

static char* corto_valueKindString[CORTO_CONSTANT+1] = {"object", "base", "member", "constant", "element"};

char* corto_strving(corto_value* v, char* buffer, unsigned int length) {
    corto_id object_name;
    corto_member m;
    corto_value* parents[CORTO_MAX_TYPE_DEPTH];
    corto_int32 parentCount, i;
    corto_value* vptr;

    if (length < (strlen("ELEMENT") + 3)) {
        corto_error("buffer passed to corto_strving is too short.");
        goto error;
    }

    /* Put label in buffer */
    sprintf(buffer, "%s ", corto_valueKindString[v->kind]);

    /* Get name of object */
    corto_fullname(corto_valueObject(v), object_name);
    if ((strlen(buffer) + (strlen(object_name) + 2 + 1)) >= length) {
        corto_error("buffer passed to corto_strving is too short for object name.");
        goto error;
    }

    /* Put objectname in buffer */
    strcat(buffer, object_name);

    /* Collect parents */
    parentCount = 0;
    vptr = v;
    do{
        if (vptr->kind != CORTO_OBJECT) {
            parents[parentCount] = vptr;
            parentCount++;
        }
    }while((vptr = vptr->parent));

    /* Put name of member or branch in buffer */
    for(i=parentCount-1; i>=0; i--) {
        vptr = parents[i];
        m = NULL;
        switch(vptr->kind) {
        case CORTO_LITERAL:
        case CORTO_VALUE:
            /* Nothing to add for just a value */
            break;
        case CORTO_BASE:
            break;
        case CORTO_MEMBER:
            m = vptr->is.member.t;
            break;
        case CORTO_ELEMENT:
            sprintf(buffer, "%s[%d]", buffer, vptr->is.element.t.index);
            m = NULL;
            break;
        default:
            corto_trace("corto_strving: unhandled '%s'", corto_valueKindString[vptr->kind]);
            m = NULL;
            break;
        }
        if (m) {
            if ((strlen(buffer) + strlen(corto_nameof(m)) + 1) >= length) {
                corto_error("buffer passed to corto_strving is too short for member name");
            } else {
                strcat(buffer, ".");
                strcat(buffer, corto_nameof(m));
            }
        }
    }

    return buffer;
error:
    return NULL;
}

char* corto_valueExpr(corto_value* v, char* buffer, unsigned int length) {
    corto_member m;
    corto_value* parents[CORTO_MAX_TYPE_DEPTH];
    corto_int32 parentCount, i;
    corto_value* vptr;

    *buffer = '\0';

    /* Collect parents */
    parentCount = 0;
    vptr = v;
    do{
        if (vptr->kind != CORTO_OBJECT) {
            parents[parentCount] = vptr;
            parentCount++;
        }
    }while((vptr = vptr->parent));

    /* Put name of member or branch in buffer */
    for(i=parentCount-1; i>=0; i--) {
        vptr = parents[i];
        m = NULL;
        switch(vptr->kind) {
        case CORTO_LITERAL:
        case CORTO_VALUE:
            break;
        case CORTO_BASE:
            break;
        case CORTO_MEMBER:
            m = vptr->is.member.t;
            break;
        case CORTO_ELEMENT:
            sprintf(buffer, "%s[%d]", buffer, vptr->is.element.t.index);
            m = NULL;
            break;
        default:
            corto_trace("corto_valueExpr: unhandled '%s'", corto_valueKindString[vptr->kind]);
            m = NULL;
            goto error;
        }
        if (m) {
            if ((strlen(buffer) + strlen(corto_nameof(m)) + 1) >= length) {
                corto_error("buffer passed to corto_strving is too short for member name");
            } else {
                strcat(buffer, ".");
                strcat(buffer, corto_nameof(m));
            }
        }
    }

    return buffer;
error:
    return NULL;
}

void corto_valueObjectInit(corto_value* val, corto_object o, corto_type t) {
    val->kind = CORTO_OBJECT;
    val->parent = NULL;
    val->is.object.o = o;
    if (t) {
        val->is.object.t = t;
    } else {
        val->is.object.t = corto_typeof(o);
    }
}

void corto_valueBaseInit(corto_value* val, corto_void *v, corto_type t) {
    val->kind = CORTO_BASE;
    val->parent = NULL;
    val->is.base.v = v;
    val->is.base.t = t;
}

void corto_valueValueInit(corto_value* val, corto_object o, corto_type t, corto_void* v) {
    val->kind = CORTO_VALUE;
    val->parent = NULL;
    val->is.value.o = o;
    val->is.value.t = t;
    val->is.value.v = v;
}
void corto_valueMemberInit(corto_value* val, corto_object o, corto_member t, corto_void* v) {
    val->kind = CORTO_MEMBER;
    val->parent = NULL;
    val->is.member.o = o;
    val->is.member.t = t;
    val->is.member.v = v;
}
void corto_valueCallInit(corto_value* val, corto_object o, corto_function t) {
    val->kind = CORTO_CALL;
    val->parent = NULL;
    val->is.call.o = o;
    val->is.call.t = t;
}
void corto_valueConstantInit(corto_value* val, corto_object o, corto_constant* t, corto_void* v) {
    val->kind = CORTO_CONSTANT;
    val->parent = NULL;
    val->is.constant.o = o;
    val->is.constant.t = t;
    val->is.constant.v = v;
}
void corto_valueElementInit(corto_value* val, corto_object o, corto_type t, corto_uint32 index, corto_void* v) {
    val->kind = CORTO_ELEMENT;
    val->parent = NULL;
    val->is.element.o = o;
    val->is.element.t.type = t;
    val->is.element.t.index = index;
    val->is.element.v = v;
}

void corto_valueMapElementInit(corto_value* val, corto_object o, corto_type t, corto_type keyType, corto_void *key, corto_void* v) {
    val->kind = CORTO_MAP_ELEMENT;
    val->parent = NULL;
    val->is.mapElement.o = o;
    val->is.mapElement.t.type = t;
    val->is.mapElement.t.keyType = keyType;
    val->is.mapElement.t.key = key;
    val->is.mapElement.v = v;
}

void corto_valueLiteralInit(corto_value* val, corto_literalKind kind, corto_void* value) {
    val->kind = CORTO_LITERAL;
    val->is.literal.kind = kind;
    val->parent = NULL;

    switch(kind) {
    case CORTO_LITERAL_BOOLEAN:
        val->is.literal.v._boolean = *(corto_bool*)value;
        break;
    case CORTO_LITERAL_CHARACTER:
        val->is.literal.v._character = *(corto_char*)value;
        break;
    case CORTO_LITERAL_INTEGER:
        val->is.literal.v._integer = *(corto_int64*)value;
        break;
    case CORTO_LITERAL_UNSIGNED_INTEGER:
        val->is.literal.v._unsigned_integer = *(corto_uint64*)value;
        break;
    case CORTO_LITERAL_FLOATING_POINT:
        val->is.literal.v._floating_point = *(corto_float64*)value;
        break;
    case CORTO_LITERAL_STRING:
        if (*(corto_string*)value) {
            val->is.literal.v._string = corto_strdup(*(corto_string*)value);
        } else {
            val->is.literal.v._string = NULL;
        }
        break;
    case CORTO_LITERAL_NULL:
        break;
    }
}

void corto_valueSetValue(corto_value* val, corto_void* v) {
    switch(val->kind) {
    case CORTO_OBJECT:
        val->is.object.o = v; /* Dangerous, but allowed */
        break;
    case CORTO_BASE:
        val->is.base.v = v;
        break;
    case CORTO_MEMBER:
        val->is.member.v = v;
        break;
    case CORTO_CONSTANT:
        val->is.constant.v = v;
        break;
    case CORTO_ELEMENT:
        val->is.element.v = v;
        break;
    case CORTO_MAP_ELEMENT:
        val->is.mapElement.v = v;
        break;
    default:
        corto_assert(0, "corto_valueSetValue: invalid valueKind %d.", val->kind);
        break;
    }
}

void corto_valueFree(corto_value* val) {
    switch(val->kind) {
    case CORTO_LITERAL:
        switch(val->is.literal.kind) {
        case CORTO_LITERAL_STRING:
            corto_dealloc(val->is.literal.v._string);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

void corto_valueStackFree(corto_value* valueStack, corto_uint32 count) {
    corto_uint32 i;
    for(i=0; i<count; i++) {
        corto_valueFree(&valueStack[i]);
    }
}

