/* Fast_Member.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_Fast_LIB
#include "Fast.h"

/* $header() */
#include "Fast__private.h"

cx_int16 Fast_Member_resolveMember(Fast_Member this, cx_type type, cx_string member) {
    cx_object o = NULL;

    if (cx_instanceof(cx_type(cx_interface_o), type) && !strcmp(member, "super")) {
        if (cx_interface(type)->base) {
            this->member = NULL;
            cx_setref(&Fast_Expression(this)->type, cx_interface(type)->base);
        } else {
            cx_id id;
            Fast_Parser_error(yparser(), "type '%s' has no base", Fast_Parser_id(type, id));
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
                Fast_Parser_error(yparser(), "unresolved member '%s' for type '%s'", member, Fast_Parser_id(type, id));
                goto error;
            }
            cx_setref(&Fast_Expression(this)->type, cx_function(o)->returnType);
        } else {
            cx_setref(&Fast_Expression(this)->type, cx_member(o)->type);
        }
        cx_setref(&this->member, o);
    }

    return 0;
error:
    return -1;
}

/* $end */

/* ::corto::Fast::Member::construct() */
cx_int16 _Fast_Member_construct(Fast_Member this) {
/* $begin(::corto::Fast::Member::construct) */

    Fast_Storage(this)->kind = Fast_MemberStorage;
    
    if (!(this->lvalue && this->rvalue)) {
        goto error;
    }

    /* If member-this can be determined at compile-time, resolve it */
    if (this->lvalue->type) { /* Type must be a known this at compile-time */
        if (Fast_Node(this->rvalue)->kind == Fast_LiteralExpr) { /* Member-expression must be a literal */
            switch(Fast_Literal(this->rvalue)->kind) {
            case Fast_Int: /* Resolve the nth member of a type */
                Fast_Parser_error(yparser(), "resolving members by index not yet supported");
                goto error;
                break;
            case Fast_Text: /* Resolve member by name */
                /* Validate that string does not exceed 512 characters */
                if (strlen(Fast_String(this->rvalue)->value) >= 512) {
                    Fast_Parser_error(yparser(), "identifiers longer than 511 characters are not supported");
                    goto error;
                }

                if (Fast_Member_resolveMember(this, this->lvalue->type, Fast_String(this->rvalue)->value)) {
                    goto error;
                }
                break;
            default:
                Fast_Parser_error(yparser(), "invalid member expression");
                goto error;
                break;
            }
        }
    }

    Fast_Expression(this)->isReference = Fast_Expression(this)->type->reference;

    return Fast_Storage_construct(Fast_Storage(this));
error:
    return -1;
/* $end */
}

/* ::corto::Fast::Member::hasSideEffects() */
cx_bool _Fast_Member_hasSideEffects_v(Fast_Member this) {
/* $begin(::corto::Fast::Member::hasSideEffects) */
    return Fast_Expression_hasSideEffects(this->lvalue);
/* $end */
}

/* ::corto::Fast::Member::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Member_toIc_v(Fast_Member this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::corto::Fast::Member::toIc) */
    ic_member result = NULL;
    cx_member member;
    ic_node lvalue;
    CX_UNUSED(stored);
    CX_UNUSED(storage);

    /* Get lvalue & rvalue */
    lvalue = Fast_Node_toIc(Fast_Node(this->lvalue), program, NULL, FALSE);

    if (Fast_Node(this->rvalue)->kind == Fast_LiteralExpr) {
        if (Fast_Literal(this->rvalue)->kind == Fast_Text) {
            cx_type t = Fast_Expression_getType(this->lvalue);
            if (cx_instanceof(cx_type(cx_interface_o), t)) {
                cx_interface baseType = cx_interface(t);
                member = cx_interface_resolveMember(baseType, Fast_String(this->rvalue)->value);
            } else {
                cx_id id;
                Fast_Parser_error(yparser(), "cannot resolve members on non-interface type '%s'", Fast_Parser_id(t, id));
                goto error;
            }
        } else {
            Fast_Parser_error(yparser(), "dynamic resolving of members not yet supported.");
            goto error;
        }
    } else {
        Fast_Parser_error(yparser(), "dynamic resolving of members not yet supported.");
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
