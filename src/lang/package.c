/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

#include "src/store/object.h"

void corto_package_onDefine(corto_observerEvent *e)
{
    corto_object owner = corto_sourceof(e->data);

    /* If owner is a mount, object is being resumed */
    if (owner && corto_instanceof(corto_loader_o, owner)) {
        if (corto_loader(owner)->autoLoad) {
            corto_id id;
            if (corto_load_intern(corto_fullpath(id, e->data), 0, NULL, TRUE, FALSE, TRUE)) {
                corto_throw("unable to auto-load package '%s'", id);
                corto_raise();
            }
        }
    }

    corto_delete(e->observer); // Delete observer after first notification
}

int16_t corto_package_construct(
    corto_package this)
{
    if (this->_public && !corto_isbuiltin_package(this) && corto_check_attr(this, CORTO_ATTR_NAMED)) {

        /* Load package after object has been defined. Create one-shot observer to
         * trigger on DEFINE event */
        if (!corto_observe(CORTO_RESUME|CORTO_ON_SELF, this)
            .instance(this)
            .callback(corto_package_onDefine))
        {
            goto error;
        }
    }

    return 0;
error:
    return -1;
}

int16_t corto_package_init(
    corto_package this)
{
    this->_public = true;
    return 0;
}
