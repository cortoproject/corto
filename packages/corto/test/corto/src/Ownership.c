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
    corto_object observable)
{
/* $begin(test/Ownership/onDelete) */
    CORTO_UNUSED(this);
    this->observable = (corto_word)observable;
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
        "owner '/r' of existing object '/o' does not match"));

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
        "owner '/r' of existing object '/o' does not match"));

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
    test_assert(!strcmp(corto_lasterr(), "can't delete /o: not owned by thread (use corto_suspend)"));

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

    corto_listen(
        this,
        test_Ownership_onDelete_o,
        CORTO_ON_DELETE,
        o,
        NULL);

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

    corto_listen(
        this,
        test_Ownership_onDelete_o,
        CORTO_ON_DELETE,
        o,
        NULL);

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
