/* ast_Character.c
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

/* ::corto::ast::Character::init() */
corto_int16 _ast_Character_init(ast_Character this) {
/* $begin(::corto::ast::Character::init) */
    ast_Literal(this)->kind = Ast_Char;
    return ast_Literal_init(ast_Literal(this));
/* $end */
}

/* ::corto::ast::Character::serialize(type dstType,word dst) */
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

/* ::corto::ast::Character::toIc(ic::program program,ic::storage storage,bool stored) */
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
