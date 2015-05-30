/* Fast_Object.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"

/* $header() */
#include "Fast__private.h"
/* $end */

/* ::cortex::Fast::Object::construct() */
cx_int16 Fast_Object_construct(Fast_Object _this) {
/* $begin(::cortex::Fast::Object::construct) */
    cx_type t = cx_typeof(Fast_Object(_this)->value);

    /* TODO: this is not nice */
    if(t == cx_type(cx_constant_o)) {
        t = cx_parentof(Fast_Object(_this)->value);
    }

    Fast_Storage(_this)->kind = Fast_ObjectStorage;
    cx_set(&Fast_Expression(_this)->type, t);
    Fast_Expression(_this)->isReference = TRUE;

    return Fast_Storage_construct(Fast_Storage(_this));
/* $end */
}

/* ::cortex::Fast::Object::getValue() */
cx_word Fast_Object_getValue(Fast_Object _this) {
/* $begin(::cortex::Fast::Object::getValue) */
    cx_word result = 0;

    /* Value of objects can only be used at compiletime when object is of
     * type constant. */
    if (cx_instanceof(cx_type(cx_constant_o), Fast_Object(_this)->value)) {
        result = (cx_word)Fast_Object(_this)->value;
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
        cx_object obj = Fast_Object(_this)->value;
        cx_type srcType = cx_typeof(obj);

        /* Handle delegates */
        if ((srcType->kind == CX_COMPOSITE) && (cx_interface(srcType)->kind == CX_DELEGATE)) {
            srcIsDelegate = TRUE;
        }
        if ((dstType->kind == CX_COMPOSITE) && (cx_interface(dstType)->kind == CX_DELEGATE)) {
            dstIsDelegate = TRUE;
        }

        /* Handle iterators */
        if ((dstType->kind == CX_ITERATOR) && (srcType->kind == CX_COLLECTION)) {
            cx_iterator_set((void*)dst, obj, cx_collection(srcType));
        } else if (dstIsDelegate) {
            if (srcIsDelegate) {
                cx_value vDst, vSrc;
                cx_valueValueInit(&vDst, NULL, cx_type(dstType), (void *)dst);
                cx_valueValueInit(&vSrc, NULL, cx_type(srcType), Fast_Object(_this)->value);
                cx_valueCopy(&vDst, &vSrc);
            } else if ((srcType->kind == CX_COMPOSITE) && (cx_interface(srcType)->kind == CX_PROCEDURE)) {
                cx_set(&((cx_delegatedata *)dst)->procedure, Fast_Object(_this)->value);
                cx_set(&((cx_delegatedata *)dst)->instance, NULL);
            }

        } else if (cx_instanceof((cx_type)dstType, Fast_Object(_this)->value)) {
            /* If object is not of a reference type and object is of dstType, copy value */
            cx_value vDst, vSrc;
            cx_valueValueInit(&vDst, NULL, cx_type(dstType), (void *)dst);
            cx_valueValueInit(&vSrc, NULL, cx_type(srcType), obj);
            cx_valueCopy(&vDst, &vSrc);

        } else {
            cx_id id, id2;
            Fast_Parser_error(yparser(), "type '%s' of object does not match destinationtype '%s'",
                    Fast_Parser_id(cx_typeof(Fast_Object(_this)->value), id),
                    Fast_Parser_id(dstType, id2));
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
            *(cx_bool*)dst = Fast_Object(_this)->value ? TRUE : FALSE;
            break;
        case Fast_Text: {
            cx_id id;
            if (*(cx_string*)dst) {
                cx_dealloc(*(cx_string*)dst);
            }
            *(cx_string*)dst = cx_strdup(Fast_Parser_id(Fast_Object(_this)->value, id));
            break;
        }
        case Fast_Ref:
            if (*(cx_object*)dst) {
                cx_free(*(cx_object*)dst);
            }
            *(cx_object*)dst = Fast_Object(_this)->value;
            cx_keep_ext(NULL, *(cx_object*)dst, "Serialize object value");
            break;
        default: {
            cx_id id;
            Fast_Parser_error(yparser(), "cannot serialize object value to storage of type '%s'", Fast_Parser_id(dstType, id));
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

/* ::cortex::Fast::Object::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Object_toIc_v(Fast_Object _this, ic_program program, ic_storage storage, cx_bool stored) {
/* $begin(::cortex::Fast::Object::toIc) */
    CX_UNUSED(program);
    CX_UNUSED(storage);
    CX_UNUSED(stored);

    return ic_node(ic_program_getObject(program, _this->value));;
/* $end */
}
