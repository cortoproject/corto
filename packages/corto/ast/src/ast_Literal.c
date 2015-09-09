/* ast_Literal.c
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

/* ::corto::ast::Literal::getValue() */
cx_word _ast_Literal_getValue_v(ast_Literal this) {
/* $begin(::corto::ast::Literal::getValue) */
    cx_word result = 0;

    switch(this->kind) {
    case Ast_Bool: result = (cx_word)&Ast_Boolean(this)->value; break;
    case Ast_Char: result = (cx_word)&Ast_Character(this)->value; break;
    case Ast_Int: result = (cx_word)&Ast_Integer(this)->value; break;
    case Ast_SignedInt: result = (cx_word)&Ast_SignedInteger(this)->value; break;
    case Ast_Float: result = (cx_word)&Ast_FloatingPoint(this)->value; break;
    default: break; /* Enumerated, Reference & Null have no value. String handles it's own value. */
    }

    return result;
/* $end */
}

/* ::corto::ast::Literal::init() */
cx_int16 _ast_Literal_init(ast_Literal this) {
/* $begin(::corto::ast::Literal::init) */
    if (!ast_Expression(this)->type) {
        switch(this->kind) {
        case Ast_Bool:
            cx_setref(&ast_Expression(this)->type, cx_bool_o);
            break;
        case Ast_Char:
            cx_setref(&ast_Expression(this)->type, cx_char_o);
            break;
        case Ast_Int:
            cx_setref(&ast_Expression(this)->type, cx_uint64_o);
            break;
        case Ast_SignedInt:
            cx_setref(&ast_Expression(this)->type, cx_int64_o);
            break;
        case Ast_Float:
            cx_setref(&ast_Expression(this)->type, cx_float64_o);
            break;
        case Ast_Text:
            cx_setref(&ast_Expression(this)->type, cx_string_o);
            break;
        case Ast_Enum:
            cx_setref(&ast_Expression(this)->type, cx_uint32_o);
            break;
        case Ast_Ref:
            cx_setref(&ast_Expression(this)->type, cx_object_o);
            break;
        case Ast_Nothing:
            /* No type. */
            break;
        }
    }

    ast_Node(this)->kind = Ast_LiteralExpr;

    return ast_Node_init(ast_Node(this));
/* $end */
}
