/* ast_Cast.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "ast.h"

/* $header() */
#include "ast__private.h"
/* $end */

/* ::corto::ast::Cast::construct() */
corto_int16 _ast_Cast_construct(ast_Cast this) {
/* $begin(::corto::ast::Cast::construct) */

    ast_Node(this)->kind = Ast_CallExpr;

    corto_type rvalueType;
    rvalueType = ast_Expression_getType(this->rvalue);
    if (rvalueType) {
        if ((this->isReference && rvalueType->reference && (rvalueType->kind == CORTO_VOID)) ||
           (corto_type_castable(this->lvalue, rvalueType) || corto_type_castable(rvalueType, this->lvalue))) {
            corto_setref(&ast_Expression(this)->type, this->lvalue);
            ast_Expression(this)->isReference = this->lvalue->reference || this->isReference;
        } else {
            corto_id id1, id2;
            ast_Parser_error(yparser(), "cannot cast from type '%s' to '%s'",
                    ast_Parser_id(rvalueType, id1), ast_Parser_id(this->lvalue, id2));
            goto error;
        }
    } else {
        /* If type of rvalue is unknown, cast is performed at runtime. Set type even though to introduce the
         * type barrier for code using this expression. */
        corto_setref(&ast_Expression(this)->type, this->lvalue);
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::ast::Cast::hasReturnedResource() */
corto_bool _ast_Cast_hasReturnedResource_v(ast_Cast this) {
/* $begin(::corto::ast::Cast::hasReturnedResource) */

    return ast_Expression_hasReturnedResource(this->rvalue);

/* $end */
}

/* ::corto::ast::Cast::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _ast_Cast_toIc_v(ast_Cast this, ic_program program, ic_storage storage, corto_bool stored) {
/* $begin(::corto::ast::Cast::toIc) */
    ic_node lvalue, rvalue, result;
    corto_bool deref1 = IC_DEREF_VALUE, deref2 = IC_DEREF_VALUE;
    corto_type thisType = ast_Expression_getType(ast_Expression(this));
    CORTO_UNUSED(stored);

    if (storage && (storage->type == thisType)) {
        result = (ic_node)storage;
    } else {
        result = (ic_node)ic_program_pushAccumulator(
            program,
            ast_Expression_getType(ast_Expression(this)),
            (this->rvalue->deref == Ast_ByReference) || thisType->reference,
            FALSE);
    }

    lvalue = (ic_node)ic_objectCreate(this->lvalue);
    rvalue = ast_Node_toIc(ast_Node(this->rvalue), program, (ic_storage)NULL, TRUE);

    if ((this->rvalue->deref == Ast_ByReference) || thisType->reference) {
        deref2 = IC_DEREF_ADDRESS;
    }
    if (ic_storage(result)->isReference) {
        deref1 = IC_DEREF_ADDRESS;
    }

    IC_3(program, ast_Node(this)->line, ic_cast, result, rvalue, lvalue,
        deref1, deref2, IC_DEREF_ADDRESS);

    return result;
/* $end */
}
