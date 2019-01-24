/* This is a managed file. Do not delete this comment. */

#include <include/test.h>
void test_ResumeSink_onDeclare(
    corto_observer_event *e)
{
    test_ResumeSink this = e->instance;
    this->declared ++;
}

void test_ResumeSink_onDefine(
    corto_observer_event *e)
{
    test_ResumeSink this = e->instance;
    this->defined ++;

}

void test_ResumeSink_onDelete(
    corto_observer_event *e)
{
    test_ResumeSink this = e->instance;
    this->deleted ++;

}

void test_ResumeSink_on_resume(
    corto_observer_event *e)
{
    test_ResumeSink this = e->instance;
    this->resumed ++;
}

void test_ResumeSink_onSuspend(
    corto_observer_event *e)
{
    test_ResumeSink this = e->instance;
    this->suspended ++;

}

void test_ResumeSink_onUpdate(
    corto_observer_event *e)
{
    test_ResumeSink this = e->instance;
    this->updated ++;

}

void test_ResumeSink_setup(
    test_ResumeSink this)
{
    /* Register sink mount */
    corto_void__create_auto(root_o, mount);
    test_SinkMount__create_auto(root_o, sinkMount, mount, "test/Foo", "{10, 20}");

    /* Setup observers */
    corto_observer_observe(test_ResumeSink_onDeclare_o, this, mount);
    corto_observer_observe(test_ResumeSink_onDefine_o, this, mount);
    corto_observer_observe(test_ResumeSink_onDelete_o, this, mount);
    corto_observer_observe(test_ResumeSink_onUpdate_o, this, mount);
    corto_observer_observe(test_ResumeSink_on_resume_o, this, mount);
    corto_observer_observe(test_ResumeSink_onSuspend_o, this, mount);
}

void test_ResumeSink_tc_cleanupParentFromResumedChild(
    test_ResumeSink this)
{
    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMount__create(NULL, NULL, "/vmount");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_create(root_o, "vmount", corto_void_o);
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
    test_assert(corto_typeof(a) == (corto_type)corto_unknown_o);
    test_assertint(corto_countof(a), 1);

    corto_object x = corto_parentof(a);
    test_assert(x != NULL);
    test_assertstr(corto_fullpath(NULL, x), "/vmount/x");
    test_assert(corto_typeof(x) == (corto_type)corto_unknown_o);
    test_assertint(corto_countof(x), 1);

    test_assert(corto_delete(k) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

}

void test_ResumeSink_tc_define(
    test_ResumeSink this)
{
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

    test_Foo o = test_Foo__create(mount, "x", 0, 0);
    test_assert(o != NULL);
    test_assert(corto_parentof(o) == mount);
    test_assert(corto_typeof(o) == corto_type(test_Foo_o));
    test_assert(corto_sourceof(o) == sinkMount);
    test_assert(corto_check_state(o, CORTO_VALID | CORTO_DECLARED));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));

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

}

void test_ResumeSink_tc_defineFromNestedVirtualMountPoint(
    test_ResumeSink this)
{

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMount__create(NULL, NULL, "/vmount/nested");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_create(root_o, "vmount/nested", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object o = corto_create(vmount, "x", corto_int32_o);
    test_assert(o != NULL);
    test_assertstr(corto_fullpath(NULL, o), "/vmount/nested/x");
    test_assert(corto_sourceof(o) == mount);

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

}

void test_ResumeSink_tc_defineFromVirtualMountPoint(
    test_ResumeSink this)
{

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMount__create(NULL, NULL, "/vmount");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_create(root_o, "vmount", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object o = corto_create(vmount, "x", corto_int32_o);
    test_assert(o != NULL);
    test_assertstr(corto_fullpath(NULL, o), "/vmount/x");
    test_assert(corto_sourceof(o) == mount);

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

}

void test_ResumeSink_tc_defineNested1(
    test_ResumeSink this)
{
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

    test_Foo o = test_Foo__create(parent, "a", 0, 0);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_Foo_o));
    test_assert(corto_sourceof(o) == sinkMount);
    test_assert(corto_check_state(o, CORTO_VALID | CORTO_DECLARED));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));

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

}

