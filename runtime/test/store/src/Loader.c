/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_Loader_tc_createSelfPackage(
    test_Loader this)
{
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    sig = corto_proc_cmd("corto rebuild createSelfPackage --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proc_cmd("corto createSelfPackage", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proc_cmd("corto clean createSelfPackage --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

}

void test_Loader_tc_loadChildNoDep(
    test_Loader this)
{
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    sig = corto_proc_cmd("corto rebuild tier2_B --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proc_cmd("corto tier1/tier2_B", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proc_cmd("corto clean tier2_B --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

}

void test_Loader_tc_loadDepOnChild(
    test_Loader this)
{
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    sig = corto_proc_cmd("corto rebuild tier2_B --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proc_cmd("corto rebuild tier2_A --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proc_cmd("corto rebuild tier1 --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proc_cmd("corto tier1", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proc_cmd("corto clean tier1 --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proc_cmd("corto clean tier2_A --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proc_cmd("corto clean tier2_B --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

}

void test_Loader_tc_loadDepOnParent(
    test_Loader this)
{
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    /* tier1/tier2_A depends on tier1/tier2_B */
    sig = corto_proc_cmd("corto rebuild tier2_B --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    /* tier1 depends on tier1/tier2_A */
    sig = corto_proc_cmd("corto rebuild tier2_A --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proc_cmd("corto rebuild tier1 --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proc_cmd("corto rebuild tier2_C --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proc_cmd("corto tier1/tier2_C", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proc_cmd("corto clean tier1 --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proc_cmd("corto clean tier2_A --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proc_cmd("corto clean tier2_B --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proc_cmd("corto clean tier2_C --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

}

void test_Loader_tc_loadDepOnSibling(
    test_Loader this)
{
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    sig = corto_proc_cmd("corto rebuild tier2_B --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proc_cmd("corto rebuild tier2_A --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proc_cmd("corto rebuild tier1 --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proc_cmd("corto tier1", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proc_cmd("corto clean tier2_A --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proc_cmd("corto clean tier2_B --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proc_cmd("corto clean tier1 --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

}

void test_Loader_tc_loadNonExistent(
    test_Loader this)
{

    corto_int16 ret = corto_load("nonexistent.cx", 0, NULL);
    test_assert(ret != 0);
    test_assert(corto_lasterr() != NULL);
    test_assertstr(corto_lasterr(), "No such file or directory (nonexistent.cx)");

}

void test_Loader_tc_loadSelf(
    test_Loader this)
{
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    sig = corto_proc_cmd("corto rebuild loadSelf --silent", &ret);
    test_assertint(ret, 0);
    test_assertint(sig, 0);

    sig = corto_proc_cmd("corto loadSelf", &ret);
    test_assertint(ret, 0);
    test_assertint(sig, 6);

    sig = corto_proc_cmd("corto clean loadSelf --silent", &ret);
    test_assertint(ret, 0);
    test_assertint(sig, 0);

}

void test_Loader_tc_locateSelf(
    test_Loader this)
{
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    sig = corto_proc_cmd("corto rebuild locateSelf --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proc_cmd("corto locateSelf", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proc_cmd("corto clean locateSelf --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

}

