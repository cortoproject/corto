/* ast_SignedInteger.c
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

/* ::corto::ast::SignedInteger::init() */
corto_int16 _ast_SignedInteger_init(ast_SignedInteger this) {
/* $begin(::corto::ast::SignedInteger::init) */
    ast_Literal(this)->kind = Ast_SignedInt;
    return ast_Literal_init(ast_Literal(this));
/* $end */
}

/* ::corto::ast::SignedInteger::serialize(type dstType,word dst) */
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

/* ::corto::ast::SignedInteger::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _ast_SignedInteger_toIc_v(ast_SignedInteger this, ic_program program, ic_storage storage, corto_bool stored) {
/* $begin(::corto::ast::SignedInteger::toIc) */
    ic_node result;
    CORTO_UNUSED(storage);
    CORTO_UNUSED(stored);
    CORTO_UNUSED(program);

    result = (ic_node)ic_literalCreate((corto_any){ast_Expression_getType(ast_Expression(this)), &this->value, FALSE});

    return result;
/* $end */
}