void test_ResumeSink_tc_defineNested1FromNestedVirtualMountPoint(
    test_ResumeSink this)
{
    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMount__create(NULL, NULL, "/vmount/nested");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_create(root_o, "vmount/nested", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object a = corto_create(vmount, "x/a", corto_float32_o);
    test_assert(a != NULL);
    test_assertstr(corto_fullpath(NULL, a), "/vmount/nested/x/a");
    test_assert(corto_sourceof(a) == mount);
    test_assert(corto_typeof(a) == (corto_type)corto_float32_o);

    corto_object x = corto_parentof(a);
    test_assert(x != NULL);
    test_assertstr(corto_fullpath(NULL, x), "/vmount/nested/x");
    test_assert(corto_typeof(x) == (corto_type)corto_unknown_o);

    test_assert(corto_delete(a) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);
}

void test_ResumeSink_tc_defineNested2(
    test_ResumeSink this)
{
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

    test_Foo o = test_Foo__create(parent, "k", 0, 0);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_Foo_o));
    test_assert(corto_sourceof(o) == sinkMount);
    test_assert(corto_check_state(o, CORTO_VALID | CORTO_DECLARED));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));

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

}

void test_ResumeSink_tc_lookup(
    test_ResumeSink this)
{
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
    test_assert(corto_sourceof(o) == sinkMount);
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));

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

}

void test_ResumeSink_tc_lookupFromMount(
    test_ResumeSink this)
{
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
    test_assert(corto_sourceof(o) == sinkMount);
    test_assert(corto_check_state(o, CORTO_VALID | CORTO_DECLARED));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));

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

}

void test_ResumeSink_tc_lookupFromNestedVirtualMountPoint(
    test_ResumeSink this)
{

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMount__create(NULL, NULL, "/vmount/nested");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_create(root_o, "vmount/nested", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object o = corto_lookup(vmount, "x");
    test_assert(o != NULL);
    test_assertstr(corto_fullpath(NULL, o), "/vmount/nested/x");

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

}

void test_ResumeSink_tc_lookupFromVirtualMountPoint(
    test_ResumeSink this)
{

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMount__create(NULL, NULL, "/vmount");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_create(root_o, "vmount", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object o = corto_lookup(vmount, "x");
    test_assert(o != NULL);
    test_assertstr(corto_fullpath(NULL, o), "/vmount/x");

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

}

void test_ResumeSink_tc_lookupNested1(
    test_ResumeSink this)
{
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
    test_assert(corto_sourceof(o) == sinkMount);
    test_assert(corto_check_state(o, CORTO_VALID | CORTO_DECLARED));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));

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

}

void test_ResumeSink_tc_lookupNested1FromMount(
    test_ResumeSink this)
{
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
    test_assert(corto_sourceof(o) == sinkMount);
    test_assert(corto_check_state(o, CORTO_VALID | CORTO_DECLARED));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));

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

}

void test_ResumeSink_tc_lookupNested1FromNestedVirtualMountPoint(
    test_ResumeSink this)
{

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMount__create(NULL, NULL, "/vmount/nested");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_create(root_o, "vmount/nested", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object a = corto_lookup(vmount, "x/a");
    test_assert(a != NULL);
    test_assertstr(corto_fullpath(NULL, a), "/vmount/nested/x/a");
    test_assert(corto_typeof(a) == (corto_type)corto_float32_o);

    corto_object x = corto_parentof(a);
    test_assert(x != NULL);
    test_assertstr(corto_fullpath(NULL, x), "/vmount/nested/x");
    test_assert(corto_typeof(x) == (corto_type)corto_unknown_o);

    test_assert(corto_delete(a) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

}

void test_ResumeSink_tc_lookupNested1FromObjectFromMount(
    test_ResumeSink this)
{

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
    test_assert(corto_sourceof(o) == sinkMount);
    test_assert(corto_check_state(o, CORTO_VALID | CORTO_DECLARED));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));

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

}

