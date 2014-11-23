#include "db_compare_ser.h"
#include "db__object.h"
#include "db_mem.h"
#include "db_util.h"
#include "db_err.h"

#include "string.h"

#define DB_COMPARE(type,v1,v2) *(type*)v1 > *(type*)v2 ? DB_GT : *(type*)v1 < *(type*)v2 ? DB_LT : DB_EQ

static db_int16 db_ser_primitive(db_serializer s, db_value *info, void *userData) {
	db_equalityKind result = DB_EQ;
    db_compare_ser_t *data = userData;
    db_type type = db_valueType(info)->real;
    void *_this = db_valueValue(info);
    void *value = (void*)((db_word)db_valueValue(&data->value) + ((db_word)_this - (db_word)data->base));
    
    DB_UNUSED(s);
    
	switch(db_primitive(type)->kind) {
        case DB_BINARY:
            switch(db_primitive(type)->width) {
                case DB_WIDTH_8:
                    result = DB_COMPARE(db_octet, _this, value);
                    break;
                case DB_WIDTH_16:
                    result = DB_COMPARE(db_uint16, _this, value);
                    break;
                case DB_WIDTH_32:
                    result = DB_COMPARE(db_uint32, _this, value);
                    break;
                case DB_WIDTH_64:
                    result = DB_COMPARE(db_uint64, _this, value);
                    break;
                case DB_WIDTH_WORD:
                    result = DB_COMPARE(db_word, _this, value);
                    break;
            }
            break;
        case DB_BOOLEAN:
            result = DB_COMPARE(db_bool, _this, value);
            break;
        case DB_CHARACTER:
            result = DB_COMPARE(db_char, _this, value);
            break;
        case DB_INTEGER:
            switch(db_primitive(type)->width) {
                case DB_WIDTH_8:
                    result = DB_COMPARE(db_int8, _this, value);
                    break;
                case DB_WIDTH_16:
                    result = DB_COMPARE(db_int16, _this, value);
                    break;
                case DB_WIDTH_32:
                    result = DB_COMPARE(db_int32, _this, value);
                    break;
                case DB_WIDTH_64:
                    result = DB_COMPARE(db_int64, _this, value);
                    break;
                case DB_WIDTH_WORD:
                    result = DB_COMPARE(intptr_t, _this, value);
                    break;
            }
            break;
        case DB_UINTEGER:
            switch(db_primitive(type)->width) {
                case DB_WIDTH_8:
                    result = DB_COMPARE(db_uint8, _this, value);
                    break;
                case DB_WIDTH_16:
                    result = DB_COMPARE(db_uint16, _this, value);
                    break;
                case DB_WIDTH_32:
                    result = DB_COMPARE(db_uint32, _this, value);
                    break;
                case DB_WIDTH_64:
                    result = DB_COMPARE(db_uint64, _this, value);
                    break;
                case DB_WIDTH_WORD:
                    result = DB_COMPARE(uintptr_t, _this, value);
                    break;
            }
            break;
        case DB_FLOAT:
            switch(db_primitive(type)->width) {
                case DB_WIDTH_32:
                    result = DB_COMPARE(db_float32, _this, value);
                    break;
                case DB_WIDTH_64:
                    result = DB_COMPARE(db_float64, _this, value);
                    break;
                default:
                    break;
            }
            break;
        case DB_TEXT:
            result = strcmp(*(db_string*)_this, *(db_string*)value);
            break;
        case DB_ENUM:
        case DB_BITMASK:
            result = DB_COMPARE(db_int32, _this, value);
            break;
        case DB_ALIAS:
            result = DB_COMPARE(db_word, _this, value);
            break;
	}
    
    data->result = result;
    
	return data->result != DB_EQ;
}

static db_int16 db_ser_reference(db_serializer s, db_value *info, void *userData) {
    db_compare_ser_t *data = userData;
    void *_this = db_valueValue(info);
    void *value = (void*)((db_word)db_valueValue(&data->value) + ((db_word)_this - (db_word)data->base));
    DB_UNUSED(s);
    
    if (*(db_object*)_this != *(db_object*)value) {
        data->result = DB_NEQ;
    } else {
        data->result = DB_EQ;
    }
    
    return data->result != DB_EQ;
}

