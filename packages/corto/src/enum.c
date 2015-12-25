/* $CORTO_GENERATED
 *
 * corto_enum.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "corto.h"

/* $header() */
#include "corto__enum.h"
#include "corto__collection.h"

corto_int16 corto__enum_bindConstant(corto_enum this, corto_constant* c) {
    if (corto_checkState(corto_type_o, CORTO_DEFINED)) {
        *c = corto_scopeSize(this);
    }
    this->constants.buffer = corto_realloc(this->constants.buffer, (this->constants.length+1) * sizeof(corto_constant*));
    this->constants.buffer[this->constants.length] = c;
    this->constants.length++;

    corto_claim(c);

    return 0;
}
/* $end */

/* $header(corto/lang/enum/constant) */
struct corto_enum_findConstant_t {
    corto_int32 value;
    corto_constant* o;
};

static int corto_enum_findConstant(corto_object o, void* udata) {
    struct corto_enum_findConstant_t* userData;

    userData = udata;
    if (*(corto_constant*)o == userData->value) {
        userData->o = o;
    }
    return userData->o == NULL;
}
/* $end */
corto_object _corto_enum_constant(corto_enum this, corto_int32 value) {
/* $begin(corto/lang/enum/constant) */
    struct corto_enum_findConstant_t walkData;

    /* Walk scope */
    walkData.value = value;
    walkData.o = NULL;
    corto_scopeWalk(this, corto_enum_findConstant, &walkData);

    return walkData.o;
/* $end */
}

corto_int16 _corto_enum_construct(corto_enum this) {
/* $begin(corto/lang/enum/construct) */
    corto_uint32 i;

    /* Define constants */
    for(i=0; i<this->constants.length; i++) {
        corto_define(this->constants.buffer[i]);
    }

    return corto_primitive_construct(corto_primitive(this));
/* $end */
}

corto_void _corto_enum_destruct(corto_enum this) {
/* $begin(corto/lang/enum/destruct) */
    corto_clear(corto_collection(corto_objectseq_o), &this->constants);
    corto_type_destruct(corto_type(this));
/* $end */
}

corto_int16 _corto_enum_init(corto_enum this) {
/* $begin(corto/lang/enum/init) */
    corto_primitive(this)->kind = CORTO_ENUM;
    corto_primitive(this)->width = CORTO_WIDTH_32;
    return corto_primitive_init((corto_primitive)this);
/* $end */
}
