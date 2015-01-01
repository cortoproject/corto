#include "cx_copy_ser.h"
#include "cx__object.h"
#include "cx_mem.h"
#include "cx_util.h"
#include "cx_err.h"

#include "string.h"

static cx_int16 cx_ser_primitive(cx_serializer s, cx_value *info, void *userData) {
    cx_type type = cx_valueType(info)->real;
    cx_copy_ser_t *data = userData;
    void *_this = cx_valueValue(info);
    void *value = (void*)((cx_word)cx_valueValue(&data->value) + ((cx_word)_this - (cx_word)data->base));
    
    DB_UNUSED(s);
    
    if (cx_primitive(type)->kind != DB_TEXT) {
        memcpy(value, _this, type->size);
    } else {
        *(cx_string*)value = cx_strdup(*(cx_string*)_this);
    }
    
    return 0;
}

static cx_int16 cx_ser_reference(cx_serializer s, cx_value *info, void *userData) {
    cx_copy_ser_t *data = userData;
    void *_this = cx_valueValue(info);
    void *value = (void*)((cx_word)cx_valueValue(&data->value) + ((cx_word)_this - (cx_word)data->base));
    DB_UNUSED(s);
 
    cx_set(value, *(cx_object*)_this);
    
    return 0;
}

/* Deinit element */
void cx_collection_deinitElement(cx_collection t, void *ptr) {
    cx_value v;
    if (cx_collection_elementRequiresAlloc(t)) {
        cx_valueValueInit(&v, NULL, cx_typedef(t->elementType), ptr);
    } else {
        cx_valueValueInit(&v, NULL, cx_typedef(t->elementType), &ptr);
    }
    cx_deinitValue(&v);
}

static cx_int16 cx_collection_copyListToArray(cx_collection t, void *array, cx_uint32 elementSize, cx_ll list, cx_bool reverse) {
    cx_equalityKind result = 0;
    cx_uint32 i=0;
    cx_iter iter;
    void *e1, *e2;
    cx_type elementType = t->elementType->real;
    cx_any v1, v2;
    
    iter = cx_llIter(list);
    while(cx_iterHasNext(&iter)) {
        if (cx_collection_elementRequiresAlloc(t)) {
            e2 = cx_iterNext(&iter);
        } else {
            e2 = cx_iterNextPtr(&iter);
        }
        e1 = DB_OFFSET(array, elementSize * i);
        v1.type = v2.type = elementType;
        v1.value = e1;
        v2.value = e2;
        if (!reverse) {
            result = cx_type_copy(v1, v2);
        } else {
            result = cx_type_copy(v2, v1);
        }
        i++;
    }
    
    return result;
}

/* TODO: should new elements be initialized? Should all elements be deinitialized first and then initialized? */
static cx_int16 cx_collection_copyListToList(cx_collection t, cx_ll list1, cx_ll list2) {
    cx_equalityKind result = 0;
    cx_iter iter1, iter2;
    void *e1, *e2;
    cx_type elementType = t->elementType->real;
    cx_any v1, v2;

    iter1 = cx_llIter(list1);
    iter2 = cx_llIter(list2);
    while(cx_iterHasNext(&iter1) && cx_iterHasNext(&iter2)) {
        if (cx_collection_elementRequiresAlloc(t)) {
            e1 = cx_iterNext(&iter1);
            e2 = cx_iterNext(&iter2);
        } else {
            e1 = cx_iterNextPtr(&iter1);
            e2 = cx_iterNextPtr(&iter2);
        }
        v1.type = v2.type = elementType;
        v1.value = e1;
        v2.value = e2;
        
        result = cx_type_copy(v1, v2);
    }
    
    return result;
}

/* Resize list */
static void cx_collection_resizeList(cx_collection t, cx_ll list, cx_uint32 size) {
    cx_uint32 ownSize = cx_llSize(list);
    cx_type elementType = t->elementType->real;
    
    /* If there are more elements in the destination, remove superfluous elements */
    if (ownSize > size) {
        cx_uint32 i;
        void *ptr;
        for(i=size; i<ownSize; i++) {
            ptr = cx_llTakeFirst(list);
            cx_collection_deinitElement(t, ptr);
        }
        /* If there are less elements in the destination, add new elements */
    } else if (ownSize < size) {
        cx_uint32 i;
        for(i=ownSize; i<size; i++) {
            void *ptr = NULL;
            if (cx_collection_elementRequiresAlloc(t)) {
                ptr = cx_calloc(elementType->size);
            }
            cx_llInsert(list, ptr);
        }
    }
}


