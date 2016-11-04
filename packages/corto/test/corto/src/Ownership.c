/* $CORTO_GENERATED
 *
 * Ownership.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_void _test_Ownership_onDelete(
    test_Ownership this,
    corto_eventMask event,
    corto_object object,
    corto_observer observer)
{
/* $begin(test/Ownership/onDelete) */
    CORTO_UNUSED(this);
    this->observable = (corto_word)object;
/* $end */
}

corto_void _test_Ownership_setup(
    test_Ownership this)
{
/* $begin(test/Ownership/setup) */

/* $end */
}

corto_void _test_Ownership_tc_checkOwnerNull(
    test_Ownership this)
{
/* $begin(test/Ownership/tc_checkOwnerNull) */
    corto_object o = corto_voidCreateChild(NULL, "o");
    test_assert(o != NULL);
    test_assert(corto_ownerof(o) == NULL);

    corto_int16 result = corto_delete(o);
    test_assert(result == 0);

/* $end */
}

corto_void _test_Ownership_tc_checkOwnerReplicator(
    test_Ownership this)
{
/* $begin(test/Ownership/tc_checkOwnerReplicator) */
    test_FooReplicator r = test_FooReplicatorCreate(root_o);

    corto_object old = corto_setOwner(r);
    test_assert(old == NULL);

    corto_object o = corto_voidCreateChild(NULL, "o");
    test_assert(o != NULL);
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_ownerof(o) == r);

    corto_int16 result = corto_delete(o);
    test_assert(result == 0);

    corto_setOwner(old);

    result = corto_delete(r);
    test_assert(result == 0);

/* $end */
}

corto_void _test_Ownership_tc_createNotOwned(
    test_Ownership this)
{
/* $begin(test/Ownership/tc_createNotOwned) */
    test_FooReplicator r = test_FooReplicatorCreateChild(root_o, "r", root_o);

    corto_object old = corto_setOwner(r);
    test_assert(old == NULL);

    corto_object o = corto_voidCreateChild(NULL, "o");
    test_assert(o != NULL);
    test_assert(corto_ownerof(o) == r);

    old = corto_setOwner(NULL);
    test_assert(old == r);

    corto_object p = corto_voidCreateChild(NULL, "o");
    test_assert(p == NULL);
    test_assert(corto_lasterr() != NULL);
    test_assert(!strcmp(corto_lasterr(),
        "owner '/r' of existing object '/o' does not match owner ''"));

    /* Set owner back to r so we can delete o */
    corto_setOwner(r);

    corto_int16 result = corto_delete(o);
    test_assert(result == 0);

    /* Set owner back to NULL so we can delete r */
    corto_setOwner(NULL);

    result = corto_delete(r);
    test_assert(result == 0);

/* $end */
}

corto_void _test_Ownership_tc_createOwned(
    test_Ownership this)
{
/* $begin(test/Ownership/tc_createOwned) */
    test_FooReplicator r = test_FooReplicatorCreateChild(root_o, "r", root_o);

    corto_object old = corto_setOwner(r);
    test_assert(old == NULL);

    corto_object o = corto_voidCreateChild(NULL, "o");
    test_assert(o != NULL);
    test_assert(corto_ownerof(o) == r);

    corto_object p = corto_voidCreateChild(NULL, "o");
    test_assert(p != NULL);
    test_assert(p == o);
    test_assert(corto_ownerof(p) == r);

    corto_int16 result = corto_delete(o);
    test_assert(result == 0);

    result = corto_delete(p);
    test_assert(result == 0);

    corto_setOwner(NULL);

    result = corto_delete(r);
    test_assert(result == 0);

/* $end */
}

corto_void _test_Ownership_tc_declareNotOwned(
    test_Ownership this)
{
/* $begin(test/Ownership/tc_declareNotOwned) */
    test_FooReplicator r = test_FooReplicatorCreateChild(root_o, "r", root_o);

    corto_object old = corto_setOwner(r);
    test_assert(old == NULL);

    corto_object o = corto_voidCreateChild(NULL, "o");
    test_assert(o != NULL);
    test_assert(corto_ownerof(o) == r);

    old = corto_setOwner(NULL);
    test_assert(old == r);

    corto_object p = corto_declareChild(NULL, "o", corto_void_o);
    test_assert(p == NULL);
    test_assert(corto_lasterr() != NULL);
    test_assert(!strcmp(corto_lasterr(),
        "owner '/r' of existing object '/o' does not match owner ''"));

    corto_setOwner(old);

    corto_int16 result = corto_delete(o);
    test_assert(result == 0);

    corto_setOwner(NULL);

    result = corto_delete(r);
    test_assert(result == 0);

/* $end */
}

