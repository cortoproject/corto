/* $CORTO_GENERATED
 *
 * ResumeSink.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

void _test_ResumeSink_onDeclare(
    corto_observerEvent *e)
{
/* $begin(test/ResumeSink/onDeclare) */
    test_ResumeSink this = e->instance;
    this->declared ++;

/* $end */
}

void _test_ResumeSink_onDefine(
    corto_observerEvent *e)
{
/* $begin(test/ResumeSink/onDefine) */
    test_ResumeSink this = e->instance;
    this->defined ++;

/* $end */
}

void _test_ResumeSink_onDelete(
    corto_observerEvent *e)
{
/* $begin(test/ResumeSink/onDelete) */
    test_ResumeSink this = e->instance;
    this->deleted ++;

/* $end */
}

void _test_ResumeSink_onResume(
    corto_observerEvent *e)
{
/* $begin(test/ResumeSink/onResume) */
    test_ResumeSink this = e->instance;
    this->resumed ++;

/* $end */
}

void _test_ResumeSink_onSuspend(
    corto_observerEvent *e)
{
/* $begin(test/ResumeSink/onSuspend) */
    test_ResumeSink this = e->instance;
    this->suspended ++;

/* $end */
}

void _test_ResumeSink_onUpdate(
    corto_observerEvent *e)
{
/* $begin(test/ResumeSink/onUpdate) */
    test_ResumeSink this = e->instance;
    this->updated ++;

/* $end */
}

void _test_ResumeSink_setup(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/setup) */
    /* Register sink mount */
    corto_voidCreateChild_auto(root_o, mount);
    test_SinkMountCreateChild_auto(root_o, sinkMount, mount, "test/Foo", "{10, 20}");

    CORTO_DEBUG_ENABLED = 1;

    /* Setup observers */
    corto_observer_observe(test_ResumeSink_onDeclare_o, this, mount);
    corto_observer_observe(test_ResumeSink_onDefine_o, this, mount);
    corto_observer_observe(test_ResumeSink_onDelete_o, this, mount);
    corto_observer_observe(test_ResumeSink_onUpdate_o, this, mount);
    corto_observer_observe(test_ResumeSink_onResume_o, this, mount);
    corto_observer_observe(test_ResumeSink_onSuspend_o, this, mount);

/* $end */
}

void _test_ResumeSink_tc_cleanupParentFromResumedChild(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_cleanupParentFromResumedChild) */

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMountCreate("/vmount");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_createChild(root_o, "vmount", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object k = corto_lookup(vmount, "x/a/k");
    test_assert(k != NULL);
    test_assertstr(corto_fullpath(NULL, k), "/vmount/x/a/k");
    test_assert(corto_typeof(k) == (corto_type)corto_int32_o);
    test_assertint(corto_countof(k), 1);

    corto_object a = corto_parentof(k);
    test_assert(a != NULL);
    test_assertstr(corto_fullpath(NULL, a), "/vmount/x/a");
    test_assert(corto_typeof(a) == (corto_type)corto_float32_o);
    test_assertint(corto_countof(a), 1);

    corto_object x = corto_parentof(a);
    test_assert(x != NULL);
    test_assertstr(corto_fullpath(NULL, x), "/vmount/x");
    test_assert(corto_typeof(x) == (corto_type)corto_int32_o);
    test_assertint(corto_countof(x), 1);

    test_assert(corto_delete(k) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

/* $end */
}

void _test_ResumeSink_tc_define(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_define) */
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_object mount = corto_resolve(root_o, "mount");
    test_assert(mount != NULL);

    corto_object sinkMount = corto_resolve(root_o, "sinkMount");
    test_assert(sinkMount != NULL);

    test_Foo o = test_FooCreateChild(mount, "x", 0, 0);
    test_assert(o != NULL);
    test_assert(corto_parentof(o) == mount);
    test_assert(corto_typeof(o) == corto_type(test_Foo_o));
    test_assert(corto_ownerof(o) == sinkMount);
    test_assert(corto_checkState(o, CORTO_DEFINED | CORTO_DECLARED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    test_assertint(this->declared, 1);
    test_assertint(this->defined, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 1);
    test_assertint(this->suspended, 0);

    test_assertint(*test_constructCalled_o, 1);
    test_assertint(*test_destructCalled_o, 0);

    /* Foo constructor modifies members */
    test_assertint(o->x, 20);
    test_assertint(o->y, 40);

    /* This should remove o from the store and "suspend" it to the sink */
    corto_release(o);

    /* No define notification should have been generated. An object was inserted into
     * the store, but since it was a suspended object, its lifecycle didn't
     * change. */
    test_assertint(this->declared, 1);
    test_assertint(this->defined, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->resumed, 1);
    test_assertint(this->suspended, 1);

    test_assertint(*test_constructCalled_o, 1);
    test_assertint(*test_destructCalled_o, 1);

    corto_release(mount);
    corto_release(sinkMount);

/* $end */
}

void _test_ResumeSink_tc_defineFromNestedVirtualMountPoint(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_defineFromNestedVirtualMountPoint) */

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMountCreate("/vmount/nested");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_createChild(root_o, "vmount/nested", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object o = corto_createChild(vmount, "x", corto_int32_o);
    test_assert(o != NULL);
    test_assertstr(corto_fullpath(NULL, o), "/vmount/nested/x");
    test_assert(corto_ownerof(o) == mount);

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

/* $end */
}

void _test_ResumeSink_tc_defineFromVirtualMountPoint(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_defineFromVirtualMountPoint) */

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMountCreate("/vmount");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_createChild(root_o, "vmount", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object o = corto_createChild(vmount, "x", corto_int32_o);
    test_assert(o != NULL);
    test_assertstr(corto_fullpath(NULL, o), "/vmount/x");
    test_assert(corto_ownerof(o) == mount);

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

/* $end */
}

void _test_ResumeSink_tc_defineMismatchingTypeFromVirtualMountPoint(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_defineMismatchingTypeFromVirtualMountPoint) */

    /* << Insert implementation >> */

/* $end */
}

void _test_ResumeSink_tc_defineMismatchingTypeNested1FromVirtualMountPoint(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_defineMismatchingTypeNested1FromVirtualMountPoint) */

    /* << Insert implementation >> */

/* $end */
}

