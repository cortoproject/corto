/* Fast_Cast.c
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

/* ::corto::Fast::Cast::construct() */
cx_int16 _Fast_Cast_construct(Fast_Cast this) {
/* $begin(::corto::Fast::Cast::construct) */

    Fast_Node(this)->kind = Fast_CallExpr;

    cx_type rvalueType;
    rvalueType = Fast_Expression_getType(this->rvalue);
    if (rvalueType) {
        if ((this->isReference && rvalueType->reference && (rvalueType->kind == CX_VOID)) ||
           (cx_type_castable(this->lvalue, rvalueType) || cx_type_castable(rvalueType, this->lvalue))) {
            cx_setref(&Fast_Expression(this)->type, this->lvalue);
            Fast_Expression(this)->isReference = this->lvalue->reference || this->isReference;
        } else {
            cx_id id1, id2;
            Fast_Parser_error(yparser(), "cannot cast from type '%s' to '%s'",
                    Fast_Parser_id(rvalueType, id1), Fast_Parser_id(this->lvalue, id2));
            goto error;
        }
    } else {
        /* If type of rvalue is unknown, cast is performed at runtime. Set type even though to introduce the
         * type barrier for code using this expression. */
        cx_setref(&Fast_Expression(this)->type, this->lvalue);
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::Fast::Cast::hasReturnedResource() */
cx_bool _Fast_Cast_hasReturnedResource_v(Fast_Cast this) {
/* $begin(::corto::Fast::Cast::hasReturnedResource) */

    return Fast_Expression_hasReturnedResource(this->rvalue);

/* $end */
}

/* ::corto::Fast::Cast::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Cast_toIc_v(Fast_Cast this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::Fast::Cast::toIc) */
    ic_node lvalue, rvalue, result;
    cx_bool deref1 = IC_DEREF_VALUE, deref2 = IC_DEREF_VALUE;
    cx_type thisType = Fast_Expression_getType(Fast_Expression(this));
    CX_UNUSED(stored);

    if (storage && (storage->type == thisType)) {
        result = (ic_node)storage;
    } else {
        result = (ic_node)ic_program_pushAccumulator(
            program,
            Fast_Expression_getType(Fast_Expression(this)),
            (this->rvalue->deref == Fast_ByReference) || thisType->reference,
            FALSE);
    }

    lvalue = (ic_node)ic_objectCreate(this->lvalue);
    rvalue = Fast_Node_toIc(Fast_Node(this->rvalue), program, (ic_storage)NULL, TRUE);

    if ((this->rvalue->deref == Fast_ByReference) || thisType->reference) {
        deref2 = IC_DEREF_ADDRESS;
    }
    if (ic_storage(result)->isReference) {
        deref1 = IC_DEREF_ADDRESS;
    }

    IC_3(program, Fast_Node(this)->line, ic_cast, result, rvalue, lvalue,
        deref1, deref2, IC_DEREF_ADDRESS);

    return result;
/* $end */
}