corto_void _test_Ownership_tc_declareOwned(
    test_Ownership this)
{
/* $begin(test/Ownership/tc_declareOwned) */
    test_FooReplicator r = test_FooReplicatorCreateChild(root_o, "r", root_o);

    corto_object old = corto_setOwner(r);
    test_assert(old == NULL);

    corto_object o = corto_voidCreateChild(NULL, "o");
    test_assert(o != NULL);
    test_assert(corto_ownerof(o) == r);

    corto_object p = corto_declareChild(NULL, "o", corto_void_o);
    test_assert(p != NULL);
    test_assert(p == o);
    test_assert(corto_ownerof(p) == r);

    corto_int16 result = corto_delete(o);
    test_assert(result == 0);

    corto_setOwner(NULL);

    result = corto_delete(r);
    test_assert(result == 0);

/* $end */
}

corto_void _test_Ownership_tc_deleteNotOwned(
    test_Ownership this)
{
/* $begin(test/Ownership/tc_deleteNotOwned) */
    test_FooReplicator r = test_FooReplicatorCreateChild(root_o, "r", root_o);

    corto_object old = corto_setOwner(r);
    test_assert(old == NULL);

    corto_object o = corto_voidCreateChild(NULL, "o");
    test_assert(o != NULL);
    test_assert(corto_ownerof(o) == r);

    corto_setOwner(NULL);

    corto_int16 result = corto_delete(o);
    test_assert(result != 0);
    test_assert(corto_lasterr() != NULL);
    test_assert(!strcmp(corto_lasterr(), "can't delete /o: not owned by thread (thread='' ((null)), object='/r' (/test/FooReplicator))"));

    result = corto_delete(r);
    test_assert(result == 0);

/* $end */
}

corto_void _test_Ownership_tc_deleteOwned(
    test_Ownership this)
{
/* $begin(test/Ownership/tc_deleteOwned) */
    test_FooReplicator r = test_FooReplicatorCreateChild(root_o, "r", root_o);

    corto_object old = corto_setOwner(r);
    test_assert(old == NULL);

    corto_object o = corto_voidCreateChild(NULL, "o");
    test_assert(o != NULL);
    test_assert(corto_ownerof(o) == r);

    corto_int16 result = corto_delete(o);
    test_assert(result == 0);

    corto_setOwner(NULL);

    result = corto_delete(r);
    test_assert(result == 0);

/* $end */
}

corto_void _test_Ownership_tc_invokeNotOwned(
    test_Ownership this)
{
/* $begin(test/Ownership/tc_invokeNotOwned) */
    test_FooReplicator r = test_FooReplicatorCreateChild(root_o, "r", root_o);

    corto_object old = corto_setOwner(r);
    test_assert(old == NULL);

    test_MethodForwardTest o = test_MethodForwardTestCreateChild(NULL, "o");
    test_assert(o != NULL);
    test_assert(corto_ownerof(o) == r);

    old = corto_setOwner(NULL);
    test_assert(old == r);

    corto_call(corto_function(test_MethodForwardTest_func_o), NULL, o);
    test_assert(o->invoked == 0);
    test_assert(r->invoked == 1);

    corto_setOwner(r);

    corto_int16 result = corto_delete(o);
    test_assert(result == 0);

    corto_setOwner(NULL);

    result = corto_delete(r);
    test_assert(result == 0);

/* $end */
}

