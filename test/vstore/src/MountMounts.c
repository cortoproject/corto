/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_MountMounts_tc_mountOnDefine(
    test_MountMounts this)
{
    corto_object myRoot = corto_void__create(root_o, "myroot");
    test_assert(myRoot != NULL);

    test_AutoResumeSinkMount mnt = test_AutoResumeSinkMountCreate(myRoot, NULL, 0);
    test_assert(mnt != NULL);

    test_assert(corto_ll_count(mnt->subscribes) == 0);
    test_assert(corto_ll_count(mnt->unsubscribes) == 0);
    test_assert(corto_ll_count(mnt->mounts) == 0);
    test_assert(corto_ll_count(mnt->unmounts) == 0);

    /* Define object in the mount, this should trigger the MOUNT callback */
    corto_object obj = corto_create(myRoot, "obj", corto_void_o);
    test_assert(obj != NULL);

    test_assert(corto_ll_count(mnt->subscribes) == 0);
    test_assert(corto_ll_count(mnt->unsubscribes) == 0);
    test_assert(corto_ll_count(mnt->mounts) == 1);
    test_assert(corto_ll_count(mnt->unmounts) == 0);
}

void test_MountMounts_tc_mountOnSubscribe(
    test_MountMounts this)
{
    /* Insert implementation */
}
