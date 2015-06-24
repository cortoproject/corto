/* cx_enum.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

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

/* ::cortex::lang::enum::constant(int32 value) */
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

/* ::cortex::lang::enum::construct() */
cx_int16 cx_enum_construct(cx_enum _this) {
/* $begin(::cortex::lang::enum::construct) */
    cx_uint32 i;

    /* Define constants */
    for(i=0; i<_this->constants.length; i++) {
        cx_define(_this->constants.buffer[i]);
    }

    return cx_primitive_construct(cx_primitive(_this));
/* $end */
}

/* ::cortex::lang::enum::destruct() */
cx_void cx_enum_destruct(cx_enum _this) {
/* $begin(::cortex::lang::enum::destruct) */
    cx_clear(cx_collection(cx_objectSeq_o), &_this->constants);
    cx_type_destruct(cx_type(_this));
/* $end */
}

/* ::cortex::lang::enum::init() */
cx_int16 cx_enum_init(cx_enum _this) {
/* $begin(::cortex::lang::enum::init) */
    cx_primitive(_this)->kind = CX_ENUM;
    cx_primitive(_this)->width = CX_WIDTH_32;
    cx_set(&cx_type(_this)->defaultType, cx_constant_o);
    return cx_primitive_init((cx_primitive)_this);
/* $end */
}
