/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_Ownership_onDelete(
    corto_observerEvent *e)
{
    test_Ownership this = e->instance;
    this->observable = (corto_word)e->data;
}

void test_Ownership_setup(
    test_Ownership this)
{

}

void test_Ownership_tc_checkOwnerNull(
    test_Ownership this)
{
    corto_object o = corto_void__create(root_o, "o");
    test_assert(o != NULL);
    test_assert(corto_sourceof(o) == NULL);

    corto_int16 result = corto_delete(o);
    test_assert(result == 0);

}

void test_Ownership_tc_checkOwnerReplicator(
    test_Ownership this)
{
    test_FooReplicator r = test_FooReplicator__create(NULL, NULL, root_o);

    corto_object old = corto_set_source(r);
    test_assert(old == NULL);

    corto_object o = corto_void__create(root_o, "o");
    test_assert(o != NULL);
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_sourceof(o) == r);

    corto_int16 result = corto_delete(o);
    test_assert(result == 0);

    corto_set_source(old);

    result = corto_delete(r);
    test_assert(result == 0);

}

void test_Ownership_tc_createOwned(
    test_Ownership this)
{
    test_FooReplicator r = test_FooReplicator__create(root_o, "r", root_o);

    corto_object old = corto_set_source(r);
    test_assert(old == NULL);

    corto_object o = corto_void__create(root_o, "o");
    test_assert(o != NULL);
    test_assert(corto_sourceof(o) == r);

    corto_object p = corto_void__create(root_o, "o");
    test_assert(p != NULL);
    test_assert(p == o);
    test_assert(corto_sourceof(p) == r);

    corto_int16 result = corto_delete(o);
    test_assert(result == 0);

    result = corto_delete(p);
    test_assert(result == 0);

    corto_set_source(NULL);

    result = corto_delete(r);
    test_assert(result == 0);

}

void test_Ownership_tc_declareOwned(
    test_Ownership this)
{
    test_FooReplicator r = test_FooReplicator__create(root_o, "r", root_o);

    corto_object old = corto_set_source(r);
    test_assert(old == NULL);

    corto_object o = corto_void__create(root_o, "o");
    test_assert(o != NULL);
    test_assert(corto_sourceof(o) == r);

    corto_object p = corto_declare(root_o, "o", corto_void_o);
    test_assert(p != NULL);
    test_assert(p == o);
    test_assert(corto_sourceof(p) == r);

    corto_int16 result = corto_delete(o);
    test_assert(result == 0);

    corto_set_source(NULL);

    result = corto_delete(r);
    test_assert(result == 0);

}

void test_Ownership_tc_deleteNotOwned(
    test_Ownership this)
{
    test_FooReplicator r = test_FooReplicator__create(root_o, "r", root_o);

    corto_object old = corto_set_source(r);
    test_assert(old == NULL);

    corto_object o = corto_void__create(root_o, "o");
    test_assert(o != NULL);
    test_assert(corto_sourceof(o) == r);

    corto_set_source(NULL);

    corto_int16 result = corto_delete(o);
    test_assert(result != 0);
    test_assert(corto_catch());

    result = corto_delete(r);
    test_assert(result == 0);

}

void test_Ownership_tc_deleteOwned(
    test_Ownership this)
{
    test_FooReplicator r = test_FooReplicator__create(root_o, "r", root_o);

    corto_object old = corto_set_source(r);
    test_assert(old == NULL);

    corto_object o = corto_void__create(root_o, "o");
    test_assert(o != NULL);
    test_assert(corto_sourceof(o) == r);

    corto_int16 result = corto_delete(o);
    test_assert(result == 0);

    corto_set_source(NULL);

    result = corto_delete(r);
    test_assert(result == 0);

}

