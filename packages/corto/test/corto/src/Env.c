/* $CORTO_GENERATED
 *
 * Env.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_void _test_Env_tc_envparseFormatAndReplace(
    test_Env this)
{
/* $begin(test/Env/tc_envparseFormatAndReplace) */
    corto_setenv("CORTO_TEST_A", "A");
    char* s = corto_envparse("A/%s/$CORTO_TEST_A", "A");
    test_assert(!strcmp(s, "A/A/A"));
    corto_dealloc(s);
/* $end */
}

corto_void _test_Env_tc_envparseReplaceMultiple(
    test_Env this)
{
/* $begin(test/Env/tc_envparseReplaceMultiple) */
    corto_setenv("CORTO_TEST_A", "A");
    char* s = corto_envparse("<$CORTO_TEST_A $CORTO_TEST_A $CORTO_TEST_A>");
    test_assert(!strcmp(s, "<A A A>"));
    corto_dealloc(s);
/* $end */
}

corto_void _test_Env_tc_envparseReplaceWithSameVariable(
    test_Env this)
{
/* $begin(test/Env/tc_envparseReplaceWithSameVariable) */
    corto_setenv("CORTO_TEST_A", "A");
    char* s = corto_envparse("$CORTO_TEST_A:$CORTO_TEST_A");
    test_assert(!strcmp(s, "A:A"));
    corto_dealloc(s);
/* $end */
}

corto_void _test_Env_tc_envparseSimpleFormat(
    test_Env this)
{
/* $begin(test/Env/tc_envparseSimpleFormat) */
    char* s = corto_envparse("A %s", "B");
    test_assert(!strcmp(s, "A B"));
    corto_dealloc(s);
/* $end */
}

corto_void _test_Env_tc_envparseSimpleReplace(
    test_Env this)
{
/* $begin(test/Env/tc_envparseSimpleReplace) */
    corto_setenv("CORTO_TEST_A", "A");
    char* s = corto_envparse("B $CORTO_TEST_A");
    test_assert(!strcmp(s, "B A"));
    corto_dealloc(s);
/* $end */
}

corto_void _test_Env_tc_envparseVariableNotFound(
    test_Env this)
{
/* $begin(test/Env/tc_envparseVariableNotFound) */
    char* s = corto_envparse("ABC ABC $CORTO_NOT_FOUND");
    test_assert(s == NULL);
    test_assertstr(corto_lasterr(), "environment variable 'CORTO_NOT_FOUND' doesn't exist");
/* $end */
}

corto_void _test_Env_tc_setenvFormatAndReplace(
    test_Env this)
{
/* $begin(test/Env/tc_setenvFormatAndReplace) */
    corto_setenv("CORTO_TEST_A", "A");
    corto_setenv("CORTO_TEST_B",  "A/%s/$CORTO_TEST_A", "A");
    test_assert(!strcmp(corto_getenv("CORTO_TEST_B"), "A/A/A"));
/* $end */
}

corto_void _test_Env_tc_setenvNull(
    test_Env this)
{
/* $begin(test/Env/tc_setenvNull) */
    corto_setenv("CORTO_TEST_A", "A");
    test_assert(!strcmp(corto_getenv("CORTO_TEST_A"), "A"));
    corto_setenv("CORTO_TEST_A", NULL);
    test_assert(corto_getenv("CORTO_TEST_A") == NULL);
/* $end */
}

corto_void _test_Env_tc_setenvReplaceMultiple(
    test_Env this)
{
/* $begin(test/Env/tc_setenvReplaceMultiple) */
    test_assert(!corto_setenv("CORTO_TEST_A", "A"));
    test_assert(!corto_setenv("CORTO_TEST_B", "<$CORTO_TEST_A $CORTO_TEST_A $CORTO_TEST_A>"));
    test_assert(!strcmp(corto_getenv("CORTO_TEST_B"), "<A A A>"));
/* $end */
}

corto_void _test_Env_tc_setenvReplaceWithSameVariable(
    test_Env this)
{
/* $begin(test/Env/tc_setenvReplaceWithSameVariable) */
    test_assert(!corto_setenv("CORTO_TEST_A", "A"));
    test_assert(!corto_setenv("CORTO_TEST_A", "$CORTO_TEST_A:$CORTO_TEST_A"));
    test_assert(!strcmp(corto_getenv("CORTO_TEST_A"), "A:A"));
/* $end */
}

corto_void _test_Env_tc_setenvSimple(
    test_Env this)
{
/* $begin(test/Env/tc_setenvSimple) */
    test_assert(!corto_setenv("CORTO_TEST_A", "A"));
    test_assert(!strcmp(corto_getenv("CORTO_TEST_A"), "A"));
/* $end */
}

corto_void _test_Env_tc_setenvSimpleFormat(
    test_Env this)
{
/* $begin(test/Env/tc_setenvSimpleFormat) */
    test_assert(!corto_setenv("CORTO_TEST_A", "A %s", "B"));
    test_assert(!strcmp(corto_getenv("CORTO_TEST_A"), "A B"));
/* $end */
}

corto_void _test_Env_tc_setenvSimpleReplace(
    test_Env this)
{
/* $begin(test/Env/tc_setenvSimpleReplace) */
    test_assert(!corto_setenv("CORTO_TEST_A", "A"));
    test_assert(!corto_setenv("CORTO_TEST_B", "B $CORTO_TEST_A"));
    test_assert(!strcmp(corto_getenv("CORTO_TEST_B"), "B A"));
/* $end */
}

corto_void _test_Env_tc_setenvVariableNotFound(
    test_Env this)
{
/* $begin(test/Env/tc_setenvVariableNotFound) */
    test_assert(corto_setenv("CORTO_TEST_A", "ABC ABC $CORTO_NOT_FOUND"));
    test_assertstr(corto_lasterr(), "environment variable 'CORTO_NOT_FOUND' doesn't exist");

/* $end */
}