void _test_ResumeSink_tc_defineMismatchingTypeNested2FromVirtualMountPoint(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_defineMismatchingTypeNested2FromVirtualMountPoint) */

    /* << Insert implementation >> */

/* $end */
}

void _test_ResumeSink_tc_defineNested1(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_defineNested1) */
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_object parent = corto_resolve(root_o, "mount/x");
    test_assert(parent != NULL);

    test_assertint(this->declared, 1);
    test_assertint(this->defined, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 1);
    test_assertint(this->suspended, 0);

    test_assertint(*test_constructCalled_o, 1);
    test_assertint(*test_destructCalled_o, 0);

    corto_object sinkMount = corto_resolve(root_o, "sinkMount");
    test_assert(sinkMount != NULL);

    test_Foo o = test_FooCreateChild(parent, "a", 0, 0);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_Foo_o));
    test_assert(corto_ownerof(o) == sinkMount);
    test_assert(corto_checkState(o, CORTO_DEFINED | CORTO_DECLARED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    test_assertint(this->declared, 2);
    test_assertint(this->defined, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 2);
    test_assertint(this->suspended, 0);

    test_assertint(*test_constructCalled_o, 2);
    test_assertint(*test_destructCalled_o, 0);

    /* Foo constructor modifies members */
    test_assertint(o->x, 20);
    test_assertint(o->y, 40);

    /* This should remove o from the store and "suspend" it to the sink */
    corto_release(o);
    corto_release(parent);

    /* No define notification should have been generated. An object was inserted into
     * the store, but since it was a suspended object, its lifecycle didn't
     * change. */
    test_assertint(this->declared, 2);
    test_assertint(this->defined, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->resumed, 2);
    test_assertint(this->suspended, 2);

    test_assertint(*test_constructCalled_o, 2);
    test_assertint(*test_destructCalled_o, 2);

    corto_release(sinkMount);

/* $end */
}

void _test_ResumeSink_tc_defineNested1FromNestedVirtualMountPoint(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_defineNested1FromNestedVirtualMountPoint) */

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMountCreate("/vmount/nested");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_createChild(root_o, "vmount/nested", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object a = corto_createChild(vmount, "x/a", corto_float32_o);
    test_assert(a != NULL);
    test_assertstr(corto_fullpath(NULL, a), "/vmount/nested/x/a");
    test_assert(corto_ownerof(a) == mount);
    test_assert(corto_typeof(a) == (corto_type)corto_float32_o);

    corto_object x = corto_parentof(a);
    test_assert(x != NULL);
    test_assertstr(corto_fullpath(NULL, x), "/vmount/nested/x");
    test_assert(corto_ownerof(x) == mount);
    test_assert(corto_typeof(x) == (corto_type)corto_int32_o);

    test_assert(corto_delete(a) == 0);
    test_assert(corto_delete(x) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

/* $end */
}

void _test_ResumeSink_tc_defineNested1FromVirtualMountPoint(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_defineNested1FromVirtualMountPoint) */

    /* << Insert implementation >> */

/* $end */
}

void _test_ResumeSink_tc_defineNested2(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_defineNested2) */
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_object parent = corto_resolve(root_o, "mount/x/a");
    test_assert(parent != NULL);

    test_assertint(this->declared, 2);
    test_assertint(this->defined, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 2);
    test_assertint(this->suspended, 0);

    test_assertint(*test_constructCalled_o, 2);
    test_assertint(*test_destructCalled_o, 0);

    corto_object sinkMount = corto_resolve(root_o, "sinkMount");
    test_assert(sinkMount != NULL);

    test_Foo o = test_FooCreateChild(parent, "k", 0, 0);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_Foo_o));
    test_assert(corto_ownerof(o) == sinkMount);
    test_assert(corto_checkState(o, CORTO_DEFINED | CORTO_DECLARED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    test_assertint(this->declared, 3);
    test_assertint(this->defined, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 3);
    test_assertint(this->suspended, 0);

    test_assertint(*test_constructCalled_o, 3);
    test_assertint(*test_destructCalled_o, 0);

    /* Foo constructor modifies members */
    test_assertint(o->x, 20);
    test_assertint(o->y, 40);

    /* This should remove o from the store and "suspend" it to the sink */
    corto_release(o);
    corto_release(parent);

    /* No define notification should have been generated. An object was inserted into
     * the store, but since it was a suspended object, its lifecycle didn't
     * change. */
    test_assertint(this->declared, 3);
    test_assertint(this->defined, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->resumed, 3);
    test_assertint(this->suspended, 3);

    test_assertint(*test_constructCalled_o, 3);
    test_assertint(*test_destructCalled_o, 3);

    corto_release(sinkMount);

/* $end */
}

void _test_ResumeSink_tc_defineNested2FromNestedVirtualMountPoint(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_defineNested2FromNestedVirtualMountPoint) */

    /* << Insert implementation >> */

/* $end */
}

