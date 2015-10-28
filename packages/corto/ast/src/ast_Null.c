/* $CORTO_GENERATED
 *
 * ast_Null.c
 *
 * Code written between the begin and end tags will be preserved when the
 * file is regenerated.
 */

#include "ast.h"

/* $header() */
#include "ast__private.h"
/* $end */

corto_int16 _ast_Null_init(ast_Null this) {
/* $begin(::corto::ast::Null::init) */
    ast_Literal(this)->kind = Ast_Nothing;
    ast_Expression(this)->type = NULL;
    return ast_Literal_init(ast_Literal(this));
/* $end */
}

corto_int16 _ast_Null_serialize(ast_Null this, corto_type dstType, corto_word dst) {
/* $begin(::corto::ast::Null::serialize) */
    ast_valueKind kind;
    CORTO_UNUSED(this);

    kind = ast_valueKindFromType(dstType);
    
    switch(kind) {
    case Ast_Bool:
        *(corto_bool*)dst = FALSE;
        break;
    case Ast_Text:
        if (*(corto_string*)dst) {
            corto_dealloc(*(corto_string*)dst);
        }
        *(corto_string*)dst = NULL;
        break;
    case Ast_Ref:
        if (*(corto_object*)dst) {
            corto_release(*(corto_object*)dst);
        }
        *(corto_object*)dst = NULL;
        break;
    default: {
        corto_id id;
        ast_Parser_error(yparser(), "cannot serialize null value to storage of type '%s'", ast_Parser_id(dstType, id));
        goto error;
        break;
    }
    }

    return 0;
error:
    return -1;
/* $end */
}

ic_node _ast_Null_toIc_v(ast_Null this, ic_program program, ic_storage storage, corto_bool stored) {
/* $begin(::corto::ast::Null::toIc) */
    CORTO_UNUSED(storage);
    CORTO_UNUSED(stored);
    CORTO_UNUSED(this);
    CORTO_UNUSED(program);

    corto_any l = {corto_type(corto_void_o), NULL, FALSE};
    return ic_node(ic_literalCreate(l));
/* $end */
}
