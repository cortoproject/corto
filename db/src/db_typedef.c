/*
 * db_typedef.c
 *
 *  Created on: Aug 5, 2012
 *      Author: sander
 */

#include "db_object.h"
#include "db_typedef.h"
#include "db_util.h"
#include "db_err.h"
#include "db__meta.h"

/* ::type::init -> ::typedef::init */
db_int16 db_typedef_init(db_typedef object) {
    DB_UNUSED(object);

    if (object->type) {
        db_typedef_construct(object);
        if (db_checkAttr(object, DB_ATTR_SCOPED) && (db_parentof(object) == hyve_lang_o)) {
            db_keep_ext(object, object->real, "Keep self for real member");
        }

    }

    return 0;
}

/* ::class::construct -> ::typedef::construct */
db_int16 db_typedef_construct(db_typedef object) {
    db_typedef real;

    real = db_typedef(object)->type;
    if (!real) {
        db_id id;
        db_error("typedef::construct: typedef '%s' points to nothing", db_fullname(object, id));
        goto error;
    }

    while(real != real->type) {
        if (!db_checkState(real, DB_VALID)) {
            db_id id, id2;
            db_error("typedef::construct: typedef '%s' points to object '%s' which is not valid", db_fullname(object, id), db_fullname(real, id2));
            goto error;
        }
        if (!db_checkState(real, DB_DEFINED)) {
            db_id id, id2;
            db_error("typedef::construct: typedef '%s' points to object '%s' which is not defined", db_fullname(object, id), db_fullname(real, id2));
            goto error;
        }
        if (!real->type) {

        }
        real = real->type;
    }

    db_assert(real != NULL, "typedef '%s' points to nothing", db_nameof(object));

    db_set_ext(object, &db_typedef(object)->real, real, "Set real-member");

	return 0;
error:
    return -1;
}

/* Destruct typedef */
void db_typedef_destruct(db_typedef object) {
	db_free_ext(object, object->real, "Free real member");
	object->real = NULL;
}

/* ::typedef::realType() */
db_type db_typedef_realType(db_typedef _this) {
	return _this->real;
}
