/* $CORTO_GENERATED
 *
 * test_Env.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "test.h"

corto_void _test_Env_tc_envparseFormatAndReplace(test_Env this) {
/* $begin(test/Env/tc_envparseFormatAndReplace) */
    corto_setenv("CORTO_TEST_A", "A");
    char* s = corto_envparse("A/%s/$CORTO_TEST_A", "A");
    test_assert(!strcmp(s, "A/A/A"));
    corto_dealloc(s);
/* $end */
}

corto_void _test_Env_tc_envparseReplaceMultiple(test_Env this) {
/* $begin(test/Env/tc_envparseReplaceMultiple) */
    corto_setenv("CORTO_TEST_A", "A");
    char* s = corto_envparse("<$CORTO_TEST_A $CORTO_TEST_A $CORTO_TEST_A>");
    test_assert(!strcmp(s, "<A A A>"));
    corto_dealloc(s);
/* $end */
}

corto_void _test_Env_tc_envparseReplaceWithSameVariable(test_Env this) {
/* $begin(test/Env/tc_envparseReplaceWithSameVariable) */
    corto_setenv("CORTO_TEST_A", "A");
    char* s = corto_envparse("$CORTO_TEST_A:$CORTO_TEST_A");
    test_assert(!strcmp(s, "A:A"));
    corto_dealloc(s);
/* $end */
}

corto_void _test_Env_tc_envparseSimpleFormat(test_Env this) {
/* $begin(test/Env/tc_envparseSimpleFormat) */
    char* s = corto_envparse("A %s", "B");
    test_assert(!strcmp(s, "A B"));
    corto_dealloc(s);
/* $end */
}

corto_void _test_Env_tc_envparseSimpleReplace(test_Env this) {
/* $begin(test/Env/tc_envparseSimpleReplace) */
    corto_setenv("CORTO_TEST_A", "A");
    char* s = corto_envparse("B $CORTO_TEST_A");
    test_assert(!strcmp(s, "B A"));
    corto_dealloc(s);
/* $end */
}

corto_void _test_Env_tc_envparseVariableNotFound(test_Env this) {
/* $begin(test/Env/tc_envparseVariableNotFound) */
    char* s = corto_envparse("ABC ABC $CORTO_NOT_FOUND");
    test_assert(s == NULL);
/* $end */
}

corto_void _test_Env_tc_setenvSimple(test_Env this) {
/* $begin(test/Env/tc_setenvSimple) */
    corto_setenv("CORTO_TEST_A", "A");
    char* a = corto_getenv("CORTO_TEST_A");
    test_assert(!strcmp(a, "A"));
/* $end */
}
