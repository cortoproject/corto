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

db_int16 db_ser_initCollection(db_serializer s, db_value* v, void* userData) {
	db_type t;
	void* o;
    
	t = db_valueType(v)->real;
	o = db_valueValue(v);
    
	switch(db_collection(t)->kind) {
        case DB_ARRAY:
            /* Serialize elements */
            if (db_serializeElements(s, v, userData)) {
                goto error;
            }
            break;
        case DB_SEQUENCE:
            break;
        case DB_LIST:
            *(db_ll*)o = db_llNew();
            break;
        case DB_MAP:
            /**(db_rbtree*)o = db_rbtreeNew(t);*/
            break;
        default:
            db_error("invalid collection object!");
            goto error;
            break;
	}
    
	return 0;
error:
	return -1;
}


struct db_serializer_s db_ser_init(db_modifier access, db_operatorKind accessKind, db_serializerTraceKind trace) {
	struct db_serializer_s s;
    
	db_serializerInit(&s);
    
	s.access = access;
	s.accessKind = accessKind;
	s.traceKind = trace;
	s.program[DB_COLLECTION] = db_ser_initCollection;
	return s;
}