void test_ResumeSink_tc_lookupNested1FromVirtualMountPoint(
    test_ResumeSink this)
{

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMount__create(NULL, NULL, "/vmount");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_create(root_o, "vmount", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object o = corto_lookup(vmount, "x/a");
    test_assert(o != NULL);
    test_assertstr(corto_fullpath(NULL, o), "/vmount/x/a");

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

}

void test_ResumeSink_tc_lookupNested1NotExist(
    test_ResumeSink this)
{
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

    /* Verify that x is not in the store */
    corto_object x = corto(CORTO_LOOKUP, {.id = "mount/x"});
    test_assert(x == NULL);

    /* x was created as unknown and was never constructed or destructed */
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_release(sinkMount);

}

void test_ResumeSink_tc_lookupNested2(
    test_ResumeSink this)
{
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
    test_assert(corto_sourceof(o) == sinkMount);
    test_assert(corto_check_state(o, CORTO_VALID | CORTO_DECLARED));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));

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

}

void test_ResumeSink_tc_lookupNested2FromMount(
    test_ResumeSink this)
{
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
    test_assert(corto_sourceof(o) == sinkMount);
    test_assert(corto_check_state(o, CORTO_VALID | CORTO_DECLARED));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));

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

}

void test_ResumeSink_tc_lookupNested2FromNestedVirtualMountPoint(
    test_ResumeSink this)
{

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMount__create(NULL, NULL, "/vmount/nested");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_create(root_o, "vmount/nested", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object k = corto_lookup(vmount, "x/a/k");
    test_assert(k != NULL);
    test_assertstr(corto_fullpath(NULL, k), "/vmount/nested/x/a/k");
    test_assert(corto_typeof(k) == (corto_type)corto_int32_o);

    corto_object a = corto_parentof(k);
    test_assert(a != NULL);
    test_assertstr(corto_fullpath(NULL, a), "/vmount/nested/x/a");
    test_assert(corto_typeof(a) == (corto_type)corto_unknown_o);

    corto_object x = corto_parentof(a);
    test_assert(x != NULL);
    test_assertstr(corto_fullpath(NULL, x), "/vmount/nested/x");
    test_assert(corto_typeof(x) == (corto_type)corto_unknown_o);

    test_assert(corto_delete(k) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

}

void test_ResumeSink_tc_lookupNested2FromObjectFromMount(
    test_ResumeSink this)
{

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
    test_assert(corto_sourceof(o) == sinkMount);
    test_assert(corto_check_state(o, CORTO_VALID | CORTO_DECLARED));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));

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

}

void test_ResumeSink_tc_lookupNested2FromVirtualMountPoint(
    test_ResumeSink this)
{

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMount__create(NULL, NULL, "/vmount");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_create(root_o, "vmount", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object k = corto_lookup(vmount, "x/a/k");
    test_assert(k != NULL);
    test_assertstr(corto_fullpath(NULL, k), "/vmount/x/a/k");
    test_assert(corto_typeof(k) == (corto_type)corto_int32_o);

    corto_object a = corto_parentof(k);
    test_assert(a != NULL);
    test_assertstr(corto_fullpath(NULL, a), "/vmount/x/a");
    test_assert(corto_typeof(a) == (corto_type)corto_unknown_o);

    corto_object x = corto_parentof(a);
    test_assert(x != NULL);
    test_assertstr(corto_fullpath(NULL, x), "/vmount/x");
    test_assert(corto_typeof(x) == (corto_type)corto_unknown_o);

    test_assert(corto_delete(k) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

}

void test_ResumeSink_tc_lookupNested2NotExist(
    test_ResumeSink this)
{
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

    /* Verify that a is not in the store */
    corto_object a = corto(CORTO_LOOKUP, {.id = "mount/x/a"});
    test_assert(a == NULL);

    /* Verify that x is not in the store */
    corto_object x = corto(CORTO_LOOKUP, {.id = "mount/x"});
    test_assert(x == NULL);

    /* x and a are not resumed and suspended */
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_release(sinkMount);

}

void test_ResumeSink_tc_lookupNotExist(
    test_ResumeSink this)
{
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

}

void test_ResumeSink_tc_resolve(
    test_ResumeSink this)
{
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
    test_assert(corto_sourceof(o) == sinkMount);
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));

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

}

