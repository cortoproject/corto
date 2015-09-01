#include "cx_compare_ser.h"
#include "cx__object.h"
#include "cx_mem.h"
#include "cx_util.h"
#include "cx_err.h"

#include "string.h"

#define CX_COMPARE(type,v1,v2) *(type*)v1 > *(type*)v2 ? CX_GT : *(type*)v1 < *(type*)v2 ? CX_LT : CX_EQ

static cx_int16 cx_ser_primitive(cx_serializer s, cx_value *info, void *userData) {
    cx_equalityKind result = CX_EQ;
    cx_compare_ser_t *data = userData;
    cx_type type = cx_valueType(info);
    void *_this = cx_valueValue(info);
    void *value = (void*)((cx_word)cx_valueValue(&data->value) + ((cx_word)_this - (cx_word)data->base));
    
    CX_UNUSED(s);
    
    switch(cx_primitive(type)->kind) {
        case CX_BINARY:
            switch(cx_primitive(type)->width) {
                case CX_WIDTH_8:
                    result = CX_COMPARE(cx_octet, _this, value);
                    break;
                case CX_WIDTH_16:
                    result = CX_COMPARE(cx_uint16, _this, value);
                    break;
                case CX_WIDTH_32:
                    result = CX_COMPARE(cx_uint32, _this, value);
                    break;
                case CX_WIDTH_64:
                    result = CX_COMPARE(cx_uint64, _this, value);
                    break;
                case CX_WIDTH_WORD:
                    result = CX_COMPARE(cx_word, _this, value);
                    break;
            }
            break;
        case CX_BOOLEAN:
            result = CX_COMPARE(cx_bool, _this, value);
            break;
        case CX_CHARACTER:
            result = CX_COMPARE(cx_char, _this, value);
            break;
        case CX_INTEGER:
            switch(cx_primitive(type)->width) {
                case CX_WIDTH_8:
                    result = CX_COMPARE(cx_int8, _this, value);
                    break;
                case CX_WIDTH_16:
                    result = CX_COMPARE(cx_int16, _this, value);
                    break;
                case CX_WIDTH_32:
                    result = CX_COMPARE(cx_int32, _this, value);
                    break;
                case CX_WIDTH_64:
                    result = CX_COMPARE(cx_int64, _this, value);
                    break;
                case CX_WIDTH_WORD:
                    result = CX_COMPARE(intptr_t, _this, value);
                    break;
            }
            break;
        case CX_UINTEGER:
            switch(cx_primitive(type)->width) {
                case CX_WIDTH_8:
                    result = CX_COMPARE(cx_uint8, _this, value);
                    break;
                case CX_WIDTH_16:
                    result = CX_COMPARE(cx_uint16, _this, value);
                    break;
                case CX_WIDTH_32:
                    result = CX_COMPARE(cx_uint32, _this, value);
                    break;
                case CX_WIDTH_64:
                    result = CX_COMPARE(cx_uint64, _this, value);
                    break;
                case CX_WIDTH_WORD:
                    result = CX_COMPARE(uintptr_t, _this, value);
                    break;
            }
            break;
        case CX_FLOAT:
            switch(cx_primitive(type)->width) {
                case CX_WIDTH_32:
                    result = CX_COMPARE(cx_float32, _this, value);
                    break;
                case CX_WIDTH_64:
                    result = CX_COMPARE(cx_float64, _this, value);
                    break;
                default:
                    break;
            }
            break;
        case CX_TEXT: {
            cx_string thisStr = *(cx_string*)_this;
            cx_string valueStr = *(cx_string*)value;
            if (thisStr && valueStr) {
                result = strcmp(thisStr, valueStr);
            } else {
                result = !(thisStr == valueStr);
            }
            break;
        }
        case CX_ENUM:
        case CX_BITMASK:
            result = CX_COMPARE(cx_int32, _this, value);
            break;
    }
    
    data->result = result;
    
    return data->result != CX_EQ;
}

