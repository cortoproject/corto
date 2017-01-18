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

corto_int16 _corto_package_construct(
    corto_package this)
{
/* $begin(corto/core/package/construct) */

    if (!corto_isBuiltinPackage(this)) {
        if (corto_checkAttr(this, CORTO_ATTR_SCOPED)) {
            corto_object owner = corto_ownerof(this);

            /* If owner is a mount, object is already being resumed */
            if (owner && corto_instanceof(corto_loader_o, owner)) {
                corto_id id;
                corto_fullpath(id, this);

                if (corto_loadIntern(id, 0, NULL, FALSE, TRUE)) {
                    corto_lasterr(); /* Ignore error */
                }
            }
        }

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
    }

    return 0;
/* $end */
}