void test_Ownership_tc_invokeNotOwned(
    test_Ownership this)
{
    test_FooReplicator r = test_FooReplicator__create(root_o, "r", root_o);

    corto_object old = corto_set_source(r);
    test_assert(old == NULL);

    test_MethodForwardTest o = test_MethodForwardTest__create(root_o, "o");
    test_assert(o != NULL);
    test_assert(corto_sourceof(o) == r);

    old = corto_set_source(NULL);
    test_assert(old == r);

    corto_invoke(corto_function(test_MethodForwardTest_func_o), NULL, o);
    test_assert(o->invoked == 0);
    test_assert(r->invoked == 1);

    corto_set_source(r);

    corto_int16 result = corto_delete(o);
    test_assert(result == 0);

    corto_set_source(NULL);

    result = corto_delete(r);
    test_assert(result == 0);

}

void test_Ownership_tc_invokeOwned(
    test_Ownership this)
{
    test_FooReplicator r = test_FooReplicator__create(root_o, "r", root_o);

    corto_object old = corto_set_source(r);
    test_assert(old == NULL);

    test_MethodForwardTest o = test_MethodForwardTest__create(root_o, "o");
    test_assert(o != NULL);
    test_assert(corto_sourceof(o) == r);

    /* Invoke method in context of mount. Nothing should happen */
    corto_invoke(corto_function(test_MethodForwardTest_func_o), NULL, o);
    test_assertint(o->invoked, 0);
    test_assertint(r->invoked, 0);

    corto_int16 result = corto_delete(o);
    test_assertint(result, 0);

    corto_set_source(NULL);

    result = corto_delete(r);
    test_assert(result == 0);

}

void test_Ownership_tc_ownedMountMount(
    test_Ownership this)
{
    test_FooReplicator r1 = test_FooReplicator__create(root_o, "r1", root_o);
    test_FooReplicator r2 = test_FooReplicator__create(root_o, "r2", root_o);

    corto_object old = corto_set_source(r1);
    test_assert(old == NULL);

    corto_int32 *o = corto_int32__create(root_o, "o", 10);
    test_assert(o != NULL);
    test_assert(corto_sourceof(o) == r1);

    corto_set_source(r2);
    test_assert(corto_owned(o) == FALSE);
    corto_set_source(r1);

    corto_int16 result = corto_delete(o);
    test_assertint(result, 0);

    corto_set_source(NULL);

    result = corto_delete(r1);
    test_assert(result == 0);

    result = corto_delete(r2);
    test_assert(result == 0);

}

void test_Ownership_tc_ownedMountMountSame(
    test_Ownership this)
{
    test_FooReplicator r1 = test_FooReplicator__create(root_o, "r1", root_o);

    corto_object old = corto_set_source(r1);
    test_assert(old == NULL);

    corto_int32 *o = corto_int32__create(root_o, "o", 10);
    test_assert(o != NULL);
    test_assert(corto_sourceof(o) == r1);

    test_assert(corto_owned(o) == TRUE);

    corto_int16 result = corto_delete(o);
    test_assertint(result, 0);

    corto_set_source(NULL);

    result = corto_delete(r1);
    test_assert(result == 0);

}

void test_Ownership_tc_ownedMountObj(
    test_Ownership this)
{
    test_FooReplicator r1 = test_FooReplicator__create(root_o, "r1", root_o);

    corto_void__create_auto(root_o, obj);

    corto_object old = corto_set_source(r1);
    test_assert(old == NULL);

    corto_int32 *o = corto_int32__create(root_o, "o", 10);
    test_assert(o != NULL);
    test_assert(corto_sourceof(o) == r1);

    corto_set_source(obj);
    test_assert(corto_owned(o) == FALSE);
    corto_set_source(r1);

    corto_int16 result = corto_delete(o);
    test_assertint(result, 0);

    corto_set_source(NULL);

    result = corto_delete(r1);
    test_assert(result == 0);

    result = corto_delete(obj);
    test_assert(result == 0);

}

void test_Ownership_tc_ownedMountSelf(
    test_Ownership this)
{
    test_FooReplicator r1 = test_FooReplicator__create(root_o, "r1", root_o);

    corto_object old = corto_set_source(r1);
    test_assert(old == NULL);

    corto_int32 *o = corto_int32__create(root_o, "o", 10);
    test_assert(o != NULL);
    test_assert(corto_sourceof(o) == r1);

    corto_set_source(NULL);
    test_assert(corto_owned(o) == FALSE);
    corto_set_source(r1);

    corto_int16 result = corto_delete(o);
    test_assertint(result, 0);

    corto_set_source(NULL);

    result = corto_delete(r1);
    test_assert(result == 0);

}