void test_ResumeSink_tc_resolveFromMount(
    test_ResumeSink this)
{
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
    test_assert(corto_sourceof(o) == sinkMount);
    test_assert(corto_check_state(o, CORTO_VALID | CORTO_DECLARED));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));

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

}

void test_ResumeSink_tc_resolveFromNestedVirtualMountPoint(
    test_ResumeSink this)
{

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMount__create(NULL, NULL, "/vmount/nested");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_create(root_o, "vmount/nested", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object o = corto_resolve(vmount, "x");
    test_assert(o != NULL);
    test_assertstr(corto_fullpath(NULL, o), "/vmount/nested/x");

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

}

void test_ResumeSink_tc_resolveFromVirtualMountPoint(
    test_ResumeSink this)
{

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMount__create(NULL, NULL, "/vmount");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_create(root_o, "vmount", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object o = corto_resolve(vmount, "x");
    test_assert(o != NULL);
    test_assertstr(corto_fullpath(NULL, o), "/vmount/x");

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);


}

void test_ResumeSink_tc_resolveNested1(
    test_ResumeSink this)
{
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
    test_assert(corto_sourceof(o) == sinkMount);
    test_assert(corto_check_state(o, CORTO_VALID | CORTO_DECLARED));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));

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

}

void test_ResumeSink_tc_resolveNested1FromMount(
    test_ResumeSink this)
{
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
    test_assert(corto_sourceof(o) == sinkMount);
    test_assert(corto_check_state(o, CORTO_VALID | CORTO_DECLARED));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));

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

}

void test_ResumeSink_tc_resolveNested1FromNestedVirtualMountPoint(
    test_ResumeSink this)
{

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMount__create(NULL, NULL, "/vmount/nested");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_create(root_o, "vmount/nested", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object a = corto_resolve(vmount, "x/a");
    test_assert(a != NULL);
    test_assertstr(corto_fullpath(NULL, a), "/vmount/nested/x/a");
    test_assert(corto_typeof(a) == (corto_type)corto_float32_o);

    corto_object x = corto_parentof(a);
    test_assert(x != NULL);
    test_assertstr(corto_fullpath(NULL, x), "/vmount/nested/x");
    test_assert(corto_typeof(x) == (corto_type)corto_unknown_o);

    test_assert(corto_delete(a) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

}

void test_ResumeSink_tc_resolveNested1FromObjectFromMount(
    test_ResumeSink this)
{

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
    test_assert(corto_sourceof(o) == sinkMount);
    test_assert(corto_check_state(o, CORTO_VALID | CORTO_DECLARED));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));

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

}

void test_ResumeSink_tc_resolveNested1FromVirtualMountPoint(
    test_ResumeSink this)
{

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMount__create(NULL, NULL, "/vmount");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_create(root_o, "vmount", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_autoload(false);
    corto_object o = corto_resolve(vmount, "x/a");
    test_assert(o != NULL);
    test_assertstr(corto_fullpath(NULL, o), "/vmount/x/a");

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

}

void test_ResumeSink_tc_resolveNested1NotExist(
    test_ResumeSink this)
{
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
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_release(sinkMount);

}

void test_ResumeSink_tc_resolveNested2(
    test_ResumeSink this)
{
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
    test_assert(corto_sourceof(o) == sinkMount);
    test_assert(corto_check_state(o, CORTO_VALID | CORTO_DECLARED));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));

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

}

void test_ResumeSink_tc_resolveNested2FromMount(
    test_ResumeSink this)
{
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
    test_assert(corto_sourceof(o) == sinkMount);
    test_assert(corto_check_state(o, CORTO_VALID | CORTO_DECLARED));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));

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

}

