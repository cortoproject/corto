/*
 * db_mm.c
 *
 *  Created on: Sep 7, 2012
 *      Author: sander
 */

#include "db_memory_ser.h"
#include "db__object.h"
#include "db_mem.h"
#include "db_util.h"
#include "db_err.h"

#include "string.h"

db_int16 db_ser_keepReference(db_serializer s, db_value* v, void* userData) {
	db_object o;
	DB_UNUSED(s);
	DB_UNUSED(userData);

    o = *(db_object*)db_valueValue(v);
    if (o) {
        db_bool weak = FALSE;
        if (v->kind == DB_MEMBER) {
            if (v->is.member.t->weak) {
                weak = TRUE;
            }
        }
        if (!weak) {
            db_keep_ext(db_valueObject(v), o, NULL);
        }
    }

	return 0;
}

db_int16 db_ser_freePrimitive(db_serializer s, db_value* v, void* udata) {
	db_type t;
	void* o;

	DB_UNUSED(s);
	DB_UNUSED(udata);

	t = db_valueType(v)->real;
	o = db_valueValue(v);

	/* Free strings */
	switch(db_primitive(t)->kind) {
	case DB_TEXT: {
	    db_string str;
	    if ((str = *(db_string*)o)) {
	        db_dealloc(str);
	    }
		break;
	}
	default:
		break;
	}

	return 0;
}

int db_ser_clear(void* o, void* udata) {
    DB_UNUSED(udata);
    db_dealloc(o);
    return 1;
}

db_int16 db_ser_freeCollection(db_serializer s, db_value* v, void* userData) {
	db_type t;
	void* o;

	t = db_valueType(v)->real;
	o = db_valueValue(v);

	/* Serialize elements */
	if (db_serializeElements(s, v, userData)) {
		goto error;
	}

	switch(db_collection(t)->kind) {
	case DB_ARRAY:
		break;
	case DB_SEQUENCE: {
	    void* buffer;
	    buffer = ((struct{db_uint32 length; void* buffer;}*)o)->buffer;
	    if (buffer) {
	        db_dealloc(buffer);
	    }
	    break;
	}
	case DB_LIST:
	    if (*(db_ll*)o) {
	        /* Free memory allocated for listnodes */
	        if (db_collection_elementRequiresAlloc(db_collection(t))) {
	            db_llWalk(*(db_ll*)o, db_ser_clear,NULL);
	        }
	        db_llFree(*(db_ll*)o);
	    }
	    break;
	case DB_MAP:
	    if (*(db_rbtree*)o) {
	        /* Free memory allocated for mapnodes */
            if (db_collection_elementRequiresAlloc(db_collection(t))) {
                db_rbtreeWalk(*(db_rbtree*)o, db_ser_clear,NULL);
            }
	        db_rbtreeFree(*(db_rbtree*)o);
	    }
	    break;

	/* Free collection object */
	default:
	    db_error("invalid collection object!");
	    goto error;
		break;
	}

	return 0;
error:
	return -1;
}

db_int16 db_ser_freeReference(db_serializer s, db_value* v, void* userData) {
    db_object *optr, o;

    DB_UNUSED(s);
    DB_UNUSED(userData);
    optr = db_valueValue(v);

    if ((o = *optr)) {
        db_bool weak = FALSE;
        if (v->kind == DB_MEMBER) {
            if (v->is.member.t->weak) {
                weak = TRUE;
            }
        }
        if (!weak) {
            db_id id;
            db_free_ext(db_valueObject(v), o, db_valueExpr(v, id, sizeof(id)));
        }
    }

    return 0;
}

struct db_serializer_s db_ser_keep(db_modifier access, db_operatorKind accessKind, db_serializerTraceKind trace) {
	struct db_serializer_s s;

	db_serializerInit(&s);

	s.access = access;
	s.accessKind = accessKind;
	s.traceKind = trace;
	s.reference = db_ser_keepReference;
	return s;
}

struct db_serializer_s db_ser_free(db_modifier access, db_operatorKind accessKind, db_serializerTraceKind trace) {
	struct db_serializer_s s;

	db_serializerInit(&s);

	s.access = access;
	s.accessKind = accessKind;
	s.traceKind = trace;
	s.reference = db_ser_freeReference;
	return s;
}

struct db_serializer_s db_ser_freeResources(db_modifier access, db_operatorKind accessKind, db_serializerTraceKind trace) {
	struct db_serializer_s s;

	db_serializerInit(&s);

	s.access = access;
	s.accessKind = accessKind;
	s.traceKind = trace;
	s.program[DB_PRIMITIVE] = db_ser_freePrimitive;
	s.program[DB_COLLECTION] = db_ser_freeCollection;
	s.reference = db_ser_freeReference;
	return s;
}
