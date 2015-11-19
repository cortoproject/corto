/* $CORTO_GENERATED
 *
 * test_Env.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "test.h"

corto_void _test_Env_tc_setenvFormatAndReplace(test_Env this) {
/* $begin(test/Env/tc_setenvFormatAndReplace) */
    corto_setenv("CORTO_TEST_A", "A");
    corto_setenv("CORTO_TEST_B", "A/%s/$A", "A");
    char* b = corto_getenv("CORTO_TEST_B");
    test_assert(!strcmp(b, "A/A/A"));
/* $end */
}

corto_void _test_Env_tc_setenvReplaceMultiple(test_Env this) {
/* $begin(test/Env/tc_setenvReplaceMultiple) */
    corto_setenv("CORTO_TEST_A", "A");
    corto_setenv("CORTO_TEST_B", "<$CORTO_TEST_A $CORTO_TEST_A $CORTO_TEST_A>");
    char* b = corto_getenv("CORTO_TEST_B");
    test_assert(!strcmp(b, "<A A A>"));
/* $end */
}

corto_void _test_Env_tc_setenvReplaceWithSameVariable(test_Env this) {
/* $begin(test/Env/tc_setenvReplaceWithSameVariable) */
    corto_setenv("CORTO_TEST_A", "A");
    corto_setenv("CORTO_TEST_A", "$CORTO_TEST_A:$CORTO_TEST_A");
    char* a = corto_getenv("CORTO_TEST_A");
    test_assert(!strcmp(a, "A:A"));
/* $end */
}

corto_void _test_Env_tc_setenvSimple(test_Env this) {
/* $begin(test/Env/tc_setenvSimple) */
    corto_setenv("CORTO_TEST_A", "A");
    char* a = corto_getenv("CORTO_TEST_A");
    test_assert(!strcmp(a, "A"));
/* $end */
}

corto_void _test_Env_tc_setenvSimpleFormat(test_Env this) {
/* $begin(test/Env/tc_setenvSimpleFormat) */
    corto_setenv("CORTO_TEST_A", "A %s", "B");
    char* a = corto_getenv("CORTO_TEST_A");
    test_assert(!strcmp(a, "A B"));
/* $end */
}

corto_void _test_Env_tc_setenvSimpleReplace(test_Env this) {
/* $begin(test/Env/tc_setenvSimpleReplace) */
    corto_setenv("CORTO_TEST_A", "A");
    corto_setenv("CORTO_TEST_B", "B $CORTO_TEST_A");
    char* a = corto_getenv("CORTO_TEST_A");
    test_assert(!strcmp(a, "A"));
    char* b = corto_getenv("CORTO_TEST_B");
    test_assert(!strcmp(b, "B A"));
/* $end */
}

corto_void _test_Env_tc_setenvVariableNotFound(test_Env this) {
/* $begin(test/Env/tc_setenvVariableNotFound) */
    corto_setenv("CORTO_TEST_A", "ABC ABC $CORTO_NOT_FOUND");
    char* a = corto_getenv("CORTO_TEST_A");
    test_assert(!strcmp(a, ""));
/* $end */
}