corto_void _test_Ownership_tc_invokeOwned(
    test_Ownership this)
{
/* $begin(test/Ownership/tc_invokeOwned) */
    test_FooReplicator r = test_FooReplicatorCreateChild(root_o, "r", root_o);

    corto_object old = corto_setOwner(r);
    test_assert(old == NULL);

    test_MethodForwardTest o = test_MethodForwardTestCreateChild(NULL, "o");
    test_assert(o != NULL);
    test_assert(corto_ownerof(o) == r);

    /* Invoke method in context of mount. Nothing should happen */
    corto_call(corto_function(test_MethodForwardTest_func_o), NULL, o);
    test_assertint(o->invoked, 0);
    test_assertint(r->invoked, 0);

    corto_int16 result = corto_delete(o);
    test_assertint(result, 0);

    corto_setOwner(NULL);

    result = corto_delete(r);
    test_assert(result == 0);

/* $end */
}

corto_void _test_Ownership_tc_ownedMountMount(
    test_Ownership this)
{
/* $begin(test/Ownership/tc_ownedMountMount) */
    test_FooReplicator r1 = test_FooReplicatorCreateChild(root_o, "r1", root_o);
    test_FooReplicator r2 = test_FooReplicatorCreateChild(root_o, "r2", root_o);

    corto_object old = corto_setOwner(r1);
    test_assert(old == NULL);

    corto_int32 *o = corto_int32CreateChild(NULL, "o", 10);
    test_assert(o != NULL);
    test_assert(corto_ownerof(o) == r1);

    corto_setOwner(r2);
    test_assert(corto_owned(o) == FALSE);
    corto_setOwner(r1);

    corto_int16 result = corto_delete(o);
    test_assertint(result, 0);

    corto_setOwner(NULL);

    result = corto_delete(r1);
    test_assert(result == 0);

    result = corto_delete(r2);
    test_assert(result == 0);

/* $end */
}

corto_void _test_Ownership_tc_ownedMountMountSame(
    test_Ownership this)
{
/* $begin(test/Ownership/tc_ownedMountMountSame) */
    test_FooReplicator r1 = test_FooReplicatorCreateChild(root_o, "r1", root_o);

    corto_object old = corto_setOwner(r1);
    test_assert(old == NULL);

    corto_int32 *o = corto_int32CreateChild(NULL, "o", 10);
    test_assert(o != NULL);
    test_assert(corto_ownerof(o) == r1);

    test_assert(corto_owned(o) == TRUE);

    corto_int16 result = corto_delete(o);
    test_assertint(result, 0);

    corto_setOwner(NULL);

    result = corto_delete(r1);
    test_assert(result == 0);

/* $end */
}

corto_void _test_Ownership_tc_ownedMountObj(
    test_Ownership this)
{
/* $begin(test/Ownership/tc_ownedMountObj) */
    test_FooReplicator r1 = test_FooReplicatorCreateChild(root_o, "r1", root_o);

    corto_voidCreateChild_auto(NULL, obj);

    corto_object old = corto_setOwner(r1);
    test_assert(old == NULL);

    corto_int32 *o = corto_int32CreateChild(NULL, "o", 10);
    test_assert(o != NULL);
    test_assert(corto_ownerof(o) == r1);

    corto_setOwner(obj);
    test_assert(corto_owned(o) == FALSE);
    corto_setOwner(r1);

    corto_int16 result = corto_delete(o);
    test_assertint(result, 0);

    corto_setOwner(NULL);

    result = corto_delete(r1);
    test_assert(result == 0);

    result = corto_delete(obj);
    test_assert(result == 0);

/* $end */
}

corto_void _test_Ownership_tc_ownedMountSelf(
    test_Ownership this)
{
/* $begin(test/Ownership/tc_ownedMountSelf) */
    test_FooReplicator r1 = test_FooReplicatorCreateChild(root_o, "r1", root_o);

    corto_object old = corto_setOwner(r1);
    test_assert(old == NULL);

    corto_int32 *o = corto_int32CreateChild(NULL, "o", 10);
    test_assert(o != NULL);
    test_assert(corto_ownerof(o) == r1);

    corto_setOwner(NULL);
    test_assert(corto_owned(o) == FALSE);
    corto_setOwner(r1);

    corto_int16 result = corto_delete(o);
    test_assertint(result, 0);

    corto_setOwner(NULL);

    result = corto_delete(r1);
    test_assert(result == 0);

/* $end */
}

