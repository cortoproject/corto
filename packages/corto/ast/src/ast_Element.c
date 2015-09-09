/* ast_Element.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_ast_LIB
#include "ast.h"

/* $header() */
#include "ast__private.h"
/* $end */

/* ::corto::ast::Element::construct() */
cx_int16 _ast_Element_construct(ast_Element this) {
/* $begin(::corto::ast::Element::construct) */
    cx_type lvalueType, rvalueType;

    ast_Storage(this)->kind = Ast_ElementStorage;

    lvalueType = ast_Expression_getType(this->lvalue);

    if (lvalueType) {
        if (lvalueType->kind == CX_COLLECTION) {
            rvalueType = ast_Expression_getType(this->rvalue);
            if (rvalueType) {
                if (cx_collection(lvalueType)->kind != CX_MAP) {
                    if (!cx_type_castable(cx_type(cx_uint32_o), rvalueType)) {
                        cx_id id;
                        ast_Parser_error(yparser(), "expected integer expression for index, got '%s'", ast_Parser_id(rvalueType, id));
                        goto error;
                    }
                } else {
                    if (!cx_type_castable(cx_map(lvalueType)->keyType, rvalueType)) {
                        cx_id id, id2;
                        ast_Parser_error(yparser(), "expected expression of type '%s' for key, got '%s'",
                                ast_Parser_id(cx_map(lvalueType)->keyType, id), ast_Parser_id(rvalueType, id2));
                        goto error;
                    }
                }
            }
            /* Set type of expression */
            cx_setref(&ast_Expression(this)->type, cx_collection(lvalueType)->elementType);
        } else {
            cx_id id;
            ast_Parser_error(yparser(), "cannot obtain element from this of non-collection type '%s'", ast_Parser_id(lvalueType, id));
            goto error;
        }
    } else {
        ast_Parser_error(yparser(), "dynamic expressions are not yet supported");
        goto error;
    }

    ast_Expression(this)->isReference = cx_collection(lvalueType)->elementType->reference;

    return ast_Storage_construct(ast_Storage(this));
error:
    return -1;
/* $end */
}

/* ::corto::ast::Element::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _ast_Element_toIc_v(ast_Element this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::ast::Element::toIc) */
    ic_element result;
    ic_node lvalue, rvalue;
    CX_UNUSED(stored);
    CX_UNUSED(storage);

    /* Get lvalue & rvalue */
    lvalue = ast_Node_toIc(ast_Node(this->lvalue), program, NULL, TRUE);
    rvalue = ast_Node_toIc(ast_Node(this->rvalue), program, NULL, TRUE);

    result = ic_program_getElement(program, ic_storage(lvalue), rvalue);

    return (ic_node)result;
/* $end */
}
