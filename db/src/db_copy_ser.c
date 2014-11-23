#include "db_copy_ser.h"
#include "db__object.h"
#include "db_mem.h"
#include "db_util.h"
#include "db_err.h"

#include "string.h"

static db_int16 db_ser_primitive(db_serializer s, db_value *info, void *userData) {
    db_type type = db_valueType(info)->real;
    db_copy_ser_t *data = userData;
    void *_this = db_valueValue(info);
    void *value = (void*)((db_word)db_valueValue(&data->value) + ((db_word)_this - (db_word)data->base));
    
    DB_UNUSED(s);
    
    if (db_primitive(type)->kind != DB_TEXT) {
        memcpy(value, _this, type->size);
    } else {
        *(db_string*)value = db_strdup(*(db_string*)_this);
    }
    
    return 0;
}

static db_int16 db_ser_reference(db_serializer s, db_value *info, void *userData) {
    db_copy_ser_t *data = userData;
    void *_this = db_valueValue(info);
    void *value = (void*)((db_word)db_valueValue(&data->value) + ((db_word)_this - (db_word)data->base));
    DB_UNUSED(s);
 
    db_set(value, *(db_object*)_this);
    
    return 0;
}

/* Deinit element */
void db_collection_deinitElement(db_collection t, void *ptr) {
    db_value v;
    if (db_collection_elementRequiresAlloc(t)) {
        db_valueValueInit(&v, NULL, db_typedef(t->elementType), ptr);
    } else {
        db_valueValueInit(&v, NULL, db_typedef(t->elementType), &ptr);
    }
    db_deinitValue(&v);
}

static db_int16 db_collection_copyListToArray(db_collection t, void *array, db_uint32 elementSize, db_ll list, db_bool reverse) {
    db_equalityKind result = 0;
    db_uint32 i=0;
    db_iter iter;
    void *e1, *e2;
    db_type elementType = t->elementType->real;
    db_any v1, v2;
    
    iter = db_llIter(list);
    while(db_iterHasNext(&iter)) {
        if (db_collection_elementRequiresAlloc(t)) {
            e2 = db_iterNext(&iter);
        } else {
            e2 = db_iterNextPtr(&iter);
        }
        e1 = DB_OFFSET(array, elementSize * i);
        v1.type = v2.type = elementType;
        v1.value = e1;
        v2.value = e2;
        if (!reverse) {
            result = db_type_copy(v1, v2);
        } else {
            result = db_type_copy(v2, v1);
        }
        i++;
    }
    
    return result;
}

/* TODO: should new elements be initialized? Should all elements be deinitialized first and then initialized? */
static db_int16 db_collection_copyListToList(db_collection t, db_ll list1, db_ll list2) {
    db_equalityKind result = 0;
    db_iter iter1, iter2;
    void *e1, *e2;
    db_type elementType = t->elementType->real;
    db_any v1, v2;

    iter1 = db_llIter(list1);
    iter2 = db_llIter(list2);
    while(db_iterHasNext(&iter1) && db_iterHasNext(&iter2)) {
        if (db_collection_elementRequiresAlloc(t)) {
            e1 = db_iterNext(&iter1);
            e2 = db_iterNext(&iter2);
        } else {
            e1 = db_iterNextPtr(&iter1);
            e2 = db_iterNextPtr(&iter2);
        }
        v1.type = v2.type = elementType;
        v1.value = e1;
        v2.value = e2;
        
        result = db_type_copy(v1, v2);
    }
    
    return result;
}

/* Resize list */
static void db_collection_resizeList(db_collection t, db_ll list, db_uint32 size) {
    db_uint32 ownSize = db_llSize(list);
    db_type elementType = t->elementType->real;
    
    /* If there are more elements in the destination, remove superfluous elements */
    if (ownSize > size) {
        db_uint32 i;
        void *ptr;
        for(i=size; i<ownSize; i++) {
            ptr = db_llTakeFirst(list);
            db_collection_deinitElement(t, ptr);
        }
        /* If there are less elements in the destination, add new elements */
    } else if (ownSize < size) {
        db_uint32 i;
        for(i=ownSize; i<size; i++) {
            void *ptr = NULL;
            if (db_collection_elementRequiresAlloc(t)) {
                ptr = db_calloc(elementType->size);
            }
            db_llInsert(list, ptr);
        }
    }
}


