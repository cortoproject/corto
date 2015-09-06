/* Fast_PostFix.c
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

/* ::corto::Fast::PostFix::construct() */
cx_int16 _Fast_PostFix_construct(Fast_PostFix _this) {
/* $begin(::corto::Fast::PostFix::construct) */
    cx_type lvalueType = Fast_Expression_getType(_this->lvalue);

    /* Validate whether operation is allowed */
    if (lvalueType->reference) {
        cx_id id;
        Fast_Parser_error(
            yparser(), "invalid operator for reference type '%s'", Fast_Parser_id(lvalueType, id));
        goto error;
    } else {
        cx_id id;
        switch(lvalueType->kind) {

        case CX_PRIMITIVE:
            switch(cx_primitive(lvalueType)->kind) {
            case CX_INTEGER:
            case CX_UINTEGER:
            case CX_BINARY:
            case CX_CHARACTER:
            case CX_FLOAT:
                break;
            default:
                Fast_Parser_error(
                    yparser(), "invalid operator for type '%s'", Fast_Parser_id(lvalueType, id));
                goto error;
                break;       
            }
            cx_setref(&Fast_Expression(_this)->type, lvalueType);
            break;

        case CX_ITERATOR:
            if (_this->operator == CX_INC) {
                /* The result of an expression that increments an iterator is a boolean */
                cx_setref(&Fast_Expression(_this)->type, cx_bool_o);
            } else {
                Fast_Parser_error(yparser(), "invalid operator for iterator");
                goto error;
            }
            break;

        default:
            Fast_Parser_error(
                yparser(), "invalid operator for type '%s'", Fast_Parser_id(lvalueType, id));
            goto error;
            break;
        }
    }

    Fast_Node(_this)->kind = Fast_PostfixExpr;
    
    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::Fast::PostFix::hasReturnedResource() */
cx_bool _Fast_PostFix_hasReturnedResource_v(Fast_PostFix _this) {
/* $begin(::corto::Fast::PostFix::hasReturnedResource) */
    return Fast_Expression_hasReturnedResource(_this->lvalue);
/* $end */
}

/* ::corto::Fast::PostFix::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_PostFix_toIc_v(Fast_PostFix _this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::Fast::PostFix::toIc) */
    ic_storage result;
    ic_node lvalue;
    cx_type lvalueType = Fast_Expression_getType(_this->lvalue);
    CX_UNUSED(stored);

    if (storage) {
        result = storage;
    } else {
        result = (ic_storage)ic_program_pushAccumulator(
            program,
            Fast_Expression_getType(Fast_Expression(_this)),
            Fast_Expression(_this)->isReference,
            FALSE);
    }

    lvalue = Fast_Node_toIc(Fast_Node(_this->lvalue), program, result, TRUE);
    IC_3(program, Fast_Node(_this)->line, ic_opKindFromOperator(_this->operator), lvalue, ic_node(result), NULL,
            IC_DEREF_VALUE, IC_DEREF_VALUE, IC_DEREF_VALUE);

    if (!storage) {
        ic_program_popAccumulator(program);
    } else if ((lvalueType->kind == CX_ITERATOR) && (_this->operator == CX_INC)) {
        lvalue = (ic_node)storage;
    }

    return (ic_node)lvalue;
/* $end */
}
