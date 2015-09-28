/* ast_Member.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "ast.h"

/* $header() */
#include "ast__private.h"

cx_int16 ast_Member_resolveMember(ast_Member this, cx_type type, cx_string member) {
    cx_object o = NULL;

    if (cx_instanceof(cx_type(cx_interface_o), type) && !strcmp(member, "super")) {
        if (cx_interface(type)->base) {
            this->member = NULL;
            cx_setref(&ast_Expression(this)->type, cx_interface(type)->base);
        } else {
            cx_id id;
            ast_Parser_error(yparser(), "type '%s' has no base", ast_Parser_id(type, id));
            goto error;
        }
    } else {
        if (cx_instanceof(cx_type(cx_interface_o), type)) {
            o = cx_interface_resolveMember(cx_interface(type), member);
        }
        if (!o) {
            /* If no members are found for name, look for methods */
            o = cx_type_resolveProcedure(type, member);
            if (!o) {
                cx_id id;
                ast_Parser_error(yparser(), "unresolved member '%s' for type '%s'", member, ast_Parser_id(type, id));
                goto error;
            }
            cx_setref(&ast_Expression(this)->type, cx_function(o)->returnType);
        } else {
            cx_setref(&ast_Expression(this)->type, cx_member(o)->type);
        }
        cx_setref(&this->member, o);
    }

    return 0;
error:
    return -1;
}

/* $end */

/* ::corto::ast::Member::construct() */
cx_int16 _ast_Member_construct(ast_Member this) {
/* $begin(::corto::ast::Member::construct) */

    ast_Storage(this)->kind = Ast_MemberStorage;
    
    if (!(this->lvalue && this->rvalue)) {
        goto error;
    }

    /* If member-this can be determined at compile-time, resolve it */
    if (this->lvalue->type) { /* Type must be a known this at compile-time */
        if (ast_Node(this->rvalue)->kind == Ast_LiteralExpr) { /* Member-expression must be a literal */
            switch(ast_Literal(this->rvalue)->kind) {
            case Ast_Int: /* Resolve the nth member of a type */
                ast_Parser_error(yparser(), "resolving members by index not yet supported");
                goto error;
                break;
            case Ast_Text: /* Resolve member by name */
                /* Validate that string does not exceed 512 characters */
                if (strlen(ast_String(this->rvalue)->value) >= 512) {
                    ast_Parser_error(yparser(), "identifiers longer than 511 characters are not supported");
                    goto error;
                }

                if (ast_Member_resolveMember(this, this->lvalue->type, ast_String(this->rvalue)->value)) {
                    goto error;
                }
                break;
            default:
                ast_Parser_error(yparser(), "invalid member expression");
                goto error;
                break;
            }
        }
    }

    ast_Expression(this)->isReference = ast_Expression(this)->type->reference;

    return ast_Storage_construct(ast_Storage(this));
error:
    return -1;
/* $end */
}

/* ::corto::ast::Member::hasSideEffects() */
cx_bool _ast_Member_hasSideEffects_v(ast_Member this) {
/* $begin(::corto::ast::Member::hasSideEffects) */
    return ast_Expression_hasSideEffects(this->lvalue);
/* $end */
}

/* ::corto::ast::Member::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _ast_Member_toIc_v(ast_Member this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::ast::Member::toIc) */
    ic_member result = NULL;
    cx_member member;
    ic_node lvalue;
    CX_UNUSED(stored);
    CX_UNUSED(storage);

    /* Get lvalue & rvalue */
    lvalue = ast_Node_toIc(ast_Node(this->lvalue), program, NULL, FALSE);

    if (ast_Node(this->rvalue)->kind == Ast_LiteralExpr) {
        if (ast_Literal(this->rvalue)->kind == Ast_Text) {
            cx_type t = ast_Expression_getType(this->lvalue);
            if (cx_instanceof(cx_type(cx_interface_o), t)) {
                cx_interface baseType = cx_interface(t);
                member = cx_interface_resolveMember(baseType, ast_String(this->rvalue)->value);
            } else {
                cx_id id;
                ast_Parser_error(yparser(), "cannot resolve members on non-interface type '%s'", ast_Parser_id(t, id));
                goto error;
            }
        } else {
            ast_Parser_error(yparser(), "dynamic resolving of members not yet supported.");
            goto error;
        }
    } else {
        ast_Parser_error(yparser(), "dynamic resolving of members not yet supported.");
        goto error;
    }

    if (member) {
        result = ic_program_getMember(program, ic_storage(lvalue), member);
    }

    return (ic_node)result;
error:
    return NULL;
/* $end */
}
