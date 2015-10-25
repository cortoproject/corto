/* $CORTO_GENERATED
 *
 * ast_Character.c
 *
 * Code written between the begin and end tags will be preserved when the
 * file is regenerated.
 */

#include "ast.h"

/* $header() */
#include "ast__private.h"
/* $end */

corto_int16 _ast_Character_init(ast_Character this) {
/* $begin(::corto::ast::Character::init) */
    ast_Literal(this)->kind = Ast_Char;
    return ast_Literal_init(ast_Literal(this));
/* $end */
}

corto_int16 _ast_Character_serialize(ast_Character this, corto_type dstType, corto_word dst) {
/* $begin(::corto::ast::Character::serialize) */
    ast_valueKind kind;

    kind = ast_valueKindFromType(dstType);

    switch(kind) {
    case Ast_Bool:
        *(corto_bool*)dst = this->value ? TRUE : FALSE;
        break;
    case Ast_Char:
    case Ast_Int:
    case Ast_SignedInt:
    case Ast_Text:
        corto_convert(corto_primitive(corto_char_o), &this->value, corto_primitive(dstType), (void*)dst);
        break;
    default: {
        corto_id id;
        ast_Parser_error(yparser(), "cannot serialize character value to storage of type '%s'", ast_Parser_id(dstType, id));
        goto error;
        break;
    }
    }

    return 0;
error:
    return -1;
/* $end */
}

ic_node _ast_Character_toIc_v(ast_Character this, ic_program program, ic_storage storage, corto_bool stored) {
/* $begin(::corto::ast::Character::toIc) */
    ic_literal result;
    CORTO_UNUSED(program);
    CORTO_UNUSED(storage);
    CORTO_UNUSED(stored);

    result = ic_literalCreate((corto_any){corto_type(corto_char_o), &this->value, FALSE});

    return ic_node(result);
/* $end */
}
