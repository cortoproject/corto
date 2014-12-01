/* db_typedef.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::lang::typedef::construct(lang::typedef object) */
db_int16 db_typedef_construct(db_typedef object) {
/* $begin(::hyve::lang::typedef::construct) */
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
/* $end */
}

/* callback ::hyve::lang::class::destruct(lang::object object) -> ::hyve::lang::typedef::destruct(lang::typedef object) */
db_void db_typedef_destruct(db_typedef object) {
/* $begin(::hyve::lang::typedef::destruct) */
	db_free_ext(object, object->real, "Free real member");
	object->real = NULL;
/* $end */
}

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::lang::typedef::init(lang::typedef object) */
db_int16 db_typedef_init(db_typedef object) {
/* $begin(::hyve::lang::typedef::init) */
    DB_UNUSED(object);

    if (object->type) {
        db_typedef_construct(object);
        if (db_checkAttr(object, DB_ATTR_SCOPED) && (db_parentof(object) == hyve_lang_o)) {
            db_keep_ext(object, object->real, "Keep self for real member");
        }

    }

    return 0;
/* $end */
}

/* ::hyve::lang::typedef::realType() */
db_type db_typedef_realType(db_typedef _this) {
/* $begin(::hyve::lang::typedef::realType) */
	return _this->real;
/* $end */
}
