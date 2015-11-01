/* $CORTO_GENERATED
 *
 * corto_list.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "corto.h"

/* $header() */
#include "corto_value.h"
typedef void (*corto_list_action)(corto_ll list, void *value, void *userData);
static void corto_list_do(corto_any object, corto_any element, corto_bool insert, corto_list_action action, void *userData);

/* In place insertion of list to a list */
typedef struct corto_list_insertWalk_t {
    corto_iter iter;
    corto_any *dest;
}corto_list_insertWalk_t;

void corto_list_insertListAction(corto_ll list, void *value, void *userData) {
    corto_list_insertWalk_t *data = userData;
    CORTO_UNUSED(list);
    corto_iterInsert(&data->iter, value);
    corto_iterNext(&data->iter);
}

int corto_list_insertWalk(void* o, void* userData) {
    corto_list_insertWalk_t *data = userData;
    corto_any src;
    src.value = o;
    src.type = corto_collection(data->dest->type)->elementType;
    src.owner = FALSE;
    corto_list_do(*data->dest, src, TRUE, corto_list_insertListAction, data);
    return 1;
}

/* Append list to list */
int corto_list_appendWalk(void* o, void* userData) {
    corto_any *dest = userData;
    corto_any src;
    src.value = o;
    src.type = corto_collection(dest->type)->elementType;
    src.owner = FALSE;
    corto_list_append_any(*dest, src);
    return 1;
}

/* Insert or append an element */
static void corto_list_do(corto_any object, corto_any element, corto_bool insert, corto_list_action action, void *userData) {
    corto_ll list = *(corto_ll*)object.value;
    void* value = NULL;
    corto_bool doCopy = TRUE;
    corto_value src, dst;
    
    /* If appending a list of the same type, insert all elements from 'element' to object */
    if (corto_type_castable(object.type, element.type)) {
        if (!insert) {
            corto_llWalk(*(corto_ll*)element.value, corto_list_appendWalk, &object);
            doCopy = FALSE;
        } else {
            corto_list_insertWalk_t walkData;
            walkData.iter = corto_llIter(list);
            walkData.dest = &object;
            corto_llWalk(*(corto_ll*)element.value, corto_list_insertWalk, &walkData);
            doCopy = FALSE;        
        }
    } else if (corto_collection_elementRequiresAlloc(corto_collection(object.type))) {
        corto_uint32 size = corto_type_sizeof(corto_collection(object.type)->elementType);
        value = corto_calloc(size);
        corto_valueValueInit(&dst, NULL, corto_collection(object.type)->elementType, value);
        corto_initv(&dst);
        corto_valueValueInit(&src, NULL, corto_collection(object.type)->elementType, element.value);
    } else {
        value = NULL;
        corto_valueValueInit(&dst, NULL, corto_collection(object.type)->elementType, &value);
        corto_initv(&dst);
        if (element.type->reference) {
            corto_valueValueInit(&src, NULL, corto_collection(object.type)->elementType, &element.value);
        } else {
            corto_valueValueInit(&src, NULL, corto_collection(object.type)->elementType, element.value);
        }
    }
    
    if (doCopy) {
        corto_copyv(&dst, &src);
        action(list, value, userData);
    }
}

static void corto_list_insertAction(corto_ll list, void *value, void *userData) {
    CORTO_UNUSED(userData);
    corto_llInsert(list, value);
}

static void corto_list_appendAction(corto_ll list, void *value, void *userData) {
    CORTO_UNUSED(userData);
    corto_llAppend(list, value);
}

static void* corto_list_do_(corto_any object, corto_bool insert) {
    corto_ll list = *(corto_ll*)object.value;
    void* value = NULL;
    corto_value dst;
    
    if (corto_collection_elementRequiresAlloc(corto_collection(object.type))) {
        corto_uint32 size = corto_type_sizeof(corto_collection(object.type)->elementType);
        value = corto_calloc(size);
        corto_valueValueInit(&dst, NULL, corto_collection(object.type)->elementType, value);
        corto_initv(&dst);
    } else {
        value = NULL;
        corto_valueValueInit(&dst, NULL, corto_collection(object.type)->elementType, &value);
        corto_initv(&dst);
    }

    if (insert) {
        corto_llInsert(list, value);
    } else {
        corto_llAppend(list, value);
    }

    return value;
}

/* Free values in collection */
static int corto_clearFreeValues(void* o, void* udata) {
    CORTO_UNUSED(udata);
    corto_dealloc(o);
    return 1;
}
/* $end */

corto_any _corto_list_append_(corto_any this) {
/* $begin(::corto::lang::list::append()) */
    corto_any result;
    result.type = corto_collection(this.type)->elementType;
    result.value = corto_list_do_(this, FALSE);
    result.owner = FALSE;
    return result;
/* $end */
}

corto_void _corto_list_append_any(corto_any this, corto_any element) {
/* $begin(::corto::lang::list::append(any element)) */
    corto_list_do(this, element, FALSE, corto_list_appendAction, NULL);
/* $end */
}

corto_void _corto_list_clear(corto_any this) {
/* $begin(::corto::lang::list::clear) */
    corto_collection c = corto_collection(this.type);
    if (corto_collection_elementRequiresAlloc(c)) {
        corto_llWalk(*(corto_ll*)this.value, corto_clearFreeValues, NULL);
    }
    corto_llClear(*(corto_ll*)this.value);
/* $end */
}

corto_int16 _corto_list_construct(corto_list this) {
/* $begin(::corto::lang::list::construct) */
    corto_type(this)->hasResources = TRUE;
    corto_type(this)->size = sizeof(corto_ll);
    corto_type(this)->alignment = CORTO_ALIGNMENT(corto_ll);
    if (!corto_collection(this)->elementType) {
        corto_error("no elementtype provided for list");
        goto error;
    }
    return corto_type_construct(corto_type(this));
error:
    return -1;
/* $end */
}

corto_int16 _corto_list_init(corto_list this) {
/* $begin(::corto::lang::list::init) */
    corto_collection(this)->kind = CORTO_LIST;
    return corto_collection_init(corto_collection(this));
/* $end */
}

corto_any _corto_list_insert_(corto_any this) {
/* $begin(::corto::lang::list::insert()) */
    corto_any result;
    result.type = corto_collection(this.type)->elementType;
    result.value = corto_list_do_(this, TRUE);
    result.owner = FALSE;
    return result;
/* $end */
}

corto_void _corto_list_insert_any(corto_any this, corto_any element) {
/* $begin(::corto::lang::list::insert(any element)) */
    corto_list_do(this, element, TRUE, corto_list_insertAction, NULL);
/* $end */
}

corto_void _corto_list_reverse(corto_any this) {
/* $begin(::corto::lang::list::reverse) */
    corto_llReverse(*(corto_ll*)this.value);
/* $end */
}
