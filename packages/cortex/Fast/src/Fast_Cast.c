/* Fast_Cast.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"

/* $header() */
#include "Fast__private.h"
/* $end */

/* ::cortex::Fast::Cast::construct() */
cx_int16 _Fast_Cast_construct(Fast_Cast _this) {
/* $begin(::cortex::Fast::Cast::construct) */

    Fast_Node(_this)->kind = Fast_CallExpr;

    cx_type rvalueType;
    rvalueType = Fast_Expression_getType(_this->rvalue);
    if (rvalueType) {
        if ((_this->isReference && rvalueType->reference && (rvalueType->kind == CX_VOID)) ||
           (cx_type_castable(_this->lvalue, rvalueType) || cx_type_castable(rvalueType, _this->lvalue))) {
            cx_setref(&Fast_Expression(_this)->type, _this->lvalue);
            Fast_Expression(_this)->isReference = _this->lvalue->reference || _this->isReference;
        } else {
            cx_id id1, id2;
            Fast_Parser_error(yparser(), "cannot cast from type '%s' to '%s'",
                    Fast_Parser_id(rvalueType, id1), Fast_Parser_id(_this->lvalue, id2));
            goto error;
        }
    } else {
        /* If type of rvalue is unknown, cast is performed at runtime. Set type even though to introduce the
         * type barrier for code using this expression. */
        cx_setref(&Fast_Expression(_this)->type, _this->lvalue);
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::Cast::hasReturnedResource() */
cx_bool Fast_Cast_hasReturnedResource_v(Fast_Cast _this) {
/* $begin(::cortex::Fast::Cast::hasReturnedResource) */

    return Fast_Expression_hasReturnedResource(_this->rvalue);

/* $end */
}

/* ::cortex::Fast::Cast::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Cast_toIc_v(Fast_Cast _this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::cortex::Fast::Cast::toIc) */
    ic_node lvalue, rvalue, result;
    cx_bool deref1 = IC_DEREF_VALUE, deref2 = IC_DEREF_VALUE;
    cx_type _thisType = Fast_Expression_getType(Fast_Expression(_this));
    CX_UNUSED(stored);

    if (storage && (storage->type == _thisType)) {
        result = (ic_node)storage;
    } else {
        result = (ic_node)ic_program_pushAccumulator(
            program,
            Fast_Expression_getType(Fast_Expression(_this)),
            (_this->rvalue->deref == Fast_ByReference) || _thisType->reference,
            FALSE);
    }

    lvalue = (ic_node)ic_object__create(_this->lvalue);
    rvalue = Fast_Node_toIc(Fast_Node(_this->rvalue), program, (ic_storage)NULL, TRUE);

    if ((_this->rvalue->deref == Fast_ByReference) || _thisType->reference) {
        deref2 = IC_DEREF_ADDRESS;
    }
    if (ic_storage(result)->isReference) {
        deref1 = IC_DEREF_ADDRESS;
    }

    IC_3(program, Fast_Node(_this)->line, ic_cast, result, rvalue, lvalue,
        deref1, deref2, IC_DEREF_ADDRESS);

    return result;
/* $end */
}
