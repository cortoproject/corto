/* This is a managed file. Do not delete this comment. */

#include <include/test.h>
void test_Ptr_tc_ptr_initDeinitReferenceType(
    test_Ptr this)
{
    test_Foo ptr;

    corto_ptr_init(&ptr, test_Foo_o);
    test_assert(ptr == NULL);

    corto_object dummy = corto_create(NULL, NULL, test_Foo_o);
    test_assert(dummy != NULL);
    test_assertint(corto_countof(dummy), 1);

    corto_set_ref(&ptr, dummy);
    test_assertint(corto_countof(dummy), 2);

    corto_ptr_deinit(&ptr, test_Foo_o);
    test_assertint(corto_countof(dummy), 1);
}

void test_Ptr_tc_ptr_newFreeReferenceType(
    test_Ptr this)
{
    test_assertint(*test_initCalled_o, 0);
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);

    /* Create new pointer to class type */
    void *ptr = corto_ptr_new(test_Foo_o);
    test_assert(ptr != NULL);

    test_assertint(*test_initCalled_o, 0);
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);

    corto_object dummy = corto_create(NULL, NULL, test_Foo_o);
    test_assert(dummy != NULL);
    test_assertint(corto_countof(dummy), 1);

    test_assertint(*test_initCalled_o, 1);
    test_assertint(*test_constructCalled_o, 1);
    test_assertint(*test_destructCalled_o, 0);

    /* Assign reference */
    corto_set_ref(ptr, dummy);
    test_assertint(corto_countof(dummy), 2);

    /* Free pointer */
    corto_ptr_free(ptr, test_Foo_o);

    test_assertint(corto_countof(dummy), 1);
    test_assert(corto_delete(dummy) == 0);
}
