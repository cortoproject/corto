/* Fast_Object.c
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
#include "Fast.h"
#include "Fast_Parser.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
/* $end */

/* callback ::cortex::lang::class::construct(object object) -> ::cortex::Fast::Object::construct(Object object) */
cx_int16 Fast_Object_construct(cx_object object) {
/* $begin(::cortex::Fast::Object::construct) */
    cx_type t = cx_typeof(Fast_ObjectBase(object)->value)->real;

    if(t == cx_type(cx_constant_o)) {
        t = cx_parentof(Fast_ObjectBase(object)->value);
    }

    Fast_Expression(object)->type = Fast_Variable(Fast_ObjectBase__create(t));
    Fast_Expression(object)->isReference = TRUE;

    return Fast_ObjectBase_construct(Fast_ObjectBase(object));
/* $end */
}

/* ::cortex::Fast::Object::getValue() */
cx_word Fast_Object_getValue(Fast_Object _this) {
/* $begin(::cortex::Fast::Object::getValue) */
    cx_word result = 0;

    /* Value of objects can only be used at compiletime when object is of
     * type constant. */
    if (cx_instanceof(cx_typedef(cx_constant_o), Fast_ObjectBase(_this)->value)) {
        result = (cx_word)Fast_ObjectBase(_this)->value;
    }

    return result;
/* $end */
}

/* ::cortex::Fast::Object::serialize(type dstType,word dst) */
cx_int16 Fast_Object_serialize(Fast_Object _this, cx_type dstType, cx_word dst) {
/* $begin(::cortex::Fast::Object::serialize) */
    Fast_valueKind kind;

    if (!dstType->reference) {
        if (cx_instanceof((cx_typedef)dstType, Fast_ObjectBase(_this)->value)) {
            /* If object is not of a reference type and object is of dstType, copy value */
            memcpy((void*)dst, Fast_ObjectBase(_this)->value, cx_type_sizeof(dstType));
        } else {
            cx_id id, id2;
            Fast_Parser_error(yparser(), "type '%s' of object does not match destinationtype '%s'",
                    cx_fullname(cx_typeof(Fast_ObjectBase(_this)->value), id),
                    cx_fullname(dstType, id2));
        }
    } else {
        if (Fast_Expression(_this)->isReference) {
            kind = FAST_Reference;
        } else {
            kind = Fast_valueKindFromType(dstType);
        }

        switch(kind) {
        case FAST_Boolean:
            *(cx_bool*)dst = Fast_ObjectBase(_this)->value ? TRUE : FALSE;
            break;
        case FAST_String: {
            cx_id id;
            if (*(cx_string*)dst) {
                cx_dealloc(*(cx_string*)dst);
            }
            *(cx_string*)dst = cx_strdup(cx_fullname(Fast_ObjectBase(_this)->value, id));
            break;
        }
        case FAST_Reference:
            if (*(cx_object*)dst) {
                cx_free(*(cx_object*)dst);
            }
            *(cx_object*)dst = Fast_ObjectBase(_this)->value;
            cx_keep_ext(NULL, *(cx_object*)dst, "Serialize object value");
            break;
        default: {
            cx_id id;
            Fast_Parser_error(yparser(), "cannot serialize object value to storage of type '%s'", cx_fullname(dstType, id));
            goto error;
            break;
        }
        }
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::Object::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Object_toIc_v(Fast_Object _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::Object::toIc) */
    cx_ic result;
    CX_UNUSED(storage);
    CX_UNUSED(stored);

    result = (cx_ic)cx_icObject__create(program, Fast_Node(_this)->line, _this->_parent.value);

    return result;
/* $end */
}
