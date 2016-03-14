/* $CORTO_GENERATED
 *
 * TreeSinkReplicator.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "test.h"

corto_void _test_TreeSinkReplicator_setup(
    test_TreeSinkReplicator this)
{
/* $begin(test/TreeSinkReplicator/setup) */

    /* Create dummy object */
    corto_attr old = corto_setAttr(CORTO_ATTR_OBSERVABLE);
    corto_object a_o = corto_voidCreateChild(root_o, "a");
    corto_setAttr(old);

    /* Create replicator */
    this->replicator = test_ListReplicatorCreate(a_o, CORTO_ON_TREE, CORTO_SINK);

/* $end */
}

corto_void _test_TreeSinkReplicator_tc_resolveFromMount(
    test_TreeSinkReplicator this)
{
/* $begin(test/TreeSinkReplicator/tc_resolveFromMount) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_TreeSinkReplicator_tc_resolveFromNested(
    test_TreeSinkReplicator this)
{
/* $begin(test/TreeSinkReplicator/tc_resolveFromNested) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_TreeSinkReplicator_tc_selectFromNestedReal(
    test_TreeSinkReplicator this)
{
/* $begin(test/TreeSinkReplicator/tc_selectFromNestedReal) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_TreeSinkReplicator_tc_selectFromNestedVirtual(
    test_TreeSinkReplicator this)
{
/* $begin(test/TreeSinkReplicator/tc_selectFromNestedVirtual) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_TreeSinkReplicator_teardown(
    test_TreeSinkReplicator this)
{
/* $begin(test/TreeSinkReplicator/teardown) */

    /* << Insert implementation >> */

/* $end */
}
