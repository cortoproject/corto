/*
 * db_collection.c
 *
 *  Created on: Aug 9, 2012
 *      Author: sander
 */

#include "db_object.h"
#include "db_type.h"
#include "db_collection.h"
#include "db_type.h"
#include "db_ll.h"
#include "db_rbtree.h"
#include "db_util.h"
#include "db_err.h"
#include "db_mem.h"
#include "db__meta.h"

typedef struct __dummySeq {
    db_uint32 length;
    void* buffer;
}__dummySeq;

/* type::init -> collection::init */
db_int16 db_collection_init(db_collection object) {
    db_type(object)->kind = DB_COLLECTION;
    return db_type__init(db_type(object));
}

/* type::init -> array::init */
db_int16 db_array_init(db_array object) {
    db_collection(object)->kind = DB_ARRAY;
    return db_collection_init(db_collection(object));
}

/* type::init -> sequence::init */
db_int16 db_sequence_init(db_sequence object) {
    db_collection(object)->kind = DB_SEQUENCE;
    return db_collection_init(db_collection(object));
}

/* type::init -> list::init */
db_int16 db_list_init(db_list object) {
    db_collection(object)->kind = DB_LIST;
    return db_collection_init(db_collection(object));
}

/* type::init -> map::init */
db_int16 db_map_init(db_map object) {
    db_collection(object)->kind = DB_MAP;
    return db_collection_init(db_collection(object));
}

/* class::construct -> collection::construct */
db_int16 db_collection_construct(db_collection object) {
	return db_type_construct(db_type(object));
}

/* class::construct -> array::construct */
db_int16 db_array_construct(db_array object) {
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

	return db_collection_construct(db_collection(object));
error:
	return -1;
}

/* class::construct -> array::construct */
void db_array_destruct(db_array object) {
    db_free_ext(object, object->elementType, "elementType");
    object->elementType = NULL;
    db_free_ext(object, db_collection(object)->elementType, "super.elementType");
    db_collection(object)->elementType = NULL;
    db_type__destruct(db_type(object));
}

/* class::construct -> sequence::construct */
db_int16 db_sequence_construct(db_sequence object) {
	db_type(object)->hasResources = TRUE;
	db_type(object)->size = sizeof(__dummySeq);
	db_type(object)->alignment = DB_ALIGNMENT(__dummySeq);
	return db_collection_construct(db_collection(object));
}

/* class::construct -> list::construct */
db_int16 db_list_construct(db_list object) {
	db_type(object)->hasResources = TRUE;
	db_type(object)->size = sizeof(db_ll);
	db_type(object)->alignment = DB_ALIGNMENT(db_ll);
	return db_collection_construct(db_collection(object));
}

/* class::construct -> map::construct */
db_int16 db_map_construct(db_map object) {
	db_type(object)->hasResources = TRUE;
	db_type(object)->size = sizeof(db_map);
	db_type(object)->alignment = DB_ALIGNMENT(db_map);
	db_collection(object)->elementType = object->elementType;
	db_keep_ext(object, object->elementType, "keep object for elementType");
	db_collection(object)->max = object->max;
	return db_collection_construct(db_collection(object));
}

/* Check for compatibility */
db_bool db_collection_castable(db_collection _this, db_type type) {
    db_bool result = FALSE;
    if (type->kind == DB_COLLECTION) {
        db_collection t = db_collection(type);
        
        /* Arrays are only castable when they match exactly in size */
        if (!(_this->kind == DB_ARRAY) || ((t->kind == DB_ARRAY) && (_this->max == t->max))) {
            if (_this->elementType != t->elementType) {
                if (_this->elementType->real->kind == DB_COLLECTION) {
                    result = db_collection_castable(db_collection(_this->elementType->real), t->elementType->real);
                }
            } else {
                result = TRUE;
            }
        }
    }
    
    return result;
}

