/* $CORTO_GENERATED
 *
 * ast_New.c
 *
 * Code written between the begin and end tags will be preserved when the
 * file is regenerated.
 */

#include "ast.h"

/* $header() */
#include "ast__private.h"
/* $end */

corto_int16 _ast_New_construct(ast_New this) {
/* $begin(::corto::ast::New::construct) */

    ast_Node(this)->kind = Ast_NewExpr;
    corto_setref(&ast_Expression(this)->type, this->type);
    ast_Expression(this)->isReference = TRUE;

    return 0;
/* $end */
}

corto_bool _ast_New_hasSideEffects_v(ast_New this) {
/* $begin(::corto::ast::New::hasSideEffects) */
    CORTO_UNUSED(this);
    return TRUE;
/* $end */
}

ic_node _ast_New_toIc_v(ast_New this, ic_program program, ic_storage storage, corto_bool stored) {
/* $begin(::corto::ast::New::toIc) */
    ic_node type, attrs, result;
    CORTO_UNUSED(stored);

    if (storage) {
        result = (ic_node)storage;
    } else {
        result = (ic_node)ic_program_pushAccumulator(program, ast_Expression_getType(ast_Expression(this)), TRUE, FALSE);
    }

    type = (ic_node)ic_objectCreate(ast_Expression(this)->type);
    if (this->attributes) {
        attrs = ast_Node_toIc(ast_Node(this->attributes), program, NULL, TRUE);
    } else {
        attrs = NULL;
    }

    IC_3(program, ast_Node(this)->line, ic_new, 
        result, type, attrs, IC_DEREF_ADDRESS, IC_DEREF_ADDRESS, IC_DEREF_VALUE)

    return result;
/* $end */
}
