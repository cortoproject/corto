/* Fast_Literal.c
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
/* $end */

/* ::cortex::Fast::Literal::getValue() */
db_word Fast_Literal_getValue_v(Fast_Literal _this) {
/* $begin(::cortex::Fast::Literal::getValue) */
	db_word result = 0;

    switch(_this->kind) {
    case FAST_Boolean: result = (db_word)&Fast_Boolean(_this)->value; break;
    case FAST_Character: result = (db_word)&Fast_Character(_this)->value; break;
    case FAST_Integer: result = (db_word)&Fast_Integer(_this)->value; break;
    case FAST_SignedInteger: result = (db_word)&Fast_SignedInteger(_this)->value; break;
    case FAST_FloatingPoint: result = (db_word)&Fast_FloatingPoint(_this)->value; break;
    default: break; /* Enumerated, Reference & Null have no value. String handles it's own value. */
    }

    return result;
/* $end */
}

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::Fast::Literal::init(Literal object) */
db_int16 Fast_Literal_init(Fast_Literal object) {
/* $begin(::cortex::Fast::Literal::init) */
    if (!Fast_Expression(object)->type) {
        switch(object->kind) {
        case FAST_Boolean:
            Fast_Expression(object)->type = (Fast_Variable)Fast_Object__create(db_bool_o);
            break;
        case FAST_Character:
            Fast_Expression(object)->type = (Fast_Variable)Fast_Object__create(db_char_o);
            break;
        case FAST_Integer:
            Fast_Expression(object)->type = (Fast_Variable)Fast_Object__create(db_uint64_o);
            break;
        case FAST_SignedInteger:
            Fast_Expression(object)->type = (Fast_Variable)Fast_Object__create(db_int64_o);
            break;
        case FAST_FloatingPoint:
            Fast_Expression(object)->type = (Fast_Variable)Fast_Object__create(db_float64_o);
            break;
        case FAST_String:
            Fast_Expression(object)->type = (Fast_Variable)Fast_Object__create(db_string_o);
            break;
        case FAST_Enumerated:
            Fast_Expression(object)->type = (Fast_Variable)Fast_Object__create(db_uint32_o);
            break;
        case FAST_Reference:
            Fast_Expression(object)->type = (Fast_Variable)Fast_Object__create(db_object_o);
            break;
        case FAST_Null:
            /* No type. */
            break;
        }
    }

    Fast_Node(object)->kind = FAST_Literal;

    return Fast_Expression_init(Fast_Expression(object));
/* $end */
}
