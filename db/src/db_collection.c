/* db_collection.c
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
/* $end */

/* ::hyve::lang::collection::castable(lang::type type) */
db_bool db_collection_castable_v(db_collection _this, db_type type) {
/* $begin(::hyve::lang::collection::castable) */
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
/* $end */
}

/* ::hyve::lang::collection::elementRequiresAlloc() */
db_bool db_collection_elementRequiresAlloc(db_collection _this) {
/* $begin(::hyve::lang::collection::elementRequiresAlloc) */
    db_bool result = TRUE;
    db_type elementType = _this->elementType->real;

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
/* $end */
}

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::lang::collection::init(lang::collection object) */
db_int16 db_collection_init(db_collection object) {
/* $begin(::hyve::lang::collection::init) */
    db_type(object)->kind = DB_COLLECTION;
    return db_type__init(db_type(object));/* $end */
}

/* ::hyve::lang::collection::size() */
db_uint32 db_collection_size(db_any _this) {
/* $begin(::hyve::lang::collection::size) */
    db_uint32 result = 0;

    switch(db_collection(_this.type)->kind) {
    case DB_ARRAY:
        result = db_collection(_this.type)->max;
        break;
    case DB_SEQUENCE:
        result = ((db_objectSeq*)_this.value)->length;
        break;
    case DB_LIST:
        result = db_llSize(*(db_ll*)_this.value);
        break;
    case DB_MAP:
        result = db_rbtreeSize(*(db_rbtree*)_this.value);
        break;
    }

    return result;
/* $end */
}