void _test_ResumeSink_tc_defineNested2FromVirtualMountPoint(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_defineNested2FromVirtualMountPoint) */

    /* << Insert implementation >> */

/* $end */
}

void _test_ResumeSink_tc_lookup(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_lookup) */
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_object sinkMount = corto_lookup(root_o, "sinkMount");
    test_assert(sinkMount != NULL);

    test_Foo o = corto_lookup(root_o, "mount/x");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_Foo_o));
    test_assert(corto_ownerof(o) == sinkMount);
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    test_assertint(*test_constructCalled_o, 1);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 1);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 1);
    test_assertint(this->suspended, 0);

    /* Foo constructor modifies members */
    test_assertint(o->x, 20);
    test_assertint(o->y, 40);

    /* This should remove o from the store and "suspend" it to the sink */
    corto_release(o);
    corto_release(sinkMount);

    test_assertint(*test_constructCalled_o, 1);
    test_assertint(*test_destructCalled_o, 1);
    test_assertint(this->declared, 1);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 1);
    test_assertint(this->suspended, 1);

/* $end */
}

void _test_ResumeSink_tc_lookupFromMount(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_lookupFromMount) */
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_object sinkMount = corto_lookup(root_o, "sinkMount");
    test_assert(sinkMount != NULL);

    corto_object mount = corto_lookup(root_o, "mount");
    test_assert(mount != NULL);

    test_Foo o = corto_lookup(mount, "x");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_Foo_o));
    test_assert(corto_ownerof(o) == sinkMount);
    test_assert(corto_checkState(o, CORTO_DEFINED | CORTO_DECLARED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    test_assertint(*test_constructCalled_o, 1);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 1);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 1);
    test_assertint(this->suspended, 0);

    /* Foo constructor modifies members */
    test_assert(o->x == 20);
    test_assert(o->y == 40);

    /* This should remove o from the store and "suspend" it to the sink */
    corto_release(o);
    corto_release(sinkMount);
    corto_release(mount);

    test_assertint(*test_constructCalled_o, 1);
    test_assertint(*test_destructCalled_o, 1);
    test_assertint(this->declared, 1);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 1);
    test_assertint(this->suspended, 1);

/* $end */
}

void _test_ResumeSink_tc_lookupFromNestedVirtualMountPoint(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_lookupFromNestedVirtualMountPoint) */

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMountCreate("/vmount/nested");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_createChild(root_o, "vmount/nested", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object o = corto_lookup(vmount, "x");
    test_assert(o != NULL);
    test_assertstr(corto_fullpath(NULL, o), "/vmount/nested/x");

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

/* $end */
}

void _test_ResumeSink_tc_lookupFromVirtualMountPoint(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_lookupFromVirtualMountPoint) */

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMountCreate("/vmount");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_createChild(root_o, "vmount", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object o = corto_lookup(vmount, "x");
    test_assert(o != NULL);
    test_assertstr(corto_fullpath(NULL, o), "/vmount/x");

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

/* $end */
}

void _test_ResumeSink_tc_lookupNested1(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_lookupNested1) */
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_object sinkMount = corto_lookup(root_o, "sinkMount");
    test_assert(sinkMount != NULL);

    test_Foo o = corto_lookup(root_o, "mount/x/a");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_Foo_o));
    test_assert(corto_ownerof(o) == sinkMount);
    test_assert(corto_checkState(o, CORTO_DEFINED | CORTO_DECLARED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    test_assertint(*test_constructCalled_o, 2);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 2);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 2);
    test_assertint(this->suspended, 0);

    /* Foo constructor modifies members */
    test_assert(o->x == 20);
    test_assert(o->y == 40);

    /* This should remove o from the store and "suspend" it to the sink */
    corto_release(o);
    corto_release(sinkMount);

    test_assertint(*test_constructCalled_o, 2);
    test_assertint(*test_destructCalled_o, 2);
    test_assertint(this->declared, 2);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 2);
    test_assertint(this->suspended, 2);

/* $end */
}

void _test_ResumeSink_tc_lookupNested1FromMount(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_lookupNested1FromMount) */
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_object sinkMount = corto_lookup(root_o, "sinkMount");
    test_assert(sinkMount != NULL);

    corto_object mount = corto_lookup(root_o, "mount");
    test_assert(mount != NULL);

    test_Foo o = corto_lookup(mount, "x/a");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_Foo_o));
    test_assert(corto_ownerof(o) == sinkMount);
    test_assert(corto_checkState(o, CORTO_DEFINED | CORTO_DECLARED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    test_assertint(*test_constructCalled_o, 2);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 2);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 2);
    test_assertint(this->suspended, 0);

    /* Foo constructor modifies values */
    test_assert(o->x == 20);
    test_assert(o->y == 40);

    /* This should remove o from the store and "suspend" it to the sink */
    corto_release(o);
    corto_release(sinkMount);
    corto_release(mount);

    test_assertint(*test_constructCalled_o, 2);
    test_assertint(*test_destructCalled_o, 2);
    test_assertint(this->declared, 2);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 2);
    test_assertint(this->suspended, 2);

