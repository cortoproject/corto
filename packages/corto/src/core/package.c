/* $CORTO_GENERATED
 *
 * package.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/core/core.h>

corto_int16 _corto_package_construct(
    corto_package this)
{
/* $begin(corto/core/package/construct) */
    if (!corto_isBuiltinPackage(this)) {
        if (corto_checkAttr(this, CORTO_ATTR_SCOPED)) {
            corto_id id;
            corto_fullpath(id, this);

            if (corto_load(id, 0, NULL)) {
                corto_lasterr(); /* Ignore error */
            }
        }
    }

    return 0;
/* $end */
}
