/* native.c
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#include <corto/c/c.h>
#include <corto/native/_load.h>

corto_native_type _corto_native_typeCreate(corto_string name) {
    corto_native_type _this;
    _this = corto_native_type(corto_declare(corto_native_type_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_ptr_setstr(&((corto_native_type)_this)->name, name);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_native_type _corto_native_typeCreateChild(corto_object _parent, corto_string _id, corto_string name) {
    corto_native_type _this;
    _this = corto_native_type(corto_declareChild(_parent, _id, corto_native_type_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        corto_ptr_setstr(&((corto_native_type)_this)->name, name);
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _corto_native_typeUpdate(corto_native_type _this, corto_string name) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            corto_ptr_setstr(&((corto_native_type)((corto_native_type)CORTO_OFFSET(_this, ((corto_type)corto_native_type_o)->size)))->name, name);
        } else {
            corto_ptr_setstr(&((corto_native_type)_this)->name, name);
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

corto_native_type _corto_native_typeDeclare(void) {
    corto_native_type _this;
    _this = corto_native_type(corto_declare(corto_native_type_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_native_type _corto_native_typeDeclareChild(corto_object _parent, corto_string _id) {
    corto_native_type _this;
    _this = corto_native_type(corto_declareChild(_parent, _id, corto_native_type_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _corto_native_typeDefine(corto_native_type _this, corto_string name) {
    CORTO_UNUSED(_this);
    corto_ptr_setstr(&((corto_native_type)_this)->name, name);
    return corto_define(_this);
}

corto_native_type _corto_native_typeAssign(corto_native_type _this, corto_string name) {
    CORTO_UNUSED(_this);
    corto_ptr_setstr(&((corto_native_type)_this)->name, name);
    return _this;
}

int32_t* corto_int32seqAppend(corto_int32seq *seq, int32_t element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (int32_t*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_int32_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    corto_ptr_copy(&seq->buffer[seq->length-1], corto_int32_o, &element);
    return &seq->buffer[seq->length-1];
}

int32_t* corto_int32seqAppendAlloc(corto_int32seq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (int32_t*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_int32_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void corto_int32seqSize(corto_int32seq *seq, corto_uint32 length) {
    corto_uint32 size;
    seq->buffer = (int32_t*)corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_int32_o))));
    if (length > seq->length) {
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
    }
    seq->length = length;
}

void corto_int32seqClear(corto_int32seq *seq) {
    corto_int32seqSize(seq, 0);
}

corto_interface* corto_interfaceseqAppend(corto_interfaceseq *seq, corto_interface element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_interface*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_interface_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    corto_ptr_setref(&seq->buffer[seq->length-1], element);
    return &seq->buffer[seq->length-1];
}

corto_interface* corto_interfaceseqAppendAlloc(corto_interfaceseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_interface*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_interface_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void corto_interfaceseqSize(corto_interfaceseq *seq, corto_uint32 length) {
    corto_uint32 size;
    seq->buffer = (corto_interface*)corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_interface_o))));
    if (length > seq->length) {
        corto_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                corto_value v;
                v = corto_value_value(&seq->buffer[i], corto_type(corto_interface_o));
                corto_value_deinit(&v);
            }
        }
    }
    seq->length = length;
}

void corto_interfaceseqClear(corto_interfaceseq *seq) {
    corto_interfaceseqSize(seq, 0);
}

corto_interfaceVector* corto_interfaceVectorseqAppend(corto_interfaceVectorseq *seq, corto_interfaceVector element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_interfaceVector*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_interfaceVector_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        corto_value v;
        v = corto_value_value(&seq->buffer[seq->length-1], corto_type(corto_interfaceVector_o));
        corto_value_init(&v);
    }
    corto_ptr_copy(&seq->buffer[seq->length-1], corto_interfaceVector_o, &element);
    return &seq->buffer[seq->length-1];
}

corto_interfaceVector* corto_interfaceVectorseqAppendAlloc(corto_interfaceVectorseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_interfaceVector*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_interfaceVector_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        corto_value v;
        v = corto_value_value(&seq->buffer[seq->length-1], corto_type(corto_interfaceVector_o));
        corto_value_init(&v);
    }
    return &seq->buffer[seq->length-1];
}

void corto_interfaceVectorseqSize(corto_interfaceVectorseq *seq, corto_uint32 length) {
    corto_uint32 size;
    if (length < seq->length) {
        corto_uint32 i;
        for(i=length; i<seq->length; i++) {
            {
                corto_value v;
                v = corto_value_value(&seq->buffer[i], corto_type(corto_interfaceVector_o));
                corto_value_deinit(&v);
            }
        }
    }
    seq->buffer = (corto_interfaceVector*)corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_interfaceVector_o))));
    if (length > seq->length) {
        corto_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                corto_value v;
                v = corto_value_value(&seq->buffer[i], corto_type(corto_interfaceVector_o));
                corto_value_deinit(&v);
            }
        }
    }
    seq->length = length;
}

void corto_interfaceVectorseqClear(corto_interfaceVectorseq *seq) {
    corto_interfaceVectorseqSize(seq, 0);
}

void corto_objectlistInsert(corto_objectlist list, corto_object element) {
    corto_ll_insert(list, (void*)(corto_word)element);
    corto_claim(element);
}

void corto_objectlistAppend(corto_objectlist list, corto_object element) {
    corto_ll_append(list, (void*)(corto_word)element);
    corto_claim(element);
}

void corto_objectlistRemove(corto_objectlist list, corto_object element) {
    corto_ll_remove(list, element);
    corto_release(element);
}

corto_object corto_objectlistTakeFirst(corto_objectlist list) {
    return (corto_object)(corto_word)corto_ll_takeFirst(list);
}

corto_object corto_objectlistLast(corto_objectlist list) {
    return (corto_object)(corto_word)corto_ll_last(list);
}

corto_object corto_objectlistGet(corto_objectlist list, corto_uint32 index) {
    return (corto_object)(corto_word)corto_ll_get(list, index);
}

corto_uint32 corto_objectlistSize(corto_objectlist list) {
    return corto_ll_size(list);
}

void corto_objectlistClear(corto_objectlist list) {
    corto_iter iter = corto_ll_iter(list);
    while(corto_iter_hasNext(&iter)) {
        void *ptr = corto_iter_next(&iter);
        corto_release(ptr);
    }
    corto_ll_clear(list);
}

corto_object* corto_objectseqAppend(corto_objectseq *seq, corto_object element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_object*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_object_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    corto_ptr_setref(&seq->buffer[seq->length-1], element);
    return &seq->buffer[seq->length-1];
}

corto_object* corto_objectseqAppendAlloc(corto_objectseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_object*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_object_o))));
    memset(seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void corto_objectseqSize(corto_objectseq *seq, corto_uint32 length) {
    corto_uint32 size;
    seq->buffer = (corto_object*)corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_object_o))));
    if (length > seq->length) {
        corto_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                corto_value v;
                v = corto_value_value(&seq->buffer[i], corto_type(corto_object_o));
                corto_value_deinit(&v);
            }
        }
    }
    seq->length = length;
}

void corto_objectseqClear(corto_objectseq *seq) {
    corto_objectseqSize(seq, 0);
}

corto_parameter* corto_parameterseqAppend(corto_parameterseq *seq, corto_parameter element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_parameter*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_parameter_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        corto_value v;
        v = corto_value_value(&seq->buffer[seq->length-1], corto_type(corto_parameter_o));
        corto_value_init(&v);
    }
    corto_ptr_copy(&seq->buffer[seq->length-1], corto_parameter_o, &element);
    return &seq->buffer[seq->length-1];
}

corto_parameter* corto_parameterseqAppendAlloc(corto_parameterseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_parameter*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_parameter_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        corto_value v;
        v = corto_value_value(&seq->buffer[seq->length-1], corto_type(corto_parameter_o));
        corto_value_init(&v);
    }
    return &seq->buffer[seq->length-1];
}

void corto_parameterseqSize(corto_parameterseq *seq, corto_uint32 length) {
    corto_uint32 size;
    if (length < seq->length) {
        corto_uint32 i;
        for(i=length; i<seq->length; i++) {
            {
                corto_value v;
                v = corto_value_value(&seq->buffer[i], corto_type(corto_parameter_o));
                corto_value_deinit(&v);
            }
        }
    }
    seq->buffer = (corto_parameter*)corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_parameter_o))));
    if (length > seq->length) {
        corto_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                corto_value v;
                v = corto_value_value(&seq->buffer[i], corto_type(corto_parameter_o));
                corto_value_deinit(&v);
            }
        }
    }
    seq->length = length;
}

void corto_parameterseqClear(corto_parameterseq *seq) {
    corto_parameterseqSize(seq, 0);
}

void corto_stringlistInsert(corto_stringlist list, corto_string element) {
    corto_ll_insert(list, (void*)corto_strdup(element));
}

void corto_stringlistAppend(corto_stringlist list, corto_string element) {
    corto_ll_append(list, (void*)corto_strdup(element));
}

corto_string corto_stringlistTakeFirst(corto_stringlist list) {
    return (corto_string)(corto_word)corto_ll_takeFirst(list);
}

corto_string corto_stringlistLast(corto_stringlist list) {
    return (corto_string)(corto_word)corto_ll_last(list);
}

corto_string corto_stringlistGet(corto_stringlist list, corto_uint32 index) {
    return (corto_string)(corto_word)corto_ll_get(list, index);
}

corto_uint32 corto_stringlistSize(corto_stringlist list) {
    return corto_ll_size(list);
}

void corto_stringlistClear(corto_stringlist list) {
    corto_iter iter = corto_ll_iter(list);
    while(corto_iter_hasNext(&iter)) {
        void *ptr = corto_iter_next(&iter);
        corto_ptr_deinit(ptr, corto_string_o);
    }
    corto_ll_clear(list);
}

corto_string* corto_stringseqAppend(corto_stringseq *seq, corto_string element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_string*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_string_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    corto_ptr_copy(&seq->buffer[seq->length-1], corto_string_o, &element);
    return &seq->buffer[seq->length-1];
}

corto_string* corto_stringseqAppendAlloc(corto_stringseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (corto_string*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_string_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void corto_stringseqSize(corto_stringseq *seq, corto_uint32 length) {
    corto_uint32 size;
    seq->buffer = (corto_string*)corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_string_o))));
    if (length > seq->length) {
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
    }
    seq->length = length;
}

void corto_stringseqClear(corto_stringseq *seq) {
    corto_stringseqSize(seq, 0);
}

uintptr_t* corto_wordseqAppend(corto_wordseq *seq, uintptr_t element) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (uintptr_t*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_word_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    corto_ptr_copy(&seq->buffer[seq->length-1], corto_word_o, &element);
    return &seq->buffer[seq->length-1];
}

uintptr_t* corto_wordseqAppendAlloc(corto_wordseq *seq) {
    corto_uint32 size;
    seq->length++;
    seq->buffer = (uintptr_t*)corto_realloc(seq->buffer, seq->length * (size=corto_type_sizeof(corto_type(corto_word_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    return &seq->buffer[seq->length-1];
}

void corto_wordseqSize(corto_wordseq *seq, corto_uint32 length) {
    corto_uint32 size;
    seq->buffer = (uintptr_t*)corto_realloc(seq->buffer, length * (size=corto_type_sizeof(corto_type(corto_word_o))));
    if (length > seq->length) {
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
    }
    seq->length = length;
}

void corto_wordseqClear(corto_wordseq *seq) {
    corto_wordseqSize(seq, 0);
}

corto_mountSubscription* corto_mountSubscriptionListInsertAlloc(corto_mountSubscriptionList list) {
    corto_mountSubscription* result;
    result = (corto_mountSubscription*)corto_calloc(corto_type_sizeof(corto_type(corto_mountSubscription_o)));
    {
        corto_value v;
        v = corto_value_value(result, corto_type(corto_mountSubscription_o));
        corto_value_init(&v);
    }
    corto_ll_insert(list, result);
    return result;
}

corto_mountSubscription* corto_mountSubscriptionListInsert(corto_mountSubscriptionList list, corto_mountSubscription* element) {
    corto_mountSubscription *result = corto_mountSubscriptionListInsertAlloc(list);
    corto_ptr_copy(result, corto_mountSubscription_o, element);
    return result;
}

corto_mountSubscription* corto_mountSubscriptionListAppendAlloc(corto_mountSubscriptionList list) {
    corto_mountSubscription* result;
    result = (corto_mountSubscription*)corto_calloc(corto_type_sizeof(corto_type(corto_mountSubscription_o)));
    {
        corto_value v;
        v = corto_value_value(result, corto_type(corto_mountSubscription_o));
        corto_value_init(&v);
    }
    corto_ll_append(list, result);
    return result;
}

corto_mountSubscription* corto_mountSubscriptionListAppend(corto_mountSubscriptionList list, corto_mountSubscription* element) {
    corto_mountSubscription *result = corto_mountSubscriptionListAppendAlloc(list);
    corto_ptr_copy(result, corto_mountSubscription_o, element);
    return result;
}

corto_mountSubscription* corto_mountSubscriptionListTakeFirst(corto_mountSubscriptionList list) {
    return (corto_mountSubscription*)(corto_word)corto_ll_takeFirst(list);
}

corto_mountSubscription* corto_mountSubscriptionListLast(corto_mountSubscriptionList list) {
    return (corto_mountSubscription*)(corto_word)corto_ll_last(list);
}

corto_mountSubscription* corto_mountSubscriptionListGet(corto_mountSubscriptionList list, corto_uint32 index) {
    return (corto_mountSubscription*)corto_ll_get(list, index);
}

corto_uint32 corto_mountSubscriptionListSize(corto_mountSubscriptionList list) {
    return corto_ll_size(list);
}

void corto_mountSubscriptionListClear(corto_mountSubscriptionList list) {
    corto_iter iter = corto_ll_iter(list);
    while(corto_iter_hasNext(&iter)) {
        void *ptr = corto_iter_next(&iter);
        corto_ptr_deinit(ptr, corto_mountSubscription_o);
        corto_dealloc(ptr);
    }
    corto_ll_clear(list);
}

corto_result* corto_resultListInsertAlloc(corto_resultList list) {
    corto_result* result;
    result = (corto_result*)corto_calloc(corto_type_sizeof(corto_type(corto_result_o)));
    {
        corto_value v;
        v = corto_value_value(result, corto_type(corto_result_o));
        corto_value_init(&v);
    }
    corto_ll_insert(list, result);
    return result;
}

corto_result* corto_resultListInsert(corto_resultList list, corto_result* element) {
    corto_result *result = corto_resultListInsertAlloc(list);
    corto_ptr_copy(result, corto_result_o, element);
    return result;
}

corto_result* corto_resultListAppendAlloc(corto_resultList list) {
    corto_result* result;
    result = (corto_result*)corto_calloc(corto_type_sizeof(corto_type(corto_result_o)));
    {
        corto_value v;
        v = corto_value_value(result, corto_type(corto_result_o));
        corto_value_init(&v);
    }
    corto_ll_append(list, result);
    return result;
}

corto_result* corto_resultListAppend(corto_resultList list, corto_result* element) {
    corto_result *result = corto_resultListAppendAlloc(list);
    corto_ptr_copy(result, corto_result_o, element);
    return result;
}

corto_result* corto_resultListTakeFirst(corto_resultList list) {
    return (corto_result*)(corto_word)corto_ll_takeFirst(list);
}

corto_result* corto_resultListLast(corto_resultList list) {
    return (corto_result*)(corto_word)corto_ll_last(list);
}

corto_result* corto_resultListGet(corto_resultList list, corto_uint32 index) {
    return (corto_result*)corto_ll_get(list, index);
}

corto_uint32 corto_resultListSize(corto_resultList list) {
    return corto_ll_size(list);
}

void corto_resultListClear(corto_resultList list) {
    corto_iter iter = corto_ll_iter(list);
    while(corto_iter_hasNext(&iter)) {
        void *ptr = corto_iter_next(&iter);
        corto_ptr_deinit(ptr, corto_result_o);
        corto_dealloc(ptr);
    }
    corto_ll_clear(list);
}