/* Resize list */
static void db_collection_resizeArray(db_collection t, void* sequence, db_uint32 size) {
    /* Only sequences can be resized */
    if (t->kind == DB_SEQUENCE) {
        db_uint32 ownSize = ((db_objectSeq*)sequence)->length;
        db_type elementType = t->elementType->real;
        
        /* If there are more elements in the destination, remove superfluous elements */
        if (ownSize > size) {
            db_uint32 i;
            for(i=size; i<ownSize; i++) {
                db_collection_deinitElement(t, DB_OFFSET(((db_objectSeq*)sequence)->buffer, elementType->size * i));
            }
            /* Reallocate buffer */
            ((db_objectSeq*)sequence)->buffer = db_realloc(((db_objectSeq*)sequence)->buffer, elementType->size * size);
            
            /* If there are less elements in the destination, add new elements */
        } else if (ownSize < size) {
            /* Reallocate buffer */
            ((db_objectSeq*)sequence)->buffer = db_realloc(((db_objectSeq*)sequence)->buffer, elementType->size * size);
            
            /* Memset new memory */
            memset(DB_OFFSET(((db_objectSeq*)sequence)->buffer, elementType->size * ownSize), 0, (size - ownSize) * elementType->size);
        }
        ((db_objectSeq*)sequence)->length = size;
    }
}

/* Copy collections */
static db_int16 db_ser_collection(db_serializer s, db_value *info, void* userData) {
    db_type t1, t2;
    void *v1, *v2;
    db_uint32 size1;
    db_copy_ser_t *data = userData;
    db_uint32 result = 0;
    
    DB_UNUSED(s);
    
    /* If this function is reached, collection-types are either equal or comparable. When the
     * base-object was a collection, the collection type can be different. When the base-object
     * was a composite type, the collection type has to be equal, since different composite
     * types are considered non-comparable. */
    t1 = db_valueType(info)->real;
    v1 = db_valueValue(info);
    
    /* Verify whether current serialized object is the base-object */
    if (info->parent) {
        t2 = t1;
        v2 = (void*)((db_word)db_valueValue(&data->value) + ((db_word)v1 - (db_word)data->base));
    } else {
        t2 = db_valueType(&data->value)->real;
        v2 = db_valueValue(&data->value);
    }
    
    {
        void *array1=NULL, *array2=NULL;
        db_ll list1=NULL, list2=NULL;
        db_uint32 elementSize=0;
        
        elementSize = db_type_sizeof(db_collection(t1)->elementType->real);
        
        switch(db_collection(t1)->kind) {
            case DB_ARRAY:
                array1 = v1;
                elementSize = db_type_sizeof(db_collection(t1)->elementType->real);
                size1 = db_collection(t1)->max;
                break;
            case DB_SEQUENCE:
                array1 = ((db_objectSeq*)v1)->buffer;
                elementSize = db_type_sizeof(db_collection(t1)->elementType->real);
                size1 = ((db_objectSeq*)v1)->length;
                break;
            case DB_LIST:
                list1 = *(db_ll*)v1;
                size1 = db_llSize(list1);
                break;
            case DB_MAP:
                break;
        }
        
        switch(db_collection(t2)->kind) {
            case DB_ARRAY:
                array2 = v2;
                break;
            case DB_SEQUENCE:
                array2 = ((db_objectSeq*)v2)->buffer;
                break;
            case DB_LIST:
                list2 = *(db_ll*)v2;
                break;
            case DB_MAP:
                break;
        }
        
        if (array1) {
            if (array2) {
                db_copy_ser_t privateData;
                                
                /* This is a bit tricky: I'm passing the pointer to what is potentially a sequence-buffer
                 * while I provide a sequence type. */
                db_valueValueInit(&privateData.value, NULL, db_typedef(t2), array2);
                privateData.base = array1;
                db_collection_resizeArray(db_collection(t2), v2, size1);
                result = db_serializeElements(s, info, &privateData);
            } else if (list2) {
                db_collection_resizeList(db_collection(t1), list2, size1);
                result = db_collection_copyListToArray(db_collection(t1), array1, elementSize, list2, TRUE);
            }
        } else if (list1) {
            if (array2) {
                db_collection_resizeArray(db_collection(t2), v2, size1);
                result = db_collection_copyListToArray(db_collection(t1), array2, elementSize, list1, FALSE);
            } else if (list2) {
                db_collection_resizeList(db_collection(t1), list2, size1);
                result = db_collection_copyListToList(db_collection(t1), list2, list1);
            }
        }
    }
    
    return result;
}

static db_int16 db_ser_construct(db_serializer s, db_value *info, void *userData) {
    db_copy_ser_t *data = userData;
    DB_UNUSED(s);
    
    db_type t1 = db_valueType(info)->real;
    db_type t2 = db_valueType(&data->value)->real;

    data->base = db_valueValue(info);
    
    return !db_type_castable(t2, t1);
}

struct db_serializer_s db_copy_ser(db_modifier access, db_operatorKind accessKind, db_serializerTraceKind trace) {
	struct db_serializer_s s;
    
	db_serializerInit(&s);
    
    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = trace;
    s.construct = db_ser_construct;
    s.program[DB_VOID] = NULL;
    s.program[DB_PRIMITIVE] = db_ser_primitive;
    s.program[DB_COLLECTION] = db_ser_collection;
    s.reference = db_ser_reference;
    return s;
}

