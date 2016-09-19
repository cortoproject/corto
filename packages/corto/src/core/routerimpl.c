/* $CORTO_GENERATED
 *
 * routerimpl.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/core/core.h>

/* $header(corto/core/routerimpl/construct) */
int corto_routerimpl_countArgs(corto_object o, void *userData) {
    if (corto_instanceof(corto_route_o, o)) {
        if (corto_routerimpl(userData)->maxArgs < corto_function(o)->parameters.length) {
            corto_routerimpl(userData)->maxArgs = corto_function(o)->parameters.length;
        }
    }
    return 1;
}
/* $end */
corto_int16 _corto_routerimpl_construct(
    corto_routerimpl this)
{
/* $begin(corto/core/routerimpl/construct) */
    corto_scopeWalk(this, corto_routerimpl_countArgs, this);
    return corto_class_construct(this);
/* $end */
}

corto_void _corto_routerimpl_destruct(
    corto_routerimpl this)
{
/* $begin(corto/core/routerimpl/destruct) */

    CORTO_UNUSED(this);

/* $end */
}