corto_void _test_Ownership_tc_ownedObjMount(
    test_Ownership this)
{
/* $begin(test/Ownership/tc_ownedObjMount) */
    test_FooReplicator r1 = test_FooReplicatorCreateChild(root_o, "r1", root_o);

    corto_voidCreateChild_auto(NULL, obj);

    corto_object old = corto_setOwner(obj);
    test_assert(old == NULL);

    corto_int32 *o = corto_int32CreateChild(NULL, "o", 10);
    test_assert(o != NULL);
    test_assert(corto_ownerof(o) == obj);

    corto_setOwner(r1);
    test_assert(corto_owned(o) == FALSE);
    corto_setOwner(obj);

    corto_int16 result = corto_delete(o);
    test_assertint(result, 0);

    corto_setOwner(NULL);

    result = corto_delete(r1);
    test_assert(result == 0);

    result = corto_delete(obj);
    test_assert(result == 0);

/* $end */
}

corto_void _test_Ownership_tc_ownedObjObj(
    test_Ownership this)
{
/* $begin(test/Ownership/tc_ownedObjObj) */
    corto_voidCreateChild_auto(NULL, obj1);
    corto_voidCreateChild_auto(NULL, obj2);

    corto_object old = corto_setOwner(obj1);
    test_assert(old == NULL);

    corto_int32 *o = corto_int32CreateChild(NULL, "o", 10);
    test_assert(o != NULL);
    test_assert(corto_ownerof(o) == obj1);

    corto_setOwner(obj2);
    test_assert(corto_owned(o) == TRUE);
    corto_setOwner(obj1);

    corto_int16 result = corto_delete(o);
    test_assertint(result, 0);

    corto_setOwner(NULL);

    result = corto_delete(obj1);
    test_assert(result == 0);

    result = corto_delete(obj2);
    test_assert(result == 0);

/* $end */
}

corto_void _test_Ownership_tc_ownedObjObjSame(
    test_Ownership this)
{
/* $begin(test/Ownership/tc_ownedObjObjSame) */
    corto_voidCreateChild_auto(NULL, obj1);

    corto_object old = corto_setOwner(obj1);
    test_assert(old == NULL);

    corto_int32 *o = corto_int32CreateChild(NULL, "o", 10);
    test_assert(o != NULL);
    test_assert(corto_ownerof(o) == obj1);

    test_assert(corto_owned(o) == TRUE);

    corto_int16 result = corto_delete(o);
    test_assertint(result, 0);

    corto_setOwner(NULL);

    result = corto_delete(obj1);
    test_assert(result == 0);

/* $end */
}

corto_void _test_Ownership_tc_ownedObjSelf(
    test_Ownership this)
{
/* $begin(test/Ownership/tc_ownedObjSelf) */
    corto_voidCreateChild_auto(NULL, obj1);

    corto_object old = corto_setOwner(obj1);
    test_assert(old == NULL);

    corto_int32 *o = corto_int32CreateChild(NULL, "o", 10);
    test_assert(o != NULL);
    test_assert(corto_ownerof(o) == obj1);

    old = corto_setOwner(NULL);
    test_assert(corto_owned(o) == TRUE);
    corto_setOwner(obj1);

    corto_int16 result = corto_delete(o);
    test_assertint(result, 0);

    corto_setOwner(NULL);

    result = corto_delete(obj1);
    test_assert(result == 0);

/* $end */
}

corto_void _test_Ownership_tc_ownedSelfMount(
    test_Ownership this)
{
/* $begin(test/Ownership/tc_ownedSelfMount) */
    test_FooReplicator r1 = test_FooReplicatorCreateChild(root_o, "r1", root_o);

    corto_int32 *o = corto_int32CreateChild(NULL, "o", 10);
    test_assert(o != NULL);
    test_assert(corto_ownerof(o) == NULL);

    corto_setOwner(r1);
    test_assert(corto_owned(o) == FALSE);
    corto_setOwner(NULL);

    corto_int16 result = corto_delete(o);
    test_assertint(result, 0);

    result = corto_delete(r1);
    test_assert(result == 0);

/* $end */
}

