/* $CORTO_GENERATED
 *
 * ast_SignedInteger.c
 *
 * Code written between the begin and end tags will be preserved when the
 * file is regenerated.
 */

#include "ast.h"

/* $header() */
#include "ast__private.h"
/* $end */

corto_int16 _ast_SignedInteger_init(ast_SignedInteger this) {
/* $begin(::corto::ast::SignedInteger::init) */
    ast_Literal(this)->kind = Ast_SignedInt;
    return ast_Literal_init(ast_Literal(this));
/* $end */
}

corto_int16 _ast_SignedInteger_serialize(ast_SignedInteger this, corto_type dstType, corto_word dst) {
/* $begin(::corto::ast::SignedInteger::serialize) */
    ast_valueKind kind;

    kind = ast_valueKindFromType(dstType);
    
    memset((void*)dst, 0, corto_type_sizeof(dstType));

    switch(kind) {
    case Ast_Bool:
        *(corto_bool*)dst = this->value ? TRUE : FALSE;
        break;
    case Ast_Char:
    case Ast_Int:
    case Ast_SignedInt:
    case Ast_Enum:
    case Ast_Text:
        corto_convert(corto_primitive(corto_int64_o), &this->value, corto_primitive(dstType), (void*)dst);
        break;
    default: {
        corto_id id;
        ast_Parser_error(yparser(), "cannot serialize signed integer value to storage of type '%s'", ast_Parser_id(dstType, id));
        goto error;
        break;
    }
    }

    return 0;
error:
    return -1;
/* $end */
}

ic_node _ast_SignedInteger_toIc_v(ast_SignedInteger this, ic_program program, ic_storage storage, corto_bool stored) {
/* $begin(::corto::ast::SignedInteger::toIc) */
    ic_node result;
    CORTO_UNUSED(storage);
    CORTO_UNUSED(stored);
    CORTO_UNUSED(program);

    corto_any l = {ast_Expression_getType(ast_Expression(this)), &this->value, FALSE};
    result = (ic_node)ic_literalCreate(l);

    return result;
/* $end */
}
