/* Fast_MemberExpr.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"
#include "Fast__meta.h"

/* $header() */
#include "Fast__api.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);

cx_int16 Fast_MemberExpr_resolveMember(Fast_MemberExpr object, cx_type type, cx_string member) {
    cx_object o = NULL;

    if (cx_instanceof(cx_typedef(cx_interface_o), type) && !strcmp(member, "super")) {
        if (cx_interface(type)->base) {
            object->member = NULL;
            Fast_Expression(object)->type = Fast_Variable(Fast_Object__create(cx_interface(type)->base));
        } else {
            cx_id id;
            Fast_Parser_error(yparser(), "type '%s' has no base", cx_fullname(type, id));
            goto error;
        }
    } else {
        if (cx_instanceof(cx_typedef(cx_interface_o), type)) {
            o = cx_interface_resolveMember(cx_interface(type), member);
        }
        if (!o) {
            /* If no members are found for name, look for methods */
            o = cx_type_resolveProcedure(type, member);
            if (!o) {
                cx_id id;
                Fast_Parser_error(yparser(), "unresolved member '%s' for type '%s'", member, cx_fullname(type, id));
                goto error;
            }
            Fast_Expression(object)->type = Fast_Variable(Fast_Object__create(cx_function(o)->returnType->real));
        } else {
            Fast_Expression(object)->type = Fast_Variable(Fast_Object__create(cx_member(o)->type->real));
        }
        object->member = o; cx_keep_ext(object, o, "Keep object for member-expression");
    }

    Fast_Expression(object)->isReference = Fast_Expression_getType(Fast_Expression(object))->reference;

    return 0;
error:
    return -1;
}

/* $end */

/* ::cortex::Fast::MemberExpr::construct() */
cx_int16 Fast_MemberExpr_construct(Fast_MemberExpr _this) {
/* $begin(::cortex::Fast::MemberExpr::construct) */
    cx_type lvalueType;
    cx_type exprType;

    Fast_Node(_this)->kind = FAST_Member;
    
    if (!(_this->lvalue && _this->rvalue)) {
        goto error;
    }

    /* If member-_this can be determined at compile-time, resolve it */
    lvalueType = Fast_Expression_getType(_this->lvalue);
    if (lvalueType) { /* Type must be a known _this at compile-time */
        if (Fast_Node(_this->rvalue)->kind == FAST_Literal) { /* Member-expression must be a literal */
            switch(Fast_Literal(_this->rvalue)->kind) {
            case FAST_Integer: /* Resolve the nth member of a type */
                Fast_Parser_error(yparser(), "resolving members by index not yet supported");
                goto error;
                break;
            case FAST_String: /* Resolve member by name */
                if (Fast_MemberExpr_resolveMember(_this, lvalueType, Fast_String(_this->rvalue)->value)) {
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

    if ((exprType = Fast_Expression_getType(Fast_Expression(_this))) && exprType->reference) {
        Fast_Expression(_this)->forceReference = TRUE;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::MemberExpr::hasSideEffects() */
cx_bool Fast_MemberExpr_hasSideEffects_v(Fast_MemberExpr _this) {
/* $begin(::cortex::Fast::MemberExpr::hasSideEffects) */
    return Fast_Expression_hasSideEffects(_this->lvalue);
/* $end */
}

/* ::cortex::Fast::MemberExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_MemberExpr_toIc_v(Fast_MemberExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::MemberExpr::toIc) */
    cx_icMember result;
    cx_member member;
    cx_ic lvalue;
    CX_UNUSED(stored);
    CX_UNUSED(storage);

    /* Get lvalue & rvalue */
    lvalue = Fast_Node_toIc(Fast_Node(_this->lvalue), program, NULL, FALSE);

    if (Fast_Node(_this->rvalue)->kind == FAST_Literal) {
        if (Fast_Literal(_this->rvalue)->kind == FAST_String) {
            cx_type t = Fast_Expression_getType(_this->lvalue);
            if (cx_instanceof(cx_typedef(cx_interface_o), t)) {
                cx_interface baseType = cx_interface(t);
                member = cx_interface_resolveMember(baseType, Fast_String(_this->rvalue)->value);
            } else {
                cx_id id;
                Fast_Parser_error(yparser(), "cannot resolve members on non-interface type '%s'", cx_fullname(t, id));
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
        result = cx_icMember__create(program, Fast_Node(_this)->line, (cx_icStorage)lvalue, member);
    }

    return (cx_ic)result;
error:
    return NULL;
/* $end */
}
