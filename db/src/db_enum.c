/* db_enum.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* $header() */
#include "db__enum.h"
#include "db__collection.h"

db_int16 db__enum_bindConstant(db_enum _this, db_constant* c) {
	db_rbtree scope;

    if (db_checkState(db_type_o, DB_DEFINED)) {
        scope = db_scopeof(_this);
        *c = db_rbtreeSize(scope)-1;
    }
    _this->constants.buffer = db_realloc(_this->constants.buffer, (_this->constants.length+1) * sizeof(db_constant*));
    _this->constants.buffer[_this->constants.length] = c;
    _this->constants.length++;
    
    db_keep(c);

	return 0;
}
/* $end */

/* ::cortex::lang::enum::constant(lang::int32 value) */
/* $header(::cortex::lang::enum::constant) */
struct db_enum_findConstant_t {
    db_int32 value;
    db_constant* o;
};

static int db_enum_findConstant(void* o, void* udata) {
    struct db_enum_findConstant_t* userData;

    userData = udata;
    if (*(db_constant*)o == userData->value) {
        userData->o = o;
    }
    return userData->o == NULL;
}
/* $end */
db_object db_enum_constant(db_enum _this, db_int32 value) {
/* $begin(::cortex::lang::enum::constant) */
    db_rbtree scope;
    struct db_enum_findConstant_t walkData;

    /* Get scope */
    scope = db_scopeof(_this);

    /* Walk scope */
    walkData.value = value;
    walkData.o = NULL;
    db_rbtreeWalk(scope, db_enum_findConstant, &walkData);

    return walkData.o;
/* $end */
}

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::lang::enum::construct(lang::enum object) */
db_int16 db_enum_construct(db_enum object) {
/* $begin(::cortex::lang::enum::construct) */
	db_uint32 i;

	/* Define constants */
	for(i=0; i<object->constants.length; i++) {
		db_define(object->constants.buffer[i]);
	}

	return db_primitive_construct(db_primitive(object));
/* $end */
}

/* callback ::cortex::lang::class::destruct(lang::object object) -> ::cortex::lang::enum::destruct(lang::enum object) */
db_void db_enum_destruct(db_enum object) {
/* $begin(::cortex::lang::enum::destruct) */
	db_clear(db_collection(db_objectSeq_o), &object->constants);
	db_type__destruct(db_type(object));
/* $end */
}

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::enum::init(lang::enum object) */
db_int16 db_enum_init(db_enum object) {
/* $begin(::cortex::lang::enum::init) */
    db_primitive(object)->kind = DB_ENUM;
    db_primitive(object)->width = DB_WIDTH_32;
    db_set(&db_type(object)->defaultType, db_constant_o);
    return db_primitive_init((db_primitive)object);
/* $end */
}
