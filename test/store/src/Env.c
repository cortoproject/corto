/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_Env_tc_envparseFormatAndReplace(
    test_Env this)
{
    corto_setenv("CORTO_TEST_A", "A");
    char* s = corto_envparse("A/%s/$CORTO_TEST_A", "A");
    test_assert(!strcmp(s, "A/A/A"));
    corto_dealloc(s);
}

void test_Env_tc_envparseReplaceMultiple(
    test_Env this)
{
    corto_setenv("CORTO_TEST_A", "A");
    char* s = corto_envparse("<$CORTO_TEST_A $CORTO_TEST_A $CORTO_TEST_A>");
    test_assert(!strcmp(s, "<A A A>"));
    corto_dealloc(s);
}

void test_Env_tc_envparseReplaceWithSameVariable(
    test_Env this)
{
    corto_setenv("CORTO_TEST_A", "A");
    char* s = corto_envparse("$CORTO_TEST_A:$CORTO_TEST_A");
    test_assert(!strcmp(s, "A:A"));
    corto_dealloc(s);
}

void test_Env_tc_envparseSimpleFormat(
    test_Env this)
{
    char* s = corto_envparse("A %s", "B");
    test_assert(!strcmp(s, "A B"));
    corto_dealloc(s);
}

void test_Env_tc_envparseSimpleReplace(
    test_Env this)
{
    corto_setenv("CORTO_TEST_A", "A");
    char* s = corto_envparse("B $CORTO_TEST_A");
    test_assert(!strcmp(s, "B A"));
    corto_dealloc(s);
}

void test_Env_tc_envparseVariableNotFound(
    test_Env this)
{
    char* s = corto_envparse("ABC ABC $CORTO_NOT_FOUND");
    test_assert(s == NULL);
    test_assert(corto_catch());
}

void test_Env_tc_setenvFormatAndReplace(
    test_Env this)
{
    corto_setenv("CORTO_TEST_A", "A");
    corto_setenv("CORTO_TEST_B",  "A/%s/$CORTO_TEST_A", "A");
    test_assert(!strcmp(corto_getenv("CORTO_TEST_B"), "A/A/A"));
}

void test_Env_tc_setenvNull(
    test_Env this)
{
    corto_setenv("CORTO_TEST_A", "A");
    test_assert(!strcmp(corto_getenv("CORTO_TEST_A"), "A"));
    corto_setenv("CORTO_TEST_A", NULL);
    test_assert(corto_getenv("CORTO_TEST_A") == NULL);
}

void test_Env_tc_setenvReplaceMultiple(
    test_Env this)
{
    test_assert(!corto_setenv("CORTO_TEST_A", "A"));
    test_assert(!corto_setenv("CORTO_TEST_B", "<$CORTO_TEST_A $CORTO_TEST_A $CORTO_TEST_A>"));
    test_assert(!strcmp(corto_getenv("CORTO_TEST_B"), "<A A A>"));
}

void test_Env_tc_setenvReplaceWithSameVariable(
    test_Env this)
{
    test_assert(!corto_setenv("CORTO_TEST_A", "A"));
    test_assert(!corto_setenv("CORTO_TEST_A", "$CORTO_TEST_A:$CORTO_TEST_A"));
    test_assert(!strcmp(corto_getenv("CORTO_TEST_A"), "A:A"));
}

void test_Env_tc_setenvSimple(
    test_Env this)
{
    test_assert(!corto_setenv("CORTO_TEST_A", "A"));
    test_assert(!strcmp(corto_getenv("CORTO_TEST_A"), "A"));
}

void test_Env_tc_setenvSimpleFormat(
    test_Env this)
{
    test_assert(!corto_setenv("CORTO_TEST_A", "A %s", "B"));
    test_assert(!strcmp(corto_getenv("CORTO_TEST_A"), "A B"));
}

void test_Env_tc_setenvSimpleReplace(
    test_Env this)
{
    test_assert(!corto_setenv("CORTO_TEST_A", "A"));
    test_assert(!corto_setenv("CORTO_TEST_B", "B $CORTO_TEST_A"));
    test_assert(!strcmp(corto_getenv("CORTO_TEST_B"), "B A"));
}

void test_Env_tc_setenvVariableNotFound(
    test_Env this)
{
    test_assert(corto_setenv("CORTO_TEST_A", "ABC ABC $CORTO_NOT_FOUND"));
    test_assert(corto_catch());
}