void test_Ownership_tc_ownedObjMount(
    test_Ownership this)
{
    test_FooReplicator r1 = test_FooReplicator__create(root_o, "r1", root_o);

    corto_void__create_auto(root_o, obj);

    corto_object old = corto_set_source(obj);
    test_assert(old == NULL);

    corto_int32 *o = corto_int32__create(root_o, "o", 10);
    test_assert(o != NULL);
    test_assert(corto_sourceof(o) == obj);

    corto_set_source(r1);
    test_assert(corto_owned(o) == FALSE);
    corto_set_source(obj);

    corto_int16 result = corto_delete(o);
    test_assertint(result, 0);

    corto_set_source(NULL);

    result = corto_delete(r1);
    test_assert(result == 0);

    result = corto_delete(obj);
    test_assert(result == 0);

}

void test_Ownership_tc_ownedObjObj(
    test_Ownership this)
{
    corto_void__create_auto(root_o, obj1);
    corto_void__create_auto(root_o, obj2);

    corto_object old = corto_set_source(obj1);
    test_assert(old == NULL);

    corto_int32 *o = corto_int32__create(root_o, "o", 10);
    test_assert(o != NULL);
    test_assert(corto_sourceof(o) == obj1);

    corto_set_source(obj2);
    test_assert(corto_owned(o) == TRUE);
    corto_set_source(obj1);

    corto_int16 result = corto_delete(o);
    test_assertint(result, 0);

    corto_set_source(NULL);

    result = corto_delete(obj1);
    test_assert(result == 0);

    result = corto_delete(obj2);
    test_assert(result == 0);

}

void test_Ownership_tc_ownedObjObjSame(
    test_Ownership this)
{
    corto_void__create_auto(root_o, obj1);

    corto_object old = corto_set_source(obj1);
    test_assert(old == NULL);

    corto_int32 *o = corto_int32__create(root_o, "o", 10);
    test_assert(o != NULL);
    test_assert(corto_sourceof(o) == obj1);

    test_assert(corto_owned(o) == TRUE);

    corto_int16 result = corto_delete(o);
    test_assertint(result, 0);

    corto_set_source(NULL);

    result = corto_delete(obj1);
    test_assert(result == 0);

}

void test_Ownership_tc_ownedObjSelf(
    test_Ownership this)
{
    corto_void__create_auto(root_o, obj1);

    corto_object old = corto_set_source(obj1);
    test_assert(old == NULL);

    corto_int32 *o = corto_int32__create(root_o, "o", 10);
    test_assert(o != NULL);
    test_assert(corto_sourceof(o) == obj1);

    old = corto_set_source(NULL);
    test_assert(corto_owned(o) == TRUE);
    corto_set_source(obj1);

    corto_int16 result = corto_delete(o);
    test_assertint(result, 0);

    corto_set_source(NULL);

    result = corto_delete(obj1);
    test_assert(result == 0);

}

void test_Ownership_tc_ownedSelfMount(
    test_Ownership this)
{
    test_FooReplicator r1 = test_FooReplicator__create(root_o, "r1", root_o);

    corto_int32 *o = corto_int32__create(root_o, "o", 10);
    test_assert(o != NULL);
    test_assert(corto_sourceof(o) == NULL);

    corto_set_source(r1);
    test_assert(corto_owned(o) == FALSE);
    corto_set_source(NULL);

    corto_int16 result = corto_delete(o);
    test_assertint(result, 0);

    result = corto_delete(r1);
    test_assert(result == 0);

}

void test_Ownership_tc_ownedSelfObj(
    test_Ownership this)
{
    corto_void__create_auto(root_o, obj1);

    corto_int32 *o = corto_int32__create(root_o, "o", 10);
    test_assert(o != NULL);
    test_assert(corto_sourceof(o) == NULL);

    corto_set_source(obj1);
    test_assert(corto_owned(o) == TRUE);
    corto_set_source(NULL);

    corto_int16 result = corto_delete(o);
    test_assertint(result, 0);

    result = corto_delete(obj1);
    test_assert(result == 0);

}