static cx_int16 cx_ser_reference(cx_serializer s, cx_value *info, void *userData) {
    cx_compare_ser_t *data = userData;
    void *_this = cx_valueValue(info);
    void *value = (void*)((cx_word)cx_valueValue(&data->value) + ((cx_word)_this - (cx_word)data->base));
    CX_UNUSED(s);
    
    if (*(cx_object*)_this != *(cx_object*)value) {
        data->result = CX_NEQ;
    } else {
        data->result = CX_EQ;
    }
    
    return data->result != CX_EQ;
}

static cx_equalityKind cx_collection_compareArrayWithList(cx_collection t, void *array, cx_uint32 elementSize, cx_ll list) {
    cx_equalityKind result = CX_EQ;
    cx_uint32 i=0;
    cx_iter iter;
    void *e1, *e2;
    cx_type elementType = t->elementType;
    cx_any v1, v2;
    
    iter = cx_llIter(list);
    while(cx_iterHasNext(&iter)) {
        if (cx_collection_elementRequiresAlloc(t)) {
            e1 = cx_iterNext(&iter);
        } else {
            e1 = cx_iterNextPtr(&iter);
        }
        e2 = CX_OFFSET(array, elementSize * i);
        v1.type = v2.type = elementType;
        v1.value = e2;
        v2.value = e1;
        result = cx_type_compare(v1, v2);
        if (result != CX_EQ) {
            break;
        }
        i++;
    }
    
    return result;
}

static cx_equalityKind cx_collection_compareListWithList(cx_collection t, cx_ll list1, cx_ll list2) {
    cx_equalityKind result = CX_EQ;
    cx_iter iter1, iter2;
    void *e1, *e2;
    cx_type elementType = t->elementType;
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
        result = cx_type_compare(v1, v2);
        if (result != CX_EQ) {
            break;
        }
    }
    
    return result;
}

/* Compare collections */
static cx_int16 cx_ser_collection(cx_serializer s, cx_value *info, void* userData) {
    cx_type t1, t2;
    void *v1, *v2;
    cx_equalityKind result = CX_EQ;
    cx_uint32 size1 = 0, size2 = 0;
    cx_compare_ser_t *data = userData;
    cx_any a1, a2;
    
    CX_UNUSED(s);
    
    /* If this function is reached, collection-types are either equal or comparable. When the 
     * base-object was a collection, the collection type can be different. When the base-object
     * was a composite type, the collection type has to be equal, since different composite 
     * types are considered non-comparable. */
    t1 = cx_valueType(info);
    v1 = cx_valueValue(info);
    
    /* Verify whether current serialized object is the base-object */
    if (info->parent) {
        t2 = t1;
        v2 = (void*)((cx_word)cx_valueValue(&data->value) + ((cx_word)v1 - (cx_word)data->base));
    } else {
        t2 = cx_valueType(&data->value);
        v2 = cx_valueValue(&data->value);
    }
    
    /* Prepare any structures for determining sizes of collections */
    a1.type = t1;
    a1.value = v1;
    a2.type = t2;
    a2.value = v2;
    
    if ((size1 = cx_collection_size(a1)) == (size2 = cx_collection_size(a2))) {
        void *array1=NULL, *array2=NULL;
        cx_ll list1=NULL, list2=NULL;
        cx_uint32 elementSize=0, mem=0;
        
        elementSize = cx_type_sizeof(cx_collection(t1)->elementType);
        
        switch(cx_collection(t1)->kind) {
            case CX_ARRAY:
                array1 = v1;
                elementSize = cx_type_sizeof(cx_collection(t1)->elementType);
                mem = cx_collection(t1)->max * elementSize;
                break;
            case CX_SEQUENCE:
                array1 = ((cx_objectseq*)v1)->buffer;
                elementSize = cx_type_sizeof(cx_collection(t1)->elementType);
                mem = ((cx_objectseq*)v1)->length * elementSize;
                break;
            case CX_LIST:
                list1 = *(cx_ll*)v1;
                break;
            case CX_MAP:
                break;
        }
        
        switch(cx_collection(t2)->kind) {
            case CX_ARRAY:
                array2 = v2;
                break;
            case CX_SEQUENCE:
                array2 = ((cx_objectseq*)v2)->buffer;
                break;
            case CX_LIST:
                list2 = *(cx_ll*)v2;
                break;
            case CX_MAP:
                break;
        }
        
        if (array1) {
            if (array2) {
                result = memcmp(array1,array2,mem); /* TODO: do a serialized compare */
            } else if (list2) {
                result = cx_collection_compareArrayWithList(cx_collection(t1), array1, elementSize, list2);
            }
        } else if (list1) {
            if (array2) {
                result = cx_collection_compareArrayWithList(cx_collection(t1), array2, elementSize, list1);
                /* Reverse result */
                if (result != CX_EQ) {
                    if (result == CX_GT) {
                        result = CX_LT;
                    } else {
                        result = CX_GT;
                    }
                }
            } else if (list2) {
                result = cx_collection_compareListWithList(cx_collection(t1), list1, list2);
            }
        }
    } else {
        result = size1 > size2 ? CX_GT : CX_LT;
    }
    
    data->result = result < 0 ? -1 : result > 0 ? 1 : 0;
    
    return data->result != CX_EQ;
}

