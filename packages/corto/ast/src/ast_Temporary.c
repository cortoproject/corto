/* ast_Temporary.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "ast.h"

/* ::corto::ast::Temporary::construct() */
corto_int16 _ast_Temporary_construct(ast_Temporary this) {
/* $begin(::corto::ast::Temporary::construct) */

    ast_Storage(this)->kind = Ast_TemporaryStorage;
    corto_setref(&ast_Expression(this)->type, this->type);
    ast_Expression(this)->isReference = this->reference;

    return ast_Storage_construct(ast_Storage(this));
/* $end */
}

/* ::corto::ast::Temporary::setProxy(Temporary proxy) */
corto_void _ast_Temporary_setProxy(ast_Temporary this, ast_Temporary proxy) {
/* $begin(::corto::ast::Temporary::setProxy) */
    corto_setref(&this->proxy, proxy);
/* $end */
}

/* ::corto::ast::Temporary::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _ast_Temporary_toIc_v(ast_Temporary this, ic_program program, ic_storage storage, corto_bool stored) {
/* $begin(::corto::ast::Temporary::toIc) */
    CORTO_UNUSED(storage);
    CORTO_UNUSED(stored);
    CORTO_UNUSED(program);

    if (!this->proxy && !this->ic) {
        ic_node acc = ic_node(ic_accumulatorCreate(NULL, this->type, this->reference || this->type->reference, FALSE));
        corto_setref(&this->ic, acc);
        corto_release(acc);
    } else if (this->proxy) {
        ic_node acc = ast_Temporary_toIc(this->proxy, program, storage, stored);
        corto_setref(&this->ic, acc);
    }

    return this->ic;
/* $end */
}
