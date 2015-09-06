/* ic_element.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_ic_LIB
#include "ic.h"

/* ::corto::ic::element::construct() */
cx_int16 _ic_element_construct(ic_element this) {
/* $begin(::corto::ic::element::construct) */
    cx_id name;
    cx_collection type = cx_collection(this->base->type);

    ic_storage(this)->kind = IC_ELEMENT;
    cx_setref(&ic_storage(this)->type, type->elementType);
    cx_setref(&ic_storage(this)->base, this->base);
    ic_storage(this)->isReference = type->elementType->reference;

    if (this->index) {
        cx_string elemStr = ic_node_str(this->index, NULL);
        sprintf(name, "%s[%s]", this->base->name, elemStr);
        cx_dealloc(elemStr);
    } else {
        sprintf(name, "*%s", this->base->name);
    }

    ic_storage(this)->name = cx_strdup(name);

    return ic_storage_construct(ic_storage(this));

/* $end */
}
