/* cx_collection.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

/* $header() */
typedef struct __dummySeq {
    cx_uint32 length;
    void* buffer;
}__dummySeq;

static int cx_arrayWalk(cx_collection _this, cx_void* array, cx_uint32 length, cx_walkAction action, cx_void* userData) {
    void* v;
    int result;
    cx_type elementType;
    cx_uint32 elementSize, i;

    result = 1;

    if (array) {
        elementType = _this->elementType->real;
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
int cx_walk(cx_collection _this, cx_void* collection, cx_walkAction action, cx_void* userData) {
    int result;

    result = 1;

    switch(_this->kind) {
    case CX_ARRAY:
        result = cx_arrayWalk(_this, collection, _this->max, action, userData);
        break;
    case CX_SEQUENCE:
        result = cx_arrayWalk(_this, ((__dummySeq*)collection)->buffer, ((__dummySeq*)collection)->length, action, userData);
        break;
    case CX_LIST: {
        cx_ll list = *(cx_ll*)collection;
        if (list) {
            if (cx_collection_elementRequiresAlloc(_this)) {
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
            if (cx_collection_elementRequiresAlloc(_this)) {
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
    cx_free(*(cx_object*)o);
    return 1;
}

/* Free values in collection */
static int cx_clearFreeValues(void* o, void* udata) {
    CX_UNUSED(udata);
    cx_dealloc(o);
    return 1;
}

/* Clear collection */
void cx_clear(cx_collection _this, cx_void* collection) {
   cx_type elementType;

   elementType = _this->elementType->real;

   /* If type is a reference type, do free's on all elements */
   if (elementType->reference) {
       cx_walk(_this, collection, cx_clearFreeReferences, NULL);
   }

   switch(_this->kind) {
   case CX_SEQUENCE:
       cx_dealloc(((__dummySeq*)collection)->buffer);
       ((__dummySeq*)collection)->buffer = NULL;
       ((__dummySeq*)collection)->length = 0;
       break;
   case CX_LIST: {
       cx_ll c;
       if ((c = *(cx_ll*)collection)) {
           if (cx_collection_elementRequiresAlloc(_this)) {
               cx_walk(_this, collection, cx_clearFreeValues, NULL);
           }
           cx_llFree(c);
       }
       break;
   }
   case CX_MAP: {
       cx_rbtree c;
       if ((c = *(cx_rbtree*)collection)) {
           if (!elementType->reference) {
               cx_walk(_this, collection, cx_clearFreeValues, NULL);
           }
           cx_rbtreeFree(c);
       }
       break;
   }
   default: {
       cx_id id;
       cx_error("the clear operation is only valid for sequences, lists and maps (got %s)", cx_fullname(_this, id));
       break;
   }
   }
}
/* $end */

/* ::cortex::lang::collection::castable(lang::type type) */
cx_bool cx_collection_castable_v(cx_collection _this, cx_type type) {
/* $begin(::cortex::lang::collection::castable) */
    cx_bool result = FALSE;
    if (type->kind == CX_COLLECTION) {
        cx_collection t = cx_collection(type);
        
        /* Arrays are only castable when they match exactly in size */
        if (!(_this->kind == CX_ARRAY) || ((t->kind == CX_ARRAY) && (_this->max == t->max))) {
            if (_this->elementType != t->elementType) {
                if (_this->elementType->real->kind == CX_COLLECTION) {
                    result = cx_collection_castable(cx_collection(_this->elementType->real), t->elementType->real);
                }
            } else {
                result = TRUE;
            }
        }
    }
    
    return result;
/* $end */
}

/* ::cortex::lang::collection::compatible(lang::type type) */
cx_bool cx_collection_compatible_v(cx_collection _this, cx_type type) {
/* $begin(::cortex::lang::collection::compatible) */
    cx_bool result = FALSE;

    if (type->kind == CX_COLLECTION) {
        if (cx_collection(_this)->kind == cx_collection(type)->kind) {
            if(cx_collection(_this)->elementType == cx_collection(type)->elementType) {
                result = TRUE;
            }
            if(cx_collection(_this)->kind == CX_MAP) {
                if(cx_map(_this)->keyType != cx_map(type)->keyType) {
                    result = FALSE;
                }
            }
        }
    }

    return result;
/* $end */
}

/* ::cortex::lang::collection::elementRequiresAlloc() */
cx_bool cx_collection_elementRequiresAlloc(cx_collection _this) {
/* $begin(::cortex::lang::collection::elementRequiresAlloc) */
    cx_bool result = TRUE;
    cx_type elementType = _this->elementType->real;

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
                /* At least a 32-bit architecture is required for cortex. */
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
        case CX_COMPOSITE:
            /* If type is composite and not a reference an alloc is required. */
            break;
        }
    }

    return result;
/* $end */
}

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::collection::init(lang::collection object) */
cx_int16 cx_collection_init(cx_collection object) {
/* $begin(::cortex::lang::collection::init) */
    cx_type(object)->kind = CX_COLLECTION;
    return cx_type__init(cx_type(object));/* $end */
}

/* ::cortex::lang::collection::size() */
cx_uint32 cx_collection_size(cx_any _this) {
/* $begin(::cortex::lang::collection::size) */
    cx_uint32 result = 0;

    switch(cx_collection(_this.type)->kind) {
    case CX_ARRAY:
        result = cx_collection(_this.type)->max;
        break;
    case CX_SEQUENCE:
        result = ((cx_objectSeq*)_this.value)->length;
        break;
    case CX_LIST:
        result = cx_llSize(*(cx_ll*)_this.value);
        break;
    case CX_MAP:
        result = cx_rbtreeSize(*(cx_rbtree*)_this.value);
        break;
    }

    return result;
/* $end */
}
