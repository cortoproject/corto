/* Fast_Member.c
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

cx_int16 Fast_Member_resolveMember(Fast_Member object, cx_type type, cx_string member) {
    cx_object o = NULL;

    if (cx_instanceof(cx_type(cx_interface_o), type) && !strcmp(member, "super")) {
        if (cx_interface(type)->base) {
            object->member = NULL;
            cx_set(&Fast_Expression(object)->type, cx_interface(type)->base);
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
            cx_set(&Fast_Expression(object)->type, cx_function(o)->returnType);
        } else {
            cx_set(&Fast_Expression(object)->type, cx_member(o)->type);
        }
        object->member = o; cx_keep_ext(object, o, "Keep object for member-expression");
    }

    Fast_Expression(object)->isReference = Fast_Expression_getType(Fast_Expression(object))->reference;

    return 0;
error:
    return -1;
}

/* $end */

/* ::cortex::Fast::Member::construct() */
cx_int16 Fast_Member_construct(Fast_Member _this) {
/* $begin(::cortex::Fast::Member::construct) */

    Fast_Storage(_this)->kind = Fast_ElementStorage;
    
    if (!(_this->lvalue && _this->rvalue)) {
        goto error;
    }

    /* If member-_this can be determined at compile-time, resolve it */
    if (_this->lvalue->type) { /* Type must be a known _this at compile-time */
        if (Fast_Node(_this->rvalue)->kind == Fast_LiteralExpr) { /* Member-expression must be a literal */
            switch(Fast_Literal(_this->rvalue)->kind) {
            case Fast_Int: /* Resolve the nth member of a type */
                Fast_Parser_error(yparser(), "resolving members by index not yet supported");
                goto error;
                break;
            case Fast_Text: /* Resolve member by name */
                /* Validate that string does not exceed 512 characters */
                if (strlen(Fast_String(_this->rvalue)->value) >= 512) {
                    Fast_Parser_error(yparser(), "identifiers longer than 511 characters are not supported");
                    goto error;
                }

                if (Fast_Member_resolveMember(_this, _this->lvalue->type, Fast_String(_this->rvalue)->value)) {
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

    return Fast_Storage_construct(Fast_Storage(_this));
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::Member::hasSideEffects() */
cx_bool Fast_Member_hasSideEffects_v(Fast_Member _this) {
/* $begin(::cortex::Fast::Member::hasSideEffects) */
    return Fast_Expression_hasSideEffects(_this->lvalue);
/* $end */
}

/* ::cortex::Fast::Member::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Member_toIc_v(Fast_Member _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::Member::toIc) */
    cx_icMember result = NULL;
    cx_member member;
    cx_ic lvalue;
    CX_UNUSED(stored);
    CX_UNUSED(storage);

    /* Get lvalue & rvalue */
    lvalue = Fast_Node_toIc(Fast_Node(_this->lvalue), program, NULL, FALSE);

    if (Fast_Node(_this->rvalue)->kind == Fast_LiteralExpr) {
        if (Fast_Literal(_this->rvalue)->kind == Fast_Text) {
            cx_type t = Fast_Expression_getType(_this->lvalue);
            if (cx_instanceof(cx_type(cx_interface_o), t)) {
                cx_interface baseType = cx_interface(t);
                member = cx_interface_resolveMember(baseType, Fast_String(_this->rvalue)->value);
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
        result = cx_icMember__create(program, Fast_Node(_this)->line, (cx_icStorage)lvalue, member);
    }

    return (cx_ic)result;
error:
    return NULL;
/* $end */
}
