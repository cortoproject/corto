/* ast_Storage.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "ast.h"

/* ::corto::ast::Storage::construct() */
cx_int16 _ast_Storage_construct(ast_Storage this) {
/* $begin(::corto::ast::Storage::construct) */

    ast_Node(this)->kind = Ast_StorageExpr;
    ast_Expression(this)->deref = ast_Expression(this)->type->reference ? Ast_ByReference : Ast_ByValue;

    return 0;
/* $end */
}
