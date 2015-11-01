/* $CORTO_GENERATED
 *
 * corto_collection.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "corto.h"

/* $header() */
typedef struct __dummySeq {
    corto_uint32 length;
    void* buffer;
}__dummySeq;

static int corto_arrayWalk(corto_collection this, corto_void* array, corto_uint32 length, corto_walkAction action, corto_void* userData) {
    void* v;
    int result;
    corto_type elementType;
    corto_uint32 elementSize, i;

    result = 1;

    if (array) {
        elementType = this->elementType;
        elementSize = corto_type_sizeof(elementType);
        v = array;

        result = 1;
        for(i=0; (i<length) && result; i++) {
            result = action(v, userData);
            v = CORTO_OFFSET(v, elementSize);
        }
    }

    return result;
}

/* Walk contents of collection */
int corto_walk(corto_collection this, corto_void* collection, corto_walkAction action, corto_void* userData) {
    int result;

    result = 1;

    switch(this->kind) {
    case CORTO_ARRAY:
        result = corto_arrayWalk(this, collection, this->max, action, userData);
        break;
    case CORTO_SEQUENCE:
        result = corto_arrayWalk(this, ((__dummySeq*)collection)->buffer, ((__dummySeq*)collection)->length, action, userData);
        break;
    case CORTO_LIST: {
        corto_ll list = *(corto_ll*)collection;
        if (list) {
            if (corto_collection_elementRequiresAlloc(this)) {
                result = corto_llWalk(list, action, userData);
            } else {
                result = corto_llWalkPtr(list, action, userData);
            }
        }
        break;
    }
    case CORTO_MAP: {
        corto_rbtree tree = *(corto_rbtree*)collection;
        if (tree) {
            if (corto_collection_elementRequiresAlloc(this)) {
                result = corto_rbtreeWalk(tree, action, userData);
            } else {
                result = corto_rbtreeWalkPtr(tree, action, userData);
            }
        }
        break;
    }
    }
    return result;
}

/* Free references in collection */
static int corto_clearFreeReferences(void* o, void* udata) {
    CORTO_UNUSED(udata);
    corto_release(*(corto_object*)o);
    return 1;
}

/* Free values in collection */
static int corto_clearFreeValues(void* o, void* udata) {
    CORTO_UNUSED(udata);
    corto_dealloc(o);
    return 1;
}

/* Clear collection */
void corto_clear(corto_collection this, corto_void* collection) {
   corto_type elementType;

   elementType = this->elementType;

   /* If type is a reference type, do free's on all elements */
   if (elementType->reference) {
       corto_walk(this, collection, corto_clearFreeReferences, NULL);
   }

   switch(this->kind) {
   case CORTO_SEQUENCE:
       corto_dealloc(((__dummySeq*)collection)->buffer);
       ((__dummySeq*)collection)->buffer = NULL;
       ((__dummySeq*)collection)->length = 0;
       break;
   case CORTO_LIST: {
       corto_ll c;
       if ((c = *(corto_ll*)collection)) {
           if (corto_collection_elementRequiresAlloc(this)) {
               corto_walk(this, collection, corto_clearFreeValues, NULL);
           }
           corto_llFree(c);
       }
       break;
   }
   case CORTO_MAP: {
       corto_rbtree c;
       if ((c = *(corto_rbtree*)collection)) {
           if (!elementType->reference) {
               corto_walk(this, collection, corto_clearFreeValues, NULL);
           }
           corto_rbtreeFree(c);
       }
       break;
   }
   default: {
       corto_id id;
       corto_error("the clear operation is only valid for sequences, lists and maps (got %s)", corto_fullname(this, id));
       break;
   }
   }
}
/* $end */

corto_bool _corto_collection_castable_v(corto_collection this, corto_type type) {
/* $begin(::corto::lang::collection::castable) */
    corto_bool result = FALSE;
    if (type->kind == CORTO_COLLECTION) {
        corto_collection t = corto_collection(type);

        /* Arrays are only castable when they match exactly in size */
        if (!(this->kind == CORTO_ARRAY) || ((t->kind == CORTO_ARRAY) && (this->max == t->max))) {
            if (this->elementType != t->elementType) {
                if (this->elementType->kind == CORTO_COLLECTION) {
                    result = corto_collection_castable(corto_collection(this->elementType), t->elementType);
                }
            } else {
                result = TRUE;
            }
        }
    }

    return result;
/* $end */
}

corto_bool _corto_collection_compatible_v(corto_collection this, corto_type type) {
/* $begin(::corto::lang::collection::compatible) */
    corto_bool result = FALSE;

    if (type->kind == CORTO_COLLECTION) {
        if (corto_collection(this)->kind == corto_collection(type)->kind) {
            if(corto_collection(this)->elementType == corto_collection(type)->elementType) {
                result = TRUE;
            }
            if(corto_collection(this)->kind == CORTO_MAP) {
                if(corto_map(this)->keyType != corto_map(type)->keyType) {
                    result = FALSE;
                }
            }
        }
    }

    return result;
/* $end */
}

corto_bool _corto_collection_elementRequiresAlloc(corto_collection this) {
/* $begin(::corto::lang::collection::elementRequiresAlloc) */
    corto_bool result = TRUE;
    corto_type elementType = this->elementType;

    if (elementType->reference) {
        result = FALSE;
    } else {
        switch(elementType->kind) {
        case CORTO_VOID:
            corto_assert(0, "non reference void type cannot be an elementtype");
            break;
        case CORTO_ANY:
            /* Any values don't fit in an address */
            break;
        case CORTO_PRIMITIVE:
            switch(corto_primitive(elementType)->width) {
            case CORTO_WIDTH_8:
            case CORTO_WIDTH_16:
            case CORTO_WIDTH_32:
            case CORTO_WIDTH_WORD:
                /* At least a 32-bit architecture is required for corto. */
                result = FALSE;
                break;
            case CORTO_WIDTH_64:
                /* Even on 64-bit architectures, don't store value directly in list. This would change usage of a collection
                 * based on architecture which would make code-portability difficult. */
                break;
            }
            break;
        case CORTO_COLLECTION:
            switch(corto_collection(elementType)->kind) {
            case CORTO_ARRAY:
            case CORTO_SEQUENCE:
                /* Arrays and sequences (typically) don't fit in a collection */
                break;
            case CORTO_LIST:
            case CORTO_MAP:
                result = FALSE; /* Lists and maps fit in an address */
                break;
            }
            break;
        case CORTO_ITERATOR:
            /* Iterators are wider than an address */
            break;
        case CORTO_COMPOSITE:
            /* If type is composite and not a reference an alloc is required. */
            break;
        }
    }

    return result;
/* $end */
}

corto_int16 _corto_collection_init(corto_collection this) {
/* $begin(::corto::lang::collection::init) */
    corto_type(this)->kind = CORTO_COLLECTION;
    return corto_type_init(corto_type(this));
/* $end */
}

corto_uint32 _corto_collection_size(corto_any this) {
/* $begin(::corto::lang::collection::size) */
    corto_uint32 result = 0;

    switch(corto_collection(this.type)->kind) {
    case CORTO_ARRAY:
        result = corto_collection(this.type)->max;
        break;
    case CORTO_SEQUENCE:
        result = ((corto_objectseq*)this.value)->length;
        break;
    case CORTO_LIST:
        result = corto_llSize(*(corto_ll*)this.value);
        break;
    case CORTO_MAP:
        result = corto_rbtreeSize(*(corto_rbtree*)this.value);
        break;
    }

    return result;
/* $end */
}
