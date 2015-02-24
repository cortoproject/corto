/* Fast_Element.c
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

/* ::cortex::Fast::Element::construct() */
cx_int16 Fast_Element_construct(Fast_Element _this) {
/* $begin(::cortex::Fast::Element::construct) */
    cx_type lvalueType, rvalueType;

    Fast_Node(_this)->kind = Fast_ElementExpr;

    lvalueType = Fast_Expression_getType(_this->lvalue);

    if (lvalueType) {
        if (lvalueType->kind == CX_COLLECTION) {
            rvalueType = Fast_Expression_getType(_this->rvalue);
            if (rvalueType) {
                if (cx_collection(lvalueType)->kind != CX_MAP) {
                    if (!cx_type_castable(cx_type(cx_uint32_o), rvalueType)) {
                        cx_id id;
                        Fast_Parser_error(yparser(), "expected integer expression for index, got '%s'", Fast_Parser_id(rvalueType, id));
                        goto error;
                    }
                } else {
                    if (!cx_type_castable(cx_map(lvalueType)->keyType, rvalueType)) {
                        cx_id id, id2;
                        Fast_Parser_error(yparser(), "expected expression of type '%s' for key, got '%s'",
                                Fast_Parser_id(cx_map(lvalueType)->keyType, id), Fast_Parser_id(rvalueType, id2));
                        goto error;
                    }
                }
            }
            /* Set type of expression */
            Fast_Expression(_this)->type = Fast_Variable(Fast_Object__create(cx_collection(lvalueType)->elementType));
        } else {
            cx_id id;
            Fast_Parser_error(yparser(), "cannot obtain element from _this of non-collection type '%s'", Fast_Parser_id(lvalueType, id));
            goto error;
        }
    } else {
        Fast_Parser_error(yparser(), "dynamic expressions are not yet supported");
        goto error;
    }
    
    if (Fast_Expression_getType(Fast_Expression(_this))->reference) {
        Fast_Expression(_this)->forceReference = TRUE;
        Fast_Expression(_this)->isReference = TRUE;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::Element::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Element_toIc_v(Fast_Element _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::Element::toIc) */
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
