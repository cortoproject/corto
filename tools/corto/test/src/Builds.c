/* $CORTO_GENERATED
 *
 * Builds.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

void _test_Builds_setup(
    test_Builds this)
{
/* $begin(test/Builds/setup) */

    corto_int16 ret = corto_chdir(TEST_ETC);
    test_assert(ret == 0);

/* $end */
}

void _test_Builds_tc_appDef(
    test_Builds this)
{
/* $begin(test/Builds/tc_appDef) */
    corto_int8 ret;
    corto_int8 sig;

    sig = corto_proccmd("corto rebuild tc_appDef --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto run tc_appDef", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto clean tc_appDef", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

/* $end */
}

void _test_Builds_tc_appDefObject(
    test_Builds this)
{
/* $begin(test/Builds/tc_appDefObject) */
    corto_int8 ret;
    corto_int8 sig;

    sig = corto_proccmd("corto rebuild tc_appDefObject --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto run tc_appDefObject", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto clean tc_appDefObject", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

/* $end */
}

void _test_Builds_tc_appLocalDef(
    test_Builds this)
{
/* $begin(test/Builds/tc_appLocalDef) */
    corto_int8 ret;
    corto_int8 sig;

    sig = corto_proccmd("corto rebuild tc_appLocalDef --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto run tc_appLocalDef", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto clean tc_appLocalDef", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

/* $end */
}

void _test_Builds_tc_appLocalDefObject(
    test_Builds this)
{
/* $begin(test/Builds/tc_appLocalDefObject) */
    corto_int8 ret;
    corto_int8 sig;

    sig = corto_proccmd("corto rebuild tc_appLocalDefObject --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto run tc_appLocalDefObject", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto clean tc_appLocalDefObject", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

/* $end */
}

void _test_Builds_tc_appNested(
    test_Builds this)
{
/* $begin(test/Builds/tc_appNested) */
    corto_int8 ret;
    corto_int8 sig;

    sig = corto_proccmd("corto rebuild tc_appNested --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto run tc_appNested", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto run fooparent/tc_appNested", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto clean tc_appNested", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

/* $end */
}

void _test_Builds_tc_appNestedDef(
    test_Builds this)
{
/* $begin(test/Builds/tc_appNestedDef) */
    corto_int8 ret;
    corto_int8 sig;

    sig = corto_proccmd("corto rebuild tc_appNestedDef --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto run tc_appNestedDef", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto run fooparent/tc_appNestedDef", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto clean tc_appNestedDef", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

/* $end */
}

void _test_Builds_tc_packageNoDef(
    test_Builds this)
{
/* $begin(test/Builds/tc_packageNoDef) */
    corto_int8 ret;
    corto_int8 sig;

    sig = corto_proccmd("corto rebuild tc_packageNoDef --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto rebuild tc_packageNoDef/noCorto --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto locate noCorto", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto clean tc_packageNoDef/noCorto", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto clean tc_packageNoDef", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

/* $end */
}

void _test_Builds_tc_runDirect(
    test_Builds this)
{
/* $begin(test/Builds/tc_runDirect) */
    corto_int8 ret;
    corto_int8 sig;

    sig = corto_proccmd("corto rebuild tc_app --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("tc_app/tc_app", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto clean tc_app", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

/* $end */
}

void _test_Builds_tc_runFromParent(
    test_Builds this)
{
/* $begin(test/Builds/tc_runFromParent) */
    corto_int8 ret;
    corto_int8 sig;

    sig = corto_proccmd("corto rebuild tc_app --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto run tc_app", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto clean tc_app", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

/* $end */
}

void _test_Builds_tc_runFromProject(
    test_Builds this)
{
/* $begin(test/Builds/tc_runFromProject) */
    corto_int8 ret;
    corto_int8 sig;

    sig = corto_proccmd("corto rebuild tc_app --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    ret = corto_chdir("tc_app");
    sig = corto_proccmd("corto run", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    sig = corto_proccmd("corto clean", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

/* $end */
}
