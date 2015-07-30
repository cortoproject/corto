/* cx_array.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* ::cortex::lang::array::construct() */
cx_int16 cx_array_construct(cx_array _this) {
/* $begin(::cortex::lang::array::construct) */
    cx_uint32 elementTypeSize;
    cx_type elementType;
  
    /* Copy array::elementType to collection::elementType, transfer ownership of reference. */
    if (_this->elementType) {
        if (!cx_collection(_this)->elementType) {
            cx_claim(_this->elementType);
            cx_collection(_this)->elementType = _this->elementType;
        }
    } else if (cx_collection(_this)->elementType) {
        if (!_this->elementType) {
            cx_claim(cx_collection(_this)->elementType);
            _this->elementType = cx_collection(_this)->elementType;
        }
    } else {
        cx_error("array::construct: no elementType provided for array");
        goto error;
    }

    /* Arrays can only be defined when their elementType is also defined. */
   if (!cx_checkState((cx_collection(_this)->elementType), CX_DEFINED)) {
       if (!(cx_instanceof(cx_type(cx_type_o), cx_collection(_this)->elementType) && cx_type(cx_collection(_this)->elementType)->reference)) {
            cx_id id;
            cx_error("array::construct: elementType '%s' is not defined.", cx_fullname(cx_collection(_this)->elementType, id));
            goto error;
       }
   }

   elementType = cx_collection(_this)->elementType;

   /* Calculate the size of the array */
    elementTypeSize = cx_type_sizeof(elementType);
    if (elementTypeSize) {
        if (cx_collection(_this)->max) {
            cx_type(_this)->size = elementTypeSize * cx_collection(_this)->max;
            cx_type(_this)->alignment = cx_type_alignmentof(elementType);
        } else {
            cx_id id;
            cx_error("array::construct: invalid array '%s' with size '0'.", cx_fullname(_this, id));
            goto error;
        }
    } else {
        cx_id id1, id2;
        cx_error("array::construct: elementType '%s' of arraytype '%s' has size 0", cx_fullname(elementType, id1), cx_fullname(_this, id2));
        goto error;
    }

    return cx_type_construct(cx_type(_this));
error:
    return -1;
/* $end */
}

/* ::cortex::lang::array::destruct() */
cx_void cx_array_destruct(cx_array _this) {
/* $begin(::cortex::lang::array::destruct) */
    cx_release(_this->elementType);
    _this->elementType = NULL;
    cx_release(cx_collection(_this)->elementType);
    cx_collection(_this)->elementType = NULL;
    cx_type_destruct(cx_type(_this));
/* $end */
}

/* ::cortex::lang::array::init() */
cx_int16 cx_array_init(cx_array _this) {
/* $begin(::cortex::lang::array::init) */
    cx_collection(_this)->kind = CX_ARRAY;
    return cx_collection_init(cx_collection(_this));
/* $end */
}
