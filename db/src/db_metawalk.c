/*
 * db_metawalk.c

 *
 *  Created on: Aug 28, 2012
 *      Author: sander
 */

#include "db_metawalk.h"
#include "db__object.h" /* To mimic an object */
#include "db_err.h"
#include "db_util.h"
#include "db_mem.h"
#include "string.h"

/* Do metawalk on type */
db_int16 db_metaWalk(db_serializer s, db_type type, void* userData) {
	db__object* o;
	db_int16 result;

	/* Instantiate dummy-object */
	o = db_malloc(sizeof(db__object) + type->size); /* alloca is dangerous here because objects can get large, causing stack overflows. */
	memset(o, 0, sizeof(db__object) + type->size);
	o->type = db_typedef(type);
	o->refcount = 1;

	result = db_serialize(s, DB_OFFSET(o, sizeof(db__object)), userData);
	db_dealloc(o);

	return result;
}

/* Serialize constants of enumeration */
db_int16 db_serializeConstants(db_serializer s, db_value* v, void* userData) {
	db_enum t;
	db_uint32 i;

	t = db_enum(db_valueType(v)->real);

	/* If there is a callback for constants, serialize them */
	if (s->metaprogram[DB_CONSTANT]) {
		db_value info;
		for(i=0; i<t->constants.length; i++) {
			/* Fill info */
			info.parent = v;
			info.kind = DB_CONSTANT;
			info.is.constant.t = t->constants.buffer[i];
			info.is.constant.v = NULL;
			info.is.constant.o = db_valueObject(v);

			/* Serialize constant */
			if (s->metaprogram[DB_CONSTANT](s, &info, userData)) {
				goto error;
			}
		}
	}

	return 0;
error:
	return -1;
}
