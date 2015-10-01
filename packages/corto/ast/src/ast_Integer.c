/* ast_Integer.c
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

/* ::corto::ast::Integer::init() */
cx_int16 _ast_Integer_init(ast_Integer this) {
/* $begin(::corto::ast::Integer::init) */
    ast_Literal(this)->kind = Ast_Int;
    return ast_Literal_init((ast_Literal)this);
/* $end */
}

/* ::corto::ast::Integer::serialize(type dstType,word dst) */
cx_int16 _ast_Integer_serialize(ast_Integer this, cx_type dstType, cx_word dst) {
/* $begin(::corto::ast::Integer::serialize) */
    ast_valueKind kind;

    kind = ast_valueKindFromType(dstType);
    memset((void*)dst, 0, cx_type_sizeof(dstType));

    switch(kind) {
    case Ast_Bool:
        *(cx_bool*)dst = this->value ? TRUE : FALSE;
        break;
    case Ast_Char:
    case Ast_Int:
    case Ast_SignedInt:
    case Ast_Float:
    case Ast_Enum:
    case Ast_Text:
        cx_convert(cx_primitive(cx_uint64_o), &this->value, cx_primitive(dstType), (void*)dst);
        break;
    default: {
        cx_id id;
        ast_Parser_error(yparser(), "cannot serialize integer value to storage of type '%s'", ast_Parser_id(dstType, id));
        goto error;
        break;
    }
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::ast::Integer::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _ast_Integer_toIc_v(ast_Integer this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::ast::Integer::toIc) */
    ic_node result;
    CX_UNUSED(program);
    CX_UNUSED(storage);
    CX_UNUSED(stored);

    result = (ic_node)ic_literalCreate((cx_any){ast_Expression_getType(ast_Expression(this)), &this->value, FALSE});

    return result;
/* $end */
}