void test_ResumeSink_tc_resolveNested2FromNestedVirtualMountPoint(
    test_ResumeSink this)
{

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMount__create(NULL, NULL, "/vmount/nested");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_create(root_o, "vmount/nested", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object k = corto_resolve(vmount, "x/a/k");
    test_assert(k != NULL);
    test_assertstr(corto_fullpath(NULL, k), "/vmount/nested/x/a/k");
    test_assert(corto_typeof(k) == (corto_type)corto_int32_o);

    corto_object a = corto_parentof(k);
    test_assert(a != NULL);
    test_assertstr(corto_fullpath(NULL, a), "/vmount/nested/x/a");
    test_assert(corto_typeof(a) == (corto_type)corto_unknown_o);

    corto_object x = corto_parentof(a);
    test_assert(x != NULL);
    test_assertstr(corto_fullpath(NULL, x), "/vmount/nested/x");
    test_assert(corto_typeof(x) == (corto_type)corto_unknown_o);

    test_assert(corto_delete(k) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

}

void test_ResumeSink_tc_resolveNested2FromObjectFromMount(
    test_ResumeSink this)
{

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
    test_assert(corto_sourceof(o) == sinkMount);
    test_assert(corto_check_state(o, CORTO_VALID | CORTO_DECLARED));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));

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

}

void test_ResumeSink_tc_resolveNested2FromVirtualMountPoint(
    test_ResumeSink this)
{

    /* Create a mount that mounts data under vmount, which does not exist in the
     * RAM store. */
    corto_object mount = test_VirtualSinkMount__create(NULL, NULL, "/vmount");
    test_assert(mount != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_create(root_o, "vmount", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount */
    corto_object o = corto_resolve(vmount, "x/a/k");
    test_assert(o != NULL);
    test_assertstr(corto_fullpath(NULL, o), "/vmount/x/a/k");

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(mount) == 0);
    test_assert(corto_delete(vmount) == 0);

}

void test_ResumeSink_tc_resolveNested2NotExist(
    test_ResumeSink this)
{
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
    test_assertint(*test_constructCalled_o, 0);
    test_assertint(*test_destructCalled_o, 0);
    test_assertint(this->declared, 0);
    test_assertint(this->defined, 0);
    test_assertint(this->deleted, 0);
    test_assertint(this->updated, 0);
    test_assertint(this->resumed, 0);
    test_assertint(this->suspended, 0);

    corto_release(sinkMount);

}

void test_ResumeSink_tc_resolveNotExist(
    test_ResumeSink this)
{
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

}

void test_ResumeSink_tc_resumeNestedFromMultiple(
    test_ResumeSink this)
{
    /* Create two mounts that mounts data under vmount, which does not exist in the
     * RAM store. */
    test_VirtualSinkMount mount1 = test_VirtualSinkMount__create(NULL, NULL, "/vmount");
    test_assert(mount1 != NULL);

    test_VirtualSinkMount mount2 = test_VirtualSinkMount__create(NULL, NULL, "/vmount");
    test_assert(mount2 != NULL);

    /* Create mount point after mount- 'mount' member has not been set */
    corto_object vmount = corto_create(root_o, "vmount", corto_void_o);
    test_assert(vmount != NULL);

    /* Lookup object from mount, test that only one mount has been invoked */
    corto_object o = corto_lookup(vmount, "x/a");
    test_assert(o != NULL);
    test_assertstr(corto_fullpath(NULL, o), "/vmount/x/a");

    /* One query, only x/a is resumed */
    test_assertint(mount1->count + mount2->count, 1);

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(mount1) == 0);
    test_assert(corto_delete(mount2) == 0);
    test_assert(corto_delete(vmount) == 0);

}

void test_ResumeSink_teardown(
    test_ResumeSink this)
{
    corto_object mount = corto_resolve(NULL, "mount");
    corto_observer_unobserve(test_ResumeSink_onDeclare_o, this, mount);
    corto_observer_unobserve(test_ResumeSink_onDefine_o, this, mount);
    corto_observer_unobserve(test_ResumeSink_onDelete_o, this, mount);
    corto_observer_unobserve(test_ResumeSink_onUpdate_o, this, mount);
    corto_observer_unobserve(test_ResumeSink_on_resume_o, this, mount);
    corto_observer_unobserve(test_ResumeSink_onSuspend_o, this, mount);
    corto_release(mount);
}

