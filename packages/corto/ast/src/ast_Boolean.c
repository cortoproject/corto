/* $CORTO_GENERATED
 *
 * ast_Boolean.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "ast.h"

/* $header() */
#include "ast__private.h"
/* $end */

corto_int16 _ast_Boolean_init(ast_Boolean this) {
/* $begin(::corto::ast::Boolean::init) */
    ast_Literal(this)->kind = Ast_Bool;
    return ast_Literal_init(ast_Literal(this));
/* $end */
}

corto_int16 _ast_Boolean_serialize(ast_Boolean this, corto_type dstType, corto_word dst) {
/* $begin(::corto::ast::Boolean::serialize) */
    ast_valueKind kind;

    kind = ast_valueKindFromType(dstType);

    switch(kind) {
    case Ast_Bool:
    case Ast_Int:
        memset((void*)dst, 0, corto_type_sizeof(dstType));
        *(corto_bool*)dst = this->value;
        break;
    case Ast_Text:
        if (*(corto_string*)dst) {
            corto_dealloc(*(corto_string*)dst);
        }
        if (this->value) {
            *(corto_string*)dst = corto_strdup("true");
        } else {
            *(corto_string*)dst = corto_strdup("false");
        }
        break;
    default: {
        corto_id id;
        ast_Parser_error(yparser(), "cannot serialize boolean value to storage of type '%s'", ast_Parser_id(dstType, id));
        goto error;
        break;
    }
    }

    return 0;
error:
    return -1;
/* $end */
}

ic_node _ast_Boolean_toIc_v(ast_Boolean this, ic_program program, ic_storage storage, corto_bool stored) {
/* $begin(::corto::ast::Boolean::toIc) */
    ic_node result;
    CORTO_UNUSED(storage);
    CORTO_UNUSED(stored);
    CORTO_UNUSED(program);

    corto_any l = {corto_type(corto_bool_o), &this->value, FALSE};
    result = (ic_node)ic_literalCreate(l);

    return result;
/* $end */
}
