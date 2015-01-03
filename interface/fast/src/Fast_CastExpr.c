/* Fast_CastExpr.c
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

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::Fast::CastExpr::construct(Fast::CastExpr object) */
cx_int16 Fast_CastExpr_construct(Fast_CastExpr object) {
/* $begin(::cortex::Fast::CastExpr::construct) */

    Fast_Node(object)->kind = FAST_Call;

    if (Fast_Node(object->lvalue)->kind == FAST_Variable) {
        if (Fast_Variable(object->lvalue)->kind == FAST_Object) {
            cx_object lvalue = Fast_ObjectBase(object->lvalue)->value;
            if (cx_class_instanceof(cx_type_o, lvalue)) {
                cx_type rvalueType;
                rvalueType = Fast_Expression_getType(object->rvalue);
                if (rvalueType) {
                    if (cx_type_castable(cx_type(lvalue), rvalueType) || cx_type_castable(rvalueType, cx_type(lvalue))) {
                        /* TODO: cx_assert(!cx_type_compatible(rvalueType, cx_type(lvalue)), "%d: redundant cast inserted", yparser()->line); */
                        Fast_Expression(object)->type = (Fast_Variable)object->lvalue;
                        Fast_Expression(object)->isReference = cx_type(lvalue)->reference;
                    } else {
                        cx_id id1, id2;
                        Fast_Parser_error(yparser(), "cannot cast from type '%s' to '%s'",
                                cx_fullname(rvalueType, id1), cx_fullname(lvalue, id2));
                        goto error;
                    }
                } else {
                    /* If type of rvalue is unknown, cast is performed at runtime. Set type even though to introduce the
                     * type barrier for code using this expression. */
                    Fast_Expression(object)->type = (Fast_Variable)object->lvalue;
                }
            } else {
                Fast_Parser_error(yparser(), "left-side of cast-expression is not a type");
                goto error;
            }
        } else {
            Fast_Parser_error(yparser(), "dynamic expressions in cast-expression not supported");
            goto error;
        }
    } else {
        Fast_Parser_error(yparser(), "dynamic expressions in cast-expression not supported");
        goto error;
    }

    /* Keep type */
    cx_keep_ext(object, object->lvalue, "type");

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::CastExpr::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
cx_ic Fast_CastExpr_toIc_v(Fast_CastExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::CastExpr::toIc) */
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

    lvalue = Fast_Node_toIc(Fast_Node(_this->lvalue), program, NULL, TRUE);
    rvalue = Fast_Node_toIc(Fast_Node(_this->rvalue), program, (cx_icStorage)NULL, TRUE);

    op = cx_icOp__create(program, Fast_Node(_this)->line, CX_IC_CAST, (cx_icValue)result, (cx_icValue)rvalue, (cx_icValue)lvalue);
    if (_this->rvalue->forceReference) {
        op->s2Deref = CX_IC_DEREF_ADDRESS;
    }
    cx_icProgram_addIc(program, (cx_ic)op);

    return result;
/* $end */
}
