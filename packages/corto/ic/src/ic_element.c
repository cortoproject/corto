/* $CORTO_GENERATED
 *
 * ic_element.c
 *
 * Code written between the begin and end tags will be preserved when the
 * file is regenerated.
 */

#include "ic.h"

corto_int16 _ic_element_construct(ic_element this) {
/* $begin(::corto::ic::element::construct) */
    corto_id name;
    corto_collection type = corto_collection(this->base->type);

    ic_storage(this)->kind = IC_ELEMENT;
    corto_setref(&ic_storage(this)->type, type->elementType);
    corto_setref(&ic_storage(this)->base, this->base);
    ic_storage(this)->isReference = type->elementType->reference;

    if (this->index) {
        corto_string elemStr = ic_node_str(this->index, NULL);
        sprintf(name, "%s[%s]", this->base->name, elemStr);
        corto_dealloc(elemStr);
    } else {
        sprintf(name, "*%s", this->base->name);
    }

    ic_storage(this)->name = corto_strdup(name);

    return ic_storage_construct(ic_storage(this));

/* $end */
}
