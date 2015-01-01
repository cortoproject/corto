/* cx_list.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

/* $header() */
#include "cx_value.h"
typedef void (*cx_list_action)(cx_ll list, void *value, void *userData);
static void cx_list_do(cx_any object, cx_any element, cx_bool insert, cx_list_action action, void *userData);

/* In place insertion of list to a list */
typedef struct cx_list_insertWalk_t {
    cx_iter iter;
    cx_any *dest;
}cx_list_insertWalk_t;

void cx_list_insertListAction(cx_ll list, void *value, void *userData) {
    cx_list_insertWalk_t *data = userData;
    CX_UNUSED(list);
    cx_iterInsert(&data->iter, value);
    cx_iterHasNext(&data->iter);
    cx_iterNext(&data->iter);
}

int cx_list_insertWalk(void* o, void* userData) {
    cx_list_insertWalk_t *data = userData;
    cx_any src;
    src.value = o;
    src.type = cx_collection(data->dest->type)->elementType->real;
    src.owner = FALSE;
    cx_list_do(*data->dest, src, TRUE, cx_list_insertListAction, data);
    return 1;
}

/* Append list to list */
int cx_list_appendWalk(void* o, void* userData) {
    cx_any *dest = userData;
    cx_any src;
    src.value = o;
    src.type = cx_collection(dest->type)->elementType->real;
    src.owner = FALSE;
    cx_list_append_lang_any(*dest, src);
    return 1;
}

/* Insert or append an element */
static void cx_list_do(cx_any object, cx_any element, cx_bool insert, cx_list_action action, void *userData) {
    cx_ll list = *(cx_ll*)object.value;
    void* value = NULL;
    cx_bool doCopy = TRUE;
    cx_value src, dst;
    
    /* If appending a list of the same type, insert all elements from 'element' to object */
    if (cx_type_castable(object.type, element.type)) {
        if (!insert) {
            cx_llWalk(*(cx_ll*)element.value, cx_list_appendWalk, &object);
            doCopy = FALSE;
        } else {
            cx_list_insertWalk_t walkData;
            walkData.iter = cx_llIter(list);
            walkData.dest = &object;
            cx_llWalk(*(cx_ll*)element.value, cx_list_insertWalk, &walkData);
            doCopy = FALSE;
            
        }
    } else if (cx_collection_elementRequiresAlloc(cx_collection(object.type))) {
        cx_uint32 size = cx_type_sizeof(cx_collection(object.type)->elementType->real);
        value = cx_calloc(size);
        cx_valueValueInit(&dst, NULL, cx_collection(object.type)->elementType, value);
        cx_initValue(&dst);
        cx_valueValueInit(&src, NULL, cx_collection(object.type)->elementType, element.value);
    } else {
        value = NULL;
        cx_valueValueInit(&dst, NULL, cx_collection(object.type)->elementType, &value);
        cx_initValue(&dst);
        cx_valueValueInit(&src, NULL, cx_collection(object.type)->elementType, element.value);
    }
    
    if (doCopy) {
        cx_valueCopy(&dst, &src);
        if (insert) {
            action(list, value, userData);
        } else {
            action(list, value, userData);
        }
    }
}

static void cx_list_insertAction(cx_ll list, void *value, void *userData) {
    CX_UNUSED(userData);
    cx_llInsert(list, value);
}

static void cx_list_appendAction(cx_ll list, void *value, void *userData) {
    CX_UNUSED(userData);
    cx_llAppend(list, value);
}

static void* cx_list_do_(cx_any object, cx_bool insert) {
    cx_ll list = *(cx_ll*)object.value;
    void* value = NULL;
    cx_value dst;
    
    if (cx_collection_elementRequiresAlloc(cx_collection(object.type))) {
        cx_uint32 size = cx_type_sizeof(cx_collection(object.type)->elementType->real);
        value = cx_calloc(size);
        cx_valueValueInit(&dst, NULL, cx_collection(object.type)->elementType, value);
        cx_initValue(&dst);
    } else {
        value = NULL;
        cx_valueValueInit(&dst, NULL, cx_collection(object.type)->elementType, &value);
        cx_initValue(&dst);
    }

    if (insert) {
        cx_llInsert(list, value);
    } else {
        cx_llAppend(list, value);
    }

    return value;
}

/* Free values in collection */
static int cx_clearFreeValues(void* o, void* udata) {
    CX_UNUSED(udata);
    cx_dealloc(o);
    return 1;
}
/* $end */

/* ::cortex::lang::list::append() */
cx_any cx_list_append_(cx_any _this) {
/* $begin(::cortex::lang::list::append()) */
    cx_any result;
    result.type = cx_collection(_this.type)->elementType->real;
    result.value = cx_list_do_(_this, FALSE);
    result.owner = FALSE;
    return result;
/* $end */
}

/* ::cortex::lang::list::append(lang::any element) */
cx_void cx_list_append_lang_any(cx_any _this, cx_any element) {
/* $begin(::cortex::lang::list::append(lang::any element)) */
	cx_list_do(_this, element, FALSE, cx_list_appendAction, NULL);
/* $end */
}

/* ::cortex::lang::list::clear() */
cx_void cx_list_clear(cx_any _this) {
/* $begin(::cortex::lang::list::clear) */
    cx_collection c = cx_collection(_this.type);
    if (cx_collection_elementRequiresAlloc(c)) {
        cx_llWalk(*(cx_ll*)_this.value, cx_clearFreeValues, NULL);
    }
    cx_llClear(*(cx_ll*)_this.value);
/* $end */
}

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::lang::list::construct(lang::list object) */
cx_int16 cx_list_construct(cx_list object) {
/* $begin(::cortex::lang::list::construct) */
	cx_type(object)->hasResources = TRUE;
	cx_type(object)->size = sizeof(cx_ll);
	cx_type(object)->alignment = CX_ALIGNMENT(cx_ll);
	return cx_type_construct(cx_type(object));
/* $end */
}

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::list::init(lang::list object) */
cx_int16 cx_list_init(cx_list object) {
/* $begin(::cortex::lang::list::init) */
    cx_collection(object)->kind = CX_LIST;
    return cx_collection_init(cx_collection(object));
/* $end */
}

/* ::cortex::lang::list::insert() */
cx_any cx_list_insert_(cx_any _this) {
/* $begin(::cortex::lang::list::insert()) */
    cx_any result;
    result.type = cx_collection(_this.type)->elementType->real;
    result.value = cx_list_do_(_this, TRUE);
    result.owner = FALSE;
    return result;
/* $end */
}

/* ::cortex::lang::list::insert(lang::any element) */
cx_void cx_list_insert_lang_any(cx_any _this, cx_any element) {
/* $begin(::cortex::lang::list::insert(lang::any element)) */
    cx_list_do(_this, element, TRUE, cx_list_insertAction, NULL);
/* $end */
}

/* ::cortex::lang::list::reverse() */
cx_void cx_list_reverse(cx_any _this) {
/* $begin(::cortex::lang::list::reverse) */
	cx_llReverse(*(cx_ll*)_this.value);
/* $end */
}
