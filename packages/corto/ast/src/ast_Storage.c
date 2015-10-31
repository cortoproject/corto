/* $CORTO_GENERATED
 *
 * ast_Storage.c
 *
 * Only ode written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "ast.h"

corto_int16 _ast_Storage_construct(ast_Storage this) {
/* $begin(::corto::ast::Storage::construct) */

    ast_Node(this)->kind = Ast_StorageExpr;
    ast_Expression(this)->deref = ast_Expression(this)->type->reference ? Ast_ByReference : Ast_ByValue;

    return 0;
/* $end */
}
