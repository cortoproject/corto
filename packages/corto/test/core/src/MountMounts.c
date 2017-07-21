/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_MountMounts_tc_mountOnDefine(
    test_MountMounts this)
{
    corto_object myRoot = corto_voidCreateChild(root_o, "myroot");
    test_assert(myRoot != NULL);

    test_AutoResumeSinkMount mnt = test_AutoResumeSinkMountCreate(myRoot, NULL, 0);
    test_assert(mnt != NULL);

    test_assert(corto_ll_size(mnt->subscribes) == 0);
    test_assert(corto_ll_size(mnt->unsubscribes) == 0);
    test_assert(corto_ll_size(mnt->mounts) == 0);
    test_assert(corto_ll_size(mnt->unmounts) == 0);

    /* Define object in the mount, this should trigger the MOUNT callback */
    corto_object obj = corto_createChild(myRoot, "obj", corto_void_o);
    test_assert(obj != NULL);

    test_assert(corto_ll_size(mnt->subscribes) == 0);
    test_assert(corto_ll_size(mnt->unsubscribes) == 0);
    test_assert(corto_ll_size(mnt->mounts) == 1);
    test_assert(corto_ll_size(mnt->unmounts) == 0);
}

void test_MountMounts_tc_mountOnSubscribe(
    test_MountMounts this)
{
    /* Insert implementation */
}