/* $end */
}

void _test_ResumeSink_tc_lookupNested1FromNestedVirtualMountPoint(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_lookupNested1FromNestedVirtualMountPoint) */

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMountCreate("/vmount/nested");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_createChild(root_o, "vmount/nested", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object a = corto_lookup(vmount, "x/a");
    test_assert(a != NULL);
    test_assertstr(corto_fullpath(NULL, a), "/vmount/nested/x/a");
    test_assert(corto_typeof(a) == (corto_type)corto_float32_o);

    corto_object x = corto_parentof(a);
    test_assert(x != NULL);
    test_assertstr(corto_fullpath(NULL, x), "/vmount/nested/x");
    test_assert(corto_typeof(x) == (corto_type)corto_int32_o);

    test_assert(corto_delete(a) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

/* $end */
}

void _test_ResumeSink_tc_lookupNested1FromObjectFromMount(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_lookupNested1FromObjectFromMount) */

    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_object sinkMount = corto_lookup(root_o, "sinkMount");
    test_assert(sinkMount != NULL);

    corto_object mount = corto_lookup(root_o, "mount");
    test_assert(mount != NULL);

    corto_object x = corto_lookup(mount, "x");
    test_assert(x != NULL);

    test_assertint(*test_constructCalled_o, 1);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 1);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 1);
    test_assertint(this->suspended, 0);

    test_Foo o = corto_lookup(x, "a");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_Foo_o));
    test_assert(corto_ownerof(o) == sinkMount);
    test_assert(corto_checkState(o, CORTO_DEFINED | CORTO_DECLARED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    test_assertint(*test_constructCalled_o, 2);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 2);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 2);
    test_assertint(this->suspended, 0);

    test_assert(o->x == 20);
    test_assert(o->y == 40);

    /* This should remove o from the store and "suspend" it to the sink */
    corto_release(o);
    corto_release(x);
    corto_release(sinkMount);
    corto_release(mount);

    test_assertint(*test_constructCalled_o, 2);
    test_assertint(*test_destructCalled_o, 2);
    test_assertint(this->declared, 2);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 2);
    test_assertint(this->suspended, 2);

/* $end */
}

void _test_ResumeSink_tc_lookupNested1FromVirtualMountPoint(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_lookupNested1FromVirtualMountPoint) */

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMountCreate("/vmount");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_createChild(root_o, "vmount", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object o = corto_lookup(vmount, "x/a");
    test_assert(o != NULL);
    test_assertstr(corto_fullpath(NULL, o), "/vmount/x/a");

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

/* $end */
}

void _test_ResumeSink_tc_lookupNested1NotExist(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_lookupNested1NotExist) */
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_object sinkMount = corto_lookup(root_o, "sinkMount");
    test_assert(sinkMount != NULL);

    test_Foo o = corto_lookup(root_o, "mount/x/notexists");
    test_assert(o == NULL);

    /* x is resumed and suspended */
    test_assertint(*test_constructCalled_o, 1);
    test_assertint(*test_destructCalled_o, 1);
    test_assertint(this->declared, 1);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 1);
    test_assertint(this->suspended, 1);

    corto_release(sinkMount);

/* $end */
}

void _test_ResumeSink_tc_lookupNested2(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_lookupNested2) */
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_object sinkMount = corto_lookup(root_o, "sinkMount");
    test_assert(sinkMount != NULL);

    test_Foo o = corto_lookup(root_o, "mount/x/a/k");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_Foo_o));
    test_assert(corto_ownerof(o) == sinkMount);
    test_assert(corto_checkState(o, CORTO_DEFINED | CORTO_DECLARED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    test_assertint(*test_constructCalled_o, 3);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 3);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 3);
    test_assertint(this->suspended, 0);

    /* Foo constructor modifies members */
    test_assert(o->x == 20);
    test_assert(o->y == 40);

    /* This should remove o from the store and "suspend" it to the sink */
    corto_release(o);
    corto_release(sinkMount);

    test_assertint(*test_constructCalled_o, 3);
    test_assertint(*test_destructCalled_o, 3);
    test_assertint(this->declared, 3);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 3);
    test_assertint(this->suspended, 3);

/* $end */
}

void _test_ResumeSink_tc_lookupNested2FromMount(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_lookupNested2FromMount) */
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_object sinkMount = corto_lookup(root_o, "sinkMount");
    test_assert(sinkMount != NULL);

    corto_object mount = corto_lookup(root_o, "mount");
    test_assert(mount != NULL);

    test_Foo o = corto_lookup(mount, "x/a/k");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_Foo_o));
    test_assert(corto_ownerof(o) == sinkMount);
    test_assert(corto_checkState(o, CORTO_DEFINED | CORTO_DECLARED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    test_assertint(*test_constructCalled_o, 3);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 3);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 3);
    test_assertint(this->suspended, 0);

    /* Foo constructor modifies members */
    test_assert(o->x == 20);
    test_assert(o->y == 40);

    /* This should remove o from the store and "suspend" it to the sink */
    corto_release(o);
    corto_release(sinkMount);
    corto_release(mount);

    test_assertint(*test_constructCalled_o, 3);
    test_assertint(*test_destructCalled_o, 3);
    test_assertint(this->declared, 3);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 3);
    test_assertint(this->suspended, 3);

