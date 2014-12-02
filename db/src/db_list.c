/* db_list.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "db.h"
#include "db__meta.h"

/* $header() */
typedef void (*db_list_action)(db_ll list, void *value, void *userData);
static void db_list_do(db_any object, db_any element, db_bool insert, db_list_action action, void *userData);

/* In place insertion of list to a list */
typedef struct db_list_insertWalk_t {
    db_iter iter;
    db_any *dest;
}db_list_insertWalk_t;

void db_list_insertListAction(db_ll list, void *value, void *userData) {
    db_list_insertWalk_t *data = userData;
    DB_UNUSED(list);
    db_iterInsert(&data->iter, value);
    db_iterHasNext(&data->iter);
    db_iterNext(&data->iter);
}

int db_list_insertWalk(void* o, void* userData) {
    db_list_insertWalk_t *data = userData;
    db_any src;
    src.value = o;
    src.type = db_collection(data->dest->type)->elementType->real;
    src.owner = FALSE;
    db_list_do(*data->dest, src, TRUE, db_list_insertListAction, data);
    return 1;
}

/* Append list to list */
int db_list_appendWalk(void* o, void* userData) {
    db_any *dest = userData;
    db_any src;
    src.value = o;
    src.type = db_collection(dest->type)->elementType->real;
    src.owner = FALSE;
    db_list_append_lang_any(*dest, src);
    return 1;
}

/* Insert or append an element */
static void db_list_do(db_any object, db_any element, db_bool insert, db_list_action action, void *userData) {
    db_ll list = *(db_ll*)object.value;
    void* value = NULL;
    db_bool doCopy = TRUE;
    db_value src, dst;
    
    /* If appending a list of the same type, insert all elements from 'element' to object */
    if (db_type_castable(object.type, element.type)) {
        if (!insert) {
            db_llWalk(*(db_ll*)element.value, db_list_appendWalk, &object);
            doCopy = FALSE;
        } else {
            db_list_insertWalk_t walkData;
            walkData.iter = db_llIter(list);
            walkData.dest = &object;
            db_llWalk(*(db_ll*)element.value, db_list_insertWalk, &walkData);
            doCopy = FALSE;
            
        }
    } else if (db_collection_elementRequiresAlloc(db_collection(object.type))) {
        db_uint32 size = db_type_sizeof(db_collection(object.type)->elementType->real);
        value = db_calloc(size);
        db_valueValueInit(&dst, NULL, db_collection(object.type)->elementType, value);
        db_initValue(&dst);
        db_valueValueInit(&src, NULL, db_collection(object.type)->elementType, element.value);
    } else {
        value = NULL;
        db_valueValueInit(&dst, NULL, db_collection(object.type)->elementType, &value);
        db_initValue(&dst);
        db_valueValueInit(&src, NULL, db_collection(object.type)->elementType, element.value);
    }
    
    if (doCopy) {
        db_valueCopy(&dst, &src);
        if (insert) {
            action(list, value, userData);
        } else {
            action(list, value, userData);
        }
    }
}

static void db_list_insertAction(db_ll list, void *value, void *userData) {
    DB_UNUSED(userData);
    db_llInsert(list, value);
}

static void db_list_appendAction(db_ll list, void *value, void *userData) {
    DB_UNUSED(userData);
    db_llAppend(list, value);
}

static void* db_list_do_(db_any object, db_bool insert) {
    db_ll list = *(db_ll*)object.value;
    void* value = NULL;
    db_value dst;
    
    if (db_collection_elementRequiresAlloc(db_collection(object.type))) {
        db_uint32 size = db_type_sizeof(db_collection(object.type)->elementType->real);
        value = db_calloc(size);
        db_valueValueInit(&dst, NULL, db_collection(object.type)->elementType, value);
        db_initValue(&dst);
    } else {
        value = NULL;
        db_valueValueInit(&dst, NULL, db_collection(object.type)->elementType, &value);
        db_initValue(&dst);
    }

    if (insert) {
        db_llInsert(list, value);
    } else {
        db_llAppend(list, value);
    }

    return value;
}

/* Free values in collection */
static int db_clearFreeValues(void* o, void* udata) {
    DB_UNUSED(udata);
    db_dealloc(o);
    return 1;
}
/* $end */

/* ::hyve::lang::list::append() */
db_any db_list_append_(db_any _this) {
/* $begin(::hyve::lang::list::append()) */
    db_any result;
    result.type = db_collection(_this.type)->elementType->real;
    result.value = db_list_do_(_this, FALSE);
    result.owner = FALSE;
    return result;
/* $end */
}

/* ::hyve::lang::list::append(lang::any element) */
db_void db_list_append_lang_any(db_any _this, db_any element) {
/* $begin(::hyve::lang::list::append(lang::any element)) */
	db_list_do(_this, element, FALSE, db_list_appendAction, NULL);
/* $end */
}

/* ::hyve::lang::list::clear() */
db_void db_list_clear(db_any _this) {
/* $begin(::hyve::lang::list::clear) */
    db_collection c = db_collection(_this.type);
    if (db_collection_elementRequiresAlloc(c)) {
        db_llWalk(*(db_ll*)_this.value, db_clearFreeValues, NULL);
    }
    db_llClear(*(db_ll*)_this.value);
/* $end */
}

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::lang::list::construct(lang::list object) */
db_int16 db_list_construct(db_list object) {
/* $begin(::hyve::lang::list::construct) */
	db_type(object)->hasResources = TRUE;
	db_type(object)->size = sizeof(db_ll);
	db_type(object)->alignment = DB_ALIGNMENT(db_ll);
	return db_type_construct(db_type(object));
/* $end */
}

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::lang::list::init(lang::list object) */
db_int16 db_list_init(db_list object) {
/* $begin(::hyve::lang::list::init) */
    db_collection(object)->kind = DB_LIST;
    return db_collection_init(db_collection(object));
/* $end */
}

/* ::hyve::lang::list::insert() */
db_any db_list_insert_(db_any _this) {
/* $begin(::hyve::lang::list::insert()) */
    db_any result;
    result.type = db_collection(_this.type)->elementType->real;
    result.value = db_list_do_(_this, TRUE);
    result.owner = FALSE;
    return result;
/* $end */
}

/* ::hyve::lang::list::insert(lang::any element) */
db_void db_list_insert_lang_any(db_any _this, db_any element) {
/* $begin(::hyve::lang::list::insert(lang::any element)) */
    db_list_do(_this, element, TRUE, db_list_insertAction, NULL);
/* $end */
}

/* ::hyve::lang::list::reverse() */
db_void db_list_reverse(db_any _this) {
/* $begin(::hyve::lang::list::reverse) */
	db_llReverse(*(db_ll*)_this.value);
/* $end */
}
