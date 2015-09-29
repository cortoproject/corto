/* ast_Local.c
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

/* ::corto::ast::Local::construct() */
cx_int16 _ast_Local_construct(ast_Local this) {
/* $begin(::corto::ast::Local::construct) */

    ast_Node(this)->kind = Ast_StorageExpr;
    ast_Storage(this)->kind = Ast_LocalStorage;
    cx_setref(&ast_Expression(this)->type, this->type);
    ast_Expression(this)->isReference = this->reference || this->type->reference;

    return ast_Storage_construct(ast_Storage(this));
/* $end */
}

/* ::corto::ast::Local::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _ast_Local_toIc_v(ast_Local this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::ast::Local::toIc) */
    ic_node result;
    CX_UNUSED(storage);
    CX_UNUSED(stored);
    CX_UNUSED(program);

    result = (ic_node)ic_program_getVariable(
                program,
                this->name);

    return result;
/* $end */
}
