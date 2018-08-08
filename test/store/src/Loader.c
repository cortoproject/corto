/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_Loader_tc_createSelfPackage(
    test_Loader this)
{
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    sig = corto_proc_cmd("bake rebuild create_self_package --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("corto create_self_package", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake clean create_self_package --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

}

void test_Loader_tc_loadChildNoDep(
    test_Loader this)
{
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    sig = corto_proc_cmd("bake rebuild tier2_b --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("corto tier1/tier2_b", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake clean tier2_b --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

}

void test_Loader_tc_loadDepOnChild(
    test_Loader this)
{
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    sig = corto_proc_cmd("bake rebuild tier2_b --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake rebuild tier2_a --verbosity error", &ret);
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

    sig = corto_proc_cmd("bake clean tier2_a --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake clean tier2_b --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

}

void test_Loader_tc_loadDepOnParent(
    test_Loader this)
{
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    /* tier1/tier2_a depends on tier1/tier2_b */
    sig = corto_proc_cmd("bake rebuild tier2_b --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    /* tier1 depends on tier1/tier2_a */
    sig = corto_proc_cmd("bake rebuild tier2_a --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake rebuild tier1 --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake rebuild tier2_c --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("corto tier1/tier2_c", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake clean tier1 --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake clean tier2_a --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake clean tier2_b --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake clean tier2_c --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

}

void test_Loader_tc_loadDepOnSibling(
    test_Loader this)
{
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    sig = corto_proc_cmd("bake rebuild tier2_b --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake rebuild tier2_a --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake rebuild tier1 --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("corto tier1", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake clean tier2_a --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake clean tier2_b --verbosity error", &ret);
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

    sig = corto_proc_cmd("bake rebuild load_self --verbosity error", &ret);
    test_assertint(sig, 0);
    test_assertint(ret, 0);

    corto_log_verbosity old = corto_log_verbositySet(CORTO_CRITICAL);

    sig = corto_proc_cmd("corto load_self", &ret);
    test_assertint(sig, 0);
    test_assertint(ret, 1);
    test_assert(corto_catch());

    corto_log_verbositySet(old);

    sig = corto_proc_cmd("bake clean load_self --verbosity error", &ret);
    test_assertint(sig, 0);
    test_assertint(ret, 0);
}

void test_Loader_tc_locateSelf(
    test_Loader this)
{
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    sig = corto_proc_cmd("bake rebuild locate_self --verbosity error", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("corto locate_self", &ret);
    test_assert(sig == 0);
    test_assert(ret == 0);

    sig = corto_proc_cmd("bake clean locate_self --verbosity error", &ret);
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
