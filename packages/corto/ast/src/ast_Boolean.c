/* ast_Boolean.c
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

/* ::corto::ast::Boolean::init() */
cx_int16 _ast_Boolean_init(ast_Boolean this) {
/* $begin(::corto::ast::Boolean::init) */
    ast_Literal(this)->kind = Ast_Bool;
    return ast_Literal_init(ast_Literal(this));
/* $end */
}

/* ::corto::ast::Boolean::serialize(type dstType,word dst) */
cx_int16 _ast_Boolean_serialize(ast_Boolean this, cx_type dstType, cx_word dst) {
/* $begin(::corto::ast::Boolean::serialize) */
    ast_valueKind kind;

    kind = ast_valueKindFromType(dstType);

    switch(kind) {
    case Ast_Bool:
    case Ast_Int:
        memset((void*)dst, 0, cx_type_sizeof(dstType));
        *(cx_bool*)dst = this->value;
        break;
    case Ast_Text:
        if (*(cx_string*)dst) {
            cx_dealloc(*(cx_string*)dst);
        }
        if (this->value) {
            *(cx_string*)dst = cx_strdup("true");
        } else {
            *(cx_string*)dst = cx_strdup("false");
        }
        break;
    default: {
        cx_id id;
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

/* ::corto::ast::Boolean::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _ast_Boolean_toIc_v(ast_Boolean this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::ast::Boolean::toIc) */
    ic_node result;
    CX_UNUSED(storage);
    CX_UNUSED(stored);
    CX_UNUSED(program);

    result = (ic_node)ic_literalCreate((cx_any){cx_type(cx_bool_o), &this->value, FALSE});

    return result;
/* $end */
}
