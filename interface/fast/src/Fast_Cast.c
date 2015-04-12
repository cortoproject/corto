/* Fast_Cast.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"
#include "Fast__meta.h"

/* $header() */
#include "cx_type.h"
#include "Fast__api.h"
#include "Fast.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
/* $end */

/* ::cortex::Fast::Cast::construct() */
cx_int16 Fast_Cast_construct(Fast_Cast _this) {
/* $begin(::cortex::Fast::Cast::construct) */

    Fast_Node(_this)->kind = Fast_CallExpr;

    cx_type rvalueType;
    rvalueType = Fast_Expression_getType(_this->rvalue);
    if (rvalueType) {
        if (cx_type_castable(_this->lvalue, rvalueType) || cx_type_castable(rvalueType, _this->lvalue)) {
            /* TODO: cx_assert(!cx_type_compatible(rvalueType, cx_type(lvalue)), "%d: redundant cast inserted", yparser()->line); */
            cx_set(&Fast_Expression(_this)->type, _this->lvalue);
            Fast_Expression(_this)->isReference = _this->lvalue->reference;
        } else {
            cx_id id1, id2;
            Fast_Parser_error(yparser(), "cannot cast from type '%s' to '%s'",
                    Fast_Parser_id(rvalueType, id1), Fast_Parser_id(_this->lvalue, id2));
            goto error;
        }
    } else {
        /* If type of rvalue is unknown, cast is performed at runtime. Set type even though to introduce the
         * type barrier for code using this expression. */
        cx_set(&Fast_Expression(_this)->type, _this->lvalue);
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::Cast::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Cast_toIc_v(Fast_Cast _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::Cast::toIc) */
    cx_ic lvalue, rvalue, result;
    cx_icOp op;
    cx_type _thisType = Fast_Expression_getType(Fast_Expression(_this));
    CX_UNUSED(stored);

    if (storage && (storage->type == _thisType)) {
        result = (cx_ic)storage;
    } else {
        result = (cx_ic)cx_icProgram_accumulatorPush(
            program, 
            Fast_Node(_this)->line, 
            Fast_Expression_getType(Fast_Expression(_this)),
            Fast_Expression(_this)->isReference);
    }

    lvalue = (cx_ic)cx_icObject__create(program, Fast_Node(_this)->line, _this->lvalue);
    rvalue = Fast_Node_toIc(Fast_Node(_this->rvalue), program, (cx_icStorage)NULL, TRUE);

    op = cx_icOp__create(program, Fast_Node(_this)->line, CX_IC_CAST, (cx_icValue)result, (cx_icValue)rvalue, (cx_icValue)lvalue);

    if ((_this->rvalue->deref == Fast_ByReference) || _thisType->reference) {
        op->s2Deref = CX_IC_DEREF_ADDRESS;
    }
    op->s3Deref = CX_IC_DEREF_ADDRESS;
    cx_icProgram_addIc(program, (cx_ic)op);

    return result;
/* $end */
}
