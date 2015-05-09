/* ic_scope.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "ic.h"

/* ::cortex::ic::scope::add(node n) */
cx_void ic_scope_add(ic_scope _this, ic_node n) {
/* $begin(::cortex::ic::scope::add) */

    cx_llAppend(_this->program, n);

/* $end */
}

/* ::cortex::ic::scope::lookupStorage(string name,bool recursive) */
ic_storage ic_scope_lookupStorage(ic_scope _this, cx_string name, cx_bool recursive) {
/* $begin(::cortex::ic::scope::lookupStorage) */
    cx_iter storageIter;
    ic_storage result = NULL;

    storageIter = cx_llIter(_this->storages);
    while(cx_iterHasNext(&storageIter)) {
        result = cx_iterNext(&storageIter);
        if (!strcmp(result->name, name)) {
            break;
        } else {
            result = NULL;
        }
    }

    if (!result && _this->parent && recursive && !_this->isFunction) {
        result = ic_scope_lookupStorage(_this->parent, name, TRUE);
    }

    return result;
/* $end */
}
