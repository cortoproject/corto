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

cx_int16 cx__enum_bindConstant(cx_enum this, cx_constant* c) {
    if (cx_checkState(cx_type_o, CX_DEFINED)) {
        *c = cx_scopeSize(this)-1;
    }
    this->constants.buffer = cx_realloc(this->constants.buffer, (this->constants.length+1) * sizeof(cx_constant*));
    this->constants.buffer[this->constants.length] = c;
    this->constants.length++;
    
    cx_claim(c);

    return 0;
}
/* $end */

/* ::corto::lang::enum::constant(int32 value) */
/* $header(::corto::lang::enum::constant) */
struct cx_enum_findConstant_t {
    cx_int32 value;
    cx_constant* o;
};

static int cx_enum_findConstant(cx_object o, void* udata) {
    struct cx_enum_findConstant_t* userData;

    userData = udata;
    if (*(cx_constant*)o == userData->value) {
        userData->o = o;
    }
    return userData->o == NULL;
}
/* $end */
cx_object _cx_enum_constant(cx_enum this, cx_int32 value) {
/* $begin(::corto::lang::enum::constant) */
    struct cx_enum_findConstant_t walkData;

    /* Walk scope */
    walkData.value = value;
    walkData.o = NULL;
    cx_scopeWalk(this, cx_enum_findConstant, &walkData);

    return walkData.o;
/* $end */
}

/* ::corto::lang::enum::construct() */
cx_int16 _cx_enum_construct(cx_enum this) {
/* $begin(::corto::lang::enum::construct) */
    cx_uint32 i;

    /* Define constants */
    for(i=0; i<this->constants.length; i++) {
        cx_define(this->constants.buffer[i]);
    }

    return cx_primitive_construct(cx_primitive(this));
/* $end */
}

/* ::corto::lang::enum::destruct() */
cx_void _cx_enum_destruct(cx_enum this) {
/* $begin(::corto::lang::enum::destruct) */
    cx_clear(cx_collection(cx_objectseq_o), &this->constants);
    cx_type_destruct(cx_type(this));
/* $end */
}

/* ::corto::lang::enum::init() */
cx_int16 _cx_enum_init(cx_enum this) {
/* $begin(::corto::lang::enum::init) */
    cx_primitive(this)->kind = CX_ENUM;
    cx_primitive(this)->width = CX_WIDTH_32;
    cx_setref(&cx_type(this)->defaultType, cx_constant_o);
    return cx_primitive_init((cx_primitive)this);
/* $end */
}
