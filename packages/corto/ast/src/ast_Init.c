/* ast_Init.c
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

/* ::corto::ast::Init::construct() */
cx_int16 _ast_Init_construct(ast_Init this) {
/* $begin(::corto::ast::Init::construct) */
	cx_type t = ast_Expression_getType(ast_Expression(this->storage));
    ast_Node(this)->kind = Ast_InitExpr;
    cx_setref(&ast_Expression(this)->type, t);
    return 0;
/* $end */
}

/* ::corto::ast::Init::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _ast_Init_toIc_v(ast_Init this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::ast::Init::toIc) */
    ic_node s;
    CX_UNUSED(stored);
    CX_UNUSED(storage);

    s = ast_Node_toIc(ast_Node(this->storage), program, NULL, TRUE);
    IC_1(program, ast_Node(this)->line, ic_init, s, IC_DEREF_ADDRESS);

    return NULL;
/* $end */
}
