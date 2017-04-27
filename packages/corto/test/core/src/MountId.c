/* $CORTO_GENERATED
 *
 * MountId.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_MountId_tc_id(
    test_MountId this)
{
/* $begin(test/MountId/tc_id) */
    test_IdMount m = test_IdMountCreate(root_o, NULL);

    /* Create object & request id from mount */
    corto_object o = corto_declareChild(root_o, NULL, corto_void_o);
    test_assert(o != NULL);
    test_assertstr(corto_idof(o), "some_unique_id");
    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(m) == 0);

/* $end */
}

corto_void _test_MountId_tc_idForNested(
    test_MountId this)
{
/* $begin(test/MountId/tc_idForNested) */
    test_IdMount m = test_IdMountCreate(root_o, NULL);

    /* Create object & request id from mount */
    corto_object p = corto_declareChild(root_o, "parent", corto_void_o);
    test_assert(p != NULL);

    corto_object o = corto_declareChild(root_o, NULL, corto_void_o);
    test_assert(o != NULL);
    test_assertstr(corto_idof(o), "some_unique_id");
    test_assert(corto_delete(p) == 0);
    test_assert(corto_delete(m) == 0);

/* $end */
}

corto_void _test_MountId_tc_idTypeFilter(
    test_MountId this)
{
/* $begin(test/MountId/tc_idTypeFilter) */
    test_IdMount m = test_IdMountCreate(root_o, "int32");

    /* Create object with a type that does not match the id mount */
    corto_object o = corto_declareChild(root_o, NULL, corto_float32_o);
    test_assert(o != NULL);

    /* Validate that this id was not obtained by IdMount */
    test_assert(strcmp(corto_idof(o), "some_unique_id"));
    corto_delete(o);

    o = corto_declareChild(root_o, NULL, corto_int32_o);
    test_assert(o != NULL);
    test_assertstr(corto_idof(o), "some_unique_id");
    test_assert(corto_delete(m) == 0);

/* $end */
}

corto_void _test_MountId_tc_noIdAvailable(
    test_MountId this)
{
/* $begin(test/MountId/tc_noIdAvailable) */

    corto_object o = corto_declareChild(root_o, NULL, corto_void_o);
    test_assert(o != NULL);

    /* Validate that this id was not obtained by IdMount */
    test_assert(strcmp(corto_idof(o), "some_unique_id"));
    corto_delete(o);
    
/* $end */
}
