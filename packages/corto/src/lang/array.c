/* $CORTO_GENERATED
 *
 * array.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "corto/lang/lang.h"

corto_int16 _corto_array_construct(corto_array this) {
/* $begin(corto/lang/array/construct) */
    corto_uint32 elementTypeSize;
    corto_type elementType;

    /* Copy array::elementType to collection::elementType, transfer ownership of reference. */
    if (this->elementType) {
        if (!corto_collection(this)->elementType) {
            corto_claim(this->elementType);
            corto_collection(this)->elementType = this->elementType;
        }
    } else if (corto_collection(this)->elementType) {
        if (!this->elementType) {
            corto_claim(corto_collection(this)->elementType);
            this->elementType = corto_collection(this)->elementType;
        }
    } else {
        corto_seterr("no elementType provided for array");
        goto error;
    }

    /* Arrays can only be defined when their elementType is also defined. */
   if (!corto_checkState((corto_collection(this)->elementType), CORTO_DEFINED)) {
       if (!(corto_instanceof(corto_type(corto_type_o), corto_collection(this)->elementType) && corto_type(corto_collection(this)->elementType)->reference)) {
            corto_seterr(
                "elementType '%s' is not defined.",
                corto_fullpath(NULL, corto_collection(this)->elementType));
            goto error;
       }
   }

   elementType = corto_collection(this)->elementType;

   /* Calculate the size of the array */
    elementTypeSize = corto_type_sizeof(elementType);
    if (elementTypeSize) {
        if (corto_collection(this)->max) {
            corto_type(this)->size = elementTypeSize * corto_collection(this)->max;
            corto_type(this)->alignment = corto_type_alignmentof(elementType);
        } else {
            corto_seterr("invalid array '%s' with size '0'.",
                corto_fullpath(NULL, this));
            goto error;
        }
    } else {
        corto_seterr("elementType '%s' of arraytype '%s' has size 0",
            corto_fullpath(NULL, elementType), corto_fullpath(NULL, this));
        goto error;
    }

    return corto_type_construct(corto_type(this));
error:
    return -1;
/* $end */
}

corto_void _corto_array_destruct(corto_array this) {
/* $begin(corto/lang/array/destruct) */
    corto_release(this->elementType);
    this->elementType = NULL;
    corto_release(corto_collection(this)->elementType);
    corto_collection(this)->elementType = NULL;
    corto_type_destruct(corto_type(this));
/* $end */
}

corto_int16 _corto_array_init(corto_array this) {
/* $begin(corto/lang/array/init) */
    corto_collection(this)->kind = CORTO_ARRAY;
    return corto_collection_init(corto_collection(this));
/* $end */
}