/* Resize list */
static void cx_collection_resizeArray(cx_collection t, void* sequence, cx_uint32 size) {
    /* Only sequences can be resized */
    if (t->kind == DB_SEQUENCE) {
        cx_uint32 ownSize = ((cx_objectSeq*)sequence)->length;
        cx_type elementType = t->elementType->real;
        
        /* If there are more elements in the destination, remove superfluous elements */
        if (ownSize > size) {
            cx_uint32 i;
            for(i=size; i<ownSize; i++) {
                cx_collection_deinitElement(t, DB_OFFSET(((cx_objectSeq*)sequence)->buffer, elementType->size * i));
            }
            /* Reallocate buffer */
            ((cx_objectSeq*)sequence)->buffer = cx_realloc(((cx_objectSeq*)sequence)->buffer, elementType->size * size);
            
            /* If there are less elements in the destination, add new elements */
        } else if (ownSize < size) {
            /* Reallocate buffer */
            ((cx_objectSeq*)sequence)->buffer = cx_realloc(((cx_objectSeq*)sequence)->buffer, elementType->size * size);
            
            /* Memset new memory */
            memset(DB_OFFSET(((cx_objectSeq*)sequence)->buffer, elementType->size * ownSize), 0, (size - ownSize) * elementType->size);
        }
        ((cx_objectSeq*)sequence)->length = size;
    }
}

/* Copy collections */
static cx_int16 cx_ser_collection(cx_serializer s, cx_value *info, void* userData) {
    cx_type t1, t2;
    void *v1, *v2;
    cx_uint32 size1;
    cx_copy_ser_t *data = userData;
    cx_uint32 result = 0;
    
    DB_UNUSED(s);
    
    /* If this function is reached, collection-types are either equal or comparable. When the
     * base-object was a collection, the collection type can be different. When the base-object
     * was a composite type, the collection type has to be equal, since different composite
     * types are considered non-comparable. */
    t1 = cx_valueType(info)->real;
    v1 = cx_valueValue(info);
    
    /* Verify whether current serialized object is the base-object */
    if (info->parent) {
        t2 = t1;
        v2 = (void*)((cx_word)cx_valueValue(&data->value) + ((cx_word)v1 - (cx_word)data->base));
    } else {
        t2 = cx_valueType(&data->value)->real;
        v2 = cx_valueValue(&data->value);
    }
    
    {
        void *array1=NULL, *array2=NULL;
        cx_ll list1=NULL, list2=NULL;
        cx_uint32 elementSize=0;
        
        elementSize = cx_type_sizeof(cx_collection(t1)->elementType->real);
        
        switch(cx_collection(t1)->kind) {
            case DB_ARRAY:
                array1 = v1;
                elementSize = cx_type_sizeof(cx_collection(t1)->elementType->real);
                size1 = cx_collection(t1)->max;
                break;
            case DB_SEQUENCE:
                array1 = ((cx_objectSeq*)v1)->buffer;
                elementSize = cx_type_sizeof(cx_collection(t1)->elementType->real);
                size1 = ((cx_objectSeq*)v1)->length;
                break;
            case DB_LIST:
                list1 = *(cx_ll*)v1;
                size1 = cx_llSize(list1);
                break;
            case DB_MAP:
                break;
        }
        
        switch(cx_collection(t2)->kind) {
            case DB_ARRAY:
                array2 = v2;
                break;
            case DB_SEQUENCE:
                array2 = ((cx_objectSeq*)v2)->buffer;
                break;
            case DB_LIST:
                list2 = *(cx_ll*)v2;
                break;
            case DB_MAP:
                break;
        }
        
        if (array1) {
            if (array2) {
                cx_copy_ser_t privateData;
                                
                /* This is a bit tricky: I'm passing the pointer to what is potentially a sequence-buffer
                 * while I provide a sequence type. */
                cx_valueValueInit(&privateData.value, NULL, cx_typedef(t2), array2);
                privateData.base = array1;
                cx_collection_resizeArray(cx_collection(t2), v2, size1);
                result = cx_serializeElements(s, info, &privateData);
            } else if (list2) {
                cx_collection_resizeList(cx_collection(t1), list2, size1);
                result = cx_collection_copyListToArray(cx_collection(t1), array1, elementSize, list2, TRUE);
            }
        } else if (list1) {
            if (array2) {
                cx_collection_resizeArray(cx_collection(t2), v2, size1);
                result = cx_collection_copyListToArray(cx_collection(t1), array2, elementSize, list1, FALSE);
            } else if (list2) {
                cx_collection_resizeList(cx_collection(t1), list2, size1);
                result = cx_collection_copyListToList(cx_collection(t1), list2, list1);
            }
        }
    }
    
    return result;
}

static cx_int16 cx_ser_construct(cx_serializer s, cx_value *info, void *userData) {
    cx_copy_ser_t *data = userData;
    DB_UNUSED(s);
    
    cx_type t1 = cx_valueType(info)->real;
    cx_type t2 = cx_valueType(&data->value)->real;

    data->base = cx_valueValue(info);
    
    return !cx_type_castable(t2, t1);
}

struct cx_serializer_s cx_copy_ser(cx_modifier access, cx_operatorKind accessKind, cx_serializerTraceKind trace) {
	struct cx_serializer_s s;
    
	cx_serializerInit(&s);
    
    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = trace;
    s.construct = cx_ser_construct;
    s.program[DB_VOID] = NULL;
    s.program[DB_PRIMITIVE] = cx_ser_primitive;
    s.program[DB_COLLECTION] = cx_ser_collection;
    s.reference = cx_ser_reference;
    return s;
}