/* Allocate buffer of specific size */
int db_sequenceAlloc(db_collection _this, db_void* collection, db_uint32 elements) {
    db_uint32 elementSize;

    elementSize = db_type_sizeof(_this->elementType->real);

    ((__dummySeq*)collection)->buffer = db_malloc(elementSize * elements);

    return (((__dummySeq*)collection)->buffer == NULL) * -1; /* Return -1 on failure */
}

static int db_arrayWalk(db_collection _this, db_void* array, db_uint32 length, db_walkAction action, db_void* userData) {
    void* v;
    int result;
    db_type elementType;
    db_uint32 elementSize, i;

    result = 1;

    if (array) {
		elementType = _this->elementType->real;
		elementSize = db_type_sizeof(elementType);
		v = array;

		result = 1;
		for(i=0; (i<length) && result; i++) {
            result = action(v, userData);
			v = DB_OFFSET(v, elementSize);
		}
    }

    return result;
}

/* Walk contents of collection */
int db_walk(db_collection _this, db_void* collection, db_walkAction action, db_void* userData) {
    int result;

    result = 1;

    switch(_this->kind) {
    case DB_ARRAY:
        result = db_arrayWalk(_this, collection, _this->max, action, userData);
        break;
    case DB_SEQUENCE:
        result = db_arrayWalk(_this, ((__dummySeq*)collection)->buffer, ((__dummySeq*)collection)->length, action, userData);
        break;
    case DB_LIST: {
        db_ll list = *(db_ll*)collection;
        if (list) {
            if (db_collection_elementRequiresAlloc(_this)) {
                result = db_llWalk(list, action, userData);
            } else {
                result = db_llWalkPtr(list, action, userData);
            }
        }
        break;
    }
    case DB_MAP: {
        db_rbtree tree = *(db_rbtree*)collection;
        if (tree) {
            if (db_collection_elementRequiresAlloc(_this)) {
                result = db_rbtreeWalk(tree, action, userData);
            } else {
                result = db_rbtreeWalkPtr(tree, action, userData);
            }
        }
        break;
    }
    }
    return result;
}

/* Free references in collection */
static int db_clearFreeReferences(void* o, void* udata) {
	DB_UNUSED(udata);
	db_free(*(db_object*)o);
	return 1;
}

/* Free values in collection */
static int db_clearFreeValues(void* o, void* udata) {
    DB_UNUSED(udata);
    db_dealloc(o);
    return 1;
}

/* Clear collection */
void db_clear(db_collection _this, db_void* collection) {
   db_type elementType;

   elementType = _this->elementType->real;

   /* If type is a reference type, do free's on all elements */
   if (elementType->reference) {
	   db_walk(_this, collection, db_clearFreeReferences, NULL);
   }

   switch(_this->kind) {
   case DB_SEQUENCE:
	   db_dealloc(((__dummySeq*)collection)->buffer);
	   ((__dummySeq*)collection)->buffer = NULL;
	   ((__dummySeq*)collection)->length = 0;
	   break;
   case DB_LIST: {
	   db_ll c;
	   if ((c = *(db_ll*)collection)) {
	       if (db_collection_elementRequiresAlloc(_this)) {
	           db_walk(_this, collection, db_clearFreeValues, NULL);
	       }
		   db_llFree(c);
	   }
	   break;
   }
   case DB_MAP: {
	   db_rbtree c;
	   if ((c = *(db_rbtree*)collection)) {
           if (!elementType->reference) {
               db_walk(_this, collection, db_clearFreeValues, NULL);
           }
		   db_rbtreeFree(c);
	   }
	   break;
   }
   default: {
       db_id id;
       db_error("the clear operation is only valid for sequences, lists and maps (got %s)", db_fullname(_this, id));
       break;
   }
   }
}

/* Request size of collection object */
db_uint32 db_size(db_collection _this, db_void* collection) {
	db_uint32 result;

	result = 0;

	switch(_this->kind) {
	case DB_ARRAY:
		result = _this->max;
		break;
	case DB_SEQUENCE:
		result = *(db_uint32*)collection;
		break;
	case DB_LIST:
		if (*(db_ll*)collection) {
			result = db_llSize(*(db_ll*)collection);
		}
		break;
	case DB_MAP:
		if (*(db_rbtree*)collection) {
			result = db_rbtreeSize(*(db_rbtree*)collection);
		}
		break;
	}

	return result;
}

