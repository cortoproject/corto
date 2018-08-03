/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_Loader_tc_createSelfPackage(
    test_Loader this)
{
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    sig = corto_proc_cmd("bake rebuild createSelfPackage --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("corto createSelfPackage", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake clean createSelfPackage --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

}

void test_Loader_tc_loadChildNoDep(
    test_Loader this)
{
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    sig = corto_proc_cmd("bake rebuild tier2_B --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("corto tier1/tier2_B", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake clean tier2_B --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

}

void test_Loader_tc_loadDepOnChild(
    test_Loader this)
{
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    sig = corto_proc_cmd("bake rebuild tier2_B --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake rebuild tier2_A --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake rebuild tier1 --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("corto tier1", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake clean tier1 --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake clean tier2_A --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake clean tier2_B --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

}

void test_Loader_tc_loadDepOnParent(
    test_Loader this)
{
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    /* tier1/tier2_A depends on tier1/tier2_B */
    sig = corto_proc_cmd("bake rebuild tier2_B --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    /* tier1 depends on tier1/tier2_A */
    sig = corto_proc_cmd("bake rebuild tier2_A --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake rebuild tier1 --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake rebuild tier2_C --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("corto tier1/tier2_C", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake clean tier1 --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake clean tier2_A --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake clean tier2_B --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake clean tier2_C --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

}

void test_Loader_tc_loadDepOnSibling(
    test_Loader this)
{
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    sig = corto_proc_cmd("bake rebuild tier2_B --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake rebuild tier2_A --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake rebuild tier1 --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("corto tier1", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake clean tier2_A --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake clean tier2_B --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake clean tier1 --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

}

void test_Loader_tc_loadNonExistent(
    test_Loader this)
{

    corto_int16 ret = corto_use("nonexistent.cx", 0, NULL);
    test_assert(ret != 0);
    test_assert(corto_catch());
}

void test_Loader_tc_loadSelf(
    test_Loader this)
{
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    sig = corto_proc_cmd("bake rebuild loadSelf --verbosity error", &ret);
    test_assertint(sig, 0);
    test_assertint(ret, 0);

    corto_log_verbosity old = corto_log_verbositySet(CORTO_CRITICAL);

    sig = corto_proc_cmd("corto loadSelf", &ret);
    test_assertint(sig, 0);
    test_assertint(ret, 1);
    test_assert(corto_catch());

    corto_log_verbositySet(old);

    sig = corto_proc_cmd("bake clean loadSelf --verbosity error", &ret);
    test_assertint(sig, 0);
    test_assertint(ret, 0);
}

void test_Loader_tc_locateSelf(
    test_Loader this)
{
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    sig = corto_proc_cmd("bake rebuild locateSelf --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("corto locateSelf", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake clean locateSelf --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);
}

void test_Loader_tc_autoloadPackageNoLib(
    test_Loader this)
{
    corto_log_setExceptionAction(CORTO_LOG_ON_EXCEPTION_ABORT);
    corto_object o = corto_create(root_o, "/driver", corto_package_o);
    test_assert(o != NULL);
    test_assert(corto_delete(o) == 0);
}
