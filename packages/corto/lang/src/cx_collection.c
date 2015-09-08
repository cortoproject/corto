/* cx_collection.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_lang_LIB
#include "cx.h"

/* $header() */
typedef struct __dummySeq {
    cx_uint32 length;
    void* buffer;
}__dummySeq;

static int cx_arrayWalk(cx_collection this, cx_void* array, cx_uint32 length, cx_walkAction action, cx_void* userData) {
    void* v;
    int result;
    cx_type elementType;
    cx_uint32 elementSize, i;

    result = 1;

    if (array) {
        elementType = this->elementType;
        elementSize = cx_type_sizeof(elementType);
        v = array;

        result = 1;
        for(i=0; (i<length) && result; i++) {
            result = action(v, userData);
            v = CX_OFFSET(v, elementSize);
        }
    }

    return result;
}

/* Walk contents of collection */
int cx_walk(cx_collection this, cx_void* collection, cx_walkAction action, cx_void* userData) {
    int result;

    result = 1;

    switch(this->kind) {
    case CX_ARRAY:
        result = cx_arrayWalk(this, collection, this->max, action, userData);
        break;
    case CX_SEQUENCE:
        result = cx_arrayWalk(this, ((__dummySeq*)collection)->buffer, ((__dummySeq*)collection)->length, action, userData);
        break;
    case CX_LIST: {
        cx_ll list = *(cx_ll*)collection;
        if (list) {
            if (cx_collection_elementRequiresAlloc(this)) {
                result = cx_llWalk(list, action, userData);
            } else {
                result = cx_llWalkPtr(list, action, userData);
            }
        }
        break;
    }
    case CX_MAP: {
        cx_rbtree tree = *(cx_rbtree*)collection;
        if (tree) {
            if (cx_collection_elementRequiresAlloc(this)) {
                result = cx_rbtreeWalk(tree, action, userData);
            } else {
                result = cx_rbtreeWalkPtr(tree, action, userData);
            }
        }
        break;
    }
    }
    return result;
}

/* Free references in collection */
static int cx_clearFreeReferences(void* o, void* udata) {
    CX_UNUSED(udata);
    cx_release(*(cx_object*)o);
    return 1;
}

/* Free values in collection */
static int cx_clearFreeValues(void* o, void* udata) {
    CX_UNUSED(udata);
    cx_dealloc(o);
    return 1;
}

/* Clear collection */
void cx_clear(cx_collection this, cx_void* collection) {
   cx_type elementType;

   elementType = this->elementType;

   /* If type is a reference type, do free's on all elements */
   if (elementType->reference) {
       cx_walk(this, collection, cx_clearFreeReferences, NULL);
   }

   switch(this->kind) {
   case CX_SEQUENCE:
       cx_dealloc(((__dummySeq*)collection)->buffer);
       ((__dummySeq*)collection)->buffer = NULL;
       ((__dummySeq*)collection)->length = 0;
       break;
   case CX_LIST: {
       cx_ll c;
       if ((c = *(cx_ll*)collection)) {
           if (cx_collection_elementRequiresAlloc(this)) {
               cx_walk(this, collection, cx_clearFreeValues, NULL);
           }
           cx_llFree(c);
       }
       break;
   }
   case CX_MAP: {
       cx_rbtree c;
       if ((c = *(cx_rbtree*)collection)) {
           if (!elementType->reference) {
               cx_walk(this, collection, cx_clearFreeValues, NULL);
           }
           cx_rbtreeFree(c);
       }
       break;
   }
   default: {
       cx_id id;
       cx_error("the clear operation is only valid for sequences, lists and maps (got %s)", cx_fullname(this, id));
       break;
   }
   }
}
/* $end */

