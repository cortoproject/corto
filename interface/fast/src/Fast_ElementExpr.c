/* Fast_ElementExpr.c
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
#include "Fast_Parser.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
/* $end */

/* callback ::cortex::lang::class::construct(object object) -> ::cortex::Fast::ElementExpr::construct(Fast::MemberExpr object) */
cx_int16 Fast_ElementExpr_construct(Fast_MemberExpr object) {
/* $begin(::cortex::Fast::ElementExpr::construct) */
    cx_type lvalueType, rvalueType;

    Fast_Node(object)->kind = FAST_Element;

    lvalueType = Fast_Expression_getType(object->lvalue);

    if (lvalueType) {
        if (lvalueType->kind == CX_COLLECTION) {
            rvalueType = Fast_Expression_getType(object->rvalue);
            if (rvalueType) {
                if (cx_collection(lvalueType)->kind != CX_MAP) {
                    if (!cx_type_castable(cx_type(cx_uint32_o), rvalueType)) {
                        cx_id id;
                        Fast_Parser_error(yparser(), "expected integer expression for index, got '%s'", cx_fullname(rvalueType, id));
                        goto error;
                    }
                } else {
                    if (!cx_type_castable(cx_map(lvalueType)->keyType->real, rvalueType)) {
                        cx_id id, id2;
                        Fast_Parser_error(yparser(), "expected expression of type '%s' for key, got '%s'",
                                cx_fullname(cx_map(lvalueType)->keyType->real, id), cx_fullname(rvalueType, id2));
                        goto error;
                    }
                }
            }
            /* Set type of expression */
            Fast_Expression(object)->type = Fast_Variable(Fast_Object__create(cx_collection(lvalueType)->elementType->real));
        } else {
            cx_id id;
            Fast_Parser_error(yparser(), "cannot obtain element from object of non-collection type '%s'", cx_fullname(lvalueType, id));
            goto error;
        }
    } else {
        Fast_Parser_error(yparser(), "dynamic expressions are not yet supported");
        goto error;
    }
    
    if (Fast_Expression_getType(Fast_Expression(object))->reference) {
        Fast_Expression(object)->forceReference = TRUE;
        Fast_Expression(object)->isReference = TRUE;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::ElementExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_ElementExpr_toIc_v(Fast_ElementExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::ElementExpr::toIc) */
    cx_icElement result;
    cx_ic lvalue, rvalue;
    CX_UNUSED(stored);
    CX_UNUSED(storage);

    /* Get lvalue & rvalue */
    lvalue = Fast_Node_toIc(Fast_Node(_this->lvalue), program, NULL, TRUE);
    rvalue = Fast_Node_toIc(Fast_Node(_this->rvalue), program, NULL, TRUE);

    result = cx_icElement__create(program, Fast_Node(_this)->line, Fast_Expression_getType(Fast_Expression(_this)), (cx_icStorage)lvalue, (cx_icValue)rvalue);

    return (cx_ic)result;
/* $end */
}
