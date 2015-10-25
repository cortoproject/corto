/* $CORTO_GENERATED
 *
 * ast_Define.c
 *
 * Code written between the begin and end tags will be preserved when the
 * file is regenerated.
 */

#include "ast.h"

/* $header() */
#include "ast__private.h"
/* $end */

corto_int16 _ast_Define_construct(ast_Define this) {
/* $begin(::corto::ast::Define::construct) */

    ast_Node(this)->kind = Ast_DefineExpr;

    return 0;
/* $end */
}

ic_node _ast_Define_toIc_v(ast_Define this, ic_program program, ic_storage storage, corto_bool stored) {
/* $begin(::corto::ast::Define::toIc) */
    ic_node object;
    CORTO_UNUSED(stored);
    CORTO_UNUSED(storage);

    object = ast_Node_toIc(ast_Node(this->object), program, NULL, TRUE);
    IC_1(program, ast_Node(this)->line, ic_define, object, IC_DEREF_ADDRESS);

    return NULL;
/* $end */
}
