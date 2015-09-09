/* ast_Null.c
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

/* ::corto::ast::Null::init() */
cx_int16 _ast_Null_init(ast_Null this) {
/* $begin(::corto::ast::Null::init) */
    ast_Literal(this)->kind = Ast_Nothing;
    ast_Expression(this)->type = NULL;
    return ast_Literal_init(ast_Literal(this));
/* $end */
}

/* ::corto::ast::Null::serialize(type dstType,word dst) */
cx_int16 _ast_Null_serialize(ast_Null this, cx_type dstType, cx_word dst) {
/* $begin(::corto::ast::Null::serialize) */
    ast_valueKind kind;
    CX_UNUSED(this);

    kind = ast_valueKindFromType(dstType);
    
    switch(kind) {
    case Ast_Bool:
        *(cx_bool*)dst = FALSE;
        break;
    case Ast_Text:
        if (*(cx_string*)dst) {
            cx_dealloc(*(cx_string*)dst);
        }
        *(cx_string*)dst = NULL;
        break;
    case Ast_Ref:
        if (*(cx_object*)dst) {
            cx_release(*(cx_object*)dst);
        }
        *(cx_object*)dst = NULL;
        break;
    default: {
        cx_id id;
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

/* ::corto::ast::Null::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _ast_Null_toIc_v(ast_Null this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::ast::Null::toIc) */
    CX_UNUSED(storage);
    CX_UNUSED(stored);
    CX_UNUSED(this);
    CX_UNUSED(program);

    return ic_node(ic_literalCreate((cx_any){cx_type(cx_void_o), NULL, FALSE}));
/* $end */
}
