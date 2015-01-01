/* cx_array.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::lang::array::construct(lang::array object) */
cx_int16 cx_array_construct(cx_array object) {
/* $begin(::cortex::lang::array::construct) */
	cx_uint32 elementTypeSize;
	cx_type elementType;
  
	/* Copy array::elementType to collection::elementType, transfer ownership of reference. */
	if (object->elementType) {
        if (!cx_collection(object)->elementType) {
            cx_keep_ext(object, object->elementType, "Keep elementType for array");
    		cx_collection(object)->elementType = object->elementType;
        }
	} else if (cx_collection(object)->elementType) {
        if (!object->elementType) {
            cx_keep_ext(object, cx_collection(object)->elementType, "Keep elementType for array");
    		object->elementType = cx_collection(object)->elementType;
        }
	} else {
		cx_error("array::construct: no elementType provided for array");
		goto error;
	}

	/* Arrays can only be defined when their elementType is also defined. */
   if (!cx_checkState((cx_collection(object)->elementType), DB_DEFINED)) {
       if (!(cx_instanceof(cx_typedef(cx_type_o), cx_collection(object)->elementType) && cx_type(cx_collection(object)->elementType)->reference)) {
            cx_id id;
            cx_error("array::construct: elementType '%s' is not defined.", cx_fullname(cx_collection(object)->elementType, id));
            goto error;
       }
   }

   elementType = cx_collection(object)->elementType->real;

   /* Calculate the size of the array */
	elementTypeSize = cx_type_sizeof(elementType);
	if (elementTypeSize) {
	    if (cx_collection(object)->max) {
            cx_type(object)->size = elementTypeSize * cx_collection(object)->max;
            cx_type(object)->alignment = cx_type_alignmentof(elementType);
	    } else {
	        cx_id id;
	        cx_error("array::construct: invalid array '%s' with size '0'.", cx_fullname(object, id));
	        goto error;
	    }
	} else {
		cx_id id1, id2;
		cx_error("array::construct: elementType '%s' of arraytype '%s' has size 0", cx_fullname(elementType, id1), cx_fullname(object, id2));
		goto error;
	}

	return cx_type_construct(cx_type(object));
error:
	return -1;
/* $end */
}

/* callback ::cortex::lang::class::destruct(lang::object object) -> ::cortex::lang::array::destruct(lang::array object) */
cx_void cx_array_destruct(cx_array object) {
/* $begin(::cortex::lang::array::destruct) */
    cx_free_ext(object, object->elementType, "elementType");
    object->elementType = NULL;
    cx_free_ext(object, cx_collection(object)->elementType, "super.elementType");
    cx_collection(object)->elementType = NULL;
    cx_type__destruct(cx_type(object));
/* $end */
}

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::array::init(lang::array object) */
cx_int16 cx_array_init(cx_array object) {
/* $begin(::cortex::lang::array::init) */
    cx_collection(object)->kind = DB_ARRAY;
    return cx_collection_init(cx_collection(object));
/* $end */
}
