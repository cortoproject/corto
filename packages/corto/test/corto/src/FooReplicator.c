/* $CORTO_GENERATED
 *
 * FooReplicator.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_FooReplicator_onInvoke(
    test_FooReplicator this,
    corto_object instance,
    corto_function proc,
    corto_word argptrs)
{
/* $begin(test/FooReplicator/onInvoke) */
    CORTO_UNUSED(instance);
    CORTO_UNUSED(proc);
    CORTO_UNUSED(argptrs);

    this->invoked ++;

/* $end */
}