/* $end */
}

void _test_ResumeSink_tc_lookupNested2FromNestedVirtualMountPoint(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_lookupNested2FromNestedVirtualMountPoint) */

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMountCreate("/vmount/nested");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_createChild(root_o, "vmount/nested", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object k = corto_lookup(vmount, "x/a/k");
    test_assert(k != NULL);
    test_assertstr(corto_fullpath(NULL, k), "/vmount/nested/x/a/k");
    test_assert(corto_typeof(k) == (corto_type)corto_int32_o);

    corto_object a = corto_lookup(vmount, "x/a");
    test_assert(a != NULL);
    test_assertstr(corto_fullpath(NULL, a), "/vmount/nested/x/a");
    test_assert(corto_typeof(a) == (corto_type)corto_float32_o);

    corto_object x = corto_parentof(a);
    test_assert(x != NULL);
    test_assertstr(corto_fullpath(NULL, x), "/vmount/nested/x");
    test_assert(corto_typeof(x) == (corto_type)corto_int32_o);

    test_assert(corto_delete(k) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

/* $end */
}

void _test_ResumeSink_tc_lookupNested2FromObjectFromMount(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_lookupNested2FromObjectFromMount) */

    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_object sinkMount = corto_lookup(root_o, "sinkMount");
    test_assert(sinkMount != NULL);

    corto_object mount = corto_lookup(root_o, "mount");
    test_assert(mount != NULL);

    corto_object x = corto_lookup(mount, "x");
    test_assert(x != NULL);

    test_assertint(*test_constructCalled_o, 1);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 1);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 1);
    test_assertint(this->suspended, 0);

    corto_object a = corto_lookup(x, "a");
    test_assert(a != NULL);

    test_assertint(*test_constructCalled_o, 2);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 2);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 2);
    test_assertint(this->suspended, 0);

    test_Foo o = corto_lookup(a, "k");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_Foo_o));
    test_assert(corto_ownerof(o) == sinkMount);
    test_assert(corto_checkState(o, CORTO_DEFINED | CORTO_DECLARED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    test_assertint(*test_constructCalled_o, 3);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 3);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 3);
    test_assertint(this->suspended, 0);

    /* Foo constructor modifies members */
    test_assert(o->x == 20);
    test_assert(o->y == 40);

    /* This should remove o from the store and "suspend" it to the sink */
    corto_release(o);
    corto_release(a);
    corto_release(x);
    corto_release(sinkMount);
    corto_release(mount);

    test_assertint(*test_constructCalled_o, 3);
    test_assertint(*test_destructCalled_o, 3);
    test_assertint(this->declared, 3);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 3);
    test_assertint(this->suspended, 3);

/* $end */
}

void _test_ResumeSink_tc_lookupNested2FromVirtualMountPoint(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_lookupNested2FromVirtualMountPoint) */

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMountCreate("/vmount");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_createChild(root_o, "vmount", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object k = corto_lookup(vmount, "x/a/k");
    test_assert(k != NULL);
    test_assertstr(corto_fullpath(NULL, k), "/vmount/x/a/k");
    test_assert(corto_typeof(k) == (corto_type)corto_int32_o);

    corto_object a = corto_parentof(k);
    test_assert(a != NULL);
    test_assertstr(corto_fullpath(NULL, a), "/vmount/x/a");
    test_assert(corto_typeof(a) == (corto_type)corto_float32_o);

    corto_object x = corto_parentof(a);
    test_assert(x != NULL);
    test_assertstr(corto_fullpath(NULL, x), "/vmount/x");
    test_assert(corto_typeof(x) == (corto_type)corto_int32_o);

    test_assert(corto_delete(k) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

/* $end */
}

void _test_ResumeSink_tc_lookupNested2NotExist(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_lookupNested2NotExist) */
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_object sinkMount = corto_lookup(root_o, "sinkMount");
    test_assert(sinkMount != NULL);

    test_Foo o = corto_lookup(root_o, "mount/x/a/notexists");
    test_assert(o == NULL);

    /* x is resumed and suspended */
    test_assertint(*test_constructCalled_o, 2);
    test_assertint(*test_destructCalled_o, 2);
    test_assertint(this->declared, 2);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 2);
    test_assertint(this->suspended, 2);

    corto_release(sinkMount);

/* $end */
}

void _test_ResumeSink_tc_lookupNotExist(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_lookupNotExist) */
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_object sinkMount = corto_lookup(root_o, "sinkMount");
    test_assert(sinkMount != NULL);

    test_Foo o = corto_lookup(root_o, "mount/notexists");
    test_assert(o == NULL);

    /* x is resumed and suspended */
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_release(sinkMount);

/* $end */
}