void test_Ownership_tc_ownedSelfSelf(
    test_Ownership this)
{
    corto_int32 *o = corto_int32__create(root_o, "o", 10);
    test_assert(o != NULL);
    test_assert(corto_sourceof(o) == NULL);

    test_assert(corto_owned(o) == TRUE);

    corto_int16 result = corto_delete(o);
    test_assertint(result, 0);

}

void test_Ownership_tc_releaseNotOwned(
    test_Ownership this)
{
    test_FooReplicator r = test_FooReplicator__create(root_o, "r", root_o);

    /* Create an observable object to catch DELETE event */
    corto_set_attr(CORTO_ATTR_PERSISTENT | CORTO_ATTR_OBSERVABLE);

    corto_object old = corto_set_source(r);
    test_assert(old == NULL);

    corto_object o = corto_void__create(root_o, "o");
    test_assert(o != NULL);
    test_assert(corto_sourceof(o) == r);

    corto_int16 ret = corto_observer_observe(test_Ownership_onDelete_o, this, o);
    test_assert(ret == 0);

    corto_int16 count = corto_release(o);
    test_assert(count == 0);
    test_assert(this->observable == 0);

    corto_set_source(NULL);

    corto_int16 result = corto_delete(r);
    test_assert(result == 0);

}

void test_Ownership_tc_releaseOwned(
    test_Ownership this)
{
    corto_object o = corto_void__create(root_o, "o");
    test_assert(o != NULL);
    test_assert(corto_sourceof(o) == NULL);

    corto_int16 ret = corto_observer_observe(test_Ownership_onDelete_o, this, o);
    test_assert(ret == 0);

    corto_int16 count = corto_release(o);

    test_assert(count == 0);
    test_assert(this->observable == 0);

}

void test_Ownership_tc_updateNotOwned(
    test_Ownership this)
{
    test_FooReplicator r = test_FooReplicator__create(root_o, "r", root_o);

    corto_object old = corto_set_source(r);
    test_assert(old == NULL);

    corto_object o = corto_void__create(root_o, "o");
    test_assert(o != NULL);
    test_assert(corto_sourceof(o) == r);

    old = corto_set_source(NULL);
    test_assert(old == r);

    corto_int16 result = corto_update(o);
    test_assert(result != 0);
    test_assert(corto_catch());

    corto_set_source(r);

    result = corto_delete(o);
    test_assert(result == 0);

    corto_set_source(NULL);

    result = corto_delete(r);
    test_assert(result == 0);

}

void test_Ownership_tc_updateNotOwnedTarget(
    test_Ownership this)
{
    corto_mount r = corto_create(NULL, NULL, corto_mount_o);

    corto_object old = corto_set_source(r);
    test_assert(old == NULL);

    corto_object o = corto_create(root_o, "o", test_ReferenceTargetMember_o);
    test_assert(o != NULL);
    test_assert(corto_sourceof(o) == r);

    old = corto_set_source(NULL);
    test_assert(old == r);

    /* Update doesn't fail because type contains target member */
    corto_int16 result = corto_update_begin(o);
    test_assert(result == 0);

    result = corto_update_end(o);
    test_assert(result == 0);

    corto_set_source(r);

    result = corto_delete(o);
    test_assert(result == 0);

    corto_set_source(NULL);

    result = corto_delete(r);
    test_assert(result == 0);

}

void test_Ownership_tc_updateOwned(
    test_Ownership this)
{
    test_FooReplicator r = test_FooReplicator__create(root_o, "r", root_o);

    corto_object old = corto_set_source(r);
    test_assert(old == NULL);

    corto_object o = corto_void__create(root_o, "o");
    test_assert(o != NULL);
    test_assert(corto_sourceof(o) == r);

    corto_int16 result = corto_update(o);
    test_assert(result == 0);

    result = corto_delete(o);
    test_assert(result == 0);

    corto_set_source(NULL);

    result = corto_delete(r);
    test_assert(result == 0);

}
