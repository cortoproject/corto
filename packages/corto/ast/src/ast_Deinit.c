/* ast_Deinit.c
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

/* ::corto::ast::Deinit::construct() */
corto_int16 _ast_Deinit_construct(ast_Deinit this) {
/* $begin(::corto::ast::Deinit::construct) */
	corto_type t = ast_Expression_getType(ast_Expression(this->storage));
    ast_Node(this)->kind = Ast_DeinitExpr;
    corto_setref(&ast_Expression(this)->type, t);
    return 0;
/* $end */
}

/* ::corto::ast::Deinit::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _ast_Deinit_toIc_v(ast_Deinit this, ic_program program, ic_storage storage, corto_bool stored) {
/* $begin(::corto::ast::Deinit::toIc) */
    ic_node s;
    CORTO_UNUSED(stored);
    CORTO_UNUSED(storage);

    s = ast_Node_toIc(ast_Node(this->storage), program, NULL, TRUE);
    IC_1(program, ast_Node(this)->line, ic_deinit, s, IC_DEREF_ADDRESS);

    return NULL;
/* $end */
}
