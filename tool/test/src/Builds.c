/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_Builds_setup(
    test_Builds this)
{

    corto_int16 ret = corto_chdir(TEST_ETC);
    test_assert(ret == 0);

}

void test_Builds_tc_appDef(
    test_Builds this)
{
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

}

void test_Builds_tc_appDefObject(
    test_Builds this)
{
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

}

void test_Builds_tc_appLocalDef(
    test_Builds this)
{
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

}

void test_Builds_tc_appLocalDefObject(
    test_Builds this)
{
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

}

void test_Builds_tc_appNested(
    test_Builds this)
{
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

}

void test_Builds_tc_appNestedDef(
    test_Builds this)
{
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

}

void test_Builds_tc_packageNoDef(
    test_Builds this)
{
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

}

void test_Builds_tc_runDirect(
    test_Builds this)
{
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

}

void test_Builds_tc_runFromParent(
    test_Builds this)
{
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

}

void test_Builds_tc_runFromProject(
    test_Builds this)
{
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

}