void test_ResumeSink_tc_cleanupResumedParentOfCreatedChild(
    test_ResumeSink this)
{
    /* Create a mount that mounts data under / */
    corto_object mount = test_VirtualSinkMount__create(NULL, NULL, "/");
    test_assert(mount != NULL);

    corto_object parent = corto_lookup(NULL, "x/a");
    test_assert(parent != NULL);
    test_assertstr(corto_fullpath(NULL, parent), "/x/a");

    /* Create object with parent */
    corto_object child = corto_create(parent, "child", corto_void_o);
    test_assert(child != NULL);
    test_assert(corto_release(parent) == 1);
}

void test_ResumeSink_tc_lookupContentTypeFail(
    test_ResumeSink this)
{
    /* Create mount intentionally with a type that doesn't match the JSON */
    corto_object data_o = corto_create(root_o, "data", corto_void_o);
    test_JsonReplicator__create(NULL, NULL, data_o, "/test/InvalidPoint");

    corto_object a = corto_lookup(NULL, "data/a");
    test_assert(a == NULL);
    test_assert(ut_catch() != 0);
}

void test_ResumeSink_tc_defineContentTypeFail(
    test_ResumeSink this)
{
    /* Create mount intentionally with a type that doesn't match the JSON */
    corto_object data_o = corto_create(root_o, "data", corto_void_o);
    test_JsonReplicator__create(NULL, NULL, data_o, "/test/InvalidPoint");

    corto_object a = corto_declare(root_o, "data/a", test_InvalidPoint_o);
    test_assert(a != NULL);

    test_assert(corto_define(a) != 0);
    test_assert(ut_catch() != 0);
    test_assert(corto_delete(a) == 0);
}

void test_ResumeSink_tc_resolveContentTypeFail(
    test_ResumeSink this)
{
    /* Create mount intentionally with a type that doesn't match the JSON */
    corto_object data_o = corto_create(root_o, "data", corto_void_o);
    test_JsonReplicator__create(NULL, NULL, data_o, "/test/InvalidPoint");

    corto_object a = corto_resolve(root_o, "data/a");
    test_assert(a == NULL);
    test_assert(ut_catch() != 0);
}

void test_ResumeSink_tc_createContentTypeFail(
    test_ResumeSink this)
{
    /* Create mount intentionally with a type that doesn't match the JSON */
    corto_object data_o = corto_create(root_o, "data", corto_void_o);
    test_JsonReplicator__create(NULL, NULL, data_o, "/test/InvalidPoint");

    corto_object a = corto_create(root_o, "data/a", test_InvalidPoint_o);
    test_assert(a == NULL);
    test_assert(ut_catch() != 0);
}

void test_ResumeSink_tc_resumeWithAutoFilter(
    test_ResumeSink this)
{
    /* JSON mount always returns all results regardless of filter */
    corto_object data_o = corto_create(root_o, "data", corto_void_o);
    test_JsonReplicator__create(NULL, NULL, data_o, "/test/Point");

    /* Resume object. Should work even though mount returns multiple objects */
    corto_object a = corto_create(root_o, "data/a", test_Point_o);
    test_assert(a != NULL);

    test_assert(corto_delete(a) == 0);
}

void test_ResumeSink_tc_declareAndResume(
    test_ResumeSink this)
{
    /* Create a mount that mounts data under / */
    corto_object data_o = corto_lookup(root_o, "data");
    corto_object m = test_SinkMount__create(
        NULL, NULL, data_o, "test/Point", "{10, 20}");
    test_assert(m != NULL);

    /* Declare and resume object from mount */
    test_Point *x = corto(CORTO_DECLARE|CORTO_RESUME, {
        .parent = data_o,
        .id = "x",
        .type = test_Point_o
    });

    test_assert(x != NULL);
    test_assert(corto_typeof(x) == (corto_type)test_Point_o);
    test_assert(corto_parentof(x) == data_o);
    test_assertstr(corto_idof(x), "x");
    test_assertint(x->x, 10);
    test_assertint(x->y, 20);
    test_assert(corto_check_state(x, CORTO_VALID));

    test_assert(corto_delete(x) == 0);
    test_assert(corto_delete(m) == 0);
}