void _test_ResumeSink_tc_resolve(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_resolve) */
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_object sinkMount = corto_resolve(root_o, "sinkMount");
    test_assert(sinkMount != NULL);

    test_Foo o = corto_resolve(root_o, "mount/x");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_Foo_o));
    test_assert(corto_ownerof(o) == sinkMount);
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    test_assertint(*test_constructCalled_o, 1);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 1);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 1);
    test_assertint(this->suspended, 0);

    /* Foo constructor modifies members */
    test_assertint(o->x, 20);
    test_assertint(o->y, 40);

    /* This should remove o from the store and "suspend" it to the sink */
    corto_release(o);
    corto_release(sinkMount);

    test_assertint(*test_constructCalled_o, 1);
    test_assertint(*test_destructCalled_o, 1);
    test_assertint(this->declared, 1);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 1);
    test_assertint(this->suspended, 1);

/* $end */
}

void _test_ResumeSink_tc_resolveFromMount(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_resolveFromMount) */
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_object sinkMount = corto_resolve(root_o, "sinkMount");
    test_assert(sinkMount != NULL);

    corto_object mount = corto_resolve(root_o, "mount");
    test_assert(mount != NULL);

    test_Foo o = corto_resolve(mount, "x");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_Foo_o));
    test_assert(corto_ownerof(o) == sinkMount);
    test_assert(corto_checkState(o, CORTO_DEFINED | CORTO_DECLARED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    test_assertint(*test_constructCalled_o, 1);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 1);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 1);
    test_assertint(this->suspended, 0);

    /* Foo constructor modifies members */
    test_assert(o->x == 20);
    test_assert(o->y == 40);

    /* This should remove o from the store and "suspend" it to the sink */
    corto_release(o);
    corto_release(sinkMount);
    corto_release(mount);

    test_assertint(*test_constructCalled_o, 1);
    test_assertint(*test_destructCalled_o, 1);
    test_assertint(this->declared, 1);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 1);
    test_assertint(this->suspended, 1);

/* $end */
}

void _test_ResumeSink_tc_resolveFromNestedVirtualMountPoint(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_resolveFromNestedVirtualMountPoint) */

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMountCreate("/vmount/nested");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_createChild(root_o, "vmount/nested", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object o = corto_resolve(vmount, "x");
    test_assert(o != NULL);
    test_assertstr(corto_fullpath(NULL, o), "/vmount/nested/x");

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

/* $end */
}

void _test_ResumeSink_tc_resolveFromVirtualMountPoint(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_resolveFromVirtualMountPoint) */

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMountCreate("/vmount");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_createChild(root_o, "vmount", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object o = corto_resolve(vmount, "x");
    test_assert(o != NULL);
    test_assertstr(corto_fullpath(NULL, o), "/vmount/x");

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);


/* $end */
}

void _test_ResumeSink_tc_resolveNested1(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_resolveNested1) */
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_object sinkMount = corto_resolve(root_o, "sinkMount");
    test_assert(sinkMount != NULL);

    test_Foo o = corto_resolve(root_o, "mount/x/a");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_Foo_o));
    test_assert(corto_ownerof(o) == sinkMount);
    test_assert(corto_checkState(o, CORTO_DEFINED | CORTO_DECLARED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    test_assertint(*test_constructCalled_o, 2);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 2);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 2);
    test_assertint(this->suspended, 0);

    /* Foo constructor modifies members */
    test_assert(o->x == 20);
    test_assert(o->y == 40);

    /* This should remove o from the store and "suspend" it to the sink */
    corto_release(o);
    corto_release(sinkMount);

    test_assertint(*test_constructCalled_o, 2);
    test_assertint(*test_destructCalled_o, 2);
    test_assertint(this->declared, 2);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 2);
    test_assertint(this->suspended, 2);

/* $end */
}

void _test_ResumeSink_tc_resolveNested1FromMount(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_resolveNested1FromMount) */
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_object sinkMount = corto_resolve(root_o, "sinkMount");
    test_assert(sinkMount != NULL);

    corto_object mount = corto_resolve(root_o, "mount");
    test_assert(mount != NULL);

    test_Foo o = corto_resolve(mount, "x/a");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_Foo_o));
    test_assert(corto_ownerof(o) == sinkMount);
    test_assert(corto_checkState(o, CORTO_DEFINED | CORTO_DECLARED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    test_assertint(*test_constructCalled_o, 2);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 2);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 2);
    test_assertint(this->suspended, 0);

    /* Foo constructor modifies values */
    test_assert(o->x == 20);
    test_assert(o->y == 40);

    /* This should remove o from the store and "suspend" it to the sink */
    corto_release(o);
    corto_release(sinkMount);
    corto_release(mount);

    test_assertint(*test_constructCalled_o, 2);
    test_assertint(*test_destructCalled_o, 2);
    test_assertint(this->declared, 2);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 2);
    test_assertint(this->suspended, 2);

/* $end */
}

