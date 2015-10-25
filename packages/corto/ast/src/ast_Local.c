/* $CORTO_GENERATED
 *
 * ast_Local.c
 *
 * Code written between the begin and end tags will be preserved when the
 * file is regenerated.
 */

#include "ast.h"

/* $header() */
#include "ast__private.h"
/* $end */

corto_int16 _ast_Local_construct(ast_Local this) {
/* $begin(::corto::ast::Local::construct) */

    ast_Node(this)->kind = Ast_StorageExpr;
    ast_Storage(this)->kind = Ast_LocalStorage;
    corto_setref(&ast_Expression(this)->type, this->type);
    ast_Expression(this)->isReference = this->reference || this->type->reference;

    return ast_Storage_construct(ast_Storage(this));
/* $end */
}

ic_node _ast_Local_toIc_v(ast_Local this, ic_program program, ic_storage storage, corto_bool stored) {
/* $begin(::corto::ast::Local::toIc) */
    ic_node result;
    CORTO_UNUSED(storage);
    CORTO_UNUSED(stored);
    CORTO_UNUSED(program);

    result = (ic_node)ic_program_getVariable(
                program,
                this->name);

    return result;
/* $end */
}