/* metaprocedure collection::size */
db_uint32 db_collection_size(db_any object) {
    db_uint32 result = 0;

    switch(db_collection(object.type)->kind) {
    case DB_ARRAY:
        result = db_collection(object.type)->max;
        break;
    case DB_SEQUENCE:
        result = ((db_objectSeq*)object.value)->length;
        break;
    case DB_LIST:
        result = db_llSize(*(db_ll*)object.value);
        break;
    case DB_MAP:
        result = db_rbtreeSize(*(db_rbtree*)object.value);
        break;
    }

    return result;
}

typedef void (*db_list_action)(db_ll list, void *value, void *userData);
static void db_list_do(db_any object, db_any element, db_bool insert, db_list_action action, void *userData);

/* In place insertion of list to a list */
typedef struct db_list_insertWalk_t {
    db_iter iter;
    db_any *dest;
}db_list_insertWalk_t;

void db_list_insertListAction(db_ll list, void *value, void *userData) {
    db_list_insertWalk_t *data = userData;
    DB_UNUSED(list);
    db_iterInsert(&data->iter, value);
    db_iterHasNext(&data->iter);
    db_iterNext(&data->iter);
}

int db_list_insertWalk(void* o, void* userData) {
    db_list_insertWalk_t *data = userData;
    db_any src;
    src.value = o;
    src.type = db_collection(data->dest->type)->elementType->real;
    src.owner = FALSE;
    db_list_do(*data->dest, src, TRUE, db_list_insertListAction, data);
    return 1;
}

/* Append list to list */
int db_list_appendWalk(void* o, void* userData) {
    db_any *dest = userData;
    db_any src;
    src.value = o;
    src.type = db_collection(dest->type)->elementType->real;
    src.owner = FALSE;
    db_list_append(*dest, src);
    return 1;
}

/* Insert or append an element */
static void db_list_do(db_any object, db_any element, db_bool insert, db_list_action action, void *userData) {
    db_ll list = *(db_ll*)object.value;
    void* value = NULL;
    db_bool doCopy = TRUE;
    db_value src, dst;
    
    /* If appending a list of the same type, insert all elements from 'element' to object */
    if (db_type_castable(object.type, element.type)) {
        if (!insert) {
            db_llWalk(*(db_ll*)element.value, db_list_appendWalk, &object);
            doCopy = FALSE;
        } else {
            db_list_insertWalk_t walkData;
            walkData.iter = db_llIter(list);
            walkData.dest = &object;
            db_llWalk(*(db_ll*)element.value, db_list_insertWalk, &walkData);
            doCopy = FALSE;
            
        }
    } else if (db_collection_elementRequiresAlloc(db_collection(object.type))) {
        db_uint32 size = db_type_sizeof(db_collection(object.type)->elementType->real);
        value = db_calloc(size);
        db_valueValueInit(&dst, NULL, db_collection(object.type)->elementType, value);
        db_initValue(&dst);
        db_valueValueInit(&src, NULL, db_collection(object.type)->elementType, element.value);
    } else {
        value = NULL;
        db_valueValueInit(&dst, NULL, db_collection(object.type)->elementType, &value);
        db_initValue(&dst);
        db_valueValueInit(&src, NULL, db_collection(object.type)->elementType, element.value);
    }
    
    if (doCopy) {
        db_valueCopy(&dst, &src);
        if (insert) {
            action(list, value, userData);
        } else {
            action(list, value, userData);
        }
    }
}

static void db_list_insertAction(db_ll list, void *value, void *userData) {
    DB_UNUSED(userData);
    db_llInsert(list, value);
}

static void db_list_appendAction(db_ll list, void *value, void *userData) {
    DB_UNUSED(userData);
    db_llAppend(list, value);
}

void db_list_insert(db_any object, db_any element) {
    db_list_do(object, element, TRUE, db_list_insertAction, NULL);
}