void _test_ResumeSink_tc_resolveNested1FromNestedVirtualMountPoint(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_resolveNested1FromNestedVirtualMountPoint) */

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMountCreate("/vmount/nested");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_createChild(root_o, "vmount/nested", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object a = corto_resolve(vmount, "x/a");
    test_assert(a != NULL);
    test_assertstr(corto_fullpath(NULL, a), "/vmount/nested/x/a");
    test_assert(corto_typeof(a) == (corto_type)corto_float32_o);

    corto_object x = corto_parentof(a);
    test_assert(x != NULL);
    test_assertstr(corto_fullpath(NULL, x), "/vmount/nested/x");
    test_assert(corto_typeof(x) == (corto_type)corto_int32_o);

    test_assert(corto_delete(a) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

/* $end */
}

void _test_ResumeSink_tc_resolveNested1FromObjectFromMount(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_resolveNested1FromObjectFromMount) */

    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_object sinkMount = corto_resolve(root_o, "sinkMount");
    test_assert(sinkMount != NULL);

    corto_object mount = corto_resolve(root_o, "mount");
    test_assert(mount != NULL);

    corto_object x = corto_resolve(mount, "x");
    test_assert(x != NULL);

    test_assertint(*test_constructCalled_o, 1);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 1);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 1);
    test_assertint(this->suspended, 0);

    test_Foo o = corto_resolve(x, "a");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_Foo_o));
    test_assert(corto_ownerof(o) == sinkMount);
    test_assert(corto_checkState(o, CORTO_DEFINED | CORTO_DECLARED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    test_assertint(*test_constructCalled_o, 2);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 2);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 2);
    test_assertint(this->suspended, 0);

    test_assert(o->x == 20);
    test_assert(o->y == 40);

    /* This should remove o from the store and "suspend" it to the sink */
    corto_release(o);
    corto_release(x);
    corto_release(sinkMount);
    corto_release(mount);

    test_assertint(*test_constructCalled_o, 2);
    test_assertint(*test_destructCalled_o, 2);
    test_assertint(this->declared, 2);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 2);
    test_assertint(this->suspended, 2);

/* $end */
}

void _test_ResumeSink_tc_resolveNested1FromVirtualMountPoint(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_resolveNested1FromVirtualMountPoint) */

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMountCreate("/vmount");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_createChild(root_o, "vmount", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_autoload(false);
    corto_object o = corto_resolve(vmount, "x/a");
    test_assert(o != NULL);
    test_assertstr(corto_fullpath(NULL, o), "/vmount/x/a");

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

/* $end */
}

void _test_ResumeSink_tc_resolveNested1NotExist(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_resolveNested1NotExist) */
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_object sinkMount = corto_resolve(root_o, "sinkMount");
    test_assert(sinkMount != NULL);

    test_Foo o = corto_resolve(root_o, "mount/x/notexists");
    test_assert(o == NULL);

    /* x is resumed and suspended */
    test_assertint(*test_constructCalled_o, 1);
    test_assertint(*test_destructCalled_o, 1);
    test_assertint(this->declared, 1);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 1);
    test_assertint(this->suspended, 1);

    corto_release(sinkMount);

/* $end */
}

void _test_ResumeSink_tc_resolveNested2(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_resolveNested2) */
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_object sinkMount = corto_resolve(root_o, "sinkMount");
    test_assert(sinkMount != NULL);

    test_Foo o = corto_resolve(root_o, "mount/x/a/k");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_Foo_o));
    test_assert(corto_ownerof(o) == sinkMount);
    test_assert(corto_checkState(o, CORTO_DEFINED | CORTO_DECLARED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    test_assertint(*test_constructCalled_o, 3);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 3);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 3);
    test_assertint(this->suspended, 0);

    /* Foo constructor modifies members */
    test_assert(o->x == 20);
    test_assert(o->y == 40);

    /* This should remove o from the store and "suspend" it to the sink */
    corto_release(o);
    corto_release(sinkMount);

    test_assertint(*test_constructCalled_o, 3);
    test_assertint(*test_destructCalled_o, 3);
    test_assertint(this->declared, 3);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 3);
    test_assertint(this->suspended, 3);

/* $end */
}

void _test_ResumeSink_tc_resolveNested2FromMount(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_resolveNested2FromMount) */
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_object sinkMount = corto_resolve(root_o, "sinkMount");
    test_assert(sinkMount != NULL);

    corto_object mount = corto_resolve(root_o, "mount");
    test_assert(mount != NULL);

    test_Foo o = corto_resolve(mount, "x/a/k");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_Foo_o));
    test_assert(corto_ownerof(o) == sinkMount);
    test_assert(corto_checkState(o, CORTO_DEFINED | CORTO_DECLARED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    test_assertint(*test_constructCalled_o, 3);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 3);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 3);
    test_assertint(this->suspended, 0);

    /* Foo constructor modifies members */
    test_assert(o->x == 20);
    test_assert(o->y == 40);

    /* This should remove o from the store and "suspend" it to the sink */
    corto_release(o);
    corto_release(sinkMount);
    corto_release(mount);

    test_assertint(*test_constructCalled_o, 3);
    test_assertint(*test_destructCalled_o, 3);
    test_assertint(this->declared, 3);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 3);
    test_assertint(this->suspended, 3);

/* $end */
}