corto_void _test_Ownership_tc_ownedSelfObj(
    test_Ownership this)
{
/* $begin(test/Ownership/tc_ownedSelfObj) */
    corto_voidCreateChild_auto(NULL, obj1);

    corto_int32 *o = corto_int32CreateChild(NULL, "o", 10);
    test_assert(o != NULL);
    test_assert(corto_ownerof(o) == NULL);

    corto_setOwner(obj1);
    test_assert(corto_owned(o) == TRUE);
    corto_setOwner(NULL);

    corto_int16 result = corto_delete(o);
    test_assertint(result, 0);

    result = corto_delete(obj1);
    test_assert(result == 0);

/* $end */
}

corto_void _test_Ownership_tc_ownedSelfSelf(
    test_Ownership this)
{
/* $begin(test/Ownership/tc_ownedSelfSelf) */
    corto_int32 *o = corto_int32CreateChild(NULL, "o", 10);
    test_assert(o != NULL);
    test_assert(corto_ownerof(o) == NULL);

    test_assert(corto_owned(o) == TRUE);

    corto_int16 result = corto_delete(o);
    test_assertint(result, 0);

/* $end */
}

corto_void _test_Ownership_tc_releaseNotOwned(
    test_Ownership this)
{
/* $begin(test/Ownership/tc_releaseNotOwned) */
    test_FooReplicator r = test_FooReplicatorCreateChild(root_o, "r", root_o);

    /* Create an observable object to catch DELETE event */
    corto_setAttr(CORTO_ATTR_PERSISTENT | CORTO_ATTR_OBSERVABLE);

    corto_object old = corto_setOwner(r);
    test_assert(old == NULL);

    corto_object o = corto_voidCreateChild(NULL, "o");
    test_assert(o != NULL);
    test_assert(corto_ownerof(o) == r);

    corto_int16 ret = corto_observer_observe(test_Ownership_onDelete_o, this, o);
    test_assert(ret == 0);

    corto_int16 count = corto_release(o);
    test_assert(count == 0);
    test_assert(this->observable == 0);

    corto_setOwner(NULL);

    corto_int16 result = corto_delete(r);
    test_assert(result == 0);

/* $end */
}

corto_void _test_Ownership_tc_releaseOwned(
    test_Ownership this)
{
/* $begin(test/Ownership/tc_releaseOwned) */
    corto_object o = corto_voidCreateChild(NULL, "o");
    test_assert(o != NULL);
    test_assert(corto_ownerof(o) == NULL);

    corto_int16 ret = corto_observer_observe(test_Ownership_onDelete_o, this, o);
    test_assert(ret == 0);

    corto_int16 count = corto_release(o);

    test_assert(count == 0);
    test_assert(this->observable == 0);

/* $end */
}

corto_void _test_Ownership_tc_updateNotOwned(
    test_Ownership this)
{
/* $begin(test/Ownership/tc_updateNotOwned) */
    test_FooReplicator r = test_FooReplicatorCreateChild(root_o, "r", root_o);

    corto_object old = corto_setOwner(r);
    test_assert(old == NULL);

    corto_object o = corto_voidCreateChild(NULL, "o");
    test_assert(o != NULL);
    test_assert(corto_ownerof(o) == r);

    old = corto_setOwner(NULL);
    test_assert(old == r);

    corto_int16 result = corto_update(o);
    test_assert(result != 0);

    corto_setOwner(r);

    result = corto_delete(o);
    test_assert(result == 0);

    corto_setOwner(NULL);

    result = corto_delete(r);
    test_assert(result == 0);

/* $end */
}

corto_void _test_Ownership_tc_updateOwned(
    test_Ownership this)
{
/* $begin(test/Ownership/tc_updateOwned) */
    test_FooReplicator r = test_FooReplicatorCreateChild(root_o, "r", root_o);

    corto_object old = corto_setOwner(r);
    test_assert(old == NULL);

    corto_object o = corto_voidCreateChild(NULL, "o");
    test_assert(o != NULL);
    test_assert(corto_ownerof(o) == r);

    corto_int16 result = corto_update(o);
    test_assert(result == 0);

    result = corto_delete(o);
    test_assert(result == 0);

    corto_setOwner(NULL);

    result = corto_delete(r);
    test_assert(result == 0);

/* $end */
}