void db_list_append(db_any object, db_any element) {
    db_list_do(object, element, FALSE, db_list_appendAction, NULL);
}

/* Insert or append an element with default value */
static void* db_list_do_(db_any object, db_bool insert) {
    db_ll list = *(db_ll*)object.value;
    void* value = NULL;
    db_value dst;
    
    if (db_collection_elementRequiresAlloc(db_collection(object.type))) {
        db_uint32 size = db_type_sizeof(db_collection(object.type)->elementType->real);
        value = db_calloc(size);
        db_valueValueInit(&dst, NULL, db_collection(object.type)->elementType, value);
        db_initValue(&dst);
    } else {
        value = NULL;
        db_valueValueInit(&dst, NULL, db_collection(object.type)->elementType, &value);
        db_initValue(&dst);
    }

    if (insert) {
        db_llInsert(list, value);
    } else {
        db_llAppend(list, value);
    }

    return value;
}

db_any db_list_insert_(db_any object) {
    db_any result;
    result.type = db_collection(object.type)->elementType->real;
    result.value = db_list_do_(object, TRUE);
    result.owner = FALSE;
    return result;
}

db_any db_list_append_(db_any object) {
    db_any result;
    result.type = db_collection(object.type)->elementType->real;
    result.value = db_list_do_(object, FALSE);
    result.owner = FALSE;
    return result;
}

void db_list_reverse(db_any object) {
    db_llReverse(*(db_ll*)object.value);
}

void db_list_clear(db_any object) {
    db_collection c = db_collection(object.type);
    if (db_collection_elementRequiresAlloc(c)) {
        db_llWalk(*(db_ll*)object.value, db_clearFreeValues, NULL);
    }
    db_llClear(*(db_ll*)object.value);
}

/* Metaprocedure sequence::size */
void db_sequence_size(db_any object, db_uint32 size) {
    db_uint32 oldSize, elementSize;

    oldSize = ((db_objectSeq*)object.value)->length;
    elementSize = db_type_sizeof(db_collection(object.type)->elementType->real);

    ((db_objectSeq*)object.value)->buffer = db_realloc(((db_objectSeq*)object.value)->buffer, size * elementSize);
    memset(DB_OFFSET(((db_objectSeq*)object.value)->buffer, oldSize * elementSize), 0, elementSize * (size - oldSize));
    ((db_objectSeq*)object.value)->length = size;
}

/* Does the elementtype require an allocation or can it directly be inserted in the case of a collection 
 * that has non consecutive storage. Prevent unnecessary allocs when a value fits in an address. */
db_bool db_collection_elementRequiresAlloc(db_collection type) {
    db_bool result = TRUE;
    db_type elementType = type->elementType->real;

    if (elementType->reference) {
        result = FALSE;
    } else {
        switch(elementType->kind) {
        case DB_VOID:
            db_assert(0, "non reference void type cannot be an elementtype");
            break;
        case DB_ANY:
            /* Any values don't fit in an address */
            break;
        case DB_PRIMITIVE:
            switch(db_primitive(elementType)->width) {
            case DB_WIDTH_8:
            case DB_WIDTH_16:
            case DB_WIDTH_32:
            case DB_WIDTH_WORD:
                /* At least a 32-bit architecture is required for hyve. */
                result = FALSE;
                break;
            case DB_WIDTH_64:
                /* Even on 64-bit architectures, don't store value directly in list. This would change usage of a collection
                 * based on architecture which would make code-portability difficult. */
                break;
            }
            break;
        case DB_COLLECTION:
            switch(db_collection(elementType)->kind) {
            case DB_ARRAY:
            case DB_SEQUENCE:
                /* Arrays and sequences (typically) don't fit in a collection */
                break;
            case DB_LIST:
            case DB_MAP:
                result = FALSE; /* Lists and maps fit in an address */
                break;
            }
            break;
        case DB_COMPOSITE:
            /* If type is composite and not a reference an alloc is required. */
            break;
        }
    }

    return result;
}


    
    
    
    
    