void _test_ResumeSink_tc_resolveNested2FromNestedVirtualMountPoint(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_resolveNested2FromNestedVirtualMountPoint) */

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMountCreate("/vmount/nested");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_createChild(root_o, "vmount/nested", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object k = corto_resolve(vmount, "x/a/k");
    test_assert(k != NULL);
    test_assertstr(corto_fullpath(NULL, k), "/vmount/nested/x/a/k");
    test_assert(corto_typeof(k) == (corto_type)corto_int32_o);

    corto_object a = corto_resolve(vmount, "x/a");
    test_assert(a != NULL);
    test_assertstr(corto_fullpath(NULL, a), "/vmount/nested/x/a");
    test_assert(corto_typeof(a) == (corto_type)corto_float32_o);

    corto_object x = corto_parentof(a);
    test_assert(x != NULL);
    test_assertstr(corto_fullpath(NULL, x), "/vmount/nested/x");
    test_assert(corto_typeof(x) == (corto_type)corto_int32_o);

    test_assert(corto_delete(k) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

/* $end */
}

void _test_ResumeSink_tc_resolveNested2FromObjectFromMount(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_resolveNested2FromObjectFromMount) */

    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_object sinkMount = corto_resolve(root_o, "sinkMount");
    test_assert(sinkMount != NULL);

    corto_object mount = corto_resolve(root_o, "mount");
    test_assert(mount != NULL);

    corto_object x = corto_resolve(mount, "x");
    test_assert(x != NULL);

    test_assertint(*test_constructCalled_o, 1);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 1);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 1);
    test_assertint(this->suspended, 0);

    corto_object a = corto_resolve(x, "a");
    test_assert(a != NULL);

    test_assertint(*test_constructCalled_o, 2);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 2);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 2);
    test_assertint(this->suspended, 0);

    test_Foo o = corto_resolve(a, "k");
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_Foo_o));
    test_assert(corto_ownerof(o) == sinkMount);
    test_assert(corto_checkState(o, CORTO_DEFINED | CORTO_DECLARED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    test_assertint(*test_constructCalled_o, 3);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 3);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 3);
    test_assertint(this->suspended, 0);

    /* Foo constructor modifies members */
    test_assert(o->x == 20);
    test_assert(o->y == 40);

    /* This should remove o from the store and "suspend" it to the sink */
    corto_release(o);
    corto_release(a);
    corto_release(x);
    corto_release(sinkMount);
    corto_release(mount);

    test_assertint(*test_constructCalled_o, 3);
    test_assertint(*test_destructCalled_o, 3);
    test_assertint(this->declared, 3);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 3);
    test_assertint(this->suspended, 3);

/* $end */
}

void _test_ResumeSink_tc_resolveNested2FromVirtualMountPoint(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_resolveNested2FromVirtualMountPoint) */

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMountCreate("/vmount");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_createChild(root_o, "vmount", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object o = corto_resolve(vmount, "x/a/k");
    test_assert(o != NULL);
    test_assertstr(corto_fullpath(NULL, o), "/vmount/x/a/k");

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

/* $end */
}

void _test_ResumeSink_tc_resolveNested2NotExist(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_resolveNested2NotExist) */
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_object sinkMount = corto_resolve(root_o, "sinkMount");
    test_assert(sinkMount != NULL);

    test_Foo o = corto_resolve(root_o, "mount/x/a/notexists");
    test_assert(o == NULL);

    /* x is resumed and suspended */
    test_assertint(*test_constructCalled_o, 2);
    test_assertint(*test_destructCalled_o, 2);
    test_assertint(this->declared, 2);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 2);
    test_assertint(this->suspended, 2);

    corto_release(sinkMount);

/* $end */
}

void _test_ResumeSink_tc_resolveNotExist(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_resolveNotExist) */
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_object sinkMount = corto_resolve(root_o, "sinkMount");
    test_assert(sinkMount != NULL);

    test_Foo o = corto_resolve(root_o, "mount/notexists");
    test_assert(o == NULL);

    /* x is resumed and suspended */
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_release(sinkMount);

/* $end */
}

void _test_ResumeSink_tc_resumeNestedFromMultiple(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/tc_resumeNestedFromMultiple) */

    /* Create two mounts that mounts data under vmount, which does not exist in the
     * RAM store. */
    test_VirtualSinkMount mount1 = test_VirtualSinkMountCreate("/vmount");
    test_assert(mount1 != NULL);

    test_VirtualSinkMount mount2 = test_VirtualSinkMountCreate("/vmount");
    test_assert(mount2 != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_createChild(root_o, "vmount", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount, test that only one mount has been invoked */
    corto_object o = corto_lookup(vmount, "x/a");
    test_assert(o != NULL);
    test_assertstr(corto_fullpath(NULL, o), "/vmount/x/a");

    /* Two queries, to resume x and x/a */
    test_assertint(mount1->count + mount2->count, 2);

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(mount1) == 0);
    test_assert(corto_delete(mount2) == 0);
    test_assert(corto_delete(vmount) == 0);

/* $end */
}

void _test_ResumeSink_teardown(
    test_ResumeSink this)
{
/* $begin(test/ResumeSink/teardown) */
    corto_object mount = corto_resolve(NULL, "mount");
    corto_observer_unobserve(test_ResumeSink_onDeclare_o, this, mount);
    corto_observer_unobserve(test_ResumeSink_onDefine_o, this, mount);
    corto_observer_unobserve(test_ResumeSink_onDelete_o, this, mount);
    corto_observer_unobserve(test_ResumeSink_onUpdate_o, this, mount);
    corto_observer_unobserve(test_ResumeSink_onResume_o, this, mount);
    corto_observer_unobserve(test_ResumeSink_onSuspend_o, this, mount);
    corto_release(mount);
/* $end */
}