static db_equalityKind db_collection_compareArrayWithList(db_collection t, void *array, db_uint32 elementSize, db_ll list) {
    db_equalityKind result = DB_EQ;
    db_uint32 i=0;
    db_iter iter;
    void *e1, *e2;
    db_type elementType = t->elementType->real;
    db_any v1, v2;
    
    iter = db_llIter(list);
    while(db_iterHasNext(&iter)) {
        if (db_collection_elementRequiresAlloc(t)) {
            e1 = db_iterNext(&iter);
        } else {
            e1 = db_iterNextPtr(&iter);
        }
        e2 = DB_OFFSET(array, elementSize * i);
        v1.type = v2.type = elementType;
        v1.value = e2;
        v2.value = e1;
        result = db_type_compare(v1, v2);
        if (result != DB_EQ) {
            break;
        }
        i++;
    }
    
    return result;
}

static db_equalityKind db_collection_compareListWithList(db_collection t, db_ll list1, db_ll list2) {
    db_equalityKind result = DB_EQ;
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
        result = db_type_compare(v1, v2);
        if (result != DB_EQ) {
            break;
        }
    }
    
    return result;
}

/* Compare collections */
static db_int16 db_ser_collection(db_serializer s, db_value *info, void* userData) {
    db_type t1, t2;
    void *v1, *v2;
    db_equalityKind result = DB_EQ;
    db_uint32 size1 = 0, size2 = 0;
    db_compare_ser_t *data = userData;
    db_any a1, a2;
    
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
    
    /* Prepare any structures for determining sizes of collections */
    a1.type = t1;
    a1.value = v1;
    a2.type = t2;
    a2.value = v2;
    
    if ((size1 = db_collection_size(a1)) == (size2 = db_collection_size(a2))) {
        void *array1=NULL, *array2=NULL;
        db_ll list1=NULL, list2=NULL;
        db_uint32 elementSize=0, mem=0;
        
        elementSize = db_type_sizeof(db_collection(t1)->elementType->real);
        
        switch(db_collection(t1)->kind) {
            case DB_ARRAY:
                array1 = v1;
                elementSize = db_type_sizeof(db_collection(t1)->elementType->real);
                mem = db_collection(t1)->max * elementSize;
                break;
            case DB_SEQUENCE:
                array1 = ((db_objectSeq*)v1)->buffer;
                elementSize = db_type_sizeof(db_collection(t1)->elementType->real);
                mem = ((db_objectSeq*)v1)->length * elementSize;
                break;
            case DB_LIST:
                list1 = *(db_ll*)v1;
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
                result = memcmp(array1,array2,mem); /* TODO: do a serialized compare */
            } else if (list2) {
                result = db_collection_compareArrayWithList(db_collection(t1), array1, elementSize, list2);
            }
        } else if (list1) {
            if (array2) {
                result = db_collection_compareArrayWithList(db_collection(t1), array2, elementSize, list1);
                /* Reverse result */
                if (result != DB_EQ) {
                    if (result == DB_GT) {
                        result = DB_LT;
                    } else {
                        result = DB_GT;
                    }
                }
            } else if (list2) {
                result = db_collection_compareListWithList(db_collection(t1), list1, list2);
            }
        }
    } else {
        result = size1 > size2 ? DB_GT : DB_LT;
    }
    
    data->result = result;
    
    return data->result != DB_EQ;
}

static db_int16 db_ser_construct(db_serializer s, db_value *info, void *userData) {
    db_compare_ser_t *data = userData;
    db_bool compare = FALSE;
    DB_UNUSED(s);
    
    db_type t1 = db_valueType(info)->real;
    db_type t2 = db_valueType(&data->value)->real;
    
    /* If types are different, validate whether comparison should take place */
    if (t1 != t2) {
        /* Certain types of collections can be compared with each other as long as their elementTypes
         * are equal */
        if ((t1->kind == DB_COLLECTION) && (t1->kind == t2->kind)) {
            switch(db_collection(t1)->kind) {
            case DB_ARRAY:
            case DB_SEQUENCE:
            case DB_LIST:
                switch(db_collection(t2)->kind) {
                case DB_ARRAY:
                case DB_SEQUENCE:
                case DB_LIST:
                    if (db_collection(t1)->elementType == db_collection(t2)->elementType) {
                        compare = TRUE;
                    }
                    break;
                case DB_MAP:
                    compare = FALSE;
                    break;
                }
                break;
            case DB_MAP:
                if (db_collection(t2)->kind == DB_MAP) {
                    if (db_collection(t1)->elementType == db_collection(t2)->elementType) {
                        if (db_map(t1)->keyType == db_map(t2)->keyType) {
                            compare = TRUE;
                        }
                    }
                }
                break;
            }
        }
    } else {
        compare = TRUE;
    }
    
    data->result = compare ? DB_EQ : DB_NEQ;
    data->base = db_valueValue(info);
    
    return !compare;
}

struct db_serializer_s db_compare_ser(db_modifier access, db_operatorKind accessKind, db_serializerTraceKind trace) {
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

