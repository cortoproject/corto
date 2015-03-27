/* Fast_PostFix.c
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

/* ::cortex::Fast::PostFix::construct() */
cx_int16 Fast_PostFix_construct(Fast_PostFix _this) {
/* $begin(::cortex::Fast::PostFix::construct) */
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
            Fast_Expression(_this)->type = Fast_Variable(Fast_Object__create(lvalueType));
            break;

        case CX_ITERATOR:
            if (_this->operator == CX_INC) {
                /* The result of an expression that increments an iterator is a boolean */
                Fast_Expression(_this)->type = Fast_Variable(Fast_Object__create(cx_bool_o));
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

/* ::cortex::Fast::PostFix::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_PostFix_toIc_v(Fast_PostFix _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::PostFix::toIc) */
    cx_icStorage result;
    cx_ic lvalue;
    cx_icOp op = NULL;
    cx_type lvalueType = Fast_Expression_getType(_this->lvalue);
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
    op = cx_icOp__create(program, Fast_Node(_this)->line, cx_icOpKindFromOperator(_this->operator), (cx_icValue)lvalue, (cx_icValue)result, NULL);
    cx_icProgram_addIc(program, (cx_ic)op);

    if (!storage) {
        cx_icProgram_accumulatorPop(program, Fast_Node(_this)->line);
    } else if ((lvalueType->kind == CX_ITERATOR) && (_this->operator == CX_INC)) {
        lvalue = (cx_ic)storage;
    }

    return (cx_ic)lvalue;
/* $end */
}
