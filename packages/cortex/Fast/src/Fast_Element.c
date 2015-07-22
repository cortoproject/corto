/* Fast_Element.c
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

/* ::cortex::Fast::Element::construct() */
cx_int16 Fast_Element_construct(Fast_Element _this) {
/* $begin(::cortex::Fast::Element::construct) */
    cx_type lvalueType, rvalueType;

    Fast_Storage(_this)->kind = Fast_ElementStorage;

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
            cx_setref(&Fast_Expression(_this)->type, cx_collection(lvalueType)->elementType);
        } else {
            cx_id id;
            Fast_Parser_error(yparser(), "cannot obtain element from _this of non-collection type '%s'", Fast_Parser_id(lvalueType, id));
            goto error;
        }
    } else {
        Fast_Parser_error(yparser(), "dynamic expressions are not yet supported");
        goto error;
    }

    Fast_Expression(_this)->isReference = cx_collection(lvalueType)->elementType->reference;

    return Fast_Storage_construct(Fast_Storage(_this));
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::Element::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Element_toIc_v(Fast_Element _this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::cortex::Fast::Element::toIc) */
    ic_element result;
    ic_node lvalue, rvalue;
    CX_UNUSED(stored);
    CX_UNUSED(storage);

    /* Get lvalue & rvalue */
    lvalue = Fast_Node_toIc(Fast_Node(_this->lvalue), program, NULL, TRUE);
    rvalue = Fast_Node_toIc(Fast_Node(_this->rvalue), program, NULL, TRUE);

    result = ic_program_getElement(program, ic_storage(lvalue), rvalue);

    return (ic_node)result;
/* $end */
}
