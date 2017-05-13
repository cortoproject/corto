/* $CORTO_GENERATED
 *
 * package.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/corto.h>

/* $header() */
#include "_object.h"
/* $end */

/* $header(corto/core/package/construct) */
void corto_package_onDefine(corto_observerEvent *e)
{
    corto_object owner = corto_ownerof(e->data);

    /* If owner is a mount, object is being resumed */
    if (owner && corto_instanceof(corto_loader_o, owner)) {
        if (corto_loader(owner)->autoLoad) {
            corto_id id;
            if (corto_loadIntern(corto_fullpath(id, e->data), 0, NULL, FALSE, TRUE)) {
                corto_lasterr(); /* Ignore error */
            }
        }
    }

    corto_delete(e->observer); // Delete observer after first notification
}
/* $end */
int16_t _corto_package_construct(
    corto_package this)
{
/* $begin(corto/core/package/construct) */

    if (!corto_isBuiltinPackage(this) && corto_checkAttr(this, CORTO_ATTR_SCOPED)) {

        /* Load package after object has been defined. Create one-shot observer to
         * trigger on DEFINE event */
        if (!corto_observe(CORTO_ON_RESUME|CORTO_ON_SELF, this)
            .instance(this)
            .callback(corto_package_onDefine)) 
        {
            goto error;
        }
    }

    return 0;
error:
    return -1;
/* $end */
}

int16_t _corto_package_init(
    corto_package this)
{
/* $begin(corto/core/package/init) */
    this->managed = TRUE;
    return 0;
/* $end */
}
