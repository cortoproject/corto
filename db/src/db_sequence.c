/* db_sequence.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* $header() */
typedef struct __dummySeq {
    db_uint32 length;
    void* buffer;
}__dummySeq;

/* Allocate buffer of specific size */
int db_sequence_alloc(db_collection _this, db_void* collection, db_uint32 elements) {
    db_uint32 elementSize;

    elementSize = db_type_sizeof(_this->elementType->real);

    ((__dummySeq*)collection)->buffer = db_malloc(elementSize * elements);

    return (((__dummySeq*)collection)->buffer == NULL) * -1; /* Return -1 on failure */
}
/* $end */

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::lang::sequence::construct(lang::sequence object) */
db_int16 db_sequence_construct(db_sequence object) {
/* $begin(::cortex::lang::sequence::construct) */
	db_type(object)->hasResources = TRUE;
	db_type(object)->size = sizeof(__dummySeq);
	db_type(object)->alignment = DB_ALIGNMENT(__dummySeq);
	return db_type_construct(db_type(object));
/* $end */
}

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::sequence::init(lang::sequence object) */
db_int16 db_sequence_init(db_sequence object) {
/* $begin(::cortex::lang::sequence::init) */
    db_collection(object)->kind = DB_SEQUENCE;
    return db_collection_init(db_collection(object));
/* $end */
}

/* ::cortex::lang::sequence::size(lang::uint32 size) */
db_void db_sequence_size(db_any _this, db_uint32 size) {
/* $begin(::cortex::lang::sequence::size) */
    db_uint32 oldSize, elementSize;

    oldSize = ((db_objectSeq*)_this.value)->length;
    elementSize = db_type_sizeof(db_collection(_this.type)->elementType->real);

    ((db_objectSeq*)_this.value)->buffer = db_realloc(((db_objectSeq*)_this.value)->buffer, size * elementSize);
    memset(DB_OFFSET(((db_objectSeq*)_this.value)->buffer, oldSize * elementSize), 0, elementSize * (size - oldSize));
    ((db_objectSeq*)_this.value)->length = size;
/* $end */
}