static cx_int16 cx_ser_construct(cx_serializer s, cx_value *info, void *userData) {
    cx_compare_ser_t *data = userData;
    cx_bool compare = FALSE;
    CX_UNUSED(s);
    
    cx_type t1 = cx_valueType(info);
    cx_type t2 = cx_valueType(&data->value);
    
    /* If types are different, validate whether comparison should take place */
    if (t1 != t2) {
        /* Certain types of collections can be compared with each other as long as their elementTypes
         * are equal */
        if ((t1->kind == CX_COLLECTION) && (t1->kind == t2->kind)) {
            switch(cx_collection(t1)->kind) {
            case CX_ARRAY:
            case CX_SEQUENCE:
            case CX_LIST:
                switch(cx_collection(t2)->kind) {
                case CX_ARRAY:
                case CX_SEQUENCE:
                case CX_LIST:
                    if (cx_collection(t1)->elementType == cx_collection(t2)->elementType) {
                        compare = TRUE;
                    }
                    break;
                case CX_MAP:
                    compare = FALSE;
                    break;
                }
                break;
            case CX_MAP:
                if (cx_collection(t2)->kind == CX_MAP) {
                    if (cx_collection(t1)->elementType == cx_collection(t2)->elementType) {
                        if (cx_map(t1)->keyType == cx_map(t2)->keyType) {
                            compare = TRUE;
                        }
                    }
                }
                break;
            }
        } else {
            if ((!t1->reference && (t1->kind == CX_VOID)) && (t2->reference || 
               ((t2->kind == CX_PRIMITIVE) && (cx_primitive(t2)->kind == CX_TEXT)))) {
                compare = TRUE;
            }
            if ((!t2->reference && (t2->kind == CX_VOID)) && (t1->reference || 
               ((t1->kind == CX_PRIMITIVE) && (cx_primitive(t1)->kind == CX_TEXT)))) {
                compare = TRUE;
            }
        }
    } else {
        compare = TRUE;
    }
    
    data->result = compare ? CX_EQ : CX_NEQ;
    data->base = cx_valueValue(info);

    return !compare;
}

struct cx_serializer_s cx_compare_ser(cx_modifier access, cx_operatorKind accessKind, cx_serializerTraceKind trace) {
    struct cx_serializer_s s;
    
    cx_serializerInit(&s);
    
    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = trace;
    s.construct = cx_ser_construct;
    s.program[CX_VOID] = NULL;
    s.program[CX_PRIMITIVE] = cx_ser_primitive;
    s.program[CX_COLLECTION] = cx_ser_collection;
    s.reference = cx_ser_reference;

    return s;
}

