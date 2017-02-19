/* $CORTO_GENERATED
 *
 * package.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/core/core.h>

/* $header() */
#include "_object.h"
/* $end */

/* $header(corto/core/package/construct) */
void corto_package_onDefine(
    corto_object instance,
    corto_eventMask mask,
    corto_object observable,
    corto_observer observer)
{
    corto_object owner = corto_ownerof(observable);

    CORTO_UNUSED(instance);
    CORTO_UNUSED(mask);
    CORTO_UNUSED(observable);
    CORTO_UNUSED(observer);

    /* If owner is a mount, object is being resumed */
    if (owner && corto_instanceof(corto_loader_o, owner)) {
        if (corto_loader(owner)->autoLoad) {
            corto_id id;
            if (corto_loadIntern(corto_fullpath(id, observable), 0, NULL, FALSE, TRUE)) {
                corto_lasterr(); /* Ignore error */
            }
        }
    }
}
/* $end */
corto_int16 _corto_package_construct(
    corto_package this)
{
/* $begin(corto/core/package/construct) */

    if (!corto_isBuiltinPackage(this) && corto_checkAttr(this, CORTO_ATTR_SCOPED)) {
        corto_id path;
        corto_string localPath;
        corto_path(path, root_o, this, "/");
        localPath = corto_envparse("$CORTO_HOME/lib/corto/%s.%s/%s",
          CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR,
          path);
        corto_cleanpath(localPath, localPath);
        if (corto_mkdir(localPath)) {
            corto_lasterr(); /* Mute uncatched error messages */
        }
        corto_dealloc(localPath);

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
