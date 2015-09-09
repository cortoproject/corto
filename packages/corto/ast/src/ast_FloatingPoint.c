/* Ast_FloatingPoint.c
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

/* ::corto::ast::FloatingPoint::init() */
cx_int16 _Ast_FloatingPoint_init(Ast_FloatingPoint this) {
/* $begin(::corto::ast::FloatingPoint::init) */
    ast_Literal(this)->kind = Ast_Float;
    return ast_Literal_init(ast_Literal(this));
/* $end */
}

/* ::corto::ast::FloatingPoint::serialize(type dstType,word dst) */
cx_int16 _Ast_FloatingPoint_serialize(Ast_FloatingPoint this, cx_type dstType, cx_word dst) {
/* $begin(::corto::ast::FloatingPoint::serialize) */
    ast_valueKind kind;

    kind = ast_valueKindFromType(dstType);
    memset((void*)dst, 0, cx_type_sizeof(dstType));

    switch(kind) {
    case Ast_Bool:
        *(cx_bool*)dst = this->value ? TRUE : FALSE;
        break;
    case Ast_Int:
    case Ast_SignedInt:
    case Ast_Float:
    case Ast_Text:
        cx_convert(cx_primitive(cx_float64_o), &this->value, cx_primitive(dstType), (void*)dst);
        break;
    default: {
        cx_id id;
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

/* ::corto::ast::FloatingPoint::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Ast_FloatingPoint_toIc_v(Ast_FloatingPoint this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::ast::FloatingPoint::toIc) */
    ic_node result;
    CX_UNUSED(program);
    CX_UNUSED(storage);
    CX_UNUSED(stored);

    result = (ic_node)ic_literalCreate((cx_any){ast_Expression_getType(ast_Expression(this)), &this->value, FALSE});

    return result;
/* $end */
}
