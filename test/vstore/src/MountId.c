/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_MountId_tc_id(
    test_MountId this)
{
    test_IdMount m = test_IdMount__create(NULL, NULL, root_o, NULL);

    /* Create object & request id from mount */
    corto_object o = corto_declare(root_o, NULL, corto_void_o);
    test_assert(o != NULL);
    test_assertstr(corto_idof(o), "some_unique_id");
    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(m) == 0);

}

void test_MountId_tc_idForNested(
    test_MountId this)
{
    test_IdMount m = test_IdMount__create(NULL, NULL, root_o, NULL);

    /* Create object & request id from mount */
    corto_object p = corto_declare(root_o, "parent", corto_void_o);
    test_assert(p != NULL);

    corto_object o = corto_declare(root_o, NULL, corto_void_o);
    test_assert(o != NULL);
    test_assertstr(corto_idof(o), "some_unique_id");
    test_assert(corto_delete(p) == 0);
    test_assert(corto_delete(m) == 0);

}

void test_MountId_tc_idTypeFilter(
    test_MountId this)
{
    test_IdMount m = test_IdMount__create(NULL, NULL, root_o, corto_int32_o);

    /* Create object with a type that does not match the id mount */
    corto_object o = corto_declare(root_o, NULL, corto_float32_o);
    test_assert(o != NULL);

    /* Validate that this id was not obtained by IdMount */
    test_assert(strcmp(corto_idof(o), "some_unique_id"));
    corto_delete(o);

    o = corto_declare(root_o, NULL, corto_int32_o);
    test_assert(o != NULL);
    test_assertstr(corto_idof(o), "some_unique_id");
    test_assert(corto_delete(m) == 0);

}

void test_MountId_tc_noIdAvailable(
    test_MountId this)
{

    corto_object o = corto_declare(root_o, NULL, corto_void_o);
    test_assert(o != NULL);

    /* Validate that this id was not obtained by IdMount */
    test_assert(strcmp(corto_idof(o), "some_unique_id"));
    corto_delete(o);
    
}

