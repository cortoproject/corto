/* Fast_PostfixExpr.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"
#include "Fast__meta.h"

/* $header() */
#include "Fast__api.h"
#include "Fast.h"
#include "Fast_Parser.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
cx_string Fast_Parser_id(cx_object o, cx_id buffer);
/* $end */

/* ::cortex::Fast::PostfixExpr::construct() */
cx_int16 Fast_PostfixExpr_construct(Fast_PostfixExpr _this) {
/* $begin(::cortex::Fast::PostfixExpr::construct) */
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
            break;
        default:
            Fast_Parser_error(
                yparser(), "invalid operator for type '%s'", Fast_Parser_id(lvalueType, id));
            goto error;
            break;
        }
    }


    Fast_Node(_this)->kind = FAST_Postfix;
    Fast_Expression(_this)->type = Fast_Variable(Fast_Object__create(lvalueType));

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::PostfixExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_PostfixExpr_toIc_v(Fast_PostfixExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::PostfixExpr::toIc) */
    cx_icStorage result;
    cx_ic lvalue;
    cx_icOp op;
    CX_UNUSED(stored);

    if (storage) {
        result = storage;
    } else {
        result = (cx_icStorage)cx_icProgram_accumulatorPush(
            program, 
            Fast_Node(_this)->line, 
            Fast_Expression_getType(Fast_Expression(_this)),
            Fast_Expression(_this)->isReference);
    }

    lvalue = Fast_Node_toIc(Fast_Node(_this->lvalue), program, result, TRUE);

    op = cx_icOp__create(program, Fast_Node(_this)->line, cx_icOpKindFromOperator(_this->operator), (cx_icValue)lvalue, NULL, NULL);
    cx_icProgram_addIc(program, (cx_ic)op);

    if (!storage) {
        cx_icProgram_accumulatorPop(program, Fast_Node(_this)->line);
    }

    return (cx_ic)lvalue;
/* $end */
}
