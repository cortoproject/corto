/* Ast_Character.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_ast_LIB
#include "ast.h"

/* $header() */
#include "ast__private.h"
/* $end */

/* ::corto::ast::Character::init() */
cx_int16 _Ast_Character_init(Ast_Character this) {
/* $begin(::corto::ast::Character::init) */
    ast_Literal(this)->kind = Ast_Char;
    return ast_Literal_init(ast_Literal(this));
/* $end */
}

/* ::corto::ast::Character::serialize(type dstType,word dst) */
cx_int16 _Ast_Character_serialize(Ast_Character this, cx_type dstType, cx_word dst) {
/* $begin(::corto::ast::Character::serialize) */
    ast_valueKind kind;

    kind = ast_valueKindFromType(dstType);

    switch(kind) {
    case Ast_Bool:
        *(cx_bool*)dst = this->value ? TRUE : FALSE;
        break;
    case Ast_Char:
    case Ast_Int:
    case Ast_SignedInt:
    case Ast_Text:
        cx_convert(cx_primitive(cx_char_o), &this->value, cx_primitive(dstType), (void*)dst);
        break;
    default: {
        cx_id id;
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
ic_node _Ast_Character_toIc_v(Ast_Character this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::ast::Character::toIc) */
    ic_literal result;
    CX_UNUSED(program);
    CX_UNUSED(storage);
    CX_UNUSED(stored);

    result = ic_literalCreate((cx_any){cx_type(cx_char_o), &this->value, FALSE});

    return ic_node(result);
/* $end */
}