void test_ResumeSink_tc_lookupAndResumeUnknown(
    test_ResumeSink this)
{
    /* Lookup /data object */
    corto_object data_o = corto_lookup(root_o, "data");

    /* Create data/x as unknown object */
    corto_object y = corto_create(data_o, "x/y", corto_int32_o);
    test_assert(y != NULL);
    test_assert(corto_typeof(y) == (corto_type)corto_int32_o);

    corto_object x = corto_parentof(y);
    test_assert(x != NULL);
    test_assert(corto_typeof(x) == corto_unknown_o);

    /* Create mount on /data */
    corto_object m = test_SinkMount__create(
        NULL, NULL, data_o, "test/Point", "{10, 20}");
    test_assert(m != NULL);

    /* Lookup x */
    corto_object o = corto_lookup(NULL, "data/x");
    test_assert(o != NULL);
    test_assert(o != x);
    test_assert(corto_typeof(o) == (corto_type)test_Point_o);

    test_assert(corto_delete(y) == 0);
    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(m) == 0);
}

void test_ResumeSink_tc_defineHidden(
    test_ResumeSink this)
{
    /* Create mount with a hidden object 'foo' */
    corto_mount m = corto_subscribe("//")
      .from("/data")
      .mount(test_HiddenParentMount_o, "{ownership: LOCAL_SOURCE}");
    test_assert(m != NULL);

    corto_object o = corto(CORTO_DECLARE|CORTO_RECURSIVE_DECLARE|CORTO_RESUME, {
        .parent = data_o, .id = "foo", .type = corto_int32_o});

    test_assert(o != NULL);
    test_assertstr(corto_idof(o), "foo");
    test_assertref(corto_typeof(o), corto_int32_o);

    /* Even though mount provides object, object should not be resumed because
     * the object is HIDDEN */
    test_assert(!corto_check_state(o, CORTO_VALID));
    test_assert(!corto_isresumed(o));

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(m) == 0);
}

static int defineUnknownCount = 0;

void defineUnknownCallback(corto_subscriber_event *e) {
    if (e->event == CORTO_DEFINE) {
        defineUnknownCount ++;
    }
}

void test_ResumeSink_tc_defineUnknown(
    test_ResumeSink this)
{
    /* Create mount with a unknown object 'helloworld' */
    corto_mount m = corto_subscribe("//")
      .from("/data")
      .mount(test_HiddenParentMount_o, "{ownership: LOCAL_SOURCE}");
    test_assert(m != NULL);

    /* Create subscriber that monitors DEFINE events */
    corto_subscriber s = corto_subscribe("helloworld")
      .from("data")
      .callback(defineUnknownCallback);

    test_assertint(defineUnknownCount, 0);

    corto_object o = corto(CORTO_DECLARE|CORTO_RECURSIVE_DECLARE|CORTO_RESUME, {
        .parent = data_o, .id = "helloworld", .type = corto_int32_o});

    test_assert(o != NULL);
    test_assertstr(corto_idof(o), "helloworld");
    test_assertref(corto_typeof(o), corto_int32_o);

    /* Even though mount provides object, object should not be resumed because
     * the object is unknown */
    test_assert(!corto_check_state(o, CORTO_VALID));
    test_assert(!corto_isresumed(o));
    test_assertint(defineUnknownCount, 0);

    /* Create object the normal way */
    corto_object p = corto_create(data_o, "helloworld", corto_int32_o);
    test_assert(o == p);
    test_assert(corto_check_state(p, CORTO_VALID));
    test_assertint(defineUnknownCount, 1);

    test_assert(corto_release(p) == 1);
    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(m) == 0);
    test_assert(corto_delete(s) == 0);
}
