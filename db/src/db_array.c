/* db_array.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::lang::array::construct(lang::array object) */
db_int16 db_array_construct(db_array object) {
/* $begin(::cortex::lang::array::construct) */
	db_uint32 elementTypeSize;
	db_type elementType;
  
	/* Copy array::elementType to collection::elementType, transfer ownership of reference. */
	if (object->elementType) {
        if (!db_collection(object)->elementType) {
            db_keep_ext(object, object->elementType, "Keep elementType for array");
    		db_collection(object)->elementType = object->elementType;
        }
	} else if (db_collection(object)->elementType) {
        if (!object->elementType) {
            db_keep_ext(object, db_collection(object)->elementType, "Keep elementType for array");
    		object->elementType = db_collection(object)->elementType;
        }
	} else {
		db_error("array::construct: no elementType provided for array");
		goto error;
	}

	/* Arrays can only be defined when their elementType is also defined. */
   if (!db_checkState((db_collection(object)->elementType), DB_DEFINED)) {
       if (!(db_instanceof(db_typedef(db_type_o), db_collection(object)->elementType) && db_type(db_collection(object)->elementType)->reference)) {
            db_id id;
            db_error("array::construct: elementType '%s' is not defined.", db_fullname(db_collection(object)->elementType, id));
            goto error;
       }
   }

   elementType = db_collection(object)->elementType->real;

   /* Calculate the size of the array */
	elementTypeSize = db_type_sizeof(elementType);
	if (elementTypeSize) {
	    if (db_collection(object)->max) {
            db_type(object)->size = elementTypeSize * db_collection(object)->max;
            db_type(object)->alignment = db_type_alignmentof(elementType);
	    } else {
	        db_id id;
	        db_error("array::construct: invalid array '%s' with size '0'.", db_fullname(object, id));
	        goto error;
	    }
	} else {
		db_id id1, id2;
		db_error("array::construct: elementType '%s' of arraytype '%s' has size 0", db_fullname(elementType, id1), db_fullname(object, id2));
		goto error;
	}

	return db_type_construct(db_type(object));
error:
	return -1;
/* $end */
}

/* callback ::cortex::lang::class::destruct(lang::object object) -> ::cortex::lang::array::destruct(lang::array object) */
db_void db_array_destruct(db_array object) {
/* $begin(::cortex::lang::array::destruct) */
    db_free_ext(object, object->elementType, "elementType");
    object->elementType = NULL;
    db_free_ext(object, db_collection(object)->elementType, "super.elementType");
    db_collection(object)->elementType = NULL;
    db_type__destruct(db_type(object));
/* $end */
}

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::array::init(lang::array object) */
db_int16 db_array_init(db_array object) {
/* $begin(::cortex::lang::array::init) */
    db_collection(object)->kind = DB_ARRAY;
    return db_collection_init(db_collection(object));
/* $end */
}
