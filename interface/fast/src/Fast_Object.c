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

/* ::cortex::Fast::Object::construct() */
cx_int16 Fast_Object_construct(Fast_Object _this) {
/* $begin(::cortex::Fast::Object::construct) */
    cx_type t = cx_typeof(Fast_ObjectBase(_this)->value);

    if(t == cx_type(cx_constant_o)) {
        t = cx_parentof(Fast_ObjectBase(_this)->value);
    }

    Fast_Expression(_this)->type = Fast_Variable(Fast_ObjectBase__create(t));
    Fast_Expression(_this)->isReference = TRUE;

    return Fast_ObjectBase_construct(Fast_ObjectBase(_this));
/* $end */
}

/* ::cortex::Fast::Object::getValue() */
cx_word Fast_Object_getValue(Fast_Object _this) {
/* $begin(::cortex::Fast::Object::getValue) */
    cx_word result = 0;

    /* Value of objects can only be used at compiletime when object is of
     * type constant. */
    if (cx_instanceof(cx_type(cx_constant_o), Fast_ObjectBase(_this)->value)) {
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
        cx_bool srcIsDelegate = FALSE, dstIsDelegate = FALSE;
        cx_object obj = Fast_ObjectBase(_this)->value;
        cx_type srcType = cx_typeof(obj);

        /* Handle delegates */
        if ((srcType->kind == CX_COMPOSITE) && (cx_interface(srcType)->kind == CX_DELEGATE)) {
            srcIsDelegate = TRUE;
        }
        if ((dstType->kind == CX_COMPOSITE) && (cx_interface(dstType)->kind == CX_DELEGATE)) {
            dstIsDelegate = TRUE;
        }

        if (dstIsDelegate) {
            if (srcIsDelegate) {
                cx_value vDst, vSrc;
                cx_valueValueInit(&vDst, NULL, cx_type(dstType), (void *)dst);
                cx_valueValueInit(&vSrc, NULL, cx_type(srcType), Fast_ObjectBase(_this)->value);
                cx_valueCopy(&vDst, &vSrc);
            } else if ((srcType->kind == CX_COMPOSITE) && (cx_interface(srcType)->kind == CX_PROCEDURE)) {
                cx_set(&((cx_delegatedata *)dst)->procedure, Fast_ObjectBase(_this)->value);
                cx_set(&((cx_delegatedata *)dst)->instance, NULL);
            }

        } else if (cx_instanceof((cx_type)dstType, Fast_ObjectBase(_this)->value)) {
            /* If object is not of a reference type and object is of dstType, copy value */
            cx_value vDst, vSrc;
            cx_valueValueInit(&vDst, NULL, cx_type(dstType), (void *)dst);
            cx_valueValueInit(&vSrc, NULL, cx_type(srcType), obj);
            cx_valueCopy(&vDst, &vSrc);

        } else {
            cx_id id, id2;
            Fast_Parser_error(yparser(), "type '%s' of object does not match destinationtype '%s'",
                    cx_fullname(cx_typeof(Fast_ObjectBase(_this)->value), id),
                    cx_fullname(dstType, id2));
            goto error;
        }
    } else {
        if (Fast_Expression(_this)->isReference) {
            kind = Fast_Ref;
        } else {
            kind = Fast_valueKindFromType(dstType);
        }

        switch(kind) {
        case Fast_Bool:
            *(cx_bool*)dst = Fast_ObjectBase(_this)->value ? TRUE : FALSE;
            break;
        case Fast_Text: {
            cx_id id;
            if (*(cx_string*)dst) {
                cx_dealloc(*(cx_string*)dst);
            }
            *(cx_string*)dst = cx_strdup(cx_fullname(Fast_ObjectBase(_this)->value, id));
            break;
        }
        case Fast_Ref:
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
