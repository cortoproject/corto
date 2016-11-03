/* $CORTO_GENERATED
 *
 * list.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/lang/lang.h>

/* $header() */
typedef void (*corto_list_action)(corto_ll list, void *value, void *userData);
static void corto_list_do(corto_any object, corto_any element, corto_bool insert, corto_list_action action, void *userData);

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
            /* TODO */
        }
    } else if (corto_collection_requiresAlloc(corto_collection(object.type)->elementType)) {
        corto_uint32 size = corto_type_sizeof(corto_collection(object.type)->elementType);
        value = corto_calloc(size);
        dst = corto_value_value(corto_collection(object.type)->elementType, value);
        corto_initv(&dst);
        src = corto_value_value(corto_collection(object.type)->elementType, element.value);
    } else {
        value = NULL;
        dst = corto_value_value(corto_collection(object.type)->elementType, &value);
        corto_initv(&dst);
        if (element.type->reference) {
            src = corto_value_value(corto_collection(object.type)->elementType, &element.value);
        } else {
            src = corto_value_value(corto_collection(object.type)->elementType, element.value);
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

    if (corto_collection_requiresAlloc(corto_collection(object.type)->elementType)) {
        corto_uint32 size = corto_type_sizeof(corto_collection(object.type)->elementType);
        value = corto_calloc(size);
        dst = corto_value_value(corto_collection(object.type)->elementType, value);
        corto_initv(&dst);
    } else {
        value = NULL;
        dst = corto_value_value(corto_collection(object.type)->elementType, &value);
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

corto_any _corto_list_append_(corto_any this)
{
/* $begin(corto/lang/list/append()) */
    corto_any result;
    result.type = corto_collection(this.type)->elementType;
    result.value = corto_list_do_(this, FALSE);
    result.owner = FALSE;
    return result;
/* $end */
}

corto_void _corto_list_append_any(corto_any this,
    corto_any element)
{
/* $begin(corto/lang/list/append(any element)) */
    corto_list_do(this, element, FALSE, corto_list_appendAction, NULL);
/* $end */
}

corto_void _corto_list_clear(corto_any this)
{
/* $begin(corto/lang/list/clear) */
    corto_collection c = corto_collection(this.type);
    if (corto_collection_requiresAlloc(c->elementType)) {
        corto_llWalk(*(corto_ll*)this.value, corto_clearFreeValues, NULL);
    }
    corto_llClear(*(corto_ll*)this.value);
/* $end */
}

corto_int16 _corto_list_construct(
    corto_list this)
{
/* $begin(corto/lang/list/construct) */
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

corto_int16 _corto_list_init(
    corto_list this)
{
/* $begin(corto/lang/list/init) */
    corto_collection(this)->kind = CORTO_LIST;
    return corto_collection_init(corto_collection(this));
/* $end */
}

corto_any _corto_list_insert_(corto_any this)
{
/* $begin(corto/lang/list/insert()) */
    corto_any result;
    result.type = corto_collection(this.type)->elementType;
    result.value = corto_list_do_(this, TRUE);
    result.owner = FALSE;
    return result;
/* $end */
}

corto_void _corto_list_insert_any(corto_any this,
    corto_any element)
{
/* $begin(corto/lang/list/insert(any element)) */
    corto_list_do(this, element, TRUE, corto_list_insertAction, NULL);
/* $end */
}

corto_void _corto_list_reverse(corto_any this)
{
/* $begin(corto/lang/list/reverse) */
    corto_llReverse(*(corto_ll*)this.value);
/* $end */
}
