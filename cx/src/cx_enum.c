/* cx_enum.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

/* $header() */
#include "cx__enum.h"
#include "cx__collection.h"

cx_int16 cx__enum_bindConstant(cx_enum _this, cx_constant* c) {
	cx_rbtree scope;

    if (cx_checkState(cx_type_o, CX_DEFINED)) {
        scope = cx_scopeof(_this);
        *c = cx_rbtreeSize(scope)-1;
    }
    _this->constants.buffer = cx_realloc(_this->constants.buffer, (_this->constants.length+1) * sizeof(cx_constant*));
    _this->constants.buffer[_this->constants.length] = c;
    _this->constants.length++;
    
    cx_keep(c);

	return 0;
}
/* $end */

/* ::cortex::lang::enum::constant(lang::int32 value) */
/* $header(::cortex::lang::enum::constant) */
struct cx_enum_findConstant_t {
    cx_int32 value;
    cx_constant* o;
};

static int cx_enum_findConstant(void* o, void* udata) {
    struct cx_enum_findConstant_t* userData;

    userData = udata;
    if (*(cx_constant*)o == userData->value) {
        userData->o = o;
    }
    return userData->o == NULL;
}
/* $end */
cx_object cx_enum_constant(cx_enum _this, cx_int32 value) {
/* $begin(::cortex::lang::enum::constant) */
    cx_rbtree scope;
    struct cx_enum_findConstant_t walkData;

    /* Get scope */
    scope = cx_scopeof(_this);

    /* Walk scope */
    walkData.value = value;
    walkData.o = NULL;
    cx_rbtreeWalk(scope, cx_enum_findConstant, &walkData);

    return walkData.o;
/* $end */
}

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::lang::enum::construct(lang::enum object) */
cx_int16 cx_enum_construct(cx_enum object) {
/* $begin(::cortex::lang::enum::construct) */
	cx_uint32 i;

	/* Define constants */
	for(i=0; i<object->constants.length; i++) {
		cx_define(object->constants.buffer[i]);
	}

	return cx_primitive_construct(cx_primitive(object));
/* $end */
}

/* callback ::cortex::lang::class::destruct(lang::object object) -> ::cortex::lang::enum::destruct(lang::enum object) */
cx_void cx_enum_destruct(cx_enum object) {
/* $begin(::cortex::lang::enum::destruct) */
	cx_clear(cx_collection(cx_objectSeq_o), &object->constants);
	cx_type__destruct(cx_type(object));
/* $end */
}

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::enum::init(lang::enum object) */
cx_int16 cx_enum_init(cx_enum object) {
/* $begin(::cortex::lang::enum::init) */
    cx_primitive(object)->kind = CX_ENUM;
    cx_primitive(object)->width = CX_WIDTH_32;
    cx_set(&cx_type(object)->defaultType, cx_constant_o);
    return cx_primitive_init((cx_primitive)object);
/* $end */
}
