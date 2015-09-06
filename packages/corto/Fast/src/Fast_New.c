/* Fast_New.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_Fast_LIB
#include "Fast.h"

/* $header() */
#include "Fast__private.h"
/* $end */

/* ::corto::Fast::New::construct() */
cx_int16 _Fast_New_construct(Fast_New this) {
/* $begin(::corto::Fast::New::construct) */

    Fast_Node(this)->kind = Fast_NewExpr;
    cx_setref(&Fast_Expression(this)->type, this->type);
    Fast_Expression(this)->isReference = TRUE;

    return 0;
/* $end */
}

/* ::corto::Fast::New::hasSideEffects() */
cx_bool _Fast_New_hasSideEffects_v(Fast_New this) {
/* $begin(::corto::Fast::New::hasSideEffects) */
    CX_UNUSED(this);
    return TRUE;
/* $end */
}

/* ::corto::Fast::New::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_New_toIc_v(Fast_New this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::Fast::New::toIc) */
    ic_node type, attrs, result;
    CX_UNUSED(stored);

    if (storage) {
        result = (ic_node)storage;
    } else {
        result = (ic_node)ic_program_pushAccumulator(program, Fast_Expression_getType(Fast_Expression(this)), TRUE, FALSE);
    }

    type = (ic_node)ic_objectCreate(Fast_Expression(this)->type);
    if (this->attributes) {
        attrs = Fast_Node_toIc(Fast_Node(this->attributes), program, NULL, TRUE);
    } else {
        attrs = NULL;
    }

    IC_3(program, Fast_Node(this)->line, ic_new, 
        result, type, attrs, IC_DEREF_ADDRESS, IC_DEREF_ADDRESS, IC_DEREF_VALUE)

    return result;
/* $end */
}
