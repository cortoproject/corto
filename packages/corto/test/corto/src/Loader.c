/* $CORTO_GENERATED
 *
 * Loader.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

void _test_Loader_tc_createSelfPackage(
    test_Loader this)
{
/* $begin(test/Loader/tc_createSelfPackage) */
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    sig = corto_proccmd("corto rebuild createSelfPackage --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto createSelfPackage", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto clean createSelfPackage --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

/* $end */
}

void _test_Loader_tc_loadChildNoDep(
    test_Loader this)
{
/* $begin(test/Loader/tc_loadChildNoDep) */
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    sig = corto_proccmd("corto rebuild tier2_B --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto tier1/tier2_B", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto clean tier2_B --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

/* $end */
}

void _test_Loader_tc_loadDepOnChild(
    test_Loader this)
{
/* $begin(test/Loader/tc_loadDepOnChild) */
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    sig = corto_proccmd("corto rebuild tier2_B --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto rebuild tier2_A --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto rebuild tier1 --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto tier1", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto clean tier1 --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto clean tier2_A --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto clean tier2_B --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

/* $end */
}

void _test_Loader_tc_loadDepOnParent(
    test_Loader this)
{
/* $begin(test/Loader/tc_loadDepOnParent) */
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    /* tier1/tier2_A depends on tier1/tier2_B */
    sig = corto_proccmd("corto rebuild tier2_B --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    /* tier1 depends on tier1/tier2_A */
    sig = corto_proccmd("corto rebuild tier2_A --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto rebuild tier1 --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto rebuild tier2_C --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto tier1/tier2_C", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto clean tier1 --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto clean tier2_A --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto clean tier2_B --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto clean tier2_C --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

/* $end */
}

void _test_Loader_tc_loadDepOnSibling(
    test_Loader this)
{
/* $begin(test/Loader/tc_loadDepOnSibling) */
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    sig = corto_proccmd("corto rebuild tier2_B --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto rebuild tier2_A --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto rebuild tier1 --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto tier1", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto clean tier2_A --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto clean tier2_B --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto clean tier1 --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

/* $end */
}

void _test_Loader_tc_loadNonExistent(
    test_Loader this)
{
/* $begin(test/Loader/tc_loadNonExistent) */

    corto_int16 ret = corto_load("nonexistent.cx", 0, NULL);
    test_assert(ret != 0);
    test_assert(corto_lasterr() != NULL);
    test_assertstr(corto_lasterr(), "No such file or directory (nonexistent.cx)");

/* $end */
}

void _test_Loader_tc_loadSelf(
    test_Loader this)
{
/* $begin(test/Loader/tc_loadSelf) */
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    sig = corto_proccmd("corto rebuild loadSelf --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto loadSelf", &ret);
    test_assert(ret == 0);
    test_assert(sig == 6);

    sig = corto_proccmd("corto clean loadSelf --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

/* $end */
}

void _test_Loader_tc_locateSelf(
    test_Loader this)
{
/* $begin(test/Loader/tc_locateSelf) */
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    sig = corto_proccmd("corto rebuild locateSelf --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto locateSelf", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto clean locateSelf --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

/* $end */
}
