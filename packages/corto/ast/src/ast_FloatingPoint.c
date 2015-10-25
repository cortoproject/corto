/* $CORTO_GENERATED
 *
 * ast_FloatingPoint.c
 *
 * Code written between the begin and end tags will be preserved when the
 * file is regenerated.
 */

#include "ast.h"

/* $header() */
#include "ast__private.h"
/* $end */

corto_int16 _ast_FloatingPoint_init(ast_FloatingPoint this) {
/* $begin(::corto::ast::FloatingPoint::init) */
    ast_Literal(this)->kind = Ast_Float;
    return ast_Literal_init(ast_Literal(this));
/* $end */
}

corto_int16 _ast_FloatingPoint_serialize(ast_FloatingPoint this, corto_type dstType, corto_word dst) {
/* $begin(::corto::ast::FloatingPoint::serialize) */
    ast_valueKind kind;

    kind = ast_valueKindFromType(dstType);
    memset((void*)dst, 0, corto_type_sizeof(dstType));

    switch(kind) {
    case Ast_Bool:
        *(corto_bool*)dst = this->value ? TRUE : FALSE;
        break;
    case Ast_Int:
    case Ast_SignedInt:
    case Ast_Float:
    case Ast_Text:
        corto_convert(corto_primitive(corto_float64_o), &this->value, corto_primitive(dstType), (void*)dst);
        break;
    default: {
        corto_id id;
        ast_Parser_error(yparser(), "cannot serialize floating point value to storage of type '%s'", ast_Parser_id(dstType, id));
        goto error;
        break;
    }
    }

    return 0;
error:
    return -1;
/* $end */
}

ic_node _ast_FloatingPoint_toIc_v(ast_FloatingPoint this, ic_program program, ic_storage storage, corto_bool stored) {
/* $begin(::corto::ast::FloatingPoint::toIc) */
    ic_node result;
    CORTO_UNUSED(program);
    CORTO_UNUSED(storage);
    CORTO_UNUSED(stored);

    result = (ic_node)ic_literalCreate((corto_any){ast_Expression_getType(ast_Expression(this)), &this->value, FALSE});

    return result;
/* $end */
}
