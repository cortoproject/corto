/* ast_Template.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "ast.h"

/* ::corto::ast::Template::construct() */
corto_int16 _ast_Template_construct(ast_Template this) {
/* $begin(::corto::ast::Template::construct) */

    if (ast_Local_construct(ast_Local(this))) {
        goto error;
    } else {
        ast_Storage(this)->kind = Ast_TemplateStorage;
    }

    return ast_Storage_construct(ast_Storage(this));
error:
    return -1;
/* $end */
}