/* ::corto::lang::collection::castable(type type) */
cx_bool _cx_collection_castable_v(cx_collection this, cx_type type) {
/* $begin(::corto::lang::collection::castable) */
    cx_bool result = FALSE;
    if (type->kind == CX_COLLECTION) {
        cx_collection t = cx_collection(type);

        /* Arrays are only castable when they match exactly in size */
        if (!(this->kind == CX_ARRAY) || ((t->kind == CX_ARRAY) && (this->max == t->max))) {
            if (this->elementType != t->elementType) {
                if (this->elementType->kind == CX_COLLECTION) {
                    result = cx_collection_castable(cx_collection(this->elementType), t->elementType);
                }
            } else {
                result = TRUE;
            }
        }
    }

    return result;
/* $end */
}

/* ::corto::lang::collection::compatible(type type) */
cx_bool _cx_collection_compatible_v(cx_collection this, cx_type type) {
/* $begin(::corto::lang::collection::compatible) */
    cx_bool result = FALSE;

    if (type->kind == CX_COLLECTION) {
        if (cx_collection(this)->kind == cx_collection(type)->kind) {
            if(cx_collection(this)->elementType == cx_collection(type)->elementType) {
                result = TRUE;
            }
            if(cx_collection(this)->kind == CX_MAP) {
                if(cx_map(this)->keyType != cx_map(type)->keyType) {
                    result = FALSE;
                }
            }
        }
    }

    return result;
/* $end */
}

/* ::corto::lang::collection::elementRequiresAlloc() */
cx_bool _cx_collection_elementRequiresAlloc(cx_collection this) {
/* $begin(::corto::lang::collection::elementRequiresAlloc) */
    cx_bool result = TRUE;
    cx_type elementType = this->elementType;

    if (elementType->reference) {
        result = FALSE;
    } else {
        switch(elementType->kind) {
        case CX_VOID:
            cx_assert(0, "non reference void type cannot be an elementtype");
            break;
        case CX_ANY:
            /* Any values don't fit in an address */
            break;
        case CX_PRIMITIVE:
            switch(cx_primitive(elementType)->width) {
            case CX_WIDTH_8:
            case CX_WIDTH_16:
            case CX_WIDTH_32:
            case CX_WIDTH_WORD:
                /* At least a 32-bit architecture is required for corto. */
                result = FALSE;
                break;
            case CX_WIDTH_64:
                /* Even on 64-bit architectures, don't store value directly in list. This would change usage of a collection
                 * based on architecture which would make code-portability difficult. */
                break;
            }
            break;
        case CX_COLLECTION:
            switch(cx_collection(elementType)->kind) {
            case CX_ARRAY:
            case CX_SEQUENCE:
                /* Arrays and sequences (typically) don't fit in a collection */
                break;
            case CX_LIST:
            case CX_MAP:
                result = FALSE; /* Lists and maps fit in an address */
                break;
            }
            break;
        case CX_ITERATOR:
            /* Iterators are wider than an address */
            break;
        case CX_COMPOSITE:
            /* If type is composite and not a reference an alloc is required. */
            break;
        }
    }

    return result;
/* $end */
}

/* ::corto::lang::collection::init() */
cx_int16 _cx_collection_init(cx_collection this) {
/* $begin(::corto::lang::collection::init) */
    cx_type(this)->kind = CX_COLLECTION;
    return cx_type_init(cx_type(this));
/* $end */
}

/* ::corto::lang::collection::size() */
cx_uint32 _cx_collection_size(cx_any this) {
/* $begin(::corto::lang::collection::size) */
    cx_uint32 result = 0;

    switch(cx_collection(this.type)->kind) {
    case CX_ARRAY:
        result = cx_collection(this.type)->max;
        break;
    case CX_SEQUENCE:
        result = ((cx_objectseq*)this.value)->length;
        break;
    case CX_LIST:
        result = cx_llSize(*(cx_ll*)this.value);
        break;
    case CX_MAP:
        result = cx_rbtreeSize(*(cx_rbtree*)this.value);
        break;
    }

    return result;
/* $end */
}
